// Ghidra Bulk Structure Creator Script
// Reads from structure_definitions.csv and creates structures + applies them to memory
// @author J90280.05_analysis
// @category Analysis
// @keybinding 
// @menupath 
// @toolbar 

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.Data;
import ghidra.program.model.address.Address;

public class BulkStructureCreator extends GhidraScript {
    
    // Field definition class
    private class StructField {
        String name;
        String type;
        int size;
        String comment;
        
        StructField(String name, String type, int size, String comment) {
            this.name = name;
            this.type = type;
            this.size = size;
            this.comment = comment;
        }
    }
    
    // Structure definition class
    private class StructDef {
        String name;
        String address;
        List<StructField> fields;
        Set<String> dependencies;
        boolean created;
        
        StructDef(String name, String address) {
            this.name = name;
            this.address = address;
            this.fields = new ArrayList<>();
            this.dependencies = new HashSet<>();
            this.created = false;
        }
    }
    
    @Override
    public void run() throws Exception {
        // Path to CSV file
        String csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() + 
                        "/structure_definitions.csv";
        
        println("Reading structure definitions from: " + csvPath);
        
        Map<String, StructDef> structures = new HashMap<>();
        
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
                
                // Parse CSV: struct_name,address,field_name,field_type,field_size,comment,depends_on
                String[] parts = line.split(",");
                if (parts.length >= 6) {
                    String structName = parts[0].trim();
                    String address = parts[1].trim();
                    String fieldName = parts[2].trim();
                    String fieldType = parts[3].trim();
                    int fieldSize = Integer.parseInt(parts[4].trim());
                    String comment = parts[5].trim();
                    String dependsOn = (parts.length >= 7) ? parts[6].trim() : "";
                    
                    // Get or create structure definition
                    StructDef structDef = structures.get(structName);
                    if (structDef == null) {
                        structDef = new StructDef(structName, address);
                        structures.put(structName, structDef);
                    }
                    
                    // Add field to structure
                    structDef.fields.add(new StructField(fieldName, fieldType, fieldSize, comment));
                    
                    // Add dependency if specified
                    if (!dependsOn.isEmpty()) {
                        structDef.dependencies.add(dependsOn);
                    }
                }
            }
        } catch (IOException e) {
            println("Error reading CSV file: " + e.getMessage());
            println("Make sure structure_definitions.csv is in your project root directory");
            return;
        }
        
        println("Found " + structures.size() + " structures to create");
        println("==========================================");
        
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        int successCount = 0;
        int failCount = 0;
        
        // Create structures in dependency order
        List<StructDef> orderedStructures = resolveDependencies(structures);
        
        println("Structure creation order:");
        for (int i = 0; i < orderedStructures.size(); i++) {
            StructDef structDef = orderedStructures.get(i);
            println("  " + (i+1) + ". " + structDef.name + " (dependencies: " + structDef.dependencies + ")");
        }
        println("");
        
        // Create each structure
        for (StructDef structDef : orderedStructures) {
            try {
                println("Creating structure: " + structDef.name);
                
                // Create new structure
                Structure struct = new StructureDataType(structDef.name, 0);
                
                // Add fields to structure
                for (StructField field : structDef.fields) {
                    DataType fieldDataType = getDataType(field.type);
                    if (fieldDataType == null) {
                        // Try to find custom structure type in DataTypeManager
                        fieldDataType = findDataTypeByName(dtm, field.type);
                        if (fieldDataType != null) {
                            println("    Found custom type '" + field.type + "' in DataTypeManager: " + fieldDataType.getClass().getSimpleName());
                        }
                    }
                    if (fieldDataType != null) {
                        // For array types (like uint8_t with size > 1), create array
                        if (field.size > fieldDataType.getLength() && fieldDataType.getLength() == 1) {
                            fieldDataType = new ArrayDataType(fieldDataType, field.size, fieldDataType.getLength());
                            println("    Created array type: " + field.type + "[" + field.size + "]");
                        }
                        struct.add(fieldDataType, field.size, field.name, field.comment);
                        println("  + " + field.name + " (" + field.type + ", " + field.size + " bytes): " + field.comment);
                    } else {
                        println("  ! Unknown data type: " + field.type + " for field " + field.name);
                        println("    Available primitive types: uint8_t, uint16_t, uint32_t, uint64_t, etc.");
                        println("    Searching DataTypeManager for custom types...");
                        // List available custom types for debugging
                        java.util.Iterator<DataType> dtIter = dtm.getAllDataTypes();
                        int customTypeCount = 0;
                        while (dtIter.hasNext() && customTypeCount < 10) {
                            DataType dt = dtIter.next();
                            if (dt instanceof Structure) {
                                println("      Found structure: " + dt.getName());
                                customTypeCount++;
                            }
                        }
                        if (customTypeCount == 0) {
                            println("      No custom structures found in DataTypeManager");
                        }
                    }
                }
                
                // Add structure to data type manager
                DataType addedStruct = dtm.addDataType(struct, DataTypeConflictHandler.REPLACE_HANDLER);
                println("  ✓ Added '" + structDef.name + "' to DataTypeManager (size: " + addedStruct.getLength() + " bytes)");
                
                // Apply structure to memory if address is specified
                if (!structDef.address.isEmpty()) {
                    try {
                        long addressLong;
                        if (structDef.address.startsWith("0x") || structDef.address.startsWith("0X")) {
                            addressLong = Long.parseLong(structDef.address.substring(2), 16);
                        } else {
                            addressLong = Long.parseLong(structDef.address, 16);
                        }
                        
                        Address addr = toAddr(addressLong);
                        
                        // Clear any existing data at this address
                        clearListing(addr, addr.add(addedStruct.getLength() - 1));
                        
                        // Create data with the structure
                        Data data = createData(addr, addedStruct);
                        if (data != null) {
                            println("✓ Applied " + structDef.name + " at address " + structDef.address);
                        }
                    } catch (Exception e) {
                        println("✗ Failed to apply structure at " + structDef.address + ": " + e.getMessage());
                    }
                } else {
                    println("✓ Created structure " + structDef.name + " (no address specified)");
                }
                
                successCount++;
                println("");
                
            } catch (Exception e) {
                println("✗ Failed to create structure " + structDef.name + ": " + e.getMessage());
                failCount++;
            }
        }
        
        println("==========================================");
        println("Results: " + successCount + " successful, " + failCount + " failed");
        
        if (successCount > 0) {
            println("\nSuccessfully created " + successCount + " structures!");
            println("You can find them in the Data Type Manager window.");
            println("Update your CSV file with new structures and re-run this script.");
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
    
    // Helper method to find DataType by name (handles category paths)
    private DataType findDataTypeByName(DataTypeManager dtm, String typeName) {
        java.util.Iterator<DataType> dtIter = dtm.getAllDataTypes();
        while (dtIter.hasNext()) {
            DataType dt = dtIter.next();
            if (dt.getName().equals(typeName)) {
                return dt;
            }
        }
        return null;
    }
    
    // Dependency resolution using topological sort
    private List<StructDef> resolveDependencies(Map<String, StructDef> structures) {
        List<StructDef> result = new ArrayList<>();
        Set<String> visited = new HashSet<>();
        Set<String> visiting = new HashSet<>();
        
        for (StructDef structDef : structures.values()) {
            if (!visited.contains(structDef.name)) {
                if (!visitDependencies(structDef, structures, visited, visiting, result)) {
                    println("⚠ Circular dependency detected involving: " + structDef.name);
                }
            }
        }
        
        return result;
    }
    
    private boolean visitDependencies(StructDef structDef, Map<String, StructDef> structures, 
                                    Set<String> visited, Set<String> visiting, List<StructDef> result) {
        if (visiting.contains(structDef.name)) {
            // Circular dependency detected
            return false;
        }
        
        if (visited.contains(structDef.name)) {
            // Already processed
            return true;
        }
        
        visiting.add(structDef.name);
        
        // Visit all dependencies first
        for (String dependency : structDef.dependencies) {
            StructDef depStructDef = structures.get(dependency);
            if (depStructDef != null) {
                if (!visitDependencies(depStructDef, structures, visited, visiting, result)) {
                    return false; // Circular dependency
                }
            } else {
                println("⚠ Dependency not found: " + dependency + " (required by " + structDef.name + ")");
            }
        }
        
        visiting.remove(structDef.name);
        visited.add(structDef.name);
        result.add(structDef);
        
        return true;
    }
}