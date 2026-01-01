"""
Locate libpython associated with this Python executable.
"""

# License
#
# Copyright 2018, Takafumi Arakaki
# Copyright Kaleb Barrett
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
#
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
# LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
# WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
from __future__ import annotations

import argparse
import ctypes
import logging
import os
import sys
from collections.abc import Iterable
from ctypes.util import find_library as _find_library
from functools import wraps
from sysconfig import get_config_var as _get_config_var
from typing import Any, Callable, TypeVar

from find_libpython._version import __version__  # noqa: F401

if sys.version_info >= (3, 10):
    from typing import ParamSpec

    P = ParamSpec("P")

T = TypeVar("T")

_logger = logging.getLogger("find_libpython")

_is_apple = sys.platform == "darwin"
_is_cygwin = sys.platform in ("msys", "cygwin")
_is_mingw = sys.platform == "mingw"
_is_windows = os.name == "nt" and not _is_mingw and not _is_cygwin
_is_posix = os.name == "posix"

_SHLIB_SUFFIX = _get_config_var("_SHLIB_SUFFIX")
if _SHLIB_SUFFIX is None:
    if _is_windows:
        _SHLIB_SUFFIX = ".dll"
    else:
        _SHLIB_SUFFIX = ".so"
if _is_apple:
    # _get_config_var("_SHLIB_SUFFIX") can be ".so" in macOS.
    # Let's not use the value from sysconfig.
    _SHLIB_SUFFIX = ".dylib"


def _linked_libpython_unix(libpython: Any) -> str | None:
    if not hasattr(libpython, "Py_GetVersion"):
        return None

    class Dl_info(ctypes.Structure):
        _fields_ = [
            ("dli_fname", ctypes.c_char_p),
            ("dli_fbase", ctypes.c_void_p),
            ("dli_sname", ctypes.c_char_p),
            ("dli_saddr", ctypes.c_void_p),
        ]

    libdl = ctypes.CDLL(_find_library("dl"))
    libdl.dladdr.argtypes = [ctypes.c_void_p, ctypes.POINTER(Dl_info)]
    libdl.dladdr.restype = ctypes.c_int

    dlinfo = Dl_info()
    retcode = libdl.dladdr(
        ctypes.cast(libpython.Py_GetVersion, ctypes.c_void_p),
        ctypes.pointer(dlinfo),
    )
    if retcode == 0:  # means error
        return None
    return os.path.realpath(dlinfo.dli_fname.decode())


def _library_name(
    name: str, suffix: str = _SHLIB_SUFFIX, _is_windows: bool = _is_windows
) -> str:
    """
    Convert a file basename `name` to a library name (no "lib" and ".so" etc.)

    >>> _library_name("libpython3.7m.so")                   # doctest: +SKIP
    'python3.7m'
    >>> _library_name("libpython3.7m.so", suffix=".so", _is_windows=False)
    'python3.7m'
    >>> _library_name("libpython3.7m.dylib", suffix=".dylib", _is_windows=False)
    'python3.7m'
    >>> _library_name("python37.dll", suffix=".dll", _is_windows=True)
    'python37'
    """
    if not _is_windows and name.startswith("lib"):
        name = name[len("lib") :]
    if suffix and name.endswith(suffix):
        name = name[: -len(suffix)]
    return name


def _append_truthy(list: list[T], item: T) -> None:
    if item:
        list.append(item)


def _uniquifying(items: Iterable[str]) -> Iterable[str]:
    """
    Yield items while excluding the duplicates and preserving the order.

    >>> list(_uniquifying([1, 2, 1, 2, 3]))
    [1, 2, 3]
    """
    seen = set()
    for x in items:
        if x not in seen:
            yield x
        seen.add(x)


def _uniquified(func: Callable[P, Iterable[str]]) -> Callable[P, Iterable[str]]:
    """Wrap iterator returned from `func` by `_uniquifying`."""

    @wraps(func)
    def wrapper(*args: P.args, **kwds: P.kwargs) -> Iterable[str]:
        return _uniquifying(func(*args, **kwds))

    return wrapper


def _get_proc_library() -> Iterable[str]:
    pid = os.getpid()
    path = f"/proc/{pid}/maps"
    lines = open(path).readlines()

    for line in lines:
        path = line.split(" ", 5)[5].strip()
        if "libpython" in os.path.basename(path):
            if not os.path.isfile(path):
                continue
            yield path


