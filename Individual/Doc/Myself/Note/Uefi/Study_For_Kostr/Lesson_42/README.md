# UEFI App Debugging Guide

- Using ShowBootVariables.efi as an Example

## 1. Set up the GDB debugging environment manually

### 1.1 Analyze the Section Information of the EFI File

Use `objdump` to view the `ShowBootVariables.efi` file:

```bash
$ objdump -h ShowBootVariables.efi 

ShowBootVariables.efi:     file format pei-x86-64

Sections:
Idx Name          Size      VMA               LMA               File off  Algn
  0 .text         00005240  0000000000000240  0000000000000240  00000240  2**4
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
  1 .data         00000580  0000000000005480  0000000000005480  00005480  2**4
                  CONTENTS, ALLOC, LOAD, DATA
  2 .reloc        00000080  0000000000005a00  0000000000005a00  00005a00  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
```

The section information of `ShowBootVariables.debug`:

```bash
$ objdump -h ShowBootVariables.debug 

ShowBootVariables.debug:     file format elf64-x86-64

Sections:
Idx Name          Size      VMA               LMA               File off  Algn
  0 .text         00005236  0000000000000240  0000000000000240  000000c0  2**6
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, CODE
  1 .data         000004a1  0000000000005480  0000000000005480  00005300  2**6
                  CONTENTS, ALLOC, LOAD, RELOC, DATA
  2 .eh_frame     00000000  0000000000005940  0000000000005940  000057c0  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  3 .rela         00000510  0000000000005940  0000000000005940  000057c0  2**3
                  CONTENTS, READONLY
  4 .build-id     00000024  0000000000005e50  0000000000005e50  00005cd0  2**2
                  CONTENTS, READONLY
  5 .debug_info   0001c6a6  0000000000000000  0000000000000000  00005cf4  2**0
                  CONTENTS, RELOC, READONLY, DEBUGGING, OCTETS
  6 .debug_abbrev 00002f8c  0000000000000000  0000000000000000  0002239a  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
  7 .debug_loclists 0000493b  0000000000000000  0000000000000000  00025326  2**0
                  CONTENTS, RELOC, READONLY, DEBUGGING, OCTETS
  8 .debug_aranges 00000560  0000000000000000  0000000000000000  00029c61  2**0
                  CONTENTS, RELOC, READONLY, DEBUGGING, OCTETS
  9 .debug_rnglists 000005b7  0000000000000000  0000000000000000  0002a1c1  2**0
                  CONTENTS, RELOC, READONLY, DEBUGGING, OCTETS
 10 .debug_line   0000397b  0000000000000000  0000000000000000  0002a778  2**0
                  CONTENTS, RELOC, READONLY, DEBUGGING, OCTETS
 11 .debug_str    00004adc  0000000000000000  0000000000000000  0002e0f3  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 12 .debug_line_str 00001b3e  0000000000000000  0000000000000000  00032bcf  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 13 .debug_frame  00001018  0000000000000000  0000000000000000  00034710  2**3
                  CONTENTS, RELOC, READONLY, DEBUGGING, OCTETS
```

- Focus the address of `.text(0x240)` and `.data(0x5480)`

## 1.2 Start QEMU and Load the Debugging Environment

Use the following command to start QEMU and load the UEFI firmware:

```bash
sudo qemu-system-x86_64 \
    -drive if=pflash,format=raw,file=OVMF.fd,id=BIOS-OVMF \
    -drive file=fat:rw:hda-contents,format=raw,if=ide,index=0 \
    -debugcon file:debug.log \
    -global isa-debugcon.iobase=0x402 \
    -s
```

Run `ShowBootVariables.efi` and check the part about `ShowBootVariables.efi` in `debug.log`:

```shell
FSOpen: Open '\ShowBootVariables.efi' Success
[Security] 3rd party image[0] can be loaded after EndOfDxe: PciRoot(0x0)/Pci(0x1,0x1)/Ata(Primary,Master,0x0)/HD(1,MBR,0xBE1AFDFA,0x3F,0xFBFC1)/\ShowBootVariables.efi.
None of Tcg2Protocol/CcMeasurementProtocol is installed.
InstallProtocolInterface: 5B1B31A1-9562-11D2-8E3F-00A0C969723B 6127040
Loading driver at 0x000060F2000 EntryPoint=0x000060F5BA0 ShowBootVariables.efi
InstallProtocolInterface: BC62157E-3E33-4FEC-9920-2D3B36D750DF 6127E98
ProtectUefiImageCommon - 0x6127040
  - 0x00000000060F2000 - 0x0000000000005A80
InstallProtocolInterface: 752F3136-4E16-4FDC-A22A-E5F46812F4CA 7E7A638
```

