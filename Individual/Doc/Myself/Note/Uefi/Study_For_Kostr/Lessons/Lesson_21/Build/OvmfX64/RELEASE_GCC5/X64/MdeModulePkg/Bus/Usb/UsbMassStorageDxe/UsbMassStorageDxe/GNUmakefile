#
# DO NOT EDIT
# This file is auto-generated by build utility
#
# Module Name:
#
#   GNUmakefile
#
# Abstract:
#
#   Auto-generated makefile for building modules, libraries or platform
#
    

#
# Platform Macro Definition
#
PLATFORM_NAME = Ovmf
PLATFORM_GUID = 5a9e7754-d81b-49ea-85ad-69eaa7b1539b
PLATFORM_VERSION = 0.1
PLATFORM_RELATIVE_DIR = edk2/OvmfPkg
PLATFORM_DIR = /media/sf_VirtualBoxShare/UEFI/edk2/OvmfPkg
PLATFORM_OUTPUT_DIR = Build/OvmfX64

#
# Module Macro Definition
#
MODULE_NAME = UsbMassStorageDxe
MODULE_GUID = 9FB4B4A7-42C0-4bcd-8540-9BCC6711F83E
MODULE_NAME_GUID = UsbMassStorageDxe
MODULE_VERSION = 1.0
MODULE_TYPE = UEFI_DRIVER
MODULE_FILE = UsbMassStorageDxe.inf
MODULE_FILE_BASE_NAME = UsbMassStorageDxe
BASE_NAME = $(MODULE_NAME)
MODULE_RELATIVE_DIR = MdeModulePkg/Bus/Usb/UsbMassStorageDxe
PACKAGE_RELATIVE_DIR = Bus/Usb/UsbMassStorageDxe
MODULE_DIR = /media/sf_VirtualBoxShare/UEFI/edk2/MdeModulePkg/Bus/Usb/UsbMassStorageDxe
FFS_OUTPUT_DIR = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/FV/Ffs/9FB4B4A7-42C0-4bcd-8540-9BCC6711F83EUsbMassStorageDxe

MODULE_ENTRY_POINT = USBMassStorageEntryPoint
ARCH_ENTRY_POINT = USBMassStorageEntryPoint
IMAGE_ENTRY_POINT = _ModuleEntryPoint

INF_VERSION = 0x00010005
BASE_NAME = UsbMassStorageDxe
MODULE_UNI_FILE = UsbMassStorageDxe.uni
FILE_GUID = 9FB4B4A7-42C0-4bcd-8540-9BCC6711F83E
MODULE_TYPE = UEFI_DRIVER
VERSION_STRING = 1.0

#
# Build Configuration Macro Definition
#
ARCH = X64
TOOLCHAIN = GCC5
TOOLCHAIN_TAG = GCC5
TARGET = RELEASE

#
# Build Directory Macro Definition
#
# PLATFORM_BUILD_DIR = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5
BUILD_DIR = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5
BIN_DIR = $(BUILD_DIR)/X64
LIB_DIR = $(BIN_DIR)
MODULE_BUILD_DIR = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe
OUTPUT_DIR = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/OUTPUT
DEBUG_DIR = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/DEBUG
DEST_DIR_OUTPUT = $(OUTPUT_DIR)
DEST_DIR_DEBUG = $(DEBUG_DIR)

#
# Shell Command Macro
#
CP = cp -p -f
MV = mv -f
RM = rm -f
MD = mkdir -p
RD = rm -r -f


#
# Tools definitions specific to this module
#
APP_FLAGS = 

ASL_FLAGS = 
ASL_OUTFLAGS =  -p
ASL = /media/sf_VirtualBoxShare/UEFI/acpica/generate/unix/bin/iasl

ASLCC_FLAGS = -x c -fno-lto -m64
ASLCC = gcc

ASLDLINK_FLAGS = -nostdlib -Wl,-n,-q,--gc-sections -z common-page-size=0x40 -Wl,--defsym=PECOFF_HEADER_SIZE=0 -Wl,--script=$(EDK_TOOLS_PATH)/Scripts/GccBase.lds -Wl,--entry,ReferenceAcpiTable -u ReferenceAcpiTable -Wl,-m,elf_x86_64
ASLDLINK = gcc

