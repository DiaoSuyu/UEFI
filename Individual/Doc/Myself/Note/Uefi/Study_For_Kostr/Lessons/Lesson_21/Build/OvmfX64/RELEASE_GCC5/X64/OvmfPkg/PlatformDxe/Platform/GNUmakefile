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
MODULE_NAME = PlatformDxe
MODULE_GUID = D9DCC5DF-4007-435E-9098-8970935504B2
MODULE_NAME_GUID = PlatformDxe
MODULE_VERSION = 1.0
MODULE_TYPE = DXE_DRIVER
MODULE_FILE = Platform.inf
MODULE_FILE_BASE_NAME = Platform
BASE_NAME = $(MODULE_NAME)
MODULE_RELATIVE_DIR = OvmfPkg/PlatformDxe
PACKAGE_RELATIVE_DIR = PlatformDxe
MODULE_DIR = /media/sf_VirtualBoxShare/UEFI/edk2/OvmfPkg/PlatformDxe
FFS_OUTPUT_DIR = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/FV/Ffs/D9DCC5DF-4007-435E-9098-8970935504B2PlatformDxe

MODULE_ENTRY_POINT = PlatformInit
ARCH_ENTRY_POINT = PlatformInit
IMAGE_ENTRY_POINT = _ModuleEntryPoint

INF_VERSION = 0x00010005
BASE_NAME = PlatformDxe
FILE_GUID = D9DCC5DF-4007-435E-9098-8970935504B2
MODULE_TYPE = DXE_DRIVER
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
MODULE_BUILD_DIR = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform
OUTPUT_DIR = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/OUTPUT
DEBUG_DIR = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/DEBUG
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
    $(OUTPUT_DIR)/Platform.obj \
    $(OUTPUT_DIR)/PlatformConfig.obj \
    $(OUTPUT_DIR)/PlatformForms.obj

STATIC_LIBRARY_FILES =  \
    $(BIN_DIR)/MdeModulePkg/Library/UefiHiiLib/UefiHiiLib/OUTPUT/UefiHiiLib.lib \
    $(BIN_DIR)/MdeModulePkg/Library/UefiHiiServicesLib/UefiHiiServicesLib/OUTPUT/UefiHiiServicesLib.lib \
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
    $(BIN_DIR)/MdePkg/Library/UefiDriverEntryPoint/UefiDriverEntryPoint/OUTPUT/UefiDriverEntryPoint.lib \
    $(BIN_DIR)/MdePkg/Library/UefiLib/UefiLib/OUTPUT/UefiLib.lib \
    $(BIN_DIR)/MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib/OUTPUT/UefiMemoryAllocationLib.lib \
    $(BIN_DIR)/MdePkg/Library/UefiRuntimeServicesTableLib/UefiRuntimeServicesTableLib/OUTPUT/UefiRuntimeServicesTableLib.lib \
    $(BIN_DIR)/OvmfPkg/Library/CcProbeLib/DxeCcProbeLib/OUTPUT/DxeCcProbeLib.lib \
    $(BIN_DIR)/OvmfPkg/Library/PlatformDebugLibIoPort/PlatformDebugLibIoPort/OUTPUT/PlatformDebugLibIoPort.lib \
    $(OUTPUT_DIR)/PlatformDxe.lib

INC =  \
    -I$(WORKSPACE)/edk2/OvmfPkg/PlatformDxe \
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
    -I$(WORKSPACE)/edk2/OvmfPkg \
    -I$(WORKSPACE)/edk2/OvmfPkg/Include

OBJECT_FILES_LIST = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/OUTPUT/object_files.lst
STATIC_LIBRARY_FILES_LIST = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/OUTPUT/static_library_files.lst


