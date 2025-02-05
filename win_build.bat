@REM # Set Environment
set WORKSPACE=%CD%
set EDK_TOOLS_PATH=%CD%\edk2\BaseTools
set CONF_PATH=%CD%\edk2\Conf
set PACKAGES_PATH=%CD%\edk2;%CD%\edk2-libc
set CYGWIN_HOME=%CD%\Tools\BuildTools\Cygwin64
set CLANG_BIN=%CD%\Tools\BuildTools\Cygwin64\bin
set NASM_PREFIX=%CD%\Tools\BuildTools\NASM\
set PYTHON_HOME=%CD%\Tools\BuildTools\Python\Python313
set PYTHON_COMMAND=%CD%\Tools\BuildTools\Python\Python313\python.exe
set IASL_PREFIX=%CD%\Tools\BuildTools\ASL\
set VS_ROOT_PATH=C:\Program Files\Microsoft Visual Studio\2022\Community

@REM # Run edk setup
edk2\edksetup.bat

@REM # Set environment variable of 'Visual Studio C++ Compiler and Tools'
"%VS_ROOT_PATH%\VC\Auxiliary\Build\vcvarsall.bat" x64