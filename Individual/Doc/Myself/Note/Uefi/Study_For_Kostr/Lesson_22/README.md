# **Difference Between `PcdsFeatureFlag` and `PcdsFixedAtBuild`, `FeaturePcd` and `FixedPcd`**  

In **EDK2**, both `PcdsFeatureFlag` and `PcdsFixedAtBuild` are part of the **Platform Configuration Database (PCD)** mechanism, used to configure platform parameters at build or runtime. The key differences are as follows:  

---

## **1. `PcdsFeatureFlag` vs. `PcdsFixedAtBuild`**  

| Type               | `PcdsFeatureFlag`  | `PcdsFixedAtBuild` |
|--------------------|-------------------|--------------------|
| **Data Type**      | `BOOLEAN`          | Any type (`UINT8`, `UINT32`, `BOOLEAN`, etc.) |
| **Purpose**        | Enables/disables a feature | Stores a fixed value determined at build time |
| **Modifiable?**    | **No**, determined at build time | **No**, determined at build time |
| **Usage**          | Used in `#if` macros to enable/disable features | Defined at build time, does not affect code logic |
| **Example**        | `#if FixedPcdGetBool(PcdFeatureX) // Enable feature` | `UINT32 val = FixedPcdGet32(PcdBuildTimeValue);` |
| **Typical Use Case** | Toggling feature enablement | Storing fixed values for configuration |

### **1.1 Example Usage**

```c
// Example of PcdsFeatureFlag
#if FixedPcdGetBool(PcdFeatureEnableX)
  // This code is only compiled if PcdFeatureEnableX = TRUE
#endif

// Example of PcdsFixedAtBuild
UINT32 Value = FixedPcdGet32(PcdSomeBuildValue);  // Value is fixed at build time
```

---

## **2. `FeaturePcd` vs. `FixedPcd`**  

These are shorthand names for `PcdsFeatureFlag` and `PcdsFixedAtBuild`, respectively:

| **Short Name** | **Full Type**       | **Meaning** |
|--------------|-----------------|----------------------|
| `FeaturePcd` | `PcdsFeatureFlag` | Only used for `BOOLEAN` feature toggles |
| `FixedPcd`   | `PcdsFixedAtBuild` | Fixed value determined at build time, non-modifiable |

- `FeaturePcdGet(PcdX)` is equivalent to `FixedPcdGetBool(PcdX)`.
- `FixedPcdGet(PcdY)` is equivalent to `FixedPcdGet32(PcdY)` (or other data types).

### **2.1 Example Usage**

```c
if (FeaturePcdGet(PcdEnableFeature)) {
  // Executes only if PcdEnableFeature is TRUE
}

UINT32 ConfigValue = FixedPcdGet(PcdBuildTimeConfig);
```

---

### **Summary**  

| Type | Modifiable? | Purpose | Data Type | Use Case |
|------|------------|---------|-----------|----------|
| `PcdsFeatureFlag` (`FeaturePcd`) | **No** | Controls feature toggling (`BOOLEAN` only) | `BOOLEAN` | Preprocessor `#if` to enable/disable features |
| `PcdsFixedAtBuild` (`FixedPcd`) | **No** | Stores a fixed value at build time | `UINT8/UINT32/BOOLEAN` | Hardcoded configuration values in firmware |

### **Simple Understanding**  

- **`PcdsFeatureFlag` / `FeaturePcd` → Used to toggle features (`#if` macros).**  
- **`PcdsFixedAtBuild` / `FixedPcd` → Used to store fixed values (read at runtime).**  

If you need to control whether a feature is enabled, use **`PcdsFeatureFlag` (`FeaturePcd`)**.  
If you need a constant, non-modifiable value, use **`PcdsFixedAtBuild` (`FixedPcd`)**.
