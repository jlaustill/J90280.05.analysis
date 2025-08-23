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
        
        println("Setting up MC68336 Memory Map based on playbook specifications...");
        println("==========================================");
        
        try {
            // 1. Internal Flash (Code) - Already exists, skip
            println("✓ Internal Flash (0x000000 - 0x007FFF): Already exists");
            
            // 2. Internal Registers
            createMemoryBlock(memory, "Internal_Registers", 0xFFFF00, 0x100, 
                            true, true, false, "CPU32 internal registers, CAN controllers, timers");
            
            // 3. Internal RAM  
            createMemoryBlock(memory, "Internal_RAM", 0xFFFE00, 0x100, 
                            true, true, false, "Internal SRAM for stack/variables");
            
            // 4. External Memory (Parameter System)
            // Based on your parameter addresses (0x80xxxx range)
            createMemoryBlock(memory, "External_Memory", 0x800000, 0x100000, 
                            true, true, false, "External memory for sensor data, CAN buffers, lookup tables");
            
            // 5. EEPROM Memory (if needed for 0x01000000 addresses)
            // createMemoryBlock(memory, "EEPROM", 0x01000000, 0x400, 
            //                 true, true, false, "Physical EEPROM");
            
            println("==========================================");
            println("Memory map setup complete!");
            println("You can now apply structures and variables to the 0x80xxxx addresses.");
            
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
                println("✓ " + name + " (0x" + Long.toHexString(startAddr).toUpperCase() + 
                       " - 0x" + Long.toHexString(startAddr + size - 1).toUpperCase() + 
                       "): Already exists");
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
            
            println("✓ Created " + name + " (0x" + Long.toHexString(startAddr).toUpperCase() + 
                   " - 0x" + Long.toHexString(startAddr + size - 1).toUpperCase() + 
                   "): " + comment);
            
        } catch (Exception e) {
            println("✗ Failed to create " + name + ": " + e.getMessage());
        }
    }
}