Here, we need to pay attention to the line `Loading driver at 0x000060F2000 EntryPoint=0x000060F5BA0 ShowBootVariables.efi`, which means that `ShowBootVariables.efi` is running at the memory address `0x000060F2000`.

## 1.3 Calculate the Loading Address of the Symbol File

Assume that `ShowBootVariables.efi` is loaded at `0x60F2000`. Calculate the starting addresses of the `.text` and `.data` sections:

```plaintext
0x60F2000 +  0x240  = 0x60F2240
0x60F2000 + 0x5480  = 0x60F7480
```

## 1.4 Start GDB and Add the Symbol File

Open a new terminal and run gdb

```bash
$ gdb
GNU gdb (Ubuntu 12.1-0ubuntu1~22.04.2) 12.1
Copyright (C) 2022 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word".
```

In GDB, execute the following commands:

```gdb
(gdb)  add-symbol-file ShowBootVariables.debug 0x611A240 -s .data 0x611F480
add symbol table from file "ShowBootVariables.debug" at
 .text_addr = 0x611a240
 .data_addr = 0x611f480
(y or n) y
Reading symbols from ShowBootVariables.debug...
```

## 1.5 Set Breakpoints and Connect to QEMU for Remote Debugging

Open a another terminal and find the line number of `ShellAppMain` in the source code:

```bash
$ grep -n ShellAppMain ShowBootVariables/ShowBootVariables.c
106:ShellAppMain (
```

We get that `ShellAppMain` is at line `106`.

Return the terminal which we have just opened, and set a breakpoint:

```gdb
(gdb) b ShowBootVariables/ShowBootVariables.c:106
Breakpoint 1 at 0x60f57e4: file /media/sf_VirtualBoxShare/UEFI/edk2/UefiLessonsPkg/ShowBootVariables/ShowBootVariables.c, line 110.
```

Then connect to QEMU for remote debugging:

```gdb
(gdb) target remote :1234
Remote debugging using :1234
warning: No executable has been specified and target does not support
determining executable automatically.  Try using the "file" command.
0x0000000006cc0051 in ?? ()
```

If QEMU is running normally, GDB will connect successfully and display the current CPU execution position.

## 1.6 Continue Execution and Debugging

Execute the command to continue running the program:

```gdb
(gdb) c
Continuing.
```

At this time, go back to the QEMU window and run `ShowBootVariables.efi` again.

When the program executes to `ShellAppMain`, you can see in the GDB window that the breakpoint is automatically triggered:

```plaintext
Breakpoint 1, ShellAppMain (Argc=1, Argv=0x6143418) at /media/sf_VirtualBoxShare/UEFI/edk2/UefiLessonsPkg/ShowBootVariables/ShowBootVariables.c:115
115     Status = GetNvramVariable (
```

Enable the GDB TUI mode (visual debugging interface):

```gdb
(gdb) tui enable
```

At this point, you can see the entire source code. Enter `c` in GDB to complete the execution of the application.

The entire operation log in gdb is under below:

```gdb
$ gdb
GNU gdb (Ubuntu 12.1-0ubuntu1~22.04.2) 12.1
Copyright (C) 2022 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word".
(gdb) add-symbol-file ShowBootVariables.debug 0x60F2240 -s .data 0x60F7480
add symbol table from file "ShowBootVariables.debug" at
 .text_addr = 0x60f2240
 .data_addr = 0x60f7480
(y or n) y
Reading symbols from ShowBootVariables.debug...
(gdb) b ShowBootVariables/ShowBootVariables.c:106
Breakpoint 1 at 0x60f57e4: file /media/sf_VirtualBoxShare/UEFI/edk2/UefiLessonsPkg/ShowBootVariables/ShowBootVariables.c, line 110.
(gdb) target remote :1234
Remote debugging using :1234
warning: No executable has been specified and target does not support
determining executable automatically.  Try using the "file" command.
0x0000000006cc0051 in ?? ()
(gdb) c
Continuing.

Breakpoint 1, ShellAppMain (Argc=1, Argv=0x6143418) at /media/sf_VirtualBoxShare/UEFI/edk2/UefiLessonsPkg/ShowBootVariables/ShowBootVariables.c:115
115     Status = GetNvramVariable (
(gdb) tui enable
```

Screenshots are down below:

