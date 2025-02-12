# Debug Log of Lesson 19

## QEMU Startup Command

```bash
qemu-system-x86_64 \
    -drive if=pflash,format=raw,readonly,file=OVMF.fd,id=BIOS-OVMF \
    -drive if=pflash,format=raw,file=OVMF_VARS.fd \
    -drive file=fat:rw:hda-contents,format=raw,if=ide,index=0 \
    -debugcon file:debug.log \
    -global isa-debugcon.iobase=0x402
```

## Current Boot Options

```bash
bcfg boot dump
Option: 00. Variable: Boot0000   
  Desc    - UiApp
  DevPath - Fv(7CB8BDC9-F8EB-4F34-AAEA-3EE4AF6516A1)/FvFile(462CAA21-7614-4503-836E-8AB6F4662331)
  Optional- N
Option: 01. Variable: Boot0001   
  Desc    - UEFI QEMU HARDDISK QM00001 
  DevPath - PciRoot(0x0)/Pci(0x1,0x1)/Ata(0x0)
  Optional- Y
Option: 02. Variable: Boot0002   
  Desc    - EFI Internal Shell 1
  DevPath - Fv(7CB8BDC9-F8EB-4F34-AAEA-3EE4AF6516A1)/FvFile(7C04A583-9E3E-4F1C-AD65-E05268D0B4D1)
  Optional- N
Option: 03. Variable: Boot0004   
  Desc    - EFI Internal Shell
  DevPath - Fv(7CB8BDC9-F8EB-4F34-AAEA-3EE4AF6516A1)/FvFile(7C04A583-9E3E-4F1C-AD65-E05268D0B4D1)
  Optional- N
```

## Add InteractiveApp.efi Boot Option

```bash
bcfg boot add 4 InteractiveApp.efi "Interactive app"
Target = 0003.
bcfg: Add Boot0003 as 4
bcfg boot dump
Option: 00. Variable: Boot0003   
  Desc    - InteractiveApp.efi
  DevPath - PciRoot(0x0)/Pci(0x1,0x1)/Ata(0x0)/HD(1,MBR,0xBE1AFDFA)/\InteractiveApp.efi
  Optional- N
Option: 01. Variable: Boot0000   
  Desc    - UiApp
  DevPath - Fv(7CB8BDC9-F8EB-4F34-AAEA-3EE4AF6516A1)/FvFile(462CAA21-7614-4503-836E-8AB6F4662331)
  Optional- N
Option: 02. Variable: Boot0001   
  Desc    - UEFI QEMU HARDDISK QM00001 
  DevPath - PciRoot(0x0)/Pci(0x1,0x1)/Ata(0x0)
  Optional- Y
Option: 03. Variable: Boot0002   
  Desc    - EFI Internal Shell 1
  DevPath - Fv(7CB8BDC9-F8EB-4F34-AAEA-3EE4AF6516A1)/FvFile(7C04A583-9E3E-4F1C-AD65-E05268D0B4D1)
  Optional- N
Option: 04. Variable: Boot0004   
  Desc    - EFI Internal Shell
  DevPath - Fv(7CB8BDC9-F8EB-4F34-AAEA-3EE4AF6516A1)/FvFile(7C04A583-9E3E-4F1C-AD65-E05268D0B4D1)
  Optional- N
```

![Figure 1](Figure/1.png)

## Move InteractiveApp.efi to Position 0

```bash
bcfg boot mv 4 0
bcfg boot dump
Option: 00. Variable: Boot0003   
  Desc    - InteractiveApp.efi
  DevPath - PciRoot(0x0)/Pci(0x1,0x1)/Ata(0x0)/HD(1,MBR,0xBE1AFDFA)/\InteractiveApp.efi
  Optional- N
Option: 01. Variable: Boot0000   
  Desc    - UiApp
  DevPath - Fv(7CB8BDC9-F8EB-4F34-AAEA-3EE4AF6516A1)/FvFile(462CAA21-7614-4503-836E-8AB6F4662331)
  Optional- N
Option: 02. Variable: Boot0001   
  Desc    - UEFI QEMU HARDDISK QM00001 
  DevPath - PciRoot(0x0)/Pci(0x1,0x1)/Ata(0x0)
  Optional- Y
Option: 03. Variable: Boot0002   
  Desc    - EFI Internal Shell 1
  DevPath - Fv(7CB8BDC9-F8EB-4F34-AAEA-3EE4AF6516A1)/FvFile(7C04A583-9E3E-4F1C-AD65-E05268D0B4D1)
  Optional- N
Option: 04. Variable: Boot0004   
  Desc    - EFI Internal Shell
  DevPath - Fv(7CB8BDC9-F8EB-4F34-AAEA-3EE4AF6516A1)/FvFile(7C04A583-9E3E-4F1C-AD65-E05268D0B4D1)
  Optional- N
```

![Figure 2](Figure/2.png)

## Remove InteractiveApp.efi Boot Option

```bash
bcfg boot rm 0
bcfg boot dump
Option: 00. Variable: Boot0000   
  Desc    - UiApp
  DevPath - Fv(7CB8BDC9-F8EB-4F34-AAEA-3EE4AF6516A1)/FvFile(462CAA21-7614-4503-836E-8AB6F4662331)
  Optional- N
Option: 01. Variable: Boot0001   
  Desc    - UEFI QEMU HARDDISK QM00001 
  DevPath - PciRoot(0x0)/Pci(0x1,0x1)/Ata(0x0)
  Optional- Y
Option: 02. Variable: Boot0002   
  Desc    - EFI Internal Shell 1
  DevPath - Fv(7CB8BDC9-F8EB-4F34-AAEA-3EE4AF6516A1)/FvFile(7C04A583-9E3E-4F1C-AD65-E05268D0B4D1)
  Optional- N
Option: 03. Variable: Boot0004   
  Desc    - EFI Internal Shell
  DevPath - Fv(7CB8BDC9-F8EB-4F34-AAEA-3EE4AF6516A1)/FvFile(7C04A583-9E3E-4F1C-AD65-E05268D0B4D1)
  Optional- N
```

![Figure 3](Figure/3.png)
