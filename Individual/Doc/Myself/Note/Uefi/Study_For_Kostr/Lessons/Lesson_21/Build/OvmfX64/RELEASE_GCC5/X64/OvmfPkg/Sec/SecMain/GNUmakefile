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
MODULE_NAME = SecMain
MODULE_GUID = df1ccef6-f301-4a63-9661-fc6030dcc880
MODULE_NAME_GUID = SecMain
MODULE_VERSION = 1.0
MODULE_TYPE = SEC
MODULE_FILE = SecMain.inf
MODULE_FILE_BASE_NAME = SecMain
BASE_NAME = $(MODULE_NAME)
MODULE_RELATIVE_DIR = OvmfPkg/Sec
PACKAGE_RELATIVE_DIR = Sec
MODULE_DIR = /media/sf_VirtualBoxShare/UEFI/edk2/OvmfPkg/Sec
FFS_OUTPUT_DIR = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/FV/Ffs/df1ccef6-f301-4a63-9661-fc6030dcc880SecMain

MODULE_ENTRY_POINT = SecMain
ARCH_ENTRY_POINT = SecMain
IMAGE_ENTRY_POINT = _ModuleEntryPoint

INF_VERSION = 1.30
BASE_NAME = SecMain
FILE_GUID = df1ccef6-f301-4a63-9661-fc6030dcc880
MODULE_TYPE = SEC
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
MODULE_BUILD_DIR = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain
OUTPUT_DIR = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/OUTPUT
DEBUG_DIR = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/DEBUG
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
    $(OUTPUT_DIR)/AmdSev.obj \
    $(OUTPUT_DIR)/AutoGen.obj \
    $(OUTPUT_DIR)/SecMain.obj \
    $(OUTPUT_DIR)/X64/SecEntry.obj

