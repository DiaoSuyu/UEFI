@REM # Set Environment
set WORKSPACE=%CD%
set EDK_TOOLS_PATH=%WORKSPACE%\edk2\BaseTools
set CONF_PATH=%WORKSPACE%\edk2\Conf
set PACKAGES_PATH=%WORKSPACE%\edk2;%CD%\edk2-libc
set CYGWIN_HOME=%WORKSPACE%\Tools\BuildTools\Cygwin64
set CLANG_BIN=%WORKSPACE%\Tools\BuildTools\Cygwin64\bin
set NASM_PREFIX=%WORKSPACE%\Tools\BuildTools\NASM\
set PYTHON_HOME=%WORKSPACE%\Tools\BuildTools\Python\Python313
set PYTHON_COMMAND=%WORKSPACE%\Tools\BuildTools\Python\Python313\python.exe
set IASL_PREFIX=%WORKSPACE%\Tools\BuildTools\ASL\
set GIT_COMMAND=%WORKSPACE%\Tools\BuildTools\Git\cmd\git.exe
@REM # Please Set this to your actual path
set VS_ROOT_PATH=%WORKSPACE%\Tools\BuildTools\MSVC\Microsoft Visual Studio\2022\Community 

@REM # Update submodule in root path
%GIT_COMMAND% submodule update --init

@REM # Run edk setup
edk2\edksetup.bat

@REM # Set environment variable of 'Visual Studio C++ Compiler and Tools'
"%VS_ROOT_PATH%\VC\Auxiliary\Build\vcvarsall.bat" x64