// Master Analysis Setup Script
// Runs all bulk analysis scripts in the correct order for complete firmware setup
// @author J90280.05_analysis
// @category Analysis
// @keybinding 
// @menupath 
// @toolbar 

import ghidra.app.script.GhidraScript;

public class MasterAnalysisSetup extends GhidraScript {
    
    @Override
    public void run() throws Exception {
        println("🚀 MASTER ANALYSIS SETUP - COMPLETE FIRMWARE AUTOMATION");
        println("========================================================");
        println("Running all bulk analysis scripts in optimal order...");
        println("");
        
        int totalScripts = 7;
        int currentScript = 0;
        
        try {
            // Step 1: Setup Memory Map (MUST be first)
            currentScript++;
            println("[" + currentScript + "/" + totalScripts + "] Setting up memory map...");
            runScript("SetupMemoryMap.java");
            println("✓ Memory map configured\n");
            
            // Step 2: Rename Functions
            currentScript++;
            println("[" + currentScript + "/" + totalScripts + "] Renaming functions...");
            runScript("BulkFunctionRenamer.java");
            println("✓ Functions renamed\n");
            
            // Step 3: Create Global Variables
            currentScript++;
            println("[" + currentScript + "/" + totalScripts + "] Creating global variables...");
            runScript("BulkVariableCreator.java");
            println("✓ Global variables created\n");
            
            // Step 4: Create Structures
            currentScript++;
            println("[" + currentScript + "/" + totalScripts + "] Creating structures...");
            runScript("BulkStructureCreator.java");
            println("✓ Structures created\n");
            
            // Step 5: Create Labels
            currentScript++;
            println("[" + currentScript + "/" + totalScripts + "] Creating labels...");
            runScript("BulkLabelCreator.java");
            println("✓ Labels created\n");
            
            // Step 6: Document Constants
            currentScript++;
            println("[" + currentScript + "/" + totalScripts + "] Documenting constants...");
            runScript("BulkConstantCreator.java");
            println("✓ Constants documented\n");
            
            // Step 7: Create Enums
            currentScript++;
            println("[" + currentScript + "/" + totalScripts + "] Creating enums...");
            runScript("BulkEnumCreator.java");
            println("✓ Enums created\n");
            
            // Step 8: Create Arrays (moved to end as it may conflict with other data)
            // Commented out by default since arrays can be more disruptive
            // Uncomment if you want arrays created automatically
            /*
            currentScript++;
            println("[" + currentScript + "/" + totalScripts + "] Creating arrays...");
            runScript("BulkArrayCreator.java");
            println("✓ Arrays created\n");
            */
            
            println("🎉 MASTER ANALYSIS SETUP COMPLETE!");
            println("========================================");
            println("Your firmware is now fully analyzed with:");
            println("✅ Proper memory layout (MC68336 architecture)");
            println("✅ Named functions with semantic meaning");
            println("✅ Typed global variables");
            println("✅ Data structures applied to memory");
            println("✅ Meaningful labels for control flow");
            println("✅ Documented constants (no more magic numbers)");
            println("✅ Organized enums for switch statements");
            println("");
            println("🔧 Manual Steps (if needed):");
            println("• Run BulkArrayCreator.java separately if you want arrays");
            println("• Update CSV files with new discoveries");
            println("• Re-run this script on fresh imports");
            println("");
            println("📁 Your CSV files are your knowledge database:");
            println("• function_renames.csv - Function names");
            println("• global_variables.csv - Variable definitions");  
            println("• structure_definitions.csv - Data structures");
            println("• labels.csv - Control flow labels");
            println("• constants.csv - Magic number meanings");
            println("• enums.csv - Enumeration definitions");
            println("• arrays.csv - Array/buffer layouts");
            println("");
            println("🚀 Ready for reverse engineering! Your firmware is now human-readable.");
            
        } catch (Exception e) {
            println("❌ Error during setup: " + e.getMessage());
            println("Some scripts may not have completed successfully.");
            println("Check individual script outputs above for details.");
        }
    }
}