ASLPP_FLAGS = -x c -E -include AutoGen.h
ASLPP = gcc

ASM_FLAGS = -c -x assembler -imacros AutoGen.h -m64
ASM = gcc

ASMLINK_FLAGS = /nologo /tiny
ASMLINK = bin16\link16.exe

BROTLI_GUID =  3D532050-5CDA-4FD0-879E-0F7F630D5AFB
BROTLI = BrotliCompress

CC_FLAGS = -g -Os -fshort-wchar -fno-builtin -fno-strict-aliasing -Wall -Werror -Wno-array-bounds -include AutoGen.h -fno-common -fstack-protector -ffunction-sections -fdata-sections -DSTRING_ARRAY_NAME=$(BASE_NAME)Strings -mstack-protector-guard=global -m64 "-DEFIAPI=__attribute__((ms_abi))" -maccumulate-outgoing-args -mno-red-zone -Wno-address -mcmodel=small -fpie -fno-asynchronous-unwind-tables -Wno-address -fno-omit-frame-pointer -flto -DUSING_LTO -Wno-unused-but-set-variable -Wno-unused-const-variable -DMDEPKG_NDEBUG -mno-mmx -mno-sse -D DISABLE_NEW_DEPRECATED_INTERFACES -D TDX_GUEST_SUPPORTED -D ENABLE_MD5_DEPRECATED_INTERFACES
CC = gcc

CRC32_GUID =  FC1BCDB0-7D31-49AA-936A-A4600D9DD083
CRC32 = GenCrc32

DEPS_FLAGS = -MMD -MF $@.deps

DLINK_FLAGS = -nostdlib -Wl,-n,-q,--gc-sections -z common-page-size=0x40 -Wl,--entry,$(IMAGE_ENTRY_POINT) -u $(IMAGE_ENTRY_POINT) -Wl,-Map,$(DEST_DIR_DEBUG)/$(BASE_NAME).map,--whole-archive -Wl,-melf_x86_64,--oformat=elf64-x86-64,-pie -flto -Os
DLINK = gcc

DLINK2_FLAGS = -Wl,--defsym=PECOFF_HEADER_SIZE=0x228 -Wl,--script=$(EDK_TOOLS_PATH)/Scripts/GccBase.lds -Wno-error

DTC_FLAGS = -H epapr
DTC = dtc

DTCPP = cpp

GENFW_FLAGS = --zero
GENFW = GenFw

LZMA_GUID =  EE4E5898-3914-4259-9D6E-DC7BD79403CF
LZMA = LzmaCompress

LZMAF86_GUID =  D42AE6BD-1352-4bfb-909A-CA72A6EAE889
LZMAF86 = LzmaF86Compress

MAKE = make

NASM_FLAGS = -f elf64
NASM = nasm

NASMB_FLAGS = -f bin

OBJCOPY_ADDDEBUGFLAG =  
OBJCOPY_FLAGS = 
OBJCOPY = objcopy
OBJCOPY_STRIPFLAG =  --strip-unneeded -R .eh_frame

OPTROM_FLAGS = -e
OPTROM = EfiRom

PKCS7SIGN_GUID =  4AAFD29D-68DF-49EE-8AA9-347D375665A7
PKCS7SIGN = Pkcs7Sign

PP_FLAGS = -E -x assembler-with-cpp -include AutoGen.h
PP = gcc

RC_FLAGS = -I binary -O elf64-x86-64 -B i386 --rename-section .data=.hii
RC = objcopy

RSA2048SHA256SIGN_GUID =  A7717414-C616-4977-9420-844712A735BF
RSA2048SHA256SIGN = Rsa2048Sha256Sign

SLINK = gcc-ar

SYMRENAME_FLAGS = Symbol renaming not needed for
SYMRENAME = echo

TIANO_GUID =  A31280AD-481E-41B6-95E8-127F4C984779
TIANO = TianoCompress