![1.png](Figure\Chapter_1\1.png "1.png")
![2.png](Figure\Chapter_1\2.png "2.png")
![3.png](Figure\Chapter_1\3.png "3.png")
![4.png](Figure\Chapter_1\4.png "4.png")

## 2. Use `efi.py` to speed up debugging

The configuration in `Chapter 1` is too complicated to operate, here has relatively easy ways to debug it

### 2.1 Download `efi.py`

<https://github.com/artem-nefedov/uefi-gdb/blob/master/efi.py>

### 2.2 Load `efi.py`

Move `efi.py` into your debug folder, open a new terminal from your debug folder, and run the command:

```shell
$ gdb -ex 'source efi.py'
GNU gdb (Ubuntu 12.1-0ubuntu1~22.04.2) 12.1
Copyright (C) 2022 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word".
```

### 2.3 Get the info of your `.efi`

Open a new terminal, and use the following command to start QEMU and load the UEFI firmware:

```bash
sudo qemu-system-x86_64 \
    -drive if=pflash,format=raw,file=OVMF.fd,id=BIOS-OVMF \
    -drive file=fat:rw:hda-contents,format=raw,if=ide,index=0 \
    -debugcon file:debug.log \
    -global isa-debugcon.iobase=0x402 \
    -s
```

Run `ShowBootVariables.efi` in QEMU and the part about `ShowBootVariables.efi` will save in `debug.log`:

Copy debug.log into your debug folder, then run this command in gdb:

```gdb
(gdb) efi -64 ShowBootVariables
Using pre-defined driver list: ['ShowBootVariables']
The target architecture is set to "i386:x86-64:intel".
Directory "Build" is missing
With architecture X64
Looking for addresses in debug.log
EFI file ShowBootVariables.efi
 Base address 0x00006119000
.text address 0x0000000000000240
.data address 0x0000000000005480
add symbol table from file "ShowBootVariables.debug" at
 .text_addr = 0x6119240
 .data_addr = 0x611e480
```

### 2.4 Set up gdb and continue debugging

```gdb
(gdb) target remote :1234
Remote debugging using :1234
warning: No executable has been specified and target does not support
determining executable automatically.  Try using the "file" command.
0x0000000006cc0051 in ?? ()
(gdb) b ShowBootVariables/ShowBootVariables.c:106
Breakpoint 1 at 0x611c7e4: file /media/sf_VirtualBoxShare/UEFI/edk2/UefiLessonsPkg/ShowBootVariables/ShowBootVariables.c, line 110.
(gdb) c
Continuing.
```

Run `ShowBootVariables.efi` in QEMU again, then you will see the breakpoint is showed in gdb, input c to continue

```gdb
Breakpoint 1, ShellAppMain (Argc=1, Argv=0x6125498) at /media/sf_VirtualBoxShare/UEFI/edk2/UefiLessonsPkg/ShowBootVariables/ShowBootVariables.c:115
115     Status = GetNvramVariable (
(gdb) c
Continuing.
```

The entire operation log in gdb is under below:

```gdb
$ gdb -ex 'source efi.py'
GNU gdb (Ubuntu 12.1-0ubuntu1~22.04.2) 12.1
Copyright (C) 2022 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word".
(gdb) efi -64 ShowBootVariables
Using pre-defined driver list: ['ShowBootVariables']
The target architecture is set to "i386:x86-64:intel".
Directory "Build" is missing
With architecture X64
Looking for addresses in debug.log
EFI file ShowBootVariables.efi
 Base address 0x00006119000
.text address 0x0000000000000240
.data address 0x0000000000005480
add symbol table from file "ShowBootVariables.debug" at
 .text_addr = 0x6119240
 .data_addr = 0x611e480
(gdb) target remote :1234
Remote debugging using :1234
warning: No executable has been specified and target does not support
determining executable automatically.  Try using the "file" command.
0x0000000006cc0051 in ?? ()
(gdb) b ShowBootVariables/ShowBootVariables.c:106
Breakpoint 1 at 0x611c7e4: file /media/sf_VirtualBoxShare/UEFI/edk2/UefiLessonsPkg/ShowBootVariables/ShowBootVariables.c, line 110.
(gdb) c
Continuing.

Breakpoint 1, ShellAppMain (Argc=1, Argv=0x6125498) at /media/sf_VirtualBoxShare/UEFI/edk2/UefiLessonsPkg/ShowBootVariables/ShowBootVariables.c:115
115     Status = GetNvramVariable (
(gdb) c
Continuing.
```

Screenshots are down below:

![1.png](Figure\Chapter_2\1.png "1.png")
![2.png](Figure\Chapter_2\2.png "2.png")