STATIC_LIBRARY_FILES =  \
    $(BIN_DIR)/CryptoPkg/Library/BaseCryptLib/SecCryptLib/OUTPUT/SecCryptLib.lib \
    $(BIN_DIR)/CryptoPkg/Library/IntrinsicLib/IntrinsicLib/OUTPUT/BaseIntrinsicLib.lib \
    $(BIN_DIR)/CryptoPkg/Library/OpensslLib/OpensslLibCrypto/OUTPUT/OpensslLibCrypto.lib \
    $(BIN_DIR)/MdeModulePkg/Library/BaseRngLibTimerLib/BaseRngLibTimerLib/OUTPUT/BaseRngLibTimerLib.lib \
    $(BIN_DIR)/MdeModulePkg/Library/DebugAgentLibNull/DebugAgentLibNull/OUTPUT/DebugAgentLibNull.lib \
    $(BIN_DIR)/MdeModulePkg/Library/LzmaCustomDecompressLib/LzmaCustomDecompressLib/OUTPUT/LzmaDecompressLib.lib \
    $(BIN_DIR)/MdePkg/Library/BaseCpuLib/BaseCpuLib/OUTPUT/BaseCpuLib.lib \
    $(BIN_DIR)/MdePkg/Library/BaseDebugPrintErrorLevelLib/BaseDebugPrintErrorLevelLib/OUTPUT/BaseDebugPrintErrorLevelLib.lib \
    $(BIN_DIR)/MdePkg/Library/BaseExtractGuidedSectionLib/BaseExtractGuidedSectionLib/OUTPUT/BaseExtractGuidedSectionLib.lib \
    $(BIN_DIR)/MdePkg/Library/BaseIoLibIntrinsic/BaseIoLibIntrinsicSev/OUTPUT/BaseIoLibIntrinsicSev.lib \
    $(BIN_DIR)/MdePkg/Library/BaseLib/BaseLib/OUTPUT/BaseLib.lib \
    $(BIN_DIR)/MdePkg/Library/BaseMemoryLibRepStr/BaseMemoryLibRepStr/OUTPUT/BaseMemoryLibRepStr.lib \
    $(BIN_DIR)/MdePkg/Library/BasePcdLibNull/BasePcdLibNull/OUTPUT/BasePcdLibNull.lib \
    $(BIN_DIR)/MdePkg/Library/BasePciCf8Lib/BasePciCf8Lib/OUTPUT/BasePciCf8Lib.lib \
    $(BIN_DIR)/MdePkg/Library/BasePciLibCf8/BasePciLibCf8/OUTPUT/BasePciLibCf8.lib \
    $(BIN_DIR)/MdePkg/Library/BasePeCoffExtraActionLibNull/BasePeCoffExtraActionLibNull/OUTPUT/PeCoffExtraActionLibNull.lib \
    $(BIN_DIR)/MdePkg/Library/BasePeCoffGetEntryPointLib/BasePeCoffGetEntryPointLib/OUTPUT/BasePeCoffGetEntryPointLib.lib \
    $(BIN_DIR)/MdePkg/Library/BasePeCoffLib/BasePeCoffLib/OUTPUT/BasePeCoffLib.lib \
    $(BIN_DIR)/MdePkg/Library/BasePrintLib/BasePrintLib/OUTPUT/BasePrintLib.lib \
    $(BIN_DIR)/MdePkg/Library/BaseSynchronizationLib/BaseSynchronizationLib/OUTPUT/BaseSynchronizationLib.lib \
    $(BIN_DIR)/MdePkg/Library/PeiHobLib/PeiHobLib/OUTPUT/PeiHobLib.lib \
    $(BIN_DIR)/MdePkg/Library/PeiMemoryAllocationLib/PeiMemoryAllocationLib/OUTPUT/PeiMemoryAllocationLib.lib \
    $(BIN_DIR)/MdePkg/Library/PeiServicesLib/PeiServicesLib/OUTPUT/PeiServicesLib.lib \
    $(BIN_DIR)/MdePkg/Library/PeiServicesTablePointerLibIdt/PeiServicesTablePointerLibIdt/OUTPUT/PeiServicesTablePointerLibIdt.lib \
    $(BIN_DIR)/MdePkg/Library/RegisterFilterLibNull/RegisterFilterLibNull/OUTPUT/FilterLibNull.lib \
    $(BIN_DIR)/MdePkg/Library/StackCheckLibNull/StackCheckLibNull/OUTPUT/StackCheckLibNull.lib \
    $(BIN_DIR)/MdePkg/Library/TdxLib/TdxLib/OUTPUT/TdxLib.lib \
    $(BIN_DIR)/OvmfPkg/IntelTdx/TdxHelperLib/SecTdxHelperLib/OUTPUT/SecTdxHelperLib.lib \
    $(BIN_DIR)/OvmfPkg/IntelTdx/TdxMeasurementLib/SecPeiTdxMeasurementLib/OUTPUT/SecPeiTdxMeasurementLib.lib \
    $(BIN_DIR)/OvmfPkg/Library/AcpiTimerLib/BaseRomAcpiTimerLib/OUTPUT/BaseRomAcpiTimerLib.lib \
    $(BIN_DIR)/OvmfPkg/Library/AmdSvsmLib/AmdSvsmLib/OUTPUT/AmdSvsmLib.lib \
    $(BIN_DIR)/OvmfPkg/Library/BaseMemEncryptSevLib/SecMemEncryptSevLib/OUTPUT/SecMemEncryptSevLib.lib \
    $(BIN_DIR)/OvmfPkg/Library/CcExitLib/SecCcExitLib/OUTPUT/SecCcExitLib.lib \
    $(BIN_DIR)/OvmfPkg/Library/CcProbeLib/SecPeiCcProbeLib/OUTPUT/SecPeiCcProbeLib.lib \
    $(BIN_DIR)/OvmfPkg/Library/PlatformDebugLibIoPort/PlatformRomDebugLibIoPort/OUTPUT/PlatformRomDebugLibIoPort.lib \
    $(BIN_DIR)/OvmfPkg/Library/TdxMailboxLib/TdxMailboxLib/OUTPUT/TdxMailboxLib.lib \
    $(BIN_DIR)/PcAtChipsetPkg/Library/SerialIoLib/SerialIoLib/OUTPUT/PcAtSerialPortLib.lib \
    $(BIN_DIR)/UefiCpuPkg/Library/BaseXApicX2ApicLib/BaseXApicX2ApicLib/OUTPUT/BaseXApicX2ApicLib.lib \
    $(BIN_DIR)/UefiCpuPkg/Library/CpuExceptionHandlerLib/SecPeiCpuExceptionHandlerLib/OUTPUT/SecPeiCpuExceptionHandlerLib.lib \
    $(BIN_DIR)/UefiCpuPkg/Library/CpuPageTableLib/CpuPageTableLib/OUTPUT/CpuPageTableLib.lib \
    $(OUTPUT_DIR)/SecMain.lib

