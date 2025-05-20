@REM +-----------------+
@REM | Set Environment |
@REM +-----------------+
@REM REM Set the root of the workspace to the current directory
set WORKSPACE=%CD%

@REM Set the path where all custom build tools are stored
set BUILD_TOOLS_PATH=%WORKSPACE%\Tools\BuildTools

@REM Set the path to the EDK2 configuration directory
set CONF_PATH=%WORKSPACE%\edk2\Conf

@REM Set the path to EDK2 BaseTools (used for building UEFI applications)
set EDK_TOOLS_PATH=%WORKSPACE%\edk2\BaseTools

@REM Set the packages path for EDK2 build (used by build tools to locate packages)
set PACKAGES_PATH=%WORKSPACE%\edk2;%WORKSPACE%\edk2-libc

@REM Set the path to Cygwin (used for Unix-like build tools on Windows)
set CYGWIN_HOME=%BUILD_TOOLS_PATH%\Cygwin64

@REM Add Cygwin's binaries to the environment
set CLANG_BIN=%CYGWIN_HOME%\bin

@REM Define the Git executable to use for version control
set GIT_COMMAND=%BUILD_TOOLS_PATH%\Git\cmd\git.exe

@REM Set the path to IASL compiler (used for compiling ACPI tables)
set IASL_PREFIX=%BUILD_TOOLS_PATH%\ASL\

@REM Set the path to NASM assembler (used for assembling source code)
set NASM_PREFIX=%BUILD_TOOLS_PATH%\NASM\

@REM Set the Python installation used by EDK2 scripts
set PYTHON_HOME=%BUILD_TOOLS_PATH%\Python\Python313

@REM Set the Python executable path explicitly
set PYTHON_COMMAND=%PYTHON_HOME%\python.exe

@REM Define the version of Visual Studio to use
set VS_VERSION=2022

@REM Define the version of MSVC (Microsoft C++ compiler toolset) to use
set MSVC_VERSION=14.43.34808

@REM Set the root path of Visual Studio installation
set VS_ROOT_PATH=%BUILD_TOOLS_PATH%\MSVC\Microsoft Visual Studio\%VS_VERSION%\Community

@REM Set the root path of the Windows SDK
set WINDOWS_KITS_ROOT_PATH=%BUILD_TOOLS_PATH%\WindowsKits

@REM Define the specific version of the Windows SDK to use
set WINSDK_VERSION=10.0.22621.0

@REM Path to the Windows SDK binaries (contains rc.exe and other tools) for x86 architecture
set WINSDK_PATH_FOR_RC_EXE=%WINDOWS_KITS_ROOT_PATH%\10\bin\%WINSDK_VERSION%\x86

@REM Set INCLUDE paths for MSVC compiler and Windows SDK headers
set INCLUDE=%VS_ROOT_PATH%\VC\Tools\MSVC\%MSVC_VERSION%\include;%INCLUDE%
set INCLUDE=%WINDOWS_KITS_ROOT_PATH%\10\Include\%WINSDK_VERSION%\shared;%INCLUDE%
set INCLUDE=%WINDOWS_KITS_ROOT_PATH%\10\Include\%WINSDK_VERSION%\ucrt;%INCLUDE%
set INCLUDE=%WINDOWS_KITS_ROOT_PATH%\10\Include\%WINSDK_VERSION%\um;%INCLUDE%
set INCLUDE=%WINDOWS_KITS_ROOT_PATH%\10\Include\%WINSDK_VERSION%\winrt;%INCLUDE%

@REM Set LIB paths for MSVC compiler and Windows SDK libraries for x86 architecture
set LIB=%VS_ROOT_PATH%\VC\Tools\MSVC\%MSVC_VERSION%\lib\x86;%LIB%
set LIB=%WINDOWS_KITS_ROOT_PATH%\10\Lib\%WINSDK_VERSION%\ucrt\x86;%LIB%
set LIB=%WINDOWS_KITS_ROOT_PATH%\10\Lib\%WINSDK_VERSION%\um\x86;%LIB%

@REM Add paths to the MSVC compiler binaries for x86 architecture
set PATH=%VS_ROOT_PATH%\VC\Tools\MSVC\%MSVC_VERSION%\bin\Hostx64\x86;%PATH%



@REM +-------------------------------+
@REM | Update submodule in root path |
@REM +-------------------------------+
%GIT_COMMAND% submodule update --init


@REM +--------------------------------------------------------------------+
@REM | Set environment variable of 'Visual Studio C++ Compiler and Tools' |
@REM +--------------------------------------------------------------------+
call "%VS_ROOT_PATH%\VC\Auxiliary\Build\vcvarsall.bat" x86


@REM +---------------+
@REM | Run edk setup |
@REM +---------------+
call edk2\edksetup.bat