#
# Overridable Target Macro Definitions
#
FORCE_REBUILD = force_build
INIT_TARGET = init
PCH_TARGET =
BC_TARGET = 
CODA_TARGET = /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/OUTPUT/PlatformDxe.efi \
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
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseIoLibIntrinsic/BaseIoLibIntrinsicSev/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BasePrintLib/BasePrintLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/PlatformDebugLibIoPort/PlatformDebugLibIoPort/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/CcProbeLib/DxeCcProbeLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/UefiBootServicesTableLib/UefiBootServicesTableLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/UefiRuntimeServicesTableLib/UefiRuntimeServicesTableLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/UefiDevicePathLibDevicePathProtocol/UefiDevicePathLibDevicePathProtocol/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/UefiLib/UefiLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdeModulePkg/Library/UefiHiiServicesLib/UefiHiiServicesLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdeModulePkg/Library/UefiHiiLib/UefiHiiLib/GNUmakefile
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/UefiDriverEntryPoint/UefiDriverEntryPoint/GNUmakefile
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
$(OUTPUT_DIR)/Platform.obj : $(MAKE_FILE)
$(OUTPUT_DIR)/Platform.obj : $(DEBUG_DIR)/AutoGen.h
$(OUTPUT_DIR)/Platform.obj : $(DEBUG_DIR)/PlatformDxeStrDefs.h
$(OUTPUT_DIR)/Platform.obj : $(WORKSPACE)/edk2/OvmfPkg/PlatformDxe/Platform.c
	"$(CC)" $(DEPS_FLAGS) $(CC_FLAGS) -c -o /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/OUTPUT/./Platform.obj $(INC) /media/sf_VirtualBoxShare/UEFI/edk2/OvmfPkg/PlatformDxe/Platform.c

$(OUTPUT_DIR)/PlatformConfig.obj : $(MAKE_FILE)
$(OUTPUT_DIR)/PlatformConfig.obj : $(DEBUG_DIR)/AutoGen.h
$(OUTPUT_DIR)/PlatformConfig.obj : $(DEBUG_DIR)/PlatformDxeStrDefs.h
$(OUTPUT_DIR)/PlatformConfig.obj : $(WORKSPACE)/edk2/OvmfPkg/PlatformDxe/PlatformConfig.c
	"$(CC)" $(DEPS_FLAGS) $(CC_FLAGS) -c -o /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/OUTPUT/./PlatformConfig.obj $(INC) /media/sf_VirtualBoxShare/UEFI/edk2/OvmfPkg/PlatformDxe/PlatformConfig.c

$(OUTPUT_DIR)/AutoGen.obj : $(MAKE_FILE)
$(OUTPUT_DIR)/AutoGen.obj : $(DEBUG_DIR)/AutoGen.h
$(OUTPUT_DIR)/AutoGen.obj : $(DEBUG_DIR)/PlatformDxeStrDefs.h
$(OUTPUT_DIR)/AutoGen.obj : $(DEBUG_DIR)/AutoGen.c
	"$(CC)" $(DEPS_FLAGS) $(CC_FLAGS) -c -o /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/OUTPUT/./AutoGen.obj $(INC) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/DEBUG/AutoGen.c

$(OUTPUT_DIR)/PlatformForms.obj : $(MAKE_FILE)
$(OUTPUT_DIR)/PlatformForms.obj : $(DEBUG_DIR)/PlatformForms.c
	"$(CC)" $(DEPS_FLAGS) $(CC_FLAGS) -c -o /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/OUTPUT/./PlatformForms.obj $(INC) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/DEBUG/PlatformForms.c

$(OUTPUT_DIR)/PlatformDxe.lib : $(OBJECT_FILES)
$(OUTPUT_DIR)/PlatformDxe.lib : $(OBJECT_FILES_LIST)
	$(RM) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/OUTPUT/PlatformDxe.lib
	"$(SLINK)" cr /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/OUTPUT/PlatformDxe.lib $(SLINK_FLAGS) @$(OBJECT_FILES_LIST)