INC =  \
    -I$(WORKSPACE)/edk2/OvmfPkg/Sec/X64 \
    -I$(WORKSPACE)/edk2/OvmfPkg/Sec \
    -I$(DEBUG_DIR) \
    -I$(WORKSPACE)/edk2/MdePkg \
    -I$(WORKSPACE)/edk2/MdePkg/Include \
    -I$(WORKSPACE)/edk2/MdePkg/Test/UnitTest/Include \
    -I$(WORKSPACE)/edk2/MdePkg/Test/Mock/Include \
    -I$(WORKSPACE)/edk2/MdePkg/Library/MipiSysTLib/mipisyst/library/include \
    -I$(WORKSPACE)/edk2/MdePkg/Include/X64 \
    -I$(WORKSPACE)/edk2/MdeModulePkg \
    -I$(WORKSPACE)/edk2/MdeModulePkg/Include \
    -I$(WORKSPACE)/edk2/MdeModulePkg/Test/Mock/Include \
    -I$(WORKSPACE)/edk2/UefiCpuPkg \
    -I$(WORKSPACE)/edk2/UefiCpuPkg/Include \
    -I$(WORKSPACE)/edk2/OvmfPkg \
    -I$(WORKSPACE)/edk2/OvmfPkg/Include

NASM_INC =  \
    -I$(WORKSPACE)/edk2/OvmfPkg/Sec/X64/ \
    -I$(WORKSPACE)/edk2/OvmfPkg/Sec/ \
    -I$(DEBUG_DIR)/ \
    -I$(WORKSPACE)/edk2/MdePkg/ \
    -I$(WORKSPACE)/edk2/MdePkg/Include/ \
    -I$(WORKSPACE)/edk2/MdePkg/Test/UnitTest/Include/ \
    -I$(WORKSPACE)/edk2/MdePkg/Test/Mock/Include/ \
    -I$(WORKSPACE)/edk2/MdePkg/Library/MipiSysTLib/mipisyst/library/include/ \
    -I$(WORKSPACE)/edk2/MdePkg/Include/X64/ \
    -I$(WORKSPACE)/edk2/MdeModulePkg/ \
    -I$(WORKSPACE)/edk2/MdeModulePkg/Include/ \
    -I$(WORKSPACE)/edk2/MdeModulePkg/Test/Mock/Include/ \
    -I$(WORKSPACE)/edk2/UefiCpuPkg/ \
    -I$(WORKSPACE)/edk2/UefiCpuPkg/Include/ \
    -I$(WORKSPACE)/edk2/OvmfPkg/ \
    -I$(WORKSPACE)/edk2/OvmfPkg/Include/

OBJECT_FILES_LIST = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/OUTPUT/object_files.lst
STATIC_LIBRARY_FILES_LIST = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/OUTPUT/static_library_files.lst
INC_LIST = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/OUTPUT/inc.lst


