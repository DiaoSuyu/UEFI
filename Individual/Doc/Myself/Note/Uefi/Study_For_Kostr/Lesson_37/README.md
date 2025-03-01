# Build Instructions for UEFI Shell and AcpiView

## 1. Building `AcpiViewApp.efi`

To build the `AcpiViewApp.efi` application, use the following commands based on your compiler:

```sh
# Using GCC5
build -p edk2/ShellPkg/ShellPkg.dsc -m ShellPkg/Application/AcpiViewApp/AcpiViewApp.inf -t GCC5 -a X64 -b RELEASE

# Using Visual Studio 2022
build -p edk2/ShellPkg/ShellPkg.dsc -m ShellPkg/Application/AcpiViewApp/AcpiViewApp.inf -t VS2022 -a X64 -b RELEASE
```

## 2. Building the `AcpiViewApp.efi` into UEFI Shell

To build the `AcpiViewApp.efi` into UEFI Shell, use the following commands:

```sh
# Using GCC5
build -p ShellPkg/ShellPkg.dsc -m ShellPkg/Application/Shell/Shell.inf -t GCC5 -a X64 -b RELEASE

# Using Visual Studio 2022
build -p ShellPkg/ShellPkg.dsc -m ShellPkg/Application/Shell/Shell.inf -t VS2022 -a X64 -b RELEASE
```

### Configuration in `edk2\ShellPkg\ShellPkg.dsc`

Please notice the `FILE_GUID = EA4BB293-2D7F-4456-A681-1F22F42CD0BC`:

```ini
ShellPkg/Application/Shell/Shell.inf {
   <Defines>
      FILE_GUID = EA4BB293-2D7F-4456-A681-1F22F42CD0BC
   <PcdsFixedAtBuild>
      gEfiShellPkgTokenSpaceGuid.PcdShellLibAutoInitialize|FALSE
   <LibraryClasses>
      NULL|ShellPkg/Library/UefiShellLevel2CommandsLib/UefiShellLevel2CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellLevel1CommandsLib/UefiShellLevel1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellLevel3CommandsLib/UefiShellLevel3CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellDriver1CommandsLib/UefiShellDriver1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellInstall1CommandsLib/UefiShellInstall1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellDebug1CommandsLib/UefiShellDebug1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellNetwork1CommandsLib/UefiShellNetwork1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellNetwork2CommandsLib/UefiShellNetwork2CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellAcpiViewCommandLib/UefiShellAcpiViewCommandLib.inf
}
```

### Locating the Built Shell EFI Binary

After building, the UEFI Shell EFI files can be found in:

```sh
ls Build/Shell/RELEASE_GCC5/X64/Shell*.efi
```

Example output:

```sh
Build/Shell/RELEASE_GCC5/X64/Shell_7C04A583-9E3E-4f1c-AD65-E05268D0B4D1.efi
Build/Shell/RELEASE_GCC5/X64/Shell_EA4BB293-2D7F-4456-A681-1F22F42CD0BC.efi
```

**Use** `Shell_EA4BB293-2D7F-4456-A681-1F22F42CD0BC.efi` **for execution.**

## 3. Integrating AcpiView into OVMF Image

To directly integrate `acpiview` into the OVMF UEFI shell, check the `edk2/OvmfPkg/Include/Dsc/ShellComponents.dsc.inc` file:

```ini
  ShellPkg/Application/Shell/Shell.inf {
    <LibraryClasses>
      ShellCommandLib|ShellPkg/Library/UefiShellCommandLib/UefiShellCommandLib.inf
      NULL|ShellPkg/Library/UefiShellLevel2CommandsLib/UefiShellLevel2CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellLevel1CommandsLib/UefiShellLevel1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellLevel3CommandsLib/UefiShellLevel3CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellDriver1CommandsLib/UefiShellDriver1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellDebug1CommandsLib/UefiShellDebug1CommandsLib.inf
!if $(ACPIVIEW_ENABLE) == TRUE
      NULL|ShellPkg/Library/UefiShellAcpiViewCommandLib/UefiShellAcpiViewCommandLib.inf
!endif
      NULL|ShellPkg/Library/UefiShellInstall1CommandsLib/UefiShellInstall1CommandsLib.inf
!if $(NETWORK_ENABLE) == TRUE
!if $(NETWORK_IP4_ENABLE) == TRUE
      NULL|ShellPkg/Library/UefiShellNetwork1CommandsLib/UefiShellNetwork1CommandsLib.inf
!endif
!if $(NETWORK_IP6_ENABLE) == TRUE
      NULL|ShellPkg/Library/UefiShellNetwork2CommandsLib/UefiShellNetwork2CommandsLib.inf
!endif
!endif
      HandleParsingLib|ShellPkg/Library/UefiHandleParsingLib/UefiHandleParsingLib.inf
      PrintLib|MdePkg/Library/BasePrintLib/BasePrintLib.inf
      BcfgCommandLib|ShellPkg/Library/UefiShellBcfgCommandLib/UefiShellBcfgCommandLib.inf

    <PcdsFixedAtBuild>
      gEfiMdePkgTokenSpaceGuid.PcdDebugPropertyMask|0xFF
      gEfiShellPkgTokenSpaceGuid.PcdShellLibAutoInitialize|FALSE
      gEfiMdePkgTokenSpaceGuid.PcdUefiLibMaxPrintBufferSize|8000
  }
```

To build the `AcpiView` into OVMF, use the following commands:

```sh
# Using GCC5
build -p ShellPkg/ShellPkg.dsc -m ShellPkg/Application/Shell/Shell.inf -t GCC5 -a X64 -b RELEASE -d ACPIVIEW_ENABLE

# Using Visual Studio 2022
build -p ShellPkg/ShellPkg.dsc -m ShellPkg/Application/Shell/Shell.inf -t VS2022 -a X64 -b RELEASE -d ACPIVIEW_ENABLE
```

This ensures `AcpiView` is available in the default UEFI Shell environment.

