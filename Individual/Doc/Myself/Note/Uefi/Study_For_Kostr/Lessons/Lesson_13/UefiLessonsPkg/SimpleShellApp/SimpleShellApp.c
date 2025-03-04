#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>


UINTN
EFIAPI
ShellAppMain (
  IN UINTN   Argc,
  IN CHAR16  **Argv
  )
{
  Print(L"Argc=%d\n", Argc);
  // SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Hello World!\n");
  gST->ConOut->OutputString(gST->ConOut, L"Hello again!\n");
  Print(L"Bye!\n");

  for (UINTN i = Argc; i > 0; i--) {
    Print(L"Arg[%d] = %s\n", Argc-i, Argv[Argc-i]);
  }

  return 0;
}