#
# Overridable Target Macro Definitions
#
FORCE_REBUILD = force_build
INIT_TARGET = init
PCH_TARGET =
BC_TARGET = 
CODA_TARGET = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/OUTPUT/SecMain.efi \
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
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/PeiServicesTablePointerLibIdt/PeiServicesTablePointerLibIdt/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/RegisterFilterLibNull/RegisterFilterLibNull/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/AmdSvsmLib/AmdSvsmLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/CcExitLib/SecCcExitLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/PeiMemoryAllocationLib/PeiMemoryAllocationLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/TdxLib/TdxLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/PeiHobLib/PeiHobLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/CcProbeLib/SecPeiCcProbeLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/BaseMemEncryptSevLib/SecMemEncryptSevLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/UefiCpuPkg/Library/BaseXApicX2ApicLib/BaseXApicX2ApicLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseIoLibIntrinsic/BaseIoLibIntrinsicSev/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseCpuLib/BaseCpuLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BasePcdLibNull/BasePcdLibNull/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/PeiServicesLib/PeiServicesLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseMemoryLibRepStr/BaseMemoryLibRepStr/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseLib/BaseLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseDebugPrintErrorLevelLib/BaseDebugPrintErrorLevelLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BasePrintLib/BasePrintLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/PlatformDebugLibIoPort/PlatformRomDebugLibIoPort/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BasePciCf8Lib/BasePciCf8Lib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BasePciLibCf8/BasePciLibCf8/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/AcpiTimerLib/BaseRomAcpiTimerLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdeModulePkg/Library/BaseRngLibTimerLib/BaseRngLibTimerLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/CryptoPkg/Library/IntrinsicLib/IntrinsicLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/CryptoPkg/Library/OpensslLib/OpensslLibCrypto/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/CryptoPkg/Library/BaseCryptLib/SecCryptLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseSynchronizationLib/BaseSynchronizationLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdeModulePkg/Library/DebugAgentLibNull/DebugAgentLibNull/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BasePeCoffExtraActionLibNull/BasePeCoffExtraActionLibNull/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/PcAtChipsetPkg/Library/SerialIoLib/SerialIoLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BasePeCoffGetEntryPointLib/BasePeCoffGetEntryPointLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseExtractGuidedSectionLib/BaseExtractGuidedSectionLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/IntelTdx/TdxMeasurementLib/SecPeiTdxMeasurementLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/TdxMailboxLib/TdxMailboxLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BasePeCoffLib/BasePeCoffLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/UefiCpuPkg/Library/CpuExceptionHandlerLib/SecPeiCpuExceptionHandlerLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/UefiCpuPkg/Library/CpuPageTableLib/CpuPageTableLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/StackCheckLibNull/StackCheckLibNull/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdeModulePkg/Library/LzmaCustomDecompressLib/LzmaCustomDecompressLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/IntelTdx/TdxHelperLib/SecTdxHelperLib/GNUmakefile
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
$(OUTPUT_DIR)/AutoGen.obj : $(MAKE_FILE)
$(OUTPUT_DIR)/AutoGen.obj : $(DEBUG_DIR)/AutoGen.h
$(OUTPUT_DIR)/AutoGen.obj : $(DEBUG_DIR)/AutoGen.c
	"$(CC)" $(DEPS_FLAGS) $(CC_FLAGS) -c -o /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/OUTPUT/./AutoGen.obj $(INC) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/DEBUG/AutoGen.c

$(OUTPUT_DIR)/SecMain.obj : $(MAKE_FILE)
$(OUTPUT_DIR)/SecMain.obj : $(DEBUG_DIR)/AutoGen.h
$(OUTPUT_DIR)/SecMain.obj : $(WORKSPACE)/edk2/OvmfPkg/Sec/SecMain.c
	"$(CC)" $(DEPS_FLAGS) $(CC_FLAGS) -c -o /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/OUTPUT/./SecMain.obj $(INC) /media/sf_VirtualBoxShare/UEFI/edk2/OvmfPkg/Sec/SecMain.c

