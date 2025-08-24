// Ghidra Bulk Global Variable Creator Script
// Reads from global_variables.csv and creates global variables with proper data types
// @author J90280.05_analysis
// @category Analysis
// @keybinding 
// @menupath 
// @toolbar 

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Data;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolTable;
import ghidra.program.model.symbol.SourceType;

public class BulkVariableCreator extends GhidraScript {
    
    @Override
    public void run() throws Exception {
        // Path to CSV file
        String csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() + 
                        "/global_variables.csv";
        
        println("Reading global variables from: " + csvPath);
        
        // Read CSV file and create variables
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
                
                // Parse CSV: address,name,type,comment
                String[] parts = line.split(",");
                if (parts.length >= 4) {
                    String addressStr = parts[0].trim();
                    String varName = parts[1].trim();
                    String typeStr = parts[2].trim();
                    String comment = parts[3].trim();
                    
                    try {
                        // Parse address
                        long addressLong;
                        if (addressStr.startsWith("0x") || addressStr.startsWith("0X")) {
                            addressLong = Long.parseLong(addressStr.substring(2), 16);
                        } else {
                            addressLong = Long.parseLong(addressStr, 16);
                        }
                        
                        Address addr = toAddr(addressLong);
                        
                        // Get data type
                        DataType dataType = getDataType(typeStr);
                        if (dataType == null) {
                            // Try to find custom structure type
                            dataType = currentProgram.getDataTypeManager().getDataType(typeStr);
                            if (dataType != null) {
                                println("  Found custom type '" + typeStr + "' in DataTypeManager");
                            } else {
                                println("✗ " + addressStr + ": Unknown data type '" + typeStr + "'");
                                println("  Available primitive types: uint8_t, uint16_t, uint32_t, byte, word, dword");
                                println("  Searching for custom structures in DataTypeManager...");
                                
                                // Debug: List available structures
                                java.util.Iterator<DataType> dtIter = currentProgram.getDataTypeManager().getAllDataTypes();
                                int structCount = 0;
                                while (dtIter.hasNext() && structCount < 5) {
                                    DataType dt = dtIter.next();
                                    if (dt instanceof Structure) {
                                        println("    Found structure: " + dt.getName());
                                        structCount++;
                                    }
                                }
                                if (structCount == 0) {
                                    println("    No structures found in DataTypeManager");
                                }
                                
                                failCount++;
                                continue;
                            }
                        }
                        
                        // Clear existing data at this address
                        clearListing(addr, addr.add(dataType.getLength() - 1));
                        
                        // Create data with the specified type
                        Data data = createData(addr, dataType);
                        if (data == null) {
                            println("✗ " + addressStr + ": Failed to create data");
                            failCount++;
                            continue;
                        }
                        
                        // Create symbol (variable name) at this address
                        SymbolTable symbolTable = currentProgram.getSymbolTable();
                        
                        // Remove any existing symbols at this address (except function symbols)
                        Symbol[] existingSymbols = symbolTable.getSymbols(addr);
                        for (Symbol symbol : existingSymbols) {
                            if (symbol.getSymbolType() != ghidra.program.model.symbol.SymbolType.FUNCTION) {
                                symbolTable.removeSymbolSpecial(symbol);
                            }
                        }
                        
                        // Create new symbol
                        Symbol newSymbol = symbolTable.createLabel(addr, varName, SourceType.USER_DEFINED);
                        if (newSymbol != null) {
                            // Set comment on the data
                            setEOLComment(addr, comment);
                            
                            println("✓ " + addressStr + ": " + varName + " (" + typeStr + ") - " + comment);
                            successCount++;
                        } else {
                            println("✗ " + addressStr + ": Failed to create symbol '" + varName + "'");
                            failCount++;
                        }
                        
                    } catch (NumberFormatException e) {
                        println("✗ " + addressStr + ": Invalid address format");
                        failCount++;
                    } catch (Exception e) {
                        println("✗ " + addressStr + ": Error creating variable - " + e.getMessage());
                        failCount++;
                    }
                }
            }
            
            println("==========================================");
            println("Results: " + successCount + " successful, " + failCount + " failed");
            
            if (successCount > 0) {
                println("\nSuccessfully created " + successCount + " global variables!");
                println("Variables are now named and typed in the Symbol Tree.");
                println("You can find them under Global namespace in the Symbol Tree window.");
            }
            
        } catch (IOException e) {
            println("Error reading CSV file: " + e.getMessage());
            println("Make sure global_variables.csv is in your project root directory");
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
            case "word":
            case "uint16":
            case "short":
                return new WordDataType();
            case "dword":
            case "uint32":
            case "int":
                return new DWordDataType();
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