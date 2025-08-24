// Ghidra Bulk Local Variable Renamer Script
// Reads from local_variables.csv and renames/retypes local variables within functions
// @author J90280.05_analysis
// @category Analysis
// @keybinding 
// @menupath 
// @toolbar 

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Iterator;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Variable;
import ghidra.program.model.listing.LocalVariable;
import ghidra.program.model.symbol.SourceType;

public class BulkLocalVariableRenamer extends GhidraScript {
    
    @Override
    public void run() throws Exception {
        // Path to CSV file
        String csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() + 
                        "/local_variables.csv";
        
        println("Reading local variables from: " + csvPath);
        
        FunctionManager functionManager = currentProgram.getFunctionManager();
        
        // Read CSV file and rename variables
        try (BufferedReader br = new BufferedReader(new FileReader(csvPath))) {
            String line;
            boolean isFirstLine = true;
            int successCount = 0;
            int failCount = 0;
            
            println("==========================================");
            
            while ((line = br.readLine()) != null) {
                // Skip header line
                if (isFirstLine) {
                    isFirstLine = false;
                    continue;
                }
                
                // Parse CSV: function_address,function_name,old_variable_name,new_variable_name,type,comment
                String[] parts = line.split(",");
                if (parts.length >= 6) {
                    String functionAddressStr = parts[0].trim();
                    String functionName = parts[1].trim();
                    String oldVarName = parts[2].trim();
                    String newVarName = parts[3].trim();
                    String typeStr = parts[4].trim();
                    String comment = parts[5].trim();
                    
                    try {
                        // Parse function address
                        long functionAddressLong;
                        if (functionAddressStr.startsWith("0x") || functionAddressStr.startsWith("0X")) {
                            functionAddressLong = Long.parseLong(functionAddressStr.substring(2), 16);
                        } else {
                            functionAddressLong = Long.parseLong(functionAddressStr, 16);
                        }
                        
                        Address functionAddr = toAddr(functionAddressLong);
                        
                        // Get function
                        Function function = functionManager.getFunctionAt(functionAddr);
                        if (function == null) {
                            println("✗ " + functionAddressStr + ": No function found at address");
                            failCount++;
                            continue;
                        }
                        
                        // Verify function name matches (optional safety check)
                        if (!function.getName().equals(functionName)) {
                            println("⚠ " + functionAddressStr + ": Function name mismatch - expected '" + 
                                   functionName + "', found '" + function.getName() + "' (continuing anyway)");
                        }
                        
                        // Get data type for the variable
                        DataType dataType = getDataType(typeStr);
                        if (dataType == null) {
                            println("✗ " + functionAddressStr + ": Unknown data type '" + typeStr + "'");
                            failCount++;
                            continue;
                        }
                        
                        // Find and rename the local variable
                        boolean variableFound = false;
                        Variable[] localVars = function.getLocalVariables();
                        
                        for (Variable var : localVars) {
                            if (var.getName().equals(oldVarName)) {
                                try {
                                    // Rename the variable
                                    var.setName(newVarName, SourceType.USER_DEFINED);
                                    
                                    // Set the data type
                                    var.setDataType(dataType, SourceType.USER_DEFINED);
                                    
                                    // Set comment if the variable supports it
                                    if (var instanceof LocalVariable) {
                                        var.setComment(comment);
                                    }
                                    
                                    println("✓ " + functionAddressStr + " (" + functionName + "): " + 
                                           oldVarName + " → " + newVarName + " (" + typeStr + ") - " + comment);
                                    successCount++;
                                    variableFound = true;
                                    break;
                                    
                                } catch (Exception e) {
                                    println("✗ " + functionAddressStr + ": Failed to rename '" + oldVarName + 
                                           "' → '" + newVarName + "' - " + e.getMessage());
                                    failCount++;
                                    variableFound = true;
                                    break;
                                }
                            }
                        }
                        
                        if (!variableFound) {
                            println("✗ " + functionAddressStr + " (" + functionName + "): Variable '" + 
                                   oldVarName + "' not found");
                            
                            // List available variables for debugging
                            println("   Available variables: ");
                            for (Variable var : localVars) {
                                println("   - " + var.getName() + " (" + var.getDataType().getName() + ")");
                            }
                            failCount++;
                        }
                        
                    } catch (NumberFormatException e) {
                        println("✗ " + functionAddressStr + ": Invalid address format");
                        failCount++;
                    } catch (Exception e) {
                        println("✗ " + functionAddressStr + ": Error processing variable - " + e.getMessage());
                        failCount++;
                    }
                }
            }
            
            println("==========================================");
            println("Results: " + successCount + " successful, " + failCount + " failed");
            
            if (successCount > 0) {
                println("\nSuccessfully renamed/retyped " + successCount + " local variables!");
                println("Variables are now properly named and typed in their respective functions.");
                println("Changes will be visible in the Decompiler view.");
            }
            
        } catch (IOException e) {
            println("Error reading CSV file: " + e.getMessage());
            println("Make sure local_variables.csv is in your project root directory");
            return;
        }
    }
    
    // Helper method to convert string type to Ghidra DataType
    private DataType getDataType(String typeString) {
        switch (typeString.toLowerCase()) {
            case "uint8_t":
            case "byte":
            case "uint8":
            case "char":
                return new ByteDataType();
            case "uint16_t":
            case "word":
            case "uint16":
            case "short":
                return new WordDataType();
            case "uint32_t":
            case "dword":
            case "uint32":
            case "int":
                return new DWordDataType();
            case "uint64_t":
            case "qword":
            case "uint64":
            case "long":
                return new QWordDataType();
            case "float":
                return new FloatDataType();
            case "double":
                return new DoubleDataType();
            case "pointer":
            case "ptr":
                return new PointerDataType();
            default:
                return null;
        }
    }
}