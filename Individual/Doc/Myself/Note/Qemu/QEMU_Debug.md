# QEMU Debugging OVMF (UEFI Firmware) on Linux

## Prerequisites

Before you begin, ensure that you have the following tools and libraries installed:

1. **QEMU** - for virtualization
2. **OVMF** - UEFI firmware
3. A valid disk image file (`disk.img`) to be loaded into QEMU.

You can install QEMU on Ubuntu using the following commands:

```bash
sudo apt update
sudo apt install qemu qemu-system-x86 qemu-utils
```

Make sure that you have the `OVMF.fd` file and a disk image file (e.g., `disk.img`) ready.

---

## Operation Guide

### A. Normal use

#### 1. Start QEMU with USB 2.0 (EHCI)

Use the following command to start QEMU with **USB 2.0 (EHCI)** controller and mount the `disk.img`.

```bash
qemu-system-x86_64 \
    -drive if=pflash,format=raw,file=OVMF.fd,id=BIOS-OVMF \
    -drive if=none,format=raw,file=disk.img,id=usb-drive \
    -device usb-ehci,id=usb-ehci \
    -device usb-storage,drive=usb-drive,bus=usb-ehci.0 \
    -nographic \
    -net none
```

- `-drive if=pflash,format=raw,file=OVMF.fd,id=BIOS-OVMF`: Load the UEFI firmware (`OVMF.fd`).
- `-drive if=none,format=raw,file=disk.img,id=usb-drive`: Attach `disk.img` as a disk image.
- `-device usb-ehci,id=usb-ehci`: Use a USB 2.0 EHCI controller.
- `-device usb-storage,drive=usb-drive,bus=usb-ehci.0`: Attach `usb-drive` as a USB storage device to the USB bus.
- `-nographic`: Disable graphical display and use the console for debugging.
- `-net none`: Disable network devices.

#### 2. Start QEMU with USB 3.0 (xHCI)

To use **USB 3.0 (xHCI)** controller, you can run the following command to mount the `disk.img`.

```bash
qemu-system-x86_64 \
    -drive if=pflash,format=raw,file=OVMF.fd,id=BIOS-OVMF \
    -drive if=none,format=raw,file=disk.img,id=usb-drive \
    -device qemu-xhci,id=usb-xhci \
    -device usb-storage,drive=usb-drive,bus=usb-xhci.0 \
    -nographic \
    -net none
```

- `-device qemu-xhci,id=usb-xhci`: Use a USB 3.0 xHCI controller.
- `-device usb-storage,drive=usb-drive,bus=usb-xhci.0`: Attach `usb-drive` as a USB storage device to the USB 3.0 bus.

#### 3. Start QEMU with AHCI Storage Controller

To use an **AHCI** storage controller, you can run the following command to mount the `disk.img`.

```bash
qemu-system-x86_64 \
    -drive if=pflash,format=raw,file=OVMF.fd,id=BIOS-OVMF \
    -drive if=none,format=raw,file=disk.img,id=ahci-ssd \
    -device ahci,id=ahci \
    -device ide-hd,drive=ahci-ssd,bus=ahci.0 \
    -nographic \
    -net none
```

- `-device ahci,id=ahci`: Use an AHCI storage controller.
- `-device ide-hd,drive=ahci-ssd,bus=ahci.0`: Attach `ahci-ssd` as an IDE hard drive to the AHCI controller.

#### 4. Start QEMU with VirtIO Storage Controller

To use a **VirtIO** storage controller, you can run the following command to mount the `disk.img` as an SSD.

```bash
qemu-system-x86_64 \
    -drive if=pflash,format=raw,file=OVMF.fd,id=BIOS-OVMF \
    -drive if=none,format=raw,file=disk.img,id=virtio-ssd \
    -device virtio-blk,drive=virtio-ssd \
    -nographic \
    -net none
```

- `-device virtio-blk,drive=virtio-ssd`: Use VirtIO block device to attach `virtio-ssd` as a hard drive..

#### 5. Start QEMU with NVMe Storage Controller

To use an **NVMe** storage controller, you can run the following command to mount the `disk.img`.

```bash
qemu-system-x86_64 \
    -drive if=pflash,format=raw,file=OVMF.fd,id=BIOS-OVMF \
    -drive if=none,format=raw,file=disk.img,id=nvme-ssd \
    -device nvme,drive=nvme-ssd,serial=1234-5678 \
    -nographic \
    -net none
```

- `-device nvme,drive=nvme-ssd,serial=1234-5678`: Use an NVMe storage controller and attach `nvme-ssd` with a unique serial number.

#### 6. Start QEMU with IDE Storage Controller

To use an IDE storage controller and mount a FAT-formatted directory (hda-contents), you can run the following command.

```bash
qemu-system-x86_64 \
    -drive if=pflash,format=raw,file=OVMF.fd,id=BIOS-OVMF \
    -drive file=fat:rw:hda-contents,format=raw,if=ide,index=0 \
    -nographic \
    -net none
```

- `drive file=fat:rw:hda-contents,format=raw,if=ide,index=0`
  - Mounts the `hda-contents` directory as a FAT-formatted IDE drive.

  - `file=fat:rw:hda-contents`: Specifies the directory to be mounted as a FAT filesystem with read-write access.

  - `format=raw`: Explicitly sets the format to raw (avoids automatic format detection warnings).

  - `if=ide`: Connects the drive to the IDE interface.

  - `index=0`: Assigns the drive to the first position (index 0) on the IDE controller.

---

### B. Debugging use

#### 1. Enable DebugLib, Enable GDB and Start QEMU

Take EHCI/IDE as an example.

```bash
qemu-system-x86_64 \
    -drive if=pflash,format=raw,file=OVMF.fd,id=BIOS-OVMF \
    -drive if=none,format=raw,file=disk.img,id=usb-drive \
    -device usb-ehci,id=usb-ehci \
    -device usb-storage,drive=usb-drive,bus=usb-ehci.0 \
    -debugcon file:debug.log \
    -global isa-debugcon.iobase=0x402 \
    -nographic \
    -net none \
    -s

qemu-system-x86_64 \
    -drive if=pflash,format=raw,file=OVMF.fd,id=BIOS-OVMF \
    -drive file=fat:rw:hda-contents,format=raw,if=ide,index=0 \
    -debugcon file:debug.log \
    -global isa-debugcon.iobase=0x402 \
    -nographic \
    -net none \
    -s

```

- `debugcon file:debug.log`: Redirects debug console output to the file `debug.log`.

- `global isa-debugcon.iobase=0x402`: Sets the I/O base address for the debug console to 0x402.

- `s`: Starts a GDB debugging server on TCP port 1234, allowing connection via `gdb target remote:1234`.

## Notes

1. **OVMF Firmware**: Ensure you have downloaded and configured the OVMF firmware (typically named `OVMF.fd`).
2. **Disk Image**: Ensure your disk image (e.g., `disk.img`) is created and ready. You can create it using the `qemu-img` tool.
3. **Network Configuration**: The commands above disable the network device by default (`-net none`). You can modify or remove this option if you need to enable networking.

---

## Conclusion

By using QEMU with OVMF firmware, you can emulate a UEFI system for development and debugging. These commands provide common hardware configurations (USB, AHCI, VirtIO, and NVMe) to help you get started with UEFI debugging. Modify the commands according to your specific requirements. If you encounter any issues, refer to the error messages for troubleshooting or adjust the parameters based on your needs.