VFR_FLAGS = -l -n
VFR = VfrCompile

VFRPP_FLAGS = -x c -E -P -DVFRCOMPILE --include $(MODULE_NAME)StrDefs.h
VFRPP = gcc

VPDTOOL_GUID =  8C3D856A-9BE6-468E-850A-24F7A8D38E08
VPDTOOL = BPDG


MAKE_FILE = $(MODULE_BUILD_DIR)/GNUmakefile

#
# Build Macro
#
OBJECT_FILES =  \
    $(OUTPUT_DIR)/AutoGen.obj \
    $(OUTPUT_DIR)/ComponentName.obj \
    $(OUTPUT_DIR)/UsbMassBoot.obj \
    $(OUTPUT_DIR)/UsbMassBot.obj \
    $(OUTPUT_DIR)/UsbMassCbi.obj \
    $(OUTPUT_DIR)/UsbMassDiskInfo.obj \
    $(OUTPUT_DIR)/UsbMassImpl.obj

STATIC_LIBRARY_FILES =  \
    $(BIN_DIR)/MdePkg/Library/BaseDebugPrintErrorLevelLib/BaseDebugPrintErrorLevelLib/OUTPUT/BaseDebugPrintErrorLevelLib.lib \
    $(BIN_DIR)/MdePkg/Library/BaseIoLibIntrinsic/BaseIoLibIntrinsicSev/OUTPUT/BaseIoLibIntrinsicSev.lib \
    $(BIN_DIR)/MdePkg/Library/BaseLib/BaseLib/OUTPUT/BaseLib.lib \
    $(BIN_DIR)/MdePkg/Library/BaseMemoryLibRepStr/BaseMemoryLibRepStr/OUTPUT/BaseMemoryLibRepStr.lib \
    $(BIN_DIR)/MdePkg/Library/BasePrintLib/BasePrintLib/OUTPUT/BasePrintLib.lib \
    $(BIN_DIR)/MdePkg/Library/DxePcdLib/DxePcdLib/OUTPUT/DxePcdLib.lib \
    $(BIN_DIR)/MdePkg/Library/RegisterFilterLibNull/RegisterFilterLibNull/OUTPUT/FilterLibNull.lib \
    $(BIN_DIR)/MdePkg/Library/StackCheckLibNull/StackCheckLibNull/OUTPUT/StackCheckLibNull.lib \
    $(BIN_DIR)/MdePkg/Library/TdxLib/TdxLib/OUTPUT/TdxLib.lib \
    $(BIN_DIR)/MdePkg/Library/UefiBootServicesTableLib/UefiBootServicesTableLib/OUTPUT/UefiBootServicesTableLib.lib \
    $(BIN_DIR)/MdePkg/Library/UefiDevicePathLibDevicePathProtocol/UefiDevicePathLibDevicePathProtocol/OUTPUT/UefiDevicePathLibDevicePathProtocol.lib \
    $(BIN_DIR)/MdePkg/Library/UefiLib/UefiLib/OUTPUT/UefiLib.lib \
    $(BIN_DIR)/MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib/OUTPUT/UefiMemoryAllocationLib.lib \
    $(BIN_DIR)/MdePkg/Library/UefiRuntimeServicesTableLib/UefiRuntimeServicesTableLib/OUTPUT/UefiRuntimeServicesTableLib.lib \
    $(BIN_DIR)/OvmfPkg/Library/CcProbeLib/DxeCcProbeLib/OUTPUT/DxeCcProbeLib.lib \
    $(BIN_DIR)/OvmfPkg/Library/PlatformDebugLibIoPort/PlatformDebugLibIoPort/OUTPUT/PlatformDebugLibIoPort.lib \
    $(BIN_DIR)/OvmfPkg/Library/QemuFwCfgLib/QemuFwCfgDxeLib/OUTPUT/QemuFwCfgDxeLib.lib \
    $(BIN_DIR)/OvmfPkg/Library/QemuFwCfgSimpleParserLib/QemuFwCfgSimpleParserLib/OUTPUT/QemuFwCfgSimpleParserLib.lib \
    $(BIN_DIR)/OvmfPkg/Library/UefiDriverEntryPointFwCfgOverrideLib/UefiDriverEntryPointFwCfgOverrideLib/OUTPUT/UefiDriverEntryPointFwCfgOverrideLib.lib \
    $(OUTPUT_DIR)/UsbMassStorageDxe.lib

