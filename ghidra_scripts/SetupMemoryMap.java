// Ghidra Memory Map Setup Script
// Creates memory blocks based on MC68336 architecture from playbook
// @author J90280.05_analysis
// @category Analysis
// @keybinding 
// @menupath 
// @toolbar 

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;

public class SetupMemoryMap extends GhidraScript {
    
    @Override
    public void run() throws Exception {
        Memory memory = currentProgram.getMemory();
        
        
        try {
            // 1. Internal Flash (Code) - Already exists, skip
            
            // 2. MC68336 Peripheral Register Blocks
            // SIM (System Integration Module) - 0xFFFA00 to 0xFFFA4A
            createMemoryBlock(memory, "SIM_Registers", 0xFFFA00, 0x4B, 
                            true, true, false, "System Integration Module registers (clock, interrupts, chip selects)");
            
            // QSM (Queued Serial Module) - 0xFFFB00 to 0xFFFB1E  
            createMemoryBlock(memory, "QSM_Registers", 0xFFFB00, 0x1F, 
                            true, true, false, "Queued Serial Module registers (SCI, SPI communication)");
            
            // TPU (Time Processor Unit) - 0xFFFC00 to 0xFFFC1E
            createMemoryBlock(memory, "TPU_Registers", 0xFFFC00, 0x1F, 
                            true, true, false, "Time Processor Unit registers (timing and control functions)");
            
            // QADC (Queued ADC) - 0xFFFD00 to 0xFFFD0E  
            createMemoryBlock(memory, "QADC_Registers", 0xFFFD00, 0x0F, 
                            true, true, false, "Queued Analog-to-Digital Converter registers");
            
            // CAN Controllers - 0xFFFE00 to 0xFFFEA2
            createMemoryBlock(memory, "CAN_Registers", 0xFFFE00, 0xA3, 
                            true, true, false, "CAN1 and CAN2 controller registers");
            
            // 3. Internal RAM  
            createMemoryBlock(memory, "Internal_RAM", 0xFFFF00, 0x100, 
                            true, true, false, "Internal SRAM for stack/variables");
            
            // 4. External Memory (Parameter System)
            // Based on your parameter addresses (0x80xxxx range)
            createMemoryBlock(memory, "External_Memory", 0x800000, 0x100000, 
                            true, true, false, "External memory for sensor data, CAN buffers, lookup tables");
            
            // 5. EEPROM Memory (Data Plate region)
            createMemoryBlock(memory, "EEPROM_DataPlate", 0x01000000, 0x2000, 
                            true, true, false, "8KB EEPROM containing Cummins data plate and configuration");
            
            println("✓ Memory map configured");
            
        } catch (Exception e) {
            println("Error setting up memory map: " + e.getMessage());
        }
    }
    
    private void createMemoryBlock(Memory memory, String name, long startAddr, long size,
                                 boolean read, boolean write, boolean execute, String comment) {
        try {
            Address start = toAddr(startAddr);
            
            // Check if block already exists
            MemoryBlock existing = memory.getBlock(start);
            if (existing != null) {
                /* println("✓ " + name + " (0x" + Long.toHexString(startAddr).toUpperCase() + 
                       " - 0x" + Long.toHexString(startAddr + size - 1).toUpperCase() + 
                       "): Already exists"); */ // Commented out for clean output
                return;
            }
            
            // Create uninitialized memory block
            MemoryBlock block = memory.createUninitializedBlock(name, start, size, false);
            
            // Set permissions
            block.setRead(read);
            block.setWrite(write);
            block.setExecute(execute);
            
            // Set comment
            block.setComment(comment);
            
            /* println("✓ Created " + name + " (0x" + Long.toHexString(startAddr).toUpperCase() + 
                   " - 0x" + Long.toHexString(startAddr + size - 1).toUpperCase() + 
                   "): " + comment); */ // Commented out for clean output
            
        } catch (Exception e) {
            println("✗ Failed to create " + name + ": " + e.getMessage());
        }
    }
}