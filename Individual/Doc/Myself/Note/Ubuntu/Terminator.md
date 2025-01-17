# The Guideline of Terminator

This guide provides instructions for installing, configuring, and using Terminator, a powerful terminal emulator for Linux.

---

## 1. Installation

To install Terminator, follow these steps:

```bash
sudo add-apt-repository ppa:gnome-terminator
sudo apt update
sudo apt install terminator
```

---

## 2. Configuration

### 1) Set Terminator as the Default Terminal

To make Terminator the default terminal emulator, run the following commands:

```bash
gsettings set org.gnome.desktop.default-applications.terminal exec /usr/bin/terminator
gsettings set org.gnome.desktop.default-applications.terminal exec-arg "-x"
```

### 2) Recover the Default Terminal

If you want to revert to the default terminal emulator, use these commands:

```bash
gsettings reset org.gnome.desktop.default-applications.terminal exec
gsettings reset org.gnome.desktop.default-applications.terminal exec-arg
```

---

## 3. Shortcut Keys

Terminator provides a variety of shortcut keys to improve productivity. Below are some commonly used shortcuts:

### Window Management

- **Split Horizontally**: `Ctrl + Shift + O`
- **Split Vertically**: `Ctrl + Shift + E`
- **Close Terminal**: `Ctrl + Shift + W`
- **Toggle Fullscreen**: `F11`
- **Zoom In**: `Ctrl + +`
- **Zoom Out**: `Ctrl + -`
- **Reset Zoom**: `Ctrl + 0`

### Tab Management

- **New Tab**: `Ctrl + Shift + T`
- **Next Tab**: `Ctrl + PageDown`
- **Previous Tab**: `Ctrl + PageUp`
- **Close Tab**: `Ctrl + Shift + W`

### Navigation

- **Move to Next Terminal**: `Alt + Right Arrow`
- **Move to Previous Terminal**: `Alt + Left Arrow`
- **Move to Terminal Above**: `Alt + Up Arrow`
- **Move to Terminal Below**: `Alt + Down Arrow`

### Miscellaneous

- **Copy Text**: `Ctrl + Shift + C`
- **Paste Text**: `Ctrl + Shift + V`
- **Search**: `Ctrl + Shift + F`
- **Clear Terminal**: `Ctrl + Shift + G`

---

## 4. Conclusion

Terminator is a highly customizable and efficient terminal emulator for Linux. By mastering its features and shortcuts, you can significantly enhance your workflow.

For more information, visit the [Terminator GitHub page](https://github.com/gnome-terminator/terminator).