INC =  \
    -I$(WORKSPACE)/edk2/MdeModulePkg/Bus/Usb/UsbMassStorageDxe \
    -I$(DEBUG_DIR) \
    -I$(WORKSPACE)/edk2/MdePkg \
    -I$(WORKSPACE)/edk2/MdePkg/Include \
    -I$(WORKSPACE)/edk2/MdePkg/Test/UnitTest/Include \
    -I$(WORKSPACE)/edk2/MdePkg/Test/Mock/Include \
    -I$(WORKSPACE)/edk2/MdePkg/Library/MipiSysTLib/mipisyst/library/include \
    -I$(WORKSPACE)/edk2/MdePkg/Include/X64

OBJECT_FILES_LIST = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/OUTPUT/object_files.lst
STATIC_LIBRARY_FILES_LIST = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/OUTPUT/static_library_files.lst


#
# Overridable Target Macro Definitions
#
FORCE_REBUILD = force_build
INIT_TARGET = init
PCH_TARGET =
BC_TARGET = 
CODA_TARGET = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/OUTPUT/UsbMassStorageDxe.efi \
              $(FFS_OUTPUT_DIR)/$(MODULE_GUID).map \
              $(FFS_OUTPUT_DIR)/$(MODULE_GUID).ffs \
              

#
# Default target, which will build dependent libraries in addition to source files
#

all: mbuild


#
# Target used when called from platform makefile, which will bypass the build of dependent libraries
#

pbuild: $(INIT_TARGET) $(BC_TARGET) $(PCH_TARGET) $(CODA_TARGET)

#
# ModuleTarget
#

mbuild: $(INIT_TARGET) $(BC_TARGET) gen_libs $(PCH_TARGET) $(CODA_TARGET)

#
# Build Target used in multi-thread build mode, which will bypass the init and gen_libs targets
#

tbuild: $(BC_TARGET) $(PCH_TARGET) $(CODA_TARGET)

#
# Phony target which is used to force executing commands for a target
#
force_build:
	-@

#
# Target to update the FD
#

fds: mbuild gen_fds

#
# Initialization target: print build information and create necessary directories
#
init: info dirs

info:
	-@echo Building ... $(MODULE_DIR)/$(MODULE_FILE) [$(ARCH)]

dirs:
	-@$(MD) $(DEBUG_DIR)
	-@$(MD) $(OUTPUT_DIR)


strdefs:
	-@$(CP) $(DEBUG_DIR)/AutoGen.h $(DEBUG_DIR)/$(MODULE_NAME)StrDefs.h

#
# GenLibsTarget
#
gen_libs:
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/RegisterFilterLibNull/RegisterFilterLibNull/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/DxePcdLib/DxePcdLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseMemoryLibRepStr/BaseMemoryLibRepStr/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseLib/BaseLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/TdxLib/TdxLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseDebugPrintErrorLevelLib/BaseDebugPrintErrorLevelLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BasePrintLib/BasePrintLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseIoLibIntrinsic/BaseIoLibIntrinsicSev/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/PlatformDebugLibIoPort/PlatformDebugLibIoPort/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/CcProbeLib/DxeCcProbeLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/UefiBootServicesTableLib/UefiBootServicesTableLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/QemuFwCfgLib/QemuFwCfgDxeLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/UefiRuntimeServicesTableLib/UefiRuntimeServicesTableLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/UefiDevicePathLibDevicePathProtocol/UefiDevicePathLibDevicePathProtocol/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/QemuFwCfgSimpleParserLib/QemuFwCfgSimpleParserLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/UefiLib/UefiLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/UefiDriverEntryPointFwCfgOverrideLib/UefiDriverEntryPointFwCfgOverrideLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/StackCheckLibNull/StackCheckLibNull/GNUmakefile
	@cd $(MODULE_BUILD_DIR)

