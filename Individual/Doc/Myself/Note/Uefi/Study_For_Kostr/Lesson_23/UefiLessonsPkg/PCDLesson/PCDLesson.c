#include <Uefi.h>
#include <Library/DevicePathLib.h>
#include <Library/PcdLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>

EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
    // FixedPcd +
    // Simple PCDs
    Print(L"Simple PCDs:\n");
    Print(L"PcdInt8 = 0x%x\n", FixedPcdGet8(PcdInt8));
    Print(L"PcdInt8 = 0x%x\n", PcdGet8(PcdInt8));
    Print(L"PcdInt16 = 0x%x\n", FixedPcdGet16(PcdInt16));
    Print(L"PcdInt32 = 0x%x\n", FixedPcdGet32(PcdInt32));
    Print(L"PcdInt64 = 0x%x\n", FixedPcdGet64(PcdInt64));
    Print(L"PcdBool = 0x%x\n", FixedPcdGetBool(PcdBool));
    Print(L"PcdInt16 = 0x%x\n", PcdGet16(PcdInt16));
    Print(L"PcdInt32 = 0x%x\n", PcdGet32(PcdInt32));
    Print(L"PcdInt64 = 0x%x\n", PcdGet64(PcdInt64));
    Print(L"PcdIntBool = 0x%x\n", PcdGetBool(PcdBool));
    Print(L"\n");

    // Expressions in initialization values
    Print(L"Expressions in initialization values:\n");
    Print(L"PcdExpression = 0x%x\n", PcdGet32(PcdExpression));
    Print(L"PcdExpression_1 = 0x%x\n", PcdGet32(PcdExpression_1));
    Print(L"PcdExpression_2 = 0x%x\n", PcdGet32(PcdExpression_2));
    Print(L"PcdExpression_3 = 0x%x\n", PcdGetBool(PcdExpression_3));
    Print(L"\n");

    // String PCDs
    Print(L"String PCDs:\n");
    Print(L"PcdAsciiStr = %a\n", FixedPcdGetPtr(PcdAsciiStr));
    Print(L"PcdAsciiStrSize = %d\n", FixedPcdGetSize(PcdAsciiStr));
    Print(L"PcdUCS2Str = %s\n", PcdGetPtr(PcdUCS2Str));
    Print(L"PcdUCS2StrSize = %d\n", PcdGetSize(PcdUCS2Str));
    Print(L"\n");

    // Byte Array PCDs
    Print(L"Byte Array PCDs:\n");
    for (UINTN i = 0; i < FixedPcdGetSize(PcdArray); i++) {
      Print(L"PcdArray[%d] = 0x%02x\n", i, ((UINT8*)FixedPcdGetPtr(PcdArray))[i]);
    }
    Print(L"\n");

    // GUID PCDs
    Print(L"GUID PCDs:\n");
    Print(L"PcdGuidInBytes = %g\n", *(EFI_GUID*)FixedPcdGetPtr(PcdGuidInBytes));
    Print(L"PcdGuid = %g\n", *(EFI_GUID*)FixedPcdGetPtr(PcdGuid));
    Print(L"\n");

    // DEVICE_PATH PCDs
    Print(L"DEVICE_PATH PCDs:\n");
    Print(L"PcdDevicePath: %s\n", ConvertDevicePathToText((EFI_DEVICE_PATH_PROTOCOL*)FixedPcdGetPtr(PcdDevicePath), FALSE, FALSE));
    Print(L"\n");

    // Using integer casts PCDs
    Print(L"Using integer casts PCDs:\n");
    for (UINTN i = 0; i < FixedPcdGetSize(PcdIntCasts); i++) {
      Print(L"PcdIntCasts[%d] = 0x%02x\n", i, ((UINT8*)FixedPcdGetPtr(PcdIntCasts))[i]);
    }
    Print(L"\n");

    // LABEL and OFFSET_OF PCDs
    Print(L"LABEL and OFFSET_OF PCDs:\n");
    for (UINTN i = 0; i < FixedPcdGetSize(PcdWithLabels); i++) {
      Print(L"PcdWithLabels[%d] = 0x%02x\n", i, ((UINT8*)FixedPcdGetPtr(PcdWithLabels))[i]);
    }
    Print(L"\n");

    // INF override PCDs
    // the order of override: DEC < INF < DSC
    // Declaration file (DEC) declares PCD with its default value
    // Every App/Driver Information file (INF) can override the value of this PCD differently
    // However a package description file that contains all these Apps/Drivers (DSC) can override this PCD for all of them
    Print(L"PcdInt32Override = %d\n", FixedPcdGet32(PcdInt32Override));
    // FixedPcd -

    // FeaturePcd +
    Print(L"PcdFeatureFlag = %d\n", FeaturePcdGet(PcdFeatureFlag));
    Print(L"PcdFeatureFlag = %d\n", PcdGetBool(PcdFeatureFlag));
    Print(L"PcdBool = %d\n", FixedPcdGetBool(PcdBool));
    Print(L"PcdBool = %d\n", PcdGetBool(PcdBool));
    // FeaturePcd -

    // PatchPcd +
    Print(L"PcdPatchableInt32 = 0x%x\n", PatchPcdGet32(PcdPatchableInt32));
    Print(L"PcdPatchableInt32 = 0x%x\n", PcdGet32(PcdPatchableInt32));
    // PCD value modification at run-time
    EFI_STATUS Status = PcdSet32S(PcdPatchableInt32, 44);
    Print(L"Status = %r\n", Status);
    Print(L"PcdPatchableInt32 = 0x%x\n", PatchPcdGet32(PcdPatchableInt32));
    Print(L"PcdPatchableInt32 = 0x%x\n", PcdGet32(PcdPatchableInt32));
    PatchPcdSet32(PcdPatchableInt32, 45);
    Print(L"PcdPatchableInt32 = 0x%x\n", PatchPcdGet32(PcdPatchableInt32));
    Print(L"PcdPatchableInt32 = 0x%x\n", PcdGet32(PcdPatchableInt32));
    // PatchPcd -

    return EFI_SUCCESS;
}