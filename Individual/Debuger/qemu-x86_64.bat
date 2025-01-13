REM @ECHO OFF
REM Prevent the script from showing the commands being executed, only show output
@ECHO OFF

REM Set Environment
REM Set the path to the debug tools
SET DEBUG_TOOLS_PATH=..\..\Tools\DebugTools\
REM Set the path for the QEMU executable
SET QEMU_EXE=%DEBUG_TOOLS_PATH%QEMU\qemu-system-x86_64.exe
REM Set the path for the EXDI (Intel UEFI Development Kit Debugger Tool) executable
SET EXDI_EXE=%DEBUG_TOOLS_PATH%Intel(R) UEFI Development Kit Debugger Tool\eXdi.exe


REM Start QEMU on Windows.
REM SDL_VIDEODRIVER=directx is faster than windib, but keyboard might not work well
REM Use windib as the alternative for display and keyboard input
SET SDL_VIDEODRIVER=windib

REM SDL_AUDIODRIVER=waveout or dsound can be used if QEMU_AUDIO_DRV=sdl.
REM Here, we use dsound as the audio driver
SET SDL_AUDIODRIVER=dsound

REM QEMU_AUDIO_DRV=dsound or fmod or sdl or none can be used to specify the audio driver.
REM Here, we use dsound for the audio driver
SET QEMU_AUDIO_DRV=dsound

REM QEMU_AUDIO_LOG_TO_MONITOR=1 will display audio log messages in the QEMU monitor.
REM Set it to 0 to suppress audio log messages.
SET QEMU_AUDIO_LOG_TO_MONITOR=0

REM PCI-based PC (default): -M pc 
REM ISA-based PC         : -M isapc
REM -M isapc is added for the NE2000 ISA network card.

REM Start the EXDI debugger tool (eXdi.exe) and launch WinDbg for debugging
start "" "%EXDI_EXE%" /LaunchWinDbg

REM Below is the command to start QEMU virtual machine
REM Use the OVMF firmware to boot the virtual machine, attach a USB device, specify the disk image, and set up a serial debug interface
REM The commented line is an example to start QEMU with additional options such as enabling sound cards and setting the time zone.
REM qemu-system-x86_64.exe -L . -m 128 -hda linux.img -soundhw sb16,es1370 -localtime -M pc -serial pipe:test

REM Start QEMU with the specified BIOS file, USB device, and serial debug interface
%QEMU_EXE% -bios OVMF.fd -usbdevice disk:HDD_BOOT.IMA -serial pipe:QemuPipeDbg