#
# Build Flash Device Image
#
gen_fds:
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BUILD_DIR)/GNUmakefile fds
	@cd $(MODULE_BUILD_DIR)

include $(MODULE_BUILD_DIR)/dependency
include $(MODULE_BUILD_DIR)/deps_target

#
# Individual Object Build Targets
#
$(OUTPUT_DIR)/UsbMassCbi.obj : $(MAKE_FILE)
$(OUTPUT_DIR)/UsbMassCbi.obj : $(DEBUG_DIR)/AutoGen.h
$(OUTPUT_DIR)/UsbMassCbi.obj : $(WORKSPACE)/edk2/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassCbi.c
	"$(CC)" $(DEPS_FLAGS) $(CC_FLAGS) -c -o /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/OUTPUT/./UsbMassCbi.obj $(INC) /media/sf_VirtualBoxShare/UEFI/edk2/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassCbi.c

$(OUTPUT_DIR)/AutoGen.obj : $(MAKE_FILE)
$(OUTPUT_DIR)/AutoGen.obj : $(DEBUG_DIR)/AutoGen.h
$(OUTPUT_DIR)/AutoGen.obj : $(DEBUG_DIR)/AutoGen.c
	"$(CC)" $(DEPS_FLAGS) $(CC_FLAGS) -c -o /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/OUTPUT/./AutoGen.obj $(INC) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/DEBUG/AutoGen.c

$(OUTPUT_DIR)/UsbMassImpl.obj : $(MAKE_FILE)
$(OUTPUT_DIR)/UsbMassImpl.obj : $(DEBUG_DIR)/AutoGen.h
$(OUTPUT_DIR)/UsbMassImpl.obj : $(WORKSPACE)/edk2/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassImpl.c
	"$(CC)" $(DEPS_FLAGS) $(CC_FLAGS) -c -o /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/OUTPUT/./UsbMassImpl.obj $(INC) /media/sf_VirtualBoxShare/UEFI/edk2/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassImpl.c

$(OUTPUT_DIR)/UsbMassBot.obj : $(MAKE_FILE)
$(OUTPUT_DIR)/UsbMassBot.obj : $(DEBUG_DIR)/AutoGen.h
$(OUTPUT_DIR)/UsbMassBot.obj : $(WORKSPACE)/edk2/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassBot.c
	"$(CC)" $(DEPS_FLAGS) $(CC_FLAGS) -c -o /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/OUTPUT/./UsbMassBot.obj $(INC) /media/sf_VirtualBoxShare/UEFI/edk2/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassBot.c

$(OUTPUT_DIR)/UsbMassDiskInfo.obj : $(MAKE_FILE)
$(OUTPUT_DIR)/UsbMassDiskInfo.obj : $(DEBUG_DIR)/AutoGen.h
$(OUTPUT_DIR)/UsbMassDiskInfo.obj : $(WORKSPACE)/edk2/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassDiskInfo.c
	"$(CC)" $(DEPS_FLAGS) $(CC_FLAGS) -c -o /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/OUTPUT/./UsbMassDiskInfo.obj $(INC) /media/sf_VirtualBoxShare/UEFI/edk2/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassDiskInfo.c

$(OUTPUT_DIR)/ComponentName.obj : $(MAKE_FILE)
$(OUTPUT_DIR)/ComponentName.obj : $(DEBUG_DIR)/AutoGen.h
$(OUTPUT_DIR)/ComponentName.obj : $(WORKSPACE)/edk2/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/ComponentName.c
	"$(CC)" $(DEPS_FLAGS) $(CC_FLAGS) -c -o /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/OUTPUT/./ComponentName.obj $(INC) /media/sf_VirtualBoxShare/UEFI/edk2/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/ComponentName.c

