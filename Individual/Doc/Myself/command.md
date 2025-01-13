# Edk2 Command

## Windows

### Build-Win

```bash
1. build -p edk2\EmulatorPkg\EmulatorPkg.dsc -t VS2022 -a X64
2. build -p edk2-libc\AppPkg\AppPkg.dsc -t VS2022 -a X64
3. build -p edk2\MdeModulePkg\MdeModulePkg.dsc -m edk2\MdeModulePkg\Application\HelloWorld\HelloWorld.inf -t VS2022 -a X64
4. build -p edk2\OvmfPkg\OvmfPkgX64.dsc -t VS2022 -a X64 -b NOOPT -D SOURCE_DEBUG_ENABLE
5. build -p edk2\SamModulePkg\SamModulePkg.dsc -t VS2022 -a X64
```

### Git-Win

```bash
git config --global --edit
git config --global url."https://github.com.cnpmjs.org/".insteadOf "https://github.com/"    # 配置 Git 使用镜像源
git config --global core.protectNTFS false # 关闭NTFS保护，用于解决Git error: invalid path
git submodule update --init --recursive # 递归初始化所有子模块
git submodule sync --recursive   # 递归更新化所有子模块
git submodule add https://XXX XXX  # 在.gitmodules内添加子模块
curl -O https://i-blog.csdnimg.cn/blog_migrate/d2eb3272b3f263a94aa4f04e48466116.png 使用git bash下载文件

如果子模块更新有问题：
1. 检查 .gitmodules 文件
首先，确保 .gitmodules 文件中有关于 Tools/efiXplorer 的条目。文件的内容应该类似于：
[submodule "Tools/efiXplorer"]
    path = Tools/efiXplorer
    url = https://gitee.com/DiaoSuYu/efiXplorer
2. 尝试强制添加子模块
如果你在添加子模块时遇到问题，可以使用 --force 选项来强制添加：
git submodule add --force https://gitee.com/DiaoSuYu/efiXplorer Tools/efiXplorer
3. 初始化和更新子模块
执行以下命令来初始化并更新所有子模块：
git submodule update --init --recursive
4. 检查子模块状态
然后再检查子模块的状态，以确认 Tools/efiXplorer 已被正确添加：
git submodule status
5. 清除旧的子模块目录（如果必要）
如果仍然无法解决问题，可能需要手动清除旧的子模块目录，并重新进行初始化和更新：
rm -rf Tools/efiXplorer
git submodule update --init --recursive
```

### QEMU-Win

```bash
qemu-system-x86_64.exe -L . -bios OVMF.fd -hdd dsydbg.vhd -serial pipe:qemu_pipe_dbg
```

## Linux

### Insufficient permissions

```bash
./linux_init.sh
bash: ./linux_init.sh: Permission denied
chmod +x linux_init.sh
```

### Git-Linux

```bash
git config --global credential.helper store 
```

### Build-Linux

```bash
build -p edk2/EmulatorPkg/EmulatorPkg.dsc -t GCC5 -a X64
build -p edk2-libc/AppPkg/AppPkg.dsc -t GCC5 -a X64
build -p OvmfPkg/OvmfPkgX64.dsc -t GCC5 -a X64
build -p OvmfPkg/OvmfPkgX64.dsc -t GCC5 -a X64 -D DEBUG_ON_SERIAL_PORT
build --platform=OvmfPkg/OvmfPkgX64.dsc --buildtarget=RELEASE --tagname=GCC5 --arch=X64
```

### QEMU-Linux

```bash
qemu-system-x86_64 -drive if=pflash,format=raw,file=Build/OvmfX64/DEBUG_GCC5/FV/OVMF.fd -nographic -net none
```
