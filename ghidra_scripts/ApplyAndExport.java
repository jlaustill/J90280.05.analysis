// Apply and Export Script
// Combines MasterAnalysisSetup.java + ExportAnalysisResults.java for quick workflow
// Perfect for iterative reverse engineering: Update CSV → Run this → Done!
// @author J90280.05_analysis
// @category Analysis
// @keybinding ctrl shift E
// @menupath Tools.Apply and Export
// @toolbar

import ghidra.app.script.GhidraScript;

public class ApplyAndExport extends GhidraScript {

    @Override
    public void run() throws Exception {
        println("⚡ QUICK UPDATE: APPLY & EXPORT");
        println("================================");
        println("Running MasterAnalysisSetup + ExportAnalysisResults...");
        println("");

        try {
            // Step 1: Apply all CSV changes to Ghidra project
            println("📥 [1/2] Applying CSV changes to Ghidra...");
            println("─────────────────────────────────────────");
            runScript("MasterAnalysisSetup.java");
            println("");
            println("✓ CSV changes applied");
            println("");

            // Step 2: Export updated analysis for Claude Code
            println("📤 [2/2] Exporting analysis for Claude Code...");
            println("───────────────────────────────────────────────");
            runScript("ExportAnalysisResults.java");
            println("");
            println("✓ Export complete");
            println("");

            // Success summary
            println("═══════════════════════════════════════════════");
            println("🎉 QUICK UPDATE COMPLETE!");
            println("═══════════════════════════════════════════════");
            println("");
            println("✅ All CSV changes applied to Ghidra");
            println("✅ Latest analysis exported to working/");
            println("");
            println("🔄 Perfect Workflow:");
            println("  1. Update CSV files with discoveries");
            println("  2. Run ApplyAndExport.java (Ctrl+Shift+E)");
            println("  3. Claude Code sees your changes instantly!");
            println("");
            println("📁 Exported files:");
            println("  • working/J90280.05.ghidra.asm");
            println("  • working/J90280.05.ghidra.cpp");

        } catch (Exception e) {
            printerr("❌ Error during quick update:");
            printerr(e.getMessage());
            e.printStackTrace();
            throw e;
        }
    }
}
