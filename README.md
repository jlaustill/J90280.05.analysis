# Cummins J90280.05 firmware reverse engineering

The purpose of this repo is to reverse engineer the firmware for the Cummins CM550 ECU well enough to understand how the inner workings work.

---

# 🏆 **MAJOR MILESTONE: 100% Function & Global Variable Coverage!**

This project has achieved **complete naming coverage** for all functions and global variables:

| Category | Named | Coverage |
|----------|-------|----------|
| **Functions** | 793 | **100%** ✅ |
| **Global Variables** | 6,087 | **100%** ✅ |

The firmware is now fully navigable with meaningful names throughout. Every function has a descriptive name, and every global variable is documented in the knowledge database.

---

# 🚀 **GHIDRA AUTOMATION WORKFLOW** 

**This project features a complete CSV-driven automation system that transforms raw firmware into fully analyzed, human-readable code through Ghidra scripting.**

## **🎯 One-Command Setup**

For a fresh firmware import, run **ONE script** in Ghidra:
```
ghidra_scripts/MasterAnalysisSetup.java
```

This automatically executes all analysis:
- ✅ Memory map setup (MC68336 architecture)
- ✅ Function renaming (793 functions)
- ✅ Global variable creation (6,087 variables)
- ✅ Structure application (433 structure fields)
- ✅ Label creation (3,495 control flow labels)
- ✅ Constant documentation (73 magic numbers)
- ✅ Enum creation (464 enum entries)

**Result**: Firmware goes from cryptic to human-readable instantly.

## **📊 The Knowledge Database (CSV Files)**

Your discoveries are stored in **9 CSV files** in `ghidra/CM550.rep/` - these ARE the playbook:

- **`function_renames.csv`** - Function names (vp44FuelTempHandler, canMessageDispatcher, etc.)
- **`function_parameters.csv`** - Function parameter names and types
- **`global_variables.csv`** - Typed variables (param_table_main, sensor_data_buffer, etc.)
- **`local_variables.csv`** - Decompiler local variable renames (matched by first-use address)
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

### **⚠️ Enum Sizing Requirements (Critical)**

Enum sizes in `enums.csv` **must match the assembly instruction operand size**:
- `move.b` (byte operations) → enum size = **1**
- `move.w` (word operations) → enum size = **2**
- `move.l` (long/dword operations) → enum size = **4**

**Why this matters**: If enum size doesn't match the variable size, Ghidra creates overlapping symbols (shown with underscore prefix like `_variable_name`), and enum member names won't appear in switch statements.

**How to verify**: Check the disassembly for how the variable is accessed:
```assembly
move.w  d0,(main_loop_phase_index).w   ; Variable is 2 bytes → enum size = 2
move.l  d1,(fuel_sync_state).l         ; Variable is 4 bytes → enum size = 4
```

**Example fix**: If `switch(_my_variable)` shows underscore:
1. Find the variable in `global_variables.csv`
2. Check assembly to determine actual operand size
3. Update both variable size AND enum size to match

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

### **⚠️ CRITICAL: CSV-Only Changes**

**NEVER make changes directly in Ghidra** (via MCP tools or manual edits). All changes MUST be made in CSV files only, then applied via ApplyAndExport.

**Why?**
- Direct Ghidra changes are NOT persisted to CSVs (source of truth)
- Creates inconsistency between CSV and Ghidra state
- Can cause unexpected side effects (e.g., variable types becoming `undefined`)
- The Ghidra project can be rebuilt from CSVs, but not vice versa

**Pre-Commit Requirements:**
1. All changes are in CSV files (NOT made directly in Ghidra)
2. ApplyAndExport (`Ctrl+Shift+E`) was run in Ghidra
3. Verified `ghidra/CM550.rep/working/J90280.05.ghidra.cpp` shows expected changes
4. No unexpected type regressions in the output

### **⚡ Quick Workflow (Recommended):**
1. **🔍 Discover** new functions/addresses in Ghidra
2. **📝 Update CSVs** with findings
3. **⚡ Press `Ctrl+Shift+E`** in Ghidra (or run `ApplyAndExport.java`)
4. **✅ Verify output** in `working/J90280.05.ghidra.cpp`
5. **🤖 Claude Code sees changes** immediately in exported files

