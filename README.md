# Cummins J90280.05 firmware reverse engineering

The purpose of this repo is to reverse engineer the firmware for the Cummins CM550 ECU well enough to understand how the inner working work.

---

# 🚀 **GHIDRA AUTOMATION WORKFLOW** 

**This project features a complete CSV-driven automation system that transforms raw firmware into fully analyzed, human-readable code through Ghidra scripting.**

## **🎯 One-Command Setup**

For a fresh firmware import, run **ONE script** in Ghidra:
```
ghidra_scripts/MasterAnalysisSetup.java
```

This automatically executes all analysis in ~30 seconds:
- ✅ Memory map setup (MC68336 architecture)
- ✅ Function renaming (12 functions) 
- ✅ Global variable creation (14 variables)
- ✅ Structure application (3 structures)
- ✅ Label creation (13 control flow labels) 
- ✅ Constant documentation (13 magic numbers)
- ✅ Enum creation (6 enums with 15+ members)

**Result**: Firmware goes from cryptic to human-readable instantly.

## **📊 The Knowledge Database (CSV Files)**

Your discoveries are stored in **7 CSV files** in `ghidra/J90280.05.rep/` - these ARE the playbook:

- **`function_renames.csv`** - Function names (vp44FuelTempHandler, canMessageDispatcher, etc.)
- **`global_variables.csv`** - Typed variables (param_table_main, sensor_data_buffer, etc.)  
- **`structure_definitions.csv`** - C-style structures (parameter_table_t, can_param_msg_t, etc.)
- **`labels.csv`** - Control flow labels (switch_case_16, call_vp44_handler, etc.)
- **`constants.csv`** - Magic numbers (VP44_FUEL_TEMP_OFFSET=112, RPM_MULTIPLIER=4, etc.)
- **`enums.csv`** - Logical groupings (CAN_MSG_TYPE, PARAM_VALIDATION, etc.) 
- **`arrays.csv`** - Arrays/buffers (parameter_buffer[16], sensor_data_buffer[256], etc.)

### **🔄 CSV Sorting Standards (Team Collaboration)**

**All CSV files are sorted to prevent merge conflicts during team collaboration:**

- **`function_renames.csv`**: Sorted by **address** (hex)
- **`global_variables.csv`**: Sorted by **address** (hex) 
- **`structure_definitions.csv`**: Sorted by **struct_name**, then **field_name**
- **`constants.csv`**: Sorted by **address** (hex)
- **`labels.csv`**: Sorted by **address** (hex)
- **`enums.csv`**: Sorted by **enum_name**, then **value**
- **`arrays.csv`**: Sorted by **address** (hex)

**Why this matters:**
- ✅ **No merge conflicts** when team members add entries
- ✅ **Predictable ordering** makes entries easy to find
- ✅ **Code reviewable** discoveries in consistent format
- ✅ **Scalable to large teams** with systematic organization

### **🤖 Automated CSV Sorting**

**Never worry about CSV ordering again!** 

Run the setup script once after cloning:
```bash
./setup-hooks.sh
```

This configures a **pre-commit hook** that automatically:
- ✅ **Sorts all CSV files** according to standardization rules  
- ✅ **Prevents merge conflicts** before they happen
- ✅ **Re-stages sorted files** automatically during commit
- ✅ **Shows colorful feedback** about what was sorted

**When adding new entries, they will automatically sort into the correct position during git commit.**

## **🔄 The Perfect Workflow**

### **⚡ Quick Workflow (Recommended):**
1. **🔍 Discover** new functions/addresses in Ghidra
2. **📝 Update CSVs** with findings
3. **⚡ Press `Ctrl+Shift+E`** in Ghidra (or run `ApplyAndExport.java`)
4. **🤖 Claude Code sees changes** immediately in exported files

### **🎯 One-Command Automation:**
The **`ApplyAndExport.java`** script combines both setup and export in one keystroke:
- **Keyboard shortcut:** `Ctrl+Shift+E`
- **Menu:** Tools → Apply and Export
- **What it does:** Runs MasterAnalysisSetup + ExportAnalysisResults automatically

### **Traditional Workflow (Manual):**
1. **🔍 Discover** new functions/addresses in Ghidra
2. **📝 Update CSVs** with findings
3. **🚀 Run MasterAnalysisSetup.java** - applies changes instantly
4. **📤 Run ExportAnalysisResults.java** - exports to `working/` for Claude Code
5. **🤖 Claude Code sees changes** immediately in exported files

### **Fresh Import:**
1. Import firmware → 2. Run MasterAnalysisSetup → 3. Run ExportAnalysisResults → **Done!**

## **📤 Claude Code Integration**

**ghidra_scripts/ExportAnalysisResults.java** creates:
- **`ghidra/CM550.rep/working/J90280.05.ghidra.asm`** - Assembly with meaningful names/comments
- **`ghidra/CM550.rep/working/J90280.05.ghidra.cpp`** - C++ decompilation with types

**Claude Code instantly sees your latest Ghidra analysis!**

## **🔧 Available Scripts** (in `ghidra_scripts/`)

