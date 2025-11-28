# Plan: Discover and Document New Enums and Structs

## Status: IN PROGRESS (Phase 2)

## Summary of Changes

### Phase 1 - Initial Enum Work (Completed)

| Enum Name | Entries | Variable | Purpose |
|-----------|---------|----------|---------|
| **SHUTDOWN_SELECTOR_SOURCE** | 10 | `shutdown_minimum_selector_value` | Identifies which fuel limiter won the minimum selection |
| **FUEL_DEMAND_SOURCE** | 8 | `fuel_demand_source_id` | Tracks which subsystem is providing fuel demand |
| **FUEL_DEMAND_LIMIT** | 6 | `fuel_demand_limit_source` | State machine for fuel limiting in fuelDemandFaultStateBuilder |
| **DIAGNOSTIC_STATUS** | 9 | `diagnostic_status_register` | Diagnostic operation mode state machine |
| **VP44_DIAG_MODE** | 10 | `vp44_diagnostic_mode_state` | VP44 diagnostic mode state machine |

### Phase 2 - Additional Enums (Current Session)

| Enum Name | Entries | Variable(s) | Purpose |
|-----------|---------|-------------|---------|
| **HIGH_RPM_PROTECTION_STATE** | 5 | `high_rpm_protection_state` | Engine protection state machine (monitoring → warning → shutdown) |
| **TPU_TRANSMISSION_STATE** | 4 | `tpu_transmission_state_machine` | CAN/serial byte transmission sequence |
| **PWM_TIMER_CYCLE_STATE** | 6 | `pwm_timer_cycle_advance_state` | Timing cycle phase (0-5 modulo 6) |
| **DERATE_EVENT_STATE** | 3 | `derate_event_state_machine` (x2) | Derate event duration tracking |
| **IO_CONTROL_STATE** | 3 | `io_control_bit0/1/4/6_state` (x4) | Per-bit output control state machine |
| **RPM_CAPTURE_STATE** | 3 | `rpm_timer_capture_state` | RPM measurement state (init → capture → fault) |
| **TIMING_MODE_SOURCE** | 4 | `timing_mode_source_selector` | Fuel timing blend source identifier |

**Phase 2 Total: 28 new enum values, 10 variables typed**

### Global Variables Updated

**Phase 1 (6 variables):**
- `shutdown_minimum_selector_value` → type: SHUTDOWN_SELECTOR_SOURCE
- `fuel_demand_source_id` → type: FUEL_DEMAND_SOURCE
- `fuel_demand_limit_source` → type: FUEL_DEMAND_LIMIT
- `diagnostic_status_register` → type: DIAGNOSTIC_STATUS
- `vp44_diagnostic_mode_state` (0x008096b6) → type: VP44_DIAG_MODE
- `vp44_diagnostic_mode_state_2` (0x008096fc) → type: VP44_DIAG_MODE

**Phase 2 (10 variables):**
- `high_rpm_protection_state` → type: HIGH_RPM_PROTECTION_STATE
- `tpu_transmission_state_machine` → type: TPU_TRANSMISSION_STATE
- `pwm_timer_cycle_advance_state` → type: PWM_TIMER_CYCLE_STATE
- `derate_event_state_machine` (0x008032da) → type: DERATE_EVENT_STATE
- `derate_event_state_machine` (0x008094ec) → type: DERATE_EVENT_STATE
- `io_control_bit0_state` → type: IO_CONTROL_STATE
- `io_control_bit1_state` → type: IO_CONTROL_STATE
- `io_control_bit4_state` → type: IO_CONTROL_STATE
- `io_control_bit6_state` → type: IO_CONTROL_STATE
- `rpm_timer_capture_state` → type: RPM_CAPTURE_STATE
- `timing_mode_source_selector` → type: TIMING_MODE_SOURCE

### Before/After Example

**Before:**
```c
if (high_rpm_protection_state == 4) {
    // what is state 4?
}
```

**After (with enum):**
```c
if (high_rpm_protection_state == SHUTDOWN_PENDING) {
    // clearly shows shutdown pending - timer expired waiting for idle
}
```

## Verification Steps

1. Run `Ctrl+Shift+E` (ApplyAndExport) in Ghidra
2. Check that switch statements show enum member names
3. Verify no underscore prefix issues (indicating size mismatches)
4. Match enum sizes to variable sizes (byte=1, word=2)

## Files Changed

- `ghidra/CM550.rep/enums.csv` - +28 enum values (Phase 2)
- `ghidra/CM550.rep/global_variables.csv` - 11 type changes (Phase 2)

## Future Opportunities (Phase 3)

### Struct Refinement
Variables with `._X_Y_` patterns could benefit from structure definitions:
- `can_memory_table_start._2_2_`
- `fuel_command_scaled._2_2_`
- `governor_fuel_pid_integral._0_2_` and `._2_2_`

### Additional Enum Candidates
- `fuel_timing_mode_blend_factor` - timing mode constants (0x4000)
- `vp44_operating_condition_value` - VP44 condition states (1-4)