### **🎯 One-Command Automation:**
The **`ApplyAndExport.java`** script combines both setup and export in one keystroke:
- **Keyboard shortcut:** `Ctrl+Shift+E`
- **Menu:** Tools → Apply and Export
- **What it does:** Runs MasterAnalysisSetup + ExportAnalysisResults automatically
- **Log file:** Creates `ghidra/CM550.rep/apply_and_export.log` (cleared each run)

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
- **`ghidra_scripts/BulkLocalVariableRenamer.java`** - Decompiler local variable renaming

## **📝 Local Variable Renaming**

The `local_variables.csv` uses **first-use address matching** for stability. Unlike global variable names, decompiler local variable names (like `cVar6`, `bVar8`) can shift when other variables in the same function are renamed. Matching by code address ensures renames are stable.

### **CSV Format:**
```csv
function_address,function_name,first_use_address,new_variable_name,type,comment
0x00012484,diagnosticCommandDispatcher,0x12580,securityCheckResult,char,Result from systemSecurityCheck()
```

### **Discovery Workflow:**
1. Add an entry with `first_use_address=0x0` (placeholder that won't match)
2. Run ApplyAndExport (Ctrl+Shift+E) - the script will output available variables with their first-use addresses
3. Check `ghidra/CM550.rep/apply_and_export.log` for the output:
   ```
   Processing function: diagnosticCommandDispatcher @ 0x12484
     ✗ No variable found with first-use at 0x0
         Searching for: myVariableName
         Available variables:
           - cVar6 (char) first-use: 0x12580
           - bVar7 (byte) first-use: 0x1256c
   ```
4. Update the CSV with the correct address from the log
5. Re-run ApplyAndExport - the variable will be renamed

### **Why First-Use Address?**
- **Stable**: Code addresses never change, even when other variables are renamed
- **Unique**: Each assignment location is unique in the binary
- **Semantic**: Ties directly to where the variable gets its value

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

## **🔌 Ghidra MCP Integration (Read-Only Analysis)**

Claude Code can interact directly with Ghidra via the MCP (Model Context Protocol) server for **reading and analysis only**.

### **⚠️ IMPORTANT: MCP is Read-Only**

**DO NOT use MCP tools to modify Ghidra** (rename, set types, etc.). Direct modifications:
- Are NOT persisted to CSV files (source of truth)
- Can cause unexpected side effects (variable types becoming `undefined`)
- Create inconsistency between CSVs and Ghidra state

**All changes must go through CSV files → ApplyAndExport workflow.**

### **MCP Tools - READ ONLY**

| Tool | Purpose | Safe to Use |
|------|---------|-------------|
| `decompile_function` | Get C code by function name | ✅ Yes |
| `decompile_function_by_address` | Get C code by hex address | ✅ Yes |
| `search_functions_by_name` | Find functions by pattern | ✅ Yes |
| `get_function_xrefs` | Get cross-references | ✅ Yes |
| `list_strings` | List strings in binary | ✅ Yes |
| `get_xrefs_to` / `get_xrefs_from` | Trace references | ✅ Yes |
| `disassemble_function` | Get assembly code | ✅ Yes |
| `list_functions` | List all functions | ✅ Yes |
| `rename_function_by_address` | Rename function | ❌ NO - Use CSV |
| `rename_variable` | Rename local variable | ❌ NO - Use CSV |
| `rename_data` | Rename global data label | ❌ NO - Use CSV |
| `set_function_prototype` | Set function signature | ❌ NO - Use CSV |
| `set_local_variable_type` | Set variable type | ❌ NO - Use CSV |

### **Correct Workflow Pattern**

**Pattern: Rename a Function**
```
1. mcp__ghidra__decompile_function_by_address("0x0000a30c")  ← READ (OK)
2. Analyze decompiled code, determine name
3. Edit function_renames.csv (add: 0x0000a30c,myFunctionName)  ← CSV ONLY
4. Run ApplyAndExport in Ghidra (Ctrl+Shift+E)
5. Verify output in working/J90280.05.ghidra.cpp
```

**Pattern: Add Structure/Variable**
```
1. mcp__ghidra__decompile_function("myFunction")  ← READ (OK)
2. Analyze code, identify structure patterns
3. Edit structure_definitions.csv or global_variables.csv  ← CSV ONLY
4. Run ApplyAndExport in Ghidra (Ctrl+Shift+E)
5. Verify output shows expected field names
```

### **Pre-Commit Requirements**
1. All changes are in CSV files (NOT made via MCP write tools)
2. Run `Ctrl+Shift+E` in Ghidra (ApplyAndExport)
3. Verify `working/*.cpp` shows expected changes
4. Check for unexpected type regressions (e.g., `byte *` → `undefined *`)
5. Commit includes synchronized CSVs + exports

---

## **💡 Pro Tips for Claude Code Sessions**

1. **CSV files are the source of truth** - ALL changes go through CSVs
2. **MCP for reading only** - use `decompile_function`, `get_xrefs`, etc. for analysis
3. **Never use MCP write tools** - `rename_*`, `set_*` tools cause sync issues
4. **Always verify before commit** - run ApplyAndExport and check the output
5. **Address references help**: `function_name @ 0x12345` for precise location
6. **Exported files have latest analysis** - `working/*.asm` and `working/*.cpp`

**The CSV→ApplyAndExport→Verify workflow ensures reproducible, consistent analysis.**

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

### **State Machine Enums** (switch statements now show readable names):
- **MAIN_LOOP_PHASE** (40 phases) - Main scheduler task phases (PHASE_0_VP44_RPM through PHASE_39)
- **ENGINE_OPERATING_MODE** (9 states) - IDLE, LOW_RPM_RUNNING, HIGH_RPM_RUNNING, CRANKING, etc.
- **VP44_ENGINE_STATE** (12 states) - VP44 injection pump state machine
- **PROTECTION_STATE** (5 states) - Engine protection coordinator (FAULT_DURATION_COUNT, DIAGNOSTIC_VALIDATE, etc.)
- **FUEL_SYNC_STATE** (5 states) - Fuel pressure synchronization state machine
- **RETARDER_MODE_STATE** (6 states) - Retarder/engine brake control

**The CSV files contain the complete reverse engineered knowledge base for this firmware.**

---

## **📊 Reverse Engineering Progress**

### **Overall Summary**
| Category | Named | Remaining | Progress |
|----------|-------|-----------|----------|
| Functions | 793 | 0 | **100%** ✅ |
| Global Variables | 6,087 | 3* | **100%** ✅ |
| Local Variables | 42 | ~22 | 66% |
| Function Parameters | 9 | TBD | In Progress |

*\*3 remaining `DAT_` references are indirect pointer accesses to already-named variables*

### **Knowledge Database Contents**
| CSV File | Entries | Description |
|----------|---------|-------------|
| `function_renames.csv` | 793 | All functions named |
| `global_variables.csv` | 6,087 | All global variables documented |
| `structure_definitions.csv` | 433 | Structure field definitions |
| `labels.csv` | 3,495 | Control flow labels |
| `enums.csv` | 464 | Enumeration entries |
| `constants.csv` | 73 | Magic number documentation |
| `local_variables.csv` | 42 | Local variable renames |
| `function_parameters.csv` | 9 | Function parameter names |

### **Next Opportunities**
1. **~22 unnamed local variables** - `local_XX` patterns in key functions
2. **~1,050 undefined type usages** - Variables needing proper typing
3. **Function parameter naming** - Improve function signatures

---

## **⚠️ Important Notes on Reference Data**

### **docs/common_parameters.json - Address Verification Status**

The `common_parameters.json` file contains CalTerm parameter definitions extracted from e2m calibration files. While the **parameter names and descriptions are reliable**, the **memory addresses may be incorrect**.

**Why addresses may be wrong:**
- Addresses were extracted from e2m files, not verified against actual firmware
- Different firmware versions may use different memory layouts
- The extraction process may have introduced errors

**Verification Goal:**
One key objective of this reverse engineering effort is to:
1. Verify which addresses in common_parameters.json are correct
2. Identify and document incorrect addresses
3. Build a verified address mapping through firmware analysis

**When verifying addresses:**
- Cross-reference decompiled code behavior with parameter descriptions
- Note verified mappings in global_variables.csv comment field
- Mark confirmed matches with "VERIFIED: matches common_parameters.json"
- Mark mismatches with "NOTE: common_parameters.json shows different address"
