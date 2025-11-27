// Ghidra C++ Decompilation Export - J90280.05 Firmware
// Generated with renamed functions, variables, and meaningful types
// Wed Nov 26 19:37:22 MST 2025


//
// Function: rpm_rate_limiter @ 0x0000a16a
//

void rpm_rate_limiter(void)

{
  rpm_fuel_protection_t_008091c4.rpm_rate_limiter_output =
       circular_buffer_t_0080c3fc.current_engine_rpm -
       rpm_control_timers_t_00800002.previous_engine_rpm;
  rpm_control_timers_t_00800002.previous_engine_rpm = circular_buffer_t_0080c3fc.current_engine_rpm;
  rpm_fuel_protection_t_008091c4.rpm_rate_limited_value = exponentialMovingAverage();
  if ((short)rpm_fuel_protection_t_008091c4.rpm_rate_limited_value <
      (short)rpm_rate_limits_t_008062f8.minimum) {
    rpm_fuel_protection_t_008091c4.rpm_rate_limited_value = rpm_rate_limits_t_008062f8.minimum;
    dma_control_block_t_00800026.control_flags1 =
         (short)rpm_rate_limits_t_008062f8.minimum * 0x10000 + 0x80000000;
  }
  else if ((short)rpm_rate_limits_t_008062f8.maximum <
           (short)rpm_fuel_protection_t_008091c4.rpm_rate_limited_value) {
    rpm_fuel_protection_t_008091c4.rpm_rate_limited_value = rpm_rate_limits_t_008062f8.maximum;
    dma_control_block_t_00800026.control_flags1 =
         (short)rpm_rate_limits_t_008062f8.maximum * 0x10000 + 0x80000000;
  }
  rpm_fuel_protection_t_008091c4.rpm_rate_secondary_calc = exponentialMovingAverage();
  return;
}



//
// Function: rpm_system_state_controller @ 0x0000a204
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort rpm_system_state_controller(void)

{
  ushort uVar1;
  
  uVar1 = engine_control_flags_t_008035d6.engine_operating_state & 0x1000;
  if ((engine_control_flags_t_008035d6.engine_operating_state & 0x1000) != 0) {
    if ((short)rpm_calibration_params_t_008062d4.threshold_lower <
        (short)rpm_fuel_protection_t_008091c4.rpm_rate_limited_value) {
      rpm_fuel_protection_t_008091c4.rpm_threshold_exceeded_flag = 1;
      rpm_control_timers_t_00800002.timer_1 = _DAT_008062fe;
    }
    else if (rpm_control_timers_t_00800002.timer_1 == 0) {
      rpm_fuel_protection_t_008091c4.rpm_threshold_exceeded_flag = 0;
    }
    else {
      rpm_control_timers_t_00800002.timer_1 = rpm_control_timers_t_00800002.timer_1 - 1;
    }
    if ((((rpm_fuel_protection_t_008091c4.fuel_system_protection_enabled == 0) ||
         (rpm_fuel_protection_t_008091c4.rpm_threshold_exceeded_flag != 0)) ||
        (circular_buffer_t_0080c3fc.current_engine_rpm <
         rpm_calibration_params_t_008062d4.threshold_upper)) ||
       (((short)rpm_calibration_params_t_008062d4.threshold_lower <
         (short)rpm_fuel_protection_t_008091c4.rpm_rate_limited_value ||
        ((short)rpm_fuel_protection_t_008091c4.rpm_rate_secondary_calc <
         (short)rpm_calibration_params_t_008062d4.secondary_threshold)))) {
      if (rpm_fuel_protection_t_008091c4.fuel_protection_timer_enable == 0) {
        if (rpm_control_timers_t_00800002.timer_2 == 0) {
          rpm_fuel_protection_t_008091c4.rpm_state_accumulator = 0;
        }
        else {
          rpm_control_timers_t_00800002.timer_2 = rpm_control_timers_t_00800002.timer_2 - 1;
        }
      }
      else {
        rpm_fuel_protection_t_008091c4.rpm_state_accumulator = 1;
        rpm_control_timers_t_00800002.timer_2 =
             rpm_calibration_params_t_008062d4.timer_reload_value_2;
      }
    }
    else {
      rpm_fuel_protection_t_008091c4.rpm_state_accumulator = 1;
      rpm_control_timers_t_00800002.timer_2 = rpm_calibration_params_t_008062d4.timer_reload_value_2
      ;
    }
    if (rpm_fuel_protection_t_008091c4.rpm_state_accumulator == 1) {
      shutdown_fuel_lookup_args_t_0080000e.input_rpm = circular_buffer_t_0080c3fc.current_engine_rpm
      ;
      rpm_fuel_protection_t_008091c4.fuel_limit_shutdown =
           lookupTableInterpolation((short *)&shutdown_fuel_lookup_args_t_0080000e);
      return rpm_fuel_protection_t_008091c4.fuel_limit_shutdown;
    }
    uVar1 = rpm_fuel_protection_t_008091c4.fuel_limit_shutdown;
    if (rpm_fuel_protection_t_008091c4.fuel_limit_shutdown < _DAT_00807f3c) {
      uVar1 = rpm_calibration_params_t_008062d4.reserved_02 +
              rpm_fuel_protection_t_008091c4.fuel_limit_shutdown;
      rpm_fuel_protection_t_008091c4.fuel_limit_shutdown = uVar1;
      if (_DAT_00807f3c < uVar1) {
        rpm_fuel_protection_t_008091c4.fuel_limit_shutdown = _DAT_00807f3c;
      }
    }
  }
  return uVar1;
}



//
// Function: shutdownMinimumSelector17 @ 0x0000a30c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void shutdownMinimumSelector17(void)

{
  if (rpm_fuel_protection_t_008091c4.fuel_limit_shutdown < _DAT_0080d494) {
    _DAT_0080d494 = rpm_fuel_protection_t_008091c4.fuel_limit_shutdown;
    _DAT_0080d496 = 0x11;
  }
  return;
}



//
// Function: highRpmFuelControlLimiter @ 0x0000a32a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort highRpmFuelControlLimiter(void)

{
  word wVar1;
  
  wVar1 = engine_control_flags_t_008035d6.engine_operating_state & 0x2000;
  if ((engine_control_flags_t_008035d6.engine_operating_state & 0x2000) != 0) {
    if (_DAT_00806302 < (short)rpm_fuel_protection_t_008091c4.rpm_rate_limited_value) {
      rpm_fuel_protection_t_008091c4.high_rpm_threshold_exceeded_flag = 1;
      rpm_control_timers_t_00800002.high_rpm_timer = _DAT_00806300;
    }
    else if (rpm_control_timers_t_00800002.high_rpm_timer == 0) {
      rpm_fuel_protection_t_008091c4.high_rpm_threshold_exceeded_flag = 0;
    }
    else {
      rpm_control_timers_t_00800002.high_rpm_timer =
           rpm_control_timers_t_00800002.high_rpm_timer - 1;
    }
    wVar1 = rpm_fuel_protection_t_008091c4.rpm_rate_limited_value;
    if ((((rpm_fuel_protection_t_008091c4.fuel_system_protection_enabled == 0) ||
         (rpm_fuel_protection_t_008091c4.high_rpm_threshold_exceeded_flag != 0)) ||
        (wVar1 = _DAT_0080926e, _DAT_0080926e <= _DAT_008062ea)) ||
       ((wVar1 = rpm_fuel_protection_t_008091c4.rpm_rate_limited_value,
        _DAT_00806302 < (short)rpm_fuel_protection_t_008091c4.rpm_rate_limited_value ||
        (wVar1 = rpm_fuel_protection_t_008091c4.rpm_rate_secondary_calc,
        (short)rpm_fuel_protection_t_008091c4.rpm_rate_secondary_calc < _DAT_008062f0)))) {
      if (rpm_fuel_protection_t_008091c4.fuel_protection_timer_enable == 0) {
        if (rpm_control_timers_t_00800002.high_rpm_accumulator_timer == 0) {
          rpm_fuel_protection_t_008091c4.high_rpm_fuel_accumulator = 0;
        }
        else {
          rpm_control_timers_t_00800002.high_rpm_accumulator_timer =
               rpm_control_timers_t_00800002.high_rpm_accumulator_timer - 1;
        }
      }
      else {
        rpm_fuel_protection_t_008091c4.high_rpm_fuel_accumulator = 1;
        rpm_control_timers_t_00800002.high_rpm_accumulator_timer = _DAT_008062ec;
      }
    }
    else {
      rpm_fuel_protection_t_008091c4.high_rpm_fuel_accumulator = 1;
      rpm_control_timers_t_00800002.high_rpm_accumulator_timer = _DAT_008062ec;
    }
    if (rpm_fuel_protection_t_008091c4.high_rpm_fuel_accumulator == 1) {
      high_rpm_fuel_lookup_args_t_0080001a.input_rpm = circular_buffer_t_0080c3fc.current_engine_rpm
      ;
      rpm_fuel_protection_t_008091c4.high_rpm_fuel_limit =
           lookupTableInterpolation((short *)&high_rpm_fuel_lookup_args_t_0080001a);
      return rpm_fuel_protection_t_008091c4.high_rpm_fuel_limit;
    }
    if (rpm_fuel_protection_t_008091c4.high_rpm_fuel_limit < 0x400) {
      rpm_fuel_protection_t_008091c4.high_rpm_fuel_limit =
           _DAT_008062ee + rpm_fuel_protection_t_008091c4.high_rpm_fuel_limit;
      wVar1 = _DAT_008062ee;
      if (0x400 < rpm_fuel_protection_t_008091c4.high_rpm_fuel_limit) {
        rpm_fuel_protection_t_008091c4.high_rpm_fuel_limit = 0x400;
      }
    }
  }
  return wVar1;
}



//
// Function: fuelLimitMinimumSelector @ 0x0000a428
//

void fuelLimitMinimumSelector(void)

{
  rpm_fuel_protection_t_008091c4.fuel_demand_before_limiting =
       fuel_demand_state_t_0080c9a4.limit_minimum;
  if (rpm_fuel_protection_t_008091c4.high_rpm_fuel_limit <
      fuel_demand_state_t_0080c9a4.limit_minimum) {
    fuel_demand_state_t_0080c9a4.limit_minimum = rpm_fuel_protection_t_008091c4.high_rpm_fuel_limit;
    fuel_demand_state_t_0080c9a4.demand_source_id = 3;
  }
  return;
}



//
// Function: lowRpmFuelProtectionLimiter @ 0x0000a44c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort lowRpmFuelProtectionLimiter(void)

{
  word wVar1;
  ushort uVar2;
  
  uVar2 = engine_control_flags_t_008035d6.engine_operating_state & 0x4000;
  if ((engine_control_flags_t_008035d6.engine_operating_state & 0x4000) != 0) {
    if (_DAT_008062e8 < (short)rpm_fuel_protection_t_008091c4.rpm_rate_limited_value) {
      rpm_fuel_protection_t_008091c4.low_rpm_threshold_exceeded_flag = 1;
      _DAT_00800000 = rpm_rate_limits_t_008062f8.threshold_timer_reload;
    }
    else if (_DAT_00800000 == 0) {
      rpm_fuel_protection_t_008091c4.low_rpm_threshold_exceeded_flag = 0;
    }
    else {
      _DAT_00800000 = _DAT_00800000 - 1;
    }
    wVar1 = rpm_fuel_protection_t_008091c4.rpm_rate_limited_value;
    if ((((rpm_fuel_protection_t_008091c4.fuel_system_protection_enabled == 0) ||
         (rpm_fuel_protection_t_008091c4.low_rpm_threshold_exceeded_flag != 0)) ||
        (wVar1 = circular_buffer_t_0080c3fc.current_engine_rpm,
        _DAT_008062e6 < circular_buffer_t_0080c3fc.current_engine_rpm)) ||
       ((wVar1 = rpm_fuel_protection_t_008091c4.rpm_rate_limited_value,
        _DAT_008062e8 < (short)rpm_fuel_protection_t_008091c4.rpm_rate_limited_value ||
        (wVar1 = rpm_fuel_protection_t_008091c4.rpm_rate_secondary_calc,
        (short)rpm_fuel_protection_t_008091c4.rpm_rate_secondary_calc < _DAT_008062e4)))) {
      if (rpm_fuel_protection_t_008091c4.fuel_protection_timer_enable == 0) {
        if (rpm_control_timers_t_00800002.low_rpm_accumulator_timer == 0) {
          rpm_fuel_protection_t_008091c4.low_rpm_fuel_accumulator = 0;
        }
        else {
          rpm_control_timers_t_00800002.low_rpm_accumulator_timer =
               rpm_control_timers_t_00800002.low_rpm_accumulator_timer - 1;
        }
      }
      else {
        rpm_fuel_protection_t_008091c4.low_rpm_fuel_accumulator = 1;
        rpm_control_timers_t_00800002.low_rpm_accumulator_timer = _DAT_008062e0;
      }
    }
    else {
      rpm_fuel_protection_t_008091c4.low_rpm_fuel_accumulator = 1;
      rpm_control_timers_t_00800002.low_rpm_accumulator_timer = _DAT_008062e0;
    }
    if (rpm_fuel_protection_t_008091c4.low_rpm_fuel_accumulator != 0) {
      rpm_fuel_protection_t_008091c4.low_rpm_fuel_protection_limit = _DAT_008062de;
      return wVar1;
    }
    uVar2 = rpm_fuel_protection_t_008091c4.low_rpm_fuel_protection_limit;
    if (rpm_fuel_protection_t_008091c4.low_rpm_fuel_protection_limit < _DAT_008037b4) {
      uVar2 = _DAT_008062e2 + rpm_fuel_protection_t_008091c4.low_rpm_fuel_protection_limit;
      rpm_fuel_protection_t_008091c4.low_rpm_fuel_protection_limit = uVar2;
      if (_DAT_008037b4 < uVar2) {
        rpm_fuel_protection_t_008091c4.low_rpm_fuel_protection_limit = _DAT_008037b4;
      }
    }
  }
  return uVar2;
}



//
// Function: dmaControllerSetup1 @ 0x0000a53e
//

void dmaControllerSetup1(void)

{
                    /* Constant: DMA_CONTROLLER_SETUP = 0x80000000 */
  dma_control_block_t_00800026.control_flags1 = 0x80000000;
                    /* Constant: DMA_DESC_ADDR_1 = 0x8062F4 */
  dma_control_block_t_00800026.descriptor_ptr1 = 0x8062f4;
  dma_control_block_t_00800026.control_flags2 = 0x80000000;
                    /* Constant: DMA_DESC_ADDR_2 = 0x8062F6 */
  dma_control_block_t_00800026.descriptor_ptr2 = 0x8062f6;
  rpm_control_timers_t_00800002.previous_engine_rpm = 0;
  return;
}



//
// Function: dmaDescriptorSetup1 @ 0x0000a56e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void dmaDescriptorSetup1(void)

{
  shutdown_fuel_lookup_args_t_0080000e.table_index = 2;
                    /* Constant: DMA_SOURCE_ADDR_1 = 0x806304 */
  shutdown_fuel_lookup_args_t_0080000e.x_axis_ptr = 0x806304;
                    /* Constant: DMA_DEST_ADDR_1 = 0x806318 */
  shutdown_fuel_lookup_args_t_0080000e.y_axis_ptr = 0x806318;
  rpm_fuel_protection_t_008091c4.fuel_limit_shutdown = _DAT_00807f3c;
  return;
}



//
// Function: dmaDescriptorSetup2 @ 0x0000a598
//

void dmaDescriptorSetup2(void)

{
  high_rpm_fuel_lookup_args_t_0080001a.table_index = 2;
                    /* Constant: DMA_SOURCE_ADDR_2 = 0x80632C */
  high_rpm_fuel_lookup_args_t_0080001a.x_axis_ptr = 0x80632c;
                    /* Constant: DMA_DEST_ADDR_2 = 0x806340 */
  high_rpm_fuel_lookup_args_t_0080001a.y_axis_ptr = 0x806340;
  rpm_fuel_protection_t_008091c4.high_rpm_fuel_limit = 0x400;
  return;
}



//
// Function: initFuelSystemOutputDriver @ 0x0000a5c0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initFuelSystemOutputDriver(void)

{
  rpm_fuel_protection_t_008091c4.fuel_system_protection_enabled = 1;
  rpm_fuel_protection_t_008091c4.low_rpm_fuel_protection_limit = _DAT_008037b4;
  return;
}



//
// Function: messageTypeToChannelMapper @ 0x0000a5e2
//

undefined1 messageTypeToChannelMapper(undefined4 param_1)

{
  byte bVar1;
  
  bVar1 = (byte)((uint)param_1 >> 0x10);
  if (0x40 < bVar1) {
    if (bVar1 < 0x4f) {
      return *(undefined1 *)((short)(param_1._0_2_ & 0xff) + 0xa593);
    }
    return 1;
  }
  if ((bVar1 != 4) && (bVar1 != 5)) {
    return 1;
  }
  return 3;
}



//
// Function: diagnosticMessageQueueWrite @ 0x0000a626
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticMessageQueueWrite(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined1 uVar3;
  undefined4 local_8;
  
  if ((int)_DAT_0080d2b4 < _DAT_0080d2bc) {
    iVar2 = (_DAT_0080d2bc - (int)_DAT_0080d2b4) + -2;
  }
  else {
    iVar2 = (_DAT_0080d2bc - (int)_DAT_0080d2b4) + 0xfe;
  }
  if (iVar2 < 3) {
    fault_status_registers_t_00805df2.io_fault_status_4 =
         fault_status_registers_t_00805df2.io_fault_status_4 | 4;
    fault_latch_registers_t_00805e32.io_fault_latch_4 =
         fault_latch_registers_t_00805e32.io_fault_latch_4 | 4;
  }
  else {
    local_8._3_1_ = (char)_DAT_0080d2b4;
    cVar1 = (char)local_8;
    local_8._0_3_ = (undefined3)((uint)_DAT_0080d2b4 >> 8);
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
    if (param_1._0_2_ == 0) {
      uVar3 = 100;
    }
    else if (param_1._0_2_ == 1) {
      uVar3 = 0x74;
      _DAT_0080c99a = param_1._0_2_;
    }
    else {
      uVar3 = 0x75;
      if (param_1._0_2_ < 0x12) {
        _DAT_0080c99a = param_1._0_2_;
      }
      else {
        _DAT_0080c99a = *(ushort *)((short)param_1._0_2_ * 2 + 0xa5f6);
      }
    }
    *local_8 = 6;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar1 + '\x02');
    *local_8 = uVar3;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar1 + '\x03');
    *_DAT_0080d2b4 = 2;
    _DAT_0080d2b4 = local_8;
    *local_8 = 0;
    tpuTransmissionTrigger();
  }
  return;
}



//
// Function: sensorFaultDebounceMonitor @ 0x0000a6fa
//

void sensorFaultDebounceMonitor(void)

{
  bool bVar1;
  short sVar2;
  undefined2 uVar3;
  ushort uVar4;
  short sVar5;
  word wVar6;
  int iVar7;
  undefined *puVar8;
  char *pcVar9;
  short *psVar10;
  
  sVar5 = 0;
  puVar8 = &DAT_008091e2;
  iVar7 = 0x8068ea;
  uVar4 = 1;
  pcVar9 = &DAT_00800036;
  psVar10 = (short *)&DAT_00809526;
  wVar6 = engine_control_flags_t_008035d6.reserved_08;
  do {
    if ((undefined *)0x809407 < puVar8) {
      return;
    }
    if (*(char *)(iVar7 + 0x17) == '\0') {
      puVar8[0xf] = 0;
    }
    else if ((byte)puVar8[0xf] < *(byte *)(iVar7 + 0x17)) {
      puVar8[0xf] = puVar8[0xf] + '\x01';
    }
    else {
      puVar8[0xf] = 1;
      if ((uVar4 & wVar6) == 0) {
        *(undefined2 *)(puVar8 + 0x10) =
             *(undefined2 *)((uint)*(ushort *)(iVar7 + 0x10) * 2 + 0xfff2b0);
        if (*(ushort *)(iVar7 + 0xc) < *(ushort *)(puVar8 + 0x10)) {
          if ((((uint)(&fault_status_registers_t_00805df2.sensor_fault_status)
                      [(short)((int)(uint)*(byte *)(iVar7 + 0x15) >> 4)] &
               1 << (*(byte *)(iVar7 + 0x15) & 0xf)) == 0) ||
             (((uint)*(ushort *)
                      (&DAT_008068c4 + (short)((int)(uint)*(byte *)(iVar7 + 0x15) >> 4) * 2) &
              1 << (*(byte *)(iVar7 + 0x15) & 0xf)) == 0)) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          if (bVar1) goto LAB_0000a864;
          *(short *)(puVar8 + 0xc) = *(short *)(iVar7 + 8) + *(short *)(puVar8 + 0xc);
          if (*(short *)(iVar7 + 10) <= *(short *)(puVar8 + 0xc)) {
            *(undefined2 *)(puVar8 + 0xc) = *(undefined2 *)(iVar7 + 10);
            puVar8[0xe] = 1;
            (&fault_status_registers_t_00805df2.sensor_fault_status)
            [(short)((int)(uint)*(byte *)(iVar7 + 0x14) >> 4)] =
                 1 << (*(byte *)(iVar7 + 0x14) & 0xf) |
                 (&fault_status_registers_t_00805df2.sensor_fault_status)
                 [(short)((int)(uint)*(byte *)(iVar7 + 0x14) >> 4)];
            (&fault_latch_registers_t_00805e32.sensor_fault_latch)
            [(short)((int)(uint)*(byte *)(iVar7 + 0x14) >> 4)] =
                 1 << (*(byte *)(iVar7 + 0x14) & 0xf) |
                 (&fault_latch_registers_t_00805e32.sensor_fault_latch)
                 [(short)((int)(uint)*(byte *)(iVar7 + 0x14) >> 4)];
          }
        }
        else {
LAB_0000a864:
          if (*(ushort *)(puVar8 + 0x10) < *(ushort *)(iVar7 + 0xe)) {
            if ((((uint)(&fault_status_registers_t_00805df2.sensor_fault_status)
                        [(short)((int)(uint)*(byte *)(iVar7 + 0x14) >> 4)] &
                 1 << (*(byte *)(iVar7 + 0x14) & 0xf)) == 0) ||
               (((uint)*(ushort *)
                        (&DAT_008068c4 + (short)((int)(uint)*(byte *)(iVar7 + 0x14) >> 4) * 2) &
                1 << (*(byte *)(iVar7 + 0x14) & 0xf)) == 0)) {
              bVar1 = false;
            }
            else {
              bVar1 = true;
            }
            if (!bVar1) {
              *(short *)(puVar8 + 0xc) = *(short *)(iVar7 + 8) + *(short *)(puVar8 + 0xc);
              if (*(short *)(iVar7 + 10) <= *(short *)(puVar8 + 0xc)) {
                *(undefined2 *)(puVar8 + 0xc) = *(undefined2 *)(iVar7 + 10);
                puVar8[0xe] = 1;
                (&fault_status_registers_t_00805df2.sensor_fault_status)
                [(short)((int)(uint)*(byte *)(iVar7 + 0x15) >> 4)] =
                     1 << (*(byte *)(iVar7 + 0x15) & 0xf) |
                     (&fault_status_registers_t_00805df2.sensor_fault_status)
                     [(short)((int)(uint)*(byte *)(iVar7 + 0x15) >> 4)];
                (&fault_latch_registers_t_00805e32.sensor_fault_latch)
                [(short)((int)(uint)*(byte *)(iVar7 + 0x15) >> 4)] =
                     1 << (*(byte *)(iVar7 + 0x15) & 0xf) |
                     (&fault_latch_registers_t_00805e32.sensor_fault_latch)
                     [(short)((int)(uint)*(byte *)(iVar7 + 0x15) >> 4)];
              }
              goto LAB_0000a964;
            }
          }
          *(short *)(puVar8 + 0xc) = *(short *)(puVar8 + 0xc) - *(short *)(iVar7 + 6);
          if (*(short *)(puVar8 + 0xc) < 0) {
            *(undefined2 *)(puVar8 + 0xc) = 0;
          }
        }
LAB_0000a964:
        if (*(short *)(puVar8 + 0xc) <= *(short *)(iVar7 + 4)) {
          puVar8[0xe] = 0;
          if (((uint)(&fault_status_registers_t_00805df2.sensor_fault_status)
                     [(short)((int)(uint)*(byte *)(iVar7 + 0x14) >> 4)] &
              1 << (*(byte *)(iVar7 + 0x14) & 0xf)) != 0) {
            if (((uint)(&fault_latch_registers_t_00805e32.sensor_fault_latch)
                       [(short)((int)(uint)*(byte *)(iVar7 + 0x14) >> 4)] &
                1 << (*(byte *)(iVar7 + 0x14) & 0xf)) == 0) {
              (&fault_status_registers_t_00805df2.sensor_fault_status)
              [(short)((int)(uint)*(byte *)(iVar7 + 0x14) >> 4)] =
                   ~(1 << (*(byte *)(iVar7 + 0x14) & 0xf)) &
                   (&fault_status_registers_t_00805df2.sensor_fault_status)
                   [(short)((int)(uint)*(byte *)(iVar7 + 0x14) >> 4)];
            }
          }
          if (((uint)(&fault_status_registers_t_00805df2.sensor_fault_status)
                     [(short)((int)(uint)*(byte *)(iVar7 + 0x15) >> 4)] &
              1 << (*(byte *)(iVar7 + 0x15) & 0xf)) != 0) {
            if (((uint)(&fault_latch_registers_t_00805e32.sensor_fault_latch)
                       [(short)((int)(uint)*(byte *)(iVar7 + 0x15) >> 4)] &
                1 << (*(byte *)(iVar7 + 0x15) & 0xf)) == 0) {
              (&fault_status_registers_t_00805df2.sensor_fault_status)
              [(short)((int)(uint)*(byte *)(iVar7 + 0x15) >> 4)] =
                   ~(1 << (*(byte *)(iVar7 + 0x15) & 0xf)) &
                   (&fault_status_registers_t_00805df2.sensor_fault_status)
                   [(short)((int)(uint)*(byte *)(iVar7 + 0x15) >> 4)];
            }
          }
        }
        if (puVar8[0xe] == '\0') {
          psVar10[3] = *(short *)(puVar8 + 0x10);
          sVar2 = lookupTableInterpolation(psVar10);
          *(short *)(puVar8 + 10) = sVar2;
          if (*(char *)(iVar7 + 0x13) != '\0') {
            if (*(short *)(puVar8 + 10) == 4) {
              if (*pcVar9 == '\x04') {
                (&fault_status_registers_t_00805df2.sensor_fault_status)
                [(short)((int)(uint)*(byte *)(iVar7 + 0x16) >> 4)] =
                     1 << (*(byte *)(iVar7 + 0x16) & 0xf) |
                     (&fault_status_registers_t_00805df2.sensor_fault_status)
                     [(short)((int)(uint)*(byte *)(iVar7 + 0x16) >> 4)];
                (&fault_latch_registers_t_00805e32.sensor_fault_latch)
                [(short)((int)(uint)*(byte *)(iVar7 + 0x16) >> 4)] =
                     1 << (*(byte *)(iVar7 + 0x16) & 0xf) |
                     (&fault_latch_registers_t_00805e32.sensor_fault_latch)
                     [(short)((int)(uint)*(byte *)(iVar7 + 0x16) >> 4)];
              }
              else {
                *pcVar9 = *pcVar9 + '\x01';
              }
            }
            else if (*pcVar9 == '\0') {
              if (((uint)(&fault_status_registers_t_00805df2.sensor_fault_status)
                         [(short)((int)(uint)*(byte *)(iVar7 + 0x16) >> 4)] &
                  1 << (*(byte *)(iVar7 + 0x16) & 0xf)) != 0) {
                if (((uint)(&fault_latch_registers_t_00805e32.sensor_fault_latch)
                           [(short)((int)(uint)*(byte *)(iVar7 + 0x16) >> 4)] &
                    1 << (*(byte *)(iVar7 + 0x16) & 0xf)) == 0) {
                  (&fault_status_registers_t_00805df2.sensor_fault_status)
                  [(short)((int)(uint)*(byte *)(iVar7 + 0x16) >> 4)] =
                       ~(1 << (*(byte *)(iVar7 + 0x16) & 0xf)) &
                       (&fault_status_registers_t_00805df2.sensor_fault_status)
                       [(short)((int)(uint)*(byte *)(iVar7 + 0x16) >> 4)];
                }
              }
            }
            else {
              *pcVar9 = *pcVar9 + -1;
            }
          }
          uVar3 = coreTableInterpolation();
          *(undefined2 *)(puVar8 + 8) = uVar3;
        }
        else {
          *(undefined2 *)(puVar8 + 8) = *(undefined2 *)(iVar7 + 2);
        }
      }
      else {
        *(undefined2 *)(puVar8 + 8) = *(undefined2 *)(&DAT_00803750 + sVar5 * 2);
      }
    }
    puVar8 = puVar8 + 0x16;
    iVar7 = iVar7 + 0x18;
    psVar10 = psVar10 + 6;
    pcVar9 = pcVar9 + 1;
    sVar5 = sVar5 + 1;
    if (sVar5 == 0x10) {
      uVar4 = 1;
      wVar6 = engine_control_flags_t_008035d6.fuel_temp_control;
    }
    else {
      uVar4 = uVar4 * 2;
    }
  } while( true );
}



//
// Function: initADCChannelConfiguration @ 0x0000ac1c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initADCChannelConfiguration(void)

{
  bool bVar1;
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  
  _DAT_0080952e = &ADCLTPCC;
  _DAT_00809528 = &ADOLPRCS;
  _DAT_00809526 = 2;
  _DAT_0080953a = &ADSATHCC;
  _DAT_00809534 = &ADPOTPIC;
  _DAT_00809532 = 2;
  _DAT_00809546 = &ADAAPRMU;
  _DAT_00809540 = &ADAAPRCS;
  _DAT_0080953e = 2;
  _DAT_00809552 = &ADBTVTMU;
  _DAT_0080954c = &ADBTVTHL;
  _DAT_0080954a = 2;
  _DAT_0080955e = &ADESSVHL;
  _DAT_00809558 = &ADESSVCS;
  _DAT_00809556 = 2;
  _DAT_0080956a = &ADTHSVFS;
  _DAT_00809564 = &ADTHSVCS;
  _DAT_00809562 = 2;
  _DAT_00809576 = &ADFTSVCS;
  _DAT_00809570 = &ADTHSVHE;
  _DAT_0080956e = 2;
  _DAT_00809582 = &ADWFFS;
  _DAT_0080957c = &ADWFFC;
  _DAT_0080957a = 2;
  _DAT_0080958e = &ADWFTE;
  _DAT_00809588 = &ADWFCA;
  _DAT_00809586 = 2;
  _DAT_0080959a = &ADEGCFFS;
  _DAT_00809594 = &ADEGCFCC;
  _DAT_00809592 = 2;
  _DAT_008095a6 = &ADPSSVFD;
  _DAT_008095a0 = &ADEGCFCA;
  _DAT_0080959e = 2;
  _DAT_008095b2 = &ADHBSVFD;
  _DAT_008095ac = &ADPSSVHE;
  _DAT_008095aa = 2;
  _DAT_008095be = &ADOCSVGD;
  _DAT_008095b8 = &ADHBSVCA;
  _DAT_008095b6 = 2;
  _DAT_008095ca = &ADOCSVMU;
  _DAT_008095c4 = &ADOCSVHL;
  _DAT_008095c2 = 2;
  _DAT_008095d6 = 0x806d40;
  _DAT_008095d0 = 0x806d3a;
  _DAT_008095ce = 2;
  _DAT_008095e2 = 0x806d4c;
  _DAT_008095dc = 0x806d46;
  _DAT_008095da = 2;
  _DAT_008095ee = 0x806d58;
  _DAT_008095e8 = 0x806d52;
  _DAT_008095e6 = 2;
  _DAT_008095fa = 0x806d64;
  _DAT_008095f4 = 0x806d5e;
  _DAT_008095f2 = 2;
  _DAT_00809606 = 0x806d70;
  _DAT_00809600 = 0x806d6a;
  _DAT_008095fe = 2;
  _DAT_00809612 = 0x806d9c;
  _DAT_0080960c = 0x806d76;
  _DAT_0080960a = 2;
  _DAT_0080961e = 0x806dd4;
  _DAT_00809618 = 0x806dc2;
  _DAT_00809616 = 2;
  _DAT_0080962a = 0x806dee;
  _DAT_00809624 = 0x806de6;
  _DAT_00809622 = 2;
  _DAT_00809636 = 0x806dfc;
  _DAT_00809630 = 0x806df6;
  _DAT_0080962e = 2;
  _DAT_00809642 = 0x806e08;
  _DAT_0080963c = 0x806e02;
  _DAT_0080963a = 2;
  _DAT_0080964e = 0x806e14;
  _DAT_00809648 = 0x806e0e;
  _DAT_00809646 = 2;
  piVar2 = (int *)&DAT_008091e2;
  iVar4 = 0x8068ea;
  do {
    if ((int *)0x809407 < piVar2) {
      sensorFaultDebounceMonitor();
      for (puVar3 = &DAT_008091e2; puVar3 < (undefined *)0x809408; puVar3 = puVar3 + 0x16) {
        *(uint *)(puVar3 + 4) = (uint)*(ushort *)(puVar3 + 10) << 0x10;
        *(undefined2 *)(puVar3 + 8) = *(undefined2 *)(puVar3 + 10);
        puVar3[0xf] = 0;
      }
      return;
    }
    piVar2[1] = 0;
    *piVar2 = iVar4;
    *(undefined1 *)((int)piVar2 + 0xf) = *(undefined1 *)(iVar4 + 0x17);
    if ((((uint)(&fault_status_registers_t_00805df2.sensor_fault_status)
                [(short)((int)(uint)*(byte *)(iVar4 + 0x15) >> 4)] &
         1 << (*(byte *)(iVar4 + 0x15) & 0xf)) == 0) ||
       (((uint)*(ushort *)(&DAT_008068c4 + (short)((int)(uint)*(byte *)(iVar4 + 0x15) >> 4) * 2) &
        1 << (*(byte *)(iVar4 + 0x15) & 0xf)) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
LAB_0000af4c:
      *(undefined2 *)(piVar2 + 3) = *(undefined2 *)(iVar4 + 10);
      *(undefined1 *)((int)piVar2 + 0xe) = 1;
    }
    else {
      if ((((uint)(&fault_status_registers_t_00805df2.sensor_fault_status)
                  [(short)((int)(uint)*(byte *)(iVar4 + 0x14) >> 4)] &
           1 << (*(byte *)(iVar4 + 0x14) & 0xf)) == 0) ||
         (((uint)*(ushort *)(&DAT_008068c4 + (short)((int)(uint)*(byte *)(iVar4 + 0x14) >> 4) * 2) &
          1 << (*(byte *)(iVar4 + 0x14) & 0xf)) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) goto LAB_0000af4c;
    }
    piVar2 = (int *)((int)piVar2 + 0x16);
    iVar4 = iVar4 + 0x18;
  } while( true );
}



//
// Function: diagnostic_fuel_calculation_with_vp44_monitoring @ 0x0000afa0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort diagnostic_fuel_calculation_with_vp44_monitoring(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined8 uVar3;
  
  if ((_DAT_008035ec & 8) == 0) {
    _DAT_00800056 = circular_buffer_t_0080c3fc.data_buffer_8;
    _DAT_0080005e = _DAT_00809258;
    uVar3 = tableInterpolationLookup((short *)&DAT_00800050);
    diagnostic_state_buffer_t_00809654.computed_value = (word)((ulonglong)uVar3 >> 0x20);
  }
  else {
    diagnostic_state_buffer_t_00809654.computed_value = _DAT_00806f9e;
  }
  uVar2 = _DAT_00803614 & 0x4000;
  if (((((_DAT_00803614 & 0x4000) == 0) ||
       (((fault_status_registers_t_00805df2.engine_fault_status & 2) != 0 &&
        (uVar2 = _DAT_008068c8 & 2, uVar2 != 0)))) ||
      (((fault_status_registers_t_00805df2.engine_fault_status & 1) != 0 &&
       (uVar2 = _DAT_008068c8 & 1, uVar2 != 0)))) ||
     (((fault_status_registers_t_00805df2.engine_fault_status & 0x10) != 0 &&
      (uVar2 = _DAT_008068c8 & 0x10, uVar2 != 0)))) {
    uVar1 = 0;
  }
  else {
    _DAT_0080006a = _DAT_0080926e;
    uVar1 = lookupTableInterpolation((short *)&DAT_00800064);
    uVar2 = uVar1;
  }
  diagnostic_state_buffer_t_00809654.computed_value =
       uVar1 + diagnostic_state_buffer_t_00809654.computed_value;
  return uVar2;
}



//
// Function: timingParameterPointerSetup @ 0x0000b05c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void timingParameterPointerSetup(void)

{
  _DAT_00800052 = 0x806e34;
  _DAT_00800050 = 2;
  _DAT_0080005a = 0x806e20;
  _DAT_00800058 = 2;
  _DAT_00800060 = 0x806e5a;
  _DAT_0080006a = _DAT_0080926e;
  _DAT_00800066 = 0x808862;
  _DAT_0080006c = 0x808876;
  _DAT_00800064 = 2;
  return;
}



//
// Function: shutdownMinimumSelector16 @ 0x0000b0b0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void shutdownMinimumSelector16(void)

{
  if (diagnostic_state_buffer_t_00809654.computed_value < _DAT_0080d494) {
    _DAT_0080d494 = diagnostic_state_buffer_t_00809654.computed_value;
    _DAT_0080d496 = 0x10;
  }
  return;
}



//
// Function: diagnosticTimingIncrementController @ 0x0000b0ce
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticTimingIncrementController(void)

{
  if (fuel_demand_state_t_0080c9a4._2_2_ != 0x10) {
    _DAT_0080d480 = 0;
    _DAT_00800070 = 0;
    return;
  }
  _DAT_0080d480 = AFICTA;
  timing_mode_control_t_0080965a.protection_counter_1 = 1;
  _DAT_00800070 = 4;
  return;
}



//
// Function: fuelAdjustmentWithFlagUpdate @ 0x0000b0fe
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelAdjustmentWithFlagUpdate(void)

{
  if ((short)(_DAT_0080d480 + fuel_demand_state_t_0080c9a4.limit_minimum) < 0) {
    fuel_demand_state_t_0080c9a4.limit_minimum = 0;
  }
  else {
    fuel_demand_state_t_0080c9a4.limit_minimum =
         _DAT_0080d480 + fuel_demand_state_t_0080c9a4.limit_minimum;
  }
  fuel_demand_state_t_0080c9a4.adjustment_active =
       _DAT_00800070 | fuel_demand_state_t_0080c9a4.adjustment_active & 0xfffb;
  return;
}



//
// Function: vp44TimingConditionChecker @ 0x0000b130
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 vp44TimingConditionChecker(void)

{
  undefined2 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (((_DAT_008035d4 & 0x8000) == 0) ||
     (uVar2 = (uint)_DAT_00803784 + (uint)_DAT_00803786, uVar2 < _DAT_008092f2)) {
    uVar1 = (undefined2)(uVar2 >> 0x10);
    _DAT_0080967e = 0;
  }
  else {
    uVar1 = 0;
    if (((_DAT_008035d4 & 0x8000) != 0) && (uVar1 = 0, _DAT_008092f2 < _DAT_00803786)) {
      _DAT_0080967e = 1;
    }
  }
  return CONCAT22(uVar1,_DAT_0080967e);
}



//
// Function: fuelTimingModeArbitrationSlowCycle40Coordinator @ 0x0000b18c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort fuelTimingModeArbitrationSlowCycle40Coordinator(void)

{
  undefined4 uVar1;
  
  if (((engine_operating_mode_t_0080c810.state == 1) ||
      (engine_operating_mode_t_0080c810.state == 2)) ||
     (engine_operating_mode_t_0080c810.state == 6)) {
    timing_mode_control_t_0080965a.fuel_source_mode_11_state = 1;
    timing_mode_control_t_0080965a.fuel_source_mode_11_timer = _DAT_00806fae;
    timing_mode_control_t_0080965a.fuel_mode_transition_state = 1;
    timing_mode_control_t_0080965a.fuel_mode_transition_timer = _DAT_00806fa6;
    timing_mode_control_t_0080965a.blend_state = 0;
    timing_mode_control_t_0080965a.blend_accumulator = 0;
    timing_mode_control_t_0080965a.reserved_1A = 0;
    timing_mode_control_t_0080965a.protection_blend_ramp = 0;
  }
  else {
    timingProtectionFlagsOrchestrator();
  }
  if (_DAT_00809cb2 == 0) {
    if ((engine_control_flags_t_008035d6.fuel_demand_control & 1) == 0) {
      uVar1 = vp44TimingConditionChecker();
      if ((short)uVar1 == 0) {
        if (((_DAT_008035d4 & 0x4000) == 0) || (_DAT_0080c990 != 1)) {
          timing_mode_control_t_0080965a.source_selector = 0;
          timing_mode_control_t_0080965a.blend_factor =
               timing_mode_control_t_0080965a.protection_blend_ramp;
        }
        else {
          timing_mode_control_t_0080965a.source_selector = 3;
          timing_mode_control_t_0080965a.blend_factor = _DAT_00806fac;
        }
      }
      else {
        timing_mode_control_t_0080965a.source_selector = 2;
        timing_mode_control_t_0080965a.blend_factor = _DAT_00806fa8;
      }
    }
    else {
      timing_mode_control_t_0080965a.source_selector = 1;
      timing_mode_control_t_0080965a.blend_factor = _DAT_00803782;
    }
  }
  else {
    timing_mode_control_t_0080965a.source_selector = 4;
    timing_mode_control_t_0080965a.blend_factor = _DAT_00809cbc;
  }
  if (0x4000 < timing_mode_control_t_0080965a.blend_factor) {
    timing_mode_control_t_0080965a.blend_factor = 0x4000;
  }
  if ((_DAT_008035ec & 0x10) == 0) {
    fuel_demand_state_t_0080c9a4.timing_blend_factor = timing_mode_control_t_0080965a.blend_factor;
  }
  return _DAT_008035ec & 0x10;
}



//
// Function: fuelTableBlendResultHandler @ 0x0000b27e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 fuelTableBlendResultHandler(void)

{
  if ((timing_mode_control_t_0080965a.protection_counter_2 == 1) &&
     (_DAT_00806fb2 < timing_mode_control_t_0080965a.blend_state)) {
    timing_mode_control_t_0080965a.blend_state = _DAT_00806fb2;
    timing_mode_control_t_0080965a._24_4_ = (uint)_DAT_00806fb2 << 0x10;
  }
  timing_mode_control_t_0080965a.blend_state = coreTableInterpolation();
  if (timing_mode_control_t_0080965a.blend_state <= _DAT_00806fb2) {
    return 0;
  }
  if (_null_ < timing_mode_control_t_0080965a.blend_state) {
    return 1;
  }
  return timing_mode_control_t_0080965a.fuel_blend_result;
}



//
// Function: fuelSourceOilPressureConditionChecker @ 0x0000b2ee
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint fuelSourceOilPressureConditionChecker(void)

{
  uint in_D0;
  
  if (((fuel_demand_state_t_0080c9a4._2_2_ != 10) && (_DAT_0080969a != 1)) && (_DAT_0080d17a != 1))
  {
    return in_D0 & 0xffff0000;
  }
  return 1;
}



//
// Function: fuelSourceMode11CountdownHandler @ 0x0000b314
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int fuelSourceMode11CountdownHandler(void)

{
  ushort uVar1;
  undefined4 in_D0;
  
  uVar1 = (ushort)((uint)in_D0 >> 0x10);
  if (fuel_demand_state_t_0080c9a4._2_2_ == 0xb) {
    timing_mode_control_t_0080965a.fuel_source_mode_11_timer = _DAT_00806fae;
    timing_mode_control_t_0080965a.fuel_source_mode_11_state = 1;
    return (uint)uVar1 << 0x10;
  }
  if ((timing_mode_control_t_0080965a.fuel_source_mode_11_state == 1) &&
     (timing_mode_control_t_0080965a.fuel_source_mode_11_timer != 0)) {
    timing_mode_control_t_0080965a.fuel_source_mode_11_timer =
         timing_mode_control_t_0080965a.fuel_source_mode_11_timer - 1;
    return (uint)uVar1 << 0x10;
  }
  timing_mode_control_t_0080965a.fuel_source_mode_11_state = 0;
  return 1;
}



//
// Function: fuelModeTransitionCountdownHandler @ 0x0000b35c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int fuelModeTransitionCountdownHandler(void)

{
  ushort uVar1;
  undefined4 in_D0;
  
  uVar1 = (ushort)((uint)in_D0 >> 0x10);
  if ((timing_mode_control_t_0080965a.protection_counter_1 == 1) ||
     (timing_mode_control_t_0080965a.protection_counter_2 == 1)) {
    timing_mode_control_t_0080965a.fuel_mode_transition_timer = _DAT_00806fa6;
    timing_mode_control_t_0080965a.fuel_mode_transition_state = 1;
    return (uint)uVar1 << 0x10;
  }
  if ((timing_mode_control_t_0080965a.fuel_mode_transition_state == 1) &&
     (timing_mode_control_t_0080965a.fuel_mode_transition_timer != 0)) {
    timing_mode_control_t_0080965a.fuel_mode_transition_timer =
         timing_mode_control_t_0080965a.fuel_mode_transition_timer - 1;
    return (uint)uVar1 << 0x10;
  }
  timing_mode_control_t_0080965a.fuel_mode_transition_state = 0;
  return 1;
}



//
// Function: timingProtectionFlagsOrchestrator @ 0x0000b3ae
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint timingProtectionFlagsOrchestrator(void)

{
  int iVar1;
  ushort uVar3;
  uint uVar2;
  
  uVar3 = 0;
  if ((_DAT_008035d4 & 0x400) != 0) {
    iVar1 = fuelSourceMode11CountdownHandler();
    uVar3 = (ushort)iVar1;
    timing_mode_control_t_0080965a.mode_11_result = uVar3;
  }
  if ((_DAT_008035d4 & 0x800) != 0) {
    iVar1 = fuelModeTransitionCountdownHandler();
    timing_mode_control_t_0080965a.transition_result = (word)iVar1;
    uVar3 = timing_mode_control_t_0080965a.transition_result | uVar3;
  }
  if ((_DAT_008035d4 & 0x1000) != 0) {
    timing_mode_control_t_0080965a.fuel_blend_result = fuelTableBlendResultHandler();
    uVar3 = timing_mode_control_t_0080965a.fuel_blend_result | uVar3;
  }
  uVar2 = _DAT_008035d4 & 0xffff2000;
  if ((_DAT_008035d4 & 0x2000) != 0) {
    uVar2 = fuelSourceOilPressureConditionChecker();
    timing_mode_control_t_0080965a.oil_pressure_result = (word)uVar2;
    uVar3 = timing_mode_control_t_0080965a.oil_pressure_result | uVar3;
  }
  if (uVar3 == 0) {
    timing_mode_control_t_0080965a.protection_blend_ramp = 0;
  }
  else if (timing_mode_control_t_0080965a.protection_blend_ramp != 0x4000) {
    if (timing_mode_control_t_0080965a.protection_blend_ramp < _DAT_00806fa4) {
      timing_mode_control_t_0080965a.protection_blend_ramp =
           _DAT_00806fa0 + timing_mode_control_t_0080965a.protection_blend_ramp;
      uVar2 = (uint)_DAT_00806fa2 + (uint)_DAT_00806fa4;
      if (uVar2 < timing_mode_control_t_0080965a.protection_blend_ramp) {
        timing_mode_control_t_0080965a.protection_blend_ramp = _DAT_00806fa2 + _DAT_00806fa4;
        uVar2 = CONCAT22((short)(uVar2 >> 0x10),timing_mode_control_t_0080965a.protection_blend_ramp
                        );
      }
    }
    else {
      uVar2 = CONCAT22((short)(uVar2 >> 0x10),_DAT_00806fa2);
      timing_mode_control_t_0080965a.protection_blend_ramp =
           _DAT_00806fa2 + timing_mode_control_t_0080965a.protection_blend_ramp;
    }
  }
  if (0x4000 < timing_mode_control_t_0080965a.protection_blend_ramp) {
    timing_mode_control_t_0080965a.protection_blend_ramp = 0x4000;
  }
  timing_mode_control_t_0080965a.protection_counter_1 = 0;
  timing_mode_control_t_0080965a.protection_counter_2 = 0;
  return uVar2;
}



//
// Function: shutdownProtectionCalculator @ 0x0000b47e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong shutdownProtectionCalculator(void)

{
  undefined2 uVar1;
  undefined4 in_D0;
  undefined4 uVar2;
  undefined4 in_D1;
  ulonglong uVar3;
  
  uVar1 = (undefined2)((uint)in_D0 >> 0x10);
  if (((engine_control_flags_t_008035d6.fuel_demand_control & 0x20) == 0) ||
     (engine_operating_mode_t_0080c810.state != 3)) {
    _DAT_00809682 = _DAT_00807f3c;
    return CONCAT44(CONCAT22(uVar1,engine_control_flags_t_008035d6.fuel_demand_control),in_D1) &
           0xffff0020ffffffff;
  }
  if ((((fault_status_registers_t_00805df2.fault_status_2 & 4) == 0) || ((_DAT_008068c6 & 4) == 0))
     && (((fault_status_registers_t_00805df2.fault_status_2 & 8) == 0 || ((_DAT_008068c6 & 8) == 0))
        )) {
    _DAT_0080007a = circular_buffer_t_0080c3fc.data_buffer_8;
    _DAT_00800082 = _DAT_008092f2;
    uVar3 = tableInterpolationLookup((short *)&DAT_00800074);
    _DAT_00809682 = (short)(uVar3 >> 0x20);
    return uVar3;
  }
  uVar2 = CONCAT22(uVar1,circular_buffer_t_0080c3fc.data_buffer_8);
  if (_DAT_00806fb6 < circular_buffer_t_0080c3fc.data_buffer_8) {
    _DAT_00809682 = _DAT_00806fb8;
    return CONCAT44(uVar2,in_D1);
  }
  _DAT_00809682 = _DAT_00807f3c;
  return CONCAT44(uVar2,in_D1);
}



//
// Function: fuelParameterPointerSetup @ 0x0000b528
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelParameterPointerSetup(void)

{
  _DAT_00800074 = 2;
  _DAT_00800076 = 0x806fba;
  _DAT_0080007c = 2;
  _DAT_0080007e = 0x806fe0;
  _DAT_00800084 = 0x806fea;
  return;
}



//
// Function: shutdownMinimumSelector15 @ 0x0000b556
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void shutdownMinimumSelector15(void)

{
  if (_DAT_00809682 < _DAT_0080d494) {
    _DAT_0080d494 = _DAT_00809682;
    _DAT_0080d496 = 0xf;
  }
  return;
}



//
// Function: rpmParameterPointerSetup @ 0x0000b574
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rpmParameterPointerSetup(void)

{
  _DAT_00800096 = 2;
  _DAT_00800098 = 0x807886;
  _DAT_0080009e = 0x807892;
  return;
}



//
// Function: targetRpmRateLimiter @ 0x0000b594
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void targetRpmRateLimiter(void)

{
  if (_DAT_00800092 == 7) {
    _DAT_008000a6 = _DAT_008000a8;
  }
  else {
    _DAT_008000a6 = _DAT_00809cfe;
  }
  _DAT_008000a8 = _DAT_00809d1a - _DAT_008000a6;
  if ((int)(short)_DAT_008000a8 < (int)-(uint)_DAT_00807884) {
    _DAT_008000a8 = (ushort)-(uint)_DAT_00807884;
  }
  if ((int)(uint)_DAT_00807884 < (int)(short)_DAT_008000a8) {
    _DAT_008000a8 = _DAT_00807884;
  }
  _DAT_008000a8 = _DAT_008000a6 + _DAT_008000a8;
  if ((int)((int)(short)_DAT_008000a8 - (uint)_DAT_00809cfe) < 0) {
    _DAT_0080009c = -(_DAT_008000a8 - _DAT_00809cfe);
  }
  else {
    _DAT_0080009c = _DAT_008000a8 - _DAT_00809cfe;
  }
  _DAT_008000a2 = lookupTableInterpolation((short *)&DAT_00800096);
  _DAT_00809cfe =
       (short)((int)((uint)_DAT_00809cfe * (uint)_DAT_008000a2 +
                    (uint)_DAT_00809d1a * (0x4000 - (uint)_DAT_008000a2)) >> 0xe);
  return;
}



//
// Function: engine_speed_governor @ 0x0000b656
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engine_speed_governor(void)

{
  int iVar1;
  int iVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sStack_6;
  
  FUN_0002f8dc();
  if ((((_DAT_0080d49c == 7) || (_DAT_0080d49c == 3)) || (_DAT_0080d49c == 2)) ||
     (_DAT_0080d49c == 0x1e)) {
    sVar4 = _DAT_00809d04;
    if (_DAT_0080d49c != _DAT_00800092) {
      iVar2 = (uint)_DAT_00809d1e * ((int)_DAT_00809d32[3] + (int)_DAT_00809d32[2]);
      if (iVar2 == 0) {
        _DAT_00809cfe = circular_buffer_t_0080c3fc.data_buffer_8;
      }
      else {
        iVar2 = (int)(((uint)fuel_demand_state_t_0080c9a4.command - (uint)_DAT_00809768) *
                      (0x400 - (uint)_DAT_00809d1c) * 0x80) / iVar2;
        if (iVar2 < 0x30d4) {
          if (iVar2 < -0x30d3) {
            iVar2 = -32000;
          }
          else {
            iVar2 = (iVar2 << 8) / 100;
          }
        }
        else {
          iVar2 = 32000;
        }
        iVar2 = (uint)circular_buffer_t_0080c3fc.data_buffer_8 + iVar2;
        if (iVar2 < 0x10000) {
          if (iVar2 < 0) {
            _DAT_00809cfe = 0;
          }
          else {
            _DAT_00809cfe = (ushort)iVar2;
          }
        }
        else {
          _DAT_00809cfe = 0xffff;
        }
      }
      _DAT_00809d12 = (uint)_DAT_00809cfe << 0x10;
      iVar2 = (uint)_DAT_00809cfe - (uint)circular_buffer_t_0080c3fc.data_buffer_8;
      if (iVar2 < 32000) {
        if (iVar2 < -31999) {
          sVar4 = -32000;
        }
        else {
          sStack_6 = (short)iVar2;
          sVar4 = sStack_6;
        }
      }
      else {
        sVar4 = 32000;
      }
    }
    if (_DAT_0080d49c == 7) {
      targetRpmRateLimiter();
    }
    else {
      _DAT_00809cfe = coreTableInterpolation();
      _DAT_008000a2 = (ushort)((int)(uint)*_DAT_00809d0e >> 2);
    }
    iVar2 = (uint)_DAT_00809cfe - (uint)circular_buffer_t_0080c3fc.data_buffer_8;
    if (iVar2 < 32000) {
      if (iVar2 < -31999) {
        _DAT_00809d04 = -32000;
      }
      else {
        sStack_6 = (short)iVar2;
        _DAT_00809d04 = sStack_6;
      }
    }
    else {
      _DAT_00809d04 = 32000;
    }
    if (_DAT_00809d2a == 1) {
      _DAT_00809d00 = 1;
      _DAT_0080008e = (uint)_DAT_00809cc0 << 0x10;
      _DAT_00800088 = _DAT_00809cc2;
      _DAT_008000a4 = _DAT_00809768;
      sVar4 = _DAT_00809cbe;
      sVar5 = _DAT_00809cc4;
      _DAT_00809d0c = _DAT_00809cc8;
      sVar3 = _DAT_00809cc6;
    }
    else if ((_DAT_00800094 == fuel_demand_state_t_0080c9a4.command) &&
            (_DAT_0080d49c == _DAT_00800092)) {
      _DAT_00809d00 = 0;
      sVar5 = _DAT_00809d08;
      sVar3 = _DAT_00809d0a;
    }
    else {
      _DAT_00809d00 = 1;
      if (_DAT_008078b0 == _DAT_008078b2) {
        _DAT_0080008e = 0;
        sVar3 = 0;
      }
      else if (_DAT_00809768 < fuel_demand_state_t_0080c9a4.command) {
        _DAT_0080008e =
             rpmFuelCalculation((uint)fuel_demand_state_t_0080c9a4.command - (uint)_DAT_00809768,
                                0x100 - _DAT_008078b4,(int)_DAT_008078b0 - (int)_DAT_008078b2);
        if (0x1700 < _DAT_0080008e) {
          _DAT_0080008e = 0x1700;
        }
        sVar3 = (short)_DAT_0080008e;
        _DAT_0080008e = _DAT_0080008e << 0x10;
      }
      else {
        iVar2 = rpmFuelCalculation((uint)_DAT_00809768 - (uint)fuel_demand_state_t_0080c9a4.command,
                                   0x100 - _DAT_008078b4,(int)_DAT_008078b0 - (int)_DAT_008078b2);
        if (0x1700 < iVar2) {
          iVar2 = 0x1700;
        }
        _DAT_0080008e = (uint)(ushort)-(short)iVar2 << 0x10;
        sVar3 = -(short)iVar2;
      }
      _DAT_00800088 = circular_buffer_t_0080c3fc.data_buffer_8;
      sVar5 = 0;
      _DAT_00809d0c = fuel_demand_state_t_0080c9a4.command - _DAT_00809768;
      _DAT_008000a4 = _DAT_00809768;
    }
    iVar2 = (uint)circular_buffer_t_0080c3fc.data_buffer_8 - (int)(short)_DAT_00800088;
    if (iVar2 < 8000) {
      if (iVar2 < -7999) {
        _DAT_00809cfc = -8000;
      }
      else {
        sStack_6 = (short)iVar2;
        _DAT_00809cfc = sStack_6;
      }
    }
    else {
      _DAT_00809cfc = 8000;
    }
    _DAT_00800088 = circular_buffer_t_0080c3fc.data_buffer_8;
    _DAT_00809cfa = _DAT_00809d04 - sVar4;
    if (_DAT_00809cfa < 32000) {
      if (_DAT_00809cfa < -31999) {
        _DAT_00809cfa = -32000;
      }
    }
    else {
      _DAT_00809cfa = 32000;
    }
    _DAT_0080008a =
         ((int)sVar4 * ((int)_DAT_00809d32[3] + (int)_DAT_00809d32[2]) +
         (int)_DAT_00809cfa * ((int)_DAT_00809d32[2] + (int)*_DAT_00809d32)) -
         (int)_DAT_00809cfc * (int)_DAT_00809d32[1] >> 9;
    if (_DAT_0080008a < 0xe6000) {
      if (_DAT_0080008a < -0xe5fff) {
        _DAT_0080008a = -0xe6000;
      }
    }
    else {
      _DAT_0080008a = 0xe6000;
    }
    sStack_6 = (short)((int)_DAT_00809cfa * (int)_DAT_00809d32[4] -
                       (int)_DAT_00809cfc * (int)_DAT_00809d32[5] >> 0xd);
    if (sStack_6 < _DAT_0080787c) {
      if (-(int)_DAT_0080787c < (int)sStack_6) {
        _DAT_00809cf8 = 0;
      }
      else {
        _DAT_00809cf8 = _DAT_0080787c + sStack_6;
        if ((int)_DAT_00809cf8 <= -(int)_DAT_00807880) {
          _DAT_00809cf8 = (short)-(int)_DAT_00807880;
        }
      }
    }
    else {
      _DAT_00809cf8 = sStack_6 - _DAT_0080787c;
      if (_DAT_00807880 <= _DAT_00809cf8) {
        _DAT_00809cf8 = _DAT_00807880;
      }
    }
    sStack_6 = (short)((int)sVar5 * (int)_DAT_0080787e >> 10) +
               (short)((int)((uint)_DAT_00809d1e * (int)_DAT_00809cf8) >> 10);
    if (sStack_6 < 0x1700) {
      if (sStack_6 < -0x16ff) {
        _DAT_00809d08 = -0x1700;
      }
      else {
        _DAT_00809d08 = sStack_6;
      }
    }
    else {
      _DAT_00809d08 = 0x1700;
    }
    _DAT_0080008e =
         (int)sVar5 * (_DAT_00809d1c - 0x400) * 0x10 +
         ((int)((uint)_DAT_00809d1c * (_DAT_0080008e >> 9)) >> 3) +
         ((int)(_DAT_0080008a * (uint)_DAT_00809d1e) >> 1);
    if (_DAT_0080008e < -0x5c00000) {
      _DAT_0080008e = -0x17000000;
    }
    else if (_DAT_0080008e < 0x5c00000) {
      _DAT_0080008e = _DAT_0080008e * 4;
    }
    else {
      _DAT_0080008e = 0x17000000;
    }
    _DAT_00809d06 = _DAT_0080008e;
    _DAT_00809d0a = _DAT_00809d08 + _DAT_0080008e;
    if (_DAT_00809d0a < -0x16ff) {
      _DAT_00809d0a = -0x1700;
    }
    else if (0x1700 < _DAT_00809d0a) {
      _DAT_00809d0a = 0x1700;
    }
    iVar2 = (int)_DAT_00809d0c * (int)_DAT_00809d32[8] +
            ((int)_DAT_00809d0a * (int)_DAT_00809d32[6] - (int)sVar3 * (int)_DAT_00809d32[7]);
    iVar1 = iVar2 >> 8;
    if (iVar1 < -0x16ff) {
      _DAT_00809d0c = -0x1700;
    }
    else if (iVar1 < 0x1700) {
      sStack_6 = (short)((uint)iVar2 >> 8);
      _DAT_00809d0c = sStack_6;
    }
    else {
      _DAT_00809d0c = 0x1700;
    }
    _DAT_008000a4 =
         (ushort)((int)((uint)_DAT_008000a4 * (uint)_DAT_008000a2 +
                       (uint)_DAT_00809768 * (0x4000 - (uint)_DAT_008000a2)) >> 0xe);
    if (0x1700 < _DAT_008000a4) {
      _DAT_008000a4 = 0x1700;
    }
    _DAT_00800094 = _DAT_008000a4 + _DAT_00809d0c;
    if ((short)_DAT_00800094 < (short)_DAT_00809d26) {
      _DAT_00809d02 = _DAT_00800094;
      if ((short)_DAT_00800094 <= (short)_DAT_00809d28) {
        _DAT_00809d02 = _DAT_00809d28;
      }
    }
    else {
      _DAT_00809d02 = _DAT_00809d26;
    }
    _DAT_0080d49a = _DAT_00809d02;
  }
  _DAT_00800092 = _DAT_0080d49c;
  return;
}



//
// Function: diagnosticDataCopyHandler @ 0x0000bdd4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticDataCopyHandler(void)

{
  if ((_DAT_00809cca != 0) && (_DAT_00809d18 == 0)) {
    _DAT_00809d18 = 0x1e;
    _DAT_00809d1a = _DAT_00809ccc;
    _DAT_00809d1c = _DAT_00809cce;
    _DAT_00809d1e = _DAT_00809cd0;
    _DAT_00809d32 = 0x809ce6;
    _DAT_00809d0e = 0x809cd2;
    _DAT_00809cbe = _DAT_00809cda;
    _DAT_00809cc0 = _DAT_00809cdc;
    _DAT_00809cc2 = _DAT_00809cde;
    _DAT_00809cc4 = _DAT_00809ce0;
    _DAT_00809cc6 = _DAT_00809ce2;
    _DAT_00809cc8 = _DAT_00809ce4;
    _DAT_00809d2a = _DAT_00809cd8;
    _DAT_00809d26 = _DAT_00809cd4;
    _DAT_00809d28 = _DAT_00809cd6;
  }
  return;
}



//
// Function: diagnosticStatus30Setter @ 0x0000be7c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticStatus30Setter(void)

{
  if ((_DAT_0080d49c == 0) && (_DAT_00809d18 == 0x1e)) {
    _DAT_0080d49c = 0x1e;
  }
  return;
}



//
// Function: diagnosticStatus2Initializer @ 0x0000be96
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticStatus2Initializer(undefined4 param_1)

{
  if ((_DAT_0080d49c == 0) && (_DAT_00809d18 == 2)) {
    _DAT_0080d49c = 2;
    _DAT_00809d32 = (uint)(ushort)fuel_arbitrator_diag_t_0080cff8._26_2_ * 0x12 + 0x8078fc;
    if (param_1._0_2_ != 2) {
      _DAT_00809d2a = 0;
      _DAT_00809d1c = 0x400;
      _DAT_00809d1e = 0x400;
      _DAT_00809d28 = _DAT_008078fa;
      _DAT_00809d26 = _DAT_008078f8;
      _DAT_00809d0e = 0x8078f6;
    }
  }
  return;
}



//
// Function: diagnosticState2Initializer @ 0x0000bf0a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticState2Initializer(void)

{
  if ((_DAT_00809d18 == 0) && (fuel_arbitrator_diag_t_0080cff8.rpm_target == 1)) {
    _DAT_00809d18 = 2;
    _DAT_00809d1a = fuel_arbitrator_diag_t_0080cff8.state_pointer._1_2_;
  }
  return;
}



//
// Function: derate_application_controller @ 0x0000bf2e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void derate_application_controller(void)

{
  _DAT_00809d2c = _DAT_00807882;
  _DAT_00809d2e = *_DAT_00809d36;
  _DAT_00809d30 = *_DAT_00809d3a;
  _DAT_00809d16 =
       _DAT_00809d2e +
       (short)(((uint)_DAT_00809d4c * ((uint)_DAT_00809d30 - (uint)_DAT_00809d2e)) / 400);
  _DAT_00809d18 = 0;
  diagnosticDataCopyHandler();
  diagnosticState2Initializer();
  diagnosticState7Setter();
  return;
}



//
// Function: initDerateSystemPointers @ 0x0000bf9c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initDerateSystemPointers(void)

{
  _DAT_00809d36 = 0x8036b6;
  _DAT_00809d3a = 0x8036b8;
  _DAT_00809d2c = _DAT_00807882;
  return;
}



//
// Function: diagnosticValueCalculator @ 0x0000bfbc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticValueCalculator(void)

{
  uint uVar1;
  
  if (_DAT_00809d2c == 1) {
    _DAT_008000be = _DAT_00809d1a;
    _DAT_00809d24 = lookupTableInterpolation((short *)&DAT_008000b8);
  }
  else if (_DAT_00809d2c == 0) {
    _DAT_008000b2 = _DAT_00809d1a;
    _DAT_00809d24 = lookupTableInterpolation((short *)&DAT_008000ac);
  }
  uVar1 = (uint)(ushort)(_DAT_008078aa + _DAT_008078a8) * (uint)_DAT_00809d24;
  if (uVar1 < 0x2655879) {
    _DAT_00809d20 = (ushort)((0x2655879 - uVar1 >> 1) / (uVar1 + 0x2655879 >> 0xb & 0xffff));
  }
  else {
    _DAT_00809d20 = 0;
  }
  _DAT_00809d22 = (undefined2)((int)(_DAT_00809d20 + 0x400) >> 1);
  _DAT_00809d1c = _DAT_00809d20;
  _DAT_00809d1e = _DAT_00809d22;
  return;
}



//
// Function: diagnosticStatus7Initializer @ 0x0000c084
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticStatus7Initializer(undefined4 param_1)

{
  if ((_DAT_0080d49c == 0) && (_DAT_008036ea == 1)) {
    _DAT_0080d49c = 7;
    diagnosticValueCalculator();
    if ((param_1._0_2_ != 7) && (param_1._0_2_ != 3)) {
      _DAT_00809d32 = 0x8078a4;
      _DAT_00809d2a = 0;
      _DAT_00809d28 = _DAT_008078a2;
      _DAT_00809d26 = _DAT_008078a0;
      _DAT_00809d0e = 0x80789e;
    }
  }
  return;
}



//
// Function: diagnosticState7Setter @ 0x0000c0e6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticState7Setter(void)

{
  if (_DAT_00809d18 == 0) {
    _DAT_00809d1a = _DAT_00809d16;
    _DAT_00809d18 = 7;
  }
  return;
}



//
// Function: diagnosticTablePointerSetup @ 0x0000c100
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticTablePointerSetup(void)

{
  _DAT_008000ac = 2;
  _DAT_008000ae = 0x8078b6;
  _DAT_008000b4 = 0x8078c6;
  _DAT_008000b8 = 2;
  _DAT_008000ba = 0x8078d6;
  _DAT_008000c0 = 0x8078e6;
  _DAT_00809d2c = 0;
  return;
}



//
// Function: tpuTimerInitializer @ 0x0000c144
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void tpuTimerInitializer(void)

{
  _DAT_008000c4 = &DAT_00ffc800;
  _DAT_00809d4a = 6;
  _DAT_00ffc812 = 0x2240;
  DAT_00ffc816 = 0x80;
  _DAT_00ffc810 = 0x9955;
  _DAT_00ffc822 = 0x2000;
  DAT_00ffc826 = 0x88;
  _DAT_00ffc820 = 0x5559;
  _DAT_00ffc832 = 0xa240;
  DAT_00ffc836 = 0x80;
  _DAT_00ffc830 = 0x9955;
  _DAT_00ffc842 = 0xa000;
  DAT_00ffc846 = 0x88;
  _DAT_00ffc840 = 0x5559;
  _DAT_00ffc852 = 0xe240;
  DAT_00ffc856 = 0x80;
  _DAT_00ffc850 = 0x9955;
  _DAT_00ffc862 = 0xe000;
  DAT_00ffc866 = 0x88;
  _DAT_00ffc860 = 0x5559;
  DAT_00ffc800 = DAT_00ffc800 | 10;
  return;
}



//
// Function: emptyStubFunction1 @ 0x0000c1f0
//

void emptyStubFunction1(void)

{
  return;
}



//
// Function: modeBasedDataDispatcher @ 0x0000c1f2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void modeBasedDataDispatcher(undefined4 param_1)

{
  char cVar1;
  
  cVar1 = (char)((uint)param_1 >> 0x10);
  if (cVar1 == '\x01') {
    vp44TimingRangeValidation();
    FUN_00033880(_DAT_008000c4 + 0x10);
    return;
  }
  if (cVar1 == '\x03') {
    FUN_00033a3a(_DAT_008000c4 + 0x30);
    return;
  }
  if (cVar1 == '\x05') {
    FUN_00033b8c();
    FUN_00033bf2(_DAT_008000c4 + 0x50);
  }
  return;
}



//
// Function: emptyStubFunction3 @ 0x0000c260
//

void emptyStubFunction3(void)

{
  return;
}



//
// Function: emptyStubFunction2 @ 0x0000c262
//

void emptyStubFunction2(void)

{
  return;
}



//
// Function: boostPressureControlInit @ 0x0000c264
//

void boostPressureControlInit(void)

{
  FUN_0002d90c();
  writeHourMeterConversionData();
  return;
}



//
// Function: engineProtectionSystemInit @ 0x0000c272
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engineProtectionSystemInit(void)

{
  engine_protection_init();
  FUN_0002d3fa();
  FUN_0002d688();
  FUN_0002c506();
  FUN_0002d92c();
  FUN_0002e282();
  FUN_0002ddea();
  FUN_0002e3a8();
  FUN_0002e5fe();
  FUN_0002ecec();
  FUN_0002ed96();
  FUN_0002f5f2();
  FUN_0002f748();
  FUN_0002c4de();
  rpmParameterPointerSetup();
  FUN_0002f920();
  FUN_0002f986();
  FUN_0002fdfe();
  FUN_00030914();
  engineModeOutputControlInit();
  FUN_00030c3e();
  FUN_00030cec();
  FUN_0002fd5e();
  FUN_00030a8e();
  FUN_000332ce();
  _DAT_0080d092 = _DAT_00803698;
  FUN_000317ee();
  FUN_00031c06();
  FUN_000320dc();
  FUN_00032342();
  FUN_00032b00();
  FUN_000320bc();
  initHourMeterConversionData();
  return;
}



//
// Function: initBoostProtectionSystem @ 0x0000c33e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initBoostProtectionSystem(void)

{
  _DAT_0080969a = 0;
  _DAT_0080969c = 0;
  _DAT_008096a6 = 0;
  _DAT_008096a8 = 0;
  _DAT_008096aa = 0;
  _DAT_008096ac = _DAT_008037b4;
  return;
}



//
// Function: periodicIoAndCanFaultMonitor @ 0x0000c368
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void periodicIoAndCanFaultMonitor(void)

{
  fault_persistence_counters_t_008000c8.periodic_monitor_phase =
       fault_persistence_counters_t_008000c8.periodic_monitor_phase + 1;
  if (4 < fault_persistence_counters_t_008000c8.periodic_monitor_phase) {
    fault_persistence_counters_t_008000c8.periodic_monitor_phase = 0;
  }
  if (fault_persistence_counters_t_008000c8.periodic_monitor_phase == 1) {
    if (((DAT_0080bdca & 0x80) != 0) == ((DAT_0080bdf3 & 0x20) != 0)) {
      if (((fault_status_registers_t_00805df2.io_fault_status_2 & 0x80) != 0) &&
         ((fault_latch_registers_t_00805e32.io_fault_latch_2 & 0x80) == 0)) {
        fault_status_registers_t_00805df2.io_fault_status_2 =
             fault_status_registers_t_00805df2.io_fault_status_2 & 0xff7f;
        fault_persistence_counters_t_008000c8.can_pin_fault = 0;
      }
    }
    else if (fault_persistence_counters_t_008000c8.can_pin_fault < _DAT_00807946) {
      fault_persistence_counters_t_008000c8.can_pin_fault =
           fault_persistence_counters_t_008000c8.can_pin_fault + 1;
    }
    else {
      fault_status_registers_t_00805df2.io_fault_status_2 =
           fault_status_registers_t_00805df2.io_fault_status_2 | 0x80;
      fault_latch_registers_t_00805e32.io_fault_latch_2 =
           fault_latch_registers_t_00805e32.io_fault_latch_2 | 0x80;
    }
    if (((DAT_0080bdcb & 0x80) != 0) == ((DAT_0080bdef & 0x80) != 0)) {
      if (((fault_status_registers_t_00805df2.io_fault_status_2 & 0x40) != 0) &&
         ((fault_latch_registers_t_00805e32.io_fault_latch_2 & 0x40) == 0)) {
        fault_status_registers_t_00805df2.io_fault_status_2 =
             fault_status_registers_t_00805df2.io_fault_status_2 & 0xffbf;
        fault_persistence_counters_t_008000c8.io_fault_1 = 0;
      }
    }
    else if (fault_persistence_counters_t_008000c8.io_fault_1 < _DAT_00807946) {
      fault_persistence_counters_t_008000c8.io_fault_1 =
           fault_persistence_counters_t_008000c8.io_fault_1 + 1;
    }
    else {
      fault_status_registers_t_00805df2.io_fault_status_2 =
           fault_status_registers_t_00805df2.io_fault_status_2 | 0x40;
      fault_latch_registers_t_00805e32.io_fault_latch_2 =
           fault_latch_registers_t_00805e32.io_fault_latch_2 | 0x40;
    }
    if (((DAT_0080bdcb & 1) != 0) == ((DAT_0080bdef & 1) != 0)) {
      if (((fault_status_registers_t_00805df2.io_fault_status_2 & 0x20) != 0) &&
         ((fault_latch_registers_t_00805e32.io_fault_latch_2 & 0x20) == 0)) {
        fault_status_registers_t_00805df2.io_fault_status_2 =
             fault_status_registers_t_00805df2.io_fault_status_2 & 0xffdf;
        fault_persistence_counters_t_008000c8.io_fault_2 = 0;
      }
    }
    else if (fault_persistence_counters_t_008000c8.io_fault_2 < _DAT_00807946) {
      fault_persistence_counters_t_008000c8.io_fault_2 =
           fault_persistence_counters_t_008000c8.io_fault_2 + 1;
    }
    else {
      fault_status_registers_t_00805df2.io_fault_status_2 =
           fault_status_registers_t_00805df2.io_fault_status_2 | 0x20;
      fault_latch_registers_t_00805e32.io_fault_latch_2 =
           fault_latch_registers_t_00805e32.io_fault_latch_2 | 0x20;
    }
    if (((DAT_0080bdcb & 2) != 0) == ((DAT_0080bdef & 2) != 0)) {
      if (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x4000) != 0) &&
         ((fault_latch_registers_t_00805e32.io_fault_latch_1 & 0x4000) == 0)) {
        fault_status_registers_t_00805df2.io_fault_status_1 =
             fault_status_registers_t_00805df2.io_fault_status_1 & 0xbfff;
        fault_persistence_counters_t_008000c8.io_fault_3 = 0;
      }
    }
    else if (fault_persistence_counters_t_008000c8.io_fault_3 < _DAT_00807946) {
      fault_persistence_counters_t_008000c8.io_fault_3 =
           fault_persistence_counters_t_008000c8.io_fault_3 + 1;
    }
    else {
      fault_status_registers_t_00805df2.io_fault_status_1 =
           fault_status_registers_t_00805df2.io_fault_status_1 | 0x4000;
      fault_latch_registers_t_00805e32.io_fault_latch_1 =
           fault_latch_registers_t_00805e32.io_fault_latch_1 | 0x4000;
    }
    if (((DAT_0080bdcb & 4) != 0) == ((DAT_0080bdef & 4) != 0)) {
      if ((fault_status_registers_t_00805df2.io_fault_status_1 & 0x8000) != 0) {
        if ((fault_latch_registers_t_00805e32.io_fault_latch_1 & 0x8000) == 0) {
          fault_status_registers_t_00805df2.io_fault_status_1 =
               fault_status_registers_t_00805df2.io_fault_status_1 & 0x7fff;
          fault_persistence_counters_t_008000c8.io_fault_4 = 0;
        }
      }
    }
    else if (fault_persistence_counters_t_008000c8.io_fault_4 < _DAT_00807946) {
      fault_persistence_counters_t_008000c8.io_fault_4 =
           fault_persistence_counters_t_008000c8.io_fault_4 + 1;
    }
    else {
      fault_status_registers_t_00805df2.io_fault_status_1 =
           fault_status_registers_t_00805df2.io_fault_status_1 | 0x8000;
      fault_latch_registers_t_00805e32.io_fault_latch_1 =
           fault_latch_registers_t_00805e32.io_fault_latch_1 | 0x8000;
    }
    if (((DAT_0080bdcb & 0x20) != 0) == ((DAT_0080bdef & 0x20) != 0)) {
      if (((fault_status_registers_t_00805df2.io_fault_status_4 & 0x2000) != 0) &&
         ((fault_latch_registers_t_00805e32.io_fault_latch_4 & 0x2000) == 0)) {
        fault_status_registers_t_00805df2.io_fault_status_4 =
             fault_status_registers_t_00805df2.io_fault_status_4 & 0xdfff;
        fault_persistence_counters_t_008000c8.io_fault_5 = 0;
      }
    }
    else if (fault_persistence_counters_t_008000c8.io_fault_5 < _DAT_00807946) {
      fault_persistence_counters_t_008000c8.io_fault_5 =
           fault_persistence_counters_t_008000c8.io_fault_5 + 1;
    }
    else {
      fault_status_registers_t_00805df2.io_fault_status_4 =
           fault_status_registers_t_00805df2.io_fault_status_4 | 0x2000;
      fault_latch_registers_t_00805e32.io_fault_latch_4 =
           fault_latch_registers_t_00805e32.io_fault_latch_4 | 0x2000;
    }
    if (((DAT_0080bdcb & 0x10) != 0) == ((DAT_0080bdef & 0x10) != 0)) {
      if (((fault_status_registers_t_00805df2.io_fault_status_2 & 0x100) != 0) &&
         ((fault_latch_registers_t_00805e32.io_fault_latch_2 & 0x100) == 0)) {
        fault_status_registers_t_00805df2.io_fault_status_2 =
             fault_status_registers_t_00805df2.io_fault_status_2 & 0xfeff;
        fault_persistence_counters_t_008000c8.io_fault_6 = 0;
      }
    }
    else if (fault_persistence_counters_t_008000c8.io_fault_6 < _DAT_00807946) {
      fault_persistence_counters_t_008000c8.io_fault_6 =
           fault_persistence_counters_t_008000c8.io_fault_6 + 1;
    }
    else {
      fault_status_registers_t_00805df2.io_fault_status_2 =
           fault_status_registers_t_00805df2.io_fault_status_2 | 0x100;
      fault_latch_registers_t_00805e32.io_fault_latch_2 =
           fault_latch_registers_t_00805e32.io_fault_latch_2 | 0x100;
    }
    if (((DAT_0080bdcb & 0x40) != 0) == ((DAT_0080bdef & 0x40) != 0)) {
      if (((fault_status_registers_t_00805df2.io_fault_status_3 & 0x4000) != 0) &&
         ((fault_latch_registers_t_00805e32.io_fault_latch_3 & 0x4000) == 0)) {
        fault_status_registers_t_00805df2.io_fault_status_3 =
             fault_status_registers_t_00805df2.io_fault_status_3 & 0xbfff;
        DAT_008000d0 = 0;
      }
    }
    else if (DAT_008000d0 < _DAT_00807946) {
      DAT_008000d0 = DAT_008000d0 + 1;
    }
    else {
      fault_status_registers_t_00805df2.io_fault_status_3 =
           fault_status_registers_t_00805df2.io_fault_status_3 | 0x4000;
      fault_latch_registers_t_00805e32.io_fault_latch_3 =
           fault_latch_registers_t_00805e32.io_fault_latch_3 | 0x4000;
    }
    if (((DAT_0080bdcb & 8) != 0) != ((DAT_0080bdef & 8) != 0)) {
      if (DAT_008000d1 < _DAT_00807946) {
        DAT_008000d1 = DAT_008000d1 + 1;
        return;
      }
      fault_status_registers_t_00805df2.io_fault_status_3 =
           fault_status_registers_t_00805df2.io_fault_status_3 | 0x800;
      fault_latch_registers_t_00805e32.io_fault_latch_3 =
           fault_latch_registers_t_00805e32.io_fault_latch_3 | 0x800;
      return;
    }
    if (((fault_status_registers_t_00805df2.io_fault_status_3 & 0x800) != 0) &&
       ((fault_latch_registers_t_00805e32.io_fault_latch_3 & 0x800) == 0)) {
      fault_status_registers_t_00805df2.io_fault_status_3 =
           fault_status_registers_t_00805df2.io_fault_status_3 & 0xf7ff;
      DAT_008000d1 = 0;
    }
  }
  return;
}



//
// Function: acceleratorThrottleFaultDetector @ 0x0000c8c2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint acceleratorThrottleFaultDetector(void)

{
  undefined2 uVar1;
  uint in_D0;
  uint uVar2;
  
  if (engine_operating_mode_t_0080c810.state == 3) {
    if (((fault_status_registers_t_00805df2.fault_status_2 & 0x400) == 0) ||
       ((_DAT_008068c6 & 0x400) == 0)) {
      in_D0 = 0;
    }
    else {
      in_D0 = 1;
    }
    if (in_D0 == 0) {
      if (((fault_status_registers_t_00805df2.fault_status_2 & 0x200) == 0) ||
         ((_DAT_008068c6 & 0x200) == 0)) {
        in_D0 = 0;
      }
      else {
        in_D0 = 1;
      }
      if ((in_D0 == 0) &&
         (in_D0 = (uint)BSTATBZA + (uint)_DAT_0080d092,
         circular_buffer_t_0080c3fc.current_engine_rpm <= in_D0)) {
        uVar1 = (undefined2)(in_D0 >> 0x10);
        in_D0 = CONCAT22(uVar1,_DAT_0080d0c6);
        if (_DAT_0080d0c6 <= _DAT_0080794c) {
          if (_DAT_008000d2 < _DAT_00807948) {
            _DAT_008000d2 = _DAT_008000d2 + 1;
          }
          if (_DAT_008000d2 == _DAT_00807948) {
            if (_DAT_00807950 < _DAT_00809258) {
              if (_DAT_008000d4 < _DAT_0080794a) {
                _DAT_008000d4 = _DAT_008000d4 + 1;
              }
            }
            else if (_DAT_008000d4 != 0) {
              _DAT_008000d4 = _DAT_008000d4 - 1;
            }
          }
          if (_DAT_008000d4 == _DAT_0080794a) {
            fault_status_registers_t_00805df2.fault_status_2 =
                 fault_status_registers_t_00805df2.fault_status_2 | 0x2000;
            fault_latch_registers_t_00805e32.fault_status_8_previous =
                 fault_latch_registers_t_00805e32.fault_status_8_previous | 0x2000;
          }
          if (_DAT_008000d4 != 0) {
            return CONCAT22(uVar1,_DAT_008000d4);
          }
          if ((fault_status_registers_t_00805df2.fault_status_2 & 0x2000) == 0) {
            return CONCAT22(uVar1,fault_status_registers_t_00805df2.fault_status_2) & 0xffff2000;
          }
          uVar2 = CONCAT22(uVar1,fault_latch_registers_t_00805e32.fault_status_8_previous) &
                  0xffff2000;
          if ((fault_latch_registers_t_00805e32.fault_status_8_previous & 0x2000) != 0) {
            return uVar2;
          }
          fault_status_registers_t_00805df2.fault_status_2 =
               fault_status_registers_t_00805df2.fault_status_2 & 0xdfff;
          return uVar2;
        }
      }
    }
  }
  _DAT_008000d4 = 0;
  _DAT_008000d2 = 0;
  return in_D0;
}



//
// Function: insiteParameterTableIterator @ 0x0000c9f0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void insiteParameterTableIterator(void)

{
  short sVar1;
  byte bVar2;
  byte bVar3;
  
  _DAT_0080d440 = &DAT_00808962;
  _DAT_0080d41c = &DAT_0080d422;
  insite_session_t_0080d407._9_4_ = _DAT_0080d2b4;
  insite_session_t_0080d407._5_4_ = _DAT_0080d2b4;
  insite_session_t_0080d407.response_ptr._0_1_ = 0;
  insite_session_t_0080d407.param_result = 0;
  insite_session_t_0080d407.command_byte = DAT_00808962;
  for (bVar2 = 0; (insite_session_t_0080d407.command_byte != 0 && (bVar2 < 0x1e)); bVar2 = bVar2 + 1
      ) {
    if (DAT_0080d420 == *_DAT_0080d41c) {
      *_DAT_0080d41c = _DAT_0080d440[1] + *_DAT_0080d41c;
      bVar3 = '\x01' << (insite_session_t_0080d407.command_byte & 7);
      sVar1 = (short)((int)(uint)insite_session_t_0080d407.command_byte >> 3);
      if (((bVar3 & *(byte *)(sVar1 + 0x8089be)) != 0) &&
         ((bVar3 & *(byte *)(sVar1 + 0x8055fe)) == 0)) {
        insiteParameterResponseBuilder();
      }
    }
    _DAT_0080d440 = _DAT_0080d440 + 3;
    insite_session_t_0080d407.command_byte = *_DAT_0080d440;
    _DAT_0080d41c = _DAT_0080d41c + 1;
  }
  responseBufferFinalize();
  return;
}



//
// Function: diagnosticMessageTransmissionManager @ 0x0000caa8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint diagnosticMessageTransmissionManager(void)

{
  byte bVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined2 extraout_D0u;
  undefined4 in_D0;
  uint uVar4;
  
  uVar3 = (undefined2)((uint)in_D0 >> 0x10);
  if (((_DAT_008035ea & 4) != 0) && ((_DAT_00809d3e & 2) != 0)) {
    diagnosticMessage45Builder();
    bVar1 = DAT_008000d6 + 1;
    bVar2 = DAT_008000d6 & 1;
    uVar3 = 0;
    DAT_008000d6 = bVar1;
    if (bVar2 == 0) {
      diagnosticMessage53Builder();
      uVar3 = extraout_D0u;
    }
  }
  uVar4 = CONCAT22(uVar3,_DAT_008035ea) & 0xffff0002;
  if ((_DAT_008035ea & 2) != 0) {
    DAT_008000d7 = DAT_008000d7 + 1;
    uVar4 = DAT_008000d7 & 1;
    if (((DAT_008000d7 & 1) == 0) && (uVar4 = _DAT_00809d3e & 1, (_DAT_00809d3e & 1) != 0)) {
      uVar4 = insiteParameterTableIterator();
      DAT_0080d420 = DAT_0080d420 + '\x01';
    }
  }
  return uVar4;
}



//
// Function: insiteParameterResponseBuilder @ 0x0000cb1e
//

void insiteParameterResponseBuilder(void)

{
  undefined2 uVar1;
  
  if (insite_session_t_0080d407.param_result == 0) {
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    *(undefined1 *)insite_session_t_0080d407._5_4_ = 0x80;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    insite_session_t_0080d407.param_result = 1;
    responseBufferSpaceCheck();
    if (DAT_0080d419 == 0) {
      fault_status_registers_t_00805df2.io_fault_status_4 =
           fault_status_registers_t_00805df2.io_fault_status_4 | 4;
      fault_latch_registers_t_00805e32.io_fault_latch_4 =
           fault_latch_registers_t_00805e32.io_fault_latch_4 | 4;
      return;
    }
  }
  uVar1 = parameterLookupForInsite();
  DAT_0080d41a = (byte)uVar1;
  if (DAT_0080d41a == 0) {
    return;
  }
  if (DAT_0080d41a <= DAT_0080d419) {
    insiteCommandByteDispatcher();
    return;
  }
  if (1 < insite_session_t_0080d407.param_result) {
    responseBufferFinalize();
    insite_session_t_0080d407._9_4_ = insite_session_t_0080d407._5_4_;
    responseBufferSpaceCheck();
    if (DAT_0080d419 < 4) {
      DAT_0080d419 = 0;
      insite_session_t_0080d407.param_result = 0;
      fault_status_registers_t_00805df2.io_fault_status_4 =
           fault_status_registers_t_00805df2.io_fault_status_4 | 4;
      fault_latch_registers_t_00805e32.io_fault_latch_4 =
           fault_latch_registers_t_00805e32.io_fault_latch_4 | 4;
      return;
    }
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    *(undefined1 *)insite_session_t_0080d407._5_4_ = 0x80;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    insite_session_t_0080d407.param_result = 1;
  }
  if ((DAT_0080d41a < 0x14) && (DAT_0080d419 < DAT_0080d41a)) {
    fault_status_registers_t_00805df2.io_fault_status_4 =
         fault_status_registers_t_00805df2.io_fault_status_4 | 4;
    fault_latch_registers_t_00805e32.io_fault_latch_4 =
         fault_latch_registers_t_00805e32.io_fault_latch_4 | 4;
    return;
  }
  insiteCommandByteDispatcher();
  return;
}



//
// Function: diagnosticCodeTableSearch @ 0x0000cc34
//

uint diagnosticCodeTableSearch(undefined4 param_1)

{
  uint in_D0;
  byte bVar1;
  
  bVar1 = 1;
  while( true ) {
    if (DAT_00804e7c < bVar1) {
      return in_D0 & 0xffffff00;
    }
    in_D0 = 0;
    if ((char)((uint)param_1 >> 0x10) == (&DAT_00804e7c)[(short)(ushort)bVar1]) break;
    bVar1 = bVar1 + 1;
  }
  return 1;
}



//
// Function: insiteCommandByteDispatcher @ 0x0000cc64
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void insiteCommandByteDispatcher(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined4 unaff_D2;
  byte bVar5;
  char cVar6;
  undefined2 uVar7;
  undefined4 local_a;
  undefined2 local_6;
  
  uVar1 = _DAT_00804bd0;
  uVar7 = (undefined2)((uint)unaff_D2 >> 0x10);
  if (insite_session_t_0080d407.command_byte < 0x80) {
    if (insite_session_t_0080d407.command_byte < 0x59) {
      if (insite_session_t_0080d407.command_byte < 0x54) {
        if (insite_session_t_0080d407.command_byte == 2) {
          bVar5 = 0;
          uVar2 = diagnosticCodeTableSearch((uint)CONCAT12(DAT_008063ff,uVar7));
          if ((char)uVar2 == '\0') {
            uVar2 = diagnosticCodeTableSearch
                              (CONCAT22((short)CONCAT31((int3)(uVar2 >> 8),DAT_008063fd),uVar7));
            if ((char)uVar2 == '\0') {
              uVar2 = diagnosticCodeTableSearch
                                (CONCAT22((short)CONCAT31((int3)(uVar2 >> 8),DAT_008063fb),uVar7));
              if ((char)uVar2 != '\0') {
                bVar5 = 0x20;
              }
            }
            else {
              bVar5 = 0x20;
            }
          }
          else {
            bVar5 = 0x20;
          }
          uVar3 = (undefined2)CONCAT31((int3)(uVar2 >> 8),DAT_00806375);
          uVar2 = diagnosticCodeTableSearch(CONCAT22(uVar3,uVar7));
          if ((char)uVar2 != '\0') {
            bVar5 = bVar5 | 0x10;
          }
          uVar4 = (undefined2)CONCAT31((int3)(uVar2 >> 8),DAT_008063b9);
          uVar2 = diagnosticCodeTableSearch(CONCAT22(uVar4,uVar3));
          if ((char)uVar2 != '\0') {
            bVar5 = bVar5 | 8;
          }
          uVar3 = (undefined2)CONCAT31((int3)(uVar2 >> 8),DAT_008063d3);
          uVar2 = diagnosticCodeTableSearch(CONCAT22(uVar3,uVar4));
          if ((char)uVar2 != '\0') {
            bVar5 = bVar5 | 4;
          }
          uVar2 = diagnosticCodeTableSearch
                            (CONCAT22((short)CONCAT31((int3)(uVar2 >> 8),DAT_008063db),uVar3));
          if ((char)uVar2 == '\0') {
            uVar2 = diagnosticCodeTableSearch
                              (CONCAT22((short)CONCAT31((int3)(uVar2 >> 8),DAT_008063e1),uVar7));
            if ((char)uVar2 != '\0') {
              bVar5 = bVar5 | 2;
            }
          }
          else {
            bVar5 = bVar5 | 2;
          }
          uVar2 = diagnosticCodeTableSearch
                            (CONCAT22((short)CONCAT31((int3)(uVar2 >> 8),DAT_008063a7),uVar7));
          if ((char)uVar2 != '\0') {
            bVar5 = bVar5 | 1;
          }
        }
        else if (insite_session_t_0080d407.command_byte == 3) {
          bVar5 = (DAT_0080bdc7 & 0x80) != 0;
          if ((DAT_0080bdc7 & 0x40) != 0) {
            bVar5 = bVar5 | 2;
          }
          if ((DAT_0080bdc7 & 0x20) != 0) {
            bVar5 = bVar5 | 4;
          }
        }
        else if (insite_session_t_0080d407.command_byte == 0x47) {
          bVar5 = 0;
          if ((high_rpm_protection_t_0080cc6a.timer != 0) &&
             (high_rpm_protection_t_0080cc6a.timer < _DAT_008036fc)) {
            bVar5 = 0x80;
          }
          if ((engine_control_flags_t_008035d6.engine_operating_state & 2) != 0) {
            bVar5 = bVar5 | 8;
          }
          if ((high_rpm_protection_t_0080cc6a.fault_flag != 0) &&
             ((engine_control_flags_t_008035d6.engine_operating_state & 4) != 0)) {
            bVar5 = bVar5 | 4;
          }
          if ((_DAT_0080c996 != 0) && (high_rpm_protection_t_0080cc6a.timer == 0)) {
            bVar5 = bVar5 | 2;
          }
          if (high_rpm_protection_t_0080cc6a.warning_flag != 0) {
            bVar5 = bVar5 | 1;
          }
        }
        else if (insite_session_t_0080d407.command_byte == 0x4a) {
          bVar5 = (byte)((int)(uint)_DAT_00803748 >> 7);
        }
        else {
          if (insite_session_t_0080d407.command_byte != 0x53) {
            return;
          }
          if (diagnostic_state_buffer_t_00809654.diagnostic_mode == 10) {
            bVar5 = 0x80;
          }
          else {
            bVar5 = 0;
          }
        }
        *(byte *)insite_session_t_0080d407._5_4_ = insite_session_t_0080d407.command_byte;
        insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
             insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
        *(byte *)insite_session_t_0080d407._5_4_ = bVar5;
        insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
             insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      }
      else {
        switch(insite_session_t_0080d407.command_byte) {
        case 0x54:
          bVar5 = (byte)((int)(uint)_DAT_008096a6 >> 7);
          break;
        case 0x55:
          bVar5 = 0;
          if (_DAT_0080969a != 0) {
            bVar5 = 0x80;
          }
          if ((DAT_0080bdc7 & 4) != 0) {
            bVar5 = bVar5 | 0x40;
          }
          if ((DAT_0080bdc7 & 8) != 0) {
            bVar5 = bVar5 | 0x20;
          }
          if ((DAT_0080bdcc & 2) != 0) {
            bVar5 = bVar5 | 0x10;
          }
          if ((DAT_0080bdcc & 1) != 0) {
            bVar5 = bVar5 | 8;
          }
          if ((DAT_0080bdcc & 8) != 0) {
            bVar5 = bVar5 | 4;
          }
          if ((DAT_0080bdcc & 4) != 0) {
            bVar5 = bVar5 | 2;
          }
          if ((DAT_0080bdcc & 0x10) != 0) {
            bVar5 = bVar5 | 1;
          }
          break;
        case 0x56:
          bVar5 = (byte)((int)(uint)_DAT_0080969c >> 7);
          break;
        case 0x57:
          bVar5 = (byte)((int)(uint)_DAT_00803746 >> 7);
          break;
        case 0x58:
          bVar5 = (byte)((int)(uint)_DAT_00807944 >> 7);
          break;
        default:
          goto switchD_0000ce84_default;
        }
        *(byte *)insite_session_t_0080d407._5_4_ = insite_session_t_0080d407.command_byte;
        insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
             insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
        *(byte *)insite_session_t_0080d407._5_4_ = bVar5;
        insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
             insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      }
    }
    else if (insite_session_t_0080d407.command_byte < 0x69) {
      if (insite_session_t_0080d407.command_byte == 0x59) {
        local_6._1_1_ = 0;
        if (_DAT_0080d17a != 0) {
          local_6._1_1_ = 0x80;
        }
        if ((DAT_0080bdc7 & 4) != 0) {
          local_6._1_1_ = (byte)local_6 | 0x40;
        }
        if ((DAT_0080bdc7 & 8) != 0) {
          local_6._1_1_ = (byte)local_6 | 0x20;
        }
        if ((DAT_0080bdcc & 2) != 0) {
          local_6._1_1_ = (byte)local_6 | 0x10;
        }
        if ((DAT_0080bdcc & 1) != 0) {
          local_6._1_1_ = (byte)local_6 | 8;
        }
        if ((DAT_0080bdcc & 8) != 0) {
          local_6._1_1_ = (byte)local_6 | 4;
        }
        if ((DAT_0080bdcc & 4) != 0) {
          local_6._1_1_ = (byte)local_6 | 2;
        }
        if ((DAT_0080bdcc & 0x10) != 0) {
          local_6._1_1_ = (byte)local_6 | 1;
        }
      }
      else if (insite_session_t_0080d407.command_byte == 0x5b) {
        local_6._1_1_ = (byte)(((uint)_DAT_00809d4c * 0xfa) / 400);
      }
      else if (insite_session_t_0080d407.command_byte == 0x5c) {
        local_6._1_1_ = (byte)((int)(uint)_DAT_0080d0c6 >> 7);
      }
      else if (insite_session_t_0080d407.command_byte == 100) {
        local_6._1_1_ = (byte)((int)(uint)_DAT_00809242 >> 6);
      }
      else {
        if (insite_session_t_0080d407.command_byte != 0x66) {
          return;
        }
        if ((ushort)((int)(uint)_DAT_00809258 >> 4) < 0xff) {
          local_6._1_1_ = (byte)((int)(uint)_DAT_00809258 >> 4);
        }
        else {
          local_6._1_1_ = 0xff;
        }
      }
      *(byte *)insite_session_t_0080d407._5_4_ = insite_session_t_0080d407.command_byte;
      insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
           insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      *(byte *)insite_session_t_0080d407._5_4_ = (byte)local_6;
      insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
           insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    }
    else {
      if (insite_session_t_0080d407.command_byte == 0x69) {
        if (_DAT_008091ea < 0x1900) {
          cVar6 = '\0';
        }
        else {
          cVar6 = (char)((int)(_DAT_008091ea - 0x1900) >> 7);
        }
      }
      else if (insite_session_t_0080d407.command_byte == 0x6c) {
        cVar6 = (char)((int)(uint)_DAT_008092f2 >> 3);
      }
      else if (insite_session_t_0080d407.command_byte == 0x6e) {
        if (_DAT_0080926e < 0x1900) {
          cVar6 = '\0';
        }
        else {
          cVar6 = (char)((int)(_DAT_0080926e - 0x1900) >> 7);
        }
      }
      else {
        if (insite_session_t_0080d407.command_byte != 0x79) {
          return;
        }
        if (_DAT_008037d4 == 0) {
          cVar6 = '\0';
        }
        else {
          cVar6 = (DAT_0080bdef & 1) != 0;
          if ((DAT_0080bdf1 & 1) != 0) {
            cVar6 = cVar6 + '\x02';
          }
          if (_DAT_008037d4 == 1) {
            switch(cVar6) {
            case '\0':
              cVar6 = '\0';
              break;
            case '\x01':
              cVar6 = -0x7f;
              break;
            case '\x02':
              cVar6 = -0x7c;
              break;
            case '\x03':
              cVar6 = -0x78;
            }
          }
          else {
            switch(cVar6) {
            case '\0':
              cVar6 = '\0';
              break;
            case '\x01':
            case '\x02':
              cVar6 = -0x7e;
              break;
            case '\x03':
              cVar6 = -0x78;
            }
          }
        }
      }
      *(byte *)insite_session_t_0080d407._5_4_ = insite_session_t_0080d407.command_byte;
      insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
           insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      *(char *)insite_session_t_0080d407._5_4_ = cVar6;
      insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
           insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    }
  }
  else if (insite_session_t_0080d407.command_byte < 0xc1) {
    if (insite_session_t_0080d407.command_byte < 0xb9) {
      if ((insite_session_t_0080d407.command_byte != 0x9c) &&
         (insite_session_t_0080d407.command_byte != 0x9d)) {
        if (insite_session_t_0080d407.command_byte == 0xa6) {
          local_6 = CONCAT11(DAT_00004446,DAT_00004445);
        }
        else if (insite_session_t_0080d407.command_byte == 0xa8) {
          local_6 = (short)((int)(uint)_DAT_00809308 >> 1) + _DAT_00809308 * 2;
        }
        else if (insite_session_t_0080d407.command_byte != 0xaf) {
          if (insite_session_t_0080d407.command_byte == 0xb6) {
            local_6 = (short)_DAT_00804bbc;
          }
          else if (insite_session_t_0080d407.command_byte == 0xb7) {
            local_6 = _DAT_0080d476;
          }
          else {
            if (insite_session_t_0080d407.command_byte != 0xb8) {
              return;
            }
            local_6 = _DAT_00804bc8;
          }
        }
      }
      *(byte *)insite_session_t_0080d407._5_4_ = insite_session_t_0080d407.command_byte;
      insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
           insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      *(byte *)insite_session_t_0080d407._5_4_ = (byte)local_6;
      insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
           insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      *(undefined1 *)insite_session_t_0080d407._5_4_ = local_6._0_1_;
      insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
           insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    }
    else {
      switch(insite_session_t_0080d407.command_byte) {
      case 0xb9:
        local_6 = _DAT_00804bca;
        break;
      default:
        goto switchD_0000ce84_default;
      case 0xbb:
        local_6 = (short)((int)(uint)_DAT_0080d178 >> 1);
        break;
      case 0xbc:
        local_6 = (short)((int)(uint)_DAT_0080d092 >> 1);
        break;
      case 0xbd:
        local_6 = (short)((int)(uint)_DAT_00807d5e >> 1);
        break;
      case 0xbe:
        local_6 = (short)((int)(uint)circular_buffer_t_0080c3fc.current_engine_rpm >> 1);
      }
      *(byte *)insite_session_t_0080d407._5_4_ = insite_session_t_0080d407.command_byte;
      insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
           insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      *(byte *)insite_session_t_0080d407._5_4_ = (byte)local_6;
      insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
           insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      *(undefined1 *)insite_session_t_0080d407._5_4_ = local_6._0_1_;
      insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
           insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    }
  }
  else if (insite_session_t_0080d407.command_byte < 0xf4) {
    if (insite_session_t_0080d407.command_byte == 0xc1) {
      insiteActiveFaultListBuilder();
      return;
    }
    if (insite_session_t_0080d407.command_byte == 0xc2) {
      insiteFaultDetailBuilder();
      return;
    }
    if (insite_session_t_0080d407.command_byte == 0xc4) {
      *(undefined1 *)insite_session_t_0080d407._5_4_ = 0xc4;
      insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
           insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      if (((DAT_0080d448 & 0xc0) == 0x80) || ((DAT_0080d448 & 0xc0) == 0x40)) {
        *(undefined1 *)insite_session_t_0080d407._5_4_ = 2;
        insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
             insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      }
      else if ((DAT_0080d448 & 0xc0) == 0) {
        if (_DAT_0080d490 == 0) {
          *(undefined1 *)insite_session_t_0080d407._5_4_ = 0;
          insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
               insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
          goto LAB_0000d55a;
        }
        *(undefined1 *)insite_session_t_0080d407._5_4_ = 5;
        insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
             insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      }
      *(undefined1 *)insite_session_t_0080d407._5_4_ = DAT_0080d447;
      insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
           insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      *(byte *)insite_session_t_0080d407._5_4_ = DAT_0080d448;
      insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
           insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      if (((DAT_0080d448 & 0xc0) == 0) && (_DAT_0080d490 != 0)) {
        bVar5 = 1;
        do {
          *(char *)insite_session_t_0080d407._5_4_ = (char)(_DAT_0080d490 / 100) + '0';
          _DAT_0080d490 = (_DAT_0080d490 % 100) * 10;
          insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
               insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
          bVar5 = bVar5 + 1;
        } while (bVar5 < 4);
      }
    }
    else {
      if (insite_session_t_0080d407.command_byte == 0xea) {
        insiteEcuIdResponseBuilder();
        return;
      }
      if (insite_session_t_0080d407.command_byte == 0xeb) {
        uVar2 = _DAT_00804bcc / 0x708;
        *(undefined1 *)insite_session_t_0080d407._5_4_ = 0xeb;
        insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
             insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
        *(undefined1 *)insite_session_t_0080d407._5_4_ = 4;
        insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
             insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
        local_a._3_1_ = (undefined1)uVar2;
        *(undefined1 *)insite_session_t_0080d407._5_4_ = (undefined1)local_a;
        insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
             insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
        local_a._2_1_ = (undefined1)(uVar2 >> 8);
        *(undefined1 *)insite_session_t_0080d407._5_4_ = local_a._2_1_;
        insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
             insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
        local_a._1_1_ = (undefined1)(uVar2 >> 0x10);
        *(undefined1 *)insite_session_t_0080d407._5_4_ = local_a._1_1_;
        insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
             insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
        *(undefined1 *)insite_session_t_0080d407._5_4_ = 0;
        insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
             insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      }
      else {
        if (insite_session_t_0080d407.command_byte != 0xec) {
          if (insite_session_t_0080d407.command_byte == 0xed) {
            insiteCapacityResponseBuilder();
            return;
          }
          if (insite_session_t_0080d407.command_byte != 0xf3) {
            return;
          }
          insiteVersionInfoBuilder();
          return;
        }
        *(undefined1 *)insite_session_t_0080d407._5_4_ = 0xec;
        insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
             insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
        *(undefined1 *)insite_session_t_0080d407._5_4_ = 4;
        insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
             insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
        local_a._3_1_ = (undefined1)uVar1;
        *(undefined1 *)insite_session_t_0080d407._5_4_ = (undefined1)local_a;
        insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
             insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
        local_a._2_1_ = (undefined1)((uint)uVar1 >> 8);
        *(undefined1 *)insite_session_t_0080d407._5_4_ = local_a._2_1_;
        insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
             insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
        local_a._1_1_ = (undefined1)((uint)uVar1 >> 0x10);
        *(undefined1 *)insite_session_t_0080d407._5_4_ = local_a._1_1_;
        insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
             insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
        local_a._0_1_ = (undefined1)((uint)uVar1 >> 0x18);
        *(undefined1 *)insite_session_t_0080d407._5_4_ = local_a._0_1_;
        insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
             insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      }
    }
  }
  else {
    switch(insite_session_t_0080d407.command_byte) {
    case 0xf4:
      local_a = proportionalCalculation(_DAT_00804bc4,10,0x40);
      break;
    case 0xf5:
      local_a = proportionalCalculation(_DAT_00804bc0,10,0x40);
      break;
    default:
      goto switchD_0000ce84_default;
    case 0xf7:
      local_a = _DAT_00804bd8 / 0x708;
      break;
    case 0xf8:
      local_a = _DAT_00804bd4 / 0x708;
      break;
    case 0xfa:
      local_a = _DAT_00804bb8;
    }
    *(byte *)insite_session_t_0080d407._5_4_ = insite_session_t_0080d407.command_byte;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    *(undefined1 *)insite_session_t_0080d407._5_4_ = 4;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    *(undefined1 *)insite_session_t_0080d407._5_4_ = (undefined1)local_a;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    *(undefined1 *)insite_session_t_0080d407._5_4_ = local_a._2_1_;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    *(undefined1 *)insite_session_t_0080d407._5_4_ = local_a._1_1_;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    *(undefined1 *)insite_session_t_0080d407._5_4_ = local_a._0_1_;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
  }
LAB_0000d55a:
  insite_session_t_0080d407.param_result = DAT_0080d41a + insite_session_t_0080d407.param_result;
  DAT_0080d419 = DAT_0080d419 - DAT_0080d41a;
switchD_0000ce84_default:
  return;
}



//
// Function: paramSystemModeController @ 0x0000d57c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void paramSystemModeController(void)

{
  uint uVar1;
  undefined4 unaff_D2;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((uint)unaff_D2 >> 0x10);
  if ((diagnostic_state_buffer_t_00809654.diagnostic_mode == 2) ||
     (diagnostic_state_buffer_t_00809654.diagnostic_mode == 1)) {
    _DAT_0080cff6 = activeParamReadFunction();
  }
  else if ((diagnostic_state_buffer_t_00809654.diagnostic_mode == 0xb) ||
          (diagnostic_state_buffer_t_00809654.diagnostic_mode == 0xc)) {
    if (_DAT_0080d49c == 8) {
      _DAT_0080cff6 = _DAT_0080d49a;
    }
    else {
      _DAT_0080cff6 = activeParamReadFunction();
    }
  }
  else {
    _DAT_0080cff6 = _DAT_00809652;
  }
  if ((short)(_DAT_008086c2 - reference_table_t_008086f6.base_reference) < 1) {
    _DAT_0080cfd8 = 0;
    return;
  }
  if ((short)(_DAT_0080cff6 - reference_table_t_008086f6.base_reference) < 1) {
    _DAT_0080cfd8 = 0;
    return;
  }
  uVar1 = param_address_calc((short)(_DAT_0080cff6 - reference_table_t_008086f6.base_reference) *
                             0x6400,CONCAT22(_DAT_008086c2 -
                                             reference_table_t_008086f6.base_reference,uVar2));
  _DAT_0080cfd8 = (ushort)uVar1;
  if (32000 < _DAT_0080cfd8) {
    _DAT_0080cfd8 = 32000;
  }
  return;
}



//
// Function: param_lookup_1 @ 0x0000d632
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void param_lookup_1(void)

{
  uint uVar1;
  undefined4 unaff_D2;
  
  if ((short)(_DAT_008086c2 - reference_table_t_008086f6.base_reference) < 1) {
    _DAT_0080cfd6 = 0;
    return;
  }
  if ((short)(fuel_demand_state_t_0080c9a4.command - reference_table_t_008086f6.base_reference) < 1)
  {
    _DAT_0080cfd6 = 0;
    return;
  }
  uVar1 = param_address_calc((short)(fuel_demand_state_t_0080c9a4.command -
                                    reference_table_t_008086f6.base_reference) * 0x6400,
                             CONCAT22(_DAT_008086c2 - reference_table_t_008086f6.base_reference,
                                      (short)((uint)unaff_D2 >> 0x10)));
  _DAT_0080cfd6 = (ushort)uVar1;
  if (32000 < _DAT_0080cfd6) {
    _DAT_0080cfd6 = 32000;
  }
  return;
}



//
// Function: param_lookup_2 @ 0x0000d69c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void param_lookup_2(void)

{
  short sVar1;
  uint uVar2;
  undefined4 unaff_D2;
  uint uVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  
  uVar5 = (undefined2)((uint)unaff_D2 >> 0x10);
  uVar3 = (uint)fuel_demand_state_t_0080c9a4.command;
  uVar2 = (uint)reference_table_t_008086f6.base_reference;
  if ((int)(uVar3 - uVar2) < 1) {
    _DAT_0080cfda = 0;
    return;
  }
  _DAT_008000de = circular_buffer_t_0080c3fc.data_buffer_8;
  uVar4 = tableInterpolationLookup((short *)&DAT_008000d8);
  sVar1 = (short)((ulonglong)uVar4 >> 0x20) - reference_table_t_008086f6.base_reference;
  if (sVar1 < 1) {
    _DAT_0080cfda = 0;
    return;
  }
  uVar2 = param_address_calc((uVar3 - uVar2) * 0x6400,CONCAT22(sVar1,uVar5));
  _DAT_0080cfda = (ushort)uVar2;
  if (32000 < _DAT_0080cfda) {
    _DAT_0080cfda = 32000;
  }
  return;
}



//
// Function: diagnosticDataBufferSetup @ 0x0000d71a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticDataBufferSetup(void)

{
  _DAT_008000de = circular_buffer_t_0080c3fc.data_buffer_8;
  _DAT_008000d8 = 2;
  _DAT_008000da = 0x807f42;
  _DAT_008000e6 = 400;
  _DAT_008000e0 = 2;
  _DAT_008000e2 = 0x807f68;
  _DAT_008000e8 = 0x807f72;
  return;
}



//
// Function: param_lookup_3 @ 0x0000d756
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void param_lookup_3(void)

{
  uint uVar1;
  undefined4 unaff_D2;
  
  if ((int)((uint)_DAT_0080d0aa - (uint)reference_table_t_008086f6.base_reference) < 1) {
    _DAT_0080cfdc = 0;
    return;
  }
  if ((short)(_DAT_008086c2 - reference_table_t_008086f6.base_reference) < 1) {
    _DAT_0080cfdc = 0;
    return;
  }
  uVar1 = param_address_calc(((uint)_DAT_0080d0aa - (uint)reference_table_t_008086f6.base_reference)
                             * 0x6400,CONCAT22(_DAT_008086c2 -
                                               reference_table_t_008086f6.base_reference,
                                               (short)((uint)unaff_D2 >> 0x10)));
  _DAT_0080cfdc = (ushort)uVar1;
  if (32000 < _DAT_0080cfdc) {
    _DAT_0080cfdc = 32000;
  }
  return;
}



//
// Function: fuelTableBlendInterpolation @ 0x0000d7c0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short fuelTableBlendInterpolation(undefined4 param_1)

{
  ushort unaff_D2w;
  ushort unaff_D3w;
  undefined8 uVar1;
  
  if (fuel_demand_state_t_0080c9a4.timing_blend_factor != 0) {
    _DAT_008000f2 = param_1._0_2_;
    uVar1 = tableInterpolationLookup((short *)&DAT_008000ec);
    unaff_D2w = (ushort)((ulonglong)uVar1 >> 0x20);
  }
  if (fuel_demand_state_t_0080c9a4.timing_blend_factor < 0x4000) {
    _DAT_00800106 = param_1._0_2_;
    uVar1 = tableInterpolationLookup((short *)&DAT_00800100);
    unaff_D3w = (ushort)((ulonglong)uVar1 >> 0x20);
  }
  if (fuel_demand_state_t_0080c9a4.timing_blend_factor == 0x4000) {
    return _DAT_008037ae + unaff_D2w;
  }
  if (fuel_demand_state_t_0080c9a4.timing_blend_factor == 0) {
    return _DAT_008037ae + unaff_D3w;
  }
  return _DAT_008037ae +
         (short)((uint)fuel_demand_state_t_0080c9a4.timing_blend_factor * (uint)unaff_D2w >> 0xe) +
         (short)((uint)unaff_D3w * (0x4000 - (uint)fuel_demand_state_t_0080c9a4.timing_blend_factor)
                >> 0xe);
}



//
// Function: fuelParameterBlendCalculator @ 0x0000d85e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelParameterBlendCalculator(void)

{
  undefined4 unaff_A2;
  undefined2 uVar1;
  undefined2 uVar2;
  
  uVar2 = _DAT_0080d092;
  _DAT_0080cfec =
       fuelTableBlendInterpolation(CONCAT22(_DAT_0080d092,(short)((uint)unaff_A2 >> 0x10)));
  uVar1 = _DAT_0080cfe8;
  _DAT_0080cfee = fuelTableBlendInterpolation(CONCAT22(_DAT_0080cfe8,uVar2));
  uVar2 = _DAT_008086c6;
  _DAT_0080cff0 = fuelTableBlendInterpolation(CONCAT22(_DAT_008086c6,uVar1));
  uVar1 = _DAT_008086c8;
  _DAT_0080cff2 = fuelTableBlendInterpolation(CONCAT22(_DAT_008086c8,uVar2));
  _DAT_0080cff4 = fuelTableBlendInterpolation(CONCAT22(_DAT_0080cfea,uVar1));
  return;
}



//
// Function: param_interpolate @ 0x0000d8b4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort param_interpolate(undefined4 param_1)

{
  ushort uVar1;
  
  if ((short)(param_1._0_2_ - reference_table_t_008086f6.base_reference) < 1) {
    uVar1 = 0;
  }
  else if ((short)(_DAT_008086c2 - reference_table_t_008086f6.base_reference) < 1) {
    uVar1 = 0;
  }
  else {
    uVar1 = (ushort)((uint)((short)(param_1._0_2_ - reference_table_t_008086f6.base_reference) *
                           0x6400) /
                    (uint)(int)(short)(_DAT_008086c2 - reference_table_t_008086f6.base_reference));
    if (32000 < uVar1) {
      uVar1 = 32000;
    }
  }
  return uVar1;
}



//
// Function: fuelOffsetCalculator @ 0x0000d90a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelOffsetCalculator(uint param_1,undefined4 param_2)

{
  if ((fuel_limit_arbitration_t_0080cc4a.comparison_low != 0) &&
     (fuel_limit_arbitration_t_0080cc4a.comparison_high != 0)) {
    _DAT_0080cfe8 =
         fuel_limit_arbitration_t_0080cc4a.arbitration_threshold +
         ((short)(((uint)fuel_limit_arbitration_t_0080cc4a.comparison_high *
                  ((uint)fuel_limit_arbitration_t_0080cc4a.comparison_low - (param_1 & 0xffff))) /
                 0x1111) - fuel_limit_arbitration_t_0080cc4a.offset_value);
    if (param_2._1_1_ == '\x01') {
      _DAT_0080cfea = _DAT_0080cfe8;
      return;
    }
    _DAT_0080cfea = _DAT_008086ca;
    return;
  }
  _DAT_0080cfe8 = fuel_limit_arbitration_t_0080cc4a.arbitration_threshold;
  _DAT_0080cfea = param_1._0_2_;
  return;
}



//
// Function: fuelModeSelectionCalculator @ 0x0000d984
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelModeSelectionCalculator(void)

{
  undefined4 unaff_D2;
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  
  uVar4 = (ushort)((uint)unaff_D2 >> 0x10);
  if ((((fuel_limit_arbitration_t_0080cc4a.source_id == 2) ||
       (fuel_limit_arbitration_t_0080cc4a.source_id == 4)) ||
      (fuel_limit_arbitration_t_0080cc4a.source_id == 5)) ||
     (fuel_limit_arbitration_t_0080cc4a.source_id == 1)) {
    cVar1 = '\x02';
  }
  else {
    cVar1 = '\0';
  }
  if (((_DAT_0080d496 == 0x12) || (_DAT_0080d496 == 0xf)) ||
     ((_DAT_0080d496 == 0x10 &&
      ((((fault_status_registers_t_00805df2.fault_status_2 & 0x200) != 0 &&
        ((_DAT_008068c6 & 0x200) != 0)) ||
       (((fault_status_registers_t_00805df2.fault_status_2 & 0x400) != 0 &&
        ((_DAT_008068c6 & 0x400) != 0)))))))) {
    cVar1 = cVar1 + '\x04';
    _DAT_0080cfec = _DAT_008086cc;
    _DAT_0080cff0 = _DAT_008086ce;
    _DAT_0080cff2 = _DAT_008086d0;
  }
  if (fuel_demand_state_t_0080c9a4.timing_blend_factor == 0x4000) {
    cVar1 = cVar1 + '\x01';
  }
  switch(cVar1) {
  case '\0':
  case '\x01':
    _DAT_0080cfe8 = fuel_limit_arbitration_t_0080cc4a.offset_value;
    _DAT_0080cfea = _DAT_008086ca;
    fuelParameterBlendCalculator();
    break;
  case '\x02':
  case '\x03':
    _DAT_0080cfe8 = fuel_limit_arbitration_t_0080cc4a.arbitration_threshold;
    if (_DAT_008086ca < fuel_limit_arbitration_t_0080cc4a.arbitration_threshold) {
      _DAT_0080cfea = _DAT_008086ca;
    }
    else {
      _DAT_0080cfea = fuel_limit_arbitration_t_0080cc4a.arbitration_threshold;
    }
    fuelParameterBlendCalculator();
    break;
  case '\x04':
    _DAT_0080cfe8 = _DAT_008086d4;
    _DAT_0080cfea = _DAT_008086ca;
    _DAT_0080cfee = _DAT_008086d6;
    _DAT_0080cff4 = _DAT_008086d2;
    break;
  case '\x05':
    _DAT_0080cfe8 = _DAT_008086da;
    _DAT_0080cfea = _DAT_008086ca;
    _DAT_0080cfee = _DAT_008086dc;
    _DAT_0080cff4 = _DAT_008086d2;
    break;
  case '\x06':
    if (fuel_limit_arbitration_t_0080cc4a.arbitration_threshold < _DAT_008086d8) {
      fuelOffsetCalculator
                (CONCAT22(fuel_limit_arbitration_t_0080cc4a.arbitration_threshold,_DAT_008086d0),
                 CONCAT22(1,uVar4));
      _DAT_0080cfee = _DAT_008086d0;
      _DAT_0080cff4 = _DAT_008086d0;
    }
    else {
      fuelOffsetCalculator(CONCAT22(_DAT_008086ca,_DAT_008086d2),(uint)uVar4);
      _DAT_0080cfee = _DAT_008086d2;
      _DAT_0080cff4 = _DAT_008086d2;
    }
    break;
  case '\a':
    if (fuel_limit_arbitration_t_0080cc4a.arbitration_threshold < _DAT_008086de) {
      fuelOffsetCalculator
                (CONCAT22(fuel_limit_arbitration_t_0080cc4a.arbitration_threshold,_DAT_008086d0),
                 CONCAT22(1,uVar4));
      _DAT_0080cfee = _DAT_008086d0;
      _DAT_0080cff4 = _DAT_008086d0;
    }
    else {
      fuelOffsetCalculator(CONCAT22(_DAT_008086ca,_DAT_008086d2),(uint)uVar4);
      _DAT_0080cfee = _DAT_008086d2;
      _DAT_0080cff4 = _DAT_008086d2;
    }
  }
  uVar3 = _DAT_0080cfec;
  _DAT_0080cfde = param_interpolate(CONCAT22(_DAT_0080cfec,uVar4));
  uVar2 = _DAT_0080cfee;
  _DAT_0080cfe0 = param_interpolate(CONCAT22(_DAT_0080cfee,uVar3));
  uVar3 = _DAT_0080cff0;
  _DAT_0080cfe2 = param_interpolate(CONCAT22(_DAT_0080cff0,uVar2));
  uVar2 = _DAT_0080cff2;
  _DAT_0080cfe4 = param_interpolate(CONCAT22(_DAT_0080cff2,uVar3));
  _DAT_0080cfe6 = param_interpolate(CONCAT22(_DAT_0080cff4,uVar2));
  return;
}



//
// Function: fuelBlendTablePointerSetup @ 0x0000dbc2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelBlendTablePointerSetup(void)

{
  _DAT_008000ec = 2;
  _DAT_008000ee = 0x807f42;
  _DAT_008000fa = 400;
  _DAT_008000f4 = 2;
  _DAT_008000f6 = 0x807f68;
  _DAT_008000fc = 0x807f72;
  _DAT_00800100 = 2;
  _DAT_00800102 = 0x808002;
  _DAT_0080010e = 400;
  _DAT_00800108 = 2;
  _DAT_0080010a = 0x808028;
  _DAT_00800110 = 0x808032;
  return;
}



//
// Function: ioControlBasedFuelCalculator @ 0x0000dc28
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ioControlBasedFuelCalculator(void)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  
  if ((DAT_0080bdef & 1) == 0) {
    sVar1 = 2;
  }
  else {
    sVar1 = 0;
  }
  if ((DAT_0080bdf1 & 1) == 0) {
    uVar3 = sVar1 + 2;
  }
  else {
    uVar3 = sVar1 + 1;
  }
  if (uVar3 < 2) {
    _DAT_00809d40 = 0;
    return;
  }
  if (_DAT_008037d4 == 2) {
    _DAT_00800116 = 0x80797a;
    _DAT_00800122 = 0x80797a;
    _DAT_00800128 = 0x80798e;
    if (uVar3 == 2) {
      _DAT_0080011c = 0x807984;
    }
    else if (uVar3 == 3) {
      _DAT_0080011c = 0x807984;
    }
    else if (uVar3 == 4) {
      _DAT_0080011c = 0x80798e;
    }
  }
  else {
    _DAT_00800116 = 0x807952;
    _DAT_00800122 = 0x807952;
    _DAT_00800128 = 0x807970;
    if (uVar3 == 2) {
      _DAT_0080011c = 0x807966;
    }
    else if (uVar3 == 3) {
      _DAT_0080011c = 0x80795c;
    }
    else if (uVar3 == 4) {
      _DAT_0080011c = 0x807970;
    }
  }
  _DAT_0080011a = circular_buffer_t_0080c3fc.data_buffer_8;
  sVar1 = lookupTableInterpolation((short *)&DAT_00800114);
  if (0 < sVar1) {
    _DAT_00800126 = *(undefined2 *)(_DAT_00800122 + 8);
    sVar2 = lookupTableInterpolation((short *)&DAT_00800120);
    if (0 < sVar2) {
      _DAT_00809d40 = (ushort)((uint)(sVar1 * 0x6400) / (uint)(int)sVar2);
      if (32000 < _DAT_00809d40) {
        _DAT_00809d40 = 32000;
      }
      return;
    }
    _DAT_00809d40 = 0;
    return;
  }
  _DAT_00809d40 = 0;
  return;
}



//
// Function: throttleTablePointerSetup @ 0x0000dd72
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void throttleTablePointerSetup(void)

{
  _DAT_00800114 = 2;
  _DAT_00800116 = 0x807952;
  _DAT_0080011c = 0x807970;
  _DAT_00800120 = 2;
  _DAT_00800122 = 0x807952;
  _DAT_00800128 = 0x807970;
  return;
}



//
// Function: bufferDecreasingPatternCheck @ 0x0000ddb4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint bufferDecreasingPatternCheck(void)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint local_18 [5];
  
  uVar1 = 0;
  puVar3 = _DAT_00800138;
  for (puVar2 = local_18; puVar2 < &stack0xfffffffc; puVar2 = puVar2 + 1) {
    if (puVar2 == local_18) {
      *puVar2 = _DAT_00800134 >> 2;
    }
    else {
      *puVar2 = *puVar3 >> 2;
      puVar3 = puVar3 + -1;
    }
    if (puVar3 < _DAT_0080013c) {
      puVar3 = _DAT_00800140;
    }
    uVar1 = *puVar3 >> 2;
    *puVar2 = *puVar2 - uVar1;
  }
  if (((((int)local_18[4] < 1) || (uVar1 = local_18[3], (int)local_18[2] <= (int)local_18[3])) ||
      (-1 < (int)local_18[2])) ||
     (((uVar1 = local_18[2], (int)local_18[1] <= (int)local_18[2] ||
       (uVar1 = local_18[0] + _DAT_008079ba, (int)local_18[1] <= (int)uVar1)) ||
      (uVar1 = (uint)_DAT_008079bc, (int)uVar1 <= (int)local_18[0])))) {
    uVar1 = uVar1 & 0xffff0000;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



//
// Function: bufferThresholdValidator @ 0x0000de50
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint bufferThresholdValidator(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (_DAT_00800138 == _DAT_0080013c) {
    uVar3 = *_DAT_00800140 >> 2;
    uVar2 = _DAT_00800140[-1] >> 2;
  }
  else if (_DAT_0080013c + 1 == _DAT_00800138) {
    uVar3 = *_DAT_0080013c >> 2;
    uVar2 = *_DAT_00800140 >> 2;
  }
  else {
    uVar3 = _DAT_00800138[-1] >> 2;
    uVar2 = _DAT_00800138[-2] >> 2;
  }
  iVar4 = _DAT_008079ce;
  if (_DAT_0080926e < _DAT_008079b8) {
    iVar4 = _DAT_008079ca;
  }
  uVar1 = uVar2 * _DAT_008079c8 >> 8;
  if (((uVar1 <= _DAT_00800134 >> 2) || (uVar1 = uVar3 - uVar2, iVar4 <= (int)uVar1)) &&
     (iVar4 <= (int)uVar3)) {
    return uVar1 & 0xffff0000;
  }
  return 1;
}



//
// Function: throttlePositionValidator @ 0x0000def4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 throttlePositionValidator(undefined4 param_1)

{
  undefined2 uVar1;
  uint uVar2;
  undefined2 uVar3;
  char cVar4;
  
  cVar4 = (char)((uint)param_1 >> 0x10);
  if (_DAT_00803788 == 0) {
    uVar3 = 0;
  }
  else {
    if (cVar4 == '\0') {
      _DAT_00800134 = _DAT_0080c75c;
      if (circular_buffer_t_0080c3fc.data_buffer_rest._16_4_ == 0x80c430) {
        _DAT_00800138 = _DAT_0080c77e;
      }
      else {
        _DAT_00800138 = circular_buffer_t_0080c3fc.data_buffer_rest._16_4_ + -4;
      }
      _DAT_0080013c = 0x80c430;
      _DAT_00800140 = _DAT_0080c77e;
      uVar2 = _DAT_00800130;
    }
    else {
      _DAT_00800134 = _DAT_0080c760;
      if (circular_buffer_t_0080c3fc.data_buffer_rest._20_4_ == 0x80c5c0) {
        _DAT_00800138 = _DAT_0080c782;
      }
      else {
        _DAT_00800138 = circular_buffer_t_0080c3fc.data_buffer_rest._20_4_ + -4;
      }
      _DAT_0080013c = 0x80c5c0;
      _DAT_00800140 = _DAT_0080c782;
      uVar2 = _DAT_0080012c;
    }
    if (_DAT_00807ce6 < circular_buffer_t_0080c3fc.data_buffer_4) {
      if (_DAT_00800134 < uVar2) {
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
    }
    else if (_DAT_00800134 < uVar2) {
      uVar2 = bufferThresholdValidator();
      uVar3 = (undefined2)uVar2;
    }
    else if ((_DAT_0080926e < _DAT_008079b6) &&
            (circular_buffer_t_0080c3fc.data_buffer_4 <= _DAT_008079be)) {
      uVar2 = bufferDecreasingPatternCheck();
      uVar3 = (undefined2)uVar2;
    }
    else {
      uVar3 = 0;
    }
    if (cVar4 == '\0') {
      _DAT_00800130 = _DAT_00800134 * _DAT_008079c6 >> 8;
    }
    else {
      _DAT_0080012c = _DAT_00800134 * _DAT_008079c6 >> 8;
    }
  }
  uVar1 = uVar3;
  if (cVar4 == '\0') {
    _DAT_00809d42 = uVar3;
    uVar1 = _DAT_00809d44;
  }
  _DAT_00809d44 = uVar1;
  return uVar3;
}



//
// Function: canBusTimingInit @ 0x0000e02c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void canBusTimingInit(void)

{
  _DAT_00800130 = _DAT_00800134 * (uint)_DAT_008079c6 >> 8;
  _DAT_0080012c = _DAT_00800134 * (uint)_DAT_008079c6 >> 8;
  return;
}



//
// Function: sendCanSingleFrame @ 0x0000e052
// ERROR: Failed to decompile
//

//
// Function: sendCanMessage @ 0x0000e180
//

void sendCanMessage(j1939_header_t *msg_header)

{
  if (msg_header->length < 9) {
    sendCanSingleFrame(msg_header->id);
    return;
  }
  sendJ1939MultiFrame(&msg_header->id);
  return;
}



//
// Function: sendJ1939MultiFrameWrapper @ 0x0000e1aa
//

void sendJ1939MultiFrameWrapper(void)

{
  uint *unaff_A2;
  
  sendJ1939MultiFrame(unaff_A2);
  return;
}



//
// Function: arrayRangeSum @ 0x0000e1b8
//

short arrayRangeSum(short *param_1,short *param_2)

{
  short sVar1;
  
  sVar1 = 0;
  for (; param_1 <= param_2; param_1 = param_1 + 1) {
    sVar1 = *param_1 + sVar1;
  }
  return sVar1;
}



//
// Function: memoryPatchCountDecrement @ 0x0000e1ce
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void memoryPatchCountDecrement(void)

{
  if (_DAT_0080d44e != 0) {
    _DAT_0080d44e = _DAT_0080d44e + -1;
    _DAT_0080d3e2 = _DAT_0080d3e2 - (uint)*(ushort *)((short)(_DAT_0080d44e * 3) * 2 + 0x80d3aa);
  }
  return;
}



//
// Function: rpm_derate_calculation_and_fault_processing @ 0x0000e200
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint rpm_derate_calculation_and_fault_processing(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = engine_control_flags_t_008035d6.reserved_08 & 0x400;
  if ((engine_control_flags_t_008035d6.reserved_08 & 0x400) == 0) {
    if (_DAT_00809d64 == 0) {
      _DAT_00800150 = _DAT_008092c6;
      uVar3 = 0x41;
      uVar2 = 0x42;
    }
    else {
      _DAT_00800150 = _DAT_00809d62;
      uVar3 = 0;
      uVar2 = 0;
    }
    uVar1 = (uint)_DAT_00800150;
    if (_DAT_00804bb6 < _DAT_00800150) {
      uVar1 = (((uint)_DAT_00800150 - (uint)_DAT_00804bb6) * 400) / (uint)_DAT_008079d6;
      _DAT_00809d5c = (ushort)uVar1;
    }
    else {
      _DAT_00809d5c = 0;
    }
    if (_DAT_00809d5a == 0) {
      if ((DAT_00800152 == '\0') && (_DAT_00809d60 == 0)) {
        if (((((((uint)(&fault_status_registers_t_00805df2.sensor_fault_status)
                       [(short)((int)uVar3 >> 4)] & 1 << (uVar3 & 0xf)) == 0) ||
              (uVar1 = (uint)*(ushort *)(&DAT_008068c4 + ((int)uVar3 >> 4) * 2),
              (uVar1 & 1 << (uVar3 & 0xf)) == 0)) &&
             ((((uint)(&fault_status_registers_t_00805df2.sensor_fault_status)
                      [(short)((int)uVar2 >> 4)] & 1 << (uVar2 & 0xf)) == 0 ||
              (uVar1 = (uint)*(ushort *)(&DAT_008068c4 + ((int)uVar2 >> 4) * 2),
              (uVar1 & 1 << (uVar2 & 0xf)) == 0)))) &&
            (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x20) == 0 ||
             (uVar1 = _DAT_008068cc & 0xffff0020, (_DAT_008068cc & 0x20) == 0)))) &&
           ((((fault_status_registers_t_00805df2.io_fault_status_1 & 8) == 0 ||
             (uVar1 = _DAT_008068cc & 0xffff0008, (_DAT_008068cc & 8) == 0)) &&
            (uVar1 = (uint)_DAT_00800150, _DAT_00804bb6 < _DAT_00800150)))) {
          _DAT_00809d4c = _DAT_00809d5c;
        }
        else {
          _DAT_00809d4c = 0;
        }
        _DAT_00809d5e = 0;
      }
      else {
        if (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x20) != 0) &&
           ((fault_latch_registers_t_00805e32.io_fault_latch_1 & 0x20) == 0)) {
          fault_status_registers_t_00805df2.io_fault_status_1 =
               fault_status_registers_t_00805df2.io_fault_status_1 & 0xffdf;
        }
        if (((fault_status_registers_t_00805df2.io_fault_status_1 & 8) != 0) &&
           ((fault_latch_registers_t_00805e32.io_fault_latch_1 & 8) == 0)) {
          fault_status_registers_t_00805df2.io_fault_status_1 =
               fault_status_registers_t_00805df2.io_fault_status_1 & 0xfff7;
        }
        if (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x10) != 0) &&
           ((fault_latch_registers_t_00805e32.io_fault_latch_1 & 0x10) == 0)) {
          fault_status_registers_t_00805df2.io_fault_status_1 =
               fault_status_registers_t_00805df2.io_fault_status_1 & 0xffef;
        }
        uVar1 = CONCAT22((short)(uVar1 >> 0x10),_DAT_00800150);
        if (_DAT_008079e2 < _DAT_00800150) {
          uVar1 = (((uint)_DAT_00800150 - (uint)_DAT_008079e2) * 400) / (uint)_DAT_008079d6;
          _DAT_00809d5c = (ushort)uVar1;
        }
        else {
          _DAT_00809d5c = 0;
        }
        _DAT_00809d50 = (ushort)(_DAT_008079e2 < _DAT_00800150);
        _DAT_00809d4c = _DAT_00809d5c;
        _DAT_00809d5e = 0;
      }
    }
    else {
      _DAT_00809d4c = _DAT_00809d58;
      _DAT_00809d5e = _DAT_00809d5a;
      _DAT_00809d5a = 0;
    }
  }
  else {
    _DAT_00809d4c = _DAT_008092c6;
  }
  if (400 < _DAT_00809d5c) {
    _DAT_00809d5c = 400;
  }
  if (400 < _DAT_00809d4c) {
    _DAT_00809d4c = 400;
  }
  return uVar1;
}



//
// Function: derateThresholdMonitorAndFaultController @ 0x0000e478
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong derateThresholdMonitorAndFaultController(void)

{
  ushort uVar1;
  undefined2 uVar2;
  short sVar4;
  short sVar5;
  uint uVar3;
  byte bVar6;
  uint in_D1;
  uint uVar7;
  ushort uVar8;
  uint uVar9;
  
  uVar7 = engine_control_flags_t_008035d6.reserved_08 & 0x400;
  if ((((engine_control_flags_t_008035d6.reserved_08 & 0x400) != 0) || (DAT_00800152 != '\0')) ||
     (_DAT_00809d60 != 0)) {
LAB_0000eac6:
    return CONCAT44(uVar7,in_D1);
  }
  if (_DAT_00809d64 == 0) {
    _DAT_00800150 = _DAT_008092c6;
    uVar7 = 0x41;
    uVar9 = 0x42;
  }
  else {
    _DAT_00800150 = _DAT_00809d62;
    uVar7 = 0;
    uVar9 = 0;
  }
  sVar4 = (short)((int)uVar7 >> 4);
  sVar5 = (short)((int)uVar9 >> 4);
  if (((((uint)(&fault_status_registers_t_00805df2.sensor_fault_status)[sVar4] & 1 << (uVar7 & 0xf))
        == 0) || (((uint)*(ushort *)(&DAT_008068c4 + sVar4 * 2) & 1 << (uVar7 & 0xf)) == 0)) &&
     ((((uint)(&fault_status_registers_t_00805df2.sensor_fault_status)[sVar5] & 1 << (uVar9 & 0xf))
       == 0 || (((uint)*(ushort *)(&DAT_008068c4 + sVar5 * 2) & 1 << (uVar9 & 0xf)) == 0)))) {
    if ((_DAT_008079e0 == 0) && (_DAT_00800150 < _DAT_00809d56)) {
      _DAT_00809d56 = _DAT_00800150;
    }
    if (_DAT_008079e0 == 1) {
      if ((_DAT_00800150 < _DAT_00809d56) && (_DAT_00809d54 == 0)) {
        _DAT_00809d54 = _DAT_008079da;
        _DAT_0080014a = _DAT_00800150;
      }
      if (_DAT_00809d54 != 0) {
        if ((uint)_DAT_008079dc + (uint)_DAT_0080014a < (uint)_DAT_00800150) {
          _DAT_00809d54 = _DAT_00809d54 + 1;
          if (_DAT_00809d54 == _DAT_008079da) {
            _DAT_0080014a = _DAT_00809d56;
            _DAT_00809d54 = 0;
          }
        }
        else {
          _DAT_00809d54 = _DAT_00809d54 + -1;
          if (_DAT_00809d54 == 0) {
            _DAT_00809d56 = _DAT_0080014a;
          }
        }
      }
    }
  }
  else {
    _DAT_00809d56 = _DAT_008079d8 + 1;
  }
  _DAT_0080014e = _DAT_008079d2 + (_DAT_00804bb6 - _DAT_008079e4);
  _DAT_0080014c = _DAT_008079d4 + (_DAT_00804bb6 - _DAT_008079e4);
  if ((((DAT_0080bdc6 & 0x80) == 0) || ((DAT_0080bdc7 & 1) != 0)) &&
     (((DAT_0080bdc6 & 0x80) != 0 || ((DAT_0080bdc7 & 1) == 0)))) {
    if ((DAT_0080bdc6 & 0x80) == 0) {
      if (_DAT_0080014e < _DAT_00800150) {
        _DAT_00809d4e = 5;
      }
      else if (_DAT_00800150 < _DAT_0080014c) {
        _DAT_00809d4e = 6;
      }
      else {
        _DAT_00809d4e = 7;
      }
    }
    else if ((_DAT_0080014e < _DAT_00800150) || (_DAT_00800150 < _DAT_0080014c)) {
      _DAT_00809d4e = 4;
    }
    else {
      _DAT_00809d4e = 7;
    }
  }
  else if ((DAT_0080bdc6 & 0x80) == 0) {
    if (_DAT_00800150 < _DAT_00804bb6) {
      if (_DAT_00800150 < _DAT_0080014c) {
        _DAT_00809d4e = 3;
      }
      else {
        _DAT_00809d4e = 8;
      }
    }
    else {
      _DAT_00809d4e = 1;
    }
  }
  else if (_DAT_00804bb6 < _DAT_00800150) {
    if (_DAT_0080014e < _DAT_00800150) {
      _DAT_00809d4e = 2;
    }
    else {
      _DAT_00809d4e = 9;
    }
  }
  else {
    _DAT_00809d4e = 0;
  }
  if ((((_DAT_00809d4e == 1) || (_DAT_00809d4e == 3)) || (_DAT_00809d4e == 5)) ||
     (_DAT_00809d4e == 9)) {
    _DAT_00809d50 = 1;
  }
  else {
    _DAT_00809d50 = 0;
  }
  if (((uint)(&fault_status_registers_t_00805df2.sensor_fault_status)[sVar4] & 1 << (uVar7 & 0xf))
      != 0) {
    uVar3 = (uint)*(ushort *)(&DAT_008068c4 + sVar4 * 2);
    uVar7 = uVar3 & 1 << (uVar7 & 0xf);
    if (uVar7 != 0) goto LAB_0000e7d2;
  }
  if (((uint)(&fault_status_registers_t_00805df2.sensor_fault_status)[sVar5] & 1 << (uVar9 & 0xf))
      != 0) {
    uVar3 = (uint)*(ushort *)(&DAT_008068c4 + sVar5 * 2);
    uVar7 = uVar3 & 1 << (uVar9 & 0xf);
    if (uVar7 != 0) {
LAB_0000e7d2:
      _DAT_00809d52 = 0;
      return CONCAT44(uVar3,uVar7);
    }
  }
  if (_DAT_00809d52 == 0) {
    if ((((DAT_0080bdc6 & 0x80) != 0) && ((DAT_0080bdc7 & 1) == 0)) &&
       ((uint)_DAT_00800150 <= (uint)_DAT_008079e4 + (uint)_DAT_00809d56)) {
      _DAT_00809d52 = 1;
    }
  }
  else if (_DAT_00809d52 == 1) {
    if ((_DAT_00809d4e == 1) && ((uint)_DAT_008079e8 + (uint)_DAT_00809d56 < (uint)_DAT_00800150)) {
      _DAT_00809d52 = 2;
    }
  }
  else if (((_DAT_00809d52 == 2) && ((DAT_0080bdc6 & 0x80) != 0)) &&
          (((DAT_0080bdc7 & 1) == 0 &&
           ((uint)_DAT_00800150 <= (uint)_DAT_008079e4 + (uint)_DAT_00809d56)))) {
    _DAT_00809d52 = 3;
  }
  if (_DAT_00809d52 == 3) {
    if (_DAT_00809d54 == 0) {
      _DAT_00804bb6 = _DAT_008079e4 + _DAT_00809d56;
    }
    if (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x20) != 0) &&
       ((fault_latch_registers_t_00805e32.io_fault_latch_1 & 0x20) == 0)) {
      fault_status_registers_t_00805df2.io_fault_status_1 =
           fault_status_registers_t_00805df2.io_fault_status_1 & 0xffdf;
    }
    if (((fault_status_registers_t_00805df2.io_fault_status_1 & 8) != 0) &&
       ((fault_latch_registers_t_00805e32.io_fault_latch_1 & 8) == 0)) {
      fault_status_registers_t_00805df2.io_fault_status_1 =
           fault_status_registers_t_00805df2.io_fault_status_1 & 0xfff7;
    }
    if (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x10) != 0) &&
       ((fault_latch_registers_t_00805e32.io_fault_latch_1 & 0x10) == 0)) {
      fault_status_registers_t_00805df2.io_fault_status_1 =
           fault_status_registers_t_00805df2.io_fault_status_1 & 0xffef;
    }
  }
  if ((_DAT_00804bb6 < _DAT_008079e4) ||
     (uVar7 = (uint)_DAT_008079d8 + (uint)_DAT_008079e4, uVar7 < _DAT_00804bb6)) {
    uVar7 = (uint)_DAT_008079d8 + (uint)_DAT_008079e4;
    in_D1 = (uint)_DAT_00804bb6;
    if ((in_D1 <= uVar7) ||
       (uVar7 = CONCAT22((short)(uVar7 >> 0x10),_DAT_008096a6), _DAT_008096a6 <= _DAT_008079e6)) {
      _DAT_00800144 = 0;
      _DAT_00800146 = 0;
      _DAT_00800148 = 0;
      goto LAB_0000eac6;
    }
  }
  uVar9 = (uint)_DAT_00804bb6;
  uVar1 = (ushort)(uVar7 >> 0x10);
  uVar7 = CONCAT22(uVar1,_DAT_008092c6);
  uVar8 = _DAT_008079ea;
  if (_DAT_00804bb6 <= _DAT_008092c6) {
    uVar8 = _DAT_008079de;
  }
  if (_DAT_00809d4e == 4) {
    if (_DAT_00800144 < uVar8) {
      _DAT_00800144 = _DAT_00800144 + 1;
    }
    else {
      fault_status_registers_t_00805df2.io_fault_status_1 =
           fault_status_registers_t_00805df2.io_fault_status_1 | 8;
      fault_latch_registers_t_00805e32.io_fault_latch_1 =
           fault_latch_registers_t_00805e32.io_fault_latch_1 | 8;
      _DAT_00809d52 = 0;
    }
  }
  else {
    _DAT_00800144 = 0;
  }
  if ((_DAT_00809d4e == 6) || (_DAT_00809d4e == 5)) {
    if (_DAT_00800146 < uVar8) {
      _DAT_00800146 = _DAT_00800146 + 1;
    }
    else {
      fault_status_registers_t_00805df2.io_fault_status_1 =
           fault_status_registers_t_00805df2.io_fault_status_1 | 0x10;
      fault_latch_registers_t_00805e32.io_fault_latch_1 =
           fault_latch_registers_t_00805e32.io_fault_latch_1 | 0x10;
      _DAT_00809d52 = 0;
    }
  }
  else {
    _DAT_00800146 = 0;
  }
  if (((_DAT_00809d4e == 2) || (_DAT_00809d4e == 3)) &&
     ((uVar7 = (uint)uVar1 << 0x10,
      (fault_status_registers_t_00805df2.io_fault_status_1 & 0x10) == 0 ||
      (uVar7 = CONCAT22(uVar1,_DAT_008068cc) & 0xffff0010, (_DAT_008068cc & 0x10) == 0)))) {
    uVar2 = (undefined2)(uVar7 >> 0x10);
    uVar7 = CONCAT22(uVar2,fault_status_registers_t_00805df2.io_fault_status_1) & 0xffff0008;
    if (((fault_status_registers_t_00805df2.io_fault_status_1 & 8) == 0) ||
       (uVar7 = CONCAT22(uVar2,_DAT_008068cc) & 0xffff0008, (_DAT_008068cc & 8) == 0)) {
      if (_DAT_00800148 < uVar8) {
        _DAT_00800148 = _DAT_00800148 + 1;
        return CONCAT44(uVar7,uVar9);
      }
      fault_status_registers_t_00805df2.io_fault_status_1 =
           fault_status_registers_t_00805df2.io_fault_status_1 | 0x20;
      fault_latch_registers_t_00805e32.io_fault_latch_1 =
           fault_latch_registers_t_00805e32.io_fault_latch_1 | 0x20;
      _DAT_00809d52 = 0;
      bVar6 = -((DAT_0080bdc6 & 0x80) != 0);
      _DAT_00804bdc = bVar6 & 1;
      return (ulonglong)CONCAT14(bVar6,uVar9) & 0x1ffffffff;
    }
  }
  _DAT_00800148 = 0;
  return CONCAT44(uVar7,uVar9);
}



//
// Function: initDerateSystem @ 0x0000eacc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort initDerateSystem(void)

{
  _DAT_00809d56 = _DAT_008079d8 + 4;
  if ((engine_control_flags_t_008035d6.fuel_demand_control & 4) != 0) {
    DAT_00800152 = 1;
  }
  return engine_control_flags_t_008035d6.fuel_demand_control & 4;
}



//
// Function: FUN_0000eaf0 @ 0x0000eaf0
// ERROR: Failed to decompile
//

//
// Function: kickdownSignalSlowCycle40Coordinator @ 0x0000eb5a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void kickdownSignalSlowCycle40Coordinator(void)

{
  if ((fuel_demand_state_t_0080c9a4._2_2_ != 0xb) &&
     (_DAT_008079ec < fuel_demand_state_t_0080c9a4.command)) {
    _DAT_00809d66 = 0;
    _DAT_0080016c = 0;
    return;
  }
  _DAT_00800166 = _DAT_0080926e;
  _DAT_00809d66 = lookupTableInterpolation((short *)&DAT_00800160);
  _DAT_0080016c = 2;
  return;
}



//
// Function: timingAccumulatorUpdate @ 0x0000ebb0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void timingAccumulatorUpdate(void)

{
  fuel_demand_state_t_0080c9a4.limit_minimum =
       _DAT_00809d66 + fuel_demand_state_t_0080c9a4.limit_minimum;
  fuel_demand_state_t_0080c9a4.adjustment_active =
       _DAT_0080016c | fuel_demand_state_t_0080c9a4.adjustment_active & 0xfffd;
  return;
}



//
// Function: initAcControlSystem @ 0x0000ebd2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initAcControlSystem(void)

{
  _DAT_00800162 = 0x8079ee;
  _DAT_00800168 = &ACVSACCO;
  _DAT_00800160 = 2;
  return;
}



//
// Function: calibrationDataCopyWithChecksum @ 0x0000ebf2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 calibrationDataCopyWithChecksum(void)

{
  ushort extraout_D0u;
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  sVar1 = arrayRangeSum((short *)&DAT_00004000,&DAT_00005e42);
  if ((sVar1 != _DAT_00803500) && (DAT_00005e42 != -0x5e5f)) {
    return 1;
  }
  puVar3 = (undefined4 *)&DAT_00004000;
  for (puVar2 = (undefined4 *)&DAT_00804882; puVar2 < (undefined4 *)0x80488c; puVar2 = puVar2 + 1) {
    *puVar2 = *puVar3;
    DAT_00fffa27 = 0xaa;
    DAT_00ffd00f = 0xaa;
    puVar3 = puVar3 + 1;
  }
  puVar3 = &DAT_00004400;
  for (puVar2 = (undefined4 *)&DAT_0080488e; puVar2 < &DAT_008062d0; puVar2 = puVar2 + 1) {
    *puVar2 = *puVar3;
    DAT_00fffa27 = 0xaa;
    DAT_00ffd00f = 0xaa;
    puVar3 = puVar3 + 1;
  }
  _DAT_0080d1a0 = 1;
  return (uint)extraout_D0u << 0x10;
}



//
// Function: calibrationDataCopySecondary @ 0x0000eca4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 calibrationDataCopySecondary(void)

{
  ushort extraout_D0u;
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  sVar1 = arrayRangeSum((short *)&DAT_00006000,(short *)0x7e42);
  if (sVar1 != _DAT_00803502) {
    return 1;
  }
  puVar3 = (undefined4 *)&DAT_00006000;
  for (puVar2 = (undefined4 *)&DAT_00804882; puVar2 < (undefined4 *)0x80488c; puVar2 = puVar2 + 1) {
    *puVar2 = *puVar3;
    DAT_00fffa27 = 0xaa;
    DAT_00ffd00f = 0xaa;
    puVar3 = puVar3 + 1;
  }
  puVar3 = (undefined4 *)&DAT_00006400;
  for (puVar2 = (undefined4 *)&DAT_0080488e; puVar2 < &DAT_008062d0; puVar2 = puVar2 + 1) {
    *puVar2 = *puVar3;
    DAT_00fffa27 = 0xaa;
    DAT_00ffd00f = 0xaa;
    puVar3 = puVar3 + 1;
  }
  _DAT_0080d1a0 = 2;
  return (uint)extraout_D0u << 0x10;
}



//
// Function: eepromCalibrationWritePrimary @ 0x0000ed52
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int eepromCalibrationWritePrimary(void)

{
  ushort extraout_D0u;
  int iVar1;
  short sVar2;
  undefined4 unaff_D2;
  char in_XF;
  char in_NF;
  char in_ZF;
  char in_VF;
  byte in_CF;
  char cVar3;
  ushort uVar4;
  ushort uVar5;
  undefined2 uVar6;
  short local_6;
  
  uVar6 = (undefined2)((uint)unaff_D2 >> 0x10);
  uVar4 = (ushort)(byte)(in_XF << 4 | in_NF << 3 | in_ZF << 2 | in_VF << 1 | in_CF);
  if ((_DAT_00803682 + _DAT_0080367a & 1U) == 0) {
    local_6 = _DAT_0080367a + 1;
  }
  else {
    local_6 = _DAT_0080367a + 2;
  }
  parameterCircularBufferWrite(0x80367a,(undefined1 *)&local_6,CONCAT22(2,uVar4));
  uVar5 = 0;
  while ((uVar5 < 5000 && (_DAT_0080367a != local_6))) {
    emptyPlaceholderFunction();
    delayWithWatchdogService(CONCAT22(500,uVar4));
    uVar5 = uVar5 + 1;
  }
  iVar1 = flashEraseFromRam(0x4000);
  if (iVar1 == 0) {
    DAT_00fffa27 = 0xaa;
    DAT_00ffd00f = 0xaa;
    sVar2 = flashProgramFromRam(0x4000,&DAT_00804882,CONCAT22(10,uVar6));
    if (sVar2 == 1) {
      DAT_00fffa27 = 0xaa;
      DAT_00ffd00f = 0xaa;
      sVar2 = flashProgramFromRam(0x4400,&DAT_0080488e,CONCAT22(0x1a42,uVar6));
      cVar3 = sVar2 == 0;
      if (sVar2 == 1) {
        DAT_00fffa27 = 0xaa;
        DAT_00ffd00f = 0xaa;
        local_6 = arrayRangeSum((short *)&DAT_00004000,&DAT_00005e42);
        DAT_00fffa27 = 0xaa;
        DAT_00ffd00f = 0xaa;
        uVar5 = (ushort)(byte)(cVar3 << 4 | 8);
        parameterCircularBufferWrite(0x803500,(undefined1 *)&local_6,CONCAT22(2,uVar5));
        uVar4 = 0;
        while ((uVar4 < 5000 && (_DAT_00803500 != local_6))) {
          emptyPlaceholderFunction();
          delayWithWatchdogService(CONCAT22(500,uVar5));
          uVar4 = uVar4 + 1;
        }
        parameterCircularBufferWrite(0x80367c,&DAT_0080367a,CONCAT22(2,uVar5));
        uVar4 = 0;
        while ((uVar4 < 5000 && (_DAT_0080367c != _DAT_0080367a))) {
          emptyPlaceholderFunction();
          delayWithWatchdogService(CONCAT22(500,uVar5));
          uVar4 = uVar4 + 1;
        }
        _DAT_0080d1a0 = 1;
        canMemoryPointerTableInit();
        iVar1 = (uint)extraout_D0u << 0x10;
      }
      else {
        iVar1 = 1;
      }
    }
    else {
      iVar1 = 1;
    }
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}



//
// Function: eepromCalibrationWriteSecondary @ 0x0000ef80
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int eepromCalibrationWriteSecondary(void)

{
  ushort extraout_D0u;
  int iVar1;
  short sVar2;
  undefined4 unaff_D2;
  char in_XF;
  char in_NF;
  char in_ZF;
  char in_VF;
  byte in_CF;
  char cVar3;
  ushort uVar4;
  ushort uVar5;
  undefined2 uVar6;
  short local_6;
  
  uVar6 = (undefined2)((uint)unaff_D2 >> 0x10);
  uVar4 = (ushort)(byte)(in_XF << 4 | in_NF << 3 | in_ZF << 2 | in_VF << 1 | in_CF);
  if ((_DAT_00803682 + _DAT_0080367a & 1U) == 0) {
    local_6 = _DAT_0080367a + 2;
  }
  else {
    local_6 = _DAT_0080367a + 1;
  }
  parameterCircularBufferWrite(0x803682,(undefined1 *)&local_6,CONCAT22(2,uVar4));
  uVar5 = 0;
  while ((uVar5 < 5000 && (_DAT_00803682 != local_6))) {
    emptyPlaceholderFunction();
    delayWithWatchdogService(CONCAT22(500,uVar4));
    uVar5 = uVar5 + 1;
  }
  iVar1 = flashEraseFromRam(0x6000);
  if (iVar1 == 0) {
    DAT_00fffa27 = 0xaa;
    DAT_00ffd00f = 0xaa;
    sVar2 = flashProgramFromRam(0x6000,&DAT_00804882,CONCAT22(10,uVar6));
    if (sVar2 == 1) {
      DAT_00fffa27 = 0xaa;
      DAT_00ffd00f = 0xaa;
      sVar2 = flashProgramFromRam(0x6400,&DAT_0080488e,CONCAT22(0x1a42,uVar6));
      cVar3 = sVar2 == 0;
      if (sVar2 == 1) {
        DAT_00fffa27 = 0xaa;
        DAT_00ffd00f = 0xaa;
        local_6 = arrayRangeSum((short *)&DAT_00006000,(short *)0x7e42);
        DAT_00fffa27 = 0xaa;
        DAT_00ffd00f = 0xaa;
        uVar5 = (ushort)(byte)(cVar3 << 4 | 8);
        parameterCircularBufferWrite(0x803502,(undefined1 *)&local_6,CONCAT22(2,uVar5));
        uVar4 = 0;
        while ((uVar4 < 5000 && (_DAT_00803502 != local_6))) {
          emptyPlaceholderFunction();
          delayWithWatchdogService(CONCAT22(500,uVar5));
          uVar4 = uVar4 + 1;
        }
        parameterCircularBufferWrite(0x803684,&DAT_00803682,CONCAT22(2,uVar5));
        uVar4 = 0;
        while ((uVar4 < 5000 && (_DAT_00803684 != _DAT_00803682))) {
          emptyPlaceholderFunction();
          delayWithWatchdogService(CONCAT22(500,uVar5));
          uVar4 = uVar4 + 1;
        }
        _DAT_0080d1a0 = 2;
        canMemoryPointerTableInit();
        iVar1 = (uint)extraout_D0u << 0x10;
      }
      else {
        iVar1 = 1;
      }
    }
    else {
      iVar1 = 1;
    }
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}



//
// Function: validateRedundantSensors @ 0x0000f1ae
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void validateRedundantSensors(void)

{
  undefined4 uVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  ushort uVar8;
  
  _DAT_0080d1a0 = 0;
  fault_status_registers_t_00805df2.sensor_fault_status =
       fault_status_registers_t_00805df2.sensor_fault_status & 0xefff;
  if (DAT_00005e42 == -0x5e5f) {
    calibrationDataCopyWithChecksum();
    _DAT_008062d0 = 0;
  }
  else if ((_DAT_0080367a != _DAT_0080367c) || (_DAT_00803682 != _DAT_00803684)) {
    if (_DAT_0080367a != _DAT_0080367c) {
      if (_DAT_00803682 != _DAT_00803684) {
        fault_status_registers_t_00805df2.sensor_fault_status =
             fault_status_registers_t_00805df2.sensor_fault_status | 0x1000;
        fault_latch_registers_t_00805e32.sensor_fault_latch =
             fault_latch_registers_t_00805e32.sensor_fault_latch | 0x1000;
      }
      else {
        uVar1 = calibrationDataCopySecondary();
        if ((short)uVar1 != 0) {
          fault_status_registers_t_00805df2.sensor_fault_status =
               fault_status_registers_t_00805df2.sensor_fault_status | 0x1000;
          fault_latch_registers_t_00805e32.sensor_fault_latch =
               fault_latch_registers_t_00805e32.sensor_fault_latch | 0x1000;
        }
      }
    }
    else {
      uVar1 = calibrationDataCopyWithChecksum();
      if ((short)uVar1 != 0) {
        fault_status_registers_t_00805df2.sensor_fault_status =
             fault_status_registers_t_00805df2.sensor_fault_status | 0x1000;
        fault_latch_registers_t_00805e32.sensor_fault_latch =
             fault_latch_registers_t_00805e32.sensor_fault_latch | 0x1000;
      }
    }
  }
  else if ((_DAT_00803682 + _DAT_0080367a & 1U) == 0) {
    uVar1 = calibrationDataCopySecondary();
    if ((short)uVar1 != 0) {
      uVar1 = calibrationDataCopyWithChecksum();
      if ((short)uVar1 != 0) {
        fault_status_registers_t_00805df2.sensor_fault_status =
             fault_status_registers_t_00805df2.sensor_fault_status | 0x1000;
        fault_latch_registers_t_00805e32.sensor_fault_latch =
             fault_latch_registers_t_00805e32.sensor_fault_latch | 0x1000;
      }
    }
  }
  else {
    uVar1 = calibrationDataCopyWithChecksum();
    if ((short)uVar1 != 0) {
      uVar1 = calibrationDataCopySecondary();
      if ((short)uVar1 != 0) {
        fault_status_registers_t_00805df2.sensor_fault_status =
             fault_status_registers_t_00805df2.sensor_fault_status | 0x1000;
        fault_latch_registers_t_00805e32.sensor_fault_latch =
             fault_latch_registers_t_00805e32.sensor_fault_latch | 0x1000;
      }
    }
  }
  bVar6 = _DAT_00803686 < _DAT_00803688;
  bVar3 = (short)(_DAT_00803686 - _DAT_00803688) < 0;
  if (_DAT_00803686 == _DAT_00803688) {
    uVar8 = (ushort)(byte)(bVar6 << 4 | bVar3 << 3 | 4U | SBORROW2(_DAT_00803686,_DAT_00803688) << 1
                          | bVar6);
    _DAT_0080016e = 0;
    parameterCircularBufferWrite(0x80368a,&DAT_0080016e,CONCAT22(2,uVar8));
    uVar2 = 0;
    while ((uVar2 < 5000 && (_DAT_0080368a != _DAT_0080016e))) {
      emptyPlaceholderFunction();
      delayWithWatchdogService(CONCAT22(500,uVar8));
      uVar2 = uVar2 + 1;
    }
    _DAT_0080016e = _DAT_0080368e + 1;
    parameterCircularBufferWrite(0x80368e,&DAT_0080016e,CONCAT22(2,uVar8));
    uVar2 = 0;
    while ((uVar2 < 5000 && (_DAT_0080368e != _DAT_0080016e))) {
      emptyPlaceholderFunction();
      delayWithWatchdogService(CONCAT22(500,uVar8));
      uVar2 = uVar2 + 1;
    }
    bVar3 = (uVar8 & 0x10) != 0;
    bVar6 = (uVar8 & 8) != 0;
    bVar4 = (uVar8 & 4) != 0;
    bVar5 = (uVar8 & 2) != 0;
    bVar7 = (uVar8 & 1) != 0;
    fault_status_registers_t_00805df2.sensor_fault_status =
         fault_status_registers_t_00805df2.sensor_fault_status & 0xf7ff;
  }
  else {
    uVar8 = (ushort)(byte)(bVar6 << 4 | bVar3 << 3 | SBORROW2(_DAT_00803686,_DAT_00803688) << 1 |
                          bVar6);
    _DAT_0080016e = _DAT_0080368a + 1;
    parameterCircularBufferWrite(0x80368a,&DAT_0080016e,CONCAT22(2,uVar8));
    uVar2 = 0;
    while ((uVar2 < 5000 && (_DAT_0080368a != _DAT_0080016e))) {
      emptyPlaceholderFunction();
      delayWithWatchdogService(CONCAT22(500,uVar8));
      uVar2 = uVar2 + 1;
    }
    _DAT_0080016e = _DAT_0080368c + 1;
    parameterCircularBufferWrite(0x80368c,&DAT_0080016e,CONCAT22(2,uVar8));
    uVar2 = 0;
    while ((uVar2 < 5000 && (_DAT_0080368c != _DAT_0080016e))) {
      emptyPlaceholderFunction();
      delayWithWatchdogService(CONCAT22(500,uVar8));
      uVar2 = uVar2 + 1;
    }
    bVar5 = SBORROW2(_DAT_0080368a,_DAT_008088c0);
    bVar6 = (short)(_DAT_0080368a - _DAT_008088c0) < 0;
    bVar4 = _DAT_0080368a == _DAT_008088c0;
    if (_DAT_0080368a < _DAT_008088c0) {
      fault_status_registers_t_00805df2.sensor_fault_status =
           fault_status_registers_t_00805df2.sensor_fault_status & 0xf7ff;
      bVar3 = true;
      bVar7 = true;
    }
    else {
      fault_status_registers_t_00805df2.sensor_fault_status =
           fault_status_registers_t_00805df2.sensor_fault_status | 0x800;
      fault_latch_registers_t_00805e32.sensor_fault_latch =
           fault_latch_registers_t_00805e32.sensor_fault_latch | 0x800;
      bVar3 = false;
      bVar7 = false;
    }
  }
  uVar8 = (ushort)(byte)(bVar3 << 4 | bVar6 << 3 | bVar4 << 2 | bVar5 << 1 | bVar7);
  _DAT_0080016e = _DAT_0080368c + _DAT_0080368e;
  parameterCircularBufferWrite(0x803686,&DAT_0080016e,CONCAT22(2,uVar8));
  uVar2 = 0;
  while ((uVar2 < 5000 && (_DAT_00803686 != _DAT_0080016e))) {
    emptyPlaceholderFunction();
    delayWithWatchdogService(CONCAT22(500,uVar8));
    uVar2 = uVar2 + 1;
  }
  return;
}



//
// Function: firmwareDataCopyToWorkingMemory @ 0x0000f4ea
//

void firmwareDataCopyToWorkingMemory(void)

{
  byte *pbVar1;
  undefined4 *puVar2;
  
  pbVar1 = &firmware_data_source;
  for (puVar2 = (undefined4 *)&DAT_008062d2; puVar2 < (undefined4 *)0x808ab2; puVar2 = puVar2 + 1) {
    DAT_00fffa27 = 0xaa;
    DAT_00ffd00f = 0xaa;
    *puVar2 = *(undefined4 *)pbVar1;
    pbVar1 = pbVar1 + 4;
  }
  return;
}



//
// Function: pwmFuelDemandOutputCalculator @ 0x0000f524
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint pwmFuelDemandOutputCalculator(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = ((uint)fuel_demand_state_t_0080c9a4.command * 0x6400) / 0x1700;
  _DAT_0080d186 = (short)uVar1;
  uVar2 = ((uint)_DAT_0080d482 * 0x6400) / 0x1700;
  _DAT_0080d188 = (short)uVar2;
  uVar3 = uVar2 & 0xffff0000;
  if ((_DAT_00805670 & 1) == 0) {
    sim_timer_control_register = sim_timer_control_register & 0xffff0000;
  }
  else {
    uVar3 = ((((uint)_DAT_00808934 * (uVar1 & 0xffff)) / 0x6400 & 0xffff) * 8000) / 1000 & 0xffff |
            ((uint)_DAT_00808934 * 8000) / 1000 << 0x10;
    sim_timer_control_register = uVar3;
  }
  uVar3 = uVar3 & 0xffff0000;
  if ((_DAT_00805670 & 2) == 0) {
    _DAT_00fff432 = _DAT_00fff432 & 0xffff0000;
  }
  else {
    uVar3 = ((((uint)_DAT_00808936 * (uVar2 & 0xffff)) / 0x6400 & 0xffff) * 8000) / 1000 & 0xffff |
            ((uint)_DAT_00808936 * 8000) / 1000 << 0x10;
    _DAT_00fff432 = uVar3;
  }
  if (5 < _DAT_0080d19a) {
    uVar3 = uVar3 & 0xffff0000;
    if ((_DAT_00805670 & 4) == 0) {
      tpu_pwm_channel_3_output = tpu_pwm_channel_3_output & 0xffff0000;
    }
    else {
      uVar3 = ((((uint)_DAT_00808938 * (uint)_DAT_0080d18a) / 0x6400 & 0xffff) * 8000) / 1000 &
              0xffff | ((uint)_DAT_00808938 * 8000) / 1000 << 0x10;
      tpu_pwm_channel_3_output = uVar3;
    }
  }
  if (5 < _DAT_0080d19a) {
    uVar3 = uVar3 & 0xffff0000;
    if ((_DAT_00805670 & 8) == 0) {
      tpu_pwm_channel_4_output = tpu_pwm_channel_4_output & 0xffff0000;
    }
    else {
      uVar3 = ((((uint)_DAT_0080893a * (uint)_DAT_0080d18c) / 0x6400 & 0xffff) * 8000) / 1000 &
              0xffff | ((uint)_DAT_0080893a * 8000) / 1000 << 0x10;
      tpu_pwm_channel_4_output = uVar3;
    }
  }
  if (((_DAT_00805670 & 0x10) != 0) && (_DAT_0080d18e != 0)) {
    if (0x63ff < _DAT_0080d18e) {
      uVar3 = ((uint)_DAT_0080893c * 8000) / 1000;
      _DAT_00fff414 = -1 - (short)uVar3;
      _DAT_00fff41a = 0x7fff8000;
      return uVar3;
    }
    _DAT_00fff414 = -(short)(((uint)_DAT_0080893c * 8000) / 1000) - 1;
    _DAT_00fff41a =
         (_DAT_00fff414 & 0x7fff) +
         (((((uint)_DAT_0080893c * (uint)_DAT_0080d18e) / 0x6400 & 0xffff) * 8000) / 1000 & 0xffff)
         | 0x7fff0000;
    return _DAT_00fff41a;
  }
  _DAT_00fff41a = 0x7fff;
  return CONCAT22((short)(uVar3 >> 0x10),_DAT_00805670) & 0xffff0010;
}



//
// Function: systemControl65 @ 0x0000f86a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 systemControl65(void)

{
  _DAT_0080d48c = _DAT_0080d48c | 1;
  return 0;
}



//
// Function: systemControl69 @ 0x0000f876
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint systemControl69(void)

{
  uint in_D0;
  
  if (_DAT_0080d3f4 == 1) {
    _DAT_0080d3f4 = 0;
    _DAT_0080d19c = 1;
    _DAT_0080d1a2 = 0xeeee;
    return in_D0 & 0xffffff00;
  }
  return 4;
}



//
// Function: securedOperation40 @ 0x0000f89c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 securedOperation40(void)

{
  _DAT_0080d19c = 0;
  _DAT_0080d3f4 = 1;
  _DAT_0080d1a2 = 0xaaaa;
  return 0;
}



//
// Function: securedOperation41 @ 0x0000f8b6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 securedOperation41(void)

{
  _DAT_0080d19c = 1;
  if (_DAT_0080d1a2 == -0x5556) {
    _DAT_0080d1a2 = -0x1112;
    _DAT_0080d3f4 = 0;
  }
  return 0;
}



//
// Function: securedOperation42 @ 0x0000f8d8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 securedOperation42(void)

{
  _DAT_0080c996 = 1;
  return 0;
}



//
// Function: eepromWriteWrapper @ 0x0000f8e4
//

void eepromWriteWrapper(byte *param_1)

{
  ushort in_stack_00000000;
  
  systemResetWithDiagnostic(param_1,(uint)in_stack_00000000);
  return;
}



//
// Function: securedOperation43 @ 0x0000f8f6
//

void securedOperation43(void)

{
  undefined2 in_stack_00000000;
  
  systemResetWithDiagnostic((byte *)0x0,CONCAT22(1,in_stack_00000000));
  return;
}



//
// Function: systemResetWithDiagnostic @ 0x0000f906
//

/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 systemResetWithDiagnostic(byte *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 unaff_A2;
  ushort uVar3;
  int local_8;
  
  uVar3 = (ushort)((uint)unaff_A2 >> 0x10);
  if (engine_operating_mode_t_0080c810.state == 1) {
    while (uVar1 = circularBufferEmptyCheck(), (char)uVar1 == '\0') {
      emptyPlaceholderFunction();
      FUN_0002bb2e(CONCAT22(500,uVar3));
    }
    local_8 = _DAT_0080d4c4;
    parameterCircularBufferWrite(0x80352c,(undefined1 *)&local_8,CONCAT22(4,uVar3));
    if (_DAT_0080d19c == 0) {
      FUN_0002bb2e(CONCAT22(0xfa,uVar3));
    }
    else {
      while (_DAT_0080352c != local_8) {
        emptyPlaceholderFunction();
        FUN_0002bb2e(CONCAT22(500,uVar3));
      }
    }
    if (param_2._1_1_ == '\0') {
      FUN_000298d8(param_1,(uint)uVar3);
    }
    else {
      diagnosticMessageQueueWrite((uint)uVar3);
    }
    FUN_0002bb2e(CONCAT22(50000,uVar3));
    DAT_0080bdf0 = DAT_0080bdf0 & 0xef;
    ioControlAndCanPinSwitching();
    _DAT_0080fffc = 0xf9d2;
    uVar2 = (*_DAT_00000008)();
    uVar2 = CONCAT31((int3)((uint)uVar2 >> 8),0xff);
  }
  else {
    uVar2 = 7;
  }
  return uVar2;
}



//
// Function: securedOperation52 @ 0x0000f9e4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 securedOperation52(void)

{
  _DAT_0080d450 = 1;
  return 0;
}



//
// Function: canMessageBufferLogger @ 0x0000f9f0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 canMessageBufferLogger(void)

{
  undefined4 uVar1;
  
  if (_DAT_0080d1a4 == 1) {
    return 7;
  }
  uVar1 = circularBufferWrite();
  if ((char)uVar1 == '\x01') {
    DAT_0080d3f3 = 0;
    return 0xb;
  }
  DAT_0080d406 = 1;
  _DAT_0080d19e = 0;
  return CONCAT31((int3)((uint)uVar1 >> 8),0xff);
}



//
// Function: systemFunction8xMaximum @ 0x0000fa40
//

void systemFunction8xMaximum(void)

{
  coreSystemFunction();
  coreSystemFunction();
  coreSystemFunction();
  coreSystemFunction();
  coreSystemFunction();
  coreSystemFunction();
  coreSystemFunction();
  coreSystemFunction();
  return;
}



//
// Function: crc16Calculate @ 0x0000fcb0
//

undefined4 crc16Calculate(byte *param_1,undefined4 param_2)

{
  ushort uVar1;
  undefined4 unaff_D3;
  undefined4 uVar2;
  
  uVar1 = 0;
  uVar2 = CONCAT22((short)((uint)unaff_D3 >> 0x10),param_2._0_2_);
  while ((char)uVar2 != '\0') {
    uVar1 = *(ushort *)((int)&DAT_0000fab0 + (short)((uVar1 ^ *param_1) & 0xff) * 2) ^ uVar1 >> 8;
    param_1 = (byte *)CONCAT31(param_1._0_3_,(char)param_1 + '\x01');
    uVar2 = CONCAT31((int3)((uint)uVar2 >> 8),(char)uVar2 + -1);
  }
  return CONCAT22((short)((uint)uVar2 >> 0x10),uVar1);
}



//
// Function: memoryPatchCrcCalculate @ 0x0000fd02
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 memoryPatchCrcCalculate(void)

{
  byte bVar2;
  ushort uVar1;
  uint unaff_D3;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  
  uVar3 = unaff_D3 & 0xffffff00;
  pbVar4 = &DAT_0080d2de;
  iVar5 = 0x80d3aa;
  for (bVar2 = 0; bVar2 < _DAT_0080d44e; bVar2 = bVar2 + 1) {
    uVar3 = CONCAT31((int3)(uVar3 >> 8),*(char *)(iVar5 + 1) + (char)uVar3);
    iVar5 = iVar5 + 6;
  }
  uVar1 = 0;
  while ((char)uVar3 != '\0') {
    uVar1 = *(ushort *)((int)&DAT_0000fab0 + (short)((uVar1 ^ *pbVar4) & 0xff) * 2) ^ uVar1 >> 8;
    pbVar4 = pbVar4 + 1;
    uVar3 = CONCAT31((int3)(uVar3 >> 8),(char)uVar3 + -1);
  }
  return CONCAT22((short)(uVar3 >> 0x10),uVar1);
}



//
// Function: coldStartFuelControlSlowCycle40Coordinator @ 0x0000fd68
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort coldStartFuelControlSlowCycle40Coordinator(void)

{
  short sVar1;
  bool bVar2;
  ushort uVar3;
  ushort uVar5;
  ushort uVar6;
  uint uVar4;
  word wVar7;
  ushort unaff_D2w;
  ushort uVar8;
  int iVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  uint uVar12;
  
  wVar7 = engine_control_flags_t_008035d6.engine_operating_state & 0x800;
  if (((((engine_control_flags_t_008035d6.engine_operating_state & 0x800) == 0) ||
       (wVar7 = timing_mode_control_t_0080965a.blend_factor,
       timing_mode_control_t_0080965a.blend_factor < _DAT_00807c1e)) ||
      (wVar7 = fuel_demand_state_t_0080c9a4.command,
      fuel_demand_state_t_0080c9a4.command < _DAT_00807c26)) ||
     ((wVar7 = circular_buffer_t_0080c3fc.data_buffer_8,
      circular_buffer_t_0080c3fc.data_buffer_8 <= _DAT_00807c24 ||
      (_DAT_00807c1c <= circular_buffer_t_0080c3fc.data_buffer_8)))) {
    _DAT_008001b0 = 0;
    _DAT_00809d6a = 0;
    _DAT_00809d6e = 0;
    return wVar7;
  }
  _DAT_008001aa = circular_buffer_t_0080c3fc.data_buffer_8;
  _DAT_00800196 = circular_buffer_t_0080c3fc.data_buffer_8;
  _DAT_0080018a = circular_buffer_t_0080c3fc.data_buffer_8;
  _DAT_00800176 = circular_buffer_t_0080c3fc.data_buffer_8;
  _DAT_0080017e = fuel_demand_state_t_0080c9a4.command;
  if (_DAT_00807c28 != 0 || _DAT_00807c0e != 0) {
    if (((fault_status_registers_t_00805df2.fault_status_2 & 0x200) == 0) ||
       ((_DAT_008068c6 & 0x200) == 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) {
      if (((fault_status_registers_t_00805df2.fault_status_2 & 0x400) == 0) ||
         ((_DAT_008068c6 & 0x400) == 0)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (!bVar2) {
        if (((fault_status_registers_t_00805df2.fault_status_2 & 4) == 0) ||
           ((_DAT_008068c6 & 4) == 0)) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if (bVar2) {
LAB_0000fe82:
          if (_DAT_00807c28 == 0) goto LAB_0000fff4;
        }
        else {
          if (((fault_status_registers_t_00805df2.fault_status_2 & 8) == 0) ||
             ((_DAT_008068c6 & 8) == 0)) {
            bVar2 = false;
          }
          else {
            bVar2 = true;
          }
          if (bVar2) goto LAB_0000fe82;
        }
        if (_DAT_00807c28 == 0) {
          _DAT_008001b2 = _DAT_008092f2 + _DAT_00809258;
        }
        else {
          _DAT_008001b2 = _DAT_00809258;
        }
        _DAT_0080019e = _DAT_008001b2;
        uVar5 = lookupTableInterpolation((short *)&DAT_00800184);
        uVar10 = tableInterpolationLookup((short *)&DAT_00800190);
        uVar11 = tableInterpolationLookup((short *)&DAT_00800170);
        uVar6 = (ushort)((ulonglong)uVar11 >> 0x20);
        uVar4 = proportionalCalculation
                          ((uint)_DAT_008001b2,(uint)(ushort)((ulonglong)uVar10 >> 0x20),0x400);
        if (uVar4 < 0xbb81) {
          _DAT_00809d6c = (ushort)uVar4;
        }
        else {
          _DAT_00809d6c = 48000;
        }
        uVar3 = _DAT_00809d6c;
        if (0 < _DAT_00809d70) {
          uVar12 = 0x100;
          uVar4 = proportionalCalculation((int)_DAT_00809d70 * (uint)uVar5,0x100,0x4444);
          uVar4 = proportionalCalculation((uint)_DAT_00809d6c,(uVar4 & 0xffff) + 0x100,uVar12);
        }
        if (uVar4 < 0xbb81) {
          _DAT_00809d6c = (ushort)uVar4;
        }
        else {
          _DAT_00809d6c = 48000;
        }
        if (_DAT_00809d6c < uVar6) {
          iVar9 = 0x7fffffff;
          uVar8 = uVar6 - _DAT_00809d6c;
        }
        else {
          uVar8 = _DAT_00809d6c - uVar6;
          iVar9 = -0x80000000;
        }
        if (_DAT_00807c10 < uVar8) {
          if ((uVar3 != 0) && (uVar5 != 0)) {
            iVar9 = rpmFuelCalculation((int)(short)(uVar6 - _DAT_00809d6c),0x4444,
                                       (uint)uVar5 * (uint)uVar3);
          }
          _DAT_00809d6e = 1;
          if (iVar9 < 0xab) {
            if (iVar9 < -0xaa) {
              unaff_D2w = 0xff56;
            }
            else {
              unaff_D2w = (ushort)iVar9;
            }
          }
          else {
            unaff_D2w = 0xaa;
          }
        }
        else {
          unaff_D2w = 0;
          _DAT_00809d6e = 1;
        }
      }
    }
  }
LAB_0000fff4:
  if (_DAT_00807c28 != 0 || _DAT_00807c0e != 0) {
    if (((fault_status_registers_t_00805df2.fault_status_2 & 0x200) == 0) ||
       ((_DAT_008068c6 & 0x200) == 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) {
      if (((fault_status_registers_t_00805df2.fault_status_2 & 0x400) == 0) ||
         ((_DAT_008068c6 & 0x400) == 0)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (!bVar2) {
        if (((fault_status_registers_t_00805df2.fault_status_2 & 4) == 0) ||
           ((_DAT_008068c6 & 4) == 0)) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if ((!bVar2) || (_DAT_00807c28 != 0)) {
          if (((fault_status_registers_t_00805df2.fault_status_2 & 8) == 0) ||
             ((_DAT_008068c6 & 8) == 0)) {
            bVar2 = false;
          }
          else {
            bVar2 = true;
          }
          if ((!bVar2) || (_DAT_00807c28 != 0)) goto LAB_000101fa;
        }
      }
    }
  }
  if (((fault_status_registers_t_00805df2.sensor_fault_status & 0x2000) == 0) ||
     ((_DAT_008068c4 & 0x2000) == 0)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (!bVar2) {
    if (((fault_status_registers_t_00805df2.sensor_fault_status & 0x4000) == 0) ||
       ((_DAT_008068c4 & 0x4000) == 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) {
      if (_DAT_00807c2a == 0) {
        if (_DAT_00807c14 < _DAT_00807c12) {
          uVar4 = 0x7fffffff;
        }
        else {
          uVar4 = 0x80000000;
        }
      }
      else {
        iVar9 = rpmFuelCalculation(((uint)circular_buffer_t_0080c3fc.data_buffer_8 *
                                   (uint)fuel_demand_state_t_0080c9a4.command) / 0x1266 & 0xffff,
                                   (uint)_DAT_00807c12 - (uint)_DAT_00807c14,(uint)_DAT_00807c2a);
        uVar4 = (uint)_DAT_00807c14 + iVar9;
      }
      if ((int)uVar4 < 0x7f81) {
        if ((int)uVar4 < 0xa00) {
          uVar4 = 0xa00;
        }
      }
      else {
        uVar4 = 0x7f80;
      }
      _DAT_00809d68 = (short)uVar4;
      if ((uint)_DAT_00807c16 + (uint)_DAT_008091ea < (uVar4 & 0xffff)) {
        sVar1 = _DAT_008091ea - _DAT_00809d68;
        uVar5 = lookupTableInterpolation((short *)&DAT_008001a4);
        iVar9 = rpmFuelCalculation((uint)uVar5,(int)sVar1,0x7800);
        if (iVar9 < 0xab) {
          if (iVar9 < -0xaa) {
            unaff_D2w = 0xff56;
          }
          else {
            unaff_D2w = (ushort)iVar9;
          }
        }
        else {
          unaff_D2w = 0xaa;
        }
        _DAT_00809d6e = 2;
      }
      else {
        unaff_D2w = 0;
        _DAT_00809d6e = 2;
      }
    }
  }
LAB_000101fa:
  if ((short)unaff_D2w < (short)_DAT_00807c22) {
    _DAT_00809d6a = _DAT_00807c22;
  }
  else if (((short)unaff_D2w < 1) ||
          ((circular_buffer_t_0080c3fc.data_buffer_8 < _DAT_00807c1a &&
           (_DAT_00807c20 < circular_buffer_t_0080c3fc.data_buffer_8)))) {
    _DAT_00809d6a = unaff_D2w;
    if ((int)(uint)_DAT_00807c18 < (int)(short)unaff_D2w) {
      _DAT_00809d6a = _DAT_00807c18;
    }
  }
  else {
    _DAT_00809d6a = 0;
  }
  if (_DAT_00807c0e != 0) {
    if (((fault_status_registers_t_00805df2.fault_status_2 & 0x200) == 0) ||
       ((_DAT_008068c6 & 0x200) == 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) {
      if (((fault_status_registers_t_00805df2.fault_status_2 & 0x400) == 0) ||
         ((_DAT_008068c6 & 0x400) == 0)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (!bVar2) {
        if (((fault_status_registers_t_00805df2.fault_status_2 & 4) == 0) ||
           ((_DAT_008068c6 & 4) == 0)) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if ((!bVar2) || (_DAT_00807c28 != 0)) {
          if (((fault_status_registers_t_00805df2.fault_status_2 & 8) == 0) ||
             ((_DAT_008068c6 & 8) == 0)) {
            uVar5 = 0;
          }
          else {
            uVar5 = 1;
          }
          if (uVar5 == 0) {
            _DAT_008001b0 = 8;
            return 0;
          }
          if (_DAT_00807c28 != 0) {
            _DAT_008001b0 = 8;
            return uVar5;
          }
        }
      }
    }
  }
  if (((fault_status_registers_t_00805df2.sensor_fault_status & 0x2000) == 0) ||
     ((_DAT_008068c4 & 0x2000) == 0)) {
    uVar5 = 0;
  }
  else {
    uVar5 = 1;
  }
  if (uVar5 == 0) {
    if (((fault_status_registers_t_00805df2.sensor_fault_status & 0x4000) == 0) ||
       ((_DAT_008068c4 & 0x4000) == 0)) {
      uVar5 = 0;
    }
    else {
      uVar5 = 1;
    }
    if (uVar5 == 0) {
      _DAT_008001b0 = 8;
      return 0;
    }
  }
  _DAT_00809d6a = 0;
  _DAT_00809d6e = 0;
  _DAT_008001b0 = 0;
  return uVar5;
}



//
// Function: timingAccumulatorClampedUpdate @ 0x00010366
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void timingAccumulatorClampedUpdate(void)

{
  _DAT_00809d70 = fuel_demand_state_t_0080c9a4.limit_minimum;
  if ((short)(_DAT_00809d6a + fuel_demand_state_t_0080c9a4.limit_minimum) < 0) {
    fuel_demand_state_t_0080c9a4.limit_minimum = 0;
  }
  else {
    fuel_demand_state_t_0080c9a4.limit_minimum =
         _DAT_00809d6a + fuel_demand_state_t_0080c9a4.limit_minimum;
  }
  fuel_demand_state_t_0080c9a4.adjustment_active =
       _DAT_008001b0 | fuel_demand_state_t_0080c9a4.adjustment_active & 0xfff7;
  return;
}



//
// Function: initAncSpeedLimitAndAltitudeDerate @ 0x000103a2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initAncSpeedLimitAndAltitudeDerate(void)

{
  _DAT_0080018a = circular_buffer_t_0080c3fc.data_buffer_8;
  _DAT_00800186 = 0x807a12;
  _DAT_0080018c = 0x807a2e;
  _DAT_00800184 = 2;
  _DAT_00800196 = circular_buffer_t_0080c3fc.data_buffer_8;
  _DAT_00800192 = 0x807a4a;
  _DAT_00800190 = 2;
  _DAT_0080019e = _DAT_008001b2;
  _DAT_0080019a = 0x807a66;
  _DAT_00800198 = 2;
  _DAT_008001a0 = 0x807a6e;
  _DAT_008001aa = circular_buffer_t_0080c3fc.data_buffer_8;
  _DAT_008001a6 = &ATAAPRDF;
  _DAT_008001ac = 0x807ad8;
  _DAT_008001a4 = 2;
  _DAT_00800176 = circular_buffer_t_0080c3fc.data_buffer_8;
  _DAT_00800172 = 0x807af4;
  _DAT_00800170 = 2;
  _DAT_0080017e = fuel_demand_state_t_0080c9a4.command;
  _DAT_0080017a = 0x807b10;
  _DAT_00800178 = 2;
  _DAT_00800180 = 0x807b20;
  return;
}



//
// Function: circularBufferWriteWithStatus @ 0x00010466
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void circularBufferWriteWithStatus(void)

{
  int *piVar1;
  
  piVar1 = (int *)&DAT_00804be8;
  do {
    while( true ) {
      if ((*piVar1 == 0) || (&DAT_00804be8 + (uint)_DAT_008001c0 * 4 <= piVar1)) {
        return;
      }
      if (_DAT_008001bc != 0) break;
      *_DAT_00809d82 = *(undefined1 *)*piVar1;
      piVar1 = piVar1 + 1;
      _DAT_008001bc = 1;
    }
    _DAT_00809d82 = _DAT_00809d82 + 1;
    if (_DAT_00809d76 < _DAT_00809d82) {
      _DAT_00809d82 = _DAT_00809d72;
    }
    *_DAT_00809d82 = *(undefined1 *)*piVar1;
    piVar1 = piVar1 + 1;
    if ((_DAT_00809d82 == _DAT_00809d7a) &&
       (_DAT_00809d7a = _DAT_00809d7a + 1, _DAT_00809d76 < _DAT_00809d7a)) {
      _DAT_00809d7a = _DAT_00809d72;
    }
  } while (_DAT_00809d82 != _DAT_008001b4);
  _DAT_008001b8 = 3;
  return;
}



//
// Function: vp44_communication_state_machine @ 0x00010504
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint vp44_communication_state_machine(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 in_D0;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  
  piVar5 = (int *)&DAT_00804be8;
  uVar2 = (undefined2)((uint)in_D0 >> 0x10);
  uVar4 = CONCAT22(uVar2,_DAT_008035d4) & 0xffff0100;
  if ((_DAT_008035d4 & 0x100) != 0) {
    uVar4 = CONCAT22(uVar2,_DAT_00804bde);
    if ((_DAT_00804bde == param_1._0_2_) && (_DAT_00804be8 != 0)) {
      if (_DAT_008001be == 0) {
        if (1 < _DAT_00804be4) {
          _DAT_008001be = 1;
        }
        if ((_DAT_008001b8 == 3) && (_DAT_00804be0 == 0)) {
          _DAT_008001b8 = 0;
        }
        uVar4 = _DAT_008001b8;
        if (_DAT_008001b8 < 4) {
          uVar4 = CONCAT22((short)(_DAT_008001b8 >> 0x10),
                           (&switchD_00010596::switchdataD_0001059a)[_DAT_008001b8]);
          switch(_DAT_008001b8) {
          case 0:
            _DAT_00809d86 = 1;
            for (; (*piVar5 != 0 && (piVar5 < (int *)0x804c68)); piVar5 = piVar5 + 1) {
              _DAT_008001c0 = _DAT_008001c0 + 1;
            }
            iVar1 = _DAT_00809d72 - 0x2000U % (uint)_DAT_008001c0;
            _DAT_00809d76 = iVar1 + 0x1fff;
            uVar3 = 0x2000 / _DAT_008001c0;
            _DAT_008001c4 = (ushort)uVar3;
            _DAT_008001c2 = _DAT_008001c4 * _DAT_008001c0;
            _DAT_00809d82 = _DAT_00809d72;
            _DAT_00809d7a = _DAT_00809d72;
            _DAT_008001bc = 0;
            if (_DAT_00804be0 == 0) {
              _DAT_008001b8 = 1;
              _DAT_008001b4 = iVar1 + 0x2000;
              uVar4 = circularBufferWriteWithStatus();
            }
            else {
              if (2 < _DAT_00804be2) {
                _DAT_00804be2 = 0;
              }
              uVar4 = (uint)_DAT_00804be2;
              if (_DAT_00804be2 == 0) {
                uVar4 = 3;
                _DAT_008001b8 = 3;
              }
              else if (_DAT_00804be2 == 1) {
                _DAT_008001b8 = 2;
                _DAT_008001b4 = (_DAT_00809d72 + ((int)uVar3 >> 1) * (uint)_DAT_008001c0) - 1;
                uVar4 = circularBufferWriteWithStatus();
              }
              else if (_DAT_00804be2 == 2) {
                _DAT_008001b8 = 2;
                _DAT_008001b4 = _DAT_00809d76;
                uVar4 = circularBufferWriteWithStatus();
              }
            }
            break;
          case 1:
            if (_DAT_00804be0 == 0) {
              uVar4 = circularBufferWriteWithStatus();
            }
            else {
              if (2 < _DAT_00804be2) {
                _DAT_00804be2 = 0;
              }
              uVar4 = (uint)_DAT_00804be2;
              if (_DAT_00804be2 == 0) {
                uVar4 = 3;
                _DAT_008001b8 = 3;
              }
              else if (_DAT_00804be2 == 1) {
                _DAT_008001b8 = 2;
                _DAT_00809d7e = _DAT_00809d82 + 1;
                if (_DAT_00809d76 < _DAT_00809d7e) {
                  _DAT_00809d7e = _DAT_00809d72;
                }
                _DAT_008001b4 =
                     _DAT_00809d82 + ((int)(uint)_DAT_008001c4 >> 1) * (uint)_DAT_008001c0;
                if (_DAT_00809d76 < _DAT_008001b4) {
                  _DAT_008001b4 = _DAT_008001b4 - _DAT_008001c2;
                }
                uVar4 = circularBufferWriteWithStatus();
              }
              else if (_DAT_00804be2 == 2) {
                _DAT_008001b8 = 2;
                _DAT_008001b4 = _DAT_00809d76;
                _DAT_00809d82 = _DAT_00809d72;
                _DAT_00809d7a = _DAT_00809d72;
                _DAT_008001bc = 0;
                uVar4 = circularBufferWriteWithStatus();
              }
            }
            break;
          case 2:
            uVar4 = circularBufferWriteWithStatus();
            break;
          case 3:
            _DAT_008001c0 = 0;
            _DAT_00809d86 = 0;
          }
        }
      }
      else {
        _DAT_008001be = _DAT_008001be + 1;
        uVar4 = CONCAT22(uVar2,_DAT_008001be);
        if (_DAT_00804be4 <= _DAT_008001be) {
          _DAT_008001be = 0;
        }
      }
    }
  }
  return uVar4;
}



//
// Function: initVp44BufferAddresses @ 0x0001078e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initVp44BufferAddresses(void)

{
  _DAT_00809d72 = 0x809d8c;
  _DAT_00809d88 = &DAT_00804be8;
  return;
}



//
// Function: engineRunTimeHistogramAccumulator @ 0x000107a4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint engineRunTimeHistogramAccumulator(void)

{
  int *piVar1;
  bool bVar2;
  undefined4 in_D0;
  uint uVar3;
  byte bVar4;
  char cVar5;
  char cVar6;
  ushort *puVar7;
  undefined8 uVar8;
  
  uVar3 = CONCAT22((short)((uint)in_D0 >> 0x10),_DAT_00803618) & 0xffff0001;
  if (((_DAT_00803618 & 1) != 0) && (engine_operating_mode_t_0080c810.state != 1)) {
    if (_DAT_00804a1c == 0) {
      _DAT_00804a14 = _DAT_00809688;
    }
    if ((_DAT_00809b10 == 0) && ((_DAT_00809b14 == 0 || (_DAT_008001cc <= _DAT_00809b14)))) {
      _DAT_00804a0c = _DAT_00809688;
    }
    else if ((_DAT_00809b14 == 0) && (_DAT_008001cc <= _DAT_00809b10)) {
      _DAT_00804a10 = _DAT_00809688;
    }
    if ((circular_buffer_t_0080c3fc.data_buffer_8 < _DAT_00807852) &&
       (_DAT_00807854 <= circular_buffer_t_0080c3fc.data_buffer_8)) {
      _DAT_008001ca = _DAT_0080c9d8;
    }
    else {
      if (circular_buffer_t_0080c3fc.data_buffer_8 < _DAT_00807852) {
        _DAT_008001f0 = _DAT_00807854;
      }
      else {
        _DAT_008001f0 = _DAT_00807852;
      }
      _DAT_008001dc = _DAT_008001f0;
      if (timing_mode_control_t_0080965a.blend_factor == 0x4000) {
        uVar8 = tableInterpolationLookup((short *)&DAT_008001d6);
        _DAT_008001ca = (ushort)((ulonglong)uVar8 >> 0x20);
      }
      else if (timing_mode_control_t_0080965a.blend_factor == 0) {
        uVar8 = tableInterpolationLookup((short *)&DAT_008001ea);
        _DAT_008001ca = (ushort)((ulonglong)uVar8 >> 0x20);
      }
      else {
        uVar8 = tableInterpolationLookup((short *)&DAT_008001d6);
        _DAT_008001d2 = (ushort)((ulonglong)uVar8 >> 0x20);
        uVar8 = tableInterpolationLookup((short *)&DAT_008001ea);
        _DAT_008001d4 = (ushort)((ulonglong)uVar8 >> 0x20);
        _DAT_008001ca =
             (short)((uint)timing_mode_control_t_0080965a.blend_factor * (uint)_DAT_008001d2 >> 0xe)
             + (short)((uint)_DAT_008001d4 *
                       (0x4000 - (uint)timing_mode_control_t_0080965a.blend_factor) >> 0xe);
      }
    }
    if (_DAT_008001ca == _DAT_0080d0aa) {
      _DAT_008001c6 = (uint)_DAT_0080787a;
    }
    else {
      _DAT_008001c6 =
           (int)(((uint)fuel_demand_state_t_0080c9a4.command - (uint)_DAT_0080d0aa) * 10000) /
           (int)((uint)_DAT_008001ca - (uint)_DAT_0080d0aa);
    }
    if ((int)_DAT_008001c6 < 0) {
      _DAT_00809b18 = 0;
      if (circular_buffer_t_0080c3fc.data_buffer_8 < _DAT_00807852) {
        DAT_00809b1a = 0x31;
      }
      else {
        DAT_00809b1a = 0x32;
      }
    }
    else {
      _DAT_00809b18 = _DAT_008001c8;
      cVar6 = '\b';
      cVar5 = '\x06';
      bVar2 = false;
      bVar4 = 1;
      puVar7 = (ushort *)&DAT_0080785a;
      while ((bVar4 < 9 && (!bVar2))) {
        if (circular_buffer_t_0080c3fc.data_buffer_8 <= *puVar7) {
          bVar2 = true;
          if (bVar4 == 1) {
            cVar6 = '\x01';
          }
          else {
            cVar6 = bVar4 - 1;
          }
        }
        bVar4 = bVar4 + 1;
        puVar7 = puVar7 + 1;
      }
      bVar2 = false;
      bVar4 = 1;
      puVar7 = (ushort *)&DAT_0080786e;
      while ((bVar4 < 7 && (!bVar2))) {
        if (_DAT_008001c8 <= *puVar7) {
          bVar2 = true;
          if (bVar4 == 1) {
            cVar5 = '\x01';
          }
          else {
            cVar5 = bVar4 - 1;
          }
        }
        bVar4 = bVar4 + 1;
        puVar7 = puVar7 + 1;
      }
      DAT_00809b1a = cVar6 + ('\x06' - cVar5) * '\b';
    }
    if (_DAT_00804a1c < 3600000000) {
      piVar1 = (int *)((short)(ushort)DAT_00809b1a * 4 + 0x804aee);
      *piVar1 = *piVar1 + 1;
      _DAT_00804a1c = _DAT_00804a1c + 1;
    }
    uVar3 = _DAT_00809b10;
    if ((_DAT_00809b10 < _DAT_008001cc) && (_DAT_00809b10 != 0)) {
      DAT_00809b1b = '\x01';
    }
    else if ((_DAT_00809b10 == 0) &&
            ((_DAT_00809b14 == 0 || (uVar3 = _DAT_00809b14, _DAT_008001cc <= _DAT_00809b14)))) {
      DAT_00809b1b = '\x01';
    }
    else if (_DAT_00809b14 < _DAT_008001cc) {
      DAT_00809b1b = '\x02';
      uVar3 = _DAT_00809b14;
    }
    else {
      DAT_00809b1b = '\0';
      uVar3 = _DAT_00809b14;
    }
    if (DAT_00809b1b == '\x01') {
      uVar3 = (uint)DAT_00809b1a;
      *(int *)(&DAT_00809b1a + (short)(ushort)DAT_00809b1a * 4) =
           *(int *)(&DAT_00809b1a + (short)(ushort)DAT_00809b1a * 4) + 1;
      _DAT_00809b10 = _DAT_00809b10 + 1;
      return uVar3;
    }
    if (DAT_00809b1b == '\x02') {
      uVar3 = (uint)DAT_00809b1a;
      piVar1 = (int *)((short)(ushort)DAT_00809b1a * 4 + 0x809be4);
      *piVar1 = *piVar1 + 1;
      _DAT_00809b14 = _DAT_00809b14 + 1;
    }
  }
  return uVar3;
}



//
// Function: initHourMeterConversionData @ 0x00010ad8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initHourMeterConversionData(void)

{
  byte bVar1;
  uint *puVar2;
  uint *puVar3;
  
  _DAT_008001dc = _DAT_00807854;
  _DAT_008001d8 = 0x807f42;
  _DAT_008001d6 = 2;
  _DAT_008001e4 = 400;
  _DAT_008001e0 = 0x807f68;
  _DAT_008001de = 2;
  _DAT_008001e6 = 0x807f72;
  _DAT_008001f0 = _DAT_00807854;
  _DAT_008001ec = 0x808002;
  _DAT_008001ea = 2;
  _DAT_008001f8 = 400;
  _DAT_008001f4 = 0x808028;
  _DAT_008001f2 = 2;
  _DAT_008001fa = 0x808032;
  _DAT_008001cc = (uint)_DAT_00807856 * 36000;
  _DAT_008001d0 = _DAT_00807856 * 0x3c;
  _DAT_00809b10 = _DAT_008001cc;
  if (_DAT_00804a18 < _DAT_008001d0) {
    _DAT_00809b10 = ((uint)_DAT_00804a18 * 36000) / 0x3c;
  }
  _DAT_00809b14 = _DAT_008001cc;
  if (_DAT_00804a1a < _DAT_008001d0) {
    _DAT_00809b14 = ((uint)_DAT_00804a1a * 36000) / 0x3c;
  }
  _DAT_00809b1c = _DAT_00804a20 * 2;
  _DAT_00809be6 = _DAT_00804a86 * 2;
  bVar1 = 1;
  puVar2 = (uint *)&DAT_00809b1e;
  puVar3 = (uint *)&DAT_00809be8;
  do {
    *puVar2 = ((uint)*(ushort *)(&DAT_00804a20 + (short)(ushort)bVar1 * 2) * 36000) / 0x3c;
    *puVar3 = ((uint)*(ushort *)(&DAT_00804a86 + (short)(ushort)bVar1 * 2) * 36000) / 0x3c;
    bVar1 = bVar1 + 1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (bVar1 < 0x33);
  return;
}



//
// Function: writeHourMeterConversionData @ 0x00010c98
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void writeHourMeterConversionData(void)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  
  if (_DAT_00809b10 < _DAT_008001cc) {
    _DAT_00804a18 = (undefined2)((uint)(&DAT_00004650 + _DAT_00809b10 * 0x3c) / 36000);
  }
  else {
    _DAT_00804a18 = _DAT_008001d0;
  }
  if (_DAT_00809b14 < _DAT_008001cc) {
    _DAT_00804a1a = (undefined2)((uint)(&DAT_00004650 + _DAT_00809b14 * 0x3c) / 36000);
  }
  else {
    _DAT_00804a1a = _DAT_008001d0;
  }
  bVar1 = 1;
  piVar2 = (int *)&DAT_00809b1e;
  piVar3 = (int *)&DAT_00809be8;
  do {
    *(short *)(&DAT_00804a20 + (short)(ushort)bVar1 * 2) =
         (short)((uint)(&DAT_00004650 + *piVar2 * 0x3c) / 36000);
    *(short *)(&DAT_00804a86 + (short)(ushort)bVar1 * 2) =
         (short)((uint)(&DAT_00004650 + *piVar3 * 0x3c) / 36000);
    bVar1 = bVar1 + 1;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (bVar1 < 0x33);
  return;
}



//
// Function: canBusConfigTypeSelector @ 0x00010d78
//

undefined4 canBusConfigTypeSelector(undefined4 param_1)

{
  char cVar1;
  
  cVar1 = (char)((uint)param_1 >> 0x10);
  if (cVar1 == DAT_008084a5) {
    return 1;
  }
  if (cVar1 == DAT_008084a7) {
    return 2;
  }
  if (cVar1 == DAT_008084a9) {
    return 3;
  }
  return 4;
}



//
// Function: speedDifferenceInterpolator @ 0x00010da4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void speedDifferenceInterpolator(undefined4 param_1)

{
  undefined8 uVar1;
  undefined2 uVar2;
  
  _DAT_00800204 = param_1._0_2_;
  uVar2 = 0x80;
  uVar1 = tableInterpolationLookup((short *)&DAT_008001fe);
  safeDivideWithClamp((short)((short)((ulonglong)uVar1 >> 0x20) - (_DAT_0080022a + param_1._2_2_)) *
                      0x6400,CONCAT22(_DAT_00807c38 - _DAT_0080bda0,uVar2));
  return;
}



//
// Function: speedBasedParameterLookup @ 0x00010e02
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void speedBasedParameterLookup(void)

{
  _DAT_00800218 = _DAT_0080d092;
  _DAT_0080bd9a = lookupTableInterpolation((short *)&DAT_00800212);
  _DAT_00800218 = _DAT_00807c3c;
  _DAT_0080bd9e = lookupTableInterpolation((short *)&DAT_00800212);
  _DAT_00800218 = CRACSWAC;
  _DAT_0080bda0 = lookupTableInterpolation((short *)&DAT_00800212);
  _DAT_00800218 = CRCNDTRF;
  _DAT_0080bda2 = lookupTableInterpolation((short *)&DAT_00800212);
  _DAT_00800218 = _DAT_00807c3a;
  _DAT_0080bd9c = lookupTableInterpolation((short *)&DAT_00800212);
  return;
}



//
// Function: multiSpeedParameterInterpolation @ 0x00010e70
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void multiSpeedParameterInterpolation(void)

{
  _DAT_00800224 = _DAT_0080926e;
  _DAT_0080022a = lookupTableInterpolation((short *)&DAT_0080021e);
  speedBasedParameterLookup();
  _DAT_0080bd96 = speedDifferenceInterpolator(CONCAT22(_DAT_0080d092,_DAT_0080bd9a));
  _DAT_0080bd98 = speedDifferenceInterpolator(CONCAT22(_DAT_00807c3a,_DAT_0080bd9c));
  _DAT_0080bd90 = speedDifferenceInterpolator(CONCAT22(_DAT_00807c3c,_DAT_0080bd9e));
  _DAT_0080bd92 = speedDifferenceInterpolator(CONCAT22(CRACSWAC,_DAT_0080bda0));
  _DAT_0080bd94 = speedDifferenceInterpolator(CONCAT22(CRCNDTRF,_DAT_0080bda2));
  return;
}



//
// Function: fuelDemandPercentageCalculator @ 0x00010f08
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelDemandPercentageCalculator(void)

{
  int iVar1;
  undefined2 uVar2;
  
  _DAT_0080bd8c = _DAT_0080d0aa;
  _DAT_00800218 = CRACSWAC;
  uVar2 = 0x80;
  _DAT_0080bda0 = lookupTableInterpolation((short *)&DAT_00800212);
  iVar1 = safeDivideWithClamp(((int)(short)fuel_demand_state_t_0080c9a4.command - (int)_DAT_0080bd8c
                              ) * 0x6400,CONCAT22(_DAT_00807c38 - _DAT_0080bda0,uVar2));
  _DAT_0080bd8e = (short)iVar1;
  return;
}



//
// Function: initIntakeManifoldTemperatureLimits @ 0x00010f76
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initIntakeManifoldTemperatureLimits(void)

{
  _DAT_008001fe = 2;
  _DAT_00800200 = 0x807f42;
  _DAT_0080020c = 400;
  _DAT_00800206 = 2;
  _DAT_00800208 = 0x807f68;
  _DAT_0080020e = 0x807f72;
  _DAT_0080021e = 2;
  _DAT_00800220 = 0x808862;
  _DAT_00800226 = 0x808876;
  _DAT_00800212 = 2;
  _DAT_00800214 = 0x80883a;
  _DAT_0080021a = 0x80884e;
  speedBasedParameterLookup();
  return;
}



//
// Function: diagnosticCodeDebounceHandler @ 0x00010fee
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticCodeDebounceHandler(undefined4 param_1)

{
  int iVar1;
  short sVar2;
  undefined4 unaff_D2;
  byte bVar3;
  
  bVar3 = (byte)((uint)param_1 >> 0x10);
  if ((((*(byte *)((short)((param_1._0_2_ & 0xff) * 5) * 2 + 0x804fcc) & 1) == 0) &&
      (*(char *)((uint)bVar3 * 6 + 0x8065d1) != '\0')) &&
     ((&DAT_00804fcd)[(short)((param_1._0_2_ & 0xff) * 5) * 2] != '\0')) {
    iVar1 = (int)(short)((ushort)*(byte *)((uint)bVar3 * 6 + 0x8065d1) << 3);
    if (((*(int *)((short)((param_1._0_2_ & 0xff) * 5) * 2 + 0x804fc8) == 0) &&
        (*(uint *)(iVar1 + 0x806354) <=
         (uint)(_DAT_0080d4c4 - *(int *)((short)((param_1._0_2_ & 0xff) * 5) * 2 + 0x804fc4)))) ||
       ((*(int *)((short)((param_1._0_2_ & 0xff) * 5) * 2 + 0x804fc8) != 0 &&
        (*(uint *)(iVar1 + 0x806358) <=
         (uint)(_DAT_0080d4c4 - *(int *)((short)((param_1._0_2_ & 0xff) * 5) * 2 + 0x804fc8)))))) {
      sVar2 = (param_1._0_2_ & 0xff) * 10;
      *(int *)(sVar2 + 0x804fc8) = _DAT_0080d4c4;
      if ((&DAT_00804fcd)[sVar2] != '\0') {
        (&DAT_00804fcd)[sVar2] = (&DAT_00804fcd)[sVar2] + -1;
      }
      if ((&DAT_00804fcd)[sVar2] == '\0') {
        diagnosticTableEntryClear
                  (CONCAT22(param_1._0_2_,(short)((uint)unaff_D2 >> 0x10)) & 0xffffff);
        if (((&DAT_008065d0)[(uint)bVar3 * 6] != '\0') &&
           ((*(ushort *)(&DAT_008065ce + (uint)bVar3 * 6) & 0x40) == 0)) {
          _DAT_00804f42 = _DAT_00804f42 + -1;
        }
        DAT_00804e9c = DAT_00804e9c + -1;
        _DAT_00804efc = _DAT_00804efc + -1;
        (&DAT_00804e9c)[_DAT_00800230] = (&DAT_00804e9c)[_DAT_00804f3e];
        iVar1 = (int)_DAT_00804f3e;
        _DAT_00804f3e = _DAT_00804f3e + -1;
        *(undefined2 *)(&DAT_00804efc + _DAT_00800230 * 2) =
             *(undefined2 *)(&DAT_00804efc + iVar1 * 2);
        _DAT_00800230 = _DAT_00800230 + -1;
      }
    }
  }
  return;
}



//
// Function: phase2_sensor_data_processor @ 0x00011060
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void phase2_sensor_data_processor(void)

{
  int iVar1;
  short sVar2;
  short in_D0w;
  byte unaff_D2b;
  int unaff_A3;
  short *unaff_A4;
  int *unaff_A5;
  undefined2 in_stack_00000000;
  
  if (((*(int *)((short)((ushort)unaff_D2b * 5) * 2 + 0x804fc8) == 0) &&
      (*(uint *)(in_D0w + 0x806354) <=
       (uint)(*unaff_A5 - *(int *)((short)((ushort)unaff_D2b * 5) * 2 + 0x804fc4)))) ||
     ((*(int *)((short)((ushort)unaff_D2b * 5) * 2 + 0x804fc8) != 0 &&
      (*(uint *)(in_D0w + 0x806358) <=
       (uint)(*unaff_A5 - *(int *)((short)((ushort)unaff_D2b * 5) * 2 + 0x804fc8)))))) {
    sVar2 = (ushort)unaff_D2b * 10;
    *(int *)(sVar2 + 0x804fc8) = *unaff_A5;
    if ((&DAT_00804fcd)[sVar2] != '\0') {
      (&DAT_00804fcd)[sVar2] = (&DAT_00804fcd)[sVar2] + -1;
    }
    if ((&DAT_00804fcd)[sVar2] == '\0') {
      diagnosticTableEntryClear((uint)CONCAT12(unaff_D2b,in_stack_00000000));
      if ((*(char *)(unaff_A3 + 4 + (uint)unaff_D2b * 6) != '\0') &&
         ((*(ushort *)(unaff_A3 + 2 + (uint)unaff_D2b * 6) & 0x40) == 0)) {
        _DAT_00804f42 = _DAT_00804f42 + -1;
      }
      DAT_00804e9c = DAT_00804e9c + -1;
      _DAT_00804efc = _DAT_00804efc + -1;
      (&DAT_00804e9c)[*unaff_A4] = (&DAT_00804e9c)[_DAT_00804f3e];
      iVar1 = (int)_DAT_00804f3e;
      _DAT_00804f3e = _DAT_00804f3e + -1;
      *(undefined2 *)(&DAT_00804efc + *unaff_A4 * 2) = *(undefined2 *)(&DAT_00804efc + iVar1 * 2);
      *unaff_A4 = *unaff_A4 + -1;
    }
  }
  return;
}



//
// Function: diagnosticQueueIterator @ 0x000111a2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticQueueIterator(void)

{
  ushort uVar1;
  uint uVar2;
  uint unaff_D2;
  
  uVar2 = unaff_D2 >> 0x10;
  uVar1 = _DAT_00800230 + 1;
  if (_DAT_00804f3e < uVar1) {
    _DAT_00800230 = 0;
  }
  else {
    unaff_D2 = (uint)(byte)(&DAT_00804e9c)[(short)uVar1];
    _DAT_00800230 = uVar1;
  }
  diagnosticCodeDebounceHandler(CONCAT22(CONCAT11((char)(uVar1 >> 8),(char)unaff_D2),(short)uVar2));
  return;
}



//
// Function: oldestDiagnosticTimestampSearch @ 0x000111de
//

short oldestDiagnosticTimestampSearch(undefined4 param_1)

{
  short sVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  short sVar5;
  
  uVar4 = 0xffffffff;
  sVar5 = -1;
  sVar2 = 0;
  sVar3 = 0;
  do {
    sVar1 = *(short *)(&DAT_00805676 + sVar3) * 10;
    if ((*(byte *)(sVar1 + 0x804fcc) == param_1._0_2_) && (*(uint *)(sVar1 + 0x804fc4) < uVar4)) {
      uVar4 = *(uint *)(sVar1 + 0x804fc4);
      sVar5 = sVar2;
    }
    sVar3 = sVar3 + 0x30;
    sVar2 = sVar2 + 1;
  } while (sVar2 < 0x14);
  return sVar5;
}



//
// Function: diagnosticCodeRegistrar @ 0x0001124a
//

void diagnosticCodeRegistrar(undefined4 param_1)

{
  ushort uVar1;
  undefined4 unaff_D2;
  short sVar2;
  short sVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((uint)unaff_D2 >> 0x10);
  sVar2 = 0;
  sVar3 = 0;
  do {
    if (param_1._0_2_ == *(short *)(&DAT_00805676 + sVar3)) {
      diagnosticTableSnapshotCapture(CONCAT22(sVar2,param_1._0_2_));
      return;
    }
    sVar3 = sVar3 + 0x30;
    sVar2 = sVar2 + 1;
  } while (sVar2 < 0x14);
  sVar2 = 0;
  sVar3 = 0;
  do {
    if (*(short *)(&DAT_00805676 + sVar3) == 0x7d) {
      diagnosticTableSnapshotCapture(CONCAT22(sVar2,param_1._0_2_));
      return;
    }
    sVar3 = sVar3 + 0x30;
    sVar2 = sVar2 + 1;
  } while (sVar2 < 0x14);
  uVar1 = oldestDiagnosticTimestampSearch(CONCAT22(2,uVar4));
  if (uVar1 < 0x14) {
    sVar2 = *(short *)(&DAT_00805676 + (short)(uVar1 * 6) * 8);
    diagnosticTableSnapshotCapture(CONCAT22(uVar1,param_1._0_2_));
    *(undefined1 *)((short)(sVar2 * 5) * 2 + 0x804fcc) = 0;
    return;
  }
  uVar1 = oldestDiagnosticTimestampSearch(CONCAT22(3,uVar4));
  if (uVar1 < 0x14) {
    sVar2 = *(short *)(&DAT_00805676 + (short)(uVar1 * 6) * 8);
    diagnosticTableSnapshotCapture(CONCAT22(uVar1,param_1._0_2_));
    *(undefined1 *)((short)(sVar2 * 5) * 2 + 0x804fcc) = 1;
  }
  return;
}



//
// Function: diagnosticCodeClearHandler @ 0x0001133c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticCodeClearHandler(void)

{
  int iVar1;
  bool bVar2;
  undefined4 unaff_D2;
  byte bVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((uint)unaff_D2 >> 0x10);
  if ((_DAT_0080d492 != 0) && (_DAT_0080d492 < 0x7d)) {
    bVar2 = false;
    bVar3 = 0;
    while (!bVar2) {
      bVar3 = bVar3 + 1;
      if ((uint)DAT_00804e9c == bVar3 - 1) {
        bVar2 = true;
      }
      else if ((&DAT_00804e9c)[(short)(ushort)bVar3] == _DAT_0080d492) {
        if (((&DAT_008065d0)[(uint)_DAT_0080d492 * 6] != '\0') &&
           ((*(ushort *)(&DAT_008065ce + (uint)_DAT_0080d492 * 6) & 0x40) == 0)) {
          _DAT_00804f42 = _DAT_00804f42 + -1;
        }
        bVar2 = true;
        DAT_00804e9c = DAT_00804e9c - 1;
        _DAT_00804efc = _DAT_00804efc + -1;
        (&DAT_00804e9c)[(short)(ushort)bVar3] = (&DAT_00804e9c)[_DAT_00804f3e];
        iVar1 = (int)_DAT_00804f3e;
        _DAT_00804f3e = _DAT_00804f3e + -1;
        *(undefined2 *)(&DAT_00804efc + (short)(ushort)bVar3 * 2) =
             *(undefined2 *)(&DAT_00804efc + iVar1 * 2);
        diagnosticTableEntryClear(CONCAT22(_DAT_0080d492,uVar4));
      }
    }
    _DAT_0080d492 = 0;
    return;
  }
  if (_DAT_0080d492 == 0) {
    for (bVar3 = 1; bVar3 <= DAT_00804e9c; bVar3 = bVar3 + 1) {
      diagnosticTableEntryClear((uint)CONCAT12((&DAT_00804e9c)[(short)(ushort)bVar3],uVar4));
    }
    DAT_00804e9c = 0;
    _DAT_00804efc = 0;
    _DAT_00804f3e = 0;
    _DAT_00804f42 = 0;
    _DAT_0080d492 = 0;
  }
  return;
}



//
// Function: diagnosticCodeMaskedClear @ 0x0001147c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticCodeMaskedClear(void)

{
  int iVar1;
  short sVar2;
  undefined4 unaff_D2;
  byte bVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((uint)unaff_D2 >> 0x10);
  if ((_DAT_0080d48e & 0xc0) == 0x40) {
    for (bVar3 = 1; bVar3 <= DAT_00804e9c; bVar3 = bVar3 + 1) {
      sVar2 = (ushort)(&DAT_00804e9c)[(short)(ushort)bVar3] * 6;
      if (((byte)(&DAT_008065d0)[sVar2] == _DAT_0080d492) &&
         (((int)(uint)*(ushort *)(&DAT_008065ce + sVar2) >> 7 & 0x3fU) == (_DAT_0080d48e & 0x3f))) {
        diagnosticTableEntryClear((uint)CONCAT12((&DAT_00804e9c)[(short)(ushort)bVar3],uVar4));
        (&DAT_00804e9c)[(short)(ushort)bVar3] = (&DAT_00804e9c)[_DAT_00804f3e];
        iVar1 = (int)_DAT_00804f3e;
        _DAT_00804f3e = _DAT_00804f3e + -1;
        *(undefined2 *)(&DAT_00804efc + (short)(ushort)bVar3 * 2) =
             *(undefined2 *)(&DAT_00804efc + iVar1 * 2);
        DAT_00804e9c = DAT_00804e9c - 1;
        _DAT_00804efc = _DAT_00804efc + -1;
        bVar3 = bVar3 - 1;
      }
    }
    _DAT_0080d492 = 0;
    return;
  }
  for (bVar3 = 1; bVar3 <= DAT_00804e9c; bVar3 = bVar3 + 1) {
    diagnosticTableEntryClear((uint)CONCAT12((&DAT_00804e9c)[(short)(ushort)bVar3],uVar4));
  }
  DAT_00804e9c = 0;
  _DAT_00804efc = 0;
  _DAT_00804f3e = 0;
  _DAT_00804f42 = 0;
  _DAT_0080d492 = 0;
  return;
}



//
// Function: diagnosticStateMachineProcessor @ 0x000115b2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticStateMachineProcessor(void)

{
  int iVar1;
  ushort uVar2;
  ushort uVar3;
  bool bVar4;
  undefined4 unaff_D2;
  byte bVar5;
  ushort uVar6;
  ushort uVar7;
  undefined2 uVar8;
  
  uVar8 = (undefined2)((uint)unaff_D2 >> 0x10);
  uVar3 = (&fault_latch_registers_t_00805e32.sensor_fault_latch)[_DAT_00800232] |
          (&fault_status_registers_t_00805df2.sensor_fault_status)[_DAT_00800232];
  (&fault_latch_registers_t_00805e32.sensor_fault_latch)[_DAT_00800232] = 0;
  uVar6 = 1;
  uVar7 = 0;
  do {
    if ((uVar6 & uVar3) == 0) {
      if (((((uVar6 & *(ushort *)(&DAT_00805e72 + _DAT_00800232 * 2)) != 0) &&
           (uVar2 = *(ushort *)((short)(uVar7 + _DAT_00800232 * 0x10) * 2 + 0x806374), uVar2 < 0x7d)
           ) && ((uVar6 & *(ushort *)(&DAT_008068c4 + _DAT_00800232 * 2)) != 0)) &&
         ((*(char *)((short)uVar2 + 0x804f46) != '\0' &&
          (*(char *)((short)uVar2 + 0x804f46) = *(char *)((short)uVar2 + 0x804f46) + -1,
          *(char *)((short)uVar2 + 0x804f46) == '\0')))) {
        *(undefined1 *)((short)(uVar2 * 5) * 2 + 0x804fcc) = 2;
        *(undefined4 *)((short)(uVar2 * 5) * 2 + 0x804fc4) = _DAT_0080d4c4;
        bVar4 = false;
        bVar5 = 0;
        while (!bVar4) {
          bVar5 = bVar5 + 1;
          if ((uint)DAT_00804e7c == bVar5 - 1) {
            bVar4 = true;
          }
          else if ((&DAT_00804e7c)[(short)(ushort)bVar5] == uVar2) {
            bVar4 = true;
            if (((&DAT_008065d0)[(uint)uVar2 * 6] != '\0') &&
               ((*(ushort *)(&DAT_008065ce + (uint)uVar2 * 6) & 0x40) == 0)) {
              _DAT_00804f40 = _DAT_00804f40 + -1;
              circularBufferPush(&CMECTR,CONCAT22(uVar2,uVar8) & 0xffffff);
            }
            DAT_00804e7c = DAT_00804e7c - 1;
            _DAT_00804ebc = _DAT_00804ebc + -1;
            (&DAT_00804e7c)[(short)(ushort)bVar5] = (&DAT_00804e7c)[_DAT_00804f3c];
            iVar1 = (int)_DAT_00804f3c;
            _DAT_00804f3c = _DAT_00804f3c + -1;
            *(undefined2 *)(&DAT_00804ebc + (short)(ushort)bVar5 * 2) =
                 *(undefined2 *)(&DAT_00804ebc + iVar1 * 2);
          }
        }
        if (DAT_00804e9c != 0x1f) {
          DAT_00804e9c = DAT_00804e9c + 1;
          _DAT_00804efc = _DAT_00804efc + 1;
          _DAT_00804f3e = _DAT_00804f3e + 1;
          (&DAT_00804e9c)[_DAT_00804f3e] = (char)uVar2;
          *(undefined2 *)(&DAT_00804efc + _DAT_00804f3e * 2) =
               *(undefined2 *)(&DAT_008065cc + (uint)uVar2 * 6);
          if (((&DAT_008065d0)[(uint)uVar2 * 6] != '\0') &&
             ((*(ushort *)(&DAT_008065ce + (uint)uVar2 * 6) & 0x40) == 0)) {
            _DAT_00804f42 = _DAT_00804f42 + 1;
          }
        }
        _DAT_00804f44 = _DAT_00804f44 + -1;
      }
    }
    else {
      uVar2 = *(ushort *)((short)(uVar7 + _DAT_00800232 * 0x10) * 2 + 0x806374);
      if ((((uVar2 < 0x7d) && ((uVar6 & *(ushort *)(&DAT_00805e72 + _DAT_00800232 * 2)) == 0)) &&
          (DAT_00804e7c != 0x1f)) && ((uVar6 & *(ushort *)(&DAT_008068c4 + _DAT_00800232 * 2)) != 0)
         ) {
        if ((&DAT_00804fcd)[(short)(uVar2 * 5) * 2] != -1) {
          (&DAT_00804fcd)[(short)(uVar2 * 5) * 2] = (&DAT_00804fcd)[(short)(uVar2 * 5) * 2] + '\x01'
          ;
        }
        if (*(char *)((short)uVar2 + 0x804f46) == '\0') {
          diagnosticCodeRegistrar(CONCAT22(uVar2,uVar8));
          *(undefined1 *)((short)(uVar2 * 5) * 2 + 0x804fcc) = 3;
          *(undefined4 *)((short)(uVar2 * 5) * 2 + 0x804fc4) = _DAT_0080d4c4;
          *(undefined4 *)((short)(uVar2 * 5) * 2 + 0x804fc8) = 0;
          bVar4 = false;
          bVar5 = 0;
          while (!bVar4) {
            bVar5 = bVar5 + 1;
            if ((uint)DAT_00804e9c == bVar5 - 1) {
              bVar4 = true;
            }
            else if ((&DAT_00804e9c)[(short)(ushort)bVar5] == uVar2) {
              bVar4 = true;
              if (((&DAT_008065d0)[(uint)uVar2 * 6] != '\0') &&
                 ((*(ushort *)(&DAT_008065ce + (uint)uVar2 * 6) & 0x40) == 0)) {
                _DAT_00804f42 = _DAT_00804f42 + -1;
              }
              DAT_00804e9c = DAT_00804e9c - 1;
              _DAT_00804efc = _DAT_00804efc + -1;
              (&DAT_00804e9c)[(short)(ushort)bVar5] = (&DAT_00804e9c)[_DAT_00804f3e];
              iVar1 = (int)_DAT_00804f3e;
              _DAT_00804f3e = _DAT_00804f3e + -1;
              *(undefined2 *)(&DAT_00804efc + (short)(ushort)bVar5 * 2) =
                   *(undefined2 *)(&DAT_00804efc + iVar1 * 2);
            }
          }
          DAT_00804e7c = DAT_00804e7c + 1;
          _DAT_00804ebc = _DAT_00804ebc + 1;
          _DAT_00804f3c = _DAT_00804f3c + 1;
          (&DAT_00804e7c)[_DAT_00804f3c] = (char)uVar2;
          *(undefined2 *)(&DAT_00804ebc + _DAT_00804f3c * 2) =
               *(undefined2 *)(&DAT_008065cc + (uint)uVar2 * 6);
          if (((&DAT_008065d0)[(uint)uVar2 * 6] != '\0') &&
             ((*(ushort *)(&DAT_008065ce + (uint)uVar2 * 6) & 0x40) == 0)) {
            _DAT_00804f40 = _DAT_00804f40 + 1;
            circularBufferPush(&CMECTR,(uint)(uint3)(CONCAT12((char)uVar2,uVar8) | 0x800000));
          }
          _DAT_00804f44 = _DAT_00804f44 + 1;
        }
        if (*(char *)((short)uVar2 + 0x804f46) != -1) {
          *(char *)((short)uVar2 + 0x804f46) = *(char *)((short)uVar2 + 0x804f46) + '\x01';
        }
      }
    }
    uVar6 = uVar6 * 2;
    uVar7 = uVar7 + 1;
  } while (uVar7 < 0x10);
  *(ushort *)(&DAT_00805e72 + _DAT_00800232 * 2) = uVar3;
  return;
}



//
// Function: faultFlagScannerAndProcessor @ 0x00011a0a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void faultFlagScannerAndProcessor(void)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  ushort *puVar4;
  
  for (iVar2 = 0;
      ((((&fault_status_registers_t_00805df2.sensor_fault_status)[(short)_DAT_00800232] == 0 &&
        ((&fault_latch_registers_t_00805e32.sensor_fault_latch)[(short)_DAT_00800232] == 0)) &&
       (*(short *)(&DAT_00805e72 + (short)_DAT_00800232 * 2) == 0)) && (iVar2 < 0x20));
      iVar2 = iVar2 + 1) {
    _DAT_00800232 = _DAT_00800232 + 1;
    if (0x1f < _DAT_00800232) {
      _DAT_00800232 = 0;
    }
  }
  if (iVar2 < 0x20) {
    diagnosticStateMachineProcessor();
    _DAT_00800232 = _DAT_00800232 + 1;
    if (0x1f < _DAT_00800232) {
      _DAT_00800232 = 0;
    }
  }
  if ((_DAT_0080d48c & 1) == 0) {
    if ((_DAT_0080d48c & 2) != 0) {
      diagnosticCodeMaskedClear();
      _DAT_0080d48c = 0;
    }
  }
  else {
    diagnosticCodeClearHandler();
    _DAT_0080d48c = 0;
  }
  if (0x18 < (uint)(_DAT_0080d4c4 - _DAT_0080022c)) {
    uVar1 = 1;
    uVar3 = 0;
    puVar4 = (ushort *)&DAT_008077c8;
    do {
      if (((uint)(byte)(&DAT_0080bdc6)[(int)(uint)*puVar4 >> 3] & 1 << (*puVar4 & 7)) == 0) {
        _DAT_0080bdc0 = ~uVar1 & _DAT_0080bdc0;
      }
      else {
        _DAT_0080bdc0 = uVar1 | _DAT_0080bdc0;
      }
      uVar1 = uVar1 * 2;
      puVar4 = puVar4 + 1;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x10);
    uVar1 = 1;
    uVar3 = 0;
    puVar4 = (ushort *)&DAT_008077e8;
    do {
      if (((uint)(byte)(&DAT_0080bdc6)[(int)(uint)*puVar4 >> 3] & 1 << (*puVar4 & 7)) == 0) {
        _DAT_0080bdc2 = ~uVar1 & _DAT_0080bdc2;
      }
      else {
        _DAT_0080bdc2 = uVar1 | _DAT_0080bdc2;
      }
      uVar1 = uVar1 * 2;
      puVar4 = puVar4 + 1;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x10);
    uVar1 = 1;
    uVar3 = 0;
    puVar4 = (ushort *)&DAT_00807808;
    do {
      if (((uint)(byte)(&DAT_0080bdc6)[(int)(uint)*puVar4 >> 3] & 1 << (*puVar4 & 7)) == 0) {
        _DAT_0080bdc4 = ~uVar1 & _DAT_0080bdc4;
      }
      else {
        _DAT_0080bdc4 = uVar1 | _DAT_0080bdc4;
      }
      uVar1 = uVar1 * 2;
      puVar4 = puVar4 + 1;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x10);
    diagnosticQueueIterator();
    _DAT_0080022c = _DAT_0080d4c4;
  }
  return;
}



//
// Function: insitePidDtcHandler @ 0x00011ba0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void insitePidDtcHandler(undefined4 param_1)

{
  bool bVar1;
  short sVar2;
  byte bVar3;
  undefined2 *puVar4;
  
  bVar1 = false;
  _DAT_0080d490 = 0;
  puVar4 = (undefined2 *)&DAT_008065cc;
  sVar2 = 0;
  for (bVar3 = 0; (!bVar1 && (bVar3 < 0x7d)); bVar3 = bVar3 + 1) {
    if (((char)((uint)param_1 >> 0x10) == *(char *)(puVar4 + 2)) &&
       (((_DAT_0080d48e & 0x3f) == ((int)(uint)(ushort)puVar4[1] >> 7 & 0x3fU) &&
        ((&DAT_00804fcd)[sVar2] != '\0')))) {
      _DAT_0080d490 = *puVar4;
      bVar1 = true;
    }
    sVar2 = sVar2 + 10;
    puVar4 = puVar4 + 3;
  }
  return;
}



//
// Function: initHourMeterSystem @ 0x00011c0c
//

void initHourMeterSystem(void)

{
  undefined2 in_stack_00000000;
  
  circularBufferInit(&CMECTR,0x80bdb6,CONCAT22(10,in_stack_00000000));
  return;
}



//
// Function: vp44_status_data_collector @ 0x00011c28
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort vp44_status_data_collector(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_D2;
  short local_12;
  uint local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = CONCAT13(DAT_00ffd003,CONCAT12(DAT_00ffd002,CONCAT11(DAT_00ffd001,DAT_00ffd000)));
  local_c._1_3_ = (uint3)CONCAT11(DAT_00ffd007,DAT_00ffd005);
  local_c = CONCAT13(DAT_00fffa11,local_c._1_3_);
  local_10 = (uint)DAT_00fffa19;
  DAT_0080bde4 = DAT_00ffd000;
  DAT_0080bde5 = DAT_00ffd001;
  DAT_0080bde6 = DAT_00ffd002;
  DAT_0080bde7 = DAT_00ffd003;
  DAT_0080bde8 = DAT_00ffd005;
  DAT_0080bde9 = DAT_00ffd007;
  DAT_0080bdea = 0;
  DAT_0080bdeb = DAT_00fffa11;
  DAT_0080bdec = DAT_00fffa19;
  *(uint *)(&DAT_00800244 + (short)(ushort)DAT_00800242 * 4) = _DAT_00807c72 ^ local_8;
  *(uint *)(&DAT_00800254 + (short)(ushort)DAT_00800242 * 4) = _DAT_00807c76 ^ local_c;
  *(uint *)(&DAT_00800264 + (short)(ushort)DAT_00800242 * 4) = _CRGNVSHY ^ local_10;
  if ((_DAT_00803614 & 0x400) != 0) {
    *(uint *)(&DAT_00800244 + (short)(ushort)DAT_00800242 * 4) =
         *(uint *)(&DAT_00800244 + (short)(ushort)DAT_00800242 * 4) ^ 0x400;
  }
  if ((_DAT_00803614 & 0x800) != 0) {
    *(uint *)(&DAT_00800244 + (short)(ushort)DAT_00800242 * 4) =
         *(uint *)(&DAT_00800244 + (short)(ushort)DAT_00800242 * 4) ^ 0x800;
  }
  if ((_DAT_00803616 & 1) != 0) {
    *(uint *)(&DAT_00800244 + (short)(ushort)DAT_00800242 * 4) =
         *(uint *)(&DAT_00800244 + (short)(ushort)DAT_00800242 * 4) ^ 2;
  }
  if ((_DAT_00803616 & 2) != 0) {
    *(uint *)(&DAT_00800244 + (short)(ushort)DAT_00800242 * 4) =
         *(uint *)(&DAT_00800244 + (short)(ushort)DAT_00800242 * 4) ^ 4;
  }
  if ((_DAT_00803616 & 4) != 0) {
    *(uint *)(&DAT_00800244 + (short)(ushort)DAT_00800242 * 4) =
         *(uint *)(&DAT_00800244 + (short)(ushort)DAT_00800242 * 4) ^ 8;
  }
  uVar2 = _DAT_00800250 | _DAT_0080024c | _DAT_00800248 | _DAT_00800244;
  uVar1 = _DAT_00800250 & _DAT_0080024c & _DAT_00800248 & _DAT_00800244;
  local_8._3_1_ = (byte)uVar2;
  local_c._3_1_ = (byte)uVar1;
  DAT_0080bdc6 = ((byte)local_c | (byte)local_8 & DAT_0080bdc6) & ~_DAT_0080023e[1] |
                 DAT_0080378a & _DAT_0080023e[1];
  local_8._2_1_ = (byte)(uVar2 >> 8);
  local_c._2_1_ = (byte)(uVar1 >> 8);
  DAT_0080bdc7 = *_DAT_0080023e & DAT_0080378b |
                 ~*_DAT_0080023e & (local_c._2_1_ | local_8._2_1_ & DAT_0080bdc7);
  local_8._1_1_ = (byte)(uVar2 >> 0x10);
  local_c._1_1_ = (byte)(uVar1 >> 0x10);
  DAT_0080bdc8 = (local_c._1_1_ | local_8._1_1_ & DAT_0080bdc8) & ~_DAT_0080023e[3] |
                 DAT_0080378c & _DAT_0080023e[3];
  local_8._0_1_ = (byte)(uVar2 >> 0x18);
  local_c._0_1_ = (byte)(uVar1 >> 0x18);
  DAT_0080bdc9 = DAT_0080378d & _DAT_0080023e[2] |
                 ~_DAT_0080023e[2] & (local_c._0_1_ | local_8._0_1_ & DAT_0080bdc9);
  uVar2 = _DAT_00800260 | _DAT_0080025c | _DAT_00800258 | _DAT_00800254;
  uVar1 = _DAT_00800260 & _DAT_0080025c & _DAT_00800258 & _DAT_00800254;
  local_8._3_1_ = (byte)uVar2;
  local_c._3_1_ = (byte)uVar1;
  DAT_0080bdca = ((byte)local_c | (byte)local_8 & DAT_0080bdca) & ~_DAT_0080023e[5] |
                 DAT_0080378e & _DAT_0080023e[5];
  local_8._2_1_ = (byte)(uVar2 >> 8);
  local_c._2_1_ = (byte)(uVar1 >> 8);
  DAT_0080bdcb = DAT_0080378f & _DAT_0080023e[4] |
                 ~_DAT_0080023e[4] & (local_c._2_1_ | local_8._2_1_ & DAT_0080bdcb);
  if (_DAT_0080374e != 0) {
    local_8._1_1_ = (byte)(uVar2 >> 0x10);
    local_c._1_1_ = (byte)(uVar1 >> 0x10);
    DAT_0080bdcc = (local_c._1_1_ | local_8._1_1_ & DAT_0080bdcc) & ~_DAT_0080023e[7] |
                   DAT_00803790 & _DAT_0080023e[7];
  }
  local_8._0_1_ = (byte)(uVar2 >> 0x18);
  local_c._0_1_ = (byte)(uVar1 >> 0x18);
  DAT_0080bdcd = (local_c._0_1_ | local_8._0_1_ & DAT_0080bdcd) & ~_DAT_0080023e[6] |
                 DAT_00803791 & _DAT_0080023e[6];
  local_8 = _DAT_00800270 | _DAT_0080026c | _DAT_00800268 | _DAT_00800264;
  local_c = _DAT_00800270 & _DAT_0080026c & _DAT_00800268 & _DAT_00800264;
  DAT_0080bdce = ((byte)local_c | (byte)local_8 & DAT_0080bdce) & ~_DAT_0080023e[9] |
                 DAT_00803792 & _DAT_0080023e[9];
  if ((_DAT_00800234 != 0) && ((DAT_0080bdc6 & 1) == 0)) {
    local_12 = _DAT_00803678 + 1;
    parameterCircularBufferWrite
              (0x803678,(undefined1 *)&local_12,CONCAT22(2,(short)((uint)unaff_D2 >> 0x10)));
  }
  _DAT_00800234 = (byte)-((DAT_0080bdc6 & 1) != 0) & 1;
  if (_DAT_0080374e != 0) {
    if ((DAT_0080bdc6 & 8) == 0) {
      DAT_0080bdcc = DAT_0080bdcc & 0xef;
    }
    else {
      DAT_0080bdcc = DAT_0080bdcc | 0x10;
    }
    if ((DAT_0080bdc6 & 4) == 0) {
      DAT_0080bdcc = DAT_0080bdcc & 0xfb;
    }
    else {
      DAT_0080bdcc = DAT_0080bdcc | 4;
    }
    if ((DAT_0080bdc6 & 2) == 0) {
      DAT_0080bdcc = DAT_0080bdcc & 0xfe;
    }
    else {
      DAT_0080bdcc = DAT_0080bdcc | 1;
    }
    if (((DAT_0080bdc6 & 2) == 0) || ((DAT_0080bdc6 & 4) == 0)) {
      DAT_0080bdcc = DAT_0080bdcc & 0xdf;
    }
    else {
      DAT_0080bdcc = DAT_0080bdcc & 0xfa | 0x20;
    }
    if ((DAT_0080bdc6 & 4) == 0) {
      _DAT_00800236 = 0;
      if (_DAT_0080374c == 1) {
        DAT_0080bdcc = DAT_0080bdcc & 0xfd;
      }
      else {
        DAT_0080bdcc = DAT_0080bdcc & 0xf7;
      }
    }
    else {
      _DAT_00800236 = _DAT_00800236 + 1;
      if ((0x18 < _DAT_00800236) && (_DAT_00800236 = 0x19, (DAT_0080bdcc & 0x20) == 0)) {
        if (_DAT_0080374c == 1) {
          DAT_0080bdcc = DAT_0080bdcc | 2;
        }
        else {
          DAT_0080bdcc = DAT_0080bdcc | 8;
        }
      }
    }
    if ((DAT_0080bdc6 & 2) == 0) {
      _DAT_00800238 = 0;
      if (_DAT_0080374c == 1) {
        DAT_0080bdcc = DAT_0080bdcc & 0xf7;
      }
      else {
        DAT_0080bdcc = DAT_0080bdcc & 0xfd;
      }
    }
    else {
      _DAT_00800238 = _DAT_00800238 + 1;
      if ((0x18 < _DAT_00800238) && (_DAT_00800238 = 0x19, (DAT_0080bdcc & 0x20) == 0)) {
        if (_DAT_0080374c == 1) {
          DAT_0080bdcc = DAT_0080bdcc | 8;
        }
        else {
          DAT_0080bdcc = DAT_0080bdcc | 2;
        }
      }
    }
  }
  if (((DAT_0080bdc9 & 1) != 0) == ((DAT_0080bdc8 & 0x20) != 0)) {
    _DAT_0080023a = _DAT_0080023a + 1;
    if (0x31 < _DAT_0080023a) {
      fault_status_registers_t_00805df2.io_fault_status_1 =
           fault_status_registers_t_00805df2.io_fault_status_1 | 0x800;
      fault_latch_registers_t_00805e32.io_fault_latch_1 =
           fault_latch_registers_t_00805e32.io_fault_latch_1 | 0x800;
    }
  }
  else {
    _DAT_0080023a = 0;
    if (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x800) != 0) &&
       ((fault_latch_registers_t_00805e32.io_fault_latch_1 & 0x800) == 0)) {
      fault_status_registers_t_00805df2.io_fault_status_1 =
           fault_status_registers_t_00805df2.io_fault_status_1 & 0xf7ff;
    }
  }
  if (((DAT_0080bdc7 & 0x20) == 0) || ((DAT_0080bdc7 & 0x40) == 0)) {
    _DAT_0080023c = 0;
    if (((fault_status_registers_t_00805df2.io_fault_status_4 & 2) != 0) &&
       ((fault_latch_registers_t_00805e32.io_fault_latch_4 & 2) == 0)) {
      fault_status_registers_t_00805df2.io_fault_status_4 =
           fault_status_registers_t_00805df2.io_fault_status_4 & 0xfffd;
    }
  }
  else {
    _DAT_0080023c = _DAT_0080023c + 1;
    if (0x31 < _DAT_0080023c) {
      fault_status_registers_t_00805df2.io_fault_status_4 =
           fault_status_registers_t_00805df2.io_fault_status_4 | 2;
      fault_latch_registers_t_00805e32.io_fault_latch_4 =
           fault_latch_registers_t_00805e32.io_fault_latch_4 | 2;
    }
  }
  emptyStubFunction4();
  if ((_DAT_00803614 & 0x10) == 0) {
    if ((DAT_0080bdc8 & 2) == 0) {
      DAT_0080bdcf = DAT_0080bdcf & 0xfe;
    }
    else {
      DAT_0080bdcf = DAT_0080bdcf | 1;
    }
  }
  else if ((DAT_0080bdc9 & 4) == 0) {
    DAT_0080bdcf = DAT_0080bdcf & 0xfe;
  }
  else {
    DAT_0080bdcf = DAT_0080bdcf | 1;
  }
  DAT_00800242 = DAT_00800242 + 1;
  if (3 < DAT_00800242) {
    DAT_00800242 = 0;
  }
  return _DAT_00803614 & 0x10;
}



//
// Function: ioControlAndCanPinSwitching @ 0x000122d0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ioControlAndCanPinSwitching(void)

{
  DAT_00ffd004 = DAT_0080bdee;
  DAT_00ffd006 = DAT_0080bdef & 0xfe | ~DAT_0080bdef & 1;
  DAT_00fffa11 = DAT_0080bdf0;
  if ((~DAT_0080bdf3 & 0x20) == 0) {
    _DAT_00fffe18 = _DAT_00fffe18 & 0xf3ff | 0x800;
  }
  else {
    _DAT_00fffe18 = _DAT_00fffe18 & 0xf3ff | 0x400;
  }
  return;
}



//
// Function: initVP44StatusMonitoring @ 0x00012356
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initVP44StatusMonitoring(void)

{
  byte bVar1;
  
  _DAT_0080023e = 0x8035ee;
  bVar1 = 0;
  do {
    vp44_status_data_collector();
    bVar1 = bVar1 + 1;
  } while (bVar1 < 4);
  return;
}



//
// Function: initCANBus @ 0x00012376
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initCANBus(void)

{
  DAT_00ffd008 = 0xf;
  DAT_00ffd009 = 0x80;
  DAT_00ffd00a = 0x80;
  DAT_00ffd004 = 0;
  DAT_0080bdf0 = DAT_0080bdf0 | 0x10;
  _DAT_00fffe0a = _DAT_00fffe0a & 0xdfff;
  _DAT_00fffe20 = _DAT_00fffe20 & 0xdfff;
  _DAT_00fffe0c = _DAT_00fffe0c & 0xff0f | 0xe0;
  _DAT_00ffffd0 = 0x113;
  _DAT_00fffe1c = _DAT_00fffe1c & 0xf3ff | 0x400;
  do {
  } while ((_DAT_00ffffd2 & 0x8000) != 0);
  do {
  } while ((_DAT_00ffffd2 & 0x8000) == 0);
  do {
  } while ((_DAT_00ffffd2 & 0x8000) != 0);
  DAT_00ffd006 = DAT_00ffd006 & 0x7f | 0x80;
  _DAT_00fffe18 = _DAT_00fffe18 & 0xf3ff | 0x400;
  DAT_0080bdf3 = DAT_0080bdf3 | 0x20;
  DAT_0080bdee = DAT_0080bdee & 0xfa | 0x80;
  DAT_0080bdef = DAT_0080bdef | 1;
  DAT_0080bdf1 = DAT_0080bdf1 | 1;
  ioControlAndCanPinSwitching();
  return;
}



//
// Function: emptyStubFunction4 @ 0x00012482
//

void emptyStubFunction4(void)

{
  return;
}



//
// Function: diagnosticCommandDispatcher @ 0x00012484
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticCommandDispatcher(void)

{
  undefined1 uVar1;
  char cVar2;
  ushort uVar3;
  uint uVar4;
  char securityCheckResult;
  char cVar6;
  undefined4 uVar5;
  undefined4 unaff_D2;
  byte bVar7;
  byte *pbVar8;
  byte subFunctionCode;
  undefined2 uVar9;
  ushort uVar10;
  undefined2 local_18;
  byte abStack_16 [10];
  undefined4 local_c;
  byte *messageDataPtr;
  ushort responsePrefix;
  char messageLength;
  
  uVar3 = _DAT_00fff404;
  responsePrefix = (ushort)((uint)unaff_D2 >> 0x10);
  if ((DAT_0080d406 != '\0') && (uVar4 = circularBufferEmptyCheck(), (char)uVar4 != '\0')) {
    DAT_0080d406 = '\0';
    diagnosticMessageQueueWrite((uint)responsePrefix);
  }
  do {
    if ((499 < (int)((uint)_DAT_00fff404 - (uint)uVar3)) ||
       ((_DAT_0080d2c2 == _DAT_0080d2ca && (DAT_0080d2ce != '\x01')))) {
      return;
    }
    messageLength = *_DAT_0080d2ca;
    messageDataPtr._3_1_ = (char)_DAT_0080d2ca;
    cVar6 = (char)messageDataPtr;
    messageDataPtr._0_3_ = (undefined3)((uint)_DAT_0080d2ca >> 8);
    messageDataPtr = (byte *)CONCAT31(messageDataPtr._0_3_,(char)messageDataPtr + '\x01');
    if (*messageDataPtr < 8) {
      if ((_DAT_008035ea & 1) != 0) {
        switch(*messageDataPtr) {
        case 3:
          messageDataPtr = (byte *)CONCAT31(messageDataPtr._0_3_,cVar6 + '\x02');
          bVar7 = 0;
          pbVar8 = abStack_16;
          do {
            *pbVar8 = *messageDataPtr;
            messageDataPtr = (byte *)CONCAT31(messageDataPtr._0_3_,(char)messageDataPtr + '\x01');
            bVar7 = bVar7 + 1;
            pbVar8 = pbVar8 + 1;
          } while (bVar7 < 10);
          securityCheckResult = systemSecurityCheck();
          if (securityCheckResult == '\0') {
            switch(*messageDataPtr) {
            case 0x40:
              cVar6 = securedOperation40();
              break;
            case 0x41:
              cVar6 = securedOperation41();
              break;
            case 0x42:
              cVar6 = securedOperation42();
              break;
            case 0x43:
              cVar6 = securedOperation43();
              break;
            default:
              cVar6 = '\x18';
              break;
            case 0x50:
              cVar6 = '\0';
              break;
            case 0x51:
              uVar4 = memoryPatchingSystem();
              cVar6 = (char)uVar4;
              break;
            case 0x52:
              cVar6 = securedOperation52();
              break;
            case 0x53:
              cVar6 = '\x04';
              break;
            case 0x54:
              uVar5 = canMessageBufferLogger();
              cVar6 = (char)uVar5;
            }
            if (cVar6 != -1) {
              diagnosticMessageQueueWrite((uint)CONCAT12(cVar6,responsePrefix));
            }
          }
          else {
            diagnosticMessageQueueWrite(CONCAT22(3,responsePrefix));
          }
          break;
        case 4:
          messageDataPtr = (byte *)CONCAT31(messageDataPtr._0_3_,cVar6 + '\x02');
          switch(*messageDataPtr) {
          case 100:
            systemControl64();
            break;
          case 0x65:
            uVar10 = 0;
            systemControl65();
            diagnosticMessageQueueWrite((uint)uVar10);
            break;
          case 0x66:
            _DAT_00809d3e = 0;
            diagnosticMessageQueueWrite((uint)responsePrefix);
            break;
          default:
            diagnosticMessageQueueWrite(CONCAT22(0x18,responsePrefix));
            break;
          case 0x69:
            uVar9 = 0;
            uVar4 = systemControl69();
            diagnosticMessageQueueWrite((uint)CONCAT12((char)uVar4,uVar9));
            break;
          case 0x70:
          case 0x72:
          case 0x76:
            diagnosticMessageQueueWrite(CONCAT22(4,responsePrefix));
            break;
          case 0x71:
            _DAT_00809d3e = _DAT_00809d3e | 1;
            diagnosticMessageQueueWrite((uint)responsePrefix);
            break;
          case 0x73:
            _DAT_00809d3e = _DAT_00809d3e | 2;
            diagnosticMessageQueueWrite((uint)responsePrefix);
            break;
          case 0x74:
            systemControl74();
            break;
          case 0x75:
            systemControl75();
          }
          break;
        case 5:
          messageDataPtr = (byte *)CONCAT31(messageDataPtr._0_3_,cVar6 + '\x02');
          if (((*messageDataPtr & 0xf) == 0) && ((*messageDataPtr & 0xf0) != 0xf0)) {
            cVar2 = messageLength + -1 + cVar6;
            local_c = (undefined1 *)CONCAT31(messageDataPtr._0_3_,cVar2);
            uVar1 = *local_c;
            local_c = (undefined1 *)CONCAT31(messageDataPtr._0_3_,cVar2 + '\x01');
            local_18 = CONCAT11(*local_c,uVar1);
            local_c = (undefined1 *)CONCAT31(messageDataPtr._0_3_,cVar6 + '\x03');
            uVar5 = crc16Calculate((byte *)CONCAT22((short)((uint)_DAT_0080d2ca >> 0x10),
                                                    (short)local_c),
                                   (uint)CONCAT12(messageLength + -4,responsePrefix));
            if ((short)uVar5 != local_18) {
              diagnosticMessageQueueWrite(CONCAT22(0x14,responsePrefix));
              break;
            }
          }
          bVar7 = *messageDataPtr & 0xf0;
          if (bVar7 == 0x60) {
            diagnosticMemoryReadHandler(CONCAT22(3,responsePrefix));
          }
          else if (bVar7 == 0xc0) {
            diagnosticMemoryReadHandler(CONCAT22(2,responsePrefix));
          }
          else if (bVar7 == 0x80) {
            diagnosticMemoryWriteHandler(CONCAT22(4,responsePrefix));
          }
          else if (bVar7 == 0xe0) {
            diagnosticMemoryReadHandler(CONCAT22(1,responsePrefix));
          }
          else if (bVar7 == 0xa0) {
            diagnosticMemoryWriteHandler(CONCAT22(2,responsePrefix));
          }
          else if (bVar7 == 0xf0) {
            multiPacketTransmitHandler();
          }
          else if (bVar7 == 0xb0) {
            multiPacketReceiveHandler();
          }
          else {
            diagnosticMessageQueueWrite(CONCAT22(4,responsePrefix));
          }
          break;
        case 6:
          messageDataPtr = (byte *)CONCAT31(messageDataPtr._0_3_,cVar6 + '\x02');
          if ((*messageDataPtr == 0x74) && (DAT_0080d2db != '\0')) {
            diagnosticMessageQueueWrite(CONCAT22(1,responsePrefix));
            DAT_0080d2db = DAT_0080d2db + -1;
            DAT_0080d404 = 0;
            if (DAT_0080d405 != '\0') {
              memoryPatchCountDecrement();
              DAT_0080d405 = '\0';
            }
          }
        }
      }
    }
    else if (*messageDataPtr < 0x80) {
      if (((0x44 < *messageDataPtr) && (*messageDataPtr < 0x57)) && ((_DAT_008035ea & 4) != 0)) {
        switch(*messageDataPtr) {
        case 0x4a:
          fuelArbitratorControlService();
          break;
        case 0x4c:
          extendedDiagnosticService4C();
          break;
        case 0x4f:
          extendedDiagnosticService4F();
          break;
        case 0x51:
          extendedDiagnosticService51();
        }
      }
    }
    else if ((_DAT_008035ea & 2) != 0) {
      insiteLiveDataHandler();
    }
    _DAT_0080d2ca = (char *)CONCAT31(_DAT_0080d2ca,messageLength + '\x01' + DAT_0080d2cd);
    DAT_0080d2ce = '\0';
    _DAT_00fffc0a = _DAT_00fffc0a | 0x20;
  } while( true );
}



//
// Function: safeDivideWithClamp @ 0x00012966
//

int safeDivideWithClamp(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if ((((int)param_1 < 0) || (param_2 < 0)) && ((-1 < (int)param_1 || (-1 < param_2)))) {
    if (param_2._0_2_ * -0x8000 < 0) {
      uVar1 = param_2._0_2_ * 0x8000;
    }
    else {
      uVar1 = param_2._0_2_ * -0x8000;
    }
    uVar2 = param_1;
    if ((int)param_1 < 0) {
      uVar2 = -param_1;
    }
    if (uVar2 < uVar1) {
      return (int)param_1 / (int)param_2._0_2_;
    }
    return CONCAT22((short)(uVar1 >> 0x10),0x8000);
  }
  if (param_2._0_2_ * 0x7fff < 0) {
    uVar1 = param_2._0_2_ * -0x7fff;
  }
  else {
    uVar1 = param_2._0_2_ * 0x7fff;
  }
  uVar2 = param_1;
  if ((int)param_1 < 0) {
    uVar2 = -param_1;
  }
  if (uVar2 < uVar1) {
    return (int)param_1 / (int)param_2._0_2_;
  }
  return CONCAT22((short)(uVar1 >> 0x10),0x7fff);
}



//
// Function: clampedDivisionCalculator @ 0x00012a26
//

uint clampedDivisionCalculator(uint param_1,uint param_2,int param_3)

{
  undefined2 uVar1;
  undefined4 in_D0;
  uint uVar2;
  uint uVar3;
  
  uVar1 = (undefined2)((uint)in_D0 >> 0x10);
  if ((((int)param_1 < 0) || ((int)param_2 < 0)) && ((-1 < (int)param_1 || (-1 < (int)param_2)))) {
    if (-1 < param_3) {
      return CONCAT22(uVar1,param_3._0_2_);
    }
    if ((int)param_2._0_2_ * (int)param_3._0_2_ < 0) {
      uVar2 = -((int)param_2._0_2_ * (int)param_3._0_2_);
    }
    else {
      uVar2 = (int)param_2._0_2_ * (int)param_3._0_2_;
    }
    uVar3 = param_1;
    if ((int)param_1 < 0) {
      uVar3 = -param_1;
    }
    if (uVar3 < uVar2) {
      uVar2 = (int)param_1 / (int)param_2._0_2_;
      if ((short)uVar2 < param_2._2_2_) {
        return uVar2;
      }
      return CONCAT22((short)(uVar2 >> 0x10),param_2._2_2_);
    }
    return CONCAT22((short)(uVar2 >> 0x10),param_3._0_2_);
  }
  if (param_2._2_2_ < 1) {
    return CONCAT22(uVar1,param_2._2_2_);
  }
  if ((int)param_2._0_2_ * (int)param_2._2_2_ < 0) {
    uVar2 = -((int)param_2._0_2_ * (int)param_2._2_2_);
  }
  else {
    uVar2 = (int)param_2._0_2_ * (int)param_2._2_2_;
  }
  uVar3 = param_1;
  if ((int)param_1 < 0) {
    uVar3 = -param_1;
  }
  if (uVar3 < uVar2) {
    uVar2 = (int)param_1 / (int)param_2._0_2_;
    if (param_3._0_2_ < (short)uVar2) {
      return uVar2;
    }
    return CONCAT22((short)(uVar2 >> 0x10),param_3._0_2_);
  }
  return CONCAT22((short)(uVar2 >> 0x10),param_2._2_2_);
}



//
// Function: param_address_calc @ 0x00012afa
//

uint param_address_calc(uint param_1,undefined4 param_2)

{
  if ((uint)param_2._0_2_ * 0xffff <= param_1) {
    return CONCAT22((short)((uint)param_2._0_2_ * 0xffff >> 0x10),0xffff);
  }
  return param_1 / param_2._0_2_;
}



//
// Function: limitedDivisionCalculator @ 0x00012b30
//

uint limitedDivisionCalculator(uint param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = (uint)param_2._0_2_ * (param_2 & 0xffff);
  if (uVar1 <= param_1) {
    return CONCAT22((short)(uVar1 >> 0x10),param_2._2_2_);
  }
  uVar1 = param_1 / param_2._0_2_;
  if ((ushort)uVar1 <= param_3._0_2_) {
    return CONCAT22((short)(uVar1 >> 0x10),param_3._0_2_);
  }
  return uVar1;
}



//
// Function: multiPacketTransmitHandler @ 0x00012b74
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void multiPacketTransmitHandler(void)

{
  undefined1 uVar1;
  byte bVar2;
  byte *pbVar3;
  char cVar4;
  char cVar7;
  int iVar5;
  undefined4 uVar6;
  undefined4 unaff_D2;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  undefined2 uVar11;
  undefined4 local_c;
  undefined4 local_8;
  
  pbVar3 = _DAT_0080d2b4;
  uVar11 = (undefined2)((uint)unaff_D2 >> 0x10);
  DAT_0080d404 = 0;
  if (*_DAT_0080d2ca == '\x06') {
    local_8._3_1_ = (char)_DAT_0080d2ca;
    cVar4 = (char)local_8;
    local_8._0_3_ = (undefined3)((uint)_DAT_0080d2ca >> 8);
    local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x03');
    uVar1 = *local_8;
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar4 + '\x04');
    diag_transfer_state_t_0080d3f8.target_address = CONCAT11(*local_8,uVar1);
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar4 + '\x05');
    cVar7 = FUN_0000eaf0(0x80);
    if (cVar7 == '\0') {
      bVar9 = *local_8;
      local_8 = (byte *)CONCAT31(local_8._0_3_,cVar4 + '\x06');
      diag_transfer_state_t_0080d3f8.byte_count = CONCAT11(*local_8,bVar9);
      if (diag_transfer_state_t_0080d3f8.byte_count < 0xf) {
        bVar10 = bVar9 + 6;
      }
      else {
        bVar10 = 0x14;
        bVar9 = 0xe;
        DAT_0080d404 = 1;
      }
      if ((int)pbVar3 < _DAT_0080d2bc) {
        iVar5 = (_DAT_0080d2bc - (int)pbVar3) + -2;
      }
      else {
        iVar5 = (_DAT_0080d2bc - (int)pbVar3) + 0xfe;
      }
      if ((int)(uint)bVar10 < iVar5) {
        local_c._3_1_ = (char)pbVar3;
        cVar4 = (char)local_c;
        local_c._0_3_ = (undefined3)((uint)pbVar3 >> 8);
        local_c = (byte *)CONCAT31(local_c._0_3_,(char)local_c + '\x01');
        *local_c = 7;
        local_c = (byte *)CONCAT31(local_c._0_3_,cVar4 + '\x02');
        *local_c = bVar9 | 0xb0;
        local_c = (byte *)CONCAT31(local_c._0_3_,cVar4 + '\x03');
        uVar6 = addressRangeValidator
                          (diag_transfer_state_t_0080d3f8.data_pointer,
                           CONCAT22(diag_transfer_state_t_0080d3f8.byte_count,uVar11));
        cVar7 = (char)uVar6;
        if ((cVar7 == '\t') || (cVar7 == '\n')) {
          diagnosticMessageQueueWrite((uint)CONCAT12(cVar7,uVar11));
          DAT_0080d404 = 0;
        }
        else {
          *local_c = (undefined1)diag_transfer_state_t_0080d3f8.target_address;
          local_c = (byte *)CONCAT31(local_c._0_3_,cVar4 + '\x04');
          *local_c = diag_transfer_state_t_0080d3f8.target_address._0_1_;
          local_c = (byte *)CONCAT31(local_c._0_3_,cVar4 + '\x05');
          *local_c = (undefined1)diag_transfer_state_t_0080d3f8.byte_count;
          local_c = (byte *)CONCAT31(local_c._0_3_,cVar4 + '\x06');
          *local_c = diag_transfer_state_t_0080d3f8.byte_count._0_1_;
          local_c = (byte *)CONCAT31(local_c._0_3_,cVar4 + '\a');
          for (bVar8 = 0; bVar8 < bVar9; bVar8 = bVar8 + 1) {
            bVar2 = *(byte *)diag_transfer_state_t_0080d3f8.data_pointer;
            diag_transfer_state_t_0080d3f8.data_pointer =
                 diag_transfer_state_t_0080d3f8.data_pointer + 1;
            *local_c = bVar2;
            local_c = (byte *)CONCAT31(local_c._0_3_,(char)local_c + '\x01');
          }
          diag_transfer_state_t_0080d3f8.byte_count =
               diag_transfer_state_t_0080d3f8.byte_count - bVar9;
          *pbVar3 = bVar10;
          *local_c = 0;
          _DAT_0080d2b4 = local_c;
          tpuTransmissionTrigger();
          DAT_0080d404 = 1;
        }
      }
      else {
        DAT_0080d404 = 0;
        diagnosticMessageQueueWrite(CONCAT22(4,uVar11));
        fault_status_registers_t_00805df2.io_fault_status_4 =
             fault_status_registers_t_00805df2.io_fault_status_4 | 4;
        fault_latch_registers_t_00805e32.io_fault_latch_4 =
             fault_latch_registers_t_00805e32.io_fault_latch_4 | 4;
      }
    }
    else {
      diagnosticMessageQueueWrite(CONCAT22(8,uVar11));
    }
  }
  else {
    diagnosticMessageQueueWrite(CONCAT22(4,uVar11));
  }
  return;
}



//
// Function: multiPacketReceiveHandler @ 0x00012d76
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void multiPacketReceiveHandler(void)

{
  short *psVar1;
  undefined1 uVar2;
  byte bVar3;
  short sVar4;
  undefined1 *puVar5;
  dword dVar6;
  undefined4 uVar7;
  char cVar8;
  undefined4 unaff_D2;
  byte bVar9;
  ushort uVar10;
  undefined2 local_a;
  undefined4 local_8;
  
  uVar10 = (ushort)((uint)unaff_D2 >> 0x10);
  local_8._3_1_ = (char)_DAT_0080d2ca;
  cVar8 = (char)local_8;
  local_8._0_3_ = (undefined3)((uint)_DAT_0080d2ca >> 8);
  local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x02');
  bVar3 = *local_8 & 0xf;
  if (DAT_0080d405 == '\x01') {
    if ((uint)*_DAT_0080d2ca - (uint)bVar3 == 4) {
      local_8 = (byte *)CONCAT31(local_8._0_3_,cVar8 + '\x03');
      uVar2 = *local_8;
      local_8 = (byte *)CONCAT31(local_8._0_3_,cVar8 + '\x04');
      local_a = CONCAT11(*local_8,uVar2);
      local_8 = (byte *)CONCAT31(local_8._0_3_,cVar8 + '\x05');
      if (local_a == diag_transfer_state_t_0080d3f8.target_address) {
        switch(diag_transfer_state_t_0080d3f8.target_address) {
        case 0x15:
        case 0x17:
        case 0x18:
        case 0x19:
          for (bVar9 = 0; bVar9 < bVar3; bVar9 = bVar9 + 1) {
            dVar6 = diag_transfer_state_t_0080d3f8.data_pointer + 1;
            *(byte *)diag_transfer_state_t_0080d3f8.data_pointer = *local_8;
            diag_transfer_state_t_0080d3f8.data_pointer = dVar6;
            local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
          }
          diag_transfer_state_t_0080d3f8._10_2_ =
               diag_transfer_state_t_0080d3f8._10_2_ - (ushort)bVar3;
          if (diag_transfer_state_t_0080d3f8._10_2_ == 0) {
            DAT_0080d405 = '\0';
          }
          break;
        default:
          uVar7 = addressRangeValidator
                            (diag_transfer_state_t_0080d3f8.data_pointer,
                             CONCAT22(diag_transfer_state_t_0080d3f8._10_2_,uVar10));
          if (((char)uVar7 == '\x03') || ((char)uVar7 == '\x05')) {
            psVar1 = (short *)((short)(_DAT_0080d44e * 3) * 2 + 0x80d3a4);
            *psVar1 = (ushort)bVar3 + *psVar1;
            for (bVar9 = 0; bVar9 < bVar3; bVar9 = bVar9 + 1) {
              puVar5 = _DAT_0080d3e2 + 1;
              *_DAT_0080d3e2 = *local_8;
              _DAT_0080d3e2 = puVar5;
              local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
            }
            diag_transfer_state_t_0080d3f8._10_2_ =
                 diag_transfer_state_t_0080d3f8._10_2_ - (ushort)bVar3;
            if (diag_transfer_state_t_0080d3f8._10_2_ == 0) {
              DAT_0080d405 = '\0';
            }
          }
          else {
            for (bVar9 = 0; bVar9 < bVar3; bVar9 = bVar9 + 1) {
              dVar6 = diag_transfer_state_t_0080d3f8.data_pointer + 1;
              *(byte *)diag_transfer_state_t_0080d3f8.data_pointer = *local_8;
              diag_transfer_state_t_0080d3f8.data_pointer = dVar6;
              local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
            }
            diag_transfer_state_t_0080d3f8._10_2_ =
                 diag_transfer_state_t_0080d3f8._10_2_ - (ushort)bVar3;
            if (diag_transfer_state_t_0080d3f8._10_2_ == 0) {
              DAT_0080d405 = '\0';
            }
          }
        }
        diagnosticMessageQueueWrite((uint)uVar10);
      }
      else {
        _DAT_0080d44e = _DAT_0080d44e - 1;
        _DAT_0080d3e2 =
             _DAT_0080d3e2 + -(uint)*(ushort *)((short)(_DAT_0080d44e * 3) * 2 + 0x80d3aa);
        DAT_0080d405 = '\0';
        diagnosticMessageQueueWrite(CONCAT22(4,uVar10));
      }
    }
    else {
      diagnosticMessageQueueWrite(CONCAT22(4,uVar10));
    }
  }
  else if ((uint)*_DAT_0080d2ca - (uint)bVar3 == 6) {
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar8 + '\x03');
    uVar2 = *local_8;
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar8 + '\x04');
    diag_transfer_state_t_0080d3f8.target_address = CONCAT11(*local_8,uVar2);
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar8 + '\x05');
    diag_transfer_state_t_0080d3f8.rx_active_flag = *local_8;
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar8 + '\x06');
    diag_transfer_state_t_0080d3f8.tx_active_flag = *local_8;
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar8 + '\a');
    cVar8 = FUN_0000eaf0(0x80);
    if (cVar8 == '\0') {
      switch(diag_transfer_state_t_0080d3f8.target_address) {
      case 0x15:
      case 0x17:
      case 0x18:
      case 0x19:
        for (bVar9 = 0; bVar9 < bVar3; bVar9 = bVar9 + 1) {
          dVar6 = diag_transfer_state_t_0080d3f8.data_pointer + 1;
          *(byte *)diag_transfer_state_t_0080d3f8.data_pointer = *local_8;
          diag_transfer_state_t_0080d3f8.data_pointer = dVar6;
          local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
        }
        diag_transfer_state_t_0080d3f8._10_2_ =
             diag_transfer_state_t_0080d3f8._10_2_ - (ushort)bVar3;
        if (diag_transfer_state_t_0080d3f8._10_2_ != 0) {
          DAT_0080d405 = '\x01';
        }
        break;
      default:
        uVar7 = addressRangeValidator
                          (diag_transfer_state_t_0080d3f8.data_pointer,
                           CONCAT22(diag_transfer_state_t_0080d3f8._10_2_,uVar10));
        cVar8 = (char)uVar7;
        if ((cVar8 == '\x05') || (cVar8 == '\x03')) {
          if ((10 < _DAT_0080d44e + 1) ||
             (0x80d3a5 - (int)_DAT_0080d3e2 <=
              (int)(uint)(ushort)diag_transfer_state_t_0080d3f8._10_2_)) {
            diagnosticMessageQueueWrite(CONCAT22(0xe,uVar10));
            return;
          }
          *(dword *)(&DAT_0080d3a6 + (short)(_DAT_0080d44e * 3) * 2) =
               diag_transfer_state_t_0080d3f8.data_pointer;
          sVar4 = _DAT_0080d44e * 3;
          _DAT_0080d44e = _DAT_0080d44e + 1;
          *(ushort *)(sVar4 * 2 + 0x80d3aa) = (ushort)bVar3;
          for (bVar9 = 0; bVar9 < bVar3; bVar9 = bVar9 + 1) {
            puVar5 = _DAT_0080d3e2 + 1;
            *_DAT_0080d3e2 = *local_8;
            _DAT_0080d3e2 = puVar5;
            local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
          }
          diag_transfer_state_t_0080d3f8._10_2_ =
               diag_transfer_state_t_0080d3f8._10_2_ - (ushort)bVar3;
          if (diag_transfer_state_t_0080d3f8._10_2_ != 0) {
            DAT_0080d405 = '\x01';
          }
        }
        else {
          if (cVar8 != '\0') {
            if (cVar8 != '\n') {
              diagnosticMessageQueueWrite(CONCAT22(9,uVar10));
              return;
            }
            diagnosticMessageQueueWrite(CONCAT22(10,uVar10));
            return;
          }
          for (bVar9 = 0; bVar9 < bVar3; bVar9 = bVar9 + 1) {
            dVar6 = diag_transfer_state_t_0080d3f8.data_pointer + 1;
            *(byte *)diag_transfer_state_t_0080d3f8.data_pointer = *local_8;
            diag_transfer_state_t_0080d3f8.data_pointer = dVar6;
            local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
          }
          if (diag_transfer_state_t_0080d3f8._10_2_ != 0) {
            DAT_0080d405 = '\x01';
          }
        }
      }
      diagnosticMessageQueueWrite((uint)uVar10);
    }
    else {
      diagnosticMessageQueueWrite(CONCAT22(8,uVar10));
    }
  }
  else {
    diagnosticMessageQueueWrite(CONCAT22(4,uVar10));
  }
  return;
}



//
// Function: circularBufferEmptyCheck @ 0x00013134
//

uint circularBufferEmptyCheck(void)

{
  uint in_D0;
  
  if (circular_buffer_t_0080c3fc.entry_count == 0) {
    return 1;
  }
  return in_D0 & 0xffffff00;
}



//
// Function: parameterCircularBufferWrite @ 0x00013144
//

uint parameterCircularBufferWrite(int param_1,undefined1 *param_2,undefined4 param_3)

{
  short sVar1;
  uint uVar2;
  
  if ((uint)param_3._0_2_ + (uint)circular_buffer_t_0080c3fc.entry_count < 0x201) {
    circular_buffer_t_0080c3fc.data_buffer_2 = (short)(param_1 + -0x8034f6) - 2;
    uVar2 = CONCAT22((short)((uint)(param_1 + -0x8034f6) >> 0x10),
                     circular_buffer_t_0080c3fc.data_buffer_2);
    *(word *)((uint)circular_buffer_t_0080c3fc.write_index * 2 + 0x80bdfa) =
         circular_buffer_t_0080c3fc.data_buffer_2;
    for (; param_3._0_2_ != 0; param_3._0_2_ = param_3._0_2_ - 1) {
      *(undefined1 *)((short)circular_buffer_t_0080c3fc.write_index + 0x80c1fa) = *param_2;
      sVar1 = (short)(param_1 + -0x8034f6) + -2;
      uVar2 = CONCAT22((short)((uint)(param_1 + -0x8034f6) >> 0x10),sVar1);
      *(short *)((uint)circular_buffer_t_0080c3fc.write_index * 2 + 0x80bdfa) = sVar1;
      circular_buffer_t_0080c3fc.write_index = circular_buffer_t_0080c3fc.write_index + 1 & 0x1ff;
      circular_buffer_t_0080c3fc.entry_count = circular_buffer_t_0080c3fc.entry_count + 1;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    return uVar2 & 0xffffff00;
  }
  return 1;
}



//
// Function: circularBufferWrite @ 0x000131d6
// ERROR: Failed to decompile
//

//
// Function: emptyPlaceholderFunction @ 0x00013240
//

void emptyPlaceholderFunction(void)

{
  return;
}



//
// Function: tpuTransmissionTrigger @ 0x00013242
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void tpuTransmissionTrigger(void)

{
  if (((DAT_0080d2d0 == '\x01') && ((_DAT_00fffc0c & 0x20) == 0)) && (DAT_0080d2da == '\0')) {
    _DAT_00fffc0e = (ushort)*_DAT_0080d2b8;
    DAT_0080d2da = '\x01';
    tpu_timer_channel_register._2_2_ = 0xfc8a;
    tpu_timer_channel_register._0_2_ = tpu_timer_channel_register._0_2_ & 0x7fff | 0x4000;
    DAT_0080d2d0 = '\0';
    _DAT_0080d2d6 = 0;
    DAT_0080d2d1 = 1;
    DAT_0080d2d3 = *_DAT_0080d2b8;
    _DAT_00fffc0a = _DAT_00fffc0a | 0x20;
  }
  return;
}



//
// Function: engine_fault_monitoring_and_rpm_calculation @ 0x000132c8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint engine_fault_monitoring_and_rpm_calculation(void)

{
  uint uVar1;
  
  if (circular_buffer_t_0080c3fc.data_buffer_rest._24_2_ == 0) {
    if (circular_buffer_t_0080c3fc.data_buffer_rest._14_2_ != 0) {
      circular_buffer_t_0080c3fc.data_buffer_rest[0xe] = 0;
      circular_buffer_t_0080c3fc.data_buffer_rest[0xf] = 0;
      canControllerConfigInit();
    }
  }
  else {
    circular_buffer_t_0080c3fc.data_buffer_rest._24_2_ =
         circular_buffer_t_0080c3fc.data_buffer_rest._24_2_ + -1;
    circular_buffer_t_0080c3fc.data_buffer_rest._14_2_ =
         SUB42(_CRGNSC / (uint)circular_buffer_t_0080c3fc.data_buffer_rest._0_4_,0);
  }
  if (circular_buffer_t_0080c3fc.data_buffer_rest._26_2_ == 0) {
    if (circular_buffer_t_0080c3fc.data_buffer_rest._12_2_ != 0) {
      circular_buffer_t_0080c3fc.data_buffer_rest[0xc] = 0;
      circular_buffer_t_0080c3fc.data_buffer_rest[0xd] = 0;
      canRpmModeConfigInit();
    }
  }
  else {
    circular_buffer_t_0080c3fc.data_buffer_rest._26_2_ =
         circular_buffer_t_0080c3fc.data_buffer_rest._26_2_ + -1;
    if ((_DAT_00807ce2 & 0xc) != 0) {
      circular_buffer_t_0080c3fc.data_buffer_rest._12_2_ =
           SUB42(_DAT_00807cbe / (uint)circular_buffer_t_0080c3fc.data_buffer_rest._4_4_,0);
    }
  }
  if (circular_buffer_t_0080c3fc.data_buffer_rest._28_2_ == 0) {
    if (circular_buffer_t_0080c3fc.data_buffer_rest._30_2_ != 0) {
      circular_buffer_t_0080c3fc.data_buffer_rest[0x1e] = 0;
      circular_buffer_t_0080c3fc.data_buffer_rest[0x1f] = 0;
    }
  }
  else {
    circular_buffer_t_0080c3fc.data_buffer_rest._28_2_ =
         circular_buffer_t_0080c3fc.data_buffer_rest._28_2_ + -1;
  }
  if ((circular_buffer_t_0080c3fc.data_buffer_rest._24_2_ == 0) &&
     (circular_buffer_t_0080c3fc.data_buffer_8 != 0)) {
    if (_DAT_0080c76c < _DAT_00807cee) {
      _DAT_0080c76c = _DAT_0080c76c + 1;
    }
    else {
      fault_status_registers_t_00805df2.engine_fault_status =
           fault_status_registers_t_00805df2.engine_fault_status | 0x1000;
      fault_latch_registers_t_00805e32.engine_fault_latch =
           fault_latch_registers_t_00805e32.engine_fault_latch | 0x1000;
    }
  }
  else if ((circular_buffer_t_0080c3fc.data_buffer_rest._24_2_ != 0) &&
          ((_DAT_0080c76c = 0, (fault_status_registers_t_00805df2.engine_fault_status & 0x1000) != 0
           && ((fault_latch_registers_t_00805e32.engine_fault_latch & 0x1000) == 0)))) {
    fault_status_registers_t_00805df2.engine_fault_status =
         fault_status_registers_t_00805df2.engine_fault_status & 0xefff;
  }
  if ((((_DAT_00807ce2 & 0xc) == 0) || (circular_buffer_t_0080c3fc.data_buffer_rest._26_2_ != 0)) ||
     (circular_buffer_t_0080c3fc.data_buffer_8 == 0)) {
    if (((circular_buffer_t_0080c3fc.data_buffer_rest._26_2_ != 0) &&
        (_DAT_0080c76e = 0, (fault_status_registers_t_00805df2.engine_fault_status & 0x400) != 0))
       && ((fault_latch_registers_t_00805e32.engine_fault_latch & 0x400) == 0)) {
      fault_status_registers_t_00805df2.engine_fault_status =
           fault_status_registers_t_00805df2.engine_fault_status & 0xfbff;
    }
  }
  else if (_DAT_0080c76e < _DAT_00807cf0) {
    _DAT_0080c76e = _DAT_0080c76e + 1;
  }
  else {
    fault_status_registers_t_00805df2.engine_fault_status =
         fault_status_registers_t_00805df2.engine_fault_status | 0x400;
    fault_latch_registers_t_00805e32.engine_fault_latch =
         fault_latch_registers_t_00805e32.engine_fault_latch | 0x400;
  }
  if ((circular_buffer_t_0080c3fc.data_buffer_rest._28_2_ == 0) &&
     (circular_buffer_t_0080c3fc.data_buffer_8 != 0)) {
    if (_DAT_0080c770 < _DAT_00807cf2) {
      _DAT_0080c770 = _DAT_0080c770 + 1;
    }
    else {
      vp44_fault_state_t_00805e14.fso_fault_status =
           vp44_fault_state_t_00805e14.fso_fault_status | 4;
      _DAT_00805e56 = _DAT_00805e56 | 4;
    }
  }
  else if ((circular_buffer_t_0080c3fc.data_buffer_rest._28_2_ != 0) &&
          ((_DAT_0080c770 = 0, (vp44_fault_state_t_00805e14.fso_fault_status & 4) != 0 &&
           ((_DAT_00805e56 & 4) == 0)))) {
    vp44_fault_state_t_00805e14.fso_fault_status =
         vp44_fault_state_t_00805e14.fso_fault_status & 0xfffb;
  }
  if (((DAT_0080c7b3 == '\x01') &&
      (_DAT_0080c76a = 0, (fault_status_registers_t_00805df2.engine_fault_status & 0x4000) != 0)) &&
     ((fault_latch_registers_t_00805e32.engine_fault_latch & 0x4000) == 0)) {
    fault_status_registers_t_00805df2.engine_fault_status =
         fault_status_registers_t_00805df2.engine_fault_status & 0xbfff;
  }
  if ((DAT_0080c7b3 == '\0') && (circular_buffer_t_0080c3fc.data_buffer_8 != 0)) {
    if (_DAT_0080c76a < _DAT_00807cec) {
      _DAT_0080c76a = _DAT_0080c76a + 1;
    }
    else {
      fault_status_registers_t_00805df2.engine_fault_status =
           fault_status_registers_t_00805df2.engine_fault_status | 0x4000;
      fault_latch_registers_t_00805e32.engine_fault_latch =
           fault_latch_registers_t_00805e32.engine_fault_latch | 0x4000;
    }
  }
  else if ((DAT_0080c7b3 == '\0') &&
          ((_DAT_0080c76a = 0, (fault_status_registers_t_00805df2.engine_fault_status & 0x4000) != 0
           && ((fault_latch_registers_t_00805e32.engine_fault_latch & 0x4000) == 0)))) {
    fault_status_registers_t_00805df2.engine_fault_status =
         fault_status_registers_t_00805df2.engine_fault_status & 0xbfff;
  }
  if ((((DAT_0080c7b2 == '\x01') || (DAT_0080c7b2 == '\0')) &&
      (_DAT_0080c768 = 0, (fault_status_registers_t_00805df2.engine_fault_status & 0x800) != 0)) &&
     ((fault_latch_registers_t_00805e32.engine_fault_latch & 0x800) == 0)) {
    fault_status_registers_t_00805df2.engine_fault_status =
         fault_status_registers_t_00805df2.engine_fault_status & 0xf7ff;
  }
  (*_DAT_0080c78e)();
  uVar1 = (uint)(ushort)circular_buffer_t_0080c3fc.data_buffer_rest._32_2_;
  if (circular_buffer_t_0080c3fc.data_buffer_rest._32_2_ == 0) {
    if (circular_buffer_t_0080c3fc.data_buffer_rest._24_2_ == 0) {
      circular_buffer_t_0080c3fc.data_buffer_4 = 0;
      circular_buffer_t_0080c3fc.data_buffer_8 = 0;
      circular_buffer_t_0080c3fc.current_engine_rpm = 0;
    }
    else {
      circular_buffer_t_0080c3fc.data_buffer_4._0_1_ =
           circular_buffer_t_0080c3fc.data_buffer_rest[0xe];
      circular_buffer_t_0080c3fc.data_buffer_4._1_1_ =
           circular_buffer_t_0080c3fc.data_buffer_rest[0xf];
      circular_buffer_t_0080c3fc.data_buffer_8 = coreTableInterpolation();
      uVar1 = _DAT_00807cc2 / _DAT_0080c776;
      circular_buffer_t_0080c3fc.current_engine_rpm = (word)uVar1;
    }
  }
  else if (circular_buffer_t_0080c3fc.data_buffer_rest._32_2_ == 1) {
    if (circular_buffer_t_0080c3fc.data_buffer_rest._26_2_ == 0) {
      circular_buffer_t_0080c3fc.data_buffer_4 = 0;
      circular_buffer_t_0080c3fc.data_buffer_8 = 0;
      circular_buffer_t_0080c3fc.current_engine_rpm = 0;
    }
    else {
      circular_buffer_t_0080c3fc.data_buffer_4._0_1_ =
           circular_buffer_t_0080c3fc.data_buffer_rest[0xc];
      circular_buffer_t_0080c3fc.data_buffer_4._1_1_ =
           circular_buffer_t_0080c3fc.data_buffer_rest[0xd];
      circular_buffer_t_0080c3fc.data_buffer_8 = coreTableInterpolation();
      uVar1 = _DAT_00807cc2 / _DAT_0080c77a;
      circular_buffer_t_0080c3fc.current_engine_rpm = (word)uVar1;
    }
  }
  else if (circular_buffer_t_0080c3fc.data_buffer_rest._32_2_ == 2) {
    if (circular_buffer_t_0080c3fc.data_buffer_rest._28_2_ == 0) {
      circular_buffer_t_0080c3fc.data_buffer_4 = 0;
      circular_buffer_t_0080c3fc.data_buffer_8 = 0;
      circular_buffer_t_0080c3fc.current_engine_rpm = 0;
    }
    else {
      circular_buffer_t_0080c3fc.data_buffer_4._0_1_ =
           circular_buffer_t_0080c3fc.data_buffer_rest[0x1e];
      circular_buffer_t_0080c3fc.data_buffer_4._1_1_ =
           circular_buffer_t_0080c3fc.data_buffer_rest[0x1f];
      uVar1 = coreTableInterpolation();
      circular_buffer_t_0080c3fc.current_engine_rpm = (word)uVar1;
      circular_buffer_t_0080c3fc.data_buffer_8 = circular_buffer_t_0080c3fc.current_engine_rpm;
    }
  }
  if (_DAT_00809cba != 0) {
    circular_buffer_t_0080c3fc.current_engine_rpm = _DAT_00809cb8;
    circular_buffer_t_0080c3fc.data_buffer_4 = _DAT_00809cb8;
    circular_buffer_t_0080c3fc.data_buffer_8 = _DAT_00809cb8;
  }
  if (engine_operating_mode_t_0080c810.state == 1) {
    uVar1 = DAT_0080bdc6 & 1;
    if ((DAT_0080bdc6 & 1) == 0) {
      _DAT_0080d1a4 = 0;
    }
    else {
      _DAT_0080d1a4 = 2;
    }
  }
  else {
    _DAT_0080d1a4 = 1;
  }
  if (circular_buffer_t_0080c3fc.current_engine_rpm < 0x800) {
    _DAT_0080c772 = CCMNFLLM;
    _DAT_0080c774 = _DAT_00807cdc;
    return uVar1;
  }
  if (circular_buffer_t_0080c3fc.current_engine_rpm < 0xff8) {
    _DAT_0080c772 = (short)((int)(uint)CCMNFLLM >> 1);
    _DAT_0080c774 = (short)((int)(uint)_DAT_00807cdc >> 1);
    return (int)(uint)_DAT_00807cdc >> 1;
  }
  if (0x17ff < circular_buffer_t_0080c3fc.current_engine_rpm) {
    _DAT_0080c772 = (short)((int)(uint)CCMNFLLM >> 3);
    _DAT_0080c774 = (short)((int)(uint)_DAT_00807cdc >> 3);
    return (int)(uint)_DAT_00807cdc >> 3;
  }
  _DAT_0080c772 = (short)((int)(uint)CCMNFLLM >> 2);
  _DAT_0080c774 = (short)((int)(uint)_DAT_00807cdc >> 2);
  return (int)(uint)_DAT_00807cdc >> 2;
}



//
// Function: engineRpmSourceInit @ 0x000137ac
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engineRpmSourceInit(void)

{
  _DAT_00800284 = 0;
  _DAT_00800280 = &CCMXFLLM;
  _DAT_0080c772 = CCMNFLLM;
  _DAT_0080c78e = &LAB_000137d8;
  circular_buffer_t_0080c3fc.data_buffer_rest[0x20] = 0;
  circular_buffer_t_0080c3fc.data_buffer_rest[0x21] = 0;
  return;
}



//
// Function: canControllerConfigInit @ 0x00013890
//

void canControllerConfigInit(void)

{
  switch(DAT_00807cf7) {
  case 0:
    can1TimerBufferInit();
    delayWithWatchdogServiceWrapper();
    emptyStubFunction5();
    return;
  case 1:
    can1TimerBufferInitAlt();
    can1MessageTransmitInit();
    emptyStubFunction6();
    return;
  case 2:
    can1TimerBufferInitDivided();
    can1MessageTransmitInit2();
    emptyStubFunction7();
    return;
  case 3:
    can1TimerBufferInitConditional();
    delayWithWatchdogServiceWrapper2();
    emptyStubFunction8();
  }
  return;
}



//
// Function: canRpmModeConfigInit @ 0x000138fe
//

void canRpmModeConfigInit(void)

{
  if (CPMNFL == 1) {
    dutyCycleMonitorCanInit();
    return;
  }
  if (CPMNFL != 2) {
    if (CPMNFL != 0) {
      return;
    }
    dutyCycleMonitorAltCanInit();
    return;
  }
  dutyCycleMonitorBufferInit();
  return;
}



//
// Function: rpmBasedFuelLimitCalculator @ 0x00013930
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rpmBasedFuelLimitCalculator(void)

{
  if (((engine_operating_mode_t_0080c810.state == 2) ||
      (engine_operating_mode_t_0080c810.state == 6)) ||
     (engine_operating_mode_t_0080c810.state == 7)) {
    _DAT_0080c800 = _DAT_0080c80e + _DAT_0080c802;
    if (_DAT_00807d3e < _DAT_0080c800) {
      _DAT_0080c800 = _DAT_00807d3e;
    }
    _DAT_0080c7fe = _DAT_0080c80c + _DAT_0080c7f6;
    if (_DAT_00807d3a < _DAT_0080c7fe) {
      _DAT_0080c7fe = _DAT_00807d3a;
    }
    if (circular_buffer_t_0080c3fc.data_buffer_8 < _DAT_0080c800) {
      _DAT_0080c7e8 = _DAT_0080c7fe;
      return;
    }
    if ((_DAT_0080c800 <= circular_buffer_t_0080c3fc.data_buffer_8) &&
       (circular_buffer_t_0080c3fc.data_buffer_8 <= _DAT_0080c7fc)) {
      _DAT_0080c7e8 =
           (short)((((uint)circular_buffer_t_0080c3fc.data_buffer_8 - (uint)_DAT_0080c800) *
                   ((uint)_DAT_0080c806 + (uint)_DAT_00807d36)) /
                  (uint)(ushort)(_DAT_0080c7fc - _DAT_0080c800)) +
           (short)(((uint)_DAT_0080c7fe *
                   ((uint)_DAT_0080c7fc - (uint)circular_buffer_t_0080c3fc.data_buffer_8)) /
                  (uint)(ushort)(_DAT_0080c7fc - _DAT_0080c800));
    }
  }
  return;
}



//
// Function: fuelTimingModeBlendCalculator @ 0x00013a1e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelTimingModeBlendCalculator(void)

{
  short sVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if (timing_mode_control_t_0080965a.blend_factor == 0x4000) {
    _DAT_008002a8 = _DAT_0080c7fc;
    _DAT_008002b0 = _DAT_0080c806 + _DAT_00807d36;
    uVar2 = tableInterpolationLookup((short *)&DAT_008002a2);
    _DAT_0080c7ec = (short)((ulonglong)uVar2 >> 0x20);
  }
  else if (timing_mode_control_t_0080965a.blend_factor == 0) {
    _DAT_008002bc = _DAT_0080c7fc;
    _DAT_008002c4 = _DAT_0080c806 + _DAT_00807d36;
    uVar2 = tableInterpolationLookup((short *)&DAT_008002b6);
    _DAT_0080c7ec =
         (short)((uint)(ushort)((ulonglong)uVar2 >> 0x20) *
                 (0x4000 - (uint)timing_mode_control_t_0080965a.blend_factor) >> 0xe);
  }
  else {
    _DAT_008002a8 = _DAT_0080c7fc;
    _DAT_008002b0 = _DAT_0080c806 + _DAT_00807d36;
    uVar2 = tableInterpolationLookup((short *)&DAT_008002a2);
    _DAT_008002bc = _DAT_0080c7fc;
    _DAT_008002c4 = _DAT_0080c806 + _DAT_00807d36;
    uVar3 = tableInterpolationLookup((short *)&DAT_008002b6);
    _DAT_0080c7ec =
         (short)((uint)timing_mode_control_t_0080965a.blend_factor *
                 (uint)(ushort)((ulonglong)uVar2 >> 0x20) >> 0xe) +
         (short)((uint)(ushort)((ulonglong)uVar3 >> 0x20) *
                 (0x4000 - (uint)timing_mode_control_t_0080965a.blend_factor) >> 0xe);
  }
  if ((uint)_DAT_0080c806 + (uint)_DAT_00807d36 < (uint)_DAT_00808a84) {
    _DAT_0080029c = _DAT_008091ea;
    sVar1 = lookupTableInterpolation((short *)&DAT_00800296);
    _DAT_0080c7f4 =
         sVar1 - (short)((int)((int)&DAT_00004caa - (uint)_DAT_00807d2c) / (int)_DAT_00808a82);
    if ((short)_DAT_0080c7f4 < 0) {
      _DAT_0080c7f4 = 0;
    }
  }
  else {
    _DAT_0080c7f4 = 0;
  }
  _DAT_00800290 = _DAT_0080926e;
  _DAT_0080c7f2 = lookupTableInterpolation((short *)&DAT_0080028a);
  if ((ushort)(_DAT_0080c7f2 + _DAT_0080c7ec) <= _DAT_0080c7f4) {
    _DAT_0080c808 = _DAT_0080c7f4;
    return;
  }
  _DAT_0080c808 = _DAT_0080c7f2 + _DAT_0080c7ec;
  return;
}



//
// Function: rpmBasedFuelTimingInterpolation @ 0x00013bd8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rpmBasedFuelTimingInterpolation(void)

{
  if (((engine_operating_mode_t_0080c810.state == 2) ||
      (engine_operating_mode_t_0080c810.state == 6)) ||
     (engine_operating_mode_t_0080c810.state == 7)) {
    fuelTimingModeBlendCalculator();
    if (circular_buffer_t_0080c3fc.data_buffer_8 < _DAT_0080c804) {
      _DAT_0080c7ea = _DAT_0080c7f8;
      return;
    }
    if ((_DAT_0080c804 <= circular_buffer_t_0080c3fc.data_buffer_8) &&
       (circular_buffer_t_0080c3fc.data_buffer_8 <= _DAT_0080c7fc)) {
      _DAT_0080c7ea =
           _DAT_0080c7f8 +
           (short)(((int)(short)(_DAT_0080c808 - _DAT_0080c7f8) *
                   (int)(short)(circular_buffer_t_0080c3fc.data_buffer_8 - _DAT_0080c804)) /
                  (int)(short)(_DAT_0080c7fc - _DAT_0080c804));
    }
  }
  return;
}



//
// Function: frictionalLoadInterpolationCalculator @ 0x00013c6a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint frictionalLoadInterpolationCalculator(void)

{
  ushort uVar1;
  undefined2 uVar2;
  uint in_D0;
  uint uVar3;
  
  uVar3 = in_D0 & 0xffff0000;
  if (((fault_status_registers_t_00805df2.engine_fault_status & 1) == 0) ||
     (uVar3 = CONCAT22((short)(in_D0 >> 0x10),_DAT_008068c8) & 0xffff0001, (_DAT_008068c8 & 1) == 0)
     ) {
    uVar2 = (undefined2)(uVar3 >> 0x10);
    uVar3 = CONCAT22(uVar2,fault_status_registers_t_00805df2.engine_fault_status) & 0xffff0002;
    if ((((fault_status_registers_t_00805df2.engine_fault_status & 2) == 0) ||
        (uVar3 = CONCAT22(uVar2,_DAT_008068c8) & 0xffff0002, (_DAT_008068c8 & 2) == 0)) &&
       (_DAT_00807d30 <= _DAT_0080926e)) {
      if (_DAT_00807d2e < _DAT_0080926e) {
        _DAT_0080c7f6 = _DAT_00807d38;
        _DAT_0080c802 = _DAT_00807d3c;
        return uVar3;
      }
      uVar1 = _DAT_00807d2e - _DAT_00807d30;
      _DAT_0080c7f6 =
           (short)((((uint)_DAT_00807d2e - (uint)_DAT_0080926e) * (uint)_DAT_00807d3a) / (uint)uVar1
                  ) +
           (short)((((uint)_DAT_0080926e - (uint)_DAT_00807d30) * (uint)_DAT_00807d38) / (uint)uVar1
                  );
      uVar3 = (((uint)_DAT_00807d2e - (uint)_DAT_0080926e) * (uint)_DAT_00807d3e) / (uint)uVar1;
      _DAT_0080c802 =
           (short)uVar3 +
           (short)((((uint)_DAT_0080926e - (uint)_DAT_00807d30) * (uint)_DAT_00807d3c) / (uint)uVar1
                  );
      return uVar3;
    }
  }
  _DAT_0080c7f6 = _DAT_00807d3a;
  _DAT_0080c802 = _DAT_00807d3e;
  return uVar3;
}



//
// Function: rpmSourceSelectorForFrictionalLoad @ 0x00013d66
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rpmSourceSelectorForFrictionalLoad(void)

{
  if (_DAT_008037f2 == 1) {
    _DAT_0080c7fc = _DAT_00807d2c;
    return;
  }
  _DAT_0080c7fc = _DAT_0080d092;
  return;
}



//
// Function: frictionalLoadTorqueInterpolator @ 0x00013d86
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint frictionalLoadTorqueInterpolator(void)

{
  ushort uVar1;
  undefined2 uVar2;
  uint in_D0;
  uint uVar3;
  
  uVar3 = in_D0 & 0xffff0000;
  if (((fault_status_registers_t_00805df2.sensor_fault_status & 0x2000) == 0) ||
     (uVar3 = CONCAT22((short)(in_D0 >> 0x10),_DAT_008068c4) & 0xffff2000,
     (_DAT_008068c4 & 0x2000) == 0)) {
    uVar2 = (undefined2)(uVar3 >> 0x10);
    uVar3 = CONCAT22(uVar2,fault_status_registers_t_00805df2.sensor_fault_status) & 0xffff4000;
    if ((((fault_status_registers_t_00805df2.sensor_fault_status & 0x4000) == 0) ||
        (uVar3 = CONCAT22(uVar2,_DAT_008068c4) & 0xffff4000, (_DAT_008068c4 & 0x4000) == 0)) &&
       (_DAT_00807d34 <= _DAT_008091ea)) {
      if (_DAT_00807d32 < _DAT_008091ea) {
        _DAT_0080c7f8 = _DAT_00807d40;
        _DAT_0080c804 = _DAT_00807d44;
        return uVar3;
      }
      uVar1 = _DAT_00807d32 - _DAT_00807d34;
      _DAT_0080c7f8 =
           (short)((((uint)_DAT_00807d32 - (uint)_DAT_008091ea) * (uint)_DAT_00807d42) / (uint)uVar1
                  ) +
           (short)((((uint)_DAT_008091ea - (uint)_DAT_00807d34) * (uint)_DAT_00807d40) / (uint)uVar1
                  );
      uVar3 = (((uint)_DAT_00807d32 - (uint)_DAT_008091ea) * (uint)_DAT_00807d46) / (uint)uVar1;
      _DAT_0080c804 =
           (short)uVar3 +
           (short)((((uint)_DAT_008091ea - (uint)_DAT_00807d34) * (uint)_DAT_00807d44) / (uint)uVar1
                  );
      return uVar3;
    }
  }
  _DAT_0080c7f8 = _DAT_00807d42;
  _DAT_0080c804 = _DAT_00807d46;
  return uVar3;
}



//
// Function: peakTorqueFuelCorrection @ 0x00013e82
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void peakTorqueFuelCorrection(void)

{
  if ((_DAT_00807d52 < _DAT_0080c7ee) && (_DAT_00800288 == 0)) {
    _DAT_0080c7fa = _DAT_00807d4a + _DAT_00807d48;
    _DAT_00800288 = 1;
  }
  if (circular_buffer_t_0080c3fc.data_buffer_8 == 0) {
    _DAT_0080c7fa = _DAT_00807d48;
  }
  _DAT_008002ca = engine_operating_mode_t_0080c810.state;
  return;
}



//
// Function: engineModeTransitionStateUpdater @ 0x00013ecc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engineModeTransitionStateUpdater(void)

{
  if (((engine_operating_mode_t_0080c810.state == 2) ||
      (engine_operating_mode_t_0080c810.state == 6)) ||
     (engine_operating_mode_t_0080c810.state == 7)) {
    _DAT_0080c80a = fuel_demand_state_t_0080c9a4.limit_minimum;
    fuel_demand_state_t_0080c9a4.limit_minimum = _DAT_0080c7ea;
    fuel_demand_state_t_0080c9a4.demand_source_id = 5;
    fuel_demand_state_t_0080c9a4.adjustment_active = 0;
  }
  return;
}



//
// Function: engineModeTransitionHandler @ 0x00013f06
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engineModeTransitionHandler(void)

{
  if (((_DAT_008002cc == 1) && (engine_operating_mode_t_0080c810.state == 2)) ||
     ((_DAT_008002cc == 3 && (engine_operating_mode_t_0080c810.state == 7)))) {
    frictionalLoadInterpolationCalculator();
    frictionalLoadTorqueInterpolator();
    rpmSourceSelectorForFrictionalLoad();
  }
  peakTorqueFuelCorrection();
  _DAT_008002cc = engine_operating_mode_t_0080c810.state;
  return;
}



//
// Function: shutdownProtectionSlowCycle40Coordinator @ 0x00013f46
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void shutdownProtectionSlowCycle40Coordinator(void)

{
  if ((engine_operating_mode_t_0080c810.state == 6) &&
     (circular_buffer_t_0080c3fc.data_buffer_8 < _DAT_0080c800)) {
    if ((int)(uint)_DAT_00807d4e < (int)((uint)_DAT_00807f3c - (uint)_DAT_0080c80c)) {
      _DAT_0080c80c = _DAT_00807d4e + _DAT_0080c80c;
    }
    else {
      _DAT_0080c80c = _DAT_00807f3c;
    }
    if ((int)(uint)_DAT_00807d50 < (int)((uint)_DAT_008037b4 - (uint)_DAT_0080c80e)) {
      _DAT_0080c80e = _DAT_00807d50 + _DAT_0080c80e;
    }
    else {
      _DAT_0080c80e = _DAT_008037b4;
    }
  }
  if ((_DAT_008002ce == 7) && (engine_operating_mode_t_0080c810.state == 1)) {
    _DAT_0080c80c = 0;
    _DAT_0080c80e = 0;
  }
  _DAT_008002ce = engine_operating_mode_t_0080c810.state;
  return;
}



//
// Function: frictionalLoadTorqueManagementSlowCycle40Coordinator @ 0x00013fe2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void frictionalLoadTorqueManagementSlowCycle40Coordinator(void)

{
  if ((((engine_operating_mode_t_0080c810.state == 2) ||
       (engine_operating_mode_t_0080c810.state == 6)) &&
      (_DAT_00807d58 < circular_buffer_t_0080c3fc.data_buffer_8)) &&
     (_DAT_0080c806 = _DAT_00807d5a + _DAT_0080c806, _DAT_00807d5c < _DAT_0080c806)) {
    _DAT_0080c806 = _DAT_00807d5c;
  }
  if ((_DAT_008002d0 != 3) && (engine_operating_mode_t_0080c810.state == 3)) {
    _DAT_0080c806 = 0;
  }
  _DAT_008002d0 = engine_operating_mode_t_0080c810.state;
  return;
}



//
// Function: engineOperatingModeStateTrackingSlowCycle40Coordinator @ 0x0001403e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engineOperatingModeStateTrackingSlowCycle40Coordinator(void)

{
  if (engine_operating_mode_t_0080c810.state == 3) {
    _DAT_0080c7ee = _DAT_0080c7ee + 1;
  }
  if (engine_operating_mode_t_0080c810.state == 1) {
    _DAT_0080c7ee = 0;
    _DAT_00800288 = 0;
  }
  if (engine_operating_mode_t_0080c810.state == 2) {
    _DAT_0080c7f0 = _DAT_0080c7f0 + 1;
  }
  else if ((_DAT_008002d2 == 7) && (engine_operating_mode_t_0080c810.state == 1)) {
    _DAT_0080c7f0 = 0;
  }
  _DAT_008002d2 = engine_operating_mode_t_0080c810.state;
  return;
}



//
// Function: frictionalLoadTorqueTransitionHandler @ 0x00014090
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void frictionalLoadTorqueTransitionHandler(void)

{
  if (((_DAT_008002d4 == 3) && (engine_operating_mode_t_0080c810.state == 7)) &&
     (_DAT_00807d52 < _DAT_0080c7ee)) {
    _DAT_0080c80c = _DAT_00807d54;
    _DAT_0080c80e = _DAT_00807d56;
  }
  _DAT_008002d4 = engine_operating_mode_t_0080c810.state;
  return;
}



//
// Function: initLoadTrendingSystem @ 0x000140ce
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initLoadTrendingSystem(void)

{
  _DAT_0080028c = 0x8079ee;
  _DAT_00800292 = &ACVSACCO;
  _DAT_0080028a = 2;
  _DAT_00800298 = 0x808a86;
  _DAT_0080029e = 0x808a9c;
  _DAT_00800296 = 2;
  _DAT_008002a4 = 0x8080c2;
  _DAT_008002a2 = 2;
  _DAT_008002ac = 0x8080e8;
  _DAT_008002aa = 2;
  _DAT_008002b2 = 0x808100;
  _DAT_008002b8 = 0x80828c;
  _DAT_008002b6 = 2;
  _DAT_008002c0 = 0x8082b2;
  _DAT_008002be = 2;
  _DAT_008002c6 = 0x8082ca;
  return;
}



//
// Function: engineOperatingModeStateMachine @ 0x00014174
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engineOperatingModeStateMachine(void)

{
  switch(engine_operating_mode_t_0080c810.state) {
  case 1:
    if ((_DAT_00807d64 < circular_buffer_t_0080c3fc.data_buffer_8) && (_DAT_00804d84 == 0)) {
      engine_operating_mode_t_0080c810.state = 2;
    }
    else if ((((DAT_0080bdc6 & 1) == 0) && (_DAT_0080d450 == 0)) || (_DAT_0080c996 == 1)) {
      engine_operating_mode_t_0080c810.state = 8;
    }
    break;
  case 2:
    if (_DAT_00807d64 < circular_buffer_t_0080c3fc.data_buffer_8) {
      if (circular_buffer_t_0080c3fc.data_buffer_8 < _DAT_0080c7fc) {
        if (_DAT_00807d4c < _DAT_0080c7f0) {
          engine_operating_mode_t_0080c810.state = 6;
        }
        else if ((((DAT_0080bdc6 & 1) == 0) && (_DAT_0080d450 == 0)) || (_DAT_0080c996 == 1)) {
          engine_operating_mode_t_0080c810.state = 8;
        }
      }
      else {
        engine_operating_mode_t_0080c810.state = 3;
      }
    }
    else {
      engine_operating_mode_t_0080c810.state = 1;
    }
    break;
  case 3:
    if (_DAT_0080969e == 1) {
      engine_operating_mode_t_0080c810.state = 4;
    }
    else if (_DAT_0080c7fa < circular_buffer_t_0080c3fc.data_buffer_8) {
      if ((((DAT_0080bdc6 & 1) == 0) && (_DAT_0080d450 == 0)) || (_DAT_0080c996 == 1)) {
        engine_operating_mode_t_0080c810.state = 8;
      }
      else if (circular_buffer_t_0080c3fc.data_buffer_8 < _DAT_00807d5e) {
        _DAT_008002d6 = 0;
      }
      else {
        _DAT_008002d6 = _DAT_008002d6 + 1;
        if (_DAT_00807d62 < _DAT_008002d6) {
          engine_operating_mode_t_0080c810.state = 5;
          _DAT_008002d6 = 0;
        }
      }
    }
    else {
      engine_operating_mode_t_0080c810.state = 7;
    }
    break;
  case 4:
    if (_DAT_0080969e == 0) {
      engine_operating_mode_t_0080c810.state = 3;
    }
    else if ((((DAT_0080bdc6 & 1) == 0) && (_DAT_0080d450 == 0)) || (_DAT_0080c996 == 1)) {
      engine_operating_mode_t_0080c810.state = 8;
    }
    break;
  case 5:
    if (circular_buffer_t_0080c3fc.data_buffer_8 < _DAT_00807d60) {
      engine_operating_mode_t_0080c810.state = 3;
    }
    else if ((((DAT_0080bdc6 & 1) == 0) && (_DAT_0080d450 == 0)) || (_DAT_0080c996 == 1)) {
      engine_operating_mode_t_0080c810.state = 8;
    }
    fault_status_registers_t_00805df2.engine_fault_status =
         fault_status_registers_t_00805df2.engine_fault_status | 0x8000;
    fault_latch_registers_t_00805e32.engine_fault_latch =
         fault_latch_registers_t_00805e32.engine_fault_latch | 0x8000;
    if (_DAT_00804d80 == 0) {
      _DAT_00804d80 = 1;
      *(undefined4 *)((short)_DAT_00804d82 * 8 + 0x804c68) = _DAT_0080d4c4;
      *(undefined2 *)((short)_DAT_00804d82 * 8 + 0x804c6e) = 0;
      *(word *)((short)_DAT_00804d82 * 8 + 0x804c6c) = circular_buffer_t_0080c3fc.data_buffer_8;
    }
    else if (*(ushort *)((short)_DAT_00804d82 * 8 + 0x804c6c) <
             circular_buffer_t_0080c3fc.data_buffer_8) {
      *(word *)((short)_DAT_00804d82 * 8 + 0x804c6c) = circular_buffer_t_0080c3fc.data_buffer_8;
    }
    break;
  case 6:
    if (_DAT_00807d64 < circular_buffer_t_0080c3fc.data_buffer_8) {
      if (circular_buffer_t_0080c3fc.data_buffer_8 < _DAT_0080c7fc) {
        if ((((DAT_0080bdc6 & 1) == 0) && (_DAT_0080d450 == 0)) || (_DAT_0080c996 == 1)) {
          engine_operating_mode_t_0080c810.state = 8;
        }
      }
      else {
        engine_operating_mode_t_0080c810.state = 3;
      }
    }
    else {
      engine_operating_mode_t_0080c810.state = 1;
    }
    break;
  case 7:
    if (_DAT_00807d64 < circular_buffer_t_0080c3fc.data_buffer_8) {
      if (circular_buffer_t_0080c3fc.data_buffer_8 < _DAT_0080c7fc) {
        if ((((DAT_0080bdc6 & 1) == 0) && (_DAT_0080d450 == 0)) || (_DAT_0080c996 == 1)) {
          engine_operating_mode_t_0080c810.state = 8;
        }
      }
      else {
        engine_operating_mode_t_0080c810.state = 3;
      }
    }
    else {
      engine_operating_mode_t_0080c810.state = 1;
    }
    break;
  case 8:
    if ((((_DAT_0080c996 == 1) && (circular_buffer_t_0080c3fc.data_buffer_8 == 0)) ||
        ((_DAT_0080c996 == 0 && ((DAT_0080bdc6 & 1) != 0)))) &&
       ((engine_operating_mode_t_0080c810.state = 1, circular_buffer_t_0080c3fc.data_buffer_8 == 0
        && (_DAT_0080c996 == 1)))) {
      _DAT_0080c996 = 0;
    }
    if (((circular_buffer_t_0080c3fc.data_buffer_8 == 0) && ((DAT_0080bdc6 & 1) == 0)) &&
       (_DAT_0080d450 == 0)) {
      engine_operating_mode_t_0080c810.shutdown_complete_flag = 1;
    }
    break;
  default:
    engine_operating_mode_t_0080c810.state = 1;
  }
  if (((engine_operating_mode_t_0080c810.state != 5) &&
      ((fault_status_registers_t_00805df2.engine_fault_status & 0x8000) != 0)) &&
     ((fault_latch_registers_t_00805e32.engine_fault_latch & 0x8000) == 0)) {
    fault_status_registers_t_00805df2.engine_fault_status =
         fault_status_registers_t_00805df2.engine_fault_status & 0x7fff;
    *(short *)((short)_DAT_00804d82 * 8 + 0x804c6e) =
         _DAT_0080d4c6 - *(short *)((short)_DAT_00804d82 * 8 + 0x804c6a);
    _DAT_00804d80 = 0;
    _DAT_00804d82 = (ushort)(_DAT_00804d82 + 1) % 5;
  }
  if (((DAT_0080bdc6 & 1) != 0) && (DAT_008002d8 == '\0')) {
    _DAT_0080d450 = 0;
  }
  DAT_008002d8 = -((DAT_0080bdc6 & 1) != 0) & 1;
  return;
}



//
// Function: engineOperatingModeInit @ 0x00014536
//

void engineOperatingModeInit(void)

{
  engine_operating_mode_t_0080c810.state = 1;
  DAT_008002d8 = 0;
  return;
}



//
// Function: engineProtectionMultiStateSlowCycle40Coordinator @ 0x00014546
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort engineProtectionMultiStateSlowCycle40Coordinator(void)

{
  ushort uVar1;
  
  if ((engine_control_flags_t_008035d6.protection_system & 0x10) == 0) {
    _DAT_0080c992 = _DAT_008037b4;
    _DAT_0080c98e = _DAT_00807f3c;
    _DAT_0080c990 = 0;
    _DAT_0080c998 = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = _DAT_008002da;
    switch(_DAT_008002da) {
    case 0:
      uVar1 = protectionState0FaultDurationCounter();
      break;
    case 1:
      uVar1 = protectionState1DiagnosticValidator();
      break;
    case 2:
      uVar1 = protectionState2ThresholdCalculator();
      break;
    case 3:
      protectionState3aPrimaryCoordinator();
      uVar1 = protectionState3bRpmMonitor();
      break;
    case 4:
      uVar1 = protectionState4EmergencyHandler();
    }
    _DAT_008002da = _DAT_008002da + 1;
    if (4 < _DAT_008002da) {
      _DAT_008002da = 0;
      return uVar1;
    }
  }
  return uVar1;
}



//
// Function: protectionThresholdCalculationHelper @ 0x000145d4
//

ushort protectionThresholdCalculationHelper
                 (int param_1,int param_2,ushort *param_3,undefined4 param_4)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  
  if (param_4._0_2_ == 0) {
    uVar3 = *param_3;
    uVar1 = *(ushort *)(param_2 + 6);
    uVar2 = *(ushort *)(param_1 + 2);
    uVar4 = *(ushort *)(param_1 + 6);
  }
  else {
    uVar3 = param_3[1];
    uVar1 = *(ushort *)(param_2 + 8);
    uVar2 = *(ushort *)(param_1 + 4);
    uVar4 = *(ushort *)(param_1 + 8);
  }
  if (uVar2 < uVar1) {
    uVar4 = uVar4 + uVar3;
    if (0x100 < uVar4) {
      uVar4 = 0x100;
    }
  }
  else if (uVar4 < uVar3) {
    uVar4 = uVar3 - uVar4;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}



//
// Function: protectionPercentageCalculator @ 0x0001462e
//

undefined4 protectionPercentageCalculator(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  short sVar2;
  
  iVar1 = ((int)(short)(param_1._0_2_ - param_1._2_2_) << 8) /
          (int)(short)(param_2._0_2_ - param_1._2_2_);
  sVar2 = (short)iVar1;
  if (sVar2 < 0x101) {
    if (sVar2 < 0) {
      sVar2 = 0;
    }
  }
  else {
    sVar2 = 0x100;
  }
  return CONCAT22((short)((uint)iVar1 >> 0x10),sVar2);
}



//
// Function: engineProtectionSystemInit @ 0x00014664
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engineProtectionSystemInit(void)

{
  _DAT_0080c814 = &DAT_0080bdc8;
  _DAT_0080c818 = 0x2000;
  _DAT_0080c83a = 0x804c90;
  _DAT_0080c842 = &DAT_0080926e;
  _DAT_0080c84c = &DAT_00807d90;
  _DAT_0080c850 = &DAT_00807d92;
  _DAT_0080c854 = &DAT_00807d94;
  _DAT_0080c868 = 0x804cb8;
  _DAT_0080c86c = 0x804cb8;
  _DAT_0080c870 = &DAT_0080976a;
  _DAT_0080c87a = 0x807db0;
  _DAT_0080c87e = 0x807db2;
  _DAT_0080c882 = 0x807db4;
  _DAT_0080c896 = 0x804ce0;
  _DAT_0080c89a = 0x804ce0;
  _DAT_0080c89e = &DAT_00809242;
  _DAT_0080c8a8 = &DAT_0080d058;
  _DAT_0080c8b0 = &DAT_0080d05a;
  _DAT_0080c8c4 = 0x804d08;
  _DAT_0080c8c8 = 0x804d30;
  _DAT_0080c8cc = &DAT_008092b0;
  _DAT_0080c8d6 = 0x807df0;
  _DAT_0080c8da = 0x807df2;
  _DAT_0080c8f2 = 0x804d58;
  _DAT_0080c8fa = 0x80c98c;
  _DAT_0080c904 = 0x80c988;
  _DAT_0080c956 = &DAT_00809200;
  _DAT_0080c960 = 0x807e50;
  protectionThresholdPointerInit();
  initShutdownLimitVariables();
  _DAT_008002da = 0;
  return;
}



//
// Function: protectionConditionEvaluator @ 0x000147b6
//

uint protectionConditionEvaluator(ushort *param_1,undefined4 *param_2,undefined4 param_3)

{
  ushort uVar1;
  ushort uVar2;
  uint in_D0;
  uint uVar3;
  ushort unaff_D3w;
  
  uVar1 = *param_1;
  if ((uVar1 & 0x30) == 0) {
    uVar2 = *(ushort *)*param_2;
    if (param_3._0_2_ == 0) {
      if (param_3._2_2_ == 0) {
        unaff_D3w = **(ushort **)((int)param_2 + 10);
      }
      else if (param_3._2_2_ == 2) {
        unaff_D3w = param_1[8];
      }
    }
    else if (param_3._2_2_ == 0) {
      unaff_D3w = **(ushort **)((int)param_2 + 0x12);
    }
    else if (param_3._2_2_ == 2) {
      unaff_D3w = param_1[9];
    }
    uVar3 = in_D0 & 0xffff0000;
    if ((uVar1 & 4) == 0) {
      if (uVar2 < unaff_D3w) {
        return 1;
      }
    }
    else if (unaff_D3w <= uVar2) {
      return 1;
    }
  }
  else {
    uVar3 = (byte)-((*(ushort *)(param_2 + 1) & *(ushort *)*param_2) != 0) & 1;
    if (uVar3 == ((byte)-((uVar1 & 0x10) != 0) & 1)) {
      return 1;
    }
  }
  return uVar3 & 0xffff0000;
}



//
// Function: protectionState0FaultDurationCounter @ 0x0001485a
//

void protectionState0FaultDurationCounter(void)

{
  ushort uVar1;
  uint uVar2;
  undefined4 *puVar3;
  ushort *puVar4;
  
  puVar3 = (undefined4 *)&DAT_0080c814;
  for (puVar4 = (ushort *)&DAT_00807d66; puVar4 < &DAT_00807e66; puVar4 = puVar4 + 0x10) {
    if (*(short *)((int)puVar3 + 0x16) == 0) {
      *(undefined2 *)((int)puVar3 + 6) = 0;
      *(undefined2 *)(puVar3 + 2) = 0;
    }
    else {
      uVar1 = *puVar4;
      if ((uVar1 & 0x101) != 0) {
        uVar2 = protectionConditionEvaluator(puVar4,puVar3,0);
        if ((short)uVar2 == 0) {
          *(undefined2 *)((int)puVar3 + 6) = 0;
        }
        else if (*(short *)((int)puVar3 + 6) != -1) {
          *(short *)((int)puVar3 + 6) = *(short *)((int)puVar3 + 6) + 1;
        }
      }
      if ((uVar1 & 0x402) != 0) {
        uVar2 = protectionConditionEvaluator(puVar4,puVar3,0x10000);
        if ((short)uVar2 == 0) {
          *(undefined2 *)(puVar3 + 2) = 0;
        }
        else if (*(short *)(puVar3 + 2) != -1) {
          *(short *)(puVar3 + 2) = *(short *)(puVar3 + 2) + 1;
        }
      }
    }
    puVar3 = (undefined4 *)((int)puVar3 + 0x2e);
  }
  return;
}



//
// Function: diagnosticProtectionEvaluator @ 0x000148f8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint diagnosticProtectionEvaluator(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  ushort *puVar4;
  
  uVar3 = engine_control_flags_t_008035d6.protection_system & 0x10;
  if ((((((engine_control_flags_t_008035d6.protection_system & 0x10) != 0) &&
        (uVar3 = engine_control_flags_t_008035d6.protection_system & 1,
        (engine_control_flags_t_008035d6.protection_system & 1) != 0)) &&
       (uVar3 = engine_control_flags_t_008035d6.protection_system & 0x20,
       (engine_control_flags_t_008035d6.protection_system & 0x20) != 0)) &&
      ((_DAT_00804e76 != 0xff && (_DAT_00804e76 != 3)))) &&
     (uVar3 = (uint)_DAT_00804e78, _DAT_00807e70 <= _DAT_00804e78)) {
    puVar4 = (ushort *)(&DAT_00807d66 + _DAT_00804e76 * 0x20);
    iVar2 = _DAT_00804e76 * 0x2e;
    uVar1 = _DAT_00804e76 * 4 + 0x70;
    uVar3 = (uint)*(ushort *)(&DAT_008035d4 + (short)((int)(uVar1 + 2) >> 4) * 2) &
            1 << (uVar1 + 2) % 0x10;
    if ((uVar3 != 0) &&
       (uVar3 = (uint)*(ushort *)(&DAT_008035d4 + (short)((int)(uVar1 + 3) >> 4) * 2) &
                1 << (uVar1 + 3) % 0x10, uVar3 != 0)) {
      uVar1 = *puVar4;
      uVar3 = 0;
      if ((uVar1 & 1) != 0) {
        uVar3 = protectionConditionEvaluator(puVar4,(undefined4 *)(&DAT_0080c814 + iVar2),0);
        if ((short)uVar3 != 0) {
          *(undefined2 *)(&DAT_0080c82c + iVar2) = 1;
          _DAT_0080c994 = 1;
        }
      }
      uVar3 = CONCAT22((short)(uVar3 >> 0x10),uVar1) & 0xffff0002;
      if ((uVar1 & 2) != 0) {
        uVar3 = protectionConditionEvaluator(puVar4,(undefined4 *)(&DAT_0080c814 + iVar2),0x10000);
        if ((short)uVar3 != 0) {
          *(undefined2 *)(&DAT_0080c82c + iVar2) = 1;
          _DAT_0080c994 = 1;
        }
      }
    }
  }
  return uVar3;
}



//
// Function: diagnosticProtectionProcessor @ 0x00014a4a
//

uint diagnosticProtectionProcessor(ushort *param_1,undefined4 *param_2,int param_3)

{
  ushort uVar1;
  uint in_D0;
  uint uVar2;
  undefined4 unaff_D2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((uint)unaff_D2 >> 0x10);
  uVar1 = *param_1;
  uVar2 = in_D0 & 0xffff0000;
  if ((uVar1 & 1) != 0) {
    uVar2 = protectionConditionEvaluator(param_1,param_2,0);
    if ((short)uVar2 == 0) {
      *(undefined2 *)(param_3 + 4) = 0;
    }
    else {
      uVar2 = uVar2 & 0xffff0000;
      if ((uVar1 & 0x40) == 0) {
        uVar2 = protectionPercentageCalculator
                          (CONCAT22(*(undefined2 *)*param_2,**(undefined2 **)((int)param_2 + 10)),
                           CONCAT22(**(undefined2 **)((int)param_2 + 0xe),uVar3));
        *(short *)(param_3 + 4) = (short)uVar2;
      }
      else {
        *(undefined2 *)(param_3 + 4) = 0x100;
      }
    }
  }
  uVar2 = CONCAT22((short)(uVar2 >> 0x10),uVar1) & 0xffff0002;
  if ((uVar1 & 2) != 0) {
    uVar2 = protectionConditionEvaluator(param_1,param_2,0x10000);
    if ((short)uVar2 == 0) {
      *(undefined2 *)(param_3 + 6) = 0;
      return uVar2;
    }
    *(undefined2 *)(param_3 + 6) = 0x100;
  }
  return uVar2;
}



//
// Function: protectionState1DiagnosticValidator @ 0x00014ae4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort protectionState1DiagnosticValidator(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  undefined *puVar4;
  ushort *puVar5;
  undefined4 *puVar6;
  
  uVar1 = engine_control_flags_t_008035d6.protection_system & 1;
  if ((((engine_control_flags_t_008035d6.protection_system & 1) != 0) &&
      (uVar1 = engine_control_flags_t_008035d6.protection_system & 0x20,
      (engine_control_flags_t_008035d6.protection_system & 0x20) != 0)) && (_DAT_00804e76 != 0xff))
  {
    puVar6 = (undefined4 *)&DAT_0080c814;
    puVar4 = &DAT_00804d86;
    uVar2 = 0x70;
    uVar3 = 0;
    for (puVar5 = (ushort *)&DAT_00807d66; puVar5 < &DAT_00807e66; puVar5 = puVar5 + 0x10) {
      if ((((int)_DAT_00804e76 == (uint)uVar3) &&
          (((uint)*(ushort *)(&DAT_008035d4 + (short)((int)(uVar2 + 2) >> 4) * 2) &
           1 << (uVar2 + 2) % 0x10) != 0)) &&
         (((uint)*(ushort *)(&DAT_008035d4 + (short)((int)(uVar2 + 3) >> 4) * 2) &
          1 << (uVar2 + 3) % 0x10) != 0)) {
        diagnosticProtectionProcessor(puVar5,puVar6,(int)puVar4);
        protectionUpdateHandler();
      }
      else {
        *(undefined2 *)(puVar4 + 4) = 0;
        *(undefined2 *)(puVar4 + 6) = 0;
      }
      puVar6 = (undefined4 *)((int)puVar6 + 0x2e);
      uVar1 = 0x1e;
      puVar4 = puVar4 + 0x1e;
      uVar2 = uVar2 + 4;
      uVar3 = uVar3 + 1;
    }
  }
  return uVar1;
}



//
// Function: protectionUpdateHandler @ 0x00014bdc
// ERROR: Failed to decompile
//

//
// Function: protectionState3aPrimaryCoordinator @ 0x00014c3a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void protectionState3aPrimaryCoordinator(void)

{
  ushort uVar1;
  undefined4 unaff_D2;
  uint uVar2;
  ushort uVar3;
  ushort *puVar4;
  ushort *puVar5;
  undefined *puVar6;
  undefined2 uVar7;
  
  uVar7 = (undefined2)((uint)unaff_D2 >> 0x10);
  puVar6 = &DAT_0080c814;
  puVar4 = (ushort *)&DAT_00804d86;
  uVar2 = 0x71;
  uVar3 = 0;
  for (puVar5 = (ushort *)&DAT_00807d66; puVar5 < &DAT_00807e66; puVar5 = puVar5 + 0x10) {
    if ((*puVar5 & 2) != 0) {
      if (((uint)*(ushort *)(&DAT_008035d4 + (short)((int)uVar2 >> 4) * 2) & 1 << (uVar2 & 0xf)) ==
          0) {
        uVar1 = 0;
      }
      else {
        uVar1 = protectionThresholdCalculationHelper
                          ((int)puVar5,(int)puVar6,puVar4,CONCAT22(1,uVar7));
        if (uVar1 < puVar4[3]) {
          uVar1 = puVar4[3];
        }
      }
      puVar4[1] = uVar1;
      if (uVar3 < uVar1) {
        uVar3 = puVar4[1];
      }
    }
    puVar6 = puVar6 + 0x2e;
    puVar4 = puVar4 + 0xf;
    uVar2 = (uint)(ushort)((short)uVar2 + 4);
  }
  _DAT_0080c992 = coreTableInterpolation(0x80);
  return;
}



//
// Function: protectionThresholdPointerInit @ 0x00014cfc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void protectionThresholdPointerInit(void)

{
  _DAT_008002e2 = (uint)_DAT_008037b4 << 0x10;
  _DAT_008002de = 0x807e6e;
  _DAT_0080c992 = _DAT_008037b4;
  return;
}



//
// Function: protectionStateUpdater @ 0x00014d24
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void protectionStateUpdater(int param_1,int param_2,undefined4 param_3)

{
  if (param_3._0_2_ == 0) {
    if (*(short *)(param_2 + 0x1a) != -1) {
      *(short *)(param_2 + 0x1a) = *(short *)(param_2 + 0x1a) + 1;
    }
  }
  else if (*(short *)(param_2 + 0x1c) != -1) {
    *(short *)(param_2 + 0x1c) = *(short *)(param_2 + 0x1c) + 1;
  }
  if (_DAT_008002ec != 0) {
    if (param_3._0_2_ == 0) {
      *(undefined2 *)(param_2 + 0x1e) = *(undefined2 *)(param_1 + 0x14);
      return;
    }
    *(undefined2 *)(param_2 + 0x20) = *(undefined2 *)(param_1 + 0x14);
  }
  return;
}



//
// Function: protectionState4EmergencyHandler @ 0x00014d6a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort protectionState4EmergencyHandler(void)

{
  ushort uVar1;
  uint uVar2;
  undefined4 unaff_D2;
  ushort uVar3;
  uint uVar4;
  ushort uVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  ushort *puVar8;
  
  uVar3 = (ushort)((uint)unaff_D2 >> 0x10);
  if ((((engine_control_flags_t_008035d6.protection_system & 1) == 0) ||
      (engine_operating_mode_t_0080c810.state == 8)) ||
     (engine_operating_mode_t_0080c810.state == 1)) {
    _DAT_0080c998 = 0;
    uVar3 = 0;
    puVar7 = &DAT_0080c814;
    do {
      *(undefined2 *)(puVar7 + 0x1a) = 0;
      *(undefined2 *)(puVar7 + 0x1c) = 0;
      uVar5 = 0x2e;
      puVar7 = puVar7 + 0x2e;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 8);
  }
  else {
    _DAT_0080c998 = 0;
    puVar8 = (ushort *)&DAT_00807d66;
    puVar6 = (undefined4 *)&DAT_0080c814;
    uVar4 = 0x72;
    uVar5 = 0;
    if ((_DAT_008002e6 == 0) && (circular_buffer_t_0080c3fc.data_buffer_8 != 0)) {
      _DAT_008002ec = 1;
    }
    else {
      _DAT_008002ec = 0;
    }
    for (; puVar8 < &DAT_00807e66; puVar8 = puVar8 + 0x10) {
      uVar1 = *puVar8;
      if (((uint)*(ushort *)(&DAT_008035d4 + (short)((int)uVar4 >> 4) * 2) & 1 << (uVar4 & 0xf)) ==
          0) {
        *(undefined2 *)((int)puVar6 + 0x1a) = 0;
        *(undefined2 *)(puVar6 + 7) = 0;
      }
      else {
        if ((uVar1 & 0x300) != 0) {
          if (*(short *)((int)puVar6 + 0x16) == 0) {
            *(undefined2 *)((int)puVar6 + 0x1a) = 0;
          }
          else {
            if ((uVar1 & 0x100) == 0) {
              if ((uVar1 & 0x200) != 0) {
                uVar2 = protectionConditionEvaluator(puVar8,puVar6,2);
                if ((short)uVar2 == 0) {
                  *(undefined2 *)((int)puVar6 + 0x1a) = 0;
                  *(undefined2 *)((int)puVar6 + 0x1e) = 0;
                }
                else {
                  protectionStateUpdater((int)puVar8,(int)puVar6,(uint)uVar3);
                }
              }
            }
            else if (puVar8[8] < *(ushort *)((int)puVar6 + 6)) {
              protectionStateUpdater((int)puVar8,(int)puVar6,(uint)uVar3);
            }
            else {
              *(undefined2 *)((int)puVar6 + 0x1a) = 0;
              *(undefined2 *)((int)puVar6 + 0x1e) = 0;
            }
            if (*(ushort *)((int)puVar6 + 0x1e) < *(ushort *)((int)puVar6 + 0x1a)) {
              _DAT_0080c998 = 1;
            }
            if ((uint)puVar8[0xf] + (uint)*(ushort *)((int)puVar6 + 0x1e) <
                (uint)*(ushort *)((int)puVar6 + 0x1a)) {
              _DAT_0080c996 = 1;
              _DAT_00804e76 = uVar5;
            }
          }
        }
        if ((uVar1 & 0xc00) != 0) {
          if (*(short *)((int)puVar6 + 0x16) == 0) {
            *(undefined2 *)(puVar6 + 7) = 0;
          }
          else {
            if ((uVar1 & 0x400) == 0) {
              if ((uVar1 & 0x800) != 0) {
                uVar2 = protectionConditionEvaluator(puVar8,puVar6,0x10002);
                if ((short)uVar2 == 0) {
                  *(undefined2 *)(puVar6 + 7) = 0;
                  *(undefined2 *)(puVar6 + 8) = 0;
                }
                else {
                  protectionStateUpdater((int)puVar8,(int)puVar6,CONCAT22(1,uVar3));
                }
              }
            }
            else if (puVar8[9] < *(ushort *)(puVar6 + 2)) {
              protectionStateUpdater((int)puVar8,(int)puVar6,CONCAT22(1,uVar3));
            }
            else {
              *(undefined2 *)(puVar6 + 7) = 0;
              *(undefined2 *)(puVar6 + 8) = 0;
            }
            if (*(ushort *)(puVar6 + 8) < *(ushort *)(puVar6 + 7)) {
              _DAT_0080c998 = 1;
            }
            if ((uint)puVar8[0xf] + (uint)*(ushort *)(puVar6 + 8) < (uint)*(ushort *)(puVar6 + 7)) {
              _DAT_0080c996 = 1;
              _DAT_00804e76 = uVar5;
            }
          }
        }
      }
      puVar6 = (undefined4 *)((int)puVar6 + 0x2e);
      uVar4 = (uint)(ushort)((short)uVar4 + 4);
      uVar5 = uVar5 + 1;
    }
    if (_DAT_0080c994 != 0 || _DAT_0080c986 != 0) {
      _DAT_0080c998 = 1;
    }
    uVar5 = _DAT_0080c994 | _DAT_0080c984;
    if (uVar5 != 0) {
      _DAT_0080c996 = 1;
    }
    if ((_DAT_0080c996 != 0) && (_DAT_008002e8 == 0)) {
      if (_DAT_00804e7a != 0xff) {
        _DAT_00804e7a = _DAT_00804e7a + 1;
      }
      uVar5 = _DAT_00804e76;
      if (_DAT_00804e76 == _DAT_008002ea) {
        if (_DAT_00804e78 != 0xff) {
          _DAT_00804e78 = _DAT_00804e78 + 1;
        }
      }
      else {
        _DAT_00804e78 = 1;
      }
    }
    _DAT_008002e8 = _DAT_0080c996;
    _DAT_008002ea = _DAT_00804e76;
  }
  _DAT_008002e6 = circular_buffer_t_0080c3fc.data_buffer_8;
  return uVar5;
}



//
// Function: protectionCalculationHelper @ 0x00015038
//

uint protectionCalculationHelper(undefined4 param_1,uint param_2)

{
  uint in_D0;
  
  if ((param_2 & 0x40000) == 0) {
    if (((param_2 & 0x80000) != 0) && (param_1._0_2_ < param_1._2_2_)) {
      return 1;
    }
  }
  else if (param_1._2_2_ < param_1._0_2_) {
    return 1;
  }
  return in_D0 & 0xffff0000;
}



//
// Function: protectionStateProcessor @ 0x00015078
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint protectionStateProcessor(undefined4 param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 unaff_D2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  short *psVar6;
  int iVar7;
  
  if (param_1._0_2_ == 0) {
    uVar4 = *(ushort *)(_DAT_008002f6 + 0x18);
    uVar3 = _DAT_008002ee[0xd];
    iVar7 = *(int *)((int)_DAT_008002f2 + 0x26);
    psVar6 = (short *)(_DAT_008002f6 + 0x16);
  }
  else {
    uVar4 = *(ushort *)(_DAT_008002f6 + 0x1c);
    uVar3 = _DAT_008002ee[0xe];
    iVar7 = *(int *)((int)_DAT_008002f2 + 0x2a);
    psVar6 = (short *)(_DAT_008002f6 + 0x1a);
  }
  if (*psVar6 == 0) {
    *psVar6 = 1;
    puVar1 = (undefined4 *)(iVar7 + (uint)uVar4 * 8);
    *puVar1 = _DAT_0080d4c4;
    *(undefined2 *)((int)puVar1 + 6) = 0;
    if ((*_DAT_008002ee & 8) == 0) {
      *(undefined2 *)(puVar1 + 1) = 0;
    }
    else {
      *(undefined2 *)(puVar1 + 1) = 0xffff;
    }
  }
  uVar5 = 1 << (uVar3 & 0xf);
  (&fault_status_registers_t_00805df2.sensor_fault_status)[(short)((int)(uint)uVar3 >> 4)] =
       uVar5 | (&fault_status_registers_t_00805df2.sensor_fault_status)
               [(short)((int)(uint)uVar3 >> 4)];
  (&fault_latch_registers_t_00805e32.sensor_fault_latch)[(short)((int)(uint)uVar3 >> 4)] =
       uVar5 | (&fault_latch_registers_t_00805e32.sensor_fault_latch)
               [(short)((int)(uint)uVar3 >> 4)];
  uVar2 = *_DAT_008002ee & 0xffff000c;
  if ((*_DAT_008002ee & 0xc) != 0) {
    uVar2 = protectionCalculationHelper
                      (CONCAT22(*(undefined2 *)*_DAT_008002f2,
                                *(undefined2 *)(iVar7 + 4 + (uint)uVar4 * 8)),
                       CONCAT22(*_DAT_008002ee,(short)((uint)unaff_D2 >> 0x10)));
    if ((short)uVar2 != 0) {
      uVar2 = CONCAT22((short)(uVar2 >> 0x10),*(undefined2 *)*_DAT_008002f2);
      *(undefined2 *)(iVar7 + 4 + (uint)uVar4 * 8) = *(undefined2 *)*_DAT_008002f2;
    }
  }
  return uVar2;
}



//
// Function: protectionStateValidator @ 0x0001517c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 protectionStateValidator(undefined4 param_1)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  ushort *puVar5;
  int iVar6;
  short *psVar7;
  
  if (param_1._0_2_ == 0) {
    puVar5 = (ushort *)(_DAT_008002f6 + 0x18);
    uVar4 = *(ushort *)(_DAT_008002ee + 0x1a);
    iVar6 = *(int *)(_DAT_008002f2 + 0x26);
    psVar7 = (short *)(_DAT_008002f6 + 0x16);
  }
  else {
    puVar5 = (ushort *)(_DAT_008002f6 + 0x1c);
    uVar4 = *(ushort *)(_DAT_008002ee + 0x1c);
    iVar6 = *(int *)(_DAT_008002f2 + 0x2a);
    psVar7 = (short *)(_DAT_008002f6 + 0x1a);
  }
  uVar2 = (uint)(&fault_status_registers_t_00805df2.sensor_fault_status)
                [(short)((int)(uint)uVar4 >> 4)];
  uVar3 = uVar2 & 1 << (uVar4 & 0xf);
  if (uVar3 != 0) {
    uVar2 = (uint)(&fault_latch_registers_t_00805e32.sensor_fault_latch)
                  [(short)((int)(uint)uVar4 >> 4)];
    uVar3 = uVar2 & 1 << (uVar4 & 0xf);
    if (uVar3 == 0) {
      uVar1 = ~(1 << (uVar4 & 0xf));
      uVar3 = (uint)uVar1;
      uVar2 = (int)(uint)uVar4 >> 4;
      (&fault_status_registers_t_00805df2.sensor_fault_status)[(short)uVar2] =
           uVar1 & (&fault_status_registers_t_00805df2.sensor_fault_status)[(short)uVar2];
      if (*psVar7 != 0) {
        *psVar7 = 0;
        *(short *)(iVar6 + 6 + (uint)*puVar5 * 8) =
             _DAT_0080d4c6 - (short)*(undefined4 *)(iVar6 + (uint)*puVar5 * 8);
        *puVar5 = *puVar5 + 1;
        uVar3 = (uint)*puVar5 % 5;
        uVar2 = *puVar5 / 5;
        *puVar5 = (ushort)uVar3;
      }
    }
  }
  return CONCAT44(uVar2,uVar3);
}



//
// Function: protectionState3bRpmMonitor @ 0x00015272
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void protectionState3bRpmMonitor(void)

{
  ushort uVar1;
  short sVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  undefined4 unaff_D2;
  ushort uVar6;
  
  uVar6 = (ushort)((uint)unaff_D2 >> 0x10);
  _DAT_008002f2 = (undefined4 *)&DAT_0080c814;
  _DAT_008002f6 = (short *)&DAT_00804d86;
  for (_DAT_008002ee = (ushort *)&DAT_00807d66; _DAT_008002ee < &DAT_00807e66;
      _DAT_008002ee = _DAT_008002ee + 0x10) {
    uVar1 = *_DAT_008002ee;
    if ((_DAT_008002ee[0xb] == 0) && (_DAT_008002ee[0xc] == 0)) {
      *(undefined2 *)((int)_DAT_008002f2 + 0x16) = 1;
    }
    else {
      if (_DAT_008002ee[0xb] < circular_buffer_t_0080c3fc.data_buffer_8) {
        *(undefined2 *)(_DAT_008002f2 + 9) = 1;
      }
      else if (circular_buffer_t_0080c3fc.data_buffer_8 == 0) {
        *(undefined2 *)((int)_DAT_008002f2 + 0x16) = 0;
        *(undefined2 *)((int)_DAT_008002f2 + 0x22) = 0;
        *(undefined2 *)(_DAT_008002f2 + 9) = 0;
      }
      if (*(short *)(_DAT_008002f2 + 9) != 0) {
        if (*(ushort *)((int)_DAT_008002f2 + 0x22) < _DAT_008002ee[0xc]) {
          *(short *)((int)_DAT_008002f2 + 0x22) = *(short *)((int)_DAT_008002f2 + 0x22) + 1;
        }
        else {
          *(undefined2 *)((int)_DAT_008002f2 + 0x16) = 1;
        }
      }
    }
    bVar3 = false;
    bVar4 = false;
    if (*(short *)((int)_DAT_008002f2 + 0x16) == 0) {
      protectionStateValidator((uint)uVar6);
      protectionStateValidator(CONCAT22(1,uVar6));
    }
    else {
      if (*(short *)(_DAT_008002f2 + 6) == 0) {
        if ((*_DAT_008002f6 != 0) || (*(short *)((int)_DAT_008002f2 + 0x1a) != 0)) {
          bVar3 = true;
        }
        if ((_DAT_008002f6[1] != 0) || (*(short *)(_DAT_008002f2 + 7) != 0)) {
          bVar4 = true;
        }
      }
      else {
        bVar3 = true;
        bVar4 = true;
      }
      if ((uVar1 & 0x1000) == 0) {
        if (bVar3) {
          *(int *)(_DAT_008002f6 + 7) = *(int *)(_DAT_008002f6 + 7) + 1;
          protectionStateProcessor((uint)uVar6);
        }
        else {
          protectionStateValidator((uint)uVar6);
        }
        if (bVar4) {
          *(int *)(_DAT_008002f6 + 9) = *(int *)(_DAT_008002f6 + 9) + 1;
          protectionStateProcessor(CONCAT22(1,uVar6));
        }
        else {
          protectionStateValidator(CONCAT22(1,uVar6));
        }
      }
      else if (bVar3 || bVar4) {
        *(int *)(_DAT_008002f6 + 7) = *(int *)(_DAT_008002f6 + 7) + 1;
        protectionStateProcessor((uint)uVar6);
      }
      else {
        protectionStateValidator((uint)uVar6);
      }
      if ((uVar1 & 0xc) != 0) {
        sVar2 = *(short *)*_DAT_008002f2;
        uVar5 = protectionCalculationHelper(CONCAT22(sVar2,_DAT_008002f6[4]),CONCAT22(uVar1,uVar6));
        if ((short)uVar5 != 0) {
          _DAT_008002f6[4] = sVar2;
          *(undefined4 *)(_DAT_008002f6 + 5) = _DAT_0080d4c4;
        }
      }
    }
    _DAT_008002f2 = (undefined4 *)((int)_DAT_008002f2 + 0x2e);
    _DAT_008002f6 = _DAT_008002f6 + 0xf;
  }
  return;
}



//
// Function: shutdownMinimumSelector29 @ 0x0001542a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void shutdownMinimumSelector29(void)

{
  if (_DAT_0080c98e < _DAT_0080d494) {
    _DAT_0080d494 = _DAT_0080c98e;
    _DAT_0080d496 = 0x1d;
  }
  return;
}



//
// Function: protectionState2ThresholdCalculator @ 0x00015448
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void protectionState2ThresholdCalculator(void)

{
  ushort uVar3;
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_D2;
  uint uVar4;
  ushort uVar5;
  undefined4 *puVar6;
  ushort *puVar7;
  ushort *puVar8;
  ushort uVar9;
  
  uVar9 = (ushort)((uint)unaff_D2 >> 0x10);
  puVar6 = (undefined4 *)&DAT_0080c814;
  puVar8 = (ushort *)&DAT_00804d86;
  uVar4 = 0x70;
  uVar5 = 0;
  for (puVar7 = (ushort *)&DAT_00807d66; puVar7 < &DAT_00807e66; puVar7 = puVar7 + 0x10) {
    if ((*puVar7 & 1) != 0) {
      if (((uint)*(ushort *)(&DAT_008035d4 + (short)((int)uVar4 >> 4) * 2) & 1 << (uVar4 & 0xf)) ==
          0) {
        uVar3 = 0;
      }
      else {
        if ((*puVar7 & 0x40) == 0) {
          if (puVar7[1] < *(ushort *)((int)puVar6 + 6)) {
            uVar1 = protectionPercentageCalculator
                              (CONCAT22(*(undefined2 *)*puVar6,**(undefined2 **)((int)puVar6 + 10)),
                               CONCAT22(**(undefined2 **)((int)puVar6 + 0xe),uVar9));
            uVar3 = (ushort)uVar1;
          }
          else {
            uVar3 = 0;
          }
        }
        else {
          uVar3 = protectionThresholdCalculationHelper((int)puVar7,(int)puVar6,puVar8,(uint)uVar9);
        }
        if (uVar3 < puVar8[2]) {
          uVar3 = puVar8[2];
        }
      }
      *puVar8 = uVar3;
      if (uVar5 < uVar3) {
        uVar5 = *puVar8;
      }
    }
    puVar6 = (undefined4 *)((int)puVar6 + 0x2e);
    puVar8 = puVar8 + 0xf;
    uVar4 = (uint)(ushort)((short)uVar4 + 4);
  }
  if ((_DAT_008035e2 & 0x1000) != 0) {
    if (circular_buffer_t_0080c3fc.data_buffer_8 == 0) {
      _DAT_008002fa = 0;
    }
    else if (_DAT_008002fa < _DAT_00807e68) {
      _DAT_008002fa = _DAT_008002fa + 1;
    }
    if (_DAT_008002fa < _DAT_00807e68) {
      _DAT_00804de0 = 0x100;
      uVar5 = 0x100;
    }
  }
  if ((int)(short)(_DAT_00807e66 + _DAT_008002fc) < (int)(uint)uVar5) {
    uVar5 = _DAT_00807e66 + _DAT_008002fc;
  }
  else if ((int)(uint)uVar5 < (int)(short)(_DAT_008002fc - _DAT_00807e66)) {
    uVar5 = _DAT_008002fc - _DAT_00807e66;
  }
  _DAT_008002fc = uVar5;
  if (0x100 < (short)_DAT_008002fc) {
    _DAT_008002fc = 0x100;
  }
  if (_DAT_008002fc == 0) {
    _DAT_0080c98e = _DAT_00807f3c;
  }
  else {
    _DAT_00800304 = circular_buffer_t_0080c3fc.data_buffer_8;
    _DAT_0080c98e = lookupTableInterpolation((short *)&DAT_008002fe);
    iVar2 = (int)(short)(0x100 - _DAT_008002fc) * (int)(short)(_DAT_0080c9d8 - _DAT_0080c98e);
    if (iVar2 < 0) {
      iVar2 = iVar2 + 0xff;
    }
    _DAT_0080c98e = _DAT_0080c98e + (short)((uint)iVar2 >> 8);
  }
  if ((short)_DAT_008002fc < 1) {
    _DAT_0080c990 = 0;
    return;
  }
  _DAT_0080c990 = 1;
  return;
}



//
// Function: initShutdownLimitVariables @ 0x0001562e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initShutdownLimitVariables(void)

{
  _DAT_008002fa = 0;
  _DAT_008002fc = 0;
  _DAT_008002fe = 2;
  _DAT_00800300 = 0x807e72;
  _DAT_00800306 = 0x807ea4;
  _DAT_0080c98e = _DAT_00807f3c;
  _DAT_0080c990 = 0;
  return;
}



//
// Function: can1TimerBufferInit @ 0x0001566a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void can1TimerBufferInit(void)

{
  byte *pbVar1;
  
  _DAT_00fffe1c = _DAT_00fffe1c & 0xffcf;
  _DAT_00fffe0a = _DAT_00fffe0a & 0xfbff;
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfbff;
  _DAT_0080c77e = circular_buffer_t_0080c3fc.data_buffer_rest + (uint)DAT_00807cce * 4 + 0x22;
  for (pbVar1 = circular_buffer_t_0080c3fc.data_buffer_rest + 0x26; pbVar1 <= _DAT_0080c77e;
      pbVar1 = pbVar1 + 4) {
    *(int *)pbVar1 = _CRFLOFPZ;
  }
  _DAT_0080c786 = 0x80c430;
  if (DAT_00807cd0 < 2) {
    circular_buffer_t_0080c3fc.data_buffer_rest[0x10] = 0;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x11] = 0x80;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x12] = 0xc4;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x13] = 0x30;
  }
  else {
    circular_buffer_t_0080c3fc.data_buffer_rest._16_4_ = (uint)DAT_00807cd0 * 4 + 0x80c430;
  }
  _DAT_0080c776 = _CRFLOFPZ * (uint)DAT_00807cce;
  circular_buffer_t_0080c3fc.data_buffer_rest._0_4_ = _CRFLOFPZ * (uint)DAT_00807cd0;
  _DAT_00808eea = rpmTimerInterruptHandler;
  _DAT_00fffe0e = _DAT_00fffe0e & 0xf0ff | 0xd00;
  _DAT_00ffffa2 = (ushort)DAT_00807cda << 8;
  _DAT_00ffffa6 = 0;
  rpm_timer_capture_value = 0;
  _DAT_00ffffa0 = 0xb;
  _DAT_00fffe14 = _DAT_00fffe14 & 0xffcf | 0x30;
  _DAT_00fffe18 = _DAT_00fffe18 & 0xffcf | 0x30;
  _DAT_00fffe0a = _DAT_00fffe0a | 0x400;
  _DAT_00fffe1c = _DAT_00fffe1c & 0xffcf | 0x20;
  if (DAT_00807cf7 == '\0') {
    _DAT_0080c78e = &LAB_0001416c;
  }
  return;
}



//
// Function: delayWithWatchdogServiceWrapper @ 0x0001578c
//

void delayWithWatchdogServiceWrapper(void)

{
  FUN_0002b5aa();
  return;
}



//
// Function: emptyStubFunction5 @ 0x00015794
//

void emptyStubFunction5(void)

{
  return;
}



//
// Function: rpmTimerInterruptHandler @ 0x00015796
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 rpmTimerInterruptHandler(void)

{
  dword dVar1;
  undefined4 in_D0;
  undefined4 in_D1;
  undefined2 uVar2;
  undefined2 uStack_1e;
  
  dVar1 = rpm_timer_capture_value;
  uVar2 = (undefined2)((uint)in_D0 >> 0x10);
  uStack_1e = (undefined2)in_D0;
  _DAT_0080c75c = rpm_timer_capture_value;
  rpm_timer_capture_value = rpm_timer_capture_value & 0xffff;
  _DAT_0080c776 =
       dVar1 + (_DAT_0080c776 - *(int *)circular_buffer_t_0080c3fc.data_buffer_rest._16_4_);
  *(dword *)circular_buffer_t_0080c3fc.data_buffer_rest._16_4_ = dVar1;
  if ((uint)circular_buffer_t_0080c3fc.data_buffer_rest._16_4_ < _DAT_0080c77e) {
    circular_buffer_t_0080c3fc.data_buffer_rest._16_4_ =
         circular_buffer_t_0080c3fc.data_buffer_rest._16_4_ + 4;
  }
  else {
    circular_buffer_t_0080c3fc.data_buffer_rest[0x10] = 0;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x11] = 0x80;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x12] = 0xc4;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x13] = 0x30;
  }
  if ((uint)circular_buffer_t_0080c3fc.data_buffer_rest._8_4_ < -(uint)_DAT_00807cd2 - 1) {
    circular_buffer_t_0080c3fc.data_buffer_rest._8_4_ =
         (uint)_DAT_00807cd2 + circular_buffer_t_0080c3fc.data_buffer_rest._8_4_;
  }
  circular_buffer_t_0080c3fc.data_buffer_rest._0_4_ =
       _DAT_0080c75c + (circular_buffer_t_0080c3fc.data_buffer_rest._0_4_ - *(int *)_DAT_0080c786);
  if (_DAT_0080c786 < _DAT_0080c77e) {
    _DAT_0080c786 = (byte *)((int)_DAT_0080c786 + 4);
  }
  else {
    _DAT_0080c786 = circular_buffer_t_0080c3fc.data_buffer_rest + 0x26;
  }
  if ((int)(uint)_DAT_0080c7ae < (int)(DAT_00807cce - 1)) {
    _DAT_0080c7ae = _DAT_0080c7ae + 1;
  }
  else {
    _DAT_0080c7ae = 0;
  }
  circular_buffer_t_0080c3fc.data_buffer_rest[0x18] = DAT_0080c772;
  circular_buffer_t_0080c3fc.data_buffer_rest[0x19] = DAT_0080c772_1;
  if (CPMNFL == 1) {
    if (DAT_0080c7d4 == '\0') {
      if (DAT_0080c7d3 < DAT_00807d20) {
        DAT_0080c7d3 = DAT_0080c7d3 + 1;
      }
      else {
        fault_status_registers_t_00805df2.sensor_fault_status =
             fault_status_registers_t_00805df2.sensor_fault_status | 1;
        fault_latch_registers_t_00805e32.sensor_fault_latch =
             fault_latch_registers_t_00805e32.sensor_fault_latch | 1;
      }
      DAT_0080c7b2 = 2;
      fault_status_registers_t_00805df2.engine_fault_status =
           fault_status_registers_t_00805df2.engine_fault_status | 0x800;
      fault_latch_registers_t_00805e32.engine_fault_latch =
           fault_latch_registers_t_00805e32.engine_fault_latch | 0x800;
    }
    else {
      DAT_0080c7d4 = DAT_0080c7d4 + -1;
      if (DAT_0080c7d3 == 0) {
        if (((fault_status_registers_t_00805df2.sensor_fault_status & 1) != 0) &&
           ((fault_latch_registers_t_00805e32.sensor_fault_latch & 1) == 0)) {
          fault_status_registers_t_00805df2.sensor_fault_status =
               fault_status_registers_t_00805df2.sensor_fault_status & 0xfffe;
        }
      }
      else {
        DAT_0080c7d3 = DAT_0080c7d3 - 1;
      }
    }
  }
  vp44_communication_state_machine(CONCAT22(1,uVar2));
  if ((_DAT_0080c75c < -_DAT_0080c750 - 1U) &&
     (_DAT_0080c750 = _DAT_0080c75c + _DAT_0080c750, _DAT_0080c758 != -1)) {
    _DAT_0080c758 = _DAT_0080c758 + 1;
  }
  rpmTimingDeltaComparator();
  emptyStubFunction3();
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfbff;
  return CONCAT44(CONCAT22(uVar2,uStack_1e),in_D1);
}



//
// Function: can1TimerBufferInitAlt @ 0x00015968
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void can1TimerBufferInitAlt(void)

{
  byte *pbVar1;
  
  _DAT_00fffe1c = _DAT_00fffe1c & 0xffcf;
  _DAT_00fffe0a = _DAT_00fffe0a & 0xfbff;
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfbff;
  _DAT_0080c77e = circular_buffer_t_0080c3fc.data_buffer_rest + (uint)DAT_00807cce * 4 + 0x22;
  for (pbVar1 = circular_buffer_t_0080c3fc.data_buffer_rest + 0x26; pbVar1 <= _DAT_0080c77e;
      pbVar1 = pbVar1 + 4) {
    *(int *)pbVar1 = _CRFLOFPZ;
  }
  _DAT_0080c786 = 0x80c430;
  if (DAT_00807cd0 < 2) {
    circular_buffer_t_0080c3fc.data_buffer_rest[0x10] = 0;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x11] = 0x80;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x12] = 0xc4;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x13] = 0x30;
  }
  else {
    circular_buffer_t_0080c3fc.data_buffer_rest._16_4_ = (uint)DAT_00807cd0 * 4 + 0x80c430;
  }
  _DAT_0080c776 = _CRFLOFPZ * (uint)DAT_00807cce;
  circular_buffer_t_0080c3fc.data_buffer_rest._0_4_ = _CRFLOFPZ * (uint)DAT_00807cd0;
  _DAT_00808eea = rpmTimerInterruptHandlerAlt;
  _DAT_00fffe0e = _DAT_00fffe0e & 0xf0ff | 0xd00;
  _DAT_00ffffa2 = (ushort)DAT_00807cda << 8;
  _DAT_00ffffa6 = 0;
  rpm_timer_capture_value = 0;
  _DAT_00ffffa0 = 0xb;
  _DAT_00fffe14 = _DAT_00fffe14 & 0xffcf | 0x30;
  _DAT_00fffe18 = _DAT_00fffe18 & 0xffcf | 0x30;
  _DAT_00fffe0a = _DAT_00fffe0a | 0x400;
  _DAT_00fffe1c = _DAT_00fffe1c & 0xffcf | 0x20;
  if (DAT_00807cf7 == '\0') {
    _DAT_0080c78e = &LAB_0001416c;
  }
  return;
}



//
// Function: can1MessageTransmitInit @ 0x00015a8a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void can1MessageTransmitInit(void)

{
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfffe;
  _DAT_00fffe12 = _DAT_00fffe12 & 0xfff0 | 9;
  _DAT_00808ec2 = &LAB_00015c30;
  _DAT_00ffff00 = 7;
  _DAT_00ffff02 = DAT_00807d02 | 0x100;
  _DAT_00ffff04 = 0x100;
  _DAT_00ffff06 = CONCAT11(DAT_00807d03,CPMXTAES._0_1_);
  _DAT_00ffff08 = 0;
  _DAT_00ffff0c = 0;
  _DAT_00fffe16 = _DAT_00fffe16 & 0xfffc | 3;
  _DAT_00fffe1a = _DAT_00fffe1a & 0xfffc | 1;
  _DAT_00fffe0a = _DAT_00fffe0a & 0xfffe | 1;
  _DAT_00fffe1e = _DAT_00fffe1e & 0xfffc | 1;
  FUN_0002b5aa();
  return;
}



//
// Function: emptyStubFunction6 @ 0x00015b48
//

void emptyStubFunction6(void)

{
  return;
}



//
// Function: rpmTimerInterruptHandlerAlt @ 0x00015b4a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 rpmTimerInterruptHandlerAlt(void)

{
  dword dVar1;
  undefined4 in_D0;
  undefined4 in_D1;
  undefined2 uVar2;
  undefined2 uStack_1e;
  
  dVar1 = rpm_timer_capture_value;
  uVar2 = (undefined2)((uint)in_D0 >> 0x10);
  uStack_1e = (undefined2)in_D0;
  _DAT_0080c75c = rpm_timer_capture_value;
  rpm_timer_capture_value = rpm_timer_capture_value & 0xffff;
  _DAT_0080c776 =
       dVar1 + (_DAT_0080c776 - *(int *)circular_buffer_t_0080c3fc.data_buffer_rest._16_4_);
  *(dword *)circular_buffer_t_0080c3fc.data_buffer_rest._16_4_ = dVar1;
  if ((uint)circular_buffer_t_0080c3fc.data_buffer_rest._16_4_ < _DAT_0080c77e) {
    circular_buffer_t_0080c3fc.data_buffer_rest._16_4_ =
         circular_buffer_t_0080c3fc.data_buffer_rest._16_4_ + 4;
  }
  else {
    circular_buffer_t_0080c3fc.data_buffer_rest[0x10] = 0;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x11] = 0x80;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x12] = 0xc4;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x13] = 0x30;
  }
  if ((uint)circular_buffer_t_0080c3fc.data_buffer_rest._8_4_ < -(uint)_DAT_00807cd2 - 1) {
    circular_buffer_t_0080c3fc.data_buffer_rest._8_4_ =
         (uint)_DAT_00807cd2 + circular_buffer_t_0080c3fc.data_buffer_rest._8_4_;
  }
  circular_buffer_t_0080c3fc.data_buffer_rest._0_4_ =
       _DAT_0080c75c + (circular_buffer_t_0080c3fc.data_buffer_rest._0_4_ - *(int *)_DAT_0080c786);
  if (_DAT_0080c786 < _DAT_0080c77e) {
    _DAT_0080c786 = (byte *)((int)_DAT_0080c786 + 4);
  }
  else {
    _DAT_0080c786 = circular_buffer_t_0080c3fc.data_buffer_rest + 0x26;
  }
  circular_buffer_t_0080c3fc.data_buffer_rest[0x18] = DAT_0080c772;
  circular_buffer_t_0080c3fc.data_buffer_rest[0x19] = DAT_0080c772_1;
  vp44_communication_state_machine(CONCAT22(1,uVar2));
  if ((_DAT_0080c75c < -_DAT_0080c750 - 1U) &&
     (_DAT_0080c750 = _DAT_0080c75c + _DAT_0080c750, _DAT_0080c758 != -1)) {
    _DAT_0080c758 = _DAT_0080c758 + 1;
  }
  rpmTimingDeltaComparator();
  emptyStubFunction3();
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfbff;
  return CONCAT44(CONCAT22(uVar2,uStack_1e),in_D1);
}



//
// Function: rpmTimingDeltaComparator @ 0x00015e96
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rpmTimingDeltaComparator(void)

{
  ushort uVar1;
  
  if (circular_buffer_t_0080c3fc.data_buffer_rest._26_2_ == 0) {
    DAT_00809684 = 1;
    return;
  }
  if (_DAT_0080c7ae == _DAT_0080c7b0) {
    _DAT_00809686 = _DAT_0080c766 - _DAT_0080c764;
    if (_DAT_0080c766 < _DAT_0080c764) {
      uVar1 = _DAT_0080c764 - _DAT_0080c766;
    }
    else {
      uVar1 = _DAT_0080c766 - _DAT_0080c764;
    }
    if (uVar1 < _DAT_0080707a) {
      DAT_00809684 = 1;
      DAT_00809685 = 1;
      return;
    }
    if (0 < _DAT_00809686) {
      DAT_00809684 = 1;
      DAT_00809685 = 0;
      return;
    }
    DAT_00809684 = 0;
    DAT_00809685 = 1;
  }
  return;
}



//
// Function: rpmTimingDeltaComparatorWithReturn @ 0x00015f26
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint rpmTimingDeltaComparatorWithReturn(void)

{
  uint in_D0;
  uint uVar1;
  ushort uVar2;
  
  if (circular_buffer_t_0080c3fc.data_buffer_rest._24_2_ == 0) {
    DAT_00809685 = 1;
    return in_D0;
  }
  uVar1 = CONCAT22((short)(in_D0 >> 0x10),_DAT_0080c7ae);
  if (_DAT_0080c7ae == _DAT_0080c7b0) {
    _DAT_00809686 = _DAT_0080c766 - _DAT_0080c764;
    if (_DAT_0080c766 < _DAT_0080c764) {
      uVar2 = _DAT_0080c764 - _DAT_0080c766;
    }
    else {
      uVar2 = _DAT_0080c766 - _DAT_0080c764;
    }
    if (uVar2 < _DAT_0080707a) {
      DAT_00809684 = 1;
      DAT_00809685 = 1;
      return (uint)uVar2;
    }
    uVar1 = (uint)(ushort)(_DAT_0080c764 - _DAT_0080c766);
    if ((ushort)(_DAT_0080c764 - _DAT_0080c766) != 0 && (short)_DAT_0080c766 <= (short)_DAT_0080c764
       ) {
      DAT_00809684 = 0;
      DAT_00809685 = 1;
      return uVar1;
    }
    DAT_00809684 = 1;
    DAT_00809685 = 0;
  }
  return uVar1;
}



//
// Function: can1TimerBufferInitDivided @ 0x00015fb6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void can1TimerBufferInitDivided(void)

{
  byte *pbVar1;
  
  _DAT_00fffe1c = _DAT_00fffe1c & 0xffcf;
  _DAT_00fffe0a = _DAT_00fffe0a & 0xfbff;
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfbff;
  _DAT_0080c77e = circular_buffer_t_0080c3fc.data_buffer_rest + (uint)DAT_00807cce * 4 + 0x22;
  for (pbVar1 = circular_buffer_t_0080c3fc.data_buffer_rest + 0x26; pbVar1 <= _DAT_0080c77e;
      pbVar1 = pbVar1 + 4) {
    *(int *)pbVar1 = _CRFLOFPZ;
  }
  _DAT_0080c786 = 0x80c430;
  if (DAT_00807cd0 < 2) {
    circular_buffer_t_0080c3fc.data_buffer_rest[0x10] = 0;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x11] = 0x80;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x12] = 0xc4;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x13] = 0x30;
  }
  else {
    circular_buffer_t_0080c3fc.data_buffer_rest._16_4_ = (uint)DAT_00807cd0 * 4 + 0x80c430;
  }
  _DAT_0080c776 = _CRFLOFPZ * (uint)DAT_00807cce;
  circular_buffer_t_0080c3fc.data_buffer_rest._0_4_ = _CRFLOFPZ * (uint)DAT_00807cd0;
  _DAT_00808eea = rpmTimerInterruptHandler2;
  _DAT_00fffe0e = _DAT_00fffe0e & 0xf0ff | 0xd00;
  _DAT_00ffffa2 = _DAT_00807cd6 / DAT_00807cce << 8;
  _DAT_00ffffa6 = 0;
  rpm_timer_capture_value = 0;
  _DAT_00ffffa0 = 0xb;
  _DAT_00fffe14 = _DAT_00fffe14 & 0xffcf | 0x30;
  _DAT_00fffe18 = _DAT_00fffe18 & 0xffcf | 0x30;
  _DAT_00fffe0a = _DAT_00fffe0a | 0x400;
  _DAT_00fffe1c = _DAT_00fffe1c & 0xffcf | 0x20;
  if (DAT_00807cf7 == '\0') {
    _DAT_0080c78e = &LAB_0001416c;
  }
  return;
}



//
// Function: can1MessageTransmitInit2 @ 0x000160e2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void can1MessageTransmitInit2(void)

{
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfffe;
  _DAT_00fffe12 = _DAT_00fffe12 & 0xfff0 | 9;
  _DAT_00ffff00 = 4;
  _DAT_00ffff02 = DAT_00807d02 | 0x100;
  _DAT_00ffff06 = CONCAT11(DAT_00807d03,CPMXTAES._0_1_);
  _DAT_00fffffc = 0xc000;
  _DAT_00fffe16 = _DAT_00fffe16 & 0xfffc | 3;
  _DAT_00fffe1a = _DAT_00fffe1a & 0xfffc | 1;
  _DAT_00fffe1e = _DAT_00fffe1e & 0xfffc | 2;
  _DAT_00808ec2 = &LAB_00016370;
  _DAT_00fffe0a = _DAT_00fffe0a & 0xfffe | 1;
  FUN_0002b5aa();
  return;
}



//
// Function: emptyStubFunction7 @ 0x00016190
//

void emptyStubFunction7(void)

{
  return;
}



//
// Function: rpmTimerInterruptHandler2 @ 0x00016192
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 rpmTimerInterruptHandler2(void)

{
  dword dVar1;
  undefined4 in_D0;
  undefined4 in_D1;
  undefined2 uVar2;
  undefined2 uStack_1e;
  
  dVar1 = rpm_timer_capture_value;
  uVar2 = (undefined2)((uint)in_D0 >> 0x10);
  uStack_1e = (undefined2)in_D0;
  _DAT_0080c75c = rpm_timer_capture_value;
  rpm_timer_capture_value = rpm_timer_capture_value & 0xffff;
  _DAT_0080c776 =
       dVar1 + (_DAT_0080c776 - *(int *)circular_buffer_t_0080c3fc.data_buffer_rest._16_4_);
  *(dword *)circular_buffer_t_0080c3fc.data_buffer_rest._16_4_ = dVar1;
  if ((uint)circular_buffer_t_0080c3fc.data_buffer_rest._16_4_ < _DAT_0080c77e) {
    circular_buffer_t_0080c3fc.data_buffer_rest._16_4_ =
         circular_buffer_t_0080c3fc.data_buffer_rest._16_4_ + 4;
  }
  else {
    circular_buffer_t_0080c3fc.data_buffer_rest[0x10] = 0;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x11] = 0x80;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x12] = 0xc4;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x13] = 0x30;
  }
  if ((uint)circular_buffer_t_0080c3fc.data_buffer_rest._8_4_ < -(uint)_DAT_00807cd2 - 1) {
    circular_buffer_t_0080c3fc.data_buffer_rest._8_4_ =
         (uint)_DAT_00807cd2 + circular_buffer_t_0080c3fc.data_buffer_rest._8_4_;
  }
  circular_buffer_t_0080c3fc.data_buffer_rest._0_4_ =
       _DAT_0080c75c + (circular_buffer_t_0080c3fc.data_buffer_rest._0_4_ - *(int *)_DAT_0080c786);
  if (_DAT_0080c786 < _DAT_0080c77e) {
    _DAT_0080c786 = (byte *)((int)_DAT_0080c786 + 4);
  }
  else {
    _DAT_0080c786 = circular_buffer_t_0080c3fc.data_buffer_rest + 0x26;
  }
  if ((int)(uint)_DAT_0080c7ae < (int)(DAT_00807cce - 1)) {
    _DAT_0080c7ae = _DAT_0080c7ae + 1;
  }
  else {
    _DAT_0080c7ae = 0;
  }
  circular_buffer_t_0080c3fc.data_buffer_rest[0x18] = DAT_0080c772;
  circular_buffer_t_0080c3fc.data_buffer_rest[0x19] = DAT_0080c772_1;
  if (CPMNFL == 1) {
    if (DAT_0080c7d4 == '\0') {
      if (DAT_0080c7d3 < DAT_00807d20) {
        DAT_0080c7d3 = DAT_0080c7d3 + 1;
      }
      else {
        fault_status_registers_t_00805df2.sensor_fault_status =
             fault_status_registers_t_00805df2.sensor_fault_status | 1;
        fault_latch_registers_t_00805e32.sensor_fault_latch =
             fault_latch_registers_t_00805e32.sensor_fault_latch | 1;
      }
      DAT_0080c7b2 = 2;
      fault_status_registers_t_00805df2.engine_fault_status =
           fault_status_registers_t_00805df2.engine_fault_status | 0x800;
      fault_latch_registers_t_00805e32.engine_fault_latch =
           fault_latch_registers_t_00805e32.engine_fault_latch | 0x800;
    }
    else {
      DAT_0080c7d4 = DAT_0080c7d4 + -1;
      if (DAT_0080c7d3 == 0) {
        if (((fault_status_registers_t_00805df2.sensor_fault_status & 1) != 0) &&
           ((fault_latch_registers_t_00805e32.sensor_fault_latch & 1) == 0)) {
          fault_status_registers_t_00805df2.sensor_fault_status =
               fault_status_registers_t_00805df2.sensor_fault_status & 0xfffe;
        }
      }
      else {
        DAT_0080c7d3 = DAT_0080c7d3 - 1;
      }
    }
  }
  vp44_communication_state_machine(CONCAT22(1,uVar2));
  vp44_communication_state_machine(CONCAT22(1,uVar2));
  if ((_DAT_0080c75c < -_DAT_0080c750 - 1U) &&
     (_DAT_0080c750 = _DAT_0080c75c + _DAT_0080c750, _DAT_0080c758 != -1)) {
    _DAT_0080c758 = _DAT_0080c758 + 1;
  }
  rpmTimingDeltaComparator();
  emptyStubFunction3();
  if ((_DAT_0080c75c < -_DAT_0080c750 - 1U) &&
     (_DAT_0080c750 = _DAT_0080c75c + _DAT_0080c750, _DAT_0080c758 != -1)) {
    _DAT_0080c758 = _DAT_0080c758 + 1;
  }
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfbff;
  return CONCAT44(CONCAT22(uVar2,uStack_1e),in_D1);
}



//
// Function: can1TimerBufferInitConditional @ 0x000163f8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint can1TimerBufferInitConditional(void)

{
  undefined4 in_D0;
  uint uVar1;
  byte *pbVar2;
  
  uVar1 = CONCAT22((short)((uint)in_D0 >> 0x10),_DAT_00807ce2) & 0xffff0001;
  if ((_DAT_00807ce2 & 1) != 0) {
    _DAT_00fffe1c = _DAT_00fffe1c & 0xffcf;
    _DAT_00fffe0a = _DAT_00fffe0a & 0xfbff;
    _DAT_00fffe20 = _DAT_00fffe20 & 0xfbff;
    _DAT_0080c77e = circular_buffer_t_0080c3fc.data_buffer_rest + (uint)DAT_00807cce * 4 + 0x22;
    for (pbVar2 = circular_buffer_t_0080c3fc.data_buffer_rest + 0x26; pbVar2 <= _DAT_0080c77e;
        pbVar2 = pbVar2 + 4) {
      *(int *)pbVar2 = _CRFLOFPZ;
    }
    _DAT_0080c786 = 0x80c430;
    if (DAT_00807cd0 < 2) {
      circular_buffer_t_0080c3fc.data_buffer_rest[0x10] = 0;
      circular_buffer_t_0080c3fc.data_buffer_rest[0x11] = 0x80;
      circular_buffer_t_0080c3fc.data_buffer_rest[0x12] = 0xc4;
      circular_buffer_t_0080c3fc.data_buffer_rest[0x13] = 0x30;
    }
    else {
      circular_buffer_t_0080c3fc.data_buffer_rest._16_4_ = (uint)DAT_00807cd0 * 4 + 0x80c430;
    }
    _DAT_0080c776 = _CRFLOFPZ * (uint)DAT_00807cce;
    uVar1 = _CRFLOFPZ * (uint)DAT_00807cd0;
    _DAT_00800332 = 0x80c430;
    _DAT_00808eea = rpmTimerInterruptHandler3;
    _DAT_00fffe0e = _DAT_00fffe0e & 0xf0ff | 0xd00;
    _DAT_00ffffa2 = 0x100;
    _DAT_00ffffa6 = 0;
    rpm_timer_capture_value = 0;
    _DAT_00ffffa0 = 7;
    _DAT_00fffe14 = _DAT_00fffe14 & 0xffcf | 0x20;
    _DAT_00fffe18 = _DAT_00fffe18 & 0xffcf | 0x30;
    _DAT_00fffe0a = _DAT_00fffe0a | 0x400;
    _DAT_00fffe1c = _DAT_00fffe1c & 0xffcf | 0x20;
    _DAT_0080c792 = &LAB_00016814;
    circular_buffer_t_0080c3fc.data_buffer_rest._0_4_ = uVar1;
  }
  if (DAT_00807cf7 == '\0') {
    _DAT_0080c78e = &LAB_0001416c;
  }
  return uVar1;
}



//
// Function: delayWithWatchdogServiceWrapper2 @ 0x00016548
//

void delayWithWatchdogServiceWrapper2(void)

{
  FUN_0002b5aa();
  return;
}



//
// Function: emptyStubFunction8 @ 0x00016550
//

void emptyStubFunction8(void)

{
  return;
}



//
// Function: rpmTimerInterruptHandler3 @ 0x00016552
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 rpmTimerInterruptHandler3(void)

{
  dword dVar1;
  undefined4 in_D0;
  int iVar2;
  undefined4 in_D1;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uStack_22;
  
  dVar1 = rpm_timer_capture_value;
  uVar4 = (undefined2)((uint)in_D0 >> 0x10);
  uStack_22 = (undefined2)in_D0;
  rpm_timer_capture_value = rpm_timer_capture_value & 0xffff;
  uVar3 = (undefined2)(dVar1 >> 0x10);
  iVar2 = throttleTimeAccumulatorProcessor(dVar1,CONCAT22(_DAT_00ffffa4,uVar4));
  if (DAT_0080c7b2 == '\x01') {
    if (iVar2 == 0) {
      _DAT_00ffffa0 = 0xffff;
      _DAT_00fffe18 = _DAT_00fffe18 & 0xffcf | 0x20;
    }
  }
  else {
    _DAT_00ffffa0 = 0x8080;
    _DAT_00fffe18 = _DAT_00fffe18 & 0xffcf | 0x20;
  }
  vp44_communication_state_machine(CONCAT22(1,uVar3));
  if ((_DAT_0080c75c < -_DAT_0080c750 - 1U) &&
     (_DAT_0080c750 = _DAT_0080c75c + _DAT_0080c750, _DAT_0080c758 != -1)) {
    _DAT_0080c758 = _DAT_0080c758 + 1;
  }
  rpmTimingDeltaComparator();
  emptyStubFunction3();
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfbff;
  return CONCAT44(CONCAT22(uVar4,uStack_22),in_D1);
}



//
// Function: throttleTimeAccumulatorProcessor @ 0x00016622
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int throttleTimeAccumulatorProcessor(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  short sVar2;
  uint unaff_A2;
  
  _DAT_0080c75c = param_1;
  _DAT_0080c764 = param_2._0_2_;
  sVar2 = throttlePositionValidator(unaff_A2 >> 0x10);
  if (sVar2 != 0) {
    if (DAT_00807cce == _DAT_00800322) {
      DAT_0080c7b2 = '\x01';
    }
    else {
      if (DAT_0080c7b2 == '\x01') {
        DAT_0080c7b2 = '\x02';
      }
      if ((circular_buffer_t_0080c3fc.data_buffer_4 < _DAT_00807ce6) &&
         (_DAT_0080c7b8 < CPMNES._0_1_)) {
        _DAT_0080c7b8 = _DAT_0080c7b8 + 1;
      }
      else if (((DAT_0080c7b2 == '\x02') && (_DAT_0080c7a2 <= _DAT_0080c7a4)) ||
              ((DAT_0080c7b6 == '\x02' && (_DAT_0080c7a2 <= _DAT_0080c7a6)))) {
        fault_status_registers_t_00805df2.engine_fault_status =
             fault_status_registers_t_00805df2.engine_fault_status | 0x800;
        fault_latch_registers_t_00805e32.engine_fault_latch =
             fault_latch_registers_t_00805e32.engine_fault_latch | 0x800;
      }
    }
    uVar1 = _DAT_0080c772;
    _DAT_0080032a = _DAT_0080c75c;
    _DAT_00800322 = 0;
    DAT_0080c772 = SUB21(_DAT_0080c772,1);
    DAT_0080c772_1 = (byte)_DAT_0080c772;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x18] = DAT_0080c772;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x19] = DAT_0080c772_1;
    _DAT_0080c772 = uVar1;
    return 0;
  }
  _DAT_00800322 = _DAT_00800322 + 1;
  if (_DAT_00800322 == 1) {
    _DAT_0080c75c = _DAT_0080032a + _DAT_0080c75c;
    _DAT_0080c7ae = 0;
  }
  else if ((_DAT_0080c7ae < DAT_00807cce) || (DAT_0080c7b2 != '\x01')) {
    _DAT_0080c7ae = _DAT_0080c7ae + 1;
  }
  else {
    DAT_0080c7b2 = '\x02';
  }
  _DAT_0080c776 =
       _DAT_0080c75c + (_DAT_0080c776 - *(int *)circular_buffer_t_0080c3fc.data_buffer_rest._16_4_);
  *(int *)circular_buffer_t_0080c3fc.data_buffer_rest._16_4_ = _DAT_0080c75c;
  if ((uint)circular_buffer_t_0080c3fc.data_buffer_rest._16_4_ < _DAT_0080c77e) {
    circular_buffer_t_0080c3fc.data_buffer_rest._16_4_ =
         circular_buffer_t_0080c3fc.data_buffer_rest._16_4_ + 4;
  }
  else {
    circular_buffer_t_0080c3fc.data_buffer_rest[0x10] = 0;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x11] = 0x80;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x12] = 0xc4;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x13] = 0x30;
  }
  if ((uint)circular_buffer_t_0080c3fc.data_buffer_rest._8_4_ < -(uint)_DAT_00807cd2 - 1) {
    circular_buffer_t_0080c3fc.data_buffer_rest._8_4_ =
         (uint)_DAT_00807cd2 + circular_buffer_t_0080c3fc.data_buffer_rest._8_4_;
  }
  circular_buffer_t_0080c3fc.data_buffer_rest._0_4_ =
       _DAT_0080c75c + (circular_buffer_t_0080c3fc.data_buffer_rest._0_4_ - *(int *)_DAT_0080c786);
  if (_DAT_0080c786 < _DAT_0080c77e) {
    _DAT_0080c786 = (byte *)((int)_DAT_0080c786 + 4);
  }
  else {
    _DAT_0080c786 = circular_buffer_t_0080c3fc.data_buffer_rest + 0x26;
  }
  if (_DAT_0080c7a6 != 0 || _DAT_0080c7a4 != 0) {
    circular_buffer_t_0080c3fc.data_buffer_rest[0x18] = DAT_0080c772;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x19] = DAT_0080c772_1;
    return _DAT_00800322;
  }
  if ((fault_status_registers_t_00805df2.engine_fault_status & 0x800) == 0) {
    circular_buffer_t_0080c3fc.data_buffer_rest[0x18] = DAT_0080c772;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x19] = DAT_0080c772_1;
    _DAT_0080c7b8 = 0;
    return _DAT_00800322;
  }
  if ((fault_latch_registers_t_00805e32.engine_fault_latch & 0x800) != 0) {
    circular_buffer_t_0080c3fc.data_buffer_rest[0x18] = DAT_0080c772;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x19] = DAT_0080c772_1;
    _DAT_0080c7b8 = 0;
    return _DAT_00800322;
  }
  fault_status_registers_t_00805df2.engine_fault_status =
       fault_status_registers_t_00805df2.engine_fault_status & 0xf7ff;
  circular_buffer_t_0080c3fc.data_buffer_rest[0x18] = DAT_0080c772;
  circular_buffer_t_0080c3fc.data_buffer_rest[0x19] = DAT_0080c772_1;
  _DAT_0080c7b8 = 0;
  return _DAT_00800322;
}



//
// Function: fuelTimingOilPressureModeController @ 0x0001685c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort fuelTimingOilPressureModeController(void)

{
  ushort uVar1;
  
  uVar1 = _DAT_008035ec & 0x10;
  if (uVar1 != 0) {
    if (_DAT_0080379c == 0) {
      if (_DAT_0080c7c6 == 2) {
        _DAT_00800342 = CKSPRP;
      }
      else {
        _DAT_00800342 = CKFLRMES;
      }
      if (_DAT_00809d4c < _DAT_00800342) {
        if (_DAT_0080c7c8 < _DAT_00807f26) {
          _DAT_0080c7c8 = _DAT_0080c7c8 + 1;
        }
      }
      else {
        _DAT_0080c7c8 = 0;
      }
      if (((_DAT_00809d4c < CKFLRMES) && (_DAT_00807f26 <= _DAT_0080c7c8)) || (_DAT_0080c7c6 == 2))
      {
        _DAT_0080c7ca = 0;
      }
      else if (_DAT_0080c7ca < _DAT_00807f28) {
        _DAT_0080c7ca = _DAT_0080c7ca + 1;
      }
      _DAT_00800346 = _DAT_00800344 - circular_buffer_t_0080c3fc.data_buffer_8;
      _DAT_00800344 = circular_buffer_t_0080c3fc.data_buffer_8;
      _DAT_0080c7c2 = exponentialMovingAverage();
      if ((int)(uint)CKEXESOF < (int)_DAT_0080c7c2) {
        if (_DAT_0080c7c0 < CKEXFLOF) {
          _DAT_0080c7c0 = _DAT_0080c7c0 + 1;
        }
      }
      else {
        _DAT_0080c7c0 = 0;
      }
      FUN_0002c252();
      if (_DAT_0080c7c6 == 0) {
        if ((((int)((uint)_DAT_0080c9d8 - (uint)_DAT_00807f24) <=
              (int)(uint)fuel_demand_state_t_0080c9a4.command) && (_DAT_0080c7ce != 0)) &&
           (((DAT_0080bdc7 & 8) == 0 &&
            ((_DAT_0080926e < CKFLOFMX && (_DAT_008091ea < _DAT_00807f1c)))))) {
          _DAT_0080c7c4 = 0x4000;
          _DAT_0080c7c6 = 2;
        }
        if ((((((_DAT_008035ec & 0x20) != 0) && ((DAT_0080bdc7 & 8) == 0)) && (_DAT_0080c7cc != 0))
            && ((timing_mode_control_t_0080965a.blend_factor < CKJSESRT &&
                (CKFLRMES <= _DAT_00809d4c)))) &&
           ((_DAT_0080926e < CKFLOFMX && (_DAT_008091ea < _DAT_00807f1c)))) {
          _DAT_0080c7c4 = CKEXFLRT;
          _DAT_0080c7c6 = 1;
        }
      }
      else if (_DAT_0080c7c6 == 2) {
        if (((_DAT_0080c7ce != 0) || (_DAT_00807f1e < _DAT_0080926e)) ||
           (_DAT_00807f20 < _DAT_008091ea)) {
          _DAT_0080c7c4 = 0;
          _DAT_0080c7c6 = 0;
        }
      }
      else if (_DAT_0080c7c6 == 1) {
        if ((((_DAT_0080c7cc != 0) || (CKJSESRT <= timing_mode_control_t_0080965a.blend_factor)) ||
            (_DAT_00807f26 <= _DAT_0080c7c8)) ||
           ((_DAT_00807f1e < _DAT_0080926e || (_DAT_00807f20 < _DAT_008091ea)))) {
          _DAT_0080c7c4 = 0;
          _DAT_0080c7c6 = 0;
        }
      }
      else {
        _DAT_0080c7c4 = 0;
        _DAT_0080c7c6 = 0;
      }
    }
    else {
      _DAT_0080c7c6 = _DAT_0080379a;
      if (_DAT_0080379a == 0) {
        _DAT_0080c7c4 = 0;
      }
      else if (_DAT_0080379a == 2) {
        _DAT_0080c7c4 = 0x4000;
      }
      else {
        _DAT_0080c7c4 = CKEXFLRT;
      }
    }
    uVar1 = 0x4000 - _DAT_0080c7c4;
    fuel_demand_state_t_0080c9a4.timing_blend_factor = uVar1;
  }
  return uVar1;
}



//
// Function: initOilPressureModeSystem @ 0x00016af2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initOilPressureModeSystem(void)

{
  _DAT_0080c7c6 = 0;
  _DAT_0080033e = 0x80000000;
  _DAT_0080033a = &CKCNEXTM;
  return;
}



//
// Function: oilPressureModeParameterPointerConfig @ 0x00016b0e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort oilPressureModeParameterPointerConfig(void)

{
  ushort uVar1;
  
  uVar1 = _DAT_008035ec & 0x10;
  if ((_DAT_008035ec & 0x10) != 0) {
    if (_DAT_0080c7c6 == 0) {
      _DAT_0080cc5e = 0x807f2a;
      _DAT_0080cc62 = 0x807f2c;
      _DAT_0080cc66 = 0x807f2e;
      return 0;
    }
    if (_DAT_0080c7c6 == 2) {
      _DAT_0080cc5e = 0x807f30;
      _DAT_0080cc62 = 0x807f32;
      _DAT_0080cc66 = 0x807f34;
      return 2;
    }
    if (_DAT_0080c7c6 == 1) {
      _DAT_0080cc5e = 0x807f36;
      _DAT_0080cc62 = 0x807f38;
      _DAT_0080cc66 = 0x807f3a;
      return 1;
    }
    _DAT_0080cc5e = 0x807f2a;
    _DAT_0080cc62 = 0x807f2c;
    _DAT_0080cc66 = 0x807f2e;
    uVar1 = _DAT_0080c7c6;
  }
  return uVar1;
}



//
// Function: dutyCycleMonitorCanInit @ 0x00016ba8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void dutyCycleMonitorCanInit(void)

{
  byte *pbVar1;
  
  _DAT_00fffe1e = _DAT_00fffe1e & 0xfff3;
  _DAT_00fffe0a = _DAT_00fffe0a & 0xfffd;
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfffd;
  DAT_0080c7b2 = 0;
  DAT_0080c7b3 = 0;
  _DAT_0080c782 = circular_buffer_t_0080c3fc.data_buffer_rest + (uint)DAT_00807ccf * 4 + 0x1b2;
  for (pbVar1 = circular_buffer_t_0080c3fc.data_buffer_rest + 0x1b6; pbVar1 <= _DAT_0080c782;
      pbVar1 = pbVar1 + 4) {
    *(int *)pbVar1 = _DAT_00807cca;
  }
  _DAT_0080c78a = 0x80c5c0;
  if (DAT_00807cd1 < 2) {
    circular_buffer_t_0080c3fc.data_buffer_rest[0x14] = 0;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x15] = 0x80;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x16] = 0xc5;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x17] = 0xc0;
  }
  else {
    circular_buffer_t_0080c3fc.data_buffer_rest._20_4_ = (uint)DAT_00807cd1 * 4 + 0x80c5c0;
  }
  _DAT_0080c77a = _DAT_00807cca * (uint)DAT_00807ccf;
  circular_buffer_t_0080c3fc.data_buffer_rest._4_4_ = _DAT_00807cca * (uint)DAT_00807cd1;
  _DAT_00808ec6 = dutyCycleMonitorIsrHandler;
  _DAT_00fffe12 = _DAT_00fffe12 & 0xff0f | 0xd0;
  _DAT_00ffff12 = 0x100;
  _DAT_00ffff16 = 0;
  _DAT_00ffff18 = 0;
  _DAT_00ffff10 = 0x4f;
  _DAT_00fffe16 = _DAT_00fffe16 & 0xfff3;
  _DAT_00fffe1a = _DAT_00fffe1a & 0xfff3 | 0xc;
  _DAT_00fffe0a = _DAT_00fffe0a | 2;
  _DAT_00fffe1e = _DAT_00fffe1e & 0xfff3 | 8;
  return;
}



//
// Function: dutyCycleMonitorIsrHandler @ 0x00016cb4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 dutyCycleMonitorIsrHandler(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  DAT_0080c7d0 = DAT_00ffff1b;
  _DAT_00ffff18 = 0;
  DAT_0080c7d4 = DAT_00807d1d;
  if (DAT_00ffff1b == _DAT_00807d18) {
    if (DAT_0080c7d2 == 0) {
      if (((fault_status_registers_t_00805df2.sensor_fault_status & 1) != 0) &&
         ((fault_latch_registers_t_00805e32.sensor_fault_latch & 1) == 0)) {
        fault_status_registers_t_00805df2.sensor_fault_status =
             fault_status_registers_t_00805df2.sensor_fault_status & 0xfffe;
      }
    }
    else {
      DAT_0080c7d2 = DAT_0080c7d2 - 1;
    }
    if (_DAT_0080c7ae == CPMXFLMF) {
      DAT_0080c7b2 = 1;
      DAT_0080c7b3 = 1;
      if (((fault_status_registers_t_00805df2.engine_fault_status & 0x800) != 0) &&
         ((fault_latch_registers_t_00805e32.engine_fault_latch & 0x800) == 0)) {
        fault_status_registers_t_00805df2.engine_fault_status =
             fault_status_registers_t_00805df2.engine_fault_status & 0xf7ff;
      }
      if (DAT_0080c7d1 == 0) {
        if (((fault_status_registers_t_00805df2.sensor_fault_status & 1) != 0) &&
           ((fault_latch_registers_t_00805e32.sensor_fault_latch & 1) == 0)) {
          fault_status_registers_t_00805df2.sensor_fault_status =
               fault_status_registers_t_00805df2.sensor_fault_status & 0xfffe;
        }
      }
      else {
        DAT_0080c7d1 = DAT_0080c7d1 - 1;
      }
    }
    else {
      DAT_0080c7b2 = 2;
      DAT_0080c7b3 = 2;
      _DAT_0080c7ae = CPMXFLMF;
      if (DAT_0080c7d1 < duty_cycle_monitor_DCMNESTB_00807d1e.rpm_thresholds._0_1_) {
        DAT_0080c7d1 = DAT_0080c7d1 + 1;
      }
      else {
        fault_status_registers_t_00805df2.sensor_fault_status =
             fault_status_registers_t_00805df2.sensor_fault_status | 1;
        fault_latch_registers_t_00805e32.sensor_fault_latch =
             fault_latch_registers_t_00805e32.sensor_fault_latch | 1;
        fault_status_registers_t_00805df2.engine_fault_status =
             fault_status_registers_t_00805df2.engine_fault_status | 0x800;
        fault_latch_registers_t_00805e32.engine_fault_latch =
             fault_latch_registers_t_00805e32.engine_fault_latch | 0x800;
      }
    }
  }
  else if (DAT_00ffff1b == _DAT_00807d1a) {
    if (DAT_0080c7d2 == 0) {
      if (((fault_status_registers_t_00805df2.sensor_fault_status & 1) != 0) &&
         ((fault_latch_registers_t_00805e32.sensor_fault_latch & 1) == 0)) {
        fault_status_registers_t_00805df2.sensor_fault_status =
             fault_status_registers_t_00805df2.sensor_fault_status & 0xfffe;
      }
    }
    else {
      DAT_0080c7d2 = DAT_0080c7d2 - 1;
    }
    if (_DAT_0080c7ae == CPBS01) {
      DAT_0080c7b2 = 1;
      DAT_0080c7b3 = 1;
      if (((fault_status_registers_t_00805df2.engine_fault_status & 0x800) != 0) &&
         ((fault_latch_registers_t_00805e32.engine_fault_latch & 0x800) == 0)) {
        fault_status_registers_t_00805df2.engine_fault_status =
             fault_status_registers_t_00805df2.engine_fault_status & 0xf7ff;
      }
      if (DAT_0080c7d1 == 0) {
        if (((fault_status_registers_t_00805df2.sensor_fault_status & 1) != 0) &&
           ((fault_latch_registers_t_00805e32.sensor_fault_latch & 1) == 0)) {
          fault_status_registers_t_00805df2.sensor_fault_status =
               fault_status_registers_t_00805df2.sensor_fault_status & 0xfffe;
        }
      }
      else {
        DAT_0080c7d1 = DAT_0080c7d1 - 1;
      }
    }
    else {
      DAT_0080c7b2 = 2;
      DAT_0080c7b3 = 2;
      _DAT_0080c7ae = CPBS01;
      if (DAT_0080c7d1 < duty_cycle_monitor_DCMNESTB_00807d1e.rpm_thresholds._0_1_) {
        DAT_0080c7d1 = DAT_0080c7d1 + 1;
      }
      else {
        fault_status_registers_t_00805df2.sensor_fault_status =
             fault_status_registers_t_00805df2.sensor_fault_status | 1;
        fault_latch_registers_t_00805e32.sensor_fault_latch =
             fault_latch_registers_t_00805e32.sensor_fault_latch | 1;
        fault_status_registers_t_00805df2.engine_fault_status =
             fault_status_registers_t_00805df2.engine_fault_status | 0x800;
        fault_latch_registers_t_00805e32.engine_fault_latch =
             fault_latch_registers_t_00805e32.engine_fault_latch | 0x800;
      }
    }
  }
  else if (DAT_0080c7d2 < (byte)duty_cycle_monitor_DCMNESTB_00807d1e.rpm_thresholds) {
    DAT_0080c7d2 = DAT_0080c7d2 + 1;
  }
  else {
    fault_status_registers_t_00805df2.sensor_fault_status =
         fault_status_registers_t_00805df2.sensor_fault_status | 1;
    fault_latch_registers_t_00805e32.sensor_fault_latch =
         fault_latch_registers_t_00805e32.sensor_fault_latch | 1;
  }
  if ((_DAT_0080c760 < -_DAT_0080c754 - 1U) &&
     (_DAT_0080c754 = _DAT_0080c760 + _DAT_0080c754, _DAT_0080c75a != -1)) {
    _DAT_0080c75a = _DAT_0080c75a + 1;
  }
  FUN_0002b6c2();
  emptyStubFunction2();
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfffd;
  return CONCAT44(in_D0,in_D1);
}



//
// Function: dutyCycleMonitorAltCanInit @ 0x00016f98
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint dutyCycleMonitorAltCanInit(void)

{
  byte *pbVar1;
  
  _DAT_00fffe1e = _DAT_00fffe1e & 0xfff3;
  _DAT_00fffe0a = _DAT_00fffe0a & 0xfffd;
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfffd;
  _DAT_0080c782 = circular_buffer_t_0080c3fc.data_buffer_rest + (uint)DAT_00807ccf * 4 + 0x1b2;
  for (pbVar1 = circular_buffer_t_0080c3fc.data_buffer_rest + 0x1b6; pbVar1 <= _DAT_0080c782;
      pbVar1 = pbVar1 + 4) {
    *(int *)pbVar1 = _DAT_00807cca;
  }
  _DAT_0080c78a = 0x80c5c0;
  if (DAT_00807cd1 < 2) {
    circular_buffer_t_0080c3fc.data_buffer_rest[0x14] = 0;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x15] = 0x80;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x16] = 0xc5;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x17] = 0xc0;
  }
  else {
    circular_buffer_t_0080c3fc.data_buffer_rest._20_4_ = (uint)DAT_00807cd1 * 4 + 0x80c5c0;
  }
  _DAT_0080c77a = _DAT_00807cca * (uint)DAT_00807ccf;
  circular_buffer_t_0080c3fc.data_buffer_rest._4_4_ = _DAT_00807cca * (uint)DAT_00807cd1;
  if ((_DAT_00807ce2 & 8) != 0) {
    _DAT_00808ec6 = dutyCycleMonitorAltIsrHandler;
    _DAT_00fffe12 = _DAT_00fffe12 & 0xff0f | 0xd0;
    _DAT_00ffff12 = 0x100;
    _DAT_00ffff16 = 0;
    _DAT_00ffff18 = 0;
    _DAT_00ffff10 = 0xb;
    _DAT_00fffe16 = _DAT_00fffe16 & 0xfff3 | 0xc;
    _DAT_00fffe1a = _DAT_00fffe1a & 0xfff3 | 0xc;
    _DAT_00fffe0a = _DAT_00fffe0a | 2;
    _DAT_00fffe1e = _DAT_00fffe1e & 0xfff3 | 8;
    _DAT_00fffe20 = _DAT_00fffe20 & 0xfffd;
  }
  return CONCAT22((short)(_DAT_00807cca * (uint)DAT_00807cd1 >> 0x10),_DAT_00807ce2) & 0xffff0008;
}



//
// Function: dutyCycleMonitorAltIsrHandler @ 0x000170b4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 dutyCycleMonitorAltIsrHandler(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  if ((_DAT_00807ce2 & 8) != 0) {
    circular_buffer_t_0080c3fc.data_buffer_rest._26_2_ = _DAT_0080c774;
    _DAT_0080c760 = _DAT_00ffff18;
    DAT_0080c7b4 = 1;
    if (((fault_status_registers_t_00805df2.engine_fault_status & 0x800) != 0) &&
       ((fault_latch_registers_t_00805e32.engine_fault_latch & 0x800) == 0)) {
      fault_status_registers_t_00805df2.engine_fault_status =
           fault_status_registers_t_00805df2.engine_fault_status & 0xf7ff;
    }
    circular_buffer_t_0080c3fc.data_buffer_rest._438_4_ = _DAT_00ffff18;
    circular_buffer_t_0080c3fc.data_buffer_rest._4_4_ = _DAT_00ffff18;
  }
  _DAT_00ffff18 = _DAT_00ffff18 & 0xffff;
  if ((_DAT_0080c760 < -_DAT_0080c754 - 1U) &&
     (_DAT_0080c754 = _DAT_0080c760 + _DAT_0080c754, _DAT_0080c75a != -1)) {
    _DAT_0080c75a = _DAT_0080c75a + 1;
  }
  FUN_0002b6c2();
  emptyStubFunction2();
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfffd;
  return CONCAT44(in_D0,in_D1);
}



//
// Function: dutyCycleMonitorBufferInit @ 0x00017164
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void dutyCycleMonitorBufferInit(void)

{
  byte *pbVar1;
  
  _DAT_0080c782 = circular_buffer_t_0080c3fc.data_buffer_rest + (uint)DAT_00807ccf * 4 + 0x1b2;
  for (pbVar1 = circular_buffer_t_0080c3fc.data_buffer_rest + 0x1b6; pbVar1 <= _DAT_0080c782;
      pbVar1 = pbVar1 + 4) {
    *(int *)pbVar1 = _DAT_00807cca;
  }
  _DAT_0080c78a = 0x80c5c0;
  if (DAT_00807cd1 < 2) {
    circular_buffer_t_0080c3fc.data_buffer_rest[0x14] = 0;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x15] = 0x80;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x16] = 0xc5;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x17] = 0xc0;
  }
  else {
    circular_buffer_t_0080c3fc.data_buffer_rest._20_4_ = (uint)DAT_00807cd1 * 4 + 0x80c5c0;
  }
  _DAT_0080c77a = _DAT_00807cca * (uint)DAT_00807ccf;
  circular_buffer_t_0080c3fc.data_buffer_rest._4_4_ = _DAT_00807cca * (uint)DAT_00807cd1;
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfffd;
  _DAT_00fffe12 = _DAT_00fffe12 & 0xff0f | 0xd0;
  _DAT_00ffff12 = 0x100;
  _DAT_00ffff16 = 0;
  _DAT_00ffff18 = 0;
  _DAT_00ffff10 = 0xb;
  _DAT_00fffe16 = _DAT_00fffe16 & 0xfff3 | 0xc;
  _DAT_00fffe1a = _DAT_00fffe1a & 0xfff3 | 0xc;
  _DAT_00fffe1e = _DAT_00fffe1e & 0xfff3 | 8;
  _DAT_00808ec6 = timerAccumulatorWithWatchdog;
  _DAT_00fffe0a = _DAT_00fffe0a & 0xfffd | 2;
  DAT_0080c7de = 0;
  _DAT_0080c7e4 = 0;
  return;
}



//
// Function: phase2_slot_0_handler @ 0x000171a6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void phase2_slot_0_handler(void)

{
  int *in_A1;
  int unaff_A3;
  byte *unaff_A4;
  
  circular_buffer_t_0080c3fc.data_buffer_rest._20_4_ = unaff_A3 + (uint)*unaff_A4 * 4;
  _DAT_0080c77a = *in_A1 * (uint)DAT_00807ccf;
  circular_buffer_t_0080c3fc.data_buffer_rest._4_4_ = *in_A1 * (uint)*unaff_A4;
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfffd;
  _DAT_00fffe12 = _DAT_00fffe12 & 0xff0f | 0xd0;
  _DAT_00ffff12 = 0x100;
  _DAT_00ffff16 = 0;
  _DAT_00ffff18 = 0;
  _DAT_00ffff10 = 0xb;
  _DAT_00fffe16 = _DAT_00fffe16 & 0xfff3 | 0xc;
  _DAT_00fffe1a = _DAT_00fffe1a & 0xfff3 | 0xc;
  _DAT_00fffe1e = _DAT_00fffe1e & 0xfff3 | 8;
  _DAT_00808ec6 = timerAccumulatorWithWatchdog;
  _DAT_00fffe0a = _DAT_00fffe0a & 0xfffd | 2;
  DAT_0080c7de = 0;
  _DAT_0080c7e4 = 0;
  return;
}



//
// Function: phase2_slot_1_handler @ 0x000171d2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void phase2_slot_1_handler(void)

{
  int *in_A1;
  byte *unaff_A4;
  
  circular_buffer_t_0080c3fc.data_buffer_rest._4_4_ = *in_A1 * (uint)*unaff_A4;
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfffd;
  _DAT_00fffe12 = _DAT_00fffe12 & 0xff0f | 0xd0;
  _DAT_00ffff12 = 0x100;
  _DAT_00ffff16 = 0;
  _DAT_00ffff18 = 0;
  _DAT_00ffff10 = 0xb;
  _DAT_00fffe16 = _DAT_00fffe16 & 0xfff3 | 0xc;
  _DAT_00fffe1a = _DAT_00fffe1a & 0xfff3 | 0xc;
  _DAT_00fffe1e = _DAT_00fffe1e & 0xfff3 | 8;
  _DAT_00808ec6 = timerAccumulatorWithWatchdog;
  _DAT_00fffe0a = _DAT_00fffe0a & 0xfffd | 2;
  DAT_0080c7de = 0;
  _DAT_0080c7e4 = 0;
  return;
}



//
// Function: phase2_slot_5_handler @ 0x00017266
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void phase2_slot_5_handler(void)

{
  DAT_0080c7de = 0;
  _DAT_0080c7e4 = 0;
  return;
}



//
// Function: timerAccumulatorWithWatchdog @ 0x00017278
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 timerAccumulatorWithWatchdog(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  if ((_DAT_0080c760 < -_DAT_0080c754 - 1U) &&
     (_DAT_0080c754 = _DAT_0080c760 + _DAT_0080c754, _DAT_0080c75a != -1)) {
    _DAT_0080c75a = _DAT_0080c75a + 1;
  }
  FUN_0002b6c2();
  emptyStubFunction2();
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfffd;
  return CONCAT44(in_D0,in_D1);
}



//
// Function: phase2_slot_7_handler @ 0x00017296
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 phase2_slot_7_handler(void)

{
  short *unaff_A2;
  int *unaff_A3;
  int *unaff_A4;
  undefined8 in_stack_00000000;
  
  *unaff_A4 = *unaff_A3 + *unaff_A4;
  if (*unaff_A2 != -1) {
    *unaff_A2 = *unaff_A2 + 1;
  }
  FUN_0002b6c2();
  emptyStubFunction2();
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfffd;
  return in_stack_00000000;
}



//
// Function: phase2_slot_8_handler @ 0x000172ae
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 phase2_slot_8_handler(void)

{
  undefined8 in_stack_00000000;
  
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfffd;
  return in_stack_00000000;
}



//
// Function: ioControlAndCanPinSwitchingWrapper @ 0x000172bc
//

void ioControlAndCanPinSwitchingWrapper(void)

{
  ioControlAndCanPinSwitching();
  return;
}



//
// Function: evenPhaseSchedulerTaskSet @ 0x000172c4
//

void evenPhaseSchedulerTaskSet(void)

{
  timerBasedTaskScheduler();
  systemStatusProcessor();
  memoryRegisterController();
  messageQueueDispatcher();
  systemStatusMonitor();
  return;
}



//
// Function: oddPhaseSchedulerTaskSet @ 0x000172e4
//

void oddPhaseSchedulerTaskSet(void)

{
  phase3_retarder_condition_monitor();
  phase3_periodic_task_scheduler();
  phase3_countdown_timer_manager();
  return;
}



//
// Function: vp44_engine_management_system @ 0x000172f8
//

void vp44_engine_management_system(void)

{
  ushort in_stack_00000000;
  
  vp44_communication_state_machine((uint)in_stack_00000000);
  vp44_status_data_collector();
  engine_fault_monitoring_and_rpm_calculation();
  vp44_rpm_derate_monitor();
  rpm_derate_calculation_and_fault_processing();
  fuel_timing_calculation_with_fault_checking();
  diagnostic_fuel_calculation_with_vp44_monitoring();
  derate_application_controller();
  engine_protection_coordinator();
  return;
}



//
// Function: engine_control_cycle @ 0x00017334
//

void engine_control_cycle(void)

{
  engine_speed_governor();
  diagnostic_parameter_handler();
  oil_pressure_protection_controller();
  advanced_oil_pressure_protection_system();
  oil_pressure_shutdown_controller();
  diagnostic_protection_coordinator();
  fuel_limit_arbitrator();
  fuel_delivery_controller();
  return;
}



//
// Function: engineDiagnosticSystemCoordinator @ 0x00017366
//

void engineDiagnosticSystemCoordinator(void)

{
  engine_fault_monitoring_and_rpm_calculation();
  governorFuelPidController();
  sensorFaultDebounceMonitor();
  faultFlagScannerAndProcessor();
  engineModeTransitionHandler();
  rpmLoadParameterLookup();
  engineOperatingModeStateMachine();
  rpmBasedFuelLimitCalculator();
  diagnosticFuelOverrideHandler();
  fuelDemandModeSelector();
  fuelDemandTableBlendCalculator();
  baseTimingTableLookup();
  return;
}



//
// Function: slowCycle4Coordinator @ 0x000173b0
//

void slowCycle4Coordinator(void)

{
  rpmBasedFuelTimingInterpolation();
  frictionalLoadTorqueTransitionHandler();
  fuelDemandBasedParameterCalculator();
  emptyPlaceholderFunction();
  diagnosticTimingIncrementController();
  diagnosticModeFuelArbitrationHandler();
  liftPumpFuelDeliveryController();
  canPinVp44StatusController();
  derateThresholdIoController();
  engineModeBasedIoController();
  rpmDerateCalculationController();
  return;
}



//
// Function: empty_debug_hook @ 0x000173f4
//

void empty_debug_hook(void)

{
  return;
}



//
// Function: engineParameterAndBoostControlWrapper @ 0x000173f6
//

void engineParameterAndBoostControlWrapper(void)

{
  engineParameterControllerWithTimer();
  boostPressureFeedbackController();
  return;
}



//
// Function: auxiliarySystemControlWrapper @ 0x00017404
//

void auxiliarySystemControlWrapper(void)

{
  fuelTempProtectionLimitCalculator();
  shutdownLimitSelector();
  return;
}



//
// Function: slowCycle8Coordinator @ 0x00017412
//

void slowCycle8Coordinator(void)

{
  vp44SensorStatusMonitor();
  vp44ExtendedProcessingRouter();
  diagnosticFlagResetHandler();
  return;
}



//
// Function: boostPressureControlCoordinator @ 0x00017426
//

void boostPressureControlCoordinator(void)

{
  boostPressureTargetCalculator();
  boostPressureProtectionStateMachine();
  return;
}



//
// Function: boost_pressure_control_wrapper @ 0x00017434
//

void boost_pressure_control_wrapper(void)

{
  boost_pressure_control_and_diagnostics();
  return;
}



//
// Function: emptySlowCycle8Placeholder @ 0x0001743c
//

void emptySlowCycle8Placeholder(void)

{
  return;
}



//
// Function: emptySlowCycle8PlaceholderCase7 @ 0x0001743e
//

void emptySlowCycle8PlaceholderCase7(void)

{
  return;
}



//
// Function: rpm_control_system @ 0x00017440
//

void rpm_control_system(void)

{
  rpm_rate_limiter();
  rpm_system_state_controller();
  return;
}



//
// Function: rpmBasedFuelLimiterCoordinator @ 0x0001744e
//

void rpmBasedFuelLimiterCoordinator(void)

{
  lowRpmFuelProtectionLimiter();
  highRpmFuelControlLimiter();
  return;
}



//
// Function: secondaryMonitoringWrapper @ 0x0001745c
//

void secondaryMonitoringWrapper(void)

{
  j1939TimeoutDataClearHandler();
  return;
}



//
// Function: slowCycle10Coordinator @ 0x00017464
//

void slowCycle10Coordinator(void)

{
  hourMeterEventLogger();
  return;
}



//
// Function: diagnosticMonitoringCoordinator @ 0x0001746c
//

void diagnosticMonitoringCoordinator(void)

{
  oilPressureRpmFaultMonitor();
  liftPumpCommStatusMonitor();
  vp44FsoFaultEnableController();
  multiParameterMinimumSelector();
  return;
}



//
// Function: epsSignalMonitoringCoordinator @ 0x00017486
//

void epsSignalMonitoringCoordinator(void)

{
  epsSignalQualityValidator();
  return;
}



//
// Function: ioControlSlowCycle10Coordinator @ 0x0001748e
//

void ioControlSlowCycle10Coordinator(void)

{
  ioControlPinSwitchingWrapper();
  return;
}



//
// Function: shutdownProtectionSlowCycle10Coordinator @ 0x00017496
//

ulonglong shutdownProtectionSlowCycle10Coordinator(void)

{
  ulonglong uVar1;
  
  uVar1 = shutdownProtectionCalculator();
  return uVar1;
}



//
// Function: diagnosticCommunicationSlowCycle10Coordinator @ 0x0001749e
//

void diagnosticCommunicationSlowCycle10Coordinator(void)

{
  diagnosticCommandDispatcher();
  return;
}



//
// Function: diagnosticDataTransmissionSlowCycle10Coordinator @ 0x000174a6
//

void diagnosticDataTransmissionSlowCycle10Coordinator(void)

{
  diagnosticMessageTransmissionManager();
  return;
}



//
// Function: vp44ControlSystemCoordinator @ 0x000174ae
//

void vp44ControlSystemCoordinator(void)

{
  fuelTimingOilPressureModeController();
  oilPressureModeParameterPointerConfig();
  vp44FsoCircuitFaultDetection();
  vp44FsoCircuitFaultDetectionBit1();
  return;
}



//
// Function: vp44ExtendedFaultDetectionCoordinator @ 0x000174c8
//

void vp44ExtendedFaultDetectionCoordinator(void)

{
  acceleratorThrottleFaultDetector();
  FUN_000343f8();
  FUN_000344e8();
  return;
}



//
// Function: advancedEngineProtectionCoordinator @ 0x000174dc
//

void advancedEngineProtectionCoordinator(void)

{
  crankFuelCalculationAndProtection();
  crankAndProtectionStateMonitor();
  vp44FsoFaultBit0Monitor();
  vp44FsoFaultBit15Monitor();
  vp44FsoMultiBitFaultMonitor();
  return;
}



//
// Function: slowCycle20Coordinator @ 0x000174fc
//

void slowCycle20Coordinator(void)

{
  vp44InjectionSystemStateController();
  return;
}



//
// Function: fuelTimingCoordinator @ 0x00017504
//

void fuelTimingCoordinator(void)

{
  timingOffsetCalculatorWrapper();
  engineModeTimingAdjuster();
  return;
}



//
// Function: slowCycle20ExtendedCoordinator @ 0x00017512
//

void slowCycle20ExtendedCoordinator(void)

{
  engineRunTimeHistogramAccumulator();
  oilPressureFuelArbitrationMonitor();
  vp44FsoStuckHighFaultDetector();
  vp44FsoStuckLowFaultDetector();
  return;
}



//
// Function: fuelCalculationSlowCycle20Coordinator @ 0x0001752c
//

void fuelCalculationSlowCycle20Coordinator(void)

{
  dualTableFuelInterpolationCalculator();
  return;
}



//
// Function: sensorStatusHistorySlowCycle20Coordinator @ 0x00017534
//

void sensorStatusHistorySlowCycle20Coordinator(void)

{
  sensorStatusHistoryTracker();
  return;
}



//
// Function: fuelSmokeLimiterSlowCycle20Coordinator @ 0x0001753c
//

void fuelSmokeLimiterSlowCycle20Coordinator(void)

{
  fuelSmokeLimiterCalculator();
  return;
}



//
// Function: camSyncDiagnosticProcessingSlowCycle20Coordinator @ 0x00017544
//

void camSyncDiagnosticProcessingSlowCycle20Coordinator(void)

{
  camSyncDiagnosticProcessor();
  return;
}



//
// Function: derateProtectionSlowCycle20Coordinator @ 0x0001754c
//

ulonglong derateProtectionSlowCycle20Coordinator(void)

{
  ulonglong uVar1;
  
  uVar1 = derateThresholdMonitorAndFaultController();
  return uVar1;
}



//
// Function: vp44ProtectionSlowCycle20Coordinator @ 0x00017554
//

void vp44ProtectionSlowCycle20Coordinator(void)

{
  vp44FaultProtectionController();
  highRpmEngineProtectionStateMachine();
  vp44FsoFaultDetectionMonitor();
  return;
}



//
// Function: vp44FsoFaultDetectionSlowCycle20Coordinator @ 0x00017568
//

void vp44FsoFaultDetectionSlowCycle20Coordinator(void)

{
  vp44FsoFaultDetectionAndProtectionController();
  return;
}



//
// Function: vp44DiagnosticFaultMonitoringSlowCycle20Coordinator @ 0x00017570
//

void vp44DiagnosticFaultMonitoringSlowCycle20Coordinator(void)

{
  vp44FaultRegisterBit2Monitor();
  vp44DiagnosticSensorThresholdMonitor();
  return;
}



//
// Function: vp44FsoFaultMonitoringSlowCycle20Coordinator @ 0x0001757e
//

void vp44FsoFaultMonitoringSlowCycle20Coordinator(void)

{
  vp44FsoFaultConditionDetector();
  return;
}



//
// Function: emptySlowCycle20PlaceholderCase15 @ 0x00017586
//

void emptySlowCycle20PlaceholderCase15(void)

{
  return;
}



//
// Function: dzgTimingAndPressureSlowCycle10Coordinator @ 0x00017588
//

void dzgTimingAndPressureSlowCycle10Coordinator(void)

{
  dzgTimingAndPressureControlStateMachine();
  return;
}



//
// Function: engineModeBasedOutputControlSlowCycle20Coordinator @ 0x00017590
//

void engineModeBasedOutputControlSlowCycle20Coordinator(void)

{
  faultBasedOutputStateCalculator();
  engineModeOutputControlStateMachine();
  return;
}



//
// Function: vp44DiagnosticControlSlowCycle20Coordinator @ 0x0001759e
//

void vp44DiagnosticControlSlowCycle20Coordinator(void)

{
  vp44SensorDiagnosticControl();
  return;
}



//
// Function: diagnosticStatisticsSlowCycle20Coordinator @ 0x000175a6
//

void diagnosticStatisticsSlowCycle20Coordinator(void)

{
  timeDeltaCalculator();
  fuelStatisticsTracker();
  clutchOperatingStatisticsTracker();
  return;
}



//
// Function: main_loop @ 0x000175ba
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 main_loop(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  mainLoopTaskSchedulerInit();
  switch(_DAT_00800358) {
  case 0:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    vp44_engine_management_system();
    empty_debug_hook();
    rpm_control_system();
    vp44ControlSystemCoordinator();
    incrementCounters();
    _DAT_0080035c = &scheduler_phase_table_t_00809782;
    _DAT_00800358 = 1;
    break;
  case 1:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    engine_control_cycle();
    engineParameterAndBoostControlWrapper();
    rpmBasedFuelLimiterCoordinator();
    vp44ExtendedFaultDetectionCoordinator();
    periodicIoAndCanFaultMonitor();
    _DAT_00800358 = 2;
    break;
  case 2:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    engineDiagnosticSystemCoordinator();
    auxiliarySystemControlWrapper();
    secondaryMonitoringWrapper();
    advancedEngineProtectionCoordinator();
    engineRpmHardwareTimerSetup();
    _DAT_00800358 = 3;
    break;
  case 3:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    slowCycle4Coordinator();
    slowCycle8Coordinator();
    slowCycle10Coordinator();
    slowCycle20Coordinator();
    _DAT_00800358 = 4;
    break;
  case 4:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    vp44_engine_management_system();
    boostPressureControlCoordinator();
    diagnosticMonitoringCoordinator();
    fuelTimingCoordinator();
    canMessageMemorySyncController();
    _DAT_00800358 = 5;
    break;
  case 5:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    engine_control_cycle();
    boost_pressure_control_wrapper();
    epsSignalMonitoringCoordinator();
    slowCycle20ExtendedCoordinator();
    _DAT_00800358 = 6;
    break;
  case 6:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    engineDiagnosticSystemCoordinator();
    emptySlowCycle8Placeholder();
    ioControlSlowCycle10Coordinator();
    fuelCalculationSlowCycle20Coordinator();
    kickdownSignalSlowCycle40Coordinator();
    _DAT_00800358 = 7;
    break;
  case 7:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    slowCycle4Coordinator();
    emptySlowCycle8PlaceholderCase7();
    shutdownProtectionSlowCycle10Coordinator();
    sensorStatusHistorySlowCycle20Coordinator();
    engineDataTrendingSlowCycle40Coordinator();
    _DAT_00800358 = 8;
    break;
  case 8:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    vp44_engine_management_system();
    empty_debug_hook();
    diagnosticCommunicationSlowCycle10Coordinator();
    fuelSmokeLimiterSlowCycle20Coordinator();
    coldStartFuelControlSlowCycle40Coordinator();
    _DAT_00800358 = 9;
    break;
  case 9:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    engine_control_cycle();
    engineParameterAndBoostControlWrapper();
    diagnosticDataTransmissionSlowCycle10Coordinator();
    camSyncDiagnosticProcessingSlowCycle20Coordinator();
    fuelTimingModeArbitrationSlowCycle40Coordinator();
    _DAT_00800358 = 10;
    break;
  case 10:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    engineDiagnosticSystemCoordinator();
    auxiliarySystemControlWrapper();
    rpm_control_system();
    derateProtectionSlowCycle20Coordinator();
    ioOutputFlagMappingSlowCycle40Coordinator();
    _DAT_00800358 = 0xb;
    break;
  case 0xb:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    slowCycle4Coordinator();
    slowCycle8Coordinator();
    rpmBasedFuelLimiterCoordinator();
    vp44ProtectionSlowCycle20Coordinator();
    shutdownProtectionSlowCycle40Coordinator();
    _DAT_00800358 = 0xc;
    break;
  case 0xc:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    vp44_engine_management_system();
    boostPressureControlCoordinator();
    secondaryMonitoringWrapper();
    vp44FsoFaultDetectionSlowCycle20Coordinator();
    frictionalLoadTorqueManagementSlowCycle40Coordinator();
    _DAT_00800358 = 0xd;
    break;
  case 0xd:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    engine_control_cycle();
    boost_pressure_control_wrapper();
    slowCycle10Coordinator();
    vp44DiagnosticFaultMonitoringSlowCycle20Coordinator();
    engineOperatingModeStateTrackingSlowCycle40Coordinator();
    _DAT_00800358 = 0xe;
    break;
  case 0xe:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    engineDiagnosticSystemCoordinator();
    emptySlowCycle8Placeholder();
    diagnosticMonitoringCoordinator();
    vp44FsoFaultMonitoringSlowCycle20Coordinator();
    fuelDemandProportionalCalculationSlowCycle40Coordinator();
    _DAT_00800358 = 0xf;
    break;
  case 0xf:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    slowCycle4Coordinator();
    emptySlowCycle8PlaceholderCase7();
    epsSignalMonitoringCoordinator();
    emptySlowCycle20PlaceholderCase15();
    epsTimingCalculationSlowCycle40Coordinator();
    vp44InjectionTimingSlowCycle40Coordinator();
    engineProtectionMultiStateSlowCycle40Coordinator();
    _DAT_00800358 = 0x10;
    break;
  case 0x10:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    vp44_engine_management_system();
    empty_debug_hook();
    ioControlSlowCycle10Coordinator();
    dzgTimingAndPressureSlowCycle10Coordinator();
    emptySlowCycle20PlaceholderCase16();
    _DAT_00800358 = 0x11;
    break;
  case 0x11:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    engine_control_cycle();
    engineParameterAndBoostControlWrapper();
    shutdownProtectionSlowCycle10Coordinator();
    engineModeBasedOutputControlSlowCycle20Coordinator();
    _DAT_00800358 = 0x12;
    break;
  case 0x12:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    engineDiagnosticSystemCoordinator();
    auxiliarySystemControlWrapper();
    diagnosticCommunicationSlowCycle10Coordinator();
    vp44DiagnosticControlSlowCycle20Coordinator();
    fuelTemperatureProtectionSlowCycle40Coordinator();
    _DAT_00800358 = 0x13;
    break;
  case 0x13:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    slowCycle4Coordinator();
    slowCycle8Coordinator();
    diagnosticDataTransmissionSlowCycle10Coordinator();
    diagnosticStatisticsSlowCycle20Coordinator();
    _DAT_00800358 = 0x14;
    break;
  case 0x14:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    vp44_engine_management_system();
    boostPressureControlCoordinator();
    rpm_control_system();
    vp44ControlSystemCoordinator();
    _DAT_00800358 = 0x15;
    break;
  case 0x15:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    engine_control_cycle();
    boost_pressure_control_wrapper();
    rpmBasedFuelLimiterCoordinator();
    vp44ExtendedFaultDetectionCoordinator();
    _DAT_00800358 = 0x16;
    break;
  case 0x16:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    engineDiagnosticSystemCoordinator();
    emptySlowCycle8Placeholder();
    secondaryMonitoringWrapper();
    advancedEngineProtectionCoordinator();
    _DAT_00800358 = 0x17;
    break;
  case 0x17:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    slowCycle4Coordinator();
    emptySlowCycle8PlaceholderCase7();
    slowCycle10Coordinator();
    slowCycle20Coordinator();
    _DAT_00800358 = 0x18;
    break;
  case 0x18:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    vp44_engine_management_system();
    empty_debug_hook();
    diagnosticMonitoringCoordinator();
    fuelTimingCoordinator();
    _DAT_00800358 = 0x19;
    break;
  case 0x19:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    engine_control_cycle();
    engineParameterAndBoostControlWrapper();
    epsSignalMonitoringCoordinator();
    slowCycle20ExtendedCoordinator();
    _DAT_00800358 = 0x1a;
    break;
  case 0x1a:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    engineDiagnosticSystemCoordinator();
    auxiliarySystemControlWrapper();
    ioControlSlowCycle10Coordinator();
    fuelCalculationSlowCycle20Coordinator();
    _DAT_00800358 = 0x1b;
    break;
  case 0x1b:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    slowCycle4Coordinator();
    slowCycle8Coordinator();
    shutdownProtectionSlowCycle10Coordinator();
    sensorStatusHistorySlowCycle20Coordinator();
    _DAT_00800358 = 0x1c;
    break;
  case 0x1c:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    vp44_engine_management_system();
    boostPressureControlCoordinator();
    diagnosticCommunicationSlowCycle10Coordinator();
    fuelSmokeLimiterSlowCycle20Coordinator();
    _DAT_00800358 = 0x1d;
    break;
  case 0x1d:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    engine_control_cycle();
    boost_pressure_control_wrapper();
    diagnosticDataTransmissionSlowCycle10Coordinator();
    camSyncDiagnosticProcessingSlowCycle20Coordinator();
    _DAT_00800358 = 0x1e;
    break;
  case 0x1e:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    engineDiagnosticSystemCoordinator();
    emptySlowCycle8Placeholder();
    rpm_control_system();
    derateProtectionSlowCycle20Coordinator();
    _DAT_00800358 = 0x1f;
    break;
  case 0x1f:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    slowCycle4Coordinator();
    emptySlowCycle8PlaceholderCase7();
    rpmBasedFuelLimiterCoordinator();
    vp44ProtectionSlowCycle20Coordinator();
    _DAT_00800358 = 0x20;
    break;
  case 0x20:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    vp44_engine_management_system();
    empty_debug_hook();
    secondaryMonitoringWrapper();
    vp44FsoFaultDetectionSlowCycle20Coordinator();
    _DAT_00800358 = 0x21;
    break;
  case 0x21:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    engine_control_cycle();
    engineParameterAndBoostControlWrapper();
    slowCycle10Coordinator();
    vp44DiagnosticFaultMonitoringSlowCycle20Coordinator();
    _DAT_00800358 = 0x22;
    break;
  case 0x22:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    engineDiagnosticSystemCoordinator();
    auxiliarySystemControlWrapper();
    diagnosticMonitoringCoordinator();
    vp44FsoFaultMonitoringSlowCycle20Coordinator();
    _DAT_00800358 = 0x23;
    break;
  case 0x23:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    slowCycle4Coordinator();
    slowCycle8Coordinator();
    epsSignalMonitoringCoordinator();
    emptySlowCycle20PlaceholderCase15();
    _DAT_00800358 = 0x24;
    break;
  case 0x24:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    vp44_engine_management_system();
    boostPressureControlCoordinator();
    ioControlSlowCycle10Coordinator();
    dzgTimingAndPressureSlowCycle10Coordinator();
    _DAT_00800358 = 0x25;
    break;
  case 0x25:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    engine_control_cycle();
    boost_pressure_control_wrapper();
    shutdownProtectionSlowCycle10Coordinator();
    engineModeBasedOutputControlSlowCycle20Coordinator();
    _DAT_00800358 = 0x26;
    break;
  case 0x26:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    engineDiagnosticSystemCoordinator();
    emptySlowCycle8Placeholder();
    diagnosticCommunicationSlowCycle10Coordinator();
    vp44DiagnosticControlSlowCycle20Coordinator();
    _DAT_00800358 = 0x27;
    break;
  case 0x27:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    slowCycle4Coordinator();
    emptySlowCycle8PlaceholderCase7();
    diagnosticDataTransmissionSlowCycle10Coordinator();
    diagnosticStatisticsSlowCycle20Coordinator();
    _DAT_00800358 = 0;
    break;
  default:
    _DAT_00800358 = 0;
  }
  schedulerPerformanceMonitor();
  DAT_00fffa27 = 0xaa;
  DAT_00ffd00f = 0xaa;
  return CONCAT44(in_D0,in_D1);
}



//
// Function: scheduler_init @ 0x00017b3a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void scheduler_init(void)

{
  _DAT_0080976e = 0;
  _DAT_0080977a = 5;
  _DAT_0080977c = 200;
  _DAT_0080977e = 0x9b7;
  _DAT_00809780 = 500;
  _DAT_00809776 = 0;
  _DAT_00800356 = 0;
  _DAT_00fffa22 = 0x152;
  _DAT_00808f0a = main_loop;
  _DAT_00fffa24 = 0x27;
  return;
}



//
// Function: mainLoopTaskSchedulerInit @ 0x00017b88
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mainLoopTaskSchedulerInit(void)

{
  scheduler_phase_table_t *psVar1;
  
  if (_DAT_0080976e != 0) {
    if (_DAT_00800356 == 0) {
      for (psVar1 = &scheduler_phase_table_t_00809782; psVar1 < (scheduler_phase_table_t *)0x809a02;
          psVar1 = psVar1 + 1) {
        (psVar1->phase_slots).last_execution_time = 0;
        (psVar1->phase_slots).runtime_ticks = 0;
        (psVar1->phase_slots).deadline_ticks = 0xffff;
        (psVar1->phase_slots).execution_count = 0;
        (psVar1->phase_slots).overrun_count = 0;
      }
      _DAT_00809770 = 0;
      _DAT_00809772 = 0;
      _DAT_00800356 = 1;
    }
    _DAT_0080035a = _DAT_00fff404;
    return;
  }
  _DAT_00800356 = 0;
  return;
}



//
// Function: schedulerPerformanceMonitor @ 0x00017bf2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void schedulerPerformanceMonitor(void)

{
  if (_DAT_0080976e != 0) {
    _DAT_00800354 = _DAT_00fff404 - _DAT_0080035a;
    if (*(ushort *)(_DAT_0080035c + 2) < _DAT_00800354) {
      *(ushort *)(_DAT_0080035c + 2) = _DAT_00800354;
    }
    if (_DAT_00800354 < *(ushort *)((int)_DAT_0080035c + 6)) {
      *(ushort *)((int)_DAT_0080035c + 6) = _DAT_00800354;
    }
    *_DAT_0080035c = (uint)_DAT_00800354 + *_DAT_0080035c;
    *(short *)(_DAT_0080035c + 1) = *(short *)(_DAT_0080035c + 1) + 1;
    if ((_DAT_0080977e < _DAT_00800354) &&
       (*(short *)((int)_DAT_0080035c + 10) = *(short *)((int)_DAT_0080035c + 10) + 1,
       _DAT_00809770 != -1)) {
      _DAT_00809770 = _DAT_00809770 + 1;
    }
    _DAT_0080035c = _DAT_0080035c + 4;
  }
  return;
}



//
// Function: schedulerWaitLoop @ 0x00017c6e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void schedulerWaitLoop(void)

{
  while (engine_operating_mode_t_0080c810.shutdown_complete_flag == 0) {
    if (_DAT_0080976e != 0) {
      for (_DAT_00809778 = 0; _DAT_00809778 < _DAT_00809776; _DAT_00809778 = _DAT_00809778 + 1) {
      }
      _DAT_00809772 = _DAT_00809772 + 1;
    }
  }
  return;
}



//
// Function: circularBufferPush @ 0x00017ca6
//

uint circularBufferPush(uint *param_1,undefined4 param_2)

{
  if (*(char *)(param_1 + 4) == '\0') {
    *(undefined1 *)param_1[1] = param_2._1_1_;
    param_1[1] = param_1[1] + 1;
    if (param_1[1] == param_1[3]) {
      param_1[1] = param_1[2];
    }
    if (*param_1 == param_1[1]) {
      *(undefined1 *)(param_1 + 4) = 1;
    }
    return *param_1 & 0xffffff00;
  }
  return 1;
}



//
// Function: circularBufferPop @ 0x00017ce2
//

uint circularBufferPop(uint *param_1,undefined1 *param_2)

{
  uint uVar1;
  
  if ((*param_1 == param_1[1]) && (*(char *)(param_1 + 4) != '\x01')) {
    return 1;
  }
  *param_2 = *(undefined1 *)*param_1;
  *param_1 = *param_1 + 1;
  uVar1 = *param_1;
  if (uVar1 == param_1[3]) {
    *param_1 = param_1[2];
  }
  *(undefined1 *)(param_1 + 4) = 0;
  return uVar1 & 0xffffff00;
}



//
// Function: circularBufferInit @ 0x00017d1a
//

void circularBufferInit(undefined4 *param_1,undefined4 param_2,uint param_3)

{
  param_1[2] = param_2;
  param_1[1] = param_2;
  *param_1 = param_2;
  param_1[3] = param_1[2] + (param_3 >> 0x10);
  *(undefined1 *)(param_1 + 4) = 0;
  return;
}



//
// Function: fuelDemandModeSelector @ 0x00017d40
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort fuelDemandModeSelector(void)

{
  ushort uVar1;
  ushort unaff_D2w;
  
  uVar1 = engine_control_flags_t_008035d6.fuel_demand_control & 0x10;
  if (uVar1 == 0) {
    uVar1 = shutdownMinimumSelectorOrchestrator();
  }
  else {
    _DAT_0080d494 = _DAT_0080379e;
    _DAT_0080d496 = 0xd;
  }
  if (engine_operating_mode_t_0080c810.state == 1) {
    fuel_demand_state_t_0080c9a4.command = 0;
    fuel_demand_state_t_0080c9a4.source_identifier = 0;
    fuel_demand_state_t_0080c9a4.reserved_03 = 0x1a;
  }
  else {
    if (engine_operating_mode_t_0080c810.state == 8) {
      fuel_demand_state_t_0080c9a4.source_identifier = 0;
      fuel_demand_state_t_0080c9a4.reserved_03 = 0x1b;
      fuel_demand_state_t_0080c9a4.command = _DAT_0080849e;
    }
    else if (engine_operating_mode_t_0080c810.state == 5) {
      fuel_demand_state_t_0080c9a4.source_identifier = 0;
      fuel_demand_state_t_0080c9a4.reserved_03 = 0x19;
      fuel_demand_state_t_0080c9a4.command = _DAT_00807f40;
    }
    else {
      uVar1 = engine_control_flags_t_008035d6.fuel_demand_control & 2;
      if (uVar1 == 0) {
        if (engine_operating_mode_t_0080c810.state == 4) {
          fuel_demand_state_t_0080c9a4.source_identifier = 0;
          fuel_demand_state_t_0080c9a4.reserved_03 = 0x18;
          fuel_demand_state_t_0080c9a4.command = _DAT_00807f3e;
        }
        else if ((engine_operating_mode_t_0080c810.state == 2) ||
                (engine_operating_mode_t_0080c810.state == 6)) {
          fuel_demand_state_t_0080c9a4.source_identifier = 0;
          fuel_demand_state_t_0080c9a4.reserved_03 = 0x16;
          fuel_demand_state_t_0080c9a4.command = _DAT_0080c7e8;
        }
        else if (engine_operating_mode_t_0080c810.state == 3) {
          if ((_DAT_00800360 == 2) || (_DAT_00800360 == 6)) {
            uVar1 = governorPidFuelCalculator();
            _DAT_00809652 = _DAT_0080c7e8;
          }
          if (((diagnostic_state_buffer_t_00809654.diagnostic_mode == 0xb) &&
              (_DAT_0080d496 == 0x14)) || (uVar1 = _DAT_00809652, _DAT_00809652 < _DAT_0080d494)) {
            fuel_demand_state_t_0080c9a4.source_identifier =
                 diagnostic_state_buffer_t_00809654.diagnostic_mode._0_1_;
            fuel_demand_state_t_0080c9a4.reserved_03 =
                 (undefined1)diagnostic_state_buffer_t_00809654.diagnostic_mode;
            fuel_demand_state_t_0080c9a4.command = _DAT_00809652;
          }
          else {
            fuel_demand_state_t_0080c9a4.source_identifier = DAT_0080d496;
            fuel_demand_state_t_0080c9a4.reserved_03 = DAT_0080d496_1;
            fuel_demand_state_t_0080c9a4.command = _DAT_0080d494;
          }
        }
        else {
          fuel_demand_state_t_0080c9a4.command = unaff_D2w;
          if (engine_operating_mode_t_0080c810.state == 7) {
            if (((diagnostic_state_buffer_t_00809654.diagnostic_mode == 0xb) &&
                (_DAT_0080d496 == 0x14)) || (uVar1 = _DAT_00809652, _DAT_00809652 < _DAT_0080d494))
            {
              fuel_demand_state_t_0080c9a4.source_identifier =
                   diagnostic_state_buffer_t_00809654.diagnostic_mode._0_1_;
              fuel_demand_state_t_0080c9a4.reserved_03 =
                   (undefined1)diagnostic_state_buffer_t_00809654.diagnostic_mode;
              fuel_demand_state_t_0080c9a4.command = _DAT_00809652;
            }
            else {
              fuel_demand_state_t_0080c9a4.source_identifier = DAT_0080d496;
              fuel_demand_state_t_0080c9a4.reserved_03 = DAT_0080d496_1;
              fuel_demand_state_t_0080c9a4.command = _DAT_0080d494;
            }
            if (fuel_demand_state_t_0080c9a4.command < _DAT_0080c7e8) {
              fuel_demand_state_t_0080c9a4.source_identifier = 0;
              fuel_demand_state_t_0080c9a4.reserved_03 = 0x16;
              fuel_demand_state_t_0080c9a4.command = _DAT_0080c7e8;
            }
          }
        }
      }
      else {
        fuel_demand_state_t_0080c9a4.source_identifier = 0;
        fuel_demand_state_t_0080c9a4.reserved_03 = 0x17;
        fuel_demand_state_t_0080c9a4.command = _DAT_008037a0;
      }
    }
    if (_DAT_00807f3c < fuel_demand_state_t_0080c9a4.command) {
      fuel_demand_state_t_0080c9a4.command = _DAT_00807f3c;
    }
    else if (fuel_demand_state_t_0080c9a4.command < _DAT_0080849e) {
      fuel_demand_state_t_0080c9a4.command = _DAT_0080849e;
    }
  }
  _DAT_00800360 = engine_operating_mode_t_0080c810.state;
  return uVar1;
}



//
// Function: flashEraseWithWatchdog @ 0x00017ed4
//

/* WARNING: Removing unreachable block (ram,0x00018018) */
/* WARNING: Removing unreachable block (ram,0x00018026) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 flashEraseWithWatchdog(void)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  
  DAT_00fffa27 = 0xaa;
  DAT_00ffd00f = 0xaa;
  uVar4 = 0;
  *_DAT_00800362 = 0x2020;
  *_DAT_00800362 = 0xd0d0;
  _calibration_download_size_n_a = 0;
  uVar2 = 0;
  do {
    uVar1 = uVar2 + 1;
    if (40000 < uVar2) {
      _calibration_download_size_n_a = 0xffff;
      return 1;
    }
    if ((DAT_00ffd000 & 1) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = uVar4 + 1;
      if (3 < uVar4) {
        *_DAT_00800362 = 0xb0b0;
        uVar4 = 0;
        while ((uVar2 = uVar4 + 1, uVar4 < 40000 &&
               ((_calibration_download_size_n_a & 0x80) != 0x80))) {
          sVar3 = 0;
          do {
            uVar4 = 0;
            do {
              DAT_00fffa27 = 0xaa;
              DAT_00ffd00f = 0xaa;
              uVar4 = uVar4 + 1;
            } while (uVar4 < 0xa0);
            sVar3 = sVar3 + 1;
            uVar4 = uVar2;
          } while (sVar3 == 0);
        }
        _calibration_download_size_n_a = 0xffff;
        return 2;
      }
    }
    sVar3 = 0;
    do {
      uVar2 = 0;
      do {
        DAT_00fffa27 = 0xaa;
        DAT_00ffd00f = 0xaa;
        uVar2 = uVar2 + 1;
      } while (uVar2 < 0xa0);
      sVar3 = sVar3 + 1;
      uVar2 = uVar1;
    } while (sVar3 == 0);
  } while( true );
}



//
// Function: flashEraseFromRam @ 0x0001802e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void flashEraseFromRam(undefined4 param_1)

{
  undefined2 *puVar1;
  code *pcVar2;
  undefined1 auStack_804 [2048];
  
  _DAT_00800362 = param_1;
  puVar1 = (undefined2 *)auStack_804;
  for (pcVar2 = flashEraseWithWatchdog; pcVar2 < flashEraseFromRam; pcVar2 = pcVar2 + 2) {
    *puVar1 = *(undefined2 *)pcVar2;
    puVar1 = puVar1 + 1;
  }
  (*(code *)auStack_804)();
  return;
}



//
// Function: flashProgramWordWithWatchdog @ 0x0001805c
//

/* WARNING: Removing unreachable block (ram,0x00018104) */
/* WARNING: Removing unreachable block (ram,0x0001810e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 flashProgramWordWithWatchdog(void)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = 0;
  while( true ) {
    DAT_00fffa27 = 0xaa;
    DAT_00ffd00f = 0xaa;
    if (_DAT_0080036a <= _DAT_00800362) {
      if ((_calibration_download_size_n_a & 0x10) != 0x10) {
        return 1;
      }
      return 0;
    }
    *_DAT_00800362 = 0x4040;
    *_DAT_00800362 = *_DAT_00800366;
    uVar2 = 0;
    while (uVar2 < 5000) {
      DAT_00fffa27 = 0xaa;
      DAT_00ffd00f = 0xaa;
      uVar2 = uVar2 + 1;
    }
    _calibration_download_size_n_a = 0xffff;
    if (4 < uVar1) break;
    uVar1 = uVar1 + 1;
  }
  return 0;
}



//
// Function: flashProgramFromRam @ 0x00018174
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void flashProgramFromRam(int param_1,undefined4 param_2,uint param_3)

{
  undefined2 *puVar1;
  code *pcVar2;
  undefined1 auStack_804 [2048];
  
  _DAT_00800366 = param_2;
  _DAT_00800362 = param_1;
  _DAT_0080036a = param_1 + (param_3 >> 0x10);
  puVar1 = (undefined2 *)auStack_804;
  for (pcVar2 = flashProgramWordWithWatchdog; pcVar2 < flashProgramFromRam; pcVar2 = pcVar2 + 2) {
    *puVar1 = *(undefined2 *)pcVar2;
    puVar1 = puVar1 + 1;
  }
  (*(code *)auStack_804)();
  return;
}



//
// Function: diagnosticStatusDefaultSetter @ 0x000181bc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticStatusDefaultSetter(void)

{
  if (_DAT_0080d49c == 0) {
    _DAT_0080d49c = 8;
  }
  return;
}



//
// Function: diagnostic_parameter_handler @ 0x000181cc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnostic_parameter_handler(void)

{
  if (_DAT_0080d49c == 8) {
    fuel_demand_state_t_0080c9a4.diagnostic_buffer = activeParamReadFunction();
    _DAT_0080d49a = fuel_demand_state_t_0080c9a4.diagnostic_buffer;
  }
  return;
}



//
// Function: fuelDemandTableBlendCalculator @ 0x000181ea
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelDemandTableBlendCalculator(void)

{
  word wVar1;
  word extraout_D0w;
  word extraout_D0w_00;
  ushort extraout_D0w_01;
  ushort extraout_D0w_02;
  
  if ((engine_control_flags_t_008035d6.reserved_06 & 0x100) == 0) {
    wVar1 = fuel_demand_state_t_0080c9a4.command;
    if (_DAT_0080ccf2 == 1) {
      _DAT_00800374 = fuel_demand_state_t_0080c9a4.command;
      wVar1 = lookupTableInterpolation((short *)&DAT_0080036e);
    }
    if (timing_mode_control_t_0080965a.blend_factor == 0x4000) {
      _DAT_00800380 = circular_buffer_t_0080c3fc.data_buffer_8;
      _DAT_00800388 = wVar1;
      tableInterpolationLookup((short *)&DAT_0080037a);
      fuel_demand_state_t_0080c9a4.table_output = extraout_D0w;
    }
    else if (timing_mode_control_t_0080965a.blend_factor == 0) {
      _DAT_00800394 = circular_buffer_t_0080c3fc.data_buffer_8;
      _DAT_0080039c = wVar1;
      tableInterpolationLookup((short *)&DAT_0080038e);
      fuel_demand_state_t_0080c9a4.table_output = extraout_D0w_00;
    }
    else {
      _DAT_00800380 = circular_buffer_t_0080c3fc.data_buffer_8;
      _DAT_00800388 = wVar1;
      tableInterpolationLookup((short *)&DAT_0080037a);
      _DAT_00800394 = circular_buffer_t_0080c3fc.data_buffer_8;
      _DAT_0080039c = wVar1;
      tableInterpolationLookup((short *)&DAT_0080038e);
      fuel_demand_state_t_0080c9a4.table_output =
           (short)((uint)timing_mode_control_t_0080965a.blend_factor * (uint)extraout_D0w_01 >> 0xe)
           + (short)((uint)extraout_D0w_02 *
                     (0x4000 - (uint)timing_mode_control_t_0080965a.blend_factor) >> 0xe);
    }
    fuel_demand_state_t_0080c9a4.demand_source_id = 0;
  }
  else {
    fuel_demand_state_t_0080c9a4.table_output = _DAT_008037b2;
    fuel_demand_state_t_0080c9a4.demand_source_id = 2;
  }
  if ((engine_control_flags_t_008035d6.protection_system & 0x4000) != 0) {
    fuel_demand_state_t_0080c9a4.table_output =
         _DAT_008037b0 + fuel_demand_state_t_0080c9a4.table_output;
    fuel_demand_state_t_0080c9a4.adjustment_active = 1;
  }
  fuel_demand_state_t_0080c9a4.limit_minimum = fuel_demand_state_t_0080c9a4.table_output;
  FUN_0002f778();
  return;
}



//
// Function: initFuelDemandCalculationSystem @ 0x0001832a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initFuelDemandCalculationSystem(void)

{
  _DAT_00800370 = 0x807c9a;
  _DAT_00800376 = &CCRFRTNG;
  _DAT_0080036e = 2;
  _DAT_0080037c = 0x8080c2;
  _DAT_0080037a = 2;
  _DAT_00800384 = 0x8080e8;
  _DAT_00800382 = 2;
  _DAT_0080038a = 0x808100;
  _DAT_00800390 = 0x80828c;
  _DAT_0080038e = 2;
  _DAT_00800398 = 0x8082b2;
  _DAT_00800396 = 2;
  _DAT_0080039e = 0x8082ca;
  return;
}



//
// Function: fuelDemandProportionalCalculationSlowCycle40Coordinator @ 0x000183a6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelDemandProportionalCalculationSlowCycle40Coordinator(void)

{
  uint uVar1;
  
  if (fuel_demand_state_t_0080c9a4.command < _DAT_0080845a) {
    _DAT_0080c9cc = 0;
    return;
  }
  uVar1 = proportionalCalculation
                    ((uint)circular_buffer_t_0080c3fc.data_buffer_8 * 0x280,
                     (uint)fuel_demand_state_t_0080c9a4.command - (uint)_DAT_0080845a,
                     (uint)_DAT_0080845c * 0x1d7);
  if (31999 < uVar1) {
    _DAT_0080c9cc = 32000;
    return;
  }
  _DAT_0080c9cc = (short)uVar1;
  return;
}



//
// Function: emptySlowCycle20PlaceholderCase16 @ 0x00018428
//

void emptySlowCycle20PlaceholderCase16(void)

{
  return;
}



//
// Function: emptyInit2 @ 0x0001842a
//

void emptyInit2(void)

{
  return;
}



//
// Function: canPinVp44StatusController @ 0x0001842c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort canPinVp44StatusController(void)

{
  ushort uVar1;
  
  uVar1 = DAT_0080bdc6 & 1;
  if (((((DAT_0080bdc6 & 1) != 0) && (_DAT_0080c9c6 == 0)) &&
      ((_DAT_0080969e == 0 || (uVar1 = _DAT_008035d4 & 0x40, (_DAT_008035d4 & 0x40) == 0)))) &&
     (((engine_operating_mode_t_0080c810.state == 5 &&
       (uVar1 = _DAT_008035ec & 2, (_DAT_008035ec & 2) == 0)) ||
      (engine_operating_mode_t_0080c810.state != 5)))) {
    DAT_0080bdf3 = DAT_0080bdf3 | 0x20;
    return uVar1;
  }
  DAT_0080bdf3 = DAT_0080bdf3 & 0xdf;
  return uVar1;
}



//
// Function: fuel_timing_calculation_with_fault_checking @ 0x0001848e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuel_timing_calculation_with_fault_checking(void)

{
  word wVar1;
  short sVar2;
  ushort unaff_D3w;
  ushort unaff_D4w;
  undefined8 uVar3;
  
  wVar1 = fuel_demand_state_t_0080c9a4.timing_blend_factor;
  if (fuel_demand_state_t_0080c9a4.timing_blend_factor != 0) {
    _DAT_008003b6 = circular_buffer_t_0080c3fc.data_buffer_8;
    uVar3 = tableInterpolationLookup((short *)&DAT_008003b0);
    unaff_D4w = (ushort)((ulonglong)uVar3 >> 0x20);
  }
  if (wVar1 < 0x4000) {
    _DAT_008003ca = circular_buffer_t_0080c3fc.data_buffer_8;
    uVar3 = tableInterpolationLookup((short *)&DAT_008003c4);
    unaff_D3w = (ushort)((ulonglong)uVar3 >> 0x20);
  }
  _DAT_0080c9d8 = unaff_D4w;
  if ((wVar1 != 0x4000) && (_DAT_0080c9d8 = unaff_D3w, wVar1 != 0)) {
    _DAT_0080c9d8 = unaff_D3w + (short)((uint)wVar1 * ((uint)unaff_D4w - (uint)unaff_D3w) >> 0xe);
  }
  if (((((_DAT_00803614 & 0x8000) == 0) ||
       (((fault_status_registers_t_00805df2.engine_fault_status & 2) != 0 &&
        ((_DAT_008068c8 & 2) != 0)))) ||
      (((fault_status_registers_t_00805df2.engine_fault_status & 1) != 0 &&
       ((_DAT_008068c8 & 1) != 0)))) ||
     (((fault_status_registers_t_00805df2.engine_fault_status & 0x10) != 0 &&
      ((_DAT_008068c8 & 0x10) != 0)))) {
    sVar2 = 0;
  }
  else {
    _DAT_008003aa = _DAT_0080926e;
    sVar2 = lookupTableInterpolation((short *)&DAT_008003a4);
  }
  _DAT_0080c9d8 = sVar2 + _DAT_0080c9d8;
  if (_DAT_0080c9d8 < _DAT_0080849e) {
    _DAT_0080c9d8 = _DAT_0080849e;
  }
  return;
}



//
// Function: fuelLimitParameterPointerSetup @ 0x00018590
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelLimitParameterPointerSetup(void)

{
  _DAT_008003b2 = 0x807f42;
  _DAT_008003b0 = 2;
  _DAT_008003be = 400;
  _DAT_008003ba = 0x807f68;
  _DAT_008003b8 = 2;
  _DAT_008003c0 = 0x807f72;
  _DAT_008003c6 = 0x808002;
  _DAT_008003c4 = 2;
  _DAT_008003d2 = 400;
  _DAT_008003ce = 0x808028;
  _DAT_008003cc = 2;
  _DAT_008003d4 = 0x808032;
  _DAT_008003aa = _DAT_0080926e;
  _DAT_008003a6 = 0x808862;
  _DAT_008003ac = 0x808876;
  _DAT_008003a4 = 2;
  return;
}



//
// Function: shutdownMinimumSelector19 @ 0x00018620
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void shutdownMinimumSelector19(void)

{
  if (_DAT_0080c9d8 < _DAT_0080d494) {
    _DAT_0080d494 = _DAT_0080c9d8;
    _DAT_0080d496 = 0x13;
  }
  return;
}



//
// Function: fuel_delivery_controller @ 0x0001863e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuel_delivery_controller(void)

{
  short sVar1;
  int iVar2;
  
  sVar1 = _DAT_0080cc3c;
  if (diagnostic_state_buffer_t_00809654.diagnostic_mode == 0xc) {
    if (((int)((int)_DAT_00808472 + (uint)fuel_limit_arbitration_t_0080cc4a.demand_limited) <
         (int)(uint)circular_buffer_t_0080c3fc.data_buffer_8) && (_DAT_00809652 < _DAT_00808474)) {
      _DAT_008003e0 = (uint)_DAT_00808470 << 0x10;
      _DAT_0080cc3c = 0;
      _DAT_008003dc = -0x80000000;
    }
    else {
      _DAT_0080cc3c = exponentialMovingAverage();
      if (_DAT_00808468 < _DAT_0080cc3c) {
        _DAT_0080cc3c = _DAT_00808468;
        _DAT_008003dc = _DAT_00808468 * 0x10000 + -0x80000000;
      }
      else if (_DAT_0080cc3c < _DAT_0080846a) {
        _DAT_0080cc3c = _DAT_0080846a;
        _DAT_008003dc = _DAT_0080846a * 0x10000 + -0x80000000;
      }
      _DAT_0080cc3e = (short)(((int)_DAT_0080cc3c * (int)_DAT_0080cc44) / 0x3c0);
      if ((int)_DAT_0080cc48 * ((int)_DAT_0080cc3c - (int)sVar1) < 0x77ff10) {
        iVar2 = ((int)_DAT_0080cc3c - (int)sVar1) * (int)_DAT_0080cc48;
        if (iVar2 < -0x77ffff) {
          _DAT_0080cc40 = -0x8000;
        }
        else {
          _DAT_0080cc40 = (short)(iVar2 / 0xf0);
        }
      }
      else {
        _DAT_0080cc40 = 0x7fff;
      }
      iVar2 = (int)_DAT_0080cc3c * (int)(short)(_DAT_0080cc46 << 2) + _DAT_008003e0;
      _DAT_008003e0 = (short)((uint)iVar2 >> 0x10);
      _DAT_008003e0 = _DAT_008003e0 - _DAT_0080c9c4;
      _DAT_008003e2 = (undefined2)iVar2;
      if (_DAT_008003e0 < (short)_DAT_0080846c) {
        if (_DAT_008003e0 < (short)_DAT_0080846e) {
          _DAT_008003e0 = (uint)_DAT_0080846e << 0x10;
        }
      }
      else {
        _DAT_008003e0 = (uint)_DAT_0080846c << 0x10;
      }
      _DAT_0080cc42 = _DAT_008003e0;
      iVar2 = (int)_DAT_008003e0 + (int)_DAT_0080cc40 + (int)_DAT_0080cc3e;
      if ((int)(uint)_DAT_0080847a < iVar2) {
        _DAT_0080cc3a = _DAT_0080847a;
      }
      else if (iVar2 < (int)(uint)_DAT_0080847c) {
        _DAT_0080cc3a = _DAT_0080847c;
      }
      else {
        _DAT_0080cc3a = (ushort)iVar2;
      }
      _DAT_00809652 = _DAT_0080cc3a;
    }
  }
  return;
}



//
// Function: fuelRpmDeviationCalculator @ 0x0001883a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelRpmDeviationCalculator(void)

{
  _DAT_0080cc3c =
       (short)((int)((int)_DAT_00808466 *
                    ((uint)fuel_limit_arbitration_t_0080cc4a.demand_limited -
                    (uint)circular_buffer_t_0080c3fc.data_buffer_8)) >> 9);
  if (_DAT_00808468 < _DAT_0080cc3c) {
    _DAT_0080cc3c = _DAT_00808468;
  }
  else if (_DAT_0080cc3c < _DAT_0080846a) {
    _DAT_0080cc3c = _DAT_0080846a;
  }
  _DAT_008003dc = _DAT_0080cc3c * 0x10000 + -0x80000000;
  _DAT_008003e0 =
       fuel_demand_state_t_0080c9a4.command -
       (short)(((int)_DAT_0080cc3c * (int)_DAT_0080cc44) / 0x3c0);
  if (_DAT_00808478 < _DAT_008003e0) {
    _DAT_008003e0 = _DAT_00808478;
  }
  else if (_DAT_008003e0 < _DAT_00808476) {
    _DAT_008003e0 = _DAT_00808476;
  }
  _DAT_008003e2 = 0;
  if (_DAT_0080847e != 0) {
    fuel_delivery_controller();
  }
  return;
}



//
// Function: fuelDeliverySystemInit @ 0x000188f6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelDeliverySystemInit(void)

{
  _DAT_0080cc44 = _DAT_0080845e;
  _DAT_0080cc46 = _DAT_00808462;
  _DAT_0080cc48 = _DAT_00808460;
  _DAT_008003dc = 0x80000000;
  _DAT_008003d8 = 0x808464;
  return;
}



//
// Function: fuel_limit_arbitrator @ 0x0001892a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuel_limit_arbitrator(void)

{
  uint uVar1;
  ushort uVar2;
  
  if (fuel_arbitrator_diag_t_0080cff8.speed_limit == 1) {
    fuel_limit_arbitration_t_0080cc4a.demand_limited = _DAT_0080875c;
    fuel_limit_arbitration_t_0080cc4a.source_id = 8;
    _DAT_0080cc5c = 0;
    return;
  }
  fuel_limit_arbitration_t_0080cc4a.offset_value = *_DAT_0080cc5e;
  fuel_limit_arbitration_t_0080cc4a.comparison_low = *_DAT_0080cc62;
  fuel_limit_arbitration_t_0080cc4a.comparison_high = *_DAT_0080cc66;
  if (fuel_limit_arbitration_t_0080cc4a.offset_value < _DAT_0080c992) {
    fuel_limit_arbitration_t_0080cc4a.source_id = 6;
    fuel_limit_arbitration_t_0080cc4a.arbitration_threshold =
         fuel_limit_arbitration_t_0080cc4a.offset_value;
  }
  else {
    fuel_limit_arbitration_t_0080cc4a.arbitration_threshold = _DAT_0080c992;
    fuel_limit_arbitration_t_0080cc4a.source_id = 5;
  }
  if ((fuel_arbitrator_diag_t_0080cff8.rpm_target == 3) &&
     (fuel_arbitrator_diag_t_0080cff8.command_counter <=
      fuel_limit_arbitration_t_0080cc4a.arbitration_threshold)) {
    fuel_limit_arbitration_t_0080cc4a.arbitration_threshold =
         fuel_arbitrator_diag_t_0080cff8.command_counter;
    fuel_limit_arbitration_t_0080cc4a.source_id = 9;
  }
  if (_DAT_008096ae <= fuel_limit_arbitration_t_0080cc4a.arbitration_threshold) {
    fuel_limit_arbitration_t_0080cc4a.arbitration_threshold = _DAT_008096ae;
    fuel_limit_arbitration_t_0080cc4a.source_id = 4;
  }
  if (rpm_fuel_protection_t_008091c4.low_rpm_fuel_protection_limit <=
      fuel_limit_arbitration_t_0080cc4a.arbitration_threshold) {
    fuel_limit_arbitration_t_0080cc4a.arbitration_threshold =
         rpm_fuel_protection_t_008091c4.low_rpm_fuel_protection_limit;
    fuel_limit_arbitration_t_0080cc4a.source_id = 3;
  }
  if (_DAT_008096ac <= fuel_limit_arbitration_t_0080cc4a.arbitration_threshold) {
    fuel_limit_arbitration_t_0080cc4a.arbitration_threshold = _DAT_008096ac;
    fuel_limit_arbitration_t_0080cc4a.source_id = 2;
  }
  if (_DAT_0080ccf6 <= fuel_limit_arbitration_t_0080cc4a.arbitration_threshold) {
    fuel_limit_arbitration_t_0080cc4a.arbitration_threshold = _DAT_0080ccf6;
    fuel_limit_arbitration_t_0080cc4a.source_id = 1;
  }
  if (fuel_limit_arbitration_t_0080cc4a.maximum_limit <=
      fuel_limit_arbitration_t_0080cc4a.arbitration_threshold) {
    fuel_limit_arbitration_t_0080cc4a.arbitration_threshold =
         fuel_limit_arbitration_t_0080cc4a.maximum_limit;
    fuel_limit_arbitration_t_0080cc4a.source_id = 7;
  }
  if (_DAT_0080d17e <= fuel_limit_arbitration_t_0080cc4a.arbitration_threshold) {
    fuel_limit_arbitration_t_0080cc4a.arbitration_threshold = _DAT_0080d17e;
    fuel_limit_arbitration_t_0080cc4a.source_id = 0xb;
  }
  if (_DAT_0080848c < fuel_limit_arbitration_t_0080cc4a.arbitration_threshold) {
    fuel_limit_arbitration_t_0080cc4a.arbitration_threshold = _DAT_0080848c;
  }
  if (fuel_limit_arbitration_t_0080cc4a.source_id == 9) {
    if ((uint)fuel_limit_arbitration_t_0080cc4a.arbitration_threshold <
        (uint)_DAT_00806e1a + (uint)_DAT_0080d092) {
      fuel_limit_arbitration_t_0080cc4a.arbitration_threshold = _DAT_00806e1a + _DAT_0080d092;
    }
  }
  else if (fuel_limit_arbitration_t_0080cc4a.arbitration_threshold < _DAT_0080848a) {
    fuel_limit_arbitration_t_0080cc4a.arbitration_threshold = _DAT_0080848a;
  }
  if (fuel_limit_arbitration_t_0080cc4a.rate_limit <
      fuel_limit_arbitration_t_0080cc4a.arbitration_threshold) {
    fuel_limit_arbitration_t_0080cc4a.rate_limit =
         _DAT_00808480 + fuel_limit_arbitration_t_0080cc4a.rate_limit;
  }
  if (fuel_limit_arbitration_t_0080cc4a.arbitration_threshold <
      fuel_limit_arbitration_t_0080cc4a.rate_limit) {
    fuel_limit_arbitration_t_0080cc4a.rate_limit =
         fuel_limit_arbitration_t_0080cc4a.arbitration_threshold;
  }
  if (((fuel_limit_arbitration_t_0080cc4a.comparison_high != 0) &&
      (fuel_limit_arbitration_t_0080cc4a.comparison_low != 0)) &&
     ((fuel_limit_arbitration_t_0080cc4a.source_id != 9 ||
      (fuel_arbitrator_diag_t_0080cff8._28_2_ != 1)))) {
    _DAT_0080cc5c = 1;
    uVar2 = _DAT_00808486;
    if ((_DAT_00809652 <= _DAT_00808486) && (uVar2 = _DAT_00809652, _DAT_00809652 < _DAT_00808488))
    {
      uVar2 = _DAT_00808488;
    }
    uVar1 = ((uint)fuel_limit_arbitration_t_0080cc4a.comparison_high *
            ((uint)fuel_limit_arbitration_t_0080cc4a.comparison_low - (uint)uVar2)) / 0x1111;
    if ((int)(uVar1 & 0xffff) <
        (int)((uint)fuel_limit_arbitration_t_0080cc4a.offset_value -
             (uint)fuel_limit_arbitration_t_0080cc4a.rate_limit)) {
      fuel_limit_arbitration_t_0080cc4a.demand_delta = 0;
    }
    else {
      fuel_limit_arbitration_t_0080cc4a.demand_delta =
           (short)uVar1 -
           (short)((uint)fuel_limit_arbitration_t_0080cc4a.offset_value -
                  (uint)fuel_limit_arbitration_t_0080cc4a.rate_limit);
    }
    if (fuel_limit_arbitration_t_0080cc4a.demand_delta <=
        fuel_limit_arbitration_t_0080cc4a.rate_limit) {
      fuel_limit_arbitration_t_0080cc4a.demand_limited =
           fuel_limit_arbitration_t_0080cc4a.rate_limit;
      return;
    }
    fuel_limit_arbitration_t_0080cc4a.demand_limited =
         fuel_limit_arbitration_t_0080cc4a.demand_delta;
    return;
  }
  fuel_limit_arbitration_t_0080cc4a.demand_limited = fuel_limit_arbitration_t_0080cc4a.rate_limit;
  _DAT_0080cc5c = 0;
  return;
}



//
// Function: fuelArbitratorInit @ 0x00018b6e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelArbitratorInit(void)

{
  _DAT_0080cc5e = &DAT_0080369a;
  _DAT_0080cc66 = 0x8036d8;
  _DAT_0080cc62 = 0x8036da;
  fuel_limit_arbitration_t_0080cc4a.rate_limit = _DAT_0080369a;
  fuel_limit_arbitration_t_0080cc4a.source_id = 6;
  fuel_limit_arbitration_t_0080cc4a.arbitration_threshold = _DAT_008037b4;
  fuel_limit_arbitration_t_0080cc4a.maximum_limit = _DAT_008037b4;
  _DAT_008096ae = _DAT_008037b4;
  return;
}



//
// Function: derateChangeDetector @ 0x00018bbe
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void derateChangeDetector(void)

{
  ushort uVar1;
  
  uVar1 = (byte)-((DAT_0080bdc7 & 8) != 0) & 1;
  _DAT_008003ea = (ushort)(uVar1 != _DAT_008003e8);
  _DAT_008003e8 = uVar1;
  uVar1 = (byte)-((DAT_0080bdc7 & 4) != 0) & 1;
  _DAT_008003e6 = (ushort)(uVar1 != _DAT_008003e4);
  _DAT_008003e4 = uVar1;
  if (_DAT_00809d4c < _DAT_008003ec) {
    uVar1 = _DAT_008003ec - _DAT_00809d4c;
  }
  else {
    uVar1 = _DAT_00809d4c - _DAT_008003ec;
  }
  if (_DAT_00808492 < uVar1) {
    _DAT_008003ec = _DAT_00809d4c;
    _DAT_008003ee = 1;
    return;
  }
  _DAT_008003ee = 0;
  return;
}



//
// Function: highRpmEngineProtectionStateMachine @ 0x00018c62
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort highRpmEngineProtectionStateMachine(void)

{
  ushort uVar1;
  
  uVar1 = engine_control_flags_t_008035d6.engine_operating_state & 2;
  if ((engine_control_flags_t_008035d6.engine_operating_state & 2) != 0) {
    uVar1 = derateChangeDetector();
    if (high_rpm_protection_t_0080cc6a.state == 0) {
      high_rpm_protection_t_0080cc6a.timer = _DAT_008036fc;
      high_rpm_protection_t_0080cc6a.warning_flag = 0;
      high_rpm_protection_t_0080cc6a.fault_flag = 0;
      _DAT_008003ec = _DAT_00809d4c;
      if (_DAT_00808494 == 0) {
        DAT_0080bdf1 = DAT_0080bdf1 | 1;
      }
      else {
        DAT_0080bdf1 = DAT_0080bdf1 & 0xfe;
      }
      if (((_DAT_0080d17a == 0) ||
          (uVar1 = engine_control_flags_t_008035d6.protection_system & 8,
          (engine_control_flags_t_008035d6.protection_system & 8) != 0)) &&
         ((_DAT_008096a6 == 0 &&
          ((engine_operating_mode_t_0080c810.state == 3 &&
           (uVar1 = _DAT_0080926e, _DAT_00808490 < _DAT_0080926e)))))) {
        if (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x100) == 0) ||
           ((_DAT_008068cc & 0x100) == 0)) {
          uVar1 = 0;
        }
        else {
          uVar1 = 1;
        }
        if ((((uVar1 == 0) && (_DAT_008003e6 == 0)) && (_DAT_008003ea == 0)) && (_DAT_008003ee == 0)
           ) {
          high_rpm_protection_t_0080cc6a.state = 1;
          return 0;
        }
      }
    }
    else if (high_rpm_protection_t_0080cc6a.state == 1) {
      high_rpm_protection_t_0080cc6a.timer = high_rpm_protection_t_0080cc6a.timer - 1;
      if ((((_DAT_0080d17a != 0) && ((engine_control_flags_t_008035d6.protection_system & 8) == 0))
          || (engine_operating_mode_t_0080c810.state != 3)) ||
         (((_DAT_0080926e <= _DAT_00808490 || (_DAT_008003e6 != 0)) ||
          ((_DAT_008003ea != 0 || (_DAT_008003ee != 0)))))) {
        high_rpm_protection_t_0080cc6a.state = 0;
      }
      uVar1 = high_rpm_protection_t_0080cc6a.timer;
      if (high_rpm_protection_t_0080cc6a.timer <= _DAT_00808496) {
        high_rpm_protection_t_0080cc6a.state = 2;
        high_rpm_protection_t_0080cc6a.warning_flag = 1;
        return high_rpm_protection_t_0080cc6a.timer;
      }
    }
    else if (high_rpm_protection_t_0080cc6a.state == 2) {
      high_rpm_protection_t_0080cc6a.timer = high_rpm_protection_t_0080cc6a.timer - 1;
      uVar1 = engine_control_flags_t_008035d6.engine_operating_state & 4;
      if ((engine_control_flags_t_008035d6.engine_operating_state & 4) == 0) {
        if ((((_DAT_0080d17a != 0) &&
             (uVar1 = engine_control_flags_t_008035d6.protection_system & 8,
             (engine_control_flags_t_008035d6.protection_system & 8) == 0)) || (_DAT_008096a6 != 0))
           || (((engine_operating_mode_t_0080c810.state != 3 || (_DAT_008003e6 != 0)) ||
               ((_DAT_008003ea != 0 || (_DAT_008003ee != 0)))))) {
          high_rpm_protection_t_0080cc6a.state = 0;
        }
      }
      else {
        uVar1 = _DAT_008003ea | _DAT_008003e6;
        if ((uVar1 != 0) || (_DAT_008003ee != 0)) {
          high_rpm_protection_t_0080cc6a.state = 3;
          high_rpm_protection_t_0080cc6a.warning_flag = 0;
          high_rpm_protection_t_0080cc6a.fault_flag = 1;
        }
      }
      if (high_rpm_protection_t_0080cc6a.timer == 0) {
        high_rpm_protection_t_0080cc6a.state = 4;
        high_rpm_protection_t_0080cc6a.warning_flag = 0;
        _DAT_0080c996 = 1;
        if (_DAT_00808494 != 0) {
          DAT_0080bdf1 = DAT_0080bdf1 | 1;
          return uVar1;
        }
        DAT_0080bdf1 = DAT_0080bdf1 & 0xfe;
        return uVar1;
      }
    }
    else if (high_rpm_protection_t_0080cc6a.state == 3) {
      if ((_DAT_008096a6 != 0) || (engine_operating_mode_t_0080c810.state == 1)) {
        high_rpm_protection_t_0080cc6a.state = 0;
        return uVar1;
      }
    }
    else if ((high_rpm_protection_t_0080cc6a.state == 4) &&
            (engine_operating_mode_t_0080c810.state == 1)) {
      high_rpm_protection_t_0080cc6a.state = 0;
    }
  }
  return uVar1;
}



//
// Function: initFuelArbitratorThreshold3 @ 0x00018e9c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initFuelArbitratorThreshold3(void)

{
  high_rpm_protection_t_0080cc6a.timer = _DAT_008036fc;
  high_rpm_protection_t_0080cc6a.state = 0;
  _DAT_0080c996 = 0;
  return;
}



//
// Function: vp44ControlStructureInit @ 0x00018eb4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44ControlStructureInit(void)

{
  timing_mode_control_t_0080965a.blend_accumulator = 0;
  timing_mode_control_t_0080965a.reserved_1A = 0;
  timing_mode_control_t_0080965a.reserved_14 = 0x80;
  timing_mode_control_t_0080965a.reserved_16 = 0x6fb0;
  timing_mode_control_t_0080965a.protection_blend_ramp = 0;
  timing_mode_control_t_0080965a.fuel_source_mode_11_state = 0;
  timing_mode_control_t_0080965a.fuel_mode_transition_state = 0;
  _DAT_0080967e = 0;
  timing_mode_control_t_0080965a.protection_counter_2 = 0;
  return;
}



//
// Function: diagnosticBufferPointerInit @ 0x00018ee4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticBufferPointerInit(void)

{
  _DAT_0080d2bc = &DAT_00808b00;
  _DAT_0080d2b4 = &DAT_00808b00;
  _DAT_0080d2b8 = 0x808b01;
  DAT_00808b00 = 0;
  CMSNCUER = 0;
  _DAT_0080d3e6 = &DAT_00808b00;
  _DAT_0080d2c6 = 0x808c01;
  DAT_00808c00 = 0;
  DAT_0080d2ce = 0;
  _DAT_0080d3ea = &DAT_00808c00;
  _DAT_0080d3ee = 0x808cff;
  _DAT_0080d2c2 = &DAT_00808c00;
  _DAT_0080d2ca = &DAT_00808c00;
  return;
}



//
// Function: initFuelArbitratorThreshold5 @ 0x00018f6c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initFuelArbitratorThreshold5(void)

{
  _DAT_0080ccf6 = _DAT_008037b4;
  _DAT_0080d4cc = _DAT_008037b4;
  return;
}



//
// Function: activeParamReadFunction @ 0x00018f82
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short activeParamReadFunction(void)

{
  word wVar1;
  ushort extraout_D0w;
  ushort extraout_D0w_00;
  ushort extraout_D0w_01;
  ushort extraout_D0w_02;
  ushort extraout_D0w_03;
  ushort extraout_D0w_04;
  ushort unaff_D2w;
  ushort uVar2;
  ushort unaff_D3w;
  
  wVar1 = fuel_demand_state_t_0080c9a4.timing_blend_factor;
  if (_DAT_00809d4c != 0) {
    if (fuel_demand_state_t_0080c9a4.timing_blend_factor != 0) {
      _DAT_008003f6 = circular_buffer_t_0080c3fc.data_buffer_8;
      _DAT_008003fe = _DAT_00809d4c;
      tableInterpolationLookup((short *)&DAT_008003f0);
      unaff_D3w = extraout_D0w;
      if ((_DAT_00809d4c != 0) && (_DAT_00809d4c != 400)) {
        _DAT_008003fe = 0;
        tableInterpolationLookup((short *)&DAT_008003f0);
        _DAT_008003fe = 400;
        tableInterpolationLookup((short *)&DAT_008003f0);
        if (extraout_D0w < extraout_D0w_00) {
          unaff_D3w = extraout_D0w_00;
        }
        if (extraout_D0w_01 < unaff_D3w) {
          unaff_D3w = extraout_D0w_01;
        }
      }
    }
    if (wVar1 < 0x4000) {
      _DAT_0080040a = circular_buffer_t_0080c3fc.data_buffer_8;
      _DAT_00800412 = _DAT_00809d4c;
      tableInterpolationLookup((short *)&DAT_00800404);
      unaff_D2w = extraout_D0w_02;
      if ((_DAT_00809d4c != 0) && (_DAT_00809d4c != 400)) {
        _DAT_00800412 = 0;
        tableInterpolationLookup((short *)&DAT_00800404);
        _DAT_00800412 = 400;
        tableInterpolationLookup((short *)&DAT_00800404);
        if (extraout_D0w_02 < extraout_D0w_03) {
          unaff_D2w = extraout_D0w_03;
        }
        if (extraout_D0w_04 < unaff_D2w) {
          unaff_D2w = extraout_D0w_04;
        }
      }
    }
    uVar2 = unaff_D2w;
    if ((wVar1 != 0) && (uVar2 = unaff_D3w, wVar1 != 0x4000)) {
      uVar2 = unaff_D2w + (short)((uint)wVar1 * ((uint)unaff_D3w - (uint)unaff_D2w) >> 0xe);
    }
    return _DAT_008037ae + uVar2;
  }
  return _DAT_0080849e;
}



//
// Function: fuelTimingModeInit @ 0x00019076
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelTimingModeInit(void)

{
  _DAT_008003f2 = 0x807f42;
  _DAT_008003f0 = 2;
  _DAT_008003fa = 0x807f68;
  _DAT_008003f8 = 2;
  _DAT_00800400 = 0x807f72;
  _DAT_00800406 = 0x808002;
  _DAT_00800404 = 2;
  _DAT_0080040e = 0x808028;
  _DAT_0080040c = 2;
  _DAT_00800414 = 0x808032;
  fuel_demand_state_t_0080c9a4.timing_blend_factor = 0x4000;
  return;
}



//
// Function: serialNodeAddressChecker @ 0x000190d8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void serialNodeAddressChecker(undefined4 param_1)

{
  if ((param_1._0_2_ & 0xff) == _DAT_0080cfb6) {
    serialTransmitHandler();
    return;
  }
  emptyStubFunction1();
  return;
}



//
// Function: serialNodeAddressForwarder @ 0x00019108
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void serialNodeAddressForwarder(undefined4 param_1)

{
  undefined4 unaff_D2;
  
  if ((_DAT_0080cfb6 < (param_1._0_2_ & 0xff)) && ((byte)((uint)param_1 >> 0x10) <= _DAT_0080cfb8))
  {
    serialReceiveBufferProcessor(CONCAT22(param_1._0_2_,(short)((uint)unaff_D2 >> 0x10)) & 0xffffff)
    ;
  }
  return;
}



//
// Function: FUN_0001913e @ 0x0001913e
// ERROR: Failed to decompile
//

//
// Function: serialPort1IsrHandler @ 0x0001917c
//

undefined8 serialPort1IsrHandler(void)

{
  byte *pbVar1;
  byte bVar2;
  undefined3 uVar3;
  undefined4 in_D0;
  undefined4 in_D1;
  undefined2 uVar4;
  undefined2 uStack_1a;
  
  uVar4 = (undefined2)((uint)in_D0 >> 0x10);
  uStack_1a = (undefined2)in_D0;
  while (bVar2 = DAT_00ffd85f, DAT_00ffd85f != 0) {
    if ((DAT_00ffd85f < 3) || (0x10 < DAT_00ffd85f)) {
      DAT_00809d46 = DAT_00ffd801;
      if ((DAT_00ffd801 & 0x80) != 0) {
        do {
        } while ((DAT_00ffd802 & 0x80) != 0);
        DAT_00ffd800 = 10;
      }
    }
    else {
      pbVar1 = (byte *)((uint)DAT_00ffd85f * 0x10 + 0xffd7e0);
      *pbVar1 = 0xfd;
      uVar3 = (undefined3)((uint)pbVar1 >> 8);
      if ((*pbVar1 & 0x20) == 0) {
        serialNodeAddressForwarder(CONCAT22((short)CONCAT31(uVar3,bVar2 - 2),uVar4));
      }
      else {
        serialNodeAddressChecker(CONCAT22((short)CONCAT31(uVar3,bVar2 - 2),uVar4));
      }
    }
  }
  return CONCAT44(CONCAT22(uVar4,uStack_1a),in_D1);
}



//
// Function: canMessageInterruptHandlerSetup @ 0x0001920a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void canMessageInterruptHandlerSetup(void)

{
  _DAT_00808e32 = serialPort1IsrHandler;
  return;
}



//
// Function: emptyStubWrapper1 @ 0x00019216
//

void emptyStubWrapper1(void)

{
  emptyStubFunction1();
  return;
}



//
// Function: modeBasedDataDispatcherWrapper @ 0x00019228
//

void modeBasedDataDispatcherWrapper(undefined4 param_1)

{
  undefined2 in_D0w;
  undefined2 in_stack_00000000;
  
  modeBasedDataDispatcher
            (CONCAT22(CONCAT11((char)((ushort)in_D0w >> 8),(char)((uint)param_1 >> 0x10)),
                      in_stack_00000000));
  return;
}



//
// Function: serialPort2IsrHandler @ 0x0001923a
//

undefined8 serialPort2IsrHandler(void)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 in_D0;
  undefined4 in_D1;
  undefined2 uVar3;
  undefined2 uStack_1a;
  
  uVar3 = (undefined2)((uint)in_D0 >> 0x10);
  uStack_1a = (undefined2)in_D0;
  while (bVar2 = DAT_00ffc85f, DAT_00ffc85f != 0) {
    if ((DAT_00ffc85f < 3) || (0x10 < DAT_00ffc85f)) {
      DAT_00809d47 = DAT_00ffc801;
      if ((DAT_00ffc801 & 0x80) != 0) {
        do {
        } while ((DAT_00ffc802 & 0x80) != 0);
        DAT_00ffc800 = 10;
      }
    }
    else {
      pbVar1 = (byte *)((uint)DAT_00ffc85f * 0x10 + 0xffc7e0);
      *pbVar1 = 0xfd;
      if ((*pbVar1 & 0x20) == 0) {
        modeBasedDataDispatcherWrapper
                  (CONCAT22((short)CONCAT31((int3)((uint)pbVar1 >> 8),bVar2 - 2),uVar3));
      }
      else {
        emptyStubWrapper1();
      }
    }
  }
  return CONCAT44(CONCAT22(uVar3,uStack_1a),in_D1);
}



//
// Function: serialCommunicationIsrRegister @ 0x000192c4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void serialCommunicationIsrRegister(void)

{
  _DAT_00808e36 = serialPort2IsrHandler;
  return;
}



//
// Function: tpuTimerChannelEnable @ 0x000192d0
//

void tpuTimerChannelEnable(void)

{
  DAT_0080d2da = 1;
  tpu_timer_channel_register._2_2_ = 0xfc8a;
  tpu_timer_channel_register._0_2_ = tpu_timer_channel_register._0_2_ & 0x7fff | 0x4000;
  return;
}



//
// Function: epsPositionSensorIsrHandler @ 0x000192f2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 epsPositionSensorIsrHandler(void)

{
  byte *pbVar1;
  undefined4 in_D0;
  undefined4 in_D1;
  byte bVar2;
  
  pbVar1 = _DAT_0080d2b8;
  if ((_DAT_00fffc0c & 0x40) != 0) {
    DAT_0080d2da = 0;
    tpu_timer_channel_register._0_2_ = tpu_timer_channel_register._0_2_ & 0x8fff;
    bVar2 = (byte)_DAT_00fffc0e;
    if (DAT_0080d2d0 == '\x01') {
      *_DAT_0080d2c6 = bVar2;
      _DAT_0080d2c6 = (byte *)CONCAT31(_DAT_0080d2c6,DAT_0080d2c9 + '\x01');
      *_DAT_0080d2c2 = *_DAT_0080d2c2 + 1;
      DAT_0080d2d3 = bVar2 + DAT_0080d2d3;
      if (_DAT_0080d2ca == _DAT_0080d2c6) {
        if (_DAT_0080d2c2 == _DAT_0080d2ca) {
          *_DAT_0080d2c2 = 0;
          DAT_0080d2d3 = 0;
          _DAT_0080d2c6 = (byte *)CONCAT31(_DAT_0080d2c6,DAT_0080d2c5 + '\x01');
        }
        else {
          DAT_0080d2ce = '\x01';
          _DAT_00fffc0a = _DAT_00fffc0a & 0xffdf;
          if (_DAT_0080d2b4 != _DAT_0080d2bc) {
            tpuTimerChannelEnable();
            DAT_0080d2da = 1;
          }
        }
      }
      else {
        tpuTimerChannelEnable();
      }
    }
    else {
      switch(_DAT_0080d2d6) {
      case 0:
        if (bVar2 == *_DAT_0080d2b8) {
          _DAT_0080d2b8 = (byte *)CONCAT31(_DAT_0080d2b8,DAT_0080d2bb + '\x01');
          _DAT_00fffc0e = (ushort)*_DAT_0080d2b8;
          tpuTimerChannelEnable();
          DAT_0080d2d3 = *_DAT_0080d2b8 + DAT_0080d2d3;
          DAT_0080d2d1 = DAT_0080d2d1 + 1;
          if (DAT_0080d2d1 == *_DAT_0080d2bc) {
            _DAT_0080d2d6 = 2;
          }
          else {
            _DAT_0080d2d6 = 1;
          }
        }
        else if (DAT_0080d2ce == '\0') {
          DAT_0080d2d0 = '\x01';
          DAT_0080d2d3 = bVar2;
          *_DAT_0080d2c6 = bVar2;
          _DAT_0080d2c6 = (byte *)CONCAT31(_DAT_0080d2c6,DAT_0080d2c9 + '\x01');
          *_DAT_0080d2c2 = *_DAT_0080d2c2 + 1;
          if (_DAT_0080d2c6 == _DAT_0080d2ca) {
            DAT_0080d2ce = '\x01';
            _DAT_00fffc0a = _DAT_00fffc0a & 0xffdf;
          }
          else {
            tpuTimerChannelEnable();
          }
        }
        else {
          DAT_0080d2d0 = '\x01';
          DAT_0080d2d3 = 0;
          tpuTimerChannelEnable();
        }
        break;
      case 1:
        _DAT_0080d2b8 = (byte *)CONCAT31(_DAT_0080d2b8,DAT_0080d2bb + '\x01');
        _DAT_00fffc0e = (ushort)*_DAT_0080d2b8;
        tpuTimerChannelEnable();
        DAT_0080d2d3 = *_DAT_0080d2b8 + DAT_0080d2d3;
        DAT_0080d2d1 = DAT_0080d2d1 + 1;
        if (DAT_0080d2d1 == *_DAT_0080d2bc) {
          _DAT_0080d2d6 = 2;
        }
        break;
      case 2:
        _DAT_00fffc0e = ~(ushort)DAT_0080d2d3 + 1 & 0xff;
        tpuTimerChannelEnable();
        _DAT_0080d2b8 = (byte *)CONCAT31(_DAT_0080d2b8,DAT_0080d2bb + '\x01');
        _DAT_0080d2d6 = 3;
        break;
      case 3:
        _DAT_0080d2bc = _DAT_0080d2b8;
        _DAT_0080d2b8 = (byte *)CONCAT31(_DAT_0080d2b8,DAT_0080d2bb + '\x01');
        DAT_0080d2d3 = 0;
        CMSNCUER = 0;
        if (((((fault_status_registers_t_00805df2.io_fault_status_4 & 4) != 0) &&
             ((_DAT_008068d2 & 4) != 0)) &&
            ((fault_status_registers_t_00805df2.io_fault_status_4 & 4) != 0)) &&
           ((fault_latch_registers_t_00805e32.io_fault_latch_4 & 4) == 0)) {
          fault_status_registers_t_00805df2.io_fault_status_4 =
               fault_status_registers_t_00805df2.io_fault_status_4 & 0xfffb;
        }
        DAT_0080d2d0 = '\x01';
        if (DAT_0080d2ce == '\0') {
          _DAT_00fffc0a = _DAT_00fffc0a | 0x20;
        }
        else {
          _DAT_00fffc0a = _DAT_00fffc0a & 0xffdf;
        }
        if (_DAT_0080d2b4 != pbVar1) {
          DAT_0080d2da = 1;
          tpu_timer_channel_register._0_2_ = tpu_timer_channel_register._0_2_ | 0x4000;
          tpu_timer_channel_register._2_2_ = 0xfcbe;
        }
      }
    }
  }
  return CONCAT44(in_D0,in_D1);
}



//
// Function: tpuChannelIsrRegister @ 0x0001958c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void tpuChannelIsrRegister(void)

{
  _DAT_00808f02 = epsPositionSensorIsrHandler;
  return;
}



//
// Function: serialTransmitHandler @ 0x00019598
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint serialTransmitHandler(void)

{
  undefined2 uVar1;
  uint uVar2;
  
  _DAT_00805576 = 1;
  *_DAT_0080cf8c = 0xfd;
  uVar2 = _DAT_0080cf78;
  if ((_DAT_0080cf78 == _DAT_0080cf7c) && (DAT_0080cf88 != '\x01')) {
    *_DAT_0080cf8c = 0x7f;
  }
  else {
    FUN_0001913e(&DAT_00ffd800);
    DAT_0080cf88 = '\0';
    uVar2 = _DAT_0080cf7c + 0xe;
    _DAT_0080cf7c = uVar2;
    if (0x80cf6a < uVar2) {
      _DAT_0080cf7c = 0x80ce60;
    }
  }
  uVar1 = (undefined2)(uVar2 >> 0x10);
  uVar2 = CONCAT22(uVar1,fault_status_registers_t_00805df2.io_fault_status_2) & 0xffff0200;
  if ((((fault_status_registers_t_00805df2.io_fault_status_2 & 0x200) != 0) &&
      (uVar2 = CONCAT22(uVar1,_DAT_008068ce) & 0xffff0200, (_DAT_008068ce & 0x200) != 0)) &&
     (uVar2 = CONCAT22(uVar1,fault_status_registers_t_00805df2.io_fault_status_2) & 0xffff0200,
     (fault_status_registers_t_00805df2.io_fault_status_2 & 0x200) != 0)) {
    uVar2 = CONCAT22(uVar1,fault_latch_registers_t_00805e32.io_fault_latch_2) & 0xffff0200;
    if ((fault_latch_registers_t_00805e32.io_fault_latch_2 & 0x200) == 0) {
      fault_status_registers_t_00805df2.io_fault_status_2 =
           fault_status_registers_t_00805df2.io_fault_status_2 & 0xfdff;
    }
  }
  return uVar2;
}



//
// Function: serialReceiveBufferProcessor @ 0x0001965a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void serialReceiveBufferProcessor(uint param_1)

{
  int iVar1;
  ushort uVar2;
  undefined1 *puVar3;
  undefined *puVar4;
  undefined1 *puVar5;
  
  if (DAT_0080cf89 == '\0') {
    iVar1 = (param_1 >> 0x10 & 0xff) * 0x10;
    do {
      (&DAT_00ffd801)[iVar1] = 0xfd;
      *_DAT_0080cf80 = *(uint *)(&DAT_00ffd802 + iVar1) >> 3;
      *(short *)(_DAT_0080cf80 + 1) = (short)((int)((byte)(&DAT_00ffd806)[iVar1] & 0xf0) >> 4);
      *(uint *)((int)_DAT_0080cf80 + 6) = (int)_DAT_0080cf80 + 10;
      uVar2 = 0;
      puVar3 = (undefined1 *)(iVar1 + 0xffd807);
      puVar5 = (undefined1 *)((int)_DAT_0080cf80 + 10);
      do {
        *puVar5 = *puVar3;
        uVar2 = uVar2 + 1;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      } while (uVar2 < 8);
    } while (((&DAT_00ffd801)[iVar1] & 2) != 0);
    _DAT_0080cf80 = (uint *)((int)_DAT_0080cf80 + 0x12);
    if ((uint *)0x80ce4e < _DAT_0080cf80) {
      _DAT_0080cf80 = (uint *)0x80ccf8;
    }
    if (_DAT_0080cf80 == _DAT_0080cf84) {
      DAT_0080cf89 = '\x01';
      puVar4 = &DAT_00ffd810 + (uint)_DAT_0080cfb6 * 0x10;
      uVar2 = _DAT_0080cfb6;
      while (uVar2 = uVar2 + 1, uVar2 <= _DAT_0080cfb8) {
        *puVar4 = 0xf7;
        *puVar4 = 0xfd;
        puVar4 = puVar4 + 0x10;
      }
    }
  }
  return;
}



//
// Function: interruptCounter1Increment @ 0x00019738
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 interruptCounter1Increment(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  _DAT_00800418 = _DAT_00800418 + 1;
  return CONCAT44(in_D0,in_D1);
}



//
// Function: interruptCounter2Increment @ 0x0001976e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 interruptCounter2Increment(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  _DAT_0080061a = _DAT_0080061a + 1;
  return CONCAT44(in_D0,in_D1);
}



//
// Function: initVectorTable @ 0x0001977e
//

void initVectorTable(void)

{
  undefined4 *puVar1;
  
  for (puVar1 = (undefined4 *)&DAT_00808dc2; puVar1 < (undefined4 *)0x8091c2; puVar1 = puVar1 + 1) {
    *puVar1 = interruptCounter2Increment;
  }
  return;
}



//
// Function: bitPatternToIndexConverter @ 0x000197c8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 bitPatternToIndexConverter(void)

{
  ushort uVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  byte *pbVar5;
  
  pbVar5 = _DAT_00800624;
  if (DAT_00800629 == 0) {
    for (; *pbVar5 == 0; pbVar5 = pbVar5 + 1) {
      DAT_00800628 = DAT_00800628 + '\b';
    }
    bVar2 = 0x80;
    bVar3 = 0;
    cVar4 = DAT_00800628;
    _DAT_00800624 = pbVar5;
    do {
      if ((bVar2 & *pbVar5) != 0) {
        uVar1 = (ushort)DAT_00800629;
        DAT_00800629 = DAT_00800629 + 1;
        *(char *)((short)uVar1 + 0x80061c) = cVar4;
      }
      bVar2 = bVar2 >> 1;
      cVar4 = cVar4 + -1;
      bVar3 = bVar3 + 1;
    } while (bVar3 < 8);
    _DAT_00800624 = _DAT_00800624 + 1;
    DAT_00800628 = DAT_00800628 + '\b';
  }
  DAT_00800629 = DAT_00800629 - 1;
  return *(undefined1 *)((short)(ushort)DAT_00800629 + 0x80061c);
}



//
// Function: insiteMultiFrameResponseBuilder @ 0x0001984e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint insiteMultiFrameResponseBuilder(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  char cVar3;
  
  cVar1 = DAT_0080d41a + -2;
  DAT_0080d446 = (char)((uint)param_1 >> 0x10);
  DAT_0080d445 = '\0';
  DAT_0080062a = (byte)param_1;
  cVar3 = DAT_0080d446 + '\x06';
  for (DAT_0080062b = cVar1 - DAT_0080d446; DAT_0080062a < DAT_0080062b;
      DAT_0080062b = DAT_0080062b - DAT_0080062a) {
    DAT_0080d445 = DAT_0080d445 + '\x01';
    cVar3 = DAT_0080062a + 5 + cVar3;
  }
  DAT_0080d445 = DAT_0080d445 + '\x01';
  DAT_0080d444 = 0;
  insite_session_t_0080d407.param_result = DAT_0080d446 + 6;
  if (_DAT_0080d2b4 < _DAT_0080d2bc) {
    uVar2 = (_DAT_0080d2bc - _DAT_0080d2b4) - 2;
  }
  else {
    uVar2 = (_DAT_0080d2bc - _DAT_0080d2b4) + 0xfe;
  }
  if ((int)(uint)(byte)(DAT_0080062b + 5 + cVar3) < (int)uVar2) {
    *(undefined1 *)insite_session_t_0080d407._5_4_ = 0xc0;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    *(char *)insite_session_t_0080d407._5_4_ = DAT_0080d446 + '\x03';
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    *(byte *)insite_session_t_0080d407._5_4_ = insite_session_t_0080d407.command_byte;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    *(char *)insite_session_t_0080d407._5_4_ = DAT_0080d445 << 4;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    *(char *)insite_session_t_0080d407._5_4_ = cVar1;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    return uVar2 & 0xffffff00;
  }
  fault_status_registers_t_00805df2.io_fault_status_4 =
       fault_status_registers_t_00805df2.io_fault_status_4 | 4;
  fault_latch_registers_t_00805e32.io_fault_latch_4 =
       fault_latch_registers_t_00805e32.io_fault_latch_4 | 4;
  return 1;
}



//
// Function: insiteMultiFrameContinuation @ 0x00019952
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void insiteMultiFrameContinuation(void)

{
  *(byte *)insite_session_t_0080d407._9_4_ = insite_session_t_0080d407.param_result;
  *(undefined1 *)insite_session_t_0080d407._5_4_ = 0;
  _DAT_0080d2b4 = insite_session_t_0080d407._5_4_;
  insite_session_t_0080d407._9_4_ = insite_session_t_0080d407._5_4_;
  tpuTransmissionTrigger();
  DAT_0080d444 = DAT_0080d444 + 1;
  if (DAT_0080d444 < DAT_0080d445) {
    DAT_0080d446 = DAT_0080062a;
  }
  else {
    DAT_0080d446 = DAT_0080062b;
  }
  insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
       insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
  *(undefined1 *)insite_session_t_0080d407._5_4_ = 0x80;
  insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
       insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
  insite_session_t_0080d407.param_result = DAT_0080d446 + 5;
  *(undefined1 *)insite_session_t_0080d407._5_4_ = 0xc0;
  insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
       insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
  *(char *)insite_session_t_0080d407._5_4_ = DAT_0080d446 + '\x02';
  insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
       insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
  *(byte *)insite_session_t_0080d407._5_4_ = insite_session_t_0080d407.command_byte;
  insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
       insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
  *(byte *)insite_session_t_0080d407._5_4_ = DAT_0080d444 & 0xf | DAT_0080d445 << 4;
  insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
       insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
  return;
}



//
// Function: insiteLiveDataHandler @ 0x00019a0a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void insiteLiveDataHandler(void)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  char cVar5;
  undefined2 uVar4;
  undefined4 unaff_D2;
  byte bVar6;
  byte bVar7;
  char *pcVar8;
  undefined2 uVar9;
  
  uVar9 = (undefined2)((uint)unaff_D2 >> 0x10);
  insite_session_t_0080d407._13_4_ = _DAT_0080d2ca;
  insite_session_t_0080d407._9_4_ = _DAT_0080d2b4;
  insite_session_t_0080d407._5_4_ = _DAT_0080d2b4;
  insite_session_t_0080d407.response_ptr._0_1_ = 1;
  bVar1 = *_DAT_0080d2ca;
  if (bVar1 < 0x15) {
    insite_session_t_0080d407.buffer_space = (byte)_DAT_0080d2ca;
    bVar7 = insite_session_t_0080d407.buffer_space;
    insite_session_t_0080d407._13_3_ = SUB43((uint)_DAT_0080d2ca >> 8,0);
    insite_session_t_0080d407.buffer_space = insite_session_t_0080d407.buffer_space + 1;
    cVar2 = *(char *)insite_session_t_0080d407._13_4_;
    insite_session_t_0080d407.buffer_space = bVar7 + 2;
    bVar7 = 1;
    insite_session_t_0080d407.param_result = 0;
    responseBufferSpaceCheck();
    if (DAT_0080d419 != '\0') {
LAB_00019c2a:
      if (bVar7 < bVar1) {
        insite_session_t_0080d407.command_byte = *(byte *)insite_session_t_0080d407._13_4_;
        insite_session_t_0080d407.buffer_space = insite_session_t_0080d407.buffer_space + 1;
        cVar5 = insiteParameterParser();
        if (cVar5 == '\0') goto LAB_00019c30;
        bVar7 = cVar5 + bVar7;
        bVar6 = insite_session_t_0080d407.buffer_space;
        if (insite_session_t_0080d407.command_byte == 0) {
          insite_session_t_0080d407.command_byte = *(byte *)insite_session_t_0080d407._13_4_;
          insite_session_t_0080d407.buffer_space = insite_session_t_0080d407.buffer_space + 1;
          uVar4 = parameterLookupForInsite();
          DAT_0080d41a = (undefined1)uVar4;
          bVar6 = '\x01' << (insite_session_t_0080d407.command_byte & 7);
          sVar3 = (short)((int)(uint)insite_session_t_0080d407.command_byte >> 3);
          if (((bVar6 & *(byte *)(sVar3 + 0x8089be)) != 0) &&
             ((bVar6 & *(byte *)(sVar3 + 0x8055fe)) == 0)) {
            insiteParameterResponseBuilder();
          }
        }
        else if (insite_session_t_0080d407.command_byte == 0x80) {
          insite_session_t_0080d407.command_byte = *(byte *)insite_session_t_0080d407._13_4_;
          insite_session_t_0080d407.buffer_space = insite_session_t_0080d407.buffer_space + 1;
          cVar5 = *(char *)insite_session_t_0080d407._13_4_;
          insite_session_t_0080d407.buffer_space = bVar6 + 2;
          if (cVar5 == -0x80) {
            uVar4 = parameterLookupForInsite();
            DAT_0080d41a = (undefined1)uVar4;
            bVar6 = '\x01' << (insite_session_t_0080d407.command_byte & 7);
            sVar3 = (short)((int)(uint)insite_session_t_0080d407.command_byte >> 3);
            if (((bVar6 & *(byte *)(sVar3 + 0x8089be)) != 0) &&
               ((bVar6 & *(byte *)(sVar3 + 0x8055fe)) == 0)) {
              insiteParameterResponseBuilder();
            }
          }
        }
        else if (insite_session_t_0080d407.command_byte == 0xc3) {
          insite_session_t_0080d407.buffer_space = insite_session_t_0080d407.buffer_space + 1;
          cVar5 = *(char *)insite_session_t_0080d407._13_4_;
          insite_session_t_0080d407.buffer_space = bVar6 + 2;
          DAT_0080d447 = *(byte *)insite_session_t_0080d407._13_4_;
          insite_session_t_0080d407.buffer_space = bVar6 + 3;
          DAT_0080d448 = *(byte *)insite_session_t_0080d407._13_4_;
          insite_session_t_0080d407.buffer_space = bVar6 + 4;
          if ((cVar5 == -0x80) && ((DAT_0080d448 & 0xc0) < 0xc0)) {
            bVar6 = 0;
            pcVar8 = &DAT_008089e0;
            while( true ) {
              if ((*pcVar8 == '\0') || (9 < bVar6)) goto LAB_00019c2a;
              if (cVar2 == *pcVar8) break;
              bVar6 = bVar6 + 1;
              pcVar8 = pcVar8 + 1;
            }
            _DAT_0080d48e = (ushort)DAT_0080d448;
            if (((DAT_0080d448 & 0xc0) == 0x80) || ((DAT_0080d448 & 0xc0) == 0x40)) {
              _DAT_0080d48c = 2;
              _DAT_0080d492 = (ushort)DAT_0080d447;
            }
            else {
              insitePidDtcHandler((uint)CONCAT12(DAT_0080d447,uVar9));
            }
            insite_session_t_0080d407.command_byte = 0xc4;
            uVar4 = parameterLookupForInsite();
            DAT_0080d41a = (undefined1)uVar4;
            insiteParameterResponseBuilder();
          }
        }
        else {
          insite_session_t_0080d407.buffer_space =
               cVar5 + -1 + insite_session_t_0080d407.buffer_space;
        }
        goto LAB_00019c2a;
      }
LAB_00019c30:
      responseBufferFinalize();
    }
  }
  return;
}



//
// Function: responseBufferSpaceCheck @ 0x00019c3c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void responseBufferSpaceCheck(void)

{
  byte bVar1;
  
  bVar1 = (CKTTCUER - DAT_0080d2b7) - 2;
  if (bVar1 < 5) {
    DAT_0080d419 = 0;
    fault_status_registers_t_00805df2.io_fault_status_4 =
         fault_status_registers_t_00805df2.io_fault_status_4 | 4;
    fault_latch_registers_t_00805e32.io_fault_latch_4 =
         fault_latch_registers_t_00805e32.io_fault_latch_4 | 4;
    return;
  }
  if (0x15 < bVar1) {
    DAT_0080d419 = 0x13;
    return;
  }
  DAT_0080d419 = (CKTTCUER - DAT_0080d2b7) + -4;
  return;
}



//
// Function: responseBufferFinalize @ 0x00019cbc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void responseBufferFinalize(void)

{
  if (1 < insite_session_t_0080d407.param_result) {
    *(byte *)insite_session_t_0080d407._9_4_ = insite_session_t_0080d407.param_result;
    *(undefined1 *)insite_session_t_0080d407._5_4_ = 0;
    _DAT_0080d2b4 = insite_session_t_0080d407._5_4_;
    tpuTransmissionTrigger();
  }
  return;
}



//
// Function: diagnosticMemoryWriteHandler @ 0x00019cf0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticMemoryWriteHandler(undefined4 param_1)

{
  char cVar3;
  undefined4 uVar1;
  uint uVar2;
  undefined4 unaff_D2;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  char cVar8;
  byte *pbVar9;
  byte *pbVar10;
  bool bVar11;
  undefined2 uVar12;
  byte bStack_f;
  uint local_e;
  byte local_9;
  undefined4 local_8;
  
  uVar12 = (undefined2)((uint)unaff_D2 >> 0x10);
  local_9 = *_DAT_0080d2ca;
  local_8._3_1_ = (char)_DAT_0080d2ca;
  cVar8 = (char)local_8;
  local_8._0_3_ = (undefined3)((uint)_DAT_0080d2ca >> 8);
  local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x02');
  bVar6 = *local_8 & 0xf;
  bVar11 = bVar6 == 0;
  if (bVar11) {
    bVar5 = 4;
  }
  else {
    bVar5 = 2;
  }
  local_8 = (byte *)CONCAT31(local_8._0_3_,cVar8 + '\x03');
  cVar8 = '\0';
  pbVar9 = &CMSYRSFG;
  bVar7 = (byte)((uint)param_1 >> 0x10);
  do {
    if (local_9 <= bVar5) {
      if (bVar5 == local_9) {
        uVar2 = diagnosticResponseBuilder((uint)CONCAT12(cVar8,uVar12));
        if ((char)uVar2 != -1) {
          diagnosticMessageQueueWrite((uint)CONCAT12((char)uVar2,uVar12));
        }
      }
      else {
        diagnosticMessageQueueWrite(CONCAT22(2,uVar12));
      }
      return;
    }
    pbVar10 = &bStack_f + bVar7;
    for (bVar4 = 0; bVar4 < bVar7; bVar4 = bVar4 + 1) {
      *pbVar10 = *local_8;
      local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
      pbVar10 = pbVar10 + -1;
    }
    if (bVar11) {
      bVar6 = *local_8;
      local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
      bVar5 = bVar5 + 1;
    }
    bVar5 = bVar6 + bVar7 + bVar5;
    cVar8 = cVar8 + '\x01';
    if (bVar7 == 2) {
      DAT_0080d164 = 2;
      if (local_e._0_2_ == 0x15) {
        _DAT_0080d458 = 1;
      }
      cVar3 = FUN_0000eaf0((short)((uint)&local_e >> 0x10));
      if (cVar3 != '\0') {
        diagnosticMessageQueueWrite(CONCAT22(8,uVar12));
        return;
      }
    }
    else {
      DAT_0080d164 = 4;
    }
    uVar1 = addressRangeValidator(local_e,(uint)CONCAT12(bVar6,uVar12));
    bVar4 = (byte)uVar1;
    if ((bVar4 == 10) || (bVar4 == 4)) {
      diagnosticMessageQueueWrite(CONCAT22(10,uVar12));
      return;
    }
    if (bVar4 == 9) {
      diagnosticMessageQueueWrite(CONCAT22(9,uVar12));
      return;
    }
    *(uint *)pbVar9 = local_e;
    *(byte **)((int)pbVar9 + 4) = local_8;
    *(byte *)((int)pbVar9 + 8) = bVar6;
    *(byte *)((int)pbVar9 + 9) = bVar4;
    pbVar9 = (byte *)((int)pbVar9 + 10);
    local_8 = (byte *)CONCAT31(local_8._0_3_,bVar6 + (char)local_8);
  } while( true );
}



//
// Function: diagnosticMemoryReadHandler @ 0x00019e62
//

/* WARNING: Removing unreachable block (ram,0x00019fea) */
/* WARNING: Removing unreachable block (ram,0x0001a010) */
/* WARNING: Removing unreachable block (ram,0x00019ff8) */
/* WARNING: Removing unreachable block (ram,0x0001a014) */
/* WARNING: Removing unreachable block (ram,0x0001a01c) */
/* WARNING: Removing unreachable block (ram,0x0001a032) */
/* WARNING: Removing unreachable block (ram,0x0001a038) */
/* WARNING: Removing unreachable block (ram,0x0001a03e) */
/* WARNING: Removing unreachable block (ram,0x0001a052) */
/* WARNING: Removing unreachable block (ram,0x0001a060) */
/* WARNING: Removing unreachable block (ram,0x0001a09a) */
/* WARNING: Removing unreachable block (ram,0x0001a0b4) */
/* WARNING: Removing unreachable block (ram,0x0001a0ba) */
/* WARNING: Removing unreachable block (ram,0x0001a0ca) */
/* WARNING: Removing unreachable block (ram,0x0001a0d4) */
/* WARNING: Removing unreachable block (ram,0x0001a0e6) */
/* WARNING: Removing unreachable block (ram,0x0001a102) */
/* WARNING: Removing unreachable block (ram,0x0001a0ee) */
/* WARNING: Removing unreachable block (ram,0x0001a066) */
/* WARNING: Removing unreachable block (ram,0x0001a08c) */
/* WARNING: Removing unreachable block (ram,0x0001a06c) */
/* WARNING: Removing unreachable block (ram,0x0001a076) */
/* WARNING: Removing unreachable block (ram,0x0001a08a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticMemoryReadHandler(undefined4 param_1)

{
  byte bVar1;
  bool bVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 unaff_D2;
  uint uVar6;
  char cVar7;
  byte bVar8;
  byte bVar9;
  char cVar10;
  undefined4 unaff_D7;
  undefined1 *puVar11;
  undefined2 uVar12;
  undefined1 local_16;
  byte bStack_15;
  undefined4 local_c;
  undefined4 local_8;
  
  pbVar3 = _DAT_0080d2b4;
  puVar11 = &stack0xffffffbc;
  uVar12 = (undefined2)((uint)unaff_D2 >> 0x10);
  cVar10 = (char)((uint)param_1 >> 0x10);
  if (cVar10 == '\x02') {
    bVar8 = 4;
  }
  else {
    bVar8 = 2;
  }
  bVar9 = *_DAT_0080d2ca;
  local_8._3_1_ = (char)_DAT_0080d2ca;
  local_8._0_3_ = (undefined3)((uint)_DAT_0080d2ca >> 8);
  local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x02');
  bVar1 = *local_8 & 0xf;
  if (bVar1 == 0) {
    if ((int)(bVar9 - 4) % (int)(bVar8 + 1) != 0) {
      diagnosticMessageQueueWrite(CONCAT22(2,uVar12));
      return;
    }
    uVar6 = (int)(bVar9 - 4) / (int)(bVar8 + 1) & 0xff;
    bVar9 = 4;
    while (cVar7 = (char)uVar6, uVar6 = (uint)(byte)(cVar7 - 1), cVar7 != '\0') {
      local_8 = (byte *)CONCAT31(local_8._0_3_,bVar8 + 1 + (char)local_8);
      bVar9 = bVar8 + *local_8 + '\x01' + bVar9;
    }
    bVar2 = true;
  }
  else {
    if ((int)(bVar9 - 2) % (int)(uint)bVar8 != 0) {
      diagnosticMessageQueueWrite(CONCAT22(2,uVar12));
      return;
    }
    bVar9 = (bVar1 + bVar8) * (char)((int)(bVar9 - 2) / (int)(uint)bVar8) + 2;
    bVar2 = false;
  }
  if ((int)_DAT_0080d2b4 < _DAT_0080d2bc) {
    iVar4 = (_DAT_0080d2bc - (int)_DAT_0080d2b4) + -2;
  }
  else {
    iVar4 = (_DAT_0080d2bc - (int)_DAT_0080d2b4) + 0xfe;
  }
  if ((int)(uint)bVar9 < iVar4) {
    local_c._3_1_ = (char)_DAT_0080d2b4;
    cVar7 = (char)local_c;
    local_c._0_3_ = (undefined3)((uint)_DAT_0080d2b4 >> 8);
    local_c = (byte *)CONCAT31(local_c._0_3_,(char)local_c + '\x01');
    *local_c = 7;
    local_c = (byte *)CONCAT31(local_c._0_3_,cVar7 + '\x02');
    if (cVar10 == '\x02') {
      *local_c = bVar1 | 0x80;
    }
    else if (cVar10 == '\x01') {
      *local_c = bVar1 | 0xa0;
    }
    else {
      *local_c = bVar1 | 0x20;
    }
    local_c = (byte *)CONCAT31(local_c._0_3_,cVar7 + '\x03');
    if (bVar2) {
      puVar11 = &stack0xffffffb6;
      uVar5 = crc16Calculate(local_c,CONCAT22((short)CONCAT31((int3)((uint)unaff_D7 >> 8),bVar9 - 4)
                                              ,uVar12));
      bStack_15 = (byte)uVar5;
      *local_c = bStack_15;
      local_c = (byte *)CONCAT31(local_c._0_3_,cVar7 + '\x04');
      local_16 = (undefined1)((uint)uVar5 >> 8);
      *local_c = local_16;
      local_c = (byte *)CONCAT31(local_c._0_3_,cVar7 + '\x05');
    }
    *pbVar3 = bVar9;
    *local_c = 0;
    _DAT_0080d2b4 = local_c;
    *(undefined4 *)(puVar11 + -4) = 0x1a160;
    tpuTransmissionTrigger();
  }
  else {
    diagnosticMessageQueueWrite(CONCAT22(4,uVar12));
    fault_status_registers_t_00805df2.io_fault_status_4 =
         fault_status_registers_t_00805df2.io_fault_status_4 | 4;
    fault_latch_registers_t_00805e32.io_fault_latch_4 =
         fault_latch_registers_t_00805e32.io_fault_latch_4 | 4;
  }
  return;
}



//
// Function: diagnosticMessage45Builder @ 0x0001a192
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticMessage45Builder(void)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  byte bVar4;
  undefined4 local_8;
  
  fuelDemandPercentageCalculator();
  if ((fuel_limit_arbitration_t_0080cc4a.arbitration_threshold != _DAT_00800638) ||
     (_DAT_0080d092 != _DAT_0080063a)) {
    DAT_0080d03a = '\x01';
    _DAT_00800638 = fuel_limit_arbitration_t_0080cc4a.arbitration_threshold;
    _DAT_0080063a = _DAT_0080d092;
  }
  if ((int)_DAT_0080d2b4 < _DAT_0080d2bc) {
    iVar3 = (_DAT_0080d2bc - (int)_DAT_0080d2b4) + -2;
  }
  else {
    iVar3 = (_DAT_0080d2bc - (int)_DAT_0080d2b4) + 0xfe;
  }
  if (iVar3 < 7) {
    fault_status_registers_t_00805df2.io_fault_status_4 =
         fault_status_registers_t_00805df2.io_fault_status_4 | 4;
    fault_latch_registers_t_00805e32.io_fault_latch_4 =
         fault_latch_registers_t_00805e32.io_fault_latch_4 | 4;
    return;
  }
  local_8._3_1_ = (char)_DAT_0080d2b4;
  cVar2 = (char)local_8;
  local_8._0_3_ = (undefined3)((uint)_DAT_0080d2b4 >> 8);
  local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
  *local_8 = 0x45;
  local_8 = (byte *)CONCAT31(local_8._0_3_,cVar2 + '\x02');
  *local_8 = (char)((ushort)_DAT_0080bd8e >> 8);
  local_8 = (byte *)CONCAT31(local_8._0_3_,cVar2 + '\x03');
  if (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x20) == 0) ||
     ((_DAT_008068cc & 0x20) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if (((fault_status_registers_t_00805df2.io_fault_status_1 & 8) == 0) ||
       ((_DAT_008068cc & 8) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x10) == 0) ||
         ((_DAT_008068cc & 0x10) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        *local_8 = (char)(((uint)_DAT_00809d4c * 0xff) / 400);
        goto LAB_0001a2b8;
      }
    }
  }
  *local_8 = 0;
LAB_0001a2b8:
  local_8 = (byte *)CONCAT31(local_8._0_3_,cVar2 + '\x04');
  bVar4 = _DAT_0080969a == 1;
  if (_DAT_0080d17a == 1) {
    bVar4 = bVar4 | 2;
  }
  if (fuel_demand_state_t_0080c9a4._2_2_ == 10) {
    bVar4 = bVar4 | 4;
  }
  if (((DAT_0080bdef & 1) == 0) || ((DAT_0080bdf1 & 1) == 0)) {
    bVar4 = bVar4 | 8;
  }
  if (_DAT_008086f0 < _DAT_00809d4c) {
    bVar4 = bVar4 | 0x10;
  }
  if (_DAT_00809d50 == 0) {
    bVar4 = bVar4 | 0x20;
  }
  if (DAT_0080d03a == '\x01') {
    bVar4 = bVar4 | 0x40;
  }
  *local_8 = bVar4;
  local_8 = (byte *)CONCAT31(local_8._0_3_,cVar2 + '\x05');
  *local_8 = (char)((int)(uint)_DAT_008086e0 >> 7);
  local_8 = (byte *)CONCAT31(local_8._0_3_,cVar2 + '\x06');
  *local_8 = DAT_008086e3;
  local_8 = (byte *)CONCAT31(local_8._0_3_,cVar2 + '\a');
  *_DAT_0080d2b4 = 6;
  *local_8 = 0;
  _DAT_0080d2b4 = local_8;
  tpuTransmissionTrigger();
  return;
}



//
// Function: diagnosticMessage46Builder @ 0x0001a398
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticMessage46Builder(void)

{
  short sVar1;
  undefined1 *puVar2;
  char cVar3;
  int iVar4;
  undefined1 local_e;
  undefined1 uStack_d;
  undefined4 local_8;
  
  puVar2 = _DAT_0080d2b4;
  if ((int)_DAT_0080d2b4 < _DAT_0080d2bc) {
    iVar4 = (_DAT_0080d2bc - (int)_DAT_0080d2b4) + -2;
  }
  else {
    iVar4 = (_DAT_0080d2bc - (int)_DAT_0080d2b4) + 0xfe;
  }
  if (iVar4 < 0x17) {
    fault_status_registers_t_00805df2.io_fault_status_4 =
         fault_status_registers_t_00805df2.io_fault_status_4 | 4;
    fault_latch_registers_t_00805e32.io_fault_latch_4 =
         fault_latch_registers_t_00805e32.io_fault_latch_4 | 4;
  }
  else {
    local_8._3_1_ = (char)_DAT_0080d2b4;
    cVar3 = (char)local_8;
    local_8._0_3_ = (undefined3)((uint)_DAT_0080d2b4 >> 8);
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
    *local_8 = 0x46;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x02');
    sVar1 = _DAT_0080d092 * 2;
    uStack_d = (undefined1)sVar1;
    *local_8 = uStack_d;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x03');
    local_e = (undefined1)((ushort)sVar1 >> 8);
    *local_8 = local_e;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x04');
    multiSpeedParameterInterpolation();
    *local_8 = (char)((ushort)_DAT_0080bd96 >> 8);
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x05');
    sVar1 = _DAT_00807c3a * 2;
    uStack_d = (undefined1)sVar1;
    *local_8 = uStack_d;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x06');
    local_e = (undefined1)((ushort)sVar1 >> 8);
    *local_8 = local_e;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\a');
    *local_8 = (char)((ushort)_DAT_0080bd98 >> 8);
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\b');
    sVar1 = _DAT_00807c3c * 2;
    uStack_d = (undefined1)sVar1;
    *local_8 = uStack_d;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\t');
    local_e = (undefined1)((ushort)sVar1 >> 8);
    *local_8 = local_e;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\n');
    *local_8 = (char)((ushort)_DAT_0080bd90 >> 8);
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\v');
    sVar1 = CRACSWAC * 2;
    uStack_d = (undefined1)sVar1;
    *local_8 = uStack_d;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\f');
    local_e = (undefined1)((ushort)sVar1 >> 8);
    *local_8 = local_e;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\r');
    *local_8 = (char)((ushort)_DAT_0080bd92 >> 8);
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x0e');
    sVar1 = CRCNDTRF * 2;
    uStack_d = (undefined1)sVar1;
    *local_8 = uStack_d;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x0f');
    local_e = (undefined1)((ushort)sVar1 >> 8);
    *local_8 = local_e;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x10');
    *local_8 = (char)((ushort)_DAT_0080bd94 >> 8);
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x11');
    sVar1 = _DAT_00807c34 * 2;
    uStack_d = (undefined1)sVar1;
    *local_8 = uStack_d;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x12');
    local_e = (undefined1)((ushort)sVar1 >> 8);
    *local_8 = local_e;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x13');
    uStack_d = (undefined1)(_DAT_00807c32 / 10);
    *local_8 = uStack_d;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x14');
    sVar1 = fuel_limit_arbitration_t_0080cc4a.demand_limited * 2;
    uStack_d = (undefined1)sVar1;
    *local_8 = uStack_d;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x15');
    local_e = (undefined1)((ushort)sVar1 >> 8);
    *local_8 = local_e;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x16');
    uStack_d = (undefined1)((int)(uint)_DAT_0080848c >> 7);
    *local_8 = uStack_d;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x17');
    *puVar2 = 0x16;
    *local_8 = 0;
    _DAT_0080d2b4 = local_8;
    tpuTransmissionTrigger();
  }
  return;
}



//
// Function: fuelArbitratorControlService @ 0x0001a5b0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint fuelArbitratorControlService(void)

{
  char cVar1;
  undefined1 uVar2;
  byte bVar3;
  ushort uVar4;
  char cVar5;
  short sVar6;
  uint uVar7;
  undefined4 unaff_D2;
  short unaff_D3w;
  bool bVar8;
  undefined2 local_c;
  undefined2 local_a;
  undefined4 local_8;
  
  cVar1 = *_DAT_0080d2ca;
  local_8._3_1_ = (char)_DAT_0080d2ca;
  cVar5 = (char)local_8;
  local_8._0_3_ = (undefined3)((uint)_DAT_0080d2ca >> 8);
  local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x02');
  uVar4 = *local_8 & 3;
  uVar7 = diagnosticMessageValidator
                    (0x4a,CONCAT12(*local_8,(short)((uint)unaff_D2 >> 0x10)) & 0x3ffff);
  if ((short)uVar7 != 0) {
    return uVar7;
  }
  if (3 < (uint)(int)(short)uVar4) goto LAB_0001a636;
  uVar7 = (uint)(&switchD_0001a604::switchdataD_0001a608)[(short)uVar4];
  switch(uVar4) {
  case 0:
    if (cVar1 != '\x03') {
      return uVar7;
    }
    goto LAB_0001a636;
  case 1:
    break;
  case 2:
    if (cVar1 != '\x04') {
      return uVar7;
    }
    goto LAB_0001a636;
  case 3:
  }
  if (cVar1 != '\x05') {
    return uVar7;
  }
LAB_0001a636:
  if (fuel_arbitrator_diag_t_0080cff8.rpm_target == 0) {
    uVar7 = diagnosticSessionValidator(0x4a);
    if ((short)uVar7 != 0) {
      return uVar7;
    }
    _DAT_0080d01e = _DAT_0080d01a;
  }
  else if ((fuel_arbitrator_diag_t_0080cff8._28_2_ != 0) ||
          ((char)fuel_arbitrator_diag_t_0080cff8.limited_value != 'J')) {
    uVar7 = diagnosticSessionValidator(0x4a);
    if ((short)uVar7 != 0) {
      return uVar7;
    }
    if (_DAT_0080d01e < _DAT_0080d01a) {
      return _DAT_0080d01a;
    }
    _DAT_0080d01e = _DAT_0080d01a;
  }
  fuel_arbitrator_diag_t_0080cff8.control_flags = (word)*local_8;
  fuel_arbitrator_diag_t_0080cff8._26_2_ = 0;
  fuel_arbitrator_diag_t_0080cff8._28_2_ = 0;
  fuel_arbitrator_diag_t_0080cff8.limited_value._1_1_ = 0x4a;
  sVar6 = unaff_D3w;
  switch(uVar4) {
  case 0:
    _DAT_0080d028 = 0;
    fuel_arbitrator_diag_t_0080cff8.rpm_target = 0;
    fuel_arbitrator_diag_t_0080cff8.fuel_mode = 0;
    fuel_arbitrator_diag_t_0080cff8._20_2_ = 0;
    sVar6 = _DAT_008086e8 + 1;
    break;
  case 1:
    diagnosticStateInitializer(0x4a);
    _DAT_0080d028 = *(short *)(_DAT_0080d01e + 4) + 1;
    fuel_arbitrator_diag_t_0080cff8.rpm_target = 1;
    fuel_arbitrator_diag_t_0080cff8.fuel_mode = 1;
    fuel_arbitrator_diag_t_0080cff8._20_2_ = 1;
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar5 + '\x03');
    uVar2 = *local_8;
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar5 + '\x04');
    local_a = CONCAT11(*local_8,uVar2);
    fuel_arbitrator_diag_t_0080cff8.state_pointer._1_2_ = (undefined2)((int)(uint)local_a >> 1);
    sVar6 = _DAT_0080d028;
    break;
  case 2:
    diagnosticStateInitializer(0x4a);
    _DAT_0080d028 = *(short *)(_DAT_0080d01e + 8) + 1;
    fuel_arbitrator_diag_t_0080cff8.rpm_target = 2;
    fuel_arbitrator_diag_t_0080cff8.fuel_mode = 1;
    fuel_arbitrator_diag_t_0080cff8._20_2_ = 0;
    local_c = (ushort)(byte)local_c;
    fuel_arbitrator_diag_t_0080cff8._16_2_ = local_c << 8;
    fuel_arbitrator_diag_t_0080cff8._24_2_ =
         _DAT_0080bd8c +
         (short)(((int)(short)(_DAT_00807c38 - _DAT_0080bda0) *
                 (int)(short)fuel_arbitrator_diag_t_0080cff8._16_2_) / 0x6400);
    sVar6 = _DAT_0080d028;
    if ((short)fuel_arbitrator_diag_t_0080cff8._24_2_ < 0) {
      fuel_arbitrator_diag_t_0080cff8._24_2_ = 0;
      sVar6 = _DAT_0080d028;
    }
    break;
  case 3:
    diagnosticStateInitializer(0x4a);
    _DAT_0080d028 = *(short *)(_DAT_0080d01e + 0xc) + 1;
    fuel_arbitrator_diag_t_0080cff8.rpm_target = 3;
    fuel_arbitrator_diag_t_0080cff8.fuel_mode = 1;
    fuel_arbitrator_diag_t_0080cff8._20_2_ = 0;
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar5 + '\x03');
    local_a = (ushort)*local_8;
    fuel_arbitrator_diag_t_0080cff8.command_counter = local_a << 7;
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar5 + '\x04');
    bVar3 = *local_8;
    if (bVar3 < 0x80) {
      local_c = (ushort)bVar3;
    }
    else {
      local_c = CONCAT11(0xff,bVar3);
    }
    fuel_arbitrator_diag_t_0080cff8.prev_state_pointer._1_2_ =
         _DAT_0080bd8c +
         (short)(((int)(short)(_DAT_00807c38 - _DAT_0080bda0) * (short)local_c * 8) / 0x6400);
    sVar6 = _DAT_0080d028;
    if (fuel_arbitrator_diag_t_0080cff8.prev_state_pointer._1_2_ < 0) {
      fuel_arbitrator_diag_t_0080cff8.prev_state_pointer._1_2_ = 0;
      sVar6 = _DAT_0080d028;
    }
  }
  _DAT_0080d032 = sVar6;
  bVar8 = (fuel_arbitrator_diag_t_0080cff8.control_flags & 4) != 0;
  _DAT_0080d036 = _DAT_0080d032;
  if (bVar8) {
    _DAT_0080d036 = 0;
  }
  fuel_arbitrator_diag_t_0080cff8.throttle_mode = (word)!bVar8;
  bVar8 = (fuel_arbitrator_diag_t_0080cff8.control_flags & 8) == 0;
  _DAT_0080d02e = _DAT_0080d032;
  if (bVar8) {
    _DAT_0080d02e = 0;
  }
  fuel_arbitrator_diag_t_0080cff8.speed_limit = (word)!bVar8;
  bVar8 = (fuel_arbitrator_diag_t_0080cff8.control_flags & 0x10) == 0;
  if (bVar8) {
    fuel_arbitrator_diag_t_0080cff8._30_2_ = 0;
  }
  else {
    _DAT_0080d032 = 0;
  }
  fuel_arbitrator_diag_t_0080cff8.fuel_limit = (word)bVar8;
  return fuel_arbitrator_diag_t_0080cff8.control_flags & 0xffff0010;
}



//
// Function: extendedDiagnosticService4C @ 0x0001a910
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void extendedDiagnosticService4C(void)

{
  undefined4 local_8;
  
  if (*_DAT_0080d2ca == '\x02') {
    local_8._3_1_ = (char)_DAT_0080d2ca;
    local_8 = (byte *)CONCAT31((int3)((uint)_DAT_0080d2ca >> 8),(char)local_8 + '\x02');
    if ((*local_8 & 1) != 0) {
      diagnosticMessage46Builder();
      DAT_0080d03a = 0;
    }
    if ((*local_8 & 8) != 0) {
      diagnosticMessage54Builder();
    }
    if ((*local_8 & 0x80) == 0) {
      fuel_arbitrator_diag_t_0080cff8.session_counter = 0;
      _DAT_0080d034 = 0;
    }
    else {
      fuel_arbitrator_diag_t_0080cff8.session_counter = 1;
      _DAT_0080d034 = _DAT_008086ee;
    }
  }
  return;
}



//
// Function: extendedDiagnosticService4F @ 0x0001a97e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint extendedDiagnosticService4F(void)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  char cVar4;
  short sVar5;
  undefined2 extraout_D0u;
  uint uVar6;
  int iVar7;
  undefined4 unaff_D2;
  short unaff_D3w;
  undefined2 local_c;
  ushort local_a;
  undefined4 local_8;
  
  cVar1 = *_DAT_0080d2ca;
  local_8._3_1_ = (char)_DAT_0080d2ca;
  cVar4 = (char)local_8;
  local_8._0_3_ = (undefined3)((uint)_DAT_0080d2ca >> 8);
  local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x02');
  uVar6 = *local_8 & 4;
  if ((*local_8 & 4) == 0) {
    uVar3 = *local_8 & 3;
    uVar6 = diagnosticMessageValidator
                      (0x4f,CONCAT12(*local_8,(short)((uint)unaff_D2 >> 0x10)) & 0x3ffff);
    if ((short)uVar6 == 0) {
      if ((uint)(int)(short)uVar3 < 4) {
        switch(uVar3) {
        case 0:
          if (cVar1 != '\x02') {
            return (uint)(&switchD_0001a9e2::switchdataD_0001a9e6)[(short)uVar3];
          }
          break;
        default:
          if (cVar1 != '\x03') {
            return (uint)(&switchD_0001a9e2::switchdataD_0001a9e6)[(short)uVar3];
          }
        }
      }
      if (fuel_arbitrator_diag_t_0080cff8.rpm_target == 0) {
        uVar6 = diagnosticSessionValidator(0x4f);
        if ((short)uVar6 != 0) {
          return uVar6;
        }
        _DAT_0080d01e = _DAT_0080d01a;
      }
      else if ((fuel_arbitrator_diag_t_0080cff8._28_2_ != 0) ||
              ((char)fuel_arbitrator_diag_t_0080cff8.limited_value != 'O')) {
        uVar6 = diagnosticSessionValidator(0x4f);
        if ((short)uVar6 != 0) {
          return uVar6;
        }
        if (_DAT_0080d01e < _DAT_0080d01a) {
          return _DAT_0080d01a;
        }
        _DAT_0080d01e = _DAT_0080d01a;
      }
      fuel_arbitrator_diag_t_0080cff8.control_flags = (word)*local_8;
      fuel_arbitrator_diag_t_0080cff8._26_2_ = 0;
      fuel_arbitrator_diag_t_0080cff8._28_2_ = 0;
      fuel_arbitrator_diag_t_0080cff8.limited_value._1_1_ = 'O';
      iVar7 = (int)(short)uVar3;
      sVar5 = unaff_D3w;
      switch((int)(short)uVar3) {
      case 0:
        _DAT_0080d028 = 0;
        fuel_arbitrator_diag_t_0080cff8.rpm_target = 0;
        fuel_arbitrator_diag_t_0080cff8.fuel_mode = 0;
        fuel_arbitrator_diag_t_0080cff8._20_2_ = 0;
        iVar7 = 0;
        sVar5 = _DAT_008086e8 + 1;
        break;
      case 1:
        diagnosticStateInitializer(0x4f);
        _DAT_0080d028 = *(short *)(_DAT_0080d01e + 4) + 1;
        fuel_arbitrator_diag_t_0080cff8.rpm_target = 1;
        fuel_arbitrator_diag_t_0080cff8.fuel_mode = 2;
        fuel_arbitrator_diag_t_0080cff8._20_2_ = 1;
        local_8 = (byte *)CONCAT31(local_8._0_3_,cVar4 + '\x03');
        local_a = (ushort)*local_8;
        fuel_arbitrator_diag_t_0080cff8.state_pointer._1_2_ = local_a << 7;
        iVar7 = CONCAT22(extraout_D0u,fuel_arbitrator_diag_t_0080cff8.state_pointer._1_2_);
        sVar5 = _DAT_0080d028;
        break;
      case 2:
        diagnosticStateInitializer(0x4f);
        _DAT_0080d028 = *(short *)(_DAT_0080d01e + 8) + 1;
        fuel_arbitrator_diag_t_0080cff8.rpm_target = 2;
        fuel_arbitrator_diag_t_0080cff8.fuel_mode = 2;
        fuel_arbitrator_diag_t_0080cff8._20_2_ = 0;
        local_8 = (byte *)CONCAT31(local_8._0_3_,cVar4 + '\x03');
        local_c = (ushort)*local_8;
        fuel_arbitrator_diag_t_0080cff8._16_2_ = local_c << 8;
        iVar7 = ((int)(short)(_DAT_00807c38 - _DAT_0080bda0) *
                (int)(short)fuel_arbitrator_diag_t_0080cff8._16_2_) / 0x6400;
        fuel_arbitrator_diag_t_0080cff8._24_2_ = _DAT_0080bd8c + (short)iVar7;
        iVar7 = CONCAT22((short)((uint)iVar7 >> 0x10),fuel_arbitrator_diag_t_0080cff8._24_2_);
        sVar5 = _DAT_0080d028;
        if ((short)fuel_arbitrator_diag_t_0080cff8._24_2_ < 0) {
          fuel_arbitrator_diag_t_0080cff8._24_2_ = 0;
          sVar5 = _DAT_0080d028;
        }
        break;
      case 3:
        diagnosticStateInitializer(0x4f);
        _DAT_0080d028 = *(short *)(_DAT_0080d01e + 0xc) + 1;
        fuel_arbitrator_diag_t_0080cff8.rpm_target = 3;
        fuel_arbitrator_diag_t_0080cff8.fuel_mode = 2;
        fuel_arbitrator_diag_t_0080cff8._20_2_ = 0;
        fuel_arbitrator_diag_t_0080cff8.command_counter = _DAT_008037b4;
        local_8 = (byte *)CONCAT31(local_8._0_3_,cVar4 + '\x03');
        bVar2 = *local_8;
        if (bVar2 < 0x80) {
          local_c = (ushort)bVar2;
        }
        else {
          local_c = CONCAT11(0xff,bVar2);
        }
        iVar7 = ((int)(short)(_DAT_00807c38 - _DAT_0080bda0) * (short)local_c * 0x100) / 0x6400;
        fuel_arbitrator_diag_t_0080cff8.prev_state_pointer._1_2_ = _DAT_0080bd8c + (short)iVar7;
        iVar7 = CONCAT22((short)((uint)iVar7 >> 0x10),
                         fuel_arbitrator_diag_t_0080cff8.prev_state_pointer._1_2_);
        sVar5 = _DAT_0080d028;
        if (fuel_arbitrator_diag_t_0080cff8.prev_state_pointer._1_2_ < 0) {
          fuel_arbitrator_diag_t_0080cff8.prev_state_pointer._1_2_ = 0;
          sVar5 = _DAT_0080d028;
        }
      }
      _DAT_0080d036 = sVar5;
      uVar6 = CONCAT22((short)((uint)iVar7 >> 0x10),fuel_arbitrator_diag_t_0080cff8.control_flags) &
              0xffff0010;
      if ((fuel_arbitrator_diag_t_0080cff8.control_flags & 0x10) == 0) {
        fuel_arbitrator_diag_t_0080cff8.throttle_mode = 0;
        _DAT_0080d036 = 0;
      }
      else {
        fuel_arbitrator_diag_t_0080cff8.throttle_mode = 1;
      }
    }
  }
  return uVar6;
}



//
// Function: extendedDiagnosticService51 @ 0x0001ac64
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void extendedDiagnosticService51(void)

{
  undefined4 local_8;
  
  if (*_DAT_0080d2ca == '\x02') {
    local_8._3_1_ = (char)_DAT_0080d2ca;
    local_8 = (byte *)CONCAT31((int3)((uint)_DAT_0080d2ca >> 8),(char)local_8 + '\x02');
    if ((*local_8 & 1) != 0) {
      diagnosticMessage46Builder();
      DAT_0080d03a = 0;
    }
    if ((*local_8 & 8) != 0) {
      diagnosticMessage54Builder();
    }
  }
  return;
}



//
// Function: diagnosticMessage53Builder @ 0x0001aca8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticMessage53Builder(void)

{
  char cVar1;
  int iVar2;
  undefined1 uVar3;
  undefined4 local_8;
  
  if ((int)_DAT_0080d2b4 < _DAT_0080d2bc) {
    iVar2 = (_DAT_0080d2bc - (int)_DAT_0080d2b4) + -2;
  }
  else {
    iVar2 = (_DAT_0080d2bc - (int)_DAT_0080d2b4) + 0xfe;
  }
  if (iVar2 < 3) {
    fault_status_registers_t_00805df2.io_fault_status_4 =
         fault_status_registers_t_00805df2.io_fault_status_4 | 4;
    fault_latch_registers_t_00805e32.io_fault_latch_4 =
         fault_latch_registers_t_00805e32.io_fault_latch_4 | 4;
  }
  else {
    local_8._3_1_ = (char)_DAT_0080d2b4;
    cVar1 = (char)local_8;
    local_8._0_3_ = (undefined3)((uint)_DAT_0080d2b4 >> 8);
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
    *local_8 = 0x53;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar1 + '\x02');
    uVar3 = 0;
    if (_DAT_0080969e == 1) {
      uVar3 = 2;
    }
    *local_8 = uVar3;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar1 + '\x03');
    *_DAT_0080d2b4 = 2;
    *local_8 = 0;
    _DAT_0080d2b4 = local_8;
    tpuTransmissionTrigger();
  }
  return;
}



//
// Function: diagnosticMessage54Builder @ 0x0001ad50
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticMessage54Builder(void)

{
  char cVar1;
  int iVar2;
  undefined4 local_8;
  
  if ((int)_DAT_0080d2b4 < _DAT_0080d2bc) {
    iVar2 = (_DAT_0080d2bc - (int)_DAT_0080d2b4) + -2;
  }
  else {
    iVar2 = (_DAT_0080d2bc - (int)_DAT_0080d2b4) + 0xfe;
  }
  if (iVar2 < 4) {
    fault_status_registers_t_00805df2.io_fault_status_4 =
         fault_status_registers_t_00805df2.io_fault_status_4 | 4;
    fault_latch_registers_t_00805e32.io_fault_latch_4 =
         fault_latch_registers_t_00805e32.io_fault_latch_4 | 4;
  }
  else {
    local_8._3_1_ = (char)_DAT_0080d2b4;
    cVar1 = (char)local_8;
    local_8._0_3_ = (undefined3)((uint)_DAT_0080d2b4 >> 8);
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
    *local_8 = 0x54;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar1 + '\x02');
    if (_DAT_008037d4 == 3) {
      *local_8 = 4;
    }
    else {
      *local_8 = 2;
    }
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar1 + '\x03');
    *local_8 = (char)(((uint)_DAT_0080894a * 0x2e1) / 10000);
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar1 + '\x04');
    *_DAT_0080d2b4 = 3;
    *local_8 = 0;
    _DAT_0080d2b4 = local_8;
    tpuTransmissionTrigger();
  }
  return;
}



//
// Function: j1939TimeoutDataClearHandler @ 0x0001ae20
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint j1939TimeoutDataClearHandler(void)

{
  uint uVar1;
  
  uVar1 = engine_control_flags_t_008035d6.protection_system & 0x100;
  if (((engine_control_flags_t_008035d6.protection_system & 0x100) != 0) &&
     (uVar1 = _DAT_008086f2 + _DAT_008054a8, uVar1 < _DAT_0080d4c4)) {
    _DAT_008054a6 = 0;
    _DAT_008054a8 = 0;
    _DAT_008054b2 = 0;
    _DAT_008054b4 = 0;
    _DAT_008054b8 = 0;
    _DAT_008054ba = 0;
    _DAT_008054ac = 0;
    _DAT_008054ae = 0;
  }
  return uVar1;
}



//
// Function: j1939MessageTypeCounter @ 0x0001ae74
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint j1939MessageTypeCounter(undefined4 param_1)

{
  undefined4 in_D0;
  uint uVar1;
  
  uVar1 = CONCAT22((short)((uint)in_D0 >> 0x10),engine_control_flags_t_008035d6.protection_system) &
          0xffff0080;
  if ((engine_control_flags_t_008035d6.protection_system & 0x80) != 0) {
    if (param_1._0_2_ == 1) {
      _DAT_008054a6 = _DAT_008054a6 + 1;
      _DAT_008054b2 = _DAT_008054b2 + 1;
      _DAT_008054b4 = _DAT_0080d4c4;
      _DAT_008054a8 = _DAT_0080d4c4;
      return _DAT_0080d4c4;
    }
    if (param_1._0_2_ == 2) {
      _DAT_008054a6 = _DAT_008054a6 + 1;
      _DAT_008054b8 = _DAT_008054b8 + 1;
      _DAT_008054ba = _DAT_0080d4c4;
      _DAT_008054a8 = _DAT_0080d4c4;
      return _DAT_0080d4c4;
    }
    if (param_1._0_2_ != 3) {
      return (int)param_1._0_2_;
    }
    _DAT_008054a6 = _DAT_008054a6 + 1;
    _DAT_008054ac = _DAT_008054ac + 1;
    _DAT_008054ae = _DAT_0080d4c4;
    _DAT_008054a8 = _DAT_0080d4c4;
    uVar1 = _DAT_0080d4c4;
  }
  return uVar1;
}



//
// Function: canMessageFilterInit @ 0x0001aef4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void canMessageFilterInit(void)

{
  byte bVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  
  bVar1 = 0;
  puVar2 = (undefined2 *)&DAT_008084b2;
  puVar3 = (undefined2 *)&DAT_0080cfc4;
  puVar4 = (undefined2 *)&DAT_0080cfba;
  puVar5 = (undefined2 *)&DAT_008084aa;
  do {
    *puVar4 = *puVar5;
    *puVar3 = *puVar2;
    bVar1 = bVar1 + 1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  } while (bVar1 < 4);
  _DAT_0080cfc2 = _DAT_008084a0;
  _DAT_0080cfcc = _DAT_008084a2;
  return;
}



//
// Function: timerSchedulerSetup @ 0x0001af38
// ERROR: Failed to decompile
//

//
// Function: phase3_periodic_task_scheduler @ 0x0001afe4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort phase3_periodic_task_scheduler(void)

{
  ushort uVar1;
  byte bVar2;
  int iVar3;
  
  uVar1 = _DAT_008035ea & 8;
  if (uVar1 != 0) {
    if ((_DAT_00809d3e & 4) != 0) {
      iVar3 = 0x80063c;
      for (bVar2 = 0; bVar2 < DAT_00800768; bVar2 = bVar2 + 1) {
        if (*(short *)(iVar3 + 4) == _DAT_0080076a) {
          *(short *)(iVar3 + 4) = *(short *)(iVar3 + 2) + *(short *)(iVar3 + 4);
          (**(code **)(iVar3 + 6))();
        }
        iVar3 = iVar3 + 10;
      }
      _DAT_0080076a = _DAT_0080076a + 1;
    }
    uVar1 = _DAT_00809d3e & 8;
    if (uVar1 != 0) {
      iVar3 = 0x800704;
      for (bVar2 = 0; bVar2 < DAT_00800769; bVar2 = bVar2 + 1) {
        if (*(short *)(iVar3 + 4) == _DAT_0080076c) {
          *(short *)(iVar3 + 4) = *(short *)(iVar3 + 2) + *(short *)(iVar3 + 4);
          (**(code **)(iVar3 + 6))();
        }
        uVar1 = 10;
        iVar3 = iVar3 + 10;
      }
      _DAT_0080076c = _DAT_0080076c + 1;
    }
  }
  return uVar1;
}



//
// Function: emptyPlaceholderInit @ 0x0001b07c
//

void emptyPlaceholderInit(void)

{
  return;
}



//
// Function: j1939TorqueControlModeParser @ 0x0001b082
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint j1939TorqueControlModeParser(int param_1,undefined4 param_2)

{
  byte bVar1;
  char cVar2;
  undefined2 uVar3;
  undefined4 in_D0;
  ushort uVar4;
  
  uVar3 = (undefined2)((uint)in_D0 >> 0x10);
  bVar1 = *(byte *)(*(int *)(param_1 + 6) + 1);
  cVar2 = *(char *)(*(int *)(param_1 + 6) + 2);
  if ((bVar1 == 0xfe) && (cVar2 == -2)) {
    uVar4 = 0xffff;
  }
  else if (cVar2 == '\x01') {
    uVar3 = (undefined2)(bVar1 - 1 >> 0x10);
    switch(bVar1 - 1) {
    case 0:
      uVar4 = 0xc;
      break;
    case 1:
      uVar4 = 0x80;
      break;
    default:
      return 4;
    case 5:
      uVar4 = 1;
      break;
    case 6:
      uVar4 = 2;
    }
  }
  else {
    if (cVar2 != -3) {
      return 4;
    }
    uVar3 = 0;
    if (bVar1 == 0xfe) {
      uVar4 = 0x8c;
    }
    else if (bVar1 == 1) {
      uVar4 = 0xc;
    }
    else {
      if (bVar1 != 2) {
        return 4;
      }
      uVar4 = 0x80;
    }
  }
  if (param_2._1_1_ == '\x01') {
    _DAT_00809d3e = uVar4 | _DAT_00809d3e;
  }
  else {
    uVar4 = ~uVar4;
    _DAT_00809d3e = uVar4 & _DAT_00809d3e;
  }
  return CONCAT22(uVar3,uVar4) & 0xffffff00;
}



//
// Function: j1939TorqueControlModeClear @ 0x0001b150
//

void j1939TorqueControlModeClear(int param_1)

{
  ushort in_stack_00000000;
  
  j1939TorqueControlModeParser(param_1,(uint)in_stack_00000000);
  return;
}



//
// Function: j1939TorqueControlModeSet @ 0x0001b160
//

void j1939TorqueControlModeSet(int param_1)

{
  undefined2 in_stack_00000000;
  
  j1939TorqueControlModeParser(param_1,CONCAT22(1,in_stack_00000000));
  return;
}



//
// Function: systemFunction4xParameterizedAlt @ 0x0001b172
//

void systemFunction4xParameterizedAlt(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  uVar3 = 0xb07e;
  coreSystemFunction(1);
  uVar2 = 0xb07e;
  uVar1 = 0x10;
  coreSystemFunction(1,uVar3);
  coreSystemFunction(1,uVar1,uVar2);
  coreSystemFunction();
  return;
}



//
// Function: coreSystemControlFunction @ 0x0001b1b4
// ERROR: Failed to decompile
//

//
// Function: timerBasedTaskScheduler @ 0x0001b1f4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint timerBasedTaskScheduler(void)

{
  char cVar1;
  bool bVar2;
  ushort uVar3;
  undefined4 in_D0;
  uint uVar4;
  byte bVar5;
  char *pcVar6;
  short *psVar7;
  undefined *puVar8;
  undefined2 local_6;
  
  uVar3 = _DAT_00fff404;
  uVar4 = CONCAT22((short)((uint)in_D0 >> 0x10),_DAT_008035ea) & 0xffff0008;
  if ((_DAT_008035ea & 8) != 0) {
    while ((uVar4 = (uint)_DAT_00fff404 - (uint)uVar3,
           (int)((uint)_DAT_00fff404 - (uint)uVar3) < 0xfa &&
           ((_DAT_0080cf80 != _DAT_0080cf84 || (uVar4 = _DAT_0080cf80, DAT_0080cf89 == '\x01'))))) {
      bVar5 = *(byte *)(_DAT_0080cf84 + 1);
      if (bVar5 < 0xf0) {
        local_6 = (ushort)bVar5 << 8;
      }
      else {
        local_6 = CONCAT11(bVar5,*(undefined1 *)(_DAT_0080cf84 + 2));
      }
      bVar2 = false;
      pcVar6 = &DAT_0080cfa4;
      do {
        if (*pcVar6 == -2) goto LAB_0001b262;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (*(char *)(_DAT_0080cf84 + 3) != cVar1);
      bVar2 = true;
LAB_0001b262:
      if (!bVar2) {
        psVar7 = (short *)&DAT_0080076e;
        for (bVar5 = 0; bVar5 < DAT_008007aa; bVar5 = bVar5 + 1) {
          if (*psVar7 == local_6) {
            (**(code **)(psVar7 + 1))(_DAT_0080cf84);
            break;
          }
          psVar7 = psVar7 + 3;
        }
      }
      _DAT_0080cf84 = _DAT_0080cf84 + 0x12;
      if (0x80ce4e < _DAT_0080cf84) {
        _DAT_0080cf84 = 0x80ccf8;
      }
      if (DAT_0080cf89 == '\x01') {
        DAT_0080cf89 = '\0';
        puVar8 = &DAT_00ffd810 + (uint)_DAT_0080cfb6 * 0x10;
        bVar5 = DAT_0080cfb7;
        while (bVar5 = bVar5 + 1, bVar5 <= _DAT_0080cfb8) {
          *puVar8 = 0xfb;
          puVar8 = puVar8 + 0x10;
        }
      }
    }
  }
  return uVar4;
}



//
// Function: phase3_retarder_condition_monitor @ 0x0001b314
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort phase3_retarder_condition_monitor(void)

{
  ushort uVar1;
  
  uVar1 = engine_control_flags_t_008035d6.protection_system & 0x1000;
  if (((((engine_control_flags_t_008035d6.protection_system & 0x1000) != 0) && (_DAT_0080cfa8 == 2))
      && (_DAT_0080cfaa == 1)) &&
     (((fuel_arbitrator_diag_t_0080cff8.rpm_target == 1 &&
       (fuel_arbitrator_diag_t_0080cff8.fuel_mode == 1)) &&
      (uVar1 = _DAT_0080d49a, _DAT_0080894c <= _DAT_0080d49a)))) {
    _DAT_0080cfb0 = 0;
    _DAT_0080cfb2 = 3;
    fuel_arbitrator_diag_t_0080cff8.throttle_mode = 0;
    _DAT_0080d036 = 0;
    _DAT_0080d038 = 0;
  }
  return uVar1;
}



//
// Function: memoryOperationDispatcher @ 0x0001b37a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint memoryOperationDispatcher(int param_1,undefined1 *param_2,uint param_3)

{
  undefined1 *puVar1;
  bool bVar2;
  undefined4 in_D0;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char securityCheckResult3;
  char securityCheckResult;
  char securityCheckResult2;
  undefined4 unaff_D2;
  short sVar6;
  ushort uVar7;
  undefined2 uVar8;
  
  uVar8 = (undefined2)((uint)unaff_D2 >> 0x10);
  if (0x6e4 < param_3) {
    return 2;
  }
  sVar6 = (short)param_3;
  uVar3 = addressLookupFunction
                    (CONCAT22((short)CONCAT31((int3)((uint)in_D0 >> 8),
                                              **(undefined1 **)(param_1 + 6)),uVar8));
  uVar7 = sVar6 + ((ushort)uVar3 & 0xff);
  if (uVar7 < 8) {
    uVar7 = 8;
  }
  if (uVar7 == *(ushort *)(param_1 + 4)) {
    bVar2 = false;
  }
  else {
    if (uVar7 + 10 != (uint)*(ushort *)(param_1 + 4)) {
      return 2;
    }
    bVar2 = true;
  }
  puVar1 = (undefined1 *)(*(int *)(param_1 + 6) + (uVar3 & 0xff));
  uVar4 = addressRangeValidator((uint)param_2,CONCAT22(sVar6,uVar8));
  uVar5 = uVar4 & 0xff;
  uVar3 = uVar5;
  if (uVar5 < 6) {
    uVar3 = (uint)(&switchD_0001b416::switchdataD_0001b41a)[uVar5];
    switch(uVar5) {
    case 0:
      uVar3 = memcpy(param_2,puVar1,CONCAT22(sVar6,uVar8));
      return uVar3 & 0xffffff00;
    case 3:
      if (_DAT_00803586 != 0xff) {
        if (!bVar2) {
          return 3;
        }
        securityCheckResult3 = systemSecurityCheck();
        if (securityCheckResult3 != '\0') {
          return 3;
        }
      }
      uVar3 = memcpy(param_2,puVar1,CONCAT22(sVar6,uVar8));
      return uVar3 & 0xffffff00;
    case 4:
      return 10;
    case 5:
      if ((_DAT_0080d1a4 == 1) && (_DAT_0080d19c != 0)) {
        return 7;
      }
      if (_DAT_00803586 != 0xff) {
        if (!bVar2) {
          return 3;
        }
        securityCheckResult = systemSecurityCheck();
        if (securityCheckResult != '\0') {
          return 3;
        }
      }
      if (_DAT_0080d19c == 1) {
        securityCheckResult2 = circularBufferWrite((short)((uint)puVar1 >> 0x10),sVar6);
        if (securityCheckResult2 == '\x01') {
          return 0xb;
        }
      }
      uVar3 = memcpy(param_2 + -0x7fcb08,puVar1,CONCAT22(sVar6,uVar8));
      return uVar3 & 0xffffff00;
    }
  }
  return CONCAT31((int3)(uVar3 >> 8),(char)uVar4);
}



//
// Function: FUN_0001b532 @ 0x0001b532
// ERROR: Failed to decompile
//

//
// Function: j1939DataCopyWrapper @ 0x0001b56e
//

void j1939DataCopyWrapper(int param_1)

{
  undefined4 unaff_A2;
  undefined1 local_6 [2];
  
  memcpy(local_6,(undefined1 *)(*(int *)(param_1 + 6) + 1),
         CONCAT22(2,(short)((uint)unaff_A2 >> 0x10)));
  FUN_0001b532(param_1);
  return;
}



//
// Function: j1939DataCopyWrapper2Byte @ 0x0001b5b6
//

void j1939DataCopyWrapper2Byte(int param_1)

{
  undefined4 unaff_A2;
  undefined1 *puVar1;
  undefined1 local_a [4];
  undefined1 local_6 [2];
  
  puVar1 = local_6;
  memcpy(puVar1,(undefined1 *)(*(int *)(param_1 + 6) + 1),
         CONCAT22(2,(short)((uint)unaff_A2 >> 0x10)));
  memcpy(local_a,(undefined1 *)(*(int *)(param_1 + 6) + 3),CONCAT22(4,(short)puVar1));
  FUN_0001b532(param_1);
  return;
}



//
// Function: j1939DataCopyWrapper2ByteAlt @ 0x0001b604
//

void j1939DataCopyWrapper2ByteAlt(int param_1)

{
  undefined4 unaff_A2;
  undefined1 local_6 [2];
  
  memcpy(local_6,(undefined1 *)(*(int *)(param_1 + 6) + 1),
         CONCAT22(2,(short)((uint)unaff_A2 >> 0x10)));
  FUN_0001b532(param_1);
  return;
}



//
// Function: j1939DataCopyWrapperExtended @ 0x0001b668
//

void j1939DataCopyWrapperExtended(int param_1)

{
  undefined4 unaff_A2;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 local_e [4];
  undefined1 local_a [4];
  undefined1 local_6 [2];
  
  puVar2 = local_6;
  memcpy(puVar2,(undefined1 *)(*(int *)(param_1 + 6) + 1),
         CONCAT22(2,(short)((uint)unaff_A2 >> 0x10)));
  puVar1 = local_a;
  memcpy(puVar1,(undefined1 *)(*(int *)(param_1 + 6) + 3),CONCAT22(4,(short)puVar2));
  memcpy(local_e,(undefined1 *)(*(int *)(param_1 + 6) + 7),CONCAT22(4,(short)puVar1));
  FUN_0001b532(param_1);
  return;
}



//
// Function: memoryOperationFromMessage @ 0x0001b6ce
//

void memoryOperationFromMessage(int param_1)

{
  undefined4 unaff_A2;
  uint local_c;
  undefined1 *local_8;
  
  memcpy((undefined1 *)&local_8,(undefined1 *)(*(int *)(param_1 + 6) + 1),
         CONCAT22(4,(short)((uint)unaff_A2 >> 0x10)));
  local_c = (uint)*(byte *)(*(int *)(param_1 + 6) + 5);
  memoryOperationDispatcher(param_1,local_8,local_c);
  return;
}



//
// Function: memoryOperationFromMessageExtended @ 0x0001b716
//

void memoryOperationFromMessageExtended(int param_1)

{
  undefined4 unaff_A2;
  undefined1 **ppuVar1;
  uint local_c;
  undefined1 *local_8;
  
  ppuVar1 = &local_8;
  memcpy((undefined1 *)ppuVar1,(undefined1 *)(*(int *)(param_1 + 6) + 1),
         CONCAT22(4,(short)((uint)unaff_A2 >> 0x10)));
  memcpy((undefined1 *)&local_c,(undefined1 *)(*(int *)(param_1 + 6) + 5),CONCAT22(4,(short)ppuVar1)
        );
  memoryOperationDispatcher(param_1,local_8,local_c);
  return;
}



//
// Function: systemFunction6xParameterized @ 0x0001b762
//

void systemFunction6xParameterized(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  uVar3 = 0xb56e;
  coreSystemFunction(1);
  uVar2 = 0xb56e;
  uVar1 = 0x45;
  coreSystemFunction(1,uVar3);
  coreSystemFunction(1,uVar1,uVar2);
  coreSystemFunction();
  coreSystemFunction();
  coreSystemFunction();
  return;
}



//
// Function: addressLookupFunction @ 0x0001b7ca
//

uint addressLookupFunction(undefined4 param_1)

{
  uint in_D0;
  
  if (0x40 < (byte)((uint)param_1 >> 0x10)) {
    return (uint)*(byte *)((short)(param_1._0_2_ & 0xff) + 0x1b77b);
  }
  return in_D0 & 0xffffff00;
}



//
// Function: diagnosticServiceSecurityValidator @ 0x0001b7e8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 diagnosticServiceSecurityValidator(int param_1)

{
  byte bVar1;
  undefined3 extraout_var;
  char securityCheckResult;
  undefined4 in_D0;
  char cVar2;
  char cVar3;
  
  bVar1 = **(byte **)(param_1 + 6);
  cVar2 = *(char *)(param_1 + 5);
  if (0x17 < bVar1) {
    return CONCAT31((int3)((uint)in_D0 >> 8),0xff);
  }
  if ((bVar1 == 3) || (bVar1 == 4)) {
    cVar3 = '\x03';
  }
  else {
    cVar3 = '\x01';
  }
  if ((('\x01' << (bVar1 & 7) & *(byte *)(((int)(uint)bVar1 >> 3) + 0x8084ba)) == 0) ||
     (_DAT_00803586 != -0x4ade)) {
    if ((cVar2 != '\b') && (cVar2 != (char)(cVar3 + '\n'))) {
      return 2;
    }
    return 0xff;
  }
  if ((char)(cVar3 + '\n') != cVar2) {
    return 2;
  }
  cVar2 = systemSecurityCheck();
  if (cVar2 == '\0') {
    return CONCAT31(extraout_var,0xff);
  }
  return 3;
}



//
// Function: diagnosticGroupPositionBufferStore @ 0x0001b8b8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticGroupPositionBufferStore(undefined4 param_1)

{
  ushort uVar1;
  uint uVar2;
  byte bVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  
  uVar1 = _DAT_00805574 + 1;
  uVar2 = (uint)_DAT_00805574;
  _DAT_00805574 = uVar1;
  if (4 < uVar1) {
    _DAT_00805574 = 0;
  }
  if (param_1._1_1_ == '\0') {
    puVar5 = (undefined2 *)&DAT_0080553a;
  }
  else {
    puVar5 = (undefined2 *)&DAT_00805554;
  }
  bVar3 = 0;
  puVar4 = (undefined2 *)(uVar2 * 0x18 + 0x8054c0);
  do {
    *puVar4 = *puVar5;
    bVar3 = bVar3 + 1;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  } while (bVar3 < 0xc);
  return;
}



//
// Function: diagnosticGroupSnapshotCapture @ 0x0001b916
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticGroupSnapshotCapture(undefined4 param_1)

{
  if (param_1._1_1_ == '\0') {
    _DAT_0080556c = 1;
    _DAT_00805570 = fuel_arbitrator_diag_t_0080cff8.fuel_mode;
    DAT_0080553a = 0;
    DAT_0080553b = (undefined1)fuel_arbitrator_diag_t_0080cff8.limited_value;
    _DAT_0080553c = fuel_arbitrator_diag_t_0080cff8.fuel_mode;
    _DAT_0080553e = 1;
    _DAT_00805540 = fuel_arbitrator_diag_t_0080cff8.rpm_target;
    _DAT_00805542 = 0;
    _DAT_00805544 = 0;
    _DAT_00805546 = 0;
    _DAT_00805548 = 0;
    _DAT_0080554a = _DAT_0080d4c4;
    _DAT_0080554e = 0;
    return;
  }
  _DAT_0080556e = 1;
  _DAT_00805572 = _DAT_0080cfaa;
  DAT_00805554 = 1;
  DAT_00805555 = DAT_0080cfad;
  _DAT_00805556 = _DAT_0080cfaa;
  _DAT_00805558 = 1;
  _DAT_0080555a = _DAT_0080cfa8;
  _DAT_0080555c = 0;
  _DAT_0080555e = 0;
  _DAT_00805560 = 0;
  _DAT_00805562 = 0;
  _DAT_00805564 = _DAT_0080d4c4;
  _DAT_00805568 = 0;
  return;
}



//
// Function: memoryRegisterController @ 0x0001b9da
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint memoryRegisterController(void)

{
  undefined2 uVar1;
  undefined4 in_D0;
  uint uVar2;
  undefined4 unaff_A2;
  undefined2 *puVar3;
  ushort uVar4;
  
  uVar4 = (ushort)((uint)unaff_A2 >> 0x10);
  uVar1 = (undefined2)((uint)in_D0 >> 0x10);
  uVar2 = CONCAT22(uVar1,engine_control_flags_t_008035d6.protection_system) & 0xffff0800;
  if ((engine_control_flags_t_008035d6.protection_system & 0x800) != 0) {
    uVar2 = CONCAT22(uVar1,fuel_arbitrator_diag_t_0080cff8.rpm_target);
    if (((fuel_arbitrator_diag_t_0080cff8.rpm_target != _DAT_008007ac) ||
        (uVar2 = CONCAT22(uVar1,fuel_arbitrator_diag_t_0080cff8._28_2_),
        fuel_arbitrator_diag_t_0080cff8._28_2_ != _DAT_008007b0)) ||
       (uVar2 = CONCAT31((int3)(uVar2 >> 8),(char)fuel_arbitrator_diag_t_0080cff8.limited_value),
       (char)fuel_arbitrator_diag_t_0080cff8.limited_value != DAT_008007b2)) {
      if (fuel_arbitrator_diag_t_0080cff8.rpm_target == 0) {
        if ((_DAT_008007ac != 0) && (_DAT_008007b0 == 1)) {
          _DAT_0080556c = 0;
          _DAT_0080554e = _DAT_0080d4c4 - _DAT_0080554a;
          uVar2 = diagnosticGroupPositionBufferStore((uint)uVar4);
        }
      }
      else if (fuel_arbitrator_diag_t_0080cff8._28_2_ == 1) {
        if (_DAT_0080556c == 1) {
          if ((char)fuel_arbitrator_diag_t_0080cff8.limited_value == DAT_008007b2) {
            if (_DAT_0080553e < 5) {
              uVar2 = (uint)_DAT_0080553e;
              _DAT_0080553e = _DAT_0080553e + 1;
              *(word *)(&DAT_00805540 + uVar2 * 2) = fuel_arbitrator_diag_t_0080cff8.rpm_target;
            }
            else {
              uVar2 = 0;
              for (puVar3 = (undefined2 *)&DAT_00805540; puVar3 < &DAT_00805548; puVar3 = puVar3 + 1
                  ) {
                *puVar3 = puVar3[1];
              }
              _DAT_00805548 = fuel_arbitrator_diag_t_0080cff8.rpm_target;
            }
          }
          else {
            _DAT_0080554e = _DAT_0080d4c4 - _DAT_0080554a;
            diagnosticGroupPositionBufferStore((uint)uVar4);
            uVar2 = diagnosticGroupSnapshotCapture((uint)uVar4);
          }
        }
        else {
          uVar2 = diagnosticGroupSnapshotCapture((uint)uVar4);
        }
      }
      else if (_DAT_008007b0 == 1) {
        _DAT_0080556c = 0;
        uVar2 = diagnosticGroupPositionBufferStore((uint)uVar4);
      }
    }
    _DAT_008007ac = fuel_arbitrator_diag_t_0080cff8.rpm_target;
    _DAT_008007b0 = fuel_arbitrator_diag_t_0080cff8._28_2_;
    DAT_008007b2 = (char)fuel_arbitrator_diag_t_0080cff8.limited_value;
    uVar2 = CONCAT22((short)(uVar2 >> 0x10),_DAT_0080cfa8);
    if ((_DAT_0080cfa8 != _DAT_008007ae) || (uVar2 = (uint)_DAT_0080cfac, uVar2 != DAT_008007b3)) {
      if (_DAT_0080cfa8 == 0) {
        if (_DAT_008007ae != 0) {
          _DAT_0080556e = 0;
          _DAT_00805568 = _DAT_0080d4c4 - _DAT_00805564;
          uVar2 = diagnosticGroupPositionBufferStore(CONCAT22(1,uVar4));
        }
      }
      else if (_DAT_0080556e == 1) {
        if (_DAT_0080cfac == DAT_008007b3) {
          if (_DAT_00805558 < 5) {
            uVar2 = (uint)_DAT_00805558;
            _DAT_00805558 = _DAT_00805558 + 1;
            *(short *)(&DAT_0080555a + uVar2 * 2) = _DAT_0080cfa8;
          }
          else {
            uVar2 = 0xe;
            for (puVar3 = (undefined2 *)&DAT_0080555a; puVar3 < &DAT_00805562; puVar3 = puVar3 + 1)
            {
              *puVar3 = puVar3[1];
            }
            _DAT_00805562 = _DAT_0080cfa8;
          }
        }
        else {
          _DAT_00805568 = _DAT_0080d4c4 - _DAT_00805564;
          diagnosticGroupPositionBufferStore(CONCAT22(1,uVar4));
          uVar2 = diagnosticGroupSnapshotCapture(CONCAT22(1,uVar4));
        }
      }
      else {
        uVar2 = diagnosticGroupSnapshotCapture(CONCAT22(1,uVar4));
      }
    }
    _DAT_008007ae = _DAT_0080cfa8;
    DAT_008007b3 = DAT_0080cfad;
  }
  return uVar2;
}



//
// Function: byteSwap32 @ 0x0001bc1e
//

undefined4 byteSwap32(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined2 uVar2;
  undefined4 local_8;
  
  uVar1 = *param_1;
  local_8._3_1_ = (undefined1)uVar1;
  local_8._0_1_ = (undefined1)((uint)uVar1 >> 0x18);
  local_8._1_1_ = (undefined1)((uint)uVar1 >> 0x10);
  local_8._2_1_ = (undefined1)((uint)uVar1 >> 8);
  uVar2 = CONCAT11((undefined1)local_8,local_8._2_1_);
  local_8 = CONCAT22(uVar2,CONCAT11(local_8._1_1_,local_8._0_1_));
  return local_8;
}



//
// Function: byteSwap16 @ 0x0001bc52
//

undefined2 byteSwap16(undefined2 *param_1)

{
  undefined2 local_6;
  
  local_6._1_1_ = (undefined1)*param_1;
  local_6._0_1_ = (undefined1)((ushort)*param_1 >> 8);
  local_6 = CONCAT11((undefined1)local_6,local_6._0_1_);
  return local_6;
}



//
// Function: ioControlBitMapper @ 0x0001bc74
//

uint ioControlBitMapper(void)

{
  uint in_D0;
  uint uVar1;
  
  uVar1 = in_D0 & 0xffffff00;
  if ((DAT_0080bdee & 0x10) != 0) {
    uVar1 = 0x40;
  }
  if ((DAT_0080bdee & 2) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  if ((DAT_0080bdee & 0x40) != 0) {
    uVar1 = uVar1 | 4;
  }
  return uVar1;
}



//
// Function: canDiagnosticResponseSender @ 0x0001bc9c
//

undefined4 canDiagnosticResponseSender(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  char cVar4;
  undefined4 uVar3;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  uint local_12;
  undefined2 local_e;
  undefined1 *local_c;
  
  uVar1 = *(undefined1 *)(*(int *)(param_1 + 6) + 1);
  uVar2 = *(undefined1 *)(*(int *)(param_1 + 6) + 2);
  cVar4 = FUN_0000eaf0();
  if (cVar4 == '\0') {
    local_12 = CONCAT31(CONCAT21((short)(CONCAT13(*param_1,0xef0000) >> 0x10),param_1[3]),param_1[2]
                       ) & 0x1cffffff;
    local_e = 7;
    local_1a = 0x42;
    local_19 = uVar1;
    local_18 = uVar2;
    local_c = &local_1a;
    uVar3 = sendCanSingleFrame(local_12,(short)((uint)&local_1a >> 0x10));
    uVar3 = CONCAT31((int3)((uint)uVar3 >> 8),0xff);
  }
  else {
    uVar3 = 8;
  }
  return uVar3;
}



//
// Function: systemFunction1xCaller @ 0x0001bd58
//

void systemFunction1xCaller(void)

{
  coreSystemFunction();
  return;
}



//
// Function: diagMemoryReadResponseBuilder @ 0x0001bd76
//

undefined4 diagMemoryReadResponseBuilder(byte *param_1,undefined1 *param_2,uint param_3)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  undefined3 uVar4;
  undefined4 in_D0;
  uint uVar5;
  undefined4 uVar6;
  undefined2 uVar7;
  j1939_header_t *msg_header;
  undefined4 unaff_D2;
  byte bVar8;
  undefined1 uVar9;
  ushort uVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined2 uVar13;
  
  uVar13 = (undefined2)((uint)unaff_D2 >> 0x10);
  cVar2 = **(char **)(param_1 + 6);
  if (0x6e4 < param_3) {
    return 2;
  }
  uVar5 = addressLookupFunction(CONCAT22((short)CONCAT31((int3)((uint)in_D0 >> 8),cVar2),uVar13));
  bVar8 = (byte)uVar5;
  if (bVar8 < 8) {
    bVar8 = 8;
  }
  if (((ushort)bVar8 != *(ushort *)(param_1 + 4)) &&
     ((ushort)(bVar8 + 10) != *(short *)(param_1 + 4))) {
    return 2;
  }
  uVar10 = (ushort)param_3;
  uVar6 = addressRangeValidator((uint)param_2,CONCAT22(uVar10,uVar13));
  uVar4 = (undefined3)((uint)uVar6 >> 8);
  if (((char)uVar6 == '\n') || ((char)uVar6 == '\t')) {
    return uVar6;
  }
  if ((cVar2 == 'C') && (uVar10 < 0x100)) {
    uVar9 = 0x44;
    *(undefined1 *)(*(int *)(param_1 + 6) + 3) = *(undefined1 *)(*(int *)(param_1 + 6) + 6);
  }
  else {
    uVar4 = 0;
    uVar9 = (&DAT_0001bd6c)[(short)(ushort)(byte)(cVar2 + 0xbd)];
  }
  uVar7 = (undefined2)CONCAT31(uVar4,uVar9);
  uVar5 = addressLookupFunction(CONCAT22(uVar7,uVar13));
  bVar8 = (char)uVar5 - 1;
  msg_header = (j1939_header_t *)multiPacketBufferAllocator(CONCAT22(uVar10 + bVar8 + 1,uVar7));
  if (msg_header == (j1939_header_t *)0x0) {
    return 4;
  }
  puVar12 = (undefined1 *)msg_header[1].id;
  msg_header->id = 0xef0000;
  bVar3 = *param_1;
  *(byte *)&msg_header->id = *(byte *)&msg_header->id & 0xe3;
  *(byte *)&msg_header->id = bVar3 & 0x1c | *(byte *)&msg_header->id;
  *(byte *)((int)&msg_header->id + 2) = param_1[3];
  *(byte *)((int)&msg_header->id + 3) = param_1[2];
  iVar1 = *(int *)(param_1 + 6);
  puVar11 = puVar12 + 1;
  *puVar12 = uVar9;
  puVar12 = puVar11;
  memcpy(puVar11,(undefined1 *)(iVar1 + 1),(uint)CONCAT12(bVar8,uVar13));
  if ((undefined1 *)0xffffff < param_2) {
    param_2 = param_2 + -0x7fcb08;
  }
  memcpy(puVar11 + bVar8,param_2,CONCAT22(uVar10,(short)((uint)puVar12 >> 0x10)));
  uVar6 = sendCanMessage(msg_header);
  return CONCAT31((int3)((uint)uVar6 >> 8),0xff);
}



//
// Function: diagMemoryReadWithOffsetBuilder @ 0x0001bedc
// ERROR: Failed to decompile
//

//
// Function: diagMemoryReadService43Handler @ 0x0001bf18
//

void diagMemoryReadService43Handler(int param_1)

{
  undefined4 unaff_A2;
  undefined1 *puVar1;
  undefined1 local_a [4];
  undefined1 local_6 [2];
  
  puVar1 = local_6;
  memcpy(puVar1,(undefined1 *)(*(int *)(param_1 + 6) + 1),
         CONCAT22(2,(short)((uint)unaff_A2 >> 0x10)));
  memcpy(local_a,(undefined1 *)(*(int *)(param_1 + 6) + 3),CONCAT22(4,(short)puVar1));
  diagMemoryReadWithOffsetBuilder(param_1);
  return;
}



//
// Function: diagMemoryReadService46Handler @ 0x0001bf64
//

void diagMemoryReadService46Handler(int param_1)

{
  undefined4 unaff_A2;
  undefined1 local_6 [2];
  
  memcpy(local_6,(undefined1 *)(*(int *)(param_1 + 6) + 1),
         CONCAT22(2,(short)((uint)unaff_A2 >> 0x10)));
  diagMemoryReadWithOffsetBuilder(param_1);
  return;
}



//
// Function: diagMemoryReadService48Handler @ 0x0001bfc8
//

void diagMemoryReadService48Handler(int param_1)

{
  undefined4 unaff_A2;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 local_e [4];
  undefined1 local_a [4];
  undefined1 local_6 [2];
  
  puVar2 = local_6;
  memcpy(puVar2,(undefined1 *)(*(int *)(param_1 + 6) + 1),
         CONCAT22(2,(short)((uint)unaff_A2 >> 0x10)));
  puVar1 = local_a;
  memcpy(puVar1,(undefined1 *)(*(int *)(param_1 + 6) + 3),CONCAT22(4,(short)puVar2));
  memcpy(local_e,(undefined1 *)(*(int *)(param_1 + 6) + 7),CONCAT22(4,(short)puVar1));
  diagMemoryReadWithOffsetBuilder(param_1);
  return;
}



//
// Function: diagMemoryReadService4aHandler @ 0x0001c02e
//

void diagMemoryReadService4aHandler(byte *param_1)

{
  undefined4 unaff_A2;
  uint local_c;
  undefined1 *local_8;
  
  memcpy((undefined1 *)&local_8,(undefined1 *)(*(int *)(param_1 + 6) + 1),
         CONCAT22(4,(short)((uint)unaff_A2 >> 0x10)));
  local_c = (uint)*(byte *)(*(int *)(param_1 + 6) + 5);
  diagMemoryReadResponseBuilder(param_1,local_8,local_c);
  return;
}



//
// Function: diagMemoryReadService4cHandler @ 0x0001c076
//

void diagMemoryReadService4cHandler(byte *param_1)

{
  undefined4 unaff_A2;
  undefined1 **ppuVar1;
  uint local_c;
  undefined1 *local_8;
  
  ppuVar1 = &local_8;
  memcpy((undefined1 *)ppuVar1,(undefined1 *)(*(int *)(param_1 + 6) + 1),
         CONCAT22(4,(short)((uint)unaff_A2 >> 0x10)));
  memcpy((undefined1 *)&local_c,(undefined1 *)(*(int *)(param_1 + 6) + 5),CONCAT22(4,(short)ppuVar1)
        );
  diagMemoryReadResponseBuilder(param_1,local_8,local_c);
  return;
}



//
// Function: registerDiagnosticMemoryServices @ 0x0001c0c2
//

void registerDiagnosticMemoryServices(void)

{
  coreSystemFunction();
  coreSystemFunction();
  coreSystemFunction();
  coreSystemFunction();
  coreSystemFunction();
  return;
}



//
// Function: sendJ1939MultiFrame @ 0x0001c10e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sendJ1939MultiFrame(uint *param_1)

{
  undefined1 *puVar1;
  undefined2 uVar2;
  byte bVar3;
  ushort uVar4;
  word wVar5;
  byte *pbVar6;
  byte *pbVar7;
  char *pcVar8;
  byte local_8;
  byte bStack_7;
  byte bStack_5;
  
  pbVar6 = diag_tp_state_t_00800f34.tx_cm_buf;
  bVar3 = *(byte *)((int)param_1 + 1);
  uVar4 = *(ushort *)((int)param_1 + 1);
  bStack_5 = (byte)uVar4;
  if ((bVar3 < 0xf0) && (bStack_5 != 0xff)) {
    if (diag_tp_state_t_00800f34.diag_state == 0) {
      diag_tp_state_t_00800f34.diag_state = 1;
      diag_tp_state_t_00800f34.expected_id_low = bStack_5;
      diag_tp_state_t_00800f34.expected_guard = uVar4 & 0xff00;
      diag_tp_state_t_00800f34.total_bytes = *(word *)(param_1 + 1);
      diag_tp_state_t_00800f34.total_packets =
           (char)((int)(diag_tp_state_t_00800f34.total_bytes - 1) / 7) + 1;
      diag_tp_state_t_00800f34.req_count = 0;
      diag_tp_state_t_00800f34.src_data_ptr = *(byte **)((int)param_1 + 6);
      diag_tp_state_t_00800f34.tx_header_id = *param_1 & 0xff00ffff | 0xec0000;
      diag_tp_state_t_00800f34.tx_length = 8;
      diag_tp_state_t_00800f34.status_code = 0;
      diag_tp_state_t_00800f34.reserved_0x47 = 0x37;
      diag_tp_state_t_00800f34.resp_byte_ptr = *(byte **)((int)param_1 + 10);
      pbVar7 = diag_tp_state_t_00800f34.tx_cm_buf + 1;
      *diag_tp_state_t_00800f34.tx_cm_buf = 0x10;
      wVar5 = diag_tp_state_t_00800f34.total_bytes;
      bStack_7 = (byte)diag_tp_state_t_00800f34.total_bytes;
      *pbVar7 = bStack_7;
      local_8 = (byte)(wVar5 >> 8);
      pbVar6[2] = local_8;
      pbVar6[3] = diag_tp_state_t_00800f34.total_packets;
      pbVar6[4] = 0xff;
      pbVar6[5] = 0;
      pbVar6[6] = bVar3;
      pbVar6[7] = 0;
      sendCanSingleFrame(diag_tp_state_t_00800f34.tx_header_id);
      if (diag_tp_state_t_00800f34.pre_status == 0) {
        *diag_tp_state_t_00800f34.resp_byte_ptr = 0x12;
        diag_tp_state_t_00800f34.tx_header_id = *param_1 & 0xff00ffff | 0xeb0000;
      }
      else {
        *diag_tp_state_t_00800f34.resp_byte_ptr = diag_tp_state_t_00800f34.pre_status;
        diag_tp_state_t_00800f34.diag_state = 0;
      }
    }
    else {
      **(undefined1 **)((int)param_1 + 10) = 8;
    }
  }
  else {
    if ((byte)*param_1 == _DAT_0080cfc2) {
      pcVar8 = &DAT_00800ee4;
    }
    else {
      if ((byte)*param_1 != _DAT_0080cfcc) {
        **(undefined1 **)((int)param_1 + 10) = 3;
        return;
      }
      pcVar8 = &DAT_00800f04;
    }
    if (*pcVar8 == '\x01') {
      **(undefined1 **)((int)param_1 + 10) = 2;
    }
    else {
      *pcVar8 = '\x01';
      *(undefined2 *)(pcVar8 + 2) = *(undefined2 *)(param_1 + 1);
      pcVar8[1] = (char)((int)(*(ushort *)(pcVar8 + 2) - 1) / 7) + '\x01';
      pcVar8[6] = '\x01';
      pcVar8[4] = '\0';
      pcVar8[5] = '\x01';
      *(undefined4 *)(pcVar8 + 8) = *(undefined4 *)((int)param_1 + 6);
      *(uint *)(pcVar8 + 0x12) = *param_1 & 0xff0000ff | 0xecff00;
      pcVar8[0x16] = '\0';
      pcVar8[0x17] = '\b';
      pcVar8[0x10] = '\0';
      pcVar8[0x11] = '\x05';
      *(undefined4 *)(pcVar8 + 0xc) = *(undefined4 *)((int)param_1 + 10);
      puVar1 = *(undefined1 **)(pcVar8 + 0x18);
      *puVar1 = 0x20;
      uVar2 = *(undefined2 *)(pcVar8 + 2);
      bStack_7 = (byte)uVar2;
      puVar1[1] = bStack_7;
      local_8 = (byte)((ushort)uVar2 >> 8);
      puVar1[2] = local_8;
      puVar1[3] = pcVar8[1];
      puVar1[4] = 0xff;
      puVar1[5] = bStack_5;
      puVar1[6] = bVar3;
      puVar1[7] = 0;
      sendCanSingleFrame(*(undefined4 *)(pcVar8 + 0x12));
      if (pcVar8[7] == '\0') {
        **(char **)(pcVar8 + 0xc) = '\x10';
        *(uint *)(pcVar8 + 0x12) = *param_1 & 0xff0000ff | 0xebff00;
      }
      else {
        **(char **)(pcVar8 + 0xc) = pcVar8[7];
        *pcVar8 = '\0';
      }
    }
  }
  return;
}



//
// Function: diagnosticParamRequestHandler @ 0x0001c33e
//

void diagnosticParamRequestHandler(can_std_rx_desc_t *rx_msg)

{
  byte bVar1;
  byte bVar2;
  word local_6;
  
  bVar1 = rx_msg->data_ptr[2];
  local_6 = (ushort)rx_msg->data_ptr[6] << 8;
  if ((((diag_tp_state_t_00800f34.diag_state == 1) &&
       ((byte)rx_msg->id == diag_tp_state_t_00800f34.expected_id_low)) &&
      (bVar1 <= diag_tp_state_t_00800f34.total_packets)) &&
     (local_6 == diag_tp_state_t_00800f34.expected_guard)) {
    bVar2 = rx_msg->data_ptr[1];
    if (bVar2 == 0) {
      diag_tp_state_t_00800f34.status_code = 0;
      diag_tp_state_t_00800f34.reserved_0x47 = 0x37;
    }
    else {
      diag_tp_state_t_00800f34.req_start = bVar1;
      diag_tp_state_t_00800f34.req_count = bVar2;
      if ((int)(uint)diag_tp_state_t_00800f34.total_packets < (int)((uint)bVar2 + (uint)bVar1 + -1))
      {
        diag_tp_state_t_00800f34.req_count = (diag_tp_state_t_00800f34.total_packets - bVar1) + 1;
      }
    }
  }
  return;
}



//
// Function: messageErrorHandler @ 0x0001c3d2
//

void messageErrorHandler(undefined4 param_1)

{
  undefined1 *puVar1;
  byte bVar2;
  undefined1 *puVar3;
  undefined1 local_1e;
  undefined1 uStack_1c;
  undefined1 auStack_1b [9];
  undefined4 local_12;
  undefined2 local_e;
  undefined1 *local_c;
  
  local_12 = CONCAT31(CONCAT21(0x18ec,param_1._1_1_),DAT_0080cfc3);
  local_e = 8;
  local_c = &uStack_1c;
  uStack_1c = 0xff;
  bVar2 = 0;
  puVar1 = auStack_1b;
  do {
    puVar3 = puVar1;
    *puVar3 = 0xff;
    bVar2 = bVar2 + 1;
    puVar1 = puVar3 + 1;
  } while (bVar2 < 4);
  puVar3[1] = 0;
  local_1e = (undefined1)((uint)param_1 >> 8);
  puVar3[2] = local_1e;
  puVar3[3] = 0;
  sendCanSingleFrame(local_12);
  return;
}



//
// Function: vp44CanFrameBuilder @ 0x0001c440
//

void vp44CanFrameBuilder(undefined4 param_1)

{
  undefined1 local_20;
  undefined1 uStack_1f;
  undefined1 local_1e;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  byte bStack_19;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined1 local_15;
  undefined4 local_12;
  undefined2 local_e;
  undefined1 *local_c;
  
  local_12 = CONCAT31(CONCAT21(0x18ec,param_1._1_1_),DAT_0080cfc3);
  local_e = 8;
  local_c = &uStack_1c;
  uStack_1c = 0x13;
  uStack_1f = (undefined1)vp44_message_t_00800f5f.additional_data;
  uStack_1b = uStack_1f;
  local_20 = (undefined1)(vp44_message_t_00800f5f.additional_data >> 8);
  uStack_1a = local_20;
  bStack_19 = vp44_message_t_00800f5f.sequence_number;
  uStack_18 = 0xff;
  uStack_17 = 0;
  local_1e = (undefined1)((uint)param_1 >> 8);
  uStack_16 = local_1e;
  local_15 = 0;
  sendCanSingleFrame(local_12);
  return;
}



//
// Function: vp44MessageTransmitter @ 0x0001c4c0
//

undefined1 vp44MessageTransmitter(undefined4 param_1,undefined2 param_2)

{
  undefined1 local_1e;
  undefined1 auStack_1c [2];
  undefined1 uStack_1a;
  undefined1 uStack_19;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined1 local_15;
  undefined1 local_13;
  undefined4 local_12;
  undefined2 local_e;
  undefined1 *local_c;
  
  local_12 = CONCAT31(CONCAT21(0x18ec,param_1._1_1_),DAT_0080cfc3);
  local_e = 8;
  local_c = auStack_1c;
  auStack_1c[0] = 0x11;
  uStack_1a = (undefined1)param_1;
  uStack_19 = 0xff;
  uStack_18 = 0xff;
  uStack_17 = 0;
  local_1e = (undefined1)((ushort)param_2 >> 8);
  uStack_16 = local_1e;
  local_15 = 0;
  sendCanSingleFrame(local_12);
  return local_13;
}



//
// Function: vp44FuelTempHandler @ 0x0001c538
//

void vp44FuelTempHandler(can_std_rx_desc_t *rx_msg)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  undefined1 extraout_var;
  undefined2 in_D0w;
  char cVar5;
  undefined2 local_8;
  word local_6;
  
  pbVar1 = rx_msg->data_ptr;
  bVar2 = pbVar1[6];
  local_6 = (ushort)bVar2 << 8;
  bVar3 = (byte)rx_msg->id;
  local_8 = CONCAT11(pbVar1[2],pbVar1[1]);
  uVar4 = (undefined1)((ushort)in_D0w >> 8);
  if ((((DAT_00800f5e == '\x01') && (bVar3 != vp44_message_t_00800f5f.expected_sequence)) ||
      (bVar2 != 0xef)) || (0x6a4 < local_8)) {
    messageErrorHandler((uint)CONCAT21(CONCAT11(uVar4,bVar3),bVar2) << 8);
  }
  else {
    DAT_00800f5e = '\x01';
    vp44_message_t_00800f5f._7_4_ = rx_msg->id;
    vp44_message_t_00800f5f.message_id = local_6;
    vp44_message_t_00800f5f.sequence_number = pbVar1[3];
    vp44_message_t_00800f5f.additional_data = local_8;
                    /* Constant: VP44_FUEL_TEMP_OFFSET = 112 */
    vp44_message_t_00800f5f._5_2_ = 0x70;
    vp44_message_t_00800f5f.retry_flag = 1;
    vp44_message_t_00800f5f.retry_count = vp44_message_t_00800f5f.sequence_number;
    if (5 < vp44_message_t_00800f5f.sequence_number) {
      vp44_message_t_00800f5f.retry_count = 5;
    }
    cVar5 = vp44MessageTransmitter(CONCAT22(CONCAT11(uVar4,bVar3),CONCAT11(uVar4,1)),0xef00);
    if (cVar5 != '\0') {
      messageErrorHandler(CONCAT22(CONCAT11(extraout_var,bVar3),vp44_message_t_00800f5f.message_id))
      ;
      DAT_00800f5e = '\0';
    }
  }
  return;
}



//
// Function: vp44MultiFrameResponseHandler @ 0x0001c60e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44MultiFrameResponseHandler(int param_1)

{
  byte bVar1;
  byte bVar2;
  undefined1 *puVar3;
  undefined3 uVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 in_D0;
  char cVar6;
  int iVar5;
  byte bVar7;
  byte bVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  
  if (((*(short *)(param_1 + 4) == 8) && (bVar2 = *(byte *)(param_1 + 3), DAT_00800f5e == '\x01'))
     && (bVar2 == vp44_message_t_00800f5f.expected_sequence)) {
    bVar1 = **(byte **)(param_1 + 6);
    if (bVar1 == vp44_message_t_00800f5f.retry_flag) {
      if (bVar1 == vp44_message_t_00800f5f.sequence_number) {
        bVar8 = (char)vp44_message_t_00800f5f.additional_data + bVar1 * -7 + 7;
      }
      else {
        bVar8 = 7;
      }
      puVar10 = *(undefined1 **)(param_1 + 6);
      puVar3 = (undefined1 *)(_DAT_00800f6c + (uint)bVar1 * 7 + -7);
      puVar9 = puVar3;
      for (bVar7 = 0; puVar10 = puVar10 + 1, bVar7 < bVar8; bVar7 = bVar7 + 1) {
        *puVar9 = *puVar10;
        puVar9 = puVar9 + 1;
      }
      vp44_message_t_00800f5f.retry_flag = vp44_message_t_00800f5f.retry_flag + 1;
      vp44_message_t_00800f5f.retry_count = vp44_message_t_00800f5f.retry_count - 1;
      if (vp44_message_t_00800f5f.retry_count == 0) {
        if (bVar1 == vp44_message_t_00800f5f.sequence_number) {
          vp44CanFrameBuilder(CONCAT22((short)CONCAT31((int3)((uint)puVar3 >> 8),bVar2),
                                       vp44_message_t_00800f5f.message_id));
          DAT_00800f5e = 0;
          _DAT_00800f6c = 0x800f78;
          diagnosticServiceDispatcher((byte *)((int)&vp44_message_t_00800f5f.message_data + 1));
          return;
        }
        iVar5 = ((uint)vp44_message_t_00800f5f.sequence_number -
                (uint)vp44_message_t_00800f5f.retry_flag) + 1;
        if (iVar5 < 6) {
          vp44_message_t_00800f5f.retry_count =
               (vp44_message_t_00800f5f.sequence_number - vp44_message_t_00800f5f.retry_flag) + 1;
          iVar5 = CONCAT31((int3)((uint)iVar5 >> 8),vp44_message_t_00800f5f.retry_count);
        }
        else {
          vp44_message_t_00800f5f.retry_count = 5;
        }
        uVar4 = (undefined3)((uint)iVar5 >> 8);
        cVar6 = vp44MessageTransmitter
                          (CONCAT22((short)CONCAT31(uVar4,bVar2),
                                    (short)CONCAT31(uVar4,vp44_message_t_00800f5f.retry_flag)),
                           vp44_message_t_00800f5f.message_id);
        if (cVar6 != '\0') {
          messageErrorHandler(CONCAT22((short)CONCAT31(extraout_var_00,bVar2),
                                       vp44_message_t_00800f5f.message_id));
          DAT_00800f5e = 0;
          return;
        }
      }
      else {
        vp44_message_t_00800f5f._5_2_ = 0x19;
      }
    }
    else {
      uVar4 = (undefined3)((uint)in_D0 >> 8);
      cVar6 = vp44MessageTransmitter
                        (CONCAT22((short)CONCAT31(uVar4,bVar2),
                                  (short)CONCAT31(uVar4,vp44_message_t_00800f5f.retry_flag)),
                         vp44_message_t_00800f5f.message_id);
      if (cVar6 != '\0') {
        messageErrorHandler(CONCAT22((short)CONCAT31(extraout_var,bVar2),
                                     vp44_message_t_00800f5f.message_id));
        DAT_00800f5e = 0;
        return;
      }
    }
  }
  return;
}



//
// Function: diagnosticStatusRequestHandler @ 0x0001c776
//

void diagnosticStatusRequestHandler(can_std_rx_desc_t *rx_msg)

{
  word local_6;
  
  if ((diag_tp_state_t_00800f34.diag_state == 1) &&
     (diag_tp_state_t_00800f34.expected_id_low == (byte)rx_msg->id)) {
    local_6 = (ushort)rx_msg->data_ptr[6] << 8;
    if (local_6 == diag_tp_state_t_00800f34.expected_guard) {
      *diag_tp_state_t_00800f34.resp_byte_ptr = 9;
      diag_tp_state_t_00800f34.diag_state = 0;
    }
  }
  return;
}



//
// Function: diagnosticErrorHandler @ 0x0001c7ca
//

void diagnosticErrorHandler(can_std_rx_desc_t *rx_msg)

{
  byte bVar1;
  word local_6;
  
  local_6 = (ushort)rx_msg->data_ptr[6] << 8;
  bVar1 = (byte)rx_msg->id;
  if (((diag_tp_state_t_00800f34.diag_state == 1) &&
      (bVar1 == diag_tp_state_t_00800f34.expected_id_low)) &&
     (local_6 == diag_tp_state_t_00800f34.expected_guard)) {
    *diag_tp_state_t_00800f34.resp_byte_ptr = 10;
    diag_tp_state_t_00800f34.diag_state = 0;
  }
  else if (((DAT_00800f5e == '\x01') && (bVar1 == vp44_message_t_00800f5f.expected_sequence)) &&
          (local_6 == vp44_message_t_00800f5f.message_id)) {
    DAT_00800f5e = '\0';
  }
  return;
}



//
// Function: vp44CanMessageDispatcher @ 0x0001c846
//

void vp44CanMessageDispatcher(can_std_rx_desc_t *rx_msg)

{
  byte bVar1;
  
  if (rx_msg->length == 8) {
    bVar1 = *rx_msg->data_ptr;
                    /* Constant: CAN_MSG_ALT_HANDLER = 17 */
    if (bVar1 == 0x11) {
      diagnosticParamRequestHandler(rx_msg);
      return;
    }
                    /* Constant: CAN_MSG_VP44_FUEL = 16 */
    if (bVar1 == 0x10) {
      vp44FuelTempHandler(rx_msg);
      return;
    }
    if (bVar1 == 0x13) {
      diagnosticStatusRequestHandler(rx_msg);
      return;
    }
                    /* Constant: CAN_MSG_ERROR_DEFAULT = 255 */
    if (bVar1 != 0xff) {
      return;
    }
    diagnosticErrorHandler(rx_msg);
  }
  return;
}



//
// Function: diagnosticParamRequestHandlerWrapper @ 0x0001c87e
//

void diagnosticParamRequestHandlerWrapper(void)

{
  can_std_rx_desc_t *unaff_A2;
  
  diagnosticParamRequestHandler(unaff_A2);
  return;
}



//
// Function: vp44FuelTempHandlerWrapper @ 0x0001c88c
//

void vp44FuelTempHandlerWrapper(void)

{
  can_std_rx_desc_t *unaff_A2;
  
  vp44FuelTempHandler(unaff_A2);
  return;
}



//
// Function: diagnosticStatusRequestHandlerWrapper @ 0x0001c89a
//

void diagnosticStatusRequestHandlerWrapper(void)

{
  can_std_rx_desc_t *unaff_A2;
  
  diagnosticStatusRequestHandler(unaff_A2);
  return;
}



//
// Function: diagnosticErrorHandlerWrapper @ 0x0001c8a8
//

void diagnosticErrorHandlerWrapper(void)

{
  can_std_rx_desc_t *unaff_A2;
  
  diagnosticErrorHandler(unaff_A2);
  return;
}



//
// Function: unknownMessageHandler @ 0x0001c8b6
//

void unknownMessageHandler(uint param_1)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  byte bVar4;
  byte bVar5;
  char *pcVar6;
  undefined1 *puVar7;
  
  iVar3 = (param_1 >> 0x10 & 0xff) * 0x20;
  pcVar6 = &DAT_00800ee4 + iVar3;
  if (*(short *)(&DAT_00800ef4 + iVar3) != 0) {
    *(short *)(&DAT_00800ef4 + iVar3) = *(short *)(&DAT_00800ef4 + iVar3) + -1;
    return;
  }
  if ((&DAT_00800eea)[iVar3] == (&DAT_00800ee5)[iVar3]) {
    bVar5 = (*(char *)(iVar3 + 0x800ee7) - *(char *)(iVar3 + 0x800ee9)) + 2;
    *(ushort *)(&DAT_00800efa + iVar3) = (ushort)bVar5;
    *pcVar6 = '\0';
  }
  else {
    bVar5 = 8;
    *(undefined2 *)(&DAT_00800efa + iVar3) = 8;
    *(short *)(&DAT_00800ee8 + iVar3) = *(short *)(&DAT_00800ee8 + iVar3) + 7;
    *(undefined2 *)(&DAT_00800ef4 + iVar3) = 5;
  }
  puVar7 = *(undefined1 **)(&DAT_00800efc + iVar3);
  uVar2 = (&DAT_00800eea)[iVar3];
  (&DAT_00800eea)[iVar3] = (&DAT_00800eea)[iVar3] + '\x01';
  *puVar7 = uVar2;
  for (bVar4 = 0; puVar7 = puVar7 + 1, (int)(uint)bVar4 < (int)(bVar5 - 1); bVar4 = bVar4 + 1) {
    puVar1 = *(undefined1 **)(&DAT_00800eec + iVar3);
    *(int *)(&DAT_00800eec + iVar3) = *(int *)(&DAT_00800eec + iVar3) + 1;
    *puVar7 = *puVar1;
  }
  sendCanSingleFrame(*(undefined4 *)(&DAT_00800ef6 + iVar3));
  if ((&DAT_00800eeb)[iVar3] == '\0') {
    if (*pcVar6 == '\x01') {
      **(undefined1 **)(&DAT_00800ef0 + iVar3) = 0x11;
      return;
    }
    **(undefined1 **)(&DAT_00800ef0 + iVar3) = 5;
    return;
  }
  **(undefined1 **)(&DAT_00800ef0 + iVar3) = (&DAT_00800eeb)[iVar3];
  *pcVar6 = '\0';
  return;
}



//
// Function: diagnosticMessageProcessor @ 0x0001c996
//

void diagnosticMessageProcessor(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  byte bVar6;
  byte *pbVar7;
  byte *pbVar8;
  
  bVar6 = diag_tp_state_t_00800f34.req_count;
  bVar3 = diag_tp_state_t_00800f34.req_start;
  if (diag_tp_state_t_00800f34.req_count == 0) {
    if (diag_tp_state_t_00800f34._18_2_ == 0) {
      *diag_tp_state_t_00800f34.resp_byte_ptr = 6;
      diag_tp_state_t_00800f34.diag_state = 0;
      return;
    }
    diag_tp_state_t_00800f34._18_2_ = diag_tp_state_t_00800f34._18_2_ + -1;
    return;
  }
  if (diag_tp_state_t_00800f34.req_count < 0xb) {
    diag_tp_state_t_00800f34.req_count = 0;
    diag_tp_state_t_00800f34.status_code = 0;
    diag_tp_state_t_00800f34.reserved_0x47 = 0x70;
  }
  else {
    bVar6 = 10;
    diag_tp_state_t_00800f34.req_start = diag_tp_state_t_00800f34.req_start + 10;
    diag_tp_state_t_00800f34.req_count = diag_tp_state_t_00800f34.req_count - 10;
  }
  pbVar8 = diag_tp_state_t_00800f34.src_data_ptr + (uint)bVar3 * 7 + -7;
  bVar5 = 0;
  cVar4 = bVar3 * '\a' + -7;
  while( true ) {
    pbVar7 = diag_tp_state_t_00800f34.tx_cm_buf;
    if (bVar6 <= bVar5) {
      return;
    }
    if (bVar3 == diag_tp_state_t_00800f34.total_packets) {
      bVar2 = ((char)diag_tp_state_t_00800f34.total_bytes - cVar4) + 1;
      diag_tp_state_t_00800f34.tx_length = (word)bVar2;
    }
    else {
      bVar2 = 8;
    }
    cVar4 = cVar4 + '\a';
    *diag_tp_state_t_00800f34.tx_cm_buf = bVar3;
    for (bVar1 = 0; pbVar7 = pbVar7 + 1, (int)(uint)bVar1 < (int)(bVar2 - 1); bVar1 = bVar1 + 1) {
      *pbVar7 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    }
    sendCanSingleFrame(diag_tp_state_t_00800f34.tx_header_id);
    if (diag_tp_state_t_00800f34.pre_status != 0) break;
    *diag_tp_state_t_00800f34.resp_byte_ptr = 0x13;
    bVar5 = bVar5 + 1;
    bVar3 = bVar3 + 1;
  }
  *diag_tp_state_t_00800f34.resp_byte_ptr = 7;
  diag_tp_state_t_00800f34.diag_state = 0;
  return;
}



//
// Function: vp44ResponseTimeoutHandler @ 0x0001cabe
//

void vp44ResponseTimeoutHandler(void)

{
  if (vp44_message_t_00800f5f._5_2_ == 0) {
    DAT_00800f5e = 0;
    return;
  }
  vp44_message_t_00800f5f._5_2_ = vp44_message_t_00800f5f._5_2_ + -1;
  return;
}



//
// Function: messageQueueDispatcher @ 0x0001cad6
//

void messageQueueDispatcher(void)

{
  ushort in_stack_00000000;
  
  if (DAT_00800ee4 == '\x01') {
    unknownMessageHandler((uint)in_stack_00000000);
  }
  if (DAT_00800f04 == '\x01') {
    unknownMessageHandler(CONCAT22(1,in_stack_00000000));
  }
  if (diag_tp_state_t_00800f34.diag_state == 1) {
    diagnosticMessageProcessor();
  }
  if (DAT_00800f5e == '\x01') {
    vp44ResponseTimeoutHandler();
  }
  return;
}



//
// Function: multiPacketBufferAllocator @ 0x0001cb18
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 multiPacketBufferAllocator(undefined4 param_1)

{
  if (param_1._0_2_ < 9) {
    _DAT_00800ed2 = 0x800edc;
    _DAT_00800ed0 = param_1._0_2_;
    _DAT_00800ed6 = 0x800eda;
    return 0x800ecc;
  }
  if ((DAT_008007c2 & 0xf0) != 0) {
    return 0;
  }
  _DAT_008007ba = 0x8007c4;
  _DAT_008007b8 = param_1._0_2_;
  _DAT_008007be = &DAT_008007c2;
  return 0x8007b4;
}



//
// Function: vp44DiagnosticBufferPointersInit @ 0x0001cb6e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44DiagnosticBufferPointersInit(void)

{
  _DAT_00800efc = 0x800f24;
  _DAT_00800f1c = 0x800f2c;
  diag_tp_state_t_00800f34.tx_cm_buf = (byte *)0x800f56;
  _DAT_00800f6c = 0x800f78;
  coreSystemControlFunction();
  coreSystemControlFunction();
  return;
}



//
// Function: fuelArbitratorResetHandler @ 0x0001cbc2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelArbitratorResetHandler(void)

{
  word wVar1;
  undefined4 unaff_A2;
  
  wVar1 = fuel_arbitrator_diag_t_0080cff8.rpm_target;
  _DAT_0080161c = fuel_arbitrator_diag_t_0080cff8.rpm_target;
  fuel_arbitrator_diag_t_0080cff8.rpm_target = 0;
  fuel_arbitrator_diag_t_0080cff8.fuel_mode = 0;
  fuel_arbitrator_diag_t_0080cff8._20_2_ = 0;
  j1939MessageTypeCounter(CONCAT22(wVar1,(short)((uint)unaff_A2 >> 0x10)));
  _DAT_0080d028 = 0;
  _DAT_0080d026 = 0;
  return;
}



//
// Function: fuelArbitratorVariablesReset @ 0x0001cbfe
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelArbitratorVariablesReset(void)

{
  _DAT_0080cfa8 = 0;
  _DAT_0080cfaa = 0;
  _DAT_0080cfb0 = 0;
  _DAT_0080cfb2 = 3;
  fuel_arbitrator_diag_t_0080cff8.throttle_mode = 0;
  _DAT_0080d02c = 0;
  _DAT_0080d02a = 0;
  _DAT_0080d036 = 0;
  _DAT_0080d038 = 0;
  return;
}



//
// Function: systemStatusProcessor @ 0x0001cc38
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint systemStatusProcessor(void)

{
  word wVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  ushort uVar5;
  undefined2 uVar6;
  undefined3 uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 unaff_D2;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  
  uVar6 = (undefined2)((uint)unaff_D2 >> 0x10);
  bVar4 = false;
  bVar3 = false;
  bVar2 = false;
  if ((_DAT_00801622 != fuel_arbitrator_diag_t_0080cff8.speed_limit) &&
     (fuel_arbitrator_diag_t_0080cff8.speed_limit == 1)) {
    _DAT_0080d030 = _DAT_008086e6 + 1;
    bVar2 = true;
  }
  if (_DAT_0080d02e != 0) {
    _DAT_0080d02e = _DAT_0080d02e + -1;
    bVar2 = true;
  }
  bVar10 = _DAT_0080d02e == 1;
  if (bVar10) {
    fuel_arbitrator_diag_t_0080cff8.speed_limit = 0;
    _DAT_0080d03c = 0;
    _DAT_0080d02e = 0;
    _DAT_0080d030 = 0;
  }
  if (_DAT_0080d030 != 0) {
    _DAT_0080d030 = _DAT_0080d030 + -1;
  }
  if (_DAT_0080d030 == 1) {
    fuel_arbitrator_diag_t_0080cff8.speed_limit = 0;
    _DAT_0080d03c = 1;
    _DAT_0080d02e = _DAT_008086ea + 1;
  }
  if (((_DAT_0080d034 != 0) &&
      (_DAT_0080d034 = _DAT_0080d034 + -1,
      _DAT_00801628 != fuel_arbitrator_diag_t_0080cff8.session_counter)) &&
     (fuel_arbitrator_diag_t_0080cff8.session_counter == 1)) {
    bVar2 = true;
  }
  bVar11 = _DAT_0080d034 == 1;
  if (bVar11) {
    fuel_arbitrator_diag_t_0080cff8.session_counter = 0;
    _DAT_0080d034 = 0;
  }
  if (((_DAT_0080d032 != 0) &&
      (_DAT_0080d032 = _DAT_0080d032 + -1,
      _DAT_0080162a != fuel_arbitrator_diag_t_0080cff8.fuel_limit)) &&
     (fuel_arbitrator_diag_t_0080cff8.fuel_limit == 1)) {
    bVar2 = true;
  }
  bVar12 = _DAT_0080d032 == 1;
  if (bVar12) {
    fuel_arbitrator_diag_t_0080cff8.fuel_limit = 0;
    _DAT_0080d032 = 0;
  }
  if (((_DAT_0080d036 != 0) &&
      (_DAT_0080d036 = _DAT_0080d036 + -1,
      _DAT_0080162c != fuel_arbitrator_diag_t_0080cff8.throttle_mode)) &&
     (fuel_arbitrator_diag_t_0080cff8.throttle_mode == 1)) {
    bVar2 = true;
  }
  bVar13 = _DAT_0080d036 == 1;
  if (bVar13) {
    fuel_arbitrator_diag_t_0080cff8.throttle_mode = 0;
    _DAT_0080d036 = 0;
  }
  bVar13 = bVar13 || (bVar12 || (bVar11 || bVar10));
  uVar5 = (short)fuel_arbitrator_diag_t_0080cff8.rpm_target >> 0xf;
  if (((fuel_arbitrator_diag_t_0080cff8.rpm_target == _DAT_0080161c) &&
      (fuel_arbitrator_diag_t_0080cff8._28_2_ == _DAT_0080161e)) &&
     ((char)fuel_arbitrator_diag_t_0080cff8.limited_value == DAT_00801620)) {
    if (_DAT_0080d028 != 0) {
      _DAT_0080d028 = _DAT_0080d028 + -1;
    }
    if (_DAT_0080d026 != 0) {
      _DAT_0080d026 = _DAT_0080d026 + -1;
    }
    uVar8 = (uint)(short)fuel_arbitrator_diag_t_0080cff8.rpm_target;
    uVar9 = uVar8;
    if (uVar8 < 4) {
      uVar9 = CONCAT22(uVar5,(&switchD_0001ce60::switchdataD_0001ce64)[uVar8]);
      uVar7 = (undefined3)(uVar9 >> 8);
      switch(uVar8) {
      case 1:
        if (_DAT_0080d028 == 1) {
          uVar9 = fuelArbitratorResetHandler();
          bVar13 = true;
        }
        else if (_DAT_0080d026 == 1) {
          ioControlEntryAdd(CONCAT22(fuel_arbitrator_diag_t_0080cff8._28_2_,
                                     (short)CONCAT31(uVar7,(char)fuel_arbitrator_diag_t_0080cff8.
                                                                 limited_value)),CONCAT22(1,uVar6));
          uVar9 = fuelArbitratorResetHandler();
        }
        break;
      case 2:
        if (_DAT_0080d028 == 1) {
          uVar9 = fuelArbitratorResetHandler();
          bVar13 = true;
        }
        else if ((_DAT_0080d026 == 1) && (fuel_arbitrator_diag_t_0080cff8.fuel_limit == 0)) {
          ioControlEntryAdd(CONCAT22(fuel_arbitrator_diag_t_0080cff8._28_2_,
                                     (short)CONCAT31(uVar7,(char)fuel_arbitrator_diag_t_0080cff8.
                                                                 limited_value)),CONCAT22(2,uVar6));
          uVar9 = fuelArbitratorResetHandler();
        }
        break;
      case 3:
        if (_DAT_0080d028 == 1) {
          uVar9 = fuelArbitratorResetHandler();
          bVar13 = true;
        }
      }
    }
  }
  else {
    uVar8 = (uint)(short)fuel_arbitrator_diag_t_0080cff8.rpm_target;
    uVar9 = uVar8;
    if (uVar8 < 4) {
      uVar9 = (uint)uVar5 << 0x10;
      switch(uVar8) {
      case 0:
        _DAT_0080d026 = 0;
        break;
      case 1:
        _DAT_0080d026 = *(short *)(_DAT_0080d01e + 6) + 1;
        uVar9 = CONCAT22(uVar5,_DAT_0080d026);
        bVar2 = true;
        break;
      case 2:
        _DAT_0080d026 = *(short *)(_DAT_0080d01e + 10) + 1;
        uVar9 = CONCAT22(uVar5,_DAT_0080d026);
        bVar2 = true;
        break;
      case 3:
        _DAT_0080d026 = 0;
        bVar2 = true;
      }
    }
    if (_DAT_0080161e == 0) {
      uVar9 = j1939MessageTypeCounter(CONCAT22(_DAT_0080161c,uVar6));
    }
  }
  if (bVar13) {
    if (fuel_arbitrator_diag_t_0080cff8._28_2_ == 1) {
      bVar4 = true;
    }
    else {
      bVar3 = true;
    }
  }
  else if (bVar2) {
    if (fuel_arbitrator_diag_t_0080cff8._28_2_ == 1) {
      DAT_0080162f = '\x01';
    }
    else {
      DAT_00801630 = '\x01';
    }
  }
  _DAT_0080161c = fuel_arbitrator_diag_t_0080cff8.rpm_target;
  _DAT_0080161e = fuel_arbitrator_diag_t_0080cff8._28_2_;
  DAT_00801620 = (char)fuel_arbitrator_diag_t_0080cff8.limited_value;
  _DAT_00801622 = fuel_arbitrator_diag_t_0080cff8.speed_limit;
  _DAT_00801628 = fuel_arbitrator_diag_t_0080cff8.session_counter;
  _DAT_0080162a = fuel_arbitrator_diag_t_0080cff8.fuel_limit;
  _DAT_0080162c = fuel_arbitrator_diag_t_0080cff8.throttle_mode;
  uVar9 = CONCAT22((short)(uVar9 >> 0x10),_DAT_0080cfa8);
  if (_DAT_0080cfa8 == _DAT_00801624) {
    uVar9 = (uint)_DAT_0080cfac;
    if (uVar9 == DAT_00801626) {
      if (_DAT_0080d02c != 0) {
        _DAT_0080d02c = _DAT_0080d02c + -1;
      }
      if (_DAT_0080d02a != 0) {
        _DAT_0080d02a = _DAT_0080d02a + -1;
      }
      if (_DAT_0080cfa8 == 2) {
        if (_DAT_0080d02c == 1) {
          uVar9 = fuelArbitratorVariablesReset();
          bVar4 = true;
        }
        else if (_DAT_0080d02a == 1) {
          ioControlTimeoutEntryAdd(CONCAT22(_DAT_0080cfac,uVar6));
          uVar9 = fuelArbitratorVariablesReset();
        }
      }
      else if ((_DAT_0080cfa8 == 3) && (_DAT_0080d02c == 1)) {
        uVar9 = fuelArbitratorVariablesReset();
        bVar4 = true;
      }
      goto LAB_0001d026;
    }
  }
  if (_DAT_0080cfa8 == 2) {
    _DAT_0080d02a = *(short *)(_DAT_0080d022 + 0x10) + 1;
    uVar9 = CONCAT22((short)(uVar9 >> 0x10),_DAT_0080d02a);
    DAT_0080162f = '\x01';
  }
  else {
    _DAT_0080d02a = 0;
    if (_DAT_0080cfa8 == 3) {
      DAT_0080162f = '\x01';
    }
  }
LAB_0001d026:
  _DAT_00801624 = _DAT_0080cfa8;
  DAT_00801626 = DAT_0080cfad;
  if (bVar3) {
    uVar9 = (uint)_DAT_00805578;
    if ((int)uVar9 < (int)(_DAT_0080875e - 1)) {
      _DAT_00805578 = _DAT_00805578 + 1;
    }
    else {
      fault_status_registers_t_00805df2.io_fault_status_4 =
           fault_status_registers_t_00805df2.io_fault_status_4 | 8;
      fault_latch_registers_t_00805e32.io_fault_latch_4 =
           fault_latch_registers_t_00805e32.io_fault_latch_4 | 8;
      _DAT_00805578 = 0;
    }
    DAT_00801630 = '\0';
  }
  else if (DAT_00801630 == '\x01') {
    uVar6 = (undefined2)(uVar9 >> 0x10);
    wVar1 = fault_status_registers_t_00805df2.io_fault_status_4;
    if (((fault_status_registers_t_00805df2.io_fault_status_4 & 8) == 0) ||
       (wVar1 = _DAT_008068d2, (_DAT_008068d2 & 8) == 0)) {
      uVar9 = CONCAT22(uVar6,wVar1) & 0xffff0008;
      DAT_00801630 = '\0';
    }
    else {
      uVar9 = CONCAT22(uVar6,fault_status_registers_t_00805df2.io_fault_status_4) & 0xffff0008;
      if ((fault_status_registers_t_00805df2.io_fault_status_4 & 8) != 0) {
        uVar9 = CONCAT22(uVar6,fault_latch_registers_t_00805e32.io_fault_latch_4) & 0xffff0008;
        if ((fault_latch_registers_t_00805e32.io_fault_latch_4 & 8) == 0) {
          fault_status_registers_t_00805df2.io_fault_status_4 =
               fault_status_registers_t_00805df2.io_fault_status_4 & 0xfff7;
          DAT_00801630 = '\0';
          _DAT_00805578 = 0;
        }
      }
    }
  }
  if (bVar4) {
    uVar9 = (uint)_DAT_0080557a;
    if ((int)uVar9 < (int)(_DAT_0080875e - 1)) {
      _DAT_0080557a = _DAT_0080557a + 1;
    }
    else {
      fault_status_registers_t_00805df2.io_fault_status_2 =
           fault_status_registers_t_00805df2.io_fault_status_2 | 0x400;
      fault_latch_registers_t_00805e32.io_fault_latch_2 =
           fault_latch_registers_t_00805e32.io_fault_latch_2 | 0x400;
    }
    DAT_0080162f = 0;
    return uVar9;
  }
  if (DAT_0080162f == '\x01') {
    uVar6 = (undefined2)(uVar9 >> 0x10);
    wVar1 = fault_status_registers_t_00805df2.io_fault_status_2;
    if (((fault_status_registers_t_00805df2.io_fault_status_2 & 0x400) == 0) ||
       (wVar1 = _DAT_008068ce, (_DAT_008068ce & 0x400) == 0)) {
      uVar9 = CONCAT22(uVar6,wVar1) & 0xffff0400;
      DAT_0080162f = '\0';
    }
    else {
      uVar9 = CONCAT22(uVar6,fault_status_registers_t_00805df2.io_fault_status_2) & 0xffff0400;
      if ((fault_status_registers_t_00805df2.io_fault_status_2 & 0x400) != 0) {
        uVar9 = CONCAT22(uVar6,fault_latch_registers_t_00805e32.io_fault_latch_2) & 0xffff0400;
        if ((fault_latch_registers_t_00805e32.io_fault_latch_2 & 0x400) == 0) {
          fault_status_registers_t_00805df2.io_fault_status_2 =
               fault_status_registers_t_00805df2.io_fault_status_2 & 0xfbff;
          DAT_0080162f = 0;
          _DAT_0080557a = 0;
          return uVar9;
        }
      }
    }
  }
  return uVar9;
}



//
// Function: diagnosticMessageValidator @ 0x0001d19c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint diagnosticMessageValidator(undefined4 param_1,undefined4 param_2)

{
  uint in_D0;
  byte bVar1;
  short *psVar2;
  
  psVar2 = (short *)&DAT_00801632;
  bVar1 = 0;
  while( true ) {
    if (DAT_0080166e <= bVar1) {
      return in_D0 & 0xffff0000;
    }
    if (((param_1._0_2_ == *psVar2) && ((char)param_1 == *(char *)(psVar2 + 1))) &&
       (param_2._0_2_ == psVar2[2])) break;
    psVar2 = psVar2 + 4;
    bVar1 = bVar1 + 1;
  }
  psVar2[3] = _DAT_008086ea;
  return 1;
}



//
// Function: ioControlTimeoutTableLookup @ 0x0001d1ec
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint ioControlTimeoutTableLookup(undefined4 param_1)

{
  uint in_D0;
  byte bVar1;
  char *pcVar2;
  
  pcVar2 = &DAT_0080165a;
  bVar1 = 0;
  while( true ) {
    if (DAT_0080166f <= bVar1) {
      return in_D0 & 0xffff0000;
    }
    if ((char)((uint)param_1 >> 0x10) == *pcVar2) break;
    pcVar2 = pcVar2 + 4;
    bVar1 = bVar1 + 1;
  }
  *(undefined2 *)(pcVar2 + 2) = _DAT_008086ea;
  return 1;
}



//
// Function: ioControlEntryAdd @ 0x0001d228
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ioControlEntryAdd(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  if (DAT_0080166e < 5) {
    iVar1 = (uint)DAT_0080166e * 8;
    DAT_0080166e = DAT_0080166e + 1;
    *(undefined2 *)(&DAT_00801632 + iVar1) = param_1._0_2_;
    (&DAT_00801634)[iVar1] = (undefined1)param_1;
    *(undefined2 *)(&DAT_00801636 + iVar1) = param_2._0_2_;
    *(undefined2 *)(&DAT_00801638 + iVar1) = _DAT_008086ea;
  }
  return;
}



//
// Function: ioControlTimeoutEntryAdd @ 0x0001d268
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ioControlTimeoutEntryAdd(undefined4 param_1)

{
  uint uVar1;
  
  if (DAT_0080166f < 5) {
    uVar1 = (uint)DAT_0080166f;
    DAT_0080166f = DAT_0080166f + 1;
    (&DAT_0080165a)[uVar1 * 4] = param_1._1_1_;
    *(undefined2 *)(&DAT_0080165c + uVar1 * 4) = _DAT_008086ea;
  }
  return;
}



//
// Function: phase3_countdown_timer_manager @ 0x0001d29c
//

void phase3_countdown_timer_manager(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  undefined2 *puVar5;
  undefined1 *puVar6;
  
  if (DAT_0080166e != 0) {
    puVar5 = (undefined2 *)(&DAT_0080162a + (uint)DAT_0080166e * 8);
    for (bVar4 = DAT_0080166e; bVar4 != 0; bVar4 = bVar4 - 1) {
      sVar1 = puVar5[3] + -1;
      puVar5[3] = sVar1;
      if (sVar1 == 0) {
        if (bVar4 == DAT_0080166e) {
          DAT_0080166e = DAT_0080166e - 1;
        }
        else {
          DAT_0080166e = DAT_0080166e - 1;
          iVar2 = (uint)DAT_0080166e * 8;
          *puVar5 = *(undefined2 *)(&DAT_00801632 + iVar2);
          *(undefined *)(puVar5 + 1) = (&DAT_00801634)[iVar2];
          puVar5[2] = *(undefined2 *)(&DAT_00801636 + iVar2);
          puVar5[3] = *(undefined2 *)(&DAT_00801638 + iVar2);
        }
      }
      puVar5 = puVar5 + -4;
    }
  }
  if (DAT_0080166f != 0) {
    puVar6 = (undefined1 *)((uint)DAT_0080166f * 4 + 0x801656);
    for (bVar4 = DAT_0080166f; bVar4 != 0; bVar4 = bVar4 - 1) {
      sVar1 = *(short *)(puVar6 + 2) + -1;
      *(short *)(puVar6 + 2) = sVar1;
      if (sVar1 == 0) {
        if (bVar4 == DAT_0080166f) {
          DAT_0080166f = DAT_0080166f - 1;
        }
        else {
          DAT_0080166f = DAT_0080166f - 1;
          uVar3 = (uint)DAT_0080166f;
          *puVar6 = (&DAT_0080165a)[uVar3 * 4];
          *(undefined2 *)(puVar6 + 2) = *(undefined2 *)(&DAT_0080165c + uVar3 * 4);
        }
      }
      puVar6 = puVar6 + -4;
    }
  }
  return;
}



//
// Function: diagnosticStateInitializer @ 0x0001d34e
//

void diagnosticStateInitializer(undefined4 param_1)

{
  int iVar1;
  byte bVar2;
  short *psVar3;
  
  if (DAT_0080166e != 0) {
    psVar3 = (short *)(&DAT_0080162a + (uint)DAT_0080166e * 8);
    for (bVar2 = DAT_0080166e; bVar2 != 0; bVar2 = bVar2 - 1) {
      if ((param_1._0_2_ == *psVar3) && ((char)param_1 == *(char *)(psVar3 + 1))) {
        if (bVar2 == DAT_0080166e) {
          DAT_0080166e = DAT_0080166e - 1;
        }
        else {
          DAT_0080166e = DAT_0080166e - 1;
          iVar1 = (uint)DAT_0080166e * 8;
          *psVar3 = *(short *)(&DAT_00801632 + iVar1);
          *(undefined *)(psVar3 + 1) = (&DAT_00801634)[iVar1];
          psVar3[2] = *(short *)(&DAT_00801636 + iVar1);
          psVar3[3] = *(short *)(&DAT_00801638 + iVar1);
        }
      }
      psVar3 = psVar3 + -4;
    }
  }
  return;
}



//
// Function: ioControlEntryRemove @ 0x0001d3b8
//

void ioControlEntryRemove(undefined4 param_1)

{
  uint uVar1;
  byte bVar2;
  char *pcVar3;
  
  if (DAT_0080166f != 0) {
    pcVar3 = (char *)((uint)DAT_0080166f * 4 + 0x801656);
    for (bVar2 = DAT_0080166f; bVar2 != 0; bVar2 = bVar2 - 1) {
      if ((char)((uint)param_1 >> 0x10) == *pcVar3) {
        if (bVar2 == DAT_0080166f) {
          DAT_0080166f = DAT_0080166f - 1;
        }
        else {
          DAT_0080166f = DAT_0080166f - 1;
          uVar1 = (uint)DAT_0080166f;
          *pcVar3 = (&DAT_0080165a)[uVar1 * 4];
          *(undefined2 *)(pcVar3 + 2) = *(undefined2 *)(&DAT_0080165c + uVar1 * 4);
        }
      }
      pcVar3 = pcVar3 + -4;
    }
  }
  return;
}



//
// Function: ioControlRegisterBitMapper @ 0x0001d40c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint ioControlRegisterBitMapper(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 in_D0;
  uint uVar3;
  
  if ((_DAT_0080d04c & 0x20) == 0) {
    DAT_0080bdee = DAT_0080bdee & 0xdf;
  }
  else {
    DAT_0080bdee = DAT_0080bdee | 0x20;
  }
  if ((_DAT_0080d04c & 4) == 0) {
    DAT_0080bdee = DAT_0080bdee & 0xef;
  }
  else {
    DAT_0080bdee = DAT_0080bdee | 0x10;
  }
  if ((_DAT_0080d04c & 0x40) == 0) {
    DAT_0080bdee = DAT_0080bdee & 0xf7;
  }
  else {
    DAT_0080bdee = DAT_0080bdee | 8;
  }
  if ((_DAT_0080d04c & 1) == 0) {
    DAT_0080bdee = DAT_0080bdee & 0xfd;
  }
  else {
    DAT_0080bdee = DAT_0080bdee | 2;
  }
  uVar1 = (short)((uint)in_D0 >> 0x10);
  if ((_DAT_0080d04c & 8) == 0) {
    uVar2 = 0;
    uVar1 = 0;
    if ((DAT_0080bdf1 & 4) == 0) {
      DAT_0080bdee = DAT_0080bdee & 0xfe;
      goto LAB_0001d486;
    }
  }
  uVar2 = uVar1;
  DAT_0080bdee = DAT_0080bdee | 1;
LAB_0001d486:
  if ((_DAT_0080d04c & 2) == 0) {
    DAT_0080bdee = DAT_0080bdee & 0xbf;
  }
  else {
    DAT_0080bdee = DAT_0080bdee | 0x40;
  }
  uVar3 = CONCAT22(uVar2,_DAT_0080d04c) & 0xffff0010;
  if ((_DAT_0080d04c & 0x10) == 0) {
    uVar3 = DAT_0080bdf1 & 8;
    if ((DAT_0080bdf1 & 8) == 0) {
      DAT_0080bdee = DAT_0080bdee & 0xfb;
      return uVar3;
    }
  }
  DAT_0080bdee = DAT_0080bdee | 4;
  return uVar3;
}



//
// Function: ioControlStateMachineWithDelay @ 0x0001d4bc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint ioControlStateMachineWithDelay(void)

{
  uint uVar1;
  
  if ((DAT_0080bdee & 1) == 0) {
    _DAT_0080d03e = 0;
  }
  else if (_DAT_0080d03e == 0) {
    _DAT_0080d03e = 1;
  }
  else if (_DAT_0080d03e == 1) {
    if ((DAT_0080bdca & 1) != 0) {
      _DAT_0080d03e = 2;
      _DAT_008016a2 = 0;
    }
  }
  else if (_DAT_0080d03e == 2) {
    if (_DAT_008016a2 < 10) {
      _DAT_008016a2 = _DAT_008016a2 + 1;
    }
    else {
      _DAT_0080d03e = 1;
      _DAT_008016a2 = 0;
    }
  }
  if ((DAT_0080bdee & 2) == 0) {
    _DAT_0080d040 = 0;
  }
  else if (_DAT_0080d040 == 0) {
    _DAT_0080d040 = 1;
  }
  else if (_DAT_0080d040 == 1) {
    if ((DAT_0080bdca & 2) != 0) {
      _DAT_0080d040 = 2;
      _DAT_008016a4 = 0;
    }
  }
  else if (_DAT_0080d040 == 2) {
    if (_DAT_008016a4 < 10) {
      _DAT_008016a4 = _DAT_008016a4 + 1;
    }
    else {
      _DAT_0080d040 = 1;
      _DAT_008016a4 = 0;
    }
  }
  if ((DAT_0080bdee & 4) == 0) {
    _DAT_0080d042 = 0;
  }
  else if (_DAT_0080d042 == 0) {
    _DAT_0080d042 = 1;
  }
  else if (_DAT_0080d042 == 1) {
    if ((DAT_0080bdca & 4) != 0) {
      _DAT_0080d042 = 2;
      _DAT_008016a6 = 0;
    }
  }
  else if (_DAT_0080d042 == 2) {
    if (_DAT_008016a6 < 10) {
      _DAT_008016a6 = _DAT_008016a6 + 1;
    }
    else {
      _DAT_0080d042 = 1;
      _DAT_008016a6 = 0;
    }
  }
  if ((DAT_0080bdee & 0x40) == 0) {
    _DAT_0080d044 = 0;
  }
  else if (_DAT_0080d044 == 0) {
    _DAT_0080d044 = 1;
  }
  else if (_DAT_0080d044 == 1) {
    if ((DAT_0080bdca & 0x40) != 0) {
      _DAT_0080d044 = 2;
      _DAT_008016a8 = 0;
    }
  }
  else if (_DAT_0080d044 == 2) {
    if (_DAT_008016a8 < 10) {
      _DAT_008016a8 = _DAT_008016a8 + 1;
    }
    else {
      _DAT_0080d044 = 1;
      _DAT_008016a8 = 0;
    }
  }
  if ((DAT_0080bdee & 0x10) == 0) {
    _DAT_0080d046 = 0;
  }
  else if (_DAT_0080d046 == 0) {
    _DAT_0080d046 = 1;
  }
  else if (_DAT_0080d046 == 1) {
    if ((DAT_0080bdca & 0x10) != 0) {
      _DAT_0080d046 = 2;
      _DAT_008016aa = 0;
    }
  }
  else if (_DAT_0080d046 == 2) {
    if (_DAT_008016aa < 10) {
      _DAT_008016aa = _DAT_008016aa + 1;
    }
    else {
      _DAT_0080d046 = 1;
      _DAT_008016aa = 0;
    }
  }
  if ((DAT_0080bdee & 0x20) == 0) {
    _DAT_0080d048 = 0;
  }
  else if (_DAT_0080d048 == 0) {
    _DAT_0080d048 = 1;
  }
  else if (_DAT_0080d048 == 1) {
    if ((DAT_0080bdca & 0x20) != 0) {
      _DAT_0080d048 = 2;
      _DAT_008016ac = 0;
    }
  }
  else if (_DAT_0080d048 == 2) {
    if (_DAT_008016ac < 10) {
      _DAT_008016ac = _DAT_008016ac + 1;
    }
    else {
      _DAT_0080d048 = 1;
      _DAT_008016ac = 0;
    }
  }
  if ((DAT_0080bdee & 8) == 0) {
    _DAT_0080d04a = 0;
    return DAT_0080bdee & 8;
  }
  uVar1 = (uint)_DAT_0080d04a;
  if (_DAT_0080d04a == 0) {
    _DAT_0080d04a = 1;
    return uVar1;
  }
  if (_DAT_0080d04a == 1) {
    if ((DAT_0080bdca & 8) != 0) {
      _DAT_0080d04a = 2;
      _DAT_008016ae = 0;
      return uVar1;
    }
  }
  else {
    if (_DAT_0080d04a != 2) {
      return uVar1;
    }
    if (9 < _DAT_008016ae) {
      _DAT_0080d04a = 1;
      _DAT_008016ae = 0;
      return uVar1;
    }
    _DAT_008016ae = _DAT_008016ae + 1;
  }
  return uVar1;
}



//
// Function: ioControlPinSwitchingWrapper @ 0x0001d7d2
//

void ioControlPinSwitchingWrapper(void)

{
  ioControlRegisterBitMapper();
  ioControlStateMachineWithDelay();
  return;
}



//
// Function: initIoControlRegister @ 0x0001d7dc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initIoControlRegister(void)

{
  DAT_0080bdee = DAT_0080bdee & 0xfe;
  _DAT_008016a2 = 0;
  return;
}



//
// Function: initTimerCounterDefaults @ 0x0001d7ec
//

void initTimerCounterDefaults(void)

{
  DAT_00801670 = 1;
  DAT_00801671 = 1;
  DAT_00801683 = 0x7d;
  DAT_00801672 = 0;
  return;
}



//
// Function: ioControlMaskStateMachine @ 0x0001d80c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ioControlMaskStateMachine(void)

{
  short sVar1;
  ushort *puVar2;
  
  if (DAT_00801671 != '\0') {
    for (puVar2 = (ushort *)&DAT_00808768; puVar2 < (ushort *)0x808787; puVar2 = puVar2 + 1) {
      _DAT_0080d04c = *puVar2 | _DAT_0080d04c;
    }
    DAT_00801671 = 0;
    _DAT_00801692 = 0x28;
    _DAT_0080168e = (ushort *)&DAT_00808768;
    return;
  }
  _DAT_0080168a = _DAT_0080168a + 1;
  sVar1 = _DAT_00801692;
  if (_DAT_0080168a == _DAT_00801692) {
    _DAT_0080d04c = ~*_DAT_0080168e & _DAT_0080d04c;
    _DAT_0080168e = _DAT_0080168e + 1;
    sVar1 = _DAT_00801692 + 10;
    if ((*_DAT_0080168e == 0) || ((ushort *)0x808786 < _DAT_0080168e)) {
      if (DAT_00801672 != '\x01') {
        DAT_00801672 = 1;
        _DAT_00801692 = _DAT_00801692 + 0x1e;
        return;
      }
      DAT_00801670 = 0;
      DAT_00801685 = 0;
      DAT_00801686 = 0;
      DAT_00801687 = 0;
    }
  }
  _DAT_00801692 = sVar1;
  return;
}



//
// Function: ioControlToggleCycle @ 0x0001d8cc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint ioControlToggleCycle(void)

{
  uint in_D0;
  
  if (_DAT_00801676 == 0) {
    _DAT_0080d04c = _DAT_0080d04c | 1;
  }
  else if (_DAT_00801676 == 10) {
    _DAT_0080d04c = _DAT_0080d04c & 0xfffe;
  }
  else if (_DAT_00801676 == 0x14) {
    _DAT_00801676 = 0;
    return 1;
  }
  _DAT_00801676 = _DAT_00801676 + 1;
  return in_D0 & 0xffffff00;
}



//
// Function: ioControlLampStateMachine @ 0x0001d904
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 ioControlLampStateMachine(void)

{
  undefined1 uVar1;
  
  uVar1 = 1;
  if (high_rpm_protection_t_0080cc6a.warning_flag == 0) {
    if (DAT_0080167e != '\0') {
      DAT_0080167e = '\0';
      _DAT_0080167a = 0;
      _DAT_0080d04c = _DAT_0080d04c & 0xfffd;
    }
  }
  else {
    uVar1 = 0;
    if (_DAT_0080167a == 0) {
      _DAT_0080d04c = _DAT_0080d04c | 2;
      _DAT_0080167a = 1;
    }
    else if (_DAT_0080167a == _DAT_00808760) {
      _DAT_0080d04c = _DAT_0080d04c & 0xfffd;
      _DAT_0080167a = _DAT_0080167a + 1;
    }
    else if (((uint)_DAT_00808760 + (uint)_DAT_00808762) - 1 == (uint)_DAT_0080167a) {
      _DAT_0080167a = 0;
    }
    else {
      _DAT_0080167a = _DAT_0080167a + 1;
    }
    DAT_0080167e = '\x01';
  }
  if (_DAT_0080c998 == 0) {
    if (DAT_0080167f != '\0') {
      DAT_0080167f = '\0';
      _DAT_0080167c = 0;
      _DAT_0080d04c = _DAT_0080d04c & 0xfffb;
    }
  }
  else {
    uVar1 = 0;
    if (_DAT_0080167c == 0) {
      _DAT_0080d04c = _DAT_0080d04c | 4;
      _DAT_0080167c = 1;
    }
    else if (_DAT_0080167c == _DAT_00808760) {
      _DAT_0080d04c = _DAT_0080d04c & 0xfffb;
      _DAT_0080167c = _DAT_0080167c + 1;
    }
    else if (((uint)_DAT_00808760 + (uint)_DAT_00808762) - 1 == (uint)_DAT_0080167c) {
      _DAT_0080167c = 0;
    }
    else {
      _DAT_0080167c = _DAT_0080167c + 1;
    }
    DAT_0080167f = '\x01';
  }
  return uVar1;
}



//
// Function: ioControlDigitDisplaySequencer @ 0x0001d9ea
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint ioControlDigitDisplaySequencer(undefined4 param_1)

{
  ushort uVar1;
  undefined3 uVar2;
  uint in_D0;
  
  if (_DAT_00801674 == 0) {
    _DAT_0080d04c = _DAT_0080d04c & 0xfffe | 2;
    _DAT_00801674 = 1;
    DAT_00801680 = (char)(param_1._0_2_ / 100);
    DAT_00801681 = (char)(param_1._0_2_ / 10) + DAT_00801680 * -10;
    uVar1 = (short)(param_1._0_2_ / 10) * 10;
    in_D0 = (uint)uVar1;
    DAT_00801682 = (char)((uint)param_1 >> 0x10) - (char)uVar1;
  }
  else {
    uVar2 = (undefined3)(in_D0 >> 8);
    if (_DAT_00801674 == 0x28) {
      _DAT_0080d04c = _DAT_0080d04c & 0xfffd;
      in_D0 = CONCAT31(uVar2,DAT_00801688);
      if (DAT_00801688 == DAT_00801680) {
        DAT_00801688 = '\0';
        _DAT_00801674 = 0x29;
      }
      else {
        in_D0 = ioControlToggleCycle();
        if ((char)in_D0 != '\0') {
          DAT_00801688 = DAT_00801688 + '\x01';
        }
      }
    }
    else if (_DAT_00801674 == 0x50) {
      in_D0 = CONCAT31(uVar2,DAT_00801688);
      if (DAT_00801688 == DAT_00801681) {
        DAT_00801688 = '\0';
        _DAT_00801674 = 0x51;
      }
      else {
        in_D0 = ioControlToggleCycle();
        if ((char)in_D0 != '\0') {
          DAT_00801688 = DAT_00801688 + '\x01';
        }
      }
    }
    else if (_DAT_00801674 == 0x78) {
      in_D0 = CONCAT31(uVar2,DAT_00801688);
      if (DAT_00801688 == DAT_00801682) {
        DAT_00801688 = '\0';
        _DAT_00801674 = 0x79;
      }
      else {
        in_D0 = ioControlToggleCycle();
        if ((char)in_D0 != '\0') {
          DAT_00801688 = DAT_00801688 + '\x01';
        }
      }
    }
    else {
      if (_DAT_00801674 != 0xa0) {
        _DAT_00801674 = _DAT_00801674 + 1;
        return 1;
      }
      _DAT_00801674 = 0;
    }
  }
  return in_D0 & 0xffffff00;
}



//
// Function: activeFaultCodeIteratorForward @ 0x0001dae8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 activeFaultCodeIteratorForward(undefined4 param_1)

{
  undefined1 uVar1;
  
  if (DAT_00804e7c == '\0') {
    uVar1 = 0x7d;
  }
  else {
    if ((param_1._1_1_ == '}') || (DAT_0080168c = DAT_0080168c + 1, _DAT_00804f3c < DAT_0080168c)) {
      DAT_0080168c = 1;
    }
    uVar1 = (&DAT_00804e7c)[(short)(ushort)DAT_0080168c];
  }
  return uVar1;
}



//
// Function: activeFaultCodeIteratorBackward @ 0x0001db2e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 activeFaultCodeIteratorBackward(undefined4 param_1)

{
  undefined1 uVar1;
  
  if (DAT_00804e7c == '\0') {
    uVar1 = 0x7d;
  }
  else {
    if ((param_1._1_1_ == '}') || (DAT_0080168c = DAT_0080168c - 1, DAT_0080168c == 0)) {
      DAT_0080168c = (byte)_DAT_00804f3c;
    }
    uVar1 = (&DAT_00804e7c)[(short)(ushort)DAT_0080168c];
  }
  return uVar1;
}



//
// Function: faultCodeDisplayController @ 0x0001db66
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint faultCodeDisplayController(void)

{
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  byte bVar2;
  uint uVar1;
  undefined4 unaff_D2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((uint)unaff_D2 >> 0x10);
  if (((DAT_0080bdc7 & 0x80) != 0) && (engine_operating_mode_t_0080c810.state == 1)) {
    DAT_00801684 = 1;
    if (((DAT_0080bdc7 & 0x80) == 0) || (DAT_00801687 != '\0')) {
      if (((DAT_0080bdc7 & 0x20) == 0) || (DAT_00801685 != '\0')) {
        uVar1 = 0;
        if (((DAT_0080bdc7 & 0x40) != 0) && (DAT_00801686 == '\0')) {
          bVar2 = activeFaultCodeIteratorBackward((uint)CONCAT12(DAT_00801683,uVar3));
          uVar1 = CONCAT31(extraout_var_01,bVar2);
          if ((bVar2 != 0x7d) &&
             (uVar1 = 0, (*(ushort *)(&DAT_008065ce + (uint)bVar2 * 6) & 0x40) == 0)) {
            _DAT_0080d04c = _DAT_0080d04c & 0xfffc;
            _DAT_00801674 = 0;
            _DAT_00801676 = 0;
            DAT_00801688 = 0;
            DAT_00801683 = bVar2;
          }
        }
      }
      else {
        bVar2 = activeFaultCodeIteratorForward((uint)CONCAT12(DAT_00801683,uVar3));
        uVar1 = CONCAT31(extraout_var_00,bVar2);
        if ((bVar2 != 0x7d) &&
           (uVar1 = 0, (*(ushort *)(&DAT_008065ce + (uint)bVar2 * 6) & 0x40) == 0)) {
          _DAT_0080d04c = _DAT_0080d04c & 0xfffc;
          _DAT_00801674 = 0;
          _DAT_00801676 = 0;
          DAT_00801688 = 0;
          DAT_00801683 = bVar2;
        }
      }
    }
    else {
      bVar2 = activeFaultCodeIteratorForward((uint)CONCAT12(DAT_00801683,uVar3));
      uVar1 = CONCAT31(extraout_var,bVar2);
      if ((bVar2 != 0x7d) && (uVar1 = 0, (*(ushort *)(&DAT_008065ce + (uint)bVar2 * 6) & 0x40) == 0)
         ) {
        _DAT_0080d04c = _DAT_0080d04c & 0xfff8;
        _DAT_00801674 = 0;
        _DAT_00801676 = 0;
        DAT_00801688 = 0;
        DAT_00801683 = bVar2;
      }
    }
    if (DAT_00801683 == 0x7d) {
      _DAT_0080d04c = _DAT_0080d04c | 3;
    }
    else {
      uVar1 = ioControlDigitDisplaySequencer
                        (CONCAT22(*(undefined2 *)(&DAT_008065cc + (uint)DAT_00801683 * 6),uVar3));
    }
    return uVar1 & 0xffffff00;
  }
  if (DAT_00801684 != '\0') {
    DAT_00801684 = '\0';
    _DAT_0080d04c = _DAT_0080d04c & 0xfffc;
  }
  return 1;
}



//
// Function: activeFaultLampStateMachine @ 0x0001dd00
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void activeFaultLampStateMachine(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  
  bVar6 = false;
  bVar1 = false;
  bVar3 = false;
  bVar2 = false;
  bVar5 = false;
  bVar4 = false;
  for (bVar7 = 1; bVar7 <= DAT_00804e7c; bVar7 = bVar7 + 1) {
    if (((*(ushort *)(&DAT_008065ce + (uint)(&DAT_00804e7c)[(short)(ushort)bVar7] * 6) & 1) == 0) ||
       ((*(ushort *)(&DAT_008065ce + (uint)(&DAT_00804e7c)[(short)(ushort)bVar7] * 6) & 0x40) != 0))
    {
      if (((*(ushort *)(&DAT_008065ce + (uint)(&DAT_00804e7c)[(short)(ushort)bVar7] * 6) & 2) == 0)
         || ((*(ushort *)(&DAT_008065ce + (uint)(&DAT_00804e7c)[(short)(ushort)bVar7] * 6) & 0x40)
             != 0)) {
        if (((*(ushort *)(&DAT_008065ce + (uint)(&DAT_00804e7c)[(short)(ushort)bVar7] * 6) & 4) != 0
            ) && ((*(ushort *)(&DAT_008065ce + (uint)(&DAT_00804e7c)[(short)(ushort)bVar7] * 6) &
                  0x40) == 0)) {
          if ((*(ushort *)(&DAT_008065ce + (uint)(&DAT_00804e7c)[(short)(ushort)bVar7] * 6) & 8) ==
              0) {
            bVar5 = true;
          }
          else {
            bVar4 = true;
          }
        }
      }
      else if ((*(ushort *)(&DAT_008065ce + (uint)(&DAT_00804e7c)[(short)(ushort)bVar7] * 6) & 8) ==
               0) {
        bVar3 = true;
      }
      else {
        bVar2 = true;
      }
    }
    else if ((*(ushort *)(&DAT_008065ce + (uint)(&DAT_00804e7c)[(short)(ushort)bVar7] * 6) & 8) == 0
            ) {
      bVar6 = true;
    }
    else {
      bVar1 = true;
    }
  }
  if (bVar1) {
    if (_DAT_00801678 == 0) {
      _DAT_0080d04c = _DAT_0080d04c | 1;
      _DAT_00801678 = 1;
    }
    else if (_DAT_00801678 == _DAT_00808760) {
      _DAT_0080d04c = _DAT_0080d04c & 0xfffe;
      _DAT_00801678 = _DAT_00801678 + 1;
    }
    else if ((uint)_DAT_00808760 + (uint)_DAT_00808762 == (uint)_DAT_00801678) {
      _DAT_00801678 = 0;
    }
    else {
      _DAT_00801678 = _DAT_00801678 + 1;
    }
  }
  else if (bVar6) {
    _DAT_0080d04c = _DAT_0080d04c | 1;
  }
  else {
    _DAT_0080d04c = _DAT_0080d04c & 0xfffe;
  }
  if (bVar2) {
    if (_DAT_0080167a == 0) {
      _DAT_0080d04c = _DAT_0080d04c | 2;
      _DAT_0080167a = 1;
    }
    else if (_DAT_0080167a == _DAT_00808760) {
      _DAT_0080d04c = _DAT_0080d04c & 0xfffd;
      _DAT_0080167a = _DAT_0080167a + 1;
    }
    else if ((uint)_DAT_00808760 + (uint)_DAT_00808762 == (uint)_DAT_0080167a) {
      _DAT_0080167a = 0;
    }
    else {
      _DAT_0080167a = _DAT_0080167a + 1;
    }
  }
  else if (bVar3) {
    _DAT_0080d04c = _DAT_0080d04c | 2;
  }
  else {
    _DAT_0080d04c = _DAT_0080d04c & 0xfffd;
  }
  if (bVar4) {
    if (_DAT_0080167c == 0) {
      _DAT_0080d04c = _DAT_0080d04c | 4;
      _DAT_0080167c = 1;
    }
    else if (_DAT_0080167c == _DAT_00808760) {
      _DAT_0080d04c = _DAT_0080d04c & 0xfffb;
      _DAT_0080167c = _DAT_0080167c + 1;
    }
    else if (((uint)_DAT_00808760 + (uint)_DAT_00808762) - 1 == (uint)_DAT_0080167c) {
      _DAT_0080167c = 0;
    }
    else {
      _DAT_0080167c = _DAT_0080167c + 1;
    }
  }
  else if (bVar5) {
    _DAT_0080d04c = _DAT_0080d04c | 4;
  }
  else {
    _DAT_0080d04c = _DAT_0080d04c & 0xfffb;
  }
  return;
}



//
// Function: faultLampBlinkPatternGenerator @ 0x0001dfc2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void faultLampBlinkPatternGenerator(void)

{
  if (_DAT_00801694 < 5) {
    if (_DAT_00801696 < 6) {
      _DAT_0080d04c = _DAT_0080d04c | 4;
    }
    else if ((_DAT_00801696 < 6) || (0xb < _DAT_00801696)) {
      if ((_DAT_00801696 < 0xc) || (0x11 < _DAT_00801696)) {
        if ((_DAT_00801696 < 0x12) || (0x17 < _DAT_00801696)) {
          if ((_DAT_00801696 < 0x18) || (0x1d < _DAT_00801696)) {
            if ((_DAT_00801696 < 0x1e) || (0x23 < _DAT_00801696)) {
              _DAT_00801696 = 0;
              _DAT_00801694 = _DAT_00801694 + 1;
              return;
            }
            _DAT_0080d04c = _DAT_0080d04c & 0xfffb;
          }
          else {
            _DAT_0080d04c = _DAT_0080d04c | 4;
          }
        }
        else {
          _DAT_0080d04c = _DAT_0080d04c & 0xfffb;
        }
      }
      else {
        _DAT_0080d04c = _DAT_0080d04c | 4;
      }
    }
    else {
      _DAT_0080d04c = _DAT_0080d04c & 0xfffb;
    }
    _DAT_00801696 = _DAT_00801696 + 1;
  }
  return;
}



//
// Function: waitToStartLampBlinkPattern @ 0x0001e050
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void waitToStartLampBlinkPattern(void)

{
  if (_DAT_00801698 < 6) {
    _DAT_0080d04c = _DAT_0080d04c | 2;
    DAT_0080169a = 1;
  }
  else if ((_DAT_00801698 < 6) || (0x17 < _DAT_00801698)) {
    if ((_DAT_00801698 < 0x18) || (0x1d < _DAT_00801698)) {
      if ((_DAT_00801698 < 0x1e) || (0x2f < _DAT_00801698)) {
        if ((_DAT_00801698 < 0x30) || (0x35 < _DAT_00801698)) {
          if ((_DAT_00801698 < 0x36) || (0x47 < _DAT_00801698)) {
            DAT_0080169a = 0;
          }
          else {
            _DAT_0080d04c = _DAT_0080d04c & 0xfffd;
          }
        }
        else {
          _DAT_0080d04c = _DAT_0080d04c | 2;
        }
      }
      else {
        _DAT_0080d04c = _DAT_0080d04c & 0xfffd;
      }
    }
    else {
      _DAT_0080d04c = _DAT_0080d04c | 2;
    }
  }
  else {
    _DAT_0080d04c = _DAT_0080d04c & 0xfffd;
  }
  _DAT_00801698 = _DAT_00801698 + 1;
  return;
}



//
// Function: periodicLampFlashController @ 0x0001e0d6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void periodicLampFlashController(void)

{
  if (DAT_0080169b == '\0') {
    _DAT_0080169c = _DAT_0080169c + 1;
    if (36000 < _DAT_0080169c) {
      DAT_0080169b = 1;
      _DAT_0080169c = 0;
      return;
    }
  }
  else {
    if (_DAT_0080169c < 0x14) {
      _DAT_0080d04c = _DAT_0080d04c | 4;
    }
    else if ((_DAT_0080169c < 0x14) || (0x4f < _DAT_0080169c)) {
      _DAT_0080169e = _DAT_0080169e + 1;
      _DAT_0080169c = 0;
    }
    else {
      _DAT_0080d04c = _DAT_0080d04c & 0xfffb;
    }
    _DAT_0080169c = _DAT_0080169c + 1;
    if (3 < _DAT_0080169e) {
      DAT_0080169b = '\0';
      _DAT_0080169c = 0;
      _DAT_0080169e = 0;
    }
  }
  return;
}



//
// Function: epsSignalQualityValidator @ 0x0001e140
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void epsSignalQualityValidator(void)

{
  uint uVar1;
  char cVar2;
  
  if (DAT_00801670 != '\0') {
    ioControlMaskStateMachine();
    return;
  }
  uVar1 = faultCodeDisplayController();
  if ((char)uVar1 != '\0') {
    cVar2 = ioControlLampStateMachine();
    if (cVar2 != '\0') {
      DAT_00801683 = 0x7d;
      activeFaultLampStateMachine();
    }
  }
  if (_DAT_008016a0 < 0x191) {
    _DAT_008016a0 = _DAT_008016a0 + 1;
  }
  if (((99 < _DAT_008016a0) && (_DAT_008016a0 < 400)) && (_DAT_0080d04e != 0)) {
    faultLampBlinkPatternGenerator();
  }
  if ((_DAT_0080d050 != 0) || (DAT_0080169a != '\0')) {
    waitToStartLampBlinkPattern();
  }
  if (((_DAT_0080373c != 0) && (_DAT_0080d04e != 0)) &&
     (engine_operating_mode_t_0080c810.state == 3)) {
    periodicLampFlashController();
  }
  DAT_00801685 = -((DAT_0080bdc7 & 0x20) != 0) & 1;
  DAT_00801686 = -((DAT_0080bdc7 & 0x40) != 0) & 1;
  DAT_00801687 = -((DAT_0080bdc7 & 0x80) != 0) & 1;
  return;
}



//
// Function: camSyncDiagnosticProcessor @ 0x0001e210
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void camSyncDiagnosticProcessor(void)

{
  uint uVar1;
  
  if (_DAT_0080d49c == 6) {
    CMLSEL = coreTableInterpolation();
    uVar1 = ((uint)_DAT_0080878a * (uint)CMLSEL) / 0x7800;
    if ((uint)_DAT_0080878c < (uint)_DAT_00808790 + (uVar1 & 0xffff)) {
      _DAT_0080d054 = _DAT_00808790;
    }
    else {
      _DAT_0080d054 = _DAT_0080878c - (short)uVar1;
    }
    if (_DAT_00809d50 == 1) {
      if (_DAT_008016b8 == 1) {
        _DAT_0080d052 = _DAT_0080878e + _DAT_0080d052;
        if (_DAT_0080d054 < _DAT_0080d052) {
          _DAT_0080d052 = _DAT_0080d054;
        }
      }
      else {
        _DAT_0080d052 = _DAT_00808792;
      }
    }
    else if (_DAT_00809d50 == 0) {
      _DAT_0080d052 = _DAT_0080849e;
    }
    _DAT_0080d49a = _DAT_0080d052;
  }
  _DAT_008016b8 = _DAT_00809d50;
  return;
}



//
// Function: epsDiagnosticModeChecker @ 0x0001e2d2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void epsDiagnosticModeChecker(undefined4 param_1)

{
  if ((((_DAT_00808794 != 0) && (_DAT_0080d49c == 0)) &&
      ((((fault_status_registers_t_00805df2.io_fault_status_1 & 2) != 0 &&
        ((_DAT_008068cc & 2) != 0)) ||
       (((fault_status_registers_t_00805df2.io_fault_status_1 & 4) != 0 &&
        ((_DAT_008068cc & 4) != 0)))))) && (_DAT_0080d49c = 6, param_1._0_2_ != 6)) {
    epsDiagnosticSnapshotCapture();
  }
  return;
}



//
// Function: epsDiagnosticSnapshotCapture @ 0x0001e33a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void epsDiagnosticSnapshotCapture(void)

{
  _DAT_0080d052 = fuel_demand_state_t_0080c9a4.command;
  _DAT_008016b4 = (uint)circular_buffer_t_0080c3fc.current_engine_rpm << 0x10;
  return;
}



//
// Function: epsDiagnosticVariablesInit @ 0x0001e358
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void epsDiagnosticVariablesInit(void)

{
  _DAT_008016b4 = 0;
  _DAT_008016b0 = 0x808788;
  return;
}



//
// Function: epsTimingCalculationSlowCycle40Coordinator @ 0x0001e36a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void epsTimingCalculationSlowCycle40Coordinator(void)

{
  _DAT_008016c0 = circular_buffer_t_0080c3fc.data_buffer_8;
  _DAT_0080d058 = lookupTableInterpolation((short *)&DAT_008016ba);
  _DAT_008016cc = circular_buffer_t_0080c3fc.data_buffer_8;
  _DAT_0080d05a = lookupTableInterpolation((short *)&DAT_008016c6);
  return;
}



//
// Function: initLookupTablePointers1 @ 0x0001e3a8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initLookupTablePointers1(void)

{
  _DAT_008016c2 = 0x8087a4;
  _DAT_008016bc = 0x808796;
  _DAT_008016ba = 2;
  _DAT_008016ce = 0x8087b2;
  _DAT_008016c8 = 0x808796;
  _DAT_008016c6 = 2;
  return;
}



//
// Function: governorFuelModeBlendCalculator @ 0x0001e3dc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void governorFuelModeBlendCalculator(void)

{
  ushort unaff_D2w;
  ushort unaff_D3w;
  undefined8 uVar1;
  
  if (timing_mode_control_t_0080965a.blend_factor != 0) {
    _DAT_008016ee = fuel_governor_state_t_0080d05c.rpm_window;
    uVar1 = tableInterpolationLookup((short *)&DAT_008016e8);
    unaff_D3w = (ushort)((ulonglong)uVar1 >> 0x20);
  }
  if (timing_mode_control_t_0080965a.blend_factor < 0x4000) {
    _DAT_00801702 = fuel_governor_state_t_0080d05c.rpm_window;
    uVar1 = tableInterpolationLookup((short *)&DAT_008016fc);
    unaff_D2w = (ushort)((ulonglong)uVar1 >> 0x20);
  }
  if (timing_mode_control_t_0080965a.blend_factor == 0x4000) {
    _DAT_008016e6 = unaff_D3w;
    return;
  }
  if (timing_mode_control_t_0080965a.blend_factor == 0) {
    _DAT_008016e6 = unaff_D2w;
    return;
  }
  _DAT_008016e6 =
       unaff_D2w +
       (short)((uint)timing_mode_control_t_0080965a.blend_factor *
               ((uint)unaff_D3w - (uint)unaff_D2w) >> 0xe);
  return;
}



//
// Function: governorFuelPidController @ 0x0001e462
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void governorFuelPidController(void)

{
  bool bVar1;
  word wVar2;
  short sVar4;
  int iVar3;
  undefined4 local_8;
  
  if (fuel_arbitrator_diag_t_0080cff8.rpm_target == 0) {
    _DAT_0080d092 = _DAT_0080d096;
  }
  else {
    _DAT_0080d092 = _DAT_00808836;
  }
  sVar4 = coreTableInterpolation();
  wVar2 = fuel_governor_state_t_0080d05c.cmd_raw;
  fuel_governor_state_t_0080d05c.rpm_window = _DAT_0080d092 + sVar4;
  if (_DAT_008087e0 < fuel_governor_state_t_0080d05c.rpm_window) {
    fuel_governor_state_t_0080d05c.rpm_window = _DAT_008087e0;
  }
  fuel_governor_state_t_0080d05c.rpm_window =
       fuel_governor_state_t_0080d05c.rpm_window - _DAT_008087e8;
  if ((diagnostic_state_buffer_t_00809654.diagnostic_mode == 0xb) ||
     (circular_buffer_t_0080c3fc.data_buffer_8 < _DAT_0080d096)) {
    fuel_governor_state_t_0080d05c.cmd_raw = exponentialMovingAverage();
    sVar4 = _DAT_0080d078;
    if ((short)_DAT_008087cc < (short)fuel_governor_state_t_0080d05c.cmd_raw) {
      fuel_governor_state_t_0080d05c.cmd_raw = _DAT_008087cc;
      _DAT_008016d6 = (short)_DAT_008087cc * 0x10000 + -0x80000000;
    }
    else if ((short)fuel_governor_state_t_0080d05c.cmd_raw < (short)_DAT_008087ce) {
      fuel_governor_state_t_0080d05c.cmd_raw = _DAT_008087ce;
      _DAT_008016d6 = (short)_DAT_008087ce * 0x10000 + -0x80000000;
    }
    epsControlModeSelector();
    if (((int)((int)_DAT_008087d6 + (uint)_DAT_0080d092) <
         (int)(uint)circular_buffer_t_0080c3fc.data_buffer_8) && (_DAT_00809652 < _DAT_008087d8)) {
      _DAT_008016e2 = (uint)_DAT_008087d4 << 0x10;
      fuel_governor_state_t_0080d05c.cmd_raw = 0;
      _DAT_008016d6 = -0x80000000;
    }
    else {
      fuel_governor_state_t_0080d05c.term_ff =
           (word)(((int)(short)fuel_governor_state_t_0080d05c.cmd_raw * (int)_DAT_0080d078) / 0x3c0)
      ;
      iVar3 = (int)_DAT_0080d07c *
              ((int)(short)fuel_governor_state_t_0080d05c.cmd_raw - (int)(short)wVar2);
      if (iVar3 < 0x783f0f) {
        if (iVar3 < -0x783fff) {
          fuel_governor_state_t_0080d05c.term_rate = 0x8000;
        }
        else {
          fuel_governor_state_t_0080d05c.term_rate =
               (word)((((int)(short)fuel_governor_state_t_0080d05c.cmd_raw - (int)(short)wVar2) *
                      (int)_DAT_0080d07c) / 0xf0);
        }
      }
      else {
        fuel_governor_state_t_0080d05c.term_rate = 0x7fff;
      }
      governorFuelModeBlendCalculator();
      fuel_governor_state_t_0080d05c.accum_hi = _DAT_008016e6 + _DAT_008087c0;
      if ((short)fuel_governor_state_t_0080d05c.accum_hi < 0) {
        fuel_governor_state_t_0080d05c.accum_hi = 0;
      }
      fuel_governor_state_t_0080d05c.limit_hi = _DAT_008016e6 + _DAT_008087d0;
      local_8._2_2_ = (word)(((int)_DAT_0080d078 - (int)sVar4) * 0x44 >> 3);
      iVar3 = _DAT_008016e2 +
              (int)(short)fuel_governor_state_t_0080d05c.cmd_raw * (int)(short)(_DAT_0080d07a << 2)
              + (int)(short)fuel_governor_state_t_0080d05c.cmd_raw * (int)(short)local_8._2_2_ * -8
              + _DAT_0080c9c4 * -0x10000;
      _DAT_008016e2 = (ushort)((uint)iVar3 >> 0x10);
      if ((short)_DAT_008016e2 < (short)fuel_governor_state_t_0080d05c.limit_hi) {
        bVar1 = (short)_DAT_008016e2 < (short)_DAT_008087d2;
        _DAT_008016e2 = iVar3;
        if (bVar1) {
          _DAT_008016e2 = (uint)_DAT_008087d2 << 0x10;
        }
      }
      else {
        _DAT_008016e2 = (uint)fuel_governor_state_t_0080d05c.limit_hi << 0x10;
      }
      fuel_governor_state_t_0080d05c.accum_lo = _DAT_008016e2;
      local_8 = (int)(short)_DAT_008016e2 +
                (int)(short)fuel_governor_state_t_0080d05c.term_rate +
                (int)(short)fuel_governor_state_t_0080d05c.term_ff;
      if ((_DAT_00803614 & 0x200) != 0) {
        local_8 = (uint)_DAT_0080d0aa + local_8;
      }
      if ((int)(uint)fuel_governor_state_t_0080d05c.accum_hi < local_8) {
        fuel_governor_state_t_0080d05c.out_cmd = fuel_governor_state_t_0080d05c.accum_hi;
      }
      else if (local_8 < (int)(uint)_DAT_008087c2) {
        fuel_governor_state_t_0080d05c.out_cmd = _DAT_008087c2;
      }
      else {
        fuel_governor_state_t_0080d05c.out_cmd = local_8._2_2_;
      }
      if (diagnostic_state_buffer_t_00809654.diagnostic_mode == 0xb) {
        _DAT_00809652 = fuel_governor_state_t_0080d05c.out_cmd;
      }
    }
  }
  return;
}



//
// Function: governorPidFuelCalculator @ 0x0001e78e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void governorPidFuelCalculator(void)

{
  word wVar1;
  undefined *puVar2;
  word wStack_6;
  
  puVar2 = (undefined *)((uint)_DAT_008087e4 * (uint)_DAT_00809d4c);
  if (&DAT_00009c40 < puVar2) {
    puVar2 = &DAT_00009c40;
  }
  _DAT_008016de = (int)puVar2 << 0x10;
  wStack_6 = (word)((int)_DAT_008087ca *
                    ((int)(short)fuel_governor_state_t_0080d05c.rpm_window -
                    (int)(short)circular_buffer_t_0080c3fc.data_buffer_8) >> 9);
  if ((short)_DAT_008087cc < (short)wStack_6) {
    wStack_6 = _DAT_008087cc;
  }
  else if ((short)wStack_6 < (short)_DAT_008087ce) {
    wStack_6 = _DAT_008087ce;
  }
  _DAT_008016d6 = (short)wStack_6 * 0x10000 + -0x80000000;
  fuel_governor_state_t_0080d05c.cmd_raw = wStack_6;
  epsInitializationWrapper();
  governorFuelModeBlendCalculator();
  fuel_governor_state_t_0080d05c.limit_cap = _DAT_008016e6 + _DAT_008087c4;
  _DAT_008016e2 =
       fuel_demand_state_t_0080c9a4.command -
       (short)(((int)(short)fuel_governor_state_t_0080d05c.cmd_raw * (int)_DAT_00808804) / 0x3c0);
  if ((_DAT_00803614 & 0x200) != 0) {
    _DAT_008016e2 = _DAT_008016e2 - _DAT_0080d0aa;
  }
  wVar1 = fuel_governor_state_t_0080d05c.limit_cap;
  if (((short)_DAT_008016e2 <= (short)fuel_governor_state_t_0080d05c.limit_cap) &&
     (wVar1 = _DAT_008016e2, (short)_DAT_008016e2 < (short)_DAT_008087c6)) {
    _DAT_008016e2 = _DAT_008087c6;
    wVar1 = _DAT_008016e2;
  }
  _DAT_008016e2 = wVar1;
  _DAT_008016e4 = 0;
  return;
}



//
// Function: intakeTemperatureTablesInit @ 0x0001e8a6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void intakeTemperatureTablesInit(void)

{
  _DAT_008016da = 0x8087e2;
  _DAT_008016d2 = 0x8087c8;
  epsControlModeInit();
  _DAT_008016ea = 0x807f42;
  _DAT_008016e8 = 2;
  _DAT_008016f6 = 400;
  _DAT_008016f2 = 0x807f68;
  _DAT_008016f0 = 2;
  _DAT_008016f8 = 0x807f72;
  _DAT_008016fe = 0x808002;
  _DAT_008016fc = 2;
  _DAT_0080170a = 400;
  _DAT_00801706 = 0x808028;
  _DAT_00801704 = 2;
  _DAT_0080170c = 0x808032;
  return;
}



//
// Function: epsAccelerationMonitor @ 0x0001e92e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint epsAccelerationMonitor(void)

{
  undefined2 uVar1;
  uint uVar2;
  word wVar3;
  
  wVar3 = fuel_governor_state_t_0080d05c.cmd_raw;
  if ((short)fuel_governor_state_t_0080d05c.cmd_raw < 0) {
    wVar3 = -fuel_governor_state_t_0080d05c.cmd_raw;
  }
  uVar2 = (uint)(short)wVar3;
  if ((int)(uint)_DAT_008087f0 < (int)uVar2) {
    _DAT_00801714 = 0;
    _DAT_00801716 = 0;
  }
  else {
    if (_DAT_00801714 < _DAT_008087ec) {
      _DAT_00801714 = _DAT_00801714 + 1;
    }
    uVar2 = CONCAT22((short)wVar3 >> 0xf,_DAT_008096a6);
    if (_DAT_008096a6 < _DAT_008087f4) {
      uVar2 = CONCAT22((short)wVar3 >> 0xf,_DAT_00801716);
      if (_DAT_00801716 < _DAT_008087ec) {
        _DAT_00801716 = _DAT_00801716 + 1;
      }
      else {
        _DAT_00801716 = 0;
      }
    }
  }
  if (_DAT_0080d076 != 0) {
    uVar2 = CONCAT22((short)(uVar2 >> 0x10),_DAT_00801716);
    if (_DAT_00801716 == _DAT_008087ec) {
      _DAT_0080d076 = 0;
      _DAT_00801710 = 0;
    }
    goto LAB_0001ea26;
  }
  if (_DAT_00801710 == 1) {
    uVar2 = (int)_DAT_008087fa + (uint)_DAT_0080d092;
    if (((int)(uint)circular_buffer_t_0080c3fc.data_buffer_8 <= (int)uVar2) ||
       (uVar2 = DAT_0080bdc7 & 4, (DAT_0080bdc7 & 4) != 0)) {
      uVar1 = (undefined2)(uVar2 >> 0x10);
      uVar2 = CONCAT22(uVar1,_DAT_008096a6);
      if ((_DAT_008096a6 < _DAT_008087f4) ||
         (uVar2 = CONCAT22(uVar1,_DAT_00801714), _DAT_00801714 != _DAT_008087ec)) goto LAB_0001e9f8;
    }
  }
  else {
LAB_0001e9f8:
    uVar2 = CONCAT22((short)(uVar2 >> 0x10),_DAT_008096a6);
    if (_DAT_008096a6 <= _DAT_008087f2) goto LAB_0001ea26;
  }
  _DAT_0080d076 = 1;
LAB_0001ea26:
  if (_DAT_0080d076 == 0) {
    if (_DAT_0080d07e == 0) {
      uVar1 = (undefined2)(uVar2 >> 0x10);
      uVar2 = CONCAT22(uVar1,engine_control_flags_t_008035d6.fuel_demand_control) & 0xffff1000;
      if (((engine_control_flags_t_008035d6.fuel_demand_control & 0x1000) != 0) &&
         ((uVar2 = CONCAT22(uVar1,fuel_governor_state_t_0080d05c.cmd_raw),
          _DAT_008087f8 < (short)fuel_governor_state_t_0080d05c.cmd_raw ||
          ((uVar2 = CONCAT22(uVar1,fuel_governor_state_t_0080d05c.cmd_raw),
           _DAT_008087f6 < (short)fuel_governor_state_t_0080d05c.cmd_raw &&
           (uVar2 = (int)_DAT_008087ee + (uint)circular_buffer_t_0080c3fc.data_buffer_8,
           (int)uVar2 < (int)(uint)_DAT_00801712)))))) {
        _DAT_0080d07e = 1;
      }
    }
    else if ((_DAT_0080d07e == 1) &&
            ((uVar2 = (int)_DAT_008087f6 - (int)_DAT_008087fc,
             (int)(short)fuel_governor_state_t_0080d05c.cmd_raw < (int)uVar2 ||
             ((uVar2 = CONCAT22((short)(uVar2 >> 0x10),fuel_governor_state_t_0080d05c.cmd_raw),
              (short)fuel_governor_state_t_0080d05c.cmd_raw < _DAT_008087f8 &&
              (uVar2 = (int)_DAT_008087ee + (uint)_DAT_00801712,
              (int)uVar2 < (int)(uint)circular_buffer_t_0080c3fc.data_buffer_8)))))) {
      _DAT_0080d07e = 0;
    }
  }
  if (_DAT_0080d07e == 1) {
    _DAT_00801710 = 1;
    _DAT_0080d08a = 0x8087fe;
  }
  _DAT_00801712 = circular_buffer_t_0080c3fc.data_buffer_8;
  return uVar2;
}



//
// Function: epsRpmTrackingInit @ 0x0001eade
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void epsRpmTrackingInit(void)

{
  _DAT_00801712 = circular_buffer_t_0080c3fc.data_buffer_8;
  _DAT_00801714 = 0;
  _DAT_00801716 = 0;
  return;
}



//
// Function: epsControlModeReset @ 0x0001eaf6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void epsControlModeReset(void)

{
  _DAT_00801710 = 0;
  return;
}



//
// Function: epsOverrideChecker @ 0x0001eafe
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint epsOverrideChecker(undefined4 param_1)

{
  uint in_D0;
  
  if (param_1._0_2_ != 0) {
    return 1;
  }
  if (_DAT_0080d082 != 0) {
    _DAT_0080d080 = _DAT_0080d082;
    _DAT_0080d08e = &DAT_0080d084;
    return 1;
  }
  return in_D0 & 0xffff0000;
}



//
// Function: epsControlModeSelector @ 0x0001eb2a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void epsControlModeSelector(void)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_D2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((uint)unaff_D2 >> 0x10);
  epsAccelerationMonitor();
  iVar1 = epsRpmTargetModeChecker();
  uVar2 = epsOverrideChecker(CONCAT22((short)iVar1,uVar3));
  if ((short)uVar2 == 0) {
    _DAT_0080d080 = _DAT_0080d07e;
    if (_DAT_0080d07e == 0) {
      _DAT_0080d08e = (undefined2 *)&DAT_00808804;
    }
    else {
      _DAT_0080d08e = _DAT_0080d08a;
    }
  }
  _DAT_0080d078 = *_DAT_0080d08e;
  _DAT_0080d07a = _DAT_0080d08e[1];
  _DAT_0080d07c = _DAT_0080d08e[2];
  return;
}



//
// Function: epsInitializationWrapper @ 0x0001eb86
//

void epsInitializationWrapper(void)

{
  epsRpmTrackingInit();
  epsCounterReset();
  return;
}



//
// Function: epsControlModeInit @ 0x0001eb94
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void epsControlModeInit(void)

{
  epsControlModeReset();
  _DAT_0080d07e = 0;
  _DAT_0080d084 = _DAT_00808804;
  _DAT_0080d086 = _DAT_00808806;
  _DAT_0080d088 = _DAT_00808808;
  return;
}



//
// Function: epsDiagnosticModeHandler @ 0x0001ebcc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void epsDiagnosticModeHandler(void)

{
  undefined2 uStack_6;
  
  if ((diagnostic_state_buffer_t_00809654.diagnostic_mode == 0xb) && (_DAT_0080d076 == 1)) {
    if ((_DAT_0080880e < (short)fuel_governor_state_t_0080d05c.cmd_raw) ||
       (((short)fuel_governor_state_t_0080d05c.cmd_raw < _DAT_00808810 || (_DAT_008096aa != 0)))) {
      _DAT_0080d07e = 0;
      _DAT_00801718 = 0;
    }
    else {
      if (_DAT_00801718 < _DAT_00808812) {
        _DAT_00801718 = _DAT_00801718 + 1;
      }
      uStack_6 = (short)((uint)_DAT_008096a8 * (uint)_DAT_0080374a >> 0xb);
      if (_DAT_0080880a < uStack_6) {
        _DAT_0080d07e = 0;
      }
      else if ((((_DAT_0080d07e == 0) && (_DAT_00801718 == _DAT_00808812)) &&
               ((engine_control_flags_t_008035d6.fuel_demand_control & 0x4000) != 0)) &&
              ((int)uStack_6 < (int)_DAT_0080880a - (int)_DAT_00808814)) {
        if (((engine_control_flags_t_008035d6.fuel_demand_control & 0x2000) == 0) ||
           (_DAT_0080880c < uStack_6)) {
          _DAT_0080d07e = 2;
          _DAT_0080d08a = 0x80881c;
        }
        else if ((int)uStack_6 < (int)_DAT_0080880c - (int)_DAT_00808814) {
          _DAT_0080d07e = 3;
          _DAT_0080d08a = 0x808816;
        }
      }
    }
  }
  return;
}



//
// Function: epsCounterReset @ 0x0001ecee
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void epsCounterReset(void)

{
  _DAT_00801718 = 0;
  return;
}



//
// Function: fuelTimingOffsetCalculator @ 0x0001ecf6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelTimingOffsetCalculator(void)

{
  if (((engine_control_flags_t_008035d6.engine_operating_state & 8) == 0) ||
     (((fault_status_registers_t_00805df2.io_fault_status_4 & 2) != 0 && ((_DAT_008068d2 & 2) != 0))
     )) {
    _DAT_0080171c = 0;
  }
  else if ((DAT_0080171a == '\0') && ((DAT_0080bdc7 & 0x20) != 0)) {
    _DAT_0080171c = _DAT_00808828 + _DAT_0080171c;
    if (_DAT_0080882a < _DAT_0080171c) {
      _DAT_0080171c = _DAT_0080882a;
    }
  }
  else if (((DAT_0080171b == '\0') && ((DAT_0080bdc7 & 0x40) != 0)) &&
          (_DAT_0080171c = _DAT_0080171c - _DAT_00808828, _DAT_0080171c < _DAT_0080882c)) {
    _DAT_0080171c = _DAT_0080882c;
  }
  _DAT_0080d096 = _DAT_0080171c + _DAT_00803698;
  if (_DAT_00808838 < _DAT_0080d096) {
    _DAT_0080d096 = _DAT_00808838;
  }
  else if (_DAT_0080d096 < _DAT_00808836) {
    _DAT_0080d096 = _DAT_00808836;
  }
  if ((_DAT_008035ec & 1) == 0) {
    _DAT_0080557c = 0;
  }
  else {
    _DAT_0080557c = _DAT_0080171c;
  }
  DAT_0080171a = -((DAT_0080bdc7 & 0x20) != 0) & 1;
  DAT_0080171b = -((DAT_0080bdc7 & 0x40) != 0) & 1;
  return;
}



//
// Function: initVP44StatusFlags @ 0x0001ee02
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort initVP44StatusFlags(void)

{
  if ((_DAT_008035ec & 1) == 0) {
    _DAT_0080557c = 0;
  }
  _DAT_0080d098 = 0;
  _DAT_0080171c = _DAT_0080557c;
  return _DAT_008035ec & 1;
}



//
// Function: epsRpmTargetModeChecker @ 0x0001ee2c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int epsRpmTargetModeChecker(void)

{
  ushort uVar1;
  undefined4 in_D0;
  
  uVar1 = (ushort)((uint)in_D0 >> 0x10);
  if ((fuel_arbitrator_diag_t_0080cff8.rpm_target != 0) &&
     (uVar1 = 0, (engine_control_flags_t_008035d6.fuel_demand_control & 0x8000) != 0)) {
    _DAT_0080d080 = 4;
    _DAT_0080d08e = 0x808822;
    return 1;
  }
  return (uint)uVar1 << 0x10;
}



//
// Function: engineModeTimingAdjuster @ 0x0001ee5c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engineModeTimingAdjuster(void)

{
  bool bVar1;
  bool bVar2;
  
  bVar2 = _DAT_0080926e < _DAT_0080882e;
  if ((_DAT_008035ec & 0x4000) == 0) {
    bVar1 = false;
  }
  else if (_DAT_0080d098 == 0) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (engine_operating_mode_t_0080c810.state == 1) {
    _DAT_0080171e = 0;
    if (bVar2) {
      _DAT_0080d094 = _DAT_00808830;
    }
    else {
      _DAT_0080d094 = 0;
    }
  }
  else if (engine_operating_mode_t_0080c810.state != 2) {
    if ((bVar2) && (_DAT_0080171e < _DAT_00808832)) {
      _DAT_0080171e = _DAT_0080171e + 1;
    }
    if ((engine_operating_mode_t_0080c810.state == 3) &&
       ((_DAT_00808832 <= _DAT_0080171e || (!bVar2)))) {
      if (_DAT_00808834 < _DAT_0080d094) {
        _DAT_0080d094 = _DAT_0080d094 - _DAT_00808834;
      }
      else {
        _DAT_0080d094 = 0;
      }
    }
  }
  if ((_DAT_0080d096 < _DAT_0080d094) && (!bVar1)) {
    _DAT_0080d096 = _DAT_0080d094;
  }
  return;
}



//
// Function: timingOffsetCalculatorWrapper @ 0x0001ef18
//

void timingOffsetCalculatorWrapper(void)

{
  fuelTimingOffsetCalculator();
  return;
}



//
// Function: qadcDataCollectionStateMachine @ 0x0001ef20
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qadcDataCollectionStateMachine(void)

{
  byte bVar1;
  undefined2 *puVar2;
  
  if (_DAT_00801722 == 2) {
    if (_DAT_00fffd24 == 5) {
      if ((_DAT_00fffd06 & 1) == 0) {
        if (circular_buffer_t_0080c3fc.entry_count == 0) {
          _DAT_00801722 = 0;
          _DAT_00801720 = circular_buffer_t_0080c3fc.data_buffer_2;
          _DAT_00fffd24 = 3;
          DAT_00fffd42 = 0xbd;
          _DAT_00fffd26 = circular_buffer_t_0080c3fc.data_buffer_2;
          DAT_00fffd43 = 0xfd;
        }
        else {
          _DAT_00801722 = 1;
        }
      }
    }
    else {
      _DAT_00fffd24 = 5;
      DAT_00fffd42 = 0xbd;
      _DAT_00fffd26 = 0;
      DAT_00fffd43 = 0x3d;
      _DAT_00fffd28 = 0;
      DAT_00fffd44 = 0xfd;
      _DAT_00fffd2a = 0;
      DAT_00fffd45 = 0xfd;
    }
  }
  else if (_DAT_00801722 == 0) {
    puVar2 = (undefined2 *)&DAT_00fffd08;
    bVar1 = 4;
    do {
      if (_DAT_0080d19c != 0) {
        *(undefined2 *)(_DAT_00801730 + (uint)_DAT_00801720) = *puVar2;
      }
      _DAT_00801720 = _DAT_00801720 + 2;
      if (0xfff < _DAT_00801720) {
        _DAT_00801720 = 0;
        DAT_00801734 = 1;
        bVar1 = 0x10;
      }
      puVar2 = puVar2 + 1;
      bVar1 = bVar1 + 1;
    } while (bVar1 < 0x10);
    if (circular_buffer_t_0080c3fc.entry_count == 0) {
      _DAT_00fffd26 = _DAT_00801720;
      DAT_00fffd43 = 0xfd;
    }
    else {
      _DAT_00801722 = 1;
    }
  }
  if (_DAT_00801722 == 1) {
    _DAT_00fffd24 = 6;
    DAT_00fffd42 = 0x3d;
    _DAT_00fffd26 = 2;
    DAT_00fffd43 = 0xbd;
    _DAT_00fffd28 = *(undefined2 *)((short)_DAT_0080c3fa * 2 + 0x80bdfa);
    DAT_00fffd44 = 0xfd;
    _DAT_00fffd2a = (ushort)*(byte *)((short)_DAT_0080c3fa + 0x80c1fa);
    DAT_00fffd45 = 0x3d;
    _DAT_00801722 = 2;
    circular_buffer_t_0080c3fc.entry_count = circular_buffer_t_0080c3fc.entry_count - 1;
    _DAT_0080c3fa = _DAT_0080c3fa + 1 & 0x1ff;
  }
  return;
}



//
// Function: tpuQadcInterruptHandler @ 0x0001f068
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 tpuQadcInterruptHandler(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  DAT_00fffc1f = DAT_00fffc1f & 0x7f;
  qadcDataCollectionStateMachine();
  _DAT_00fffc1a = _DAT_00fffc1a | 0x8000;
  return CONCAT44(in_D0,in_D1);
}



//
// Function: emptyStubWrapper2 @ 0x0001f08e
//

void emptyStubWrapper2(void)

{
  return;
}



//
// Function: initTPU @ 0x0001f090
//

/* WARNING: Removing unreachable block (ram,0x0001f19e) */
/* WARNING: Removing unreachable block (ram,0x0001f1b0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initTPU(void)

{
  ushort uVar1;
  
  emptyStubWrapper2();
  _DAT_00808f06 = tpuQadcInterruptHandler;
  DAT_00fffc16 = 0x7b;
  DAT_00fffc17 = 0xfe;
  DAT_00fffc15 = 0xff;
  _DAT_00fffc18 = 0x8004;
  _DAT_00fffc1c = _DAT_00fffc1c & 0xf0f0 | 0xf02;
  _DAT_00fffc1a = _DAT_00fffc1a & 0x8000 | 0x1001;
  _DAT_00fffd20 = 0;
  DAT_00fffd40 = 0x7e;
  _DAT_00fffd22 = 0;
  DAT_00fffd41 = 0x7e;
  _DAT_00fffd24 = 3;
  DAT_00fffd42 = 0xbd;
  _DAT_00fffd26 = _DAT_00801720;
  DAT_00fffd43 = 0xfd;
  uVar1 = 4;
  do {
    *(undefined2 *)(&DAT_00fffd20 + (uint)uVar1 * 2) = 0;
    (&DAT_00fffd40)[uVar1] = 0xfd;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x10);
  _DAT_0080d19c = 1;
  _DAT_00801730 = 0x8034f8;
  _DAT_00801722 = 0;
  if (DAT_00801734 == '\0') {
    do {
    } while( true );
  }
  _DAT_00fffc1c = _DAT_00fffc1c | 0x8000;
  _DAT_00fffc1a = _DAT_00fffc1a & 0xff00 | 0x8023;
  return;
}



//
// Function: memcpy @ 0x0001f1e0
//

void memcpy(undefined1 *param_1,undefined1 *param_2,undefined4 param_3)

{
  ushort uVar1;
  
  for (uVar1 = 0; uVar1 < param_3._0_2_; uVar1 = uVar1 + 1) {
    *param_1 = *param_2;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}



//
// Function: dualTableFuelInterpolationCalculator @ 0x0001f1fa
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void dualTableFuelInterpolationCalculator(void)

{
  short sVar1;
  short sVar2;
  
  _DAT_0080173c = circular_buffer_t_0080c3fc.data_buffer_8;
  _DAT_00801748 = _DAT_0080926e;
  sVar1 = lookupTableInterpolation((short *)&DAT_00801742);
  sVar2 = lookupTableInterpolation((short *)&DAT_00801736);
  _DAT_0080d0aa = sVar1 + sVar2;
  return;
}



//
// Function: initRpmLookupTables @ 0x0001f23e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initRpmLookupTables(void)

{
  _DAT_0080173c = circular_buffer_t_0080c3fc.data_buffer_8;
  _DAT_00801738 = 0x80883a;
  _DAT_0080173e = 0x80884e;
  _DAT_00801736 = 2;
  _DAT_00801748 = _DAT_0080926e;
  _DAT_00801744 = 0x808862;
  _DAT_0080174a = 0x808876;
  _DAT_00801742 = 2;
  return;
}



//
// Function: crankStateVariablesReset @ 0x0001f28c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void crankStateVariablesReset(void)

{
  CKIITAES = 0;
  _DAT_0080d050 = 0;
  CKIIFLES = 0;
  _DAT_0080557e = 0;
  _DAT_00805586 = 0;
  _DAT_00805582 = 0;
  _DAT_0080558a = 0;
  _DAT_0080d04e = 0;
  _DAT_0080558e = 0;
  _DAT_00805590 = _DAT_0080175c;
  return;
}



//
// Function: crankFuelAndTimingBufferStore @ 0x0001f2ce
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void crankFuelAndTimingBufferStore(void)

{
  short sVar1;
  short sVar2;
  
  _DAT_0080175c = (short)((_DAT_00805590 + 2) % 3);
  *(undefined4 *)((short)(_DAT_0080175c * 2) * 8 + 0x80559c) = _DAT_00805f2c;
  *(int *)((short)(_DAT_0080175c * 2) * 8 + 0x8055a0) = _CKINFRAJ;
  *(undefined4 *)((short)(_DAT_0080175c * 2) * 8 + 0x8055ce) = _DAT_00805f6c;
  *(int *)((short)(_DAT_0080175c * 2) * 8 + 0x8055d2) = _CKEXFLAJ;
  if (_DAT_00803734 != 0) {
    if (_DAT_00803734 == 1) {
      if ((_DAT_0080558e & 0xc) == 0) {
        *(undefined2 *)(_DAT_0080175c * 2 + 0x805594) = 0;
      }
      else {
        *(undefined2 *)(_DAT_0080175c * 2 + 0x805594) = 1;
      }
      *(uint *)((short)(_DAT_0080175c * 2) * 8 + 0x8055a8) = (uint)_DAT_00803736 * 0x465;
      *(uint *)((short)(_DAT_0080175c * 2) * 8 + 0x8055a4) = (uint)_DAT_00803736 * 0x465;
      *(undefined4 *)((short)(_DAT_0080175c * 2) * 8 + 0x8055da) = 0;
      *(undefined4 *)((short)(_DAT_0080175c * 2) * 8 + 0x8055d6) = 0;
      return;
    }
    *(undefined4 *)((short)(_DAT_0080175c * 2) * 8 + 0x8055a8) = 0;
    *(undefined4 *)((short)(_DAT_0080175c * 2) * 8 + 0x8055a4) = 0;
    *(undefined4 *)((short)(_DAT_0080175c * 2) * 8 + 0x8055da) = 0;
    *(undefined4 *)((short)(_DAT_0080175c * 2) * 8 + 0x8055d6) = 0;
    return;
  }
  *(ushort *)(_DAT_0080175c * 2 + 0x805594) = (ushort)(_DAT_0080558e != 0);
  *(uint *)((short)(_DAT_0080175c * 2) * 8 + 0x8055a4) = (uint)_DAT_0080d0c0 * 0x465;
  sVar1 = _DAT_0080175c << 4;
  *(uint *)(sVar1 + 0x8055d6) = (uint)_DAT_0080d0ba << 7;
  if (0x63ff < CKAJIIFL) {
    *(undefined4 *)((short)(_DAT_0080175c * 2) * 8 + 0x8055a8) = _DAT_00805582;
    *(undefined4 *)((short)(_DAT_0080175c * 2) * 8 + 0x8055da) = _DAT_0080558a;
    return;
  }
  sVar2 = _DAT_0080175c << 4;
  *(int *)(sVar2 + 0x8055a8) = _CKINFRAJ + (*(int *)(sVar1 + 0x8055a4) - _DAT_0080557e);
  *(int *)((short)(_DAT_0080175c * 2) * 8 + 0x8055da) =
       _CKEXFLAJ + (*(int *)(sVar2 + 0x8055d6) - _DAT_00805586);
  return;
}



//
// Function: crankFuelCalculationAndProtection @ 0x0001f4f8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint crankFuelCalculationAndProtection(void)

{
  undefined4 in_D0;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  undefined1 *puVar5;
  
  puVar5 = &stack0xffffffe0;
  uVar3 = CONCAT22((short)((uint)in_D0 >> 0x10),_DAT_008035ec) & 0xffff2000;
  if ((_DAT_008035ec & 0x2000) != 0) {
    if ((ushort)(((uint)_DAT_0080373a << 8) / 10) <= CKAJIIFL) {
      _DAT_0080d04e = 1;
    }
    _CKINFRAJ = _DAT_00805f2c - *(int *)((short)(_DAT_00805590 * 2) * 8 + 0x80559c);
    _CKEXFLAJ = _DAT_00805f6c - *(int *)((short)(_DAT_00805590 * 2) * 8 + 0x8055ce);
    if ((circular_buffer_t_0080c3fc.data_buffer_8 != 0) && (_DAT_00805f40 != 0)) {
      if (_DAT_0080888a < _DAT_00801758) {
        _DAT_0080558e = _DAT_0080558e | 2;
      }
      else {
        _DAT_00801758 = _DAT_00801758 + 1;
      }
    }
    if (((circular_buffer_t_0080c3fc.data_buffer_8 != 0) &&
        ((fault_status_registers_t_00805df2.sensor_fault_status & 0x800) != 0)) &&
       ((_DAT_008068c4 & 0x800) != 0)) {
      if (_DAT_0080888a < _DAT_0080175a) {
        _DAT_0080558e = _DAT_0080558e | 4;
      }
      else {
        _DAT_0080175a = _DAT_0080175a + 1;
      }
    }
    uVar3 = (uint)_DAT_00803734;
    if (_DAT_00803734 == 0) {
      uVar4 = (short)_DAT_00805f2c - _DAT_00801750;
      _DAT_0080174e = _DAT_00805f2c;
      uVar4 = (ushort)((uint)uVar4 * (uint)_DAT_0080d0c2 >> 8);
      if (-(uint)uVar4 - 1 < _DAT_0080557e) {
        _DAT_0080558e = _DAT_0080558e | 8;
      }
      _DAT_0080557e = uVar4 + _DAT_0080557e;
      uVar1 = proportionalCalculation(_DAT_0080557e,0x6400,(uint)_DAT_0080d0c0 * 0x465);
      uVar4 = (short)_DAT_00805f6c - _DAT_00801754;
      _DAT_00801752 = _DAT_00805f6c;
      uVar4 = (ushort)((uint)uVar4 * (uint)_DAT_0080d0c2 >> 8);
      if (-(uint)uVar4 - 1 < _DAT_00805586) {
        _DAT_0080558e = _DAT_0080558e | 8;
      }
      _DAT_00805586 = uVar4 + _DAT_00805586;
      uVar2 = proportionalCalculation(_DAT_00805586,0x6400,(uint)_DAT_0080d0ba << 7);
      puVar5 = &stack0xffffffe0;
      if ((uVar1 < uVar2) || (uVar3 = (uint)CKAJIIES, uVar1 < uVar3)) {
        if ((uVar1 < CKAJIIES) && (uVar3 = (uint)CKAJIIES, uVar2 < uVar3)) {
          _DAT_0080d0ac = 3;
          CKAJIIFL = CKAJIIES;
        }
        else {
          uVar3 = (uint)CKAJIIES;
          _DAT_0080d0ac = 2;
          CKAJIIFL = (word)uVar2;
        }
      }
      else {
        _DAT_0080d0ac = 1;
        CKAJIIFL = (word)uVar1;
      }
    }
    else if (_DAT_00803734 == 1) {
      puVar5 = &stack0xffffffd4;
      uVar3 = proportionalCalculation
                        (_DAT_00805f2c - *(int *)((short)(_DAT_00805590 * 2) * 8 + 0x80559c),0x6400,
                         (uint)_DAT_00803736 * 0x465);
      CKAJIIFL = (word)uVar3;
      _DAT_0080d0ac = 1;
    }
    else {
      CKAJIIFL = CKAJIIES;
      _DAT_0080d0ac = 3;
    }
    if (((_DAT_00805582 == 0) && (_DAT_0080558a == 0)) && (0x63ff < CKAJIIFL)) {
      _DAT_00805582 = _DAT_00805f2c - *(int *)((short)(_DAT_00805590 * 2) * 8 + 0x80559c);
      uVar3 = _DAT_00805f6c - *(int *)((short)(_DAT_00805590 * 2) * 8 + 0x8055ce);
      _DAT_0080558a = uVar3;
    }
    if ((_DAT_00801756 == 1) || (_DAT_0080d050 == 1)) {
      *(undefined4 *)(puVar5 + -4) = 0x1f7b4;
      crankFuelAndTimingBufferStore();
      *(undefined4 *)(puVar5 + -4) = 0x1f7b8;
      uVar3 = crankStateVariablesReset();
    }
    _DAT_00801756 = CKIITAES;
  }
  return uVar3;
}



//
// Function: initParameterScalingSystem @ 0x0001f7cc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initParameterScalingSystem(void)

{
  short local_1c [4];
  undefined4 local_14;
  short local_10 [4];
  undefined4 local_8;
  
  _DAT_0080174e = _DAT_00805f2c;
  _DAT_00801752 = _DAT_00805f6c;
  _DAT_0080d0c2 = 0x100;
  local_1c[0] = 2;
  local_1c[1] = 0x80;
  local_1c[2] = -0x7774;
  local_14 = 0x8088a4;
  local_10[0] = 2;
  local_10[1] = 0x80;
  local_10[2] = -0x7774;
  local_8 = 0x808898;
  if (_DAT_00803734 == 0) {
    local_1c[3] = _DAT_00803738;
    _DAT_0080d0ba = lookupTableInterpolation(local_1c);
    local_10[3] = _DAT_00803738;
    _DAT_0080d0c0 = lookupTableInterpolation(local_10);
  }
  return;
}



//
// Function: pwmOutputInit @ 0x0001f860
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void pwmOutputInit(void)

{
  _DAT_00ffd00c =
       (DAT_008088b3 & 7) << 0xc |
       (ushort)(30000000 / ((uint)DAT_008088b2 * (uint)_DAT_008088b0)) & 0xfff;
  if (DAT_008088b4 == '\x01') {
    _DAT_00ffd00c = _DAT_00ffd00c | 0x8000;
  }
  return;
}



//
// Function: fuelSmokeLimiterCalculator @ 0x0001f8aa
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelSmokeLimiterCalculator(void)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  
  if ((_DAT_0080d0aa < fuel_demand_state_t_0080c9a4.command) && (_DAT_0080d0aa < _DAT_0080c9d8)) {
    uVar2 = proportionalCalculation
                      ((uint)fuel_demand_state_t_0080c9a4.command - (uint)_DAT_0080d0aa,0x6400,
                       (uint)_DAT_0080c9d8 - (uint)_DAT_0080d0aa);
    if (uVar2 < 0x7f81) {
      _DAT_0080d0c8 = (undefined2)uVar2;
    }
    else {
      _DAT_0080d0c8 = 0x7f80;
    }
  }
  else {
    _DAT_0080d0c8 = 0;
  }
  if (_DAT_0080d0aa < fuel_demand_state_t_0080c9a4.command) {
    if ((fuel_limit_arbitration_t_0080cc4a.rate_limit < circular_buffer_t_0080c3fc.data_buffer_8) &&
       (_DAT_0080cc5c != 0)) {
      iVar1 = ((uint)fuel_limit_arbitration_t_0080cc4a.offset_value +
              (uint)circular_buffer_t_0080c3fc.data_buffer_8) -
              (uint)fuel_limit_arbitration_t_0080cc4a.rate_limit;
      uVar2 = iVar1 * 0x1111;
      if ((uint)fuel_limit_arbitration_t_0080cc4a.comparison_low *
          (uint)fuel_limit_arbitration_t_0080cc4a.comparison_high < uVar2 ||
          (uint)fuel_limit_arbitration_t_0080cc4a.comparison_low *
          (uint)fuel_limit_arbitration_t_0080cc4a.comparison_high + iVar1 * -0x1111 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = fuel_limit_arbitration_t_0080cc4a.comparison_low -
                (short)(uVar2 / fuel_limit_arbitration_t_0080cc4a.comparison_high);
        if (0x1700 < uVar3) {
          uVar3 = 0x1700;
        }
      }
      if (uVar3 <= _DAT_0080d0aa) {
        _DAT_0080d0c6 = 0;
        return;
      }
      uVar3 = uVar3 - _DAT_0080d0aa;
    }
    else {
      if (_DAT_0080c9d8 <= _DAT_0080d0aa) {
        _DAT_0080d0c6 = 0;
        return;
      }
      uVar3 = _DAT_0080c9d8 - _DAT_0080d0aa;
    }
    uVar2 = (uint)(ushort)(fuel_demand_state_t_0080c9a4.command - _DAT_0080d0aa) * 0x6400;
    if (uVar2 < (uint)uVar3 * 0x7f80) {
      _DAT_0080d0c6 = (undefined2)(uVar2 / uVar3);
    }
    else {
      _DAT_0080d0c6 = 0x7f80;
    }
  }
  else {
    _DAT_0080d0c6 = 0;
  }
  return;
}



//
// Function: insiteActiveFaultListBuilder @ 0x0001fa00
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void insiteActiveFaultListBuilder(void)

{
  char cVar2;
  uint uVar1;
  byte bVar3;
  
  if (DAT_0080d41a < 0x14) {
    *(byte *)insite_session_t_0080d407._5_4_ = insite_session_t_0080d407.command_byte;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    cVar2 = (char)_DAT_00804f44;
    *(char *)insite_session_t_0080d407._5_4_ = cVar2;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    bVar3 = 1;
    for (; cVar2 != '\0'; cVar2 = cVar2 + -1) {
      *(byte *)insite_session_t_0080d407._5_4_ = (&DAT_00804e7c)[(short)(ushort)bVar3] | 0x80;
      insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
           insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      bVar3 = bVar3 + 1;
    }
    insite_session_t_0080d407.param_result = DAT_0080d41a + insite_session_t_0080d407.param_result;
    DAT_0080d419 = DAT_0080d419 - DAT_0080d41a;
    return;
  }
  uVar1 = insiteMultiFrameResponseBuilder(0xe000f);
  if ((char)uVar1 == '\0') {
    bVar3 = 1;
    while (DAT_0080d444 <= DAT_0080d445) {
      while (cVar2 = DAT_0080d446 + -1, DAT_0080d446 != '\0') {
        DAT_0080d446 = cVar2;
        *(byte *)insite_session_t_0080d407._5_4_ = (&DAT_00804e7c)[(short)(ushort)bVar3] & 0x80;
        bVar3 = bVar3 + 1;
        insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
             insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      }
      if (DAT_0080d444 == DAT_0080d445) {
        DAT_0080d446 = cVar2;
        responseBufferFinalize();
        insite_session_t_0080d407._9_4_ = insite_session_t_0080d407._5_4_;
        DAT_0080d444 = DAT_0080d444 + 1;
        insite_session_t_0080d407.param_result = 0;
      }
      else {
        DAT_0080d446 = cVar2;
        insiteMultiFrameContinuation();
      }
    }
  }
  return;
}



//
// Function: insiteFaultDetailBuilder @ 0x0001fafe
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void insiteFaultDetailBuilder(void)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  byte bVar7;
  byte *pbVar8;
  byte *pbVar9;
  
  if (DAT_0080d41a < 0x14) {
    *(byte *)insite_session_t_0080d407._5_4_ = insite_session_t_0080d407.command_byte;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    if (insite_session_t_0080d407.response_ptr._0_1_ == '\0') {
      *(char *)insite_session_t_0080d407._5_4_ = (char)_DAT_00804f40 * '\x02';
      insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
           insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      uVar4 = _DAT_00804f40;
      uVar6 = 1;
      while ((char)uVar4 != '\0') {
        uVar5 = (ushort)(byte)((char)uVar6 + 1);
        sVar2 = (ushort)(byte)(&DAT_00804e7c)[(short)uVar6] * 6;
        uVar6 = uVar5;
        if (((*(ushort *)(&DAT_008065ce + sVar2) & 0x2000) == 0) && ((&DAT_008065d0)[sVar2] != '\0')
           ) {
          *(undefined *)insite_session_t_0080d407._5_4_ = (&DAT_008065d0)[sVar2];
          insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
               insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
          *(byte *)insite_session_t_0080d407._5_4_ =
               (byte)((int)(uint)*(ushort *)(&DAT_008065ce + sVar2) >> 7) & 0x3f;
          insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
               insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
          uVar4 = (ushort)(byte)((char)uVar4 - 1);
        }
      }
    }
    else {
      *(char *)insite_session_t_0080d407._5_4_ =
           ((char)_DAT_00804f42 + (char)_DAT_00804f40) * '\x03';
      insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
           insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      uVar4 = _DAT_00804f40;
      uVar6 = 1;
      while ((char)uVar4 != '\0') {
        uVar5 = (ushort)(byte)((char)uVar6 + 1);
        bVar7 = (&DAT_00804e7c)[(short)uVar6];
        sVar2 = (ushort)bVar7 * 6;
        uVar6 = uVar5;
        if (((*(ushort *)(&DAT_008065ce + sVar2) & 0x2000) == 0) && ((&DAT_008065d0)[sVar2] != '\0')
           ) {
          *(undefined *)insite_session_t_0080d407._5_4_ = (&DAT_008065d0)[sVar2];
          insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
               insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
          *(byte *)insite_session_t_0080d407._5_4_ =
               (byte)((int)(uint)*(ushort *)(&DAT_008065ce + sVar2) >> 7) & 0x3f | 0x80;
          insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
               insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
          *(undefined *)insite_session_t_0080d407._5_4_ =
               (&DAT_00804fcd)[(short)((ushort)bVar7 * 5) * 2];
          insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
               insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
          uVar4 = (ushort)(byte)((char)uVar4 - 1);
        }
      }
      uVar4 = _DAT_00804f42;
      uVar6 = 1;
      while ((char)uVar4 != '\0') {
        uVar5 = (ushort)(byte)((char)uVar6 + 1);
        bVar7 = (&DAT_00804e9c)[(short)uVar6];
        sVar2 = (ushort)bVar7 * 6;
        uVar6 = uVar5;
        if (((*(ushort *)(&DAT_008065ce + sVar2) & 0x2000) == 0) && ((&DAT_008065d0)[sVar2] != '\0')
           ) {
          *(undefined *)insite_session_t_0080d407._5_4_ = (&DAT_008065d0)[sVar2];
          insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
               insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
          *(byte *)insite_session_t_0080d407._5_4_ =
               (byte)((int)(uint)*(ushort *)(&DAT_008065ce + sVar2) >> 7) & 0x3f | 0xc0;
          insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
               insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
          *(undefined *)insite_session_t_0080d407._5_4_ =
               (&DAT_00804fcd)[(short)((ushort)bVar7 * 5) * 2];
          insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
               insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
          uVar4 = (ushort)(byte)((char)uVar4 - 1);
        }
      }
    }
    insite_session_t_0080d407.param_result = DAT_0080d41a + insite_session_t_0080d407.param_result;
    DAT_0080d419 = DAT_0080d419 - DAT_0080d41a;
    return;
  }
  if (insite_session_t_0080d407.response_ptr._0_1_ == '\0') {
    uVar3 = insiteMultiFrameResponseBuilder(0xe000e);
    if ((char)uVar3 == '\0') {
      uVar4 = 1;
      while (DAT_0080d444 <= DAT_0080d445) {
        while (DAT_0080d446 != '\0') {
          uVar6 = (ushort)(byte)((char)uVar4 + 1);
          sVar2 = (ushort)(byte)(&DAT_00804e7c)[(short)uVar4] * 6;
          uVar4 = uVar6;
          if (((*(ushort *)(&DAT_008065ce + sVar2) & 0x2000) == 0) &&
             ((&DAT_008065d0)[sVar2] != '\0')) {
            *(undefined *)insite_session_t_0080d407._5_4_ = (&DAT_008065d0)[sVar2];
            insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
                 insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
            *(byte *)insite_session_t_0080d407._5_4_ =
                 (byte)((int)(uint)*(ushort *)(&DAT_008065ce + sVar2) >> 7) & 0x3f;
            insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
                 insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
            DAT_0080d446 = DAT_0080d446 + -2;
          }
        }
        if (DAT_0080d444 == DAT_0080d445) {
          responseBufferFinalize();
          insite_session_t_0080d407._9_4_ = insite_session_t_0080d407._5_4_;
          DAT_0080d444 = DAT_0080d444 + 1;
          insite_session_t_0080d407.param_result = 0;
        }
        else {
          insiteMultiFrameContinuation();
        }
      }
      return;
    }
  }
  else {
    uVar3 = insiteMultiFrameResponseBuilder(0xc000f);
    if ((char)uVar3 == '\0') {
      bVar7 = 0;
      pbVar8 = &DAT_00804e7d;
      uVar4 = _DAT_00804f40;
      while (DAT_0080d444 <= DAT_0080d445) {
        while (DAT_0080d446 != '\0') {
          pbVar9 = pbVar8;
          if ((char)uVar4 == '\0') {
            pbVar9 = &DAT_00804e9d;
            bVar7 = 0x40;
            uVar4 = _DAT_00804f42;
          }
          pbVar8 = pbVar9 + 1;
          bVar1 = *pbVar9;
          sVar2 = (ushort)bVar1 * 6;
          if (((*(ushort *)(&DAT_008065ce + sVar2) & 0x2000) == 0) &&
             ((&DAT_008065d0)[sVar2] != '\0')) {
            *(undefined *)insite_session_t_0080d407._5_4_ = (&DAT_008065d0)[sVar2];
            insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
                 insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
            *(byte *)insite_session_t_0080d407._5_4_ =
                 bVar7 | (byte)((int)(uint)*(ushort *)(&DAT_008065ce + sVar2) >> 7) & 0x3f | 0x80;
            insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
                 insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
            *(undefined *)insite_session_t_0080d407._5_4_ =
                 (&DAT_00804fcd)[(short)((ushort)bVar1 * 5) * 2];
            insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
                 insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
            uVar4 = (ushort)(byte)((char)uVar4 - 1);
            DAT_0080d446 = DAT_0080d446 + -3;
          }
        }
        if (DAT_0080d444 == DAT_0080d445) {
          responseBufferFinalize();
          insite_session_t_0080d407._9_4_ = insite_session_t_0080d407._5_4_;
          DAT_0080d444 = DAT_0080d444 + 1;
          insite_session_t_0080d407.param_result = 0;
        }
        else {
          insiteMultiFrameContinuation();
        }
      }
    }
  }
  return;
}



//
// Function: insiteEcuIdResponseBuilder @ 0x0001fec4
//

void insiteEcuIdResponseBuilder(void)

{
  char cVar1;
  uint uVar2;
  byte bVar3;
  undefined1 *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  
  if (DAT_0080d41a < 0x14) {
    *(byte *)insite_session_t_0080d407._5_4_ = insite_session_t_0080d407.command_byte;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    *(byte *)insite_session_t_0080d407._5_4_ = DAT_0080d41a - 2;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    bVar3 = 0;
    puVar4 = &DAT_0000444b;
    do {
      *(undefined1 *)insite_session_t_0080d407._5_4_ = *puVar4;
      insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
           insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      bVar3 = bVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (bVar3 < 4);
    *(undefined1 *)insite_session_t_0080d407._5_4_ = 0x2a;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    bVar3 = 0;
    puVar4 = &DAT_0000444f;
    do {
      *(undefined1 *)insite_session_t_0080d407._5_4_ = *puVar4;
      insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
           insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      bVar3 = bVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (bVar3 < 4);
    *(undefined1 *)insite_session_t_0080d407._5_4_ = 0x2a;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    bVar3 = 0;
    puVar4 = &DAT_0000445f;
    do {
      *(undefined1 *)insite_session_t_0080d407._5_4_ = *puVar4;
      insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
           insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      bVar3 = bVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (bVar3 < 0xc);
    insite_session_t_0080d407.param_result = DAT_0080d41a + insite_session_t_0080d407.param_result;
    DAT_0080d419 = DAT_0080d419 - DAT_0080d41a;
    return;
  }
  uVar2 = insiteMultiFrameResponseBuilder(0xe000f);
  if ((char)uVar2 == '\0') {
    bVar3 = 0;
    puVar6 = &DAT_00801760;
    puVar4 = &DAT_0000444b;
    do {
      puVar5 = puVar6;
      *puVar5 = *puVar4;
      bVar3 = bVar3 + 1;
      puVar6 = puVar5 + 1;
      puVar4 = puVar4 + 1;
    } while (bVar3 < 4);
    puVar5[1] = 0x2a;
    bVar3 = 0;
    puVar6 = puVar5 + 2;
    puVar4 = &DAT_0000444f;
    do {
      puVar5 = puVar6;
      *puVar5 = *puVar4;
      bVar3 = bVar3 + 1;
      puVar6 = puVar5 + 1;
      puVar4 = puVar4 + 1;
    } while (bVar3 < 4);
    puVar5[1] = 0x2a;
    bVar3 = 0;
    puVar6 = puVar5 + 2;
    puVar4 = &DAT_0000445f;
    do {
      *puVar6 = *puVar4;
      bVar3 = bVar3 + 1;
      puVar6 = puVar6 + 1;
      puVar4 = puVar4 + 1;
    } while (bVar3 < 0xc);
    puVar6 = &DAT_00801760;
    while (DAT_0080d444 <= DAT_0080d445) {
      while (cVar1 = DAT_0080d446 + -1, DAT_0080d446 != '\0') {
        DAT_0080d446 = cVar1;
        *(undefined *)insite_session_t_0080d407._5_4_ = *puVar6;
        insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
             insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
        puVar6 = puVar6 + 1;
      }
      if (DAT_0080d444 == DAT_0080d445) {
        DAT_0080d446 = cVar1;
        responseBufferFinalize();
        insite_session_t_0080d407._9_4_ = insite_session_t_0080d407._5_4_;
        DAT_0080d444 = DAT_0080d444 + 1;
        insite_session_t_0080d407.param_result = 0;
      }
      else {
        DAT_0080d446 = cVar1;
        insiteMultiFrameContinuation();
      }
    }
  }
  return;
}



//
// Function: insiteCapacityResponseBuilder @ 0x0002003c
//

void insiteCapacityResponseBuilder(void)

{
  uint uVar1;
  byte bVar2;
  char *pcVar3;
  
  if (DAT_0080d41a < 0x14) {
    *(byte *)insite_session_t_0080d407._5_4_ = insite_session_t_0080d407.command_byte;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    *(undefined1 *)insite_session_t_0080d407._5_4_ = 0x14;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    pcVar3 = s_CAPACITY_39442720003948543000394_00004499 + 0x1e;
    for (bVar2 = 0; bVar2 < 0x14; bVar2 = bVar2 + 1) {
      *(char *)insite_session_t_0080d407._5_4_ = *pcVar3;
      insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
           insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      pcVar3 = pcVar3 + 1;
    }
    insite_session_t_0080d407.param_result = DAT_0080d41a + insite_session_t_0080d407.param_result;
    DAT_0080d419 = DAT_0080d419 - DAT_0080d41a;
    return;
  }
  uVar1 = insiteMultiFrameResponseBuilder(0xe000f);
  if ((char)uVar1 == '\0') {
    pcVar3 = s_CAPACITY_39442720003948543000394_00004499 + 0x1e;
    while (DAT_0080d444 <= DAT_0080d445) {
      for (bVar2 = 0; bVar2 < DAT_0080d446; bVar2 = bVar2 + 1) {
        *(char *)insite_session_t_0080d407._5_4_ = *pcVar3;
        insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
             insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
        pcVar3 = pcVar3 + 1;
      }
      if (DAT_0080d444 == DAT_0080d445) {
        responseBufferFinalize();
        insite_session_t_0080d407._9_4_ = insite_session_t_0080d407._5_4_;
        DAT_0080d444 = DAT_0080d444 + 1;
        insite_session_t_0080d407.param_result = 0;
      }
      else {
        insiteMultiFrameContinuation();
      }
    }
  }
  return;
}



//
// Function: insiteVersionInfoBuilder @ 0x0002011c
//

void insiteVersionInfoBuilder(void)

{
  char cVar1;
  uint uVar2;
  byte bVar3;
  undefined1 *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  
  if (DAT_0080d41a < 0x14) {
    *(byte *)insite_session_t_0080d407._5_4_ = insite_session_t_0080d407.command_byte;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    *(byte *)insite_session_t_0080d407._5_4_ = DAT_0080d41a - 2;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    *(undefined1 *)insite_session_t_0080d407._5_4_ = 0x80;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    bVar3 = 0;
    puVar4 = &DAT_00004404;
    do {
      *(undefined1 *)insite_session_t_0080d407._5_4_ = *puVar4;
      insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
           insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      bVar3 = bVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (bVar3 < 5);
    *(undefined1 *)insite_session_t_0080d407._5_4_ = 0x2a;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    bVar3 = 0;
    puVar4 = &DAT_00004409;
    do {
      *(undefined1 *)insite_session_t_0080d407._5_4_ = *puVar4;
      insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
           insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      bVar3 = bVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (bVar3 < 0x11);
    *(undefined1 *)insite_session_t_0080d407._5_4_ = 0x2a;
    insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
         insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
    bVar3 = 0;
    puVar4 = &DAT_0000441a;
    do {
      *(undefined1 *)insite_session_t_0080d407._5_4_ = *puVar4;
      insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
           insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
      bVar3 = bVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (bVar3 < 4);
    insite_session_t_0080d407.param_result = DAT_0080d41a + insite_session_t_0080d407.param_result;
    DAT_0080d419 = DAT_0080d419 - DAT_0080d41a;
    return;
  }
  uVar2 = insiteMultiFrameResponseBuilder(0xe000f);
  if ((char)uVar2 == '\0') {
    DAT_00801776 = 0x80;
    bVar3 = 0;
    puVar6 = &DAT_00801777;
    puVar4 = &DAT_00004404;
    do {
      puVar5 = puVar6;
      *puVar5 = *puVar4;
      bVar3 = bVar3 + 1;
      puVar6 = puVar5 + 1;
      puVar4 = puVar4 + 1;
    } while (bVar3 < 5);
    puVar5[1] = 0x2a;
    bVar3 = 0;
    puVar6 = puVar5 + 2;
    puVar4 = &DAT_00004409;
    do {
      puVar5 = puVar6;
      *puVar5 = *puVar4;
      bVar3 = bVar3 + 1;
      puVar6 = puVar5 + 1;
      puVar4 = puVar4 + 1;
    } while (bVar3 < 0x11);
    puVar5[1] = 0x2a;
    bVar3 = 0;
    puVar6 = puVar5 + 2;
    puVar4 = &DAT_0000441a;
    do {
      *puVar6 = *puVar4;
      bVar3 = bVar3 + 1;
      puVar6 = puVar6 + 1;
      puVar4 = puVar4 + 1;
    } while (bVar3 < 4);
    puVar6 = &DAT_00801776;
    while (DAT_0080d444 <= DAT_0080d445) {
      while (cVar1 = DAT_0080d446 + -1, DAT_0080d446 != '\0') {
        DAT_0080d446 = cVar1;
        *(undefined *)insite_session_t_0080d407._5_4_ = *puVar6;
        insite_session_t_0080d407.tx_buffer_ptr._2_1_ =
             insite_session_t_0080d407.tx_buffer_ptr._2_1_ + '\x01';
        puVar6 = puVar6 + 1;
      }
      if (DAT_0080d444 == DAT_0080d445) {
        DAT_0080d446 = cVar1;
        responseBufferFinalize();
        insite_session_t_0080d407._9_4_ = insite_session_t_0080d407._5_4_;
        DAT_0080d444 = DAT_0080d444 + 1;
        insite_session_t_0080d407.param_result = 0;
      }
      else {
        DAT_0080d446 = cVar1;
        insiteMultiFrameContinuation();
      }
    }
  }
  return;
}



//
// Function: hourMeterEventLogger @ 0x000202a4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void hourMeterEventLogger(void)

{
  byte bVar1;
  bool bVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  ushort uVar6;
  byte bVar7;
  byte *pbVar8;
  byte local_5;
  
  while( true ) {
    uVar5 = circularBufferPop(&CMECTR,&local_5);
    if ((char)uVar5 != '\0') break;
    iVar4 = (uint)(local_5 & 0x7f) * 6;
    if ((((&DAT_008065d0)[iVar4] != '\0') && ((*(ushort *)(&DAT_008065ce + iVar4) & 0x800) == 0)) &&
       (((uint)DAT_000202a2 & 1 << ((int)(*(ushort *)(&DAT_008065ce + iVar4) & 0x780) >> 7)) != 0))
    {
      bVar1 = (&DAT_008065d0)[iVar4];
      bVar7 = '\x01' << (bVar1 & 7);
      sVar3 = (short)((int)(uint)bVar1 >> 3);
      if ((bVar7 & *(byte *)(sVar3 + 0x8089be)) != 0) {
        uVar6 = _DAT_0080561e;
        for (pbVar8 = &DAT_00805620; (uVar6 != 0 && (bVar1 != *pbVar8)); pbVar8 = pbVar8 + 2) {
          uVar6 = uVar6 - 1;
        }
        if (uVar6 == 0) {
          if ((local_5 & 0x80) != 0) {
            *pbVar8 = bVar1;
            pbVar8[1] = 1;
            _DAT_0080561e = _DAT_0080561e + 1;
            *(byte *)(sVar3 + 0x8055fe) = bVar7 | *(byte *)(sVar3 + 0x8055fe);
          }
        }
        else if ((local_5 & 0x80) == 0) {
          bVar1 = pbVar8[1] - 1;
          pbVar8[1] = bVar1;
          if (bVar1 == 0) {
            *(byte *)(sVar3 + 0x8055fe) = ~bVar7 & *(byte *)(sVar3 + 0x8055fe);
            uVar6 = _DAT_0080561e - 1;
            bVar2 = 1 < _DAT_0080561e;
            _DAT_0080561e = uVar6;
            if (bVar2) {
              *pbVar8 = (&DAT_00805620)[(short)uVar6 * 2];
              pbVar8[1] = (&DAT_00805621)[(short)_DAT_0080561e * 2];
            }
          }
        }
        else {
          pbVar8[1] = pbVar8[1] + 1;
        }
      }
    }
  }
  return;
}



//
// Function: mainSystemInitialization @ 0x00020462
//

/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mainSystemInitialization(void)

{
  char in_XF;
  char cVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  
  DAT_00fffc04 = 0;
  _DAT_00fffc0a = 0;
  _DAT_00fffa22 = 0;
  _DAT_00fffa24 = 0;
  _DAT_00fffe0a = 0;
  _DAT_00fff400 = 0x1201;
  _DAT_00fff408 = 8;
  _DAT_00fff410 = 0x200;
  tpu_timer_channel_register._0_2_ = 4;
  _DAT_00fff418 = 8;
  _DAT_00fff41a = 0;
  _DAT_00fff41c = 0;
  _DAT_00fff420 = 1;
  _DAT_00fff448 = 1;
  _DAT_00fff450 = 1;
  sim_timer_control_register._0_2_ = 0xffff;
  sim_timer_control_register._2_2_ = 0;
  _DAT_00fff428 = 8;
  _DAT_00fff432 = 0xffff;
  _DAT_00fff434 = 0;
  _DAT_00fff430 = 8;
  tpu_pwm_channel_3_output._0_2_ = 0xffff;
  tpu_pwm_channel_3_output._2_2_ = 0;
  _DAT_00fff438 = 8;
  tpu_pwm_channel_4_output._0_2_ = 0xffff;
  tpu_pwm_channel_4_output._2_2_ = 0;
  _DAT_00fff440 = 8;
  _DAT_00fff460 = 0x104;
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x576;
  initInternalRamAndCAN1();
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x57c;
  clearWorkingMemory();
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x582;
  firmwareDataCopyToWorkingMemory();
  _DAT_0080d1a2 = 0xeeee;
  DAT_0080bdf0 = DAT_0080bdf0 | 8;
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x598;
  initVectorTable();
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x5ac;
  initQADC();
  _DAT_00fffc00 = 5;
  DAT_00fffc04 = 0x13;
  DAT_00fffc05 = 0x50;
  cVar1 = '\0';
  cVar2 = '\0';
  cVar3 = '\0';
  bVar4 = 0;
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x5ca;
  initTPU();
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x5d0;
  initMIOS14Timers();
  _DAT_0080fffe = (ushort)(byte)(in_XF << 4 | cVar1 << 3 | cVar2 << 2 | cVar3 << 1 | bVar4);
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x5e0;
  validateRedundantSensors();
  if (_DAT_0080367e == 0) {
    fault_status_registers_t_00805df2.sensor_fault_status =
         fault_status_registers_t_00805df2.sensor_fault_status & 0xfbff;
  }
  else {
    fault_status_registers_t_00805df2.sensor_fault_status =
         fault_status_registers_t_00805df2.sensor_fault_status | 0x400;
    fault_latch_registers_t_00805e32.sensor_fault_latch =
         fault_latch_registers_t_00805e32.sensor_fault_latch | 0x400;
  }
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x61c;
  initVP44StatusMonitoring();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x622;
  initADCChannelConfiguration();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x628;
  initCANBus();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x62e;
  initLoopCounter();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x634;
  initFuelSystemOutputDriver();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x63a;
  dmaDescriptorSetup2();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x640;
  initDerateSystemPointers();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x646;
  initMultiSystemParameters();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x64c;
  dmaControllerSetup1();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x652;
  engineProtectionSystemInit();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x658;
  diagnosticProtectionEvaluator();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x65e;
  fuelDeliverySystemInit();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x664;
  fuelArbitratorInit();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x66a;
  engineRpmSourceInit();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x670;
  canBusTimingInit();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x676;
  canControllerConfigInit();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x67c;
  canRpmModeConfigInit();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x682;
  engineOperatingModeInit();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x688;
  scheduler_init();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x68e;
  emptyInitPlaceholder();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x694;
  initDiagnosticModeSystem();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x69a;
  initDerateSystem();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6a0;
  initBoostProtectionSystem();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6a6;
  initAcControlSystem();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6ac;
  initAncSpeedLimitAndAltitudeDerate();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6b2;
  initVp44BufferAddresses();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6b8;
  initHourMeterSystem();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6be;
  initLoadTrendingSystem();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6c4;
  initOilPressureModeSystem();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6ca;
  initFuelDemandCalculationSystem();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6d0;
  emptyInit2();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6d6;
  initFuelArbitratorThreshold5();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6dc;
  initFuelArbitratorThreshold3();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6e2;
  initTimerCounterDefaults();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6e8;
  initIoControlRegister();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6ee;
  initLookupTablePointers1();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6f4;
  initVP44StatusFlags();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6fa;
  initRpmLookupTables();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x700;
  initParameterScalingSystem();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x706;
  initOilPressureProtectionPointers();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x70c;
  initOilPressureMonitoring();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x712;
  initSensorDataArrays();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x718;
  initDiagnosticSystemState();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x71e;
  initIntakeManifoldTemperatureLimits();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x724;
  vp44ControlStructureInit();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x72a;
  hardwareTimerFlagsInit();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x730;
  intakeTemperatureTablesInit();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x736;
  masterSubsystemInit();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x73c;
  fuelTimingModeInit();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x742;
  canMessageFilterInit();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x748;
  engineProtectionSystemInit();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x74e;
  tpuChannelIsrRegister();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x754;
  engineSpeedIsrRegister();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x75a;
  can1ControllerInit();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x760;
  pwmOutputInit();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x766;
  serialCommunicationIsrRegister();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x76c;
  canMessageInterruptHandlerSetup();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x772;
  dualCanControllerInit();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x778;
  initDiagnosticProtocol();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x77e;
  emptyPlaceholderInit();
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x786;
  initMIOS14Timers();
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x78c;
  engineModeOutputControlInit();
  engine_operating_mode_t_0080c810.shutdown_complete_flag = 0;
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x7a4;
  schedulerWaitLoop();
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x7ae;
  boostPressureControlInit();
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x7b4;
  vp44CommunicationTestAndInit();
  return;
}



//
// Function: phase4InitSequence @ 0x00020780
//

/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void phase4InitSequence(void)

{
  initMIOS14Timers();
  engineModeOutputControlInit();
  engine_operating_mode_t_0080c810.shutdown_complete_flag = 0;
  _DAT_0080fffc = 0x207a4;
  schedulerWaitLoop();
  _DAT_0080fffc = 0x207ae;
  boostPressureControlInit();
  _DAT_0080fffc = 0x207b4;
  vp44CommunicationTestAndInit();
  return;
}



//
// Function: dualCanControllerInit @ 0x000207b6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void dualCanControllerInit(void)

{
  byte bVar1;
  undefined *puVar2;
  
  do {
    DAT_00ffd802 = DAT_008088c3;
  } while ((DAT_008088c3 & 0x80) != 0);
  DAT_00ffd808 = DAT_008088ca;
  DAT_00ffd809 = DAT_008088cb;
  DAT_00ffd80a = DAT_008088cc;
  DAT_00ffd80b = DAT_008088cd;
  _DAT_00ffd806 = _DAT_008088ce;
  DAT_00ffd82f = DAT_008088c5;
  DAT_00ffd83f = DAT_008088c7;
  DAT_00ffd84f = DAT_008088c9;
  DAT_00ffd81f = 0;
  DAT_00ffd800 = 0;
  puVar2 = &DAT_00ffd810;
  bVar1 = 1;
  do {
    *puVar2 = 0x7d;
    puVar2 = puVar2 + 0x10;
    bVar1 = bVar1 + 1;
  } while (bVar1 < 0x10);
  DAT_00ffd800 = DAT_00ffd800 & 0xfe;
  do {
    DAT_00ffc802 = DAT_008088d1;
  } while ((DAT_008088d1 & 0x80) != 0);
  DAT_00ffc808 = DAT_008088d8;
  DAT_00ffc809 = DAT_008088d9;
  DAT_00ffc80a = DAT_008088da;
  DAT_00ffc80b = DAT_008088db;
  _DAT_00ffc806 = _DAT_008088dc;
  DAT_00ffc82f = DAT_008088d3;
  DAT_00ffc83f = DAT_008088d5;
  DAT_00ffc84f = DAT_008088d7;
  DAT_00ffc81f = 0;
  DAT_00ffc800 = 0;
  puVar2 = &DAT_00ffc810;
  bVar1 = 1;
  do {
    *puVar2 = 0x7d;
    puVar2 = puVar2 + 0x10;
    bVar1 = bVar1 + 1;
  } while (bVar1 < 0x10);
  DAT_00ffc800 = DAT_00ffc800 & 0xfe;
  tpuTimerInitializer();
  canTransmissionScheduler();
  return;
}



//
// Function: canTransmissionScheduler @ 0x00020918
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void canTransmissionScheduler(void)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  undefined *puVar6;
  
  _DAT_0080cf7c = 0x80ce60;
  _DAT_0080cf78 = 0x80ce60;
  _DAT_0080cf84 = 0x80ccf8;
  _DAT_0080cf80 = 0x80ccf8;
  vp44DiagnosticBufferPointersInit();
  _DAT_0080cfa2 = 4;
  bVar3 = 0;
  puVar6 = &DAT_0080cfa4;
  do {
    *puVar6 = 0xfe;
    bVar3 = bVar3 + 1;
    puVar6 = puVar6 + 1;
  } while (bVar3 < 4);
  canBufferSetup1();
  j1939MessageSetup_PGN_65265();
  vp44Command0x100Builder();
  cumminsProprietaryDM_983_Builder();
  secondaryParamPGN_65247_Builder();
  extendedDiagPGN_65251_Builder();
  cumminsProprietaryTSC_PGN_15728640_Builder();
  fuelEconomyPGN_65266_Builder();
  retarderConfigPGN_65249_Builder();
  retarderModeThresholdsSetup();
  ambientConditionsPGN_65269_Builder();
  engineFluidLevelPGN_65263_Builder();
  engineHoursPGN_65252_Builder();
  intakeManifoldPGN_65526_Builder();
  cruiseControlPGN_65264_Builder();
  electronicBrakePGN_65527_Builder();
  engineCoolantPGN_65226_Builder();
  diagnosticDM8PGN_65232_Builder();
  timerSchedulerSetup(0,100);
  timerSchedulerSetup(0,0x14);
  timerSchedulerSetup(0,0x32);
  timerSchedulerSetup(0,0xfa);
  timerSchedulerSetup(0,5000);
  timerSchedulerSetup(1,100);
  timerSchedulerSetup(0,100);
  timerSchedulerSetup(1,5000);
  timerSchedulerSetup(0,1000);
  timerSchedulerSetup(0,500);
  timerSchedulerSetup(0,100);
  timerSchedulerSetup(0,1000);
  timerSchedulerSetup(0,500);
  timerSchedulerSetup(0,1000);
  timerSchedulerSetup(0,1000);
  systemControlFunction1();
  systemControlFunction4();
  systemControlFunction3();
  diagnosticDataDump();
  systemControlFunction2();
  registerDiagnosticMemoryServices();
  systemFunction1xCaller();
  systemFunction6xParameterized();
  systemFunction8xMaximum();
  systemFunction4xParameterizedAlt();
  _DAT_0080cfb6 = _DAT_00809d48 + 1;
  _DAT_00809d48 = _DAT_00809d48 + 8;
  _DAT_0080cf8c = &DAT_00ffd800 + (uint)_DAT_0080cfb6 * 0x10;
  _DAT_0080cfb8 = _DAT_00809d48;
  *_DAT_0080cf8c = 0x55;
  _DAT_0080cf8c[1] = 0xfb;
  *_DAT_0080cf8c = 0xef;
  _DAT_0080cf8c[6] = 4;
  puVar6 = &DAT_00ffd810 + (uint)_DAT_0080cfb6 * 0x10;
  uVar2 = (uint)_DAT_0080cfc2;
  bVar5 = DAT_0080cfc3 << 3;
  bVar3 = 0;
  for (bVar4 = 0; bVar4 < _DAT_008088de; bVar4 = bVar4 + 1) {
    *puVar6 = 0x99;
    puVar6[6] = 4;
    puVar6[1] = 0xdf;
    puVar6[2] = *(undefined1 *)(bVar3 + 0x8088ea);
    puVar6[3] = (byte)((int)(uVar2 & 0xe0) >> 5) | *(byte *)((byte)(bVar3 + 1) + 0x8088ea) & 0xf8;
    bVar1 = bVar3 + 3;
    puVar6[4] = bVar5 | *(byte *)((byte)(bVar3 + 2) + 0x8088ea) & 7;
    bVar3 = bVar3 + 4;
    puVar6[5] = *(undefined1 *)(bVar1 + 0x8088ea);
    puVar6 = puVar6 + 0x10;
  }
  for (bVar4 = 0; bVar4 < _DAT_008088e0; bVar4 = bVar4 + 1) {
    *puVar6 = 0x99;
    puVar6[1] = 0xdf;
    puVar6[6] = 4;
    puVar6[2] = *(undefined1 *)(bVar3 + 0x8088ea);
    puVar6[3] = *(undefined1 *)((byte)(bVar3 + 1) + 0x8088ea);
    bVar5 = bVar3 + 3;
    puVar6[4] = *(undefined1 *)((byte)(bVar3 + 2) + 0x8088ea);
    bVar3 = bVar3 + 4;
    puVar6[5] = *(undefined1 *)(bVar5 + 0x8088ea);
    puVar6 = puVar6 + 0x10;
  }
  uVar2 = (uint)_DAT_0080cfcc;
  bVar5 = DAT_0080cfcd << 3;
  for (bVar4 = 0; bVar4 < _DAT_008088e2; bVar4 = bVar4 + 1) {
    *puVar6 = 0x99;
    puVar6[1] = 0xdf;
    puVar6[6] = 4;
    puVar6[2] = *(undefined1 *)(bVar3 + 0x8088ea);
    puVar6[3] = (byte)((int)(uVar2 & 0xe0) >> 5) | *(byte *)((byte)(bVar3 + 1) + 0x8088ea) & 0xf8;
    bVar1 = bVar3 + 3;
    puVar6[4] = bVar5 | *(byte *)((byte)(bVar3 + 2) + 0x8088ea) & 7;
    bVar3 = bVar3 + 4;
    puVar6[5] = *(undefined1 *)(bVar1 + 0x8088ea);
    puVar6 = puVar6 + 0x10;
  }
  for (bVar4 = 0; bVar4 < _DAT_008088e4; bVar4 = bVar4 + 1) {
    *puVar6 = 0x99;
    puVar6[1] = 0xdf;
    puVar6[6] = 4;
    puVar6[2] = *(undefined1 *)(bVar3 + 0x8088ea);
    puVar6[3] = *(undefined1 *)((byte)(bVar3 + 1) + 0x8088ea);
    bVar5 = bVar3 + 3;
    puVar6[4] = *(undefined1 *)((byte)(bVar3 + 2) + 0x8088ea);
    bVar3 = bVar3 + 4;
    puVar6[5] = *(undefined1 *)(bVar5 + 0x8088ea);
    puVar6 = puVar6 + 0x10;
  }
  DAT_00ffd800 = DAT_00ffd800 | 10;
  return;
}



//
// Function: mainCanTransmissionLoop @ 0x00020980
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mainCanTransmissionLoop(void)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  undefined *puVar6;
  int unaff_A3;
  code *unaff_A4;
  int *unaff_A5;
  
  vp44Command0x100Builder();
  cumminsProprietaryDM_983_Builder();
  secondaryParamPGN_65247_Builder();
  extendedDiagPGN_65251_Builder();
  cumminsProprietaryTSC_PGN_15728640_Builder();
  fuelEconomyPGN_65266_Builder();
  retarderConfigPGN_65249_Builder();
  retarderModeThresholdsSetup();
  ambientConditionsPGN_65269_Builder();
  engineFluidLevelPGN_65263_Builder();
  engineHoursPGN_65252_Builder();
  intakeManifoldPGN_65526_Builder();
  cruiseControlPGN_65264_Builder();
  electronicBrakePGN_65527_Builder();
  engineCoolantPGN_65226_Builder();
  diagnosticDM8PGN_65232_Builder();
  (*unaff_A4)(0,100);
  (*unaff_A4)(0,0x14);
  (*unaff_A4)(0,0x32);
  (*unaff_A4)(0,0xfa);
  (*unaff_A4)(0,5000);
  (*unaff_A4)(1,100);
  (*unaff_A4)(0,100);
  (*unaff_A4)(1,5000);
  (*unaff_A4)(0,1000);
  (*unaff_A4)(0,500);
  (*unaff_A4)(0,100);
  (*unaff_A4)(0,1000);
  (*unaff_A4)(0,500);
  (*unaff_A4)(0,1000);
  (*unaff_A4)(0,1000);
  systemControlFunction1();
  systemControlFunction4();
  systemControlFunction3();
  diagnosticDataDump();
  systemControlFunction2();
  registerDiagnosticMemoryServices();
  systemFunction1xCaller();
  systemFunction6xParameterized();
  systemFunction8xMaximum();
  systemFunction4xParameterizedAlt();
  _DAT_0080cfb6 = _DAT_00809d48 + 1;
  _DAT_00809d48 = _DAT_00809d48 + 8;
  uVar2 = (uint)_DAT_0080cfb6;
  _DAT_0080cfb8 = _DAT_00809d48;
  *unaff_A5 = (int)(&DAT_00ffd800 + uVar2 * 0x10);
  (&DAT_00ffd800)[uVar2 * 0x10] = 0x55;
  *(undefined1 *)(*unaff_A5 + 1) = 0xfb;
  *(undefined1 *)*unaff_A5 = 0xef;
  *(undefined1 *)(*unaff_A5 + 6) = 4;
  puVar6 = &DAT_00ffd810 + (uint)_DAT_0080cfb6 * 0x10;
  uVar2 = (uint)_DAT_0080cfc2;
  bVar5 = DAT_0080cfc3 << 3;
  bVar3 = 0;
  for (bVar4 = 0; bVar4 < _DAT_008088de; bVar4 = bVar4 + 1) {
    *puVar6 = 0x99;
    puVar6[6] = 4;
    puVar6[1] = 0xdf;
    puVar6[2] = *(undefined1 *)(unaff_A3 + (uint)bVar3);
    puVar6[3] = (byte)((int)(uVar2 & 0xe0) >> 5) |
                *(byte *)(unaff_A3 + (uint)(byte)(bVar3 + 1)) & 0xf8;
    bVar1 = bVar3 + 3;
    puVar6[4] = bVar5 | *(byte *)(unaff_A3 + (uint)(byte)(bVar3 + 2)) & 7;
    bVar3 = bVar3 + 4;
    puVar6[5] = *(undefined1 *)(unaff_A3 + (uint)bVar1);
    puVar6 = puVar6 + 0x10;
  }
  for (bVar4 = 0; bVar4 < _DAT_008088e0; bVar4 = bVar4 + 1) {
    *puVar6 = 0x99;
    puVar6[1] = 0xdf;
    puVar6[6] = 4;
    puVar6[2] = *(undefined1 *)(unaff_A3 + (uint)bVar3);
    puVar6[3] = *(undefined1 *)(unaff_A3 + (uint)(byte)(bVar3 + 1));
    bVar5 = bVar3 + 3;
    puVar6[4] = *(undefined1 *)(unaff_A3 + (uint)(byte)(bVar3 + 2));
    bVar3 = bVar3 + 4;
    puVar6[5] = *(undefined1 *)(unaff_A3 + (uint)bVar5);
    puVar6 = puVar6 + 0x10;
  }
  uVar2 = (uint)_DAT_0080cfcc;
  bVar5 = DAT_0080cfcd << 3;
  for (bVar4 = 0; bVar4 < _DAT_008088e2; bVar4 = bVar4 + 1) {
    *puVar6 = 0x99;
    puVar6[1] = 0xdf;
    puVar6[6] = 4;
    puVar6[2] = *(undefined1 *)(unaff_A3 + (uint)bVar3);
    puVar6[3] = (byte)((int)(uVar2 & 0xe0) >> 5) |
                *(byte *)(unaff_A3 + (uint)(byte)(bVar3 + 1)) & 0xf8;
    bVar1 = bVar3 + 3;
    puVar6[4] = bVar5 | *(byte *)(unaff_A3 + (uint)(byte)(bVar3 + 2)) & 7;
    bVar3 = bVar3 + 4;
    puVar6[5] = *(undefined1 *)(unaff_A3 + (uint)bVar1);
    puVar6 = puVar6 + 0x10;
  }
  for (bVar4 = 0; bVar4 < _DAT_008088e4; bVar4 = bVar4 + 1) {
    *puVar6 = 0x99;
    puVar6[1] = 0xdf;
    puVar6[6] = 4;
    puVar6[2] = *(undefined1 *)(unaff_A3 + (uint)bVar3);
    puVar6[3] = *(undefined1 *)(unaff_A3 + (uint)(byte)(bVar3 + 1));
    bVar5 = bVar3 + 3;
    puVar6[4] = *(undefined1 *)(unaff_A3 + (uint)(byte)(bVar3 + 2));
    bVar3 = bVar3 + 4;
    puVar6[5] = *(undefined1 *)(unaff_A3 + (uint)bVar5);
    puVar6 = puVar6 + 0x10;
  }
  DAT_00ffd800 = DAT_00ffd800 | 10;
  return;
}



//
// Function: vp44StatusInitAndWait @ 0x00020de4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44StatusInitAndWait(void)

{
  short sVar1;
  ushort uVar2;
  char in_XF;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  ushort uVar7;
  short local_6;
  
  DAT_00fffa27 = 0xaa;
  DAT_00ffd00f = 0xaa;
  cVar3 = '\x01';
  cVar4 = '\0';
  cVar5 = '\0';
  bVar6 = 0;
  initVP44StatusMonitoring();
  uVar7 = (ushort)(byte)(in_XF << 4 | cVar3 << 3 | cVar4 << 2 | cVar5 << 1 | bVar6);
  local_6 = _DAT_0080368e + 1;
  parameterCircularBufferWrite(0x80368e,(undefined1 *)&local_6,CONCAT22(2,uVar7));
  uVar2 = 0;
  while ((uVar2 < 1000 && (_DAT_0080368e != local_6))) {
    emptyPlaceholderFunction();
    delayWithWatchdogService(CONCAT22(500,uVar7));
    uVar2 = uVar2 + 1;
  }
  local_6 = _DAT_0080368c + _DAT_0080368e;
  parameterCircularBufferWrite(0x803686,(undefined1 *)&local_6,CONCAT22(2,uVar7));
  uVar2 = 0;
  while ((uVar2 < 1000 && (_DAT_00803686 != local_6))) {
    emptyPlaceholderFunction();
    sVar1 = 0;
    do {
      uVar7 = 0;
      do {
        DAT_00fffa27 = 0xaa;
        DAT_00ffd00f = 0xaa;
        uVar7 = uVar7 + 1;
      } while (uVar7 < 0xa0);
      sVar1 = sVar1 + 1;
    } while (sVar1 == 0);
    uVar2 = uVar2 + 1;
  }
  DAT_00fffa27 = 0xaa;
  DAT_00ffd00f = 0xaa;
  phase4InitSequence();
  return;
}



//
// Function: vp44CommunicationTestAndInit @ 0x00020f14
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44CommunicationTestAndInit(void)

{
  uint uVar1;
  undefined4 unaff_D2;
  short sVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  byte bVar6;
  uint unaff_D7;
  byte *pbVar7;
  undefined2 *puVar8;
  char in_XF;
  char cVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  byte bVar13;
  ushort uVar14;
  undefined2 uVar15;
  int local_a;
  ushort local_6;
  
  uVar15 = (undefined2)((uint)unaff_D2 >> 0x10);
  FUN_00028b78();
  DAT_00fffa27 = 0xaa;
  DAT_00ffd00f = 0xaa;
  _DAT_0080d19c = 1;
  uVar14 = (ushort)(byte)(in_XF << 4);
  uVar5 = 0;
  while ((uVar5 < 1000 && (uVar1 = circularBufferEmptyCheck(), (char)uVar1 == '\0'))) {
    emptyPlaceholderFunction();
    delayWithWatchdogService(CONCAT22(500,uVar14));
    uVar5 = uVar5 + 1;
  }
  DAT_0080bdf0 = DAT_0080bdf0 | 4;
  ioControlAndCanPinSwitching();
  if (_DAT_0080d19e != 0) {
    pbVar7 = system_protected_area_t_008062cb.protected_flags + 1;
    if (_DAT_0080d1a0 == 2) {
      puVar8 = (undefined2 *)&DAT_00007e3e;
    }
    else {
      puVar8 = (undefined2 *)&DAT_00005e3e;
    }
    for (; pbVar7 < system_protected_area_t_008062cb.protected_flags + 3; pbVar7 = pbVar7 + 2) {
      *(undefined2 *)pbVar7 = *puVar8;
      puVar8 = puVar8 + 1;
    }
  }
  sVar2 = _DAT_0080d1a0;
  DAT_00fffa27 = 0xaa;
  DAT_00ffd00f = 0xaa;
  bVar13 = 1;
  do {
    if (((sVar2 == 2) && (bVar13 == 1)) || ((sVar2 == 1 && (bVar13 == 2)))) {
      DAT_00fffa27 = 0xaa;
      DAT_00ffd00f = 0xaa;
      uVar1 = eepromCalibrationWritePrimary();
      unaff_D7 = uVar1 & 0xffff;
      DAT_00fffa27 = 0xaa;
      DAT_00ffd00f = 0xaa;
    }
    else if (((sVar2 == 1) && (bVar13 == 1)) || ((sVar2 == 2 && (bVar13 == 2)))) {
      DAT_00fffa27 = 0xaa;
      DAT_00ffd00f = 0xaa;
      uVar1 = eepromCalibrationWriteSecondary();
      unaff_D7 = uVar1 & 0xffff;
      DAT_00fffa27 = 0xaa;
      DAT_00ffd00f = 0xaa;
    }
    if ((short)unaff_D7 == 1) {
      vp44StatusInitAndWait();
    }
    if (_DAT_00803686 != _DAT_00803688) {
      parameterCircularBufferWrite
                (0x803688,&DAT_00803686,
                 CONCAT22(2,(ushort)(byte)((_DAT_00803686 < _DAT_00803688) << 4 |
                                           ((short)(_DAT_00803686 - _DAT_00803688) < 0) << 3 |
                                           SBORROW2(_DAT_00803686,_DAT_00803688) << 1 |
                                          _DAT_00803686 < _DAT_00803688)));
      uVar5 = 0;
      while( true ) {
        DAT_00fffa27 = 0xaa;
        DAT_00ffd00f = 0xaa;
        if ((999 < uVar5) || (_DAT_00803686 == _DAT_00803688)) break;
        emptyPlaceholderFunction();
        sVar3 = 0;
        do {
          uVar14 = 0;
          do {
            uVar14 = uVar14 + 1;
          } while (uVar14 < 0xa0);
          sVar3 = sVar3 + 1;
        } while (sVar3 == 0);
        uVar5 = uVar5 + 1;
      }
    }
    bVar6 = 0;
    while (bVar6 < 4) {
      DAT_00fffa27 = 0xaa;
      DAT_00ffd00f = 0xaa;
      vp44_status_data_collector();
      delayWithWatchdogService(CONCAT22(10000,uVar15));
      bVar6 = bVar6 + 1;
    }
    if ((DAT_0080bdc6 & 1) != 0) {
      vp44StatusInitAndWait();
    }
    bVar6 = bVar13 + 1;
    cVar12 = bVar13 - 1;
    bVar13 = bVar6;
  } while (bVar6 < 3);
  uVar14 = (ushort)(byte)((bVar6 < 2) << 4 | (cVar12 < '\0') << 3 | (bVar6 == 2) << 2 |
                          SBORROW1(bVar6,'\x02') << 1 | bVar6 < 2);
  local_a = _DAT_0080d4c4;
  parameterCircularBufferWrite(0x80352c,(undefined1 *)&local_a,CONCAT22(4,uVar14));
  uVar5 = 0;
  while( true ) {
    DAT_00fffa27 = 0xaa;
    DAT_00ffd00f = 0xaa;
    if ((999 < uVar5) || (_DAT_0080352c == local_a)) break;
    emptyPlaceholderFunction();
    sVar2 = 0;
    do {
      uVar4 = 0;
      do {
        uVar4 = uVar4 + 1;
      } while (uVar4 < 0xa0);
      sVar2 = sVar2 + 1;
    } while (sVar2 == 0);
    uVar5 = uVar5 + 1;
  }
  local_6 = 0;
  parameterCircularBufferWrite
            (0x80367e,(undefined1 *)&local_6,
             CONCAT22(2,(ushort)(byte)(((uVar14 & 0x10) != 0) << 4 | ((uVar14 & 8) != 0) << 3 |
                                       ((uVar14 & 4) != 0) << 2 | ((uVar14 & 2) != 0) << 1 |
                                      (uVar14 & 1) != 0)));
  uVar5 = 0;
  while ((uVar5 < 1000 && (_DAT_0080367e != local_6))) {
    emptyPlaceholderFunction();
    sVar2 = 0;
    do {
      uVar14 = 0;
      do {
        DAT_00fffa27 = 0xaa;
        DAT_00ffd00f = 0xaa;
        uVar14 = uVar14 + 1;
      } while (uVar14 < 0xa0);
      sVar2 = sVar2 + 1;
    } while (sVar2 == 0);
    uVar5 = uVar5 + 1;
  }
  flashBootloaderProgrammer();
  DAT_0080bdf0 = DAT_0080bdf0 & 0xf3;
  DAT_00fffa27 = 0xaa;
  DAT_00ffd00f = 0xaa;
  ioControlAndCanPinSwitching();
  local_6 = 0;
  sVar2 = _DAT_00fff404;
  do {
    while ((ushort)(_DAT_00fff404 - sVar2) < 500) {
      DAT_00fffa27 = 0xaa;
      DAT_00ffd00f = 0xaa;
      vp44_status_data_collector();
      if ((DAT_0080bdc6 & 1) != 0) {
        DAT_0080bdf0 = DAT_0080bdf0 & 0xfb | 8;
        DAT_00fffa27 = 0xaa;
        DAT_00ffd00f = 0xaa;
        ioControlAndCanPinSwitching();
        vp44StatusInitAndWait();
      }
    }
    local_6 = local_6 + 1;
    sVar2 = _DAT_00fff404;
  } while (local_6 < 0x28);
  DAT_0080bdf0 = DAT_0080bdf0 & 0xfb | 8;
  DAT_00fffa27 = 0xaa;
  DAT_00ffd00f = 0xaa;
  ioControlAndCanPinSwitching();
  DAT_00fffa27 = 0xaa;
  DAT_00ffd00f = 0xaa;
  bVar13 = 0;
  while( true ) {
    cVar12 = bVar13 < 4;
    cVar11 = SBORROW1(bVar13,'\x04');
    cVar9 = (char)(bVar13 - 4) < '\0';
    if (!(bool)cVar12) break;
    DAT_00fffa27 = 0xaa;
    DAT_00ffd00f = 0xaa;
    vp44_status_data_collector();
    delayWithWatchdogService(CONCAT22(10000,uVar15));
    bVar13 = bVar13 + 1;
  }
  cVar10 = (DAT_0080bdc6 & 1) == 0;
  bVar13 = cVar12;
  if (!(bool)cVar10) {
    vp44StatusInitAndWait();
  }
  local_6 = 1;
  parameterCircularBufferWrite
            (0x80367e,(undefined1 *)&local_6,
             CONCAT22(2,(ushort)(byte)(cVar12 << 4 | cVar9 << 3 | cVar10 << 2 | cVar11 << 1 | bVar13
                                      )));
  uVar5 = 0;
  while ((uVar5 < 1000 && (_DAT_0080367e != local_6))) {
    emptyPlaceholderFunction();
    sVar2 = 0;
    do {
      uVar14 = 0;
      do {
        DAT_00fffa27 = 0xaa;
        DAT_00ffd00f = 0xaa;
        uVar14 = uVar14 + 1;
      } while (uVar14 < 0xa0);
      sVar2 = sVar2 + 1;
    } while (sVar2 == 0);
    uVar5 = uVar5 + 1;
  }
  while ((DAT_0080bdc6 & 1) == 0) {
    vp44_status_data_collector();
  }
  vp44StatusInitAndWait();
  return;
}



//
// Function: huffmanTreeBuilder @ 0x00024d06
//

short huffmanTreeBuilder(int param_1)

{
  ushort uVar2;
  uint uVar1;
  ushort uVar3;
  uint uVar4;
  ushort uVar5;
  
  *(undefined2 *)(param_1 + 0xc06) = 0xffff;
  for (uVar2 = 0; uVar2 < 0x100; uVar2 = uVar2 + 1) {
    *(ushort *)(param_1 + (uint)uVar2 * 6) = (ushort)(byte)(&DAT_0002160e)[(short)uVar2];
  }
  *(undefined2 *)(param_1 + 0x600) = 1;
  uVar2 = 0x101;
  while( true ) {
    uVar5 = 0x201;
    uVar4 = 0x201;
    uVar1 = 0;
    while( true ) {
      uVar3 = (ushort)uVar1;
      if (uVar2 <= uVar3) break;
      DAT_00fffa27 = 0xaa;
      DAT_00ffd00f = 0xaa;
      if (*(short *)(param_1 + uVar1 * 6) != 0) {
        if (*(ushort *)(param_1 + uVar1 * 6) < *(ushort *)(param_1 + (uint)uVar5 * 6)) {
          uVar4 = (uint)uVar5;
          uVar5 = uVar3;
        }
        else if (*(ushort *)(param_1 + uVar1 * 6) < *(ushort *)(param_1 + uVar4 * 6)) {
          uVar4 = uVar1;
        }
      }
      uVar1 = (uint)(ushort)(uVar3 + 1);
    }
    if ((short)uVar4 == 0x201) break;
    *(short *)(param_1 + (uint)uVar2 * 6) =
         *(short *)(param_1 + uVar4 * 6) + *(short *)(param_1 + (uint)uVar5 * 6);
    *(undefined2 *)(param_1 + (uint)uVar5 * 6) = 0;
    *(undefined2 *)(param_1 + uVar4 * 6) = 0;
    *(ushort *)(param_1 + 2 + (uint)uVar2 * 6) = uVar5;
    *(short *)(param_1 + 4 + (uint)uVar2 * 6) = (short)uVar4;
    uVar2 = uVar2 + 1;
  }
  return uVar2 - 1;
}



//
// Function: huffmanDecompress @ 0x00024e58
//

void huffmanDecompress(int param_1,undefined4 param_2)

{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  byte *pbVar4;
  undefined *local_8;
  
  bVar2 = 0;
  pbVar4 = &DAT_0002170d;
  local_8 = &DAT_00800000;
  bVar1 = false;
  while( true ) {
    DAT_00fffa27 = 0xaa;
    DAT_00ffd00f = 0xaa;
    uVar3 = param_2._0_2_;
    do {
      bVar2 = (byte)((int)(uint)bVar2 >> 1);
      if (bVar2 == 0) {
        bVar2 = 0x80;
        pbVar4 = pbVar4 + 1;
        if (&DAT_00024d04 < pbVar4) {
          bVar1 = true;
        }
      }
      if ((*pbVar4 & bVar2) == 0) {
        uVar3 = *(ushort *)(param_1 + 2 + (uint)uVar3 * 6);
      }
      else {
        uVar3 = *(ushort *)(param_1 + 4 + (uint)uVar3 * 6);
      }
    } while ((0x100 < uVar3) && (!bVar1));
    if (bVar1) break;
    *local_8 = (char)uVar3;
    local_8 = local_8 + 1;
  }
  return;
}



//
// Function: huffmanDecompressMain @ 0x00024efc
//

void huffmanDecompressMain(void)

{
  short sVar1;
  undefined4 unaff_A2;
  undefined2 *puVar2;
  undefined2 uVar3;
  undefined2 local_c0a [1539];
  
  uVar3 = (undefined2)((uint)unaff_A2 >> 0x10);
  for (puVar2 = local_c0a; puVar2 < &stack0xfffffffc; puVar2 = puVar2 + 3) {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
  }
  sVar1 = huffmanTreeBuilder((int)local_c0a);
  huffmanDecompress((int)local_c0a,CONCAT22(sVar1,uVar3));
  return;
}



//
// Function: busyWaitDelayLoop @ 0x00024f36
//

void busyWaitDelayLoop(undefined4 param_1)

{
  ushort uVar1;
  ushort uVar2;
  
  for (uVar2 = 0; uVar2 < param_1._0_2_; uVar2 = uVar2 + 1) {
    for (uVar1 = 0; uVar1 < 0x378; uVar1 = uVar1 + 1) {
    }
  }
  return;
}



//
// Function: portPinTestSequence1 @ 0x00024f50
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte portPinTestSequence1(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  undefined4 unaff_D2;
  undefined2 uVar4;
  undefined2 uVar5;
  
  _DAT_00fff208 = _DAT_00fff208 | 0x700;
  _DAT_00fff206 = 0x600;
  uVar5 = 1;
  busyWaitDelayLoop(CONCAT22(1,(short)((uint)unaff_D2 >> 0x10)));
  uVar1 = _DAT_00fff206 & 1;
  _DAT_00fff208 = _DAT_00fff208 | 0x700;
  _DAT_00fff206 = 0x400;
  uVar4 = 1;
  busyWaitDelayLoop(CONCAT22(1,uVar5));
  uVar2 = _DAT_00fff206 & 1;
  _DAT_00fff208 = _DAT_00fff208 | 0x700;
  _DAT_00fff206 = 0x300;
  uVar5 = 1;
  busyWaitDelayLoop(CONCAT22(1,uVar4));
  uVar3 = _DAT_00fff206 & 2;
  _DAT_00fff208 = _DAT_00fff208 | 0x700;
  _DAT_00fff206 = 0x200;
  busyWaitDelayLoop(CONCAT22(1,uVar5));
  return -((_DAT_00fff206 & 1) != 0) & 1U &
         -(uVar3 != 0) & 1U & -(uVar2 != 0) & 1U & -(uVar1 != 0) & 1U;
}



//
// Function: waitForPortPinStable @ 0x00025020
//

void waitForPortPinStable(void)

{
  undefined4 unaff_D2;
  byte bVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((uint)unaff_D2 >> 0x10);
  bVar1 = 0;
  while (bVar1 < 5) {
    if ((DAT_00ffd000 & 1) == 0) {
      bVar1 = 0;
    }
    else {
      bVar1 = bVar1 + 1;
    }
    busyWaitDelayLoop(CONCAT22(2,uVar2));
  }
  return;
}



//
// Function: portPinTestSequence2 @ 0x0002504e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte portPinTestSequence2(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 unaff_D2;
  undefined2 uVar3;
  undefined2 uVar4;
  
  _DAT_00fff208 = _DAT_00fff208 | 0x700;
  _DAT_00fff206 = 0x200;
  uVar4 = 1;
  busyWaitDelayLoop(CONCAT22(1,(short)((uint)unaff_D2 >> 0x10)));
  uVar1 = _DAT_00fff206 & 1;
  _DAT_00fff208 = _DAT_00fff208 | 0x700;
  _DAT_00fff206 = 0x300;
  uVar3 = 1;
  busyWaitDelayLoop(CONCAT22(1,uVar4));
  uVar2 = _DAT_00fff206 & 2;
  _DAT_00fff208 = _DAT_00fff208 | 0x700;
  _DAT_00fff206 = 0x600;
  busyWaitDelayLoop(CONCAT22(1,uVar3));
  DAT_00807c86 = -((DAT_00ffd001 & 1) != 0) & 1U &
                 -((_DAT_00fff206 & 1) != 0) & 1U & -(uVar2 == 0) & 1U & -(uVar1 != 0) & 1U;
  return DAT_00807c86;
}



//
// Function: tpuAndQadcVerification @ 0x00025108
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 tpuAndQadcVerification(void)

{
  byte bVar1;
  
  _DAT_00fffc18 = 0x8004;
  DAT_00fffc16 = 0x7b;
  DAT_00fffc17 = 0xfe;
  DAT_00fffc15 = 0xff;
  _DAT_00fffc1a = _DAT_00fffc1a & 0x8000 | 0x1028;
  _DAT_00fffc1c = _DAT_00fffc1c & 0xf0ff | 0xf00;
  _DAT_00fffd20 = 3;
  DAT_00fffd40 = 0xbd;
  _DAT_00fffd22 = 0;
  DAT_00fffd41 = 0xfd;
  for (bVar1 = 2; bVar1 < 0x10; bVar1 = bVar1 + 1) {
    *(undefined2 *)(&DAT_00fffd20 + (uint)bVar1 * 2) = 0;
    (&DAT_00fffd40)[bVar1] = 0xbd;
  }
  _DAT_00fffc1a = _DAT_00fffc1a | 0x8000;
  do {
    do {
    } while ((DAT_00fffc1f & 0x80) == 0);
  } while ((DAT_00fffc1f & 0xf) != 0xf);
  if (((uint)_DAT_00fffd06 | (uint)_DAT_00fffd04 << 8) != 0x600d) {
    return 1;
  }
  return 0x6000;
}



//
// Function: hardwareInitAndStartup @ 0x000251f4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void hardwareInitAndStartup(void)

{
  byte bVar2;
  undefined4 uVar1;
  code *pcVar3;
  
  DAT_00ffd008 = 0x40;
  DAT_00ffd00e = 0x80;
  waitForPortPinStable();
  DAT_00fffa15 = DAT_00fffa15 | 8;
  DAT_00fffa11 = DAT_00fffa11 | 8;
  DAT_00fffc1f = DAT_00fffc1f & 0x7f;
  _DAT_00fffc1a = _DAT_00fffc1a & 0x7fff;
  _DAT_00fffc1c = _DAT_00fffc1c & 0x7ff0;
  _DAT_00fffc0a = 0;
  _DAT_00fffa22 = 0;
  _DAT_00fffa24 = 0;
  _DAT_00fffe0a = 0;
  _DAT_00fff418 = 0;
  _DAT_00fff420 = 0;
  _DAT_00fff428 = 0;
  _DAT_00fff430 = 0;
  _DAT_00fff438 = 0;
  _DAT_00fff440 = 0;
  _DAT_00fff448 = 0;
  _DAT_00fff450 = 0;
  _DAT_00fff400 = 0x1601;
  _DAT_00fff408 = 8;
  _DAT_00fff410 = 0;
  tpu_timer_channel_register._0_2_ = 4;
  _DAT_00fff460 = 0x104;
  _DAT_00fffc00 = 5;
  DAT_00fffc04 = 0x13;
  DAT_00fffc05 = 0x50;
  ramClearWithWatchdog();
  bVar2 = portPinTestSequence1();
  if (bVar2 == 0) {
    bVar2 = portPinTestSequence2();
    if (bVar2 == 0) {
      uVar1 = tpuAndQadcVerification();
      if ((char)uVar1 == '\0') {
        if ((_canBufferSetup1 == -0x6789abcd) || (_canBufferSetup1 == -0x6789abce)) {
          pcVar3 = (code *)&SUB_70003002;
        }
        else {
          pcVar3 = (code *)&SUB_b0390080;
        }
        goto LAB_00025350;
      }
    }
  }
  huffmanDecompressMain();
  pcVar3 = (code *)&SUB_00824b32;
LAB_00025350:
  (*pcVar3)();
  return;
}



//
// Function: ramClearWithWatchdog @ 0x00025356
//

void ramClearWithWatchdog(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)&DAT_00800000;
  while (puVar2 < (undefined4 *)0x807eb0) {
    puVar1 = puVar2 + 0x40;
    if ((undefined4 *)0x807eb0 < puVar1) {
      puVar1 = (undefined4 *)0x807eb0;
    }
    for (; puVar2 < puVar1; puVar2 = puVar2 + 1) {
      *puVar2 = 0;
    }
    DAT_00fffa27 = 0xaa;
    DAT_00ffd00f = 0xaa;
  }
  return;
}



//
// Function: flashBootloaderProgrammer @ 0x000253a6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void flashBootloaderProgrammer(void)

{
  int iVar1;
  undefined4 unaff_D2;
  code *pcVar2;
  code *pcVar3;
  code *pcVar4;
  undefined2 uVar5;
  undefined1 auStack_104 [256];
  
  uVar5 = (undefined2)((uint)unaff_D2 >> 0x10);
  if ((_DAT_00808912 == -0x452f) && (_DAT_00000014 < DAT_000214fe)) {
    DAT_0080bdf0 = DAT_0080bdf0 | 2;
    ioControlAndCanPinSwitching();
    iVar1 = flashEraseFromRam(0);
    if (iVar1 == 0) {
      pcVar4 = (code *)0x0;
      pcVar3 = (code *)&DAT_000214ea;
      while (pcVar3 < flashBootloaderProgrammer) {
        pcVar2 = (code *)auStack_104;
        for (; (pcVar2 < &stack0xfffffffc && (pcVar3 < flashBootloaderProgrammer));
            pcVar3 = pcVar3 + 1) {
          *pcVar2 = *pcVar3;
          pcVar2 = pcVar2 + 1;
        }
        flashProgramFromRam((int)pcVar4,auStack_104,
                            CONCAT22((short)pcVar2 - (short)auStack_104,uVar5));
        pcVar4 = pcVar2 + ((int)pcVar4 - (int)auStack_104);
      }
    }
    DAT_0080bdf0 = DAT_0080bdf0 & 0xfd;
    ioControlAndCanPinSwitching();
  }
  return;
}



//
// Function: dataBufferCopy @ 0x0002544a
//

void dataBufferCopy(undefined1 *param_1,undefined4 param_2)

{
  ushort uVar1;
  undefined *puVar2;
  
  puVar2 = &DAT_00801794;
  for (uVar1 = 0; uVar1 < param_2._0_2_; uVar1 = uVar1 + 1) {
    *puVar2 = *param_1;
    param_1 = (undefined1 *)CONCAT31(param_1._0_3_,(char)param_1 + '\x01');
    puVar2 = puVar2 + 1;
  }
  return;
}



//
// Function: diagnosticResponseBuilder @ 0x00025476
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint diagnosticResponseBuilder(undefined4 param_1)

{
  short sVar1;
  uint in_D0;
  uint uVar2;
  byte bVar3;
  byte bVar5;
  ushort uVar4;
  byte bVar6;
  byte bVar7;
  byte *pbVar8;
  undefined1 *puVar9;
  undefined4 local_8;
  
  pbVar8 = &CMSYRSFG;
  bVar3 = 0;
  bVar5 = 0;
  for (bVar6 = 0; bVar7 = (byte)((uint)param_1 >> 0x10), bVar6 < bVar7; bVar6 = bVar6 + 1) {
    if ((pbVar8[9] == 5) || (pbVar8[9] == 3)) {
      bVar5 = bVar5 + 1;
      bVar3 = pbVar8[8] + bVar3;
    }
    in_D0 = 0;
    pbVar8 = pbVar8 + 10;
  }
  if ((bVar5 == 0) ||
     (((uint)bVar5 + (uint)_DAT_0080d44e < 0xb &&
      (in_D0 = (int)&DAT_0080d3a6 - (int)_DAT_0080d3e2, (int)(uint)bVar3 <= (int)in_D0)))) {
    pbVar8 = &CMSYRSFG;
    for (bVar5 = 0; bVar5 < bVar7; bVar5 = bVar5 + 1) {
      local_8 = *(undefined1 **)(pbVar8 + 4);
      uVar4 = (ushort)pbVar8[8];
      if ((pbVar8[9] == 5) || (pbVar8[9] == 3)) {
        *(undefined1 **)(&DAT_0080d3a6 + (short)(_DAT_0080d44e * 3) * 2) = *(undefined1 **)pbVar8;
        sVar1 = _DAT_0080d44e * 3;
        _DAT_0080d44e = _DAT_0080d44e + 1;
        *(ushort *)(sVar1 * 2 + 0x80d3aa) = uVar4;
        for (bVar3 = 0; bVar3 < uVar4; bVar3 = bVar3 + 1) {
          *_DAT_0080d3e2 = *local_8;
          local_8 = (undefined1 *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
          _DAT_0080d3e2 = _DAT_0080d3e2 + 1;
        }
      }
      else {
        puVar9 = *(undefined1 **)pbVar8;
        for (bVar3 = 0; bVar3 < uVar4; bVar3 = bVar3 + 1) {
          *puVar9 = *local_8;
          local_8 = (undefined1 *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
          puVar9 = puVar9 + 1;
        }
      }
      in_D0 = 0;
      pbVar8 = pbVar8 + 10;
    }
    uVar2 = in_D0 & 0xffffff00;
  }
  else {
    uVar2 = 0xe;
  }
  return uVar2;
}



//
// Function: system_startup @ 0x00025596
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void system_startup(void)

{
  uRam00fffa00 = 0x604f;
  uRam00fffa04 = 0x7f08;
  DAT_00fffa11 = 0xa9;
  DAT_00fffa15 = 0xfe;
  uRam00fffa17 = 1;
  DAT_00fffa19 = 0xff;
  uRam00fffa1d = 0xc9;
  uRam00fffa1f = 0x30;
  uRam00fffa21 = 0x9e;
  uRam00fffa44 = 0x2bbf;
  uRam00fffa46 = 0;
  uRam00fffa48 = 5;
  uRam00fffa4a = 0x6830;
  uRam00fffa4c = 0x8003;
  uRam00fffa4e = 0x5830;
  uRam00fffa50 = 0x8003;
  uRam00fffa52 = 0x3830;
  uRam00fffa54 = 0xffd0;
  uRam00fffa56 = 0x5830;
  uRam00fffa58 = 5;
  uRam00fffa5a = 0x7030;
  uRam00fffa5c = 0xffd8;
  uRam00fffa5e = 0x5bf0;
  uRam00fffa60 = 0xffc8;
  uRam00fffa62 = 0x5bf0;
  _DAT_00fffa64 = 0;
  _DAT_00fffa66 = 0;
  _DAT_00fffa68 = 0xfffb;
  _DAT_00fffa6a = 0x2801;
  _DAT_00fffa6c = 0;
  _DAT_00fffa6e = 0;
  _DAT_00fffa70 = 0;
  _DAT_00fffa72 = 0;
  _DAT_00fffa74 = 0;
  _DAT_00fffa76 = 0;
  mainSystemInitialization();
  return;
}



//
// Function: initDiagnosticProtocol @ 0x000256a4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 initDiagnosticProtocol(void)

{
  byte bVar1;
  
  _DAT_0080d452 = &DAT_0080d2de;
  _DAT_0080d45a = 200;
  _DAT_0080d44a = &DAT_0080d3a6;
  _DAT_0080d44e = 0;
  _DAT_0080d3e2 = &DAT_0080d2de;
  diagnosticBufferPointerInit();
  DAT_0080d2d3 = 0;
  DAT_0080d2db = 0;
  DAT_0080d2d0 = 1;
  DAT_0080d2da = 0;
  DAT_0080d2dc = 0;
  DAT_0080d404 = 0;
  DAT_0080d405 = 0;
  _DAT_00809d3e = _DAT_008037f0;
  _DAT_0080d41c = &DAT_0080d422;
  _DAT_0080d440 = &DAT_00808962;
  for (bVar1 = 0; (*_DAT_0080d440 != '\0' && (bVar1 < 0x1e)); bVar1 = bVar1 + 1) {
    *_DAT_0080d41c = _DAT_0080d440[2] + _DAT_0080d440[1];
    _DAT_0080d41c = _DAT_0080d41c + 1;
    _DAT_0080d440 = _DAT_0080d440 + 3;
  }
  _DAT_00fffc08 = 0x34;
  _DAT_00fffc0a = 0x102c;
  return _DAT_00fffc0c;
}



//
// Function: systemControl64 @ 0x00025768
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void systemControl64(void)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  undefined4 unaff_D2;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  undefined4 local_8;
  
  if (DAT_0080d404 != '\0') {
    if (diag_transfer_state_t_0080d3f8.byte_count < 0x10) {
      bVar6 = (byte)diag_transfer_state_t_0080d3f8.byte_count + 4;
      DAT_0080d404 = '\0';
      bVar5 = (byte)diag_transfer_state_t_0080d3f8.byte_count;
    }
    else {
      bVar6 = 0x13;
      bVar5 = 0xf;
    }
    if ((int)_DAT_0080d2b4 < _DAT_0080d2bc) {
      iVar3 = (_DAT_0080d2bc - (int)_DAT_0080d2b4) + -2;
    }
    else {
      iVar3 = (_DAT_0080d2bc - (int)_DAT_0080d2b4) + 0xfe;
    }
    if ((int)(uint)bVar6 < iVar3) {
      local_8._3_1_ = (char)_DAT_0080d2b4;
      cVar2 = (char)local_8;
      local_8._0_3_ = (undefined3)((uint)_DAT_0080d2b4 >> 8);
      local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
      *local_8 = 7;
      local_8 = (byte *)CONCAT31(local_8._0_3_,cVar2 + '\x02');
      *local_8 = bVar5 | 0xb0;
      local_8 = (byte *)CONCAT31(local_8._0_3_,cVar2 + '\x03');
      *local_8 = (undefined1)diag_transfer_state_t_0080d3f8.target_address;
      local_8 = (byte *)CONCAT31(local_8._0_3_,cVar2 + '\x04');
      *local_8 = diag_transfer_state_t_0080d3f8.target_address._0_1_;
      local_8 = (byte *)CONCAT31(local_8._0_3_,cVar2 + '\x05');
      for (bVar4 = 0; bVar4 < bVar5; bVar4 = bVar4 + 1) {
        bVar1 = *(byte *)diag_transfer_state_t_0080d3f8.data_pointer;
        diag_transfer_state_t_0080d3f8.data_pointer =
             diag_transfer_state_t_0080d3f8.data_pointer + 1;
        *local_8 = bVar1;
        local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
      }
      diag_transfer_state_t_0080d3f8.byte_count = diag_transfer_state_t_0080d3f8.byte_count - bVar5;
      *_DAT_0080d2b4 = bVar6;
      *local_8 = 0;
      _DAT_0080d2b4 = local_8;
      tpuTransmissionTrigger();
    }
    else {
      DAT_0080d404 = '\0';
      diagnosticMessageQueueWrite(CONCAT22(4,(short)((uint)unaff_D2 >> 0x10)));
      fault_status_registers_t_00805df2.io_fault_status_4 =
           fault_status_registers_t_00805df2.io_fault_status_4 | 4;
      fault_latch_registers_t_00805e32.io_fault_latch_4 =
           fault_latch_registers_t_00805e32.io_fault_latch_4 | 4;
    }
  }
  return;
}



//
// Function: systemControl74 @ 0x0002588c
//

void systemControl74(void)

{
  if (DAT_0080d405 != '\0') {
    memoryPatchCountDecrement();
  }
  DAT_0080d404 = 0;
  DAT_0080d405 = 0;
  return;
}



//
// Function: systemControl75 @ 0x000258aa
//

void systemControl75(void)

{
  if (DAT_0080d405 != '\0') {
    memoryPatchCountDecrement();
  }
  DAT_0080d404 = 0;
  DAT_0080d405 = 0;
  return;
}



//
// Function: memoryPatchBufferInit @ 0x000258c8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void memoryPatchBufferInit(void)

{
  _DAT_0080d3e2 = &DAT_0080d2de;
  _DAT_0080d458 = 0;
  _DAT_0080d44e = 0;
  return;
}



//
// Function: memoryPatchingSystem @ 0x000258e0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint memoryPatchingSystem(void)

{
  system_protected_area_t *psVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  uint in_D0;
  undefined4 uVar5;
  char cVar7;
  uint uVar6;
  byte bVar8;
  byte bVar9;
  byte *pbVar10;
  uint *puVar11;
  uint *puVar12;
  
  if (_DAT_0080d44e == 0) {
    return in_D0 & 0xffffff00;
  }
  if ((_DAT_0080d1a4 == 1) && (_DAT_0080d19c != 0)) {
    puVar12 = (uint *)(&DAT_0080d3a6 + (short)((_DAT_0080d44e & 0xff) * 6));
    cVar7 = DAT_0080d44f;
    while( true ) {
      puVar11 = (uint *)((int)puVar12 + -6);
      cVar4 = cVar7 + -1;
      if (cVar7 == '\0') break;
      psVar1 = (system_protected_area_t *)*puVar11;
      pbVar10 = (byte *)((int)puVar12 + -1);
      if ((((system_protected_area_t *)0xffffff < psVar1) ||
          ((&system_protected_area_t_008062cb < psVar1 &&
           (psVar1 < (system_protected_area_t *)0x8062cf)))) ||
         ((puVar12 = puVar11, cVar7 = cVar4,
          &system_protected_area_t_008062cb < psVar1->protected_flags + *pbVar10 &&
          (psVar1->protected_flags + *pbVar10 < (byte *)0x8062cf)))) {
        memoryPatchBufferInit();
        return 7;
      }
    }
  }
  if ((_DAT_0080d3f4 == 0) &&
     ((_DAT_0080d458 == 0 || (uVar5 = memoryPatchCrcCalculate(), (short)uVar5 != _DAT_0080d456)))) {
    memoryPatchBufferInit();
    return 0x14;
  }
  if (10 < _DAT_0080d44e) {
    memoryPatchBufferInit();
    return 4;
  }
  _DAT_0080d3e2 = &DAT_0080d2de;
  bVar9 = 0;
  puVar12 = (uint *)&DAT_0080d3a6;
  do {
    if (_DAT_0080d44e <= bVar9) {
      uVar6 = memoryPatchBufferInit();
      return uVar6 & 0xffffff00;
    }
    pbVar10 = (byte *)*puVar12;
    bVar3 = *(byte *)((int)puVar12 + 5);
    if (pbVar10 < (byte *)0x1000000) {
      for (bVar8 = 0; bVar8 < bVar3; bVar8 = bVar8 + 1) {
        if (((&system_protected_area_t_008062cb < pbVar10) && (pbVar10 < (byte *)0x8062cf)) &&
           (_DAT_0080d3f4 == 0)) {
          _DAT_0080d19e = 0;
        }
        bVar2 = *_DAT_0080d3e2;
        _DAT_0080d3e2 = _DAT_0080d3e2 + 1;
        *pbVar10 = bVar2;
        pbVar10 = pbVar10 + 1;
      }
    }
    else {
      if ((_DAT_0080d19c == 1) &&
         (cVar7 = circularBufferWrite((short)((uint)_DAT_0080d3e2 >> 0x10),bVar3), cVar7 == '\x01'))
      {
        memoryPatchBufferInit();
        return 4;
      }
      pbVar10 = pbVar10 + -0x7fcb08;
      for (bVar8 = 0; bVar8 < bVar3; bVar8 = bVar8 + 1) {
        bVar2 = *_DAT_0080d3e2;
        _DAT_0080d3e2 = _DAT_0080d3e2 + 1;
        *pbVar10 = bVar2;
        pbVar10 = pbVar10 + 1;
      }
    }
    puVar12 = (uint *)((int)puVar12 + 6);
    bVar9 = bVar9 + 1;
  } while( true );
}



//
// Function: advanced_oil_pressure_protection_system @ 0x00025a90
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void advanced_oil_pressure_protection_system(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  short sVar6;
  uint uVar7;
  ushort uVar8;
  ushort local_10;
  ushort local_c;
  ushort uStack_6;
  
  if (_DAT_0080d17a == 1) {
    if (_DAT_008018a4 != 1) {
      fuelDemandProportionalCalculator();
    }
    sVar6 = _DAT_0080d172;
    sVar5 = _DAT_0080d168;
    if (_DAT_00801894 != _DAT_0080d174) {
      uStack_6 = (ushort)((uint)_DAT_008036aa * (uint)_DAT_0080d174 >> 10);
      uVar7 = (uint)_DAT_008036a8 * (uint)(ushort)(uStack_6 + 0x200);
      if (uVar7 < 0xf99999) {
        if (uVar7 < 0x41894) {
          _DAT_00801896 = 0x20c;
        }
        else {
          uStack_6 = (ushort)(uVar7 >> 9);
          _DAT_00801896 = uStack_6;
        }
      }
      else {
        _DAT_00801896 = 0x7ccc;
      }
    }
    _DAT_00801894 = _DAT_0080d174;
    _DAT_0080d168 = exponentialMovingAverage();
    if (_DAT_00808918 < _DAT_0080d168) {
      _DAT_0080d168 = _DAT_00808918;
    }
    if (_DAT_0080d168 < _DAT_0080891a) {
      _DAT_0080d168 = _DAT_0080891a;
    }
    uVar7 = (uint)_DAT_00808922 * ((uint)_DAT_00801896 * (uint)_DAT_008036a6 >> 10 & 0xffff);
    if (uVar7 < 0x1000000) {
      uStack_6 = (ushort)(uVar7 >> 10);
      uVar8 = uStack_6;
    }
    else {
      uVar8 = 0x4000;
    }
    _DAT_0080d16a = (short)(((int)_DAT_0080d168 * (int)(short)_DAT_00808922) / 0x3c0);
    if (0x1700 < _DAT_0080d16a) {
      _DAT_0080d16a = 0x1700;
    }
    if (_DAT_0080d16a < -0x1700) {
      _DAT_0080d16a = -0x1700;
    }
    _DAT_0080d16c = (short)(((int)_DAT_00808914 * ((int)_DAT_0080d168 - (int)sVar5)) / 0xf0);
    if (0x1c4a < _DAT_0080d16c) {
      _DAT_0080d16c = 0x1c4a;
    }
    if (_DAT_0080d16c < -0x1c4a) {
      _DAT_0080d16c = -0x1c4a;
    }
    _DAT_0080d172 = _DAT_0080d16c + _DAT_0080d16a;
    if (0x1700 < _DAT_0080d172) {
      _DAT_0080d172 = 0x1700;
    }
    if (_DAT_0080d172 < -0x1700) {
      _DAT_0080d172 = -0x1700;
    }
    if (_DAT_0080d0aa < _DAT_0080d166) {
      uStack_6 = (ushort)((uint)uVar8 * ((uint)_DAT_0080d166 - (uint)_DAT_0080d0aa) >> 0xe);
      _DAT_0080d170 = uStack_6;
    }
    else {
      _DAT_0080d170 = 0;
    }
    uStack_6 = (ushort)((uint)uVar8 * (0x7fff - (uint)_DAT_00808920) >> 0xe);
    uVar1 = uStack_6 + _DAT_00808920;
    iVar3 = (uint)_DAT_0080891c * (uint)uVar1 * 2;
    iVar4 = (uint)_DAT_0080891e * (uint)uVar1 * 2;
    if (fuel_demand_state_t_0080c9a4._2_2_ != 4) {
      _DAT_0080d172 = _DAT_0080d16a;
      if (_DAT_0080d0aa < fuel_demand_state_t_0080c9a4.command) {
        uStack_6 = (ushort)((uint)uVar8 *
                            ((uint)fuel_demand_state_t_0080c9a4.command - (uint)_DAT_0080d0aa) >>
                           0xe);
        _DAT_0080d170 = uStack_6;
      }
      else {
        _DAT_0080d170 = 0;
      }
      iVar2 = (uint)fuel_demand_state_t_0080c9a4.command * (uint)uVar1 * 2;
      _DAT_008018a0 = (short)((uint)iVar2 >> 0x10);
      _DAT_008018a2 = (undefined2)iVar2;
      _DAT_008018a0 = CONCAT22((_DAT_0080c9c4 + _DAT_008018a0) - _DAT_0080d170,_DAT_008018a2);
    }
    iVar2 = ((int)sVar6 - (int)_DAT_0080d170) * (0x7fff - (short)_DAT_00808920) * 2 + _DAT_008018a0;
    _DAT_008018a0 = (short)((uint)iVar2 >> 0x10);
    _DAT_008018a0 = _DAT_008018a0 - _DAT_0080c9c4;
    _DAT_008018a2 = (undefined2)iVar2;
    local_c = (ushort)((uint)iVar3 >> 0x10);
    if (_DAT_008018a0 < (short)local_c) {
      local_10 = (ushort)((uint)iVar4 >> 0x10);
      if (_DAT_008018a0 < (short)local_10) {
        _DAT_008018a0 = (uint)local_10 << 0x10;
      }
    }
    else {
      _DAT_008018a0 = (uint)local_c << 0x10;
    }
    _DAT_0080d16e = _DAT_008018a0;
    uVar7 = ((int)_DAT_008018a0 + (int)_DAT_0080d172) * 0x8000;
    if (iVar4 >> 1 < (int)uVar7) {
      if ((int)uVar7 < iVar3 >> 1) {
        _DAT_0080d166 = (ushort)(uVar7 / uVar1);
      }
      else {
        _DAT_0080d166 = _DAT_0080891c;
      }
    }
    else {
      _DAT_0080d166 = _DAT_0080891e;
    }
    if ((_DAT_0080d17a == 1) && (_DAT_0080d176 < _DAT_0080d494)) {
      _DAT_0080d494 = _DAT_0080d176;
      _DAT_0080d496 = 0x22;
    }
  }
  else {
    _DAT_0080d166 = 0;
  }
  _DAT_008018a4 = _DAT_0080d17a;
  return;
}



//
// Function: fuelDemandProportionalCalculator @ 0x00025ece
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelDemandProportionalCalculator(void)

{
  int iVar1;
  uint uVar2;
  undefined2 uStack_6;
  
  _DAT_0080d172 = 0;
  rpmSnapshotCapture();
  _DAT_0080189c = 0x80000000;
  _DAT_0080d168 = 0;
  uVar2 = proportionalCalculation
                    ((uint)_DAT_008036a8,((uint)_DAT_008036aa * (uint)_DAT_0080d174 >> 10) + 0x200,1
                    );
  if (uVar2 < 0xf99999) {
    uStack_6 = (ushort)(uVar2 >> 9);
    _DAT_00801896 = uStack_6;
  }
  else {
    _DAT_00801896 = 0x7ccc;
  }
  uVar2 = ((uint)_DAT_00801896 * (uint)_DAT_008036a6 >> 10 & 0xffff) * (int)_DAT_00808922;
  if (uVar2 < 0x1000000) {
    uStack_6 = (ushort)(uVar2 >> 10);
  }
  else {
    uStack_6 = 0x4000;
  }
  uStack_6 = (ushort)((uint)uStack_6 * (0x7fff - (uint)_DAT_00808920) >> 0xe);
  _DAT_008018a0 =
       (uint)fuel_demand_state_t_0080c9a4.command * (uint)(ushort)(uStack_6 + _DAT_00808920) * 2;
  iVar1 = _DAT_008018a0;
  _DAT_008018a0 = (undefined2)((uint)_DAT_008018a0 >> 0x10);
  _DAT_0080d16e = _DAT_008018a0;
  _DAT_0080d166 = fuel_demand_state_t_0080c9a4.command;
  _DAT_008018a0 = iVar1;
  return;
}



//
// Function: fuelDemandScaleFactorCalculator @ 0x00025fda
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelDemandScaleFactorCalculator(void)

{
  undefined4 local_8;
  
  if (_DAT_008086c2 < reference_table_t_008086f6.base_reference) {
    local_8 = 0;
  }
  else {
    local_8 = (uint)_DAT_008086c2 - (uint)reference_table_t_008086f6.base_reference;
  }
  _DAT_0080d176 =
       reference_table_t_008086f6.base_reference +
       (short)(((uint)_DAT_0080380e * (local_8 & 0xffff)) / (uint)_DAT_00807c32);
  _DAT_0080189c = 0x80000000;
  _DAT_00801898 = 0x808916;
  fuelDemandTablePointerInit();
  return;
}



//
// Function: oil_pressure_protection_controller @ 0x0002604e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void oil_pressure_protection_controller(void)

{
  ushort uVar1;
  
  if (_DAT_0080d174 < _DAT_0080d178) {
    uVar1 = _DAT_0080d178 - _DAT_0080d174;
  }
  else {
    uVar1 = _DAT_0080d174 - _DAT_0080d178;
  }
  if (uVar1 <= _DAT_00808926) {
    _DAT_0080d174 = _DAT_0080d178;
    return;
  }
  _DAT_008018aa = (uint)_DAT_0080d174 << 0x10;
  uVar1 = coreTableInterpolation();
  if (uVar1 <= _DAT_0080d174) {
    if ((int)(uint)_DAT_00808926 < (int)((uint)_DAT_0080d174 - (uint)uVar1)) {
      _DAT_0080d174 = uVar1;
      return;
    }
    _DAT_0080d174 = _DAT_0080d174 - _DAT_00808926;
    return;
  }
  if ((int)(uint)_DAT_00808926 <= (int)((uint)uVar1 - (uint)_DAT_0080d174)) {
    _DAT_0080d174 = uVar1;
    return;
  }
  _DAT_0080d174 = _DAT_00808926 + _DAT_0080d174;
  return;
}



//
// Function: rpmSnapshotCapture @ 0x000260ec
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rpmSnapshotCapture(void)

{
  _DAT_0080d174 = circular_buffer_t_0080c3fc.data_buffer_8;
  _DAT_008018aa = 0;
  return;
}



//
// Function: fuelDemandTablePointerInit @ 0x000260fe
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelDemandTablePointerInit(void)

{
  _DAT_008018aa = 0;
  _DAT_008018a6 = 0x808928;
  return;
}



//
// Function: oil_pressure_shutdown_controller @ 0x00026110
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint oil_pressure_shutdown_controller(void)

{
  uint in_D0;
  uint uVar1;
  
  if ((((_DAT_0080d49c == 1) || (_DAT_0080d49c == 2)) || (_DAT_0080d49c == 0x1e)) ||
     (_DAT_0080d49c == 3)) {
    _DAT_0080d184 = _DAT_0080d49c;
    _DAT_0080d182 = _DAT_0080d49a;
    _DAT_0080d180 = 0;
    _DAT_0080d17e = _DAT_008037b4;
    return in_D0;
  }
  if (_DAT_0080d17a == 1) {
    in_D0 = engine_control_flags_t_008035d6.engine_operating_state & 0x10;
    if ((engine_control_flags_t_008035d6.engine_operating_state & 0x10) != 0) {
      if ((_DAT_0080d49c == 7) || (_DAT_0080d49c == 8)) {
        uVar1 = (uint)_DAT_0080d49a;
        if (_DAT_0080d166 <= _DAT_0080d49a) {
          uVar1 = engine_control_flags_t_008035d6.protection_system & 0x2000;
          if ((engine_control_flags_t_008035d6.protection_system & 0x2000) != 0) {
            _DAT_0080d182 = _DAT_0080d49a;
            _DAT_0080d184 = _DAT_0080d49c;
            _DAT_0080d17e = _DAT_0080380a;
            _DAT_0080d180 = 1;
            return uVar1;
          }
        }
        _DAT_0080d182 = _DAT_0080d166;
        _DAT_0080d184 = 4;
        _DAT_0080d180 = 0;
        _DAT_0080d17e = _DAT_008037b4;
        return uVar1;
      }
      if ((_DAT_0080d49c != 6) && (_DAT_0080d49c != 5)) {
        return in_D0;
      }
      _DAT_0080d182 = _DAT_0080d166;
      _DAT_0080d184 = 4;
      _DAT_0080d180 = 0;
      _DAT_0080d17e = _DAT_008037b4;
      return in_D0;
    }
  }
  _DAT_0080d184 = _DAT_0080d49c;
  _DAT_0080d182 = _DAT_0080d49a;
  _DAT_0080d180 = 0;
  _DAT_0080d17e = _DAT_008037b4;
  return in_D0;
}



//
// Function: initOilPressureMonitoring @ 0x0002621c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initOilPressureMonitoring(void)

{
  _DAT_0080d180 = 0;
  _DAT_0080d17e = _DAT_008037b4;
  return;
}



//
// Function: initMIOS14Timers @ 0x0002622e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint initMIOS14Timers(void)

{
  uint uVar1;
  
  _DAT_00fff428 = 8;
  _DAT_00fff430 = 8;
  _DAT_00fff438 = 8;
  _DAT_00fff440 = 8;
  _DAT_00fff414 = -(short)(((uint)_DAT_0080893c * 8000) / 1000) - 1;
  _DAT_00fff418 = _DAT_00fff418 & 0xf | 9;
  uVar1 = 0x7fff0000;
  if ((_DAT_00805670 & 1) == 0) {
    sim_timer_control_register = sim_timer_control_register & 0xffff0000;
  }
  else {
    uVar1 = ((((uint)_DAT_00808934 * (uint)_DAT_0080d186) / 0x6400 & 0xffff) * 8000) / 1000 & 0xffff
            | ((uint)_DAT_00808934 * 8000) / 1000 << 0x10;
    sim_timer_control_register = uVar1;
  }
  uVar1 = uVar1 & 0xffff0000;
  if ((_DAT_00805670 & 2) == 0) {
    _DAT_00fff432 = _DAT_00fff432 & 0xffff0000;
  }
  else {
    uVar1 = ((((uint)_DAT_00808936 * (uint)_DAT_0080d188) / 0x6400 & 0xffff) * 8000) / 1000 & 0xffff
            | ((uint)_DAT_00808936 * 8000) / 1000 << 0x10;
    _DAT_00fff432 = uVar1;
  }
  if (5 < _DAT_0080d19a) {
    uVar1 = uVar1 & 0xffff0000;
    if ((_DAT_00805670 & 4) == 0) {
      tpu_pwm_channel_3_output = tpu_pwm_channel_3_output & 0xffff0000;
    }
    else {
      uVar1 = ((((uint)_DAT_00808938 * (uint)_DAT_0080d18a) / 0x6400 & 0xffff) * 8000) / 1000 &
              0xffff | ((uint)_DAT_00808938 * 8000) / 1000 << 0x10;
      tpu_pwm_channel_3_output = uVar1;
    }
  }
  if (5 < _DAT_0080d19a) {
    uVar1 = uVar1 & 0xffff0000;
    if ((_DAT_00805670 & 8) == 0) {
      tpu_pwm_channel_4_output = tpu_pwm_channel_4_output & 0xffff0000;
    }
    else {
      uVar1 = ((((uint)_DAT_0080893a * (uint)_DAT_0080d18c) / 0x6400 & 0xffff) * 8000) / 1000 &
              0xffff | ((uint)_DAT_0080893a * 8000) / 1000 << 0x10;
      tpu_pwm_channel_4_output = uVar1;
    }
  }
  uVar1 = CONCAT22((short)(uVar1 >> 0x10),_DAT_00805670) & 0xffff0010;
  if (((_DAT_00805670 & 0x10) == 0) || (_DAT_0080d18e == 0)) {
    _DAT_00fff41a = 0x7fff;
  }
  else if (_DAT_0080d18e < 0x6400) {
    _DAT_00fff414 = -(short)(((uint)_DAT_0080893c * 8000) / 1000) - 1;
    uVar1 = (_DAT_00fff414 & 0x7fff) +
            (((((uint)_DAT_0080893c * (uint)_DAT_0080d18e) / 0x6400 & 0xffff) * 8000) / 1000 &
            0xffff) | 0x7fff0000;
    _DAT_00fff41a = uVar1;
  }
  else {
    uVar1 = ((uint)_DAT_0080893c * 8000) / 1000;
    _DAT_00fff414 = -(short)uVar1 - 1;
    _DAT_00fff41a = 0x7fff8000;
  }
  _DAT_00805670 = _DAT_00805670 | 0x1f;
  return uVar1;
}



//
// Function: hardwareTimerFlagsInit @ 0x000265a4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void hardwareTimerFlagsInit(void)

{
  _DAT_00fff450 = 1;
  _DAT_00fff448 = 1;
  _DAT_00fff420 = 1;
  return;
}



//
// Function: oilPressureRpmFaultMonitor @ 0x000265be
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint oilPressureRpmFaultMonitor(void)

{
  uint in_D0;
  uint uVar1;
  
  if (_DAT_0080d19a < 6) {
    _DAT_0080d19a = _DAT_0080d19a + 1;
    in_D0 = waterInFuelDiagnosticHandler();
  }
  if (_DAT_00808934 != 0) {
    if ((_DAT_00fff450 & 0x8000) == 0) {
      if ((_DAT_0080d186 == 0) || ((_DAT_00805670 & 1) == 0)) {
        if ((_DAT_00fff450 & 0x80) == 0) {
          in_D0 = fault_status_registers_t_00805df2.io_fault_status_4 & 0xffff0010;
          if (((fault_status_registers_t_00805df2.io_fault_status_4 & 0x10) != 0) &&
             (in_D0 = fault_latch_registers_t_00805e32.io_fault_latch_4 & 0xffff0010,
             (fault_latch_registers_t_00805e32.io_fault_latch_4 & 0x10) == 0)) {
            _DAT_0080d190 = 0;
            fault_status_registers_t_00805df2.io_fault_status_4 =
                 fault_status_registers_t_00805df2.io_fault_status_4 & 0xffef;
          }
        }
        else {
          in_D0 = (uint)_DAT_0080d190;
          if (_DAT_0080d190 < _DAT_00808940) {
            _DAT_0080d190 = _DAT_0080d190 + 1;
          }
          else {
            fault_status_registers_t_00805df2.io_fault_status_4 =
                 fault_status_registers_t_00805df2.io_fault_status_4 | 0x10;
            fault_latch_registers_t_00805e32.io_fault_latch_4 =
                 fault_latch_registers_t_00805e32.io_fault_latch_4 | 0x10;
          }
        }
      }
      else if (_DAT_0080d186 < 0x6400) {
        in_D0 = _DAT_00fff428 & 0xffff8000;
        if ((((_DAT_00fff428 & 0x8000) != 0) &&
            (in_D0 = fault_status_registers_t_00805df2.io_fault_status_4 & 0xffff0010,
            (fault_status_registers_t_00805df2.io_fault_status_4 & 0x10) != 0)) &&
           (in_D0 = fault_latch_registers_t_00805e32.io_fault_latch_4 & 0xffff0010,
           (fault_latch_registers_t_00805e32.io_fault_latch_4 & 0x10) == 0)) {
          _DAT_00fff428 = _DAT_00fff428 & 0x7fff;
          _DAT_0080d190 = 0;
          fault_status_registers_t_00805df2.io_fault_status_4 =
               fault_status_registers_t_00805df2.io_fault_status_4 & 0xffef;
        }
      }
      else if ((_DAT_00fff450 & 0x80) == 0) {
        in_D0 = (uint)_DAT_0080d190;
        if (_DAT_0080d190 < _DAT_00808940) {
          _DAT_0080d190 = _DAT_0080d190 + 1;
        }
        else {
          fault_status_registers_t_00805df2.io_fault_status_4 =
               fault_status_registers_t_00805df2.io_fault_status_4 | 0x10;
          fault_latch_registers_t_00805e32.io_fault_latch_4 =
               fault_latch_registers_t_00805e32.io_fault_latch_4 | 0x10;
        }
      }
      else {
        in_D0 = fault_status_registers_t_00805df2.io_fault_status_4 & 0xffff0010;
        if (((fault_status_registers_t_00805df2.io_fault_status_4 & 0x10) != 0) &&
           (in_D0 = fault_latch_registers_t_00805e32.io_fault_latch_4 & 0xffff0010,
           (fault_latch_registers_t_00805e32.io_fault_latch_4 & 0x10) == 0)) {
          _DAT_0080d190 = 0;
          fault_status_registers_t_00805df2.io_fault_status_4 =
               fault_status_registers_t_00805df2.io_fault_status_4 & 0xffef;
        }
      }
    }
    else {
      in_D0 = fault_status_registers_t_00805df2.io_fault_status_4 & 0xffff0010;
      if (((fault_status_registers_t_00805df2.io_fault_status_4 & 0x10) != 0) &&
         (in_D0 = fault_latch_registers_t_00805e32.io_fault_latch_4 & 0xffff0010,
         (fault_latch_registers_t_00805e32.io_fault_latch_4 & 0x10) == 0)) {
        _DAT_00fff450 = _DAT_00fff450 & 0x7fff;
        fault_status_registers_t_00805df2.io_fault_status_4 =
             fault_status_registers_t_00805df2.io_fault_status_4 & 0xffef;
        _DAT_0080d190 = 0;
      }
    }
  }
  if (_DAT_00808936 != 0) {
    if ((_DAT_00fff448 & 0x8000) == 0) {
      if ((_DAT_0080d188 == 0) || ((_DAT_00805670 & 2) == 0)) {
        if ((_DAT_00fff448 & 0x80) == 0) {
          in_D0 = fault_status_registers_t_00805df2.io_fault_status_4 & 0xffff0020;
          if ((fault_status_registers_t_00805df2.io_fault_status_4 & 0x20) != 0) {
            in_D0 = fault_latch_registers_t_00805e32.io_fault_latch_4 & 0xffff0020;
            if ((fault_latch_registers_t_00805e32.io_fault_latch_4 & 0x20) == 0) {
              fault_status_registers_t_00805df2.io_fault_status_4 =
                   fault_status_registers_t_00805df2.io_fault_status_4 & 0xffdf;
              _DAT_0080d192 = 0;
            }
          }
        }
        else {
          in_D0 = (uint)_DAT_0080d192;
          if (_DAT_0080d192 < _DAT_00808942) {
            _DAT_0080d192 = _DAT_0080d192 + 1;
          }
          else {
            fault_status_registers_t_00805df2.io_fault_status_4 =
                 fault_status_registers_t_00805df2.io_fault_status_4 | 0x20;
            fault_latch_registers_t_00805e32.io_fault_latch_4 =
                 fault_latch_registers_t_00805e32.io_fault_latch_4 | 0x20;
          }
        }
      }
      else if (_DAT_0080d188 < 0x6400) {
        in_D0 = _DAT_00fff430 & 0xffff8000;
        if ((((_DAT_00fff430 & 0x8000) != 0) &&
            (in_D0 = fault_status_registers_t_00805df2.io_fault_status_4 & 0xffff0020,
            (fault_status_registers_t_00805df2.io_fault_status_4 & 0x20) != 0)) &&
           (in_D0 = fault_latch_registers_t_00805e32.io_fault_latch_4 & 0xffff0020,
           (fault_latch_registers_t_00805e32.io_fault_latch_4 & 0x20) == 0)) {
          _DAT_00fff430 = _DAT_00fff430 & 0x7fff;
          fault_status_registers_t_00805df2.io_fault_status_4 =
               fault_status_registers_t_00805df2.io_fault_status_4 & 0xffdf;
          _DAT_0080d192 = 0;
        }
      }
      else if ((_DAT_00fff448 & 0x80) == 0) {
        in_D0 = (uint)_DAT_0080d192;
        if (_DAT_00808942 < _DAT_0080d192) {
          fault_status_registers_t_00805df2.io_fault_status_4 =
               fault_status_registers_t_00805df2.io_fault_status_4 | 0x20;
          fault_latch_registers_t_00805e32.io_fault_latch_4 =
               fault_latch_registers_t_00805e32.io_fault_latch_4 | 0x20;
        }
        else {
          _DAT_0080d192 = _DAT_0080d192 + 1;
        }
      }
      else {
        in_D0 = fault_status_registers_t_00805df2.io_fault_status_4 & 0xffff0020;
        if ((fault_status_registers_t_00805df2.io_fault_status_4 & 0x20) != 0) {
          in_D0 = fault_latch_registers_t_00805e32.io_fault_latch_4 & 0xffff0020;
          if ((fault_latch_registers_t_00805e32.io_fault_latch_4 & 0x20) == 0) {
            fault_status_registers_t_00805df2.io_fault_status_4 =
                 fault_status_registers_t_00805df2.io_fault_status_4 & 0xffdf;
            _DAT_0080d192 = 0;
          }
        }
      }
    }
    else {
      in_D0 = fault_status_registers_t_00805df2.io_fault_status_4 & 0xffff0020;
      if (((fault_status_registers_t_00805df2.io_fault_status_4 & 0x20) != 0) &&
         (in_D0 = fault_latch_registers_t_00805e32.io_fault_latch_4 & 0xffff0020,
         (fault_latch_registers_t_00805e32.io_fault_latch_4 & 0x20) == 0)) {
        _DAT_00fff448 = _DAT_00fff448 & 0x7fff;
        fault_status_registers_t_00805df2.io_fault_status_4 =
             fault_status_registers_t_00805df2.io_fault_status_4 & 0xffdf;
        _DAT_0080d192 = 0;
      }
    }
  }
  if (_DAT_0080893c != 0) {
    if ((_DAT_00fff420 & 0x8000) == 0) {
      if ((_DAT_0080d18e == 0) || ((_DAT_00805670 & 0x10) == 0)) {
        if ((_DAT_00fff420 & 0x80) != 0) {
          uVar1 = (uint)_DAT_0080d198;
          if (_DAT_00808948 <= _DAT_0080d198) {
            fault_status_registers_t_00805df2.io_fault_status_4 =
                 fault_status_registers_t_00805df2.io_fault_status_4 | 0x100;
            fault_latch_registers_t_00805e32.io_fault_latch_4 =
                 fault_latch_registers_t_00805e32.io_fault_latch_4 | 0x100;
            return uVar1;
          }
          _DAT_0080d198 = _DAT_0080d198 + 1;
          return uVar1;
        }
        in_D0 = fault_status_registers_t_00805df2.io_fault_status_4 & 0xffff0100;
        if (((fault_status_registers_t_00805df2.io_fault_status_4 & 0x100) != 0) &&
           (in_D0 = fault_latch_registers_t_00805e32.io_fault_latch_4 & 0xffff0100,
           (fault_latch_registers_t_00805e32.io_fault_latch_4 & 0x100) == 0)) {
          _DAT_0080d198 = 0;
          fault_status_registers_t_00805df2.io_fault_status_4 =
               fault_status_registers_t_00805df2.io_fault_status_4 & 0xfeff;
          return in_D0;
        }
      }
      else if (_DAT_0080d18e < 0x6400) {
        in_D0 = _DAT_00fff418 & 0xffff8000;
        if ((((_DAT_00fff418 & 0x8000) != 0) &&
            (in_D0 = fault_status_registers_t_00805df2.io_fault_status_4 & 0xffff0100,
            (fault_status_registers_t_00805df2.io_fault_status_4 & 0x100) != 0)) &&
           (in_D0 = fault_latch_registers_t_00805e32.io_fault_latch_4 & 0xffff0100,
           (fault_latch_registers_t_00805e32.io_fault_latch_4 & 0x100) == 0)) {
          _DAT_00fff418 = _DAT_00fff418 & 0x7fff;
          fault_status_registers_t_00805df2.io_fault_status_4 =
               fault_status_registers_t_00805df2.io_fault_status_4 & 0xfeff;
          _DAT_0080d198 = 0;
          return in_D0;
        }
      }
      else {
        if ((_DAT_00fff420 & 0x80) == 0) {
          uVar1 = (uint)_DAT_0080d198;
          if (_DAT_00808948 <= _DAT_0080d198) {
            fault_status_registers_t_00805df2.io_fault_status_4 =
                 fault_status_registers_t_00805df2.io_fault_status_4 | 0x100;
            fault_latch_registers_t_00805e32.io_fault_latch_4 =
                 fault_latch_registers_t_00805e32.io_fault_latch_4 | 0x100;
            return uVar1;
          }
          _DAT_0080d198 = _DAT_0080d198 + 1;
          return uVar1;
        }
        in_D0 = fault_status_registers_t_00805df2.io_fault_status_4 & 0xffff0100;
        if ((fault_status_registers_t_00805df2.io_fault_status_4 & 0x100) != 0) {
          in_D0 = fault_latch_registers_t_00805e32.io_fault_latch_4 & 0xffff0100;
          if ((fault_latch_registers_t_00805e32.io_fault_latch_4 & 0x100) == 0) {
            fault_status_registers_t_00805df2.io_fault_status_4 =
                 fault_status_registers_t_00805df2.io_fault_status_4 & 0xfeff;
            _DAT_0080d198 = 0;
            return in_D0;
          }
        }
      }
    }
    else {
      in_D0 = fault_status_registers_t_00805df2.io_fault_status_4 & 0xffff0100;
      if (((fault_status_registers_t_00805df2.io_fault_status_4 & 0x100) != 0) &&
         (in_D0 = fault_latch_registers_t_00805e32.io_fault_latch_4 & 0xffff0100,
         (fault_latch_registers_t_00805e32.io_fault_latch_4 & 0x100) == 0)) {
        _DAT_00fff420 = _DAT_00fff420 & 0x7fff;
        fault_status_registers_t_00805df2.io_fault_status_4 =
             fault_status_registers_t_00805df2.io_fault_status_4 & 0xfeff;
        _DAT_0080d198 = 0;
      }
    }
  }
  return in_D0;
}



//
// Function: waterInFuelDiagnosticHandler @ 0x00026aca
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint waterInFuelDiagnosticHandler(void)

{
  uint uVar1;
  dword dVar2;
  
  if (_DAT_0080d19a == 1) {
    uVar1 = 0;
    if ((_DAT_00805670 & 4) == 0) {
      tpu_pwm_channel_3_output = tpu_pwm_channel_3_output & 0xffff0000;
    }
    else {
      uVar1 = ((((uint)_DAT_00808938 * 0x6400) / 0x6400 & 0xffff) * 8000) / 1000 & 0xffff |
              ((uint)_DAT_00808938 * 8000) / 1000 << 0x10;
      tpu_pwm_channel_3_output = uVar1;
    }
    if ((_DAT_00805670 & 8) != 0) {
      tpu_pwm_channel_4_output =
           ((((uint)_DAT_0080893a * 0x6400) / 0x6400 & 0xffff) * 8000) / 1000 & 0xffff |
           ((uint)_DAT_0080893a * 8000) / 1000 << 0x10;
      return tpu_pwm_channel_4_output;
    }
    tpu_pwm_channel_4_output = tpu_pwm_channel_4_output & 0xffff0000;
    return CONCAT22((short)(uVar1 >> 0x10),_DAT_00805670) & 0xffff0008;
  }
  if ((_DAT_0080d19a != 3) && (_DAT_0080d19a != 5)) {
    return (uint)_DAT_0080d19a;
  }
  if ((((_DAT_00fff438 & 0x80) == 0) || ((DAT_00fffa19 & 2) == 0)) &&
     (((_DAT_00fff438 & 0x80) != 0 || ((DAT_00fffa19 & 2) != 0)))) {
    fault_status_registers_t_00805df2.io_fault_status_4 =
         fault_status_registers_t_00805df2.io_fault_status_4 | 0x40;
    fault_latch_registers_t_00805e32.io_fault_latch_4 =
         fault_latch_registers_t_00805e32.io_fault_latch_4 | 0x40;
  }
  else if (((fault_status_registers_t_00805df2.io_fault_status_4 & 0x40) != 0) &&
          ((fault_latch_registers_t_00805e32.io_fault_latch_4 & 0x40) == 0)) {
    fault_status_registers_t_00805df2.io_fault_status_4 =
         fault_status_registers_t_00805df2.io_fault_status_4 & 0xffbf;
  }
  if (((_DAT_00fff440 & 0x80) == 0) || ((DAT_00fffa19 & 4) == 0)) {
    if ((_DAT_00fff440 & 0x80) == 0) {
      if ((DAT_00fffa19 & 4) == 0) goto LAB_00026cc4;
    }
    fault_status_registers_t_00805df2.io_fault_status_4 =
         fault_status_registers_t_00805df2.io_fault_status_4 | 0x80;
    fault_latch_registers_t_00805e32.io_fault_latch_4 =
         fault_latch_registers_t_00805e32.io_fault_latch_4 | 0x80;
  }
  else {
LAB_00026cc4:
    if (((fault_status_registers_t_00805df2.io_fault_status_4 & 0x100) != 0) &&
       ((fault_latch_registers_t_00805e32.io_fault_latch_4 & 0x100) == 0)) {
      fault_status_registers_t_00805df2.io_fault_status_4 =
           fault_status_registers_t_00805df2.io_fault_status_4 & 0xff7f;
    }
  }
  dVar2 = 0;
  if ((_DAT_00805670 & 4) == 0) {
    tpu_pwm_channel_3_output = tpu_pwm_channel_3_output & 0xffff0000;
  }
  else {
    dVar2 = ((uint)_DAT_00808938 * 8000) / 1000 << 0x10;
    tpu_pwm_channel_3_output = dVar2;
  }
  if ((_DAT_00805670 & 8) != 0) {
    tpu_pwm_channel_4_output = ((uint)_DAT_0080893a * 8000) / 1000 << 0x10;
    return tpu_pwm_channel_4_output;
  }
  tpu_pwm_channel_4_output = tpu_pwm_channel_4_output & 0xffff0000;
  return CONCAT22((short)(dVar2 >> 0x10),_DAT_00805670) & 0xffff0008;
}



//
// Function: ioOutputFlagMappingSlowCycle40Coordinator @ 0x00026d98
//

void ioOutputFlagMappingSlowCycle40Coordinator(void)

{
  if ((DAT_0080bdef & 1) == 0) {
    DAT_0080d0c5 = DAT_0080d0c5 | 8;
  }
  else {
    DAT_0080d0c5 = DAT_0080d0c5 & 0xf7;
  }
  if ((DAT_0080bdf1 & 1) == 0) {
    DAT_0080d0c5 = DAT_0080d0c5 | 0x40;
  }
  else {
    DAT_0080d0c5 = DAT_0080d0c5 & 0xbf;
  }
  if ((DAT_0080bdef & 0x80) == 0) {
    DAT_0080d0c5 = DAT_0080d0c5 & 0xef;
  }
  else {
    DAT_0080d0c5 = DAT_0080d0c5 | 0x10;
  }
  if ((DAT_0080bdf3 & 0x20) == 0) {
    DAT_0080d0c5 = DAT_0080d0c5 & 0xdf;
  }
  else {
    DAT_0080d0c5 = DAT_0080d0c5 | 0x20;
  }
  if ((DAT_0080bdee & 1) == 0) {
    DAT_0080d0c4 = DAT_0080d0c4 & 0xef;
  }
  else {
    DAT_0080d0c4 = DAT_0080d0c4 | 0x10;
  }
  if ((DAT_0080bdee & 2) == 0) {
    DAT_0080d0c4 = DAT_0080d0c4 & 0xdf;
  }
  else {
    DAT_0080d0c4 = DAT_0080d0c4 | 0x20;
  }
  if ((DAT_0080bdee & 4) == 0) {
    DAT_0080d0c4 = DAT_0080d0c4 & 0xbf;
  }
  else {
    DAT_0080d0c4 = DAT_0080d0c4 | 0x40;
  }
  if ((DAT_0080bdee & 0x10) != 0) {
    DAT_0080d0c4 = DAT_0080d0c4 | 0x80;
    return;
  }
  DAT_0080d0c4 = DAT_0080d0c4 & 0x7f;
  return;
}



//
// Function: initQADC @ 0x00026e7e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initQADC(void)

{
  byte bVar1;
  byte *pbVar2;
  ushort *puVar3;
  
  _DAT_00fff200 = 0;
  _DAT_00fff206 = 0;
  _DAT_00fff20a = 0x81f7;
  _DAT_00fff20c = 0;
  _DAT_00fff20e = 0x1100;
  bVar1 = 0;
  pbVar2 = &DAT_00026e56;
  puVar3 = (ushort *)&DAT_00fff230;
  do {
    *puVar3 = *pbVar2 & 0x3f | 0xc0;
    bVar1 = bVar1 + 1;
    pbVar2 = pbVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (bVar1 < 0x28);
  return;
}



//
// Function: clearWorkingMemory @ 0x00026ec4
//

void clearWorkingMemory(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)&DAT_00800000;
  while (puVar2 < (undefined4 *)0x80d5ca) {
    puVar1 = puVar2 + 0x40;
    if ((undefined4 *)0x80d5ca < puVar1) {
      puVar1 = (undefined4 *)0x80d5ca;
    }
    for (; puVar2 <= puVar1; puVar2 = puVar2 + 1) {
      *puVar2 = 0;
    }
    DAT_00fffa27 = 0xaa;
    DAT_00ffd00f = 0xaa;
  }
  return;
}



//
// Function: canMemoryPointerTableInit @ 0x00026f10
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void canMemoryPointerTableInit(void)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  int *piVar4;
  int *piVar5;
  
  _DAT_008018ae = &DAT_008062d2;
  _DAT_008018b2 = 0x808ab2;
  _DAT_008018b6 = &firmware_data_source;
  _DAT_008018ba = 0x8062cc;
  _DAT_008018be = 0x8062ce;
  if (_DAT_0080d1a0 == 2) {
    _DAT_008018c2 = &DAT_00007e3e;
  }
  else {
    _DAT_008018c2 = &DAT_00005e3e;
  }
  uVar3 = 0;
  piVar5 = (int *)&DAT_008018b2;
  for (piVar4 = (int *)&DAT_008018ae; piVar4 < &DAT_008018c6; piVar4 = piVar4 + 3) {
    iVar1 = *piVar4;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 1;
    }
    iVar2 = *piVar5;
    if (iVar2 < 0) {
      iVar2 = iVar2 + 1;
    }
    uVar3 = ((short)(iVar2 >> 1) - (short)(iVar1 >> 1)) + uVar3;
    piVar5 = piVar5 + 3;
  }
  _DAT_008018d4 = uVar3 / 0x14 + 1;
  _DAT_008018c6 = &DAT_008018ae;
  _DAT_008018ce = &DAT_008062d2;
  _DAT_008018ca = &firmware_data_source;
  _DAT_008018d2 = 0;
  _DAT_0080d19c = 1;
  _DAT_0080d19e = 1;
  _DAT_008018d6 = 1;
  return;
}



//
// Function: canMessageMemorySyncController @ 0x00026ff4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void canMessageMemorySyncController(void)

{
  undefined4 *puVar1;
  short *psVar2;
  
  if ((_DAT_008018d6 == 0) && (_DAT_0080d19c != 0)) {
    canMemoryPointerTableInit();
  }
  if (_DAT_0080d1a0 == 0) {
    _DAT_0080d19c = 0;
  }
  if (_DAT_0080d19c != 0) {
    if (((short *)_DAT_008018c6[1] <= _DAT_008018ce) ||
       ((_DAT_008018c6 == (undefined4 *)&DAT_008018ba && (_DAT_0080d19e == 0)))) {
      puVar1 = _DAT_008018c6 + 3;
      if ((puVar1 == (undefined4 *)&DAT_008018ba) && (_DAT_0080d19e == 0)) {
        puVar1 = _DAT_008018c6 + 6;
      }
      _DAT_008018c6 = puVar1;
      if ((undefined4 *)0x8018c5 < _DAT_008018c6) {
        _DAT_008018c6 = (undefined4 *)&DAT_008018ae;
        if (_DAT_008018d2 == 0) {
          if (((fault_status_registers_t_00805df2.sensor_fault_status & 2) != 0) &&
             ((fault_latch_registers_t_00805e32.sensor_fault_latch & 2) == 0)) {
            fault_status_registers_t_00805df2.sensor_fault_status =
                 fault_status_registers_t_00805df2.sensor_fault_status & 0xfffd;
          }
        }
        else {
          fault_status_registers_t_00805df2.sensor_fault_status =
               fault_status_registers_t_00805df2.sensor_fault_status | 2;
          fault_latch_registers_t_00805e32.sensor_fault_latch =
               fault_latch_registers_t_00805e32.sensor_fault_latch | 2;
        }
        _DAT_008018d2 = 0;
      }
      _DAT_008018ce = (short *)*_DAT_008018c6;
      _DAT_008018ca = (short *)_DAT_008018c6[2];
    }
    psVar2 = _DAT_008018ce + _DAT_008018d4;
    if ((short *)_DAT_008018c6[1] < psVar2) {
      psVar2 = (short *)_DAT_008018c6[1];
    }
    for (; _DAT_008018ce < psVar2; _DAT_008018ce = _DAT_008018ce + 1) {
      if (*_DAT_008018ce != *_DAT_008018ca) {
        *_DAT_008018ce = *_DAT_008018ca;
        _DAT_008018d2 = 1;
      }
      _DAT_008018ca = _DAT_008018ca + 1;
    }
  }
  _DAT_008018d6 = _DAT_0080d19c;
  return;
}



//
// Function: insiteParameterParser @ 0x00027168
//

char insiteParameterParser(void)

{
  char cVar1;
  
  if (insite_session_t_0080d407.command_byte < 0x80) {
    cVar1 = '\x02';
  }
  else if (insite_session_t_0080d407.command_byte < 0xc0) {
    cVar1 = '\x03';
  }
  else if (insite_session_t_0080d407.command_byte < 0xfe) {
    if (*(byte *)insite_session_t_0080d407._13_4_ < 0x13) {
      cVar1 = *(byte *)insite_session_t_0080d407._13_4_ + 2;
    }
    else {
      cVar1 = '\x14';
    }
  }
  else {
    cVar1 = '\0';
  }
  return cVar1;
}



//
// Function: parameterLookupForInsite @ 0x000271b0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 parameterLookupForInsite(void)

{
  short sVar1;
  
  if (insite_session_t_0080d407.command_byte < 0x80) {
    return 2;
  }
  if (insite_session_t_0080d407.command_byte < 0xc0) {
    return 3;
  }
  if (insite_session_t_0080d407.command_byte == 0xc1) {
    return CONCAT11((char)((ushort)_DAT_00804f44 >> 8),(char)_DAT_00804f44 + '\x02');
  }
  if (insite_session_t_0080d407.command_byte == 0xc2) {
    if (insite_session_t_0080d407.response_ptr._0_1_ == '\0') {
      return CONCAT11((char)((ushort)_DAT_00804f40 >> 8),(char)_DAT_00804f40 * '\x02' + '\x02');
    }
    sVar1 = (_DAT_00804f42 + _DAT_00804f40) * 3;
    return CONCAT11((char)((ushort)sVar1 >> 8),(char)sVar1 + '\x02');
  }
  if (insite_session_t_0080d407.command_byte == 0xc4) {
    if ((DAT_0080d448 & 0xc0) != 0) {
      return 4;
    }
    if (_DAT_0080d490 == 0) {
      return 2;
    }
    return 7;
  }
  if (insite_session_t_0080d407.command_byte == 0xea) {
    return 0x18;
  }
  if (insite_session_t_0080d407.command_byte != 0xed) {
    if (insite_session_t_0080d407.command_byte != 0xf3) {
      return 6;
    }
    return 0x1f;
  }
  return 0x16;
}



//
// Function: coreSystemFunction @ 0x0002725a
// ERROR: Failed to decompile
//

//
// Function: diagnosticServiceDispatcher @ 0x0002729a
//

void diagnosticServiceDispatcher(byte *param_1)

{
  undefined4 in_D0;
  undefined4 unaff_D2;
  byte bVar1;
  char cVar2;
  char *pcVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((uint)unaff_D2 >> 0x10);
  pcVar3 = &DAT_008018d8;
  cVar2 = '\x18';
  bVar1 = 0;
  do {
    if (DAT_00801998 <= bVar1) {
LAB_000272e6:
      if (cVar2 != -1) {
        FUN_000298d8(param_1,CONCAT22((short)CONCAT31((int3)((uint)in_D0 >> 8),cVar2),uVar4));
      }
      return;
    }
    in_D0 = CONCAT31((int3)((uint)in_D0 >> 8),*pcVar3);
    if (*pcVar3 == **(char **)(param_1 + 6)) {
      in_D0 = diagnosticServiceSecurityValidator((int)param_1);
      cVar2 = (char)in_D0;
      if (cVar2 == -1) {
        in_D0 = (**(code **)(pcVar3 + 2))((short)param_1);
        cVar2 = (char)in_D0;
      }
      goto LAB_000272e6;
    }
    pcVar3 = pcVar3 + 6;
    bVar1 = bVar1 + 1;
  } while( true );
}



//
// Function: systemControlFunction1 @ 0x00027300
//

void systemControlFunction1(void)

{
  coreSystemControlFunction();
  return;
}



//
// Function: diagnosticResponseHandler2 @ 0x00027314
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticResponseHandler2(int param_1)

{
  ushort in_stack_00000000;
  
  _DAT_0080d48c = 2;
  FUN_00029476(param_1,(uint)in_stack_00000000);
  return;
}



//
// Function: canTransmissionTrigger @ 0x0002732e
//

void canTransmissionTrigger(void)

{
  canTransmissionController();
  return;
}



//
// Function: diagnosticServiceByteHandler @ 0x00027342
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticServiceByteHandler(int param_1)

{
  undefined2 in_D0w;
  undefined4 unaff_A2;
  undefined2 uVar1;
  
  uVar1 = (undefined2)((uint)unaff_A2 >> 0x10);
  DAT_0080199a = **(char **)(param_1 + 6);
  FUN_0002a1f6(CONCAT22(CONCAT11((char)((ushort)in_D0w >> 8),DAT_0080199a),0x32));
  if ((DAT_0080199a == '\0') && ((_DAT_008084ca & 0x100) != 0)) {
    FUN_0002a1f6(CONCAT22(_DAT_008084ca & 0x100,0x32));
    return;
  }
  if ((DAT_0080199a == '\x01') && ((_DAT_008084ca & 0x200) != 0)) {
    FUN_0002a1f6(CONCAT22(CONCAT11((char)((_DAT_008084ca & 0x200) >> 8),1),0x32));
    return;
  }
  FUN_00029476(param_1,CONCAT22(1,uVar1));
  return;
}



//
// Function: systemControlFunction2 @ 0x000273c0
//

void systemControlFunction2(void)

{
  coreSystemControlFunction();
  return;
}



//
// Function: fuelArbitratorMessageHandler @ 0x000273d4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelArbitratorMessageHandler(int param_1)

{
  if (((*(byte *)(param_1 + 3) == _DAT_008084a4) || (_DAT_008084a4 == 0xff)) &&
     (*(short *)(param_1 + 4) == 8)) {
    DAT_008019a2 = **(byte **)(param_1 + 6);
    DAT_008019a6 = *(byte *)(*(int *)(param_1 + 6) + 4);
    if (_DAT_0080d03c == 0) {
      if ((DAT_008019a6 & 3) == 1) {
        if ((fuel_arbitrator_diag_t_0080cff8.rpm_target == 1) &&
           (fuel_arbitrator_diag_t_0080cff8.fuel_mode == 1)) {
          fuel_arbitrator_diag_t_0080cff8.speed_limit = 1;
          _DAT_0080d02e = _DAT_008086e4 + 1;
        }
      }
      else if ((DAT_008019a6 & 3) != 3) {
        fuel_arbitrator_diag_t_0080cff8.speed_limit = 0;
        _DAT_0080d02e = 0;
        _DAT_0080d030 = 0;
      }
    }
    if ((DAT_008019a6 & 0xc) == 4) {
      fuel_arbitrator_diag_t_0080cff8.session_counter = 1;
      _DAT_0080d034 = _DAT_008086ee + 1;
    }
    else if ((DAT_008019a6 & 0xc) != 0xc) {
      fuel_arbitrator_diag_t_0080cff8.session_counter = 0;
      _DAT_0080d034 = 0;
    }
    if (((DAT_008019a2 & 0x30) == 0x10) || ((DAT_008019a2 & 3) == 1)) {
      fuel_arbitrator_diag_t_0080cff8.fuel_limit = 0;
      _DAT_0080d032 = 0;
      return;
    }
    fuel_arbitrator_diag_t_0080cff8.fuel_limit = 1;
    _DAT_0080d032 = _DAT_008086ec + 1;
    fuel_arbitrator_diag_t_0080cff8._30_2_ = 1;
  }
  return;
}



//
// Function: systemControlFunction3 @ 0x00027514
//

void systemControlFunction3(void)

{
  coreSystemControlFunction();
  return;
}



//
// Function: torqueControlModeHandler @ 0x00027528
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void torqueControlModeHandler(int param_1)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  undefined3 uVar5;
  undefined4 in_D0;
  uint uVar6;
  undefined4 uVar7;
  undefined4 unaff_D2;
  undefined2 uVar8;
  
  uVar8 = (undefined2)((uint)unaff_D2 >> 0x10);
  if (*(short *)(param_1 + 4) == 8) {
    DAT_008019aa = **(byte **)(param_1 + 6);
    bVar4 = DAT_008019aa & 3;
    bVar3 = DAT_008019aa & 3;
    bVar2 = DAT_008019aa & 0x30;
    DAT_008019ac = *(undefined1 *)(*(int *)(param_1 + 6) + 1);
    DAT_008019ab = *(undefined1 *)(*(int *)(param_1 + 6) + 2);
    DAT_008019ad = *(byte *)(*(int *)(param_1 + 6) + 3);
    cVar1 = *(char *)(param_1 + 3);
    uVar5 = (undefined3)((uint)in_D0 >> 8);
    if ((DAT_008019aa & 3) == 0) {
      uVar6 = diagnosticStateInitializer(CONCAT22(1,(short)CONCAT31(uVar5,cVar1)));
    }
    else {
      uVar6 = diagnosticMessageValidator
                        (CONCAT22(1,(short)CONCAT31(uVar5,cVar1)),
                         CONCAT12(DAT_008019aa,uVar8) & 0x3ffff);
      if ((short)uVar6 != 0) {
        return;
      }
    }
    uVar5 = (undefined3)(uVar6 >> 8);
    if (fuel_arbitrator_diag_t_0080cff8.rpm_target == 0) {
      uVar6 = diagnosticSessionValidator(CONCAT22(1,(short)CONCAT31(uVar5,cVar1)));
      if ((short)uVar6 != 0) {
        return;
      }
      _DAT_0080d01e = _DAT_0080d01a;
    }
    else if (fuel_arbitrator_diag_t_0080cff8._28_2_ == 1) {
      if (cVar1 != (char)fuel_arbitrator_diag_t_0080cff8.limited_value) {
        if (bVar4 == 0) {
          return;
        }
        uVar6 = diagnosticSessionValidator(CONCAT22(1,(short)CONCAT31(uVar5,cVar1)));
        if ((short)uVar6 != 0) {
          return;
        }
        if (DAT_008019b2 < bVar2) {
          return;
        }
        if (bVar2 == DAT_008019b2) {
          if (fuel_arbitrator_diag_t_0080cff8.rpm_target != 3) {
            return;
          }
          if (bVar3 == 3) {
            if (DAT_008019b6 < DAT_008019ad) {
              return;
            }
            if ((DAT_008019b6 == DAT_008019ad) &&
               (_DAT_008019b4 <= CONCAT11(DAT_008019ab,DAT_008019ac))) {
              return;
            }
          }
        }
        _DAT_0080d01e = _DAT_0080d01a;
      }
    }
    else {
      uVar6 = diagnosticSessionValidator(CONCAT22(1,(short)CONCAT31(uVar5,cVar1)));
      if ((short)uVar6 != 0) {
        return;
      }
      if (_DAT_0080d01e < _DAT_0080d01a) {
        return;
      }
      _DAT_0080d01e = _DAT_0080d01a;
    }
    fuel_arbitrator_diag_t_0080cff8.control_flags = (word)DAT_008019aa;
    DAT_008019b2 = bVar2;
    fuel_arbitrator_diag_t_0080cff8._28_2_ = 1;
    fuel_arbitrator_diag_t_0080cff8.limited_value._1_1_ = cVar1;
    switch(bVar3) {
    case 0:
      _DAT_0080d028 = 0;
      fuel_arbitrator_diag_t_0080cff8.rpm_target = 0;
      fuel_arbitrator_diag_t_0080cff8.fuel_mode = 0;
      fuel_arbitrator_diag_t_0080cff8._20_2_ = 0;
      return;
    case 1:
      _DAT_0080d028 = *(short *)(_DAT_0080d01e + 4) + 1;
      fuel_arbitrator_diag_t_0080cff8.rpm_target = 1;
      uVar7 = canBusConfigTypeSelector
                        (CONCAT22(CONCAT11((char)((ushort)_DAT_0080d028 >> 8),
                                           *(undefined1 *)(param_1 + 3)),uVar8));
      fuel_arbitrator_diag_t_0080cff8.fuel_mode = (word)uVar7;
      fuel_arbitrator_diag_t_0080cff8._20_2_ = 1;
      fuel_arbitrator_diag_t_0080cff8.state_pointer._1_2_ = CONCAT11(DAT_008019ab,DAT_008019ac);
      _DAT_008019b4 = fuel_arbitrator_diag_t_0080cff8.state_pointer._1_2_;
      if (24000 < fuel_arbitrator_diag_t_0080cff8.state_pointer._1_2_) {
        fuel_arbitrator_diag_t_0080cff8.state_pointer._1_2_ = 24000;
      }
      fuel_arbitrator_diag_t_0080cff8._26_2_ = (short)((int)(DAT_008019aa & 0xc) >> 2);
      return;
    case 2:
      _DAT_0080d028 = *(short *)(_DAT_0080d01e + 8) + 1;
      fuel_arbitrator_diag_t_0080cff8.rpm_target = 2;
      uVar7 = canBusConfigTypeSelector
                        (CONCAT22(CONCAT11((char)((ushort)_DAT_0080d028 >> 8),
                                           *(undefined1 *)(param_1 + 3)),uVar8));
      fuel_arbitrator_diag_t_0080cff8.fuel_mode = (word)uVar7;
      fuel_arbitrator_diag_t_0080cff8._20_2_ = 0;
      DAT_008019b6 = DAT_008019ad;
      fuel_arbitrator_diag_t_0080cff8._16_2_ = (ushort)DAT_008019ad * 0x100 + -32000;
      fuel_arbitrator_diag_t_0080cff8._24_2_ =
           reference_table_t_008086f6.base_reference +
           (short)(((int)(short)fuel_arbitrator_diag_t_0080cff8._16_2_ *
                   ((int)_DAT_008086c2 - (int)(short)reference_table_t_008086f6.base_reference)) /
                  0x6400);
      if ((short)fuel_arbitrator_diag_t_0080cff8._24_2_ < 0) {
        fuel_arbitrator_diag_t_0080cff8._24_2_ = 0;
        return;
      }
      return;
    case 3:
      _DAT_0080d028 = *(short *)(_DAT_0080d01e + 0xc) + 1;
      fuel_arbitrator_diag_t_0080cff8.rpm_target = 3;
      uVar7 = canBusConfigTypeSelector
                        (CONCAT22(CONCAT11((char)((ushort)_DAT_0080d028 >> 8),
                                           *(undefined1 *)(param_1 + 3)),uVar8));
      fuel_arbitrator_diag_t_0080cff8.fuel_mode = (word)uVar7;
      fuel_arbitrator_diag_t_0080cff8._20_2_ = 0;
      _DAT_008019b4 = CONCAT11(DAT_008019ab,DAT_008019ac);
      fuel_arbitrator_diag_t_0080cff8.command_counter = _DAT_008019b4;
      DAT_008019b6 = DAT_008019ad;
      fuel_arbitrator_diag_t_0080cff8.prev_state_pointer._1_2_ =
           reference_table_t_008086f6.base_reference +
           (short)(((int)(short)((ushort)DAT_008019ad * 0x100 + -32000) *
                   ((int)_DAT_008086c2 - (int)(short)reference_table_t_008086f6.base_reference)) /
                  0x6400);
      if (fuel_arbitrator_diag_t_0080cff8.prev_state_pointer._1_2_ < 0) {
        fuel_arbitrator_diag_t_0080cff8.prev_state_pointer._1_2_ = 0;
        return;
      }
    }
  }
  return;
}



//
// Function: canTransmissionController @ 0x0002787e
// ERROR: Failed to decompile
//

//
// Function: diagnosticServiceDispatcherByPgn @ 0x000278be
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticServiceDispatcherByPgn(int param_1)

{
  undefined4 unaff_D2;
  byte bVar1;
  char *pcVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((uint)unaff_D2 >> 0x10);
  pcVar2 = &DAT_008019b8;
  if ((*(byte *)(param_1 + 2) == _DAT_0080cfc2) || (*(char *)(param_1 + 2) == -1)) {
    for (bVar1 = 0; bVar1 < DAT_00801a36; bVar1 = bVar1 + 1) {
      if ((pcVar2[1] == **(char **)(param_1 + 6)) &&
         (*(char *)(*(int *)(param_1 + 6) + 1) == *pcVar2)) {
        (**(code **)(pcVar2 + 2))((short)param_1);
        break;
      }
      pcVar2 = pcVar2 + 6;
    }
    if ((bVar1 == DAT_00801a36) && (*(char *)(param_1 + 2) != -1)) {
      FUN_00029476(param_1,CONCAT22(1,uVar3));
    }
  }
  return;
}



//
// Function: diagnosticDataDump @ 0x0002793e
//

void diagnosticDataDump(void)

{
  coreSystemControlFunction();
  engineSerialNumberPGN_65259_Builder();
  engineTemperaturePGN_65262_Builder();
  intakeExhaustConditionsPGN_65257_Builder();
  ioControlPGN_65244_Builder();
  vehicleDistancePGN_65248_Builder();
  vehicleHoursPGN_65255_Builder();
  canTransmissionController();
  canTransmissionController();
  canTransmissionController();
  canTransmissionController();
  canTransmissionController();
  canTransmissionController();
  engineCoolantPGN_65226_Builder();
  diagnosticDM2PGN_65227_Builder();
  canTransmissionTrigger();
  diagnosticDM4PGN_65229_Builder();
  diagnosticDM5PGN_65230_Builder();
  diagnosticDM11PGN_65234_Builder();
  return;
}



//
// Function: retarderModeThresholdCalculator @ 0x000279ee
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint retarderModeThresholdCalculator(undefined4 param_1)

{
  uint in_D0;
  ushort uVar2;
  ushort uVar3;
  uint uVar1;
  
  if (param_1._0_2_ == 0) {
    return in_D0 & 0xffffff00;
  }
  if (_DAT_008037d4 != 1) {
    _DAT_00801a60 = circular_buffer_t_0080c3fc.data_buffer_8;
    uVar3 = lookupTableInterpolation((short *)&DAT_00801a5a);
    uVar1 = ((uint)param_1._0_2_ * (uint)_DAT_00807996) / 0x6400;
    if (uVar3 < (ushort)uVar1) {
      if (_DAT_008037d4 == 3) {
        return 1;
      }
      return 3;
    }
    if (_DAT_008037d4 == 3) {
      return uVar1 & 0xffffff00;
    }
    return 1;
  }
  _DAT_00801a48 = circular_buffer_t_0080c3fc.data_buffer_8;
  uVar2 = lookupTableInterpolation((short *)&DAT_00801a42);
  uVar3 = (ushort)(((uint)param_1._0_2_ * (uint)_DAT_00807978) / 0x6400);
  if (uVar3 < uVar2) {
    return 1;
  }
  _DAT_00801a54 = circular_buffer_t_0080c3fc.data_buffer_8;
  uVar2 = lookupTableInterpolation((short *)&DAT_00801a4e);
  if (uVar3 < uVar2) {
    return 2;
  }
  return 3;
}



//
// Function: retarderPercentageScaler @ 0x00027aca
//

short retarderPercentageScaler(undefined4 param_1)

{
  byte bVar1;
  
  bVar1 = (byte)((uint)param_1 >> 0x10);
  if (bVar1 < 0x19) {
    return 0x6400;
  }
  if (0x7c < bVar1) {
    return 0;
  }
  return (0x7d - (param_1._0_2_ & 0xff)) * 0x100;
}



//
// Function: retarderControlModeHandler @ 0x00027afa
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void retarderControlModeHandler(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  ushort uVar6;
  undefined4 uVar5;
  undefined2 uVar7;
  short sVar8;
  undefined4 unaff_D2;
  bool bVar9;
  undefined2 uVar10;
  
  uVar7 = (undefined2)((uint)unaff_D2 >> 0x10);
  if ((_DAT_008037d4 != 0) && (*(short *)(param_1 + 4) == 8)) {
    DAT_00801a3a = **(byte **)(param_1 + 6);
    bVar3 = DAT_00801a3a & 3;
    if (bVar3 != 1) {
      bVar2 = DAT_00801a3a & 0x30;
      DAT_00801a3d = *(byte *)(*(int *)(param_1 + 6) + 3);
      bVar1 = *(byte *)(param_1 + 3);
      if (bVar3 == 0) {
        uVar4 = ioControlEntryRemove((uint)CONCAT12(bVar1,uVar7));
      }
      else {
        uVar4 = ioControlTimeoutTableLookup((uint)CONCAT12(bVar1,uVar7));
        if ((short)uVar4 != 0) {
          return;
        }
      }
      if (_DAT_0080cfa8 == 0) {
        uVar4 = diagnosticSessionValidator(CONCAT22(1,(short)CONCAT31((int3)(uVar4 >> 8),bVar1)));
        if ((short)uVar4 != 0) {
          return;
        }
        _DAT_0080d022 = _DAT_0080d01a;
      }
      else if (bVar1 != _DAT_0080cfac) {
        if (bVar3 == 0) {
          return;
        }
        uVar4 = diagnosticSessionValidator(CONCAT22(1,(ushort)bVar1));
        if ((short)uVar4 != 0) {
          return;
        }
        if (DAT_00801a38 < bVar2) {
          return;
        }
        if (bVar2 == DAT_00801a38) {
          if (_DAT_0080cfa8 == 2) {
            return;
          }
          if ((bVar3 == 3) && (DAT_00801a3d <= DAT_00801a39)) {
            return;
          }
        }
        _DAT_0080d022 = _DAT_0080d01a;
      }
      DAT_00801a38 = bVar2;
      DAT_00801a39 = DAT_00801a3d;
      _DAT_0080cfac = (ushort)bVar1;
      _DAT_0080cfae = (ushort)DAT_00801a3a;
      if (bVar3 == 0) {
        _DAT_0080d02c = 0;
        _DAT_0080cfa8 = 0;
        _DAT_0080cfaa = 0;
        _DAT_0080cfb0 = 0;
        _DAT_0080cfb2 = 3;
        fuel_arbitrator_diag_t_0080cff8.throttle_mode = 0;
        return;
      }
      if (bVar3 == 2) {
        sVar8 = retarderPercentageScaler((uint)CONCAT12(DAT_00801a3d,uVar7));
        _DAT_0080cfb4 = sVar8;
        if (((((engine_control_flags_t_008035d6.protection_system & 0x1000) == 0) ||
             (bVar1 != _DAT_008084a4)) || (fuel_arbitrator_diag_t_0080cff8.rpm_target != 1)) ||
           (((fuel_arbitrator_diag_t_0080cff8.fuel_mode != 1 || (_DAT_0080d49a < _DAT_0080894c)) ||
            (sVar8 == 0)))) {
          _DAT_0080d02c = *(short *)(_DAT_0080d022 + 0xe) + 1;
          _DAT_0080cfa8 = 2;
          uVar10 = CONCAT11((char)((ushort)_DAT_0080d02c >> 8),*(undefined1 *)(param_1 + 3));
          uVar5 = canBusConfigTypeSelector(CONCAT22(uVar10,uVar7));
          _DAT_0080cfaa = (undefined2)uVar5;
          _DAT_0080cfb2 = 3;
          uVar4 = retarderModeThresholdCalculator(CONCAT22(sVar8,uVar10));
          _DAT_0080cfb0 = (ushort)uVar4 & 0xff;
          if ((uVar4 & 0xff) == 0) {
            fuel_arbitrator_diag_t_0080cff8.throttle_mode = 1;
            _DAT_0080d036 = *(short *)(_DAT_0080d022 + 0xe) + 1;
          }
          else {
            fuel_arbitrator_diag_t_0080cff8.throttle_mode = 0;
            _DAT_0080d036 = 0;
          }
        }
        else {
          _DAT_0080d02c = 0;
          _DAT_0080cfa8 = 0;
          _DAT_0080cfaa = 0;
          _DAT_0080cfb0 = 0;
          _DAT_0080cfb2 = 3;
          fuel_arbitrator_diag_t_0080cff8.throttle_mode = 0;
          _DAT_0080d036 = 0;
        }
        _DAT_0080d038 = 0;
        return;
      }
      if (bVar3 != 3) {
        return;
      }
      _DAT_0080cfa8 = 3;
      uVar6 = (ushort)*(byte *)(param_1 + 3);
      uVar5 = canBusConfigTypeSelector((uint)CONCAT12(*(byte *)(param_1 + 3),uVar7));
      _DAT_0080cfaa = (undefined2)uVar5;
      _DAT_0080cfb0 = 0;
      uVar7 = (undefined2)CONCAT31((int3)((uint)uVar5 >> 8),DAT_00801a3d);
      sVar8 = retarderPercentageScaler(CONCAT22(uVar7,uVar6));
      _DAT_0080d02c = *(short *)(_DAT_0080d022 + 0x12) + 1;
      uVar4 = retarderModeThresholdCalculator(CONCAT22(sVar8,uVar7));
      _DAT_0080cfb2 = (ushort)uVar4 & 0xff;
      bVar9 = (uVar4 & 0xff) != 0;
      if (bVar9) {
        _DAT_0080d036 = 0;
      }
      else {
        _DAT_0080d036 = *(short *)(_DAT_0080d022 + 0x12) + 1;
      }
      fuel_arbitrator_diag_t_0080cff8.throttle_mode = (word)!bVar9;
      _DAT_0080d038 = 0;
    }
  }
  return;
}



//
// Function: retarderModeThresholdsSetup @ 0x00027dd4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void retarderModeThresholdsSetup(void)

{
  _DAT_0080cfb2 = 3;
  _DAT_00801a44 = 0x807952;
  _DAT_00801a4a = 0x807998;
  _DAT_00801a42 = 2;
  _DAT_00801a50 = 0x807952;
  _DAT_00801a56 = 0x8079a2;
  _DAT_00801a4e = 2;
  _DAT_00801a5c = 0x80797a;
  _DAT_00801a62 = 0x8079ac;
  _DAT_00801a5a = 2;
  return;
}



//
// Function: torqueControlAddressDispatcher @ 0x00027e3e
//

void torqueControlAddressDispatcher(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 2);
  if ((cVar1 != DAT_0080cfc3) && (cVar1 != -1)) {
    if ((cVar1 == DAT_0080cfcd) || (cVar1 == -1)) {
      retarderControlModeHandler(param_1);
    }
    return;
  }
  torqueControlModeHandler(param_1);
  return;
}



//
// Function: systemControlFunction4 @ 0x00027e86
//

void systemControlFunction4(void)

{
  coreSystemControlFunction();
  return;
}



//
// Function: systemSecurityCheck @ 0x00027e98
//

undefined1 systemSecurityCheck(void)

{
  return 0;
}



//
// Function: diagnosticTableEntryRemover @ 0x00027e9c
//

void diagnosticTableEntryRemover(undefined4 param_1)

{
  bool bVar1;
  short sVar2;
  short unaff_D3w;
  
  bVar1 = false;
  sVar2 = unaff_D3w * 0x30;
  while ((unaff_D3w < 0x14 && (!bVar1))) {
    if (param_1._0_2_ == *(short *)(&DAT_00805676 + sVar2)) {
      *(undefined2 *)(&DAT_00805676 + sVar2) = 0x7d;
      *(undefined2 *)(&DAT_00805a36 + sVar2) = 0x7d;
      bVar1 = true;
    }
    sVar2 = sVar2 + 0x30;
    unaff_D3w = unaff_D3w + 1;
  }
  return;
}



//
// Function: diagnosticTableEntryClear @ 0x00027ef0
//

void diagnosticTableEntryClear(undefined4 param_1)

{
  short sVar1;
  undefined4 unaff_D2;
  
  sVar1 = param_1._0_2_ * 10;
  (&DAT_00804fcd)[sVar1] = 0;
  *(undefined4 *)(sVar1 + 0x804fc4) = 0;
  *(undefined4 *)(sVar1 + 0x804fc8) = 0;
  if (*(char *)(sVar1 + 0x804fcc) == '\x02') {
    diagnosticTableEntryRemover(CONCAT22(param_1._0_2_,(short)((uint)unaff_D2 >> 0x10)));
  }
  *(undefined1 *)(sVar1 + 0x804fcc) = 0;
  return;
}



//
// Function: diagnosticTableSnapshotCapture @ 0x00027f4c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticTableSnapshotCapture(undefined4 param_1)

{
  short sVar1;
  
  if ((*(ushort *)(&DAT_008065ce + (short)(param_1._2_2_ * 3) * 2) & 0x10) != 0) {
    sVar1 = param_1._0_2_ * 0x30;
    *(short *)(&DAT_00805a36 + sVar1) = param_1._2_2_;
    *(undefined2 *)(&DAT_00805a3e + sVar1) = _DAT_0080d0c6;
    *(undefined2 *)(&DAT_00805a38 + sVar1) = _DAT_008096a6;
    *(word *)(sVar1 + 0x805a3a) = circular_buffer_t_0080c3fc.current_engine_rpm;
    *(undefined2 *)(sVar1 + 0x805a40) = _DAT_00809d4c;
    *(undefined2 *)(&DAT_00805a42 + sVar1) = _DAT_00809258;
    *(undefined4 *)(sVar1 + 0x805a32) = _DAT_0080d4c4;
    *(undefined2 *)(&DAT_00805a44 + sVar1) = _DAT_0080926e;
    *(undefined2 *)(sVar1 + 0x805a46) = _DAT_008091ea;
    *(undefined2 *)(sVar1 + 0x805a48) = _DAT_00809242;
    *(undefined2 *)(sVar1 + 0x805a3c) = _DAT_0080bdc0;
    *(undefined2 *)(sVar1 + 0x805a4a) = _DAT_0080bdc2;
    *(undefined4 *)(sVar1 + 0x805a4c) = _DAT_00809688;
    *(undefined2 *)(sVar1 + 0x805a50) = fuel_demand_state_t_0080c9a4._2_2_;
    *(undefined2 *)(sVar1 + 0x805a52) = _DAT_00809308;
    *(word *)(sVar1 + 0x805a54) = fuel_demand_state_t_0080c9a4.command;
    *(undefined2 *)(sVar1 + 0x805a56) = _DAT_0080d482;
    *(undefined2 *)(sVar1 + 0x805a58) = _DAT_00809a5e;
    *(undefined2 *)(sVar1 + 0x805a5a) = _DAT_00809a58;
    *(undefined2 *)(sVar1 + 0x805a5c) = _DAT_0080938c;
    *(undefined2 *)(sVar1 + 0x805a5e) = _DAT_00809a4e;
    *(undefined2 *)(sVar1 + 0x805a60) = _DAT_0080bdc4;
  }
  sVar1 = param_1._0_2_ * 0x30;
  if (param_1._2_2_ != *(short *)(&DAT_00805676 + sVar1)) {
    *(short *)(&DAT_00805676 + sVar1) = param_1._2_2_;
    *(undefined2 *)(sVar1 + 0x80567e) = _DAT_0080d0c6;
    *(undefined2 *)(sVar1 + 0x805678) = _DAT_008096a6;
    *(word *)(sVar1 + 0x80567a) = circular_buffer_t_0080c3fc.current_engine_rpm;
    *(undefined2 *)(sVar1 + 0x805680) = _DAT_00809d4c;
    *(undefined2 *)(sVar1 + 0x805682) = _DAT_00809258;
    *(undefined4 *)(sVar1 + 0x805672) = _DAT_0080d4c4;
    *(undefined2 *)(sVar1 + 0x805684) = _DAT_0080926e;
    *(undefined2 *)(sVar1 + 0x805686) = _DAT_008091ea;
    *(undefined2 *)(sVar1 + 0x805688) = _DAT_00809242;
    *(undefined2 *)(sVar1 + 0x80567c) = _DAT_0080bdc0;
    *(undefined2 *)(sVar1 + 0x80568a) = _DAT_0080bdc2;
    *(undefined4 *)(sVar1 + 0x80568c) = _DAT_00809688;
    *(undefined2 *)(sVar1 + 0x805690) = fuel_demand_state_t_0080c9a4._2_2_;
    *(undefined2 *)(sVar1 + 0x805692) = _DAT_00809308;
    *(word *)(sVar1 + 0x805694) = fuel_demand_state_t_0080c9a4.command;
    *(undefined2 *)(sVar1 + 0x805696) = _DAT_0080d482;
    *(undefined2 *)(sVar1 + 0x805698) = _DAT_00809a5e;
    *(undefined2 *)(sVar1 + 0x80569a) = _DAT_00809a58;
    *(undefined2 *)(sVar1 + 0x80569c) = _DAT_0080938c;
    *(undefined2 *)(sVar1 + 0x80569e) = _DAT_00809a4e;
    *(undefined2 *)(sVar1 + 0x8056a0) = _DAT_0080bdc4;
  }
  return;
}



//
// Function: initSensorDataArrays @ 0x000281e8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initSensorDataArrays(void)

{
  char cVar1;
  short sVar2;
  
  cVar1 = '\0';
  if (_DAT_0080d4c4 == 0) {
    sVar2 = 0;
    for (; cVar1 != '\x14'; cVar1 = cVar1 + '\x01') {
      *(undefined2 *)(&DAT_00805676 + sVar2) = 0x7d;
      *(undefined2 *)(&DAT_00805a36 + sVar2) = 0x7d;
      sVar2 = sVar2 + 0x30;
    }
  }
  return;
}



//
// Function: tpuChannelStateMachine @ 0x00028220
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 tpuChannelStateMachine(void)

{
  char cVar1;
  undefined4 in_D0;
  int iVar2;
  undefined4 in_D1;
  
  DAT_0080d2da = 0;
  tpu_timer_channel_register._0_2_ = tpu_timer_channel_register._0_2_ & 0xfff;
  if (((DAT_0080d2d0 == '\x01') && (*_DAT_0080d2c2 != 0)) && (DAT_0080d2ce == '\0')) {
    if (*_DAT_0080d2c2 < 3) {
      _DAT_0080d2c6 = (byte *)CONCAT31(_DAT_0080d2c6,DAT_0080d2c5 + '\x01');
      *_DAT_0080d2c2 = 0;
      DAT_0080d2d3 = 0;
    }
    else if (DAT_0080d2d3 == 0) {
      *_DAT_0080d2c2 = *_DAT_0080d2c2 - 1;
      _DAT_0080d2c2 = (byte *)CONCAT31(_DAT_0080d2c2,DAT_0080d2c9 + -1);
      *_DAT_0080d2c2 = 0;
    }
    else {
      _DAT_0080d2c6 = (byte *)CONCAT31(_DAT_0080d2c6,DAT_0080d2c5 + '\x01');
      if (*_DAT_0080d2c6 < 7) {
        if ((int)_DAT_0080d2c2 < _DAT_0080d2ca) {
          iVar2 = (_DAT_0080d2ca - (int)_DAT_0080d2c2) + -2;
        }
        else {
          iVar2 = (_DAT_0080d2ca - (int)_DAT_0080d2c2) + 0xfe;
        }
        if (3 < iVar2) {
          DAT_0080d2db = DAT_0080d2db + '\x01';
          *_DAT_0080d2c2 = 2;
          _DAT_0080d2c2 = (byte *)CONCAT31(_DAT_0080d2c2,DAT_0080d2c5 + '\x01');
          *_DAT_0080d2c2 = 6;
          _DAT_0080d2c2 = (byte *)CONCAT31(_DAT_0080d2c2,DAT_0080d2c5 + '\x01');
          *_DAT_0080d2c2 = 0x74;
          cVar1 = DAT_0080d2c5;
          _DAT_0080d2c2 = (byte *)CONCAT31(_DAT_0080d2c2,DAT_0080d2c5 + '\x01');
          _DAT_0080d2c6 = (byte *)CONCAT31(_DAT_0080d2c6,cVar1 + '\x02');
        }
      }
      *_DAT_0080d2c2 = 0;
      DAT_0080d2d3 = 0;
    }
  }
  if (DAT_0080d2d0 == '\0') {
    DAT_0080d2d3 = 0;
    DAT_0080d2d0 = '\x01';
    DAT_0080d2bb = (char)_DAT_0080d2bc;
    _DAT_0080d2b8 = (byte *)CONCAT31((int3)((uint)_DAT_0080d2bc >> 8),DAT_0080d2bb + '\x01');
    DAT_0080d2da = 1;
    tpu_timer_channel_register._2_2_ = 0xfcbe;
    tpu_timer_channel_register._0_2_ = tpu_timer_channel_register._0_2_ & 0x7fff | 0x4000;
  }
  else if (_DAT_0080d2b4 != _DAT_0080d2bc) {
    if ((_DAT_00fffc0c & 0x20) == 0) {
      _DAT_00fffc0e = (ushort)*_DAT_0080d2b8;
      DAT_0080d2d0 = '\0';
      _DAT_0080d2d6 = 0;
      DAT_0080d2d1 = 1;
      DAT_0080d2d3 = *_DAT_0080d2b8;
      _DAT_00fffc0a = _DAT_00fffc0a | 0x20;
    }
    else {
      DAT_0080d2da = 1;
      tpu_timer_channel_register._2_2_ = 0xfc8a;
      tpu_timer_channel_register._0_2_ = tpu_timer_channel_register._0_2_ & 0x7fff | 0x4000;
    }
  }
  return CONCAT44(in_D0,in_D1);
}



//
// Function: engineSpeedIsrRegister @ 0x000283c0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engineSpeedIsrRegister(void)

{
  _DAT_00808fee = tpuChannelStateMachine;
  tpu_timer_channel_register._0_2_ = tpu_timer_channel_register._0_2_ & 0xfff;
  return;
}



//
// Function: engineRpmHardwareTimerSetup @ 0x000283dc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engineRpmHardwareTimerSetup(void)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  undefined4 local_8;
  
  uVar3 = circular_buffer_t_0080c3fc.data_buffer_8;
  if (_DAT_0080d460 == 1) {
    uVar3 = _DAT_0080d45e;
  }
  if ((uVar3 != 0) && (uVar3 < _DAT_00801a66)) {
    uVar3 = _DAT_00801a66;
  }
  if ((uVar3 == 0) || (0x10c5 < _DAT_00808a4e)) {
    _DAT_0080d462 = 0x4230bdc0;
    local_8 = proportionalCalculation(16000000,0x4230bdc0,32000000);
    local_8 = local_8 & 0xffff;
  }
  else {
    _DAT_0080d462 = ((uint)_DAT_00808a4e * 1000000) / (uint)uVar3;
    uVar2 = proportionalCalculation(16000000,_DAT_0080d462,32000000);
    local_8 = uVar2 & 0xffff;
    uVar1 = local_8;
    local_8 = CONCAT22((short)((int)uVar1 >> 1),(short)uVar2);
  }
  _DAT_00ffffc4 = local_8;
  return;
}



//
// Function: can1ControllerInit @ 0x000284aa
//

/* WARNING: Removing unreachable block (ram,0x00028528) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void can1ControllerInit(void)

{
  _DAT_00fffe0a = _DAT_00fffe0a & 0xefff;
  _DAT_00fffe20 = _DAT_00fffe20 & 0xefff;
  _DAT_00fffe0c = _DAT_00fffe0c & 0xfff0 | 0xb;
  _DAT_00ffffc0 = 0x92;
  _DAT_00ffffc4 = 0xffff;
  _DAT_00fffe18 = _DAT_00fffe18 & 0xfcff | 0x200;
  _DAT_00fffe1c = _DAT_00fffe1c & 0xfcff | 0x100;
  _DAT_00801a66 = (ushort)((int)((uint)_DAT_00808a4e * 0x1e84) >> 10);
  if (_DAT_00801a66 < _DAT_00808a50) {
    _DAT_00801a66 = _DAT_00808a50;
  }
  return;
}



//
// Function: emptyStubFunction9 @ 0x0002853c
//

undefined8 emptyStubFunction9(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  return CONCAT44(in_D0,in_D1);
}



//
// Function: emptyInitPlaceholder @ 0x00028546
//

void emptyInitPlaceholder(void)

{
  return;
}



//
// Function: engineStatisticsAccumulator @ 0x00028548
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 engineStatisticsAccumulator(uint *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  
  iVar1 = _DAT_0080d46a;
  uVar3 = 0;
  *param_1 = _DAT_0080d46a + *param_1;
  if (0xfffff < *param_1) {
    uVar2 = *param_1 >> 0x14;
    uVar3 = (ushort)(-uVar2 - 1 <= *param_2);
    *param_2 = uVar2 + *param_2;
    iVar1 = uVar2 * 0x100000;
    *param_1 = *param_1 + uVar2 * -0x100000;
  }
  return CONCAT22((short)((uint)iVar1 >> 0x10),uVar3);
}



//
// Function: runTimeCountersUpdate @ 0x00028588
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void runTimeCountersUpdate(void)

{
  _DAT_00804bcc = _DAT_00805f44 + 1;
  _DAT_00805f48 = _DAT_00805f48 + 1;
  _DAT_00805f44 = _DAT_00804bcc;
  if (_DAT_0080d46a != 0) {
    engineStatisticsAccumulator((uint *)&DAT_00805f24,(uint *)&DAT_00805f38);
    engineStatisticsAccumulator((uint *)0x805f58,(uint *)&DAT_00804bd0);
  }
  return;
}



//
// Function: runTimeCountersUpdateAlt @ 0x000285c8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void runTimeCountersUpdateAlt(void)

{
  _DAT_00805f4c = _DAT_00805f4c + 1;
  _DAT_00804bd4 = _DAT_00805f64 + 1;
  _DAT_00805f64 = _DAT_00804bd4;
  if (_DAT_0080d46a != 0) {
    engineStatisticsAccumulator((uint *)&DAT_00805f28,(uint *)&DAT_00805f3c);
    engineStatisticsAccumulator((uint *)0x805f5c,(uint *)0x805f60);
  }
  return;
}



//
// Function: FUN_0002860c @ 0x0002860c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte FUN_0002860c(void)

{
  byte bVar1;
  
  bVar1 = DAT_0080bdef & 1;
  if (((DAT_0080bdef & 1) == 0) && (bVar1 = DAT_0080bdf1 & 1, (DAT_0080bdf1 & 1) == 0)) {
    return bVar1;
  }
  _DAT_00805f68 = _DAT_00805f68 + 1;
  _DAT_00805f50 = _DAT_00805f50 + 1;
  return bVar1;
}



//
// Function: FUN_00028638 @ 0x00028638
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00028638(void)

{
  ushort uVar1;
  
  if (circular_buffer_t_0080c3fc.current_engine_rpm != 0) {
    if (_DAT_00805f8a < circular_buffer_t_0080c3fc.current_engine_rpm) {
      _DAT_00805f8a = circular_buffer_t_0080c3fc.current_engine_rpm;
    }
    if ((circular_buffer_t_0080c3fc.current_engine_rpm < _DAT_00803818) || (_DAT_00808a66 == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = (short)((int)((uint)circular_buffer_t_0080c3fc.current_engine_rpm -
                           (uint)_DAT_00803818) / (int)(uint)_DAT_00808a66) + 1;
      if (0x18 < uVar1) {
        uVar1 = 0x18;
      }
    }
    *(int *)(&DAT_00805eb4 + (short)uVar1 * 4) = *(int *)(&DAT_00805eb4 + (short)uVar1 * 4) + 1;
  }
  DAT_00801a84 = DAT_00801a84 + '\x01';
  if (DAT_00801a84 == '\n') {
    DAT_00801a84 = '\0';
    if (circular_buffer_t_0080c3fc.current_engine_rpm != 0) {
      if (_DAT_00805f80 != -1) {
        _DAT_00805f80 = _DAT_00805f80 + 1;
      }
      if (_DAT_00805f7c != -1) {
        _DAT_00805f7c = _DAT_00805f7c + 1;
      }
      _DAT_00801a82 =
           _DAT_00801a82 - (short)((int)((uint)_DAT_00801a82 - (uint)_DAT_0080d0c8) / _DAT_00805f80)
      ;
      _DAT_00801a80 =
           _DAT_00801a80 - (short)((int)((uint)_DAT_00801a80 - (uint)_DAT_0080d0c8) / _DAT_00805f7c)
      ;
      _DAT_00805f78 = _DAT_00801a80;
      _DAT_00805f7a = _DAT_00801a82;
    }
  }
  if (fuel_demand_state_t_0080c9a4._2_2_ == 0xb) {
    if (_DAT_00801a7a != 0) {
      _DAT_00801a7a = _DAT_00801a7a + -1;
    }
    if (_DAT_00801a78 != 0) {
      _DAT_00801a78 = _DAT_00801a78 + -1;
    }
    if (_DAT_00801a7c != 0) {
      _DAT_00801a7c = _DAT_00801a7c + -1;
    }
    _DAT_00801a74 = 0;
  }
  else {
    _DAT_00801a74 = _DAT_00801a74 + 1;
    if (_DAT_00808a68 < _DAT_008092b0) {
      if (_DAT_00808a58 < _DAT_0080d0c8) {
        _DAT_00801a78 = _DAT_00808a5a;
      }
      if (_DAT_00808a62 < circular_buffer_t_0080c3fc.current_engine_rpm) {
        _DAT_00801a7a = _DAT_00808a64;
      }
      if (_DAT_00808a5c < _DAT_00801a74) {
        _DAT_00801a7c = _DAT_00808a60;
      }
    }
  }
  if (((engine_operating_mode_t_0080c810.state == 8) && (_DAT_00801a7e != 8)) &&
     ((_DAT_00801a7a != 0 || _DAT_00801a78 != 0 || (_DAT_00801a7c != 0)))) {
    _DAT_00805f88 = _DAT_00805f88 + 1;
    _DAT_00801a78 = 0;
    _DAT_00801a7a = 0;
    _DAT_00801a7c = 0;
  }
  _DAT_00801a7e = engine_operating_mode_t_0080c810.state;
  if (fuel_demand_state_t_0080c9a4._2_2_ == 0x12) {
    _DAT_00805f84 = _DAT_00805f84 + 1;
  }
  return;
}



//
// Function: fuelStatisticsTracker @ 0x0002880e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort fuelStatisticsTracker(void)

{
  uint uVar1;
  undefined4 uVar2;
  ushort uVar3;
  undefined4 *puVar4;
  
  if (_DAT_0080d47c == 1) {
    _DAT_0080d47c = 0;
    _DAT_0080d466 = 1;
    uVar3 = 0;
    puVar4 = (undefined4 *)&DAT_00805eb4;
    do {
      *puVar4 = 0;
      uVar3 = uVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (uVar3 < 0x19);
    _DAT_00805f18 = 0;
    _DAT_00805f20 = 0;
    _DAT_00805f24 = 0;
    _DAT_00805f28 = 0;
    _DAT_00805f30 = 0;
    _DAT_00805f34 = 0;
    _DAT_00805f38 = 0;
    _DAT_00805f3c = 0;
    _DAT_00805f40 = 0;
    _DAT_00805f48 = 0;
    _DAT_00805f4c = 0;
    _DAT_00805f50 = 0;
    _DAT_00805f54 = 0;
    _DAT_00805f70 = 0;
    _DAT_00805f7a = 0;
    _DAT_00805f80 = 0;
    _DAT_00805f84 = 0;
    _DAT_00805f88 = 0;
    _DAT_00805f8a = 0;
    _DAT_00804bbc = 0;
  }
  uVar3 = engine_control_flags_t_008035d6.engine_operating_state & 0x200;
  if (uVar3 != 0) {
    if (circular_buffer_t_0080c3fc.current_engine_rpm == 0) {
      _DAT_0080d47a = 0;
    }
    else if ((fuel_demand_state_t_0080c9a4._2_2_ == 0xb) && (_DAT_008096a6 == 0)) {
      _DAT_0080d47a = 1;
    }
    else if (_DAT_0080d17a == 1) {
      _DAT_0080d47a = 2;
    }
    else {
      _DAT_0080d47a = 3;
    }
    if (_DAT_0080d47a == 0) {
      _DAT_0080d476 = 0;
      _DAT_0080d478 = 0;
      _DAT_00801a68 = 0;
    }
    else {
      if (0xfffffffd < _DAT_00805f2c) {
        _DAT_00805f40 = _DAT_00805f40 | 0x10;
      }
      _DAT_00805f2c = _DAT_00805f2c + 1;
      if (0xfffffffd < _DAT_00805f54) {
        _DAT_00805f40 = _DAT_00805f40 | 0x400;
      }
      _DAT_00805f54 = _DAT_00805f54 + 1;
      if (_DAT_00805f2c < -_DAT_00803814 - 1U) {
        _DAT_00804bd8 = _DAT_00803814 + _DAT_00805f2c;
      }
      else {
        _DAT_00804bd8 = -1;
      }
      if (_DAT_00808a56 == 0) {
        _DAT_0080d46a =
             proportionalCalculation(_DAT_00805f8c - _DAT_00801a70,0x800000,_DAT_00808a6a);
        _DAT_00801a70 = _DAT_00805f8c;
      }
      else {
        _DAT_0080d46a = proportionalCalculation((uint)_DAT_0080c9ca,0x5000000,0x39c2c30);
      }
      if (_DAT_0080d46a == 0) {
        _DAT_0080d476 = 0;
        _DAT_0080d478 = 0;
      }
      else {
        DAT_0080d468 = DAT_0080d469;
        uVar1 = proportionalCalculation(_DAT_0080d46a,0x232893,0x800000);
        if (uVar1 < 0x10000) {
          _DAT_0080d478 = (ushort)uVar1;
        }
        else {
          _DAT_0080d478 = 0xffff;
        }
        if (DAT_00801a85 == '\0') {
          _DAT_00801a6a = _DAT_0080d478;
          DAT_00801a85 = '\x01';
        }
        else {
          uVar1 = (((uint)_DAT_00801a6a + (uint)_DAT_0080d478 >> 1) +
                  (uint)_DAT_00801a6c + (uint)_DAT_00801a6e) / 3;
          if (uVar1 < 0x10000) {
            _DAT_0080d476 = (ushort)uVar1;
          }
          else {
            _DAT_0080d476 = 0xffff;
          }
          _DAT_00801a6e = _DAT_00801a6c;
          _DAT_00801a6c = _DAT_0080d476;
          DAT_00801a85 = '\0';
        }
        uVar2 = engineStatisticsAccumulator((uint *)0x805f1c,(uint *)&DAT_00805f6c);
        if ((short)uVar2 != 0) {
          _DAT_00805f40 = _DAT_00805f40 | 0x20;
        }
        uVar2 = engineStatisticsAccumulator((uint *)&DAT_00805f20,(uint *)&DAT_00805f34);
        if ((short)uVar2 != 0) {
          _DAT_00805f40 = _DAT_00805f40 | 0x800;
        }
        _DAT_00804bb8 = _DAT_00805f6c;
        _DAT_00804bbc = _DAT_00805f34;
        if (DAT_0080d468 == '\0') {
          _DAT_00801a68 = 0;
        }
        else if (_DAT_00808a54 < _DAT_00801a68) {
          _DAT_00805f40 = _DAT_00805f40 | 0x41;
        }
        else {
          _DAT_00801a68 = _DAT_00801a68 + 1;
        }
      }
      if (_DAT_0080d47a == 3) {
        engineStatisticsAccumulator((uint *)&DAT_00805f18,(uint *)&DAT_00805f30);
      }
      else if (_DAT_0080d47a == 1) {
        runTimeCountersUpdate();
      }
      else if (_DAT_0080d47a == 2) {
        runTimeCountersUpdateAlt();
      }
      FUN_0002860c();
      if (_DAT_0080c7c4 != 0) {
        _DAT_00805f70 = _DAT_00805f70 + 1;
        _DAT_00805f74 = _DAT_00805f74 + 1;
      }
    }
    uVar3 = FUN_00028638();
  }
  return uVar3;
}



//
// Function: FUN_00028b78 @ 0x00028b78
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_00028b78(void)

{
  if ((engine_control_flags_t_008035d6.engine_operating_state & 0x200) != 0) {
    if (_DAT_00803680 != 0) {
      _DAT_00805f40 = _DAT_00805f40 | 0x82;
    }
    if (_DAT_0080368a != 0) {
      _DAT_00805f40 = _DAT_00805f40 | 0x208;
    }
    if (_DAT_00803692 != 0) {
      _DAT_00805f40 = _DAT_00805f40 | 0x104;
    }
  }
  return engine_control_flags_t_008035d6.engine_operating_state & 0x200;
}



//
// Function: initDiagnosticSystemState @ 0x00028bda
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initDiagnosticSystemState(void)

{
  _DAT_0080d47a = 0;
  DAT_0080d468 = 0;
  _DAT_00801a70 = _DAT_00805f8c;
  _DAT_00801a6a = 0;
  _DAT_00801a74 = 0;
  _DAT_00801a80 = 0;
  _DAT_00801a82 = 0;
  _DAT_00801a7e = 0;
  return;
}



//
// Function: initInternalRamAndCAN1 @ 0x0002939c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initInternalRamAndCAN1(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((_DAT_00fffe00 & 0x400) != 0x400) {
    _DAT_00fffb04 = 0xffe0;
    puVar1 = &DAT_00028c10;
    puVar2 = (undefined4 *)&DAT_00ffe000;
    do {
      puVar3 = puVar2 + 1;
      *puVar2 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar2 = puVar3;
    } while (puVar3 < (undefined4 *)0xffe68c);
    do {
      puVar1 = puVar3 + 1;
      *puVar3 = 0;
      puVar3 = puVar1;
    } while (puVar1 < (undefined4 *)0xffe6ff);
    puVar2 = &DAT_0002929c;
    do {
      puVar3 = puVar1 + 1;
      *puVar1 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar1 = puVar3;
    } while (puVar3 < (undefined4 *)0xffe7ff);
    _DAT_00fffe00 = 0x407;
    _DAT_00fffe0a = 0;
    _DAT_00fffe08 = 0x440;
  }
  return;
}



//
// Function: diagnosticSessionValidator @ 0x00029422
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint diagnosticSessionValidator(undefined4 param_1)

{
  uint in_D0;
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = &reference_table_t_008086f6.config_byte;
  bVar1 = 0;
  while (((param_1._0_2_ != *(short *)pbVar2 || ((char)param_1 != pbVar2[3])) &&
         ((param_1._0_2_ != 1 || ((*(short *)pbVar2 != 1 || (pbVar2[3] != -1))))))) {
    in_D0 = 0;
    pbVar2 = pbVar2 + 0x14;
    bVar1 = bVar1 + 1;
    if (4 < bVar1) {
      return 1;
    }
  }
  _DAT_0080d01a = pbVar2;
  return in_D0 & 0xffff0000;
}



//
// Function: FUN_00029476 @ 0x00029476
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00029476(int param_1,undefined4 param_2)

{
  _DAT_00801a86 =
       CONCAT13((char)(((ushort)can_priority_lookup_table_t_008037b6._0_2_ & 7) << 2),0xe8ff00);
  _DAT_00801a88 = CONCAT11(*(undefined1 *)(param_1 + 3),*(undefined1 *)(param_1 + 2));
  DAT_00801a94 = (undefined1)((uint)param_2 >> 0x10);
  DAT_00801a99 = **(undefined1 **)(param_1 + 6);
  DAT_00801a9a = *(undefined1 *)(*(int *)(param_1 + 6) + 1);
  DAT_00801a9b = *(undefined1 *)(*(int *)(param_1 + 6) + 2);
  sendCanMessage((j1939_header_t *)&DAT_00801a86);
  return;
}



//
// Function: canBufferSetup1 @ 0x000294ea
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void canBufferSetup1(void)

{
  _DAT_00801a8a = 8;
  _DAT_00801a8c = &DAT_00801a94;
  _DAT_00801a90 = 0x801a9c;
  DAT_00801a95 = 0xff;
  DAT_00801a96 = 0xff;
  DAT_00801a97 = 0xff;
  DAT_00801a98 = 0xff;
  return;
}



//
// Function: FUN_00029522 @ 0x00029522
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00029522(void)

{
  DAT_00801aac = (undefined1)((((uint)_DAT_008092f2 * 2 >> 7) * 0x1afa) / 1000);
  sendCanMessage((j1939_header_t *)&DAT_00801a9e);
  return;
}



//
// Function: ambientConditionsPGN_65269_Builder @ 0x0002956a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ambientConditionsPGN_65269_Builder(void)

{
  _DAT_00801a9e =
       CONCAT13((char)(((ushort)can_priority_lookup_table_t_008037b6._2_2_ & 7) << 2),0xfef500);
  _DAT_00801aa2 = 8;
  _DAT_00801aa4 = &DAT_00801aac;
  _DAT_00801aa8 = 0x801ab4;
  _DAT_00801a9e = CONCAT31(_DAT_00801a9e,DAT_0080cfc3);
  DAT_00801aad = 0xff;
  DAT_00801aae = 0xff;
  DAT_00801aaf = 0xff;
  DAT_00801ab0 = 0xff;
  DAT_00801ab1 = 0xff;
  _DAT_00801ab2 = 0xffff;
  return;
}



//
// Function: ambientConditionsDataBuilder @ 0x000295d4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ambientConditionsDataBuilder(void)

{
  uint uVar1;
  undefined2 local_6;
  
  if ((DAT_0080bdc6 & 0x20) == 0) {
    DAT_00801ac4 = 0xf3;
  }
  else {
    DAT_00801ac4 = 0xf7;
  }
  if ((-(8 < _DAT_008096a6) & 1U) < 0x9d) {
    local_6 = _DAT_008096a6;
  }
  else {
    local_6 = 0x9c00;
  }
  uVar1 = (uint)local_6;
  local_6._1_1_ = (undefined1)(uVar1 * 0x19c >> 8);
  DAT_00801ac5 = (undefined1)local_6;
  local_6._0_1_ = (undefined1)(uVar1 * 0x19c >> 0x10);
  DAT_00801ac6 = local_6._0_1_;
  if ((DAT_0080bdc7 & 4) == 0) {
    DAT_00801ac7 = 0;
  }
  else {
    DAT_00801ac7 = 4;
  }
  if ((DAT_0080bdc7 & 8) != 0) {
    DAT_00801ac7 = DAT_00801ac7 | 0x10;
  }
  if ((DAT_0080bdcc & 0x10) != 0) {
    DAT_00801ac7 = DAT_00801ac7 | 4;
  }
  if (_DAT_0080969a == 1) {
    DAT_00801ac7 = DAT_00801ac7 | 1;
  }
  if ((DAT_0080bdcc & 2) == 0) {
    DAT_00801ac8 = 0;
  }
  else {
    DAT_00801ac8 = 0x40;
  }
  if ((DAT_0080bdcc & 1) != 0) {
    DAT_00801ac8 = DAT_00801ac8 | 0x10;
  }
  if ((DAT_0080bdcc & 8) != 0) {
    DAT_00801ac8 = DAT_00801ac8 | 4;
  }
  if ((DAT_0080bdcc & 4) != 0) {
    DAT_00801ac8 = DAT_00801ac8 | 1;
  }
  DAT_00801ac9 = (undefined1)((uint)_DAT_0080969c * 0x19c >> 0x10);
  if (_DAT_0080969a == 1) {
    DAT_00801aca = 0x3f;
  }
  else {
    DAT_00801aca = 0x1f;
  }
  sendCanMessage((j1939_header_t *)&DAT_00801ab6);
  return;
}



//
// Function: j1939MessageSetup_PGN_65265 @ 0x00029796
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void j1939MessageSetup_PGN_65265(void)

{
  _DAT_00801ab6 =
       CONCAT13((char)(((ushort)can_priority_lookup_table_t_008037b6._4_2_ & 7) << 2),0xfef100);
  _DAT_00801ab6 = CONCAT31(_DAT_00801ab6,DAT_0080cfc3);
  _DAT_00801aba = 7;
  _DAT_00801abc = &DAT_00801ac4;
  _DAT_00801ac0 = 0x801acc;
  DAT_00801ac4 = 0xf3;
  DAT_00801acb = 0xff;
  canTransmissionController();
  return;
}



//
// Function: FUN_000297fc @ 0x000297fc
//

void FUN_000297fc(void)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  
  bVar1 = 0;
  puVar2 = &DAT_00801adc;
  puVar3 = &DAT_00004404;
  do {
    *puVar2 = *puVar3;
    bVar1 = bVar1 + 1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (bVar1 < 5);
  DAT_00801ae1 = 0x2a;
  bVar1 = 0;
  puVar2 = &DAT_00801ae2;
  puVar3 = &DAT_00004409;
  do {
    *puVar2 = *puVar3;
    bVar1 = bVar1 + 1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (bVar1 < 0x11);
  DAT_00801af3 = 0x2a;
  bVar1 = 0;
  puVar2 = &DAT_00801af4;
  puVar3 = &DAT_0000441a;
  do {
    *puVar2 = *puVar3;
    bVar1 = bVar1 + 1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (bVar1 < 4);
  sendCanMessage((j1939_header_t *)&DAT_00801ace);
  return;
}



//
// Function: engineSerialNumberPGN_65259_Builder @ 0x00029868
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engineSerialNumberPGN_65259_Builder(void)

{
  _DAT_00801ace = CONCAT13((char)((_DAT_008037bc & 7) << 2),0xfeeb00);
  _DAT_00801ad2 = 0x1c;
  _DAT_00801ad4 = &DAT_00801adc;
  _DAT_00801ad8 = 0x801af8;
  _DAT_00801ace = CONCAT31(_DAT_00801ace,DAT_0080cfc3);
  canTransmissionController();
  return;
}



//
// Function: FUN_000298d8 @ 0x000298d8
//

byte * FUN_000298d8(byte *param_1,undefined4 param_2)

{
  undefined4 in_D0;
  undefined2 uVar1;
  byte bVar2;
  j1939_header_t *msg_header;
  undefined4 unaff_D2;
  char cVar3;
  byte bVar4;
  short sVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  
  uVar1 = (undefined2)CONCAT31((int3)((uint)in_D0 >> 8),**(undefined1 **)(param_1 + 6));
  bVar2 = messageTypeToChannelMapper(CONCAT22(uVar1,(short)((uint)unaff_D2 >> 0x10)));
  cVar3 = (char)((uint)param_2 >> 0x10);
  if (cVar3 == '\0') {
    sVar5 = bVar2 + 1;
  }
  else {
    sVar5 = bVar2 + 2;
  }
  msg_header = (j1939_header_t *)multiPacketBufferAllocator(CONCAT22(sVar5,uVar1));
  if (msg_header != (j1939_header_t *)0x0) {
    msg_header->id = 0xef0000;
    bVar4 = *param_1;
    *(byte *)&msg_header->id = *(byte *)&msg_header->id & 0xe3;
    *(byte *)&msg_header->id = bVar4 & 0x1c | *(byte *)&msg_header->id;
    *(byte *)((int)&msg_header->id + 2) = param_1[3];
    *(byte *)((int)&msg_header->id + 3) = param_1[2];
    puVar7 = (undefined1 *)msg_header[1].id;
    if (cVar3 == '\0') {
      puVar6 = puVar7 + 1;
      *puVar7 = 0xc;
    }
    else {
      *puVar7 = 0xd;
      puVar6 = puVar7 + 2;
      puVar7[1] = *(undefined1 *)((int)&DAT_000298be + (int)(short)(param_2._0_2_ & 0xff));
    }
    puVar7 = *(undefined1 **)(param_1 + 6);
    for (bVar4 = 0; bVar4 < bVar2; bVar4 = bVar4 + 1) {
      *puVar6 = *puVar7;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    msg_header = (j1939_header_t *)sendCanMessage(msg_header);
  }
  return (byte *)msg_header;
}



//
// Function: FUN_00029976 @ 0x00029976
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte FUN_00029976(void)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  uint *puVar5;
  
  _DAT_00801b04 = &DAT_008021fe;
  bVar3 = DAT_008021fe & 0xf0;
  if (bVar3 == 0) {
    _DAT_00801afe = 2;
    if (DAT_00804e7c == 0) {
      DAT_00801b08 = 0;
      _DAT_00801b0a = 0xffffffff;
      _DAT_00801afe = 6;
    }
    else {
      uVar2 = ioControlBitMapper();
      DAT_00801b08 = (undefined1)uVar2;
      puVar5 = (uint *)&DAT_00801b0a;
      for (bVar3 = 1; bVar3 <= DAT_00804e7c; bVar3 = bVar3 + 1) {
        bVar1 = (&DAT_00804e7c)[(short)(ushort)bVar3];
        if ((*(ushort *)(&DAT_008065ce + (short)((ushort)bVar1 * 3) * 2) & 0x4000) == 0) {
          if ((byte)(&DAT_00804fcd)[(short)((ushort)bVar1 * 10)] < 0x80) {
            bVar4 = (&DAT_00804fcd)[(short)((ushort)bVar1 * 10)];
          }
          else {
            bVar4 = 0x7f;
          }
          uVar2 = *(uint *)((short)(ushort)bVar1 * 4 + 0x8084ce) & 0xffffe000;
          *puVar5 = CONCAT22((short)(uVar2 >> 0x10),
                             (ushort)bVar4 |
                             (*(byte *)((short)(ushort)bVar1 * 4 + 0x8084d0) & 0x1f) * 2 |
                             (ushort)uVar2) | 0x80;
          _DAT_00801afe = _DAT_00801afe + 4;
        }
        puVar5 = puVar5 + 1;
      }
    }
    bVar3 = sendCanMessage((j1939_header_t *)&DAT_00801afa);
  }
  return bVar3;
}



//
// Function: engineCoolantPGN_65226_Builder @ 0x00029a86
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engineCoolantPGN_65226_Builder(void)

{
  _DAT_00801afa = CONCAT13((char)((_DAT_008037be & 7) << 2),0xfeca00);
  _DAT_00801b00 = &DAT_00801b08;
  _DAT_00801b04 = &DAT_008021fe;
  _DAT_00801afa = CONCAT31(_DAT_00801afa,DAT_0080cfc3);
  DAT_00801b09 = 0xff;
  DAT_00801b0d = DAT_00801b0d & 0x7f;
  canTransmissionController();
  return;
}



//
// Function: FUN_00029ae4 @ 0x00029ae4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte FUN_00029ae4(void)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  uint *puVar5;
  
  bVar3 = DAT_00802904 & 0xf0;
  if (bVar3 == 0) {
    _DAT_00802204 = 2;
    uVar2 = ioControlBitMapper();
    DAT_0080220e = (undefined1)uVar2;
    if (DAT_00804e9c == 0) {
      _DAT_00802210 = 0xffffffff;
      _DAT_00802204 = _DAT_00802204 + 4;
    }
    else {
      puVar5 = (uint *)&DAT_00802210;
      for (bVar3 = 1; bVar3 <= DAT_00804e9c; bVar3 = bVar3 + 1) {
        if ((*(ushort *)
              (&DAT_008065ce + (short)((ushort)(&DAT_00804e9c)[(short)(ushort)bVar3] * 3) * 2) &
            0x4000) == 0) {
          bVar1 = (&DAT_00804e9c)[(short)(ushort)bVar3];
          if ((byte)(&DAT_00804fcd)[(short)((ushort)bVar1 * 10)] < 0x80) {
            bVar4 = (&DAT_00804fcd)[(short)((ushort)bVar1 * 10)];
          }
          else {
            bVar4 = 0x7f;
          }
          uVar2 = *(uint *)((short)(ushort)bVar1 * 4 + 0x8084ce) & 0xffffe000;
          *puVar5 = CONCAT22((short)(uVar2 >> 0x10),
                             (ushort)bVar4 |
                             (*(byte *)((short)(ushort)bVar1 * 4 + 0x8084d0) & 0x1f) * 2 |
                             (ushort)uVar2) | 0x80;
          _DAT_00802204 = _DAT_00802204 + 4;
        }
        puVar5 = puVar5 + 1;
      }
    }
    bVar3 = sendCanMessage((j1939_header_t *)&DAT_00802200);
  }
  return bVar3;
}



//
// Function: diagnosticDM2PGN_65227_Builder @ 0x00029bf4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticDM2PGN_65227_Builder(void)

{
  _DAT_00802200 = CONCAT13((char)((_DAT_008037c0 & 7) << 2),0xfecb00);
  _DAT_00802206 = &DAT_0080220e;
  _DAT_0080220a = &DAT_00802904;
  _DAT_00802200 = CONCAT31(_DAT_00802200,DAT_0080cfc3);
  DAT_0080220f = 0xff;
  DAT_00802213 = DAT_00802213 & 0x7f;
  canTransmissionController();
  return;
}



//
// Function: buildCanMessage @ 0x00029c52
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte buildCanMessage(void)

{
  undefined4 uVar1;
  int iVar2;
  short sVar3;
  undefined2 uVar4;
  byte bVar5;
  ushort uVar6;
  byte bVar7;
  int iVar8;
  short sVar9;
  undefined *puVar10;
  undefined2 local_6;
  
  bVar5 = DAT_00802fec & 0xf0;
  if (bVar5 == 0) {
    _DAT_0080290a = 0;
    if ((DAT_00804e7c == '\0') && (DAT_00804e9c == '\0')) {
      DAT_00802914 = 0;
      DAT_00802915 = 0;
      DAT_00802916 = 0;
      DAT_00802917 = 0;
      DAT_00802918 = 0;
      DAT_00802919 = 0xff;
      DAT_0080291a = 0xff;
      DAT_0080291c = 0xff;
      _DAT_0080290a = 8;
    }
    else {
      bVar5 = 0;
      puVar10 = &DAT_00802914;
      iVar8 = 0;
      do {
        sVar9 = (short)iVar8;
        if (*(short *)(&DAT_00805676 + sVar9) != 0x7d) {
          iVar2 = (uint)(*(short *)(&DAT_00805a36 + sVar9) != 0x7d) * 0x3c0;
          sVar3 = (short)iVar2;
          uVar6 = (ushort)((uint)(((int)(uint)*(ushort *)((short)(sVar9 + sVar3) + 0x805682) >> 7) *
                                 0x1afa) / 1000);
          if (500 < uVar6) {
            uVar6 = 500;
          }
          puVar10[6] = (char)((int)(uint)uVar6 >> 1);
          uVar4 = byteSwap16((undefined2 *)(iVar8 + iVar2 + 0x80567a));
          puVar10[8] = (char)uVar4;
          puVar10[7] = (char)((ushort)uVar4 >> 8);
          puVar10[9] = (char)((ushort)*(undefined2 *)((short)(sVar9 + sVar3) + 0x80567e) >> 8);
          puVar10[10] = (char)(((short)((int)(uint)*(ushort *)((short)(sVar9 + sVar3) + 0x805684) >>
                                       7) * 5 + -0xa0) / 9) + '(';
          if (_DAT_008084c4 == 1) {
            local_6 = (undefined2)
                      ((uint)*(ushort *)((short)(sVar9 + sVar3) + 0x805678) * 0x19c >> 8);
            uVar4 = byteSwap16(&local_6);
            puVar10[0xc] = (char)uVar4;
            puVar10[0xb] = (char)((ushort)uVar4 >> 8);
          }
          else {
            puVar10[0xb] = 0xff;
            puVar10[0xc] = 0xff;
          }
          puVar10[0xd] = (char)*(undefined2 *)(&DAT_00805676 + (short)(sVar9 + sVar3));
          puVar10[0xe] = (char)((ushort)*(undefined2 *)(&DAT_00805676 + (short)(sVar9 + sVar3)) >> 8
                               );
          puVar10[0xf] = 0;
          puVar10[0x10] = DAT_008084c3;
          bVar7 = 0;
          do {
            iVar2 = (uint)bVar7 * 0x1c;
            uVar1 = *(undefined4 *)((short)(sVar9 + (ushort)bVar7 * 0x3c0) + 0x805672);
            puVar10[iVar2 + 0x14] = (char)uVar1;
            puVar10[iVar2 + 0x13] = (char)((uint)uVar1 >> 8);
            puVar10[iVar2 + 0x12] = (char)((uint)uVar1 >> 0x10);
            puVar10[iVar2 + 0x11] = (char)((uint)uVar1 >> 0x18);
            uVar4 = *(undefined2 *)(&DAT_00805676 + (short)(sVar9 + (ushort)bVar7 * 0x3c0));
            puVar10[iVar2 + 0x16] = (char)uVar4;
            puVar10[iVar2 + 0x15] = (char)((ushort)uVar4 >> 8);
            uVar4 = *(undefined2 *)((short)(sVar9 + (ushort)bVar7 * 0x3c0) + 0x805678);
            puVar10[iVar2 + 0x18] = (char)uVar4;
            puVar10[iVar2 + 0x17] = (char)((ushort)uVar4 >> 8);
            uVar4 = *(undefined2 *)((short)(sVar9 + (ushort)bVar7 * 0x3c0) + 0x80567a);
            puVar10[iVar2 + 0x1a] = (char)uVar4;
            puVar10[iVar2 + 0x19] = (char)((ushort)uVar4 >> 8);
            uVar4 = *(undefined2 *)((short)(sVar9 + (ushort)bVar7 * 0x3c0) + 0x80567c);
            puVar10[iVar2 + 0x1c] = (char)uVar4;
            puVar10[iVar2 + 0x1b] = (char)((ushort)uVar4 >> 8);
            uVar4 = *(undefined2 *)((short)(sVar9 + (ushort)bVar7 * 0x3c0) + 0x80567e);
            puVar10[iVar2 + 0x1e] = (char)uVar4;
            puVar10[iVar2 + 0x1d] = (char)((ushort)uVar4 >> 8);
            uVar4 = *(undefined2 *)((short)(sVar9 + (ushort)bVar7 * 0x3c0) + 0x805680);
            puVar10[iVar2 + 0x20] = (char)uVar4;
            puVar10[iVar2 + 0x1f] = (char)((ushort)uVar4 >> 8);
            uVar4 = *(undefined2 *)((short)(sVar9 + (ushort)bVar7 * 0x3c0) + 0x805682);
            puVar10[iVar2 + 0x22] = (char)uVar4;
            puVar10[iVar2 + 0x21] = (char)((ushort)uVar4 >> 8);
            uVar4 = *(undefined2 *)((short)(sVar9 + (ushort)bVar7 * 0x3c0) + 0x805684);
            puVar10[iVar2 + 0x24] = (char)uVar4;
            puVar10[iVar2 + 0x23] = (char)((ushort)uVar4 >> 8);
            uVar4 = *(undefined2 *)((short)(sVar9 + (ushort)bVar7 * 0x3c0) + 0x805686);
            puVar10[iVar2 + 0x26] = (char)uVar4;
            puVar10[iVar2 + 0x25] = (char)((ushort)uVar4 >> 8);
            puVar10[iVar2 + 0x27] = 0;
            puVar10[iVar2 + 0x28] = 0;
            uVar4 = *(undefined2 *)((short)(sVar9 + (ushort)bVar7 * 0x3c0) + 0x805688);
            puVar10[iVar2 + 0x2a] = (char)uVar4;
            puVar10[iVar2 + 0x29] = (char)((ushort)uVar4 >> 8);
            uVar4 = *(undefined2 *)((short)(sVar9 + (ushort)bVar7 * 0x3c0) + 0x80568a);
            puVar10[iVar2 + 0x2c] = (char)uVar4;
            puVar10[iVar2 + 0x2b] = (char)((ushort)uVar4 >> 8);
            bVar7 = bVar7 + 1;
          } while (bVar7 < 2);
        }
        _DAT_0080290a = _DAT_0080290a + 0x49;
        iVar8 = iVar8 + 0x30;
        puVar10 = puVar10 + 0x49;
        bVar5 = bVar5 + 1;
      } while (bVar5 < 0x14);
    }
    bVar5 = sendCanMessage((j1939_header_t *)&DAT_00802906);
  }
  return bVar5;
}



//
// Function: diagnosticDM4PGN_65229_Builder @ 0x0002a090
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticDM4PGN_65229_Builder(void)

{
  byte bVar1;
  undefined *puVar2;
  
  _DAT_00802906 = CONCAT13((char)((_DAT_008037c2 & 7) << 2),0xfecd00);
  _DAT_0080290c = &DAT_00802914;
  _DAT_00802910 = &DAT_00802fec;
  _DAT_00802906 = CONCAT31(_DAT_00802906,DAT_0080cfc3);
  bVar1 = 0;
  puVar2 = &DAT_00802914;
  do {
    *puVar2 = 0x49;
    puVar2[5] = 0xff;
    puVar2 = puVar2 + 0x49;
    bVar1 = bVar1 + 1;
  } while (bVar1 < 0x14);
  canTransmissionController();
  return;
}



//
// Function: FUN_0002a100 @ 0x0002a100
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002a100(void)

{
  ushort local_6;
  
  local_6 = 0;
  DAT_00802ffc = DAT_00804e7c;
  DAT_00802ffd = DAT_00804e9c;
  DAT_00802ffe = DAT_008084c7;
  DAT_00802fff = DAT_008084c9;
  _DAT_00803000 = byteSwap16((undefined2 *)&DAT_008084ca);
  if (_DAT_0080cfce == 1) {
    local_6 = local_6 & 0xfeff;
  }
  else if ((_DAT_008084ca & 0x100) == 0) {
    local_6 = local_6 | 0x100;
  }
  else if ((_DAT_0080cfce == 0) && ((_DAT_008084ca & 0x100) != 0)) {
    local_6 = local_6 | 0x100;
  }
  _DAT_00803002 = byteSwap16(&local_6);
  sendCanMessage((j1939_header_t *)&DAT_00802fee);
  return;
}



//
// Function: diagnosticDM5PGN_65230_Builder @ 0x0002a1a0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticDM5PGN_65230_Builder(void)

{
  _DAT_00802fee = CONCAT13((char)((_DAT_008037c4 & 7) << 2),0xfece00);
  _DAT_00802ff2 = 8;
  _DAT_00802ff4 = &DAT_00802ffc;
  _DAT_00802ff8 = 0x803004;
  _DAT_00802fee = CONCAT31(_DAT_00802fee,DAT_0080cfc3);
  canTransmissionController();
  return;
}



//
// Function: FUN_0002a1f6 @ 0x0002a1f6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002a1f6(undefined4 param_1)

{
  DAT_00803014 = param_1._1_1_;
  _DAT_00803016 = byteSwap16((undefined2 *)((int)&param_1 + 2));
  sendCanMessage((j1939_header_t *)&DAT_00803006);
  return;
}



//
// Function: diagnosticDM8PGN_65232_Builder @ 0x0002a222
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticDM8PGN_65232_Builder(void)

{
  _DAT_00803006 = CONCAT13((char)((_DAT_008037c6 & 7) << 2),0xfed000);
  _DAT_0080300a = 8;
  _DAT_0080300c = &DAT_00803014;
  _DAT_00803010 = 0x80301c;
  _DAT_00803006 = CONCAT31(_DAT_00803006,DAT_0080cfc3);
  DAT_00803015 = 0xff;
  _DAT_00803018 = 0xffff;
  _DAT_0080301a = 0xffff;
  return;
}



//
// Function: diagnosticDM11PGN_65234_Builder @ 0x0002a29c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticDM11PGN_65234_Builder(void)

{
  _DAT_0080301e = CONCAT13((char)((_DAT_008037c8 & 7) << 2),0xfed200);
  _DAT_00803022 = 2;
  _DAT_00803024 = &DAT_0080302c;
  _DAT_00803028 = 0x803034;
  _DAT_0080301e = CONCAT31(_DAT_0080301e,DAT_0080cfc3);
  canTransmissionController();
  return;
}



//
// Function: buildPgn61444_ProprietarySpeed @ 0x0002a2f2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void buildPgn61444_ProprietarySpeed(void)

{
  byte local_6;
  byte bStack_5;
  
  if (fuel_arbitrator_diag_t_0080cff8.rpm_target == 0) {
    switch(fuel_demand_state_t_0080c9a4._2_2_) {
    case (BADTYPE)0x3:
    case (BADTYPE)0x7:
    case (BADTYPE)0x8:
      j1939_vp44_msg_t_00803036.j1939_status_byte = 0xf1;
      break;
    case (BADTYPE)0x4:
      j1939_vp44_msg_t_00803036.j1939_status_byte = 0xf3;
      break;
    default:
      j1939_vp44_msg_t_00803036.j1939_status_byte = 0xfe;
      break;
    case (BADTYPE)0x9:
      j1939_vp44_msg_t_00803036.j1939_status_byte = 0xf2;
      break;
    case (BADTYPE)0xa:
      j1939_vp44_msg_t_00803036.j1939_status_byte = 0xf4;
      break;
    case (BADTYPE)0xb:
      j1939_vp44_msg_t_00803036.j1939_status_byte = 0xf0;
      break;
    case (BADTYPE)0xc:
      j1939_vp44_msg_t_00803036.j1939_status_byte = 0xf9;
      break;
    case (BADTYPE)0xd:
    case (BADTYPE)0xe:
    case (BADTYPE)0xf:
    case (BADTYPE)0x10:
    case (BADTYPE)0x11:
    case (BADTYPE)0x12:
    case (BADTYPE)0x13:
    case (BADTYPE)0x14:
    case (BADTYPE)0x15:
      j1939_vp44_msg_t_00803036.j1939_status_byte = 0xf8;
      break;
    case (BADTYPE)0x18:
      j1939_vp44_msg_t_00803036.j1939_status_byte = 0xfa;
    }
  }
  else if (fuel_arbitrator_diag_t_0080cff8.fuel_mode == 1) {
    j1939_vp44_msg_t_00803036.j1939_status_byte = 0xf6;
  }
  else if (fuel_arbitrator_diag_t_0080cff8.fuel_mode == 3) {
    j1939_vp44_msg_t_00803036.j1939_status_byte = 0xf5;
  }
  else if (fuel_arbitrator_diag_t_0080cff8.fuel_mode == 2) {
    j1939_vp44_msg_t_00803036.j1939_status_byte = 0xf7;
  }
  else {
    j1939_vp44_msg_t_00803036.j1939_status_byte = 0xfe;
  }
  paramSystemModeController();
                    /* Constant: VP44_FUEL_OFFSET = 125 */
  j1939_vp44_msg_t_00803036.fuel_amount_high = (char)((ushort)_DAT_0080cfd8 >> 8) + 0x7d;
  param_lookup_1();
  j1939_vp44_msg_t_00803036.fuel_amount_low = (char)((ushort)_DAT_0080cfd6 >> 8) + 0x7d;
  bStack_5 = (byte)circular_buffer_t_0080c3fc.data_buffer_8;
  j1939_vp44_msg_t_00803036.rpm_low = bStack_5;
  local_6 = (byte)(circular_buffer_t_0080c3fc.data_buffer_8 >> 8);
  j1939_vp44_msg_t_00803036.rpm_high = local_6;
  sendCanMessage((j1939_header_t *)((int)&j1939_vp44_msg_t_00803036.vp44_header + 3));
  return;
}



//
// Function: vp44Command0x100Builder @ 0x0002a418
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44Command0x100Builder(void)

{
                    /* Constant: VP44_MSG_HEADER = 0xF00400 */
  j1939_vp44_msg_t_00803036.vp44_header._3_1_ = (char)((_DAT_008037ca & 7) << 2);
  j1939_vp44_msg_t_00803036.vp44_fuel_high = 0xf0;
  j1939_vp44_msg_t_00803036.vp44_fuel_low = 4;
  j1939_vp44_msg_t_00803036.timing_byte3 = 0;
  j1939_vp44_msg_t_00803036.timing_byte3 = DAT_0080cfc3;
  j1939_vp44_msg_t_00803036.timing_byte4 = 0;
  j1939_vp44_msg_t_00803036.timing_byte5 = 5;
  ram0x00803044 = &j1939_vp44_msg_t_00803036;
  _DAT_00803048 = 0x80304c;
  return;
}



//
// Function: buildProprietaryLoadStatusMessage @ 0x0002a45c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void buildProprietaryLoadStatusMessage(void)

{
  bool bVar1;
  
  if (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x20) == 0) ||
     ((_DAT_008068cc & 0x20) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if (((fault_status_registers_t_00805df2.io_fault_status_1 & 8) == 0) ||
       ((_DAT_008068cc & 8) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (_DAT_008086f0 < _DAT_00809d4c) {
        DAT_0080304e = 0xf4;
      }
      else {
        DAT_0080304e = 0xf0;
      }
      DAT_0080304f = (char)((int)(uint)_DAT_00809d4c >> 1) + (char)((int)(uint)_DAT_00809d4c >> 3);
      goto LAB_0002a4ea;
    }
  }
  DAT_0080304e = 0xf8;
  DAT_0080304f = -2;
LAB_0002a4ea:
  if (_DAT_00809d50 == 0) {
    DAT_0080304e = DAT_0080304e | 1;
  }
  param_lookup_2();
  DAT_00803050 = (undefined1)((ushort)_DAT_0080cfda >> 8);
  sendCanMessage((j1939_header_t *)&j1939_diagnostic_buffer_t_00803056);
  return;
}



//
// Function: cumminsProprietaryDM_983_Builder @ 0x0002a51e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cumminsProprietaryDM_983_Builder(void)

{
  j1939_diagnostic_buffer_t_00803056.can_id = CONCAT13((char)((_DAT_008037cc & 7) << 2),0xf00300);
  j1939_diagnostic_buffer_t_00803056.can_id =
       CONCAT31(j1939_diagnostic_buffer_t_00803056.can_id._0_3_,DAT_0080cfc3);
  j1939_diagnostic_buffer_t_00803056.message_length = 3;
  j1939_diagnostic_buffer_t_00803056.data_ptr = (dword)&DAT_0080304e;
  j1939_diagnostic_buffer_t_00803056.unused_ptr = 0x803064;
  diagnosticDataBufferSetup();
  canTransmissionController();
  return;
}



//
// Function: configParamCanBuilder @ 0x0002a57e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void configParamCanBuilder(void)

{
  undefined1 local_6;
  undefined1 uStack_5;
  
  param_lookup_3();
  DAT_00803066 = (char)((ushort)_DAT_0080cfdc >> 8) + '}';
  uStack_5 = (undefined1)_DAT_008086e0;
  DAT_00803067 = uStack_5;
  local_6 = (undefined1)((ushort)_DAT_008086e0 >> 8);
  DAT_00803068 = local_6;
  DAT_00803069 = DAT_008086e3;
  sendCanMessage((j1939_header_t *)&DAT_0080306e);
  return;
}



//
// Function: secondaryParamPGN_65247_Builder @ 0x0002a5da
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void secondaryParamPGN_65247_Builder(void)

{
  _DAT_0080306e = CONCAT13((char)((_DAT_008037ce & 7) << 2),0xfedf00);
  _DAT_0080306e = CONCAT31(_DAT_0080306e,DAT_0080cfc3);
  _DAT_00803072 = 4;
  _DAT_00803074 = &DAT_00803066;
  _DAT_00803078 = 0x80307c;
  return;
}



//
// Function: fuelParameterCanMessageBuilder @ 0x0002a61e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte fuelParameterCanMessageBuilder(void)

{
  byte bVar1;
  ushort uVar2;
  ushort *puVar3;
  undefined2 local_6;
  
  bVar1 = DAT_008030a8 & 0xf0;
  if (bVar1 == 0) {
    fuelModeSelectionCalculator();
    local_6._1_1_ = (undefined1)_DAT_0080d092;
    DAT_0080307e = (undefined1)local_6;
    local_6._0_1_ = (undefined1)((ushort)_DAT_0080d092 >> 8);
    DAT_0080307f = local_6._0_1_;
    DAT_00803080 = (char)(_DAT_0080cfde >> 8) + '}';
    local_6._1_1_ = (undefined1)_DAT_0080cfe8;
    DAT_00803081 = (undefined1)local_6;
    local_6._0_1_ = (undefined1)((ushort)_DAT_0080cfe8 >> 8);
    DAT_00803082 = local_6._0_1_;
    DAT_00803083 = (char)((ushort)_DAT_0080cfe0 >> 8) + '}';
    local_6._1_1_ = (undefined1)_DAT_008086c6;
    DAT_00803084 = (undefined1)local_6;
    local_6._0_1_ = (undefined1)((ushort)_DAT_008086c6 >> 8);
    DAT_00803085 = local_6._0_1_;
    DAT_00803086 = (char)((ushort)_DAT_0080cfe2 >> 8) + '}';
    local_6._1_1_ = (undefined1)_DAT_008086c8;
    DAT_00803087 = (undefined1)local_6;
    local_6._0_1_ = (undefined1)((ushort)_DAT_008086c8 >> 8);
    DAT_00803088 = local_6._0_1_;
    DAT_00803089 = (char)((ushort)_DAT_0080cfe4 >> 8) + '}';
    local_6._1_1_ = (undefined1)_DAT_0080cfea;
    DAT_0080308a = (undefined1)local_6;
    local_6._0_1_ = (undefined1)((ushort)_DAT_0080cfea >> 8);
    DAT_0080308b = local_6._0_1_;
    DAT_0080308c = (char)((ushort)_DAT_0080cfe6 >> 8) + '}';
    if (fuel_limit_arbitration_t_0080cc4a.comparison_high == 0) {
      local_6 = fuel_limit_arbitration_t_0080cc4a.arbitration_threshold;
    }
    else {
      local_6 = (short)(((uint)fuel_limit_arbitration_t_0080cc4a.comparison_high *
                        ((uint)fuel_limit_arbitration_t_0080cc4a.comparison_low -
                        (uint)reference_table_t_008086f6.base_reference)) / 0x1111) -
                (fuel_limit_arbitration_t_0080cc4a.offset_value -
                fuel_limit_arbitration_t_0080cc4a.arbitration_threshold);
      if (0xfaff < local_6) {
        local_6 = 0xfaff;
      }
    }
    DAT_0080308d = (undefined1)local_6;
    DAT_0080308e = local_6._0_1_;
    local_6._1_1_ = (undefined1)_DAT_008086c4;
    DAT_00803091 = (undefined1)local_6;
    local_6._0_1_ = (undefined1)((ushort)_DAT_008086c4 >> 8);
    DAT_00803092 = local_6._0_1_;
    local_6._1_1_ = (undefined1)_DAT_0080875c;
    DAT_00803093 = (undefined1)local_6;
    local_6._0_1_ = (undefined1)((ushort)_DAT_0080875c >> 8);
    DAT_00803094 = local_6._0_1_;
    DAT_00803095 = (undefined1)(_DAT_008086e6 / 10);
    DAT_00803096 = (undefined1)(_DAT_00808836 / 0x50);
    if (_DAT_0080848c < 0x4e21) {
      DAT_00803097 = (undefined1)(_DAT_0080848c / 0x50);
    }
    else {
      DAT_00803097 = 0x20;
    }
    uVar2 = _DAT_0080cfde;
    for (puVar3 = (ushort *)&DAT_0080cfe0; puVar3 < (ushort *)0x80cfe7; puVar3 = puVar3 + 1) {
      if (uVar2 < *puVar3) {
        uVar2 = *puVar3;
      }
    }
    DAT_00803099 = (char)(uVar2 >> 8) + '}';
    bVar1 = sendCanMessage((j1939_header_t *)&DAT_0080309a);
  }
  return bVar1;
}



//
// Function: extendedDiagPGN_65251_Builder @ 0x0002a7f8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void extendedDiagPGN_65251_Builder(void)

{
  _DAT_0080309a = CONCAT13((char)((_DAT_008037d0 & 7) << 2),0xfee300);
  _DAT_0080309a = CONCAT31(_DAT_0080309a,DAT_0080cfc3);
  _DAT_0080309e = 0x1c;
  _DAT_008030a0 = &DAT_0080307e;
  _DAT_008030a4 = &DAT_008030a8;
  DAT_0080308f = 0xff;
  DAT_00803090 = 0xff;
  DAT_00803098 = 0x7d;
  fuelBlendTablePointerSetup();
  return;
}



//
// Function: FUN_0002a856 @ 0x0002a856
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002a856(void)

{
  DAT_008030be = (undefined1)((int)((uint)(((int)(uint)_DAT_008092b0 >> 7) * 0x1afa) / 1000) >> 1);
  DAT_008030bb = (undefined1)((int)((uint)(((int)(uint)_DAT_00809242 >> 7) * 0x1afa) / 1000) >> 2);
  sendCanMessage((j1939_header_t *)&DAT_008030aa);
  return;
}



//
// Function: engineFluidLevelPGN_65263_Builder @ 0x0002a8da
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engineFluidLevelPGN_65263_Builder(void)

{
  _DAT_008030aa = CONCAT13((char)((_DAT_008037d2 & 7) << 2),0xfeef00);
  _DAT_008030ae = 8;
  _DAT_008030b0 = &DAT_008030b8;
  _DAT_008030b4 = 0x8030c0;
  _DAT_008030aa = CONCAT31(_DAT_008030aa,DAT_0080cfc3);
  DAT_008030b8 = 0xff;
  _DAT_008030bc = 0xffff;
  DAT_008030bf = 0xff;
  DAT_008030b9 = 0xff;
  return;
}



//
// Function: engineFluidLevelDataBuilder @ 0x0002a93a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engineFluidLevelDataBuilder(void)

{
  int iVar1;
  short sVar2;
  undefined2 local_6;
  
  iVar1 = ((short)(_DAT_0080926e + -0x1900 >> 7) * 5 + -0xa0) / 9;
  sVar2 = (short)iVar1;
  if (sVar2 < -0x28) {
    DAT_008030d0 = '\0';
  }
  else if (sVar2 < 0xd2) {
    local_6._1_1_ = (char)iVar1;
    DAT_008030d0 = (char)local_6 + '(';
  }
  else {
    DAT_008030d0 = -6;
  }
  iVar1 = ((short)(_DAT_00809200 + -0x1900 >> 7) * 5 + -0xa0) / 9;
  sVar2 = (short)iVar1;
  if (sVar2 < -0x28) {
    DAT_008030d1 = '\0';
  }
  else if (sVar2 < 0xd2) {
    local_6._1_1_ = (char)iVar1;
    DAT_008030d1 = (char)local_6 + '(';
  }
  else {
    DAT_008030d1 = -6;
  }
  local_6 = (short)(((short)(_DAT_008092b0 + -0x1900 >> 7) * 5 + -0xa0) / 9);
  if (local_6 < -0x111) {
    _DAT_008030d2 = 0;
  }
  else if (local_6 < 0x6c7) {
    local_6 = (local_6 + 0x111) * 0x20;
    _DAT_008030d2 = byteSwap16(&local_6);
  }
  else {
    local_6 = -0x500;
    _DAT_008030d2 = byteSwap16(&local_6);
  }
  sendCanMessage((j1939_header_t *)&DAT_008030c2);
  return;
}



//
// Function: engineTemperaturePGN_65262_Builder @ 0x0002aa74
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engineTemperaturePGN_65262_Builder(void)

{
  _DAT_008030c2 = CONCAT13((char)((_DAT_008037d8 & 7) << 2),0xfeee00);
  _DAT_008030c6 = 8;
  _DAT_008030c8 = &DAT_008030d0;
  _DAT_008030cc = 0x8030d8;
  _DAT_008030c2 = CONCAT31(_DAT_008030c2,DAT_0080cfc3);
  _DAT_008030d4 = 0xffff;
  DAT_008030d6 = 0xff;
  DAT_008030d7 = 0xff;
  canTransmissionController();
  return;
}



//
// Function: torqueControlDataBuilder @ 0x0002aade
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void torqueControlDataBuilder(void)

{
  if ((engine_control_flags_t_008035d6.protection_system & 0x1000) == 0) {
    DAT_008030da = 0;
  }
  else {
    DAT_008030da = 0x40;
  }
  if (_DAT_008096a0 != 0) {
    DAT_008030da = DAT_008030da | 0x10;
  }
  switch(_DAT_008096a2) {
  case 1:
  case 4:
    if (_DAT_008096b0 == 1) {
      DAT_008030da = DAT_008030da | 6;
    }
    else if (_DAT_008096b0 == 3) {
      DAT_008030da = DAT_008030da | 5;
    }
    else if (_DAT_008096b0 == 2) {
      DAT_008030da = DAT_008030da | 7;
    }
    else {
      DAT_008030da = DAT_008030da | 0xe;
    }
    break;
  case 2:
    DAT_008030da = DAT_008030da | 2;
    break;
  case 3:
    DAT_008030da = DAT_008030da | 1;
  }
  if (_DAT_008037d4 == 0) {
    DAT_008030db = -1;
  }
  else {
    ioControlBasedFuelCalculator();
    DAT_008030db = '}' - (char)((ushort)_DAT_00809d40 >> 8);
  }
  sendCanMessage((j1939_header_t *)&DAT_008030e2);
  return;
}



//
// Function: cumminsProprietaryTSC_PGN_15728640_Builder @ 0x0002aba4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cumminsProprietaryTSC_PGN_15728640_Builder(void)

{
  _DAT_008030e2 = CONCAT13((char)((_DAT_008037d6 & 7) << 2),0xf00000);
  _DAT_008030e2 = CONCAT31(_DAT_008030e2,DAT_0080cfcd);
  throttleTablePointerSetup();
  _DAT_008030e6 = 2;
  _DAT_008030e8 = &DAT_008030da;
  _DAT_008030ec = 0x8030f0;
  return;
}



//
// Function: FUN_0002abf2 @ 0x0002abf2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002abf2(void)

{
  uint local_8;
  
  local_8 = proportionalCalculation(_DAT_00804bbc,0x39c2c3,1000000);
  local_8 = proportionalCalculation(local_8,2,8);
  _DAT_00803100 = byteSwap32(&local_8);
  local_8 = _DAT_00804bb8 >> 2;
  local_8 = proportionalCalculation(local_8,0x39c2c3,1000000);
  _DAT_00803104 = byteSwap32(&local_8);
  sendCanMessage((j1939_header_t *)&DAT_008030f2);
  return;
}



//
// Function: intakeExhaustConditionsPGN_65257_Builder @ 0x0002ac7a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void intakeExhaustConditionsPGN_65257_Builder(void)

{
  _DAT_008030f2 = CONCAT13((char)((_DAT_008037da & 7) << 2),0xfee900);
  _DAT_008030f6 = 8;
  _DAT_008030f8 = &DAT_00803100;
  _DAT_008030fc = 0x803108;
  _DAT_008030f2 = CONCAT31(_DAT_008030f2,DAT_0080cfc3);
  canTransmissionController();
  return;
}



//
// Function: fuelEconomyDataBuilder @ 0x0002acd0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelEconomyDataBuilder(void)

{
  uint uVar1;
  short sVar2;
  undefined1 local_6;
  undefined1 uStack_5;
  
  uVar1 = proportionalCalculation((uint)_DAT_0080d478,0xe10,8000);
  uVar1 = uVar1 / 10;
  if (0xc8c < uVar1) {
    uVar1 = 0xc8c;
  }
  sVar2 = (short)uVar1 * 0x14;
  uStack_5 = (undefined1)sVar2;
  DAT_0080310c = uStack_5;
  local_6 = (undefined1)((ushort)sVar2 >> 8);
  DAT_0080310d = local_6;
  uVar1 = ((uint)_DAT_00804bc8 * 0x2136) / 10000;
  uStack_5 = (undefined1)uVar1;
  DAT_0080310e = uStack_5;
  local_6 = (undefined1)(uVar1 >> 8);
  DAT_0080310f = local_6;
  uVar1 = ((uint)_DAT_00804bca * 0x2136) / 10000;
  uStack_5 = (undefined1)uVar1;
  DAT_00803110 = uStack_5;
  local_6 = (undefined1)(uVar1 >> 8);
  DAT_00803111 = local_6;
  sendCanMessage((j1939_header_t *)&DAT_00803114);
  return;
}



//
// Function: fuelEconomyPGN_65266_Builder @ 0x0002ada8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelEconomyPGN_65266_Builder(void)

{
  _DAT_00803114 = CONCAT13((char)((_DAT_008037dc & 7) << 2),0xfef200);
  _DAT_00803114 = CONCAT31(_DAT_00803114,DAT_0080cfc3);
  _DAT_00803118 = 6;
  _DAT_0080311a = &DAT_0080310c;
  _DAT_0080311e = 0x803122;
  return;
}



//
// Function: FUN_0002adec @ 0x0002adec
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002adec(void)

{
  uint local_8;
  
  local_8 = _DAT_00804bd0 >> 2;
  local_8 = proportionalCalculation(local_8,0x39c2c3,1000000);
  _DAT_00803136 = byteSwap32(&local_8);
  local_8 = proportionalCalculation(_DAT_00804bcc,0x14,0x40);
  _DAT_0080313a = byteSwap32(&local_8);
  sendCanMessage((j1939_header_t *)&DAT_00803128);
  return;
}



//
// Function: ioControlPGN_65244_Builder @ 0x0002ae60
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ioControlPGN_65244_Builder(void)

{
  _DAT_00803128 = CONCAT13((char)((_DAT_008037de & 7) << 2),0xfedc00);
  _DAT_0080312c = 8;
  _DAT_0080312e = &DAT_00803136;
  _DAT_00803132 = 0x80313e;
  _DAT_00803128 = CONCAT31(_DAT_00803128,DAT_0080cfc3);
  canTransmissionController();
  return;
}



//
// Function: engineHoursPGN_65252_Builder @ 0x0002aee2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engineHoursPGN_65252_Builder(void)

{
  _DAT_00803140 = CONCAT13((char)((_DAT_008037e0 & 7) << 2),0xfee400);
  _DAT_00803144 = 8;
  _DAT_00803146 = &DAT_0080314e;
  _DAT_0080314a = 0x803156;
  _DAT_00803140 = CONCAT31(_DAT_00803140,DAT_0080cfc3);
  DAT_00803150 = 0xff;
  DAT_00803151 = 0xff;
  DAT_00803152 = 0xff;
  DAT_00803153 = 0xff;
  DAT_00803154 = 0xff;
  DAT_00803155 = 0xff;
  DAT_0080314f = 0x3f;
  return;
}



//
// Function: FUN_0002af52 @ 0x0002af52
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002af52(void)

{
  DAT_00803167 = (undefined1)((short)(((_DAT_00809258 >> 7) * 0x1afa) / 1000) >> 1);
  DAT_00803168 = (char)(((_DAT_008091ea >> 7) * 5 + -0xa0) / 9) + '(';
  sendCanMessage((j1939_header_t *)&DAT_00803158);
  return;
}



//
// Function: intakeManifoldPGN_65526_Builder @ 0x0002afca
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void intakeManifoldPGN_65526_Builder(void)

{
  _DAT_00803158 = CONCAT13((char)((_DAT_008037e2 & 7) << 2),0xfef600);
  _DAT_0080315c = 8;
  _DAT_0080315e = &DAT_00803166;
  _DAT_00803162 = 0x80316e;
  _DAT_00803158 = CONCAT31(_DAT_00803158,DAT_0080cfc3);
  DAT_00803166 = 0xff;
  DAT_00803169 = 0xff;
  DAT_0080316a = 0xff;
  DAT_0080316b = 0xff;
  DAT_0080316c = 0xff;
  DAT_0080316d = 0xff;
  return;
}



//
// Function: cruiseControlPGN_65264_Builder @ 0x0002b060
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cruiseControlPGN_65264_Builder(void)

{
  _DAT_00803170 = CONCAT13((char)((_DAT_008037e6 & 7) << 2),0xfef000);
  _DAT_00803174 = 8;
  _DAT_00803176 = &DAT_0080317e;
  _DAT_0080317a = 0x803186;
  _DAT_00803170 = CONCAT31(_DAT_00803170,DAT_0080cfc3);
  DAT_0080317e = 0xff;
  DAT_0080317f = 0xff;
  DAT_00803180 = 0xff;
  DAT_00803183 = 0xff;
  DAT_00803184 = 0xff;
  DAT_00803185 = 0xff;
  return;
}



//
// Function: retarderConfigDataBuilder @ 0x0002b0cc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte retarderConfigDataBuilder(void)

{
  byte bVar1;
  undefined1 local_6;
  undefined1 uStack_5;
  
  bVar1 = DAT_008031a8 & 0xf0;
  if (bVar1 == 0) {
    if (_DAT_008037d4 == 3) {
      DAT_00803188 = 0x14;
    }
    else {
      DAT_00803188 = 3;
    }
    if (_DAT_008037d4 == 0) {
      DAT_00803189 = 0xff;
    }
    else if (_DAT_008037d4 == 1) {
      DAT_00803189 = 3;
    }
    else {
      DAT_00803189 = 2;
    }
    uStack_5 = (undefined1)_DAT_0080894e;
    DAT_0080318a = uStack_5;
    local_6 = (undefined1)((ushort)_DAT_0080894e >> 8);
    DAT_0080318b = local_6;
    DAT_0080318c = '}' - (char)((ushort)_DAT_00808956 >> 8);
    uStack_5 = (undefined1)_DAT_0080895e;
    DAT_0080318d = uStack_5;
    local_6 = (undefined1)((ushort)_DAT_0080895e >> 8);
    DAT_0080318e = local_6;
    DAT_0080318f = '}' - (char)((ushort)_DAT_00808958 >> 8);
    uStack_5 = (undefined1)_DAT_00808952;
    DAT_00803190 = uStack_5;
    local_6 = (undefined1)((ushort)_DAT_00808952 >> 8);
    DAT_00803191 = local_6;
    DAT_00803192 = '}' - (char)((ushort)_DAT_0080895a >> 8);
    uStack_5 = (undefined1)_DAT_00808954;
    DAT_00803193 = uStack_5;
    local_6 = (undefined1)((ushort)_DAT_00808954 >> 8);
    DAT_00803194 = local_6;
    DAT_00803195 = '}' - (char)((ushort)_DAT_0080895c >> 8);
    uStack_5 = (undefined1)_DAT_00808950;
    DAT_00803196 = uStack_5;
    local_6 = (undefined1)((ushort)_DAT_00808950 >> 8);
    DAT_00803197 = local_6;
    uStack_5 = (undefined1)_DAT_0080894a;
    DAT_00803198 = uStack_5;
    local_6 = (undefined1)((ushort)_DAT_0080894a >> 8);
    DAT_00803199 = local_6;
    bVar1 = sendCanMessage((j1939_header_t *)&DAT_0080319a);
  }
  return bVar1;
}



//
// Function: retarderConfigPGN_65249_Builder @ 0x0002b1f6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void retarderConfigPGN_65249_Builder(void)

{
  _DAT_0080319a = CONCAT13((char)((_DAT_008037e8 & 7) << 2),0xfee100);
  _DAT_0080319a = CONCAT31(_DAT_0080319a,DAT_0080cfcd);
  _DAT_0080319e = 0x12;
  _DAT_008031a0 = &DAT_00803188;
  _DAT_008031a4 = &DAT_008031a8;
  return;
}



//
// Function: FUN_0002b23a @ 0x0002b23a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b23a(void)

{
  undefined4 local_8;
  
  local_8 = proportionalCalculation(_DAT_00804bc4,0x3268,10000);
  _DAT_008031b8 = byteSwap32(&local_8);
  local_8 = proportionalCalculation(_DAT_00804bc0,0x3268,10000);
  _DAT_008031bc = byteSwap32(&local_8);
  sendCanMessage((j1939_header_t *)&DAT_008031aa);
  return;
}



//
// Function: vehicleDistancePGN_65248_Builder @ 0x0002b29e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vehicleDistancePGN_65248_Builder(void)

{
  _DAT_008031aa = CONCAT13((char)((_DAT_008037ea & 7) << 2),0xfee000);
  _DAT_008031ae = 8;
  _DAT_008031b0 = &DAT_008031b8;
  _DAT_008031b4 = 0x8031c0;
  _DAT_008031aa = CONCAT31(_DAT_008031aa,DAT_0080cfc3);
  canTransmissionController();
  return;
}



//
// Function: FUN_0002b2f4 @ 0x0002b2f4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b2f4(void)

{
  undefined2 local_6;
  
  local_6 = (undefined2)((uint)_DAT_00809308 * 0x14 >> 3);
  _DAT_008031d6 = byteSwap16(&local_6);
  sendCanMessage((j1939_header_t *)&DAT_008031c2);
  return;
}



//
// Function: electronicBrakePGN_65527_Builder @ 0x0002b338
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void electronicBrakePGN_65527_Builder(void)

{
  _DAT_008031c2 = CONCAT13((char)((_DAT_008037ec & 7) << 2),0xfef700);
  _DAT_008031c6 = 8;
  _DAT_008031c8 = &DAT_008031d0;
  _DAT_008031cc = 0x8031d8;
  _DAT_008031c2 = CONCAT31(_DAT_008031c2,DAT_0080cfc3);
  DAT_008031d0 = 0xff;
  DAT_008031d1 = 0xff;
  _DAT_008031d2 = 0xffff;
  _DAT_008031d4 = 0xffff;
  return;
}



//
// Function: FUN_0002b398 @ 0x0002b398
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b398(void)

{
  undefined4 local_8;
  
  local_8 = proportionalCalculation(_DAT_00804bd8,0x14,0x40);
  _DAT_008031e8 = byteSwap32(&local_8);
  local_8 = proportionalCalculation(_DAT_00804bd4,0x14,0x40);
  _DAT_008031ec = byteSwap32(&local_8);
  sendCanMessage((j1939_header_t *)&DAT_008031da);
  return;
}



//
// Function: vehicleHoursPGN_65255_Builder @ 0x0002b3fc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vehicleHoursPGN_65255_Builder(void)

{
  _DAT_008031da = CONCAT13((char)((_DAT_008037ee & 7) << 2),0xfee700);
  _DAT_008031de = 8;
  _DAT_008031e0 = &DAT_008031e8;
  _DAT_008031e4 = 0x8031f0;
  _DAT_008031da = CONCAT31(_DAT_008031da,DAT_0080cfc3);
  canTransmissionController();
  return;
}



//
// Function: incrementCounters @ 0x0002b452
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void incrementCounters(void)

{
  _DAT_0080d4c4 = _DAT_0080d4c4 + 1;
  if (engine_operating_mode_t_0080c810.state != 1) {
    _DAT_00809688 = _DAT_00809688 + 1;
  }
  return;
}



//
// Function: initLoopCounter @ 0x0002b46a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initLoopCounter(void)

{
  _DAT_0080d4c4 = _DAT_0080352c;
  return;
}



//
// Function: FUN_0002b476 @ 0x0002b476
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b476(void)

{
  if ((_DAT_0080d49c == 0) && (fuel_arbitrator_diag_t_0080cff8.rpm_target == 2)) {
    _DAT_0080d49c = 1;
    _DAT_0080d49a = fuel_arbitrator_diag_t_0080cff8._24_2_;
  }
  return;
}



//
// Function: FUN_0002b49a @ 0x0002b49a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b49a(void)

{
  if ((_DAT_0080d49c == 0) && ((engine_control_flags_t_008035d6.reserved_06 & 1) != 0)) {
    _DAT_0080d49c = 5;
    _DAT_0080d49a = _DAT_0080381c;
  }
  return;
}



//
// Function: engine_protection_coordinator @ 0x0002b4c2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engine_protection_coordinator(void)

{
  undefined2 uVar1;
  undefined4 unaff_D2;
  undefined2 uVar2;
  undefined2 uVar3;
  
  uVar1 = _DAT_0080d49c;
  uVar3 = (undefined2)((uint)unaff_D2 >> 0x10);
  _DAT_0080d49c = 0;
  diagnosticStatus30Setter();
  FUN_0002b476();
  uVar2 = uVar1;
  diagnosticStatus2Initializer(CONCAT22(uVar1,uVar3));
  FUN_0002b49a();
  epsDiagnosticModeChecker(CONCAT22(uVar1,uVar2));
  diagnosticStatus7Initializer(CONCAT22(uVar1,uVar2));
  diagnosticStatusDefaultSetter();
  return;
}



//
// Function: initMultiSystemParameters @ 0x0002b4fe
//

void initMultiSystemParameters(void)

{
  diagnosticTablePointerSetup();
  epsDiagnosticVariablesInit();
  fuelDemandScaleFactorCalculator();
  return;
}



//
// Function: addressRangeValidator @ 0x0002b544
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 addressRangeValidator(uint param_1,uint param_2)

{
  undefined3 uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar2 = param_2 >> 0x10;
  uVar4 = (param_1 + uVar2) - 1;
  if (uVar4 < param_1) {
    return 9;
  }
  puVar5 = &DAT_0002b512;
  bVar3 = 0;
  while ((param_1 < *puVar5 || (puVar5[1] < uVar4))) {
    uVar2 = 0;
    puVar5 = (uint *)((int)puVar5 + 10);
    bVar3 = bVar3 + 1;
    if (4 < bVar3) {
      return 9;
    }
  }
  uVar1 = (undefined3)(uVar2 >> 8);
  if (_DAT_0080d3f4 == 1) {
    return CONCAT31(uVar1,*(undefined1 *)(puVar5 + 2));
  }
  return CONCAT31(uVar1,*(undefined1 *)((int)puVar5 + 9));
}



//
// Function: FUN_0002b5aa @ 0x0002b5aa
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b5aa(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  
  if (DAT_00807cf7 == '\0') {
    _DAT_00808ec2 = &LAB_00015946;
    _DAT_00fffe12 = _DAT_00fffe12 & 0xfff0 | 0xc;
    _DAT_00ffff04 = _DAT_00807cd6 / 6;
    _DAT_00ffff02 = 0xe;
    _DAT_00ffff00 = 0xb;
    _DAT_00fffe16 = _DAT_00fffe16 & 0xfffc | 1;
    _DAT_00fffe1a = _DAT_00fffe1a & 0xfffc | 1;
    _DAT_00fffe1e = _DAT_00fffe1e & 0xfffc | 2;
    _DAT_00fffe0a = _DAT_00fffe0a & 0xfffe | 1;
    _DAT_00fffe20 = _DAT_00fffe20 & 0xfffe;
    return;
  }
  if (DAT_00807cf7 != '\x01') {
    return;
  }
  DAT_0080d49e = DAT_00808a78 + -1;
  iVar1 = 0;
  iVar2 = 0;
  uVar3 = (uint)CPMXFLTP._0_1_;
  piVar4 = (int *)&DAT_0080d4a8;
  do {
    *piVar4 = iVar2 / 6;
    iVar2 = uVar3 * 0x10000 + iVar2;
    iVar1 = iVar1 + 1;
    piVar4 = piVar4 + 1;
  } while (iVar1 < 6);
  _DAT_0080d4a4 = (uint)CPMXFLTP._0_1_ << 0x10;
  FUN_0002b880();
  return;
}



//
// Function: FUN_0002b6c2 @ 0x0002b6c2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b6c2(void)

{
  if (DAT_00807cf7 == '\0') {
    _DAT_00fffe20 = _DAT_00fffe20 & 0xfffe;
    _DAT_00fffe12 = _DAT_00fffe12 & 0xfff0 | 0xc;
    _DAT_00ffff04 = 1;
    _DAT_00ffff02 = 0xe;
    _DAT_00ffff00 = 0xb;
    _DAT_00fffe16 = _DAT_00fffe16 & 0xfffc | 1;
    _DAT_00fffe1a = _DAT_00fffe1a & 0xfffc | 1;
    _DAT_00fffe0a = _DAT_00fffe0a & 0xfffe | 1;
    _DAT_00fffe1e = _DAT_00fffe1e & 0xfffc | 2;
  }
  return;
}



//
// Function: FUN_0002b744 @ 0x0002b744
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b744(void)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  
  DAT_0080d49e = DAT_00808a78 - 1U;
  iVar1 = _DAT_0080d4a4 +
          _DAT_00808a7a +
          _AAPRSNST + *(int *)(&DAT_0080d4a8 + (short)(ushort)(byte)(DAT_00808a78 - 1U) * 4) + 0x100
  ;
  uVar3 = (iVar1 >> 0x10 & 0xffffU) % (DAT_00807d02 + 2);
  _DAT_00ffff38 = (ushort)uVar3;
  uVar2 = (ushort)(iVar1 >> 1) & 0x7f00;
  if (uVar3 == DAT_00807d02 + 1) {
    _DAT_00ffff38 = _DAT_00ffff38 - 1 | uVar2 | 0x8000;
  }
  else {
    _DAT_00ffff38 = _DAT_00ffff38 | uVar2;
  }
  uVar3 = (_DAT_00808a7e + iVar1 >> 0x10 & 0xffffU) % (DAT_00807d02 + 2);
  _DAT_00ffff3a = (ushort)uVar3;
  uVar2 = (ushort)(_DAT_00808a7e + iVar1 >> 1) & 0x7f00;
  if (DAT_00807d02 + 1 == uVar3) {
    _DAT_00ffff3a = _DAT_00ffff3a - 1 | uVar2 | 0x8000;
  }
  else {
    _DAT_00ffff3a = _DAT_00ffff3a | uVar2;
  }
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfff7;
  _DAT_00fffe12 = _DAT_00fffe12 & 0xfff | 0x8000;
  _DAT_00ffff30 = 0x880;
  _DAT_00fffe16 = _DAT_00fffe16 & 0xff3f;
  _DAT_00fffe1a = _DAT_00fffe1a & 0xff3f | 0x80;
  _DAT_00fffe1e = _DAT_00fffe1e & 0xff3f | 0x40;
  _DAT_00fffe0a = _DAT_00fffe0a & 0xfff7 | 8;
  return;
}



//
// Function: FUN_0002b880 @ 0x0002b880
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b880(void)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  
  iVar1 = _DAT_0080d4a4 +
          _DAT_00808a7a + _AAPRSNST + *(int *)(&DAT_0080d4a8 + (short)(ushort)DAT_0080d49e * 4) +
          0x100;
  uVar3 = (iVar1 >> 0x10 & 0xffffU) % (DAT_00807d02 + 2);
  _DAT_00ffff38 = (ushort)uVar3;
  uVar2 = (ushort)(iVar1 >> 1) & 0x7f00;
  if (uVar3 == DAT_00807d02 + 1) {
    _DAT_00ffff38 = _DAT_00ffff38 - 1 | uVar2 | 0x8000;
  }
  else {
    _DAT_00ffff38 = _DAT_00ffff38 | uVar2;
  }
  uVar3 = (_DAT_00808a7e + iVar1 >> 0x10 & 0xffffU) % (DAT_00807d02 + 2);
  _DAT_00ffff3a = (ushort)uVar3;
  uVar2 = (ushort)(_DAT_00808a7e + iVar1 >> 1) & 0x7f00;
  if (DAT_00807d02 + 1 == uVar3) {
    _DAT_00ffff3a = _DAT_00ffff3a - 1 | uVar2 | 0x8000;
  }
  else {
    _DAT_00ffff3a = _DAT_00ffff3a | uVar2;
  }
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfff7;
  _DAT_00fffe12 = _DAT_00fffe12 & 0xfff | 0x8000;
  _DAT_00ffff30 = 0x880;
  _DAT_00fffe16 = _DAT_00fffe16 & 0xff3f;
  _DAT_00fffe1a = _DAT_00fffe1a & 0xff3f | 0x80;
  _DAT_00fffe1e = _DAT_00fffe1e & 0xff3f | 0x40;
  _DAT_00808ece = FUN_0002ba56;
  _DAT_00fffe0a = _DAT_00fffe0a & 0xfff7 | 8;
  return;
}



//
// Function: FUN_0002b9b8 @ 0x0002b9b8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b9b8(void)

{
  if (DAT_00807cf7 == '\0') {
    _DAT_00ffff04 = _DAT_00807cd6 / 6;
    _DAT_00fffe0a = _DAT_00fffe0a & 0xfff7;
    _DAT_00fffe20 = _DAT_00fffe20 & 0xfff7;
    _DAT_00fffe12 = _DAT_00fffe12 & 0xfff | 0xa000;
    _DAT_00ffff34 = 0;
    _DAT_00ffff38 = 0x19b;
    _DAT_00ffff30 = 0x8e;
    _DAT_00fffe16 = _DAT_00fffe16 & 0xff3f;
    _DAT_00fffe1a = _DAT_00fffe1a & 0xff3f | 0x80;
    _DAT_00fffe1e = _DAT_00fffe1e & 0xff3f | 0x40;
  }
  if ((DAT_0080c79b != '\0') && (DAT_00807cf7 == '\x01')) {
    FUN_0002b744();
  }
  return;
}



//
// Function: FUN_0002ba56 @ 0x0002ba56
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0002ba56(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  uint uVar1;
  
  if (DAT_0080c7b2 == '\x01') {
    switch(DAT_0080d49e) {
    case 0:
    case 4:
    case 5:
      if (DAT_0080c7b5 == '\0') {
        DAT_0080d49e = (byte)((DAT_0080d49e + 3) % 6);
      }
      break;
    case 1:
    case 2:
    case 3:
      if (DAT_0080c7b5 != '\0') {
        DAT_0080d49e = (byte)((DAT_0080d49e + 3) % 6);
      }
    }
  }
  uVar1 = (DAT_0080d49e + 1) % 6;
  DAT_0080d49e = (byte)uVar1;
  DAT_00809af1 = (char)((DAT_00808a79 + uVar1) % 6) + '\x01';
  FUN_0002b880();
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfff7;
  return CONCAT44(in_D0,in_D1);
}



//
// Function: delayWithWatchdogService @ 0x0002baf0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void delayWithWatchdogService(undefined4 param_1)

{
  while (param_1._0_2_ != 0) {
    DAT_00fffa27 = 0xaa;
    DAT_00ffd00f = 0xaa;
  }
  return;
}



//
// Function: FUN_0002bb2e @ 0x0002bb2e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002bb2e(undefined4 param_1)

{
  while (param_1._0_2_ != 0) {
    DAT_00fffa27 = 0xaa;
    DAT_00ffd00f = 0xaa;
  }
  return;
}



//
// Function: engineDataTrendingSlowCycle40Coordinator @ 0x0002bb6c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engineDataTrendingSlowCycle40Coordinator(void)

{
  _DAT_008031f6 = 2;
  _DAT_008031f8 = 0x808a86;
  _DAT_008031fc = _DAT_008091ea;
  _DAT_008031fe = 0x808a9c;
  if (_DAT_00808a84 < fuel_demand_state_t_0080c9a4.command) {
    _DAT_0080d4c0 = 0;
    return;
  }
  _DAT_008031f4 = lookupTableInterpolation((short *)&DAT_008031f6);
  return;
}



//
// Function: FUN_0002bbac @ 0x0002bbac
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002bbac(void)

{
  short *unaff_A2;
  
  _DAT_008031f4 = lookupTableInterpolation(unaff_A2);
  return;
}



//
// Function: fuelDemandBasedParameterCalculator @ 0x0002bbc0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelDemandBasedParameterCalculator(void)

{
  if (_DAT_00808a84 < fuel_demand_state_t_0080c9a4.command) {
    _DAT_0080d4c0 = 0;
    return;
  }
  _DAT_0080d4c0 = circular_buffer_t_0080c3fc.data_buffer_8 / _DAT_00808a82 + _DAT_008031f4 + -0xc4;
  if (_DAT_0080d4c0 < 0) {
    _DAT_0080d4c0 = 0;
  }
  return;
}



//
// Function: FUN_0002bc06 @ 0x0002bc06
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002bc06(void)

{
  _DAT_0080d4c2 = fuel_demand_state_t_0080c9a4.limit_minimum;
  if (fuel_demand_state_t_0080c9a4.limit_minimum < _DAT_0080d4c0) {
    fuel_demand_state_t_0080c9a4.limit_minimum = _DAT_0080d4c0;
    fuel_demand_state_t_0080c9a4.demand_source_id = 1;
  }
  return;
}



//
// Function: vp44_rpm_derate_monitor @ 0x0002bc2a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort vp44_rpm_derate_monitor(void)

{
  ushort uVar1;
  
  uVar1 = _DAT_008035ec & 0x80;
  if ((((_DAT_008035ec & 0x80) != 0) && (uVar1 = DAT_0080bdc7 & 2, (DAT_0080bdc7 & 2) == 0)) &&
     (uVar1 = _DAT_00809d5a, _DAT_00809d5a <= _DAT_0080707e)) {
    _DAT_00809d5a = _DAT_0080707e;
    _DAT_00809d58 = 0;
  }
  return uVar1;
}



//
// Function: diagnostic_protection_coordinator @ 0x0002bc62
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnostic_protection_coordinator(void)

{
  FUN_0002d96a();
  FUN_0002da0e();
  FUN_0002db10();
  if (((diagnostic_state_buffer_t_00809654.diagnostic_mode == 7) ||
      (diagnostic_state_buffer_t_00809654.diagnostic_mode == 8)) ||
     (diagnostic_state_buffer_t_00809654.diagnostic_mode == 9)) {
    _DAT_00803206 = diagnostic_state_buffer_t_00809654.diagnostic_mode;
  }
  switch(diagnostic_state_buffer_t_00809654.diagnostic_mode) {
  case 9:
    if ((_DAT_0080969a == 0) ||
       ((((fuel_demand_state_t_0080c9a4.command < _DAT_0080d182 && (_DAT_0080d182 < _DAT_00809696))
         && ((_DAT_0080d182 < _DAT_00809694 && (_DAT_00809d4c != 0)))) ||
        (((_DAT_0080d184 == 2 || (_DAT_0080d184 == 1)) || (_DAT_0080d184 == 5)))))) {
      _DAT_00809652 = _DAT_0080d182;
      diagnostic_state_buffer_t_00809654.diagnostic_mode = _DAT_0080d184;
      return;
    }
    if ((circular_buffer_t_0080c3fc.data_buffer_8 <= _DAT_0080d092) &&
       ((uint)_DAT_00803820 + (uint)_DAT_0080969c < (uint)_DAT_008096f8)) {
      diagnostic_state_buffer_t_00809654.diagnostic_mode = 0xb;
      timing_mode_control_t_0080965a.protection_counter_2 = 1;
      governorPidFuelCalculator();
    }
    if ((((_DAT_00809696 == _DAT_00809698) &&
         (((fuel_demand_state_t_0080c9a4.command <= _DAT_0080d182 && (0xc < _DAT_00809d4c)) ||
          (_DAT_0080973c <= _DAT_0080969c)))) || (_DAT_00809696 < _DAT_00809698)) &&
       ((_DAT_00809696 < _DAT_00809694 && (_DAT_00809696 < _DAT_00809652)))) {
      diagnostic_state_buffer_t_00809654.diagnostic_mode = 10;
      FUN_0002d210();
      return;
    }
    if ((((_DAT_00809694 < _DAT_00809652) || (_DAT_00809694 <= _DAT_0080d182)) &&
        (_DAT_00809694 < _DAT_00809696)) && (_DAT_00809694 < _DAT_00809698)) {
      diagnostic_state_buffer_t_00809654.diagnostic_mode = 0xc;
      return;
    }
    break;
  case 10:
    if (((((circular_buffer_t_0080c3fc.data_buffer_8 < 8000) || (_DAT_0080d184 == 2)) ||
         (_DAT_0080d184 == 1)) || (_DAT_008096aa != 0)) ||
       ((_DAT_0080d182 < fuel_demand_state_t_0080c9a4.command &&
        (((_DAT_0080969a == 0 || (_DAT_00803206 == 7)) ||
         ((_DAT_00803206 == 8 || (_DAT_0080d184 == 5)))))))) {
      _DAT_00809652 = _DAT_0080d182;
      diagnostic_state_buffer_t_00809654.diagnostic_mode = _DAT_0080d184;
      return;
    }
    if ((_DAT_00809694 < _DAT_00809652) && (_DAT_00809694 <= _DAT_00809696)) {
      diagnostic_state_buffer_t_00809654.diagnostic_mode = 0xc;
      return;
    }
    if ((((((_DAT_0080969a != 0) && (_DAT_00803206 == 9)) &&
          (_DAT_0080d182 < fuel_demand_state_t_0080c9a4.command)) &&
         ((_DAT_00809698 < _DAT_00809696 ||
          ((_DAT_00809698 == _DAT_00809696 && (_DAT_0080969c < _DAT_0080973c)))))) &&
        (_DAT_00809698 < _DAT_00809694)) && (_DAT_00809698 < _DAT_00809652)) {
      diagnostic_state_buffer_t_00809654.diagnostic_mode = 9;
      FUN_0002d210();
      return;
    }
    break;
  case 0xb:
    if ((((uint)_DAT_0080d182 <= _DAT_00809652 + 0xe) &&
        (((uint)circular_buffer_t_0080c3fc.data_buffer_8 <=
          (uint)_DAT_00807098 + (uint)_DAT_0080d092 || (_DAT_00809d4c != 0)))) ||
       (((_DAT_0080c99c != 0 ||
         ((_DAT_00809d4c == 0 &&
          (((_DAT_0080d184 == 7 || (_DAT_0080d184 == 8)) && (_DAT_0080969a == 0)))))) ||
        ((fuel_arbitrator_diag_t_0080cff8.rpm_target == 3 &&
         (fuel_arbitrator_diag_t_0080cff8.prev_state_pointer._1_2_ <= _DAT_00809652)))))) {
      if ((_DAT_0080969a != 0) &&
         ((((uint)_DAT_008096f8 < (uint)_DAT_00803820 + (uint)_DAT_0080969c ||
           ((uint)_DAT_00807098 + (uint)_DAT_0080d092 <
            (uint)circular_buffer_t_0080c3fc.data_buffer_8)) &&
          ((_DAT_0080c99c == 0 &&
           ((fuel_arbitrator_diag_t_0080cff8.rpm_target != 3 ||
            (_DAT_00809652 < fuel_arbitrator_diag_t_0080cff8.prev_state_pointer._1_2_)))))))) {
        diagnostic_state_buffer_t_00809654.diagnostic_mode = 9;
        FUN_0002d210();
      }
      _DAT_00803202 = 0;
      return;
    }
    _DAT_00803202 = _DAT_00803202 + 1;
    if (_DAT_00806e1e == 0) {
      _DAT_00809652 = _DAT_0080d182;
      diagnostic_state_buffer_t_00809654.diagnostic_mode = _DAT_0080d184;
      _DAT_00803202 = 0;
      return;
    }
    if (_DAT_00803202 == _DAT_00806e1e) {
      _DAT_00809652 = _DAT_0080d182;
      diagnostic_state_buffer_t_00809654.diagnostic_mode = _DAT_0080d184;
      _DAT_00803202 = 0;
      return;
    }
    break;
  case 0xc:
    if ((_DAT_0080d182 < _DAT_00809652) &&
       (((_DAT_0080969a == 0 || (_DAT_0080d184 == 2)) ||
        (((_DAT_0080d184 == 1 || ((_DAT_0080d184 == 5 || (_DAT_00803206 == 7)))) ||
         (_DAT_00803206 == 8)))))) {
      _DAT_00803204 = _DAT_00803204 + 1;
      if (_DAT_00806e1c == 0) {
        _DAT_00809652 = _DAT_0080d182;
        diagnostic_state_buffer_t_00809654.diagnostic_mode = _DAT_0080d184;
        _DAT_00803204 = 0;
        return;
      }
      if (_DAT_00803204 == _DAT_00806e1c) {
        _DAT_00809652 = _DAT_0080d182;
        diagnostic_state_buffer_t_00809654.diagnostic_mode = _DAT_0080d184;
        _DAT_00803204 = 0;
        return;
      }
    }
    else {
      _DAT_00803204 = 0;
      if ((_DAT_00809696 < _DAT_00809652) && (_DAT_00809696 < _DAT_00809694)) {
        diagnostic_state_buffer_t_00809654.diagnostic_mode = 10;
        FUN_0002d210();
        return;
      }
      if ((((_DAT_0080d182 <= fuel_demand_state_t_0080c9a4.command) && (_DAT_00803206 == 9)) &&
          (_DAT_00809698 < _DAT_00809652)) &&
         ((_DAT_00809698 < _DAT_00809694 && (_DAT_0080969a != 0)))) {
        diagnostic_state_buffer_t_00809654.diagnostic_mode = 9;
        FUN_0002d210();
        return;
      }
    }
    break;
  default:
    if (((circular_buffer_t_0080c3fc.data_buffer_8 <= _DAT_0080d092) &&
        (_DAT_00809652 < fuel_governor_state_t_0080d05c.out_cmd)) ||
       ((((uint)circular_buffer_t_0080c3fc.data_buffer_8 <=
          (uint)_DAT_00806e1a + (uint)_DAT_0080d092 &&
         ((_DAT_00809d4c == 0 && (_DAT_00809652 < fuel_governor_state_t_0080d05c.out_cmd)))) &&
        ((_DAT_0080d184 == 7 || (_DAT_0080d184 == 8)))))) {
      diagnostic_state_buffer_t_00809654.diagnostic_mode = 0xb;
      timing_mode_control_t_0080965a.protection_counter_2 = 1;
      governorPidFuelCalculator();
      return;
    }
    if ((_DAT_00809694 <= _DAT_0080d182) && (_DAT_00809694 <= _DAT_00809696)) {
      diagnostic_state_buffer_t_00809654.diagnostic_mode = 0xc;
      fuelRpmDeviationCalculator();
      return;
    }
    if ((((_DAT_00809696 < _DAT_0080d182) && (_DAT_00809696 <= _DAT_00809694)) &&
        (7999 < circular_buffer_t_0080c3fc.data_buffer_8)) &&
       (((_DAT_008096aa == 0 && (_DAT_0080d184 != 2)) && (_DAT_0080d184 != 1)))) {
      diagnostic_state_buffer_t_00809654.diagnostic_mode = 10;
      FUN_0002d210();
      return;
    }
    if (((_DAT_0080969a != 0) && (_DAT_0080d182 <= _DAT_00809698)) &&
       ((_DAT_0080d182 <= fuel_demand_state_t_0080c9a4.command &&
        (((_DAT_0080d184 != 2 && (_DAT_0080d184 != 1)) && (_DAT_0080d184 != 5)))))) {
      diagnostic_state_buffer_t_00809654.diagnostic_mode = 9;
      FUN_0002d210();
      return;
    }
    _DAT_00809652 = _DAT_0080d182;
    diagnostic_state_buffer_t_00809654.diagnostic_mode = _DAT_0080d184;
  }
  return;
}



//
// Function: initDiagnosticModeSystem @ 0x0002c240
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initDiagnosticModeSystem(void)

{
  diagnostic_state_buffer_t_00809654.diagnostic_mode = 0xb;
  _DAT_00803206 = 7;
  return;
}



//
// Function: FUN_0002c252 @ 0x0002c252
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0002c252(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (_DAT_0080c7ca < _DAT_00807f28) {
    _DAT_00809692 = _DAT_0080708c;
  }
  else {
    _DAT_00809692 = _DAT_00807096 + _DAT_00809692;
    if (_DAT_0080708a < _DAT_00809692) {
      _DAT_00809692 = _DAT_0080708a;
    }
  }
  if (_DAT_0080969a == 0) {
    if (_DAT_0080968c < _DAT_00807080) {
      _DAT_0080968c = _DAT_0080968c + 1;
    }
  }
  else {
    _DAT_0080968c = 0;
  }
  if (_DAT_00809690 < _DAT_008096a6) {
    _DAT_00809690 = coreTableInterpolation();
  }
  if ((_DAT_00807f26 <= _DAT_0080c7c8) && (_DAT_00807080 <= _DAT_0080968c)) {
    _DAT_00809690 = _DAT_008096a6;
  }
  if ((_DAT_00803210 == 2) && (_DAT_0080c7c6 == 0)) {
    _DAT_00809690 = _DAT_008096a6;
  }
  _DAT_00803210 = _DAT_0080c7c6;
  if (_DAT_0080969a == 0) {
    if (_DAT_00803746 < _DAT_00809690) {
      _DAT_00809690 = _DAT_00803746;
    }
  }
  else if (_DAT_0080969c < _DAT_00809690) {
    _DAT_00809690 = _DAT_0080969c;
  }
  iVar2 = rpmFuelCalculation((uint)_DAT_00803746 - (uint)_DAT_00809690,(uint)_DAT_00807082,0x80);
  uVar4 = (uint)_DAT_0080708e - iVar2;
  if ((int)(uint)_DAT_0080708e < (int)uVar4) {
    uVar4 = (uint)_DAT_0080708e;
  }
  else if ((int)uVar4 < (int)(uint)_DAT_00807092) {
    uVar4 = (uint)_DAT_00807092;
  }
  _DAT_0080968e = (short)uVar4;
  sVar1 = _DAT_0080c7c6 >> 0xf;
  if (_DAT_0080c7c6 == 0) {
    if (((((_DAT_008035ec & 0x20) == 0) || (_DAT_008096a8 < _DAT_00807088)) ||
        (_DAT_00807086 < _DAT_008096a8)) || (_DAT_00809692 < _DAT_008096a6)) {
      _DAT_0080c7cc = 0;
    }
    else {
      _DAT_0080c7cc = 1;
    }
    uVar3 = (uint)_DAT_008096a6;
    if (((_DAT_00807094 <= _DAT_008096a6) &&
        ((uVar3 = (uint)_DAT_00809690 - (uVar4 & 0xffff), (int)(uint)_DAT_008096a6 < (int)uVar3 ||
         (uVar3 = CONCAT22((short)(uVar3 >> 0x10),_DAT_0080c7c0), CKEXFLOF <= _DAT_0080c7c0)))) &&
       (uVar3 = CONCAT22((short)(uVar3 >> 0x10),_DAT_008096a8), _DAT_008096a8 <= _DAT_00807090)) {
      _DAT_0080c7ce = 1;
      return uVar3;
    }
    _DAT_0080c7ce = 0;
    return uVar3;
  }
  if (_DAT_0080c7c6 == 1) {
    uVar4 = _DAT_008035ec & 0x20;
    if (((_DAT_008035ec & 0x20) != 0) &&
       (((uVar4 = (uint)_DAT_008096a8, _DAT_008096a8 < _DAT_00807088 ||
         (uVar4 = (uint)_DAT_008096a8, _DAT_00807086 < _DAT_008096a8)) ||
        (uVar4 = (uint)_DAT_008096a6, _DAT_00809692 < _DAT_008096a6)))) {
      _DAT_0080c7cc = 1;
      return uVar4;
    }
    _DAT_0080c7cc = 0;
    return uVar4;
  }
  if (_DAT_0080c7c6 != 2) {
    return (int)_DAT_0080c7c6;
  }
  uVar4 = CONCAT22(sVar1,_DAT_008096a6);
  if ((((_DAT_008096a6 < _DAT_00809690) &&
       (uVar4 = CONCAT22(sVar1,_DAT_008096a6), _DAT_00807094 <= _DAT_008096a6)) &&
      (uVar4 = CONCAT22(sVar1,_DAT_008096a8), _DAT_008096a8 <= _DAT_00807090)) &&
     ((uVar4 = CONCAT22(sVar1,_DAT_0080c7c8), _DAT_0080c7c8 < _DAT_00807f26 ||
      (uVar4 = CONCAT22(sVar1,_DAT_0080968c), _DAT_0080968c < _DAT_00807080)))) {
    _DAT_0080c7ce = 0;
    return uVar4;
  }
  _DAT_0080c7ce = 1;
  return uVar4;
}



//
// Function: FUN_0002c4de @ 0x0002c4de
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002c4de(void)

{
  _DAT_0080320c = 0;
  _DAT_00803208 = 0x807084;
  return;
}



//
// Function: diagnosticFlagResetHandler @ 0x0002c4f0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort diagnosticFlagResetHandler(void)

{
  if ((engine_control_flags_t_008035d6.fuel_temp_control & 0x8000) == 0) {
    _DAT_008096b2 = 0;
  }
  return engine_control_flags_t_008035d6.fuel_temp_control & 0x8000;
}



//
// Function: FUN_0002c506 @ 0x0002c506
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0002c506(void)

{
  if ((engine_control_flags_t_008035d6.fuel_temp_control & 0x8000) != 0) {
    _DAT_008096b2 = 0;
  }
  return engine_control_flags_t_008035d6.fuel_temp_control & 0x8000;
}



//
// Function: FUN_0002c51a @ 0x0002c51a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002c51a(undefined4 param_1)

{
  ushort uVar1;
  short sVar2;
  short sStack_6;
  
  _DAT_00803218 = _DAT_0080971c;
  _DAT_008096c6 = lookupTableInterpolation((short *)&DAT_00803212);
  if (diagnostic_state_buffer_t_00809654.diagnostic_mode == 9) {
    if ((((_DAT_008096b6 == 1) || (_DAT_008096b6 == 3)) || (_DAT_008096b6 == 2)) ||
       (_DAT_008096b6 == 4)) {
      _DAT_008096b8 = 0;
    }
    else {
      if (_DAT_0080969c < _DAT_008096f8) {
        uVar1 = _DAT_008096f8 - _DAT_0080969c;
      }
      else {
        uVar1 = _DAT_0080969c - _DAT_008096f8;
      }
      if (((uVar1 < _DAT_008070a0) && (param_1._0_2_ <= _DAT_008096e0)) &&
         (_DAT_0080709c <= param_1._0_2_)) {
        _DAT_008096b8 = 1;
      }
    }
  }
  if ((_DAT_008096b8 == 0) && (diagnostic_state_buffer_t_00809654.diagnostic_mode == 9)) {
    _DAT_008096c4 = 0;
  }
  else if (_DAT_008096e0 < param_1._0_2_) {
    uVar1 = _DAT_008096de;
    if (diagnostic_state_buffer_t_00809654.diagnostic_mode == 9) {
      uVar1 = _DAT_008096d2;
    }
    sStack_6 = (short)((uint)uVar1 * ((uint)param_1._0_2_ - (uint)_DAT_008096e0) >> 10);
    if (sStack_6 < 0xa01) {
      _DAT_008096c4 = sStack_6;
    }
    else {
      _DAT_008096c4 = 0xa00;
    }
  }
  else if (param_1._0_2_ < _DAT_0080709c) {
    sVar2 = _DAT_008096d8;
    if (diagnostic_state_buffer_t_00809654.diagnostic_mode == 9) {
      sVar2 = _DAT_008096be;
    }
    sStack_6 = (short)((int)sVar2 * ((int)(short)param_1._0_2_ - (int)(short)_DAT_0080709c) >> 10);
    if (sStack_6 < -0xa00) {
      _DAT_008096c4 = -0xa00;
    }
    else {
      _DAT_008096c4 = sStack_6;
    }
  }
  else {
    _DAT_008096c4 = 0;
  }
  if (_DAT_008096ec < 1) {
    if (-(int)_DAT_008096ec == (int)_DAT_008070b4 + (int)_DAT_008070b2 ||
        -((int)_DAT_008070b4 + (int)_DAT_008070b2) < (int)_DAT_008096ec) {
      if (-((int)_DAT_008070b2 - (int)_DAT_008070b4) < (int)_DAT_008096ec) {
        _DAT_0080321e = 0;
      }
    }
    else {
      _DAT_0080321e = 1;
    }
  }
  else if ((int)_DAT_008070b4 + (int)_DAT_008070b2 < (int)_DAT_008096ec) {
    _DAT_0080321e = 1;
  }
  else if ((int)_DAT_008096ec < (int)_DAT_008070b2 - (int)_DAT_008070b4) {
    _DAT_0080321e = 0;
  }
  if (_DAT_0080321e != 0) {
    if (_DAT_00803220 == 0) {
      if ((uint)fuel_demand_state_t_0080c9a4.command < _DAT_0080709c + 0x3a) {
        _DAT_0080321e = 0;
      }
    }
    else if (fuel_demand_state_t_0080c9a4.command < _DAT_0080709c) {
      _DAT_0080321e = 0;
    }
  }
  if (_DAT_0080321e == 0) {
    _DAT_008096e2 = (undefined2 *)&DAT_008070a2;
  }
  else {
    _DAT_008096e2 = (undefined2 *)&DAT_008070b6;
  }
  _DAT_008096cc = *_DAT_008096e2;
  _DAT_008096c8 = _DAT_008096e2[1];
  _DAT_008096c2 = _DAT_008096e2[2];
  _DAT_008096ca = _DAT_008096e2[3];
  if (_DAT_0080321e != _DAT_00803220) {
    _DAT_008096c0 = 1;
  }
  _DAT_00803220 = _DAT_0080321e;
  return;
}



//
// Function: update_engine_protection_thresholds @ 0x0002c7e0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void update_engine_protection_thresholds(void)

{
  _DAT_008096d4 = _DAT_008096d8;
  _DAT_008096da = _DAT_008096de;
  if ((_DAT_008096b8 == 1) && (_DAT_0080969a == 1)) {
    _DAT_008096ce = _DAT_008096d2;
    _DAT_008096ba = _DAT_008096be;
  }
  else {
    _DAT_008096ce = 0;
    _DAT_008096ba = 0;
  }
  if (_DAT_0080c7c6 == 0) {
    _DAT_008096e0 = _DAT_008070ac;
  }
  else if (_DAT_0080c7c6 == 2) {
    _DAT_008096e0 = _DAT_008070ae;
  }
  else if (_DAT_0080c7c6 == 1) {
    _DAT_008096e0 = _DAT_0080709e;
  }
  _DAT_008096dc = _DAT_008096e0;
  _DAT_008096d0 = _DAT_008096e0;
  return;
}



//
// Function: FUN_0002c870 @ 0x0002c870
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0002c870(undefined4 param_1)

{
  uint uVar1;
  undefined *puVar2;
  ushort local_8;
  ushort uStack_6;
  
  uVar1 = (((uint)_DAT_0080385c * (uint)_DAT_00803828) / 0x3c & 0xffff) * (uint)_DAT_0080374a;
  local_8 = (ushort)(uVar1 >> 0x17);
  if (local_8 == 0) {
    puVar2 = (undefined *)((uVar1 >> 7 & 0xffff) * (uint)param_1._0_2_);
    local_8 = (ushort)((uint)puVar2 >> 0x10);
    uStack_6 = local_8;
    if (local_8 < 0x1f41) {
      uStack_6 = 8000;
    }
  }
  else {
    puVar2 = (undefined *)((uint)param_1._0_2_ * (uVar1 >> 0xb & 0xffff) >> 0xc);
    if (puVar2 < &DAT_00008ca0) {
      uStack_6 = (ushort)puVar2;
      if (uStack_6 < 0x1f41) {
        uStack_6 = 8000;
      }
    }
    else {
      uStack_6 = 36000;
    }
  }
  return CONCAT22((short)((uint)puVar2 >> 0x10),uStack_6);
}



//
// Function: FUN_0002c8fe @ 0x0002c8fe
// ERROR: Failed to decompile
//

//
// Function: FUN_0002c968 @ 0x0002c968
// ERROR: Failed to decompile
//

//
// Function: engine_protection_init @ 0x0002c99a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engine_protection_init(void)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 unaff_D2;
  short sVar3;
  undefined2 local_18;
  undefined4 local_16;
  undefined2 local_12;
  undefined2 local_10;
  undefined4 local_e;
  undefined2 local_a;
  undefined4 local_8;
  
  _DAT_00803212 = 2;
  _DAT_00803214 = 0x8070be;
  _DAT_0080321a = 0x8070cc;
  _DAT_008096c0 = 0;
  _DAT_008096c4 = 0;
  _DAT_008096b8 = 0;
  local_16 = 0x808002;
  local_18 = 2;
  local_a = 400;
  local_e = 0x808028;
  local_10 = 2;
  local_8 = 0x808032;
  uVar2 = FUN_0002c870(CONCAT22(_DAT_00803746 - _DAT_00803822,(short)((uint)unaff_D2 >> 0x10)));
  local_12 = (undefined2)uVar2;
  sVar3 = _DAT_00803822;
  _DAT_008096d2 = FUN_0002c8fe();
  uVar2 = FUN_0002c870(CONCAT22(_DAT_00803748 - _DAT_00803826,sVar3));
  local_12 = (undefined2)uVar2;
  _DAT_008096de = FUN_0002c8fe((short)((uint)&local_18 >> 0x10));
  if (_DAT_008070f6 < _DAT_0080709c) {
    uVar1 = _DAT_0080709c - _DAT_008070f6;
    _DAT_008096be = FUN_0002c968();
    _DAT_008096d8 = FUN_0002c968((short)((uint)uVar1 * 0x1164 >> 0x10),uVar1);
  }
  else {
    _DAT_008096be = 0;
    _DAT_008096d8 = 0;
  }
  _DAT_008096dc = _DAT_008070ac;
  _DAT_008096d0 = _DAT_008070ac;
  _DAT_008096d6 = _DAT_0080709c;
  _DAT_008096bc = _DAT_0080709c;
  _DAT_008096ce = 0;
  _DAT_008096ba = 0;
  _DAT_008096d4 = _DAT_008096d8;
  _DAT_008096da = _DAT_008096de;
  _DAT_0080321e = 0;
  _DAT_00803220 = 0;
  return;
}



//
// Function: FUN_0002cb08 @ 0x0002cb08
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0002cb08(void)

{
  int iVar1;
  undefined2 uStack_6;
  
  iVar1 = (uint)_DAT_0080382c * (int)(short)(((int)_DAT_008096ec * (int)_DAT_008096c6) / 1000);
  if (iVar1 < 0x138800) {
    if (iVar1 < -0x1387ff) {
      uStack_6 = 0xd8f0;
    }
    else {
      iVar1 = iVar1 >> 7;
      uStack_6 = (undefined2)iVar1;
    }
  }
  else {
    uStack_6 = 10000;
  }
  return CONCAT22((short)((uint)iVar1 >> 0x10),uStack_6);
}



//
// Function: boost_pressure_control_and_diagnostics @ 0x0002cb6a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void boost_pressure_control_and_diagnostics(void)

{
  bool bVar1;
  ushort uVar2;
  short sVar4;
  int iVar3;
  undefined4 unaff_D2;
  short sVar5;
  short sVar6;
  word wVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  ushort uStack_a;
  int local_8;
  
  uVar9 = (undefined2)((uint)unaff_D2 >> 0x10);
  uVar8 = 0x322a;
  wVar7 = fuel_demand_state_t_0080c9a4.command;
  _DAT_00803228 = coreTableInterpolation(0x80);
  _DAT_00803264 = coreTableInterpolation(0x80,wVar7,uVar8);
  sVar5 = _DAT_00803226;
  _DAT_00803226 = FUN_0003574e();
  uVar2 = _DAT_00803224;
  sVar5 = _DAT_00803226 - sVar5;
  if (sVar5 < 0x67) {
    if (sVar5 < -0x66) {
      sVar5 = -0x66;
    }
  }
  else {
    sVar5 = 0x66;
  }
  if (((_DAT_00807100 < sVar5) || ((int)sVar5 < -(int)_DAT_00807100)) || (_DAT_0080326e == 0)) {
    _DAT_0080326e = _DAT_00807102;
  }
  else {
    if (_DAT_0080326e == _DAT_00807102) {
      _DAT_00803266 = _DAT_00803264;
    }
    if (_DAT_0080326e != 0) {
      _DAT_0080326e = _DAT_0080326e + -1;
    }
  }
  if ((_DAT_0080326e == 0) && (_DAT_0080711c <= _DAT_00803226)) {
    DAT_00803270 = '\x01';
    _DAT_00803262 = _DAT_00803266;
  }
  else if (DAT_00803270 == '\0') {
    _DAT_00803262 = fuel_demand_state_t_0080c9a4.command;
  }
  if ((diagnostic_state_buffer_t_00809654.diagnostic_mode == 9) ||
     (diagnostic_state_buffer_t_00809654.diagnostic_mode == 10)) {
    if (_DAT_008096ee == 1) {
      FUN_0002d210();
    }
    else {
      if (diagnostic_state_buffer_t_00809654.diagnostic_mode == 9) {
        _DAT_00803224 = _DAT_0080969c;
        if (uVar2 < _DAT_0080969c) {
          if ((ushort)(_DAT_008070da + uVar2) < _DAT_0080969c) {
            _DAT_00803224 = _DAT_008070da + uVar2;
          }
        }
        else if ((_DAT_0080969c < uVar2) &&
                ((uint)_DAT_008070dc + (uint)_DAT_0080969c < (uint)uVar2)) {
          _DAT_00803224 = uVar2 - _DAT_008070dc;
        }
        _DAT_008096f6 = _DAT_00803224;
        if (((_DAT_00803256 == 1) && ((DAT_0080bdcc & 2) == 0)) ||
           ((_DAT_00803258 == 1 && ((DAT_0080bdcc & 8) == 0)))) {
          FUN_0002d210();
        }
      }
      else {
        _DAT_008096f6 = _DAT_0080973c;
      }
      _DAT_008096ea = _DAT_008096f6 - _DAT_008096f8;
      if (_DAT_008070f2 < _DAT_008096ea) {
        _DAT_008096ea = _DAT_008070f2;
      }
      else if (_DAT_008096ea < _DAT_008070f4) {
        _DAT_008096ea = _DAT_008070f4;
      }
      FUN_0002c51a(CONCAT22(_DAT_00803228,uVar9));
      if ((int)_DAT_008096ea < _DAT_008096c4 + 0xa00) {
        if (_DAT_008096c4 + -0xa00 < (int)_DAT_008096ea) {
          _DAT_008096ec = _DAT_008096ea - _DAT_008096c4;
        }
        else {
          _DAT_008096ec = -0xa00;
        }
      }
      else {
        _DAT_008096ec = 0xa00;
      }
      FUN_0002cb08();
      sVar4 = FUN_0003566e(0x80);
      if (sVar4 < 12000) {
        if (sVar4 < -12000) {
          sVar4 = -12000;
        }
      }
      else {
        sVar4 = 12000;
      }
      uStack_a = (ushort)((int)sVar5 * (int)_DAT_008096c6 >> 5);
      iVar3 = (uint)_DAT_0080382c * (int)(short)uStack_a;
      sVar6 = _DAT_008070e2;
      if ((iVar3 < _DAT_008070e2 * 0x16) && (sVar6 = _DAT_008070e4, _DAT_008070e4 * 0x16 < iVar3)) {
        sVar6 = (short)(iVar3 / 0x16);
      }
      iVar3 = (int)sVar4 * (int)_DAT_008096cc >> 0xc;
      if (iVar3 < 0x7fff) {
        if (iVar3 < -0x7fff) {
          _DAT_008096f4 = -0x8000;
        }
        else {
          uStack_a = (ushort)iVar3;
          _DAT_008096f4 = uStack_a;
        }
      }
      else {
        _DAT_008096f4 = 0x7fff;
      }
      uStack_a = (ushort)((int)sVar6 * (int)_DAT_008096c2 >> 0xf);
      _DAT_008096e8 = uStack_a;
      local_8 = (int)_DAT_008070f0 *
                ((int)(short)fuel_demand_state_t_0080c9a4.command - (int)(short)_DAT_00803222) * 2;
      if (local_8 < 0x6e66667) {
        if (local_8 < -0x6e66666) {
          local_8 = -0x6e66666;
        }
      }
      else {
        local_8 = 0x6e66666;
      }
      _DAT_008096f0 = local_8._0_2_;
      if (_DAT_008096c0 != 0) {
        _DAT_008096c0 = 0;
        iVar3 = ((int)(short)uStack_a + ((int)(short)_DAT_00803222 - (int)_DAT_008096f4)) -
                (int)_DAT_00803268;
        if ((int)(uint)_DAT_008070ea < iVar3) {
          _DAT_00803252 = _DAT_008070ea;
        }
        else if (iVar3 < (int)(uint)_DAT_008070f6) {
          _DAT_00803252 = _DAT_008070f6;
        }
        else {
          _DAT_00803252 = (ushort)iVar3;
        }
        _DAT_00803252 = (uint)_DAT_00803252 << 0x10;
      }
      local_8 = local_8 + (((int)sVar4 * (int)_DAT_008096c8 * 4 + _DAT_00803252) -
                          ((int)sVar6 * (int)_DAT_008096ca >> 4));
      _DAT_00803252 = (ushort)((uint)local_8 >> 0x10);
      if ((short)_DAT_00803252 < (short)_DAT_008070ea) {
        bVar1 = (short)_DAT_00803252 < (short)_DAT_008070f6;
        _DAT_00803252 = local_8;
        if (bVar1) {
          _DAT_00803252 = (uint)_DAT_008070f6 << 0x10;
        }
      }
      else {
        _DAT_00803252 = (uint)_DAT_008070ea << 0x10;
      }
      _DAT_008096f2 = _DAT_00803252;
      if (_DAT_0080326c == 0) {
        _DAT_00803278 = sVar5 * 0x20 - (short)(((int)_DAT_0080710e * (int)_DAT_008096ec) / 0x19);
        if ((_DAT_0080710a < _DAT_00803278) && (_DAT_008096ec < _DAT_0080710c)) {
          if (_DAT_00803272 == 0) {
            _DAT_00803276 = 1;
          }
          else {
            _DAT_00803276 = 0;
            _DAT_00803272 = _DAT_00803272 + -1;
          }
        }
        else {
          _DAT_00803272 = 4;
          _DAT_00803276 = 0;
        }
        if (_DAT_00803276 != 0) {
          _DAT_00803274 = _DAT_00807104 * sVar5;
          if (_DAT_00803274 < 0x6e6) {
            if (_DAT_00803274 < -0x6e6) {
              _DAT_00803274 = -0x6e6;
            }
          }
          else {
            _DAT_00803274 = 0x6e6;
          }
          _DAT_008096f2 = _DAT_00803252 - _DAT_00803274;
          _DAT_00803252 = _DAT_00803252 + _DAT_00803274 * -0x10000;
          _DAT_0080326c = _DAT_00807106;
          _DAT_00803268 = _DAT_00803274;
          _DAT_00803272 = 4;
        }
      }
      else {
        _DAT_0080326c = _DAT_0080326c + -1;
      }
      if (_DAT_00803268 < 1) {
        if (_DAT_00803268 < 0) {
          if (-(int)_DAT_00807108 < (int)_DAT_00803268) {
            _DAT_00803268 = 0;
          }
          else {
            _DAT_00803268 = _DAT_00807108 + _DAT_00803268;
          }
        }
      }
      else if (_DAT_00803268 < _DAT_00807108) {
        _DAT_00803268 = 0;
      }
      else {
        _DAT_00803268 = _DAT_00803268 - _DAT_00807108;
      }
      iVar3 = (int)_DAT_00803268 +
              (((int)_DAT_008096f2 + (int)_DAT_008096f4) - (int)(short)uStack_a);
      if (iVar3 < 0x2e00) {
        if (iVar3 < -0x24b) {
          _DAT_00803222 = 0xfdb4;
        }
        else {
          uStack_a = (ushort)iVar3;
          _DAT_00803222 = uStack_a;
        }
      }
      else {
        _DAT_00803222 = 0x2e00;
      }
      if ((short)_DAT_00803222 < (short)_DAT_008070ea) {
        if ((short)_DAT_008070ec < (short)_DAT_00803222) {
          _DAT_008096e6 = _DAT_00803222;
        }
        else {
          _DAT_008096e6 = _DAT_008070ec;
        }
      }
      else {
        _DAT_008096e6 = _DAT_008070ea;
      }
      _DAT_00809652 = _DAT_008096e6;
    }
  }
  _DAT_0080326a = diagnostic_state_buffer_t_00809654.diagnostic_mode;
  update_engine_protection_thresholds();
  _DAT_00803256 = (byte)-((DAT_0080bdcc & 2) != 0) & 1;
  _DAT_00803258 = (byte)-((DAT_0080bdcc & 8) != 0) & 1;
  return;
}



//
// Function: FUN_0002d210 @ 0x0002d210
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002d210(void)

{
  undefined4 uVar1;
  short sVar2;
  undefined4 unaff_D2;
  undefined4 local_8;
  
  if (diagnostic_state_buffer_t_00809654.diagnostic_mode == 10) {
    _DAT_008096ea = _DAT_0080973c - _DAT_008096f8;
    if (_DAT_008096ea < _DAT_008070f2) {
      if (_DAT_008096ea < _DAT_008070f4) {
        _DAT_008096ea = _DAT_008070f4;
      }
    }
    else {
      _DAT_008096ea = _DAT_008070f2;
    }
  }
  else {
    _DAT_00803224 = _DAT_008096f8;
    _DAT_008096f6 = _DAT_008096f8;
    _DAT_008096ea = 0;
  }
  _DAT_008096ec = _DAT_008096ea;
  FUN_0002c51a(CONCAT22(_DAT_00803228,(short)((uint)unaff_D2 >> 0x10)));
  if ((int)_DAT_008096ea < _DAT_008096c4 + 0xa00) {
    if (_DAT_008096c4 + -0xa00 < (int)_DAT_008096ea) {
      _DAT_008096ec = _DAT_008096ea - _DAT_008096c4;
    }
    else {
      _DAT_008096ec = -0xa00;
    }
  }
  else {
    _DAT_008096ec = 0xa00;
  }
  uVar1 = FUN_0002cb08();
  sVar2 = (short)uVar1;
  _DAT_0080323a = (int)sVar2 << 0x10;
  _DAT_0080323e = (int)sVar2 << 0x10;
  _DAT_0080324a = (uint)_DAT_008096f8 << 0x10;
  _DAT_0080324e = (uint)_DAT_008096f8 << 0x10;
  _DAT_00803226 = _DAT_008096f8;
  local_8 = (int)sVar2 * (int)_DAT_008096cc >> 0xc;
  if (local_8 < 0x1700) {
    if (local_8 < -0x16ff) {
      local_8 = 0xe900;
    }
  }
  else {
    local_8 = 0x1700;
  }
  if ((_DAT_0080326a == 7) || (_DAT_0080326a == 8)) {
    _DAT_00803252 = _DAT_00803262;
    if (diagnostic_state_buffer_t_00809654.diagnostic_mode == 10) {
      _DAT_00803252 = fuel_demand_state_t_0080c9a4.command - _DAT_008070fa;
    }
    _DAT_00803268 = fuel_demand_state_t_0080c9a4.command - _DAT_00803252;
    _DAT_00803252 = _DAT_00803252 - local_8._2_2_;
  }
  else {
    _DAT_00803268 = 0;
    _DAT_00803252 = fuel_demand_state_t_0080c9a4.command - local_8._2_2_;
  }
  if (_DAT_00803252 < _DAT_008070ea) {
    if (_DAT_00803252 < _DAT_008070f6) {
      _DAT_00803252 = _DAT_008070f6;
    }
  }
  else {
    _DAT_00803252 = _DAT_008070ea;
  }
  _DAT_00803254 = 0;
  _DAT_008096f2 = _DAT_00803252;
  _DAT_00803222 = fuel_demand_state_t_0080c9a4.command;
  _DAT_008096ee = 0;
  _DAT_00803272 = 4;
  return;
}



//
// Function: FUN_0002d3fa @ 0x0002d3fa
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002d3fa(void)

{
  _DAT_008096ee = 0;
  _DAT_00803232 = 0x8070e6;
  _DAT_00803236 = 0x8070e8;
  _DAT_00803242 = 0x8070de;
  _DAT_00803246 = 0x8070e0;
  _DAT_0080322a = 0x8070aa;
  _DAT_0080325a = 0x8070fe;
  return;
}



//
// Function: FUN_0002d43e @ 0x0002d43e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0002d43e(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  ushort uVar4;
  bool bVar5;
  
  bVar5 = (DAT_0080bdcc & 4) != 0;
  if ((DAT_0080327a == '\0') && (bVar5)) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  DAT_0080327a = bVar5;
  bVar5 = (DAT_0080bdcc & 1) != 0;
  if ((DAT_0080327b == '\0') && (bVar5)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  DAT_0080327b = -bVar5 & 1;
  if ((_DAT_0080327c == 4) || (_DAT_008096b4 != 4)) {
    bVar5 = false;
  }
  else {
    bVar5 = true;
  }
  if ((_DAT_0080327c == 3) || (_DAT_008096b4 != 3)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  _DAT_0080327c = _DAT_008096b4;
  if ((bVar5 || bVar2) || (bVar1)) {
    bVar5 = true;
  }
  else {
    bVar5 = false;
  }
  _DAT_008096b6 = 0x100;
  if ((engine_control_flags_t_008035d6.engine_operating_state & 0x40) == 0) {
    _DAT_008096b6 = 0;
    uVar4 = engine_control_flags_t_008035d6.engine_operating_state & 0x40;
  }
  else {
    if ((_DAT_0080971e == 0) || (_DAT_0080711e == 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if ((_DAT_008096b4 == 2) || (_DAT_008096b4 == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    uVar4 = DAT_0080bdcc & 0x10;
    if (((((((DAT_0080bdcc & 0x10) == 0) || (uVar4 = _DAT_008096f8, _DAT_008096f8 < _DAT_00807944))
          || (uVar4 = DAT_0080bdc7 & 4, (DAT_0080bdc7 & 4) != 0)) ||
         ((uVar4 = circular_buffer_t_0080c3fc.current_engine_rpm,
          circular_buffer_t_0080c3fc.current_engine_rpm < _DAT_0080709a ||
          (uVar4 = DAT_0080bdc7 & 8, (DAT_0080bdc7 & 8) != 0)))) || ((bVar2 || (bVar1)))) ||
       ((fuel_arbitrator_diag_t_0080cff8.fuel_limit != 0 &&
        (fuel_arbitrator_diag_t_0080cff8._30_2_ == 1)))) {
      if (_DAT_008096fc == 0) {
        _DAT_008096b6 = 0;
      }
      else {
        _DAT_008096b6 = 8;
      }
    }
    else if (bVar3) {
      if ((_DAT_00809d4c < 0xc) || (diagnostic_state_buffer_t_00809654.diagnostic_mode == 9)) {
        bVar5 = false;
      }
      else {
        bVar5 = true;
      }
      if ((_DAT_0080969a == 0) || (bVar5)) {
        uVar4 = _DAT_008096f8;
        if (_DAT_0080711c <= _DAT_008096f8) {
          _DAT_008096b6 = 1;
        }
      }
      else if (_DAT_0080374c == 0) {
        _DAT_008096b6 = 5;
      }
      else {
        _DAT_008096b6 = 6;
      }
    }
    else if ((DAT_0080bdcc & 8) == 0) {
      if (bVar5) {
        if (_DAT_0080969a == 0) {
          uVar4 = _DAT_008096f8;
          if ((_DAT_0080711c <= _DAT_008096f8) && (_DAT_008096fc != 0)) {
            _DAT_008096b6 = 2;
          }
        }
        else if (_DAT_0080374c == 0) {
          _DAT_008096b6 = 6;
        }
        else {
          _DAT_008096b6 = 5;
        }
      }
      else if (((DAT_0080bdcc & 2) != 0) && (_DAT_0080969a != 0)) {
        _DAT_008096b6 = 4;
      }
    }
    else if (_DAT_0080969a != 0) {
      _DAT_008096b6 = 3;
    }
  }
  if (_DAT_008096b6 == 0x100) {
    if (_DAT_0080969a != 0) {
      _DAT_008096b6 = 7;
      return uVar4;
    }
    if (_DAT_008096fc != 0) {
      _DAT_008096b6 = 8;
      return uVar4;
    }
    _DAT_008096b6 = 0;
  }
  return uVar4;
}



//
// Function: FUN_0002d688 @ 0x0002d688
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002d688(void)

{
  DAT_0080327a = 0;
  DAT_0080327b = 0;
  _DAT_008096b4 = 0;
  _DAT_0080327c = 0;
  return;
}



//
// Function: boostPressureFeedbackController @ 0x0002d6a2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void boostPressureFeedbackController(void)

{
  uint uVar1;
  
  if (_DAT_00803832 != 0) {
    _DAT_008096f8 = _DAT_008096a6;
    return;
  }
  uVar1 = ((uint)circular_buffer_t_0080c3fc.data_buffer_8 << 0x10) /
          ((uint)_DAT_00803830 * (uint)_DAT_0080971c >> 10) >> 2;
  if (uVar1 < 0x8001) {
    _DAT_008096f8 = (ushort)uVar1;
  }
  else {
    _DAT_008096f8 = 0x8000;
  }
  if (_DAT_0080327e < _DAT_008096f8) {
    if ((int)(uint)_DAT_00807110 < (int)((uint)_DAT_008096f8 - (uint)_DAT_0080327e)) {
      _DAT_008096f8 = _DAT_00807110 + _DAT_0080327e;
    }
  }
  else if ((_DAT_008096f8 < _DAT_0080327e) &&
          ((int)(uint)_DAT_00807110 < (int)((uint)_DAT_0080327e - (uint)_DAT_008096f8))) {
    _DAT_008096f8 = _DAT_0080327e - _DAT_00807110;
  }
  _DAT_0080327e = _DAT_008096f8;
  return;
}



//
// Function: FUN_0002d74a @ 0x0002d74a
//

ushort FUN_0002d74a(undefined4 param_1)

{
  if (param_1._0_2_ < param_1._2_2_) {
    return param_1._0_2_;
  }
  return param_1._2_2_;
}



//
// Function: FUN_0002d75e @ 0x0002d75e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002d75e(undefined4 param_1)

{
  if (_DAT_0080969c < param_1._0_2_) {
    _DAT_0080969c = _DAT_0080711a;
    return;
  }
  _DAT_0080969c = _DAT_0080969c - param_1._0_2_;
  if (_DAT_0080969c < _DAT_0080711a) {
    _DAT_0080969c = _DAT_0080711a;
  }
  return;
}



//
// Function: FUN_0002d782 @ 0x0002d782
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002d782(undefined4 param_1)

{
  if ((int)(uint)_DAT_0080969c < (int)((uint)_DAT_00803746 - (uint)param_1._0_2_)) {
    _DAT_0080969c = param_1._0_2_ + _DAT_0080969c;
    return;
  }
  _DAT_0080969c = _DAT_00803746;
  return;
}



//
// Function: boostPressureProtectionStateMachine @ 0x0002d7b4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void boostPressureProtectionStateMachine(void)

{
  undefined4 unaff_A2;
  undefined2 uVar1;
  
  uVar1 = (undefined2)((uint)unaff_A2 >> 0x10);
  switch(_DAT_008096b6) {
  case 0:
    _DAT_0080969a = 0;
    _DAT_008096fc = 0;
    return;
  case 1:
    _DAT_0080969c = FUN_0002d74a(CONCAT22(_DAT_008096f8,_DAT_00803746));
    _DAT_0080969a = 1;
    _DAT_008096fc = 1;
    _DAT_008096fa = _DAT_0080969c;
    break;
  case 2:
    _DAT_0080969a = 1;
    _DAT_0080969c = _DAT_008096fa;
    break;
  case 3:
    FUN_0002d75e(CONCAT22(_DAT_00807118,uVar1));
    break;
  case 4:
    FUN_0002d782(CONCAT22(_DAT_00807112,uVar1));
    break;
  case 5:
    FUN_0002d75e(CONCAT22(_DAT_00807114,uVar1));
    break;
  case 6:
    FUN_0002d782(CONCAT22(_DAT_00807116,uVar1));
    break;
  case 8:
    _DAT_0080969a = 0;
    return;
  }
  if ((_DAT_008096b6 == 3) || (_DAT_00803280 != 3)) {
    if ((_DAT_008096b6 != 4) && (_DAT_00803280 == 4)) {
      if (_DAT_008096fa < _DAT_008096f8) {
        _DAT_0080969c = FUN_0002d74a(CONCAT22(_DAT_008096f8,_DAT_00803746));
      }
      else {
        _DAT_0080969c = _DAT_008096fa;
      }
    }
  }
  else if (_DAT_008096f8 < _DAT_008096fa) {
    if (_DAT_008096f8 < _DAT_0080711c) {
      _DAT_0080969a = 0;
    }
    else {
      _DAT_0080969c = _DAT_008096f8;
    }
  }
  else {
    _DAT_0080969c = _DAT_008096fa;
  }
  if (_DAT_008096b6 == 7) {
    _DAT_008096fa = _DAT_0080969c;
  }
  if ((_DAT_00803746 < _DAT_008096fa) || (_DAT_008096fa < _DAT_0080711c)) {
    _DAT_008096fc = 0;
  }
  else {
    _DAT_008096fc = 1;
  }
  _DAT_00803280 = _DAT_008096b6;
  return;
}



//
// Function: FUN_0002d90c @ 0x0002d90c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0002d90c(void)

{
  ushort uVar1;
  
  uVar1 = engine_control_flags_t_008035d6.engine_operating_state & 0x8000;
  if ((engine_control_flags_t_008035d6.engine_operating_state & 0x8000) != 0) {
    _DAT_00805f90 = _DAT_0080969c;
    return uVar1;
  }
  _DAT_00805f90 = 0;
  return uVar1;
}



//
// Function: FUN_0002d92c @ 0x0002d92c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002d92c(void)

{
  _DAT_00803280 = 0;
  if ((_DAT_0080711c < _DAT_00805f90) && (_DAT_00805f90 < _DAT_00803746)) {
    _DAT_008096fc = 1;
    _DAT_0080969c = _DAT_00805f90;
    _DAT_008096fa = _DAT_00805f90;
  }
  return;
}



//
// Function: FUN_0002d96a @ 0x0002d96a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002d96a(void)

{
  uint uVar1;
  
  if (circular_buffer_t_0080c3fc.data_buffer_8 <
      fuel_limit_arbitration_t_0080cc4a.arbitration_threshold) {
    _DAT_00809694 = 0x1700;
  }
  else if (fuel_limit_arbitration_t_0080cc4a.comparison_high == 0) {
    _DAT_00809694 = 0;
  }
  else {
    _DAT_00803282 =
         (uint)(ushort)((fuel_limit_arbitration_t_0080cc4a.offset_value +
                        circular_buffer_t_0080c3fc.data_buffer_8) -
                       fuel_limit_arbitration_t_0080cc4a.arbitration_threshold) << 0x10;
    uVar1 = _DAT_00803282 / ((uint)fuel_limit_arbitration_t_0080cc4a.comparison_high * 0xf);
    _DAT_00803282 = (short)(uVar1 >> 0x10);
    _DAT_00803282 = uVar1;
    if ((_DAT_00803282 == 0) &&
       (_DAT_00803284 = (ushort)uVar1,
       _DAT_00803284 < fuel_limit_arbitration_t_0080cc4a.comparison_low)) {
      _DAT_00809694 = fuel_limit_arbitration_t_0080cc4a.comparison_low - _DAT_00803284;
      if (0x1700 < _DAT_00809694) {
        _DAT_00809694 = 0x1700;
      }
    }
    else {
      _DAT_00809694 = 0;
    }
  }
  return;
}



//
// Function: FUN_0002da0e @ 0x0002da0e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002da0e(void)

{
  int iVar1;
  
  if (_DAT_0080969a != 1) {
    _DAT_00809698 = 0x1700;
    return;
  }
  if (_DAT_0080969c < _DAT_008096f8) {
    if (_DAT_008096ba == 0) {
      _DAT_00809698 = 0;
      return;
    }
    _DAT_00803286 = 1;
    _DAT_00803288 = _DAT_008096ba;
    iVar1 = (uint)_DAT_008096f8 - (uint)_DAT_0080969c;
  }
  else {
    if (_DAT_008096ce == 0) {
      _DAT_00809698 = 0x1700;
      return;
    }
    _DAT_00803286 = 0;
    _DAT_00803288 = _DAT_008096ce;
    iVar1 = (uint)_DAT_0080969c - (uint)_DAT_008096f8;
  }
  _DAT_00803282 = iVar1 * 0x400;
  if (_DAT_00803286 == 0) {
    _DAT_00803282 = (uint)_DAT_008096d0 + _DAT_00803282 / _DAT_00803288;
  }
  else {
    _DAT_00803282 = (uint)_DAT_008096bc - _DAT_00803282 / _DAT_00803288;
  }
  if (0x1700 < (int)_DAT_00803282) {
    _DAT_00809698 = 0x1700;
    return;
  }
  if ((int)_DAT_00803282 < 0) {
    _DAT_00809698 = 0;
    return;
  }
  _DAT_00809698 = _DAT_00803284;
  return;
}



//
// Function: FUN_0002db10 @ 0x0002db10
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0002db10(void)

{
  int iVar1;
  uint uVar2;
  
  if (((engine_control_flags_t_008035d6.engine_operating_state & 0x80) == 0) || (_DAT_008096aa != 0)
     ) {
    _DAT_00809696 = 0x1700;
    return engine_control_flags_t_008035d6.engine_operating_state & 0x80;
  }
  if (_DAT_0080973c < _DAT_008096f8) {
    if (_DAT_008096d4 == 0) {
      _DAT_00809696 = 0;
      return (uint)_DAT_008096f8;
    }
    _DAT_00803286 = 1;
    _DAT_00803288 = _DAT_008096d4;
    iVar1 = (uint)_DAT_008096f8 - (uint)_DAT_0080973c;
  }
  else {
    if (_DAT_008096da == 0) {
      _DAT_00809696 = 0x1700;
      return (uint)_DAT_008096f8;
    }
    _DAT_00803286 = 0;
    _DAT_00803288 = _DAT_008096da;
    iVar1 = (uint)_DAT_0080973c - (uint)_DAT_008096f8;
  }
  _DAT_00803282 = iVar1 * 0x400;
  if (_DAT_00803286 == 0) {
    uVar2 = (uint)_DAT_008096dc;
    _DAT_00803282 = uVar2 + _DAT_00803282 / _DAT_00803288;
  }
  else {
    uVar2 = (uint)_DAT_008096d6 - _DAT_00803282 / _DAT_00803288;
    _DAT_00803282 = uVar2;
  }
  if (0x1700 < (int)_DAT_00803282) {
    _DAT_00809696 = 0x1700;
    return uVar2;
  }
  if ((int)_DAT_00803282 < 0) {
    _DAT_00809696 = 0;
    return uVar2;
  }
  _DAT_00809696 = _DAT_00803284;
  return uVar2;
}



//
// Function: fuelTempProtectionLimitCalculator @ 0x0002dc1e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelTempProtectionLimitCalculator(void)

{
  ushort uVar1;
  
  if ((_DAT_008071ae <= _DAT_008096a6) && (engine_operating_mode_t_0080c810.state != 1)) {
    if (_DAT_0080975c == 0) {
      _DAT_00803292 = 0xffff;
    }
    else {
      _DAT_00803292 = (ushort)((_DAT_00809758 * (uint)_DAT_00803846) / _DAT_0080975c);
    }
    if (_DAT_008096a8 < _DAT_00803292) {
      uVar1 = _DAT_00803292 - _DAT_008096a8;
    }
    else {
      uVar1 = _DAT_008096a8 - _DAT_00803292;
    }
    if (((_DAT_0080714a < _DAT_00803292) && (_DAT_00803292 < _DAT_0080714c)) &&
       (uVar1 <= _DAT_00807148)) {
      _DAT_0080971a = _DAT_00803292;
      _DAT_0080971e = 0;
      if (_DAT_00809722 != 0) {
        _DAT_00809722 = _DAT_00809722 + -1;
      }
      _DAT_008096a8 = coreTableInterpolation();
      _DAT_0080971c = _DAT_008096a8;
    }
    else {
      _DAT_0080971e = 1;
      _DAT_00809722 = _DAT_00807152;
      _DAT_0080971a = _DAT_00803292;
      if (_DAT_00803292 < _DAT_0080714a) {
        _DAT_0080971a = _DAT_0080714a;
      }
      else if (_DAT_0080714c < _DAT_00803292) {
        _DAT_0080971a = _DAT_0080714c;
      }
      _DAT_008096a8 = _DAT_0080971a;
      _DAT_0080328e = (uint)_DAT_0080971a << 0x10;
    }
    if ((circular_buffer_t_0080c3fc.data_buffer_8 < 8000) && (_DAT_00807156 < _DAT_008096a6)) {
      _DAT_00809720 = _DAT_00807154;
    }
    else if (_DAT_00809720 != 0) {
      _DAT_00809720 = _DAT_00809720 + -1;
    }
    if ((fuel_arbitrator_diag_t_0080cff8.fuel_limit == 0 && _DAT_00809722 == 0) &&
       (_DAT_00809720 == 0)) {
      _DAT_008096aa = 0;
    }
    else {
      _DAT_008096aa = 1;
      _DAT_00803294 = 1;
    }
    if ((((_DAT_0080971c == _DAT_00803296) && (_DAT_008096aa == 0)) && (_DAT_00803294 == 1)) &&
       (_DAT_00807158 < fuel_demand_state_t_0080c9a4.command)) {
      _DAT_00809724 = _DAT_0080971c;
      _DAT_00803294 = 0;
    }
    _DAT_00803296 = _DAT_0080971c;
    return;
  }
  _DAT_0080971a = _DAT_00807150;
  _DAT_008096a8 = _DAT_00807150;
  _DAT_0080971c = _DAT_00807150;
  _DAT_00809724 = _DAT_00807150;
  _DAT_008096aa = 1;
  _DAT_0080328e = (uint)_DAT_00807150 << 0x10;
  return;
}



//
// Function: FUN_0002ddea @ 0x0002ddea
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002ddea(void)

{
  fuel_arbitrator_diag_t_0080cff8.fuel_limit = 0;
  _DAT_0080971a = _DAT_00807150;
  _DAT_008096a8 = _DAT_00807150;
  _DAT_0080971c = _DAT_00807150;
  _DAT_0080328e = (uint)_DAT_00807150 << 0x10;
  _DAT_0080328a = 0x80714e;
  _DAT_00803296 = _DAT_00807150;
  return;
}



//
// Function: shutdownLimitSelector @ 0x0002de2e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort shutdownLimitSelector(void)

{
  ushort in_D0w;
  
  if (((_DAT_008096aa != 0) && (in_D0w = _DAT_008096a6, _DAT_0080973c < _DAT_008096a6)) &&
     (in_D0w = engine_control_flags_t_008035d6.engine_operating_state & 0x80,
     (engine_control_flags_t_008035d6.engine_operating_state & 0x80) != 0)) {
    _DAT_0080972c = _DAT_008071a6;
    return in_D0w;
  }
  _DAT_0080972c = _DAT_00807f3c;
  return in_D0w;
}



//
// Function: FUN_0002de68 @ 0x0002de68
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002de68(void)

{
  if (_DAT_0080972c < _DAT_0080d494) {
    _DAT_0080d494 = _DAT_0080972c;
    _DAT_0080d496 = 0x15;
  }
  return;
}



//
// Function: crankDataBufferStore @ 0x0002de92
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void crankDataBufferStore(void)

{
  short sVar1;
  
  _DAT_008032b8 = (short)((_DAT_00805590 + 2) % 3);
  *(undefined4 *)((short)(_DAT_008032b8 * 2) * 8 + 0x805fb4) = _DAT_0080626c;
  *(int *)((short)(_DAT_008032b8 * 2) * 8 + 0x805fb8) = _DAT_00809726;
  if (_DAT_00803734 == 0) {
    sVar1 = _DAT_008032b8 << 4;
    *(uint *)(sVar1 + 0x805fbc) = (uint)_DAT_0080972a * 0x280;
    if (CKAJIIFL < 0x6400) {
      *(int *)((short)(_DAT_008032b8 * 2) * 8 + 0x805fc0) =
           _DAT_00809726 + (*(int *)(sVar1 + 0x805fbc) - _DAT_00805faa);
    }
    else {
      *(undefined4 *)((short)(_DAT_008032b8 * 2) * 8 + 0x805fc0) = _DAT_00805fae;
    }
  }
  else if (_DAT_00803734 == 3) {
    *(ushort *)(_DAT_008032b8 * 2 + 0x805594) = (ushort)(_DAT_0080558e != 0);
    *(uint *)((short)(_DAT_008032b8 * 2) * 8 + 0x805fc0) = (uint)_DAT_0080384a * 0x280;
    *(uint *)((short)(_DAT_008032b8 * 2) * 8 + 0x805fbc) = (uint)_DAT_0080384a * 0x280;
  }
  else {
    *(undefined4 *)((short)(_DAT_008032b8 * 2) * 8 + 0x805fc0) = 0;
    *(undefined4 *)((short)(_DAT_008032b8 * 2) * 8 + 0x805fbc) = 0;
  }
  _DAT_00805fae = 0;
  _DAT_00805faa = 0;
  return;
}



//
// Function: crankAndProtectionStateMonitor @ 0x0002dfd0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint crankAndProtectionStateMonitor(void)

{
  undefined4 in_D0;
  uint uVar1;
  ushort uVar2;
  
  uVar1 = CONCAT22((short)((uint)in_D0 >> 0x10),_DAT_008035ec) & 0xffff2000;
  if ((_DAT_008035ec & 0x2000) != 0) {
    if ((((circular_buffer_t_0080c3fc.data_buffer_8 == 0) && (_DAT_0080d1a4 == 2)) &&
        (_DAT_0080329e <= _DAT_0080715c)) && (_DAT_0080329a < 0xc)) {
      DAT_00803298 = 0;
      if (_DAT_0080329c == 1) {
        if (_DAT_0080329e == _DAT_0080715c) {
          _DAT_0080329e = 0;
          _DAT_0080329a = 0;
        }
        _DAT_0080329e = _DAT_0080329e + 1;
      }
      else {
        _DAT_0080329e = 0;
      }
      if ((DAT_0080bdc7 & 8) != 0) {
        DAT_00803298 = 2;
      }
      if (_DAT_008032a2 == 1) {
        DAT_00803298 = DAT_00803298 | 1;
      }
      if (_DAT_00809d50 == 1) {
        DAT_00803298 = DAT_00803298 | 8;
      }
      if (_DAT_008032a0 == 1) {
        DAT_00803298 = DAT_00803298 | 4;
      }
      if ((&DAT_0002de86)[(short)_DAT_0080329a] == DAT_00803298) {
        _DAT_008032a0 = _DAT_00809d50;
        _DAT_008032a2 = (ushort)((DAT_0080bdc7 & 8) != 0);
        _DAT_0080329a = _DAT_0080329a + 1;
        if (4 < _DAT_0080329a) {
          _DAT_0080329c = 1;
        }
      }
      if ((_DAT_0080329a == 0xc) && (CKIIFLES = 1, _DAT_008032ba == 1)) {
        _DAT_0080d050 = 1;
      }
    }
    if (((circular_buffer_t_0080c3fc.data_buffer_8 != 0) &&
        ((fault_status_registers_t_00805df2.io_fault_status_1 & 0x100) != 0)) &&
       ((_DAT_008068cc & 0x100) != 0)) {
      if (_DAT_008032b4 == _DAT_0080888a) {
        _DAT_0080558e = _DAT_0080558e | 1;
      }
      else {
        _DAT_008032b4 = _DAT_008032b4 + 1;
      }
    }
    if (((circular_buffer_t_0080c3fc.data_buffer_8 != 0) &&
        ((fault_status_registers_t_00805df2.io_fault_status_1 & 0x200) != 0)) &&
       ((_DAT_008068cc & 0x200) != 0)) {
      if (_DAT_008032b6 == _DAT_0080888a) {
        _DAT_0080558e = _DAT_0080558e | 0x20;
      }
      else {
        _DAT_008032b6 = _DAT_008032b6 + 1;
      }
    }
    uVar1 = _DAT_0080626c - *(int *)((short)(_DAT_00805590 * 2) * 8 + 0x805fb4);
    _DAT_00809726 = uVar1;
    if (_DAT_00803734 == 0) {
      _DAT_008032ae = 9;
      _DAT_0080d0c2 = lookupTableInterpolation((short *)&DAT_008032a8);
      uVar2 = (short)_DAT_0080626c - _DAT_008032a6;
      _DAT_008032a4 = _DAT_0080626c;
      uVar2 = (ushort)((uint)uVar2 * (uint)_DAT_0080d0c2 >> 8);
      if (-(uint)uVar2 - 1 < _DAT_00805faa) {
        _DAT_0080558e = _DAT_0080558e | 8;
      }
      _DAT_00805faa = uVar2 + _DAT_00805faa;
      uVar1 = proportionalCalculation(_DAT_00805faa,0x6400,(uint)_DAT_0080972a * 0x280);
      CKAJIIES = (word)uVar1;
      if ((_DAT_00805fae == 0) && (0x63ff < CKAJIIFL)) {
        _DAT_00805fae = _DAT_00809726;
      }
    }
    else if (_DAT_00803734 == 3) {
      uVar1 = proportionalCalculation(uVar1,0x6400,(uint)_DAT_0080384a * 0x280);
      CKAJIIES = (word)uVar1;
    }
    else {
      CKAJIIES = 0;
    }
    if ((CKIITAES == 1) || ((CKIIFLES == 1 && (_DAT_008032ba == 1)))) {
      uVar1 = crankDataBufferStore();
    }
  }
  return uVar1;
}



//
// Function: FUN_0002e282 @ 0x0002e282
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002e282(void)

{
  ushort uVar1;
  short local_10 [4];
  undefined4 local_8;
  
  uVar1 = 0;
  _DAT_008032a4 = _DAT_0080626c;
  _DAT_008032ba = 1;
  _DAT_008032a8 = 2;
  _DAT_008032aa = 0x80716a;
  _DAT_008032b0 = 0x807188;
  local_10[0] = 2;
  local_10[1] = 0x80;
  local_10[2] = -0x7774;
  local_8 = 0x80715e;
  while ((uVar1 < 6 && (_DAT_008032ba == 1))) {
    if (((&DAT_008049ec)[(short)uVar1] == '0') &&
       ((&DAT_008034fa)[(short)uVar1] == (char)((char)uVar1 + 'A'))) {
      uVar1 = uVar1 + 1;
    }
    else {
      _DAT_008032ba = 0;
    }
  }
  if (_DAT_00803734 == 0) {
    local_10[3] = _DAT_00803738;
    _DAT_0080972a = lookupTableInterpolation(local_10);
  }
  return;
}



//
// Function: engineParameterControllerWithTimer @ 0x0002e336
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engineParameterControllerWithTimer(void)

{
  if (_DAT_00809760 != 0) {
    _DAT_00809760 = _DAT_00809760 + -1;
  }
  if (_DAT_00809760 == 0) {
    _DAT_0080972e = 0;
  }
  else if (_DAT_00809758 < _DAT_0080384e) {
    _DAT_0080972e = _DAT_008071ac;
  }
  else if (_DAT_00803852 < _DAT_00809758) {
    _DAT_0080972e = _DAT_008071ae;
  }
  else {
    _DAT_0080972e = (undefined2)(_DAT_00809730 / _DAT_00809758);
  }
  _DAT_008096a6 = coreTableInterpolation();
  return;
}



//
// Function: FUN_0002e3a8 @ 0x0002e3a8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002e3a8(void)

{
  _DAT_00809738 = 0;
  _DAT_00809734 = &derate_table_EPFLTB_008071a8;
  _DAT_00809730 = proportionalCalculation((uint)_DAT_0080385a * 0xe1000,500000,_DAT_00803856);
  return;
}



//
// Function: boostPressureTargetCalculator @ 0x0002e3ee
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint boostPressureTargetCalculator(void)

{
  int iVar1;
  uint uVar2;
  undefined4 in_D0;
  uint uVar3;
  undefined *puVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  
  uVar3 = CONCAT22((short)((uint)in_D0 >> 0x10),
                   engine_control_flags_t_008035d6.engine_operating_state) & 0xffff0100;
  if ((engine_control_flags_t_008035d6.engine_operating_state & 0x100) == 0) {
    _DAT_0080973c = _DAT_00803748;
  }
  else {
    if (_DAT_0080971a < _DAT_008096a8) {
      iVar1 = (uint)_DAT_008096a8 - (uint)_DAT_0080971a;
    }
    else {
      iVar1 = (uint)_DAT_0080971a - (uint)_DAT_008096a8;
    }
    if (_DAT_008096a8 == 0) {
      puVar4 = &DAT_00006400;
    }
    else {
      puVar4 = (undefined *)((uint)(iVar1 * 0x6400) / (uint)_DAT_008096a8);
      if ((undefined *)0x63ff < puVar4) {
        puVar4 = &DAT_00006400;
      }
    }
    uVar7 = _DAT_00803748;
    uVar6 = _DAT_00803748;
    if ((_DAT_0080973e < (int)(uint)_DAT_008096a8) &&
       (uVar7 = _DAT_00803866, uVar6 = _DAT_00803864, _DAT_00809742 < (int)(uint)_DAT_008096a8)) {
      uVar7 = _DAT_00803866 - _DAT_0080386a;
      uVar6 = _DAT_00803864 - _DAT_00803868;
    }
    uVar2 = (int)(short)boost_pressure_control_t_00809746.state_machine - 1;
    uVar3 = uVar2;
    if (uVar2 < 6) {
      uVar3 = CONCAT22((short)(uVar2 >> 0x10),(&switchD_0002e4d8::switchdataD_0002e4dc)[uVar2]);
      uVar5 = (ushort)puVar4;
      switch(uVar2) {
      case 0:
        uVar3 = (uint)_DAT_008096a8;
        if (_DAT_0080973e < (int)uVar3) {
          boost_pressure_control_t_00809746.state_machine = 2;
          _DAT_0080973c = uVar6;
        }
        else {
          boost_pressure_control_t_00809746.state_machine = 6;
          _DAT_0080973c = uVar6;
        }
        break;
      case 1:
        _DAT_008032c2 = 0x64000000;
        boost_pressure_control_t_00809746.interpolation_result = 0x6400;
        boost_pressure_control_t_00809746.state_machine = 3;
        _DAT_0080973c = uVar6;
        break;
      case 2:
        boost_pressure_control_t_00809746.interpolation_result = coreTableInterpolation();
        uVar3 = (uint)_DAT_008096a8;
        if ((_DAT_0080973e < (int)uVar3) && (uVar5 <= _DAT_008071bc)) {
          uVar3 = (uint)boost_pressure_control_t_00809746.interpolation_result;
          if (boost_pressure_control_t_00809746.interpolation_result <= _DAT_008071b2) {
            boost_pressure_control_t_00809746.state_machine = 4;
          }
        }
        else {
          boost_pressure_control_t_00809746.state_machine = 1;
        }
        break;
      case 3:
        _DAT_0080973c = _DAT_008096a6;
        if ((uVar7 <= _DAT_008096a6) && (uVar7 = _DAT_0080973c, uVar6 < _DAT_008096a6)) {
          uVar7 = uVar6;
        }
        _DAT_0080973c = uVar7;
        boost_pressure_control_t_00809746.state_machine = 5;
        break;
      case 4:
        if (uVar7 < _DAT_0080973c) {
          _DAT_0080973c = _DAT_0080973c - _DAT_008071b4;
        }
        uVar3 = (uint)_DAT_008096a8;
        if ((_DAT_0080973e < (int)uVar3) && (uVar5 <= _DAT_008071bc)) {
          uVar3 = (uint)_DAT_0080d0c8;
          if (_DAT_008071b8 < _DAT_0080d0c8) {
            boost_pressure_control_t_00809746.state_machine = 2;
          }
        }
        else {
          boost_pressure_control_t_00809746.state_machine = 1;
        }
        break;
      case 5:
        boost_pressure_control_t_00809746.active_flag = 0;
        uVar3 = (uint)_DAT_008096a8;
        if ((_DAT_0080973e < (int)uVar3) || (_DAT_0080973c = uVar6, _DAT_008071ba < uVar5)) {
          boost_pressure_control_t_00809746.state_machine = 1;
          _DAT_0080973c = uVar6;
        }
      }
    }
    if ((DAT_0080bdc7 & 8) != 0) {
      boost_pressure_control_t_00809746.state_machine = 5;
    }
    if (boost_pressure_control_t_00809746.state_machine != 6) {
      boost_pressure_control_t_00809746.active_flag = 1;
      return uVar3;
    }
  }
  return uVar3;
}



//
// Function: FUN_0002e5fe @ 0x0002e5fe
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002e5fe(void)

{
  uint uVar1;
  
  boost_pressure_control_t_00809746.state_machine = 1;
  boost_pressure_control_t_00809746.active_flag = 1;
  _DAT_0080973c = _DAT_00803748;
  boost_pressure_control_t_00809746.interpolation_result = _DAT_0080d0c8;
  _DAT_008032c2 = 0x64000000;
  _DAT_008032be = 0x8071b6;
  _DAT_0080973e = ((uint)_DAT_00803828 * (int)(&DAT_00006400 + _DAT_008071b0)) / 0x6400;
  if (_DAT_0080714c < _DAT_0080973e) {
    _DAT_0080973e = (uint)_DAT_0080714c;
  }
  else {
    _DAT_0080973e = _DAT_0080973e & 0xffff;
  }
  uVar1 = ((int)(&DAT_00006400 + _DAT_008071b0) * (uint)_DAT_0080386c) / 0x6400;
  if (_DAT_0080714c < uVar1) {
    _DAT_00809742 = (uint)_DAT_0080714c;
    return;
  }
  _DAT_00809742 = uVar1 & 0xffff;
  return;
}



//
// Function: FUN_0002e6c2 @ 0x0002e6c2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0002e6c2(uint *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  
  iVar1 = _DAT_0080974c;
  uVar3 = 0;
  *param_1 = _DAT_0080974c + *param_1;
  if (0xfffff < *param_1) {
    uVar2 = *param_1 >> 0x14;
    uVar3 = (ushort)(-uVar2 - 1 <= *param_2);
    *param_2 = uVar2 + *param_2;
    iVar1 = uVar2 * 0x100000;
    *param_1 = *param_1 + uVar2 * -0x100000;
  }
  return CONCAT22((short)((uint)iVar1 >> 0x10),uVar3);
}



//
// Function: FUN_0002e702 @ 0x0002e702
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002e702(void)

{
  if ((_DAT_0080969a == 1) &&
     (((fuel_demand_state_t_0080c9a4._2_2_ == 9 &&
       (_DAT_0080d49a < fuel_demand_state_t_0080c9a4.command)) ||
      ((fuel_demand_state_t_0080c9a4._2_2_ != 9 &&
       ((_DAT_0080d49a < _DAT_00809698 || (_DAT_00809d4c == 0)))))))) {
    _DAT_0080627e = _DAT_0080627e + 1;
    _DAT_008062a6 = _DAT_008062a6 + 1;
    FUN_0002e6c2((uint *)&DAT_0080629e,(uint *)&DAT_008062aa);
  }
  if (fuel_demand_state_t_0080c9a4._2_2_ == 10) {
    _DAT_0080628a = _DAT_0080628a + 1;
    FUN_0002e6c2((uint *)&DAT_008062a2,(uint *)&DAT_008062ae);
  }
  return;
}



//
// Function: FUN_0002e786 @ 0x0002e786
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002e786(void)

{
  if ((_DAT_0080c7c4 != 0) && (_DAT_008071d4 < _DAT_0080972e)) {
    FUN_0002e6c2((uint *)&DAT_0080625c,(uint *)&DAT_00806292);
  }
  return;
}



//
// Function: FUN_0002e7b0 @ 0x0002e7b0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002e7b0(void)

{
  if (_DAT_0080973e < (int)(uint)_DAT_0080971c) {
    _DAT_008032d4 = 0;
  }
  else if (_DAT_008032d4 < _DAT_008071ce) {
    _DAT_008032d4 = _DAT_008032d4 + 1;
  }
  else {
    _DAT_0080628e = _DAT_0080628e + 1;
    FUN_0002e6c2((uint *)&DAT_008062b6,(uint *)&DAT_008062be);
  }
  if ((_DAT_0080973e < (int)(uint)_DAT_0080971c) && ((int)(uint)_DAT_0080971c <= _DAT_00809742)) {
    if (_DAT_008071d0 <= _DAT_008032d6) {
      _DAT_00806282 = _DAT_00806282 + 1;
      FUN_0002e6c2((uint *)&DAT_008062b2,(uint *)&DAT_008062ba);
      return;
    }
    _DAT_008032d6 = _DAT_008032d6 + 1;
    return;
  }
  _DAT_008032d6 = 0;
  return;
}



//
// Function: FUN_0002e84a @ 0x0002e84a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002e84a(void)

{
  ushort uVar1;
  
  if ((_DAT_008062ca < _DAT_008096a6) && (_DAT_00809d4c != 0)) {
    _DAT_008062ca = _DAT_008096a6;
  }
  uVar1 = _DAT_008096a6 >> 8;
  if (uVar1 == 0) {
    _DAT_00805ffc = _DAT_00805ffc + 1;
  }
  else if (1 < uVar1) {
    if (uVar1 < 0x98) {
      *(int *)(&DAT_00805ffc + (short)uVar1 * 4) = *(int *)(&DAT_00805ffc + (short)uVar1 * 4) + 1;
    }
    else {
      _DAT_00806254 = _DAT_00806254 + 1;
    }
  }
  if ((high_rpm_protection_t_0080cc6a.state == 4) && (DAT_008032c6 == '\0')) {
    _DAT_008062c2 = _DAT_008062c2 + 1;
    DAT_008032c6 = '\x01';
    DAT_008032c7 = '\0';
  }
  if ((high_rpm_protection_t_0080cc6a.state == 3) && (DAT_008032c7 == '\0')) {
    _DAT_008062c6 = _DAT_008062c6 + 1;
    DAT_008032c7 = '\x01';
    DAT_008032c6 = '\0';
  }
  if ((high_rpm_protection_t_0080cc6a.state != 4) && (high_rpm_protection_t_0080cc6a.state != 3)) {
    DAT_008032c7 = '\0';
    DAT_008032c6 = '\0';
  }
  return;
}



//
// Function: clutchOperatingStatisticsTracker @ 0x0002e8f2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort clutchOperatingStatisticsTracker(void)

{
  undefined4 uVar1;
  ushort uVar2;
  undefined4 *puVar3;
  
  if (_DAT_0080d466 == 1) {
    _DAT_0080d466 = 0;
    uVar2 = 0;
    puVar3 = (undefined4 *)&DAT_00805ffc;
    do {
      *puVar3 = 0;
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (uVar2 < 0x97);
    _DAT_00806258 = 0;
    _DAT_0080625c = 0;
    _DAT_00806260 = 0;
    _DAT_00806264 = 0;
    _DAT_00806270 = 0;
    _DAT_00806274 = 0;
    _DAT_00806278 = 0;
    _DAT_0080627a = 0;
    _DAT_0080627c = 0;
    _DAT_0080627e = 0;
    _DAT_00806282 = 0;
    _DAT_0080628a = 0;
    _DAT_0080628e = 0;
    _DAT_00806292 = 0;
    _DAT_00806296 = 0;
    _DAT_0080629a = 0;
    _DAT_0080629e = 0;
    _DAT_008062a2 = 0;
    _DAT_008062a6 = 0;
    _DAT_008062aa = 0;
    _DAT_008062ae = 0;
    _DAT_008062b2 = 0;
    _DAT_008062b6 = 0;
    _DAT_008062ba = 0;
    _DAT_008062be = 0;
    _DAT_008062c2 = 0;
    _DAT_008062c6 = 0;
    _DAT_008062ca = 0;
    _DAT_0080974c = 0;
    _DAT_00805fa2 = 0;
    _DAT_00805fa6 = 0;
  }
  uVar2 = engine_control_flags_t_008035d6.engine_operating_state & 0x200;
  if (uVar2 != 0) {
    _DAT_0080974c = proportionalCalculation((uint)_DAT_008032c8 + (uint)_DAT_0080972e,0x20000,36000)
    ;
    if (_DAT_0080d46a == 0) {
      if (_DAT_0080974c == 0) {
        _DAT_00809750 = 0;
        _DAT_00804bc8 = 0;
      }
      else {
        _DAT_00809750 = 0xffffffff;
        _DAT_00804bc8 = 0xffff;
      }
    }
    else {
      if (_DAT_0080974c / _DAT_0080d46a < 0x7ff) {
        _DAT_00809750 = proportionalCalculation(_DAT_0080974c,0x200000,_DAT_0080d46a);
      }
      else {
        _DAT_00809750 = 0xffffffff;
      }
      if (_DAT_00809750 >> 0x10 < 0x10000) {
        _DAT_00804bc8 = (undefined2)(_DAT_00809750 >> 0x10);
      }
      else {
        _DAT_00804bc8 = 0xffff;
      }
    }
    uVar1 = FUN_0002e6c2((uint *)&DAT_00806258,(uint *)0x806268);
    if ((short)uVar1 == 1) {
      _DAT_00806278 = _DAT_00806278 | 8;
    }
    uVar1 = FUN_0002e6c2((uint *)&DAT_00806260,(uint *)&DAT_0080626c);
    if ((short)uVar1 == 1) {
      _DAT_00806278 = _DAT_00806278 | 4;
    }
    uVar1 = FUN_0002e6c2((uint *)&DAT_00806264,(uint *)&DAT_00806274);
    if ((short)uVar1 == 1) {
      _DAT_00806278 = _DAT_00806278 | 0x20;
    }
    if ((((fault_status_registers_t_00805df2.io_fault_status_1 & 0x100) == 0) ||
        ((_DAT_008068cc & 0x100) == 0)) &&
       (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x200) == 0 ||
        ((_DAT_008068cc & 0x200) == 0)))) {
      _DAT_008032d2 = 0;
    }
    else if (_DAT_00808a54 < _DAT_008032d2) {
      _DAT_00806278 = _DAT_00806278 | 0x13;
    }
    else {
      _DAT_008032d2 = _DAT_008032d2 + 1;
    }
    if (_DAT_00805f34 == 0) {
      if (_DAT_00806274 == 0) {
        _DAT_00806270 = 0;
      }
      else {
        _DAT_00806270 = 0xffffffff;
      }
    }
    else if (_DAT_00806274 / _DAT_00805f34 < 0x3ff) {
      _DAT_00806270 = proportionalCalculation(_DAT_00806274,0x400000,_DAT_00805f34);
    }
    else {
      _DAT_00806270 = 0xffffffff;
    }
    _DAT_00804bc0 = _DAT_00803870 + _DAT_0080626c;
    _DAT_00804bc4 = _DAT_00806274;
    if (_DAT_00806270 >> 0x11 < 0x10000) {
      _DAT_00804bca = (ushort)(_DAT_00806270 >> 0x11);
    }
    else {
      _DAT_00804bca = 0xffff;
    }
    if ((DAT_0080bdc7 & 8) == 0) {
      _DAT_008032da = 0;
    }
    else {
      if (_DAT_008032da == 0) {
        _DAT_008032da = 1;
        _DAT_008032ca = 0;
      }
      else if ((_DAT_008032da == 1) && (_DAT_008032ca < _DAT_008071c6)) {
        _DAT_008032ca = _DAT_008032ca + 1;
      }
      else {
        _DAT_0080627a = _DAT_0080627a + 1;
        _DAT_008032da = 2;
      }
      FUN_0002e6c2((uint *)&DAT_00806296,(uint *)&DAT_0080629a);
    }
    _DAT_008032d0 = _DAT_008032d0 + 1;
    if (_DAT_008032d0 == 10) {
      _DAT_008032d0 = 0;
      _DAT_008032cc = (uint)_DAT_008032c8 - (uint)_DAT_0080972e;
      if ((_DAT_008032d8 == 0) && (_DAT_008071ca <= _DAT_008032cc)) {
        _DAT_008032d8 = 1;
        _DAT_0080627c = _DAT_0080627c + 1;
      }
      else if (_DAT_008032cc < _DAT_008071ca) {
        _DAT_008032d8 = 0;
      }
      _DAT_008032c8 = _DAT_0080972e;
    }
    if (circular_buffer_t_0080c3fc.current_engine_rpm != 0) {
      FUN_0002e702();
      FUN_0002e786();
      FUN_0002e7b0();
    }
    uVar2 = FUN_0002e84a();
  }
  return uVar2;
}



//
// Function: FUN_0002ecec @ 0x0002ecec
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002ecec(void)

{
  _DAT_008032da = 0;
  _DAT_008032d8 = 0;
  DAT_008032c6 = 0;
  DAT_008032c7 = 0;
  return;
}



//
// Function: FUN_0002ed06 @ 0x0002ed06
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0002ed06(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfffb;
  _DAT_00809760 = _DAT_008071aa;
  _DAT_00809758 = _DAT_00ffff28;
  _DAT_00ffff28 = _DAT_00ffff28 & 0xffff;
  if (circular_buffer_t_0080c3fc.data_buffer_rest._32_2_ == 0) {
    if (_DAT_0080c758 == 0) {
      _DAT_0080975c = 0;
    }
    else {
      _DAT_0080975c = _DAT_0080c750 / _DAT_0080c758;
    }
    _DAT_0080c750 = 0;
    _DAT_0080c758 = 0;
  }
  else if (circular_buffer_t_0080c3fc.data_buffer_rest._32_2_ == 1) {
    if (_DAT_0080c75a == 0) {
      _DAT_0080975c = 0;
    }
    else {
      _DAT_0080975c = _DAT_0080c754 / _DAT_0080c75a;
    }
    _DAT_0080c754 = 0;
    _DAT_0080c75a = 0;
  }
  return CONCAT44(in_D0,in_D1);
}



//
// Function: FUN_0002ed96 @ 0x0002ed96
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002ed96(void)

{
  _DAT_00fffe20 = _DAT_00fffe20 & 0xfffb;
  _DAT_00808eca = FUN_0002ed06;
  _DAT_00fffe12 = _DAT_00fffe12 & 0xf0ff | 0xd00;
  _DAT_00ffff22 = _DAT_0080385a << 8;
  _DAT_00ffff26 = 0;
  _DAT_00ffff28 = 0;
  _DAT_00ffff20 = 0xb;
  _DAT_00fffe16 = _DAT_00fffe16 & 0xffcf | 0x30;
  _DAT_00fffe1a = _DAT_00fffe1a & 0xffcf | 0x30;
  _DAT_00fffe0a = _DAT_00fffe0a & 0xfffb | 4;
  _DAT_00fffe1e = _DAT_00fffe1e & 0xffcf | 0x20;
  return;
}



//
// Function: FUN_0002ee28 @ 0x0002ee28
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002ee28(void)

{
  _DAT_00805fe6 = 0;
  _DAT_00805fe8 = 0;
  _DAT_00805fec = 0;
  _DAT_00805fee = 0;
  _DAT_00805ff0 = 0;
  _DAT_00805ff2 = 0;
  _DAT_008032e6 = coreTableInterpolation();
  _DAT_008032e8 = coreTableInterpolation();
  _DAT_008032ea = coreTableInterpolation();
  _DAT_008032ec = coreTableInterpolation();
  return;
}



//
// Function: vp44FaultProtectionController @ 0x0002eeac
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44FaultProtectionController(void)

{
  bool bVar1;
  uint uVar2;
  ushort uVar3;
  word wVar4;
  undefined *puVar5;
  
  if (DAT_008032dc == '\0') {
    if (((((fault_status_registers_t_00805df2.io_fault_status_1 & 0x100) != 0) &&
         ((_DAT_008068cc & 0x100) != 0)) ||
        (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x200) != 0 &&
         ((_DAT_008068cc & 0x200) != 0)))) && (_DAT_0080387e < _DAT_008096ae)) {
      _DAT_008096ae = _DAT_0080387e;
    }
    uVar2 = proportionalCalculation
                      ((uint)_DAT_00803748,
                       (uint)_DAT_00803828 *
                       ((uint)_DAT_0080385c * (uint)_DAT_0080374a >> 7 & 0xffff) >> 0xb & 0xffff,
                       0x100);
    uVar2 = proportionalCalculation(uVar2,8,0x3c);
    if (uVar2 < 0x10000) {
      _DAT_00809764 = (ushort)uVar2;
    }
    else {
      _DAT_00809764 = 0xffff;
    }
    _DAT_00803314 = (short)((uint)_DAT_00803828 * (uint)_DAT_008071e8 >> 0xb);
    _DAT_00803312 = _DAT_00803314 + _DAT_00803828;
    _DAT_00803314 = _DAT_00803828 - _DAT_00803314;
    uVar3 = _DAT_0080386c;
    if (0x7ffc < _DAT_0080386c) {
      uVar3 = _DAT_0080386c - 1;
    }
    _DAT_00803310 = (short)((uint)uVar3 * (uint)_DAT_008071e8 >> 0xb);
    _DAT_0080330e = _DAT_00803310 + uVar3;
    _DAT_00803310 = uVar3 - _DAT_00803310;
    DAT_008032dc = '\x01';
  }
  if (((((_DAT_008035ec & 0x100) != 0) && (_DAT_0080385e != 0)) && (_DAT_0080972e == 0)) &&
     ((_DAT_008071ea < _DAT_008096a6 && ((DAT_0080bdc7 & 8) == 0)))) {
    _DAT_00805fe4 = 2;
    _DAT_008096ae = _DAT_0080387e;
    fault_status_registers_t_00805df2.io_fault_status_1 =
         fault_status_registers_t_00805df2.io_fault_status_1 | 0x100;
    fault_latch_registers_t_00805e32.io_fault_latch_1 =
         fault_latch_registers_t_00805e32.io_fault_latch_1 | 0x100;
  }
  if ((((_DAT_008035ec & 0x200) != 0) && (_DAT_0080d17a == 0)) &&
     ((_DAT_0080385e != 0 && (_DAT_008096a6 == 0)))) {
    if ((_DAT_008032e0 == 0) && (_DAT_00809d50 == 1)) {
      _DAT_00805ff4 = _DAT_00805ff4 + 1;
    }
    if (_DAT_008071da < circular_buffer_t_0080c3fc.data_buffer_8) {
      if ((~DAT_008032dd & (DAT_0080bdc7 & 8) != 0) != 0) {
        _DAT_00805ff6 = _DAT_00805ff6 + 1;
      }
      if ((~DAT_008032de & (DAT_0080bdc7 & 4) != 0) != 0) {
        _DAT_00805ff8 = _DAT_00805ff8 + 1;
      }
    }
    if ((_DAT_008071dc <= _DAT_00805ff4) &&
       ((_DAT_008071d6 <= _DAT_00805ff6 || (_DAT_008071d8 <= _DAT_00805ff8)))) {
      _DAT_00805fe4 = 1;
      _DAT_008096ae = _DAT_0080387e;
      fault_status_registers_t_00805df2.io_fault_status_1 =
           fault_status_registers_t_00805df2.io_fault_status_1 | 0x100;
      fault_latch_registers_t_00805e32.io_fault_latch_1 =
           fault_latch_registers_t_00805e32.io_fault_latch_1 | 0x100;
    }
  }
  if (((_DAT_0080972e != 0) || (_DAT_0080d17a == 1)) ||
     (((_DAT_008035ec & 0x100) == 0 && ((_DAT_008035ec & 0x200) == 0)))) {
    if (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x100) != 0) &&
       ((fault_latch_registers_t_00805e32.io_fault_latch_1 & 0x100) == 0)) {
      fault_status_registers_t_00805df2.io_fault_status_1 =
           fault_status_registers_t_00805df2.io_fault_status_1 & 0xfeff;
      _DAT_008096ae = _DAT_008037b4;
    }
    _DAT_00805ff4 = 0;
    _DAT_00805ff8 = 0;
    _DAT_00805ff6 = 0;
  }
  if (((_DAT_0080385e != 0) && (_DAT_0080d17a == 0)) && ((_DAT_008035d4 & 0x80) != 0)) {
    if (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x100) == 0) ||
       ((_DAT_008068cc & 0x100) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x200) == 0) ||
         ((_DAT_008068cc & 0x200) == 0)) {
        if (_DAT_008071ae < _DAT_008096a6) {
          if ((_DAT_00809762 & 1) != 0) {
            if (_DAT_008032e2 < _DAT_0080971c) {
              uVar3 = _DAT_0080971c - _DAT_008032e2;
            }
            else {
              uVar3 = _DAT_008032e2 - _DAT_0080971c;
            }
            if (_DAT_008071e6 < uVar3) {
              if (_DAT_00805fec == 0) {
                _DAT_00805fec = 1;
                _DAT_008032e4 = _DAT_0080972e;
              }
              else {
                _DAT_008032e2 = _DAT_0080971c;
              }
            }
            if (_DAT_00805fec != 0) {
              if (_DAT_008071e4 < _DAT_00805fec) {
                if (_DAT_00805ff0 < _DAT_008071e0) {
                  _DAT_00805ff2 = _DAT_00805ff2 + 1;
                  if (_DAT_008071de < _DAT_00805ff2) {
                    fault_status_registers_t_00805df2.io_fault_status_1 =
                         fault_status_registers_t_00805df2.io_fault_status_1 | 0x200;
                    fault_latch_registers_t_00805e32.io_fault_latch_1 =
                         fault_latch_registers_t_00805e32.io_fault_latch_1 | 0x200;
                    _DAT_00805fe4 = 3;
                    _DAT_008096ae = _DAT_0080387e;
                  }
                  else {
                    _DAT_00805fec = 0;
                    _DAT_00805ff0 = 0;
                  }
                }
                else {
                  _DAT_00805fec = 0;
                  _DAT_00805ff0 = 0;
                }
              }
              else {
                _DAT_00805fec = _DAT_00805fec + 1;
                if (_DAT_0080d0c8 < _DAT_008071e2) {
                  _DAT_00805ff0 = _DAT_00805ff0 + 1;
                }
                if (_DAT_008032e4 < _DAT_0080972e) {
                  uVar3 = _DAT_0080972e - _DAT_008032e4;
                }
                else {
                  uVar3 = _DAT_008032e4 - _DAT_0080972e;
                }
                if (_DAT_008071f4 < uVar3) {
                  _DAT_00805fec = 0;
                  _DAT_00805ff2 = 0;
                  _DAT_00805ff0 = 0;
                  _DAT_008032e4 = _DAT_0080972e;
                  _DAT_008032e2 = _DAT_0080971c;
                }
              }
            }
          }
          if ((_DAT_00809762 & 4) != 0) {
            puVar5 = &DAT_008032ee;
            wVar4 = circular_buffer_t_0080c3fc.current_engine_rpm;
            _DAT_008032e6 = coreTableInterpolation();
            _DAT_008032e8 = coreTableInterpolation(0x80,wVar4,puVar5);
            if (_DAT_008071ee < _DAT_00805fe6) {
              fault_status_registers_t_00805df2.io_fault_status_1 =
                   fault_status_registers_t_00805df2.io_fault_status_1 | 0x200;
              fault_latch_registers_t_00805e32.io_fault_latch_1 =
                   fault_latch_registers_t_00805e32.io_fault_latch_1 | 0x200;
              _DAT_00805fe4 = 4;
              _DAT_008096ae = _DAT_0080387e;
            }
            else if (((_DAT_008096aa == 0) || (_DAT_008032e6 <= _DAT_00809764)) ||
                    (_DAT_008032e8 <= _DAT_008071f0)) {
              _DAT_00805fe6 = 0;
            }
            else {
              _DAT_00805fe6 = _DAT_00805fe6 + 1;
            }
          }
          if ((_DAT_00809762 & 2) != 0) {
            puVar5 = &DAT_008032fe;
            wVar4 = circular_buffer_t_0080c3fc.current_engine_rpm;
            _DAT_008032ea = coreTableInterpolation();
            _DAT_008032ec = coreTableInterpolation(0x80,wVar4,puVar5);
            if (_DAT_008071f8 < _DAT_00805fe8) {
              fault_status_registers_t_00805df2.io_fault_status_1 =
                   fault_status_registers_t_00805df2.io_fault_status_1 | 0x200;
              fault_latch_registers_t_00805e32.io_fault_latch_1 =
                   fault_latch_registers_t_00805e32.io_fault_latch_1 | 0x200;
              _DAT_00805fe4 = 5;
              _DAT_008096ae = _DAT_0080387e;
            }
            else if (((_DAT_0080971c == _DAT_00803312) || (_DAT_0080971c == _DAT_00803314)) ||
                    (((_DAT_0080971c == _DAT_0080330e ||
                      ((_DAT_0080971c == _DAT_00803310 || (_DAT_008032ea <= _DAT_00809764)))) ||
                     (_DAT_008032ec <= _DAT_008071f0)))) {
              _DAT_00805fe8 = 0;
            }
            else {
              _DAT_00805fe8 = _DAT_00805fe8 + 1;
            }
          }
        }
        else {
          FUN_0002ee28();
        }
      }
      else if ((_DAT_008071f2 < _DAT_00805fee) ||
              ((((_DAT_00809762 & 1) == 0 && ((_DAT_00809762 & 2) == 0)) &&
               ((_DAT_00809762 & 4) == 0)))) {
        if (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x200) != 0) &&
           ((fault_latch_registers_t_00805e32.io_fault_latch_1 & 0x200) == 0)) {
          fault_status_registers_t_00805df2.io_fault_status_1 =
               fault_status_registers_t_00805df2.io_fault_status_1 & 0xfdff;
          _DAT_008096ae = _DAT_008037b4;
          FUN_0002ee28();
        }
      }
      else if (_DAT_008096a6 == 0 && circular_buffer_t_0080c3fc.data_buffer_8 == 0) {
        _DAT_00805fee = _DAT_00805fee + 1;
      }
      else {
        _DAT_00805fee = 0;
      }
      goto LAB_0002f5b6;
    }
  }
  if ((((_DAT_008035d4 & 0x80) == 0) &&
      ((fault_status_registers_t_00805df2.io_fault_status_1 & 0x200) != 0)) &&
     ((fault_latch_registers_t_00805e32.io_fault_latch_1 & 0x200) == 0)) {
    fault_status_registers_t_00805df2.io_fault_status_1 =
         fault_status_registers_t_00805df2.io_fault_status_1 & 0xfdff;
    _DAT_008096ae = _DAT_008037b4;
  }
  FUN_0002ee28();
LAB_0002f5b6:
  DAT_008032dd = -((DAT_0080bdc7 & 8) != 0) & 1;
  DAT_008032de = -((DAT_0080bdc7 & 4) != 0) & 1;
  _DAT_008032e0 = _DAT_00809d50;
  return;
}



//
// Function: FUN_0002f5f2 @ 0x0002f5f2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002f5f2(void)

{
  _DAT_008032f2 = 0;
  _DAT_008032ee = 0x8071ec;
  _DAT_008032fa = 0;
  _DAT_008032f6 = 0x8071ec;
  _DAT_00803302 = 0;
  _DAT_008032fe = 0x8071f6;
  _DAT_0080330a = 0;
  _DAT_00803306 = 0x8071f6;
  _DAT_008032e2 = 0x7ffd;
  _DAT_00809762 =
       *(undefined2 *)
        ((uint)(byte)((byte)_DAT_00803874 | (char)_DAT_00803876 * '\x02') * 2 + 0x8071fc);
  return;
}



//
// Function: oilPressureFuelArbitrationMonitor @ 0x0002f662
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort oilPressureFuelArbitrationMonitor(void)

{
  ushort uVar1;
  
  uVar1 = _DAT_00809766;
  if (_DAT_0080d17a == 1) {
    if ((engine_control_flags_t_008035d6.protection_system & 0x8000) == 0) {
      _DAT_00809766 = 0;
      _DAT_008096ac = _DAT_008037b4;
      return engine_control_flags_t_008035d6.protection_system & 0x8000;
    }
    if (_DAT_00807204 <= _DAT_008096a6) {
      _DAT_00809766 = 0;
      _DAT_008096ac = _DAT_008037b4;
      return _DAT_008096a6;
    }
    if (_DAT_00809766 <= _DAT_00807206) {
      _DAT_00809766 = _DAT_00809766 + 1;
      return uVar1;
    }
    _DAT_008096ac = _DAT_0080387e;
    return _DAT_00809766;
  }
  if ((engine_control_flags_t_008035d6.protection_system & 0x8000) != 0) {
    if (_DAT_00807204 <= _DAT_008096a6) {
      _DAT_00809766 = 0;
      _DAT_008096ac = _DAT_008037b4;
      return _DAT_008096a6;
    }
    if (_DAT_00809766 <= _DAT_00807206) {
      _DAT_00809766 = _DAT_00809766 + 1;
      return uVar1;
    }
    _DAT_008096ac = _DAT_0080387e;
    return _DAT_00809766;
  }
  if (_DAT_00807204 <= _DAT_008096a6) {
    _DAT_00809766 = 0;
    _DAT_008096ac = _DAT_008037b4;
    return _DAT_008096a6;
  }
  if (_DAT_00809766 <= _DAT_00807206) {
    _DAT_00809766 = _DAT_00809766 + 1;
    return uVar1;
  }
  _DAT_008096ac = _DAT_0080387e;
  return _DAT_00809766;
}



//
// Function: FUN_0002f748 @ 0x0002f748
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002f748(void)

{
  _DAT_008096ac = _DAT_008037b4;
  return;
}



//
// Function: FUN_0002f754 @ 0x0002f754
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002f754(void)

{
  if (_DAT_00808a74 < fuel_demand_state_t_0080c9a4.limit_minimum) {
    _DAT_0080d488 = fuel_demand_state_t_0080c9a4.limit_minimum;
    fuel_demand_state_t_0080c9a4.limit_minimum = _DAT_00808a74;
    fuel_demand_state_t_0080c9a4.demand_source_id = 4;
  }
  return;
}



//
// Function: FUN_0002f778 @ 0x0002f778
//

void FUN_0002f778(void)

{
  FUN_00030cb0();
  timingAccumulatorUpdate();
  fuelAdjustmentWithFlagUpdate();
  timingAccumulatorClampedUpdate();
  FUN_0002bc06();
  fuelLimitMinimumSelector();
  FUN_0002f754();
  engineModeTransitionStateUpdater();
  FUN_000317c2();
  return;
}



//
// Function: diagnosticModeFuelArbitrationHandler @ 0x0002f7ac
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticModeFuelArbitrationHandler(void)

{
  _DAT_0080d486 = fuel_demand_state_t_0080c9a4.limit_minimum;
  if (fuel_demand_state_t_0080c9a4._2_2_ == 0x1b) {
    _DAT_0080d482 = _DAT_00808a76;
    _DAT_0080c9b4 = 10;
    fuel_demand_state_t_0080c9a4.adjustment_active = 0;
  }
  else if (fuel_demand_state_t_0080c9a4._2_2_ == 0x19) {
    _DAT_0080d482 = _DAT_00808a70;
    _DAT_0080c9b4 = 9;
    fuel_demand_state_t_0080c9a4.adjustment_active = 0;
  }
  else if (fuel_demand_state_t_0080c9a4._2_2_ == 0x1a) {
    _DAT_0080d482 = 0;
    _DAT_0080c9b4 = 8;
    fuel_demand_state_t_0080c9a4.adjustment_active = 0;
  }
  else if ((engine_control_flags_t_008035d6.fuel_demand_control & 8) == 0) {
    _DAT_0080d482 = fuel_demand_state_t_0080c9a4.limit_minimum;
    _DAT_0080c9b4 = fuel_demand_state_t_0080c9a4.demand_source_id;
  }
  else {
    _DAT_0080d482 = _DAT_0080381a;
    _DAT_0080c9b4 = 7;
    fuel_demand_state_t_0080c9a4.adjustment_active = 0;
  }
  _DAT_0080d48a = fuel_demand_state_t_0080c9a4.adjustment_active;
  fuel_demand_state_t_0080c9a4.adjustment_active = 0;
  return;
}



//
// Function: FUN_0002f83e @ 0x0002f83e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002f83e(void)

{
  if (_DAT_0080d498 < _DAT_0080d494) {
    _DAT_0080d494 = _DAT_0080d498;
    _DAT_0080d496 = 0x1c;
  }
  return;
}



//
// Function: FUN_0002f85c @ 0x0002f85c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002f85c(void)

{
  if ((fuel_arbitrator_diag_t_0080cff8.rpm_target == 3) &&
     (fuel_arbitrator_diag_t_0080cff8.prev_state_pointer._1_2_ < _DAT_0080d494)) {
    _DAT_0080d494 = fuel_arbitrator_diag_t_0080cff8.prev_state_pointer._1_2_;
    _DAT_0080d496 = 0x14;
  }
  return;
}



//
// Function: shutdownMinimumSelectorOrchestrator @ 0x0002f884
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void shutdownMinimumSelectorOrchestrator(void)

{
  _DAT_0080d494 = _DAT_00807f3c;
  shutdownMinimumSelector17();
  shutdownMinimumSelector16();
  shutdownMinimumSelector15();
  shutdownMinimumSelector19();
  shutdownMinimumSelector29();
  FUN_0002f85c();
  FUN_0002f83e();
  FUN_0002de68();
  return;
}



//
// Function: masterSubsystemInit @ 0x0002f8b8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void masterSubsystemInit(void)

{
  fuelParameterPointerSetup();
  timingParameterPointerSetup();
  dmaDescriptorSetup1();
  fuelLimitParameterPointerSetup();
  _DAT_0080d498 = _DAT_00807f3c;
  return;
}



//
// Function: FUN_0002f8dc @ 0x0002f8dc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002f8dc(void)

{
  short sVar1;
  short sVar2;
  
  _DAT_0080331c = _DAT_00809d1a;
  _DAT_00803328 = _DAT_0080926e;
  sVar1 = lookupTableInterpolation((short *)&DAT_00803322);
  sVar2 = lookupTableInterpolation((short *)&DAT_00803316);
  _DAT_00809768 = sVar1 + sVar2;
  return;
}



//
// Function: FUN_0002f920 @ 0x0002f920
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002f920(void)

{
  _DAT_0080331c = _DAT_00809d1a;
  _DAT_00803318 = 0x80720a;
  _DAT_0080331e = 0x80721e;
  _DAT_00803316 = 2;
  _DAT_00803328 = _DAT_0080926e;
  _DAT_00803324 = 0x807232;
  _DAT_0080332a = 0x807246;
  _DAT_00803322 = 2;
  return;
}



//
// Function: vp44ExtendedProcessingRouter @ 0x0002f96e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44ExtendedProcessingRouter(void)

{
  if (_DAT_0080374e != 0) {
    FUN_0002d43e();
    return;
  }
  FUN_0002f9e0();
  return;
}



//
// Function: FUN_0002f986 @ 0x0002f986
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002f986(void)

{
  if (_DAT_0080374e != 0) {
    FUN_0002d688();
    return;
  }
  _DAT_00803332 = 0;
  _DAT_0080333c = 0;
  _DAT_008096b4 = 0;
  _DAT_0080333a = 0;
  _DAT_00803330 = 4;
  _DAT_00803338 = 4;
  _DAT_00803336 = 4;
  _DAT_0080333e = 4;
  _DAT_00803334 = 0;
  _DAT_0080332e = _DAT_0080734e;
  return;
}



//
// Function: FUN_0002f9e0 @ 0x0002f9e0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002f9e0(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  _DAT_00803336 = FUN_0002fa84();
  _DAT_00803332 = FUN_0002fb08();
  uVar1 = FUN_0002fcc8();
  _DAT_008096b6 = (undefined2)uVar1;
  uVar2 = FUN_0002fb28();
  if ((short)uVar2 == 0) {
    if (_DAT_00803336 == 2) {
      _DAT_008096b6 = FUN_0002fbc8();
    }
    else if (_DAT_00803336 == 1) {
      uVar2 = FUN_0002fc40();
      _DAT_008096b6 = (undefined2)uVar2;
    }
    else {
      uVar1 = FUN_0002fc76();
      if ((short)uVar1 != 0) {
        _DAT_008096b6 = FUN_0002fcac();
      }
    }
  }
  else {
    uVar2 = FUN_0002fba2();
    if ((short)uVar2 == 0) {
      _DAT_008096b6 = 8;
    }
    else {
      _DAT_008096b6 = 0;
    }
  }
  _DAT_00803338 = _DAT_00803330;
  _DAT_0080333a = _DAT_008096b4;
  _DAT_0080333c = _DAT_00803332;
  _DAT_0080333e = _DAT_00803336;
  return;
}



//
// Function: FUN_0002fa84 @ 0x0002fa84
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short FUN_0002fa84(void)

{
  _DAT_00803330 = _DAT_0080938c;
  if (_DAT_0080734c < 2) {
    return _DAT_0080938c;
  }
  if (_DAT_0080938c == _DAT_0080333e) {
    _DAT_00803334 = 2;
    return _DAT_0080333e;
  }
  if (_DAT_0080938c != _DAT_00803338) {
    if (1 < _DAT_00803334) {
      _DAT_00803334 = _DAT_00803334 - 1;
      return _DAT_0080333e;
    }
    return 4;
  }
  if ((int)(uint)_DAT_00803334 < (int)(_DAT_0080734c - 1)) {
    _DAT_00803334 = _DAT_00803334 + 1;
    return 4;
  }
  return _DAT_0080938c;
}



//
// Function: FUN_0002fb08 @ 0x0002fb08
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_0002fb08(void)

{
  if (_DAT_00803336 == 5) {
    return 1;
  }
  if (_DAT_00803336 == 0) {
    return 0;
  }
  return _DAT_0080333c;
}



//
// Function: FUN_0002fb28 @ 0x0002fb28
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0002fb28(void)

{
  if (((((((engine_control_flags_t_008035d6.engine_operating_state & 0x40) != 0) &&
         (_DAT_00803332 != 0)) && (_DAT_00807944 <= _DAT_008096f8)) &&
       (((DAT_0080bdc7 & 4) == 0 && (_DAT_0080709a < circular_buffer_t_0080c3fc.current_engine_rpm))
       )) && (((DAT_0080bdc7 & 8) == 0 && ((_DAT_0080971e == 0 || (_DAT_0080711e == 0)))))) &&
     ((_DAT_008096b4 != 2 && (_DAT_008096b4 != 1)))) {
    return 0;
  }
  return 1;
}



//
// Function: FUN_0002fba2 @ 0x0002fba2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0002fba2(void)

{
  if ((((engine_control_flags_t_008035d6.engine_operating_state & 0x40) != 0) &&
      (_DAT_00803332 != 0)) && (_DAT_008096fc != 0)) {
    return 0;
  }
  return 1;
}



//
// Function: FUN_0002fbc8 @ 0x0002fbc8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_0002fbc8(void)

{
  undefined2 uVar1;
  
  uVar1 = _DAT_008096b6;
  if (_DAT_0080969a == 0) {
    if (_DAT_0080711c <= _DAT_008096f8) {
      uVar1 = 1;
    }
  }
  else if (_DAT_0080333e == 2) {
    if (_DAT_0080332e == 0) {
      uVar1 = 4;
    }
    else {
      _DAT_0080332e = _DAT_0080332e + -1;
    }
  }
  else {
    _DAT_0080332e = _DAT_0080734e;
    if ((int)((uint)_DAT_008096f8 - (uint)_DAT_0080969c) < (int)(uint)_DAT_00807350) {
      uVar1 = 6;
    }
    else if (_DAT_0080711c <= _DAT_008096f8) {
      uVar1 = 1;
    }
  }
  return uVar1;
}



//
// Function: FUN_0002fc40 @ 0x0002fc40
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0002fc40(void)

{
  undefined2 uVar1;
  undefined4 in_D0;
  undefined2 uVar2;
  
  uVar1 = (undefined2)((uint)in_D0 >> 0x10);
  uVar2 = _DAT_008096b6;
  if (_DAT_0080969a != 0) {
    if (_DAT_0080333e == 1) {
      if (_DAT_0080332e == 0) {
        uVar1 = 0;
        uVar2 = 3;
      }
      else {
        _DAT_0080332e = _DAT_0080332e + -1;
      }
    }
    else {
      _DAT_0080332e = _DAT_0080734e;
      uVar1 = 0;
      uVar2 = 5;
    }
  }
  return CONCAT22(uVar1,uVar2);
}



//
// Function: FUN_0002fc76 @ 0x0002fc76
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0002fc76(void)

{
  uint in_D0;
  
  if (((_DAT_00803336 != 3) && ((_DAT_0080333a == 4 || (_DAT_008096b4 != 4)))) &&
     ((_DAT_0080333a == 3 || (_DAT_008096b4 != 3)))) {
    return in_D0 & 0xffff0000;
  }
  return 1;
}



//
// Function: FUN_0002fcac @ 0x0002fcac
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_0002fcac(void)

{
  if ((_DAT_0080969a == 0) && (_DAT_008096fc != 0)) {
    return 2;
  }
  return _DAT_008096b6;
}



//
// Function: FUN_0002fcc8 @ 0x0002fcc8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0002fcc8(void)

{
  uint in_D0;
  
  if (_DAT_0080969a != 0) {
    return 7;
  }
  if (_DAT_008096fc != 0) {
    return 8;
  }
  return in_D0 & 0xffff0000;
}



//
// Function: diagnosticFuelOverrideHandler @ 0x0002fce4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticFuelOverrideHandler(void)

{
  if (((_DAT_00803342 == 9) && (diagnostic_state_buffer_t_00809654.diagnostic_mode == 8)) &&
     (_DAT_00809652 < _DAT_00803344)) {
    _DAT_00803340 = _DAT_00803344;
  }
  if (_DAT_0080725a < _DAT_00803340) {
    _DAT_00803340 = _DAT_00803340 - _DAT_0080725a;
  }
  else {
    _DAT_00803340 = 0;
  }
  if (((_DAT_00809652 < _DAT_00803340) && (diagnostic_state_buffer_t_00809654.diagnostic_mode == 8))
     && ((_DAT_008096aa == 0 || (_DAT_0080725c != 0)))) {
    _DAT_00809652 = _DAT_00803340;
  }
  _DAT_00803342 = diagnostic_state_buffer_t_00809654.diagnostic_mode;
  _DAT_00803344 = fuel_demand_state_t_0080c9a4.command;
  return;
}



//
// Function: FUN_0002fd5e @ 0x0002fd5e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002fd5e(void)

{
  _DAT_00803340 = 0;
  _DAT_00803342 = 8;
  _DAT_00803344 = 0;
  return;
}



//
// Function: vp44InjectionTimingSlowCycle40Coordinator @ 0x0002fd74
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44InjectionTimingSlowCycle40Coordinator(void)

{
  bool bVar1;
  
  if (_DAT_0080969e == 1) {
    _DAT_0080976c = 0;
  }
  if (_DAT_0080976c < _DAT_0080725e) {
    _DAT_0080976c = _DAT_0080976c + 1;
    if (((fault_status_registers_t_00805df2.sensor_fault_status & 0x8000) == 0) ||
       ((_DAT_008068c4 & 0x8000) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (((fault_status_registers_t_00805df2.io_fault_status_3 & 0x1000) == 0) ||
         ((_DAT_008068d0 & 0x1000) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        _DAT_0080976a = _DAT_008068ec;
        goto LAB_0002fdf2;
      }
    }
    _DAT_0080976a = _DAT_00803348;
  }
  else {
    _DAT_0080976a = _DAT_008091ea;
  }
LAB_0002fdf2:
  _DAT_00803346 = (uint)_DAT_0080976a;
  return;
}



//
// Function: FUN_0002fdfe @ 0x0002fdfe
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002fdfe(void)

{
  _DAT_0080976a = _DAT_008091ea;
  _DAT_00803346 = (uint)_DAT_008091ea;
  _DAT_0080976c = _DAT_0080725e;
  return;
}



//
// Function: engineModeOutputControlInit @ 0x0002fe20
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort engineModeOutputControlInit(void)

{
  if ((_DAT_00803614 & 0x40) != 0) {
    _DAT_00809a04 = 0;
    DAT_0080bdef = DAT_0080bdef & 0xf9;
    DAT_00809a03 = 1;
    _DAT_00809a0a = 0;
    _DAT_00809a0c = 0;
    _DAT_0080334e = 0;
    _DAT_00803350 = 0;
    _DAT_008033b6 = 10;
    _DAT_008033b8 = 0;
    _DAT_00803370 = 0x807292;
    _DAT_00803368 = 2;
    _DAT_0080336a = 0x807278;
    _DAT_0080338c = 2;
    _DAT_0080338e = 0x8072ac;
    _DAT_00803394 = 2;
    _DAT_00803396 = 0x8072bc;
    _DAT_0080339c = 0x8072c6;
    _DAT_0080337c = 0x807318;
    _DAT_00803374 = 2;
    _DAT_00803376 = 0x8072fe;
    _DAT_00803388 = 0x80733e;
    _DAT_00803380 = 2;
    _DAT_00803382 = 0x807332;
  }
  return _DAT_00803614 & 0x40;
}



//
// Function: engineModeOutputControlStateMachine @ 0x0002ff3a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint engineModeOutputControlStateMachine(void)

{
  bool bVar1;
  undefined4 in_D0;
  uint uVar2;
  uint uVar3;
  
  if ((_DAT_00803614 & 0x40) == 0) {
    return CONCAT22((short)((uint)in_D0 >> 0x10),_DAT_00803614) & 0xffff0040;
  }
  if ((_DAT_00807272 < _DAT_008096a6) && (_DAT_00809a04 == 4)) {
    _DAT_00809a0c = 2;
    _DAT_00809a04 = 5;
    goto LAB_000300ac;
  }
  if (((fault_status_registers_t_00805df2.io_fault_status_2 & 0x1000) == 0) ||
     ((_DAT_008068ce & 0x1000) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
LAB_0002ffea:
    _DAT_00809a0c = 3;
    _DAT_00809a04 = 5;
  }
  else {
    if (((fault_status_registers_t_00805df2.io_fault_status_2 & 0x800) == 0) ||
       ((_DAT_008068ce & 0x800) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) goto LAB_0002ffea;
    if (((_DAT_00807268 < _DAT_00809308) && (_DAT_00809a04 != 0)) && (_DAT_00809a04 != 3)) {
      _DAT_00809a04 = 5;
    }
  }
  if ((_DAT_00803356 == 0) && (_DAT_00809a04 == 3)) {
    _DAT_00809a0c = 4;
    _DAT_00809a04 = 5;
  }
  else {
    if (((engine_operating_mode_t_0080c810.state == 8) ||
        (engine_operating_mode_t_0080c810.state == 1)) &&
       ((_DAT_00809a04 == 4 || (_DAT_00809a04 == 3)))) {
      _DAT_00803362 = _DAT_00803362 + 1;
    }
    else {
      _DAT_00803362 = 0;
    }
    if ((_DAT_008033b6 <= _DAT_00803362) && ((_DAT_00809a04 == 3 || (_DAT_00809a04 == 4)))) {
      _DAT_00809a04 = 2;
    }
  }
  if (_DAT_00809a04 == 0) {
    _DAT_00809a04 = 1;
  }
  else if (_DAT_00809a04 == 1) {
    _DAT_00809a04 = 2;
  }
  else if (((engine_operating_mode_t_0080c810.state == 2) ||
           (engine_operating_mode_t_0080c810.state == 6)) && (_DAT_00809a04 == 2)) {
    _DAT_00809a04 = 3;
  }
  else if ((((engine_operating_mode_t_0080c810.state == 3) ||
            (engine_operating_mode_t_0080c810.state == 4)) ||
           ((engine_operating_mode_t_0080c810.state == 7 ||
            (engine_operating_mode_t_0080c810.state == 5)))) &&
          ((_DAT_00809a04 == 2 || (_DAT_00809a04 == 3)))) {
    _DAT_00809a04 = 4;
  }
LAB_000300ac:
  uVar2 = (uint)_DAT_00809a04;
  uVar3 = uVar2;
  if (uVar2 < 6) {
    uVar3 = CONCAT22(_DAT_00809a04 >> 0xf,(&switchD_000300ba::switchdataD_000300be)[uVar2]);
    switch(uVar2) {
    case 1:
      uVar3 = outputControlState1Handler();
      break;
    case 2:
      uVar3 = outputControlState2Handler();
      break;
    case 3:
      uVar3 = outputControlState3Handler();
      break;
    case 4:
      uVar3 = outputControlState4Handler();
      break;
    case 5:
      uVar3 = outputControlState5FaultHandler();
    }
  }
  if (_DAT_00809a0a == 1) {
    DAT_0080bdef = DAT_0080bdef & 0xfb | 2;
  }
  else if (_DAT_00809a0a == 2) {
    DAT_0080bdef = DAT_0080bdef & 0xfd | 4;
  }
  else if (_DAT_00809a0a == 3) {
    DAT_0080bdef = DAT_0080bdef | 6;
  }
  else if (_DAT_00809a0a == 4) {
    DAT_0080bdef = DAT_0080bdef & 0xf9;
  }
  if (((_DAT_00809a0a == 1) || (_DAT_00809a0a == 2)) || (_DAT_00809a0a == 3)) {
    if (((_DAT_0080334e != 1) && (_DAT_0080334e != 2)) && (_DAT_0080334e != 3)) {
      _DAT_0080335a = _DAT_00807266;
    }
    if (_DAT_0080335a == 0) {
      DAT_0080bdef = DAT_0080bdef & 0xf9;
    }
    else {
      _DAT_0080335a = _DAT_0080335a + -1;
    }
  }
  _DAT_00803350 = _DAT_00809a04;
  _DAT_0080334e = _DAT_00809a0a;
  return uVar3;
}



//
// Function: outputControlState1Handler @ 0x000301a6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void outputControlState1Handler(void)

{
  _DAT_0080337a = _DAT_00809a10;
  _DAT_008033ac = lookupTableInterpolation((short *)&DAT_00803374);
  if (_DAT_008033ac != 0) {
    _DAT_00803352 = _DAT_008033ac;
    DAT_0080bdef = DAT_0080bdef | 6;
    DAT_0080bdf1 = DAT_0080bdf1 | 4;
    DAT_00809a03 = DAT_00809a03 & 0xfe;
    DAT_00809a03 = DAT_00809a03 | 2;
    DAT_00803366 = 0;
    return;
  }
  _DAT_00809a0c = 6;
  DAT_0080bdef = DAT_0080bdef & 0xf9;
  DAT_00803366 = 1;
  return;
}



//
// Function: outputControlState2Handler @ 0x00030226
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void outputControlState2Handler(void)

{
  if ((DAT_00809a03 & 0x10) != 0) {
    DAT_00809a03 = DAT_00809a03 & 0xef;
    DAT_00809a03 = DAT_00809a03 | 0x40;
  }
  if ((DAT_00809a03 & 0x20) != 0) {
    DAT_00809a03 = DAT_00809a03 & 0xdf;
    DAT_00809a03 = DAT_00809a03 | 0x40;
  }
  if (_DAT_00803352 == 0) {
    DAT_0080bdef = DAT_0080bdef & 0xf9;
    if (DAT_00803366 == '\0') {
      DAT_0080bdf1 = DAT_0080bdf1 & 0xfb;
    }
    if (_DAT_008033ac != 0) {
      DAT_00809a03 = DAT_00809a03 & 0xfd;
      DAT_00809a03 = DAT_00809a03 | 8;
    }
  }
  else {
    DAT_0080bdef = DAT_0080bdef | 6;
    DAT_0080bdf1 = DAT_0080bdf1 | 4;
    _DAT_00803352 = _DAT_00803352 + -1;
  }
  _DAT_00803356 = _DAT_00807260;
  _DAT_00803364 = 100;
  return;
}



//
// Function: outputControlState3Handler @ 0x000302c6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void outputControlState3Handler(void)

{
  DAT_0080bdef = DAT_0080bdef & 0xf9;
  DAT_0080bdf1 = DAT_0080bdf1 & 0xfb;
  if (_DAT_00803356 != 0) {
    _DAT_00803356 = _DAT_00803356 + -1;
  }
  if ((DAT_00809a03 & 2) != 0) {
    DAT_00809a03 = DAT_00809a03 & 0xfd;
    DAT_00809a03 = DAT_00809a03 | 4;
  }
  DAT_00809a03 = DAT_00809a03 | 0x10;
  _DAT_00803352 = 0;
  return;
}



//
// Function: outputControlState4Handler @ 0x00030314
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void outputControlState4Handler(void)

{
  bool bVar1;
  byte bVar2;
  undefined2 *puVar3;
  undefined8 uVar4;
  
  if ((_DAT_00803350 != 4) && (DAT_0080bdf1 = DAT_0080bdf1 & 0xfb, _DAT_00804a0a != 0)) {
    _DAT_00809a0c = 8;
    _DAT_00804a0a = _DAT_00804a0a + -1;
    outputControlState5FaultHandler();
    return;
  }
  if (_DAT_008033b8 == 0) {
    bVar1 = (uint)_DAT_00809a10 <= (uint)_DAT_00807270 + (uint)_DAT_00809a12;
    if (bVar1) {
      _DAT_008033b4 = _DAT_00809a10;
    }
    else {
      _DAT_008033b4 = _DAT_00809a12;
    }
    DAT_00809a0e = !bVar1;
    _DAT_0080336e = _DAT_008033b4;
    _DAT_00809a06 = lookupTableInterpolation((short *)&DAT_00803368);
    if (_DAT_00809a06 == 6) {
      if (_DAT_00803364 != 0) {
        _DAT_00803364 = _DAT_00803364 + -1;
      }
      if (_DAT_00803364 == 0) {
        _DAT_00809a0c = 6;
        outputControlState5FaultHandler();
        return;
      }
      DAT_0080bdef = DAT_0080bdef & 0xf9;
      return;
    }
    if ((_DAT_00807274 < _DAT_0080926e) && (_DAT_00807276 < _DAT_008033b4)) {
      _DAT_00809a0c = 7;
      outputControlState5FaultHandler();
      return;
    }
    bVar2 = 0;
    puVar3 = (undefined2 *)&DAT_008033a2;
    do {
      _DAT_00803392 = _DAT_00809a06;
      _DAT_0080339a = (ushort)bVar2;
      uVar4 = tableInterpolationLookup((short *)&DAT_0080338c);
      *puVar3 = (short)((ulonglong)uVar4 >> 0x20);
      bVar2 = bVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (bVar2 < 5);
    _DAT_0080334c = 6;
    _DAT_008033a0 = 0;
    _DAT_0080334a = 1;
    _DAT_00803358 = 0;
    _DAT_00803354 = 0;
    _DAT_00809a08 = 2;
    _DAT_008033b8 = 1;
  }
  else {
    _DAT_00803358 = _DAT_00803358 + 1;
  }
  DAT_00809a03 = DAT_00809a03 & 0xee;
  DAT_00809a03 = DAT_00809a03 | 0x20;
  if (_DAT_00807262 <= fuel_demand_state_t_0080c9a4.command) {
    _DAT_00803354 = _DAT_00803354 + 1;
  }
  if (_DAT_00803354 < _DAT_00807264) {
    if (((_DAT_00809a06 == 0) || (_DAT_00809a06 == 1)) || (_DAT_00809a06 == 2)) {
      FUN_00030542();
    }
    else {
      FUN_00030578();
    }
    if (_DAT_008033a0 == 4) {
      DAT_00809a03 = DAT_00809a03 & 0xdf;
      DAT_00809a03 = DAT_00809a03 | 0x80;
      outputControlState5FaultHandler();
    }
    else {
      FUN_0003068a();
    }
  }
  else {
    _DAT_00809a0c = 9;
    outputControlState5FaultHandler();
  }
  _DAT_0080334c = _DAT_008033a0;
  return;
}



//
// Function: FUN_00030542 @ 0x00030542
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00030542(void)

{
  if (_DAT_0080334a == 0) {
    if (_DAT_0080334c == 0) {
      _DAT_008033a0 = 1;
      return;
    }
    if (_DAT_0080334c == 1) {
      _DAT_008033a0 = 2;
      return;
    }
    if (_DAT_0080334c == 2) {
      _DAT_008033a0 = 4;
    }
  }
  return;
}



//
// Function: FUN_00030578 @ 0x00030578
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00030578(void)

{
  undefined2 uVar1;
  undefined4 in_D0;
  uint uVar2;
  
  uVar1 = (undefined2)((uint)in_D0 >> 0x10);
  uVar2 = CONCAT22(uVar1,_DAT_0080334a | _DAT_0080334c);
  if ((_DAT_0080334a | _DAT_0080334c) == 0) {
    uVar2 = CONCAT22(uVar1,circular_buffer_t_0080c3fc.data_buffer_8);
    if (_DAT_0080726c < circular_buffer_t_0080c3fc.data_buffer_8) {
      _DAT_008033a0 = 1;
      return uVar2;
    }
    _DAT_008033a0 = 2;
    return uVar2;
  }
  if (_DAT_0080334c == 1) {
    if (_DAT_0080334a == 0) {
      _DAT_008033a0 = 3;
      return uVar2;
    }
    uVar2 = (uint)_DAT_0080726c - (uint)_DAT_0080726e;
    if ((int)(uint)circular_buffer_t_0080c3fc.data_buffer_8 < (int)uVar2) {
      _DAT_008033a0 = 2;
      return uVar2;
    }
  }
  else if (_DAT_0080334c == 2) {
    if (_DAT_0080334a == 0) {
      _DAT_008033a0 = 4;
      return uVar2;
    }
    uVar2 = (uint)_DAT_0080726e + (uint)_DAT_0080726c;
    if (uVar2 < circular_buffer_t_0080c3fc.data_buffer_8) {
      uVar2 = (uint)_DAT_008033a4 + (uint)_DAT_008033a2;
      if ((uint)_DAT_00803358 < (uint)_DAT_008033a4 + (uint)_DAT_008033a2) {
        _DAT_008033a0 = 1;
        return uVar2;
      }
      _DAT_008033a0 = 3;
      return uVar2;
    }
  }
  else if (_DAT_0080334c == 3) {
    if (_DAT_0080334a == 0) {
      _DAT_008033a0 = 4;
      return uVar2;
    }
    uVar2 = (uint)_DAT_0080726c - (uint)_DAT_0080726e;
    if ((int)(uint)circular_buffer_t_0080c3fc.data_buffer_8 < (int)uVar2) {
      _DAT_008033a0 = 2;
    }
  }
  return uVar2;
}



//
// Function: FUN_0003068a @ 0x0003068a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0003068a(void)

{
  bool bVar1;
  
  if (_DAT_008033a0 == _DAT_0080334c) {
    DAT_008033b0 = 0;
    bVar1 = false;
  }
  else {
    if ((((_DAT_00809a06 == 0) || (_DAT_00809a06 == 1)) || (_DAT_00809a06 == 2)) ||
       (_DAT_008033a0 == 0)) {
      _DAT_008033b2 = *(short *)(&DAT_008033a2 + _DAT_008033a0 * 2);
    }
    else if (((_DAT_00809a06 == 3) || (_DAT_00809a06 == 4)) || (_DAT_00809a06 == 5)) {
      if (_DAT_008033a0 == 1) {
        _DAT_008033b2 = (_DAT_008033a4 + _DAT_008033a2) - _DAT_00803358;
      }
      else if (_DAT_008033a0 == 2) {
        _DAT_008033b2 = (_DAT_008033a6 + _DAT_008033a2) - _DAT_00803358;
      }
      else if (_DAT_008033a0 == 3) {
        _DAT_008033b2 = (_DAT_008033a8 + _DAT_008033a4 + _DAT_008033a2) - _DAT_00803358;
      }
    }
    _DAT_00803386 = _DAT_008033a0;
    _DAT_008033ae = lookupTableInterpolation((short *)&DAT_00803380);
    DAT_008033b0 = 1;
    bVar1 = true;
    _DAT_0080334a = 1;
  }
  if (bVar1) {
    _DAT_0080335c = _DAT_008033b2;
    _DAT_0080335e = 0x65;
    _DAT_00803360 = (short)(((uint)_DAT_008033ae * 100) / 100) + 1;
    if (_DAT_00809a08 == 1) {
      _DAT_00809a08 = 2;
    }
    else {
      _DAT_00809a08 = 1;
    }
  }
  if (_DAT_0080335c == 0) {
    _DAT_0080334a = 0;
    return;
  }
  _DAT_0080335c = _DAT_0080335c + -1;
  if (_DAT_00803360 != 0) {
    _DAT_00803360 = _DAT_00803360 + -1;
  }
  _DAT_0080335e = _DAT_0080335e + -1;
  if (_DAT_0080335e == 0) {
    _DAT_0080335e = 100;
    _DAT_00803360 = (short)(((uint)_DAT_008033ae * 100) / 100);
    if (_DAT_00809a08 == 1) {
      _DAT_00809a08 = 2;
    }
    else {
      _DAT_00809a08 = 1;
    }
  }
  if (_DAT_00803360 == 0) {
    DAT_0080bdef = DAT_0080bdef & 0xf9;
    return;
  }
  if (_DAT_008033a0 == 0) {
    DAT_0080bdef = DAT_0080bdef | 6;
    return;
  }
  if (_DAT_00809a08 == 1) {
    DAT_0080bdef = DAT_0080bdef & 0xfb | 2;
    return;
  }
  DAT_0080bdef = DAT_0080bdef & 0xfd | 4;
  return;
}



//
// Function: outputControlState5FaultHandler @ 0x00030896
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void outputControlState5FaultHandler(void)

{
  _DAT_00809a04 = 5;
  DAT_0080bdef = DAT_0080bdef & 0xf9;
  DAT_0080bdf1 = DAT_0080bdf1 & 0xfb;
  if ((DAT_00809a03 & 2) != 0) {
    DAT_00809a03 = DAT_00809a03 & 0xfd;
    DAT_00809a03 = DAT_00809a03 | 4;
  }
  if ((DAT_00809a03 & 0x10) != 0) {
    DAT_00809a03 = DAT_00809a03 & 0xef;
    DAT_00809a03 = DAT_00809a03 | 0x40;
  }
  if ((DAT_00809a03 & 0x20) != 0) {
    DAT_00809a03 = DAT_00809a03 & 0xdf;
    DAT_00809a03 = DAT_00809a03 | 0x40;
  }
  if (_DAT_00809a0c == 0) {
    _DAT_00809a0c = 1;
  }
  return;
}



//
// Function: FUN_00030914 @ 0x00030914
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_00030914(void)

{
  bool bVar2;
  ushort uVar1;
  
  uVar1 = _DAT_00803614 & 0x40;
  if (uVar1 != 0) {
    if (((fault_status_registers_t_00805df2.sensor_fault_status & 0x4000) == 0) ||
       ((_DAT_008068c4 & 0x4000) == 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) {
      if (((fault_status_registers_t_00805df2.sensor_fault_status & 0x2000) == 0) ||
         ((_DAT_008068c4 & 0x2000) == 0)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (!bVar2) {
        _DAT_00809a10 = _DAT_008091ea;
        return 0;
      }
    }
    if (((fault_status_registers_t_00805df2.engine_fault_status & 2) == 0) ||
       ((_DAT_008068c8 & 2) == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    if (uVar1 == 0) {
      if (((fault_status_registers_t_00805df2.engine_fault_status & 1) == 0) ||
         ((_DAT_008068c8 & 1) == 0)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
      if (uVar1 == 0) {
        _DAT_00809a10 = _DAT_0080926e;
        return 0;
      }
    }
    _DAT_00809a10 = _DAT_0080734a;
  }
  return uVar1;
}



//
// Function: faultBasedOutputStateCalculator @ 0x000309da
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort faultBasedOutputStateCalculator(void)

{
  ushort uVar1;
  short sVar2;
  
  uVar1 = _DAT_00803614 & 0x40;
  if (uVar1 != 0) {
    if (_DAT_00809a58 < 0xcd1) {
      sVar2 = _DAT_00809a58;
      if (_DAT_00809a58 < -800) {
        sVar2 = -800;
      }
    }
    else {
      sVar2 = 0xcd0;
    }
    if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x100) == 0) ||
       ((_DAT_008068e8 & 0x100) == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    if (uVar1 == 0) {
      if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x80) == 0) ||
         ((_DAT_008068e8 & 0x80) == 0)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
      if (uVar1 == 0) {
        if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x40) == 0) ||
           ((_DAT_008068e8 & 0x40) == 0)) {
          uVar1 = 0;
        }
        else {
          uVar1 = 1;
        }
        if (uVar1 == 0) {
          _DAT_00809a12 = sVar2 * 8 + 0x1900;
          return 0;
        }
      }
    }
    _DAT_00809a12 = _DAT_00809a10;
  }
  return uVar1;
}



//
// Function: FUN_00030a8e @ 0x00030a8e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00030a8e(void)

{
  _DAT_008033bc = 1;
  _DAT_008033ba = 1;
  DAT_0080bdef = DAT_0080bdef | 0x10;
  _DAT_008033c0 = _DAT_008077bc;
  DAT_008033bf = 1;
  DAT_008033be = 0;
  return;
}



//
// Function: engineModeBasedIoController @ 0x00030ac0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engineModeBasedIoController(void)

{
  if (DAT_008077c6 != '\0') {
    if (DAT_008077c7 == '\0') {
      DAT_0080bdef = DAT_0080bdef & 0xef;
      return;
    }
    DAT_0080bdef = DAT_0080bdef | 0x10;
    return;
  }
  switch(engine_operating_mode_t_0080c810.state) {
  case 1:
  case 8:
    _DAT_008033ba = 1;
    break;
  case 2:
  case 6:
  case 7:
    _DAT_008033ba = 2;
    break;
  case 3:
  case 4:
    _DAT_008033ba = 3;
    break;
  case 5:
    _DAT_008033ba = 4;
  }
  if (_DAT_0080c9c6 != 0) {
    DAT_008033bf = 0;
    _DAT_008033bc = 1;
    DAT_0080bdef = DAT_0080bdef & 0xef;
    return;
  }
  if (_DAT_008033ba == 3) {
    if (_DAT_008033bc != 3) {
      DAT_008033be = '\x01';
      DAT_008033bf = '\x01';
      DAT_0080bdef = DAT_0080bdef | 0x10;
    }
  }
  else if ((_DAT_008033bc == _DAT_008033ba) && (_DAT_008033c0 != 0)) {
    _DAT_008033c0 = _DAT_008033c0 + -1;
  }
  else if (_DAT_008033ba == 1) {
    if (_DAT_008033bc == 1) {
      if (DAT_008033bf != '\0') {
        DAT_008033bf = '\0';
        DAT_0080bdef = DAT_0080bdef & 0xef;
      }
    }
    else {
      if (DAT_008033be == '\0') {
        _DAT_008033c0 = _DAT_008077c2;
      }
      else {
        _DAT_008033c0 = _DAT_008077c4;
      }
      DAT_0080bdef = DAT_0080bdef | 0x10;
      DAT_008033bf = '\x01';
    }
  }
  else if (_DAT_008033ba == 2) {
    if (_DAT_008033bc == 2) {
      if (DAT_008033bf == '\0') {
        DAT_008033bf = '\x01';
        DAT_0080bdef = DAT_0080bdef | 0x10;
        _DAT_008033c0 = _DAT_008077c0;
      }
      else {
        DAT_008033bf = '\0';
        DAT_0080bdef = DAT_0080bdef & 0xef;
        _DAT_008033c0 = _DAT_008077be;
      }
    }
    else {
      DAT_008033bf = '\0';
      DAT_0080bdef = DAT_0080bdef & 0xef;
      _DAT_008033c0 = _DAT_008077be;
    }
  }
  else if (_DAT_008033ba == 4) {
    DAT_008033bf = '\0';
    DAT_0080bdef = DAT_0080bdef & 0xef;
  }
  _DAT_008033bc = _DAT_008033ba;
  return;
}



//
// Function: FUN_00030c3e @ 0x00030c3e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00030c3e(void)

{
  _DAT_008033ca = 2;
  _DAT_008033cc = 0x80735c;
  _DAT_008033c2 = 2;
  _DAT_008033c4 = 0x807352;
  _DAT_008033d2 = 0x807366;
  _DAT_00809a34 = 0;
  _DAT_00809a32 = 0;
  return;
}



//
// Function: rpmLoadParameterLookup @ 0x00030c78
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint rpmLoadParameterLookup(void)

{
  undefined4 in_D0;
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = CONCAT22((short)((uint)in_D0 >> 0x10),_DAT_00803614) & 0xffff0001;
  if ((_DAT_00803614 & 1) != 0) {
    _DAT_008033c8 = _DAT_00809258;
    _DAT_008033d0 = circular_buffer_t_0080c3fc.data_buffer_8;
    uVar2 = tableInterpolationLookup((short *)&DAT_008033c2);
    uVar1 = (uint)((ulonglong)uVar2 >> 0x20);
    _DAT_00809a32 = (undefined2)((ulonglong)uVar2 >> 0x20);
  }
  return uVar1;
}



//
// Function: FUN_00030cb0 @ 0x00030cb0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_00030cb0(void)

{
  ushort uVar1;
  
  uVar1 = _DAT_00803614 & 1;
  if (((_DAT_00803614 & 1) != 0) && (fuel_demand_state_t_0080c9a4.demand_source_id == 0)) {
    _DAT_00809a34 = fuel_demand_state_t_0080c9a4.limit_minimum;
    uVar1 = _DAT_00809a32;
    if (fuel_demand_state_t_0080c9a4.limit_minimum < _DAT_00809a32) {
      fuel_demand_state_t_0080c9a4.limit_minimum = _DAT_00809a32;
      fuel_demand_state_t_0080c9a4.demand_source_id = 0xb;
    }
  }
  return uVar1;
}



//
// Function: FUN_00030cec @ 0x00030cec
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00030cec(void)

{
  undefined4 in_D0;
  
  _DAT_00809a3c = 0;
  _DAT_0080d186 = 0;
  if ((_DAT_00805670 & 1) != 0) {
    sim_timer_control_register = ((uint)_DAT_00808934 * 8000) / 1000 << 0x10;
    return sim_timer_control_register;
  }
  sim_timer_control_register = sim_timer_control_register & 0xffff0000;
  return CONCAT22((short)((uint)in_D0 >> 0x10),_DAT_00805670) & 0xffff0001;
}



//
// Function: rpmDerateCalculationController @ 0x00030d40
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint rpmDerateCalculationController(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = (uint)_DAT_00803880;
  if (uVar1 < 0x10) {
    uVar3 = (uint)(ushort)(_DAT_00803880 >> 0xf) << 0x10;
    switch(uVar1) {
    default:
      uVar3 = (uint)_DAT_00809d4c * 0x50 >> 2;
      _DAT_00809a36 = (ushort)uVar3;
      break;
    case 3:
    case 4:
    case 5:
      if (_DAT_0080bd8e < 1) {
        _DAT_00809a36 = 0;
      }
      else {
        uVar3 = (uint)(_DAT_0080bd8e * 0x50) >> 8;
        _DAT_00809a36 = (ushort)((uint)(_DAT_0080bd8e * 0x50) >> 8);
      }
      break;
    case 6:
    case 7:
    case 8:
      uVar3 = 0;
      _DAT_00809a36 = (ushort)((uint)_DAT_0080d0c6 * 0x50 >> 8);
      break;
    case 9:
    case 10:
      _DAT_00809a36 = _DAT_00809a38;
      break;
    case 0xb:
    case 0xc:
    case 0xd:
      uVar3 = 0;
      _DAT_00809a36 = (ushort)((uint)_DAT_0080cfd8 * 0x50 >> 8);
      break;
    case 0xe:
    case 0xf:
      iVar2 = rpmFuelCalculation((uint)fuel_demand_state_t_0080c9a4.command,(int)_DAT_00807396,0x3a)
      ;
      iVar2 = (uint)circular_buffer_t_0080c3fc.data_buffer_8 + (iVar2 >> 3);
      if (iVar2 < 64000) {
        if (iVar2 < 1) {
          _DAT_00809a3e = 0;
        }
        else {
          _DAT_00809a3e = (ushort)iVar2;
        }
      }
      else {
        _DAT_00809a3e = 64000;
      }
      iVar2 = rpmFuelCalculation((uint)fuel_demand_state_t_0080c9a4.command,(int)_DAT_00807398,0x3a)
      ;
      iVar2 = (uint)circular_buffer_t_0080c3fc.data_buffer_8 + (iVar2 >> 3);
      if (iVar2 < 64000) {
        if (iVar2 < 1) {
          _DAT_00809a40 = 0;
        }
        else {
          _DAT_00809a40 = (ushort)iVar2;
        }
      }
      else {
        _DAT_00809a40 = 64000;
      }
      uVar3 = 0;
      if (circular_buffer_t_0080c3fc.data_buffer_8 < _DAT_0080739a) {
        if (_DAT_00803880 == 0xe) {
          uVar3 = 0;
          _DAT_00809a36 = (ushort)((uint)_DAT_0080d0c6 * 0x50 >> 8);
        }
        else {
          uVar3 = 0;
          _DAT_00809a36 = (ushort)((uint)_DAT_0080cfd8 * 0x50 >> 8);
        }
      }
      else {
        _DAT_00809a36 = 0;
      }
    }
  }
  else {
    _DAT_00809a36 = 0;
    uVar3 = uVar1;
  }
  if (((_DAT_00803880 == 0xe) || (_DAT_00803880 == 0xf)) &&
     (((diagnostic_state_buffer_t_00809654.diagnostic_mode == 9 ||
       (diagnostic_state_buffer_t_00809654.diagnostic_mode == 10)) ||
      (((_DAT_0080969a == 1 && (diagnostic_state_buffer_t_00809654.diagnostic_mode == 0xc)) &&
       (_DAT_00809d4c < 0xc)))))) {
    if ((_DAT_00807392 < _DAT_00809a3e) || (_DAT_0080738e < _DAT_00809a36)) {
      _DAT_00809a3c = 0x6400;
    }
    else if ((_DAT_00809a40 < _DAT_00807394) && (_DAT_00809a36 < _DAT_00807390)) {
      _DAT_00809a3c = 0;
    }
    _DAT_0080d186 = _DAT_00809a3c;
    if ((_DAT_00805670 & 1) == 0) {
      sim_timer_control_register = sim_timer_control_register & 0xffff0000;
      return CONCAT22((short)(uVar3 >> 0x10),_DAT_00805670) & 0xffff0001;
    }
    sim_timer_control_register =
         ((((uint)_DAT_00808934 * (uint)_DAT_00809a3c) / 0x6400 & 0xffff) * 8000) / 1000 & 0xffff |
         ((uint)_DAT_00808934 * 8000) / 1000 << 0x10;
    return sim_timer_control_register;
  }
  if (((((_DAT_00803880 != 2) && (_DAT_00803880 != 5)) && (_DAT_00803880 != 8)) &&
      ((_DAT_00803880 != 10 && (_DAT_00803880 != 0xd)))) &&
     ((_DAT_00803880 != 0xe && (_DAT_00803880 != 0xf)))) {
    _DAT_00809a3a = _DAT_00807388 + (short)(((int)_DAT_00807386 * (int)(short)_DAT_00809a36) / 4000)
    ;
    if ((int)(uint)_DAT_0080738a < (int)(short)_DAT_00809a3a) {
      _DAT_00809a3a = _DAT_0080738a;
    }
    else if ((int)(short)_DAT_00809a3a < (int)(uint)_DAT_0080738c) {
      _DAT_00809a3a = _DAT_0080738c;
    }
    uVar1 = ((uint)_DAT_00809a3a << 8) >> 1;
    _DAT_00809a3c = (ushort)uVar1;
    _DAT_0080d186 = _DAT_00809a3c;
    if ((_DAT_00805670 & 1) == 0) {
      sim_timer_control_register = sim_timer_control_register & 0xffff0000;
      return CONCAT22(_DAT_00809a3a >> 9,_DAT_00805670) & 0xffff0001;
    }
    sim_timer_control_register =
         ((((uint)_DAT_00808934 * (uVar1 & 0xffff)) / 0x6400 & 0xffff) * 8000) / 1000 & 0xffff |
         ((uint)_DAT_00808934 * 8000) / 1000 << 0x10;
    return sim_timer_control_register;
  }
  if ((_DAT_00803880 == 0xe) || (_DAT_00803880 == 0xf)) {
    uVar3 = (uint)_DAT_00809d4c * 0x50 >> 2;
    _DAT_00809a36 = (ushort)uVar3;
  }
  if (_DAT_0080738e < _DAT_00809a36) {
    _DAT_00809a3c = 0x6400;
  }
  if (_DAT_00809a36 < _DAT_00807390) {
    _DAT_00809a3c = 0;
  }
  _DAT_0080d186 = _DAT_00809a3c;
  if ((_DAT_00805670 & 1) == 0) {
    sim_timer_control_register = sim_timer_control_register & 0xffff0000;
    return CONCAT22((short)(uVar3 >> 0x10),_DAT_00805670) & 0xffff0001;
  }
  sim_timer_control_register =
       ((((uint)_DAT_00808934 * (uint)_DAT_00809a3c) / 0x6400 & 0xffff) * 8000) / 1000 & 0xffff |
       ((uint)_DAT_00808934 * 8000) / 1000 << 0x10;
  return sim_timer_control_register;
}



//
// Function: vp44DiagnosticSensorThresholdMonitor @ 0x000311ea
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort vp44DiagnosticSensorThresholdMonitor(void)

{
  ushort uVar1;
  word wVar2;
  
  if ((_DAT_00803614 & 0x100) == 0) {
    return 0;
  }
  if (((fault_status_registers_t_00805df2.fault_status_2 & 0x200) == 0) ||
     ((_DAT_008068c6 & 0x200) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  if (uVar1 == 0) {
    if (((fault_status_registers_t_00805df2.fault_status_2 & 0x400) == 0) ||
       ((_DAT_008068c6 & 0x400) == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    if (uVar1 == 0) {
      if (((fault_status_registers_t_00805df2.fault_status_2 & 0x2000) == 0) ||
         ((_DAT_008068c6 & 0x2000) == 0)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
      if (uVar1 == 0) {
        wVar2 = 0;
        if (((fuel_demand_state_t_0080c9a4._2_2_ != 0x10) ||
            (wVar2 = _DAT_00809258, _DAT_00809258 <= _DAT_0080782a)) ||
           (wVar2 = circular_buffer_t_0080c3fc.data_buffer_8,
           circular_buffer_t_0080c3fc.data_buffer_8 <= _DAT_00807828)) {
          if (_DAT_008033d6 == 0) {
            return wVar2;
          }
          _DAT_008033d6 = _DAT_008033d6 - 1;
          if (_DAT_008033d6 != 0) {
            return wVar2;
          }
          fault_status_registers_t_00805df2.fault_status_2 =
               fault_status_registers_t_00805df2.fault_status_2 & 0xf7ff;
          return wVar2;
        }
        if (_DAT_0080782c <= _DAT_008033d6) {
          return _DAT_008033d6;
        }
        _DAT_008033d6 = _DAT_008033d6 + 1;
        if (_DAT_008033d6 != _DAT_0080782c) {
          return _DAT_008033d6;
        }
        fault_status_registers_t_00805df2.fault_status_2 =
             fault_status_registers_t_00805df2.fault_status_2 | 0x800;
        fault_latch_registers_t_00805e32.fault_status_8_previous =
             fault_latch_registers_t_00805e32.fault_status_8_previous | 0x800;
        return _DAT_008033d6;
      }
    }
  }
  _DAT_008033d6 = 0;
  fault_status_registers_t_00805df2.fault_status_2 =
       fault_status_registers_t_00805df2.fault_status_2 & 0xf7ff;
  return uVar1;
}



//
// Function: vp44FaultRegisterBit2Monitor @ 0x00031306
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort vp44FaultRegisterBit2Monitor(void)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = _DAT_0080d04c;
  if ((_DAT_00803614 & 2) == 0) {
    fault_status_registers_t_00805df2.io_fault_status_1 =
         fault_status_registers_t_00805df2.io_fault_status_1 & 0xdfff;
    uVar2 = 0;
  }
  else {
    if (_DAT_008093a2 == 1) {
      _DAT_0080d04c = _DAT_0080d04c | 0x10;
      fault_status_registers_t_00805df2.io_fault_status_1 =
           fault_status_registers_t_00805df2.io_fault_status_1 | 0x2000;
      fault_latch_registers_t_00805e32.io_fault_latch_1 =
           fault_latch_registers_t_00805e32.io_fault_latch_1 | 0x2000;
      return _DAT_00803614 & 2;
    }
    _DAT_0080d04c = _DAT_0080d04c & 0xffef;
    uVar2 = fault_status_registers_t_00805df2.io_fault_status_1 & 0x2000;
    if (uVar2 != 0) {
      uVar2 = fault_latch_registers_t_00805e32.io_fault_latch_1 & 0x2000;
      if (uVar2 == 0) {
        fault_status_registers_t_00805df2.io_fault_status_1 =
             fault_status_registers_t_00805df2.io_fault_status_1 & 0xdfff;
        return uVar2;
      }
    }
  }
  _DAT_0080d04c = uVar1 & 0xffef;
  return uVar2;
}



//
// Function: FUN_00031394 @ 0x00031394
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00031394(void)

{
  _DAT_008096a0 = (ushort)((DAT_0080bdc7 & 0x10) != 0);
  if ((_DAT_00803838 != 0) && ((DAT_0080bdcc & 0x40) != 0)) {
    _DAT_008096a0 = _DAT_008096a0 | 2;
  }
  return;
}



//
// Function: FUN_000313c4 @ 0x000313c4
//

ushort FUN_000313c4(uint param_1)

{
  ushort uVar1;
  
  if (((param_1 & 0x10000) == 0) ||
     ((fault_status_registers_t_00805df2.io_fault_status_2 & 0x20) != 0)) {
    DAT_0080bdef = DAT_0080bdef | 1;
  }
  else {
    DAT_0080bdef = DAT_0080bdef & 0xfe;
  }
  uVar1 = param_1._0_2_ & 2;
  if (((param_1 & 0x20000) != 0) &&
     (uVar1 = fault_status_registers_t_00805df2.sensor_fault_status & 1,
     (fault_status_registers_t_00805df2.sensor_fault_status & 1) == 0)) {
    DAT_0080bdf1 = DAT_0080bdf1 & 0xfe;
    return uVar1;
  }
  DAT_0080bdf1 = DAT_0080bdf1 | 1;
  return uVar1;
}



//
// Function: FUN_0003141c @ 0x0003141c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0003141c(void)

{
  ushort uVar1;
  
  uVar1 = _DAT_008096b4 | _DAT_0080969a;
  if (uVar1 != 0) {
    if (_DAT_008096b2 == 0) {
      _DAT_008096fe = 0;
      _DAT_008096a2 = 0;
      return uVar1;
    }
    uVar1 = _DAT_008096b2;
    if (_DAT_008096b2 < _DAT_008096fe) {
      _DAT_008096fe = _DAT_008096b2;
      _DAT_008096a2 = 2;
    }
  }
  return uVar1;
}



//
// Function: FUN_0003145a @ 0x0003145a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0003145a(void)

{
  FUN_00031394();
  if (_DAT_008096a0 == 0) {
    _DAT_008096fe = 0;
    _DAT_008096a2 = 0;
    return;
  }
  if (_DAT_008096a0 < _DAT_008096fe) {
    _DAT_008096fe = _DAT_008096a0;
    _DAT_008096a2 = 3;
  }
  return;
}



//
// Function: FUN_00031494 @ 0x00031494
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00031494(void)

{
  if (((_DAT_008096a2 != 0) && (_DAT_008096a2 != 5)) &&
     ((int)(short)_DAT_0080cfb2 < (int)(uint)_DAT_008096fe)) {
    _DAT_008096fe = _DAT_0080cfb2;
    _DAT_008096a2 = 4;
  }
  return;
}



//
// Function: FUN_000314c6 @ 0x000314c6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000314c6(void)

{
  if (_DAT_0080cfb0 == 0) {
    _DAT_00809702 = 0;
    _DAT_00809700 = 5;
    return;
  }
  _DAT_00809702 = _DAT_0080cfb0;
  _DAT_00809700 = 1;
  return;
}



//
// Function: FUN_000314ee @ 0x000314ee
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_000314ee(void)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar2 = 0;
  bVar1 = false;
  if (((_DAT_00807120 < circular_buffer_t_0080c3fc.data_buffer_8) && (_DAT_00809258 < _DAT_00807126)
      ) && (fuel_demand_state_t_0080c9a4.command <= _DAT_00807130)) {
    uVar2 = 1;
  }
  else if ((circular_buffer_t_0080c3fc.data_buffer_8 <= _DAT_00803836) ||
          (_DAT_00807130 < fuel_demand_state_t_0080c9a4.command)) {
    bVar1 = true;
  }
  if (((_DAT_008033da != 0) && (bVar1)) || ((uVar2 | _DAT_008033da) == 0)) {
    _DAT_008096fe = 0;
    _DAT_008096a2 = 0;
    return 0;
  }
  if (_DAT_00809702 != 0) {
    _DAT_008096fe = _DAT_00809702;
    _DAT_008096a2 = _DAT_00809700;
    return uVar2 | _DAT_008033da;
  }
  uVar3 = 0;
  uVar2 = _DAT_0080d17a | _DAT_00809d4c;
  if ((uVar2 == 0) &&
     ((uVar2 = DAT_0080bdc7 & 4, (DAT_0080bdc7 & 4) == 0 ||
      ((uVar2 = DAT_0080bdc7 & 4, (DAT_0080bdc7 & 4) != 0 &&
       (uVar2 = engine_control_flags_t_008035d6.protection_system & 0x40,
       (engine_control_flags_t_008035d6.protection_system & 0x40) == 0)))))) {
    uVar3 = 1;
  }
  if (((_DAT_008033da == 0) || (uVar3 != 0)) && (uVar2 = uVar3 | _DAT_008033da, uVar2 != 0)) {
    _DAT_008096fe = 4;
    _DAT_008096a2 = 5;
    FUN_0003141c();
    FUN_0003145a();
    uVar2 = FUN_00031494();
    return uVar2;
  }
  _DAT_008096fe = 0;
  _DAT_008096a2 = 0;
  return uVar2;
}



//
// Function: fuelPressureSyncStateMachine @ 0x000315f6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelPressureSyncStateMachine(void)

{
  bool bVar1;
  
  switch(_DAT_008033de) {
  case 0:
    if (_DAT_008096fe != 0) {
      if (((fault_status_registers_t_00805df2.fault_status_2 & 0x400) == 0) &&
         ((fault_status_registers_t_00805df2.fault_status_2 & 0x200) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((bVar1) && (_DAT_00807124 != 0)) {
        _DAT_008033de = 1;
        _DAT_008033d8 = 0;
      }
      else if (((uint)*(ushort *)(&DAT_008035d4 + (short)((int)(uint)_DAT_0080712c >> 4) * 2) &
               1 << (_DAT_0080712c & 0xf)) == 0) {
        _DAT_008033de = 3;
      }
      else {
        _DAT_008033de = 2;
      }
    }
    break;
  case 1:
    if (_DAT_008096fe == 0) {
      if (_DAT_00807122 == 0) {
        _DAT_008033de = 0;
      }
      else {
        _DAT_008033de = 4;
        _DAT_008033d8 = 0;
      }
    }
    else if (_DAT_00807124 <= _DAT_008033d8) {
      _DAT_008033de = 3;
    }
    break;
  case 2:
    if (_DAT_008096fe == 0) {
      if (_DAT_00807122 == 0) {
        _DAT_008033de = 0;
      }
      else {
        _DAT_008033de = 4;
        _DAT_008033d8 = 0;
      }
    }
    else {
      if (((fault_status_registers_t_00805df2.fault_status_2 & 0x400) == 0) &&
         ((fault_status_registers_t_00805df2.fault_status_2 & 0x200) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((bVar1) && (_DAT_00807124 != 0)) {
        _DAT_008033de = 1;
        _DAT_008033d8 = 0;
      }
      else if ((_DAT_008033da != 0) &&
              ((_DAT_0080712e <= circular_buffer_t_0080c3fc.data_buffer_8 || (_DAT_008033dc != 0))))
      {
        _DAT_008033de = 3;
      }
    }
    break;
  case 3:
    if (_DAT_008096fe == 0) {
      if (_DAT_00807122 == 0) {
        _DAT_008033de = 0;
      }
      else {
        _DAT_008033de = 4;
        _DAT_008033d8 = 0;
      }
    }
    break;
  case 4:
    if (_DAT_00807122 <= _DAT_008033d8) {
      _DAT_008033de = 0;
    }
  }
  _DAT_008033d8 = _DAT_008033d8 + 1;
  return;
}



//
// Function: vp44InjectionSystemStateController @ 0x00031768
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44InjectionSystemStateController(void)

{
  undefined4 unaff_A2;
  ushort uVar1;
  
  uVar1 = (ushort)((uint)unaff_A2 >> 0x10);
  FUN_000314c6();
  FUN_000314ee();
  fuelPressureSyncStateMachine();
  _DAT_0080969e = (ushort)(_DAT_008033de != 0);
  if (_DAT_008033de == 3) {
    FUN_000313c4(CONCAT22(_DAT_008096fe,uVar1));
  }
  else {
    FUN_000313c4((uint)uVar1);
  }
  _DAT_008033dc = _DAT_008033da;
  _DAT_008033da = _DAT_008096fe;
  return;
}



//
// Function: FUN_000317c2 @ 0x000317c2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000317c2(void)

{
  if (fuel_demand_state_t_0080c9a4._2_2_ == 0x18) {
    _DAT_00809704 = fuel_demand_state_t_0080c9a4.limit_minimum;
    fuel_demand_state_t_0080c9a4.limit_minimum = _DAT_00808a72;
    fuel_demand_state_t_0080c9a4.demand_source_id = 6;
    fuel_demand_state_t_0080c9a4.adjustment_active = 0;
  }
  return;
}



//
// Function: FUN_000317ee @ 0x000317ee
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000317ee(void)

{
  ushort in_stack_00000000;
  
  _DAT_0080969e = 0;
  FUN_000313c4((uint)in_stack_00000000);
  _DAT_008033de = 0;
  _DAT_00809700 = 5;
  _DAT_008096a2 = 5;
  return;
}



//
// Function: fuelTemperatureLimitingPrimary @ 0x00031814
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort fuelTemperatureLimitingPrimary(void)

{
  bool bVar1;
  ushort uVar2;
  
  _DAT_00809706 = 0;
  _DAT_008033ee = 0;
  _DAT_008033f0 = 0;
  if (_DAT_0080713e <= circular_buffer_t_0080c3fc.data_buffer_8) {
    _DAT_008033ee = 0;
    _DAT_008033f0 = 0;
    _DAT_00809706 = 0;
    return circular_buffer_t_0080c3fc.data_buffer_8;
  }
  if ((DAT_0080bdc6 & 1) == 0) {
    _DAT_008033ee = 0;
    _DAT_008033f0 = 0;
    _DAT_00809706 = 0;
    return DAT_0080bdc6 & 1;
  }
  if ((_DAT_00809712 == 1) || (_DAT_00809712 == 3)) {
    _DAT_00809706 = 1;
  }
  if (_DAT_0080926e < _DAT_00807134) {
    if (((fault_status_registers_t_00805df2.engine_fault_status & 1) == 0) ||
       ((_DAT_008068c8 & 1) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) goto LAB_000318d6;
    if (((fault_status_registers_t_00805df2.engine_fault_status & 2) == 0) ||
       ((_DAT_008068c8 & 2) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || ((_DAT_008033ea == 1 && (_DAT_00807132 <= _DAT_0080926e)))) goto LAB_000318d6;
  }
  else {
LAB_000318d6:
    _DAT_00809706 = 1;
    _DAT_008033ee = 1;
  }
  if ((engine_control_flags_t_008035d6.fuel_temp_control & 0x1000) == 0) {
    if (_DAT_008091ea < _DAT_00807138) {
      if (((fault_status_registers_t_00805df2.sensor_fault_status & 0x2000) == 0) ||
         ((_DAT_008068c4 & 0x2000) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((fault_status_registers_t_00805df2.sensor_fault_status & 0x4000) == 0) ||
           ((_DAT_008068c4 & 0x4000) == 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if ((!bVar1) && ((_DAT_008033ea != 1 || (_DAT_008091ea < _DAT_00807136))))
        goto LAB_00031956;
      }
    }
    _DAT_00809706 = 1;
    _DAT_008033ee = 1;
  }
LAB_00031956:
  if (((engine_control_flags_t_008035d6.fuel_temp_control & 0x4000) != 0) &&
     ((DAT_0080bdc6 & 0x10) != 0)) {
    _DAT_00809706 = 1;
    _DAT_008033f0 = 1;
  }
  if (((engine_control_flags_t_008035d6.fuel_temp_control & 0x400) != 0) &&
     (((DAT_0080bdcf & 1) != 0 || ((_DAT_008033ea == 1 && (_DAT_0080970e < _DAT_0080383c)))))) {
    _DAT_00809706 = 1;
  }
  if ((engine_control_flags_t_008035d6.fuel_temp_control & 0x2000) != 0) {
    if ((((_DAT_00803838 == 0) || (_DAT_008096fe != 3)) || (_DAT_008091ea <= _DAT_00807142)) ||
       ((_DAT_0080926e <= _DAT_00807140 || (_DAT_00809710 < _DAT_00807144)))) {
      if ((((_DAT_00803838 == 0) && ((_DAT_008096fe == 1 && (_DAT_00807142 < _DAT_008091ea)))) &&
          (_DAT_00807140 < _DAT_0080926e)) && (_DAT_00807144 <= _DAT_00809710)) {
        _DAT_00809706 = 1;
        _DAT_008033ee = 1;
      }
    }
    else {
      _DAT_00809706 = 1;
      _DAT_008033ee = 1;
    }
  }
  if (_DAT_00809714 != 0) {
    _DAT_00809706 = 1;
  }
  uVar2 = engine_control_flags_t_008035d6.fuel_temp_control & 0x1000;
  if (((engine_control_flags_t_008035d6.fuel_temp_control & 0x1000) == 0) &&
     (uVar2 = _DAT_00809718, _DAT_00809718 < _DAT_0080713c)) {
    _DAT_00809706 = 1;
    _DAT_008033ee = 1;
  }
  return uVar2;
}



//
// Function: fuelTemperatureLimitingSecondary @ 0x00031a76
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort fuelTemperatureLimitingSecondary(void)

{
  bool bVar1;
  
  _DAT_00809708 = 0;
  if (_DAT_0080713e <= circular_buffer_t_0080c3fc.data_buffer_8) {
    _DAT_00809708 = 0;
    return circular_buffer_t_0080c3fc.data_buffer_8;
  }
  if ((DAT_0080bdc6 & 1) == 0) {
    _DAT_00809708 = 0;
    return DAT_0080bdc6 & 1;
  }
  if ((engine_control_flags_t_008035d6.fuel_temp_control & 0x1000) == 0) {
    _DAT_00809708 = 0;
    return engine_control_flags_t_008035d6.fuel_temp_control & 0x1000;
  }
  if ((_DAT_00809712 == 2) || (_DAT_00809712 == 3)) {
    _DAT_00809708 = 1;
  }
  if (_DAT_008091ea < _DAT_00807138) {
    if (((fault_status_registers_t_00805df2.sensor_fault_status & 0x2000) == 0) ||
       ((_DAT_008068c4 & 0x2000) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (((fault_status_registers_t_00805df2.sensor_fault_status & 0x4000) == 0) ||
         ((_DAT_008068c4 & 0x4000) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((!bVar1) && ((_DAT_008033ec == 0 || (_DAT_008091ea < _DAT_00807136)))) goto LAB_00031b34;
    }
  }
  _DAT_00809708 = 1;
LAB_00031b34:
  if (((engine_control_flags_t_008035d6.fuel_temp_control & 0x4000) != 0) &&
     ((DAT_0080bdc6 & 0x10) != 0)) {
    _DAT_00809708 = 1;
  }
  if (_DAT_00809716 != 0) {
    _DAT_00809708 = 1;
  }
  if (_DAT_00809718 < _DAT_0080713c) {
    _DAT_00809708 = 1;
  }
  return _DAT_00809718;
}



//
// Function: ioControlSourceRegisterManager @ 0x00031b78
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ioControlSourceRegisterManager(uint param_1)

{
  byte bVar1;
  
  bVar1 = (byte)param_1;
  if (param_1._0_2_ == 0) {
    if (_DAT_0080713a == 0) {
      (&DAT_0080bdee)[(int)(param_1 & 0xffff) >> 3] =
           ~('\x01' << (bVar1 & 7)) & (&DAT_0080bdee)[(int)(param_1 & 0xffff) >> 3];
      return;
    }
    (&DAT_0080bdee)[(int)(param_1 & 0xffff) >> 3] =
         '\x01' << (bVar1 & 7) | (&DAT_0080bdee)[(int)(param_1 & 0xffff) >> 3];
    return;
  }
  if (_DAT_0080713a == 0) {
    (&DAT_0080bdee)[(int)(param_1 & 0xffff) >> 3] =
         '\x01' << (bVar1 & 7) | (&DAT_0080bdee)[(int)(param_1 & 0xffff) >> 3];
    return;
  }
  (&DAT_0080bdee)[(int)(param_1 & 0xffff) >> 3] =
       ~('\x01' << (bVar1 & 7)) & (&DAT_0080bdee)[(int)(param_1 & 0xffff) >> 3];
  return;
}



//
// Function: FUN_00031c06 @ 0x00031c06
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00031c06(void)

{
  _DAT_00809706 = 0;
  _DAT_00809708 = 0;
  _DAT_008033e2 = 0;
  _DAT_008033e4 = 0;
  _DAT_008033e6 = 0;
  _DAT_00809718 = _DAT_0080713c;
  _DAT_00809710 = _DAT_00807144;
  _DAT_0080970e = _DAT_0080383c;
  ioControlSourceRegisterManager(0xf);
  ioControlSourceRegisterManager(CONCAT22(_DAT_00809708,0x18));
  return;
}



//
// Function: fuelTemperatureProtectionSlowCycle40Coordinator @ 0x00031c60
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint fuelTemperatureProtectionSlowCycle40Coordinator(void)

{
  undefined2 uVar1;
  uint uVar2;
  bool bVar3;
  
  _DAT_008033ea = _DAT_00809706;
  _DAT_008033ec = _DAT_00809708;
  if (engine_operating_mode_t_0080c810.state == 1) {
    _DAT_00809706 = 0;
    _DAT_00809708 = 0;
    ioControlSourceRegisterManager(0xf);
    _DAT_0080970a = (ushort)DAT_0080bdef;
    return (uint)DAT_0080bdef;
  }
  fuelTemperatureLimitingPrimary();
  ioControlSourceRegisterManager(CONCAT22(_DAT_00809706,0xf));
  _DAT_0080970a = (ushort)DAT_0080bdef;
  _DAT_008033e8 = _DAT_008033e6;
  bVar3 = (DAT_0080bdcf & 1) != 0;
  if ((engine_control_flags_t_008035d6.fuel_temp_control & 0x400) != 0) {
    if ((bVar3) && (_DAT_008033e6 == 0)) {
      _DAT_0080970e = 0;
      _DAT_008033e2 = 1;
      _DAT_008033e4 = 1;
    }
    else if (_DAT_0080970e < _DAT_0080383c) {
      _DAT_0080970e = _DAT_0080970e + 1;
    }
  }
  if (_DAT_00809706 == 0) {
    _DAT_008033e4 = 0;
  }
  if ((_DAT_008033e4 != 0) && (_DAT_00805f9a != -1)) {
    _DAT_00805f9a = _DAT_00805f9a + 1;
  }
  if ((engine_control_flags_t_008035d6.fuel_temp_control & 0x800) != 0) {
    if (_DAT_00803842 < _DAT_008096a6) {
      _DAT_0080970e = _DAT_0080383c;
    }
    if ((_DAT_008096a6 < _DAT_00803840) && (_DAT_008033e2 == 1)) {
      _DAT_0080970e = 0;
    }
    if ((_DAT_00803840 <= _DAT_008096a6) && (_DAT_0080383c <= _DAT_0080970e)) {
      _DAT_008033e2 = 0;
    }
  }
  if ((engine_control_flags_t_008035d6.fuel_temp_control & 0x2000) != 0) {
    if (((_DAT_008096fe != 3) || (_DAT_008091ea <= _DAT_00807142)) ||
       (_DAT_0080926e <= _DAT_00807140)) {
      _DAT_00809710 = 0;
    }
    if (((_DAT_00803838 == 0) && (_DAT_008096fe != 1)) ||
       ((_DAT_008091ea <= _DAT_00807142 || (_DAT_0080926e <= _DAT_00807140)))) {
      _DAT_00809710 = 0;
    }
    if (((_DAT_008096fe == 3) && (_DAT_00807142 < _DAT_008091ea)) &&
       ((_DAT_00807140 < _DAT_0080926e && (_DAT_00809710 < _DAT_00807144)))) {
      _DAT_00809710 = _DAT_00809710 + 1;
    }
    if ((((_DAT_00803838 == 0) && (_DAT_008096fe == 1)) && (_DAT_00807142 < _DAT_008091ea)) &&
       ((_DAT_00807140 < _DAT_0080926e && (_DAT_00809710 < _DAT_00807144)))) {
      _DAT_00809710 = _DAT_00809710 + 1;
    }
  }
  if (_DAT_00809714 != 0) {
    _DAT_00809714 = _DAT_00809714 + -1;
  }
  if ((engine_control_flags_t_008035d6.fuel_temp_control & 0x1000) == 0) {
    if (((_DAT_00809706 == 0) || (_DAT_008033ea != 0)) || (_DAT_008091ea < _DAT_00807138)) {
      if (_DAT_00809718 < _DAT_0080713c) {
        _DAT_00809718 = _DAT_00809718 + 1;
      }
    }
    else {
      _DAT_00809718 = 0;
    }
  }
  if (_DAT_00809706 != 0) {
    if (_DAT_00807146 < _DAT_008096a6) {
      if (_DAT_00805f9e != -1) {
        _DAT_00805f9e = _DAT_00805f9e + 1;
      }
    }
    else if (_DAT_00805f92 != -1) {
      _DAT_00805f92 = _DAT_00805f92 + 1;
    }
    if (_DAT_008033f0 != 0) {
      _DAT_00805fa6 = _DAT_00805fa6 + 1;
    }
    if (_DAT_008033ee != 0) {
      _DAT_00805fa2 = _DAT_00805fa2 + 1;
    }
  }
  _DAT_008033e6 = (ushort)bVar3;
  fuelTemperatureLimitingSecondary();
  ioControlSourceRegisterManager(CONCAT22(_DAT_00809708,0x18));
  uVar1 = 0;
  _DAT_0080970c = (ushort)DAT_0080bdf1;
  if ((_DAT_00809708 != 0) && (uVar1 = 0xffff, _DAT_00805f96 != -1)) {
    _DAT_00805f96 = _DAT_00805f96 + 1;
  }
  if (_DAT_00809716 != 0) {
    _DAT_00809716 = _DAT_00809716 + -1;
  }
  uVar2 = CONCAT22(uVar1,engine_control_flags_t_008035d6.fuel_temp_control) & 0xffff1000;
  if ((engine_control_flags_t_008035d6.fuel_temp_control & 0x1000) != 0) {
    if (((_DAT_00809708 != 0) && (_DAT_008033ec == 0)) &&
       (uVar2 = CONCAT22(uVar1,_DAT_008091ea), _DAT_00807138 <= _DAT_008091ea)) {
      _DAT_00809718 = 0;
      return uVar2;
    }
    uVar2 = CONCAT22((short)(uVar2 >> 0x10),_DAT_00809718);
    if (_DAT_00809718 < _DAT_0080713c) {
      _DAT_00809718 = _DAT_00809718 + 1;
    }
  }
  return uVar2;
}



//
// Function: vp44SensorStatusMonitor @ 0x00031fb8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44SensorStatusMonitor(void)

{
  if (_DAT_0080374e == 0) {
    if (_DAT_0080938c == _DAT_008033f6) {
      _DAT_008033f8 = 2;
    }
    else if (_DAT_0080938c == _DAT_008033f4) {
      if (_DAT_008033f8 + 1 < (uint)_DAT_0080734c) {
        _DAT_008033f8 = _DAT_008033f8 + 1;
        _DAT_008033f6 = 4;
      }
      else {
        _DAT_008033f6 = _DAT_0080938c;
      }
    }
    else if (_DAT_008033f8 < 2) {
      _DAT_008033f6 = 4;
    }
    else {
      _DAT_008033f8 = _DAT_008033f8 - 1;
    }
    if (_DAT_0080734c < 2) {
      _DAT_008033f6 = _DAT_0080938c;
    }
    if (_DAT_008033f6 == 5) {
      DAT_0080bdcc = DAT_0080bdcc | 0x10;
    }
    else if (_DAT_008033f6 == 0) {
      DAT_0080bdcc = DAT_0080bdcc & 0xef;
    }
    if (_DAT_008033f6 == 2) {
      if (_DAT_008033f2 < _DAT_0080734e) {
        DAT_0080bdcc = DAT_0080bdcc & 0xfd | 4;
        _DAT_008033f2 = _DAT_008033f2 + 1;
      }
      else {
        DAT_0080bdcc = DAT_0080bdcc | 6;
      }
    }
    else {
      DAT_0080bdcc = DAT_0080bdcc & 0xf9;
      _DAT_008033f2 = 0;
    }
    if (_DAT_008033f6 == 3) {
      DAT_0080bdcc = DAT_0080bdcc | 1;
    }
    else {
      DAT_0080bdcc = DAT_0080bdcc & 0xfe;
    }
    if (_DAT_008033f6 == 1) {
      DAT_0080bdcc = DAT_0080bdcc | 8;
    }
    else {
      DAT_0080bdcc = DAT_0080bdcc & 0xf7;
    }
    _DAT_008033f4 = _DAT_0080938c;
  }
  return;
}



//
// Function: FUN_000320bc @ 0x000320bc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000320bc(void)

{
  if (_DAT_0080374e == 0) {
    _DAT_008033f4 = 4;
    _DAT_008033f6 = 4;
    _DAT_008033f8 = 0;
  }
  return;
}



//
// Function: FUN_000320dc @ 0x000320dc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000320dc(void)

{
  _DAT_008033fa = 0;
  _DAT_008033fc = 0;
  _DAT_008033fe = 1;
  _DAT_00803400 = 1;
  _DAT_00803402 = 1;
  _DAT_00803404 = 0;
  _DAT_00803406 = 1;
  _DAT_00803408 = 0;
  _DAT_0080340a = 0;
  _DAT_00809b04 = 0;
  return;
}



//
// Function: vp44SensorDiagnosticControl @ 0x0003211a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort vp44SensorDiagnosticControl(void)

{
  ushort uVar1;
  
  uVar1 = _DAT_00803614 & 0x10;
  if (uVar1 != 0) {
    if (circular_buffer_t_0080c3fc.data_buffer_8 < _DAT_00807836) {
      _DAT_008033fa = 0;
    }
    else if ((byte)((-((DAT_0080bdc9 & 8) != 0) & 1U) +
                   (-((DAT_0080bdc9 & 0x20) != 0) & 1U) * '\x02' +
                   (-((DAT_0080bdc9 & 0x40) != 0) & 1U) * '\x04') == '\x06') {
      _DAT_008033fa = 1;
    }
    else {
      _DAT_008033fa = 0;
    }
    DAT_00803413 = (-((DAT_0080bdc9 & 8) != 0) & 1U) +
                   (-((DAT_0080bdcf & 1) != 0) & 1U) * '\x02' +
                   (-((DAT_0080bdc9 & 0x20) != 0) & 1U) * '\x04';
    if ((_DAT_0080340c != 0) && (_DAT_00809b04 == 0)) {
      _DAT_0080340c = _DAT_0080340c + -1;
    }
    if (_DAT_00809b04 == 0) {
      if ((_DAT_00809b0c < _DAT_00807830) ||
         ((fuel_demand_state_t_0080c9a4._2_2_ != 0x10 &&
          (fuel_demand_state_t_0080c9a4._2_2_ != 0x13)))) {
        if (_DAT_008033fa == 1) {
          _DAT_00809b02 = 1;
        }
        else if ((_DAT_0080340c == 0) || ((DAT_0080bdc9 & 8) != 0)) {
          _DAT_00809b02 = 0;
        }
      }
      else {
        _DAT_00803410 = _DAT_00809b02;
        _DAT_00809b02 = 0;
        _DAT_00809b04 = 1;
        _DAT_0080340e = _DAT_00807832;
      }
    }
    else if (_DAT_0080340e == 0) {
      _DAT_00809b02 = _DAT_00803410;
      _DAT_00809b04 = 0;
    }
    else {
      _DAT_00809b02 = 0;
      _DAT_0080340e = _DAT_0080340e + -1;
    }
    if ((DAT_00803412 != '\0') && ((DAT_0080bdc9 & 0x20) == 0)) {
      _DAT_0080340c = _DAT_0080782e;
    }
    _DAT_00803414 = *(short *)(&DAT_008033fc + (short)(ushort)DAT_00803413 * 2);
    if (_DAT_00803414 == 1) {
      if (_DAT_00809b06 < _DAT_00807834) {
        _DAT_00809b06 = _DAT_00809b06 + 1;
        _DAT_00803414 = 0;
      }
      else {
        _DAT_00803414 = 1;
      }
    }
    else {
      _DAT_00809b06 = 0;
    }
    if (_DAT_00803414 == 0) {
      fault_status_registers_t_00805df2.io_fault_status_1 =
           fault_status_registers_t_00805df2.io_fault_status_1 & 0xfbff;
    }
    else {
      fault_status_registers_t_00805df2.io_fault_status_1 =
           fault_status_registers_t_00805df2.io_fault_status_1 | 0x400;
      fault_latch_registers_t_00805e32.io_fault_latch_1 =
           fault_latch_registers_t_00805e32.io_fault_latch_1 | 0x400;
    }
    uVar1 = (byte)-((DAT_0080bdc9 & 0x20) != 0) & 1;
    DAT_00803412 = (char)uVar1;
    if (_DAT_00809b02 == 1) {
      DAT_0080bdef = DAT_0080bdef | 8;
      return uVar1;
    }
    DAT_0080bdef = DAT_0080bdef & 0xf7;
  }
  return uVar1;
}



//
// Function: FUN_00032342 @ 0x00032342
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00032342(void)

{
  _DAT_00803416 = 0;
  _DAT_0080341e = 0;
  _DAT_00803418 = 7;
  _DAT_00803420 = 7;
  _DAT_0080341c = 0;
  _DAT_00803424 = 0;
  _DAT_0080341a = _DAT_0080783e;
  _DAT_00803422 = _DAT_00807846;
  return;
}



//
// Function: dzgTimingAndPressureControlStateMachine @ 0x00032380
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint dzgTimingAndPressureControlStateMachine(void)

{
  ushort uVar1;
  ushort uVar4;
  uint uVar2;
  ushort uVar5;
  int iVar3;
  ushort uVar6;
  bool bVar7;
  
  uVar6 = _DAT_00809308;
  if (_DAT_00809308 < 0x11) {
    uVar6 = 0x10;
  }
  switch(_DAT_0080341c) {
  case 0:
    if (_DAT_0080783c < _DAT_0080926e) {
      bVar7 = _DAT_00807838 < _DAT_00803416;
      _DAT_00803416 = _DAT_00803416 + 1;
      if (bVar7) {
        _DAT_00803416 = 0;
        _DAT_0080341c = 1;
        if ((int)((uint)_DAT_00807840 - (uint)_DAT_0080783e) < 0) {
          iVar3 = -((uint)_DAT_00807840 - (uint)_DAT_0080783e);
        }
        else {
          iVar3 = (uint)_DAT_00807840 - (uint)_DAT_0080783e;
        }
        _DAT_00803418 = (ushort)(iVar3 / (int)(uint)_DAT_0080783a);
        _DAT_0080341a = _DAT_00807840;
      }
    }
    else {
      _DAT_00803416 = 0;
    }
    break;
  case 1:
    if (_DAT_0080926e < _DAT_0080783c) {
      bVar7 = _DAT_00807838 < _DAT_00803416;
      _DAT_00803416 = _DAT_00803416 + 1;
      if (bVar7) {
        _DAT_00803416 = 0;
        _DAT_0080341c = 0;
        if ((int)((uint)_DAT_00807840 - (uint)_DAT_0080783e) < 0) {
          iVar3 = -((uint)_DAT_00807840 - (uint)_DAT_0080783e);
        }
        else {
          iVar3 = (uint)_DAT_00807840 - (uint)_DAT_0080783e;
        }
        _DAT_00803418 = (ushort)(iVar3 / (int)(uint)_DAT_0080783a);
        _DAT_0080341a = _DAT_0080783e;
      }
    }
    else if ((_DAT_00807d94 < _DAT_0080926e) || (_DAT_00807d90 < _DAT_0080926e)) {
      bVar7 = _DAT_00807838 < _DAT_00803416;
      _DAT_00803416 = _DAT_00803416 + 1;
      if (bVar7) {
        _DAT_00803416 = 0;
        _DAT_0080341c = 2;
        if ((int)((uint)_DAT_00807842 - (uint)_DAT_00807840) < 0) {
          iVar3 = -((uint)_DAT_00807842 - (uint)_DAT_00807840);
        }
        else {
          iVar3 = (uint)_DAT_00807842 - (uint)_DAT_00807840;
        }
        _DAT_00803418 = (ushort)(iVar3 / (int)(uint)_DAT_0080783a);
        _DAT_0080341a = _DAT_00807842;
      }
    }
    else {
      _DAT_00803416 = 0;
    }
    break;
  case 2:
    if ((_DAT_0080926e < _DAT_00807d94) && (_DAT_0080926e < _DAT_00807d90)) {
      bVar7 = _DAT_00807838 < _DAT_00803416;
      _DAT_00803416 = _DAT_00803416 + 1;
      if (bVar7) {
        _DAT_00803416 = 0;
        _DAT_0080341c = 1;
        if ((int)((uint)_DAT_00807842 - (uint)_DAT_00807840) < 0) {
          iVar3 = -((uint)_DAT_00807842 - (uint)_DAT_00807840);
        }
        else {
          iVar3 = (uint)_DAT_00807842 - (uint)_DAT_00807840;
        }
        _DAT_00803418 = (ushort)(iVar3 / (int)(uint)_DAT_0080783a);
        _DAT_0080341a = _DAT_00807840;
      }
    }
    else if (_DAT_00807d92 < _DAT_0080926e) {
      bVar7 = _DAT_00807838 < _DAT_00803416;
      _DAT_00803416 = _DAT_00803416 + 1;
      if (bVar7) {
        _DAT_00803416 = 0;
        _DAT_0080341c = 3;
        if ((int)((uint)_DAT_00807844 - (uint)_DAT_00807842) < 0) {
          iVar3 = -((uint)_DAT_00807844 - (uint)_DAT_00807842);
        }
        else {
          iVar3 = (uint)_DAT_00807844 - (uint)_DAT_00807842;
        }
        _DAT_00803418 = (ushort)(iVar3 / (int)(uint)_DAT_0080783a);
        _DAT_0080341a = _DAT_00807844;
      }
    }
    else {
      _DAT_00803416 = 0;
    }
    break;
  case 3:
    if (_DAT_0080926e < _DAT_00807d92) {
      bVar7 = _DAT_00807838 < _DAT_00803416;
      _DAT_00803416 = _DAT_00803416 + 1;
      if (bVar7) {
        _DAT_00803416 = 0;
        _DAT_0080341c = 2;
        if ((int)((uint)_DAT_00807844 - (uint)_DAT_00807842) < 0) {
          iVar3 = -((uint)_DAT_00807844 - (uint)_DAT_00807842);
        }
        else {
          iVar3 = (uint)_DAT_00807844 - (uint)_DAT_00807842;
        }
        _DAT_00803418 = (ushort)(iVar3 / (int)(uint)_DAT_0080783a);
        _DAT_0080341a = _DAT_00807842;
      }
    }
    else {
      _DAT_00803416 = 0;
    }
  }
  uVar4 = (ushort)(((uVar6 - 8) * (uint)_DAT_0080341a * 0x20) / 100);
  if (0x6400 < uVar4) {
    uVar4 = 0x6400;
  }
  if (_DAT_00803418 < 2) {
    _DAT_00803418 = 1;
  }
  uVar2 = ((uVar6 - 8) * (uint)_DAT_00803418 * 0x20) / 100;
  uVar5 = (ushort)uVar2;
  if (_DAT_00809b08 < uVar4) {
    uVar1 = uVar4;
    if ((uVar2 & 0xffff) + (uint)_DAT_00809b08 <= (uint)uVar4) {
      uVar1 = uVar5 + _DAT_00809b08;
    }
  }
  else {
    uVar1 = _DAT_00809b08;
    if (((uVar4 < _DAT_00809b08) &&
        (uVar1 = uVar4, (uVar2 & 0xffff) + (uint)uVar4 <= (uint)_DAT_00809b08)) &&
       (uVar5 <= _DAT_00809b08)) {
      uVar1 = _DAT_00809b08 - uVar5;
    }
  }
  _DAT_00809b08 = uVar1;
  _DAT_0080d18c = _DAT_00809b08;
  if (5 < _DAT_0080d19a) {
    if ((_DAT_00805670 & 8) == 0) {
      tpu_pwm_channel_4_output = tpu_pwm_channel_4_output & 0xffff0000;
    }
    else {
      tpu_pwm_channel_4_output =
           ((((uint)_DAT_0080893a * (uint)_DAT_00809b08) / 0x6400 & 0xffff) * 8000) / 1000 & 0xffff
           | ((uint)_DAT_0080893a * 8000) / 1000 << 0x10;
    }
  }
  if (_DAT_00803424 == 0) {
    if (_DAT_0080d05a < _DAT_00809242) {
      bVar7 = _DAT_00807838 < _DAT_0080341e;
      _DAT_0080341e = _DAT_0080341e + 1;
      if (bVar7) {
        _DAT_0080341e = 0;
        _DAT_00803424 = 1;
        if ((int)((uint)_DAT_00807848 - (uint)_DAT_00807846) < 0) {
          iVar3 = -((uint)_DAT_00807848 - (uint)_DAT_00807846);
        }
        else {
          iVar3 = (uint)_DAT_00807848 - (uint)_DAT_00807846;
        }
        _DAT_00803420 = (ushort)(iVar3 / (int)(uint)_DAT_0080783a);
        _DAT_00803422 = _DAT_00807848;
      }
    }
    else {
      _DAT_0080341e = 0;
    }
  }
  else if (_DAT_00803424 == 1) {
    if (_DAT_00809242 < _DAT_0080d05a) {
      bVar7 = _DAT_00807838 < _DAT_0080341e;
      _DAT_0080341e = _DAT_0080341e + 1;
      if (bVar7) {
        _DAT_0080341e = 0;
        _DAT_00803424 = 0;
        if ((int)((uint)_DAT_00807848 - (uint)_DAT_00807846) < 0) {
          iVar3 = -((uint)_DAT_00807848 - (uint)_DAT_00807846);
        }
        else {
          iVar3 = (uint)_DAT_00807848 - (uint)_DAT_00807846;
        }
        _DAT_00803420 = (ushort)(iVar3 / (int)(uint)_DAT_0080783a);
        _DAT_00803422 = _DAT_00807846;
      }
    }
    else if (_DAT_0080d058 < _DAT_00809242) {
      bVar7 = _DAT_00807838 < _DAT_0080341e;
      _DAT_0080341e = _DAT_0080341e + 1;
      if (bVar7) {
        _DAT_0080341e = 0;
        _DAT_00803424 = 2;
        if ((int)((uint)_DAT_0080784a - (uint)_DAT_00807848) < 0) {
          iVar3 = -((uint)_DAT_0080784a - (uint)_DAT_00807848);
        }
        else {
          iVar3 = (uint)_DAT_0080784a - (uint)_DAT_00807848;
        }
        _DAT_00803420 = (ushort)(iVar3 / (int)(uint)_DAT_0080783a);
        _DAT_00803422 = _DAT_0080784a;
      }
    }
    else {
      _DAT_0080341e = 0;
    }
  }
  else if (_DAT_00803424 == 2) {
    if (_DAT_00809242 < _DAT_0080d058) {
      bVar7 = _DAT_00807838 < _DAT_0080341e;
      _DAT_0080341e = _DAT_0080341e + 1;
      if (bVar7) {
        _DAT_0080341e = 0;
        _DAT_00803424 = 1;
        if ((int)((uint)_DAT_0080784a - (uint)_DAT_00807848) < 0) {
          iVar3 = -((uint)_DAT_0080784a - (uint)_DAT_00807848);
        }
        else {
          iVar3 = (uint)_DAT_0080784a - (uint)_DAT_00807848;
        }
        _DAT_00803420 = (ushort)(iVar3 / (int)(uint)_DAT_0080783a);
        _DAT_00803422 = _DAT_00807848;
      }
    }
    else {
      _DAT_0080341e = 0;
    }
  }
  uVar4 = (ushort)(((uVar6 - 8) * (uint)_DAT_00803422 * 0x20) / 100);
  if (0x6400 < uVar4) {
    uVar4 = 0x6400;
  }
  if (_DAT_00803420 < 2) {
    _DAT_00803420 = 1;
  }
  uVar2 = ((uVar6 - 8) * (uint)_DAT_00803420 * 0x20) / 100;
  uVar6 = (ushort)uVar2;
  if (_DAT_00809b0a < uVar4) {
    uVar2 = (uVar2 & 0xffff) + (uint)_DAT_00809b0a;
    uVar5 = uVar4;
    if (uVar2 <= uVar4) {
      uVar5 = uVar6 + _DAT_00809b0a;
    }
  }
  else {
    uVar5 = _DAT_00809b0a;
    if (((uVar4 < _DAT_00809b0a) &&
        (uVar2 = (uVar2 & 0xffff) + (uint)uVar4, uVar5 = uVar4, uVar2 <= _DAT_00809b0a)) &&
       (uVar6 <= _DAT_00809b0a)) {
      uVar5 = _DAT_00809b0a - uVar6;
    }
  }
  _DAT_00809b0a = uVar5;
  _DAT_0080d18a = _DAT_00809b0a;
  if (5 < _DAT_0080d19a) {
    uVar2 = CONCAT22((short)(uVar2 >> 0x10),_DAT_00805670) & 0xffff0004;
    if ((_DAT_00805670 & 4) != 0) {
      tpu_pwm_channel_3_output =
           ((((uint)_DAT_00808938 * (uint)_DAT_00809b0a) / 0x6400 & 0xffff) * 8000) / 1000 & 0xffff
           | ((uint)_DAT_00808938 * 8000) / 1000 << 0x10;
      return tpu_pwm_channel_3_output;
    }
    tpu_pwm_channel_3_output = tpu_pwm_channel_3_output & 0xffff0000;
  }
  return uVar2;
}



//
// Function: FUN_00032b00 @ 0x00032b00
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00032b00(void)

{
  _DAT_0080342a = 0x80000000;
  _DAT_00803426 = 0x80784c;
  return;
}



//
// Function: timeDeltaCalculator @ 0x00032b16
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void timeDeltaCalculator(void)

{
  _DAT_00809b0e = _DAT_0080972e - _DAT_0080342e;
  _DAT_00809b0c = exponentialMovingAverage();
  _DAT_0080342e = _DAT_0080972e;
  return;
}



//
// Function: FUN_00032b72 @ 0x00032b72
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00032b72(void)

{
  uint uVar1;
  
  if ((((_DAT_008035ec & 0x8000) != 0) &&
      ((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x400) != 0)) &&
     ((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x800) == 0)) {
    oil_pressure_protection_t_00803430.rpm_limit_target = _DAT_00803806;
    return oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x800;
  }
  if ((((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x80) != 0) &&
      ((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x40) == 0)) &&
     (((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x400) == 0 &&
      (((oil_pressure_protection_t_00803430.sensor_status_history_bits & 8) == 0 &&
       ((oil_pressure_protection_t_00803430.sensor_status_history_bits & 2) == 0)))))) {
    oil_pressure_protection_t_00803430.rpm_limit_target = _DAT_00803706;
    return oil_pressure_protection_t_00803430.sensor_status_history_bits & 2;
  }
  uVar1 = oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x200;
  if ((uVar1 != 0) &&
     ((((uVar1 = oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x100, uVar1 == 0
        && (uVar1 = oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x400,
           uVar1 == 0)) &&
       (uVar1 = oil_pressure_protection_t_00803430.sensor_status_history_bits & 8, uVar1 == 0)) &&
      (uVar1 = oil_pressure_protection_t_00803430.sensor_status_history_bits & 2, uVar1 == 0)))) {
    oil_pressure_protection_t_00803430.rpm_limit_target = _DAT_0080370a;
  }
  return uVar1;
}



//
// Function: sensorStatusHistoryTracker @ 0x00032c1c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sensorStatusHistoryTracker(void)

{
  bool bVar1;
  
  oil_pressure_protection_t_00803430.sensor_status_history_bits =
       oil_pressure_protection_t_00803430.sensor_status_history_bits * 2 & 0x2aaaa;
  if ((DAT_0080bdcc & 2) != 0) {
    oil_pressure_protection_t_00803430.sensor_status_history_bits =
         oil_pressure_protection_t_00803430.sensor_status_history_bits | 1;
  }
  if ((DAT_0080bdcc & 8) != 0) {
    oil_pressure_protection_t_00803430.sensor_status_history_bits =
         oil_pressure_protection_t_00803430.sensor_status_history_bits | 4;
  }
  if ((DAT_0080bdcc & 0x10) != 0) {
    oil_pressure_protection_t_00803430.sensor_status_history_bits =
         oil_pressure_protection_t_00803430.sensor_status_history_bits | 0x10;
  }
  if ((DAT_0080bdcc & 1) != 0) {
    oil_pressure_protection_t_00803430.sensor_status_history_bits =
         oil_pressure_protection_t_00803430.sensor_status_history_bits | 0x40;
  }
  if ((DAT_0080bdcc & 4) != 0) {
    oil_pressure_protection_t_00803430.sensor_status_history_bits =
         oil_pressure_protection_t_00803430.sensor_status_history_bits | 0x100;
  }
  if ((DAT_0080bdcc & 0x20) != 0) {
    oil_pressure_protection_t_00803430.sensor_status_history_bits =
         oil_pressure_protection_t_00803430.sensor_status_history_bits | 0x400;
  }
  if ((DAT_0080bdc8 & 0x10) != 0) {
    oil_pressure_protection_t_00803430.sensor_status_history_bits =
         oil_pressure_protection_t_00803430.sensor_status_history_bits | 0x1000;
  }
  if ((DAT_0080bdc7 & 8) != 0) {
    oil_pressure_protection_t_00803430.sensor_status_history_bits =
         oil_pressure_protection_t_00803430.sensor_status_history_bits | 0x10000;
  }
  if ((DAT_0080bdc7 & 4) != 0) {
    oil_pressure_protection_t_00803430.sensor_status_history_bits =
         oil_pressure_protection_t_00803430.sensor_status_history_bits | 0x4000;
  }
  switch(_DAT_0080d17c) {
  case 0:
    if ((((engine_control_flags_t_008035d6.engine_operating_state & 0x10) == 0) ||
        (oil_pressure_protection_t_00803430.validation_timer <= _DAT_00808932)) ||
       (oil_pressure_protection_t_00803430.state_index == 0)) {
      if ((((_DAT_00808932 < oil_pressure_protection_t_00803430.sensor_validation_counter) &&
           (oil_pressure_protection_t_00803430.rpm_limit_previous == 0)) ||
          ((_DAT_008037f8 < _DAT_008096a6 ||
           (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x200) != 0 &&
            ((_DAT_008068cc & 0x200) != 0)))))) ||
         (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x100) != 0 &&
          ((_DAT_008068cc & 0x100) != 0)))) {
        _DAT_0080d17c = 2;
      }
      else if ((oil_pressure_protection_t_00803430.rpm_limit_previous == 0) ||
              (oil_pressure_protection_t_00803430.sensor_validation_counter <= _DAT_00808932)) {
        if ((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x1000) == 0) {
          oil_pressure_protection_t_00803430.sensor_validation_counter =
               oil_pressure_protection_t_00803430.sensor_validation_counter + 1;
          oil_pressure_protection_t_00803430.validation_timer = 0;
        }
        else {
          oil_pressure_protection_t_00803430.validation_timer =
               oil_pressure_protection_t_00803430.validation_timer + 1;
          oil_pressure_protection_t_00803430.sensor_validation_counter = 0;
          if (((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x2000) == 0) &&
             (oil_pressure_protection_t_00803430.state_index < _DAT_008037fc)) {
            oil_pressure_protection_t_00803430.state_index =
                 oil_pressure_protection_t_00803430.state_index + 1;
          }
        }
      }
      else {
        _DAT_0080d17c = 3;
        oil_pressure_protection_t_00803430.rpm_limit_target =
             oil_pressure_protection_t_00803430.rpm_limit_previous;
      }
    }
    else {
      _DAT_0080d17c = 1;
      oil_pressure_protection_t_00803430.rpm_limit_target =
           **(word **)(&DAT_00803442 + (short)oil_pressure_protection_t_00803430.state_index * 4);
    }
    break;
  case 1:
    if ((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x1000) == 0) {
      _DAT_0080d17c = 0;
      oil_pressure_protection_t_00803430.state_index = 0;
    }
    else if ((_DAT_008037f8 < _DAT_008096a6) ||
            (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x100) != 0 &&
             ((_DAT_008068cc & 0x100) != 0)))) {
      _DAT_0080d17c = 2;
    }
    else {
      oil_pressure_protection_t_00803430.sensor_validation_counter = 0;
      oil_pressure_protection_t_00803430.validation_timer = 0;
      oil_pressure_protection_t_00803430.state_index = 0;
    }
    break;
  case 2:
    if (((_DAT_008096a6 < _DAT_008037f8) &&
        (_DAT_0080892c <= circular_buffer_t_0080c3fc.data_buffer_8)) &&
       (circular_buffer_t_0080c3fc.data_buffer_8 <= _DAT_0080892a)) {
      if (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x200) == 0) ||
         ((_DAT_008068cc & 0x200) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x100) == 0) ||
           ((_DAT_008068cc & 0x100) == 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if ((!bVar1) &&
           ((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x1000) != 0)) {
          _DAT_0080d17c = 0;
          oil_pressure_protection_t_00803430.state_index =
               oil_pressure_protection_t_00803430.state_index + 1;
          break;
        }
      }
    }
    if (((((engine_control_flags_t_008035d6.engine_operating_state & 0x10) != 0) &&
         ((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x10) != 0)) &&
        (_DAT_008096a6 <= _DAT_008037f8)) &&
       ((_DAT_0080892c <= circular_buffer_t_0080c3fc.data_buffer_8 &&
        (circular_buffer_t_0080c3fc.data_buffer_8 <= _DAT_0080892a)))) {
      if (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x200) == 0) ||
         ((_DAT_008068cc & 0x200) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x100) == 0) ||
           ((_DAT_008068cc & 0x100) == 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if ((((!bVar1) &&
             (((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x4000) == 0 ||
              ((_DAT_008035ec & 0x1000) == 0)))) &&
            (((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x10000) == 0 ||
             ((_DAT_008035ec & 0x800) == 0)))) &&
           (((((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x80) != 0 &&
              ((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x40) == 0)) ||
             (((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x200) != 0 &&
              ((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x100) == 0)))) ||
            ((((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x800) == 0 &&
              ((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x400) != 0)) &&
             ((_DAT_008035ec & 0x8000) != 0)))))) {
          _DAT_0080d17c = 3;
          if ((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x400) == 0) {
            if (((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x80) == 0) ||
               ((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x40) != 0)) {
              if (((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x200) != 0) &&
                 ((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x100) == 0)) {
                oil_pressure_protection_t_00803430.rpm_limit_target = _DAT_0080370a;
              }
            }
            else {
              oil_pressure_protection_t_00803430.rpm_limit_target = _DAT_00803706;
            }
          }
          break;
        }
      }
    }
    oil_pressure_protection_t_00803430.rpm_ramp_complete = 0;
    oil_pressure_protection_t_00803430.state_index = 0;
    oil_pressure_protection_t_00803430.sensor_validation_counter = 0;
    oil_pressure_protection_t_00803430.validation_timer = 0;
    oil_pressure_protection_t_00803430.rpm_limit_previous = 0;
    break;
  case 3:
    if (_DAT_008096a6 <= _DAT_008037f8) {
      if (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x200) == 0) ||
         ((_DAT_008068cc & 0x200) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x100) == 0) ||
           ((_DAT_008068cc & 0x100) == 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if ((!bVar1) &&
           ((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x1000) != 0)) {
          _DAT_0080d17c = 0;
          oil_pressure_protection_t_00803430.state_index =
               oil_pressure_protection_t_00803430.state_index + 1;
          oil_pressure_protection_t_00803430.rpm_limit_previous =
               oil_pressure_protection_t_00803430.rpm_limit_target;
          break;
        }
      }
    }
    if ((((((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x10) == 0) ||
          (_DAT_008037f8 < _DAT_008096a6)) ||
         (((fault_status_registers_t_00805df2.io_fault_status_1 & 0x100) != 0 &&
          ((_DAT_008068cc & 0x100) != 0)))) ||
        (((_DAT_008035ec & 0x1000) != 0 &&
         ((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x4000) != 0)))) ||
       (((_DAT_008035ec & 0x800) != 0 &&
        ((oil_pressure_protection_t_00803430.sensor_status_history_bits & 0x10000) != 0)))) {
      _DAT_0080d17c = 2;
    }
    else {
      oil_pressure_protection_t_00803430.sensor_validation_counter = 0;
      oil_pressure_protection_t_00803430.validation_timer = 0;
      oil_pressure_protection_t_00803430.state_index = 0;
      FUN_00032b72();
      if ((oil_pressure_protection_t_00803430.sensor_status_history_bits & 1) == 0) {
        if ((oil_pressure_protection_t_00803430.sensor_status_history_bits & 4) == 0) {
          if (((oil_pressure_protection_t_00803430.sensor_status_history_bits & 2) != 0) ||
             ((oil_pressure_protection_t_00803430.sensor_status_history_bits & 8) != 0)) {
            oil_pressure_protection_t_00803430.rpm_limit_target =
                 circular_buffer_t_0080c3fc.data_buffer_8;
            if (_DAT_0080d0aa <= fuel_demand_state_t_0080c9a4.command) {
              oil_pressure_protection_t_00803430.rpm_limit_target =
                   (short)(((uint)(ushort)(fuel_demand_state_t_0080c9a4.command - _DAT_0080d0aa) *
                           (uint)_DAT_008036a6) / 0x1d70) + circular_buffer_t_0080c3fc.data_buffer_8
              ;
            }
            if (_DAT_008036a2 < oil_pressure_protection_t_00803430.rpm_limit_target) {
              oil_pressure_protection_t_00803430.rpm_limit_target = _DAT_008036a2;
            }
            else if (oil_pressure_protection_t_00803430.rpm_limit_target < _DAT_008037fa) {
              oil_pressure_protection_t_00803430.rpm_limit_target = _DAT_008037fa;
            }
          }
        }
        else if (oil_pressure_protection_t_00803430.rpm_limit_target <
                 (ushort)(_DAT_00808924 + _DAT_008037fa)) {
          oil_pressure_protection_t_00803430.rpm_limit_target = _DAT_008037fa;
        }
        else {
          oil_pressure_protection_t_00803430.rpm_limit_target =
               oil_pressure_protection_t_00803430.rpm_limit_target - _DAT_00808924;
        }
      }
      else if ((ushort)(_DAT_008036a2 - _DAT_00808924) <
               oil_pressure_protection_t_00803430.rpm_limit_target) {
        oil_pressure_protection_t_00803430.rpm_limit_target = _DAT_008036a2;
      }
      else {
        oil_pressure_protection_t_00803430.rpm_limit_target =
             _DAT_00808924 + oil_pressure_protection_t_00803430.rpm_limit_target;
      }
    }
  }
  if (((ushort)(_DAT_008037f6 + oil_pressure_protection_t_00803430.rpm_limit_current) <
       oil_pressure_protection_t_00803430.rpm_limit_target) &&
     (oil_pressure_protection_t_00803430.rpm_ramp_complete == 0)) {
    oil_pressure_protection_t_00803430.rpm_limit_current =
         _DAT_008037f6 + oil_pressure_protection_t_00803430.rpm_limit_current;
  }
  else {
    oil_pressure_protection_t_00803430.rpm_limit_current =
         oil_pressure_protection_t_00803430.rpm_limit_target;
    oil_pressure_protection_t_00803430.rpm_ramp_complete = 1;
  }
  _DAT_0080d178 = oil_pressure_protection_t_00803430.rpm_limit_current;
  if ((_DAT_0080d17c != 3) && (_DAT_0080d17c != 1)) {
    _DAT_0080d17a = 0;
    return;
  }
  _DAT_0080d17a = 1;
  return;
}



//
// Function: initOilPressureProtectionPointers @ 0x00033254
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void initOilPressureProtectionPointers(void)

{
  _DAT_0080d17c = 2;
  _DAT_0080d17a = 0;
  _DAT_0080d178 = 0;
  _DAT_00803442 = 0x8036a0;
  _DAT_00803446 = 0x8036a0;
  _DAT_0080344a = 0x8037fe;
  _DAT_0080344e = 0x803800;
  _DAT_00803452 = 0x803802;
  _DAT_00803456 = 0x803804;
  oil_pressure_protection_t_00803430.rpm_limit_previous = 0;
  oil_pressure_protection_t_00803430.sensor_validation_counter = 0;
  oil_pressure_protection_t_00803430.validation_timer = 0;
  oil_pressure_protection_t_00803430.state_index = 0;
  oil_pressure_protection_t_00803430.rpm_ramp_complete = 0;
  oil_pressure_protection_t_00803430.rpm_limit_current = 0;
  oil_pressure_protection_t_00803430.sensor_status_history_bits._2_2_ =
       oil_pressure_protection_t_00803430.sensor_status_history_bits._2_2_ | 0x2000;
  return;
}



//
// Function: FUN_000332ce @ 0x000332ce
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000332ce(void)

{
  byte bVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined *puVar4;
  
  _DAT_00809a9c = 0x2240;
  _DAT_00809a9e = 0;
  DAT_00809aa0 = 0x80;
  _DAT_00809a9a = 0x9955;
  _DAT_00809a8c = 0x2000;
  _DAT_00809a8e = 0;
  DAT_00809a90 = 0x88;
  _DAT_00809a8a = 0x5559;
  _DAT_00809abc = 0xa240;
  _DAT_00809abe = 0;
  DAT_00809ac0 = 0x80;
  _DAT_00809aba = 0x9955;
  _DAT_00809aac = 0xa000;
  _DAT_00809aae = 0;
  DAT_00809ab0 = 0x88;
  _DAT_00809aaa = 0x5559;
  _DAT_00809adc = 0xe240;
  _DAT_00809ade = 0;
  DAT_00809ae0 = 0x80;
  _DAT_00809ada = 0x9955;
  _DAT_00809acc = 0xe000;
  _DAT_00809ace = 0;
  DAT_00809ad0 = 0x88;
  _DAT_00809aca = 0x5559;
  _DAT_0080c9c6 = 0;
  DAT_008034a0 = 0;
  DAT_008034a1 = 1;
  _DAT_0080d498 = 0x1700;
  bVar1 = 0;
  puVar2 = (undefined2 *)&DAT_00809a7c;
  puVar3 = (undefined2 *)&DAT_008077aa;
  puVar4 = &DAT_00809aea;
  do {
    *puVar2 = *puVar3;
    *puVar4 = 1;
    bVar1 = bVar1 + 1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  } while (bVar1 < 6);
  _DAT_00809a52 = 0;
  _DAT_0080346e = &DAT_0080345a;
  _DAT_00803486 = &DAT_00803472;
  _DAT_0080345a = 2;
  _DAT_0080345c = 0x807454;
  _DAT_00803462 = 2;
  _DAT_00803464 = 0x807474;
  _DAT_0080346a = 0x807494;
  _DAT_00803472 = 2;
  _DAT_00803474 = 0x807656;
  _DAT_0080347a = 2;
  _DAT_0080347c = 0x807670;
  _DAT_00803482 = 0x80768a;
  _DAT_00809a76 = _DAT_008073f4;
  _DAT_00809a72 = _DAT_008073f4;
  _DAT_00809af8 = 0x1700;
  _DAT_00809a48 = 0x1700;
  _DAT_00809a4c = 0x1700;
  _DAT_00809a44 = 0x1700;
  _DAT_00809a4a = 0x1700;
  _DAT_00809a46 = 0x1700;
  _DAT_00809a42 = 0x1700;
  _DAT_00809af4 = 0x28f;
  _DAT_00809afa = 0x28f;
  _DAT_00809af2 = 0x28f;
  _DAT_00809afe = 0x28f;
  _DAT_00805e12 = _DAT_00805e12 & 0x7fff;
  vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status & 0xfb6e;
  _DAT_00803494 = 0x28f0000;
  _DAT_00803490 = 0x807404;
  _DAT_0080349c = 0x28f0000;
  _DAT_00803498 = 0x807404;
  FUN_00035548();
  return;
}



//
// Function: vp44TimingRangeValidation @ 0x00033524
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44TimingRangeValidation(void)

{
  bool bVar1;
  ushort uVar2;
  short sVar3;
  byte bVar4;
  undefined **ppuVar5;
  undefined *local_2a;
  undefined2 local_26;
  undefined *puStack_24;
  undefined1 local_6;
  undefined1 uStack_5;
  
  ppuVar5 = (undefined **)&stack0xffffffe0;
  if (DAT_00809af1 == '\0') {
    bVar4 = 0;
  }
  else {
    bVar4 = DAT_00809af1 - 1;
  }
  if (_DAT_0080742e < circular_buffer_t_0080c3fc.data_buffer_4) {
    DAT_008034a7 = DAT_008034a7 + 1;
    uVar2 = _DAT_0080742e;
    if (DAT_0080743b < DAT_008034a7) {
      vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status | 0x400;
      _DAT_00805e54 = _DAT_00805e54 | 0x400;
      DAT_008034a7 = 0;
    }
  }
  else {
    DAT_008034a7 = 0;
    uVar2 = circular_buffer_t_0080c3fc.data_buffer_4;
  }
  local_6 = (undefined1)((uint)((int)(uint)uVar2 >> 1) >> 8);
  DAT_00809a98 = local_6;
  uStack_5 = (undefined1)((int)(uint)uVar2 >> 1);
  DAT_00809a97 = uStack_5;
  if (_DAT_00807430 < _DAT_00809a52) {
    DAT_008034a9 = DAT_008034a9 + 1;
    sVar3 = _DAT_00807430;
    if (DAT_0080743b < DAT_008034a9) {
      vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status | 0x400;
      _DAT_00805e54 = _DAT_00805e54 | 0x400;
      DAT_008034a9 = 0;
    }
  }
  else if (_DAT_00809a52 < _DAT_00807432) {
    DAT_008034a8 = DAT_008034a8 + 1;
    sVar3 = _DAT_00807432;
    if (DAT_0080743b < DAT_008034a8) {
      vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status | 0x400;
      _DAT_00805e54 = _DAT_00805e54 | 0x400;
      DAT_008034a8 = 0;
    }
  }
  else {
    DAT_008034a9 = 0;
    DAT_008034a8 = 0;
    sVar3 = _DAT_00809a52;
  }
  local_6 = (undefined1)((ushort)sVar3 >> 8);
  DAT_00809a96 = local_6;
  uStack_5 = (undefined1)sVar3;
  DAT_00809a95 = uStack_5;
  if (_DAT_00807436 < _DAT_0080739e) {
    DAT_008034ab = DAT_008034ab + 1;
    sVar3 = _DAT_00807436;
    if (DAT_0080743b < DAT_008034ab) {
      vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status | 0x400;
      _DAT_00805e54 = _DAT_00805e54 | 0x400;
      DAT_008034ab = 0;
    }
  }
  else if (_DAT_0080739e < _DAT_00807438) {
    DAT_008034aa = DAT_008034aa + 1;
    sVar3 = _DAT_00807438;
    if (DAT_0080743b < DAT_008034aa) {
      vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status | 0x400;
      _DAT_00805e54 = _DAT_00805e54 | 0x400;
      DAT_008034aa = 0;
    }
  }
  else {
    DAT_008034ab = 0;
    DAT_008034aa = 0;
    sVar3 = _DAT_0080739e;
  }
  local_6 = (undefined1)((ushort)sVar3 >> 8);
  DAT_00809a94 = local_6;
  uStack_5 = (undefined1)sVar3;
  DAT_00809a93 = uStack_5;
  if ((&DAT_00809aea)[(short)(ushort)bVar4] == '\0') {
    _DAT_00809a54 = 0;
  }
  else {
    _DAT_00809a54 = _DAT_00809a6c + *(short *)(&DAT_00809a7c + (short)(ushort)bVar4 * 2);
    if ((int)(uint)_DAT_0080742c < (int)(short)_DAT_00809a54) {
      DAT_008034a6 = DAT_008034a6 + 1;
      if (DAT_0080743b < DAT_008034a6) {
        vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status | 0x400;
        _DAT_00805e54 = _DAT_00805e54 | 0x400;
        DAT_008034a6 = 0;
      }
      _DAT_00809a54 = _DAT_0080742c;
    }
    else if ((short)_DAT_00809a54 < 0) {
      DAT_008034a5 = DAT_008034a5 + 1;
      if (DAT_0080743b < DAT_008034a5) {
        vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status | 0x400;
        _DAT_00805e54 = _DAT_00805e54 | 0x400;
        DAT_008034a5 = 0;
      }
      _DAT_00809a54 = 0;
    }
    else {
      DAT_008034a6 = 0;
      DAT_008034a5 = 0;
    }
  }
  local_6 = (undefined1)(_DAT_00809a54 >> 8);
  DAT_00809a92 = local_6;
  uStack_5 = (undefined1)_DAT_00809a54;
  DAT_00809a91 = uStack_5;
  _DAT_00805f8c = _DAT_00805f8c + (uint)fuel_demand_state_t_0080c9a4.command;
  puStack_24 = (undefined *)0x3381e;
  FUN_00035488();
  if (((vp44_fault_state_t_00805e14.fault_status & 0x20) == 0) || ((_DAT_008068e6 & 0x20) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    puStack_24 = &DAT_00809a8c;
    local_26 = 2;
    ppuVar5 = &local_2a;
    local_2a = &DAT_00ffc800;
    FUN_0001913e();
  }
  if ((_DAT_008073b2 <= circular_buffer_t_0080c3fc.data_buffer_4) &&
     (circular_buffer_t_0080c3fc.data_buffer_4 <= _DAT_008073b0)) {
    *(undefined4 *)((int)ppuVar5 + -4) = 0x33876;
    FUN_000339c2();
  }
  return;
}



//
// Function: FUN_00033880 @ 0x00033880
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_00033880(int param_1)

{
  int iVar1;
  ushort uVar2;
  undefined2 local_6;
  
  DAT_0080348a = 1;
  DAT_00809aa1 = *(undefined1 *)(param_1 + 7);
  DAT_00809aa2 = *(undefined1 *)(param_1 + 8);
  DAT_00809aa3 = *(undefined1 *)(param_1 + 9);
  DAT_00809aa4 = *(byte *)(param_1 + 10);
  DAT_00809aa5 = *(undefined1 *)(param_1 + 0xb);
  DAT_00809aa6 = *(undefined1 *)(param_1 + 0xc);
  DAT_00809aa7 = *(undefined1 *)(param_1 + 0xd);
  DAT_00809aa8 = *(undefined1 *)(param_1 + 0xe);
  DAT_00809a5e = DAT_00809aa2;
  DAT_00809a5f = DAT_00809aa1;
  DAT_00809af0 = (undefined1)((int)(DAT_00809aa4 & 0xe0) >> 5);
  local_6 = CONCAT11(DAT_00809aa4,DAT_00809aa3) & 0x1fff;
  _DAT_00809a5c = local_6;
  local_6 = CONCAT11(DAT_00809aa6,DAT_00809aa5);
  _DAT_00809a4e = local_6 << 2;
  circular_buffer_t_0080c3fc.data_buffer_rest[0x1e] = (char)((ushort)_DAT_00809a4e >> 8);
  circular_buffer_t_0080c3fc.data_buffer_rest[0x1f] = (char)_DAT_00809a4e;
  circular_buffer_t_0080c3fc.data_buffer_rest._28_2_ = _DAT_00807cde;
  local_6 = CONCAT11(DAT_00809aa8,DAT_00809aa7);
  iVar1 = (short)local_6 * 0xe66;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0x7ff;
  }
  _DAT_00809a58 = (short)(iVar1 >> 0xb) + -0x1cb6;
  uVar2 = DAT_0080bdc6 & 1;
  if (((DAT_0080bdc6 & 1) == 0) &&
     (uVar2 = circular_buffer_t_0080c3fc.data_buffer_4,
     circular_buffer_t_0080c3fc.data_buffer_4 < _DAT_00807434)) {
    DAT_0080348a = 1;
    DAT_0080348b = DAT_0080348b + '\x01';
    circular_buffer_t_0080c3fc.data_buffer_rest._28_2_ = _DAT_00807cde;
    circular_buffer_t_0080c3fc.data_buffer_rest[0x1e] = (char)((ushort)_DAT_00809a4e >> 8);
    circular_buffer_t_0080c3fc.data_buffer_rest[0x1f] = (char)_DAT_00809a4e;
    return circular_buffer_t_0080c3fc.data_buffer_4;
  }
  DAT_0080348b = 0;
  return uVar2;
}



//
// Function: FUN_000339c2 @ 0x000339c2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000339c2(void)

{
  undefined1 local_6;
  undefined1 uStack_5;
  
  local_6 = (undefined1)((ushort)_DAT_008073ea >> 8);
  DAT_00809ab8 = local_6;
  uStack_5 = (undefined1)_DAT_008073ea;
  DAT_00809ab7 = uStack_5;
  local_6 = (undefined1)((ushort)_DAT_008073e8 >> 8);
  DAT_00809ab6 = local_6;
  uStack_5 = (undefined1)_DAT_008073e8;
  DAT_00809ab5 = uStack_5;
  local_6 = (undefined1)((ushort)_DAT_008073e6 >> 8);
  DAT_00809ab4 = local_6;
  uStack_5 = (undefined1)_DAT_008073e6;
  DAT_00809ab3 = uStack_5;
  local_6 = (undefined1)((ushort)_DAT_008073e4 >> 8);
  DAT_00809ab2 = local_6;
  uStack_5 = (undefined1)_DAT_008073e4;
  DAT_00809ab1 = uStack_5;
  FUN_0001913e(&DAT_00ffc800);
  return;
}



//
// Function: FUN_00033a3a @ 0x00033a3a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00033a3a(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 local_6;
  
  DAT_00809ac1 = *(undefined1 *)(param_1 + 7);
  DAT_00809ac2 = *(undefined1 *)(param_1 + 8);
  DAT_00809ac3 = *(undefined1 *)(param_1 + 9);
  DAT_00809ac4 = *(undefined1 *)(param_1 + 10);
  DAT_00809ac5 = *(undefined1 *)(param_1 + 0xb);
  DAT_00809ac6 = *(undefined1 *)(param_1 + 0xc);
  DAT_00809ac7 = *(undefined1 *)(param_1 + 0xd);
  DAT_00809ac8 = *(undefined1 *)(param_1 + 0xe);
  local_6 = CONCAT11(*(undefined1 *)(param_1 + 8),*(undefined1 *)(param_1 + 7));
  uVar1 = local_6;
  _DAT_00809a60 = local_6;
  local_6 = CONCAT11(*(undefined1 *)(param_1 + 10),*(undefined1 *)(param_1 + 9));
  uVar2 = local_6;
  _DAT_00809a62 = local_6;
  local_6 = CONCAT11(*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 0xb));
  _DAT_00809af2 = local_6;
  _DAT_00809a64 = local_6;
  local_6 = CONCAT11(*(undefined1 *)(param_1 + 0xe),*(undefined1 *)(param_1 + 0xd));
  _DAT_00809a66 = local_6;
  if (DAT_008073df == '\x01') {
    _DAT_00809a6e = uVar1 & 0xff;
  }
  else if (DAT_008073df == '\x02') {
    _DAT_00809a6e = (uint)uVar1;
  }
  else if (DAT_008073df == '\x04') {
    _DAT_00809a6e = (uint)uVar1 + (uint)uVar2 * 0x10000;
  }
  if (_DAT_00809a6e < _DAT_00809a76) {
    _DAT_00809a76 = _DAT_00809a6e;
  }
  if (_DAT_00809a72 < _DAT_00809a6e) {
    _DAT_00809a72 = _DAT_00809a6e;
  }
  _DAT_00809afe = local_6;
  return;
}



//
// Function: FUN_00033b8c @ 0x00033b8c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00033b8c(void)

{
  undefined1 local_6;
  undefined1 uStack_5;
  
  local_6 = (undefined1)((ushort)_DAT_008073a2 >> 8);
  DAT_00809ad2 = local_6;
  uStack_5 = (undefined1)_DAT_008073a2;
  DAT_00809ad1 = uStack_5;
  DAT_00809ad3 = DAT_008073bb;
  DAT_00809ad4 = DAT_008073ec;
  DAT_00809ad5 = DAT_008073ed;
  DAT_00809ad6 = DAT_008073ee;
  DAT_00809ad7 = DAT_008073a0;
  DAT_00809ad8 = DAT_008073a1;
  FUN_0001913e(&DAT_00ffc800);
  return;
}



//
// Function: FUN_00033bf2 @ 0x00033bf2
//

void FUN_00033bf2(int param_1)

{
  DAT_00809a6b = *(undefined1 *)(param_1 + 7);
  DAT_00809ae2 = *(undefined1 *)(param_1 + 8);
  DAT_00809ae3 = *(undefined1 *)(param_1 + 9);
  DAT_00809ae4 = *(undefined1 *)(param_1 + 10);
  DAT_00809ae5 = *(undefined1 *)(param_1 + 0xb);
  DAT_00809ae6 = *(undefined1 *)(param_1 + 0xc);
  DAT_00809ae7 = *(undefined1 *)(param_1 + 0xd);
  DAT_00809ae8 = *(undefined1 *)(param_1 + 0xe);
  DAT_00809ae1 = DAT_00809a6b;
  FUN_000350ae();
  return;
}



//
// Function: baseTimingTableLookup @ 0x00033c48
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void baseTimingTableLookup(void)

{
  undefined8 uVar1;
  
  _DAT_0080c9c8 = fuel_demand_state_t_0080c9a4.command;
  _DAT_00803460 = circular_buffer_t_0080c3fc.data_buffer_4;
  _DAT_00803468 = fuel_demand_state_t_0080c9a4.command;
  uVar1 = tableInterpolationLookup(_DAT_0080346e);
  _DAT_00809a6c = (short)((ulonglong)uVar1 >> 0x20);
  return;
}



//
// Function: liftPumpFuelDeliveryController @ 0x00033c84
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void liftPumpFuelDeliveryController(void)

{
  short sVar1;
  ushort uVar2;
  undefined8 uVar3;
  
  _DAT_00803478 = circular_buffer_t_0080c3fc.data_buffer_4;
  _DAT_00803480 = fuel_demand_state_t_0080c9a4.command;
  uVar3 = tableInterpolationLookup(_DAT_00803486);
  _DAT_00809a5a = (short)((ulonglong)uVar3 >> 0x20);
  uVar2 = _DAT_00807400;
  if ((DAT_0080348f == '\0') && (uVar2 = _DAT_0080d482, DAT_0080348e != '\0')) {
    uVar2 = _DAT_008073d2;
  }
  _DAT_00809a68 = _DAT_008073aa + (short)((int)((int)_DAT_008073a8 * (uint)uVar2) / 0x161);
  _DAT_00809a50 = _DAT_00809a5a + _DAT_00809a68;
  sVar1 = _DAT_00809a50 / 3;
  _DAT_00809a7a = sVar1 - _DAT_008034ac;
  if ((short)_DAT_00809a7a < 0) {
    if ((-(uint)_DAT_008073ae == (int)(short)_DAT_00809a7a ||
         -(int)(short)_DAT_00809a7a < (int)(uint)_DAT_008073ae) && (_DAT_008073ae != 0)) {
      _DAT_00809a7a = -_DAT_008073ae;
      sVar1 = _DAT_00809a7a + _DAT_008034ac;
    }
  }
  else if (((int)(uint)_DAT_008073ac < (int)(short)_DAT_00809a7a) && (_DAT_008073ac != 0)) {
    _DAT_00809a7a = _DAT_008073ac;
    sVar1 = _DAT_008073ac + _DAT_008034ac;
  }
  _DAT_008034ac = sVar1;
  _DAT_00809a52 = _DAT_008034ac * 3;
  _DAT_00809af6 =
       _DAT_00807418 +
       (short)((int)(((int)_DAT_00807416 - (int)_DAT_00807418) *
                    ((uint)circular_buffer_t_0080c3fc.data_buffer_4 - (uint)_DAT_0080741c)) /
              (int)((uint)_DAT_0080741a - (uint)_DAT_0080741c));
  return;
}



//
// Function: derateThresholdIoController @ 0x00033dca
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void derateThresholdIoController(void)

{
  if (_DAT_00809d50 == 0) {
    DAT_0080bdf0 = DAT_0080bdf0 & 0xbf;
  }
  else {
    DAT_0080bdf0 = DAT_0080bdf0 | 0x40;
  }
  if ((_DAT_00809d50 != _DAT_008034ae) && (DAT_008034a4 < 2)) {
    DAT_008034a4 = DAT_008034a4 + 1;
  }
  _DAT_008034ae = _DAT_00809d50;
  return;
}



//
// Function: vp44FsoFaultDetectionMonitor @ 0x00033e0e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44FsoFaultDetectionMonitor(void)

{
  bool bVar1;
  int iVar2;
  
  if (DAT_008034a1 != '\0') {
    if ((DAT_00809a5f & 0x20) == 0) {
      DAT_008034b5 = DAT_008034b5 + 1;
      if (DAT_008073b5 <= DAT_008034b5) {
        vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status & 0xfff7
        ;
        DAT_008034b5 = 0;
      }
      DAT_008034b4 = 0;
    }
    else {
      DAT_008034b4 = DAT_008034b4 + 1;
      if (DAT_008073b5 <= DAT_008034b4) {
        vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status | 8;
        _DAT_00805e54 = _DAT_00805e54 | 8;
        DAT_008034b4 = 0;
      }
      DAT_008034b5 = 0;
    }
    if ((DAT_00809a5f & 0x40) == 0) {
      DAT_008034b7 = DAT_008034b7 + 1;
      if (DAT_008073b5 <= DAT_008034b7) {
        vp44_fault_state_t_00805e14.fso_fault_status =
             vp44_fault_state_t_00805e14.fso_fault_status & 0xff7f;
        DAT_008034b7 = 0;
      }
      DAT_008034b6 = 0;
    }
    else {
      DAT_008034b6 = DAT_008034b6 + 1;
      if (DAT_008073b5 <= DAT_008034b6) {
        _DAT_00805e56 = _DAT_00805e56 | 0x80;
        vp44_fault_state_t_00805e14.fso_fault_status =
             vp44_fault_state_t_00805e14.fso_fault_status & 0xfeff | 0x80;
        DAT_008034b6 = 0;
      }
      DAT_008034b7 = 0;
    }
    if (((DAT_00809a5f & 0x20) == 0) || ((DAT_00809a5f & 0x40) == 0)) {
      if (_DAT_008073c2 < _DAT_00809a58) {
        DAT_008034b8 = DAT_008034b8 + 1;
        if (DAT_008073b5 <= DAT_008034b8) {
          _DAT_00805e56 = _DAT_00805e56 | 0x40;
          vp44_fault_state_t_00805e14.fso_fault_status =
               vp44_fault_state_t_00805e14.fso_fault_status & 0xfeff | 0x40;
          DAT_008034b8 = 0;
        }
      }
      else {
        DAT_008034b8 = 0;
      }
    }
    if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x80) == 0) ||
       ((_DAT_008068e8 & 0x80) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (((vp44_fault_state_t_00805e14.fault_status & 8) == 0) || ((_DAT_008068e6 & 8) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x800) == 0) ||
           ((_DAT_008068e8 & 0x800) == 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (!bVar1) {
          if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x400) == 0) ||
             ((_DAT_008068e8 & 0x400) == 0)) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          if (!bVar1) {
            if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x200) == 0) ||
               ((_DAT_008068e8 & 0x200) == 0)) {
              bVar1 = false;
            }
            else {
              bVar1 = true;
            }
            if (((!bVar1) && (_DAT_00809a58 < _DAT_008073c4)) && (_DAT_008073b8 < _DAT_0080926e)) {
              if (_DAT_00809a58 == _DAT_008034b0) {
                DAT_008034ba = DAT_008034ba + 1;
                if (_DAT_008073c6 <= DAT_008034ba) {
                  vp44_fault_state_t_00805e14.fso_fault_status =
                       vp44_fault_state_t_00805e14.fso_fault_status | 0x100;
                  _DAT_00805e56 = _DAT_00805e56 | 0x100;
                  _DAT_008034b2 = _DAT_00809a58;
                  DAT_008034ba = 0;
                }
              }
              else {
                _DAT_008034b0 = _DAT_00809a58;
                DAT_008034ba = 0;
              }
            }
          }
        }
      }
    }
    if (_DAT_00809a58 < _DAT_008073fe) {
      DAT_008034b9 = DAT_008034b9 + 1;
      if (DAT_008073b5 <= DAT_008034b9) {
        vp44_fault_state_t_00805e14.fso_fault_status =
             vp44_fault_state_t_00805e14.fso_fault_status & 0xffbf;
        DAT_008034b9 = 0;
      }
    }
    else {
      DAT_008034b9 = 0;
    }
    if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x100) != 0) &&
       ((_DAT_008068e8 & 0x100) != 0)) {
      if ((int)_DAT_00809a58 - (int)_DAT_008034b2 < 0) {
        iVar2 = -((int)_DAT_00809a58 - (int)_DAT_008034b2);
      }
      else {
        iVar2 = (int)_DAT_00809a58 - (int)_DAT_008034b2;
      }
      if ((int)(uint)_DAT_008073c8 < iVar2) {
        vp44_fault_state_t_00805e14.fso_fault_status =
             vp44_fault_state_t_00805e14.fso_fault_status & 0xfeff;
      }
    }
    if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x80) == 0) ||
       ((_DAT_008068e8 & 0x80) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    _DAT_00809a48 = 0x1700;
    if ((bVar1) && (_DAT_0080740a < 0x1700)) {
      _DAT_00809a48 = _DAT_0080740a;
    }
    if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x40) == 0) ||
       ((_DAT_008068e8 & 0x40) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) && (_DAT_0080740c < _DAT_00809a48)) {
      _DAT_00809a48 = _DAT_0080740c;
    }
    if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x100) == 0) ||
       ((_DAT_008068e8 & 0x100) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) && (_DAT_0080740e < _DAT_00809a48)) {
      _DAT_00809a48 = _DAT_0080740e;
    }
  }
  return;
}



//
// Function: vp44FsoCircuitFaultDetection @ 0x000341ea
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44FsoCircuitFaultDetection(void)

{
  if (DAT_008034a1 != '\0') {
    if ((DAT_00809a5f & 1) != 0) {
      if ((_DAT_0080741e < circular_buffer_t_0080c3fc.data_buffer_4) &&
         (circular_buffer_t_0080c3fc.data_buffer_4 <= _DAT_0080743c)) {
        DAT_008034bb = DAT_008034bb + 1;
        if (DAT_00807425 <= DAT_008034bb) {
          vp44_fault_state_t_00805e14.fso_fault_status =
               vp44_fault_state_t_00805e14.fso_fault_status | 0x20;
          _DAT_00805e56 = _DAT_00805e56 | 0x20;
          DAT_008034a0 = 1;
          DAT_0080348f = 1;
          DAT_008034bb = 0;
        }
      }
      else if (_DAT_0080743c < circular_buffer_t_0080c3fc.data_buffer_4) {
        DAT_008034bc = DAT_008034bc + 1;
        if (DAT_0080743e <= DAT_008034bc) {
          vp44_fault_state_t_00805e14.fso_fault_status =
               vp44_fault_state_t_00805e14.fso_fault_status | 0x20;
          _DAT_00805e56 = _DAT_00805e56 | 0x20;
          DAT_008034a0 = 1;
          DAT_0080348f = 1;
          DAT_008034bc = 0;
        }
      }
      else {
        DAT_008034bb = 0;
        DAT_008034bc = 0;
      }
      DAT_008034bd = 0;
      return;
    }
    DAT_008034bd = DAT_008034bd + 1;
    if (DAT_00807425 <= DAT_008034bd) {
      vp44_fault_state_t_00805e14.fso_fault_status =
           vp44_fault_state_t_00805e14.fso_fault_status & 0xffdf;
      DAT_0080348f = 0;
      DAT_008034bd = 0;
    }
    DAT_008034bb = 0;
    DAT_008034bc = 0;
  }
  return;
}



//
// Function: vp44FsoCircuitFaultDetectionBit1 @ 0x000342f6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44FsoCircuitFaultDetectionBit1(void)

{
  if (DAT_008034a1 != '\0') {
    if ((DAT_00809a5f & 2) != 0) {
      if ((_DAT_0080741e < circular_buffer_t_0080c3fc.data_buffer_4) &&
         (circular_buffer_t_0080c3fc.data_buffer_4 <= _DAT_0080743c)) {
        DAT_008034be = DAT_008034be + 1;
        if (DAT_00807425 <= DAT_008034be) {
          vp44_fault_state_t_00805e14.fso_fault_status =
               vp44_fault_state_t_00805e14.fso_fault_status | 0x10;
          _DAT_00805e56 = _DAT_00805e56 | 0x10;
          _DAT_00809af8 = _DAT_00807428;
          DAT_008034be = 0;
        }
      }
      else if (_DAT_0080743c < circular_buffer_t_0080c3fc.data_buffer_4) {
        DAT_008034bf = DAT_008034bf + 1;
        if (DAT_0080743e <= DAT_008034bf) {
          vp44_fault_state_t_00805e14.fso_fault_status =
               vp44_fault_state_t_00805e14.fso_fault_status | 0x10;
          _DAT_00805e56 = _DAT_00805e56 | 0x10;
          _DAT_00809af8 = _DAT_00807428;
          DAT_008034bf = 0;
        }
      }
      else {
        DAT_008034be = 0;
        DAT_008034bf = 0;
      }
      DAT_008034c0 = 0;
      return;
    }
    DAT_008034c0 = DAT_008034c0 + 1;
    if (DAT_00807425 <= DAT_008034c0) {
      vp44_fault_state_t_00805e14.fso_fault_status =
           vp44_fault_state_t_00805e14.fso_fault_status & 0xffef;
      _DAT_00809af8 = 0x1700;
      DAT_008034c0 = 0;
    }
    DAT_008034be = 0;
    DAT_008034bf = 0;
  }
  return;
}



//
// Function: FUN_000343f8 @ 0x000343f8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000343f8(void)

{
  if (DAT_008034a1 != '\0') {
    if ((DAT_00809a5f & 0x10) != 0) {
      if ((_DAT_00807422 < circular_buffer_t_0080c3fc.data_buffer_4) &&
         (circular_buffer_t_0080c3fc.data_buffer_4 <= _DAT_00807440)) {
        DAT_008034c1 = DAT_008034c1 + 1;
        if (DAT_00807424 <= DAT_008034c1) {
          vp44_fault_state_t_00805e14.fso_fault_status =
               vp44_fault_state_t_00805e14.fso_fault_status | 8;
          _DAT_00805e56 = _DAT_00805e56 | 8;
          DAT_008034c1 = 0;
        }
      }
      else if (_DAT_00807440 < circular_buffer_t_0080c3fc.data_buffer_4) {
        DAT_008034c2 = DAT_008034c2 + 1;
        if (DAT_0080743f <= DAT_008034c2) {
          vp44_fault_state_t_00805e14.fso_fault_status =
               vp44_fault_state_t_00805e14.fso_fault_status | 8;
          _DAT_00805e56 = _DAT_00805e56 | 8;
          DAT_008034c2 = 0;
        }
      }
      else {
        DAT_008034c1 = 0;
        DAT_008034c2 = 0;
      }
      DAT_008034c3 = 0;
      return;
    }
    if ((DAT_00809a5f & 8) == 0) {
      DAT_008034c3 = DAT_008034c3 + 1;
      if (DAT_00807425 <= DAT_008034c3) {
        vp44_fault_state_t_00805e14.fso_fault_status =
             vp44_fault_state_t_00805e14.fso_fault_status & 0xfff7;
        DAT_008034c3 = 0;
      }
    }
    DAT_008034c1 = 0;
    DAT_008034c2 = 0;
  }
  return;
}



//
// Function: FUN_000344e8 @ 0x000344e8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000344e8(void)

{
  short sVar1;
  bool bVar2;
  
  if (DAT_008034a1 != '\0') {
    _DAT_00809afa = coreTableInterpolation();
    sVar1 = _DAT_00809afa;
    if (_DAT_00809a4e != 0) {
      sVar1 = coreTableInterpolation();
    }
    _DAT_00809af4 = sVar1;
    _DAT_00809afc = _DAT_00809afa - _DAT_00809af4;
    if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x800) == 0) ||
       ((_DAT_008068e8 & 0x800) == 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) {
      if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x400) == 0) ||
         ((_DAT_008068e8 & 0x400) == 0)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (!bVar2) {
        if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x200) == 0) ||
           ((_DAT_008068e8 & 0x200) == 0)) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if (!bVar2) {
          if ((DAT_00809a5f & 0x80) == 0) {
            vp44_fault_state_t_00805e14.fault_status =
                 vp44_fault_state_t_00805e14.fault_status & 0xfffb;
            DAT_008034c4 = 0;
          }
          else {
            DAT_008034c4 = DAT_008034c4 + 1;
            if (DAT_00807403 <= DAT_008034c4) {
              vp44_fault_state_t_00805e14.fault_status =
                   vp44_fault_state_t_00805e14.fault_status | 4;
              _DAT_00805e54 = _DAT_00805e54 | 4;
              DAT_008034c4 = 0;
            }
          }
          if (((vp44_fault_state_t_00805e14.fault_status & 4) == 0) || ((_DAT_008068e6 & 4) == 0)) {
            bVar2 = false;
          }
          else {
            bVar2 = true;
          }
          if (!bVar2) {
            switch(engine_operating_mode_t_0080c810.state) {
            case 2:
            case 6:
            case 7:
              if (_DAT_0080744e < _DAT_00809afc) {
                DAT_008034c6 = DAT_008034c6 + 1;
                if (DAT_00807402 <= DAT_008034c6) {
                  vp44_fault_state_t_00805e14.fault_status =
                       vp44_fault_state_t_00805e14.fault_status | 2;
                  _DAT_00805e54 = _DAT_00805e54 | 2;
                  DAT_008034c6 = 0;
                }
                DAT_008034c8 = 0;
              }
              else {
                if ((_DAT_00809afc < _DAT_00807452) &&
                   (DAT_008034c8 = DAT_008034c8 + 1, DAT_00807402 <= DAT_008034c8)) {
                  vp44_fault_state_t_00805e14.fault_status =
                       vp44_fault_state_t_00805e14.fault_status & 0xfffd;
                  DAT_008034c8 = 0;
                }
                DAT_008034c6 = 0;
              }
              DAT_008034c5 = 0;
              DAT_008034c7 = 0;
              return;
            case 3:
              if (_DAT_0080744c < _DAT_00809afc) {
                DAT_008034c5 = DAT_008034c5 + 1;
                if (DAT_00807402 <= DAT_008034c5) {
                  vp44_fault_state_t_00805e14.fault_status =
                       vp44_fault_state_t_00805e14.fault_status | 2;
                  _DAT_00805e54 = _DAT_00805e54 | 2;
                  DAT_008034c5 = 0;
                }
                DAT_008034c7 = 0;
              }
              else {
                if ((_DAT_00809afc < _DAT_00807450) &&
                   (DAT_008034c7 = DAT_008034c7 + 1, DAT_00807402 <= DAT_008034c7)) {
                  vp44_fault_state_t_00805e14.fault_status =
                       vp44_fault_state_t_00805e14.fault_status & 0xfffd;
                  DAT_008034c7 = 0;
                }
                DAT_008034c5 = 0;
              }
              DAT_008034c6 = 0;
              DAT_008034c8 = 0;
              return;
            default:
              DAT_008034c5 = '\0';
              DAT_008034c7 = 0;
              DAT_008034c6 = '\0';
              DAT_008034c8 = 0;
            }
          }
        }
      }
    }
  }
  return;
}



//
// Function: vp44FsoFaultDetectionAndProtectionController @ 0x00034782
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44FsoFaultDetectionAndProtectionController(void)

{
  bool bVar1;
  ushort uVar2;
  
  if (DAT_008034a1 == '\0') {
    return;
  }
  if ((((DAT_00809a5e & 1) == 0) || (_DAT_00809a68 <= _DAT_00807414)) ||
     ((int)(uint)_DAT_00809af6 <= (int)_DAT_00809a68)) {
    vp44_fault_state_t_00805e14.fso_fault_status =
         vp44_fault_state_t_00805e14.fso_fault_status & 0xfffd;
    DAT_008034ce = 0;
  }
  else {
    DAT_008034ce = DAT_008034ce + 1;
    if (DAT_00807413 <= DAT_008034ce) {
      vp44_fault_state_t_00805e14.fso_fault_status =
           vp44_fault_state_t_00805e14.fso_fault_status | 2;
      _DAT_00805e56 = _DAT_00805e56 | 2;
      DAT_008034ce = 0;
    }
  }
  if ((DAT_008073ef != '\0') && (DAT_008034c9 == '\0')) {
    if ((((_DAT_0080742a < _DAT_0080926e) &&
         ((_DAT_008073dc < circular_buffer_t_0080c3fc.data_buffer_4 &&
          (circular_buffer_t_0080c3fc.data_buffer_4 < _DAT_008073da)))) &&
        (fuel_demand_state_t_0080c9a4.command < _DAT_008073d8)) && (_DAT_00809d50 == 0)) {
      uVar2 = _DAT_008034ca + 1;
      if (_DAT_008073d6 <= (ushort)(_DAT_008034ca + 1)) {
        DAT_0080348e = '\x01';
        uVar2 = _DAT_008034ca;
      }
      _DAT_008034ca = uVar2;
      if ((DAT_0080348e != '\0') &&
         (_DAT_008034cc = _DAT_008034cc + 1, _DAT_008073d4 <= _DAT_008034cc)) {
        DAT_008034c9 = '\x01';
        DAT_0080348e = '\0';
        if ((_DAT_00809a76 < _DAT_008073ce) || (_DAT_008073ca < _DAT_00809a76)) {
          vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status | 0x40
          ;
          _DAT_00805e54 = _DAT_00805e54 | 0x40;
        }
        else if ((_DAT_008073ce < _DAT_00809a76) && (_DAT_00809a76 < _DAT_008073ca)) {
          vp44_fault_state_t_00805e14.fault_status =
               vp44_fault_state_t_00805e14.fault_status & 0xffbf;
        }
      }
    }
    else {
      _DAT_008034ca = 0;
      _DAT_008034cc = 0;
    }
  }
  if (((vp44_fault_state_t_00805e14.fault_status & 0x40) == 0) || ((_DAT_008068e6 & 0x40) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if (((vp44_fault_state_t_00805e14.fso_fault_status & 2) == 0) || ((_DAT_008068e8 & 2) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      _DAT_00809a4c = 0x1700;
      return;
    }
  }
  _DAT_00809a4c = _DAT_008073f2;
  return;
}



//
// Function: vp44FsoFaultBit0Monitor @ 0x00034976
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44FsoFaultBit0Monitor(void)

{
  if (DAT_008034a1 != '\0') {
    if ((DAT_00809a5e & 4) != 0) {
      if ((_DAT_008073b6 < fuel_demand_state_t_0080c9a4.command) && (_DAT_00807410 < _DAT_00809af4))
      {
        _DAT_008034d0 = _DAT_008034d0 + 1;
        if (DAT_008073b4 < _DAT_008034d0) {
          vp44_fault_state_t_00805e14.fso_fault_status =
               vp44_fault_state_t_00805e14.fso_fault_status | 1;
          _DAT_00805e56 = _DAT_00805e56 | 1;
          _DAT_00809a44 = _DAT_008073fa;
          _DAT_008034d0 = 0;
        }
      }
      else {
        _DAT_008034d0 = 0;
      }
      _DAT_008034d2 = 0;
      return;
    }
    _DAT_008034d2 = _DAT_008034d2 + 1;
    if (DAT_008073b4 < _DAT_008034d2) {
      vp44_fault_state_t_00805e14.fso_fault_status =
           vp44_fault_state_t_00805e14.fso_fault_status & 0xfffe;
      _DAT_00809a44 = 0x1700;
      _DAT_008034d2 = 0;
    }
    _DAT_008034d0 = 0;
  }
  return;
}



//
// Function: vp44FsoFaultBit15Monitor @ 0x00034a32
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44FsoFaultBit15Monitor(void)

{
  bool bVar1;
  
  if (DAT_008034a1 == '\0') {
    return;
  }
  if ((DAT_00809a5e & 0x20) == 0) {
    DAT_008034d8 = DAT_008034d8 + 1;
    if (DAT_00807425 < DAT_008034d8) {
      vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status & 0x7fff;
      _DAT_00809a4a = 0x1700;
      DAT_008034d8 = 0;
    }
    _DAT_008034d4 = 0;
    _DAT_008034d6 = 0;
    return;
  }
  if (engine_operating_mode_t_0080c810.state == 1) {
    DAT_008034d8 = 0;
    return;
  }
  if (engine_operating_mode_t_0080c810.state == 8) {
    DAT_008034d8 = 0;
    return;
  }
  if (((fault_status_registers_t_00805df2.engine_fault_status & 0x1000) == 0) ||
     ((_DAT_008068c8 & 0x1000) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if (((fault_status_registers_t_00805df2.engine_fault_status & 0x4000) == 0) ||
       ((_DAT_008068c8 & 0x4000) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      _DAT_008034d4 = _DAT_008034d4 + 1;
      if (DAT_0080743a < _DAT_008034d4) {
        vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status | 0x8000
        ;
        _DAT_00805e54 = _DAT_00805e54 | 0x8000;
        _DAT_008034d4 = 0;
      }
      goto LAB_00034af2;
    }
  }
  _DAT_008034d4 = 0;
LAB_00034af2:
  _DAT_008034d6 = _DAT_008034d6 + 1;
  if (DAT_0080743a < _DAT_008034d6) {
    _DAT_00809a4a = _DAT_008073f0;
    _DAT_008034d6 = 0;
  }
  DAT_008034d8 = 0;
  return;
}



//
// Function: vp44FsoMultiBitFaultMonitor @ 0x00034b46
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44FsoMultiBitFaultMonitor(void)

{
  bool bVar1;
  
  if ((DAT_008034a1 != '\0') && (1 < DAT_008034a4)) {
    if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x800) == 0) ||
       ((_DAT_008068e8 & 0x800) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x400) == 0) ||
         ((_DAT_008068e8 & 0x400) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x200) == 0) ||
           ((_DAT_008068e8 & 0x200) == 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (!bVar1) {
          if ((DAT_00809a5f & 4) != 0) {
            if (_DAT_00809d50 != 0) {
              if (_DAT_0080744a < circular_buffer_t_0080c3fc.data_buffer_4) {
                _DAT_008034da = _DAT_008034da + 1;
                if (DAT_008073de < _DAT_008034da) {
                  vp44_fault_state_t_00805e14.fault_status =
                       vp44_fault_state_t_00805e14.fault_status | 0x4000;
                  _DAT_00805e54 = _DAT_00805e54 | 0x4000;
                  _DAT_008034da = 0;
                }
              }
              else {
                _DAT_008034da = 0;
              }
              _DAT_008034e0 = 0;
              return;
            }
            _DAT_008034e0 = _DAT_008034e0 + 1;
            if (DAT_008073de < _DAT_008034e0) {
              vp44_fault_state_t_00805e14.fault_status =
                   vp44_fault_state_t_00805e14.fault_status & 0xdfff;
              _DAT_008034e0 = 0;
            }
            _DAT_008034da = 0;
            return;
          }
          if (_DAT_00809d50 == 0) {
            if (_DAT_0080744a < circular_buffer_t_0080c3fc.data_buffer_4) {
              _DAT_008034de = _DAT_008034de + 1;
              if (DAT_008073de < _DAT_008034de) {
                vp44_fault_state_t_00805e14.fault_status =
                     vp44_fault_state_t_00805e14.fault_status | 0x2000;
                _DAT_00805e54 = _DAT_00805e54 | 0x2000;
                _DAT_008034de = 0;
              }
              _DAT_008034dc = 0;
            }
            else {
              _DAT_008034da = 0;
            }
            _DAT_008034de = _DAT_008034de + 1;
            if (DAT_008073de < _DAT_008034de) {
              vp44_fault_state_t_00805e14.fault_status =
                   vp44_fault_state_t_00805e14.fault_status | 0x2000;
              _DAT_00805e54 = _DAT_00805e54 | 0x2000;
              _DAT_008034de = 0;
            }
            _DAT_008034e0 = 0;
            return;
          }
          _DAT_008034e0 = _DAT_008034e0 + 1;
          if (DAT_008073de < _DAT_008034e0) {
            vp44_fault_state_t_00805e14.fault_status =
                 vp44_fault_state_t_00805e14.fault_status & 0xbfff;
            _DAT_008034e0 = 0;
          }
          _DAT_008034de = 0;
        }
      }
    }
  }
  return;
}



//
// Function: vp44FsoStuckHighFaultDetector @ 0x00034d16
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44FsoStuckHighFaultDetector(void)

{
  if (DAT_008034a1 != '\0') {
    if ((DAT_00809a5e & 8) != 0) {
      _DAT_008034e2 = _DAT_008034e2 + 1;
      if (DAT_008073ba < _DAT_008034e2) {
        vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status | 0x1000
        ;
        _DAT_00805e54 = _DAT_00805e54 | 0x1000;
        _DAT_008034e2 = 0;
      }
      _DAT_008034e4 = 0;
      return;
    }
    _DAT_008034e4 = _DAT_008034e4 + 1;
    if (DAT_008073ba < _DAT_008034e4) {
      vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status & 0xefff;
      _DAT_008034e4 = 0;
    }
    _DAT_008034e2 = 0;
  }
  return;
}



//
// Function: vp44FsoStuckLowFaultDetector @ 0x00034d9e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44FsoStuckLowFaultDetector(void)

{
  bool bVar1;
  
  if (DAT_008034a1 != '\0') {
    if ((DAT_00809a5e & 0x80) == 0) {
      _DAT_00805e12 = _DAT_00805e12 & 0xf7ff;
    }
    else {
      if (((vp44_fault_state_t_00805e14.fault_status & 0x400) == 0) ||
         ((_DAT_008068e6 & 0x400) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x800) == 0) ||
           ((_DAT_008068e8 & 0x800) == 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (!bVar1) {
          if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x400) == 0) ||
             ((_DAT_008068e8 & 0x400) == 0)) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          if (!bVar1) {
            if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x200) == 0) ||
               ((_DAT_008068e8 & 0x200) == 0)) {
              bVar1 = false;
            }
            else {
              bVar1 = true;
            }
            if (!bVar1) {
              _DAT_00805e12 = _DAT_00805e12 | 0x800;
              _DAT_00805e52 = _DAT_00805e52 | 0x800;
              return;
            }
          }
        }
      }
    }
  }
  return;
}



//
// Function: vp44FsoFaultConditionDetector @ 0x00034e7a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44FsoFaultConditionDetector(void)

{
  bool bVar1;
  int iVar2;
  
  if (DAT_008034a1 == '\0') {
    return;
  }
  if (_DAT_008034a2 < _DAT_00807446) {
    _DAT_008034a2 = _DAT_008034a2 + 1;
  }
  if (((_DAT_00805e12 & 0x800) == 0) || ((_DAT_008068e4 & 0x800) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x800) == 0) ||
       ((_DAT_008068e8 & 0x800) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x400) == 0) ||
         ((_DAT_008068e8 & 0x400) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x200) == 0) ||
           ((_DAT_008068e8 & 0x200) == 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (!bVar1) {
          if ((((_DAT_00809a54 == 0) && (_DAT_00807442 < circular_buffer_t_0080c3fc.data_buffer_4))
              && (_DAT_00807420 < _DAT_00809a5c)) &&
             (DAT_008034e6 = DAT_008034e6 + 1, DAT_0080739c <= DAT_008034e6)) {
            vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status | 1;
            _DAT_00805e54 = _DAT_00805e54 | 1;
            DAT_008034a0 = 1;
            DAT_008034e6 = 0;
          }
          goto LAB_00034fa0;
        }
      }
    }
  }
  DAT_008034e6 = 0;
LAB_00034fa0:
  if (((_DAT_00805e12 & 0x800) == 0) || ((_DAT_008068e4 & 0x800) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x800) == 0) ||
       ((_DAT_008068e8 & 0x800) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x400) == 0) ||
         ((_DAT_008068e8 & 0x400) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((vp44_fault_state_t_00805e14.fso_fault_status & 0x200) == 0) ||
           ((_DAT_008068e8 & 0x200) == 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (!bVar1) {
          if (circular_buffer_t_0080c3fc.data_buffer_4 <= _DAT_00807444) {
            return;
          }
          if ((int)((uint)circular_buffer_t_0080c3fc.data_buffer_4 - (uint)_DAT_00809a4e) < 0) {
            iVar2 = -((uint)circular_buffer_t_0080c3fc.data_buffer_4 - (uint)_DAT_00809a4e);
          }
          else {
            iVar2 = (uint)circular_buffer_t_0080c3fc.data_buffer_4 - (uint)_DAT_00809a4e;
          }
          if (iVar2 <= (int)(uint)_DAT_00807426) {
            return;
          }
          if ((byte)(DAT_008034e7 + 1) < DAT_0080739c) {
            DAT_008034e7 = DAT_008034e7 + 1;
            return;
          }
          _DAT_00805e12 = _DAT_00805e12 | 0x8000;
          _DAT_00805e52 = _DAT_00805e52 | 0x8000;
          DAT_008034a0 = 1;
          DAT_008034e7 = 0;
          return;
        }
      }
    }
  }
  DAT_008034e7 = 0;
  return;
}



//
// Function: FUN_000350ae @ 0x000350ae
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000350ae(void)

{
  if (DAT_008034a1 != '\0') {
    if (((DAT_00809a6b & 1) == 0) && ((DAT_00809a6b & 2) == 0)) {
      vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status & 0xfdff;
      _DAT_00809a46 = 0x1700;
    }
    else {
      vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status | 0x200;
      _DAT_00805e54 = _DAT_00805e54 | 0x200;
      _DAT_00809a46 = _DAT_008073e2;
    }
    if ((DAT_00809a6b & 4) == 0) {
      vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status & 0xfeff;
      _DAT_00809a42 = 0x1700;
    }
    else {
      vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status | 0x100;
      _DAT_00805e54 = _DAT_00805e54 | 0x100;
      _DAT_00809a42 = _DAT_008073e0;
    }
    if ((DAT_00809a6b & 8) != 0) {
      vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status | 0x80;
      _DAT_00805e54 = _DAT_00805e54 | 0x80;
      DAT_008034a0 = 1;
    }
    if ((DAT_00809a6b & 0x10) != 0) {
      vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status | 0x10;
      _DAT_00805e54 = _DAT_00805e54 | 0x10;
      DAT_008034a0 = 1;
    }
    if ((DAT_00809a6b & 0x20) == 0) {
      _DAT_00805e12 = _DAT_00805e12 & 0xdfff;
    }
    else {
      _DAT_00805e12 = _DAT_00805e12 | 0x2000;
      _DAT_00805e52 = _DAT_00805e52 | 0x2000;
    }
    if ((DAT_00809a6b & 0x40) != 0) {
      _DAT_00805e12 = _DAT_00805e12 | 0x4000;
      _DAT_00805e52 = _DAT_00805e52 | 0x4000;
      return;
    }
    _DAT_00805e12 = _DAT_00805e12 & 0xbfff;
  }
  return;
}



//
// Function: multiParameterMinimumSelector @ 0x00035228
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void multiParameterMinimumSelector(void)

{
  _DAT_0080d498 = 0x1700;
  if (_DAT_00809af8 < 0x1700) {
    _DAT_0080d498 = _DAT_00809af8;
  }
  if (_DAT_00809a48 < _DAT_0080d498) {
    _DAT_0080d498 = _DAT_00809a48;
  }
  if (_DAT_00809a4c < _DAT_0080d498) {
    _DAT_0080d498 = _DAT_00809a4c;
  }
  if (_DAT_00809a44 < _DAT_0080d498) {
    _DAT_0080d498 = _DAT_00809a44;
  }
  if (_DAT_00809a4a < _DAT_0080d498) {
    _DAT_0080d498 = _DAT_00809a4a;
  }
  if (_DAT_00809a46 < _DAT_0080d498) {
    _DAT_0080d498 = _DAT_00809a46;
  }
  if (_DAT_00809a42 < _DAT_0080d498) {
    _DAT_0080d498 = _DAT_00809a42;
  }
  return;
}



//
// Function: systemStatusMonitor @ 0x00035298
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void systemStatusMonitor(void)

{
  bool bVar1;
  
  if (DAT_008034a1 != '\0') {
    if (((vp44_fault_state_t_00805e14.fault_status & 0x20) == 0) || ((_DAT_008068e6 & 0x20) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (DAT_0080348a != '\0') {
        vp44_fault_state_t_00805e14.fso_fault_status =
             vp44_fault_state_t_00805e14.fso_fault_status & 0xf1ff;
        _DAT_0080348c = 0;
        DAT_0080348a = 0;
        return;
      }
      if (_DAT_008073f8 < _DAT_0080348c) {
        switch(DAT_00809d47 & 7) {
        case 0:
        case 1:
        case 3:
        case 6:
        case 7:
          vp44_fault_state_t_00805e14.fso_fault_status =
               vp44_fault_state_t_00805e14.fso_fault_status | 0x800;
          _DAT_00805e56 = _DAT_00805e56 | 0x800;
          break;
        case 2:
          vp44_fault_state_t_00805e14.fso_fault_status =
               vp44_fault_state_t_00805e14.fso_fault_status | 0x200;
          _DAT_00805e56 = _DAT_00805e56 | 0x200;
          break;
        case 4:
        case 5:
          vp44_fault_state_t_00805e14.fso_fault_status =
               vp44_fault_state_t_00805e14.fso_fault_status | 0x400;
          _DAT_00805e56 = _DAT_00805e56 | 0x400;
          break;
        default:
          vp44_fault_state_t_00805e14.fso_fault_status =
               vp44_fault_state_t_00805e14.fso_fault_status | 0x800;
          _DAT_00805e56 = _DAT_00805e56 | 0x800;
        }
        _DAT_0080348c = 0;
        return;
      }
      _DAT_0080348c = _DAT_0080348c + 1;
      if (_DAT_008073f8 < _DAT_0080348c) {
        FUN_0001913e(&DAT_00ffc800);
      }
    }
  }
  return;
}



//
// Function: liftPumpCommStatusMonitor @ 0x000353ec
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte liftPumpCommStatusMonitor(void)

{
  byte bVar1;
  
  bVar1 = DAT_0080348b;
  if (DAT_00807412 < DAT_0080348b) {
    _DAT_00805e12 = _DAT_00805e12 | 0x1000;
    _DAT_00805e52 = _DAT_00805e52 | 0x1000;
    DAT_0080348b = DAT_00807412;
    return bVar1;
  }
  if ((DAT_0080bdc6 & 1) == 0) {
    _DAT_00805e12 = _DAT_00805e12 & 0xefff;
  }
  return DAT_0080bdc6 & 1;
}



//
// Function: vp44FsoFaultEnableController @ 0x0003544a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44FsoFaultEnableController(void)

{
  _DAT_0080c9c6 = (ushort)DAT_008034a0;
  if (((engine_operating_mode_t_0080c810.state != 5) &&
      (engine_operating_mode_t_0080c810.state != 8)) && (DAT_008034a0 != 1)) {
    DAT_008034a1 = 1;
    return;
  }
  DAT_008034a1 = 0;
  return;
}



//
// Function: FUN_00035488 @ 0x00035488
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_00035488(void)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = _DAT_008034e8;
  _DAT_00809b00 = CONCAT11(DAT_00809a92,DAT_00809a91);
  uVar2 = _DAT_00803614 & 0x2000;
  if ((((((_DAT_00803614 & 0x2000) != 0) && (fuel_arbitrator_diag_t_0080cff8.rpm_target != 1)) &&
       (fuel_arbitrator_diag_t_0080cff8.rpm_target != 2)) &&
      ((_DAT_0080d17a == 0 && (_DAT_0080969a == 0)))) &&
     ((_DAT_00809d50 == 0 &&
      ((uVar2 = _DAT_00809b00, _DAT_008077b8 < _DAT_00809b00 &&
       (uVar2 = circular_buffer_t_0080c3fc.data_buffer_4,
       _DAT_008077ba < circular_buffer_t_0080c3fc.data_buffer_4)))))) {
    if (_DAT_008034e8 < _DAT_008077b6) {
      _DAT_008034e8 = _DAT_008034e8 + 1;
      return uVar1;
    }
    vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status | 0x20;
    _DAT_00805e54 = _DAT_00805e54 | 0x20;
    return _DAT_008034e8;
  }
  _DAT_008034e8 = 0;
  return uVar2;
}



//
// Function: FUN_00035548 @ 0x00035548
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00035548(void)

{
  _DAT_008034e8 = 0;
  vp44_fault_state_t_00805e14.fault_status = vp44_fault_state_t_00805e14.fault_status & 0xffdf;
  return;
}



//
// Function: lookupTableInterpolation @ 0x00035560
//

short lookupTableInterpolation(short *param_1)

{
  short *psVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  ushort *puVar6;
  ushort *puVar7;
  
  psVar1 = *(short **)(param_1 + 1);
  puVar6 = (ushort *)((int)psVar1 + (int)*param_1);
  uVar3 = param_1[3];
  if (*puVar6 < uVar3) {
    for (; puVar6[1] <= uVar3; puVar6 = puVar6 + 1) {
      if (*(ushort *)((int)psVar1 + (int)*psVar1) <= uVar3) {
        iVar5 = ((int)psVar1 + (int)*psVar1) - (int)psVar1;
        *param_1 = (short)iVar5 + -2;
        return *(short *)(*(int *)(param_1 + 4) + iVar5);
      }
    }
  }
  else {
    do {
      if (uVar3 <= (ushort)psVar1[1]) {
        sVar4 = *(short *)(*(int *)(param_1 + 4) + 2);
        *param_1 = 2;
        return sVar4;
      }
      puVar6 = puVar6 + -1;
    } while (uVar3 < *puVar6);
  }
  uVar2 = *puVar6;
  *param_1 = (short)((int)puVar6 - (int)psVar1);
  puVar7 = (ushort *)(*(int *)(param_1 + 4) + ((int)puVar6 - (int)psVar1));
  if (*puVar7 < puVar7[1]) {
    sVar4 = *puVar7 + (short)(((uint)(ushort)(puVar7[1] - *puVar7) * (uint)(ushort)(uVar3 - uVar2))
                             / (uint)(ushort)(puVar6[1] - *puVar6));
  }
  else {
    sVar4 = *puVar7 - (short)(((uint)(ushort)(*puVar7 - puVar7[1]) * (uint)(ushort)(uVar3 - uVar2))
                             / (uint)(ushort)(puVar6[1] - *puVar6));
  }
  return sVar4;
}



//
// Function: exponentialMovingAverage @ 0x00035608
// ERROR: Failed to decompile
//

//
// Function: FUN_0003566e @ 0x0003566e
// ERROR: Failed to decompile
//

//
// Function: coreTableInterpolation @ 0x000356f8
// ERROR: Failed to decompile
//

//
// Function: FUN_0003574e @ 0x0003574e
// ERROR: Failed to decompile
//

//
// Function: proportionalCalculation @ 0x000357d2
//

undefined4 proportionalCalculation(uint param_1,uint param_2,uint param_3)

{
  return (int)(((ulonglong)param_2 * (ulonglong)param_1) / (ulonglong)param_3);
}



//
// Function: rpmFuelCalculation @ 0x000357e4
//

undefined4 rpmFuelCalculation(int param_1,int param_2,int param_3)

{
  return (int)(((longlong)(int)((ulonglong)((longlong)param_2 * (longlong)param_1) >> 0x20) << 0x20
               | (longlong)(int)((longlong)param_2 * (longlong)param_1)) / (longlong)param_3);
}



//
// Function: tableInterpolationLookup @ 0x000357f6
//

undefined8 tableInterpolationLookup(short *param_1)

{
  short *psVar1;
  short *psVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 in_D1;
  ushort uVar10;
  undefined2 uVar11;
  undefined4 unaff_D3;
  ushort uVar12;
  ushort *puVar13;
  ushort *puVar14;
  short sVar15;
  ushort *puVar16;
  
  psVar1 = *(short **)(param_1 + 1);
  puVar13 = (ushort *)((int)psVar1 + (int)*psVar1);
  puVar14 = (ushort *)((int)psVar1 + (int)*param_1);
  uVar10 = param_1[3];
  if (*puVar14 < uVar10) {
    for (; puVar14[1] <= uVar10; puVar14 = puVar14 + 1) {
      if (*puVar13 <= uVar10) {
        puVar14 = puVar13 + -1;
        uVar10 = *puVar13;
        break;
      }
    }
  }
  else {
    do {
      if (uVar10 <= (ushort)psVar1[1]) {
        puVar14 = (ushort *)(psVar1 + 1);
        uVar10 = psVar1[1];
        break;
      }
      puVar14 = puVar14 + -1;
    } while (uVar10 < *puVar14);
  }
  psVar2 = *(short **)(param_1 + 5);
  puVar16 = (ushort *)((int)psVar2 + (int)*psVar2);
  puVar13 = (ushort *)((int)psVar2 + (int)param_1[4]);
  uVar12 = param_1[7];
  if (*puVar13 < uVar12) {
    for (; puVar13[1] <= uVar12; puVar13 = puVar13 + 1) {
      if (*puVar16 <= uVar12) {
        puVar13 = puVar16 + -1;
        uVar12 = *puVar16;
        break;
      }
    }
  }
  else {
    do {
      if (uVar12 <= (ushort)psVar2[1]) {
        puVar13 = (ushort *)(psVar2 + 1);
        uVar12 = psVar2[1];
        break;
      }
      puVar13 = puVar13 + -1;
    } while (uVar12 < *puVar13);
  }
  uVar6 = puVar14[1] - *puVar14;
  uVar10 = uVar10 - *puVar14;
  sVar15 = (short)puVar14 - (short)psVar1;
  *param_1 = sVar15;
  uVar7 = puVar13[1] - *puVar13;
  uVar3 = *puVar13;
  param_1[4] = (short)((int)puVar13 - (int)psVar2);
  puVar13 = (ushort *)
            ((int)sVar15 +
            *(int *)(param_1 + 8) +
            (int)(short)((ushort)(((int)puVar13 - (int)psVar2) - 2U >> 1) & 0x7fff) * (int)*psVar1);
  uVar4 = puVar13[-1];
  if (uVar4 < *puVar13) {
    sVar15 = (short)(((uint)(ushort)(*puVar13 - uVar4) * (uint)uVar10) / (uint)uVar6);
  }
  else {
    sVar15 = -(short)(((uint)(ushort)(uVar4 - *puVar13) * (uint)uVar10) / (uint)uVar6);
  }
  uVar4 = sVar15 + uVar4;
  puVar13 = (ushort *)((int)*psVar1 + (int)(puVar13 + -1));
  uVar5 = *puVar13;
  uVar11 = (undefined2)((uint)unaff_D3 >> 0x10);
  if (uVar5 < puVar13[1]) {
    sVar15 = (short)(((uint)(ushort)(puVar13[1] - uVar5) * (uint)uVar10) / (uint)uVar6);
  }
  else {
    uVar8 = (uint)(ushort)(uVar5 - puVar13[1]) * (uint)uVar10;
    uVar11 = (undefined2)(uVar8 % (uint)uVar6);
    sVar15 = -(short)(uVar8 / uVar6);
  }
  uVar5 = uVar5 + sVar15;
  if (uVar4 < uVar5) {
    uVar8 = (uint)(ushort)(uVar5 - uVar4) * (uint)(ushort)(uVar12 - uVar3);
    uVar9 = CONCAT22((short)(uVar8 % (uint)uVar7),uVar4 + (short)(uVar8 / uVar7));
  }
  else {
    uVar9 = CONCAT22(uVar11,uVar4 - (short)(((uint)(ushort)(uVar4 - uVar5) *
                                            (uint)(ushort)(uVar12 - uVar3)) / (uint)uVar7));
  }
  return CONCAT44(uVar9,in_D1);
}



// Export complete - 772 functions processed