$(OUTPUT_DIR)/UsbMassBoot.obj : $(MAKE_FILE)
$(OUTPUT_DIR)/UsbMassBoot.obj : $(DEBUG_DIR)/AutoGen.h
$(OUTPUT_DIR)/UsbMassBoot.obj : $(WORKSPACE)/edk2/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassBoot.c
	"$(CC)" $(DEPS_FLAGS) $(CC_FLAGS) -c -o /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/OUTPUT/./UsbMassBoot.obj $(INC) /media/sf_VirtualBoxShare/UEFI/edk2/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassBoot.c

$(OUTPUT_DIR)/UsbMassStorageDxe.lib : $(OBJECT_FILES)
$(OUTPUT_DIR)/UsbMassStorageDxe.lib : $(OBJECT_FILES_LIST)
	$(RM) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/OUTPUT/UsbMassStorageDxe.lib
	"$(SLINK)" cr /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/OUTPUT/UsbMassStorageDxe.lib $(SLINK_FLAGS) @$(OBJECT_FILES_LIST)

$(DEBUG_DIR)/UsbMassStorageDxe.dll : $(MAKE_FILE)
$(DEBUG_DIR)/UsbMassStorageDxe.dll : $(STATIC_LIBRARY_FILES)
$(DEBUG_DIR)/UsbMassStorageDxe.dll : $(STATIC_LIBRARY_FILES_LIST)
	"$(DLINK)" -o /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/DEBUG/UsbMassStorageDxe.dll $(DLINK_FLAGS) -Wl,--start-group,@$(STATIC_LIBRARY_FILES_LIST),--end-group $(CC_FLAGS) $(DLINK2_FLAGS)
	"$(OBJCOPY)" $(OBJCOPY_FLAGS) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/DEBUG/UsbMassStorageDxe.dll