@_uniquified
def candidate_names(suffix: str = _SHLIB_SUFFIX) -> Iterable[str]:
    """
    Iterate over candidate file names of libpython.

    Yields
    ------
    name : str
        Candidate name libpython.
    """

    # Quoting configure.ac in the cpython code base:
    # "INSTSONAME is the name of the shared library that will be use to install
    # on the system - some systems like version suffix, others don't.""
    #
    # A typical INSTSONAME is 'libpython3.8.so.1.0' on Linux, or
    # 'Python.framework/Versions/3.9/Python' on MacOS. Due to the possible
    # version suffix we have to find the suffix within the filename.
    INSTSONAME = _get_config_var("INSTSONAME")
    if INSTSONAME and suffix in INSTSONAME:
        yield INSTSONAME

    LDLIBRARY = _get_config_var("LDLIBRARY")
    if LDLIBRARY and os.path.splitext(LDLIBRARY)[1] == suffix:
        yield LDLIBRARY

    LIBRARY = _get_config_var("LIBRARY")
    if LIBRARY and os.path.splitext(LIBRARY)[1] == suffix:
        yield LIBRARY

    DLLLIBRARY = _get_config_var("DLLLIBRARY")
    if DLLLIBRARY:
        yield DLLLIBRARY

    if _is_mingw:
        dlprefix = "lib"
    elif _is_windows or _is_cygwin:
        dlprefix = ""
    else:
        dlprefix = "lib"

    sysdata = dict(
        v=sys.version_info,
        # VERSION is X.Y in Linux/macOS and XY in Windows:
        VERSION=(
            _get_config_var("VERSION")
            or f"{sys.version_info.major}.{sys.version_info.minor}"
        ),
        ABIFLAGS=(_get_config_var("ABIFLAGS") or _get_config_var("abiflags") or ""),
    )

    for stem in [
        "python{VERSION}{ABIFLAGS}".format(**sysdata),
        "python{VERSION}".format(**sysdata),
    ]:
        yield dlprefix + stem + suffix


def _linked_pythondll() -> str | None:
    # On Windows there is the `sys.dllhandle` attribute which is the
    # DLL Handle ID for the associated python.dll for the installation.
    # We can use the GetModuleFileName function to get the path to the
    # python.dll this way.

    # sys.dllhandle is an module ID, which is just a void* cast to an integer,
    # we turn it back into a pointer for the ctypes call
    dll_hmodule = ctypes.cast(sys.dllhandle, ctypes.c_void_p)  # type: ignore[attr-defined]

    # create a buffer for the return path of the maximum length of filepaths in Windows unicode interfaces
    # https://docs.microsoft.com/en-us/windows/win32/fileio/maximum-file-path-limitation
    path_return_buffer = ctypes.create_unicode_buffer(32768)

    # GetModuleFileName sets the return buffer to the value of the path used to load the module.
    # We expect it to always be a normalized absolute path to python.dll.
    r = ctypes.windll.kernel32.GetModuleFileNameW(  # type: ignore[attr-defined]
        dll_hmodule, path_return_buffer, len(path_return_buffer)
    )

    # The return value is the length of the returned string in unicode characters
    # if the size of the buffer (argument 3) is returned, the buffer was too small.
    # Don't know what else to do here but give up.
    if r == len(path_return_buffer):
        return None

    return path_return_buffer.value


@_uniquified
def candidate_paths(suffix: str = _SHLIB_SUFFIX) -> Iterable[str]:
    """
    Iterate over candidate paths of libpython.

    Yields
    ------
    path : str or None
        Candidate path to libpython.  The path may not be a fullpath
        and may not exist.
    """

    if _is_windows:
        if (res := _linked_pythondll()) is not None:
            yield res

    # List candidates for directories in which libpython may exist
    lib_dirs: list[str] = []
    _append_truthy(lib_dirs, _get_config_var("LIBPL"))
    _append_truthy(lib_dirs, _get_config_var("srcdir"))
    _append_truthy(lib_dirs, _get_config_var("LIBDIR"))
    if _is_windows or _is_mingw or _is_cygwin:
        # On Windows DLLs go in bin/ while static libraries go in lib/
        _append_truthy(lib_dirs, _get_config_var("BINDIR"))

    # LIBPL seems to be the right config_var to use.  It is the one
    # used in python-config when shared library is not enabled:
    # https://github.com/python/cpython/blob/v3.7.0/Misc/python-config.in#L55-L57
    #
    # But we try other places just in case.

    if _is_windows or _is_cygwin or _is_mingw:
        lib_dirs.append(os.path.join(os.path.dirname(sys.executable)))
    else:
        lib_dirs.append(
            os.path.join(os.path.dirname(os.path.dirname(sys.executable)), "lib")
        )

    # For macOS:
    _append_truthy(lib_dirs, _get_config_var("PYTHONFRAMEWORKPREFIX"))

    lib_dirs.append(sys.exec_prefix)
    lib_dirs.append(os.path.join(sys.exec_prefix, "lib"))

    lib_basenames = list(candidate_names(suffix=suffix))

    if _is_posix and not _is_cygwin:
        for basename in lib_basenames:
            try:
                libpython = ctypes.CDLL(basename)
            except OSError:
                pass
            else:
                if (res := _linked_libpython_unix(libpython)) is not None:
                    yield res

        try:
            yield from _get_proc_library()
        except OSError:
            _logger.debug("Unable to check /proc filesystem for libpython")

    for directory in lib_dirs:
        for basename in lib_basenames:
            yield os.path.join(directory, basename)

    # In macOS and Windows, ctypes.util.find_library returns a full path:
    for basename in lib_basenames:
        if (res := _find_library(_library_name(basename))) is not None:
            yield res


