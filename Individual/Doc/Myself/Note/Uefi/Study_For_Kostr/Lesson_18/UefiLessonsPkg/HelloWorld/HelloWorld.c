#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>

EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{

    UINTN Index;
    EFI_EVENT Events[1];
    BOOLEAN PlusPressed = FALSE;
    BOOLEAN MinusPressed = FALSE;

    SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Hello World!\n");
    gST->ConOut->OutputString(gST->ConOut, L"Hello again!\n");
    Print(L"Bye!\n");

    // Support one event
    // gBS->WaitForEvent(1, &(gST->ConIn->WaitForKey), &Index);

    Events[0] = gST->ConIn->WaitForKey;

    Print(L"Press '+' and '-' together to continue...\n");

    while (!(PlusPressed && MinusPressed)) {
        gBS->WaitForEvent(1, Events, &Index);
        if (Index == 0) {
            EFI_INPUT_KEY Key;
            gST->ConIn->ReadKeyStroke(gST->ConIn, &Key);
            if (Key.UnicodeChar == '+') {
                PlusPressed = TRUE;
                Print(L"Detected + key\n");
            } else if (Key.UnicodeChar == '-') {
                MinusPressed = TRUE;
                Print(L"Detected - key\n");
            }
        }
    }
    
    Print(L"Both '+' and '-' detected! Exiting...\n");

    gST->ConIn->Reset(gST->ConIn, FALSE);

    return EFI_SUCCESS;
}
