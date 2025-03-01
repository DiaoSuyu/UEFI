#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Protocol/SimpleClass.h>


UINTN mNumber = 0;
EFI_HANDLE  mSimpleClassHandle = NULL;



EFI_STATUS
EFIAPI
SimpleClassProtocolSetNumber (
  IN UINTN  Number
  )
{
    mNumber = Number;
    return EFI_SUCCESS;
}


EFI_STATUS
EFIAPI
SimpleClassProtocolGetNumber (
  IN UINTN  *Number
  )
{
    if (Number == NULL) {
        return EFI_INVALID_PARAMETER;
    }
    *Number = mNumber;
    return EFI_SUCCESS;
}


SIMPLE_CLASS_PROTOCOL mSimpleClass = {
  SimpleClassProtocolGetNumber,
  SimpleClassProtocolSetNumber
};


EFI_STATUS
EFIAPI
SimpleClassProtocolDriverUnload (
  IN EFI_HANDLE  ImageHandle
  )
{
    Print(L"Bye-bye from SimpleClassProtocol driver, handle = %p\n", mSimpleClassHandle);
    EFI_STATUS Status = gBS->UninstallMultipleProtocolInterfaces(
        mSimpleClassHandle,
        &gSimpleClassProtocolGuid,
        &mSimpleClass,
        NULL
    );
    return Status;
}


EFI_STATUS
EFIAPI
SimpleClassProtocolDriverEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
    Print(L"Hello from SimpleClassProtocol driver");

    EFI_STATUS Status;
    Status = gBS->InstallMultipleProtocolInterfaces (
        &mSimpleClassHandle,
        &gSimpleClassProtocolGuid,
        &mSimpleClass,
        NULL
    );
    if (!EFI_ERROR(Status)) {
        Print(L", handle = %p\n", mSimpleClassHandle);
    } else {
        Print(L"\n", mSimpleClassHandle);
    }

  return Status;
}