# Possibly useful links:
# * https://packages.ubuntu.com/bionic/amd64/libpython3.6/filelist
# * https://github.com/Valloric/ycmd/issues/518
# * https://github.com/Valloric/ycmd/pull/519


def _normalize_path(
    path: str, suffix: str = _SHLIB_SUFFIX, _is_apple: bool = _is_apple
) -> str | None:
    """
    Normalize shared library `path` to a real path.

    If `path` is not a full path, `None` is returned.  If `path` does
    not exists, append `_SHLIB_SUFFIX` and check if it exists.
    Finally, the path is canonicalized by following the symlinks.

    Parameters
    ----------
    path : str or None
        A candidate path to a shared library.
    """
    if not path:
        return None
    if not os.path.isabs(path):
        return None
    if os.path.isfile(path):
        return os.path.realpath(path)
    if os.path.isfile(path + suffix):
        return os.path.realpath(path + suffix)
    if _is_apple:
        return _normalize_path(
            _remove_suffix_apple(path), suffix=".so", _is_apple=False
        )
    return None


def _remove_suffix_apple(path: str) -> str:
    """
    Strip off .so or .dylib.

    >>> _remove_suffix_apple("libpython.so")
    'libpython'
    >>> _remove_suffix_apple("libpython.dylib")
    'libpython'
    >>> _remove_suffix_apple("libpython3.7")
    'libpython3.7'
    """
    if path.endswith(".dylib"):
        return path[: -len(".dylib")]
    if path.endswith(".so"):
        return path[: -len(".so")]
    return path


@_uniquified
def _finding_libpython() -> Iterable[str]:
    """
    Iterate over existing libpython paths.

    The first item is likely to be the best one.

    Yields
    ------
    path : str
        Existing path to a libpython.
    """
    for path in candidate_paths():
        _logger.debug("Candidate: %s", path)
        normalized = _normalize_path(path)
        if normalized:
            _logger.debug("Found: %s", normalized)
            yield normalized
        else:
            _logger.debug("Not found.")


def find_libpython() -> str | None:
    """
    Return a path (`str`) to libpython or `None` if not found.

    Parameters
    ----------
    path : str or None
        Existing path to the (supposedly) correct libpython.
    """
    for path in _finding_libpython():
        return os.path.realpath(path)
    return None


def _cli_find_libpython(cli_op: str, verbose: bool) -> int:
    # Importing `logging` module here so that using `logging.debug`
    # instead of `_logger.debug` outside of this function becomes an
    # error.

    def _print_all(items: Iterable[str]) -> None:
        for x in items:
            print(x)

    if verbose:
        logging.basicConfig(format="%(levelname)s %(message)s", level=logging.DEBUG)

    if cli_op == "list-all":
        _print_all(_finding_libpython())
    elif cli_op == "candidate-names":
        _print_all(candidate_names())
    elif cli_op == "candidate-paths":
        _print_all(p for p in candidate_paths() if p and os.path.isabs(p))
    elif cli_op == "platform-info":
        _log_platform_info()
    else:
        path = find_libpython()
        if path is None:
            return 1
        print(path, end="")

    return 0


def _log_platform_info():
    print(f"is_windows = {_is_windows}")
    print(f"is_apple = {_is_apple}")
    print(f"is_mingw = {_is_mingw}")
    print(f"is_msys = {_is_cygwin}")
    print(f"is_posix = {_is_posix}")


def main(args: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "-v", "--verbose", action="store_true", help="Print debugging information."
    )

    group = parser.add_mutually_exclusive_group()
    group.add_argument(
        "--list-all",
        action="store_const",
        dest="cli_op",
        const="list-all",
        help="Print list of all paths found.",
    )
    group.add_argument(
        "--candidate-names",
        action="store_const",
        dest="cli_op",
        const="candidate-names",
        help="Print list of candidate names of libpython.",
    )
    group.add_argument(
        "--candidate-paths",
        action="store_const",
        dest="cli_op",
        const="candidate-paths",
        help="Print list of candidate paths of libpython.",
    )
    group.add_argument(
        "--platform-info",
        action="store_const",
        dest="cli_op",
        const="platform-info",
        help="Print information about the platform and exit.",
    )
    group.add_argument(
        "--version", action="version", version=f"find_libpython {__version__}"
    )

    ns = parser.parse_args(args)
    return _cli_find_libpython(**vars(ns))