$(OUTPUT_DIR)/AmdSev.obj : $(MAKE_FILE)
$(OUTPUT_DIR)/AmdSev.obj : $(DEBUG_DIR)/AutoGen.h
$(OUTPUT_DIR)/AmdSev.obj : $(WORKSPACE)/edk2/OvmfPkg/Sec/AmdSev.c
	"$(CC)" $(DEPS_FLAGS) $(CC_FLAGS) -c -o /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/OUTPUT/./AmdSev.obj $(INC) /media/sf_VirtualBoxShare/UEFI/edk2/OvmfPkg/Sec/AmdSev.c

$(OUTPUT_DIR)/SecMain.lib : $(OBJECT_FILES)
$(OUTPUT_DIR)/SecMain.lib : $(OBJECT_FILES_LIST)
	$(RM) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/OUTPUT/SecMain.lib
	"$(SLINK)" cr /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/OUTPUT/SecMain.lib $(SLINK_FLAGS) @$(OBJECT_FILES_LIST)

$(DEBUG_DIR)/SecMain.dll : $(MAKE_FILE)
$(DEBUG_DIR)/SecMain.dll : $(STATIC_LIBRARY_FILES)
$(DEBUG_DIR)/SecMain.dll : $(STATIC_LIBRARY_FILES_LIST)
	"$(DLINK)" -o /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/DEBUG/SecMain.dll $(DLINK_FLAGS) $(DLINK_XIPFLAGS) -Wl,--start-group,@$(STATIC_LIBRARY_FILES_LIST),--end-group $(CC_FLAGS) $(CC_XIPFLAGS) $(DLINK2_FLAGS)
	"$(OBJCOPY)" $(OBJCOPY_FLAGS) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/DEBUG/SecMain.dll

