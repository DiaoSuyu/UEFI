#!/bin/bash

# Update source
sudo apt update
 
# Install the required tools
sudo apt install git python3 uuid-dev nasm bison flex build-essential x11proto-xext-dev libx11-dev libxext-dev qemu qemu-system qemu-kvm

# Check if python already points to python3
if ! command -v python &>/dev/null; then
    sudo ln -s /usr/bin/python3 /usr/bin/python
    echo "Python3 mapped to python."
else
    echo "Python is already mapped to python3."
fi

# Update submodule in root path
git submodule update --init

# Update submodule in edk2
cd edk2
git submodule update --init

# Build edk2 basetools
make -C BaseTools

# Build ACPICA
cd ..
make -C acpica
