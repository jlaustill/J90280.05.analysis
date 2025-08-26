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
            // SIM (System Integration Module) - Extended to 0xFFFA50 to cover all variables
            createMemoryBlock(memory, "SIM_Registers", 0xFFFA00, 0x51, 
                            true, true, false, "System Integration Module registers (clock, interrupts, chip selects)");
            
            // QSM (Queued Serial Module) - Extended to 0xFFFB30
            createMemoryBlock(memory, "QSM_Registers", 0xFFFB00, 0x31, 
                            true, true, false, "Queued Serial Module registers (SCI, SPI communication)");
            
            // TPU (Time Processor Unit) - Extended to 0xFFFC30
            createMemoryBlock(memory, "TPU_Registers", 0xFFFC00, 0x31, 
                            true, true, false, "Time Processor Unit registers (timing and control functions)");
            
            // SIM CAN Control Ports - For our discovered CAN switching registers
            createMemoryBlock(memory, "SIM_CAN_Control_Ports", 0xFFD000, 0x20, 
                            true, true, false, "SIM CAN control ports for pin switching (0xFFD004, 0xFFD006)");
            
            // QADC (Queued ADC) - Extended to 0xFFFD20  
            createMemoryBlock(memory, "QADC_Registers", 0xFFFD00, 0x21, 
                            true, true, false, "Queued Analog-to-Digital Converter registers");
            
            // CAN Controllers - Extended to 0xFFFEB0
            createMemoryBlock(memory, "CAN_Registers", 0xFFFE00, 0xB1, 
                            true, true, false, "CAN1 and CAN2 controller registers");
            
            // 3. Timer/System Registers - For hardware_timer_register at 0xFFF404
            createMemoryBlock(memory, "System_Timer_Registers", 0xFFF400, 0x10, 
                            true, true, false, "System timer registers including hardware_timer_register");
            
            // 4. Internal RAM  
            createMemoryBlock(memory, "Internal_RAM", 0xFFFF00, 0x100, 
                            true, true, false, "Internal SRAM for stack/variables");
            
            // 5. External Memory (Parameter System)
            // Based on your parameter addresses (0x80xxxx range)
            createMemoryBlock(memory, "External_Memory", 0x800000, 0x100000, 
                            true, true, false, "External memory for sensor data, CAN buffers, lookup tables");
            
            // 6. EEPROM Memory (Data Plate region)
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