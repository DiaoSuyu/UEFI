@echo off
setlocal enabledelayedexpansion

set "APP_NAME=%1"

if "%APP_NAME%"=="" (
    echo Usage: %~nx0 AppName
    exit /b 1
)

for /f "delims=" %%A in ('powershell -command "[guid]::NewGuid().ToString()"') do set "UUID=%%A"

if not exist "%APP_NAME%" mkdir "%APP_NAME%"

(
echo ## @file
echo #  %APP_NAME%: need to modify
echo #
echo ##
echo.
echo [Defines]
echo   INF_VERSION                    = 1.25
echo   BASE_NAME                      = %APP_NAME%
echo   FILE_GUID                      = %UUID%
echo   MODULE_TYPE                    = UEFI_APPLICATION
echo   VERSION_STRING                 = 1.0
echo   ENTRY_POINT                    = UefiMain
echo.
echo [Sources]
echo   %APP_NAME%.c
echo.
echo [Packages]
echo   MdePkg/MdePkg.dec
echo.
echo [LibraryClasses]
echo   UefiApplicationEntryPoint
echo   UefiLib
) > "%APP_NAME%\%APP_NAME%.inf"

(
echo #include ^<Uefi.h^>
echo #include ^<Library/UefiBootServicesTableLib.h^>
echo #include ^<Library/UefiLib.h^>
echo.
echo EFI_STATUS
echo EFIAPI
echo UefiMain ^(
echo   IN EFI_HANDLE        ImageHandle,
echo   IN EFI_SYSTEM_TABLE  *SystemTable
echo   ^)
echo {
echo   return EFI_SUCCESS;
echo }
) > "%APP_NAME%\%APP_NAME%.c"

echo Done! The UEFI application template has been created in "%APP_NAME%" folder.