### **⚡ Quick Workflow Script (Recommended):**
- **`ApplyAndExport.java`** - **FASTEST WORKFLOW!** Combines MasterAnalysisSetup + ExportAnalysisResults
  - Keyboard: `Ctrl+Shift+E`
  - Menu: Tools → Apply and Export
  - Perfect for: Iterative reverse engineering (update CSV → press hotkey → done!)

### **Master Scripts:**
- **`MasterAnalysisSetup.java`** - Complete analysis automation (functions, structures, enums, labels, etc.)
- **`ExportAnalysisResults.java`** - Export analysis to working/ for Claude Code integration

### **Individual Scripts:**
- **`ghidra_scripts/SetupMemoryMap.java`** - MC68336 memory layout with 8KB EEPROM
- **`ghidra_scripts/BulkFunctionRenamer.java`** - CSV-driven function renaming
- **`ghidra_scripts/BulkVariableCreator.java`** - Typed global variables  
- **`ghidra_scripts/BulkStructureCreator.java`** - Structure definitions
- **`ghidra_scripts/BulkLabelCreator.java`** - Control flow labels
- **`ghidra_scripts/BulkConstantCreator.java`** - Magic number documentation
- **`ghidra_scripts/BulkEnumCreator.java`** - Enumeration creation
- **`ghidra_scripts/BulkArrayCreator.java`** - Array/buffer definitions
- **`ghidra_scripts/BulkFunctionParameterRenamer.java`** - Function parameter naming

## **🔄 Script Updates & Deployment**

**When scripts are modified in the project directory:**

1. **Copy to Ghidra Scripts Directory:**
   ```bash
   # Copy individual script
   cp ghidra_scripts/SetupMemoryMap.java ~/ghidra_scripts/
   cp ghidra_scripts/MasterAnalysisSetup.java ~/ghidra_scripts/
   
   # Copy all scripts (after updates)
   cp ghidra_scripts/*.java ~/ghidra_scripts/
   ```

2. **Verify Script Updates:**
   ```bash
   ls -la ~/ghidra_scripts/*.java
   ```

3. **Refresh Ghidra Script Manager:**
   - In Ghidra: **Window → Script Manager**
   - Click **Refresh** button to reload updated scripts

**⚠️ Important:** Always copy updated scripts from `ghidra_scripts/` to `~/ghidra_scripts/` directory after modifications to ensure Ghidra uses the latest versions.

**📁 Script Organization:**
- **`ghidra_scripts/`** - Project scripts (version controlled)
- **`~/ghidra_scripts/`** - User Ghidra directory (runtime execution)

## **💡 Pro Tips for Claude Code Sessions**

1. **CSV files contain complete knowledge** - reference them for discoveries
2. **Exported files have latest analysis** - `working/*.asm` and `working/*.cpp` 
3. **Update workflow**: CSV → MasterAnalysisSetup → ExportAnalysisResults → Claude Code
4. **Address references help**: `function_name @ 0x12345` for precise location
5. **This workflow makes Claude Code an extension of Ghidra analysis**

**This represents a 10x+ productivity improvement in firmware reverse engineering.**

---

## **🔧 Ghidra Import Settings**

**File**: `firmware/J90280.05.full.bin` (converted from Intel HEX)  
**Architecture**: 68000:BE:32:default  
**Base Address**: 0x00000000  
**Import Method**: Raw Binary

### **Memory Blocks** (auto-created by ghidra_scripts/SetupMemoryMap.java)
- **Internal Flash**: 0x000000 - 0x007FFF (32KB, R/X)
- **Internal Registers**: 0xFFFF00 - 0xFFFFFF (256B, R/W) 
- **Internal RAM**: 0xFFFE00 - 0xFFFEFF (256B, R/W)
- **External Memory**: 0x800000 - 0x8FFFFF (1MB, R/W) - Parameter system region

---

## **🎯 Key Findings** (stored in CSV knowledge database)

### **Critical Functions:**
- **vp44FuelTempHandler** @ 0x1C538 - VP44 injection pump fuel temperature processing
- **canMessageDispatcher** @ 0x1C846 - CAN message routing by type (16=VP44, 17/19=Alt, 255=Error)
- **buildCanMessage** @ 0x29C52 - J1939 message assembly (fuel%, RPM×4, timing advance)
- **param_address_calc** @ 0x12AFA - EEPROM parameter address calculation (Block×256+Offset)

### **Parameter System:**
- **param_lookup_1/2/3** @ 0xd632/0xd69c/0xd756 - Parameter retrieval with validation
- **param_interpolate** @ 0xd8b4 - EEPROM default value calculator  
- **Parameter tables** @ 0x80CFDx - Runtime parameter storage
- **Reference tables** @ 0x8086xx - Scaling factors and limits

### **Network Architecture:**
- **J1939 functions**: sendJ1939Msg, sendJ1939SingleFrame, sendJ1939MultiFrame
- **VP44 network**: Separate CAN bus for injection pump communication  
- **Message formats**: 8-byte J1939 frames with engine sensor data

**The CSV files contain the complete reverse engineered knowledge base for this firmware.**