$(DEBUG_DIR)/PlatformDxe.dll : $(MAKE_FILE)
$(DEBUG_DIR)/PlatformDxe.dll : $(STATIC_LIBRARY_FILES)
$(DEBUG_DIR)/PlatformDxe.dll : $(STATIC_LIBRARY_FILES_LIST)
	"$(DLINK)" -o /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/DEBUG/PlatformDxe.dll $(DLINK_FLAGS) -Wl,--start-group,@$(STATIC_LIBRARY_FILES_LIST),--end-group $(CC_FLAGS) $(DLINK2_FLAGS)
	"$(OBJCOPY)" $(OBJCOPY_FLAGS) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/DEBUG/PlatformDxe.dll

$(OUTPUT_DIR)/PlatformDxe.efi : $(DEBUG_DIR)/PlatformDxe.dll
	$(CP) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/DEBUG/PlatformDxe.dll $(DEBUG_DIR)/$(MODULE_NAME).debug
	"$(OBJCOPY)" $(OBJCOPY_STRIPFLAG) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/DEBUG/PlatformDxe.dll
	-"$(OBJCOPY)" $(OBJCOPY_ADDDEBUGFLAG) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/DEBUG/PlatformDxe.dll
	-$(CP) $(DEBUG_DIR)/$(MODULE_NAME).debug $(BIN_DIR)/$(MODULE_NAME_GUID).debug
	"$(GENFW)" -e $(MODULE_TYPE) -o /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/OUTPUT/PlatformDxe.efi /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/DEBUG/PlatformDxe.dll $(GENFW_FLAGS)
	$(CP) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/OUTPUT/PlatformDxe.efi $(DEBUG_DIR)
	$(CP) /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/OUTPUT/PlatformDxe.efi $(BIN_DIR)/$(MODULE_NAME_GUID).efi
	-$(CP) $(DEBUG_DIR)/*.map $(OUTPUT_DIR)

$(OUTPUT_DIR)/PlatformDxe.map : $(OUTPUT_DIR)/PlatformDxe.efi
	

$(DEBUG_DIR)/PlatformForms.c : $(MAKE_FILE)
$(DEBUG_DIR)/PlatformForms.c : $(DEBUG_DIR)/AutoGen.h
$(DEBUG_DIR)/PlatformForms.c : $(DEBUG_DIR)/PlatformDxeStrDefs.h
$(DEBUG_DIR)/PlatformForms.c : $(WORKSPACE)/edk2/OvmfPkg/PlatformDxe/PlatformForms.vfr
	"$(VFRPP)" $(DEPS_FLAGS) $(VFRPP_FLAGS) $(INC) /media/sf_VirtualBoxShare/UEFI/edk2/OvmfPkg/PlatformDxe/PlatformForms.vfr > $(OUTPUT_DIR)/PlatformForms.i
	"$(VFR)" $(VFR_FLAGS) --string-db $(OUTPUT_DIR)/$(MODULE_NAME)StrDefs.hpk --output-directory /media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/DEBUG/. $(OUTPUT_DIR)/PlatformForms.i

$(FFS_OUTPUT_DIR)/$(MODULE_GUID).map : $(OUTPUT_DIR)/PlatformDxe.map
	test -f $(OUTPUT_DIR)/PlatformDxe.map && $(CP) $(OUTPUT_DIR)/PlatformDxe.map $(FFS_OUTPUT_DIR)/$(MODULE_GUID).map
$(FFS_OUTPUT_DIR)/$(MODULE_GUID).ffs : $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC1.1.dpx $(FFS_OUTPUT_DIR)/PlatformDxeOffset.raw $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC2.1.pe32 $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC3.ui $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC4.ver
	GenFfs -t EFI_FV_FILETYPE_DRIVER -g $(MODULE_GUID) -o $(FFS_OUTPUT_DIR)/$(MODULE_GUID).ffs -oi $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC1.1.dpx -oi $(FFS_OUTPUT_DIR)/PlatformDxeOffset.raw -oi $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC2.1.pe32 -oi $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC3.ui -oi $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC4.ver
$(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC1.1.dpx : $(OUTPUT_DIR)/PlatformDxe.depex
	-test -e $(OUTPUT_DIR)/PlatformDxe.depex && GenSec -s EFI_SECTION_DXE_DEPEX -o $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC1.1.dpx $(OUTPUT_DIR)/PlatformDxe.depex
$(FFS_OUTPUT_DIR)/PlatformDxeOffset.raw : $(FFS_OUTPUT_DIR)/PlatformDxe.offset
	-test -e $(FFS_OUTPUT_DIR)/PlatformDxe.offset && GenSec -s EFI_SECTION_RAW -o $(FFS_OUTPUT_DIR)/PlatformDxeOffset.raw $(FFS_OUTPUT_DIR)/PlatformDxe.offset
$(FFS_OUTPUT_DIR)/PlatformDxe.offset : $(DEBUG_DIR)/PlatformDxe.efi
	Trim --Vfr-Uni-Offset -o $(FFS_OUTPUT_DIR)/PlatformDxe.offset --ModuleName=PlatformDxe --DebugDir=/media/sf_VirtualBoxShare/UEFI/Build/OvmfX64/RELEASE_GCC5/X64/OvmfPkg/PlatformDxe/Platform/DEBUG 
$(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC2.1.pe32 : $(OUTPUT_DIR)/PlatformDxe.efi
	-test -e $(OUTPUT_DIR)/PlatformDxe.efi && GenSec -s EFI_SECTION_PE32 -o $(FFS_OUTPUT_DIR)/$(MODULE_GUID)SEC2.1.pe32 $(OUTPUT_DIR)/PlatformDxe.efi
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
	-@test -e $(BIN_DIR)/MdePkg/Library/BaseIoLibIntrinsic/BaseIoLibIntrinsicSev/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BaseIoLibIntrinsic/BaseIoLibIntrinsicSev/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/BasePrintLib/BasePrintLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/BasePrintLib/BasePrintLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/OvmfPkg/Library/PlatformDebugLibIoPort/PlatformDebugLibIoPort/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/PlatformDebugLibIoPort/PlatformDebugLibIoPort/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/OvmfPkg/Library/CcProbeLib/DxeCcProbeLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/OvmfPkg/Library/CcProbeLib/DxeCcProbeLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/UefiBootServicesTableLib/UefiBootServicesTableLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/UefiBootServicesTableLib/UefiBootServicesTableLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/UefiRuntimeServicesTableLib/UefiRuntimeServicesTableLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/UefiRuntimeServicesTableLib/UefiRuntimeServicesTableLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/UefiDevicePathLibDevicePathProtocol/UefiDevicePathLibDevicePathProtocol/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/UefiDevicePathLibDevicePathProtocol/UefiDevicePathLibDevicePathProtocol/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/UefiLib/UefiLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/UefiLib/UefiLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdeModulePkg/Library/UefiHiiServicesLib/UefiHiiServicesLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdeModulePkg/Library/UefiHiiServicesLib/UefiHiiServicesLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdeModulePkg/Library/UefiHiiLib/UefiHiiLib/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdeModulePkg/Library/UefiHiiLib/UefiHiiLib/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/UefiDriverEntryPoint/UefiDriverEntryPoint/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/UefiDriverEntryPoint/UefiDriverEntryPoint/GNUmakefile cleanall
	-@test -e $(BIN_DIR)/MdePkg/Library/StackCheckLibNull/StackCheckLibNull/GNUmakefile && "$(MAKE)" $(MAKE_FLAGS) -f $(BIN_DIR)/MdePkg/Library/StackCheckLibNull/StackCheckLibNull/GNUmakefile cleanall
	@cd $(MODULE_BUILD_DIR)

