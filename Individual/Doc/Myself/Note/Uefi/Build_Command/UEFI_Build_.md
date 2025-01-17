# EDK2 Build Commands for GCC5 and MSVC

This document outlines the build commands for different EDK2 packages using **GCC5** and **MSVC**.

The EDK2 build system uses various command-line flags to customize and control the build process. Below is a comprehensive list of parameters that can be used in the `build` command.

---

## **Common Parameters and Options**  

1. **`-p` / `--platform` (Platform Description File)**  
   Specifies the platform file (.dsc) to use for the build. This file contains the project settings, module components, and configuration definitions for the platform.

   **Valid Parameters:**  
   The path to the `.dsc` file that defines the platform.

   **Example:**

   ```bash
   -p / --platform OvmfPkg/OvmfPkgX64.dsc
   ```

2. **`-m` / `--module` (Module Information)**  
   Specifies the module or component to build, typically used with a `.inf` file to build individual modules.

   **Valid Parameters:**  
   The path to the `.inf` file of the module you want to build.

   **Example:**

   ```bash
   -m / --module edk2/MdeModulePkg/Application/HelloWorld/HelloWorld.inf
   ```

3. **`-t` / `--tagname` (Toolchain/Tag)**  
   Defines the toolchain used to build the project or assigns a tag to the build. It helps identify the build configuration.

   **Valid Parameters:**  
   - `GCC5`: GNU Compiler Collection 5  
   - `VS2022`: Microsoft Visual Studio 2022  
   - `CLANG`: Clang  
   - `ICC`: Intel Compiler  

   **Example:**

   ```bash
   -t / --tagname GCC5
   -t / --tagname VS2022
   ```

4. **`-a` / `--arch` (Architecture)**  
   Specifies the target architecture for the build. The architecture defines the target platform.

   **Valid Parameters:**  
   - `X64`: 64-bit architecture  
   - `ARM`: ARM architecture (used for ARM-based processors)  
   - `IA32`: 32-bit Intel architecture (legacy)  

   **Example:**

   ```bash
   -a / --arch X64
   -a / --arch ARM
   -a / --arch IA32
   ```

5. **`-b` / `--buildtarget` (Build Option)**  
   Specifies the build type or target. It defines the optimization and debugging settings for the build.

   **Valid Parameters:**  
   - `NOOPT`: No optimization (useful for debugging)  
   - `DEBUG`: Debug build (enables debugging features)  
   - `RELEASE`: Optimized release build (removes debugging symbols for efficiency)  
   - `SPEED`: Optimization for speed  
   - `PROFILE`: Builds the project with profiling enabled

   **Example:**

   ```bash
   -b / --buildtarget NOOPT
   -b / --buildtarget DEBUG
   -b / --buildtarget RELEASE
   -b / --buildtarget SPEED
   -b / --buildtarget PROFILE
   ```

6. **`-D` / `--define` (Define Preprocessor Macro)**  
   Defines a macro for the preprocessor. This option is useful for enabling or disabling features or configurations during the build process.

   **Valid Parameters:**  
   Any valid preprocessor macro you wish to define (e.g., enable debugging, enable specific features, or set debug levels).

   **Example:**

   ```bash
   -D / --define SOURCE_DEBUG_ENABLE
   -D / --define DEBUG_ON_SERIAL_PORT
   -D / --define DEBUG_LEVEL=3
   ```

---

## **Examples of Full Build Commands**

Here is the **shorthand version** and **full version** for each of the provided commands:

### **For GCC Toolchain (GCC5):**

```bash
# Build for EmulatorPkg
build -p edk2/EmulatorPkg/EmulatorPkg.dsc -t GCC5 -a X64
build --platform edk2/EmulatorPkg/EmulatorPkg.dsc --tagname GCC5 --arch X64

# Build for AppPkg
build -p edk2-libc/AppPkg/AppPkg.dsc -t GCC5 -a X64
build --platform edk2-libc/AppPkg/AppPkg.dsc --tagname GCC5 --arch X64

# Build for OvmfPkg
build -p OvmfPkg/OvmfPkgX64.dsc -t GCC5 -a X64
build --platform OvmfPkg/OvmfPkgX64.dsc --tagname GCC5 --arch X64

# Build OvmfPkg with Debug option
build -p OvmfPkg/OvmfPkgX64.dsc -t GCC5 -a X64 -b DEBUG -D DEBUG_ON_SERIAL_PORT
build --platform OvmfPkg/OvmfPkgX64.dsc --tagname GCC5 --arch X64 --buildtarget DEBUG --define DEBUG_ON_SERIAL_PORT

build -p edk2/SamModulePkg/SamModulePkg.dsc -t GCC5 -a X64 -b DEBUG
build --platform edk2/SamModulePkg/SamModulePkg.dsc --tagname GCC5 --arch X64 --buildtarget DEBUG
```

### **For Microsoft Visual Studio (VS2022):**

```bash
# Build for EmulatorPkg
build -p edk2/EmulatorPkg/EmulatorPkg.dsc -t VS2022 -a X64
build --platform edk2/EmulatorPkg/EmulatorPkg.dsc --tagname VS2022 --arch X64

# Build for AppPkg
build -p edk2-libc/AppPkg/AppPkg.dsc -t VS2022 -a X64
build --platform edk2-libc/AppPkg/AppPkg.dsc --tagname VS2022 --arch X64

# Build for HelloWorld module
build -p edk2/MdeModulePkg/MdeModulePkg.dsc -m edk2/MdeModulePkg/Application/HelloWorld/HelloWorld.inf -t VS2022 -a X64
build --platform edk2/MdeModulePkg/MdeModulePkg.dsc --module edk2/MdeModulePkg/Application/HelloWorld/HelloWorld.inf --tagname VS2022 --arch X64

# Build OvmfPkg with optimization and debug options
build -p edk2/OvmfPkg/OvmfPkgX64.dsc -t VS2022 -a X64 -b NOOPT -D SOURCE_DEBUG_ENABLE
build --platform edk2/OvmfPkg/OvmfPkgX64.dsc --tagname VS2022 --arch X64 --buildtarget NOOPT --define SOURCE_DEBUG_ENABLE

# Build for SamModulePkg
build -p edk2/SamModulePkg/SamModulePkg.dsc -t VS2022 -a X64
build --platform edk2/SamModulePkg/SamModulePkg.dsc --tagname VS2022 --arch X64
```
