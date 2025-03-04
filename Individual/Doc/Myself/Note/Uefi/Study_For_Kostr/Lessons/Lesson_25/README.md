# **PCD Access Functions in EDK2**

PCD access functions allow retrieving and setting values for **Fixed, Feature Flag, Patchable, Dynamic, and DynamicEx PCDs**.  

## **1. Fixed at Build PCD (`PcdsFixedAtBuild`)**  

**📌 Characteristics:**  

- **Immutable** at runtime (set at build time).  
- Used for **constant values** like buffer sizes, magic numbers, or compile-time settings.  

| Function | Description |
|----------|-------------|
| `FixedPcdGetBool(TokenName)` | Get a `BOOLEAN` fixed PCD. |
| `FixedPcdGet8(TokenName)` | Get an `UINT8` fixed PCD. |
| `FixedPcdGet16(TokenName)` | Get an `UINT16` fixed PCD. |
| `FixedPcdGet32(TokenName)` | Get an `UINT32` fixed PCD. |
| `FixedPcdGet64(TokenName)` | Get an `UINT64` fixed PCD. |
| `FixedPcdGetPtr(TokenName)` | Get a `VOID*` fixed PCD (pointer). |
| `FixedPcdGetSize(TokenName)` | Get the **size** of a pointer PCD. |

**Example:**  

```c
UINT32 BufferSize = FixedPcdGet32(PcdBufferSize);
CONST CHAR8* Str = FixedPcdGetPtr(PcdString);
UINTN StrLen = FixedPcdGetSize(PcdString);
```

```ini
[PcdsFixedAtBuild]
  gMyPkgTokenSpaceGuid.PcdBufferSize|0x1000|UINT32|0
  gMyPkgTokenSpaceGuid.PcdString|"Hello, UEFI"|VOID*|0
```

---

## **2. Feature Flag PCD (`PcdsFeatureFlag`)**  

**📌 Characteristics:**  

- **Boolean-only** (`TRUE/FALSE`), cannot be modified at runtime.  
- Used for **compile-time feature toggles (`#if`)**.  

| Function | Description |
|----------|-------------|
| `FeaturePcdGet(TokenName)` | Get a `BOOLEAN` feature flag PCD. |

**Example:**  

```c
#if FeaturePcdGet(PcdEnableDebug)
// Enable debug mode
EnableDebugMode();
#endif
```

```ini
[PcdsFeatureFlag]
  gMyPkgTokenSpaceGuid.PcdEnableDebug|TRUE|BOOLEAN|0
```

---

## **3. Patchable PCD (`PcdsPatchableInModule`)**  

**📌 Characteristics:**  

- Can be modified **within a single module**, but not across modules.  
- Used for **temporary or module-local settings**.  

| Get Function | Set Function |
|--------------|-------------|
| `PatchPcdGetBool(TokenName)` | `PatchPcdSetBool(TokenName, Value)` |
| `PatchPcdGet8(TokenName)` | `PatchPcdSet8(TokenName, Value)` |
| `PatchPcdGet16(TokenName)` | `PatchPcdSet16(TokenName, Value)` |
| `PatchPcdGet32(TokenName)` | `PatchPcdSet32(TokenName, Value)` |
| `PatchPcdGet64(TokenName)` | `PatchPcdSet64(TokenName, Value)` |
| `PatchPcdGetPtr(TokenName)` | `PatchPcdSetPtr(TokenName, Size, Buffer)` |
| `PatchPcdGetSize(TokenName)` | _No Set Function_ |

**Example:**  

```c
UINT32 PatchVal = PatchPcdGet32(PcdPatchableValue);
PatchPcdSet32(PcdPatchableValue, PatchVal + 1);
```

```ini
[PcdsPatchableInModule]
  gMyPkgTokenSpaceGuid.PcdPatchableValue|0x10|UINT32|0
```

---

## **4. Dynamic PCD (`PcdsDynamic`)**  

**📌 Characteristics:**  

- **Globally modifiable** at runtime across modules.  
- Used for **runtime configuration settings**.  

| Get Function | Set Function |
|--------------|-------------|
| `PcdGetBool(TokenName)` | `PcdSetBoolS(TokenName, Value)` |
| `PcdGet8(TokenName)` | `PcdSet8S(TokenName, Value)` |
| `PcdGet16(TokenName)` | `PcdSet16S(TokenName, Value)` |
| `PcdGet32(TokenName)` | `PcdSet32S(TokenName, Value)` |
| `PcdGet64(TokenName)` | `PcdSet64S(TokenName, Value)` |
| `PcdGetPtr(TokenName)` | `PcdSetPtrS(TokenName, SizeOfBuffer, Buffer)` |
| `PcdGetSize(TokenName)` | _No Set Function_ |

**Example:**  

```c
UINT32 Timeout = PcdGet32(PcdNetworkTimeout);
PcdSet32S(PcdNetworkTimeout, 5000);
```

```ini
[PcdsDynamic]
  gMyPkgTokenSpaceGuid.PcdNetworkTimeout|3000|UINT32|0
```

---

## **5. DynamicEx PCD (`PcdsDynamicEx`)**  

**📌 Characteristics:**  

- Same as `Dynamic`, but **scoped by a GUID**.  
- Used for **avoiding name conflicts** between different modules.  

| Get Function | Set Function |
|--------------|-------------|
| `PcdGetExBool(Guid, TokenName)` | `PcdSetExBoolS(Guid, TokenName, Value)` |
| `PcdGetEx8(Guid, TokenName)` | `PcdSetEx8S(Guid, TokenName, Value)` |
| `PcdGetEx16(Guid, TokenName)` | `PcdSetEx16S(Guid, TokenName, Value)` |
| `PcdGetEx32(Guid, TokenName)` | `PcdSetEx32S(Guid, TokenName, Value)` |
| `PcdGetEx64(Guid, TokenName)` | `PcdSetEx64S(Guid, TokenName, Value)` |
| `PcdGetExPtr(Guid, TokenName)` | `PcdSetExPtrS(Guid, TokenName, SizeOfBuffer, Buffer)` |
| `PcdGetExSize(Guid, TokenName)` | _No Set Function_ |

**Example:**  

```c
EFI_GUID MyGuid = gMyPkgTokenSpaceGuid;
UINT32 Value = PcdGetEx32(&MyGuid, PcdSharedConfig);
PcdSetEx32S(&MyGuid, PcdSharedConfig, 42);
```

```ini
[PcdsDynamicEx]
  gMyPkgTokenSpaceGuid.PcdSharedConfig|0x20|UINT32|0
```

---

## **Summary Table**

| **PCD Type** | **Modifiable?** | **Scope** | **Access Functions** |
|-------------|---------------|---------|----------------|
| **Fixed at Build** | ❌ No | **Build-time only** | `FixedPcdGet<Type>(TokenName)` |
| **Feature Flag** | ❌ No | **Build-time only** (`BOOLEAN` only) | `FeaturePcdGet(TokenName)` |
| **Patchable** | ✅ Yes (module-only) | **Local to a module** | `PatchPcdGet<Type>(TokenName)`, `PatchPcdSet<Type>(TokenName, Value)` |
| **Dynamic** | ✅ Yes | **Globally modifiable** | `PcdGet<Type>(TokenName)`, `PcdSet<Type>S(TokenName, Value)` |
| **DynamicEx** | ✅ Yes | **Globally modifiable with GUID scope** | `PcdGetEx<Type>(Guid, TokenName)`, `PcdSetEx<Type>S(Guid, TokenName, Value)` |
