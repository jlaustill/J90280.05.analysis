# 5.9 Cummins + CM550 ECU Configuration Guide

## Engine Setup
- **Engine**: 5.9L Cummins ISB
- **ECU**: CM550 (J90280.05 firmware)
- **Sensor**: 60-2 camshaft position sensor only
- **Target**: Mode 0 timing method compatibility

## Current Analysis Status
✅ **CONFIRMED COMPATIBLE** - Mode 0 supports 60-2 camshaft sensor with calibration changes

---

## Required Calibration Parameter Changes

### CAM_SYNC Group Parameters

| Parameter | Current Value | Required Value | Description |
|-----------|--------------|----------------|-------------|
| **ESNOTTCU** | 34 | **58** | Active teeth count for 60-2 pattern |
| **ESNMTTMS** | 1 | **2** | Missing tooth gap width (2-tooth gap) |
| **MSTTFNEN** | DISABLE | **ENABLE** | Enable missing tooth detection algorithm |
| **ESNOTTRA** | 1.453 | **~2.0-2.5** | Tooth spacing ratio for gap detection |

### MAP Sensor Configuration

| Parameter | Current Value | Required Value | Description |
|-----------|--------------|----------------|-------------|
| **ADBSPRCA** | 19 | **19** | ADC channel for MAP sensor (keep current) |
| **ADBSPRYA** | Stock curve | **Custom 10-bar curve** | Voltage-to-pressure calibration table |
| **ADBSPRHL** | 948 | **Adjust for 10-bar** | High error limit for sensor range |
| **ADBSPRLL** | 77 | **Adjust for 10-bar** | Low error limit for sensor range |
| **BSSNPZ** | 0 | **Check sensor type** | 0=gauge pressure, 1=absolute pressure |

### J1939 Throttle Pedal Configuration

| Parameter | Current Value | Required Value | Description |
|-----------|--------------|----------------|-------------|
| **JCCNRXFT[13]** | 0x00000000 | **0x07F00400** | Enable TSC1 (Torque/Speed Control) message reception |
| **ANPZ** | 9 | **9** | Accelerator interlock priority (keep current) |
| **JCTHKCTD** | 95.0% | **Adjust as needed** | Throttle kickdown threshold |
| **THROTTLE** | Current | **Monitor J1939** | Main throttle parameter |

### Verified Compatible Settings (No Changes Needed)

| Parameter | Current Value | Status | Description |
|-----------|--------------|--------|-------------|
| **CSEN** | 1 (ENABLED) | ✅ Keep | Cam synchronization enabled |
| **ESPECK01** | 30.00° | ✅ Keep | Primary speed measurement interval |
| **ESPECK02** | 720.00° | ✅ Keep | Backup measurement (full cycle) |
| **ESPECM01** | 24 | ✅ Keep | Primary speed pulse periods per cam |
| **EST2CY** | 6 | ✅ Keep | Number of cylinders |
| **CSERCUMX** | 25 | ✅ Keep | Max sync errors before fault |
| **CSXT_1PC** | 75.0% | ✅ Keep | Sync pulse detection threshold |
| **CSXT_2PC** | 85.2% | ✅ Keep | Secondary sync detection threshold |

### 60-2 Pattern Details
- **58 active teeth** spaced 6° apart on camshaft
- **2-tooth gap** creates 12° sync space
- **At crank speed**: Each cam tooth = 12° crank rotation
- **Missing tooth gap**: 24° crank rotation (easily detectable)

### Speed Measurement Logic
```
Sampling Rate: Every 30° crank = 15° cam rotation
Teeth per Sample: ~2.5 teeth pass sensor
Measurements per Cycle: 24 samples per cam revolution
Sync Detection: 2-tooth gap = 4 sample periods
```

---

## Troubleshooting Guide

### If Sync Errors Occur
- **Increase ESNOTTRA** (try 2.2, 2.5) for better gap detection
- **Check sensor mounting** and air gap
- **Verify sensor supply voltage** is stable
- **Monitor CSERCUMX counter** - should stay below 25

### If Engine Won't Start
- **Revert to original calibration** immediately
- **Check MSTTFNEN setting** - may need gradual enable
- **Verify ESNOTTCU = 58** is correctly set
- **Ensure sensor wiring is correct**

### If Rough Idle/Hunting
- **Fine-tune ESNOTTRA** in small increments (±0.1)
- **Check sync pulse thresholds** (CSXT_1PC/2PC)
- **Monitor fuel delivery consistency**
- **Verify timing advance is stable**
