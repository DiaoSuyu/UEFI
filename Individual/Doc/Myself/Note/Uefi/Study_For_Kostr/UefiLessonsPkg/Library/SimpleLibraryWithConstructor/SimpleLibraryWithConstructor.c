#include <Library/SimpleLibrary.h>
#include <Library/UefiLib.h>



UINTN
Plus2 (
  IN UINTN  number
  ) 
{
    return number + 2;
}


EFI_STATUS
EFIAPI
SimpleLibraryConstructor (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
    Print(L"Hello from library constructor!\n");
    return EFI_SUCCESS;
}