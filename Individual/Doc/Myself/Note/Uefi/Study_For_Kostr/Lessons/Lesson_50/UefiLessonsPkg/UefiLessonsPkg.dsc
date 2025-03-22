[Defines]
  PLATFORM_NAME                  = UefiLessonsPkg
  PLATFORM_GUID                  = 3db7270f-ffac-4139-90a4-0ae68f3f8167
  PLATFORM_VERSION               = 0.01
  DSC_SPECIFICATION              = 0x00010006
  OUTPUT_DIRECTORY               = Build/UefiLessonsPkg
  SUPPORTED_ARCHITECTURES        = X64
  BUILD_TARGETS                  = RELEASE
  SKUID_IDENTIFIER               = DEFAULT

[LibraryClasses]
  BaseLib|MdePkg/Library/BaseLib/BaseLib.inf
  BaseMemoryLib|MdePkg/Library/BaseMemoryLib/BaseMemoryLib.inf
  CommonLib|SamModulePkg/SamLib/Library/CommonLib/CommonLib.inf
  DebugLib|MdePkg/Library/UefiDebugLibConOut/UefiDebugLibConOut.inf
  DebugPrintErrorLevelLib|MdePkg/Library/BaseDebugPrintErrorLevelLib/BaseDebugPrintErrorLevelLib.inf
  DevicePathLib|MdePkg/Library/UefiDevicePathLib/UefiDevicePathLib.inf
  FileHandleLib|MdePkg/Library/UefiFileHandleLib/UefiFileHandleLib.inf
  HiiLib|MdeModulePkg/Library/UefiHiiLib/UefiHiiLib.inf
  MemoryAllocationLib|MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib.inf
  PcdLib|MdePkg/Library/BasePcdLibNull/BasePcdLibNull.inf
  PrintLib|MdePkg/Library/BasePrintLib/BasePrintLib.inf
  RegisterFilterLib|MdePkg/Library/RegisterFilterLibNull/RegisterFilterLibNull.inf
  ShellCEntryLib|ShellPkg/Library/UefiShellCEntryLib/UefiShellCEntryLib.inf
  ShellLib|ShellPkg/Library/UefiShellLib/UefiShellLib.inf
  # SimpleLibrary|UefiLessonsPkg/Library/SimpleLibrary/SimpleLibrary.inf                                # Lesson35 created, override in Lesson36
  # SimpleLibrary|UefiLessonsPkg/Library/SimpleLibraryWithConstructor/SimpleLibraryWithConstructor.inf  # Lesson36 created with step1, override in Lesson36 with step2
  SimpleLibrary|UefiLessonsPkg/Library/SimpleLibraryWithConstructorAndDestructor/SimpleLibraryWithConstructorAndDestructor.inf
  SortLib|MdeModulePkg/Library/UefiSortLib/UefiSortLib.inf
  UefiApplicationEntryPoint|MdePkg/Library/UefiApplicationEntryPoint/UefiApplicationEntryPoint.inf
  UefiBootServicesTableLib|MdePkg/Library/UefiBootServicesTableLib/UefiBootServicesTableLib.inf
  UefiDriverEntryPoint|MdePkg/Library/UefiDriverEntryPoint/UefiDriverEntryPoint.inf
  UefiLib|MdePkg/Library/UefiLib/UefiLib.inf
  UefiHiiServicesLib|MdeModulePkg/Library/UefiHiiServicesLib/UefiHiiServicesLib.inf
  UefiRuntimeServicesTableLib|MdePkg/Library/UefiRuntimeServicesTableLib/UefiRuntimeServicesTableLib.inf

[Components]
  UefiLessonsPkg/AcpiInfo/AcpiInfo.inf
  UefiLessonsPkg/Debug/HIIDebug/HIIDebug.inf
  UefiLessonsPkg/HelloWorld/HelloWorld.inf
  UefiLessonsPkg/HIIStringsC/HIIStringsC.inf
  UefiLessonsPkg/HIIStringsUNI/HIIStringsUNI.inf
  UefiLessonsPkg/HIIStringsUNIRC/HIIStringsUNIRC.inf
  UefiLessonsPkg/HotKeyDriver/HotKeyDriver.inf
  UefiLessonsPkg/ImageHandle/ImageHandle.inf
  UefiLessonsPkg/ImageInfo/ImageInfo.inf
  UefiLessonsPkg/InteractiveApp/InteractiveApp.inf
  UefiLessonsPkg/Library/SimpleLibrary/SimpleLibrary.inf
  UefiLessonsPkg/ListPCI/ListPCI.inf
  UefiLessonsPkg/MemoryInfo/MemoryInfo.inf
  UefiLessonsPkg/PCDLesson/PCDLesson.inf {
    # DSC in-module overrides
    <PcdsFixedAtBuild>
    gUefiLessonsPkgTokenSpaceGuid.PcdInt32Override|48
  }
  UefiLessonsPkg/PCIRomInfo/PCIRomInfo.inf
  UefiLessonsPkg/ShowBootVariables/ShowBootVariables.inf
  UefiLessonsPkg/SaveBGRT/SaveBGRT.inf
  UefiLessonsPkg/ShowHII/ShowHII.inf
  UefiLessonsPkg/ShowTables/ShowTables.inf
  UefiLessonsPkg/SimpleClassProtocol/SimpleClassProtocol.inf
  UefiLessonsPkg/SimpleClassUser/SimpleClassUser.inf
  UefiLessonsPkg/SimpleDriver/SimpleDriver.inf
  UefiLessonsPkg/SimpleLibraryUser/SimpleLibraryUser.inf
  UefiLessonsPkg/SimplestApp/SimplestApp.inf
  UefiLessonsPkg/SimpleShellApp/SimpleShellApp.inf
  UefiLessonsPkg/SmbiosInfo/SmbiosInfo.inf

[PcdsFixedAtBuild]
  # DSC override PCDs
  gUefiLessonsPkgTokenSpaceGuid.PcdInt32Override|44

[BuildOptions]
  # Avoid: error LNK2001: unresolved external symbol __security_check_cookie
  MSFT:*_*_*_CC_FLAGS = /GS-

  # Avoid: undefined reference to `__stack_chk_guard'
  # Avoid: undefined reference to `__stack_chk_fail'
  GCC:*_*_*_CC_FLAGS = -fno-stack-protector