$(OUTPUT_DIR)/SecMain.efi : $(DEBUG_DIR)/SecMain.dll
	$(CP) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/DEBUG/SecMain.dll $(DEBUG_DIR)/$(MODULE_NAME).debug
	"$(OBJCOPY)" $(OBJCOPY_STRIPFLAG) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/DEBUG/SecMain.dll
	-"$(OBJCOPY)" $(OBJCOPY_ADDDEBUGFLAG) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/DEBUG/SecMain.dll
	-$(CP) $(DEBUG_DIR)/$(MODULE_NAME).debug $(BIN_DIR)/$(MODULE_NAME_GUID).debug
	"$(GENFW)" -e $(MODULE_TYPE) -o /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/OUTPUT/SecMain.efi /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/DEBUG/SecMain.dll $(GENFW_FLAGS)
	$(CP) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/OUTPUT/SecMain.efi $(DEBUG_DIR)
	$(CP) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/OUTPUT/SecMain.efi $(BIN_DIR)/$(MODULE_NAME_GUID).efi
	-$(CP) $(DEBUG_DIR)/*.map $(OUTPUT_DIR)

$(OUTPUT_DIR)/SecMain.map : $(OUTPUT_DIR)/SecMain.efi
	

$(OUTPUT_DIR)/X64/SecEntry.obj : $(MAKE_FILE)
$(OUTPUT_DIR)/X64/SecEntry.obj : $(DEBUG_DIR)/AutoGen.h
$(OUTPUT_DIR)/X64/SecEntry.obj : $(WORKSPACE)/edk2/OvmfPkg/Sec/X64/SecEntry.nasm
	Trim --asm-file -o /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/OUTPUT/X64/SecEntry.i -i $(INC_LIST) /media/sf_VirtualBoxShare/UEFI/edk2/OvmfPkg/Sec/X64/SecEntry.nasm
	"$(PP)" $(DEPS_FLAGS) $(PP_FLAGS) $(INC) /media/sf_VirtualBoxShare/UEFI/edk2/OvmfPkg/Sec/X64/SecEntry.nasm > /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/OUTPUT/X64/SecEntry.ii
	Trim --trim-long --source-code -o /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/OUTPUT/X64/SecEntry.iii /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/OUTPUT/X64/SecEntry.ii
	"$(NASM)" -I/media/sf_VirtualBoxShare/UEFI/edk2/OvmfPkg/Sec/X64/ $(NASM_INC) $(NASM_FLAGS) -o /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/OUTPUT/X64/SecEntry.obj /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/Sec/SecMain/OUTPUT/X64/SecEntry.iii

$(FFS_OUTPUT_DIR)/$(MODULE_GUID).map : $(OUTPUT_DIR)/SecMain.map
	test -f $(OUTPUT_DIR)/SecMain.map && $(CP) $(OUTPUT_DIR)/SecMain.map $(FFS_OUTPUT_DIR)/$(MODULE_GUID).map
$(FFS_OUTPUT_DIR)/$(MODULE_GUID).ffs : $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC1.1.pe32 $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC2.ui $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC3.ver
	GenFfs -t EFI_FV_FILETYPE_SECURITY_CORE -g $(MODULE_GUID) -o $(FFS_OUTPUT_DIR)/$(MODULE_GUID).ffs -oi $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC1.1.pe32 -oi $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC2.ui -oi $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC3.ver
$(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC1.1.pe32 : $(OUTPUT_DIR)/SecMain.efi
	-test -e $(OUTPUT_DIR)/SecMain.efi && GenSec -s EFI_SECTION_PE32 -o $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC1.1.pe32 $(OUTPUT_DIR)/SecMain.efi
$(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC2.ui : $(MODULE_DIR)/$(MODULE_FILE)
	GenSec -s EFI_SECTION_USER_INTERFACE -n $(MODULE_NAME) -o $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC2.ui
$(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC3.ver : $(MODULE_DIR)/$(MODULE_FILE)
	GenSec -s EFI_SECTION_VERSION -n 1.0 -o $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC3.ver


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
	-@test -e $(BIN_DIR)/MdePkg/Library/PeiServicesTablePointerLibIdt/PeiServicesTablePointerLibIdt/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/PeiServicesTablePointerLibIdt/PeiServicesTablePointerLibIdt/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/RegisterFilterLibNull/RegisterFilterLibNull/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/RegisterFilterLibNull/RegisterFilterLibNull/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/OvmfPkg/Library/AmdSvsmLib/AmdSvsmLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/AmdSvsmLib/AmdSvsmLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/OvmfPkg/Library/CcExitLib/SecCcExitLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/CcExitLib/SecCcExitLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/PeiMemoryAllocationLib/PeiMemoryAllocationLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/PeiMemoryAllocationLib/PeiMemoryAllocationLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/TdxLib/TdxLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/TdxLib/TdxLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/PeiHobLib/PeiHobLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/PeiHobLib/PeiHobLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/OvmfPkg/Library/CcProbeLib/SecPeiCcProbeLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/CcProbeLib/SecPeiCcProbeLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/OvmfPkg/Library/BaseMemEncryptSevLib/SecMemEncryptSevLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/BaseMemEncryptSevLib/SecMemEncryptSevLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/UefiCpuPkg/Library/BaseXApicX2ApicLib/BaseXApicX2ApicLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/UefiCpuPkg/Library/BaseXApicX2ApicLib/BaseXApicX2ApicLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/BaseIoLibIntrinsic/BaseIoLibIntrinsicSev/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseIoLibIntrinsic/BaseIoLibIntrinsicSev/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/BaseCpuLib/BaseCpuLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseCpuLib/BaseCpuLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/BasePcdLibNull/BasePcdLibNull/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BasePcdLibNull/BasePcdLibNull/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/PeiServicesLib/PeiServicesLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/PeiServicesLib/PeiServicesLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/BaseMemoryLibRepStr/BaseMemoryLibRepStr/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseMemoryLibRepStr/BaseMemoryLibRepStr/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/BaseLib/BaseLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseLib/BaseLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/BaseDebugPrintErrorLevelLib/BaseDebugPrintErrorLevelLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseDebugPrintErrorLevelLib/BaseDebugPrintErrorLevelLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/BasePrintLib/BasePrintLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BasePrintLib/BasePrintLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/OvmfPkg/Library/PlatformDebugLibIoPort/PlatformRomDebugLibIoPort/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/PlatformDebugLibIoPort/PlatformRomDebugLibIoPort/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/BasePciCf8Lib/BasePciCf8Lib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BasePciCf8Lib/BasePciCf8Lib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/BasePciLibCf8/BasePciLibCf8/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BasePciLibCf8/BasePciLibCf8/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/OvmfPkg/Library/AcpiTimerLib/BaseRomAcpiTimerLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/AcpiTimerLib/BaseRomAcpiTimerLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdeModulePkg/Library/BaseRngLibTimerLib/BaseRngLibTimerLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdeModulePkg/Library/BaseRngLibTimerLib/BaseRngLibTimerLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/CryptoPkg/Library/IntrinsicLib/IntrinsicLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/CryptoPkg/Library/IntrinsicLib/IntrinsicLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/CryptoPkg/Library/OpensslLib/OpensslLibCrypto/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/CryptoPkg/Library/OpensslLib/OpensslLibCrypto/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/CryptoPkg/Library/BaseCryptLib/SecCryptLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/CryptoPkg/Library/BaseCryptLib/SecCryptLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/BaseSynchronizationLib/BaseSynchronizationLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseSynchronizationLib/BaseSynchronizationLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdeModulePkg/Library/DebugAgentLibNull/DebugAgentLibNull/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdeModulePkg/Library/DebugAgentLibNull/DebugAgentLibNull/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/BasePeCoffExtraActionLibNull/BasePeCoffExtraActionLibNull/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BasePeCoffExtraActionLibNull/BasePeCoffExtraActionLibNull/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/PcAtChipsetPkg/Library/SerialIoLib/SerialIoLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/PcAtChipsetPkg/Library/SerialIoLib/SerialIoLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/BasePeCoffGetEntryPointLib/BasePeCoffGetEntryPointLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BasePeCoffGetEntryPointLib/BasePeCoffGetEntryPointLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/BaseExtractGuidedSectionLib/BaseExtractGuidedSectionLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseExtractGuidedSectionLib/BaseExtractGuidedSectionLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/OvmfPkg/IntelTdx/TdxMeasurementLib/SecPeiTdxMeasurementLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/IntelTdx/TdxMeasurementLib/SecPeiTdxMeasurementLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/OvmfPkg/Library/TdxMailboxLib/TdxMailboxLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/TdxMailboxLib/TdxMailboxLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/BasePeCoffLib/BasePeCoffLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BasePeCoffLib/BasePeCoffLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/UefiCpuPkg/Library/CpuExceptionHandlerLib/SecPeiCpuExceptionHandlerLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/UefiCpuPkg/Library/CpuExceptionHandlerLib/SecPeiCpuExceptionHandlerLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/UefiCpuPkg/Library/CpuPageTableLib/CpuPageTableLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/UefiCpuPkg/Library/CpuPageTableLib/CpuPageTableLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/StackCheckLibNull/StackCheckLibNull/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/StackCheckLibNull/StackCheckLibNull/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdeModulePkg/Library/LzmaCustomDecompressLib/LzmaCustomDecompressLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdeModulePkg/Library/LzmaCustomDecompressLib/LzmaCustomDecompressLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/OvmfPkg/IntelTdx/TdxHelperLib/SecTdxHelperLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/IntelTdx/TdxHelperLib/SecTdxHelperLib/GNUmakefile cleanall
	@cd $(MODULE_BUILD_DIR)

