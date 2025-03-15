@REM # Enable delayed variable expansion. This allows using "!" to access variables that are modified within loops or conditional blocks.
@REM # Without this, the script would use the value of variables at the time the loop or block is entered, rather than during execution.
setlocal EnableDelayedExpansion

@REM # Set Git environment
set WORKSPACE=%CD%
set GIT_COMMAND=%WORKSPACE%\Tools\BuildTools\Git\cmd\git.exe

@REM # Define system path that you want to add
set "NEW_PATH=C:\Windows C:\Windows\system32

@REM # Get current system path
for /f "tokens=*" %%a in ('powershell -Command "[System.Environment]::GetEnvironmentVariable('Path', 'Machine')"') do set "CURRENT_PATH=%%a"

@REM # Init updated system path
set "UPDATED_PATH=!CURRENT_PATH!"

@REM # Check and add paths
for %%p in (%NEW_PATH%) do (
    set "FOUND=0"
    for %%i in ("!CURRENT_PATH:;=";"!") do (
        if /i "%%~i"=="%%p" (
            set "FOUND=1"
            break
        )
    )
    if !FOUND! EQU 0 (
        set "UPDATED_PATH=!UPDATED_PATH!;%%p"
    )
)

@REM # Update system PATH if needed
if not "!UPDATED_PATH!"=="!CURRENT_PATH!" (
    powershell -Command "[System.Environment]::SetEnvironmentVariable('Path', '!UPDATED_PATH!', 'Machine')"
    echo New system path is added successfully.
)

@REM # Update submodule in root
%GIT_COMMAND% submodule update --init

@REM # Update submodule in edk2
cd edk2
%GIT_COMMAND% submodule update --init

@REM # Rebuild basetools, it will not real rebuild basetools if it has rebuilt
edksetup.bat Rebuild