$(OUTPUT_DIR)/UsbMassStorageDxe.efi : $(DEBUG_DIR)/UsbMassStorageDxe.dll
	$(CP) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/DEBUG/UsbMassStorageDxe.dll $(DEBUG_DIR)/$(MODULE_NAME).debug
	"$(OBJCOPY)" $(OBJCOPY_STRIPFLAG) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/DEBUG/UsbMassStorageDxe.dll
	-"$(OBJCOPY)" $(OBJCOPY_ADDDEBUGFLAG) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/DEBUG/UsbMassStorageDxe.dll
	-$(CP) $(DEBUG_DIR)/$(MODULE_NAME).debug $(BIN_DIR)/$(MODULE_NAME_GUID).debug
	"$(GENFW)" -e $(MODULE_TYPE) -o /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/OUTPUT/UsbMassStorageDxe.efi /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/DEBUG/UsbMassStorageDxe.dll $(GENFW_FLAGS)
	$(CP) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/OUTPUT/UsbMassStorageDxe.efi $(DEBUG_DIR)
	$(CP) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe/OUTPUT/UsbMassStorageDxe.efi $(BIN_DIR)/$(MODULE_NAME_GUID).efi
	-$(CP) $(DEBUG_DIR)/*.map $(OUTPUT_DIR)

$(OUTPUT_DIR)/UsbMassStorageDxe.map : $(OUTPUT_DIR)/UsbMassStorageDxe.efi
	

$(FFS_OUTPUT_DIR)/$(MODULE_GUID).map : $(OUTPUT_DIR)/UsbMassStorageDxe.map
	test -f $(OUTPUT_DIR)/UsbMassStorageDxe.map && $(CP) $(OUTPUT_DIR)/UsbMassStorageDxe.map $(FFS_OUTPUT_DIR)/$(MODULE_GUID).map
$(FFS_OUTPUT_DIR)/$(MODULE_GUID).ffs : $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC1.1.dpx $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC2.1.pe32 $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC3.ui $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC4.ver
	GenFfs -t EFI_FV_FILETYPE_DRIVER -g $(MODULE_GUID) -o $(FFS_OUTPUT_DIR)/$(MODULE_GUID).ffs -oi $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC1.1.dpx -oi $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC2.1.pe32 -oi $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC3.ui -oi $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC4.ver
$(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC1.1.dpx : $(OUTPUT_DIR)/UsbMassStorageDxe.depex
	-test -e $(OUTPUT_DIR)/UsbMassStorageDxe.depex && GenSec -s EFI_SECTION_DXE_DEPEX -o $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC1.1.dpx $(OUTPUT_DIR)/UsbMassStorageDxe.depex
$(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC2.1.pe32 : $(OUTPUT_DIR)/UsbMassStorageDxe.efi
	-test -e $(OUTPUT_DIR)/UsbMassStorageDxe.efi && GenSec -s EFI_SECTION_PE32 -o $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC2.1.pe32 $(OUTPUT_DIR)/UsbMassStorageDxe.efi
$(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC3.ui : $(MODULE_DIR)/$(MODULE_FILE)
	GenSec -s EFI_SECTION_USER_INTERFACE -n $(MODULE_NAME) -o $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC3.ui
$(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC4.ver : $(MODULE_DIR)/$(MODULE_FILE)
	GenSec -s EFI_SECTION_VERSION -n 1.0 -o $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC4.ver


#
# clean all intermediate files
#
clean:
	$(RD) $(OUTPUT_DIR)
		$(RM) AutoGenTimeStamp

#
# clean all generated files
#
cleanall:
	$(RD) $(DEBUG_DIR)
	$(RD) $(OUTPUT_DIR)
	$(RM) *.pdb *.idb > NUL 2>&1
	$(RM) $(BIN_DIR)/$(MODULE_NAME).efi
	$(RM) AutoGenTimeStamp

#
# clean all dependent libraries built
#
cleanlib:
	-@test -e $(BIN_DIR)/MdePkg/Library/RegisterFilterLibNull/RegisterFilterLibNull/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/RegisterFilterLibNull/RegisterFilterLibNull/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/DxePcdLib/DxePcdLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/DxePcdLib/DxePcdLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/BaseMemoryLibRepStr/BaseMemoryLibRepStr/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseMemoryLibRepStr/BaseMemoryLibRepStr/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/BaseLib/BaseLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseLib/BaseLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/TdxLib/TdxLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/TdxLib/TdxLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/BaseDebugPrintErrorLevelLib/BaseDebugPrintErrorLevelLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseDebugPrintErrorLevelLib/BaseDebugPrintErrorLevelLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/BasePrintLib/BasePrintLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BasePrintLib/BasePrintLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/BaseIoLibIntrinsic/BaseIoLibIntrinsicSev/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseIoLibIntrinsic/BaseIoLibIntrinsicSev/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/OvmfPkg/Library/PlatformDebugLibIoPort/PlatformDebugLibIoPort/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/PlatformDebugLibIoPort/PlatformDebugLibIoPort/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/OvmfPkg/Library/CcProbeLib/DxeCcProbeLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/CcProbeLib/DxeCcProbeLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/UefiBootServicesTableLib/UefiBootServicesTableLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/UefiBootServicesTableLib/UefiBootServicesTableLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/OvmfPkg/Library/QemuFwCfgLib/QemuFwCfgDxeLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/QemuFwCfgLib/QemuFwCfgDxeLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/UefiRuntimeServicesTableLib/UefiRuntimeServicesTableLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/UefiRuntimeServicesTableLib/UefiRuntimeServicesTableLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/UefiDevicePathLibDevicePathProtocol/UefiDevicePathLibDevicePathProtocol/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/UefiDevicePathLibDevicePathProtocol/UefiDevicePathLibDevicePathProtocol/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/OvmfPkg/Library/QemuFwCfgSimpleParserLib/QemuFwCfgSimpleParserLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/QemuFwCfgSimpleParserLib/QemuFwCfgSimpleParserLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/UefiLib/UefiLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/UefiLib/UefiLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/OvmfPkg/Library/UefiDriverEntryPointFwCfgOverrideLib/UefiDriverEntryPointFwCfgOverrideLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/UefiDriverEntryPointFwCfgOverrideLib/UefiDriverEntryPointFwCfgOverrideLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/StackCheckLibNull/StackCheckLibNull/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/StackCheckLibNull/StackCheckLibNull/GNUmakefile cleanall
	@cd $(MODULE_BUILD_DIR)

