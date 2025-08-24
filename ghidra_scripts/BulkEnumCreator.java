// Ghidra Bulk Enum Creator Script
// Reads from enums.csv and creates enum data types for switch statements and constants
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
import java.util.ArrayList;
import java.util.List;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;

public class BulkEnumCreator extends GhidraScript {
    
    // Enum member class
    private class EnumMember {
        long value;
        String name;
        String comment;
        
        EnumMember(long value, String name, String comment) {
            this.value = value;
            this.name = name;
            this.comment = comment;
        }
    }
    
    // Enum definition class
    private class EnumDef {
        String name;
        List<EnumMember> members;
        
        EnumDef(String name) {
            this.name = name;
            this.members = new ArrayList<>();
        }
    }
    
    @Override
    public void run() throws Exception {
        // Path to CSV file
        String csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() + 
                        "/enums.csv";
        
        println("Reading enum definitions from: " + csvPath);
        
        Map<String, EnumDef> enums = new HashMap<>();
        
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
                
                // Parse CSV: enum_name,value,member_name,comment
                String[] parts = line.split(",");
                if (parts.length >= 4) {
                    String enumName = parts[0].trim();
                    String valueStr = parts[1].trim();
                    String memberName = parts[2].trim();
                    String comment = parts[3].trim();
                    
                    // Parse value
                    long value;
                    try {
                        if (valueStr.startsWith("0x") || valueStr.startsWith("0X")) {
                            value = Long.parseLong(valueStr.substring(2), 16);
                        } else {
                            value = Long.parseLong(valueStr);
                        }
                    } catch (NumberFormatException e) {
                        println("✗ Invalid value format: " + valueStr + " for " + enumName);
                        continue;
                    }
                    
                    // Get or create enum definition
                    EnumDef enumDef = enums.get(enumName);
                    if (enumDef == null) {
                        enumDef = new EnumDef(enumName);
                        enums.put(enumName, enumDef);
                    }
                    
                    // Add member to enum
                    enumDef.members.add(new EnumMember(value, memberName, comment));
                }
            }
        } catch (IOException e) {
            println("Error reading CSV file: " + e.getMessage());
            println("Make sure enums.csv is in your project root directory");
            return;
        }
        
        println("Found " + enums.size() + " enums to create");
        println("==========================================");
        
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        int successCount = 0;
        int failCount = 0;
        
        // Create each enum
        for (EnumDef enumDef : enums.values()) {
            try {
                println("Creating enum: " + enumDef.name);
                
                // Create new enum (32-bit by default for compatibility)
                EnumDataType enumType = new EnumDataType(enumDef.name, 4);
                
                // Add members to enum
                for (EnumMember member : enumDef.members) {
                    try {
                        enumType.add(member.name, member.value, member.comment);
                        println("  + " + member.name + " = " + member.value + " (" + member.comment + ")");
                    } catch (Exception e) {
                        println("  ! Failed to add member " + member.name + ": " + e.getMessage());
                    }
                }
                
                // Add enum to data type manager
                DataType addedEnum = dtm.addDataType(enumType, DataTypeConflictHandler.REPLACE_HANDLER);
                
                println("✓ Created enum " + enumDef.name + " with " + enumDef.members.size() + " members");
                successCount++;
                println("");
                
            } catch (Exception e) {
                println("✗ Failed to create enum " + enumDef.name + ": " + e.getMessage());
                failCount++;
            }
        }
        
        println("==========================================");
        println("Results: " + successCount + " successful, " + failCount + " failed");
        
        if (successCount > 0) {
            println("\nSuccessfully created " + successCount + " enums!");
            println("You can find them in the Data Type Manager under your program category.");
            println("Use these enums to replace magic numbers in switch statements and comparisons.");
            println("\nTo apply an enum to a variable or parameter:");
            println("1. Right-click on the variable/parameter");
            println("2. Select 'Retype Variable' or 'Retype Global'"); 
            println("3. Choose your enum from the data type list");
            println("\nSwitch statements will now show enum member names instead of raw numbers!");
        }
    }
}