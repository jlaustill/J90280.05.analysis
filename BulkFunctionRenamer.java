// Ghidra Bulk Function Renamer Script
// Reads from function_renames.csv and applies function name changes
// @author J90280.05_analysis
// @category Analysis
// @keybinding 
// @menupath 
// @toolbar 

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;

public class BulkFunctionRenamer extends GhidraScript {
    
    @Override
    public void run() throws Exception {
        // Path to CSV file (relative to project directory)
        String csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() + 
                        "/function_renames.csv";
        
        println("Reading function renames from: " + csvPath);
        
        Map<String, String> functionRenames = new HashMap<>();
        
        // Read CSV file
        try (BufferedReader br = new BufferedReader(new FileReader(csvPath))) {
            String line;
            boolean isFirstLine = true;
            
            while ((line = br.readLine()) != null) {
                // Skip header line
                if (isFirstLine) {
                    isFirstLine = false;
                    continue;
                }
                
                // Parse CSV: address,newName
                String[] parts = line.split(",");
                if (parts.length >= 2) {
                    String address = parts[0].trim();
                    String newName = parts[1].trim();
                    functionRenames.put(address, newName);
                }
            }
        } catch (IOException e) {
            println("Error reading CSV file: " + e.getMessage());
            println("Make sure function_renames.csv is in your project root directory");
            return;
        }
        
        println("Found " + functionRenames.size() + " functions to rename");
        println("==========================================");
        
        // Apply renames
        int successCount = 0;
        int failCount = 0;
        
        for (Map.Entry<String, String> entry : functionRenames.entrySet()) {
            String addressStr = entry.getKey();
            String newName = entry.getValue();
            
            try {
                // Handle hex addresses (with or without 0x prefix)
                long addressLong;
                if (addressStr.startsWith("0x") || addressStr.startsWith("0X")) {
                    addressLong = Long.parseLong(addressStr.substring(2), 16);
                } else {
                    addressLong = Long.parseLong(addressStr, 16);
                }
                
                Function func = getFunctionAt(toAddr(addressLong));
                if (func != null) {
                    String oldName = func.getName();
                    func.setName(newName, SourceType.USER_DEFINED);
                    println("✓ " + addressStr + ": " + oldName + " → " + newName);
                    successCount++;
                } else {
                    println("✗ " + addressStr + ": No function found at this address");
                    failCount++;
                }
            } catch (NumberFormatException e) {
                println("✗ " + addressStr + ": Invalid address format");
                failCount++;
            } catch (Exception e) {
                println("✗ " + addressStr + ": Error renaming - " + e.getMessage());
                failCount++;
            }
        }
        
        println("==========================================");
        println("Results: " + successCount + " successful, " + failCount + " failed");
        
        if (successCount > 0) {
            println("\nSuccessfully renamed " + successCount + " functions!");
            println("You can now update your CSV file with new addresses/names and re-run this script.");
        }
    }
}