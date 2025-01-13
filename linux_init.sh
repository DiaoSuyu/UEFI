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

# Update submodule
git submodule update --init --recursive

# Build edk2 basetools
make -C edk2/BaseTools

# Build ACPICA
make -C acpica
