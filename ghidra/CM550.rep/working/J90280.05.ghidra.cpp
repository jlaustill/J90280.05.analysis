// Ghidra C++ Decompilation Export - J90280.05 Firmware
// Generated with renamed functions, variables, and meaningful types
// Sat Aug 30 10:32:03 MDT 2025


//
// Function: rpm_rate_limiter @ 0x0000a16a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rpm_rate_limiter(void)

{
  _rpm_delta_value = _current_engine_rpm_raw - _previous_engine_rpm;
  _previous_engine_rpm = _current_engine_rpm_raw;
  _rpm_rate_limited_value = FUN_00035608();
  if (_rpm_rate_limited_value < _rpm_rate_min_threshold) {
    _rpm_rate_limited_value = _rpm_rate_min_threshold;
    dma_control_flags1 = _rpm_rate_min_threshold * 0x10000 + 0x80000000;
  }
  else if (dma_desc_dest_addr1._2_2_ < _rpm_rate_limited_value) {
    _rpm_rate_limited_value = dma_desc_dest_addr1._2_2_;
    dma_control_flags1 = dma_desc_dest_addr1._2_2_ * 0x10000 + 0x80000000;
  }
  _rpm_rate_secondary_calc = FUN_00035608();
  return;
}



//
// Function: rpm_system_state_controller @ 0x0000a204
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort rpm_system_state_controller(void)

{
  ushort uVar1;
  
  uVar1 = _diagnostic_system_flags_1 & 0x1000;
  if ((_diagnostic_system_flags_1 & 0x1000) != 0) {
    if (_rpm_threshold_lower < _rpm_rate_limited_value) {
      _rpm_threshold_exceeded_flag = 1;
      _rpm_control_timer_1 = _rpm_timer_reload_value_1;
    }
    else if (_rpm_control_timer_1 == 0) {
      _rpm_threshold_exceeded_flag = 0;
    }
    else {
      _rpm_control_timer_1 = _rpm_control_timer_1 + -1;
    }
    if ((((_request_to_strobe_set_0_then_set_1_fso_driver_0_1 == 0) ||
         (_rpm_threshold_exceeded_flag != 0)) || (_current_engine_rpm_raw < _rpm_threshold_upper))
       || ((_rpm_threshold_lower < _rpm_rate_limited_value ||
           (_rpm_rate_secondary_calc < _rpm_secondary_threshold)))) {
      if (_rpm_control_override_flag == 0) {
        if (_rpm_control_timer_2 == 0) {
          _rpm_system_mode_flag = 0;
        }
        else {
          _rpm_control_timer_2 = _rpm_control_timer_2 + -1;
        }
      }
      else {
        _rpm_system_mode_flag = 1;
        _rpm_control_timer_2 = _rpm_timer_reload_value_2;
      }
    }
    else {
      _rpm_system_mode_flag = 1;
      _rpm_control_timer_2 = _rpm_timer_reload_value_2;
    }
    if (_rpm_system_mode_flag == 1) {
      _DAT_00800014 = _current_engine_rpm_raw;
      _DAT_008091c4 = lookupTableInterpolation((short *)&dma_descriptor_base1);
      return _DAT_008091c4;
    }
    uVar1 = _DAT_008091c4;
    if (_DAT_008091c4 < max_number_of_shutdowns_before_restart_is_not_allowed_0_255) {
      uVar1 = _DAT_008062d6 + _DAT_008091c4;
      _DAT_008091c4 = uVar1;
      if (max_number_of_shutdowns_before_restart_is_not_allowed_0_255 < uVar1) {
        _DAT_008091c4 = max_number_of_shutdowns_before_restart_is_not_allowed_0_255;
      }
    }
  }
  return uVar1;
}



//
// Function: FUN_0000a30c @ 0x0000a30c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000a30c(void)

{
  if (_DAT_008091c4 < _DAT_0080d494) {
    _DAT_0080d494 = _DAT_008091c4;
    _DAT_0080d496 = 0x11;
  }
  return;
}



//
// Function: FUN_0000a32a @ 0x0000a32a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0000a32a(void)

{
  ushort uVar1;
  
  uVar1 = _diagnostic_system_flags_1 & 0x2000;
  if ((_diagnostic_system_flags_1 & 0x2000) != 0) {
    if (_DAT_00806302 < (short)_rpm_rate_limited_value) {
      none_none = 1;
      _DAT_00800004 = _DAT_00806300;
    }
    else if (_DAT_00800004 == 0) {
      none_none = 0;
    }
    else {
      _DAT_00800004 = _DAT_00800004 + -1;
    }
    uVar1 = _rpm_rate_limited_value;
    if ((((_request_to_strobe_set_0_then_set_1_fso_driver_0_1 == 0) || (none_none != 0)) ||
        (uVar1 = _DAT_0080926e, _DAT_0080926e <= _DAT_008062ea)) ||
       ((uVar1 = _rpm_rate_limited_value, _DAT_00806302 < (short)_rpm_rate_limited_value ||
        (uVar1 = _rpm_rate_secondary_calc, (short)_rpm_rate_secondary_calc < _DAT_008062f0)))) {
      if (_rpm_control_override_flag == 0) {
        if (_DAT_00800008 == 0) {
          _DAT_008091d2 = 0;
        }
        else {
          _DAT_00800008 = _DAT_00800008 + -1;
        }
      }
      else {
        _DAT_008091d2 = 1;
        _DAT_00800008 = _DAT_008062ec;
      }
    }
    else {
      _DAT_008091d2 = 1;
      _DAT_00800008 = _DAT_008062ec;
    }
    if (_DAT_008091d2 == 1) {
      _DAT_00800020 = _current_engine_rpm_raw;
      _DAT_008091c6 = lookupTableInterpolation((short *)&dma_descriptor_base2);
      return _DAT_008091c6;
    }
    if (_DAT_008091c6 < 0x400) {
      _DAT_008091c6 = _DAT_008062ee + _DAT_008091c6;
      uVar1 = _DAT_008062ee;
      if (0x400 < _DAT_008091c6) {
        _DAT_008091c6 = 0x400;
      }
    }
  }
  return uVar1;
}



//
// Function: FUN_0000a428 @ 0x0000a428
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000a428(void)

{
  _DAT_008091d6 = _DAT_0080c9ae;
  if (_DAT_008091c6 < _DAT_0080c9ae) {
    _DAT_0080c9ae = _DAT_008091c6;
    _DAT_0080c9b0 = 3;
  }
  return;
}



//
// Function: FUN_0000a44c @ 0x0000a44c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0000a44c(void)

{
  ushort uVar1;
  
  uVar1 = _diagnostic_system_flags_1 & 0x4000;
  if ((_diagnostic_system_flags_1 & 0x4000) != 0) {
    if (_DAT_008062e8 < (short)_rpm_rate_limited_value) {
      _DAT_008091d8 = 1;
      _DAT_00800000 = _DAT_008062fc;
    }
    else if (_DAT_00800000 == 0) {
      _DAT_008091d8 = 0;
    }
    else {
      _DAT_00800000 = _DAT_00800000 + -1;
    }
    uVar1 = _rpm_rate_limited_value;
    if ((((_request_to_strobe_set_0_then_set_1_fso_driver_0_1 == 0) || (_DAT_008091d8 != 0)) ||
        (uVar1 = _current_engine_rpm_raw, _DAT_008062e6 < _current_engine_rpm_raw)) ||
       ((uVar1 = _rpm_rate_limited_value, _DAT_008062e8 < (short)_rpm_rate_limited_value ||
        (uVar1 = _rpm_rate_secondary_calc, (short)_rpm_rate_secondary_calc < _DAT_008062e4)))) {
      if (_rpm_control_override_flag == 0) {
        if (_DAT_0080000a == 0) {
          _DAT_008091d4 = 0;
        }
        else {
          _DAT_0080000a = _DAT_0080000a + -1;
        }
      }
      else {
        _DAT_008091d4 = 1;
        _DAT_0080000a = _DAT_008062e0;
      }
    }
    else {
      _DAT_008091d4 = 1;
      _DAT_0080000a = _DAT_008062e0;
    }
    if (_DAT_008091d4 != 0) {
      _fuel_arbitrator_threshold_3 = _DAT_008062de;
      return uVar1;
    }
    uVar1 = _fuel_arbitrator_threshold_3;
    if (_fuel_arbitrator_threshold_3 < _oil_pressure_precrank_status) {
      uVar1 = _DAT_008062e2 + _fuel_arbitrator_threshold_3;
      _fuel_arbitrator_threshold_3 = uVar1;
      if (_oil_pressure_precrank_status < uVar1) {
        _fuel_arbitrator_threshold_3 = _oil_pressure_precrank_status;
      }
    }
  }
  return uVar1;
}



//
// Function: dmaControllerSetup1 @ 0x0000a53e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void dmaControllerSetup1(void)

{
                    /* Constant: DMA_CONTROLLER_SETUP = 0x80000000 */
  dma_control_flags1 = 0x80000000;
                    /* Constant: DMA_DESC_ADDR_1 = 0x8062F4 */
  dma_descriptor_ptr1 = (dword)&dma_desc_source_addr1;
  dma_control_flags2 = 0x80000000;
                    /* Constant: DMA_DESC_ADDR_2 = 0x8062F6 */
  dma_descriptor_ptr2 = (dword)&dma_desc_dest_addr1;
  _previous_engine_rpm = 0;
  return;
}



//
// Function: dmaDescriptorSetup1 @ 0x0000a56e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void dmaDescriptorSetup1(void)

{
  dma_descriptor_base1 = 2;
                    /* Constant: DMA_SOURCE_ADDR_1 = 0x806304 */
  _DAT_00800010 = &dma_desc_source_addr2;
                    /* Constant: DMA_DEST_ADDR_1 = 0x806318 */
  _DAT_00800016 = &dma_desc_dest_addr2;
  _DAT_008091c4 = max_number_of_shutdowns_before_restart_is_not_allowed_0_255;
  return;
}



//
// Function: dmaDescriptorSetup2 @ 0x0000a598
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void dmaDescriptorSetup2(void)

{
  dma_descriptor_base2 = 2;
                    /* Constant: DMA_SOURCE_ADDR_2 = 0x80632C */
  _DAT_0080001c = &dma_desc_source_addr3;
                    /* Constant: DMA_DEST_ADDR_2 = 0x806340 */
  _DAT_00800022 = &dma_desc_dest_addr3;
  _DAT_008091c6 = 0x400;
  return;
}



//
// Function: FUN_0000a5c0 @ 0x0000a5c0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000a5c0(void)

{
  _request_to_strobe_set_0_then_set_1_fso_driver_0_1 = 1;
  _fuel_arbitrator_threshold_3 = _oil_pressure_precrank_status;
  return;
}



//
// Function: FUN_0000a5e2 @ 0x0000a5e2
//

undefined1 FUN_0000a5e2(undefined4 param_1)

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
// Function: FUN_0000a626 @ 0x0000a626
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000a626(undefined4 param_1)

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
    _DAT_00805e00 = _DAT_00805e00 | 4;
    _DAT_00805e40 = _DAT_00805e40 | 4;
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
    FUN_00013242();
  }
  return;
}



//
// Function: FUN_0000a6fa @ 0x0000a6fa
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000a6fa(void)

{
  bool bVar1;
  short sVar2;
  undefined2 uVar3;
  ushort uVar4;
  short sVar5;
  ushort uVar6;
  int iVar7;
  byte *pbVar8;
  char *pcVar9;
  short *psVar10;
  
  sVar5 = 0;
  pbVar8 = &request_to_strobe_set_0_then_set_1_cold_start_aid_1_driver_0_1;
  iVar7 = 0x8068ea;
  uVar4 = 1;
  pcVar9 = &DAT_00800036;
  psVar10 = (short *)&DAT_00809526;
  uVar6 = _engine_control_flags_register;
  do {
    if ((byte *)0x809407 < pbVar8) {
      return;
    }
    if (*(char *)(iVar7 + 0x17) == '\0') {
      pbVar8[0xf] = 0;
    }
    else if (pbVar8[0xf] < *(byte *)(iVar7 + 0x17)) {
      pbVar8[0xf] = pbVar8[0xf] + 1;
    }
    else {
      pbVar8[0xf] = 1;
      if ((uVar4 & uVar6) == 0) {
        *(undefined2 *)(pbVar8 + 0x10) =
             *(undefined2 *)((uint)*(ushort *)(iVar7 + 0x10) * 2 + 0xfff2b0);
        if (*(ushort *)(iVar7 + 0xc) < *(ushort *)(pbVar8 + 0x10)) {
          if ((((uint)*(ushort *)
                       (&DAT_00805df2 + (short)((int)(uint)*(byte *)(iVar7 + 0x15) >> 4) * 2) &
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
          *(short *)(pbVar8 + 0xc) = *(short *)(iVar7 + 8) + *(short *)(pbVar8 + 0xc);
          if (*(short *)(iVar7 + 10) <= *(short *)(pbVar8 + 0xc)) {
            *(undefined2 *)(pbVar8 + 0xc) = *(undefined2 *)(iVar7 + 10);
            pbVar8[0xe] = 1;
            *(ushort *)(&DAT_00805df2 + (short)((int)(uint)*(byte *)(iVar7 + 0x14) >> 4) * 2) =
                 1 << (*(byte *)(iVar7 + 0x14) & 0xf) |
                 *(ushort *)(&DAT_00805df2 + (short)((int)(uint)*(byte *)(iVar7 + 0x14) >> 4) * 2);
            *(ushort *)(&DAT_00805e32 + (short)((int)(uint)*(byte *)(iVar7 + 0x14) >> 4) * 2) =
                 1 << (*(byte *)(iVar7 + 0x14) & 0xf) |
                 *(ushort *)(&DAT_00805e32 + (short)((int)(uint)*(byte *)(iVar7 + 0x14) >> 4) * 2);
          }
        }
        else {
LAB_0000a864:
          if (*(ushort *)(pbVar8 + 0x10) < *(ushort *)(iVar7 + 0xe)) {
            if ((((uint)*(ushort *)
                         (&DAT_00805df2 + (short)((int)(uint)*(byte *)(iVar7 + 0x14) >> 4) * 2) &
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
              *(short *)(pbVar8 + 0xc) = *(short *)(iVar7 + 8) + *(short *)(pbVar8 + 0xc);
              if (*(short *)(iVar7 + 10) <= *(short *)(pbVar8 + 0xc)) {
                *(undefined2 *)(pbVar8 + 0xc) = *(undefined2 *)(iVar7 + 10);
                pbVar8[0xe] = 1;
                *(ushort *)(&DAT_00805df2 + (short)((int)(uint)*(byte *)(iVar7 + 0x15) >> 4) * 2) =
                     1 << (*(byte *)(iVar7 + 0x15) & 0xf) |
                     *(ushort *)
                      (&DAT_00805df2 + (short)((int)(uint)*(byte *)(iVar7 + 0x15) >> 4) * 2);
                *(ushort *)(&DAT_00805e32 + (short)((int)(uint)*(byte *)(iVar7 + 0x15) >> 4) * 2) =
                     1 << (*(byte *)(iVar7 + 0x15) & 0xf) |
                     *(ushort *)
                      (&DAT_00805e32 + (short)((int)(uint)*(byte *)(iVar7 + 0x15) >> 4) * 2);
              }
              goto LAB_0000a964;
            }
          }
          *(short *)(pbVar8 + 0xc) = *(short *)(pbVar8 + 0xc) - *(short *)(iVar7 + 6);
          if (*(short *)(pbVar8 + 0xc) < 0) {
            pbVar8[0xc] = 0;
            pbVar8[0xd] = 0;
          }
        }
LAB_0000a964:
        if (*(short *)(pbVar8 + 0xc) <= *(short *)(iVar7 + 4)) {
          pbVar8[0xe] = 0;
          if (((uint)*(ushort *)
                      (&DAT_00805df2 + (short)((int)(uint)*(byte *)(iVar7 + 0x14) >> 4) * 2) &
              1 << (*(byte *)(iVar7 + 0x14) & 0xf)) != 0) {
            if (((uint)*(ushort *)
                        (&DAT_00805e32 + (short)((int)(uint)*(byte *)(iVar7 + 0x14) >> 4) * 2) &
                1 << (*(byte *)(iVar7 + 0x14) & 0xf)) == 0) {
              *(ushort *)(&DAT_00805df2 + (short)((int)(uint)*(byte *)(iVar7 + 0x14) >> 4) * 2) =
                   ~(1 << (*(byte *)(iVar7 + 0x14) & 0xf)) &
                   *(ushort *)(&DAT_00805df2 + (short)((int)(uint)*(byte *)(iVar7 + 0x14) >> 4) * 2)
              ;
            }
          }
          if (((uint)*(ushort *)
                      (&DAT_00805df2 + (short)((int)(uint)*(byte *)(iVar7 + 0x15) >> 4) * 2) &
              1 << (*(byte *)(iVar7 + 0x15) & 0xf)) != 0) {
            if (((uint)*(ushort *)
                        (&DAT_00805e32 + (short)((int)(uint)*(byte *)(iVar7 + 0x15) >> 4) * 2) &
                1 << (*(byte *)(iVar7 + 0x15) & 0xf)) == 0) {
              *(ushort *)(&DAT_00805df2 + (short)((int)(uint)*(byte *)(iVar7 + 0x15) >> 4) * 2) =
                   ~(1 << (*(byte *)(iVar7 + 0x15) & 0xf)) &
                   *(ushort *)(&DAT_00805df2 + (short)((int)(uint)*(byte *)(iVar7 + 0x15) >> 4) * 2)
              ;
            }
          }
        }
        if (pbVar8[0xe] == 0) {
          psVar10[3] = *(short *)(pbVar8 + 0x10);
          sVar2 = lookupTableInterpolation(psVar10);
          *(short *)(pbVar8 + 10) = sVar2;
          if (*(char *)(iVar7 + 0x13) != '\0') {
            if (*(short *)(pbVar8 + 10) == 4) {
              if (*pcVar9 == '\x04') {
                *(ushort *)(&DAT_00805df2 + (short)((int)(uint)*(byte *)(iVar7 + 0x16) >> 4) * 2) =
                     1 << (*(byte *)(iVar7 + 0x16) & 0xf) |
                     *(ushort *)
                      (&DAT_00805df2 + (short)((int)(uint)*(byte *)(iVar7 + 0x16) >> 4) * 2);
                *(ushort *)(&DAT_00805e32 + (short)((int)(uint)*(byte *)(iVar7 + 0x16) >> 4) * 2) =
                     1 << (*(byte *)(iVar7 + 0x16) & 0xf) |
                     *(ushort *)
                      (&DAT_00805e32 + (short)((int)(uint)*(byte *)(iVar7 + 0x16) >> 4) * 2);
              }
              else {
                *pcVar9 = *pcVar9 + '\x01';
              }
            }
            else if (*pcVar9 == '\0') {
              if (((uint)*(ushort *)
                          (&DAT_00805df2 + (short)((int)(uint)*(byte *)(iVar7 + 0x16) >> 4) * 2) &
                  1 << (*(byte *)(iVar7 + 0x16) & 0xf)) != 0) {
                if (((uint)*(ushort *)
                            (&DAT_00805e32 + (short)((int)(uint)*(byte *)(iVar7 + 0x16) >> 4) * 2) &
                    1 << (*(byte *)(iVar7 + 0x16) & 0xf)) == 0) {
                  *(ushort *)(&DAT_00805df2 + (short)((int)(uint)*(byte *)(iVar7 + 0x16) >> 4) * 2)
                       = ~(1 << (*(byte *)(iVar7 + 0x16) & 0xf)) &
                         *(ushort *)
                          (&DAT_00805df2 + (short)((int)(uint)*(byte *)(iVar7 + 0x16) >> 4) * 2);
                }
              }
            }
            else {
              *pcVar9 = *pcVar9 + -1;
            }
          }
          uVar3 = coreTableInterpolation();
          *(undefined2 *)(pbVar8 + 8) = uVar3;
        }
        else {
          *(undefined2 *)(pbVar8 + 8) = *(undefined2 *)(iVar7 + 2);
        }
      }
      else {
        *(undefined2 *)(pbVar8 + 8) = *(undefined2 *)(&DAT_00803750 + sVar5 * 2);
      }
    }
    pbVar8 = pbVar8 + 0x16;
    iVar7 = iVar7 + 0x18;
    psVar10 = psVar10 + 6;
    pcVar9 = pcVar9 + 1;
    sVar5 = sVar5 + 1;
    if (sVar5 == 0x10) {
      uVar4 = 1;
      uVar6 = _DAT_008035e0;
    }
    else {
      uVar4 = uVar4 * 2;
    }
  } while( true );
}



//
// Function: FUN_0000ac1c @ 0x0000ac1c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000ac1c(void)

{
  bool bVar1;
  byte *pbVar2;
  int iVar3;
  
  _DAT_0080952e = &a_d_fault_clear_counts_for_coolant_temperature_0_32767;
  _DAT_00809528 = &a_d_digital_filter_constant_for_oil_pressure_0_1;
  _DAT_00809526 = 2;
  _DAT_0080953a = &a_d_fault_clear_counts_for_sampled_throttle_0_32767;
  _DAT_00809534 = &a_d_fault_increment_0_32767;
  _DAT_00809532 = 2;
  _DAT_00809546 = &channel_mux_setting_0_255;
  _DAT_00809540 = &a_d_digital_filter_constant_for_ambient_air_pressure_0_1;
  _DAT_0080953e = 2;
  _DAT_00809552 = &channel_mux_setting_0_255;
  _DAT_0080954c = &a_d_high_error_limit_for_battery_voltage_0_1023;
  _DAT_0080954a = 2;
  _DAT_0080955e = &a_d_high_error_limit_0_1023;
  _DAT_00809558 = &a_d_digital_filter_constant_0_1;
  _DAT_00809556 = 2;
  _DAT_0080956a = &a_d_fault_set_0_32767;
  _DAT_00809564 = &a_d_digital_filter_constant_0_1;
  _DAT_00809562 = 2;
  _DAT_00809576 = &a_d_digital_filter_constant_0_1;
  _DAT_00809570 = &error_number_storage_for_throttle_position_sv_high_error_0_255;
  _DAT_0080956e = 2;
  _DAT_00809582 = &water_in_fuel_a_d_fault_set_0_32767;
  _DAT_0080957c = &water_in_fuel_a_d_fault_clear_counts_0_32767;
  _DAT_0080957a = 2;
  _DAT_0080958e = &water_in_fuel_tri_state_error_none;
  _DAT_00809588 = &water_in_fuel_channel_address_none;
  _DAT_00809586 = 2;
  _DAT_0080959a = &a_d_fault_set_0_32767;
  _DAT_00809594 = &a_d_fault_clear_counts_0_32767;
  _DAT_00809592 = 2;
  _DAT_008095a6 = &a_d_fault_decrement_0_32767;
  _DAT_008095a0 = &egr_current_feedback_channel_address_none;
  _DAT_0080959e = 2;
  _DAT_008095b2 = &ADHBSVFD;
  _DAT_008095ac = &error_number_storage_for_programming_pulse_sv_high_error_0_255;
  _DAT_008095aa = 2;
  _DAT_008095be = &global_default_value;
  _DAT_008095b8 = &ADHBSVCA;
  _DAT_008095b6 = 2;
  _DAT_008095ca = &channel_mux_setting_0_255;
  _DAT_008095c4 = &a_d_high_error_limit_0_1023;
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
  pbVar2 = &request_to_strobe_set_0_then_set_1_cold_start_aid_1_driver_0_1;
  iVar3 = 0x8068ea;
  do {
    if ((byte *)0x809407 < pbVar2) {
      FUN_0000a6fa();
      for (pbVar2 = &request_to_strobe_set_0_then_set_1_cold_start_aid_1_driver_0_1;
          pbVar2 < (byte *)0x809408; pbVar2 = pbVar2 + 0x16) {
        *(uint *)(pbVar2 + 4) = (uint)*(ushort *)(pbVar2 + 10) << 0x10;
        *(undefined2 *)(pbVar2 + 8) = *(undefined2 *)(pbVar2 + 10);
        pbVar2[0xf] = 0;
      }
      return;
    }
    pbVar2[4] = 0;
    pbVar2[5] = 0;
    pbVar2[6] = 0;
    pbVar2[7] = 0;
    *(int *)pbVar2 = iVar3;
    pbVar2[0xf] = *(byte *)(iVar3 + 0x17);
    if ((((uint)*(ushort *)(&DAT_00805df2 + (short)((int)(uint)*(byte *)(iVar3 + 0x15) >> 4) * 2) &
         1 << (*(byte *)(iVar3 + 0x15) & 0xf)) == 0) ||
       (((uint)*(ushort *)(&DAT_008068c4 + (short)((int)(uint)*(byte *)(iVar3 + 0x15) >> 4) * 2) &
        1 << (*(byte *)(iVar3 + 0x15) & 0xf)) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
LAB_0000af4c:
      *(undefined2 *)(pbVar2 + 0xc) = *(undefined2 *)(iVar3 + 10);
      pbVar2[0xe] = 1;
    }
    else {
      if ((((uint)*(ushort *)(&DAT_00805df2 + (short)((int)(uint)*(byte *)(iVar3 + 0x14) >> 4) * 2)
           & 1 << (*(byte *)(iVar3 + 0x14) & 0xf)) == 0) ||
         (((uint)*(ushort *)(&DAT_008068c4 + (short)((int)(uint)*(byte *)(iVar3 + 0x14) >> 4) * 2) &
          1 << (*(byte *)(iVar3 + 0x14) & 0xf)) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) goto LAB_0000af4c;
    }
    pbVar2 = pbVar2 + 0x16;
    iVar3 = iVar3 + 0x18;
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
  
  if ((vp44_status_flags_2 & 8) == 0) {
    _diagnostic_rpm_input = current_engine_rpm;
    _diagnostic_secondary_input = _diagnostic_sensor_reading;
    uVar3 = tableInterpolationLookup((short *)&diagnostic_fuel_table_base);
    diagnostic_state_buffer_t_00809654.computed_value = (word)((ulonglong)uVar3 >> 0x20);
  }
  else {
    diagnostic_state_buffer_t_00809654.computed_value = _vp44_override_fuel_value;
  }
  uVar2 = _vp44_flag_register_1 & 0x4000;
  if (((((_vp44_flag_register_1 & 0x4000) == 0) ||
       (((_engine_fault_status_register_1 & 2) != 0 &&
        (uVar2 = _engine_fault_confirmation_register & 2, uVar2 != 0)))) ||
      (((_engine_fault_status_register_1 & 1) != 0 &&
       (uVar2 = _engine_fault_confirmation_register & 1, uVar2 != 0)))) ||
     (((_engine_fault_status_register_1 & 0x10) != 0 &&
      (uVar2 = _engine_fault_confirmation_register & 0x10, uVar2 != 0)))) {
    uVar1 = 0;
  }
  else {
    _diagnostic_correction_input = _DAT_0080926e;
    uVar1 = lookupTableInterpolation((short *)&diagnostic_correction_table_base);
    uVar2 = uVar1;
  }
  diagnostic_state_buffer_t_00809654.computed_value =
       uVar1 + diagnostic_state_buffer_t_00809654.computed_value;
  return uVar2;
}



//
// Function: FUN_0000b05c @ 0x0000b05c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000b05c(void)

{
  _DAT_00800052 = 0x806e34;
  _diagnostic_fuel_table_base = 2;
  _DAT_0080005a = 0x806e20;
  _DAT_00800058 = 2;
  _DAT_00800060 = 0x806e5a;
  _diagnostic_correction_input = _DAT_0080926e;
  _DAT_00800066 = 0x808862;
  _DAT_0080006c = 0x808876;
  _diagnostic_correction_table_base = 2;
  return;
}



//
// Function: FUN_0000b0b0 @ 0x0000b0b0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000b0b0(void)

{
  if (diagnostic_state_buffer_t_00809654.computed_value < _DAT_0080d494) {
    _DAT_0080d494 = diagnostic_state_buffer_t_00809654.computed_value;
    _DAT_0080d496 = 0x10;
  }
  return;
}



//
// Function: FUN_0000b0ce @ 0x0000b0ce
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000b0ce(void)

{
  if (_DAT_0080c9a6 != 0x10) {
    _DAT_0080d480 = 0;
    _DAT_00800070 = 0;
    return;
  }
  _DAT_0080d480 = calibratible_timing_increment_that_is_added_to_base_timing_any_0_120;
  _DAT_00809668 = 1;
  _DAT_00800070 = 4;
  return;
}



//
// Function: FUN_0000b0fe @ 0x0000b0fe
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000b0fe(void)

{
  if ((short)(_DAT_0080d480 + _DAT_0080c9ae) < 0) {
    _DAT_0080c9ae = 0;
  }
  else {
    _DAT_0080c9ae = _DAT_0080d480 + _DAT_0080c9ae;
  }
  _DAT_0080c9b2 = _DAT_00800070 | _DAT_0080c9b2 & 0xfffb;
  return;
}



//
// Function: FUN_0000b130 @ 0x0000b130
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000b130(void)

{
  undefined2 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (((vp44_status_flags_1 & 0x8000) == 0) ||
     (uVar2 = (uint)_DAT_00803784 + (uint)_DAT_00803786, uVar2 < _DAT_008092f2)) {
    uVar1 = (undefined2)(uVar2 >> 0x10);
    _DAT_0080967e = 0;
  }
  else {
    uVar1 = 0;
    if (((vp44_status_flags_1 & 0x8000) != 0) && (uVar1 = 0, _DAT_008092f2 < _DAT_00803786)) {
      _DAT_0080967e = 1;
    }
  }
  return CONCAT22(uVar1,_DAT_0080967e);
}



//
// Function: FUN_0000b18c @ 0x0000b18c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0000b18c(void)

{
  undefined4 uVar1;
  
  if (((engine_operating_mode == IDLE) || (engine_operating_mode == LOW_RPM_RUNNING)) ||
     (engine_operating_mode == TRANSITIONAL_MODE_6)) {
    _DAT_00809676 = 1;
    _DAT_00809678 = _DAT_00806fae;
    _DAT_0080967a = 1;
    _DAT_0080967c = _DAT_00806fa6;
    _DAT_0080966c = 0;
    _DAT_00809672 = 0;
    _DAT_0080965c = 0;
  }
  else {
    FUN_0000b3ae();
  }
  if (_DAT_00809cb2 == 0) {
    if ((_DAT_008035d6 & 1) == 0) {
      uVar1 = FUN_0000b130();
      if ((short)uVar1 == 0) {
        if (((vp44_status_flags_1 & 0x4000) == 0) || (_DAT_0080c990 != 1)) {
          _DAT_0080965e = 0;
          _DAT_0080965a = _DAT_0080965c;
        }
        else {
          _DAT_0080965e = 3;
          _DAT_0080965a = _DAT_00806fac;
        }
      }
      else {
        _DAT_0080965e = 2;
        _DAT_0080965a = _DAT_00806fa8;
      }
    }
    else {
      _DAT_0080965e = 1;
      _DAT_0080965a = _DAT_00803782;
    }
  }
  else {
    _DAT_0080965e = 4;
    _DAT_0080965a = _DAT_00809cbc;
  }
  if (0x4000 < _DAT_0080965a) {
    _DAT_0080965a = 0x4000;
  }
  if ((vp44_status_flags_2 & 0x10) == 0) {
    _fuel_timing_mode_selector = _DAT_0080965a;
  }
  return vp44_status_flags_2 & 0x10;
}



//
// Function: FUN_0000b27e @ 0x0000b27e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_0000b27e(void)

{
  if ((_DAT_0080966a == 1) && (_DAT_00806fb2 < _DAT_0080966c)) {
    _DAT_0080966c = _DAT_00806fb2;
    _DAT_00809672 = (uint)_DAT_00806fb2 << 0x10;
  }
  _DAT_0080966c = coreTableInterpolation();
  if (_DAT_0080966c <= _DAT_00806fb2) {
    return 0;
  }
  if (_null_ < _DAT_0080966c) {
    return 1;
  }
  return _DAT_00809662;
}



//
// Function: FUN_0000b2ee @ 0x0000b2ee
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0000b2ee(void)

{
  uint in_D0;
  
  if (((_DAT_0080c9a6 != 10) && (_protection_system_enable_flag != 1)) &&
     (pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._2_2_ != 1)) {
    return in_D0 & 0xffff0000;
  }
  return 1;
}



//
// Function: FUN_0000b314 @ 0x0000b314
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0000b314(void)

{
  ushort uVar1;
  undefined4 in_D0;
  
  uVar1 = (ushort)((uint)in_D0 >> 0x10);
  if (_DAT_0080c9a6 == 0xb) {
    _DAT_00809678 = _DAT_00806fae;
    _DAT_00809676 = 1;
    return (uint)uVar1 << 0x10;
  }
  if ((_DAT_00809676 == 1) && (_DAT_00809678 != 0)) {
    _DAT_00809678 = _DAT_00809678 + -1;
    return (uint)uVar1 << 0x10;
  }
  _DAT_00809676 = 0;
  return 1;
}



//
// Function: FUN_0000b35c @ 0x0000b35c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0000b35c(void)

{
  ushort uVar1;
  undefined4 in_D0;
  
  uVar1 = (ushort)((uint)in_D0 >> 0x10);
  if ((_DAT_00809668 == 1) || (_DAT_0080966a == 1)) {
    _DAT_0080967c = _DAT_00806fa6;
    _DAT_0080967a = 1;
    return (uint)uVar1 << 0x10;
  }
  if ((_DAT_0080967a == 1) && (_DAT_0080967c != 0)) {
    _DAT_0080967c = _DAT_0080967c + -1;
    return (uint)uVar1 << 0x10;
  }
  _DAT_0080967a = 0;
  return 1;
}



//
// Function: FUN_0000b3ae @ 0x0000b3ae
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0000b3ae(void)

{
  int iVar1;
  ushort uVar3;
  uint uVar2;
  
  uVar3 = 0;
  if ((vp44_status_flags_1 & 0x400) != 0) {
    iVar1 = FUN_0000b314();
    uVar3 = (ushort)iVar1;
    _DAT_00809666 = uVar3;
  }
  if ((vp44_status_flags_1 & 0x800) != 0) {
    iVar1 = FUN_0000b35c();
    _DAT_00809660 = (ushort)iVar1;
    uVar3 = _DAT_00809660 | uVar3;
  }
  if ((vp44_status_flags_1 & 0x1000) != 0) {
    _DAT_00809662 = FUN_0000b27e();
    uVar3 = _DAT_00809662 | uVar3;
  }
  uVar2 = vp44_status_flags_1 & 0xffff2000;
  if ((vp44_status_flags_1 & 0x2000) != 0) {
    uVar2 = FUN_0000b2ee();
    _DAT_00809664 = (ushort)uVar2;
    uVar3 = _DAT_00809664 | uVar3;
  }
  if (uVar3 == 0) {
    _DAT_0080965c = 0;
  }
  else if (_DAT_0080965c != 0x4000) {
    if (_DAT_0080965c < _DAT_00806fa4) {
      _DAT_0080965c = _DAT_00806fa0 + _DAT_0080965c;
      uVar2 = (uint)_DAT_00806fa2 + (uint)_DAT_00806fa4;
      if (uVar2 < _DAT_0080965c) {
        _DAT_0080965c = _DAT_00806fa2 + _DAT_00806fa4;
        uVar2 = CONCAT22((short)(uVar2 >> 0x10),_DAT_0080965c);
      }
    }
    else {
      uVar2 = CONCAT22((short)(uVar2 >> 0x10),_DAT_00806fa2);
      _DAT_0080965c = _DAT_00806fa2 + _DAT_0080965c;
    }
  }
  if (0x4000 < _DAT_0080965c) {
    _DAT_0080965c = 0x4000;
  }
  _DAT_00809668 = 0;
  _DAT_0080966a = 0;
  return uVar2;
}



//
// Function: FUN_0000b47e @ 0x0000b47e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_0000b47e(void)

{
  undefined2 uVar1;
  undefined4 in_D0;
  undefined4 uVar2;
  undefined4 in_D1;
  ulonglong uVar3;
  
  uVar1 = (undefined2)((uint)in_D0 >> 0x10);
  if (((_DAT_008035d6 & 0x20) == 0) || (engine_operating_mode != HIGH_RPM_RUNNING)) {
    _DAT_00809682 = max_number_of_shutdowns_before_restart_is_not_allowed_0_255;
    return CONCAT44(CONCAT22(uVar1,_DAT_008035d6),in_D1) & 0xffff0020ffffffff;
  }
  if ((((_DAT_00805df4 & 4) == 0) || ((_DAT_008068c6 & 4) == 0)) &&
     (((_DAT_00805df4 & 8) == 0 || ((_DAT_008068c6 & 8) == 0)))) {
    _DAT_0080007a = current_engine_rpm;
    _DAT_00800082 = _DAT_008092f2;
    uVar3 = tableInterpolationLookup((short *)&DAT_00800074);
    _DAT_00809682 = (short)(uVar3 >> 0x20);
    return uVar3;
  }
  uVar2 = CONCAT22(uVar1,current_engine_rpm);
  if (_DAT_00806fb6 < current_engine_rpm) {
    _DAT_00809682 = _DAT_00806fb8;
    return CONCAT44(uVar2,in_D1);
  }
  _DAT_00809682 = max_number_of_shutdowns_before_restart_is_not_allowed_0_255;
  return CONCAT44(uVar2,in_D1);
}



//
// Function: FUN_0000b528 @ 0x0000b528
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000b528(void)

{
  _DAT_00800074 = 2;
  _DAT_00800076 = 0x806fba;
  _DAT_0080007c = 2;
  _DAT_0080007e = 0x806fe0;
  _DAT_00800084 = 0x806fea;
  return;
}



//
// Function: FUN_0000b556 @ 0x0000b556
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000b556(void)

{
  if (_DAT_00809682 < _DAT_0080d494) {
    _DAT_0080d494 = _DAT_00809682;
    _DAT_0080d496 = 0xf;
  }
  return;
}



//
// Function: FUN_0000b574 @ 0x0000b574
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000b574(void)

{
  _DAT_00800096 = 2;
  _DAT_00800098 = 0x807886;
  _DAT_0080009e = 0x807892;
  return;
}



//
// Function: FUN_0000b594 @ 0x0000b594
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000b594(void)

{
  if (_DAT_00800092 == 7) {
    _DAT_008000a6 = _DAT_008000a8;
  }
  else {
    _DAT_008000a6 = _target_engine_rpm;
  }
  _DAT_008000a8 = _DAT_00809d1a - _DAT_008000a6;
  if ((int)(short)_DAT_008000a8 < (int)-(uint)_DAT_00807884) {
    _DAT_008000a8 = (ushort)-(uint)_DAT_00807884;
  }
  if ((int)(uint)_DAT_00807884 < (int)(short)_DAT_008000a8) {
    _DAT_008000a8 = _DAT_00807884;
  }
  _DAT_008000a8 = _DAT_008000a6 + _DAT_008000a8;
  if ((int)((int)(short)_DAT_008000a8 - (uint)_target_engine_rpm) < 0) {
    _DAT_0080009c = -(_DAT_008000a8 - _target_engine_rpm);
  }
  else {
    _DAT_0080009c = _DAT_008000a8 - _target_engine_rpm;
  }
  _DAT_008000a2 = lookupTableInterpolation((short *)&DAT_00800096);
  _target_engine_rpm =
       (short)((int)((uint)_target_engine_rpm * (uint)_DAT_008000a2 +
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
  if ((((diagnostic_status_register == 7) || (diagnostic_status_register == 3)) ||
      (diagnostic_status_register == 2)) || (diagnostic_status_register == 0x1e)) {
    sVar4 = _DAT_00809d04;
    if (diagnostic_status_register != _DAT_00800092) {
      iVar2 = (uint)_DAT_00809d1e * ((int)_DAT_00809d32[3] + (int)_DAT_00809d32[2]);
      if (iVar2 == 0) {
        _target_engine_rpm = current_engine_rpm;
      }
      else {
        iVar2 = (int)(((uint)_current_fuel_demand_value - (uint)_DAT_00809768) *
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
        iVar2 = (uint)current_engine_rpm + iVar2;
        if (iVar2 < 0x10000) {
          if (iVar2 < 0) {
            _target_engine_rpm = 0;
          }
          else {
            _target_engine_rpm = (ushort)iVar2;
          }
        }
        else {
          _target_engine_rpm = 0xffff;
        }
      }
      _DAT_00809d12 = (uint)_target_engine_rpm << 0x10;
      iVar2 = (uint)_target_engine_rpm - (uint)current_engine_rpm;
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
    if (diagnostic_status_register == 7) {
      FUN_0000b594();
    }
    else {
      _target_engine_rpm = coreTableInterpolation();
      _DAT_008000a2 = (ushort)((int)(uint)*_DAT_00809d0e >> 2);
    }
    iVar2 = (uint)_target_engine_rpm - (uint)current_engine_rpm;
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
    else if ((_DAT_00800094 == _current_fuel_demand_value) &&
            (diagnostic_status_register == _DAT_00800092)) {
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
      else if (_DAT_00809768 < _current_fuel_demand_value) {
        _DAT_0080008e =
             rpmFuelCalculation((uint)_current_fuel_demand_value - (uint)_DAT_00809768,
                                0x100 - _DAT_008078b4,(int)_DAT_008078b0 - (int)_DAT_008078b2);
        if (0x1700 < _DAT_0080008e) {
          _DAT_0080008e = 0x1700;
        }
        sVar3 = (short)_DAT_0080008e;
        _DAT_0080008e = _DAT_0080008e << 0x10;
      }
      else {
        iVar2 = rpmFuelCalculation((uint)_DAT_00809768 - (uint)_current_fuel_demand_value,
                                   0x100 - _DAT_008078b4,(int)_DAT_008078b0 - (int)_DAT_008078b2);
        if (0x1700 < iVar2) {
          iVar2 = 0x1700;
        }
        _DAT_0080008e = (uint)(ushort)-(short)iVar2 << 0x10;
        sVar3 = -(short)iVar2;
      }
      _DAT_00800088 = current_engine_rpm;
      sVar5 = 0;
      _DAT_00809d0c = _current_fuel_demand_value - _DAT_00809768;
      _DAT_008000a4 = _DAT_00809768;
    }
    iVar2 = (uint)current_engine_rpm - (int)(short)_DAT_00800088;
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
    _DAT_00800088 = current_engine_rpm;
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
    cached_parameter_value = _DAT_00809d02;
  }
  _DAT_00800092 = diagnostic_status_register;
  return;
}



//
// Function: FUN_0000bdd4 @ 0x0000bdd4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000bdd4(void)

{
  if ((_DAT_00809cca != 0) && (_derate_status_flag == 0)) {
    _derate_status_flag = 0x1e;
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
// Function: FUN_0000be7c @ 0x0000be7c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000be7c(void)

{
  if ((diagnostic_status_register == 0) && (_derate_status_flag == 0x1e)) {
    diagnostic_status_register = 0x1e;
  }
  return;
}



//
// Function: FUN_0000be96 @ 0x0000be96
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000be96(undefined4 param_1)

{
  if ((diagnostic_status_register == 0) && (_derate_status_flag == 2)) {
    diagnostic_status_register = 2;
    _DAT_00809d32 = (uint)_DAT_0080d012 * 0x12 + 0x8078fc;
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
// Function: FUN_0000bf0a @ 0x0000bf0a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000bf0a(void)

{
  if ((_derate_status_flag == 0) && (_fuel_arbitrator_condition_flag == 1)) {
    _derate_status_flag = 2;
    _DAT_00809d1a = _DAT_0080d00a;
  }
  return;
}



//
// Function: derate_application_controller @ 0x0000bf2e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void derate_application_controller(void)

{
  _derate_base_value = _DAT_00807882;
  _derate_min_limit = *_derate_min_limit_ptr;
  _derate_max_limit = *_derate_max_limit_ptr;
  _calculated_derate_output =
       _derate_min_limit +
       (short)(((uint)_active_derate_value * ((uint)_derate_max_limit - (uint)_derate_min_limit)) /
              400);
  _derate_status_flag = 0;
  FUN_0000bdd4();
  FUN_0000bf0a();
  FUN_0000c0e6();
  return;
}



//
// Function: FUN_0000bf9c @ 0x0000bf9c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000bf9c(void)

{
  _derate_min_limit_ptr = 0x8036b6;
  _derate_max_limit_ptr = 0x8036b8;
  _derate_base_value = _DAT_00807882;
  return;
}



//
// Function: FUN_0000bfbc @ 0x0000bfbc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000bfbc(void)

{
  uint uVar1;
  
  if (_derate_base_value == 1) {
    _DAT_008000be = _DAT_00809d1a;
    _DAT_00809d24 = lookupTableInterpolation((short *)&DAT_008000b8);
  }
  else if (_derate_base_value == 0) {
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
// Function: FUN_0000c084 @ 0x0000c084
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000c084(undefined4 param_1)

{
  if ((diagnostic_status_register == 0) && (_DAT_008036ea == 1)) {
    diagnostic_status_register = 7;
    FUN_0000bfbc();
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
// Function: FUN_0000c0e6 @ 0x0000c0e6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000c0e6(void)

{
  if (_derate_status_flag == 0) {
    _DAT_00809d1a = _calculated_derate_output;
    _derate_status_flag = 7;
  }
  return;
}



//
// Function: FUN_0000c100 @ 0x0000c100
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000c100(void)

{
  _DAT_008000ac = 2;
  _DAT_008000ae = 0x8078b6;
  _DAT_008000b4 = 0x8078c6;
  _DAT_008000b8 = 2;
  _DAT_008000ba = 0x8078d6;
  _DAT_008000c0 = 0x8078e6;
  _derate_base_value = 0;
  return;
}



//
// Function: FUN_0000c144 @ 0x0000c144
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000c144(void)

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
// Function: FUN_0000c1f0 @ 0x0000c1f0
//

void FUN_0000c1f0(void)

{
  return;
}



//
// Function: FUN_0000c1f2 @ 0x0000c1f2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000c1f2(undefined4 param_1)

{
  char cVar1;
  
  cVar1 = (char)((uint)param_1 >> 0x10);
  if (cVar1 == '\x01') {
    FUN_00033524();
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
// Function: FUN_0000c260 @ 0x0000c260
//

void FUN_0000c260(void)

{
  return;
}



//
// Function: FUN_0000c262 @ 0x0000c262
//

void FUN_0000c262(void)

{
  return;
}



//
// Function: FUN_0000c264 @ 0x0000c264
//

void FUN_0000c264(void)

{
  FUN_0002d90c();
  FUN_00010c98();
  return;
}



//
// Function: FUN_0000c272 @ 0x0000c272
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000c272(void)

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
  FUN_0000b574();
  FUN_0002f920();
  FUN_0002f986();
  FUN_0002fdfe();
  FUN_00030914();
  FUN_0002fe20();
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
  FUN_00010ad8();
  return;
}



//
// Function: FUN_0000c33e @ 0x0000c33e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000c33e(void)

{
  _protection_system_enable_flag = 0;
  _target_boost_pressure_base = 0;
  _DAT_008096a6 = 0;
  _DAT_008096a8 = 0;
  _DAT_008096aa = 0;
  _fuel_arbitrator_threshold_4 = _oil_pressure_precrank_status;
  return;
}



//
// Function: FUN_0000c368 @ 0x0000c368
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000c368(void)

{
  DAT_008000c8 = DAT_008000c8 + 1;
  if (4 < DAT_008000c8) {
    DAT_008000c8 = 0;
  }
  if (DAT_008000c8 == 1) {
    if (((DAT_0080bdca & 0x80) != 0) == ((can_pin_switching_control_flags & 0x20) != 0)) {
      if (((_DAT_00805dfc & 0x80) != 0) && ((_DAT_00805e3c & 0x80) == 0)) {
        _DAT_00805dfc = _DAT_00805dfc & 0xff7f;
        DAT_008000c9 = 0;
      }
    }
    else if (DAT_008000c9 < _DAT_00807946) {
      DAT_008000c9 = DAT_008000c9 + 1;
    }
    else {
      _DAT_00805dfc = _DAT_00805dfc | 0x80;
      _DAT_00805e3c = _DAT_00805e3c | 0x80;
    }
    if (((DAT_0080bdcb & 0x80) != 0) == ((io_control_flags & 0x80) != 0)) {
      if (((_DAT_00805dfc & 0x40) != 0) && ((_DAT_00805e3c & 0x40) == 0)) {
        _DAT_00805dfc = _DAT_00805dfc & 0xffbf;
        DAT_008000ca = 0;
      }
    }
    else if (DAT_008000ca < _DAT_00807946) {
      DAT_008000ca = DAT_008000ca + 1;
    }
    else {
      _DAT_00805dfc = _DAT_00805dfc | 0x40;
      _DAT_00805e3c = _DAT_00805e3c | 0x40;
    }
    if (((DAT_0080bdcb & 1) != 0) == ((io_control_flags & 1) != 0)) {
      if (((_DAT_00805dfc & 0x20) != 0) && ((_DAT_00805e3c & 0x20) == 0)) {
        _DAT_00805dfc = _DAT_00805dfc & 0xffdf;
        DAT_008000cb = 0;
      }
    }
    else if (DAT_008000cb < _DAT_00807946) {
      DAT_008000cb = DAT_008000cb + 1;
    }
    else {
      _DAT_00805dfc = _DAT_00805dfc | 0x20;
      _DAT_00805e3c = _DAT_00805e3c | 0x20;
    }
    if (((DAT_0080bdcb & 2) != 0) == ((io_control_flags & 2) != 0)) {
      if (((_engine_fault_register_a & 0x4000) != 0) && ((_engine_fault_register_c & 0x4000) == 0))
      {
        _engine_fault_register_a = _engine_fault_register_a & 0xbfff;
        DAT_008000cc = 0;
      }
    }
    else if (DAT_008000cc < _DAT_00807946) {
      DAT_008000cc = DAT_008000cc + 1;
    }
    else {
      _engine_fault_register_a = _engine_fault_register_a | 0x4000;
      _engine_fault_register_c = _engine_fault_register_c | 0x4000;
    }
    if (((DAT_0080bdcb & 4) != 0) == ((io_control_flags & 4) != 0)) {
      if ((_engine_fault_register_a & 0x8000) != 0) {
        if ((_engine_fault_register_c & 0x8000) == 0) {
          _engine_fault_register_a = _engine_fault_register_a & 0x7fff;
          DAT_008000cd = 0;
        }
      }
    }
    else if (DAT_008000cd < _DAT_00807946) {
      DAT_008000cd = DAT_008000cd + 1;
    }
    else {
      _engine_fault_register_a = _engine_fault_register_a | 0x8000;
      _engine_fault_register_c = _engine_fault_register_c | 0x8000;
    }
    if (((DAT_0080bdcb & 0x20) != 0) == ((io_control_flags & 0x20) != 0)) {
      if (((_DAT_00805e00 & 0x2000) != 0) && ((_DAT_00805e40 & 0x2000) == 0)) {
        _DAT_00805e00 = _DAT_00805e00 & 0xdfff;
        DAT_008000ce = 0;
      }
    }
    else if (DAT_008000ce < _DAT_00807946) {
      DAT_008000ce = DAT_008000ce + 1;
    }
    else {
      _DAT_00805e00 = _DAT_00805e00 | 0x2000;
      _DAT_00805e40 = _DAT_00805e40 | 0x2000;
    }
    if (((DAT_0080bdcb & 0x10) != 0) == ((io_control_flags & 0x10) != 0)) {
      if (((_DAT_00805dfc & 0x100) != 0) && ((_DAT_00805e3c & 0x100) == 0)) {
        _DAT_00805dfc = _DAT_00805dfc & 0xfeff;
        DAT_008000cf = 0;
      }
    }
    else if (DAT_008000cf < _DAT_00807946) {
      DAT_008000cf = DAT_008000cf + 1;
    }
    else {
      _DAT_00805dfc = _DAT_00805dfc | 0x100;
      _DAT_00805e3c = _DAT_00805e3c | 0x100;
    }
    if (((DAT_0080bdcb & 0x40) != 0) == ((io_control_flags & 0x40) != 0)) {
      if (((_DAT_00805dfe & 0x4000) != 0) && ((_DAT_00805e3e & 0x4000) == 0)) {
        _DAT_00805dfe = _DAT_00805dfe & 0xbfff;
        DAT_008000d0 = 0;
      }
    }
    else if (DAT_008000d0 < _DAT_00807946) {
      DAT_008000d0 = DAT_008000d0 + 1;
    }
    else {
      _DAT_00805dfe = _DAT_00805dfe | 0x4000;
      _DAT_00805e3e = _DAT_00805e3e | 0x4000;
    }
    if (((DAT_0080bdcb & 8) != 0) != ((io_control_flags & 8) != 0)) {
      if (DAT_008000d1 < _DAT_00807946) {
        DAT_008000d1 = DAT_008000d1 + 1;
        return;
      }
      _DAT_00805dfe = _DAT_00805dfe | 0x800;
      _DAT_00805e3e = _DAT_00805e3e | 0x800;
      return;
    }
    if (((_DAT_00805dfe & 0x800) != 0) && ((_DAT_00805e3e & 0x800) == 0)) {
      _DAT_00805dfe = _DAT_00805dfe & 0xf7ff;
      DAT_008000d1 = 0;
    }
  }
  return;
}



//
// Function: FUN_0000c8c2 @ 0x0000c8c2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0000c8c2(void)

{
  undefined2 uVar1;
  uint in_D0;
  uint uVar2;
  
  if (engine_operating_mode == HIGH_RPM_RUNNING) {
    if (((_DAT_00805df4 & 0x400) == 0) || ((_DAT_008068c6 & 0x400) == 0)) {
      in_D0 = 0;
    }
    else {
      in_D0 = 1;
    }
    if (in_D0 == 0) {
      if (((_DAT_00805df4 & 0x200) == 0) || ((_DAT_008068c6 & 0x200) == 0)) {
        in_D0 = 0;
      }
      else {
        in_D0 = 1;
      }
      if ((in_D0 == 0) &&
         (in_D0 = (uint)BSTATBZA + (uint)_DAT_0080d092, _current_engine_rpm_raw <= in_D0)) {
        uVar1 = (undefined2)(in_D0 >> 0x10);
        in_D0 = CONCAT22(uVar1,asthrfes_calc_input);
        if (asthrfes_calc_input <= _DAT_0080794c) {
          if (_DAT_008000d2 < _DAT_00807948) {
            _DAT_008000d2 = _DAT_008000d2 + 1;
          }
          if (_DAT_008000d2 == _DAT_00807948) {
            if (_DAT_00807950 < _diagnostic_sensor_reading) {
              if (_DAT_008000d4 < _DAT_0080794a) {
                _DAT_008000d4 = _DAT_008000d4 + 1;
              }
            }
            else if (_DAT_008000d4 != 0) {
              _DAT_008000d4 = _DAT_008000d4 - 1;
            }
          }
          if (_DAT_008000d4 == _DAT_0080794a) {
            _DAT_00805df4 = _DAT_00805df4 | 0x2000;
            _DAT_00805e34 = _DAT_00805e34 | 0x2000;
          }
          if (_DAT_008000d4 != 0) {
            return CONCAT22(uVar1,_DAT_008000d4);
          }
          if ((_DAT_00805df4 & 0x2000) == 0) {
            return CONCAT22(uVar1,_DAT_00805df4) & 0xffff2000;
          }
          uVar2 = CONCAT22(uVar1,_DAT_00805e34) & 0xffff2000;
          if ((_DAT_00805e34 & 0x2000) != 0) {
            return uVar2;
          }
          _DAT_00805df4 = _DAT_00805df4 & 0xdfff;
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
// Function: FUN_0000c9f0 @ 0x0000c9f0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000c9f0(void)

{
  short sVar1;
  byte bVar2;
  byte bVar3;
  
  _DAT_0080d440 = &DAT_00808962;
  _DAT_0080d41c = &DAT_0080d422;
  _DAT_0080d410 = _DAT_0080d2b4;
  _DAT_0080d40c = _DAT_0080d2b4;
  DAT_0080d409 = 0;
  DAT_0080d418 = 0;
  DAT_0080d407 = DAT_00808962;
  for (bVar2 = 0; (DAT_0080d407 != 0 && (bVar2 < 0x1e)); bVar2 = bVar2 + 1) {
    if (DAT_0080d420 == *_DAT_0080d41c) {
      *_DAT_0080d41c = _DAT_0080d440[1] + *_DAT_0080d41c;
      bVar3 = '\x01' << (DAT_0080d407 & 7);
      sVar1 = (short)((int)(uint)DAT_0080d407 >> 3);
      if (((bVar3 & *(byte *)((int)&
                                   maximum_time_between_tailshaft_pulses_allowed_before_vehicle_0_04_40
                             + (int)sVar1)) != 0) && ((bVar3 & *(byte *)(sVar1 + 0x8055fe)) == 0)) {
        FUN_0000cb1e();
      }
    }
    _DAT_0080d440 = _DAT_0080d440 + 3;
    DAT_0080d407 = *_DAT_0080d440;
    _DAT_0080d41c = _DAT_0080d41c + 1;
  }
  FUN_00019cbc();
  return;
}



//
// Function: FUN_0000caa8 @ 0x0000caa8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0000caa8(void)

{
  byte bVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined2 extraout_D0u;
  undefined4 in_D0;
  uint uVar4;
  
  uVar3 = (undefined2)((uint)in_D0 >> 0x10);
  if (((_DAT_008035ea & 4) != 0) && ((_DAT_00809d3e & 2) != 0)) {
    FUN_0001a192();
    bVar1 = DAT_008000d6 + 1;
    bVar2 = DAT_008000d6 & 1;
    uVar3 = 0;
    DAT_008000d6 = bVar1;
    if (bVar2 == 0) {
      FUN_0001aca8();
      uVar3 = extraout_D0u;
    }
  }
  uVar4 = CONCAT22(uVar3,_DAT_008035ea) & 0xffff0002;
  if ((_DAT_008035ea & 2) != 0) {
    DAT_008000d7 = DAT_008000d7 + 1;
    uVar4 = DAT_008000d7 & 1;
    if (((DAT_008000d7 & 1) == 0) && (uVar4 = _DAT_00809d3e & 1, (_DAT_00809d3e & 1) != 0)) {
      uVar4 = FUN_0000c9f0();
      DAT_0080d420 = DAT_0080d420 + '\x01';
    }
  }
  return uVar4;
}



//
// Function: FUN_0000cb1e @ 0x0000cb1e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000cb1e(void)

{
  undefined2 uVar1;
  
  if (DAT_0080d418 == 0) {
    _DAT_0080d40c = (undefined1 *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    *_DAT_0080d40c = 0x80;
    _DAT_0080d40c = (undefined1 *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    DAT_0080d418 = 1;
    FUN_00019c3c();
    if (DAT_0080d419 == 0) {
      _DAT_00805e00 = _DAT_00805e00 | 4;
      _DAT_00805e40 = _DAT_00805e40 | 4;
      return;
    }
  }
  uVar1 = FUN_000271b0();
  DAT_0080d41a = (byte)uVar1;
  if (DAT_0080d41a == 0) {
    return;
  }
  if (DAT_0080d41a <= DAT_0080d419) {
    FUN_0000cc64();
    return;
  }
  if (1 < DAT_0080d418) {
    FUN_00019cbc();
    _DAT_0080d410 = _DAT_0080d40c;
    FUN_00019c3c();
    if (DAT_0080d419 < 4) {
      DAT_0080d419 = 0;
      DAT_0080d418 = 0;
      _DAT_00805e00 = _DAT_00805e00 | 4;
      _DAT_00805e40 = _DAT_00805e40 | 4;
      return;
    }
    _DAT_0080d40c = (undefined1 *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    *_DAT_0080d40c = 0x80;
    _DAT_0080d40c = (undefined1 *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    DAT_0080d418 = 1;
  }
  if ((DAT_0080d41a < 0x14) && (DAT_0080d419 < DAT_0080d41a)) {
    _DAT_00805e00 = _DAT_00805e00 | 4;
    _DAT_00805e40 = _DAT_00805e40 | 4;
    return;
  }
  FUN_0000cc64();
  return;
}



//
// Function: FUN_0000cc34 @ 0x0000cc34
//

uint FUN_0000cc34(undefined4 param_1)

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
// Function: FUN_0000cc64 @ 0x0000cc64
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000cc64(void)

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
  if (DAT_0080d407 < 0x80) {
    if (DAT_0080d407 < 0x59) {
      if (DAT_0080d407 < 0x54) {
        if (DAT_0080d407 == 2) {
          bVar5 = 0;
          uVar2 = FUN_0000cc34((uint)CONCAT12(DAT_008063ff,uVar7));
          if ((char)uVar2 == '\0') {
            uVar2 = FUN_0000cc34(CONCAT22((short)CONCAT31((int3)(uVar2 >> 8),DAT_008063fd),uVar7));
            if ((char)uVar2 == '\0') {
              uVar2 = FUN_0000cc34(CONCAT22((short)CONCAT31((int3)(uVar2 >> 8),DAT_008063fb),uVar7))
              ;
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
          uVar2 = FUN_0000cc34(CONCAT22(uVar3,uVar7));
          if ((char)uVar2 != '\0') {
            bVar5 = bVar5 | 0x10;
          }
          uVar4 = (undefined2)CONCAT31((int3)(uVar2 >> 8),DAT_008063b9);
          uVar2 = FUN_0000cc34(CONCAT22(uVar4,uVar3));
          if ((char)uVar2 != '\0') {
            bVar5 = bVar5 | 8;
          }
          uVar3 = (undefined2)CONCAT31((int3)(uVar2 >> 8),DAT_008063d3);
          uVar2 = FUN_0000cc34(CONCAT22(uVar3,uVar4));
          if ((char)uVar2 != '\0') {
            bVar5 = bVar5 | 4;
          }
          uVar2 = FUN_0000cc34(CONCAT22((short)CONCAT31((int3)(uVar2 >> 8),DAT_008063db),uVar3));
          if ((char)uVar2 == '\0') {
            uVar2 = FUN_0000cc34(CONCAT22((short)CONCAT31((int3)(uVar2 >> 8),DAT_008063e1),uVar7));
            if ((char)uVar2 != '\0') {
              bVar5 = bVar5 | 2;
            }
          }
          else {
            bVar5 = bVar5 | 2;
          }
          uVar2 = FUN_0000cc34(CONCAT22((short)CONCAT31((int3)(uVar2 >> 8),DAT_008063a7),uVar7));
          if ((char)uVar2 != '\0') {
            bVar5 = bVar5 | 1;
          }
        }
        else if (DAT_0080d407 == 3) {
          bVar5 = (DAT_0080bdc7 & 0x80) != 0;
          if ((DAT_0080bdc7 & 0x40) != 0) {
            bVar5 = bVar5 | 2;
          }
          if ((DAT_0080bdc7 & 0x20) != 0) {
            bVar5 = bVar5 | 4;
          }
        }
        else if (DAT_0080d407 == 0x47) {
          bVar5 = 0;
          if ((_DAT_0080cc6e != 0) && (_DAT_0080cc6e < _DAT_008036fc)) {
            bVar5 = 0x80;
          }
          if ((_diagnostic_system_flags_1 & 2) != 0) {
            bVar5 = bVar5 | 8;
          }
          if ((_DAT_0080cc6a != 0) && ((_diagnostic_system_flags_1 & 4) != 0)) {
            bVar5 = bVar5 | 4;
          }
          if ((_DAT_0080c996 != 0) && (_DAT_0080cc6e == 0)) {
            bVar5 = bVar5 | 2;
          }
          if (_DAT_0080cc72 != 0) {
            bVar5 = bVar5 | 1;
          }
        }
        else if (DAT_0080d407 == 0x4a) {
          bVar5 = (byte)((int)(uint)_DAT_00803748 >> 7);
        }
        else {
          if (DAT_0080d407 != 0x53) {
            return;
          }
          if (diagnostic_state_buffer_t_00809654.diagnostic_mode == 10) {
            bVar5 = 0x80;
          }
          else {
            bVar5 = 0;
          }
        }
        *_DAT_0080d40c = DAT_0080d407;
        _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
        *_DAT_0080d40c = bVar5;
        _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      }
      else {
        switch(DAT_0080d407) {
        case 0x54:
          bVar5 = (byte)((int)(uint)_DAT_008096a6 >> 7);
          break;
        case 0x55:
          bVar5 = 0;
          if (_protection_system_enable_flag != 0) {
            bVar5 = 0x80;
          }
          if ((DAT_0080bdc7 & 4) != 0) {
            bVar5 = bVar5 | 0x40;
          }
          if ((DAT_0080bdc7 & 8) != 0) {
            bVar5 = bVar5 | 0x20;
          }
          if ((sensor_status_register & 2) != 0) {
            bVar5 = bVar5 | 0x10;
          }
          if ((sensor_status_register & 1) != 0) {
            bVar5 = bVar5 | 8;
          }
          if ((sensor_status_register & 8) != 0) {
            bVar5 = bVar5 | 4;
          }
          if ((sensor_status_register & 4) != 0) {
            bVar5 = bVar5 | 2;
          }
          if ((sensor_status_register & 0x10) != 0) {
            bVar5 = bVar5 | 1;
          }
          break;
        case 0x56:
          bVar5 = (byte)((int)(uint)_target_boost_pressure_base >> 7);
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
        *_DAT_0080d40c = DAT_0080d407;
        _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
        *_DAT_0080d40c = bVar5;
        _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      }
    }
    else if (DAT_0080d407 < 0x69) {
      if (DAT_0080d407 == 0x59) {
        local_6._1_1_ = 0;
        if (pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._2_2_ != 0) {
          local_6._1_1_ = 0x80;
        }
        if ((DAT_0080bdc7 & 4) != 0) {
          local_6._1_1_ = (byte)local_6 | 0x40;
        }
        if ((DAT_0080bdc7 & 8) != 0) {
          local_6._1_1_ = (byte)local_6 | 0x20;
        }
        if ((sensor_status_register & 2) != 0) {
          local_6._1_1_ = (byte)local_6 | 0x10;
        }
        if ((sensor_status_register & 1) != 0) {
          local_6._1_1_ = (byte)local_6 | 8;
        }
        if ((sensor_status_register & 8) != 0) {
          local_6._1_1_ = (byte)local_6 | 4;
        }
        if ((sensor_status_register & 4) != 0) {
          local_6._1_1_ = (byte)local_6 | 2;
        }
        if ((sensor_status_register & 0x10) != 0) {
          local_6._1_1_ = (byte)local_6 | 1;
        }
      }
      else if (DAT_0080d407 == 0x5b) {
        local_6._1_1_ = (byte)(((uint)_active_derate_value * 0xfa) / 400);
      }
      else if (DAT_0080d407 == 0x5c) {
        local_6._1_1_ = (byte)((int)(uint)asthrfes_calc_input >> 7);
      }
      else if (DAT_0080d407 == 100) {
        local_6._1_1_ = (byte)((int)(uint)_DAT_00809242 >> 6);
      }
      else {
        if (DAT_0080d407 != 0x66) {
          return;
        }
        if ((ushort)((int)(uint)_diagnostic_sensor_reading >> 4) < 0xff) {
          local_6._1_1_ = (byte)((int)(uint)_diagnostic_sensor_reading >> 4);
        }
        else {
          local_6._1_1_ = 0xff;
        }
      }
      *_DAT_0080d40c = DAT_0080d407;
      _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      *_DAT_0080d40c = (byte)local_6;
      _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    }
    else {
      if (DAT_0080d407 == 0x69) {
        if (_DAT_008091ea < 0x1900) {
          cVar6 = '\0';
        }
        else {
          cVar6 = (char)((int)(_DAT_008091ea - 0x1900) >> 7);
        }
      }
      else if (DAT_0080d407 == 0x6c) {
        cVar6 = (char)((int)(uint)_DAT_008092f2 >> 3);
      }
      else if (DAT_0080d407 == 0x6e) {
        if (_DAT_0080926e < 0x1900) {
          cVar6 = '\0';
        }
        else {
          cVar6 = (char)((int)(_DAT_0080926e - 0x1900) >> 7);
        }
      }
      else {
        if (DAT_0080d407 != 0x79) {
          return;
        }
        if (_DAT_008037d4 == 0) {
          cVar6 = '\0';
        }
        else {
          cVar6 = (io_control_flags & 1) != 0;
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
      *_DAT_0080d40c = DAT_0080d407;
      _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      *_DAT_0080d40c = cVar6;
      _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    }
  }
  else if (DAT_0080d407 < 0xc1) {
    if (DAT_0080d407 < 0xb9) {
      if ((DAT_0080d407 != 0x9c) && (DAT_0080d407 != 0x9d)) {
        if (DAT_0080d407 == 0xa6) {
          local_6 = CONCAT11(DAT_00004446,DAT_00004445);
        }
        else if (DAT_0080d407 == 0xa8) {
          local_6 = (short)((int)(uint)_DAT_00809308 >> 1) + _DAT_00809308 * 2;
        }
        else if (DAT_0080d407 != 0xaf) {
          if (DAT_0080d407 == 0xb6) {
            local_6 = (short)_DAT_00804bbc;
          }
          else if (DAT_0080d407 == 0xb7) {
            local_6 = _DAT_0080d476;
          }
          else {
            if (DAT_0080d407 != 0xb8) {
              return;
            }
            local_6 = _DAT_00804bc8;
          }
        }
      }
      *_DAT_0080d40c = DAT_0080d407;
      _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      *_DAT_0080d40c = (byte)local_6;
      _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      *_DAT_0080d40c = local_6._0_1_;
      _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    }
    else {
      switch(DAT_0080d407) {
      case 0xb9:
        local_6 = _DAT_00804bca;
        break;
      default:
        goto switchD_0000ce84_default;
      case 0xbb:
        local_6 = (short)((int)(uint)pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._0_2_ >> 1);
        break;
      case 0xbc:
        local_6 = (short)((int)(uint)_DAT_0080d092 >> 1);
        break;
      case 0xbd:
        local_6 = (short)((int)(uint)user_inversion_bit_mask_for_the_user_datalogger_switc_invert_no_invert
                                     ._0_2_ >> 1);
        break;
      case 0xbe:
        local_6 = (short)((int)(uint)_current_engine_rpm_raw >> 1);
      }
      *_DAT_0080d40c = DAT_0080d407;
      _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      *_DAT_0080d40c = (byte)local_6;
      _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      *_DAT_0080d40c = local_6._0_1_;
      _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    }
  }
  else if (DAT_0080d407 < 0xf4) {
    if (DAT_0080d407 == 0xc1) {
      FUN_0001fa00();
      return;
    }
    if (DAT_0080d407 == 0xc2) {
      FUN_0001fafe();
      return;
    }
    if (DAT_0080d407 == 0xc4) {
      *_DAT_0080d40c = 0xc4;
      _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      if (((DAT_0080d448 & 0xc0) == 0x80) || ((DAT_0080d448 & 0xc0) == 0x40)) {
        *_DAT_0080d40c = 2;
        _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      }
      else if ((DAT_0080d448 & 0xc0) == 0) {
        if (_DAT_0080d490 == 0) {
          *_DAT_0080d40c = 0;
          _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
          goto LAB_0000d55a;
        }
        *_DAT_0080d40c = 5;
        _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      }
      *_DAT_0080d40c = DAT_0080d447;
      _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      *_DAT_0080d40c = DAT_0080d448;
      _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      if (((DAT_0080d448 & 0xc0) == 0) && (_DAT_0080d490 != 0)) {
        bVar5 = 1;
        do {
          *_DAT_0080d40c = (char)(_DAT_0080d490 / 100) + 0x30;
          _DAT_0080d490 = (_DAT_0080d490 % 100) * 10;
          _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
          bVar5 = bVar5 + 1;
        } while (bVar5 < 4);
      }
    }
    else {
      if (DAT_0080d407 == 0xea) {
        FUN_0001fec4();
        return;
      }
      if (DAT_0080d407 == 0xeb) {
        uVar2 = _DAT_00804bcc / 0x708;
        *_DAT_0080d40c = 0xeb;
        _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
        *_DAT_0080d40c = 4;
        _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
        local_a._3_1_ = (undefined1)uVar2;
        *_DAT_0080d40c = (undefined1)local_a;
        _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
        local_a._2_1_ = (undefined1)(uVar2 >> 8);
        *_DAT_0080d40c = local_a._2_1_;
        _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
        local_a._1_1_ = (undefined1)(uVar2 >> 0x10);
        *_DAT_0080d40c = local_a._1_1_;
        _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
        *_DAT_0080d40c = 0;
        _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      }
      else {
        if (DAT_0080d407 != 0xec) {
          if (DAT_0080d407 == 0xed) {
            FUN_0002003c();
            return;
          }
          if (DAT_0080d407 != 0xf3) {
            return;
          }
          FUN_0002011c();
          return;
        }
        *_DAT_0080d40c = 0xec;
        _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
        *_DAT_0080d40c = 4;
        _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
        local_a._3_1_ = (undefined1)uVar1;
        *_DAT_0080d40c = (undefined1)local_a;
        _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
        local_a._2_1_ = (undefined1)((uint)uVar1 >> 8);
        *_DAT_0080d40c = local_a._2_1_;
        _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
        local_a._1_1_ = (undefined1)((uint)uVar1 >> 0x10);
        *_DAT_0080d40c = local_a._1_1_;
        _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
        local_a._0_1_ = (undefined1)((uint)uVar1 >> 0x18);
        *_DAT_0080d40c = local_a._0_1_;
        _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      }
    }
  }
  else {
    switch(DAT_0080d407) {
    case 0xf4:
      local_a = FUN_000357d2(_DAT_00804bc4,10,0x40);
      break;
    case 0xf5:
      local_a = FUN_000357d2(_DAT_00804bc0,10,0x40);
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
    *_DAT_0080d40c = DAT_0080d407;
    _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    *_DAT_0080d40c = 4;
    _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    *_DAT_0080d40c = (undefined1)local_a;
    _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    *_DAT_0080d40c = local_a._2_1_;
    _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    *_DAT_0080d40c = local_a._1_1_;
    _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    *_DAT_0080d40c = local_a._0_1_;
    _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
  }
LAB_0000d55a:
  DAT_0080d418 = DAT_0080d41a + DAT_0080d418;
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
    if (diagnostic_status_register == 8) {
      _DAT_0080cff6 = cached_parameter_value;
    }
    else {
      _DAT_0080cff6 = activeParamReadFunction();
    }
  }
  else {
    _DAT_0080cff6 = _diagnostic_rpm_threshold_status;
  }
  if ((short)(param_scale_factor - param_ref_base) < 1) {
    param_table_aux = 0;
    return;
  }
  if ((short)(_DAT_0080cff6 - param_ref_base) < 1) {
    param_table_aux = 0;
    return;
  }
  uVar1 = param_address_calc((short)(_DAT_0080cff6 - param_ref_base) * 0x6400,
                             CONCAT22(param_scale_factor - param_ref_base,uVar2));
  param_table_aux = (word)uVar1;
  if (32000 < param_table_aux) {
    param_table_aux = 32000;
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
  
  if ((short)(param_scale_factor - param_ref_base) < 1) {
    param_table_main = 0;
    return;
  }
  if ((short)(_current_fuel_demand_value - param_ref_base) < 1) {
    param_table_main = 0;
    return;
  }
  uVar1 = param_address_calc((short)(_current_fuel_demand_value - param_ref_base) * 0x6400,
                             CONCAT22(param_scale_factor - param_ref_base,
                                      (short)((uint)unaff_D2 >> 0x10)));
  param_table_main = (word)uVar1;
  if (32000 < param_table_main) {
    param_table_main = 32000;
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
  uVar3 = (uint)_current_fuel_demand_value;
  uVar2 = (uint)param_ref_base;
  if ((int)(uVar3 - uVar2) < 1) {
    param_table_ctrl = 0;
    return;
  }
  _DAT_008000de = current_engine_rpm;
  uVar4 = tableInterpolationLookup((short *)&DAT_008000d8);
  sVar1 = (short)((ulonglong)uVar4 >> 0x20) - param_ref_base;
  if (sVar1 < 1) {
    param_table_ctrl = 0;
    return;
  }
  uVar2 = param_address_calc((uVar3 - uVar2) * 0x6400,CONCAT22(sVar1,uVar5));
  param_table_ctrl = (word)uVar2;
  if (32000 < param_table_ctrl) {
    param_table_ctrl = 32000;
  }
  return;
}



//
// Function: diagnosticDataBufferSetup @ 0x0000d71a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticDataBufferSetup(void)

{
  _DAT_008000de = current_engine_rpm;
  _DAT_008000d8 = 2;
  _DAT_008000da = 0x807f42;
  _DAT_008000e6 = 400;
  _DAT_008000e0 = 2;
  _DAT_008000e2 = 0x807f68;
  _DAT_008000e8 = &lower_limitation_of_intake_manifold_temperature_to_inhibit_50_to_293;
  return;
}



//
// Function: param_lookup_3 @ 0x0000d756
//

void param_lookup_3(void)

{
  uint uVar1;
  undefined4 unaff_D2;
  
  if ((int)((uint)fsmxthfl_calc_input - (uint)param_ref_base) < 1) {
    param_table_ext = 0;
    return;
  }
  if ((short)(param_scale_factor - param_ref_base) < 1) {
    param_table_ext = 0;
    return;
  }
  uVar1 = param_address_calc(((uint)fsmxthfl_calc_input - (uint)param_ref_base) * 0x6400,
                             CONCAT22(param_scale_factor - param_ref_base,
                                      (short)((uint)unaff_D2 >> 0x10)));
  param_table_ext = (word)uVar1;
  if (32000 < param_table_ext) {
    param_table_ext = 32000;
  }
  return;
}



//
// Function: FUN_0000d7c0 @ 0x0000d7c0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short FUN_0000d7c0(undefined4 param_1)

{
  ushort unaff_D2w;
  ushort unaff_D3w;
  undefined8 uVar1;
  
  if (_fuel_timing_mode_selector != 0) {
    _DAT_008000f2 = param_1._0_2_;
    uVar1 = tableInterpolationLookup((short *)&DAT_008000ec);
    unaff_D2w = (ushort)((ulonglong)uVar1 >> 0x20);
  }
  if (_fuel_timing_mode_selector < 0x4000) {
    _DAT_00800106 = param_1._0_2_;
    uVar1 = tableInterpolationLookup((short *)&DAT_00800100);
    unaff_D3w = (ushort)((ulonglong)uVar1 >> 0x20);
  }
  if (_fuel_timing_mode_selector == 0x4000) {
    return _DAT_008037ae + unaff_D2w;
  }
  if (_fuel_timing_mode_selector == 0) {
    return _DAT_008037ae + unaff_D3w;
  }
  return _DAT_008037ae +
         (short)((uint)_fuel_timing_mode_selector * (uint)unaff_D2w >> 0xe) +
         (short)((uint)unaff_D3w * (0x4000 - (uint)_fuel_timing_mode_selector) >> 0xe);
}



//
// Function: FUN_0000d85e @ 0x0000d85e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000d85e(void)

{
  undefined4 unaff_A2;
  undefined2 uVar1;
  undefined2 uVar2;
  
  uVar2 = _DAT_0080d092;
  _DAT_0080cfec = FUN_0000d7c0(CONCAT22(_DAT_0080d092,(short)((uint)unaff_A2 >> 0x10)));
  uVar1 = _DAT_0080cfe8;
  _DAT_0080cfee = FUN_0000d7c0(CONCAT22(_DAT_0080cfe8,uVar2));
  uVar2 = _DAT_008086c6;
  _DAT_0080cff0 = FUN_0000d7c0(CONCAT22(_DAT_008086c6,uVar1));
  uVar1 = _DAT_008086c8;
  _DAT_0080cff2 = FUN_0000d7c0(CONCAT22(_DAT_008086c8,uVar2));
  _DAT_0080cff4 = FUN_0000d7c0(CONCAT22(_DAT_0080cfea,uVar1));
  return;
}



//
// Function: param_interpolate @ 0x0000d8b4
//

ushort param_interpolate(undefined4 param_1)

{
  ushort uVar1;
  
  if ((short)(param_1._0_2_ - param_ref_base) < 1) {
    uVar1 = 0;
  }
  else if ((short)(param_scale_factor - param_ref_base) < 1) {
    uVar1 = 0;
  }
  else {
    uVar1 = (ushort)((uint)((short)(param_1._0_2_ - param_ref_base) * 0x6400) /
                    (uint)(int)(short)(param_scale_factor - param_ref_base));
    if (32000 < uVar1) {
      uVar1 = 32000;
    }
  }
  return uVar1;
}



//
// Function: FUN_0000d90a @ 0x0000d90a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000d90a(uint param_1,undefined4 param_2)

{
  if ((_DAT_0080cc56 != 0) && (_DAT_0080cc58 != 0)) {
    _DAT_0080cfe8 =
         _arbitrated_fuel_limit +
         ((short)(((uint)_DAT_0080cc58 * ((uint)_DAT_0080cc56 - (param_1 & 0xffff))) / 0x1111) -
         _DAT_0080cc54);
    if (param_2._1_1_ == '\x01') {
      _DAT_0080cfea = _DAT_0080cfe8;
      return;
    }
    _DAT_0080cfea = _DAT_008086ca;
    return;
  }
  _DAT_0080cfe8 = _arbitrated_fuel_limit;
  _DAT_0080cfea = param_1._0_2_;
  return;
}



//
// Function: FUN_0000d984 @ 0x0000d984
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000d984(void)

{
  undefined4 unaff_D2;
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  
  uVar4 = (ushort)((uint)unaff_D2 >> 0x10);
  if ((((_arbitrator_active_limit_priority == 2) || (_arbitrator_active_limit_priority == 4)) ||
      (_arbitrator_active_limit_priority == 5)) || (_arbitrator_active_limit_priority == 1)) {
    cVar1 = '\x02';
  }
  else {
    cVar1 = '\0';
  }
  if (((_DAT_0080d496 == 0x12) || (_DAT_0080d496 == 0xf)) ||
     ((_DAT_0080d496 == 0x10 &&
      ((((_DAT_00805df4 & 0x200) != 0 && ((_DAT_008068c6 & 0x200) != 0)) ||
       (((_DAT_00805df4 & 0x400) != 0 && ((_DAT_008068c6 & 0x400) != 0)))))))) {
    cVar1 = cVar1 + '\x04';
    _DAT_0080cfec = _DAT_008086cc;
    _DAT_0080cff0 = _DAT_008086ce;
    _DAT_0080cff2 = _DAT_008086d0;
  }
  if (_fuel_timing_mode_selector == 0x4000) {
    cVar1 = cVar1 + '\x01';
  }
  switch(cVar1) {
  case '\0':
  case '\x01':
    _DAT_0080cfe8 = _DAT_0080cc54;
    _DAT_0080cfea = _DAT_008086ca;
    FUN_0000d85e();
    break;
  case '\x02':
  case '\x03':
    _DAT_0080cfe8 = _arbitrated_fuel_limit;
    if (_DAT_008086ca < _arbitrated_fuel_limit) {
      _DAT_0080cfea = _DAT_008086ca;
    }
    else {
      _DAT_0080cfea = _arbitrated_fuel_limit;
    }
    FUN_0000d85e();
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
    if (_arbitrated_fuel_limit < _DAT_008086d8) {
      FUN_0000d90a(CONCAT22(_arbitrated_fuel_limit,_DAT_008086d0),CONCAT22(1,uVar4));
      _DAT_0080cfee = _DAT_008086d0;
      _DAT_0080cff4 = _DAT_008086d0;
    }
    else {
      FUN_0000d90a(CONCAT22(_DAT_008086ca,_DAT_008086d2),(uint)uVar4);
      _DAT_0080cfee = _DAT_008086d2;
      _DAT_0080cff4 = _DAT_008086d2;
    }
    break;
  case '\a':
    if (_arbitrated_fuel_limit < _DAT_008086de) {
      FUN_0000d90a(CONCAT22(_arbitrated_fuel_limit,_DAT_008086d0),CONCAT22(1,uVar4));
      _DAT_0080cfee = _DAT_008086d0;
      _DAT_0080cff4 = _DAT_008086d0;
    }
    else {
      FUN_0000d90a(CONCAT22(_DAT_008086ca,_DAT_008086d2),(uint)uVar4);
      _DAT_0080cfee = _DAT_008086d2;
      _DAT_0080cff4 = _DAT_008086d2;
    }
  }
  uVar3 = _DAT_0080cfec;
  param_table_calc = param_interpolate(CONCAT22(_DAT_0080cfec,uVar4));
  uVar2 = _DAT_0080cfee;
  calculated_2 = param_interpolate(CONCAT22(_DAT_0080cfee,uVar3));
  uVar3 = _DAT_0080cff0;
  calculated_3 = param_interpolate(CONCAT22(_DAT_0080cff0,uVar2));
  uVar2 = _DAT_0080cff2;
  calculated_4 = param_interpolate(CONCAT22(_DAT_0080cff2,uVar3));
  result_buffer = param_interpolate(CONCAT22(_DAT_0080cff4,uVar2));
  return;
}



//
// Function: FUN_0000dbc2 @ 0x0000dbc2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000dbc2(void)

{
  _DAT_008000ec = 2;
  _DAT_008000ee = 0x807f42;
  _DAT_008000fa = 400;
  _DAT_008000f4 = 2;
  _DAT_008000f6 = 0x807f68;
  _DAT_008000fc = &lower_limitation_of_intake_manifold_temperature_to_inhibit_50_to_293;
  _DAT_00800100 = 2;
  _DAT_00800102 = 0x808002;
  _DAT_0080010e = 400;
  _DAT_00800108 = 2;
  _DAT_0080010a = 0x808028;
  _DAT_00800110 = 0x808032;
  return;
}



//
// Function: FUN_0000dc28 @ 0x0000dc28
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000dc28(void)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  
  if ((io_control_flags & 1) == 0) {
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
  _DAT_0080011a = current_engine_rpm;
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
// Function: FUN_0000dd72 @ 0x0000dd72
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000dd72(void)

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
// Function: FUN_0000ddb4 @ 0x0000ddb4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0000ddb4(void)

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
// Function: FUN_0000de50 @ 0x0000de50
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0000de50(void)

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
// Function: FUN_0000def4 @ 0x0000def4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_0000def4(undefined4 param_1)

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
      if (_DAT_0080c41a == &DAT_0080c430) {
        _DAT_00800138 = _DAT_0080c77e;
      }
      else {
        _DAT_00800138 = _DAT_0080c41a + -4;
      }
      _DAT_0080013c = &DAT_0080c430;
      _DAT_00800140 = _DAT_0080c77e;
      uVar2 = _DAT_00800130;
    }
    else {
      _DAT_00800134 = _DAT_0080c760;
      if (_DAT_0080c41e == &DAT_0080c5c0) {
        _DAT_00800138 = _DAT_0080c782;
      }
      else {
        _DAT_00800138 = _DAT_0080c41e + -4;
      }
      _DAT_0080013c = &DAT_0080c5c0;
      _DAT_00800140 = _DAT_0080c782;
      uVar2 = _DAT_0080012c;
    }
    if (time_to_delay_before_setting_a_new_throttle_min_0_25500 < _current_engine_fuel_demand) {
      if (_DAT_00800134 < uVar2) {
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
    }
    else if (_DAT_00800134 < uVar2) {
      uVar2 = FUN_0000de50();
      uVar3 = (undefined2)uVar2;
    }
    else if ((_DAT_0080926e < _DAT_008079b6) && (_current_engine_fuel_demand <= _DAT_008079be)) {
      uVar2 = FUN_0000ddb4();
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
// Function: FUN_0000e02c @ 0x0000e02c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000e02c(void)

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
// Function: FUN_0000e1aa @ 0x0000e1aa
//

void FUN_0000e1aa(void)

{
  uint *unaff_A2;
  
  sendJ1939MultiFrame(unaff_A2);
  return;
}



//
// Function: FUN_0000e1b8 @ 0x0000e1b8
//

short FUN_0000e1b8(short *param_1,short *param_2)

{
  short sVar1;
  
  sVar1 = 0;
  for (; param_1 <= param_2; param_1 = param_1 + 1) {
    sVar1 = *param_1 + sVar1;
  }
  return sVar1;
}



//
// Function: FUN_0000e1ce @ 0x0000e1ce
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000e1ce(void)

{
  if (_memory_patch_count != 0) {
    _memory_patch_count = _memory_patch_count + -1;
    _DAT_0080d3e2 =
         _DAT_0080d3e2 - (uint)*(ushort *)((short)(_memory_patch_count * 3) * 2 + 0x80d3aa);
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
  
  uVar1 = _engine_control_flags_register & 0x400;
  if ((_engine_control_flags_register & 0x400) == 0) {
    if (_derate_mode_selector == 0) {
      _current_derate_target = _normal_derate_reference;
      uVar3 = 0x41;
      uVar2 = 0x42;
    }
    else {
      _current_derate_target = _override_derate_reference;
      uVar3 = 0;
      uVar2 = 0;
    }
    uVar1 = (uint)_current_derate_target;
    if (_derate_threshold_base < _current_derate_target) {
      uVar1 = (((uint)_current_derate_target - (uint)_derate_threshold_base) * 400) /
              (uint)_derate_scaling_factor;
      _calculated_derate_amount = (ushort)uVar1;
    }
    else {
      _calculated_derate_amount = 0;
    }
    if (_rpm_derate_timer == 0) {
      if ((derate_status_flag == '\0') && (_derate_override_flag == 0)) {
        if (((((((uint)*(ushort *)(&DAT_00805df2 + (short)((int)uVar3 >> 4) * 2) &
                1 << (uVar3 & 0xf)) == 0) ||
              (uVar1 = (uint)*(ushort *)(&DAT_008068c4 + ((int)uVar3 >> 4) * 2),
              (uVar1 & 1 << (uVar3 & 0xf)) == 0)) &&
             ((((uint)*(ushort *)(&DAT_00805df2 + (short)((int)uVar2 >> 4) * 2) & 1 << (uVar2 & 0xf)
               ) == 0 ||
              (uVar1 = (uint)*(ushort *)(&DAT_008068c4 + ((int)uVar2 >> 4) * 2),
              (uVar1 & 1 << (uVar2 & 0xf)) == 0)))) &&
            (((_engine_fault_register_a & 0x20) == 0 ||
             (uVar1 = _engine_fault_register_b & 0xffff0020, (_engine_fault_register_b & 0x20) == 0)
             ))) && ((((_engine_fault_register_a & 8) == 0 ||
                      (uVar1 = _engine_fault_register_b & 0xffff0008,
                      (_engine_fault_register_b & 8) == 0)) &&
                     (uVar1 = (uint)_current_derate_target,
                     _derate_threshold_base < _current_derate_target)))) {
          _active_derate_value = _calculated_derate_amount;
        }
        else {
          _active_derate_value = 0;
        }
        _derate_timer_status = 0;
      }
      else {
        if (((_engine_fault_register_a & 0x20) != 0) && ((_engine_fault_register_c & 0x20) == 0)) {
          _engine_fault_register_a = _engine_fault_register_a & 0xffdf;
        }
        if (((_engine_fault_register_a & 8) != 0) && ((_engine_fault_register_c & 8) == 0)) {
          _engine_fault_register_a = _engine_fault_register_a & 0xfff7;
        }
        if (((_engine_fault_register_a & 0x10) != 0) && ((_engine_fault_register_c & 0x10) == 0)) {
          _engine_fault_register_a = _engine_fault_register_a & 0xffef;
        }
        uVar1 = CONCAT22((short)(uVar1 >> 0x10),_current_derate_target);
        if (the_transmission_pwm_scaling_from_load_to_duty_cycle_2_2 < _current_derate_target) {
          uVar1 = (((uint)_current_derate_target -
                   (uint)the_transmission_pwm_scaling_from_load_to_duty_cycle_2_2) * 400) /
                  (uint)_derate_scaling_factor;
          _calculated_derate_amount = (ushort)uVar1;
        }
        else {
          _calculated_derate_amount = 0;
        }
        _derate_threshold_exceeded =
             (ushort)(the_transmission_pwm_scaling_from_load_to_duty_cycle_2_2 <
                     _current_derate_target);
        _active_derate_value = _calculated_derate_amount;
        _derate_timer_status = 0;
      }
    }
    else {
      _active_derate_value = _rpm_derate_status;
      _derate_timer_status = _rpm_derate_timer;
      _rpm_derate_timer = 0;
    }
  }
  else {
    _active_derate_value = _normal_derate_reference;
  }
  if (400 < _calculated_derate_amount) {
    _calculated_derate_amount = 400;
  }
  if (400 < _active_derate_value) {
    _active_derate_value = 400;
  }
  return uVar1;
}



//
// Function: FUN_0000e478 @ 0x0000e478
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_0000e478(void)

{
  ushort uVar1;
  undefined2 uVar2;
  short sVar4;
  short sVar5;
  uint uVar3;
  byte bVar6;
  uint in_D1;
  uint uVar7;
  word wVar8;
  uint uVar9;
  
  uVar7 = _engine_control_flags_register & 0x400;
  if ((((_engine_control_flags_register & 0x400) != 0) || (derate_status_flag != '\0')) ||
     (_derate_override_flag != 0)) {
LAB_0000eac6:
    return CONCAT44(uVar7,in_D1);
  }
  if (_derate_mode_selector == 0) {
    _current_derate_target = _normal_derate_reference;
    uVar7 = 0x41;
    uVar9 = 0x42;
  }
  else {
    _current_derate_target = _override_derate_reference;
    uVar7 = 0;
    uVar9 = 0;
  }
  sVar4 = (short)((int)uVar7 >> 4);
  sVar5 = (short)((int)uVar9 >> 4);
  if (((((uint)*(ushort *)(&DAT_00805df2 + sVar4 * 2) & 1 << (uVar7 & 0xf)) == 0) ||
      (((uint)*(ushort *)(&DAT_008068c4 + sVar4 * 2) & 1 << (uVar7 & 0xf)) == 0)) &&
     ((((uint)*(ushort *)(&DAT_00805df2 + sVar5 * 2) & 1 << (uVar9 & 0xf)) == 0 ||
      (((uint)*(ushort *)(&DAT_008068c4 + sVar5 * 2) & 1 << (uVar9 & 0xf)) == 0)))) {
    if ((_DAT_008079e0 == 0) && (_current_derate_target < _DAT_00809d56)) {
      _DAT_00809d56 = _current_derate_target;
    }
    if (_DAT_008079e0 == 1) {
      if ((_current_derate_target < _DAT_00809d56) && (_DAT_00809d54 == 0)) {
        _DAT_00809d54 = _DAT_008079da;
        _DAT_0080014a = _current_derate_target;
      }
      if (_DAT_00809d54 != 0) {
        if ((uint)_DAT_008079dc + (uint)_DAT_0080014a < (uint)_current_derate_target) {
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
  _DAT_0080014e =
       _DAT_008079d2 +
       (_derate_threshold_base - the_transmission_pwm_bias_from_load_to_duty_cycle_100_100);
  _DAT_0080014c =
       _DAT_008079d4 +
       (_derate_threshold_base - the_transmission_pwm_bias_from_load_to_duty_cycle_100_100);
  if ((((vp44_communication_status & 0x80) == 0) || ((DAT_0080bdc7 & 1) != 0)) &&
     (((vp44_communication_status & 0x80) != 0 || ((DAT_0080bdc7 & 1) == 0)))) {
    if ((vp44_communication_status & 0x80) == 0) {
      if (_DAT_0080014e < _current_derate_target) {
        _DAT_00809d4e = 5;
      }
      else if (_current_derate_target < _DAT_0080014c) {
        _DAT_00809d4e = 6;
      }
      else {
        _DAT_00809d4e = 7;
      }
    }
    else if ((_DAT_0080014e < _current_derate_target) || (_current_derate_target < _DAT_0080014c)) {
      _DAT_00809d4e = 4;
    }
    else {
      _DAT_00809d4e = 7;
    }
  }
  else if ((vp44_communication_status & 0x80) == 0) {
    if (_current_derate_target < _derate_threshold_base) {
      if (_current_derate_target < _DAT_0080014c) {
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
  else if (_derate_threshold_base < _current_derate_target) {
    if (_DAT_0080014e < _current_derate_target) {
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
    _derate_threshold_exceeded = 1;
  }
  else {
    _derate_threshold_exceeded = 0;
  }
  if (((uint)*(ushort *)(&DAT_00805df2 + sVar4 * 2) & 1 << (uVar7 & 0xf)) != 0) {
    uVar3 = (uint)*(ushort *)(&DAT_008068c4 + sVar4 * 2);
    uVar7 = uVar3 & 1 << (uVar7 & 0xf);
    if (uVar7 != 0) goto LAB_0000e7d2;
  }
  if (((uint)*(ushort *)(&DAT_00805df2 + sVar5 * 2) & 1 << (uVar9 & 0xf)) != 0) {
    uVar3 = (uint)*(ushort *)(&DAT_008068c4 + sVar5 * 2);
    uVar7 = uVar3 & 1 << (uVar9 & 0xf);
    if (uVar7 != 0) {
LAB_0000e7d2:
      _DAT_00809d52 = 0;
      return CONCAT44(uVar3,uVar7);
    }
  }
  if (_DAT_00809d52 == 0) {
    if ((((vp44_communication_status & 0x80) != 0) && ((DAT_0080bdc7 & 1) == 0)) &&
       ((uint)_current_derate_target <=
        (uint)the_transmission_pwm_bias_from_load_to_duty_cycle_100_100 + (uint)_DAT_00809d56)) {
      _DAT_00809d52 = 1;
    }
  }
  else if (_DAT_00809d52 == 1) {
    if ((_DAT_00809d4e == 1) &&
       ((uint)the_transmission_pwm_signal_dutycycle_minimum_value_high_time_0_100 +
        (uint)_DAT_00809d56 < (uint)_current_derate_target)) {
      _DAT_00809d52 = 2;
    }
  }
  else if (((_DAT_00809d52 == 2) && ((vp44_communication_status & 0x80) != 0)) &&
          (((DAT_0080bdc7 & 1) == 0 &&
           ((uint)_current_derate_target <=
            (uint)the_transmission_pwm_bias_from_load_to_duty_cycle_100_100 + (uint)_DAT_00809d56)))
          ) {
    _DAT_00809d52 = 3;
  }
  if (_DAT_00809d52 == 3) {
    if (_DAT_00809d54 == 0) {
      _derate_threshold_base =
           the_transmission_pwm_bias_from_load_to_duty_cycle_100_100 + _DAT_00809d56;
    }
    if (((_engine_fault_register_a & 0x20) != 0) && ((_engine_fault_register_c & 0x20) == 0)) {
      _engine_fault_register_a = _engine_fault_register_a & 0xffdf;
    }
    if (((_engine_fault_register_a & 8) != 0) && ((_engine_fault_register_c & 8) == 0)) {
      _engine_fault_register_a = _engine_fault_register_a & 0xfff7;
    }
    if (((_engine_fault_register_a & 0x10) != 0) && ((_engine_fault_register_c & 0x10) == 0)) {
      _engine_fault_register_a = _engine_fault_register_a & 0xffef;
    }
  }
  if ((_derate_threshold_base < the_transmission_pwm_bias_from_load_to_duty_cycle_100_100) ||
     (uVar7 = (uint)_DAT_008079d8 + (uint)the_transmission_pwm_bias_from_load_to_duty_cycle_100_100,
     uVar7 < _derate_threshold_base)) {
    uVar7 = (uint)_DAT_008079d8 + (uint)the_transmission_pwm_bias_from_load_to_duty_cycle_100_100;
    in_D1 = (uint)_derate_threshold_base;
    if ((in_D1 <= uVar7) ||
       (uVar7 = CONCAT22((short)(uVar7 >> 0x10),_DAT_008096a6),
       _DAT_008096a6 <= the_transmission_pwm_signal_dutycycle_maximum_value_high_time_0_100)) {
      _DAT_00800144 = 0;
      _DAT_00800146 = 0;
      _DAT_00800148 = 0;
      goto LAB_0000eac6;
    }
  }
  uVar9 = (uint)_derate_threshold_base;
  uVar1 = (ushort)(uVar7 >> 0x10);
  uVar7 = CONCAT22(uVar1,_normal_derate_reference);
  wVar8 = the_load_point_at_which_the_kick_down_signal_activates_0_127;
  if (_derate_threshold_base <= _normal_derate_reference) {
    wVar8 = _DAT_008079de;
  }
  if (_DAT_00809d4e == 4) {
    if (_DAT_00800144 < wVar8) {
      _DAT_00800144 = _DAT_00800144 + 1;
    }
    else {
      _engine_fault_register_a = _engine_fault_register_a | 8;
      _engine_fault_register_c = _engine_fault_register_c | 8;
      _DAT_00809d52 = 0;
    }
  }
  else {
    _DAT_00800144 = 0;
  }
  if ((_DAT_00809d4e == 6) || (_DAT_00809d4e == 5)) {
    if (_DAT_00800146 < wVar8) {
      _DAT_00800146 = _DAT_00800146 + 1;
    }
    else {
      _engine_fault_register_a = _engine_fault_register_a | 0x10;
      _engine_fault_register_c = _engine_fault_register_c | 0x10;
      _DAT_00809d52 = 0;
    }
  }
  else {
    _DAT_00800146 = 0;
  }
  if (((_DAT_00809d4e == 2) || (_DAT_00809d4e == 3)) &&
     ((uVar7 = (uint)uVar1 << 0x10, (_engine_fault_register_a & 0x10) == 0 ||
      (uVar7 = CONCAT22(uVar1,_engine_fault_register_b) & 0xffff0010,
      (_engine_fault_register_b & 0x10) == 0)))) {
    uVar2 = (undefined2)(uVar7 >> 0x10);
    uVar7 = CONCAT22(uVar2,_engine_fault_register_a) & 0xffff0008;
    if (((_engine_fault_register_a & 8) == 0) ||
       (uVar7 = CONCAT22(uVar2,_engine_fault_register_b) & 0xffff0008,
       (_engine_fault_register_b & 8) == 0)) {
      if (_DAT_00800148 < wVar8) {
        _DAT_00800148 = _DAT_00800148 + 1;
        return CONCAT44(uVar7,uVar9);
      }
      _engine_fault_register_a = _engine_fault_register_a | 0x20;
      _engine_fault_register_c = _engine_fault_register_c | 0x20;
      _DAT_00809d52 = 0;
      bVar6 = -((vp44_communication_status & 0x80) != 0);
      _DAT_00804bdc = bVar6 & 1;
      return (ulonglong)CONCAT14(bVar6,uVar9) & 0x1ffffffff;
    }
  }
  _DAT_00800148 = 0;
  return CONCAT44(uVar7,uVar9);
}



//
// Function: FUN_0000eacc @ 0x0000eacc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0000eacc(void)

{
  _DAT_00809d56 = _DAT_008079d8 + 4;
  if ((_DAT_008035d6 & 4) != 0) {
    derate_status_flag = 1;
  }
  return _DAT_008035d6 & 4;
}



//
// Function: FUN_0000eaf0 @ 0x0000eaf0
// ERROR: Failed to decompile
//

//
// Function: FUN_0000eb5a @ 0x0000eb5a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000eb5a(void)

{
  if ((_DAT_0080c9a6 != 0xb) &&
     (the_load_point_at_which_the_kick_down_signal_de_activates_0_127 < _current_fuel_demand_value))
  {
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
// Function: FUN_0000ebb0 @ 0x0000ebb0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000ebb0(void)

{
  _DAT_0080c9ae = _DAT_00809d66 + _DAT_0080c9ae;
  _DAT_0080c9b2 = _DAT_0080016c | _DAT_0080c9b2 & 0xfffd;
  return;
}



//
// Function: FUN_0000ebd2 @ 0x0000ebd2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000ebd2(void)

{
  _DAT_00800162 = &engine_speed_at_0_fuel_which_activates_kick_down_signal_0_8000;
  _DAT_00800168 = &accel_threshold_to_disable_a_c_1200_1200;
  _DAT_00800160 = 2;
  return;
}



//
// Function: FUN_0000ebf2 @ 0x0000ebf2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000ebf2(void)

{
  ushort extraout_D0u;
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  sVar1 = FUN_0000e1b8((short *)&DAT_00004000,&DAT_00005e42);
  if ((sVar1 != _DAT_00803500) && (DAT_00005e42 != -0x5e5f)) {
    return 1;
  }
  puVar3 = (undefined4 *)&DAT_00004000;
  for (puVar2 = (undefined4 *)&DAT_00804882; puVar2 < (undefined4 *)0x80488c; puVar2 = puVar2 + 1) {
    *puVar2 = *puVar3;
    REG_SIM_SWSR = 0xaa;
    DAT_00ffd00f = 0xaa;
    puVar3 = puVar3 + 1;
  }
  puVar3 = &DAT_00004400;
  for (puVar2 = (undefined4 *)&DAT_0080488e; puVar2 < &DAT_008062d0; puVar2 = puVar2 + 1) {
    *puVar2 = *puVar3;
    REG_SIM_SWSR = 0xaa;
    DAT_00ffd00f = 0xaa;
    puVar3 = puVar3 + 1;
  }
  points_to_engine_sync_fuel_pressure_fuel_minimun_threshold_0_2_32._2_2_ = 1;
  return (uint)extraout_D0u << 0x10;
}



//
// Function: FUN_0000eca4 @ 0x0000eca4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000eca4(void)

{
  ushort extraout_D0u;
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  sVar1 = FUN_0000e1b8((short *)&DAT_00006000,(short *)0x7e42);
  if (sVar1 != _DAT_00803502) {
    return 1;
  }
  puVar3 = (undefined4 *)&DAT_00006000;
  for (puVar2 = (undefined4 *)&DAT_00804882; puVar2 < (undefined4 *)0x80488c; puVar2 = puVar2 + 1) {
    *puVar2 = *puVar3;
    REG_SIM_SWSR = 0xaa;
    DAT_00ffd00f = 0xaa;
    puVar3 = puVar3 + 1;
  }
  puVar3 = (undefined4 *)&DAT_00006400;
  for (puVar2 = (undefined4 *)&DAT_0080488e; puVar2 < &DAT_008062d0; puVar2 = puVar2 + 1) {
    *puVar2 = *puVar3;
    REG_SIM_SWSR = 0xaa;
    DAT_00ffd00f = 0xaa;
    puVar3 = puVar3 + 1;
  }
  points_to_engine_sync_fuel_pressure_fuel_minimun_threshold_0_2_32._2_2_ = 2;
  return (uint)extraout_D0u << 0x10;
}



//
// Function: FUN_0000ed52 @ 0x0000ed52
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0000ed52(void)

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
  FUN_00013144(0x80367a,(undefined1 *)&local_6,CONCAT22(2,uVar4));
  uVar5 = 0;
  while ((uVar5 < 5000 && (_DAT_0080367a != local_6))) {
    FUN_00013240();
    FUN_0002baf0(CONCAT22(500,uVar4));
    uVar5 = uVar5 + 1;
  }
  iVar1 = FUN_0001802e(0x4000);
  if (iVar1 == 0) {
    REG_SIM_SWSR = 0xaa;
    DAT_00ffd00f = 0xaa;
    sVar2 = FUN_00018174(0x4000,&DAT_00804882,CONCAT22(10,uVar6));
    if (sVar2 == 1) {
      REG_SIM_SWSR = 0xaa;
      DAT_00ffd00f = 0xaa;
      sVar2 = FUN_00018174(0x4400,&DAT_0080488e,CONCAT22(0x1a42,uVar6));
      cVar3 = sVar2 == 0;
      if (sVar2 == 1) {
        REG_SIM_SWSR = 0xaa;
        DAT_00ffd00f = 0xaa;
        local_6 = FUN_0000e1b8((short *)&DAT_00004000,&DAT_00005e42);
        REG_SIM_SWSR = 0xaa;
        DAT_00ffd00f = 0xaa;
        uVar5 = (ushort)(byte)(cVar3 << 4 | 8);
        FUN_00013144(0x803500,(undefined1 *)&local_6,CONCAT22(2,uVar5));
        uVar4 = 0;
        while ((uVar4 < 5000 && (_DAT_00803500 != local_6))) {
          FUN_00013240();
          FUN_0002baf0(CONCAT22(500,uVar5));
          uVar4 = uVar4 + 1;
        }
        FUN_00013144(0x80367c,&DAT_0080367a,CONCAT22(2,uVar5));
        uVar4 = 0;
        while ((uVar4 < 5000 && (_DAT_0080367c != _DAT_0080367a))) {
          FUN_00013240();
          FUN_0002baf0(CONCAT22(500,uVar5));
          uVar4 = uVar4 + 1;
        }
        points_to_engine_sync_fuel_pressure_fuel_minimun_threshold_0_2_32._2_2_ = 1;
        FUN_00026f10();
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
// Function: FUN_0000ef80 @ 0x0000ef80
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0000ef80(void)

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
  FUN_00013144(0x803682,(undefined1 *)&local_6,CONCAT22(2,uVar4));
  uVar5 = 0;
  while ((uVar5 < 5000 && (_DAT_00803682 != local_6))) {
    FUN_00013240();
    FUN_0002baf0(CONCAT22(500,uVar4));
    uVar5 = uVar5 + 1;
  }
  iVar1 = FUN_0001802e(0x6000);
  if (iVar1 == 0) {
    REG_SIM_SWSR = 0xaa;
    DAT_00ffd00f = 0xaa;
    sVar2 = FUN_00018174(0x6000,&DAT_00804882,CONCAT22(10,uVar6));
    if (sVar2 == 1) {
      REG_SIM_SWSR = 0xaa;
      DAT_00ffd00f = 0xaa;
      sVar2 = FUN_00018174(0x6400,&DAT_0080488e,CONCAT22(0x1a42,uVar6));
      cVar3 = sVar2 == 0;
      if (sVar2 == 1) {
        REG_SIM_SWSR = 0xaa;
        DAT_00ffd00f = 0xaa;
        local_6 = FUN_0000e1b8((short *)&DAT_00006000,(short *)0x7e42);
        REG_SIM_SWSR = 0xaa;
        DAT_00ffd00f = 0xaa;
        uVar5 = (ushort)(byte)(cVar3 << 4 | 8);
        FUN_00013144(0x803502,(undefined1 *)&local_6,CONCAT22(2,uVar5));
        uVar4 = 0;
        while ((uVar4 < 5000 && (_DAT_00803502 != local_6))) {
          FUN_00013240();
          FUN_0002baf0(CONCAT22(500,uVar5));
          uVar4 = uVar4 + 1;
        }
        FUN_00013144(0x803684,&DAT_00803682,CONCAT22(2,uVar5));
        uVar4 = 0;
        while ((uVar4 < 5000 && (_DAT_00803684 != _DAT_00803682))) {
          FUN_00013240();
          FUN_0002baf0(CONCAT22(500,uVar5));
          uVar4 = uVar4 + 1;
        }
        points_to_engine_sync_fuel_pressure_fuel_minimun_threshold_0_2_32._2_2_ = 2;
        FUN_00026f10();
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
// Function: FUN_0000f1ae @ 0x0000f1ae
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000f1ae(void)

{
  undefined4 uVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  ushort uVar8;
  
  points_to_engine_sync_fuel_pressure_fuel_minimun_threshold_0_2_32._2_2_ = 0;
  _DAT_00805df2 = _DAT_00805df2 & 0xefff;
  if (DAT_00005e42 == -0x5e5f) {
    FUN_0000ebf2();
    _DAT_008062d0 = 0;
  }
  else if ((_DAT_0080367a != _DAT_0080367c) || (_DAT_00803682 != _DAT_00803684)) {
    if (_DAT_0080367a != _DAT_0080367c) {
      if (_DAT_00803682 != _DAT_00803684) {
        _DAT_00805df2 = _DAT_00805df2 | 0x1000;
        _DAT_00805e32 = _DAT_00805e32 | 0x1000;
      }
      else {
        uVar1 = FUN_0000eca4();
        if ((short)uVar1 != 0) {
          _DAT_00805df2 = _DAT_00805df2 | 0x1000;
          _DAT_00805e32 = _DAT_00805e32 | 0x1000;
        }
      }
    }
    else {
      uVar1 = FUN_0000ebf2();
      if ((short)uVar1 != 0) {
        _DAT_00805df2 = _DAT_00805df2 | 0x1000;
        _DAT_00805e32 = _DAT_00805e32 | 0x1000;
      }
    }
  }
  else if ((_DAT_00803682 + _DAT_0080367a & 1U) == 0) {
    uVar1 = FUN_0000eca4();
    if ((short)uVar1 != 0) {
      uVar1 = FUN_0000ebf2();
      if ((short)uVar1 != 0) {
        _DAT_00805df2 = _DAT_00805df2 | 0x1000;
        _DAT_00805e32 = _DAT_00805e32 | 0x1000;
      }
    }
  }
  else {
    uVar1 = FUN_0000ebf2();
    if ((short)uVar1 != 0) {
      uVar1 = FUN_0000eca4();
      if ((short)uVar1 != 0) {
        _DAT_00805df2 = _DAT_00805df2 | 0x1000;
        _DAT_00805e32 = _DAT_00805e32 | 0x1000;
      }
    }
  }
  bVar6 = _DAT_00803686 < _DAT_00803688;
  bVar3 = (short)(_DAT_00803686 - _DAT_00803688) < 0;
  if (_DAT_00803686 == _DAT_00803688) {
    uVar8 = (ushort)(byte)(bVar6 << 4 | bVar3 << 3 | 4U | SBORROW2(_DAT_00803686,_DAT_00803688) << 1
                          | bVar6);
    _DAT_0080016e = 0;
    FUN_00013144(0x80368a,&DAT_0080016e,CONCAT22(2,uVar8));
    uVar2 = 0;
    while ((uVar2 < 5000 && (_DAT_0080368a != _DAT_0080016e))) {
      FUN_00013240();
      FUN_0002baf0(CONCAT22(500,uVar8));
      uVar2 = uVar2 + 1;
    }
    _DAT_0080016e = _DAT_0080368e + 1;
    FUN_00013144(0x80368e,&DAT_0080016e,CONCAT22(2,uVar8));
    uVar2 = 0;
    while ((uVar2 < 5000 && (_DAT_0080368e != _DAT_0080016e))) {
      FUN_00013240();
      FUN_0002baf0(CONCAT22(500,uVar8));
      uVar2 = uVar2 + 1;
    }
    bVar3 = (uVar8 & 0x10) != 0;
    bVar6 = (uVar8 & 8) != 0;
    bVar4 = (uVar8 & 4) != 0;
    bVar5 = (uVar8 & 2) != 0;
    bVar7 = (uVar8 & 1) != 0;
    _DAT_00805df2 = _DAT_00805df2 & 0xf7ff;
  }
  else {
    uVar8 = (ushort)(byte)(bVar6 << 4 | bVar3 << 3 | SBORROW2(_DAT_00803686,_DAT_00803688) << 1 |
                          bVar6);
    _DAT_0080016e = _DAT_0080368a + 1;
    FUN_00013144(0x80368a,&DAT_0080016e,CONCAT22(2,uVar8));
    uVar2 = 0;
    while ((uVar2 < 5000 && (_DAT_0080368a != _DAT_0080016e))) {
      FUN_00013240();
      FUN_0002baf0(CONCAT22(500,uVar8));
      uVar2 = uVar2 + 1;
    }
    _DAT_0080016e = _DAT_0080368c + 1;
    FUN_00013144(0x80368c,&DAT_0080016e,CONCAT22(2,uVar8));
    uVar2 = 0;
    while ((uVar2 < 5000 && (_DAT_0080368c != _DAT_0080016e))) {
      FUN_00013240();
      FUN_0002baf0(CONCAT22(500,uVar8));
      uVar2 = uVar2 + 1;
    }
    bVar5 = SBORROW2(_DAT_0080368a,_DAT_008088c0);
    bVar6 = (short)(_DAT_0080368a - _DAT_008088c0) < 0;
    bVar4 = _DAT_0080368a == _DAT_008088c0;
    if (_DAT_0080368a < _DAT_008088c0) {
      _DAT_00805df2 = _DAT_00805df2 & 0xf7ff;
      bVar3 = true;
      bVar7 = true;
    }
    else {
      _DAT_00805df2 = _DAT_00805df2 | 0x800;
      _DAT_00805e32 = _DAT_00805e32 | 0x800;
      bVar3 = false;
      bVar7 = false;
    }
  }
  uVar8 = (ushort)(byte)(bVar3 << 4 | bVar6 << 3 | bVar4 << 2 | bVar5 << 1 | bVar7);
  _DAT_0080016e = _DAT_0080368c + _DAT_0080368e;
  FUN_00013144(0x803686,&DAT_0080016e,CONCAT22(2,uVar8));
  uVar2 = 0;
  while ((uVar2 < 5000 && (_DAT_00803686 != _DAT_0080016e))) {
    FUN_00013240();
    FUN_0002baf0(CONCAT22(500,uVar8));
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
    REG_SIM_SWSR = 0xaa;
    DAT_00ffd00f = 0xaa;
    *puVar2 = *(undefined4 *)pbVar1;
    pbVar1 = pbVar1 + 4;
  }
  return;
}



//
// Function: FUN_0000f524 @ 0x0000f524
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0000f524(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = ((uint)_current_fuel_demand_value * 0x6400) / 0x1700;
  delay_before_warning_about_shutdown_from_oil_press_rpm_0_65535 = (word)uVar1;
  uVar2 = ((uint)_DAT_0080d482 * 0x6400) / 0x1700;
  time_since_rpm_crossed_oil_pres_start_mon_rpm_0_65535 = (word)uVar2;
  uVar3 = uVar2 & 0xffff0000;
  if ((_DAT_00805670 & 1) == 0) {
    _DAT_00fff42a = _DAT_00fff42a & 0xffff0000;
  }
  else {
    uVar3 = ((((uint)_DAT_00808934 * (uVar1 & 0xffff)) / 0x6400 & 0xffff) * 8000) / 1000 & 0xffff |
            ((uint)_DAT_00808934 * 8000) / 1000 << 0x10;
    _DAT_00fff42a = uVar3;
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
  if (5 < amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535) {
    uVar3 = uVar3 & 0xffff0000;
    if ((_DAT_00805670 & 4) == 0) {
      _DAT_00fff43a = _DAT_00fff43a & 0xffff0000;
    }
    else {
      uVar3 = ((((uint)_DAT_00808938 * (uint)errors_allowed_timer_running_flag_for_oil_pres_0_1) /
                0x6400 & 0xffff) * 8000) / 1000 & 0xffff |
              ((uint)_DAT_00808938 * 8000) / 1000 << 0x10;
      _DAT_00fff43a = uVar3;
    }
  }
  if (5 < amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535) {
    uVar3 = uVar3 & 0xffff0000;
    if ((_DAT_00805670 & 8) == 0) {
      _DAT_00fff442 = _DAT_00fff442 & 0xffff0000;
    }
    else {
      uVar3 = ((((uint)_DAT_0080893a *
                (uint)pointer_to_oil_pressure_fuel_fault_log_data_0_2_32._0_2_) / 0x6400 & 0xffff) *
              8000) / 1000 & 0xffff | ((uint)_DAT_0080893a * 8000) / 1000 << 0x10;
      _DAT_00fff442 = uVar3;
    }
  }
  if (((_DAT_00805670 & 0x10) != 0) &&
     (pointer_to_oil_pressure_fuel_fault_log_data_0_2_32._2_2_ != 0)) {
    if (0x63ff < pointer_to_oil_pressure_fuel_fault_log_data_0_2_32._2_2_) {
      uVar3 = ((uint)_DAT_0080893c * 8000) / 1000;
      _DAT_00fff414 = -1 - (short)uVar3;
      _DAT_00fff41a = 0x7fff8000;
      return uVar3;
    }
    _DAT_00fff414 = -(short)(((uint)_DAT_0080893c * 8000) / 1000) - 1;
    _DAT_00fff41a =
         (_DAT_00fff414 & 0x7fff) +
         (((((uint)_DAT_0080893c * (uint)pointer_to_oil_pressure_fuel_fault_log_data_0_2_32._2_2_) /
            0x6400 & 0xffff) * 8000) / 1000 & 0xffff) | 0x7fff0000;
    return _DAT_00fff41a;
  }
  _DAT_00fff41a = 0x7fff;
  return CONCAT22((short)(uVar3 >> 0x10),_DAT_00805670) & 0xffff0010;
}



//
// Function: FUN_0000f86a @ 0x0000f86a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0000f86a(void)

{
  _DAT_0080d48c = _DAT_0080d48c | 1;
  return 0;
}



//
// Function: FUN_0000f876 @ 0x0000f876
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0000f876(void)

{
  uint in_D0;
  
  if (_DAT_0080d3f4 == 1) {
    _DAT_0080d3f4 = 0;
    amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535 = 1;
    points_to_water_in_fuel_fuel_maximum_threshold_0_2_32._0_2_ = 0xeeee;
    return in_D0 & 0xffffff00;
  }
  return 4;
}



//
// Function: FUN_0000f89c @ 0x0000f89c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0000f89c(void)

{
  amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535 = 0;
  _DAT_0080d3f4 = 1;
  points_to_water_in_fuel_fuel_maximum_threshold_0_2_32._0_2_ = 0xaaaa;
  return 0;
}



//
// Function: FUN_0000f8b6 @ 0x0000f8b6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0000f8b6(void)

{
  amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535 = 1;
  if (points_to_water_in_fuel_fuel_maximum_threshold_0_2_32._0_2_ == -0x5556) {
    points_to_water_in_fuel_fuel_maximum_threshold_0_2_32._0_2_ = -0x1112;
    _DAT_0080d3f4 = 0;
  }
  return 0;
}



//
// Function: FUN_0000f8d8 @ 0x0000f8d8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0000f8d8(void)

{
  _DAT_0080c996 = 1;
  return 0;
}



//
// Function: FUN_0000f8e4 @ 0x0000f8e4
//

void FUN_0000f8e4(byte *param_1)

{
  ushort in_stack_00000000;
  
  FUN_0000f906(param_1,(uint)in_stack_00000000);
  return;
}



//
// Function: FUN_0000f8f6 @ 0x0000f8f6
//

void FUN_0000f8f6(void)

{
  undefined2 in_stack_00000000;
  
  FUN_0000f906((byte *)0x0,CONCAT22(1,in_stack_00000000));
  return;
}



//
// Function: FUN_0000f906 @ 0x0000f906
//

/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000f906(byte *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 unaff_A2;
  ushort uVar3;
  dword local_8;
  
  uVar3 = (ushort)((uint)unaff_A2 >> 0x10);
  if (engine_operating_mode == IDLE) {
    while (uVar1 = FUN_00013134(), (char)uVar1 == '\0') {
      FUN_00013240();
      FUN_0002bb2e(CONCAT22(500,uVar3));
    }
    local_8 = loopCounter;
    FUN_00013144(0x80352c,(undefined1 *)&local_8,CONCAT22(4,uVar3));
    if (amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535 == 0) {
      FUN_0002bb2e(CONCAT22(0xfa,uVar3));
    }
    else {
      while (_DAT_0080352c != local_8) {
        FUN_00013240();
        FUN_0002bb2e(CONCAT22(500,uVar3));
      }
    }
    if (param_2._1_1_ == '\0') {
      FUN_000298d8(param_1,(uint)uVar3);
    }
    else {
      FUN_0000a626((uint)uVar3);
    }
    FUN_0002bb2e(CONCAT22(50000,uVar3));
    sim_data_direction_control = sim_data_direction_control & 0xef;
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
// Function: FUN_0000f9e4 @ 0x0000f9e4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0000f9e4(void)

{
  _DAT_0080d450 = 1;
  return 0;
}



//
// Function: canMessageBufferLogger @ 0x0000f9f0
//

undefined4 canMessageBufferLogger(void)

{
  undefined4 uVar1;
  
  if (points_to_water_in_fuel_fuel_maximum_threshold_0_2_32._2_2_ == 1) {
    return 7;
  }
  uVar1 = circularBufferWrite();
  if ((char)uVar1 == '\x01') {
    DAT_0080d3f3 = 0;
    return 0xb;
  }
  DAT_0080d406 = 1;
  points_to_engine_sync_fuel_pressure_fuel_minimun_threshold_0_2_32._0_2_ = 0;
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
// Function: FUN_0000fcb0 @ 0x0000fcb0
//

undefined4 FUN_0000fcb0(byte *param_1,undefined4 param_2)

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
// Function: FUN_0000fd02 @ 0x0000fd02
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000fd02(void)

{
  byte bVar2;
  ushort uVar1;
  uint unaff_D3;
  uint uVar3;
  word *pwVar4;
  int iVar5;
  
  uVar3 = unaff_D3 & 0xffffff00;
  pwVar4 = &tracks_progress_of_fan_on_due_to_ac_0_3600;
  iVar5 = 0x80d3aa;
  for (bVar2 = 0; bVar2 < _memory_patch_count; bVar2 = bVar2 + 1) {
    uVar3 = CONCAT31((int3)(uVar3 >> 8),*(char *)(iVar5 + 1) + (char)uVar3);
    iVar5 = iVar5 + 6;
  }
  uVar1 = 0;
  while ((char)uVar3 != '\0') {
    uVar1 = *(ushort *)((int)&DAT_0000fab0 + (short)((uVar1 ^ *(byte *)pwVar4) & 0xff) * 2) ^
            uVar1 >> 8;
    pwVar4 = (word *)((int)pwVar4 + 1);
    uVar3 = CONCAT31((int3)(uVar3 >> 8),(char)uVar3 + -1);
  }
  return CONCAT22((short)(uVar3 >> 0x10),uVar1);
}



//
// Function: FUN_0000fd68 @ 0x0000fd68
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0000fd68(void)

{
  short sVar1;
  bool bVar2;
  ushort uVar3;
  ushort uVar5;
  ushort uVar6;
  uint uVar4;
  word unaff_D2w;
  ushort uVar7;
  int iVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  uint uVar11;
  
  uVar5 = _diagnostic_system_flags_1 & 0x800;
  if (((((_diagnostic_system_flags_1 & 0x800) == 0) ||
       (uVar5 = _DAT_0080965a, _DAT_0080965a < value_used_to_detect_sync_pulse_0_100)) ||
      (uVar5 = _current_fuel_demand_value,
      _current_fuel_demand_value < used_in_cranking_mode_0_4000._0_2_)) ||
     ((uVar5 = current_engine_rpm, current_engine_rpm <= used_in_cranking_mode_0_4000._2_2_ ||
      (replaced_old_crank_timer_count2_0 <= current_engine_rpm)))) {
    _DAT_008001b0 = 0;
    _DAT_00809d6a = 0;
    _DAT_00809d6e = 0;
    return uVar5;
  }
  _DAT_008001aa = current_engine_rpm;
  _DAT_00800196 = current_engine_rpm;
  _DAT_0080018a = current_engine_rpm;
  _DAT_00800176 = current_engine_rpm;
  _DAT_0080017e = _current_fuel_demand_value;
  if (used_in_cranking_mode_0_4000._2_2_ != 0 || temp_below_which_cold_crank_can_run_50_293 != 0) {
    if (((_DAT_00805df4 & 0x200) == 0) || ((_DAT_008068c6 & 0x200) == 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) {
      if (((_DAT_00805df4 & 0x400) == 0) || ((_DAT_008068c6 & 0x400) == 0)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (!bVar2) {
        if (((_DAT_00805df4 & 4) == 0) || ((_DAT_008068c6 & 4) == 0)) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if (bVar2) {
LAB_0000fe82:
          if (used_in_cranking_mode_0_4000._2_2_ == 0) goto LAB_0000fff4;
        }
        else {
          if (((_DAT_00805df4 & 8) == 0) || ((_DAT_008068c6 & 8) == 0)) {
            bVar2 = false;
          }
          else {
            bVar2 = true;
          }
          if (bVar2) goto LAB_0000fe82;
        }
        if (used_in_cranking_mode_0_4000._2_2_ == 0) {
          _DAT_008001b2 = _DAT_008092f2 + _diagnostic_sensor_reading;
        }
        else {
          _DAT_008001b2 = _diagnostic_sensor_reading;
        }
        _DAT_0080019e = _DAT_008001b2;
        uVar5 = lookupTableInterpolation((short *)&DAT_00800184);
        uVar9 = tableInterpolationLookup((short *)&DAT_00800190);
        uVar10 = tableInterpolationLookup((short *)&DAT_00800170);
        uVar6 = (ushort)((ulonglong)uVar10 >> 0x20);
        uVar4 = FUN_000357d2((uint)_DAT_008001b2,(uint)(ushort)((ulonglong)uVar9 >> 0x20),0x400);
        if (uVar4 < 0xbb81) {
          _DAT_00809d6c = (ushort)uVar4;
        }
        else {
          _DAT_00809d6c = 48000;
        }
        uVar3 = _DAT_00809d6c;
        if (0 < _DAT_00809d70) {
          uVar11 = 0x100;
          uVar4 = FUN_000357d2((int)_DAT_00809d70 * (uint)uVar5,0x100,0x4444);
          uVar4 = FUN_000357d2((uint)_DAT_00809d6c,(uVar4 & 0xffff) + 0x100,uVar11);
        }
        if (uVar4 < 0xbb81) {
          _DAT_00809d6c = (ushort)uVar4;
        }
        else {
          _DAT_00809d6c = 48000;
        }
        if (_DAT_00809d6c < uVar6) {
          iVar8 = 0x7fffffff;
          uVar7 = uVar6 - _DAT_00809d6c;
        }
        else {
          uVar7 = _DAT_00809d6c - uVar6;
          iVar8 = -0x80000000;
        }
        if (temp_below_which_cold_crank_can_run_50_293 < uVar7) {
          if ((uVar3 != 0) && (uVar5 != 0)) {
            iVar8 = rpmFuelCalculation((int)(short)(uVar6 - _DAT_00809d6c),0x4444,
                                       (uint)uVar5 * (uint)uVar3);
          }
          _DAT_00809d6e = 1;
          if (iVar8 < 0xab) {
            if (iVar8 < -0xaa) {
              unaff_D2w = 0xff56;
            }
            else {
              unaff_D2w = (word)iVar8;
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
  if (used_in_cranking_mode_0_4000._2_2_ != 0 || temp_below_which_cold_crank_can_run_50_293 != 0) {
    if (((_DAT_00805df4 & 0x200) == 0) || ((_DAT_008068c6 & 0x200) == 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) {
      if (((_DAT_00805df4 & 0x400) == 0) || ((_DAT_008068c6 & 0x400) == 0)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (!bVar2) {
        if (((_DAT_00805df4 & 4) == 0) || ((_DAT_008068c6 & 4) == 0)) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if ((!bVar2) || (used_in_cranking_mode_0_4000._2_2_ != 0)) {
          if (((_DAT_00805df4 & 8) == 0) || ((_DAT_008068c6 & 8) == 0)) {
            bVar2 = false;
          }
          else {
            bVar2 = true;
          }
          if ((!bVar2) || (used_in_cranking_mode_0_4000._2_2_ != 0)) goto LAB_000101fa;
        }
      }
    }
  }
  if (((_DAT_00805df2 & 0x2000) == 0) || ((_DAT_008068c4 & 0x2000) == 0)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (!bVar2) {
    if (((_DAT_00805df2 & 0x4000) == 0) || ((_DAT_008068c4 & 0x4000) == 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) {
      if (the_value_above_set_speed_where_e_brakes_will_turn_off_regard_0_5_10 == 0) {
        if (time_constant_compared_with_prior_pulse_time_in_final_cold_sy_400_0 <
            time_constant_compared_with_prior_pulse_slope_in_final_cold_0_4000) {
          uVar4 = 0x7fffffff;
        }
        else {
          uVar4 = 0x80000000;
        }
      }
      else {
        iVar8 = rpmFuelCalculation(((uint)current_engine_rpm * (uint)_current_fuel_demand_value) /
                                   0x1266 & 0xffff,
                                   (uint)
                                   time_constant_compared_with_prior_pulse_slope_in_final_cold_0_4000
                                   - (uint)
                                     time_constant_compared_with_prior_pulse_time_in_final_cold_sy_400_0
                                   ,(uint)
                                    the_value_above_set_speed_where_e_brakes_will_turn_off_regard_0_5_10
                                  );
        uVar4 = (uint)time_constant_compared_with_prior_pulse_time_in_final_cold_sy_400_0 + iVar8;
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
      if ((uint)engine_speed_limit_below_which_the_cold_crank_sync_determina_0_8000 +
          (uint)_DAT_008091ea < (uVar4 & 0xffff)) {
        sVar1 = _DAT_008091ea - _DAT_00809d68;
        uVar5 = lookupTableInterpolation((short *)&DAT_008001a4);
        iVar8 = rpmFuelCalculation((uint)uVar5,(int)sVar1,0x7800);
        if (iVar8 < 0xab) {
          if (iVar8 < -0xaa) {
            unaff_D2w = 0xff56;
          }
          else {
            unaff_D2w = (word)iVar8;
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
  if ((short)unaff_D2w < (short)used_in_cranking_mode_0_4000._0_2_) {
    _DAT_00809d6a = used_in_cranking_mode_0_4000._0_2_;
  }
  else if (((short)unaff_D2w < 1) ||
          ((current_engine_rpm < replaced_old_crank_timer_count1_0 &&
           (value_used_to_detect_sync_pulse_0_100 < current_engine_rpm)))) {
    _DAT_00809d6a = unaff_D2w;
    if ((int)(uint)number_of_sync_errors_above_which_crank_fueling_will_be_inhib_0_200 <
        (int)(short)unaff_D2w) {
      _DAT_00809d6a = number_of_sync_errors_above_which_crank_fueling_will_be_inhib_0_200;
    }
  }
  else {
    _DAT_00809d6a = 0;
  }
  if (temp_below_which_cold_crank_can_run_50_293 != 0) {
    if (((_DAT_00805df4 & 0x200) == 0) || ((_DAT_008068c6 & 0x200) == 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) {
      if (((_DAT_00805df4 & 0x400) == 0) || ((_DAT_008068c6 & 0x400) == 0)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (!bVar2) {
        if (((_DAT_00805df4 & 4) == 0) || ((_DAT_008068c6 & 4) == 0)) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if ((!bVar2) || (used_in_cranking_mode_0_4000._2_2_ != 0)) {
          if (((_DAT_00805df4 & 8) == 0) || ((_DAT_008068c6 & 8) == 0)) {
            uVar5 = 0;
          }
          else {
            uVar5 = 1;
          }
          if (uVar5 == 0) {
            _DAT_008001b0 = 8;
            return 0;
          }
          if (used_in_cranking_mode_0_4000._2_2_ != 0) {
            _DAT_008001b0 = 8;
            return uVar5;
          }
        }
      }
    }
  }
  if (((_DAT_00805df2 & 0x2000) == 0) || ((_DAT_008068c4 & 0x2000) == 0)) {
    uVar5 = 0;
  }
  else {
    uVar5 = 1;
  }
  if (uVar5 == 0) {
    if (((_DAT_00805df2 & 0x4000) == 0) || ((_DAT_008068c4 & 0x4000) == 0)) {
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
// Function: FUN_00010366 @ 0x00010366
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010366(void)

{
  _DAT_00809d70 = _DAT_0080c9ae;
  if ((short)(_DAT_00809d6a + _DAT_0080c9ae) < 0) {
    _DAT_0080c9ae = 0;
  }
  else {
    _DAT_0080c9ae = _DAT_00809d6a + _DAT_0080c9ae;
  }
  _DAT_0080c9b2 = _DAT_008001b0 | _DAT_0080c9b2 & 0xfff7;
  return;
}



//
// Function: FUN_000103a2 @ 0x000103a2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000103a2(void)

{
  _DAT_0080018a = current_engine_rpm;
  _DAT_00800186 = &duty_cycle_conversion_factor_for_cool_temp_gauge_hot_state_0_9;
  _DAT_0080018c = &minimum_amount_of_time_which_the_anc_speed_limit_will_be_active_0_20;
  _DAT_00800184 = 2;
  _DAT_00800196 = current_engine_rpm;
  _DAT_00800192 = &duration_anc_speed_limit_will_be_disabled_after_a_bare_engine_a_0_20;
  _DAT_00800190 = 2;
  _DAT_0080019e = _DAT_008001b2;
  _DAT_0080019a = 0x807a66;
  _DAT_00800198 = 2;
  _DAT_008001a0 = 0x807a6e;
  _DAT_008001aa = current_engine_rpm;
  _DAT_008001a6 = &default_fueling_to_be_used_by_altitude_derate_if_ambient_air_p_0_100;
  _DAT_008001ac = 0x807ad8;
  _DAT_008001a4 = 2;
  _DAT_00800176 = current_engine_rpm;
  _DAT_00800172 = 0x807af4;
  _DAT_00800170 = 2;
  _DAT_0080017e = _current_fuel_demand_value;
  _DAT_0080017a = 0x807b10;
  _DAT_00800178 = 2;
  _DAT_00800180 = 0x807b20;
  return;
}



//
// Function: FUN_00010466 @ 0x00010466
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010466(void)

{
  int *piVar1;
  
  piVar1 = (int *)&vp44_buffer_start;
  do {
    while( true ) {
      if ((*piVar1 == 0) || (&vp44_buffer_start + (uint)_vp44_buffer_count * 4 <= piVar1)) {
        return;
      }
      if (_vp44_transmission_index != 0) break;
      *_vp44_current_read_address = *(undefined1 *)*piVar1;
      piVar1 = piVar1 + 1;
      _vp44_transmission_index = 1;
    }
    _vp44_current_read_address = _vp44_current_read_address + 1;
    if (_vp44_end_address < _vp44_current_read_address) {
      _vp44_current_read_address = _vp44_base_address;
    }
    *_vp44_current_read_address = *(undefined1 *)*piVar1;
    piVar1 = piVar1 + 1;
    if ((_vp44_current_read_address == _vp44_current_write_address) &&
       (_vp44_current_write_address = _vp44_current_write_address + 1,
       _vp44_end_address < _vp44_current_write_address)) {
      _vp44_current_write_address = _vp44_base_address;
    }
  } while (_vp44_current_read_address != _vp44_transmission_address);
  _vp44_state_machine_index = 3;
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
  
  piVar5 = (int *)&vp44_buffer_start;
  uVar2 = (undefined2)((uint)in_D0 >> 0x10);
  uVar4 = CONCAT22(uVar2,vp44_status_flags_1) & 0xffff0100;
  if ((vp44_status_flags_1 & 0x100) != 0) {
    uVar4 = CONCAT22(uVar2,_vp44_command_id);
    if ((_vp44_command_id == param_1._0_2_) && (_vp44_buffer_start != 0)) {
      if (_vp44_init_flag == 0) {
        if (1 < _vp44_buffer_size) {
          _vp44_init_flag = 1;
        }
        if ((_vp44_state_machine_index == 3) && (_vp44_comm_mode == 0)) {
          _vp44_state_machine_index = 0;
        }
        uVar4 = _vp44_state_machine_index;
        if (_vp44_state_machine_index < 4) {
          uVar4 = CONCAT22((short)(_vp44_state_machine_index >> 0x10),
                           (&switchD_00010596::switchdataD_0001059a)[_vp44_state_machine_index]);
          switch(_vp44_state_machine_index) {
          case 0:
            _vp44_transmission_active = 1;
            for (; (*piVar5 != 0 && (piVar5 < (int *)0x804c68)); piVar5 = piVar5 + 1) {
              _vp44_buffer_count = _vp44_buffer_count + 1;
            }
            iVar1 = _vp44_base_address - 0x2000U % (uint)_vp44_buffer_count;
            _vp44_end_address = iVar1 + 0x1fff;
            uVar3 = 0x2000 / _vp44_buffer_count;
            _vp44_block_size = (ushort)uVar3;
            _vp44_total_data_size = _vp44_block_size * _vp44_buffer_count;
            _vp44_current_read_address = _vp44_base_address;
            _vp44_current_write_address = _vp44_base_address;
            _vp44_transmission_index = 0;
            if (_vp44_comm_mode == 0) {
              _vp44_state_machine_index = 1;
              _vp44_transmission_address = iVar1 + 0x2000;
              uVar4 = FUN_00010466();
            }
            else {
              if (2 < _vp44_comm_state) {
                _vp44_comm_state = 0;
              }
              uVar4 = (uint)_vp44_comm_state;
              if (_vp44_comm_state == 0) {
                uVar4 = 3;
                _vp44_state_machine_index = 3;
              }
              else if (_vp44_comm_state == 1) {
                _vp44_state_machine_index = 2;
                _vp44_transmission_address =
                     (_vp44_base_address + ((int)uVar3 >> 1) * (uint)_vp44_buffer_count) - 1;
                uVar4 = FUN_00010466();
              }
              else if (_vp44_comm_state == 2) {
                _vp44_state_machine_index = 2;
                _vp44_transmission_address = _vp44_end_address;
                uVar4 = FUN_00010466();
              }
            }
            break;
          case 1:
            if (_vp44_comm_mode == 0) {
              uVar4 = FUN_00010466();
            }
            else {
              if (2 < _vp44_comm_state) {
                _vp44_comm_state = 0;
              }
              uVar4 = (uint)_vp44_comm_state;
              if (_vp44_comm_state == 0) {
                uVar4 = 3;
                _vp44_state_machine_index = 3;
              }
              else if (_vp44_comm_state == 1) {
                _vp44_state_machine_index = 2;
                _DAT_00809d7e = _vp44_current_read_address + 1;
                if (_vp44_end_address < _DAT_00809d7e) {
                  _DAT_00809d7e = _vp44_base_address;
                }
                _vp44_transmission_address =
                     _vp44_current_read_address +
                     ((int)(uint)_vp44_block_size >> 1) * (uint)_vp44_buffer_count;
                if (_vp44_end_address < _vp44_transmission_address) {
                  _vp44_transmission_address = _vp44_transmission_address - _vp44_total_data_size;
                }
                uVar4 = FUN_00010466();
              }
              else if (_vp44_comm_state == 2) {
                _vp44_state_machine_index = 2;
                _vp44_transmission_address = _vp44_end_address;
                _vp44_current_read_address = _vp44_base_address;
                _vp44_current_write_address = _vp44_base_address;
                _vp44_transmission_index = 0;
                uVar4 = FUN_00010466();
              }
            }
            break;
          case 2:
            uVar4 = FUN_00010466();
            break;
          case 3:
            _vp44_buffer_count = 0;
            _vp44_transmission_active = 0;
          }
        }
      }
      else {
        _vp44_init_flag = _vp44_init_flag + 1;
        uVar4 = CONCAT22(uVar2,_vp44_init_flag);
        if (_vp44_buffer_size <= _vp44_init_flag) {
          _vp44_init_flag = 0;
        }
      }
    }
  }
  return uVar4;
}



//
// Function: FUN_0001078e @ 0x0001078e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001078e(void)

{
  _vp44_base_address = 0x809d8c;
  _DAT_00809d88 = &vp44_buffer_start;
  return;
}



//
// Function: FUN_000107a4 @ 0x000107a4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_000107a4(void)

{
  int *piVar1;
  bool bVar2;
  undefined4 in_D0;
  uint uVar3;
  byte bVar4;
  char cVar5;
  char cVar6;
  word *pwVar7;
  ushort *puVar8;
  undefined8 uVar9;
  
  uVar3 = CONCAT22((short)((uint)in_D0 >> 0x10),_DAT_00803618) & 0xffff0001;
  if (((_DAT_00803618 & 1) != 0) && (engine_operating_mode != IDLE)) {
    if (_DAT_00804a1c == 0) {
      _DAT_00804a14 = engineRunCounter;
    }
    if ((_DAT_00809b10 == 0) && ((_DAT_00809b14 == 0 || (_DAT_008001cc <= _DAT_00809b14)))) {
      _DAT_00804a0c = engineRunCounter;
    }
    else if ((_DAT_00809b14 == 0) && (_DAT_008001cc <= _DAT_00809b10)) {
      _DAT_00804a10 = engineRunCounter;
    }
    if ((current_engine_rpm < _DAT_00807852) && (_DAT_00807854 <= current_engine_rpm)) {
      _DAT_008001ca = _calculated_fuel_timing_value;
    }
    else {
      if (current_engine_rpm < _DAT_00807852) {
        _DAT_008001f0 = _DAT_00807854;
      }
      else {
        _DAT_008001f0 = _DAT_00807852;
      }
      _DAT_008001dc = _DAT_008001f0;
      if (_DAT_0080965a == 0x4000) {
        uVar9 = tableInterpolationLookup((short *)&DAT_008001d6);
        _DAT_008001ca = (ushort)((ulonglong)uVar9 >> 0x20);
      }
      else if (_DAT_0080965a == 0) {
        uVar9 = tableInterpolationLookup((short *)&DAT_008001ea);
        _DAT_008001ca = (ushort)((ulonglong)uVar9 >> 0x20);
      }
      else {
        uVar9 = tableInterpolationLookup((short *)&DAT_008001d6);
        _DAT_008001d2 = (ushort)((ulonglong)uVar9 >> 0x20);
        uVar9 = tableInterpolationLookup((short *)&DAT_008001ea);
        _DAT_008001d4 = (ushort)((ulonglong)uVar9 >> 0x20);
        _DAT_008001ca =
             (short)((uint)_DAT_0080965a * (uint)_DAT_008001d2 >> 0xe) +
             (short)((uint)_DAT_008001d4 * (0x4000 - (uint)_DAT_0080965a) >> 0xe);
      }
    }
    if (_DAT_008001ca == fsmxthfl_calc_input) {
      _DAT_008001c6 = (uint)_DAT_0080787a;
    }
    else {
      _DAT_008001c6 =
           (int)(((uint)_current_fuel_demand_value - (uint)fsmxthfl_calc_input) * 10000) /
           (int)((uint)_DAT_008001ca - (uint)fsmxthfl_calc_input);
    }
    if ((int)_DAT_008001c6 < 0) {
      _DAT_00809b18 = 0;
      if (current_engine_rpm < _DAT_00807852) {
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
      pwVar7 = &hysteresis_added_to_postheat_stage_rpm_transitions_0_4500;
      while ((bVar4 < 9 && (!bVar2))) {
        if (current_engine_rpm <= *pwVar7) {
          bVar2 = true;
          if (bVar4 == 1) {
            cVar6 = '\x01';
          }
          else {
            cVar6 = bVar4 - 1;
          }
        }
        bVar4 = bVar4 + 1;
        pwVar7 = pwVar7 + 1;
      }
      bVar2 = false;
      bVar4 = 1;
      puVar8 = (ushort *)&DAT_0080786e;
      while ((bVar4 < 7 && (!bVar2))) {
        if (_DAT_008001c8 <= *puVar8) {
          bVar2 = true;
          if (bVar4 == 1) {
            cVar5 = '\x01';
          }
          else {
            cVar5 = bVar4 - 1;
          }
        }
        bVar4 = bVar4 + 1;
        puVar8 = puVar8 + 1;
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
// Function: FUN_00010ad8 @ 0x00010ad8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010ad8(void)

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
  _DAT_008001e6 = &lower_limitation_of_intake_manifold_temperature_to_inhibit_50_to_293;
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
// Function: FUN_00010c98 @ 0x00010c98
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010c98(void)

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
// Function: FUN_00010d78 @ 0x00010d78
//

undefined4 FUN_00010d78(undefined4 param_1)

{
  char cVar1;
  
  cVar1 = (char)((uint)param_1 >> 0x10);
  if (cVar1 == (char)the_can_bus_configuration_register_0_255) {
    return 1;
  }
  if (cVar1 == (char)the_can_bit_timing_0_register_0_255) {
    return 2;
  }
  if (cVar1 == (char)the_can_bit_timing_1_register_0_255) {
    return 3;
  }
  return 4;
}



//
// Function: FUN_00010da4 @ 0x00010da4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010da4(undefined4 param_1)

{
  undefined8 uVar1;
  undefined2 uVar2;
  
  _DAT_00800204 = param_1._0_2_;
  uVar2 = 0x80;
  uVar1 = tableInterpolationLookup((short *)&DAT_008001fe);
  FUN_00012966((short)((short)((ulonglong)uVar1 >> 0x20) - (_DAT_0080022a + param_1._2_2_)) * 0x6400
               ,CONCAT22(the_maximum_speed_a_customer_may_program_to_correspond_with_s_1_5_15 -
                         _DAT_0080bda0,uVar2));
  return;
}



//
// Function: FUN_00010e02 @ 0x00010e02
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010e02(void)

{
  _DAT_00800218 = _DAT_0080d092;
  _DAT_0080bd9a = lookupTableInterpolation((short *)&DAT_00800212);
  _DAT_00800218 = _DAT_00807c3c;
  _DAT_0080bd9e = lookupTableInterpolation((short *)&DAT_00800212);
  _DAT_00800218 = CRACSWAC;
  _DAT_0080bda0 = lookupTableInterpolation((short *)&DAT_00800212);
  _DAT_00800218 = CRCNDTRF;
  _DAT_0080bda2 = lookupTableInterpolation((short *)&DAT_00800212);
  _DAT_00800218 = the_minimum_speed_a_customer_may_program_to_correspond_with_s_1_5_15;
  _DAT_0080bd9c = lookupTableInterpolation((short *)&DAT_00800212);
  return;
}



//
// Function: FUN_00010e70 @ 0x00010e70
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010e70(void)

{
  _DAT_00800224 = _DAT_0080926e;
  _DAT_0080022a = lookupTableInterpolation((short *)&DAT_0080021e);
  FUN_00010e02();
  _DAT_0080bd96 = FUN_00010da4(CONCAT22(_DAT_0080d092,_DAT_0080bd9a));
  _DAT_0080bd98 =
       FUN_00010da4(CONCAT22(the_minimum_speed_a_customer_may_program_to_correspond_with_s_1_5_15,
                             _DAT_0080bd9c));
  _DAT_0080bd90 = FUN_00010da4(CONCAT22(_DAT_00807c3c,_DAT_0080bd9e));
  _DAT_0080bd92 = FUN_00010da4(CONCAT22(CRACSWAC,_DAT_0080bda0));
  _DAT_0080bd94 = FUN_00010da4(CONCAT22(CRCNDTRF,_DAT_0080bda2));
  return;
}



//
// Function: FUN_00010f08 @ 0x00010f08
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010f08(void)

{
  int iVar1;
  undefined2 uVar2;
  
  _DAT_0080bd8c = fsmxthfl_calc_input;
  _DAT_00800218 = CRACSWAC;
  uVar2 = 0x80;
  _DAT_0080bda0 = lookupTableInterpolation((short *)&DAT_00800212);
  iVar1 = FUN_00012966(((int)_current_fuel_demand_value - (int)(short)_DAT_0080bd8c) * 0x6400,
                       CONCAT22(the_maximum_speed_a_customer_may_program_to_correspond_with_s_1_5_15
                                - _DAT_0080bda0,uVar2));
  _DAT_0080bd8e = (short)iVar1;
  return;
}



//
// Function: FUN_00010f76 @ 0x00010f76
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010f76(void)

{
  _DAT_008001fe = 2;
  _DAT_00800200 = 0x807f42;
  _DAT_0080020c = 400;
  _DAT_00800206 = 2;
  _DAT_00800208 = 0x807f68;
  _DAT_0080020e = &lower_limitation_of_intake_manifold_temperature_to_inhibit_50_to_293;
  _DAT_0080021e = 2;
  _DAT_00800220 = 0x808862;
  _DAT_00800226 = 0x808876;
  _DAT_00800212 = 2;
  _DAT_00800214 = 0x80883a;
  _DAT_0080021a = 0x80884e;
  FUN_00010e02();
  return;
}



//
// Function: FUN_00010fee @ 0x00010fee
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010fee(undefined4 param_1)

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
    if (((*(int *)(&ivs_switch_status_when_throttle_validation_process_error_true_false +
                  (short)((param_1._0_2_ & 0xff) * 5)) == 0) &&
        (*(uint *)(iVar1 + 0x806354) <=
         loopCounter - *(int *)((short)((param_1._0_2_ & 0xff) * 5) * 2 + 0x804fc4))) ||
       ((*(int *)(&ivs_switch_status_when_throttle_validation_process_error_true_false +
                 (short)((param_1._0_2_ & 0xff) * 5)) != 0 &&
        (*(uint *)(iVar1 + 0x806358) <=
         loopCounter -
         *(int *)(&ivs_switch_status_when_throttle_validation_process_error_true_false +
                 (short)((param_1._0_2_ & 0xff) * 5)))))) {
      sVar2 = (param_1._0_2_ & 0xff) * 10;
      *(dword *)((int)&ivs_switch_status_when_throttle_validation_process_error_true_false +
                (int)sVar2) = loopCounter;
      if ((&DAT_00804fcd)[sVar2] != '\0') {
        (&DAT_00804fcd)[sVar2] = (&DAT_00804fcd)[sVar2] + -1;
      }
      if ((&DAT_00804fcd)[sVar2] == '\0') {
        FUN_00027ef0(CONCAT22(param_1._0_2_,(short)((uint)unaff_D2 >> 0x10)) & 0xffffff);
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
// Function: FUN_000111a2 @ 0x000111a2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000111a2(void)

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
  FUN_00010fee(CONCAT22(CONCAT11((char)(uVar1 >> 8),(char)unaff_D2),(short)uVar2));
  return;
}



//
// Function: FUN_000111de @ 0x000111de
//

short FUN_000111de(undefined4 param_1)

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
// Function: FUN_0001124a @ 0x0001124a
//

void FUN_0001124a(undefined4 param_1)

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
      FUN_00027f4c(CONCAT22(sVar2,param_1._0_2_));
      return;
    }
    sVar3 = sVar3 + 0x30;
    sVar2 = sVar2 + 1;
  } while (sVar2 < 0x14);
  sVar2 = 0;
  sVar3 = 0;
  do {
    if (*(short *)(&DAT_00805676 + sVar3) == 0x7d) {
      FUN_00027f4c(CONCAT22(sVar2,param_1._0_2_));
      return;
    }
    sVar3 = sVar3 + 0x30;
    sVar2 = sVar2 + 1;
  } while (sVar2 < 0x14);
  uVar1 = FUN_000111de(CONCAT22(2,uVar4));
  if (uVar1 < 0x14) {
    sVar2 = *(short *)(&DAT_00805676 + (short)(uVar1 * 6) * 8);
    FUN_00027f4c(CONCAT22(uVar1,param_1._0_2_));
    *(undefined1 *)((short)(sVar2 * 5) * 2 + 0x804fcc) = 0;
    return;
  }
  uVar1 = FUN_000111de(CONCAT22(3,uVar4));
  if (uVar1 < 0x14) {
    sVar2 = *(short *)(&DAT_00805676 + (short)(uVar1 * 6) * 8);
    FUN_00027f4c(CONCAT22(uVar1,param_1._0_2_));
    *(undefined1 *)((short)(sVar2 * 5) * 2 + 0x804fcc) = 1;
  }
  return;
}



//
// Function: FUN_0001133c @ 0x0001133c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001133c(void)

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
        FUN_00027ef0(CONCAT22(_DAT_0080d492,uVar4));
      }
    }
    _DAT_0080d492 = 0;
    return;
  }
  if (_DAT_0080d492 == 0) {
    for (bVar3 = 1; bVar3 <= DAT_00804e9c; bVar3 = bVar3 + 1) {
      FUN_00027ef0((uint)CONCAT12((&DAT_00804e9c)[(short)(ushort)bVar3],uVar4));
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
// Function: FUN_0001147c @ 0x0001147c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001147c(void)

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
        FUN_00027ef0((uint)CONCAT12((&DAT_00804e9c)[(short)(ushort)bVar3],uVar4));
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
    FUN_00027ef0((uint)CONCAT12((&DAT_00804e9c)[(short)(ushort)bVar3],uVar4));
  }
  DAT_00804e9c = 0;
  _DAT_00804efc = 0;
  _DAT_00804f3e = 0;
  _DAT_00804f42 = 0;
  _DAT_0080d492 = 0;
  return;
}



//
// Function: FUN_000115b2 @ 0x000115b2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000115b2(void)

{
  int iVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  bool bVar5;
  undefined4 unaff_D2;
  byte bVar6;
  ushort uVar7;
  ushort uVar8;
  undefined2 uVar9;
  
  uVar9 = (undefined2)((uint)unaff_D2 >> 0x10);
  uVar2 = *(ushort *)(&DAT_00805df2 + _DAT_00800232 * 2);
  uVar3 = *(ushort *)(&DAT_00805e32 + _DAT_00800232 * 2);
  *(undefined2 *)(&DAT_00805e32 + _DAT_00800232 * 2) = 0;
  uVar7 = 1;
  uVar8 = 0;
  do {
    if ((uVar7 & (uVar3 | uVar2)) == 0) {
      if (((((uVar7 & *(ushort *)(&DAT_00805e72 + _DAT_00800232 * 2)) != 0) &&
           (uVar4 = *(ushort *)((short)(uVar8 + _DAT_00800232 * 0x10) * 2 + 0x806374), uVar4 < 0x7d)
           ) && ((uVar7 & *(ushort *)(&DAT_008068c4 + _DAT_00800232 * 2)) != 0)) &&
         ((*(char *)((short)uVar4 + 0x804f46) != '\0' &&
          (*(char *)((short)uVar4 + 0x804f46) = *(char *)((short)uVar4 + 0x804f46) + -1,
          *(char *)((short)uVar4 + 0x804f46) == '\0')))) {
        *(undefined1 *)((short)(uVar4 * 5) * 2 + 0x804fcc) = 2;
        *(dword *)((short)(uVar4 * 5) * 2 + 0x804fc4) = loopCounter;
        bVar5 = false;
        bVar6 = 0;
        while (!bVar5) {
          bVar6 = bVar6 + 1;
          if ((uint)DAT_00804e7c == bVar6 - 1) {
            bVar5 = true;
          }
          else if ((&DAT_00804e7c)[(short)(ushort)bVar6] == uVar4) {
            bVar5 = true;
            if (((&DAT_008065d0)[(uint)uVar4 * 6] != '\0') &&
               ((*(ushort *)(&DAT_008065ce + (uint)uVar4 * 6) & 0x40) == 0)) {
              _DAT_00804f40 = _DAT_00804f40 + -1;
              FUN_00017ca6(&hour_meter_ecm_run_time_none,CONCAT22(uVar4,uVar9) & 0xffffff);
            }
            DAT_00804e7c = DAT_00804e7c - 1;
            _DAT_00804ebc = _DAT_00804ebc + -1;
            (&DAT_00804e7c)[(short)(ushort)bVar6] = (&DAT_00804e7c)[_DAT_00804f3c];
            iVar1 = (int)_DAT_00804f3c;
            _DAT_00804f3c = _DAT_00804f3c + -1;
            *(undefined2 *)(&DAT_00804ebc + (short)(ushort)bVar6 * 2) =
                 *(undefined2 *)(&DAT_00804ebc + iVar1 * 2);
          }
        }
        if (DAT_00804e9c != 0x1f) {
          DAT_00804e9c = DAT_00804e9c + 1;
          _DAT_00804efc = _DAT_00804efc + 1;
          _DAT_00804f3e = _DAT_00804f3e + 1;
          (&DAT_00804e9c)[_DAT_00804f3e] = (char)uVar4;
          *(undefined2 *)(&DAT_00804efc + _DAT_00804f3e * 2) =
               *(undefined2 *)(&DAT_008065cc + (uint)uVar4 * 6);
          if (((&DAT_008065d0)[(uint)uVar4 * 6] != '\0') &&
             ((*(ushort *)(&DAT_008065ce + (uint)uVar4 * 6) & 0x40) == 0)) {
            _DAT_00804f42 = _DAT_00804f42 + 1;
          }
        }
        _DAT_00804f44 = _DAT_00804f44 + -1;
      }
    }
    else {
      uVar4 = *(ushort *)((short)(uVar8 + _DAT_00800232 * 0x10) * 2 + 0x806374);
      if ((((uVar4 < 0x7d) && ((uVar7 & *(ushort *)(&DAT_00805e72 + _DAT_00800232 * 2)) == 0)) &&
          (DAT_00804e7c != 0x1f)) && ((uVar7 & *(ushort *)(&DAT_008068c4 + _DAT_00800232 * 2)) != 0)
         ) {
        if ((&DAT_00804fcd)[(short)(uVar4 * 5) * 2] != -1) {
          (&DAT_00804fcd)[(short)(uVar4 * 5) * 2] = (&DAT_00804fcd)[(short)(uVar4 * 5) * 2] + '\x01'
          ;
        }
        if (*(char *)((short)uVar4 + 0x804f46) == '\0') {
          FUN_0001124a(CONCAT22(uVar4,uVar9));
          *(undefined1 *)((short)(uVar4 * 5) * 2 + 0x804fcc) = 3;
          *(dword *)((short)(uVar4 * 5) * 2 + 0x804fc4) = loopCounter;
          (&ivs_switch_status_when_throttle_validation_process_error_true_false + (short)(uVar4 * 5)
          )[0] = 0;
          (&ivs_switch_status_when_throttle_validation_process_error_true_false + (short)(uVar4 * 5)
          )[1] = 0;
          bVar5 = false;
          bVar6 = 0;
          while (!bVar5) {
            bVar6 = bVar6 + 1;
            if ((uint)DAT_00804e9c == bVar6 - 1) {
              bVar5 = true;
            }
            else if ((&DAT_00804e9c)[(short)(ushort)bVar6] == uVar4) {
              bVar5 = true;
              if (((&DAT_008065d0)[(uint)uVar4 * 6] != '\0') &&
                 ((*(ushort *)(&DAT_008065ce + (uint)uVar4 * 6) & 0x40) == 0)) {
                _DAT_00804f42 = _DAT_00804f42 + -1;
              }
              DAT_00804e9c = DAT_00804e9c - 1;
              _DAT_00804efc = _DAT_00804efc + -1;
              (&DAT_00804e9c)[(short)(ushort)bVar6] = (&DAT_00804e9c)[_DAT_00804f3e];
              iVar1 = (int)_DAT_00804f3e;
              _DAT_00804f3e = _DAT_00804f3e + -1;
              *(undefined2 *)(&DAT_00804efc + (short)(ushort)bVar6 * 2) =
                   *(undefined2 *)(&DAT_00804efc + iVar1 * 2);
            }
          }
          DAT_00804e7c = DAT_00804e7c + 1;
          _DAT_00804ebc = _DAT_00804ebc + 1;
          _DAT_00804f3c = _DAT_00804f3c + 1;
          (&DAT_00804e7c)[_DAT_00804f3c] = (char)uVar4;
          *(undefined2 *)(&DAT_00804ebc + _DAT_00804f3c * 2) =
               *(undefined2 *)(&DAT_008065cc + (uint)uVar4 * 6);
          if (((&DAT_008065d0)[(uint)uVar4 * 6] != '\0') &&
             ((*(ushort *)(&DAT_008065ce + (uint)uVar4 * 6) & 0x40) == 0)) {
            _DAT_00804f40 = _DAT_00804f40 + 1;
            FUN_00017ca6(&hour_meter_ecm_run_time_none,
                         (uint)(uint3)(CONCAT12((char)uVar4,uVar9) | 0x800000));
          }
          _DAT_00804f44 = _DAT_00804f44 + 1;
        }
        if (*(char *)((short)uVar4 + 0x804f46) != -1) {
          *(char *)((short)uVar4 + 0x804f46) = *(char *)((short)uVar4 + 0x804f46) + '\x01';
        }
      }
    }
    uVar7 = uVar7 * 2;
    uVar8 = uVar8 + 1;
  } while (uVar8 < 0x10);
  *(ushort *)(&DAT_00805e72 + _DAT_00800232 * 2) = uVar3 | uVar2;
  return;
}



//
// Function: FUN_00011a0a @ 0x00011a0a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00011a0a(void)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  ushort *puVar4;
  
  for (iVar2 = 0;
      (((*(short *)(&DAT_00805df2 + (short)_DAT_00800232 * 2) == 0 &&
        (*(short *)(&DAT_00805e32 + (short)_DAT_00800232 * 2) == 0)) &&
       (*(short *)(&DAT_00805e72 + (short)_DAT_00800232 * 2) == 0)) && (iVar2 < 0x20));
      iVar2 = iVar2 + 1) {
    _DAT_00800232 = _DAT_00800232 + 1;
    if (0x1f < _DAT_00800232) {
      _DAT_00800232 = 0;
    }
  }
  if (iVar2 < 0x20) {
    FUN_000115b2();
    _DAT_00800232 = _DAT_00800232 + 1;
    if (0x1f < _DAT_00800232) {
      _DAT_00800232 = 0;
    }
  }
  if ((_DAT_0080d48c & 1) == 0) {
    if ((_DAT_0080d48c & 2) != 0) {
      FUN_0001147c();
      _DAT_0080d48c = 0;
    }
  }
  else {
    FUN_0001133c();
    _DAT_0080d48c = 0;
  }
  if (0x18 < loopCounter - _DAT_0080022c) {
    uVar1 = 1;
    uVar3 = 0;
    puVar4 = (ushort *)&DAT_008077c8;
    do {
      if (((uint)(&vp44_communication_status)[(int)(uint)*puVar4 >> 3] & 1 << (*puVar4 & 7)) == 0) {
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
      if (((uint)(&vp44_communication_status)[(int)(uint)*puVar4 >> 3] & 1 << (*puVar4 & 7)) == 0) {
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
      if (((uint)(&vp44_communication_status)[(int)(uint)*puVar4 >> 3] & 1 << (*puVar4 & 7)) == 0) {
        _DAT_0080bdc4 = ~uVar1 & _DAT_0080bdc4;
      }
      else {
        _DAT_0080bdc4 = uVar1 | _DAT_0080bdc4;
      }
      uVar1 = uVar1 * 2;
      puVar4 = puVar4 + 1;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x10);
    FUN_000111a2();
    _DAT_0080022c = loopCounter;
  }
  return;
}



//
// Function: FUN_00011ba0 @ 0x00011ba0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00011ba0(undefined4 param_1)

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
// Function: FUN_00011c0c @ 0x00011c0c
//

void FUN_00011c0c(void)

{
  undefined2 in_stack_00000000;
  
  FUN_00017d1a(&hour_meter_ecm_run_time_none,0x80bdb6,CONCAT22(10,in_stack_00000000));
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
  local_c = CONCAT13((undefined1)sim_ddir,local_c._1_3_);
  local_10 = (uint)(byte)sim_picr;
  vp44_status_buffer_start = DAT_00ffd000;
  vp44_status_byte1 = DAT_00ffd001;
  vp44_status_byte2 = DAT_00ffd002;
  vp44_status_byte3 = DAT_00ffd003;
  vp44_status_byte4 = DAT_00ffd005;
  vp44_status_byte5 = DAT_00ffd007;
  vp44_status_byte6 = 0;
  vp44_status_byte7 = (undefined1)sim_ddir;
  vp44_status_byte8 = (byte)sim_picr;
  *(uint *)(&vp44_status_array_0 + (short)(ushort)vp44_buffer_index * 4) =
       _vp44_xor_mask_1 ^ local_8;
  *(uint *)(&vp44_extended_array_0 + (short)(ushort)vp44_buffer_index * 4) =
       _vp44_xor_mask_2 ^ local_c;
  *(uint *)(&vp44_third_array_0 + (short)(ushort)vp44_buffer_index * 4) =
       _high_limit_for_cruise_rsg_error_delta_0_255 ^ local_10;
  if ((_vp44_flag_register_1 & 0x400) != 0) {
    *(uint *)(&vp44_status_array_0 + (short)(ushort)vp44_buffer_index * 4) =
         *(uint *)(&vp44_status_array_0 + (short)(ushort)vp44_buffer_index * 4) ^ 0x400;
  }
  if ((_vp44_flag_register_1 & 0x800) != 0) {
    *(uint *)(&vp44_status_array_0 + (short)(ushort)vp44_buffer_index * 4) =
         *(uint *)(&vp44_status_array_0 + (short)(ushort)vp44_buffer_index * 4) ^ 0x800;
  }
  if ((_vp44_flag_register_2 & 1) != 0) {
    *(uint *)(&vp44_status_array_0 + (short)(ushort)vp44_buffer_index * 4) =
         *(uint *)(&vp44_status_array_0 + (short)(ushort)vp44_buffer_index * 4) ^ 2;
  }
  if ((_vp44_flag_register_2 & 2) != 0) {
    *(uint *)(&vp44_status_array_0 + (short)(ushort)vp44_buffer_index * 4) =
         *(uint *)(&vp44_status_array_0 + (short)(ushort)vp44_buffer_index * 4) ^ 4;
  }
  if ((_vp44_flag_register_2 & 4) != 0) {
    *(uint *)(&vp44_status_array_0 + (short)(ushort)vp44_buffer_index * 4) =
         *(uint *)(&vp44_status_array_0 + (short)(ushort)vp44_buffer_index * 4) ^ 8;
  }
  uVar2 = _vp44_status_array_3 | _vp44_status_array_2 | _vp44_status_array_1 | _vp44_status_array_0;
  uVar1 = _vp44_status_array_3 & _vp44_status_array_2 & _vp44_status_array_1 & _vp44_status_array_0;
  local_8._3_1_ = (byte)uVar2;
  local_c._3_1_ = (byte)uVar1;
  vp44_communication_status =
       ((byte)local_c | (byte)local_8 & vp44_communication_status) & ~_vp44_mask_array[1] |
       vp44_forced_status_1 & _vp44_mask_array[1];
  local_8._2_1_ = (byte)(uVar2 >> 8);
  local_c._2_1_ = (byte)(uVar1 >> 8);
  DAT_0080bdc7 = *_vp44_mask_array & vp44_forced_status_2 |
                 ~*_vp44_mask_array & (local_c._2_1_ | local_8._2_1_ & DAT_0080bdc7);
  local_8._1_1_ = (byte)(uVar2 >> 0x10);
  local_c._1_1_ = (byte)(uVar1 >> 0x10);
  DAT_0080bdc8 = (local_c._1_1_ | local_8._1_1_ & DAT_0080bdc8) & ~_vp44_mask_array[3] |
                 vp44_forced_status_3 & _vp44_mask_array[3];
  local_8._0_1_ = (byte)(uVar2 >> 0x18);
  local_c._0_1_ = (byte)(uVar1 >> 0x18);
  DAT_0080bdc9 = vp44_forced_status_4 & _vp44_mask_array[2] |
                 ~_vp44_mask_array[2] & (local_c._0_1_ | local_8._0_1_ & DAT_0080bdc9);
  uVar2 = _vp44_extended_array_3 |
          _vp44_extended_array_2 | _vp44_extended_array_1 | _vp44_extended_array_0;
  uVar1 = _vp44_extended_array_3 &
          _vp44_extended_array_2 & _vp44_extended_array_1 & _vp44_extended_array_0;
  local_8._3_1_ = (byte)uVar2;
  local_c._3_1_ = (byte)uVar1;
  DAT_0080bdca = ((byte)local_c | (byte)local_8 & DAT_0080bdca) & ~_vp44_mask_array[5] |
                 vp44_forced_status_5 & _vp44_mask_array[5];
  local_8._2_1_ = (byte)(uVar2 >> 8);
  local_c._2_1_ = (byte)(uVar1 >> 8);
  DAT_0080bdcb = vp44_forced_status_6 & _vp44_mask_array[4] |
                 ~_vp44_mask_array[4] & (local_c._2_1_ | local_8._2_1_ & DAT_0080bdcb);
  if (_vp44_extended_processing_enable != 0) {
    local_8._1_1_ = (byte)(uVar2 >> 0x10);
    local_c._1_1_ = (byte)(uVar1 >> 0x10);
    sensor_status_register =
         (local_c._1_1_ | local_8._1_1_ & sensor_status_register) & ~_vp44_mask_array[7] |
         DAT_00803790 & _vp44_mask_array[7];
  }
  local_8._0_1_ = (byte)(uVar2 >> 0x18);
  local_c._0_1_ = (byte)(uVar1 >> 0x18);
  DAT_0080bdcd = (local_c._0_1_ | local_8._0_1_ & DAT_0080bdcd) & ~_vp44_mask_array[6] |
                 DAT_00803791 & _vp44_mask_array[6];
  local_8 = _DAT_00800270 | _DAT_0080026c | _DAT_00800268 | _vp44_third_array_0;
  local_c = _DAT_00800270 & _DAT_0080026c & _DAT_00800268 & _vp44_third_array_0;
  DAT_0080bdce = ((byte)local_c | (byte)local_8 & DAT_0080bdce) & ~_vp44_mask_array[9] |
                 DAT_00803792 & _vp44_mask_array[9];
  if ((_DAT_00800234 != 0) && ((vp44_communication_status & 1) == 0)) {
    local_12 = _DAT_00803678 + 1;
    FUN_00013144(0x803678,(undefined1 *)&local_12,CONCAT22(2,(short)((uint)unaff_D2 >> 0x10)));
  }
  _DAT_00800234 = (byte)-((vp44_communication_status & 1) != 0) & 1;
  if (_vp44_extended_processing_enable != 0) {
    if ((vp44_communication_status & 8) == 0) {
      sensor_status_register = sensor_status_register & 0xef;
    }
    else {
      sensor_status_register = sensor_status_register | 0x10;
    }
    if ((vp44_communication_status & 4) == 0) {
      sensor_status_register = sensor_status_register & 0xfb;
    }
    else {
      sensor_status_register = sensor_status_register | 4;
    }
    if ((vp44_communication_status & 2) == 0) {
      sensor_status_register = sensor_status_register & 0xfe;
    }
    else {
      sensor_status_register = sensor_status_register | 1;
    }
    if (((vp44_communication_status & 2) == 0) || ((vp44_communication_status & 4) == 0)) {
      sensor_status_register = sensor_status_register & 0xdf;
    }
    else {
      sensor_status_register = sensor_status_register & 0xfa | 0x20;
    }
    if ((vp44_communication_status & 4) == 0) {
      _DAT_00800236 = 0;
      if (_DAT_0080374c == 1) {
        sensor_status_register = sensor_status_register & 0xfd;
      }
      else {
        sensor_status_register = sensor_status_register & 0xf7;
      }
    }
    else {
      _DAT_00800236 = _DAT_00800236 + 1;
      if ((0x18 < _DAT_00800236) && (_DAT_00800236 = 0x19, (sensor_status_register & 0x20) == 0)) {
        if (_DAT_0080374c == 1) {
          sensor_status_register = sensor_status_register | 2;
        }
        else {
          sensor_status_register = sensor_status_register | 8;
        }
      }
    }
    if ((vp44_communication_status & 2) == 0) {
      _DAT_00800238 = 0;
      if (_DAT_0080374c == 1) {
        sensor_status_register = sensor_status_register & 0xf7;
      }
      else {
        sensor_status_register = sensor_status_register & 0xfd;
      }
    }
    else {
      _DAT_00800238 = _DAT_00800238 + 1;
      if ((0x18 < _DAT_00800238) && (_DAT_00800238 = 0x19, (sensor_status_register & 0x20) == 0)) {
        if (_DAT_0080374c == 1) {
          sensor_status_register = sensor_status_register | 8;
        }
        else {
          sensor_status_register = sensor_status_register | 2;
        }
      }
    }
  }
  if (((DAT_0080bdc9 & 1) != 0) == ((DAT_0080bdc8 & 0x20) != 0)) {
    _DAT_0080023a = _DAT_0080023a + 1;
    if (0x31 < _DAT_0080023a) {
      _engine_fault_register_a = _engine_fault_register_a | 0x800;
      _engine_fault_register_c = _engine_fault_register_c | 0x800;
    }
  }
  else {
    _DAT_0080023a = 0;
    if (((_engine_fault_register_a & 0x800) != 0) && ((_engine_fault_register_c & 0x800) == 0)) {
      _engine_fault_register_a = _engine_fault_register_a & 0xf7ff;
    }
  }
  if (((DAT_0080bdc7 & 0x20) == 0) || ((DAT_0080bdc7 & 0x40) == 0)) {
    _DAT_0080023c = 0;
    if (((_DAT_00805e00 & 2) != 0) && ((_DAT_00805e40 & 2) == 0)) {
      _DAT_00805e00 = _DAT_00805e00 & 0xfffd;
    }
  }
  else {
    _DAT_0080023c = _DAT_0080023c + 1;
    if (0x31 < _DAT_0080023c) {
      _DAT_00805e00 = _DAT_00805e00 | 2;
      _DAT_00805e40 = _DAT_00805e40 | 2;
    }
  }
  FUN_00012482();
  if ((_vp44_flag_register_1 & 0x10) == 0) {
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
  vp44_buffer_index = vp44_buffer_index + 1;
  if (3 < vp44_buffer_index) {
    vp44_buffer_index = 0;
  }
  return _vp44_flag_register_1 & 0x10;
}



//
// Function: ioControlAndCanPinSwitching @ 0x000122d0
//

void ioControlAndCanPinSwitching(void)

{
  SIM_CAN_CONTROL_PORT_1 = io_control_source_register;
  SIM_CAN_CONTROL_PORT_2 = io_control_flags & 0xfe | ~io_control_flags & 1;
  sim_ddir._1_1_ = sim_data_direction_control;
  if ((~can_pin_switching_control_flags & 0x20) == 0) {
    can1_canidar2 = can1_canidar2 & 0xf3ff | 0x800;
  }
  else {
    can1_canidar2 = can1_canidar2 & 0xf3ff | 0x400;
  }
  return;
}



//
// Function: FUN_00012356 @ 0x00012356
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00012356(void)

{
  byte bVar1;
  
  _vp44_mask_array = 0x8035ee;
  bVar1 = 0;
  do {
    vp44_status_data_collector();
    bVar1 = bVar1 + 1;
  } while (bVar1 < 4);
  return;
}



//
// Function: FUN_00012376 @ 0x00012376
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00012376(void)

{
  DAT_00ffd008 = 0xf;
  DAT_00ffd009 = 0x80;
  DAT_00ffd00a = 0x80;
  SIM_CAN_CONTROL_PORT_1 = 0;
  sim_data_direction_control = sim_data_direction_control | 0x10;
  can1_cantbsel = can1_cantbsel & 0xdfff;
  can1_canidmr2 = can1_canidmr2 & 0xdfff;
  can1_canidac = can1_canidac & 0xff0f | 0xe0;
  _DAT_00ffffd0 = 0x113;
  can1_canidmr0 = can1_canidmr0 & 0xf3ff | 0x400;
  do {
  } while ((_DAT_00ffffd2 & 0x8000) != 0);
  do {
  } while ((_DAT_00ffffd2 & 0x8000) == 0);
  do {
  } while ((_DAT_00ffffd2 & 0x8000) != 0);
  SIM_CAN_CONTROL_PORT_2 = SIM_CAN_CONTROL_PORT_2 & 0x7f | 0x80;
  can1_canidar2 = can1_canidar2 & 0xf3ff | 0x400;
  can_pin_switching_control_flags = can_pin_switching_control_flags | 0x20;
  io_control_source_register = io_control_source_register & 0xfa | 0x80;
  io_control_flags = io_control_flags | 1;
  DAT_0080bdf1 = DAT_0080bdf1 | 1;
  ioControlAndCanPinSwitching();
  return;
}



//
// Function: FUN_00012482 @ 0x00012482
//

void FUN_00012482(void)

{
  return;
}



//
// Function: FUN_00012484 @ 0x00012484
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00012484(void)

{
  char cVar1;
  undefined1 uVar2;
  char cVar3;
  ushort uVar4;
  uint uVar5;
  char cVar7;
  undefined4 uVar6;
  undefined4 unaff_D2;
  byte bVar8;
  undefined1 *puVar9;
  undefined2 uVar10;
  ushort uVar11;
  ushort uVar12;
  undefined2 local_18;
  undefined1 auStack_16 [10];
  undefined4 local_c;
  undefined4 local_8;
  
  uVar4 = hardware_timer_register._0_2_;
  uVar12 = (ushort)((uint)unaff_D2 >> 0x10);
  if ((DAT_0080d406 != '\0') && (uVar5 = FUN_00013134(), (char)uVar5 != '\0')) {
    DAT_0080d406 = '\0';
    FUN_0000a626((uint)uVar12);
  }
  do {
    if ((499 < (int)((uint)hardware_timer_register._0_2_ - (uint)uVar4)) ||
       ((_DAT_0080d2c2 == _enables_input_of_eps_period_data_to_pptb_0_1 && (DAT_0080d2ce != '\x01'))
       )) {
      return;
    }
    cVar1 = *_enables_input_of_eps_period_data_to_pptb_0_1;
    local_8._3_1_ = (char)_enables_input_of_eps_period_data_to_pptb_0_1;
    cVar7 = (char)local_8;
    local_8._0_3_ = (undefined3)((uint)_enables_input_of_eps_period_data_to_pptb_0_1 >> 8);
    local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
    if (*local_8 < 8) {
      if ((_DAT_008035ea & 1) != 0) {
        switch(*local_8) {
        case 3:
          local_8 = (byte *)CONCAT31(local_8._0_3_,cVar7 + '\x02');
          bVar8 = 0;
          puVar9 = auStack_16;
          do {
            *puVar9 = *local_8;
            local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
            bVar8 = bVar8 + 1;
            puVar9 = puVar9 + 1;
          } while (bVar8 < 10);
          cVar7 = systemSecurityCheck();
          if (cVar7 == '\0') {
            switch(*local_8) {
            case 0x40:
              cVar7 = FUN_0000f89c();
              break;
            case 0x41:
              cVar7 = FUN_0000f8b6();
              break;
            case 0x42:
              cVar7 = FUN_0000f8d8();
              break;
            case 0x43:
              cVar7 = FUN_0000f8f6();
              break;
            default:
              cVar7 = '\x18';
              break;
            case 0x50:
              cVar7 = '\0';
              break;
            case 0x51:
              uVar5 = memoryPatchingSystem();
              cVar7 = (char)uVar5;
              break;
            case 0x52:
              cVar7 = FUN_0000f9e4();
              break;
            case 0x53:
              cVar7 = '\x04';
              break;
            case 0x54:
              uVar6 = canMessageBufferLogger();
              cVar7 = (char)uVar6;
            }
            if (cVar7 != -1) {
              FUN_0000a626((uint)CONCAT12(cVar7,uVar12));
            }
          }
          else {
            FUN_0000a626(CONCAT22(3,uVar12));
          }
          break;
        case 4:
          local_8 = (byte *)CONCAT31(local_8._0_3_,cVar7 + '\x02');
          switch(*local_8) {
          case 100:
            FUN_00025768();
            break;
          case 0x65:
            uVar11 = 0;
            FUN_0000f86a();
            FUN_0000a626((uint)uVar11);
            break;
          case 0x66:
            _DAT_00809d3e = 0;
            FUN_0000a626((uint)uVar12);
            break;
          default:
            FUN_0000a626(CONCAT22(0x18,uVar12));
            break;
          case 0x69:
            uVar10 = 0;
            uVar5 = FUN_0000f876();
            FUN_0000a626((uint)CONCAT12((char)uVar5,uVar10));
            break;
          case 0x70:
          case 0x72:
          case 0x76:
            FUN_0000a626(CONCAT22(4,uVar12));
            break;
          case 0x71:
            _DAT_00809d3e = _DAT_00809d3e | 1;
            FUN_0000a626((uint)uVar12);
            break;
          case 0x73:
            _DAT_00809d3e = _DAT_00809d3e | 2;
            FUN_0000a626((uint)uVar12);
            break;
          case 0x74:
            FUN_0002588c();
            break;
          case 0x75:
            FUN_000258aa();
          }
          break;
        case 5:
          local_8 = (byte *)CONCAT31(local_8._0_3_,cVar7 + '\x02');
          if (((*local_8 & 0xf) == 0) && ((*local_8 & 0xf0) != 0xf0)) {
            cVar3 = cVar1 + -1 + cVar7;
            local_c = (undefined1 *)CONCAT31(local_8._0_3_,cVar3);
            uVar2 = *local_c;
            local_c = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x01');
            local_18 = CONCAT11(*local_c,uVar2);
            local_c = (undefined1 *)CONCAT31(local_8._0_3_,cVar7 + '\x03');
            uVar6 = FUN_0000fcb0((byte *)CONCAT22((short)((uint)
                                                  _enables_input_of_eps_period_data_to_pptb_0_1 >>
                                                  0x10),(short)local_c),
                                 (uint)CONCAT12(cVar1 + -4,uVar12));
            if ((short)uVar6 != local_18) {
              FUN_0000a626(CONCAT22(0x14,uVar12));
              break;
            }
          }
          bVar8 = *local_8 & 0xf0;
          if (bVar8 == 0x60) {
            FUN_00019e62(CONCAT22(3,uVar12));
          }
          else if (bVar8 == 0xc0) {
            FUN_00019e62(CONCAT22(2,uVar12));
          }
          else if (bVar8 == 0x80) {
            FUN_00019cf0(CONCAT22(4,uVar12));
          }
          else if (bVar8 == 0xe0) {
            FUN_00019e62(CONCAT22(1,uVar12));
          }
          else if (bVar8 == 0xa0) {
            FUN_00019cf0(CONCAT22(2,uVar12));
          }
          else if (bVar8 == 0xf0) {
            FUN_00012b74();
          }
          else if (bVar8 == 0xb0) {
            FUN_00012d76();
          }
          else {
            FUN_0000a626(CONCAT22(4,uVar12));
          }
          break;
        case 6:
          local_8 = (byte *)CONCAT31(local_8._0_3_,cVar7 + '\x02');
          if ((*local_8 == 't') && (DAT_0080d2db != '\0')) {
            FUN_0000a626(CONCAT22(1,uVar12));
            DAT_0080d2db = DAT_0080d2db + -1;
            DAT_0080d404 = 0;
            if (DAT_0080d405 != '\0') {
              FUN_0000e1ce();
              DAT_0080d405 = '\0';
            }
          }
        }
      }
    }
    else if (*local_8 < 0x80) {
      if (((0x44 < *local_8) && (*local_8 < 0x57)) && ((_DAT_008035ea & 4) != 0)) {
        switch(*local_8) {
        case 0x4a:
          FUN_0001a5b0();
          break;
        case 0x4c:
          FUN_0001a910();
          break;
        case 0x4f:
          FUN_0001a97e();
          break;
        case 0x51:
          FUN_0001ac64();
        }
      }
    }
    else if ((_DAT_008035ea & 2) != 0) {
      FUN_00019a0a();
    }
    _enables_input_of_eps_period_data_to_pptb_0_1 =
         (char *)CONCAT31(_enables_input_of_eps_period_data_to_pptb_0_1,
                          cVar1 + '\x01' + DAT_0080d2cd);
    DAT_0080d2ce = '\0';
    tpu_cier = tpu_cier | 0x20;
  } while( true );
}



//
// Function: FUN_00012966 @ 0x00012966
//

int FUN_00012966(uint param_1,int param_2)

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
// Function: FUN_00012a26 @ 0x00012a26
//

uint FUN_00012a26(uint param_1,uint param_2,int param_3)

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
// Function: FUN_00012b30 @ 0x00012b30
//

uint FUN_00012b30(uint param_1,uint param_2,undefined4 param_3)

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
// Function: FUN_00012b74 @ 0x00012b74
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00012b74(void)

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
  if (*_enables_input_of_eps_period_data_to_pptb_0_1 == '\x06') {
    local_8._3_1_ = (char)_enables_input_of_eps_period_data_to_pptb_0_1;
    cVar4 = (char)local_8;
    local_8._0_3_ = (undefined3)((uint)_enables_input_of_eps_period_data_to_pptb_0_1 >> 8);
    local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x03');
    uVar1 = *local_8;
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar4 + '\x04');
    _DAT_0080d3f8 = CONCAT11(*local_8,uVar1);
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar4 + '\x05');
    cVar7 = FUN_0000eaf0(0x80);
    if (cVar7 == '\0') {
      bVar9 = *local_8;
      local_8 = (byte *)CONCAT31(local_8._0_3_,cVar4 + '\x06');
      _DAT_0080d400 = CONCAT11(*local_8,bVar9);
      if (_DAT_0080d400 < 0xf) {
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
        uVar6 = addressRangeValidator((uint)_DAT_0080d3fa,CONCAT22(_DAT_0080d400,uVar11));
        cVar7 = (char)uVar6;
        if ((cVar7 == '\t') || (cVar7 == '\n')) {
          FUN_0000a626((uint)CONCAT12(cVar7,uVar11));
          DAT_0080d404 = 0;
        }
        else {
          *local_c = DAT_0080d3f9;
          local_c = (byte *)CONCAT31(local_c._0_3_,cVar4 + '\x04');
          *local_c = DAT_0080d3f8;
          local_c = (byte *)CONCAT31(local_c._0_3_,cVar4 + '\x05');
          *local_c = DAT_0080d401;
          local_c = (byte *)CONCAT31(local_c._0_3_,cVar4 + '\x06');
          *local_c = DAT_0080d400;
          local_c = (byte *)CONCAT31(local_c._0_3_,cVar4 + '\a');
          for (bVar8 = 0; bVar8 < bVar9; bVar8 = bVar8 + 1) {
            bVar2 = *_DAT_0080d3fa;
            _DAT_0080d3fa = _DAT_0080d3fa + 1;
            *local_c = bVar2;
            local_c = (byte *)CONCAT31(local_c._0_3_,(char)local_c + '\x01');
          }
          _DAT_0080d400 = _DAT_0080d400 - bVar9;
          *pbVar3 = bVar10;
          *local_c = 0;
          _DAT_0080d2b4 = local_c;
          FUN_00013242();
          DAT_0080d404 = 1;
        }
      }
      else {
        DAT_0080d404 = 0;
        FUN_0000a626(CONCAT22(4,uVar11));
        _DAT_00805e00 = _DAT_00805e00 | 4;
        _DAT_00805e40 = _DAT_00805e40 | 4;
      }
    }
    else {
      FUN_0000a626(CONCAT22(8,uVar11));
    }
  }
  else {
    FUN_0000a626(CONCAT22(4,uVar11));
  }
  return;
}



//
// Function: FUN_00012d76 @ 0x00012d76
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00012d76(void)

{
  undefined1 uVar1;
  byte bVar2;
  short sVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  char cVar6;
  undefined4 unaff_D2;
  byte bVar7;
  ushort uVar8;
  undefined2 local_a;
  undefined4 local_8;
  
  uVar8 = (ushort)((uint)unaff_D2 >> 0x10);
  local_8._3_1_ = (char)_enables_input_of_eps_period_data_to_pptb_0_1;
  cVar6 = (char)local_8;
  local_8._0_3_ = (undefined3)((uint)_enables_input_of_eps_period_data_to_pptb_0_1 >> 8);
  local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x02');
  bVar2 = *local_8 & 0xf;
  if (DAT_0080d405 == '\x01') {
    if ((uint)*_enables_input_of_eps_period_data_to_pptb_0_1 - (uint)bVar2 == 4) {
      local_8 = (byte *)CONCAT31(local_8._0_3_,cVar6 + '\x03');
      uVar1 = *local_8;
      local_8 = (byte *)CONCAT31(local_8._0_3_,cVar6 + '\x04');
      local_a = CONCAT11(*local_8,uVar1);
      local_8 = (byte *)CONCAT31(local_8._0_3_,cVar6 + '\x05');
      if (local_a == _DAT_0080d3f8) {
        switch(_DAT_0080d3f8) {
        case 0x15:
        case 0x17:
        case 0x18:
        case 0x19:
          for (bVar7 = 0; bVar7 < bVar2; bVar7 = bVar7 + 1) {
            puVar4 = _DAT_0080d3fa + 1;
            *_DAT_0080d3fa = *local_8;
            _DAT_0080d3fa = puVar4;
            local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
          }
          _DAT_0080d402 = _DAT_0080d402 - bVar2;
          if (_DAT_0080d402 == 0) {
            DAT_0080d405 = '\0';
          }
          break;
        default:
          uVar5 = addressRangeValidator((uint)_DAT_0080d3fa,CONCAT22(_DAT_0080d402,uVar8));
          if (((char)uVar5 == '\x03') || ((char)uVar5 == '\x05')) {
            (&timer_used_to_disable_rsg_when_veh_and_eng_speeds_disagree_0_100)
            [(short)(_memory_patch_count * 3)] =
                 (ushort)bVar2 +
                 (&timer_used_to_disable_rsg_when_veh_and_eng_speeds_disagree_0_100)
                 [(short)(_memory_patch_count * 3)];
            for (bVar7 = 0; bVar7 < bVar2; bVar7 = bVar7 + 1) {
              puVar4 = _DAT_0080d3e2 + 1;
              *_DAT_0080d3e2 = *local_8;
              _DAT_0080d3e2 = puVar4;
              local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
            }
            _DAT_0080d402 = _DAT_0080d402 - bVar2;
            if (_DAT_0080d402 == 0) {
              DAT_0080d405 = '\0';
            }
          }
          else {
            for (bVar7 = 0; bVar7 < bVar2; bVar7 = bVar7 + 1) {
              puVar4 = _DAT_0080d3fa + 1;
              *_DAT_0080d3fa = *local_8;
              _DAT_0080d3fa = puVar4;
              local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
            }
            _DAT_0080d402 = _DAT_0080d402 - bVar2;
            if (_DAT_0080d402 == 0) {
              DAT_0080d405 = '\0';
            }
          }
        }
        FUN_0000a626((uint)uVar8);
      }
      else {
        _memory_patch_count = _memory_patch_count - 1;
        _DAT_0080d3e2 =
             _DAT_0080d3e2 + -(uint)*(ushort *)((short)(_memory_patch_count * 3) * 2 + 0x80d3aa);
        DAT_0080d405 = '\0';
        FUN_0000a626(CONCAT22(4,uVar8));
      }
    }
    else {
      FUN_0000a626(CONCAT22(4,uVar8));
    }
  }
  else if ((uint)*_enables_input_of_eps_period_data_to_pptb_0_1 - (uint)bVar2 == 6) {
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar6 + '\x03');
    uVar1 = *local_8;
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar6 + '\x04');
    _DAT_0080d3f8 = CONCAT11(*local_8,uVar1);
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar6 + '\x05');
    uVar1 = *local_8;
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar6 + '\x06');
    _DAT_0080d402 = CONCAT11(*local_8,uVar1);
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar6 + '\a');
    cVar6 = FUN_0000eaf0(0x80);
    if (cVar6 == '\0') {
      switch(_DAT_0080d3f8) {
      case 0x15:
      case 0x17:
      case 0x18:
      case 0x19:
        for (bVar7 = 0; bVar7 < bVar2; bVar7 = bVar7 + 1) {
          puVar4 = _DAT_0080d3fa + 1;
          *_DAT_0080d3fa = *local_8;
          _DAT_0080d3fa = puVar4;
          local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
        }
        _DAT_0080d402 = _DAT_0080d402 - bVar2;
        if (_DAT_0080d402 != 0) {
          DAT_0080d405 = '\x01';
        }
        break;
      default:
        uVar5 = addressRangeValidator((uint)_DAT_0080d3fa,CONCAT22(_DAT_0080d402,uVar8));
        cVar6 = (char)uVar5;
        if ((cVar6 == '\x05') || (cVar6 == '\x03')) {
          if ((10 < _memory_patch_count + 1) ||
             (0x80d3a5 - (int)_DAT_0080d3e2 <= (int)(uint)_DAT_0080d402)) {
            FUN_0000a626(CONCAT22(0xe,uVar8));
            return;
          }
          *(undefined1 **)
           (&timer_used_to_disable_rsg_when_gear_ratio_changes_0_100 +
           (short)(_memory_patch_count * 3)) = _DAT_0080d3fa;
          sVar3 = _memory_patch_count * 3;
          _memory_patch_count = _memory_patch_count + 1;
          *(ushort *)(sVar3 * 2 + 0x80d3aa) = (ushort)bVar2;
          for (bVar7 = 0; bVar7 < bVar2; bVar7 = bVar7 + 1) {
            puVar4 = _DAT_0080d3e2 + 1;
            *_DAT_0080d3e2 = *local_8;
            _DAT_0080d3e2 = puVar4;
            local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
          }
          _DAT_0080d402 = _DAT_0080d402 - bVar2;
          if (_DAT_0080d402 != 0) {
            DAT_0080d405 = '\x01';
          }
        }
        else {
          if (cVar6 != '\0') {
            if (cVar6 != '\n') {
              FUN_0000a626(CONCAT22(9,uVar8));
              return;
            }
            FUN_0000a626(CONCAT22(10,uVar8));
            return;
          }
          for (bVar7 = 0; bVar7 < bVar2; bVar7 = bVar7 + 1) {
            puVar4 = _DAT_0080d3fa + 1;
            *_DAT_0080d3fa = *local_8;
            _DAT_0080d3fa = puVar4;
            local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
          }
          if (_DAT_0080d402 != 0) {
            DAT_0080d405 = '\x01';
          }
        }
      }
      FUN_0000a626((uint)uVar8);
    }
    else {
      FUN_0000a626(CONCAT22(8,uVar8));
    }
  }
  else {
    FUN_0000a626(CONCAT22(4,uVar8));
  }
  return;
}



//
// Function: FUN_00013134 @ 0x00013134
//

uint FUN_00013134(void)

{
  uint in_D0;
  
  if (circular_buffer_count == 0) {
    return 1;
  }
  return in_D0 & 0xffffff00;
}



//
// Function: FUN_00013144 @ 0x00013144
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00013144(int param_1,undefined1 *param_2,undefined4 param_3)

{
  word wVar1;
  uint uVar2;
  
  if ((uint)param_3._0_2_ + (uint)circular_buffer_count < 0x201) {
    _DAT_0080c402 = (short)(param_1 + -0x8034f6) - 2;
    uVar2 = CONCAT22((short)((uint)(param_1 + -0x8034f6) >> 0x10),_DAT_0080c402);
    (&circular_buffer_metadata)[circular_buffer_write_index] = _DAT_0080c402;
    for (; param_3._0_2_ != 0; param_3._0_2_ = param_3._0_2_ - 1) {
      (&circular_buffer_data)[(short)circular_buffer_write_index] = *param_2;
      wVar1 = (short)(param_1 + -0x8034f6) - 2;
      uVar2 = CONCAT22((short)((uint)(param_1 + -0x8034f6) >> 0x10),wVar1);
      (&circular_buffer_metadata)[circular_buffer_write_index] = wVar1;
      circular_buffer_write_index = circular_buffer_write_index + 1 & 0x1ff;
      circular_buffer_count = circular_buffer_count + 1;
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
// Function: FUN_00013240 @ 0x00013240
//

void FUN_00013240(void)

{
  return;
}



//
// Function: FUN_00013242 @ 0x00013242
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00013242(void)

{
  if (((DAT_0080d2d0 == '\x01') && ((tpu_cfsr0 & 0x20) == 0)) && (DAT_0080d2da == '\0')) {
    tpu_cfsr1 = (word)*_track_the_time_when_throttle_is_less_than_a_threshold_0_30;
    DAT_0080d2da = '\x01';
    _DAT_00fff45a = 0xfc8a;
    _DAT_00fff458 = _DAT_00fff458 & 0x7fff | 0x4000;
    DAT_0080d2d0 = '\0';
    _DAT_0080d2d6 = 0;
    DAT_0080d2d1 = 1;
    DAT_0080d2d3 = *_track_the_time_when_throttle_is_less_than_a_threshold_0_30;
    tpu_cier = tpu_cier | 0x20;
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
  
  if (_engine_fault_timer_1 == 0) {
    if (_engine_rpm_calculation_param_1 != 0) {
      _engine_rpm_calculation_param_1 = 0;
      FUN_00013890();
    }
  }
  else {
    _engine_fault_timer_1 = _engine_fault_timer_1 + -1;
    _engine_rpm_calculation_param_1 = (ushort)(_CRGNSC / _engine_divisor_param_1);
  }
  if (_engine_fault_timer_2 == 0) {
    if (_engine_rpm_calculation_param_2 != 0) {
      _engine_rpm_calculation_param_2 = 0;
      FUN_000138fe();
    }
  }
  else {
    _engine_fault_timer_2 = _engine_fault_timer_2 + -1;
    if ((_engine_system_status_flags & 0xc) != 0) {
      _engine_rpm_calculation_param_2 =
           (ushort)(_engine_calculation_constant_1 / _engine_divisor_param_2);
    }
  }
  if (_engine_fault_timer_3 == 0) {
    if (_engine_rpm_calculation_param_3 != 0) {
      _engine_rpm_calculation_param_3 = 0;
    }
  }
  else {
    _engine_fault_timer_3 = _engine_fault_timer_3 + -1;
  }
  if ((_engine_fault_timer_1 == 0) && (current_engine_rpm != 0)) {
    if (_engine_fault_counter_1 < _engine_fault_threshold_1) {
      _engine_fault_counter_1 = _engine_fault_counter_1 + 1;
    }
    else {
      _engine_fault_status_register_1 = _engine_fault_status_register_1 | 0x1000;
      _engine_fault_status_register_2 = _engine_fault_status_register_2 | 0x1000;
    }
  }
  else if ((_engine_fault_timer_1 != 0) &&
          ((_engine_fault_counter_1 = 0, (_engine_fault_status_register_1 & 0x1000) != 0 &&
           ((_engine_fault_status_register_2 & 0x1000) == 0)))) {
    _engine_fault_status_register_1 = _engine_fault_status_register_1 & 0xefff;
  }
  if ((((_engine_system_status_flags & 0xc) == 0) || (_engine_fault_timer_2 != 0)) ||
     (current_engine_rpm == 0)) {
    if (((_engine_fault_timer_2 != 0) &&
        (_engine_fault_counter_2 = 0, (_engine_fault_status_register_1 & 0x400) != 0)) &&
       ((_engine_fault_status_register_2 & 0x400) == 0)) {
      _engine_fault_status_register_1 = _engine_fault_status_register_1 & 0xfbff;
    }
  }
  else if (_engine_fault_counter_2 < _engine_fault_threshold_2) {
    _engine_fault_counter_2 = _engine_fault_counter_2 + 1;
  }
  else {
    _engine_fault_status_register_1 = _engine_fault_status_register_1 | 0x400;
    _engine_fault_status_register_2 = _engine_fault_status_register_2 | 0x400;
  }
  if ((_engine_fault_timer_3 == 0) && (current_engine_rpm != 0)) {
    if (_engine_fault_counter_3 <
        mph_above_which_throttle_faults_can_be_logged_for_uncalibrated_0_255) {
      _engine_fault_counter_3 = _engine_fault_counter_3 + 1;
    }
    else {
      _engine_fault_status_register_3 = _engine_fault_status_register_3 | 4;
      _engine_fault_status_register_4 = _engine_fault_status_register_4 | 4;
    }
  }
  else if ((_engine_fault_timer_3 != 0) &&
          ((_engine_fault_counter_3 = 0, (_engine_fault_status_register_3 & 4) != 0 &&
           ((_engine_fault_status_register_4 & 4) == 0)))) {
    _engine_fault_status_register_3 = _engine_fault_status_register_3 & 0xfffb;
  }
  if (((DAT_0080c7b3 == '\x01') &&
      (_engine_fault_counter_4 = 0, (_engine_fault_status_register_1 & 0x4000) != 0)) &&
     ((_engine_fault_status_register_2 & 0x4000) == 0)) {
    _engine_fault_status_register_1 = _engine_fault_status_register_1 & 0xbfff;
  }
  if ((DAT_0080c7b3 == '\0') && (current_engine_rpm != 0)) {
    if (_engine_fault_counter_4 <
        flag_to_delay_resetting_of_throttle_min_when_sampled_thrott_true_false) {
      _engine_fault_counter_4 = _engine_fault_counter_4 + 1;
    }
    else {
      _engine_fault_status_register_1 = _engine_fault_status_register_1 | 0x4000;
      _engine_fault_status_register_2 = _engine_fault_status_register_2 | 0x4000;
    }
  }
  else if ((DAT_0080c7b3 == '\0') &&
          ((_engine_fault_counter_4 = 0, (_engine_fault_status_register_1 & 0x4000) != 0 &&
           ((_engine_fault_status_register_2 & 0x4000) == 0)))) {
    _engine_fault_status_register_1 = _engine_fault_status_register_1 & 0xbfff;
  }
  if ((((DAT_0080c7b2 == '\x01') || (DAT_0080c7b2 == '\0')) &&
      (_engine_fault_counter_5 = 0, (_engine_fault_status_register_1 & 0x800) != 0)) &&
     ((_engine_fault_status_register_2 & 0x800) == 0)) {
    _engine_fault_status_register_1 = _engine_fault_status_register_1 & 0xf7ff;
  }
  (*_engine_callback_function_ptr)();
  uVar1 = (uint)_engine_rpm_source_selector;
  if (_engine_rpm_source_selector == 0) {
    if (_engine_fault_timer_1 == 0) {
      _current_engine_fuel_demand = 0;
      current_engine_rpm = 0;
      _current_engine_rpm_raw = 0;
    }
    else {
      _current_engine_fuel_demand = _engine_rpm_calculation_param_1;
      current_engine_rpm = coreTableInterpolation();
      uVar1 = _engine_rpm_base_frequency / _engine_rpm_divisor_1;
      _current_engine_rpm_raw = (ushort)uVar1;
    }
  }
  else if (_engine_rpm_source_selector == 1) {
    if (_engine_fault_timer_2 == 0) {
      _current_engine_fuel_demand = 0;
      current_engine_rpm = 0;
      _current_engine_rpm_raw = 0;
    }
    else {
      _current_engine_fuel_demand = _engine_rpm_calculation_param_2;
      current_engine_rpm = coreTableInterpolation();
      uVar1 = _engine_rpm_base_frequency / _engine_rpm_divisor_2;
      _current_engine_rpm_raw = (ushort)uVar1;
    }
  }
  else if (_engine_rpm_source_selector == 2) {
    if (_engine_fault_timer_3 == 0) {
      _current_engine_fuel_demand = 0;
      current_engine_rpm = 0;
      _current_engine_rpm_raw = 0;
    }
    else {
      _current_engine_fuel_demand = _engine_rpm_calculation_param_3;
      uVar1 = coreTableInterpolation();
      _current_engine_rpm_raw = (ushort)uVar1;
      current_engine_rpm = _current_engine_rpm_raw;
    }
  }
  if (_engine_override_enable != 0) {
    _current_engine_rpm_raw = _engine_override_rpm_value;
    _current_engine_fuel_demand = _engine_override_rpm_value;
    current_engine_rpm = _engine_override_rpm_value;
  }
  if (engine_operating_mode == IDLE) {
    uVar1 = vp44_communication_status & 1;
    if ((vp44_communication_status & 1) == 0) {
      points_to_water_in_fuel_fuel_maximum_threshold_0_2_32._2_2_ = 0;
    }
    else {
      points_to_water_in_fuel_fuel_maximum_threshold_0_2_32._2_2_ = 2;
    }
  }
  else {
    points_to_water_in_fuel_fuel_maximum_threshold_0_2_32._2_2_ = 1;
  }
  if (_current_engine_rpm_raw < 0x800) {
    _DAT_0080c772 = CCMNFLLM;
    _DAT_0080c774 = _DAT_00807cdc;
    return uVar1;
  }
  if (_current_engine_rpm_raw < 0xff8) {
    _DAT_0080c772 = (short)((int)(uint)CCMNFLLM >> 1);
    _DAT_0080c774 = (short)((int)(uint)_DAT_00807cdc >> 1);
    return (int)(uint)_DAT_00807cdc >> 1;
  }
  if (0x17ff < _current_engine_rpm_raw) {
    _DAT_0080c772 = (short)((int)(uint)CCMNFLLM >> 3);
    _DAT_0080c774 = (short)((int)(uint)_DAT_00807cdc >> 3);
    return (int)(uint)_DAT_00807cdc >> 3;
  }
  _DAT_0080c772 = (short)((int)(uint)CCMNFLLM >> 2);
  _DAT_0080c774 = (short)((int)(uint)_DAT_00807cdc >> 2);
  return (int)(uint)_DAT_00807cdc >> 2;
}



//
// Function: FUN_000137ac @ 0x000137ac
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000137ac(void)

{
  _DAT_00800284 = 0;
  _DAT_00800280 = &CCMXFLLM;
  _DAT_0080c772 = CCMNFLLM;
  _engine_callback_function_ptr = &LAB_000137d8;
  _engine_rpm_source_selector = 0;
  return;
}



//
// Function: FUN_00013890 @ 0x00013890
//

void FUN_00013890(void)

{
  switch((undefined1)time_fault_conditions_must_exist_before_logging_a_throttle_faul_0_2000) {
  case 0:
    FUN_0001566a();
    FUN_0001578c();
    FUN_00015794();
    return;
  case 1:
    FUN_00015968();
    FUN_00015a8a();
    FUN_00015b48();
    return;
  case 2:
    FUN_00015fb6();
    FUN_000160e2();
    FUN_00016190();
    return;
  case 3:
    FUN_000163f8();
    FUN_00016548();
    FUN_00016550();
  }
  return;
}



//
// Function: FUN_000138fe @ 0x000138fe
//

void FUN_000138fe(void)

{
  if (minimum_allowable_fueling_for_this_algorithm_to_operate_0_100 == 1) {
    FUN_00016ba8();
    return;
  }
  if (minimum_allowable_fueling_for_this_algorithm_to_operate_0_100 != 2) {
    if (minimum_allowable_fueling_for_this_algorithm_to_operate_0_100 != 0) {
      return;
    }
    FUN_00016f98();
    return;
  }
  FUN_00017164();
  return;
}



//
// Function: FUN_00013930 @ 0x00013930
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00013930(void)

{
  if (((engine_operating_mode == LOW_RPM_RUNNING) || (engine_operating_mode == TRANSITIONAL_MODE_6))
     || (engine_operating_mode == TRANSITIONAL_MODE_7)) {
    _DAT_0080c800 = _DAT_0080c80e + _DAT_0080c802;
    if (_DAT_00807d3e < _DAT_0080c800) {
      _DAT_0080c800 = _DAT_00807d3e;
    }
    _DAT_0080c7fe = _DAT_0080c80c + _DAT_0080c7f6;
    if (_DAT_00807d3a < _DAT_0080c7fe) {
      _DAT_0080c7fe = _DAT_00807d3a;
    }
    if (current_engine_rpm < _DAT_0080c800) {
      _DAT_0080c7e8 = _DAT_0080c7fe;
      return;
    }
    if ((_DAT_0080c800 <= current_engine_rpm) && (current_engine_rpm <= _DAT_0080c7fc)) {
      _DAT_0080c7e8 =
           (short)((((uint)current_engine_rpm - (uint)_DAT_0080c800) *
                   ((uint)_DAT_0080c806 + (uint)_DAT_00807d36)) /
                  (uint)(ushort)(_DAT_0080c7fc - _DAT_0080c800)) +
           (short)(((uint)_DAT_0080c7fe * ((uint)_DAT_0080c7fc - (uint)current_engine_rpm)) /
                  (uint)(ushort)(_DAT_0080c7fc - _DAT_0080c800));
    }
  }
  return;
}



//
// Function: FUN_00013a1e @ 0x00013a1e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00013a1e(void)

{
  short sVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if (_DAT_0080965a == 0x4000) {
    _DAT_008002a8 = _DAT_0080c7fc;
    _DAT_008002b0 = _DAT_0080c806 + _DAT_00807d36;
    uVar2 = tableInterpolationLookup((short *)&DAT_008002a2);
    _DAT_0080c7ec = (short)((ulonglong)uVar2 >> 0x20);
  }
  else if (_DAT_0080965a == 0) {
    _DAT_008002bc = _DAT_0080c7fc;
    _DAT_008002c4 = _DAT_0080c806 + _DAT_00807d36;
    uVar2 = tableInterpolationLookup((short *)&DAT_008002b6);
    _DAT_0080c7ec =
         (short)((uint)(ushort)((ulonglong)uVar2 >> 0x20) * (0x4000 - (uint)_DAT_0080965a) >> 0xe);
  }
  else {
    _DAT_008002a8 = _DAT_0080c7fc;
    _DAT_008002b0 = _DAT_0080c806 + _DAT_00807d36;
    uVar2 = tableInterpolationLookup((short *)&DAT_008002a2);
    _DAT_008002bc = _DAT_0080c7fc;
    _DAT_008002c4 = _DAT_0080c806 + _DAT_00807d36;
    uVar3 = tableInterpolationLookup((short *)&DAT_008002b6);
    _DAT_0080c7ec =
         (short)((uint)_DAT_0080965a * (uint)(ushort)((ulonglong)uVar2 >> 0x20) >> 0xe) +
         (short)((uint)(ushort)((ulonglong)uVar3 >> 0x20) * (0x4000 - (uint)_DAT_0080965a) >> 0xe);
  }
  if ((uint)_DAT_0080c806 + (uint)_DAT_00807d36 <
      (uint)upper_limit_at_which_loading_trigger_is_satisfied_in_trendin_0_127_5) {
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
// Function: FUN_00013bd8 @ 0x00013bd8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00013bd8(void)

{
  if (((engine_operating_mode == LOW_RPM_RUNNING) || (engine_operating_mode == TRANSITIONAL_MODE_6))
     || (engine_operating_mode == TRANSITIONAL_MODE_7)) {
    FUN_00013a1e();
    if (current_engine_rpm < _DAT_0080c804) {
      _DAT_0080c7ea = _DAT_0080c7f8;
      return;
    }
    if ((_DAT_0080c804 <= current_engine_rpm) && (current_engine_rpm <= _DAT_0080c7fc)) {
      _DAT_0080c7ea =
           _DAT_0080c7f8 +
           (short)(((int)(short)(_DAT_0080c808 - _DAT_0080c7f8) *
                   (int)(short)(current_engine_rpm - _DAT_0080c804)) /
                  (int)(short)(_DAT_0080c7fc - _DAT_0080c804));
    }
  }
  return;
}



//
// Function: FUN_00013c6a @ 0x00013c6a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00013c6a(void)

{
  ushort uVar1;
  undefined2 uVar2;
  uint in_D0;
  uint uVar3;
  
  uVar3 = in_D0 & 0xffff0000;
  if (((_engine_fault_status_register_1 & 1) == 0) ||
     (uVar3 = CONCAT22((short)(in_D0 >> 0x10),_engine_fault_confirmation_register) & 0xffff0001,
     (_engine_fault_confirmation_register & 1) == 0)) {
    uVar2 = (undefined2)(uVar3 >> 0x10);
    uVar3 = CONCAT22(uVar2,_engine_fault_status_register_1) & 0xffff0002;
    if ((((_engine_fault_status_register_1 & 2) == 0) ||
        (uVar3 = CONCAT22(uVar2,_engine_fault_confirmation_register) & 0xffff0002,
        (_engine_fault_confirmation_register & 2) == 0)) && (_DAT_00807d30 <= _DAT_0080926e)) {
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
// Function: FUN_00013d66 @ 0x00013d66
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00013d66(void)

{
  if (_DAT_008037f2 == 1) {
    _DAT_0080c7fc = _DAT_00807d2c;
    return;
  }
  _DAT_0080c7fc = _DAT_0080d092;
  return;
}



//
// Function: FUN_00013d86 @ 0x00013d86
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00013d86(void)

{
  ushort uVar1;
  undefined2 uVar2;
  uint in_D0;
  uint uVar3;
  
  uVar3 = in_D0 & 0xffff0000;
  if (((_DAT_00805df2 & 0x2000) == 0) ||
     (uVar3 = CONCAT22((short)(in_D0 >> 0x10),_DAT_008068c4) & 0xffff2000,
     (_DAT_008068c4 & 0x2000) == 0)) {
    uVar2 = (undefined2)(uVar3 >> 0x10);
    uVar3 = CONCAT22(uVar2,_DAT_00805df2) & 0xffff4000;
    if ((((_DAT_00805df2 & 0x4000) == 0) ||
        (uVar3 = CONCAT22(uVar2,_DAT_008068c4) & 0xffff4000, (_DAT_008068c4 & 0x4000) == 0)) &&
       (_DAT_00807d34 <= _DAT_008091ea)) {
      if (_DAT_00807d32 < _DAT_008091ea) {
        _DAT_0080c7f8 = _DAT_00807d40;
        _DAT_0080c804 = jcomm_frict_load_line_slope_slope_used_to_calculate_frictiona_0_1_05;
        return uVar3;
      }
      uVar1 = _DAT_00807d32 - _DAT_00807d34;
      _DAT_0080c7f8 =
           (short)((((uint)_DAT_00807d32 - (uint)_DAT_008091ea) *
                   (uint)jcomm_frict_load_at_600_rpm_point_used_to_calculate_frictional_0_100) /
                  (uint)uVar1) +
           (short)((((uint)_DAT_008091ea - (uint)_DAT_00807d34) * (uint)_DAT_00807d40) / (uint)uVar1
                  );
      uVar3 = (((uint)_DAT_00807d32 - (uint)_DAT_008091ea) *
              (uint)jcomm_peak_torque_tau_0_torque_rating_of_engine_associated_wi_0_5000) /
              (uint)uVar1;
      _DAT_0080c804 =
           (short)uVar3 +
           (short)((((uint)_DAT_008091ea - (uint)_DAT_00807d34) *
                   (uint)jcomm_frict_load_line_slope_slope_used_to_calculate_frictiona_0_1_05) /
                  (uint)uVar1);
      return uVar3;
    }
  }
  _DAT_0080c7f8 = jcomm_frict_load_at_600_rpm_point_used_to_calculate_frictional_0_100;
  _DAT_0080c804 = jcomm_peak_torque_tau_0_torque_rating_of_engine_associated_wi_0_5000;
  return uVar3;
}



//
// Function: FUN_00013e82 @ 0x00013e82
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00013e82(void)

{
  if ((_DAT_00807d52 < _DAT_0080c7ee) && (_DAT_00800288 == 0)) {
    _DAT_0080c7fa =
         jcomm_peak_torque_min_fueling_tau_0_frict_load_fuel_at_peak_to_0_100 + _DAT_00807d48;
    _DAT_00800288 = 1;
  }
  if (current_engine_rpm == 0) {
    _DAT_0080c7fa = _DAT_00807d48;
  }
  _DAT_008002ca = engine_operating_mode;
  return;
}



//
// Function: FUN_00013ecc @ 0x00013ecc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00013ecc(void)

{
  if (((engine_operating_mode == LOW_RPM_RUNNING) || (engine_operating_mode == TRANSITIONAL_MODE_6))
     || (engine_operating_mode == TRANSITIONAL_MODE_7)) {
    _DAT_0080c80a = _DAT_0080c9ae;
    _DAT_0080c9ae = _DAT_0080c7ea;
    _DAT_0080c9b0 = 5;
    _DAT_0080c9b2 = 0;
  }
  return;
}



//
// Function: FUN_00013f06 @ 0x00013f06
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00013f06(void)

{
  if (((_DAT_008002cc == 1) && (engine_operating_mode == LOW_RPM_RUNNING)) ||
     ((_DAT_008002cc == 3 && (engine_operating_mode == TRANSITIONAL_MODE_7)))) {
    FUN_00013c6a();
    FUN_00013d86();
    FUN_00013d66();
  }
  FUN_00013e82();
  _DAT_008002cc = engine_operating_mode;
  return;
}



//
// Function: FUN_00013f46 @ 0x00013f46
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00013f46(void)

{
  if ((engine_operating_mode == TRANSITIONAL_MODE_6) && (current_engine_rpm < _DAT_0080c800)) {
    if ((int)(uint)_DAT_00807d4e <
        (int)((uint)max_number_of_shutdowns_before_restart_is_not_allowed_0_255 -
             (uint)_DAT_0080c80c)) {
      _DAT_0080c80c = _DAT_00807d4e + _DAT_0080c80c;
    }
    else {
      _DAT_0080c80c = max_number_of_shutdowns_before_restart_is_not_allowed_0_255;
    }
    if ((int)(uint)_DAT_00807d50 < (int)((uint)_oil_pressure_precrank_status - (uint)_DAT_0080c80e))
    {
      _DAT_0080c80e = _DAT_00807d50 + _DAT_0080c80e;
    }
    else {
      _DAT_0080c80e = _oil_pressure_precrank_status;
    }
  }
  if ((_DAT_008002ce == 7) && (engine_operating_mode == IDLE)) {
    _DAT_0080c80c = 0;
    _DAT_0080c80e = 0;
  }
  _DAT_008002ce = engine_operating_mode;
  return;
}



//
// Function: FUN_00013fe2 @ 0x00013fe2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00013fe2(void)

{
  if ((((engine_operating_mode == LOW_RPM_RUNNING) || (engine_operating_mode == TRANSITIONAL_MODE_6)
       ) && (frictional_load_torque_in_fueling_at_breakpoint_4_engine_rpm_0_100 < current_engine_rpm
            )) &&
     (_DAT_0080c806 =
           frictional_load_torque_in_fueling_at_breakpoint_5_engine_rpm_0_100 + _DAT_0080c806,
     frictional_load_torque_in_fueling_at_rated_engine_rpm_0_100 < _DAT_0080c806)) {
    _DAT_0080c806 = frictional_load_torque_in_fueling_at_rated_engine_rpm_0_100;
  }
  if ((_DAT_008002d0 != 3) && (engine_operating_mode == HIGH_RPM_RUNNING)) {
    _DAT_0080c806 = 0;
  }
  _DAT_008002d0 = engine_operating_mode;
  return;
}



//
// Function: FUN_0001403e @ 0x0001403e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001403e(void)

{
  if (engine_operating_mode == HIGH_RPM_RUNNING) {
    _DAT_0080c7ee = _DAT_0080c7ee + 1;
  }
  if (engine_operating_mode == IDLE) {
    _DAT_0080c7ee = 0;
    _DAT_00800288 = 0;
  }
  if (engine_operating_mode == LOW_RPM_RUNNING) {
    _DAT_0080c7f0 = _DAT_0080c7f0 + 1;
  }
  else if ((_DAT_008002d2 == 7) && (engine_operating_mode == IDLE)) {
    _DAT_0080c7f0 = 0;
  }
  _DAT_008002d2 = engine_operating_mode;
  return;
}



//
// Function: FUN_00014090 @ 0x00014090
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00014090(void)

{
  if (((_DAT_008002d4 == 3) && (engine_operating_mode == TRANSITIONAL_MODE_7)) &&
     (_DAT_00807d52 < _DAT_0080c7ee)) {
    _DAT_0080c80c = _DAT_00807d54;
    _DAT_0080c80e = frictional_load_torque_in_fueling_at_breakpoint_3_engine_rpm_0_100;
  }
  _DAT_008002d4 = engine_operating_mode;
  return;
}



//
// Function: FUN_000140ce @ 0x000140ce
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000140ce(void)

{
  _DAT_0080028c = &engine_speed_at_0_fuel_which_activates_kick_down_signal_0_8000;
  _DAT_00800292 = &accel_threshold_to_disable_a_c_1200_1200;
  _DAT_0080028a = 2;
  _DAT_00800298 = &lower_limit_at_which_loading_trigger_is_satisfied_in_trendin_0_127_5;
  _DAT_0080029e = &count_minimum_for_percent_load_to_be_low_0_100;
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
// Function: FUN_00014174 @ 0x00014174
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00014174(void)

{
  switch(engine_operating_mode) {
  case IDLE:
    if ((_DAT_00807d64 < current_engine_rpm) && (_DAT_00804d84 == 0)) {
      engine_operating_mode = LOW_RPM_RUNNING;
    }
    else if ((((vp44_communication_status & 1) == 0) && (_DAT_0080d450 == 0)) ||
            (_DAT_0080c996 == 1)) {
      engine_operating_mode = FAULT_EMERGENCY;
    }
    break;
  case LOW_RPM_RUNNING:
    if (_DAT_00807d64 < current_engine_rpm) {
      if (current_engine_rpm < _DAT_0080c7fc) {
        if (jcomm_peak_fueling_tau_0_max_fueling_on_100_throttle_curve_fo_0_100 < _DAT_0080c7f0) {
          engine_operating_mode = TRANSITIONAL_MODE_6;
        }
        else if ((((vp44_communication_status & 1) == 0) && (_DAT_0080d450 == 0)) ||
                (_DAT_0080c996 == 1)) {
          engine_operating_mode = FAULT_EMERGENCY;
        }
      }
      else {
        engine_operating_mode = HIGH_RPM_RUNNING;
      }
    }
    else {
      engine_operating_mode = IDLE;
    }
    break;
  case HIGH_RPM_RUNNING:
    if (vp44_injection_system_active == 1) {
      engine_operating_mode = VP44_INJECTION_ACTIVE;
    }
    else if (_DAT_0080c7fa < current_engine_rpm) {
      if ((((vp44_communication_status & 1) == 0) && (_DAT_0080d450 == 0)) || (_DAT_0080c996 == 1))
      {
        engine_operating_mode = FAULT_EMERGENCY;
      }
      else if (current_engine_rpm <
               user_inversion_bit_mask_for_the_user_datalogger_switc_invert_no_invert._0_2_) {
        _DAT_008002d6 = 0;
      }
      else {
        _DAT_008002d6 = _DAT_008002d6 + 1;
        if (_DAT_00807d62 < _DAT_008002d6) {
          engine_operating_mode = HIGH_PERFORMANCE;
          _DAT_008002d6 = 0;
        }
      }
    }
    else {
      engine_operating_mode = TRANSITIONAL_MODE_7;
    }
    break;
  case VP44_INJECTION_ACTIVE:
    if (vp44_injection_system_active == 0) {
      engine_operating_mode = HIGH_RPM_RUNNING;
    }
    else if ((((vp44_communication_status & 1) == 0) && (_DAT_0080d450 == 0)) ||
            (_DAT_0080c996 == 1)) {
      engine_operating_mode = FAULT_EMERGENCY;
    }
    break;
  case HIGH_PERFORMANCE:
    if (current_engine_rpm <
        user_inversion_bit_mask_for_the_user_datalogger_switc_invert_no_invert._2_2_) {
      engine_operating_mode = HIGH_RPM_RUNNING;
    }
    else if ((((vp44_communication_status & 1) == 0) && (_DAT_0080d450 == 0)) ||
            (_DAT_0080c996 == 1)) {
      engine_operating_mode = FAULT_EMERGENCY;
    }
    _engine_fault_status_register_1 = _engine_fault_status_register_1 | 0x8000;
    _engine_fault_status_register_2 = _engine_fault_status_register_2 | 0x8000;
    if (_DAT_00804d80 == 0) {
      _DAT_00804d80 = 1;
      *(dword *)((short)_DAT_00804d82 * 8 + 0x804c68) = loopCounter;
      *(undefined2 *)((short)_DAT_00804d82 * 8 + 0x804c6e) = 0;
      *(word *)((short)_DAT_00804d82 * 8 + 0x804c6c) = current_engine_rpm;
    }
    else if (*(ushort *)((short)_DAT_00804d82 * 8 + 0x804c6c) < current_engine_rpm) {
      *(word *)((short)_DAT_00804d82 * 8 + 0x804c6c) = current_engine_rpm;
    }
    break;
  case TRANSITIONAL_MODE_6:
    if (_DAT_00807d64 < current_engine_rpm) {
      if (current_engine_rpm < _DAT_0080c7fc) {
        if ((((vp44_communication_status & 1) == 0) && (_DAT_0080d450 == 0)) || (_DAT_0080c996 == 1)
           ) {
          engine_operating_mode = FAULT_EMERGENCY;
        }
      }
      else {
        engine_operating_mode = HIGH_RPM_RUNNING;
      }
    }
    else {
      engine_operating_mode = IDLE;
    }
    break;
  case TRANSITIONAL_MODE_7:
    if (_DAT_00807d64 < current_engine_rpm) {
      if (current_engine_rpm < _DAT_0080c7fc) {
        if ((((vp44_communication_status & 1) == 0) && (_DAT_0080d450 == 0)) || (_DAT_0080c996 == 1)
           ) {
          engine_operating_mode = FAULT_EMERGENCY;
        }
      }
      else {
        engine_operating_mode = HIGH_RPM_RUNNING;
      }
    }
    else {
      engine_operating_mode = IDLE;
    }
    break;
  case FAULT_EMERGENCY:
    if ((((_DAT_0080c996 == 1) && (current_engine_rpm == 0)) ||
        ((_DAT_0080c996 == 0 && ((vp44_communication_status & 1) != 0)))) &&
       ((engine_operating_mode = IDLE, current_engine_rpm == 0 && (_DAT_0080c996 == 1)))) {
      _DAT_0080c996 = 0;
    }
    if (((current_engine_rpm == 0) && ((vp44_communication_status & 1) == 0)) &&
       (_DAT_0080d450 == 0)) {
      _DAT_0080c812 = 1;
    }
    break;
  default:
    engine_operating_mode = IDLE;
  }
  if (((engine_operating_mode != HIGH_PERFORMANCE) &&
      ((_engine_fault_status_register_1 & 0x8000) != 0)) &&
     ((_engine_fault_status_register_2 & 0x8000) == 0)) {
    _engine_fault_status_register_1 = _engine_fault_status_register_1 & 0x7fff;
    *(short *)((short)_DAT_00804d82 * 8 + 0x804c6e) =
         loopCounter._2_2_ - *(short *)((short)_DAT_00804d82 * 8 + 0x804c6a);
    _DAT_00804d80 = 0;
    _DAT_00804d82 = (ushort)(_DAT_00804d82 + 1) % 5;
  }
  if (((vp44_communication_status & 1) != 0) && (DAT_008002d8 == '\0')) {
    _DAT_0080d450 = 0;
  }
  DAT_008002d8 = -((vp44_communication_status & 1) != 0) & 1;
  return;
}



//
// Function: FUN_00014536 @ 0x00014536
//

void FUN_00014536(void)

{
  engine_operating_mode = IDLE;
  DAT_008002d8 = 0;
  return;
}



//
// Function: FUN_00014546 @ 0x00014546
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_00014546(void)

{
  ushort uVar1;
  
  if ((_diagnostic_system_flags_2 & 0x10) == 0) {
    _fuel_arbitrator_threshold_1 = _oil_pressure_precrank_status;
    _DAT_0080c98e = max_number_of_shutdowns_before_restart_is_not_allowed_0_255;
    _DAT_0080c990 = 0;
    _DAT_0080c998 = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = _DAT_008002da;
    switch(_DAT_008002da) {
    case 0:
      uVar1 = FUN_0001485a();
      break;
    case 1:
      uVar1 = FUN_00014ae4();
      break;
    case 2:
      uVar1 = FUN_00015448();
      break;
    case 3:
      FUN_00014c3a();
      uVar1 = FUN_00015272();
      break;
    case 4:
      uVar1 = FUN_00014d6a();
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
// Function: FUN_000145d4 @ 0x000145d4
//

ushort FUN_000145d4(int param_1,int param_2,ushort *param_3,undefined4 param_4)

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
// Function: FUN_0001462e @ 0x0001462e
//

undefined4 FUN_0001462e(undefined4 param_1,undefined4 param_2)

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
// Function: FUN_00014664 @ 0x00014664
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00014664(void)

{
  _DAT_0080c814 = &DAT_0080bdc8;
  _DAT_0080c818 = 0x2000;
  _DAT_0080c83a = 0x804c90;
  _DAT_0080c842 = &DAT_0080926e;
  _DAT_0080c84c = &DAT_00807d90;
  _DAT_0080c850 = &time_abuse_event_must_be_continuously_present_before_it_will_b_0_100;
  _DAT_0080c854 = &time_that_must_elasp_since_last_event_to_consider_an_abuse_0_100000;
  _DAT_0080c868 = 0x804cb8;
  _DAT_0080c86c = 0x804cb8;
  _DAT_0080c870 = &DAT_0080976a;
  _DAT_0080c87a = &time_abuse_event_must_be_continuously_present_before_it_will_0_100;
  _DAT_0080c87e = &time_that_must_elasp_since_last_event_to_consider_an_abuse_0_100000;
  _DAT_0080c882 = 0x807db4;
  _DAT_0080c896 = 0x804ce0;
  _DAT_0080c89a = 0x804ce0;
  _DAT_0080c89e = &DAT_00809242;
  _DAT_0080c8a8 = &DAT_0080d058;
  _DAT_0080c8b0 = &eps_main_lost_duration_0_20;
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
  FUN_00014cfc();
  FUN_0001562e();
  _DAT_008002da = 0;
  return;
}



//
// Function: FUN_000147b6 @ 0x000147b6
//

uint FUN_000147b6(ushort *param_1,undefined4 *param_2,undefined4 param_3)

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
// Function: FUN_0001485a @ 0x0001485a
//

void FUN_0001485a(void)

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
        uVar2 = FUN_000147b6(puVar4,puVar3,0);
        if ((short)uVar2 == 0) {
          *(undefined2 *)((int)puVar3 + 6) = 0;
        }
        else if (*(short *)((int)puVar3 + 6) != -1) {
          *(short *)((int)puVar3 + 6) = *(short *)((int)puVar3 + 6) + 1;
        }
      }
      if ((uVar1 & 0x402) != 0) {
        uVar2 = FUN_000147b6(puVar4,puVar3,0x10000);
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
// Function: FUN_000148f8 @ 0x000148f8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_000148f8(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  ushort *puVar4;
  
  uVar3 = _diagnostic_system_flags_2 & 0x10;
  if ((((((_diagnostic_system_flags_2 & 0x10) != 0) &&
        (uVar3 = _diagnostic_system_flags_2 & 1, (_diagnostic_system_flags_2 & 1) != 0)) &&
       (uVar3 = _diagnostic_system_flags_2 & 0x20, (_diagnostic_system_flags_2 & 0x20) != 0)) &&
      ((_DAT_00804e76 != 0xff && (_DAT_00804e76 != 3)))) &&
     (uVar3 = (uint)_DAT_00804e78, _DAT_00807e70 <= _DAT_00804e78)) {
    puVar4 = (ushort *)(&DAT_00807d66 + _DAT_00804e76 * 0x20);
    iVar2 = _DAT_00804e76 * 0x2e;
    uVar1 = _DAT_00804e76 * 4 + 0x70;
    uVar3 = (uint)(&vp44_status_flags_1)[(short)((int)(uVar1 + 2) >> 4)] & 1 << (uVar1 + 2) % 0x10;
    if ((uVar3 != 0) &&
       (uVar3 = (uint)(&vp44_status_flags_1)[(short)((int)(uVar1 + 3) >> 4)] &
                1 << (uVar1 + 3) % 0x10, uVar3 != 0)) {
      uVar1 = *puVar4;
      uVar3 = 0;
      if ((uVar1 & 1) != 0) {
        uVar3 = FUN_000147b6(puVar4,(undefined4 *)(&DAT_0080c814 + iVar2),0);
        if ((short)uVar3 != 0) {
          *(undefined2 *)(&DAT_0080c82c + iVar2) = 1;
          _DAT_0080c994 = 1;
        }
      }
      uVar3 = CONCAT22((short)(uVar3 >> 0x10),uVar1) & 0xffff0002;
      if ((uVar1 & 2) != 0) {
        uVar3 = FUN_000147b6(puVar4,(undefined4 *)(&DAT_0080c814 + iVar2),0x10000);
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
// Function: FUN_00014a4a @ 0x00014a4a
//

uint FUN_00014a4a(ushort *param_1,undefined4 *param_2,int param_3)

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
    uVar2 = FUN_000147b6(param_1,param_2,0);
    if ((short)uVar2 == 0) {
      *(undefined2 *)(param_3 + 4) = 0;
    }
    else {
      uVar2 = uVar2 & 0xffff0000;
      if ((uVar1 & 0x40) == 0) {
        uVar2 = FUN_0001462e(CONCAT22(*(undefined2 *)*param_2,**(undefined2 **)((int)param_2 + 10)),
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
    uVar2 = FUN_000147b6(param_1,param_2,0x10000);
    if ((short)uVar2 == 0) {
      *(undefined2 *)(param_3 + 6) = 0;
      return uVar2;
    }
    *(undefined2 *)(param_3 + 6) = 0x100;
  }
  return uVar2;
}



//
// Function: FUN_00014ae4 @ 0x00014ae4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_00014ae4(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  undefined *puVar4;
  ushort *puVar5;
  undefined4 *puVar6;
  
  uVar1 = _diagnostic_system_flags_2 & 1;
  if ((((_diagnostic_system_flags_2 & 1) != 0) &&
      (uVar1 = _diagnostic_system_flags_2 & 0x20, (_diagnostic_system_flags_2 & 0x20) != 0)) &&
     (_DAT_00804e76 != 0xff)) {
    puVar6 = (undefined4 *)&DAT_0080c814;
    puVar4 = &DAT_00804d86;
    uVar2 = 0x70;
    uVar3 = 0;
    for (puVar5 = (ushort *)&DAT_00807d66; puVar5 < &DAT_00807e66; puVar5 = puVar5 + 0x10) {
      if ((((int)_DAT_00804e76 == (uint)uVar3) &&
          (((uint)(&vp44_status_flags_1)[(short)((int)(uVar2 + 2) >> 4)] & 1 << (uVar2 + 2) % 0x10)
           != 0)) &&
         (((uint)(&vp44_status_flags_1)[(short)((int)(uVar2 + 3) >> 4)] & 1 << (uVar2 + 3) % 0x10)
          != 0)) {
        FUN_00014a4a(puVar5,puVar6,(int)puVar4);
        FUN_00014bdc();
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
// Function: FUN_00014bdc @ 0x00014bdc
// ERROR: Failed to decompile
//

//
// Function: FUN_00014c3a @ 0x00014c3a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00014c3a(void)

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
      if (((uint)(&vp44_status_flags_1)[(short)((int)uVar2 >> 4)] & 1 << (uVar2 & 0xf)) == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = FUN_000145d4((int)puVar5,(int)puVar6,puVar4,CONCAT22(1,uVar7));
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
  _fuel_arbitrator_threshold_1 = coreTableInterpolation(0x80);
  return;
}



//
// Function: FUN_00014cfc @ 0x00014cfc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00014cfc(void)

{
  _DAT_008002e2 = (uint)_oil_pressure_precrank_status << 0x10;
  _DAT_008002de = 0x807e6e;
  _fuel_arbitrator_threshold_1 = _oil_pressure_precrank_status;
  return;
}



//
// Function: FUN_00014d24 @ 0x00014d24
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00014d24(int param_1,int param_2,undefined4 param_3)

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
// Function: FUN_00014d6a @ 0x00014d6a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_00014d6a(void)

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
  if ((((_diagnostic_system_flags_2 & 1) == 0) || (engine_operating_mode == FAULT_EMERGENCY)) ||
     (engine_operating_mode == IDLE)) {
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
    if ((_DAT_008002e6 == 0) && (current_engine_rpm != 0)) {
      _DAT_008002ec = 1;
    }
    else {
      _DAT_008002ec = 0;
    }
    for (; puVar8 < &DAT_00807e66; puVar8 = puVar8 + 0x10) {
      uVar1 = *puVar8;
      if (((uint)(&vp44_status_flags_1)[(short)((int)uVar4 >> 4)] & 1 << (uVar4 & 0xf)) == 0) {
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
                uVar2 = FUN_000147b6(puVar8,puVar6,2);
                if ((short)uVar2 == 0) {
                  *(undefined2 *)((int)puVar6 + 0x1a) = 0;
                  *(undefined2 *)((int)puVar6 + 0x1e) = 0;
                }
                else {
                  FUN_00014d24((int)puVar8,(int)puVar6,(uint)uVar3);
                }
              }
            }
            else if (puVar8[8] < *(ushort *)((int)puVar6 + 6)) {
              FUN_00014d24((int)puVar8,(int)puVar6,(uint)uVar3);
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
                uVar2 = FUN_000147b6(puVar8,puVar6,0x10002);
                if ((short)uVar2 == 0) {
                  *(undefined2 *)(puVar6 + 7) = 0;
                  *(undefined2 *)(puVar6 + 8) = 0;
                }
                else {
                  FUN_00014d24((int)puVar8,(int)puVar6,CONCAT22(1,uVar3));
                }
              }
            }
            else if (puVar8[9] < *(ushort *)(puVar6 + 2)) {
              FUN_00014d24((int)puVar8,(int)puVar6,CONCAT22(1,uVar3));
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
  _DAT_008002e6 = current_engine_rpm;
  return uVar5;
}



//
// Function: FUN_00015038 @ 0x00015038
//

uint FUN_00015038(undefined4 param_1,uint param_2)

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
// Function: FUN_00015078 @ 0x00015078
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00015078(undefined4 param_1)

{
  dword *pdVar1;
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
    pdVar1 = (dword *)(iVar7 + (uint)uVar4 * 8);
    *pdVar1 = loopCounter;
    *(undefined2 *)((int)pdVar1 + 6) = 0;
    if ((*_DAT_008002ee & 8) == 0) {
      *(undefined2 *)(pdVar1 + 1) = 0;
    }
    else {
      *(undefined2 *)(pdVar1 + 1) = 0xffff;
    }
  }
  uVar5 = 1 << (uVar3 & 0xf);
  *(ushort *)(&DAT_00805df2 + (short)((int)(uint)uVar3 >> 4) * 2) =
       uVar5 | *(ushort *)(&DAT_00805df2 + (short)((int)(uint)uVar3 >> 4) * 2);
  *(ushort *)(&DAT_00805e32 + (short)((int)(uint)uVar3 >> 4) * 2) =
       uVar5 | *(ushort *)(&DAT_00805e32 + (short)((int)(uint)uVar3 >> 4) * 2);
  uVar2 = *_DAT_008002ee & 0xffff000c;
  if ((*_DAT_008002ee & 0xc) != 0) {
    uVar2 = FUN_00015038(CONCAT22(*(undefined2 *)*_DAT_008002f2,
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
// Function: FUN_0001517c @ 0x0001517c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0001517c(undefined4 param_1)

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
  uVar2 = (uint)*(ushort *)(&DAT_00805df2 + (short)((int)(uint)uVar4 >> 4) * 2);
  uVar3 = uVar2 & 1 << (uVar4 & 0xf);
  if (uVar3 != 0) {
    uVar2 = (uint)*(ushort *)(&DAT_00805e32 + (short)((int)(uint)uVar4 >> 4) * 2);
    uVar3 = uVar2 & 1 << (uVar4 & 0xf);
    if (uVar3 == 0) {
      uVar1 = ~(1 << (uVar4 & 0xf));
      uVar3 = (uint)uVar1;
      uVar2 = (int)(uint)uVar4 >> 4;
      *(ushort *)(&DAT_00805df2 + (short)uVar2 * 2) =
           uVar1 & *(ushort *)(&DAT_00805df2 + (short)uVar2 * 2);
      if (*psVar7 != 0) {
        *psVar7 = 0;
        *(short *)(iVar6 + 6 + (uint)*puVar5 * 8) =
             loopCounter._2_2_ - (short)*(undefined4 *)(iVar6 + (uint)*puVar5 * 8);
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
// Function: FUN_00015272 @ 0x00015272
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00015272(void)

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
      if (_DAT_008002ee[0xb] < current_engine_rpm) {
        *(undefined2 *)(_DAT_008002f2 + 9) = 1;
      }
      else if (current_engine_rpm == 0) {
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
      FUN_0001517c((uint)uVar6);
      FUN_0001517c(CONCAT22(1,uVar6));
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
          FUN_00015078((uint)uVar6);
        }
        else {
          FUN_0001517c((uint)uVar6);
        }
        if (bVar4) {
          *(int *)(_DAT_008002f6 + 9) = *(int *)(_DAT_008002f6 + 9) + 1;
          FUN_00015078(CONCAT22(1,uVar6));
        }
        else {
          FUN_0001517c(CONCAT22(1,uVar6));
        }
      }
      else if (bVar3 || bVar4) {
        *(int *)(_DAT_008002f6 + 7) = *(int *)(_DAT_008002f6 + 7) + 1;
        FUN_00015078((uint)uVar6);
      }
      else {
        FUN_0001517c((uint)uVar6);
      }
      if ((uVar1 & 0xc) != 0) {
        sVar2 = *(short *)*_DAT_008002f2;
        uVar5 = FUN_00015038(CONCAT22(sVar2,_DAT_008002f6[4]),CONCAT22(uVar1,uVar6));
        if ((short)uVar5 != 0) {
          _DAT_008002f6[4] = sVar2;
          *(dword *)(_DAT_008002f6 + 5) = loopCounter;
        }
      }
    }
    _DAT_008002f2 = (undefined4 *)((int)_DAT_008002f2 + 0x2e);
    _DAT_008002f6 = _DAT_008002f6 + 0xf;
  }
  return;
}



//
// Function: FUN_0001542a @ 0x0001542a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001542a(void)

{
  if (_DAT_0080c98e < _DAT_0080d494) {
    _DAT_0080d494 = _DAT_0080c98e;
    _DAT_0080d496 = 0x1d;
  }
  return;
}



//
// Function: FUN_00015448 @ 0x00015448
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00015448(void)

{
  ushort uVar3;
  undefined4 uVar1;
  short sVar4;
  int iVar2;
  undefined4 unaff_D2;
  uint uVar5;
  ushort uVar6;
  undefined4 *puVar7;
  ushort *puVar8;
  ushort *puVar9;
  ushort uVar10;
  
  uVar10 = (ushort)((uint)unaff_D2 >> 0x10);
  puVar7 = (undefined4 *)&DAT_0080c814;
  puVar9 = (ushort *)&DAT_00804d86;
  uVar5 = 0x70;
  uVar6 = 0;
  for (puVar8 = (ushort *)&DAT_00807d66; puVar8 < &DAT_00807e66; puVar8 = puVar8 + 0x10) {
    if ((*puVar8 & 1) != 0) {
      if (((uint)(&vp44_status_flags_1)[(short)((int)uVar5 >> 4)] & 1 << (uVar5 & 0xf)) == 0) {
        uVar3 = 0;
      }
      else {
        if ((*puVar8 & 0x40) == 0) {
          if (puVar8[1] < *(ushort *)((int)puVar7 + 6)) {
            uVar1 = FUN_0001462e(CONCAT22(*(undefined2 *)*puVar7,**(undefined2 **)((int)puVar7 + 10)
                                         ),CONCAT22(**(undefined2 **)((int)puVar7 + 0xe),uVar10));
            uVar3 = (ushort)uVar1;
          }
          else {
            uVar3 = 0;
          }
        }
        else {
          uVar3 = FUN_000145d4((int)puVar8,(int)puVar7,puVar9,(uint)uVar10);
        }
        if (uVar3 < puVar9[2]) {
          uVar3 = puVar9[2];
        }
      }
      *puVar9 = uVar3;
      if (uVar6 < uVar3) {
        uVar6 = *puVar9;
      }
    }
    puVar7 = (undefined4 *)((int)puVar7 + 0x2e);
    puVar9 = puVar9 + 0xf;
    uVar5 = (uint)(ushort)((short)uVar5 + 4);
  }
  if ((_DAT_008035e2 & 0x1000) != 0) {
    if (current_engine_rpm == 0) {
      _DAT_008002fa = 0;
    }
    else if (_DAT_008002fa < _DAT_00807e68) {
      _DAT_008002fa = _DAT_008002fa + 1;
    }
    if (_DAT_008002fa < _DAT_00807e68) {
      _DAT_00804de0 = 0x100;
      uVar6 = 0x100;
    }
  }
  if ((int)(short)(_DAT_00807e66 + _DAT_008002fc) < (int)(uint)uVar6) {
    uVar6 = _DAT_00807e66 + _DAT_008002fc;
  }
  else if ((int)(uint)uVar6 < (int)(short)(_DAT_008002fc - _DAT_00807e66)) {
    uVar6 = _DAT_008002fc - _DAT_00807e66;
  }
  _DAT_008002fc = uVar6;
  if (0x100 < (short)_DAT_008002fc) {
    _DAT_008002fc = 0x100;
  }
  if (_DAT_008002fc == 0) {
    _DAT_0080c98e = max_number_of_shutdowns_before_restart_is_not_allowed_0_255;
  }
  else {
    _DAT_00800304 = current_engine_rpm;
    sVar4 = lookupTableInterpolation((short *)&DAT_008002fe);
    iVar2 = (int)(short)(0x100 - _DAT_008002fc) *
            (int)(short)(_calculated_fuel_timing_value - sVar4);
    if (iVar2 < 0) {
      iVar2 = iVar2 + 0xff;
    }
    _DAT_0080c98e = sVar4 + (short)((uint)iVar2 >> 8);
  }
  if ((short)_DAT_008002fc < 1) {
    _DAT_0080c990 = 0;
    return;
  }
  _DAT_0080c990 = 1;
  return;
}



//
// Function: FUN_0001562e @ 0x0001562e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001562e(void)

{
  _DAT_008002fa = 0;
  _DAT_008002fc = 0;
  _DAT_008002fe = 2;
  _DAT_00800300 = 0x807e72;
  _DAT_00800306 = 0x807ea4;
  _DAT_0080c98e = max_number_of_shutdowns_before_restart_is_not_allowed_0_255;
  _DAT_0080c990 = 0;
  return;
}



//
// Function: FUN_0001566a @ 0x0001566a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001566a(void)

{
  int *piVar1;
  
  can1_canidmr0 = can1_canidmr0 & 0xffcf;
  can1_cantbsel = can1_cantbsel & 0xfbff;
  can1_canidmr2 = can1_canidmr2 & 0xfbff;
  _DAT_0080c77e = (int *)((uint)DAT_00807cce * 4 + 0x80c42c);
  for (piVar1 = (int *)&DAT_0080c430; piVar1 <= _DAT_0080c77e; piVar1 = piVar1 + 1) {
    *piVar1 = _CRFLOFPZ;
  }
  _DAT_0080c786 = &DAT_0080c430;
  if (DAT_00807cd0 < 2) {
    _DAT_0080c41a = &DAT_0080c430;
  }
  else {
    _DAT_0080c41a = &DAT_0080c430 + (uint)DAT_00807cd0 * 4;
  }
  _engine_rpm_divisor_1 = _CRFLOFPZ * (uint)DAT_00807cce;
  _engine_divisor_param_1 = _CRFLOFPZ * (uint)DAT_00807cd0;
  _DAT_00808eea = FUN_00015796;
  can1_reserved = can1_reserved & 0xf0ff | 0xd00;
  _DAT_00ffffa2 = (ushort)DAT_00807cda << 8;
  _DAT_00ffffa6 = 0;
  _DAT_00ffffa8 = 0;
  _DAT_00ffffa0 = 0xb;
  can1_canidar0 = can1_canidar0 & 0xffcf | 0x30;
  can1_canidar2 = can1_canidar2 & 0xffcf | 0x30;
  can1_cantbsel = can1_cantbsel | 0x400;
  can1_canidmr0 = can1_canidmr0 & 0xffcf | 0x20;
  if ((char)time_fault_conditions_must_exist_before_logging_a_throttle_faul_0_2000 == '\0') {
    _engine_callback_function_ptr = &LAB_0001416c;
  }
  return;
}



//
// Function: FUN_0001578c @ 0x0001578c
//

void FUN_0001578c(void)

{
  FUN_0002b5aa();
  return;
}



//
// Function: FUN_00015794 @ 0x00015794
//

void FUN_00015794(void)

{
  return;
}



//
// Function: FUN_00015796 @ 0x00015796
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00015796(void)

{
  uint uVar1;
  undefined4 in_D0;
  undefined4 in_D1;
  undefined2 uVar2;
  undefined2 uStack_1e;
  
  uVar1 = _DAT_00ffffa8;
  uVar2 = (undefined2)((uint)in_D0 >> 0x10);
  uStack_1e = (undefined2)in_D0;
  _DAT_0080c75c = _DAT_00ffffa8;
  _DAT_00ffffa8 = _DAT_00ffffa8 & 0xffff;
  _engine_rpm_divisor_1 = uVar1 + (_engine_rpm_divisor_1 - *_DAT_0080c41a);
  *_DAT_0080c41a = uVar1;
  if (_DAT_0080c41a < _DAT_0080c77e) {
    _DAT_0080c41a = _DAT_0080c41a + 1;
  }
  else {
    _DAT_0080c41a = (uint *)&DAT_0080c430;
  }
  if (_DAT_0080c412 < -(uint)_DAT_00807cd2 - 1) {
    _DAT_0080c412 = _DAT_00807cd2 + _DAT_0080c412;
  }
  _engine_divisor_param_1 = _DAT_0080c75c + (_engine_divisor_param_1 - *_DAT_0080c786);
  if (_DAT_0080c786 < _DAT_0080c77e) {
    _DAT_0080c786 = _DAT_0080c786 + 1;
  }
  else {
    _DAT_0080c786 = (uint *)&DAT_0080c430;
  }
  if ((int)(uint)_DAT_0080c7ae < (int)(DAT_00807cce - 1)) {
    _DAT_0080c7ae = _DAT_0080c7ae + 1;
  }
  else {
    _DAT_0080c7ae = 0;
  }
  _engine_fault_timer_1 = _DAT_0080c772;
  if (minimum_allowable_fueling_for_this_algorithm_to_operate_0_100 == 1) {
    if (DAT_0080c7d4 == '\0') {
      if (DAT_0080c7d3 < DAT_00807d20) {
        DAT_0080c7d3 = DAT_0080c7d3 + 1;
      }
      else {
        _DAT_00805df2 = _DAT_00805df2 | 1;
        _DAT_00805e32 = _DAT_00805e32 | 1;
      }
      DAT_0080c7b2 = 2;
      _engine_fault_status_register_1 = _engine_fault_status_register_1 | 0x800;
      _engine_fault_status_register_2 = _engine_fault_status_register_2 | 0x800;
    }
    else {
      DAT_0080c7d4 = DAT_0080c7d4 + -1;
      if (DAT_0080c7d3 == 0) {
        if (((_DAT_00805df2 & 1) != 0) && ((_DAT_00805e32 & 1) == 0)) {
          _DAT_00805df2 = _DAT_00805df2 & 0xfffe;
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
  FUN_00015e96();
  FUN_0000c260();
  can1_canidmr2 = can1_canidmr2 & 0xfbff;
  return CONCAT44(CONCAT22(uVar2,uStack_1e),in_D1);
}



//
// Function: FUN_00015968 @ 0x00015968
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00015968(void)

{
  int *piVar1;
  
  can1_canidmr0 = can1_canidmr0 & 0xffcf;
  can1_cantbsel = can1_cantbsel & 0xfbff;
  can1_canidmr2 = can1_canidmr2 & 0xfbff;
  _DAT_0080c77e = (int *)((uint)DAT_00807cce * 4 + 0x80c42c);
  for (piVar1 = (int *)&DAT_0080c430; piVar1 <= _DAT_0080c77e; piVar1 = piVar1 + 1) {
    *piVar1 = _CRFLOFPZ;
  }
  _DAT_0080c786 = &DAT_0080c430;
  if (DAT_00807cd0 < 2) {
    _DAT_0080c41a = &DAT_0080c430;
  }
  else {
    _DAT_0080c41a = &DAT_0080c430 + (uint)DAT_00807cd0 * 4;
  }
  _engine_rpm_divisor_1 = _CRFLOFPZ * (uint)DAT_00807cce;
  _engine_divisor_param_1 = _CRFLOFPZ * (uint)DAT_00807cd0;
  _DAT_00808eea = FUN_00015b4a;
  can1_reserved = can1_reserved & 0xf0ff | 0xd00;
  _DAT_00ffffa2 = (ushort)DAT_00807cda << 8;
  _DAT_00ffffa6 = 0;
  _DAT_00ffffa8 = 0;
  _DAT_00ffffa0 = 0xb;
  can1_canidar0 = can1_canidar0 & 0xffcf | 0x30;
  can1_canidar2 = can1_canidar2 & 0xffcf | 0x30;
  can1_cantbsel = can1_cantbsel | 0x400;
  can1_canidmr0 = can1_canidmr0 & 0xffcf | 0x20;
  if ((char)time_fault_conditions_must_exist_before_logging_a_throttle_faul_0_2000 == '\0') {
    _engine_callback_function_ptr = &LAB_0001416c;
  }
  return;
}



//
// Function: FUN_00015a8a @ 0x00015a8a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00015a8a(void)

{
  can1_canidmr2 = can1_canidmr2 & 0xfffe;
  can1_cantxerr = can1_cantxerr & 0xfff0 | 9;
  _DAT_00808ec2 = &LAB_00015c30;
  _DAT_00ffff00 = 7;
  _DAT_00ffff02 = maximum_allowed_timing_advance_for_this_algorithm_0_20._0_1_ | 0x100;
  _DAT_00ffff04 = 0x100;
  _DAT_00ffff06 =
       CONCAT11((undefined1)maximum_allowed_timing_advance_for_this_algorithm_0_20,
                maximum_allowed_engine_speed_for_timing_advance_in_this_algor_0_4500._0_1_);
  _DAT_00ffff08 = 0;
  _DAT_00ffff0c = 0;
  can1_canidar1 = can1_canidar1 & 0xfffc | 3;
  can1_canidar3 = can1_canidar3 & 0xfffc | 1;
  can1_cantbsel = can1_cantbsel & 0xfffe | 1;
  can1_canidmr1 = can1_canidmr1 & 0xfffc | 1;
  FUN_0002b5aa();
  return;
}



//
// Function: FUN_00015b48 @ 0x00015b48
//

void FUN_00015b48(void)

{
  return;
}



//
// Function: FUN_00015b4a @ 0x00015b4a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00015b4a(void)

{
  uint uVar1;
  undefined4 in_D0;
  undefined4 in_D1;
  undefined2 uVar2;
  undefined2 uStack_1e;
  
  uVar1 = _DAT_00ffffa8;
  uVar2 = (undefined2)((uint)in_D0 >> 0x10);
  uStack_1e = (undefined2)in_D0;
  _DAT_0080c75c = _DAT_00ffffa8;
  _DAT_00ffffa8 = _DAT_00ffffa8 & 0xffff;
  _engine_rpm_divisor_1 = uVar1 + (_engine_rpm_divisor_1 - *_DAT_0080c41a);
  *_DAT_0080c41a = uVar1;
  if (_DAT_0080c41a < _DAT_0080c77e) {
    _DAT_0080c41a = _DAT_0080c41a + 1;
  }
  else {
    _DAT_0080c41a = (uint *)&DAT_0080c430;
  }
  if (_DAT_0080c412 < -(uint)_DAT_00807cd2 - 1) {
    _DAT_0080c412 = _DAT_00807cd2 + _DAT_0080c412;
  }
  _engine_divisor_param_1 = _DAT_0080c75c + (_engine_divisor_param_1 - *_DAT_0080c786);
  if (_DAT_0080c786 < _DAT_0080c77e) {
    _DAT_0080c786 = _DAT_0080c786 + 1;
  }
  else {
    _DAT_0080c786 = (uint *)&DAT_0080c430;
  }
  _engine_fault_timer_1 = _DAT_0080c772;
  vp44_communication_state_machine(CONCAT22(1,uVar2));
  if ((_DAT_0080c75c < -_DAT_0080c750 - 1U) &&
     (_DAT_0080c750 = _DAT_0080c75c + _DAT_0080c750, _DAT_0080c758 != -1)) {
    _DAT_0080c758 = _DAT_0080c758 + 1;
  }
  FUN_00015e96();
  FUN_0000c260();
  can1_canidmr2 = can1_canidmr2 & 0xfbff;
  return CONCAT44(CONCAT22(uVar2,uStack_1e),in_D1);
}



//
// Function: FUN_00015e96 @ 0x00015e96
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00015e96(void)

{
  ushort uVar1;
  
  if (_engine_fault_timer_2 == 0) {
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
// Function: FUN_00015f26 @ 0x00015f26
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00015f26(void)

{
  uint in_D0;
  uint uVar1;
  ushort uVar2;
  
  if (_engine_fault_timer_1 == 0) {
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
// Function: FUN_00015fb6 @ 0x00015fb6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00015fb6(void)

{
  int *piVar1;
  
  can1_canidmr0 = can1_canidmr0 & 0xffcf;
  can1_cantbsel = can1_cantbsel & 0xfbff;
  can1_canidmr2 = can1_canidmr2 & 0xfbff;
  _DAT_0080c77e = (int *)((uint)DAT_00807cce * 4 + 0x80c42c);
  for (piVar1 = (int *)&DAT_0080c430; piVar1 <= _DAT_0080c77e; piVar1 = piVar1 + 1) {
    *piVar1 = _CRFLOFPZ;
  }
  _DAT_0080c786 = &DAT_0080c430;
  if (DAT_00807cd0 < 2) {
    _DAT_0080c41a = &DAT_0080c430;
  }
  else {
    _DAT_0080c41a = &DAT_0080c430 + (uint)DAT_00807cd0 * 4;
  }
  _engine_rpm_divisor_1 = _CRFLOFPZ * (uint)DAT_00807cce;
  _engine_divisor_param_1 = _CRFLOFPZ * (uint)DAT_00807cd0;
  _DAT_00808eea = FUN_00016192;
  can1_reserved = can1_reserved & 0xf0ff | 0xd00;
  _DAT_00ffffa2 = _DAT_00807cd6 / DAT_00807cce << 8;
  _DAT_00ffffa6 = 0;
  _DAT_00ffffa8 = 0;
  _DAT_00ffffa0 = 0xb;
  can1_canidar0 = can1_canidar0 & 0xffcf | 0x30;
  can1_canidar2 = can1_canidar2 & 0xffcf | 0x30;
  can1_cantbsel = can1_cantbsel | 0x400;
  can1_canidmr0 = can1_canidmr0 & 0xffcf | 0x20;
  if ((char)time_fault_conditions_must_exist_before_logging_a_throttle_faul_0_2000 == '\0') {
    _engine_callback_function_ptr = &LAB_0001416c;
  }
  return;
}



//
// Function: FUN_000160e2 @ 0x000160e2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000160e2(void)

{
  can1_canidmr2 = can1_canidmr2 & 0xfffe;
  can1_cantxerr = can1_cantxerr & 0xfff0 | 9;
  _DAT_00ffff00 = 4;
  _DAT_00ffff02 = maximum_allowed_timing_advance_for_this_algorithm_0_20._0_1_ | 0x100;
  _DAT_00ffff06 =
       CONCAT11((undefined1)maximum_allowed_timing_advance_for_this_algorithm_0_20,
                maximum_allowed_engine_speed_for_timing_advance_in_this_algor_0_4500._0_1_);
  _DAT_00fffffc = 0xc000;
  can1_canidar1 = can1_canidar1 & 0xfffc | 3;
  can1_canidar3 = can1_canidar3 & 0xfffc | 1;
  can1_canidmr1 = can1_canidmr1 & 0xfffc | 2;
  _DAT_00808ec2 = &LAB_00016370;
  can1_cantbsel = can1_cantbsel & 0xfffe | 1;
  FUN_0002b5aa();
  return;
}



//
// Function: FUN_00016190 @ 0x00016190
//

void FUN_00016190(void)

{
  return;
}



//
// Function: FUN_00016192 @ 0x00016192
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00016192(void)

{
  uint uVar1;
  undefined4 in_D0;
  undefined4 in_D1;
  undefined2 uVar2;
  undefined2 uStack_1e;
  
  uVar1 = _DAT_00ffffa8;
  uVar2 = (undefined2)((uint)in_D0 >> 0x10);
  uStack_1e = (undefined2)in_D0;
  _DAT_0080c75c = _DAT_00ffffa8;
  _DAT_00ffffa8 = _DAT_00ffffa8 & 0xffff;
  _engine_rpm_divisor_1 = uVar1 + (_engine_rpm_divisor_1 - *_DAT_0080c41a);
  *_DAT_0080c41a = uVar1;
  if (_DAT_0080c41a < _DAT_0080c77e) {
    _DAT_0080c41a = _DAT_0080c41a + 1;
  }
  else {
    _DAT_0080c41a = (uint *)&DAT_0080c430;
  }
  if (_DAT_0080c412 < -(uint)_DAT_00807cd2 - 1) {
    _DAT_0080c412 = _DAT_00807cd2 + _DAT_0080c412;
  }
  _engine_divisor_param_1 = _DAT_0080c75c + (_engine_divisor_param_1 - *_DAT_0080c786);
  if (_DAT_0080c786 < _DAT_0080c77e) {
    _DAT_0080c786 = _DAT_0080c786 + 1;
  }
  else {
    _DAT_0080c786 = (uint *)&DAT_0080c430;
  }
  if ((int)(uint)_DAT_0080c7ae < (int)(DAT_00807cce - 1)) {
    _DAT_0080c7ae = _DAT_0080c7ae + 1;
  }
  else {
    _DAT_0080c7ae = 0;
  }
  _engine_fault_timer_1 = _DAT_0080c772;
  if (minimum_allowable_fueling_for_this_algorithm_to_operate_0_100 == 1) {
    if (DAT_0080c7d4 == '\0') {
      if (DAT_0080c7d3 < DAT_00807d20) {
        DAT_0080c7d3 = DAT_0080c7d3 + 1;
      }
      else {
        _DAT_00805df2 = _DAT_00805df2 | 1;
        _DAT_00805e32 = _DAT_00805e32 | 1;
      }
      DAT_0080c7b2 = 2;
      _engine_fault_status_register_1 = _engine_fault_status_register_1 | 0x800;
      _engine_fault_status_register_2 = _engine_fault_status_register_2 | 0x800;
    }
    else {
      DAT_0080c7d4 = DAT_0080c7d4 + -1;
      if (DAT_0080c7d3 == 0) {
        if (((_DAT_00805df2 & 1) != 0) && ((_DAT_00805e32 & 1) == 0)) {
          _DAT_00805df2 = _DAT_00805df2 & 0xfffe;
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
  FUN_00015e96();
  FUN_0000c260();
  if ((_DAT_0080c75c < -_DAT_0080c750 - 1U) &&
     (_DAT_0080c750 = _DAT_0080c75c + _DAT_0080c750, _DAT_0080c758 != -1)) {
    _DAT_0080c758 = _DAT_0080c758 + 1;
  }
  can1_canidmr2 = can1_canidmr2 & 0xfbff;
  return CONCAT44(CONCAT22(uVar2,uStack_1e),in_D1);
}



//
// Function: FUN_000163f8 @ 0x000163f8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_000163f8(void)

{
  undefined4 in_D0;
  uint uVar1;
  int *piVar2;
  
  uVar1 = CONCAT22((short)((uint)in_D0 >> 0x10),_engine_system_status_flags) & 0xffff0001;
  if ((_engine_system_status_flags & 1) != 0) {
    can1_canidmr0 = can1_canidmr0 & 0xffcf;
    can1_cantbsel = can1_cantbsel & 0xfbff;
    can1_canidmr2 = can1_canidmr2 & 0xfbff;
    _DAT_0080c77e = (int *)((uint)DAT_00807cce * 4 + 0x80c42c);
    for (piVar2 = (int *)&DAT_0080c430; piVar2 <= _DAT_0080c77e; piVar2 = piVar2 + 1) {
      *piVar2 = _CRFLOFPZ;
    }
    _DAT_0080c786 = &DAT_0080c430;
    if (DAT_00807cd0 < 2) {
      _DAT_0080c41a = &DAT_0080c430;
    }
    else {
      _DAT_0080c41a = &DAT_0080c430 + (uint)DAT_00807cd0 * 4;
    }
    _engine_rpm_divisor_1 = _CRFLOFPZ * (uint)DAT_00807cce;
    uVar1 = _CRFLOFPZ * (uint)DAT_00807cd0;
    _DAT_00800332 = &DAT_0080c430;
    _DAT_00808eea = FUN_00016552;
    can1_reserved = can1_reserved & 0xf0ff | 0xd00;
    _DAT_00ffffa2 = 0x100;
    _DAT_00ffffa6 = 0;
    _DAT_00ffffa8 = 0;
    _DAT_00ffffa0 = 7;
    can1_canidar0 = can1_canidar0 & 0xffcf | 0x20;
    can1_canidar2 = can1_canidar2 & 0xffcf | 0x30;
    can1_cantbsel = can1_cantbsel | 0x400;
    can1_canidmr0 = can1_canidmr0 & 0xffcf | 0x20;
    _DAT_0080c792 = &LAB_00016814;
    _engine_divisor_param_1 = uVar1;
  }
  if ((char)time_fault_conditions_must_exist_before_logging_a_throttle_faul_0_2000 == '\0') {
    _engine_callback_function_ptr = &LAB_0001416c;
  }
  return uVar1;
}



//
// Function: FUN_00016548 @ 0x00016548
//

void FUN_00016548(void)

{
  FUN_0002b5aa();
  return;
}



//
// Function: FUN_00016550 @ 0x00016550
//

void FUN_00016550(void)

{
  return;
}



//
// Function: FUN_00016552 @ 0x00016552
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00016552(void)

{
  uint uVar1;
  undefined4 in_D0;
  int iVar2;
  undefined4 in_D1;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uStack_22;
  
  uVar1 = _DAT_00ffffa8;
  uVar4 = (undefined2)((uint)in_D0 >> 0x10);
  uStack_22 = (undefined2)in_D0;
  _DAT_00ffffa8 = _DAT_00ffffa8 & 0xffff;
  uVar3 = (undefined2)(uVar1 >> 0x10);
  iVar2 = FUN_00016622(uVar1,CONCAT22(_DAT_00ffffa4,uVar4));
  if (DAT_0080c7b2 == '\x01') {
    if (iVar2 == 0) {
      _DAT_00ffffa0 = 0xffff;
      can1_canidar2 = can1_canidar2 & 0xffcf | 0x20;
    }
  }
  else {
    _DAT_00ffffa0 = 0x8080;
    can1_canidar2 = can1_canidar2 & 0xffcf | 0x20;
  }
  vp44_communication_state_machine(CONCAT22(1,uVar3));
  if ((_DAT_0080c75c < -_DAT_0080c750 - 1U) &&
     (_DAT_0080c750 = _DAT_0080c75c + _DAT_0080c750, _DAT_0080c758 != -1)) {
    _DAT_0080c758 = _DAT_0080c758 + 1;
  }
  FUN_00015e96();
  FUN_0000c260();
  can1_canidmr2 = can1_canidmr2 & 0xfbff;
  return CONCAT44(CONCAT22(uVar4,uStack_22),in_D1);
}



//
// Function: FUN_00016622 @ 0x00016622
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00016622(int param_1,undefined4 param_2)

{
  short sVar1;
  uint unaff_A2;
  
  _DAT_0080c75c = param_1;
  _DAT_0080c764 = param_2._0_2_;
  sVar1 = FUN_0000def4(unaff_A2 >> 0x10);
  if (sVar1 != 0) {
    if (DAT_00807cce == _DAT_00800322) {
      DAT_0080c7b2 = '\x01';
    }
    else {
      if (DAT_0080c7b2 == '\x01') {
        DAT_0080c7b2 = '\x02';
      }
      if ((_current_engine_fuel_demand < time_to_delay_before_setting_a_new_throttle_min_0_25500) &&
         (_DAT_0080c7b8 < minimum_allowable_engine_speed_for_this_algorithm_to_operate_0_4500._0_1_)
         ) {
        _DAT_0080c7b8 = _DAT_0080c7b8 + 1;
      }
      else if (((DAT_0080c7b2 == '\x02') && (_DAT_0080c7a2 <= _DAT_0080c7a4)) ||
              ((DAT_0080c7b6 == '\x02' && (_DAT_0080c7a2 <= _DAT_0080c7a6)))) {
        _engine_fault_status_register_1 = _engine_fault_status_register_1 | 0x800;
        _engine_fault_status_register_2 = _engine_fault_status_register_2 | 0x800;
      }
    }
    _DAT_0080032a = _DAT_0080c75c;
    _DAT_00800322 = 0;
    _engine_fault_timer_1 = _DAT_0080c772;
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
  _engine_rpm_divisor_1 = _DAT_0080c75c + (_engine_rpm_divisor_1 - *_DAT_0080c41a);
  *_DAT_0080c41a = _DAT_0080c75c;
  if (_DAT_0080c41a < _DAT_0080c77e) {
    _DAT_0080c41a = _DAT_0080c41a + 1;
  }
  else {
    _DAT_0080c41a = (int *)&DAT_0080c430;
  }
  if (_DAT_0080c412 < -(uint)_DAT_00807cd2 - 1) {
    _DAT_0080c412 = _DAT_00807cd2 + _DAT_0080c412;
  }
  _engine_divisor_param_1 = _DAT_0080c75c + (_engine_divisor_param_1 - *_DAT_0080c786);
  if (_DAT_0080c786 < _DAT_0080c77e) {
    _DAT_0080c786 = _DAT_0080c786 + 1;
  }
  else {
    _DAT_0080c786 = (int *)&DAT_0080c430;
  }
  if (_DAT_0080c7a6 != 0 || _DAT_0080c7a4 != 0) {
    _engine_fault_timer_1 = _DAT_0080c772;
    return _DAT_00800322;
  }
  if ((_engine_fault_status_register_1 & 0x800) == 0) {
    _engine_fault_timer_1 = _DAT_0080c772;
    _DAT_0080c7b8 = 0;
    return _DAT_00800322;
  }
  if ((_engine_fault_status_register_2 & 0x800) != 0) {
    _engine_fault_timer_1 = _DAT_0080c772;
    _DAT_0080c7b8 = 0;
    return _DAT_00800322;
  }
  _engine_fault_status_register_1 = _engine_fault_status_register_1 & 0xf7ff;
  _engine_fault_timer_1 = _DAT_0080c772;
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
  
  uVar1 = vp44_status_flags_2 & 0x10;
  if (uVar1 != 0) {
    if (oil_pressure_mode_active_flag == 0) {
      if (_oil_pressure_mode_selector == 2) {
        _DAT_00800342 = engine_speed_for_transition_into_out_of_crank_reentr_state_0_300;
      }
      else {
        _DAT_00800342 = crank_exit_fuel_ramp_rpm_0_1000;
      }
      if (_active_derate_value < _DAT_00800342) {
        if (_DAT_0080c7c8 < determines_how_engine_position_is_sync_d_to_cam_0) {
          _DAT_0080c7c8 = _DAT_0080c7c8 + 1;
        }
      }
      else {
        _DAT_0080c7c8 = 0;
      }
      if (((_active_derate_value < crank_exit_fuel_ramp_rpm_0_1000) &&
          (determines_how_engine_position_is_sync_d_to_cam_0 <= _DAT_0080c7c8)) ||
         (_oil_pressure_mode_selector == 2)) {
        _DAT_0080c7ca = 0;
      }
      else if (_DAT_0080c7ca < _software_padding_0_255) {
        _DAT_0080c7ca = _DAT_0080c7ca + 1;
      }
      _DAT_00800346 = _DAT_00800344 - current_engine_rpm;
      _DAT_00800344 = current_engine_rpm;
      _DAT_0080c7c2 = FUN_00035608();
      if ((int)(uint)crank_exited_initial_rpm_offset_1000_1000 < (int)_DAT_0080c7c2) {
        if (_DAT_0080c7c0 < crank_exited_initial_fueling_offset_100_100) {
          _DAT_0080c7c0 = _DAT_0080c7c0 + 1;
        }
      }
      else {
        _DAT_0080c7c0 = 0;
      }
      FUN_0002c252();
      if (_oil_pressure_mode_selector == 0) {
        if ((((int)((uint)_calculated_fuel_timing_value - (uint)_software_padding_0) <=
              (int)(uint)_current_fuel_demand_value) && (_DAT_0080c7ce != 0)) &&
           (((DAT_0080bdc7 & 8) == 0 &&
            ((_DAT_0080926e < crank_exit_fuel_ramp_rate_maximum_0_100 &&
             (_DAT_008091ea < _DAT_00807f1c)))))) {
          fuel_timing_control_value = 0x4000;
          _oil_pressure_mode_selector = 2;
        }
        if ((((((vp44_status_flags_2 & 0x20) != 0) && ((DAT_0080bdc7 & 8) == 0)) &&
             (_DAT_0080c7cc != 0)) &&
            ((_DAT_0080965a < crank_jumpstart_rpm_ramp_rate_0_1000 &&
             (crank_exit_fuel_ramp_rpm_0_1000 <= _active_derate_value)))) &&
           ((_DAT_0080926e < crank_exit_fuel_ramp_rate_maximum_0_100 &&
            (_DAT_008091ea < _DAT_00807f1c)))) {
          fuel_timing_control_value = crank_exit_fuel_ramp_rate_0_100;
          _oil_pressure_mode_selector = 1;
        }
      }
      else if (_oil_pressure_mode_selector == 2) {
        if (((_DAT_0080c7ce != 0) || (_DAT_00807f1e < _DAT_0080926e)) ||
           (_DAT_00807f20 < _DAT_008091ea)) {
          fuel_timing_control_value = 0;
          _oil_pressure_mode_selector = 0;
        }
      }
      else if (_oil_pressure_mode_selector == 1) {
        if ((((_DAT_0080c7cc != 0) || (crank_jumpstart_rpm_ramp_rate_0_1000 <= _DAT_0080965a)) ||
            (determines_how_engine_position_is_sync_d_to_cam_0 <= _DAT_0080c7c8)) ||
           ((_DAT_00807f1e < _DAT_0080926e || (_DAT_00807f20 < _DAT_008091ea)))) {
          fuel_timing_control_value = 0;
          _oil_pressure_mode_selector = 0;
        }
      }
      else {
        fuel_timing_control_value = 0;
        _oil_pressure_mode_selector = 0;
      }
    }
    else {
      _oil_pressure_mode_selector = oil_pressure_override_mode;
      if (oil_pressure_override_mode == 0) {
        fuel_timing_control_value = 0;
      }
      else if (oil_pressure_override_mode == 2) {
        fuel_timing_control_value = 0x4000;
      }
      else {
        fuel_timing_control_value = crank_exit_fuel_ramp_rate_0_100;
      }
    }
    uVar1 = 0x4000 - fuel_timing_control_value;
    _fuel_timing_mode_selector = uVar1;
  }
  return uVar1;
}



//
// Function: FUN_00016af2 @ 0x00016af2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00016af2(void)

{
  _oil_pressure_mode_selector = 0;
  _DAT_0080033e = 0x80000000;
  _DAT_0080033a = &crank_exit_time_0_13107;
  return;
}



//
// Function: oilPressureModeParameterPointerConfig @ 0x00016b0e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort oilPressureModeParameterPointerConfig(void)

{
  ushort uVar1;
  
  uVar1 = vp44_status_flags_2 & 0x10;
  if ((vp44_status_flags_2 & 0x10) != 0) {
    if (_oil_pressure_mode_selector == 0) {
      param_pointer_set_1 = 0x807f2a;
      param_pointer_set_2 = 0x807f2c;
      param_pointer_set_3 =
           (dword)&max_crank_sync_backup_error_count_crank_sync_backup_errors_b_0_255;
      return 0;
    }
    if (_oil_pressure_mode_selector == 2) {
      param_pointer_set_1 =
           (dword)&max_cam_sync_backup_error_count_of_cam_sync_backup_errors_be_0_255;
      param_pointer_set_2 =
           (dword)&time_to_reach_full_derate_during_engine_protection_fuelin_0_0039_256;
      param_pointer_set_3 =
           (dword)&period_of_time_after_powerup_during_which_no_oil_pres_faults_0_255;
      return 2;
    }
    if (_oil_pressure_mode_selector == 1) {
      param_pointer_set_1 =
           (dword)&fills_hole_left_by_making_engine_protection_rpm_delta_a_globa_0_3000;
      param_pointer_set_2 = (dword)&EPMXDQRP;
      param_pointer_set_3 = (dword)&maximum_rpm_limit_filter_time_constant_0_1_0;
      return 1;
    }
    param_pointer_set_1 = 0x807f2a;
    param_pointer_set_2 = 0x807f2c;
    param_pointer_set_3 = (dword)&max_crank_sync_backup_error_count_crank_sync_backup_errors_b_0_255
    ;
    uVar1 = _oil_pressure_mode_selector;
  }
  return uVar1;
}



//
// Function: FUN_00016ba8 @ 0x00016ba8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00016ba8(void)

{
  int *piVar1;
  
  can1_canidmr1 = can1_canidmr1 & 0xfff3;
  can1_cantbsel = can1_cantbsel & 0xfffd;
  can1_canidmr2 = can1_canidmr2 & 0xfffd;
  DAT_0080c7b2 = 0;
  DAT_0080c7b3 = 0;
  _DAT_0080c782 = (int *)((uint)DAT_00807ccf * 4 + 0x80c5bc);
  for (piVar1 = (int *)&DAT_0080c5c0; piVar1 <= _DAT_0080c782; piVar1 = piVar1 + 1) {
    *piVar1 = _DAT_00807cca;
  }
  _DAT_0080c78a = &DAT_0080c5c0;
  if (DAT_00807cd1 < 2) {
    _DAT_0080c41e = &DAT_0080c5c0;
  }
  else {
    _DAT_0080c41e = &DAT_0080c5c0 + (uint)DAT_00807cd1 * 4;
  }
  _engine_rpm_divisor_2 = _DAT_00807cca * (uint)DAT_00807ccf;
  _engine_divisor_param_2 = _DAT_00807cca * (uint)DAT_00807cd1;
  _DAT_00808ec6 = FUN_00016cb4;
  can1_cantxerr = can1_cantxerr & 0xff0f | 0xd0;
  _DAT_00ffff12 = 0x100;
  _DAT_00ffff16 = 0;
  _DAT_00ffff18 = 0;
  _DAT_00ffff10 = 0x4f;
  can1_canidar1 = can1_canidar1 & 0xfff3;
  can1_canidar3 = can1_canidar3 & 0xfff3 | 0xc;
  can1_cantbsel = can1_cantbsel | 2;
  can1_canidmr1 = can1_canidmr1 & 0xfff3 | 8;
  return;
}



//
// Function: FUN_00016cb4 @ 0x00016cb4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00016cb4(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  DAT_0080c7d0 = DAT_00ffff1b;
  _DAT_00ffff18 = 0;
  DAT_0080c7d4 = (undefined1)duty_cycle_short_term_log_time_period_1_0_1000_0;
  if (DAT_00ffff1b == DCMNHIES) {
    if (DAT_0080c7d2 == 0) {
      if (((_DAT_00805df2 & 1) != 0) && ((_DAT_00805e32 & 1) == 0)) {
        _DAT_00805df2 = _DAT_00805df2 & 0xfffe;
      }
    }
    else {
      DAT_0080c7d2 = DAT_0080c7d2 - 1;
    }
    if (_DAT_0080c7ae == fuel_rate_at_maximum_fueling_conditions_32000_450000) {
      DAT_0080c7b2 = 1;
      DAT_0080c7b3 = 1;
      if (((_engine_fault_status_register_1 & 0x800) != 0) &&
         ((_engine_fault_status_register_2 & 0x800) == 0)) {
        _engine_fault_status_register_1 = _engine_fault_status_register_1 & 0xf7ff;
      }
      if (DAT_0080c7d1 == 0) {
        if (((_DAT_00805df2 & 1) != 0) && ((_DAT_00805e32 & 1) == 0)) {
          _DAT_00805df2 = _DAT_00805df2 & 0xfffe;
        }
      }
      else {
        DAT_0080c7d1 = DAT_0080c7d1 - 1;
      }
    }
    else {
      DAT_0080c7b2 = 2;
      DAT_0080c7b3 = 2;
      _DAT_0080c7ae = fuel_rate_at_maximum_fueling_conditions_32000_450000;
      if (DAT_0080c7d1 < duty_cycle_monitor_DCMNESTB_00807d1e.rpm_thresholds._0_1_) {
        DAT_0080c7d1 = DAT_0080c7d1 + 1;
      }
      else {
        _DAT_00805df2 = _DAT_00805df2 | 1;
        _DAT_00805e32 = _DAT_00805e32 | 1;
        _engine_fault_status_register_1 = _engine_fault_status_register_1 | 0x800;
        _engine_fault_status_register_2 = _engine_fault_status_register_2 | 0x800;
      }
    }
  }
  else if (DAT_00ffff1b == DCMNLOES) {
    if (DAT_0080c7d2 == 0) {
      if (((_DAT_00805df2 & 1) != 0) && ((_DAT_00805e32 & 1) == 0)) {
        _DAT_00805df2 = _DAT_00805df2 & 0xfffe;
      }
    }
    else {
      DAT_0080c7d2 = DAT_0080c7d2 - 1;
    }
    if (_DAT_0080c7ae == CPBS01) {
      DAT_0080c7b2 = 1;
      DAT_0080c7b3 = 1;
      if (((_engine_fault_status_register_1 & 0x800) != 0) &&
         ((_engine_fault_status_register_2 & 0x800) == 0)) {
        _engine_fault_status_register_1 = _engine_fault_status_register_1 & 0xf7ff;
      }
      if (DAT_0080c7d1 == 0) {
        if (((_DAT_00805df2 & 1) != 0) && ((_DAT_00805e32 & 1) == 0)) {
          _DAT_00805df2 = _DAT_00805df2 & 0xfffe;
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
        _DAT_00805df2 = _DAT_00805df2 | 1;
        _DAT_00805e32 = _DAT_00805e32 | 1;
        _engine_fault_status_register_1 = _engine_fault_status_register_1 | 0x800;
        _engine_fault_status_register_2 = _engine_fault_status_register_2 | 0x800;
      }
    }
  }
  else if (DAT_0080c7d2 < (byte)duty_cycle_monitor_DCMNESTB_00807d1e.rpm_thresholds) {
    DAT_0080c7d2 = DAT_0080c7d2 + 1;
  }
  else {
    _DAT_00805df2 = _DAT_00805df2 | 1;
    _DAT_00805e32 = _DAT_00805e32 | 1;
  }
  if ((_DAT_0080c760 < -_DAT_0080c754 - 1U) &&
     (_DAT_0080c754 = _DAT_0080c760 + _DAT_0080c754, _DAT_0080c75a != -1)) {
    _DAT_0080c75a = _DAT_0080c75a + 1;
  }
  FUN_0002b6c2();
  FUN_0000c262();
  can1_canidmr2 = can1_canidmr2 & 0xfffd;
  return CONCAT44(in_D0,in_D1);
}



//
// Function: FUN_00016f98 @ 0x00016f98
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00016f98(void)

{
  int *piVar1;
  
  can1_canidmr1 = can1_canidmr1 & 0xfff3;
  can1_cantbsel = can1_cantbsel & 0xfffd;
  can1_canidmr2 = can1_canidmr2 & 0xfffd;
  _DAT_0080c782 = (int *)((uint)DAT_00807ccf * 4 + 0x80c5bc);
  for (piVar1 = (int *)&DAT_0080c5c0; piVar1 <= _DAT_0080c782; piVar1 = piVar1 + 1) {
    *piVar1 = _DAT_00807cca;
  }
  _DAT_0080c78a = &DAT_0080c5c0;
  if (DAT_00807cd1 < 2) {
    _DAT_0080c41e = &DAT_0080c5c0;
  }
  else {
    _DAT_0080c41e = &DAT_0080c5c0 + (uint)DAT_00807cd1 * 4;
  }
  _engine_rpm_divisor_2 = _DAT_00807cca * (uint)DAT_00807ccf;
  _engine_divisor_param_2 = _DAT_00807cca * (uint)DAT_00807cd1;
  if ((_engine_system_status_flags & 8) != 0) {
    _DAT_00808ec6 = FUN_000170b4;
    can1_cantxerr = can1_cantxerr & 0xff0f | 0xd0;
    _DAT_00ffff12 = 0x100;
    _DAT_00ffff16 = 0;
    _DAT_00ffff18 = 0;
    _DAT_00ffff10 = 0xb;
    can1_canidar1 = can1_canidar1 & 0xfff3 | 0xc;
    can1_canidar3 = can1_canidar3 & 0xfff3 | 0xc;
    can1_cantbsel = can1_cantbsel | 2;
    can1_canidmr1 = can1_canidmr1 & 0xfff3 | 8;
    can1_canidmr2 = can1_canidmr2 & 0xfffd;
  }
  return CONCAT22((short)(_DAT_00807cca * (uint)DAT_00807cd1 >> 0x10),_engine_system_status_flags) &
         0xffff0008;
}



//
// Function: FUN_000170b4 @ 0x000170b4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000170b4(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  if ((_engine_system_status_flags & 8) != 0) {
    _engine_fault_timer_2 = _DAT_0080c774;
    _DAT_0080c760 = _DAT_00ffff18;
    DAT_0080c7b4 = 1;
    if (((_engine_fault_status_register_1 & 0x800) != 0) &&
       ((_engine_fault_status_register_2 & 0x800) == 0)) {
      _engine_fault_status_register_1 = _engine_fault_status_register_1 & 0xf7ff;
    }
    _DAT_0080c5c0 = _DAT_00ffff18;
    _engine_divisor_param_2 = _DAT_00ffff18;
  }
  _DAT_00ffff18 = _DAT_00ffff18 & 0xffff;
  if ((_DAT_0080c760 < -_DAT_0080c754 - 1U) &&
     (_DAT_0080c754 = _DAT_0080c760 + _DAT_0080c754, _DAT_0080c75a != -1)) {
    _DAT_0080c75a = _DAT_0080c75a + 1;
  }
  FUN_0002b6c2();
  FUN_0000c262();
  can1_canidmr2 = can1_canidmr2 & 0xfffd;
  return CONCAT44(in_D0,in_D1);
}



//
// Function: FUN_00017164 @ 0x00017164
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00017164(void)

{
  int *piVar1;
  
  _DAT_0080c782 = (int *)((uint)DAT_00807ccf * 4 + 0x80c5bc);
  for (piVar1 = (int *)&DAT_0080c5c0; piVar1 <= _DAT_0080c782; piVar1 = piVar1 + 1) {
    *piVar1 = _DAT_00807cca;
  }
  _DAT_0080c78a = &DAT_0080c5c0;
  if (DAT_00807cd1 < 2) {
    _DAT_0080c41e = &DAT_0080c5c0;
  }
  else {
    _DAT_0080c41e = &DAT_0080c5c0 + (uint)DAT_00807cd1 * 4;
  }
  _engine_rpm_divisor_2 = _DAT_00807cca * (uint)DAT_00807ccf;
  _engine_divisor_param_2 = _DAT_00807cca * (uint)DAT_00807cd1;
  can1_canidmr2 = can1_canidmr2 & 0xfffd;
  can1_cantxerr = can1_cantxerr & 0xff0f | 0xd0;
  _DAT_00ffff12 = 0x100;
  _DAT_00ffff16 = 0;
  _DAT_00ffff18 = 0;
  _DAT_00ffff10 = 0xb;
  can1_canidar1 = can1_canidar1 & 0xfff3 | 0xc;
  can1_canidar3 = can1_canidar3 & 0xfff3 | 0xc;
  can1_canidmr1 = can1_canidmr1 & 0xfff3 | 8;
  _DAT_00808ec6 = FUN_00017278;
  can1_cantbsel = can1_cantbsel & 0xfffd | 2;
  DAT_0080c7de = 0;
  _DAT_0080c7e4 = 0;
  return;
}



//
// Function: FUN_00017278 @ 0x00017278
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00017278(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  if ((_DAT_0080c760 < -_DAT_0080c754 - 1U) &&
     (_DAT_0080c754 = _DAT_0080c760 + _DAT_0080c754, _DAT_0080c75a != -1)) {
    _DAT_0080c75a = _DAT_0080c75a + 1;
  }
  FUN_0002b6c2();
  FUN_0000c262();
  can1_canidmr2 = can1_canidmr2 & 0xfffd;
  return CONCAT44(in_D0,in_D1);
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
  FUN_0001b314();
  FUN_0001afe4();
  FUN_0001d29c();
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
// Function: FUN_00017366 @ 0x00017366
//

void FUN_00017366(void)

{
  engine_fault_monitoring_and_rpm_calculation();
  FUN_0001e462();
  FUN_0000a6fa();
  FUN_00011a0a();
  FUN_00013f06();
  FUN_00030c78();
  FUN_00014174();
  FUN_00013930();
  FUN_0002fce4();
  FUN_00017d40();
  FUN_000181ea();
  FUN_00033c48();
  return;
}



//
// Function: FUN_000173b0 @ 0x000173b0
//

void FUN_000173b0(void)

{
  FUN_00013bd8();
  FUN_00014090();
  FUN_0002bbc0();
  FUN_00013240();
  FUN_0000b0ce();
  FUN_0002f7ac();
  FUN_00033c84();
  FUN_0001842c();
  FUN_00033dca();
  FUN_00030ac0();
  FUN_00030d40();
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
// Function: FUN_000173f6 @ 0x000173f6
//

void FUN_000173f6(void)

{
  engineParameterControllerWithTimer();
  boostPressureFeedbackController();
  return;
}



//
// Function: FUN_00017404 @ 0x00017404
//

void FUN_00017404(void)

{
  FUN_0002dc1e();
  FUN_0002de2e();
  return;
}



//
// Function: FUN_00017412 @ 0x00017412
//

void FUN_00017412(void)

{
  FUN_00031fb8();
  FUN_0002f96e();
  FUN_0002c4f0();
  return;
}



//
// Function: FUN_00017426 @ 0x00017426
//

void FUN_00017426(void)

{
  FUN_0002e3ee();
  FUN_0002d7b4();
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
// Function: FUN_0001743c @ 0x0001743c
//

void FUN_0001743c(void)

{
  return;
}



//
// Function: FUN_0001743e @ 0x0001743e
//

void FUN_0001743e(void)

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
// Function: FUN_0001744e @ 0x0001744e
//

void FUN_0001744e(void)

{
  FUN_0000a44c();
  FUN_0000a32a();
  return;
}



//
// Function: FUN_0001745c @ 0x0001745c
//

void FUN_0001745c(void)

{
  FUN_0001ae20();
  return;
}



//
// Function: FUN_00017464 @ 0x00017464
//

void FUN_00017464(void)

{
  FUN_000202a4();
  return;
}



//
// Function: FUN_0001746c @ 0x0001746c
//

void FUN_0001746c(void)

{
  FUN_000265be();
  FUN_000353ec();
  FUN_0003544a();
  FUN_00035228();
  return;
}



//
// Function: FUN_00017486 @ 0x00017486
//

void FUN_00017486(void)

{
  FUN_0001e140();
  return;
}



//
// Function: FUN_0001748e @ 0x0001748e
//

void FUN_0001748e(void)

{
  FUN_0001d7d2();
  return;
}



//
// Function: FUN_00017496 @ 0x00017496
//

ulonglong FUN_00017496(void)

{
  ulonglong uVar1;
  
  uVar1 = FUN_0000b47e();
  return uVar1;
}



//
// Function: FUN_0001749e @ 0x0001749e
//

void FUN_0001749e(void)

{
  FUN_00012484();
  return;
}



//
// Function: FUN_000174a6 @ 0x000174a6
//

void FUN_000174a6(void)

{
  FUN_0000caa8();
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
  FUN_0000c8c2();
  FUN_000343f8();
  FUN_000344e8();
  return;
}



//
// Function: advancedEngineProtectionCoordinator @ 0x000174dc
//

void advancedEngineProtectionCoordinator(void)

{
  FUN_0001f4f8();
  FUN_0002dfd0();
  FUN_00034976();
  FUN_00034a32();
  FUN_00034b46();
  return;
}



//
// Function: FUN_000174fc @ 0x000174fc
//

void FUN_000174fc(void)

{
  FUN_00031768();
  return;
}



//
// Function: FUN_00017504 @ 0x00017504
//

void FUN_00017504(void)

{
  FUN_0001ef18();
  FUN_0001ee5c();
  return;
}



//
// Function: FUN_00017512 @ 0x00017512
//

void FUN_00017512(void)

{
  FUN_000107a4();
  FUN_0002f662();
  FUN_00034d16();
  FUN_00034d9e();
  return;
}



//
// Function: FUN_0001752c @ 0x0001752c
//

void FUN_0001752c(void)

{
  FUN_0001f1fa();
  return;
}



//
// Function: FUN_00017534 @ 0x00017534
//

void FUN_00017534(void)

{
  FUN_00032c1c();
  return;
}



//
// Function: FUN_0001753c @ 0x0001753c
//

void FUN_0001753c(void)

{
  FUN_0001f8aa();
  return;
}



//
// Function: FUN_00017544 @ 0x00017544
//

void FUN_00017544(void)

{
  FUN_0001e210();
  return;
}



//
// Function: FUN_0001754c @ 0x0001754c
//

ulonglong FUN_0001754c(void)

{
  ulonglong uVar1;
  
  uVar1 = FUN_0000e478();
  return uVar1;
}



//
// Function: FUN_00017554 @ 0x00017554
//

void FUN_00017554(void)

{
  FUN_0002eeac();
  FUN_00018c62();
  FUN_00033e0e();
  return;
}



//
// Function: FUN_00017568 @ 0x00017568
//

void FUN_00017568(void)

{
  FUN_00034782();
  return;
}



//
// Function: FUN_00017570 @ 0x00017570
//

void FUN_00017570(void)

{
  FUN_00031306();
  FUN_000311ea();
  return;
}



//
// Function: FUN_0001757e @ 0x0001757e
//

void FUN_0001757e(void)

{
  FUN_00034e7a();
  return;
}



//
// Function: FUN_00017586 @ 0x00017586
//

void FUN_00017586(void)

{
  return;
}



//
// Function: FUN_00017588 @ 0x00017588
//

void FUN_00017588(void)

{
  FUN_00032380();
  return;
}



//
// Function: FUN_00017590 @ 0x00017590
//

void FUN_00017590(void)

{
  FUN_000309da();
  FUN_0002ff3a();
  return;
}



//
// Function: FUN_0001759e @ 0x0001759e
//

void FUN_0001759e(void)

{
  FUN_0003211a();
  return;
}



//
// Function: FUN_000175a6 @ 0x000175a6
//

void FUN_000175a6(void)

{
  FUN_00032b16();
  FUN_0002880e();
  FUN_0002e8f2();
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
  switch(_main_loop_phase_index) {
  case 0:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    vp44_engine_management_system();
    empty_debug_hook();
    rpm_control_system();
    vp44ControlSystemCoordinator();
    incrementCounters();
    _scheduler_phase_pointer = &scheduler_phase_table;
    _main_loop_phase_index = 1;
    break;
  case 1:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    engine_control_cycle();
    FUN_000173f6();
    FUN_0001744e();
    vp44ExtendedFaultDetectionCoordinator();
    FUN_0000c368();
    _main_loop_phase_index = 2;
    break;
  case 2:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    FUN_00017366();
    FUN_00017404();
    FUN_0001745c();
    advancedEngineProtectionCoordinator();
    FUN_000283dc();
    _main_loop_phase_index = 3;
    break;
  case 3:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    FUN_000173b0();
    FUN_00017412();
    FUN_00017464();
    FUN_000174fc();
    _main_loop_phase_index = 4;
    break;
  case 4:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    vp44_engine_management_system();
    FUN_00017426();
    FUN_0001746c();
    FUN_00017504();
    FUN_00026ff4();
    _main_loop_phase_index = 5;
    break;
  case 5:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    engine_control_cycle();
    boost_pressure_control_wrapper();
    FUN_00017486();
    FUN_00017512();
    _main_loop_phase_index = 6;
    break;
  case 6:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    FUN_00017366();
    FUN_0001743c();
    FUN_0001748e();
    FUN_0001752c();
    FUN_0000eb5a();
    _main_loop_phase_index = 7;
    break;
  case 7:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    FUN_000173b0();
    FUN_0001743e();
    FUN_00017496();
    FUN_00017534();
    FUN_0002bb6c();
    _main_loop_phase_index = 8;
    break;
  case 8:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    vp44_engine_management_system();
    empty_debug_hook();
    FUN_0001749e();
    FUN_0001753c();
    FUN_0000fd68();
    _main_loop_phase_index = 9;
    break;
  case 9:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    engine_control_cycle();
    FUN_000173f6();
    FUN_000174a6();
    FUN_00017544();
    FUN_0000b18c();
    _main_loop_phase_index = 10;
    break;
  case 10:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    FUN_00017366();
    FUN_00017404();
    rpm_control_system();
    FUN_0001754c();
    FUN_00026d98();
    _main_loop_phase_index = 0xb;
    break;
  case 0xb:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    FUN_000173b0();
    FUN_00017412();
    FUN_0001744e();
    FUN_00017554();
    FUN_00013f46();
    _main_loop_phase_index = 0xc;
    break;
  case 0xc:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    vp44_engine_management_system();
    FUN_00017426();
    FUN_0001745c();
    FUN_00017568();
    FUN_00013fe2();
    _main_loop_phase_index = 0xd;
    break;
  case 0xd:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    engine_control_cycle();
    boost_pressure_control_wrapper();
    FUN_00017464();
    FUN_00017570();
    FUN_0001403e();
    _main_loop_phase_index = 0xe;
    break;
  case 0xe:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    FUN_00017366();
    FUN_0001743c();
    FUN_0001746c();
    FUN_0001757e();
    FUN_000183a6();
    _main_loop_phase_index = 0xf;
    break;
  case 0xf:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    FUN_000173b0();
    FUN_0001743e();
    FUN_00017486();
    FUN_00017586();
    FUN_0001e36a();
    FUN_0002fd74();
    FUN_00014546();
    _main_loop_phase_index = 0x10;
    break;
  case 0x10:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    vp44_engine_management_system();
    empty_debug_hook();
    FUN_0001748e();
    FUN_00017588();
    FUN_00018428();
    _main_loop_phase_index = 0x11;
    break;
  case 0x11:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    engine_control_cycle();
    FUN_000173f6();
    FUN_00017496();
    FUN_00017590();
    _main_loop_phase_index = 0x12;
    break;
  case 0x12:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    FUN_00017366();
    FUN_00017404();
    FUN_0001749e();
    FUN_0001759e();
    FUN_00031c60();
    _main_loop_phase_index = 0x13;
    break;
  case 0x13:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    FUN_000173b0();
    FUN_00017412();
    FUN_000174a6();
    FUN_000175a6();
    _main_loop_phase_index = 0x14;
    break;
  case 0x14:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    vp44_engine_management_system();
    FUN_00017426();
    rpm_control_system();
    vp44ControlSystemCoordinator();
    _main_loop_phase_index = 0x15;
    break;
  case 0x15:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    engine_control_cycle();
    boost_pressure_control_wrapper();
    FUN_0001744e();
    vp44ExtendedFaultDetectionCoordinator();
    _main_loop_phase_index = 0x16;
    break;
  case 0x16:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    FUN_00017366();
    FUN_0001743c();
    FUN_0001745c();
    advancedEngineProtectionCoordinator();
    _main_loop_phase_index = 0x17;
    break;
  case 0x17:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    FUN_000173b0();
    FUN_0001743e();
    FUN_00017464();
    FUN_000174fc();
    _main_loop_phase_index = 0x18;
    break;
  case 0x18:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    vp44_engine_management_system();
    empty_debug_hook();
    FUN_0001746c();
    FUN_00017504();
    _main_loop_phase_index = 0x19;
    break;
  case 0x19:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    engine_control_cycle();
    FUN_000173f6();
    FUN_00017486();
    FUN_00017512();
    _main_loop_phase_index = 0x1a;
    break;
  case 0x1a:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    FUN_00017366();
    FUN_00017404();
    FUN_0001748e();
    FUN_0001752c();
    _main_loop_phase_index = 0x1b;
    break;
  case 0x1b:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    FUN_000173b0();
    FUN_00017412();
    FUN_00017496();
    FUN_00017534();
    _main_loop_phase_index = 0x1c;
    break;
  case 0x1c:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    vp44_engine_management_system();
    FUN_00017426();
    FUN_0001749e();
    FUN_0001753c();
    _main_loop_phase_index = 0x1d;
    break;
  case 0x1d:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    engine_control_cycle();
    boost_pressure_control_wrapper();
    FUN_000174a6();
    FUN_00017544();
    _main_loop_phase_index = 0x1e;
    break;
  case 0x1e:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    FUN_00017366();
    FUN_0001743c();
    rpm_control_system();
    FUN_0001754c();
    _main_loop_phase_index = 0x1f;
    break;
  case 0x1f:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    FUN_000173b0();
    FUN_0001743e();
    FUN_0001744e();
    FUN_00017554();
    _main_loop_phase_index = 0x20;
    break;
  case 0x20:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    vp44_engine_management_system();
    empty_debug_hook();
    FUN_0001745c();
    FUN_00017568();
    _main_loop_phase_index = 0x21;
    break;
  case 0x21:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    engine_control_cycle();
    FUN_000173f6();
    FUN_00017464();
    FUN_00017570();
    _main_loop_phase_index = 0x22;
    break;
  case 0x22:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    FUN_00017366();
    FUN_00017404();
    FUN_0001746c();
    FUN_0001757e();
    _main_loop_phase_index = 0x23;
    break;
  case 0x23:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    FUN_000173b0();
    FUN_00017412();
    FUN_00017486();
    FUN_00017586();
    _main_loop_phase_index = 0x24;
    break;
  case 0x24:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    vp44_engine_management_system();
    FUN_00017426();
    FUN_0001748e();
    FUN_00017588();
    _main_loop_phase_index = 0x25;
    break;
  case 0x25:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    engine_control_cycle();
    boost_pressure_control_wrapper();
    FUN_00017496();
    FUN_00017590();
    _main_loop_phase_index = 0x26;
    break;
  case 0x26:
    ioControlAndCanPinSwitchingWrapper();
    evenPhaseSchedulerTaskSet();
    FUN_00017366();
    FUN_0001743c();
    FUN_0001749e();
    FUN_0001759e();
    _main_loop_phase_index = 0x27;
    break;
  case 0x27:
    ioControlAndCanPinSwitchingWrapper();
    oddPhaseSchedulerTaskSet();
    FUN_000173b0();
    FUN_0001743e();
    FUN_000174a6();
    FUN_000175a6();
    _main_loop_phase_index = 0;
    break;
  default:
    _main_loop_phase_index = 0;
  }
  FUN_00017bf2();
  REG_SIM_SWSR = 0xaa;
  DAT_00ffd00f = 0xaa;
  return CONCAT44(in_D0,in_D1);
}



//
// Function: scheduler_init @ 0x00017b3a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void scheduler_init(void)

{
  schedule_armed = 0;
  _DAT_0080977a = 5;
  _DAT_0080977c = 200;
  _DAT_0080977e = 0x9b7;
  _DAT_00809780 = 500;
  _DAT_00809776 = 0;
  _main_loop_counter = 0;
  REG_SIM_PICR = 0x152;
  _main_loop_callback = main_loop;
  REG_SIM_PITR = 0x27;
  return;
}



//
// Function: mainLoopTaskSchedulerInit @ 0x00017b88
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mainLoopTaskSchedulerInit(void)

{
  scheduler_phase_table_t *psVar1;
  
  if (schedule_armed != 0) {
    if (_main_loop_counter == 0) {
      for (psVar1 = &scheduler_phase_table; psVar1 < (scheduler_phase_table_t *)0x809a02;
          psVar1 = psVar1 + 1) {
        (psVar1->phase_slots).last_execution_time = 0;
        (psVar1->phase_slots).runtime_ticks = 0;
        (psVar1->phase_slots).deadline_ticks = 0xffff;
        (psVar1->phase_slots).execution_count = 0;
        (psVar1->phase_slots).overrun_count = 0;
      }
      _DAT_00809770 = 0;
      _DAT_00809772 = 0;
      _main_loop_counter = 1;
    }
    _DAT_0080035a = hardware_timer_register._0_2_;
    return;
  }
  _main_loop_counter = 0;
  return;
}



//
// Function: FUN_00017bf2 @ 0x00017bf2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00017bf2(void)

{
  if (schedule_armed != 0) {
    _DAT_00800354 = hardware_timer_register._0_2_ - _DAT_0080035a;
    if (*(ushort *)(_scheduler_phase_pointer + 2) < _DAT_00800354) {
      *(ushort *)(_scheduler_phase_pointer + 2) = _DAT_00800354;
    }
    if (_DAT_00800354 < *(ushort *)((int)_scheduler_phase_pointer + 6)) {
      *(ushort *)((int)_scheduler_phase_pointer + 6) = _DAT_00800354;
    }
    *_scheduler_phase_pointer = (uint)_DAT_00800354 + *_scheduler_phase_pointer;
    *(short *)(_scheduler_phase_pointer + 1) = *(short *)(_scheduler_phase_pointer + 1) + 1;
    if ((_DAT_0080977e < _DAT_00800354) &&
       (*(short *)((int)_scheduler_phase_pointer + 10) =
             *(short *)((int)_scheduler_phase_pointer + 10) + 1, _DAT_00809770 != -1)) {
      _DAT_00809770 = _DAT_00809770 + 1;
    }
    _scheduler_phase_pointer = _scheduler_phase_pointer + 4;
  }
  return;
}



//
// Function: FUN_00017c6e @ 0x00017c6e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00017c6e(void)

{
  while (_DAT_0080c812 == 0) {
    if (schedule_armed != 0) {
      for (_DAT_00809778 = 0; _DAT_00809778 < _DAT_00809776; _DAT_00809778 = _DAT_00809778 + 1) {
      }
      _DAT_00809772 = _DAT_00809772 + 1;
    }
  }
  return;
}



//
// Function: FUN_00017ca6 @ 0x00017ca6
//

uint FUN_00017ca6(uint *param_1,undefined4 param_2)

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
// Function: FUN_00017ce2 @ 0x00017ce2
//

uint FUN_00017ce2(uint *param_1,undefined1 *param_2)

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
// Function: FUN_00017d1a @ 0x00017d1a
//

void FUN_00017d1a(undefined4 *param_1,undefined4 param_2,uint param_3)

{
  param_1[2] = param_2;
  param_1[1] = param_2;
  *param_1 = param_2;
  param_1[3] = param_1[2] + (param_3 >> 0x10);
  *(undefined1 *)(param_1 + 4) = 0;
  return;
}



//
// Function: FUN_00017d40 @ 0x00017d40
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_00017d40(void)

{
  ushort uVar1;
  ushort unaff_D2w;
  
  uVar1 = _DAT_008035d6 & 0x10;
  if (uVar1 == 0) {
    uVar1 = FUN_0002f884();
  }
  else {
    _DAT_0080d494 = _DAT_0080379e;
    _DAT_0080d496 = 0xd;
  }
  if (engine_operating_mode == IDLE) {
    _current_fuel_demand_value = 0;
    _DAT_0080c9a6 = 0x1a;
  }
  else {
    if (engine_operating_mode == FAULT_EMERGENCY) {
      _DAT_0080c9a6 = 0x1b;
      _current_fuel_demand_value = mask_used_for_can_msg_object_15_0_ffffffff._0_2_;
    }
    else if (engine_operating_mode == HIGH_PERFORMANCE) {
      _DAT_0080c9a6 = 0x19;
      _current_fuel_demand_value = intercept_fueling_between_hsg_brkpt_and_the_epf_curve_0_100;
    }
    else {
      uVar1 = _DAT_008035d6 & 2;
      if (uVar1 == 0) {
        if (engine_operating_mode == VP44_INJECTION_ACTIVE) {
          _DAT_0080c9a6 = 0x18;
          _current_fuel_demand_value = intercept_fueling_between_lsg_ref_and_the_epf_curve_0_100;
        }
        else if ((engine_operating_mode == LOW_RPM_RUNNING) ||
                (engine_operating_mode == TRANSITIONAL_MODE_6)) {
          _DAT_0080c9a6 = 0x16;
          _current_fuel_demand_value = _DAT_0080c7e8;
        }
        else if (engine_operating_mode == HIGH_RPM_RUNNING) {
          if ((_DAT_00800360 == 2) || (_DAT_00800360 == 6)) {
            uVar1 = FUN_0001e78e();
            _diagnostic_rpm_threshold_status = _DAT_0080c7e8;
          }
          if (((diagnostic_state_buffer_t_00809654.diagnostic_mode == 0xb) &&
              (_DAT_0080d496 == 0x14)) ||
             (uVar1 = _diagnostic_rpm_threshold_status,
             _diagnostic_rpm_threshold_status < _DAT_0080d494)) {
            _DAT_0080c9a6 = diagnostic_state_buffer_t_00809654.diagnostic_mode;
            _current_fuel_demand_value = _diagnostic_rpm_threshold_status;
          }
          else {
            _DAT_0080c9a6 = _DAT_0080d496;
            _current_fuel_demand_value = _DAT_0080d494;
          }
        }
        else {
          _current_fuel_demand_value = unaff_D2w;
          if (engine_operating_mode == TRANSITIONAL_MODE_7) {
            if (((diagnostic_state_buffer_t_00809654.diagnostic_mode == 0xb) &&
                (_DAT_0080d496 == 0x14)) ||
               (uVar1 = _diagnostic_rpm_threshold_status,
               _diagnostic_rpm_threshold_status < _DAT_0080d494)) {
              _DAT_0080c9a6 = diagnostic_state_buffer_t_00809654.diagnostic_mode;
              _current_fuel_demand_value = _diagnostic_rpm_threshold_status;
            }
            else {
              _DAT_0080c9a6 = _DAT_0080d496;
              _current_fuel_demand_value = _DAT_0080d494;
            }
            if (_current_fuel_demand_value < _DAT_0080c7e8) {
              _DAT_0080c9a6 = 0x16;
              _current_fuel_demand_value = _DAT_0080c7e8;
            }
          }
        }
      }
      else {
        _DAT_0080c9a6 = 0x17;
        _current_fuel_demand_value = _DAT_008037a0;
      }
    }
    if (max_number_of_shutdowns_before_restart_is_not_allowed_0_255 < _current_fuel_demand_value) {
      _current_fuel_demand_value = max_number_of_shutdowns_before_restart_is_not_allowed_0_255;
    }
    else if (_current_fuel_demand_value < mask_used_for_can_msg_object_15_0_ffffffff._0_2_) {
      _current_fuel_demand_value = mask_used_for_can_msg_object_15_0_ffffffff._0_2_;
    }
  }
  _DAT_00800360 = engine_operating_mode;
  return uVar1;
}



//
// Function: FUN_00017ed4 @ 0x00017ed4
//

/* WARNING: Removing unreachable block (ram,0x00018018) */
/* WARNING: Removing unreachable block (ram,0x00018026) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00017ed4(void)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  
  REG_SIM_SWSR = 0xaa;
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
              REG_SIM_SWSR = 0xaa;
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
        REG_SIM_SWSR = 0xaa;
        DAT_00ffd00f = 0xaa;
        uVar2 = uVar2 + 1;
      } while (uVar2 < 0xa0);
      sVar3 = sVar3 + 1;
      uVar2 = uVar1;
    } while (sVar3 == 0);
  } while( true );
}



//
// Function: FUN_0001802e @ 0x0001802e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001802e(undefined4 param_1)

{
  undefined2 *puVar1;
  code *pcVar2;
  undefined1 auStack_804 [2048];
  
  _DAT_00800362 = param_1;
  puVar1 = (undefined2 *)auStack_804;
  for (pcVar2 = FUN_00017ed4; pcVar2 < FUN_0001802e; pcVar2 = pcVar2 + 2) {
    *puVar1 = *(undefined2 *)pcVar2;
    puVar1 = puVar1 + 1;
  }
  (*(code *)auStack_804)();
  return;
}



//
// Function: FUN_0001805c @ 0x0001805c
//

/* WARNING: Removing unreachable block (ram,0x00018104) */
/* WARNING: Removing unreachable block (ram,0x0001810e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0001805c(void)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = 0;
  while( true ) {
    REG_SIM_SWSR = 0xaa;
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
      REG_SIM_SWSR = 0xaa;
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
// Function: FUN_00018174 @ 0x00018174
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00018174(int param_1,undefined4 param_2,uint param_3)

{
  undefined2 *puVar1;
  code *pcVar2;
  undefined1 auStack_804 [2048];
  
  _DAT_00800366 = param_2;
  _DAT_00800362 = param_1;
  _DAT_0080036a = param_1 + (param_3 >> 0x10);
  puVar1 = (undefined2 *)auStack_804;
  for (pcVar2 = FUN_0001805c; pcVar2 < FUN_00018174; pcVar2 = pcVar2 + 2) {
    *puVar1 = *(undefined2 *)pcVar2;
    puVar1 = puVar1 + 1;
  }
  (*(code *)auStack_804)();
  return;
}



//
// Function: FUN_000181bc @ 0x000181bc
//

void FUN_000181bc(void)

{
  if (diagnostic_status_register == 0) {
    diagnostic_status_register = 8;
  }
  return;
}



//
// Function: diagnostic_parameter_handler @ 0x000181cc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnostic_parameter_handler(void)

{
  if (diagnostic_status_register == 8) {
    _diagnostic_parameter_buffer = activeParamReadFunction();
    cached_parameter_value = _diagnostic_parameter_buffer;
  }
  return;
}



//
// Function: FUN_000181ea @ 0x000181ea
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000181ea(void)

{
  short sVar1;
  short extraout_D0w;
  short extraout_D0w_00;
  ushort extraout_D0w_01;
  ushort extraout_D0w_02;
  
  if ((_DAT_008035dc & 0x100) == 0) {
    sVar1 = _current_fuel_demand_value;
    if (_DAT_0080ccf2 == 1) {
      _DAT_00800374 = _current_fuel_demand_value;
      sVar1 = lookupTableInterpolation((short *)&DAT_0080036e);
    }
    if (_DAT_0080965a == 0x4000) {
      _DAT_00800380 = current_engine_rpm;
      _DAT_00800388 = sVar1;
      tableInterpolationLookup((short *)&DAT_0080037a);
      _DAT_0080c9ac = extraout_D0w;
    }
    else if (_DAT_0080965a == 0) {
      _DAT_00800394 = current_engine_rpm;
      _DAT_0080039c = sVar1;
      tableInterpolationLookup((short *)&DAT_0080038e);
      _DAT_0080c9ac = extraout_D0w_00;
    }
    else {
      _DAT_00800380 = current_engine_rpm;
      _DAT_00800388 = sVar1;
      tableInterpolationLookup((short *)&DAT_0080037a);
      _DAT_00800394 = current_engine_rpm;
      _DAT_0080039c = sVar1;
      tableInterpolationLookup((short *)&DAT_0080038e);
      _DAT_0080c9ac =
           (short)((uint)_DAT_0080965a * (uint)extraout_D0w_01 >> 0xe) +
           (short)((uint)extraout_D0w_02 * (0x4000 - (uint)_DAT_0080965a) >> 0xe);
    }
    _DAT_0080c9b0 = 0;
  }
  else {
    _DAT_0080c9ac = _DAT_008037b2;
    _DAT_0080c9b0 = 2;
  }
  if ((_diagnostic_system_flags_2 & 0x4000) != 0) {
    _DAT_0080c9ac = _DAT_008037b0 + _DAT_0080c9ac;
    _DAT_0080c9b2 = 1;
  }
  _DAT_0080c9ae = _DAT_0080c9ac;
  FUN_0002f778();
  return;
}



//
// Function: FUN_0001832a @ 0x0001832a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001832a(void)

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
// Function: FUN_000183a6 @ 0x000183a6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000183a6(void)

{
  uint uVar1;
  
  if (_current_fuel_demand_value < _DAT_0080845a) {
    _DAT_0080c9cc = 0;
    return;
  }
  uVar1 = FUN_000357d2((uint)current_engine_rpm * 0x280,
                       (uint)_current_fuel_demand_value - (uint)_DAT_0080845a,
                       (uint)_DAT_0080845c * 0x1d7);
  if (31999 < uVar1) {
    _DAT_0080c9cc = 32000;
    return;
  }
  _DAT_0080c9cc = (short)uVar1;
  return;
}



//
// Function: FUN_00018428 @ 0x00018428
//

void FUN_00018428(void)

{
  return;
}



//
// Function: FUN_0001842a @ 0x0001842a
//

void FUN_0001842a(void)

{
  return;
}



//
// Function: FUN_0001842c @ 0x0001842c
//

ushort FUN_0001842c(void)

{
  ushort uVar1;
  
  uVar1 = vp44_communication_status & 1;
  if (((((vp44_communication_status & 1) != 0) && (engine_control_system_ready == 0)) &&
      ((vp44_injection_system_active == 0 ||
       (uVar1 = vp44_status_flags_1 & 0x40, (vp44_status_flags_1 & 0x40) == 0)))) &&
     (((engine_operating_mode == HIGH_PERFORMANCE &&
       (uVar1 = vp44_status_flags_2 & 2, (vp44_status_flags_2 & 2) == 0)) ||
      (engine_operating_mode != HIGH_PERFORMANCE)))) {
    can_pin_switching_control_flags = can_pin_switching_control_flags | 0x20;
    return uVar1;
  }
  can_pin_switching_control_flags = can_pin_switching_control_flags & 0xdf;
  return uVar1;
}



//
// Function: fuel_timing_calculation_with_fault_checking @ 0x0001848e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuel_timing_calculation_with_fault_checking(void)

{
  ushort uVar1;
  short sVar2;
  ushort unaff_D3w;
  ushort unaff_D4w;
  undefined8 uVar3;
  
  uVar1 = _fuel_timing_mode_selector;
  if (_fuel_timing_mode_selector != 0) {
    _rpm_input_for_fuel_table_1 = current_engine_rpm;
    uVar3 = tableInterpolationLookup((short *)&fuel_lookup_table_1_base);
    unaff_D4w = (ushort)((ulonglong)uVar3 >> 0x20);
  }
  if (uVar1 < 0x4000) {
    _rpm_input_for_fuel_table_2 = current_engine_rpm;
    uVar3 = tableInterpolationLookup((short *)&fuel_lookup_table_2_base);
    unaff_D3w = (ushort)((ulonglong)uVar3 >> 0x20);
  }
  _calculated_fuel_timing_value = unaff_D4w;
  if ((uVar1 != 0x4000) && (_calculated_fuel_timing_value = unaff_D3w, uVar1 != 0)) {
    _calculated_fuel_timing_value =
         unaff_D3w + (short)((uint)uVar1 * ((uint)unaff_D4w - (uint)unaff_D3w) >> 0xe);
  }
  if (((((_vp44_flag_register_1 & 0x8000) == 0) ||
       (((_engine_fault_status_register_1 & 2) != 0 &&
        ((_engine_fault_confirmation_register & 2) != 0)))) ||
      (((_engine_fault_status_register_1 & 1) != 0 &&
       ((_engine_fault_confirmation_register & 1) != 0)))) ||
     (((_engine_fault_status_register_1 & 0x10) != 0 &&
      ((_engine_fault_confirmation_register & 0x10) != 0)))) {
    sVar2 = 0;
  }
  else {
    _fuel_correction_input = _DAT_0080926e;
    sVar2 = lookupTableInterpolation((short *)&fuel_correction_table_base);
  }
  _calculated_fuel_timing_value = sVar2 + _calculated_fuel_timing_value;
  if (_calculated_fuel_timing_value < mask_used_for_can_msg_object_15_0_ffffffff._0_2_) {
    _calculated_fuel_timing_value = mask_used_for_can_msg_object_15_0_ffffffff._0_2_;
  }
  return;
}



//
// Function: FUN_00018590 @ 0x00018590
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00018590(void)

{
  _DAT_008003b2 = 0x807f42;
  _fuel_lookup_table_1_base = 2;
  _DAT_008003be = 400;
  _DAT_008003ba = 0x807f68;
  _DAT_008003b8 = 2;
  _DAT_008003c0 = &lower_limitation_of_intake_manifold_temperature_to_inhibit_50_to_293;
  _DAT_008003c6 = 0x808002;
  _fuel_lookup_table_2_base = 2;
  _DAT_008003d2 = 400;
  _DAT_008003ce = 0x808028;
  _DAT_008003cc = 2;
  _DAT_008003d4 = 0x808032;
  _fuel_correction_input = _DAT_0080926e;
  _DAT_008003a6 = 0x808862;
  _DAT_008003ac = 0x808876;
  _fuel_correction_table_base = 2;
  return;
}



//
// Function: FUN_00018620 @ 0x00018620
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00018620(void)

{
  if (_calculated_fuel_timing_value < _DAT_0080d494) {
    _DAT_0080d494 = _calculated_fuel_timing_value;
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
  
  sVar1 = _fuel_delivery_target;
  if (diagnostic_state_buffer_t_00809654.diagnostic_mode == 0xc) {
    if (((int)((int)_number_of_engine_speed_targets_per_crankshaft_revolution_1_255 +
              (uint)_arbitrator_fuel_value_buffer) < (int)(uint)current_engine_rpm) &&
       (_diagnostic_rpm_threshold_status < _rpm_comparison_threshold)) {
      _final_fuel_delivery_command =
           (uint)engine_speed_above_which_the_overspeed_algorithm_disables_fue_0_4000 << 0x10;
      _fuel_delivery_target = 0;
      _fuel_delivery_status = -0x80000000;
    }
    else {
      _fuel_delivery_target = FUN_00035608();
      if (_fuel_delivery_max_limit < _fuel_delivery_target) {
        _fuel_delivery_target = _fuel_delivery_max_limit;
        _fuel_delivery_status = _fuel_delivery_max_limit * 0x10000 + -0x80000000;
      }
      else if (_fuel_delivery_target < _fuel_delivery_min_limit) {
        _fuel_delivery_target = _fuel_delivery_min_limit;
        _fuel_delivery_status = _fuel_delivery_min_limit * 0x10000 + -0x80000000;
      }
      _fuel_delivery_scaled =
           (short)(((int)_fuel_delivery_target * (int)_fuel_delivery_gain_factor) / 0x3c0);
      if ((int)_fuel_delivery_rate_limit_gain * ((int)_fuel_delivery_target - (int)sVar1) < 0x77ff10
         ) {
        iVar2 = ((int)_fuel_delivery_target - (int)sVar1) * (int)_fuel_delivery_rate_limit_gain;
        if (iVar2 < -0x77ffff) {
          _fuel_delivery_rate_delta = -0x8000;
        }
        else {
          _fuel_delivery_rate_delta = (short)(iVar2 / 0xf0);
        }
      }
      else {
        _fuel_delivery_rate_delta = 0x7fff;
      }
      iVar2 = (int)_fuel_delivery_target * (int)(short)(_fuel_delivery_offset_factor << 2) +
              _final_fuel_delivery_command;
      _final_fuel_delivery_command = (short)((uint)iVar2 >> 0x10);
      _final_fuel_delivery_command = _final_fuel_delivery_command - _fuel_delivery_offset_correction
      ;
      _fuel_delivery_command_low = (undefined2)iVar2;
      if (_final_fuel_delivery_command < (short)_fuel_delivery_upper_bound) {
        if (_final_fuel_delivery_command < (short)_fuel_delivery_lower_bound) {
          _final_fuel_delivery_command = (uint)_fuel_delivery_lower_bound << 0x10;
        }
      }
      else {
        _final_fuel_delivery_command = (uint)_fuel_delivery_upper_bound << 0x10;
      }
      _DAT_0080cc42 = _final_fuel_delivery_command;
      iVar2 = (int)_final_fuel_delivery_command +
              (int)_fuel_delivery_rate_delta + (int)_fuel_delivery_scaled;
      if ((int)(uint)intercept_of_rpm_vs_phase_lag_line_defining_time_offset_for_syn_0_16 < iVar2) {
        _DAT_0080cc3a = intercept_of_rpm_vs_phase_lag_line_defining_time_offset_for_syn_0_16;
      }
      else if (iVar2 < (int)(uint)
                            slope_of_rpm_vs_phase_lag_line_defining_time_offset_for_s_0_0_031136) {
        _DAT_0080cc3a = slope_of_rpm_vs_phase_lag_line_defining_time_offset_for_s_0_0_031136;
      }
      else {
        _DAT_0080cc3a = (word)iVar2;
      }
      _diagnostic_rpm_threshold_status = _DAT_0080cc3a;
    }
  }
  return;
}



//
// Function: FUN_0001883a @ 0x0001883a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001883a(void)

{
  _fuel_delivery_target =
       (short)((int)((int)_DAT_00808466 *
                    ((uint)_arbitrator_fuel_value_buffer - (uint)current_engine_rpm)) >> 9);
  if (_fuel_delivery_max_limit < _fuel_delivery_target) {
    _fuel_delivery_target = _fuel_delivery_max_limit;
  }
  else if (_fuel_delivery_target < _fuel_delivery_min_limit) {
    _fuel_delivery_target = _fuel_delivery_min_limit;
  }
  _fuel_delivery_status = _fuel_delivery_target * 0x10000 + -0x80000000;
  _final_fuel_delivery_command =
       _current_fuel_demand_value -
       (short)(((int)_fuel_delivery_target * (int)_fuel_delivery_gain_factor) / 0x3c0);
  if (_DAT_00808478 < _final_fuel_delivery_command) {
    _final_fuel_delivery_command = _DAT_00808478;
  }
  else if (_final_fuel_delivery_command < _DAT_00808476) {
    _final_fuel_delivery_command = _DAT_00808476;
  }
  _fuel_delivery_command_low = 0;
  if (_DAT_0080847e != 0) {
    fuel_delivery_controller();
  }
  return;
}



//
// Function: FUN_000188f6 @ 0x000188f6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000188f6(void)

{
  _fuel_delivery_gain_factor = _DAT_0080845e;
  _fuel_delivery_offset_factor = _DAT_00808462;
  _fuel_delivery_rate_limit_gain = _DAT_00808460;
  _fuel_delivery_status = 0x80000000;
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
  word wVar2;
  
  if (_arbitrator_special_mode_flag == 1) {
    _arbitrator_fuel_value_buffer = _diagnostic_mode_parameter;
    _arbitrator_active_limit_priority = 8;
    _arbitrator_status_flag = 0;
    return;
  }
  _DAT_0080cc54 = *(ushort *)param_pointer_set_1;
  _DAT_0080cc56 = *(ushort *)param_pointer_set_2;
  _DAT_0080cc58 = *(ushort *)param_pointer_set_3;
  if (_DAT_0080cc54 < _fuel_arbitrator_threshold_1) {
    _arbitrator_active_limit_priority = 6;
    _arbitrated_fuel_limit = _DAT_0080cc54;
  }
  else {
    _arbitrated_fuel_limit = _fuel_arbitrator_threshold_1;
    _arbitrator_active_limit_priority = 5;
  }
  if ((_fuel_arbitrator_condition_flag == 3) &&
     (_fuel_arbitrator_conditional_limit <= _arbitrated_fuel_limit)) {
    _arbitrated_fuel_limit = _fuel_arbitrator_conditional_limit;
    _arbitrator_active_limit_priority = 9;
  }
  if (_fuel_arbitrator_threshold_2 <= _arbitrated_fuel_limit) {
    _arbitrated_fuel_limit = _fuel_arbitrator_threshold_2;
    _arbitrator_active_limit_priority = 4;
  }
  if (_fuel_arbitrator_threshold_3 <= _arbitrated_fuel_limit) {
    _arbitrated_fuel_limit = _fuel_arbitrator_threshold_3;
    _arbitrator_active_limit_priority = 3;
  }
  if (_fuel_arbitrator_threshold_4 <= _arbitrated_fuel_limit) {
    _arbitrated_fuel_limit = _fuel_arbitrator_threshold_4;
    _arbitrator_active_limit_priority = 2;
  }
  if (_fuel_arbitrator_threshold_5 <= _arbitrated_fuel_limit) {
    _arbitrated_fuel_limit = _fuel_arbitrator_threshold_5;
    _arbitrator_active_limit_priority = 1;
  }
  if (_fuel_arbitrator_threshold_6 <= _arbitrated_fuel_limit) {
    _arbitrated_fuel_limit = _fuel_arbitrator_threshold_6;
    _arbitrator_active_limit_priority = 7;
  }
  if (true_oil_pressure_precrank_error_1_true_0_false <= _arbitrated_fuel_limit) {
    _arbitrated_fuel_limit = true_oil_pressure_precrank_error_1_true_0_false;
    _arbitrator_active_limit_priority = 0xb;
  }
  if (allowed_rate_of_torque_limit_change_0_2000 < _arbitrated_fuel_limit) {
    _arbitrated_fuel_limit = allowed_rate_of_torque_limit_change_0_2000;
  }
  if (_arbitrator_active_limit_priority == 9) {
    if ((uint)_arbitrated_fuel_limit < (uint)_DAT_00806e1a + (uint)_DAT_0080d092) {
      _arbitrated_fuel_limit = _DAT_00806e1a + _DAT_0080d092;
    }
  }
  else if (_arbitrated_fuel_limit < _DAT_0080848a) {
    _arbitrated_fuel_limit = _DAT_0080848a;
  }
  if (_DAT_0080cc5a < _arbitrated_fuel_limit) {
    _DAT_0080cc5a =
         number_of_consecutive_occurances_of_powerdown_data_lost_to_set_1_255 + _DAT_0080cc5a;
  }
  if (_arbitrated_fuel_limit < _DAT_0080cc5a) {
    _DAT_0080cc5a = _arbitrated_fuel_limit;
  }
  if (((_DAT_0080cc58 != 0) && (_DAT_0080cc56 != 0)) &&
     ((_arbitrator_active_limit_priority != 9 || (_DAT_0080d014 != 1)))) {
    _arbitrator_status_flag = 1;
    wVar2 = load_descriminator_to_determine_lugback_0_100;
    if ((_diagnostic_rpm_threshold_status <= load_descriminator_to_determine_lugback_0_100) &&
       (wVar2 = _diagnostic_rpm_threshold_status,
       _diagnostic_rpm_threshold_status < load_descriminator_to_determine_lugback_0_100)) {
      wVar2 = load_descriminator_to_determine_lugback_0_100;
    }
    uVar1 = ((uint)_DAT_0080cc58 * ((uint)_DAT_0080cc56 - (uint)wVar2)) / 0x1111;
    if ((int)(uVar1 & 0xffff) < (int)((uint)_DAT_0080cc54 - (uint)_DAT_0080cc5a)) {
      _DAT_0080cc50 = 0;
    }
    else {
      _DAT_0080cc50 = (short)uVar1 - (short)((uint)_DAT_0080cc54 - (uint)_DAT_0080cc5a);
    }
    if (_DAT_0080cc50 <= _DAT_0080cc5a) {
      _arbitrator_fuel_value_buffer = _DAT_0080cc5a;
      return;
    }
    _arbitrator_fuel_value_buffer = _DAT_0080cc50;
    return;
  }
  _arbitrator_fuel_value_buffer = _DAT_0080cc5a;
  _arbitrator_status_flag = 0;
  return;
}



//
// Function: FUN_00018b6e @ 0x00018b6e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00018b6e(void)

{
  param_pointer_set_1 = (dword)&DAT_0080369a;
  param_pointer_set_3 = 0x8036d8;
  param_pointer_set_2 = 0x8036da;
  _DAT_0080cc5a = _DAT_0080369a;
  _arbitrator_active_limit_priority = 6;
  _arbitrated_fuel_limit = _oil_pressure_precrank_status;
  _fuel_arbitrator_threshold_6 = _oil_pressure_precrank_status;
  _fuel_arbitrator_threshold_2 = _oil_pressure_precrank_status;
  return;
}



//
// Function: FUN_00018bbe @ 0x00018bbe
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00018bbe(void)

{
  ushort uVar1;
  
  uVar1 = (byte)-((DAT_0080bdc7 & 8) != 0) & 1;
  _DAT_008003ea = (ushort)(uVar1 != _DAT_008003e8);
  _DAT_008003e8 = uVar1;
  uVar1 = (byte)-((DAT_0080bdc7 & 4) != 0) & 1;
  _DAT_008003e6 = (ushort)(uVar1 != _DAT_008003e4);
  _DAT_008003e4 = uVar1;
  if (_active_derate_value < _DAT_008003ec) {
    uVar1 = _DAT_008003ec - _active_derate_value;
  }
  else {
    uVar1 = _active_derate_value - _DAT_008003ec;
  }
  if (the_can_1_bus_configuration_register_0_255 < uVar1) {
    _DAT_008003ec = _active_derate_value;
    _DAT_008003ee = 1;
    return;
  }
  _DAT_008003ee = 0;
  return;
}



//
// Function: FUN_00018c62 @ 0x00018c62
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_00018c62(void)

{
  ushort uVar1;
  
  uVar1 = _diagnostic_system_flags_1 & 2;
  if ((_diagnostic_system_flags_1 & 2) != 0) {
    uVar1 = FUN_00018bbe();
    if (_DAT_0080cc6c == 0) {
      _DAT_0080cc6e = _DAT_008036fc;
      _DAT_0080cc72 = 0;
      _DAT_0080cc6a = 0;
      _DAT_008003ec = _active_derate_value;
      if (the_can_1_bit_timing_0_register_0_255 == 0) {
        DAT_0080bdf1 = DAT_0080bdf1 | 1;
      }
      else {
        DAT_0080bdf1 = DAT_0080bdf1 & 0xfe;
      }
      if (((pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._2_2_ == 0) ||
          (uVar1 = _diagnostic_system_flags_2 & 8, (_diagnostic_system_flags_2 & 8) != 0)) &&
         ((_DAT_008096a6 == 0 &&
          ((engine_operating_mode == HIGH_RPM_RUNNING &&
           (uVar1 = _DAT_0080926e, the_can_1_cpu_interface_register_0_255 < _DAT_0080926e)))))) {
        if (((_engine_fault_register_a & 0x100) == 0) || ((_engine_fault_register_b & 0x100) == 0))
        {
          uVar1 = 0;
        }
        else {
          uVar1 = 1;
        }
        if ((((uVar1 == 0) && (_DAT_008003e6 == 0)) && (_DAT_008003ea == 0)) && (_DAT_008003ee == 0)
           ) {
          _DAT_0080cc6c = 1;
          return 0;
        }
      }
    }
    else if (_DAT_0080cc6c == 1) {
      _DAT_0080cc6e = _DAT_0080cc6e - 1;
      if ((((pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._2_2_ != 0) &&
           ((_diagnostic_system_flags_2 & 8) == 0)) || (engine_operating_mode != HIGH_RPM_RUNNING))
         || (((_DAT_0080926e <= the_can_1_cpu_interface_register_0_255 || (_DAT_008003e6 != 0)) ||
             ((_DAT_008003ea != 0 || (_DAT_008003ee != 0)))))) {
        _DAT_0080cc6c = 0;
      }
      uVar1 = _DAT_0080cc6e;
      if (_DAT_0080cc6e <= the_can_1_bit_timing_1_register_0_255) {
        _DAT_0080cc6c = 2;
        _DAT_0080cc72 = 1;
        return _DAT_0080cc6e;
      }
    }
    else if (_DAT_0080cc6c == 2) {
      _DAT_0080cc6e = _DAT_0080cc6e - 1;
      uVar1 = _diagnostic_system_flags_1 & 4;
      if ((_diagnostic_system_flags_1 & 4) == 0) {
        if ((((pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._2_2_ != 0) &&
             (uVar1 = _diagnostic_system_flags_2 & 8, (_diagnostic_system_flags_2 & 8) == 0)) ||
            (_DAT_008096a6 != 0)) ||
           (((engine_operating_mode != HIGH_RPM_RUNNING || (_DAT_008003e6 != 0)) ||
            ((_DAT_008003ea != 0 || (_DAT_008003ee != 0)))))) {
          _DAT_0080cc6c = 0;
        }
      }
      else {
        uVar1 = _DAT_008003ea | _DAT_008003e6;
        if ((uVar1 != 0) || (_DAT_008003ee != 0)) {
          _DAT_0080cc6c = 3;
          _DAT_0080cc72 = 0;
          _DAT_0080cc6a = 1;
        }
      }
      if (_DAT_0080cc6e == 0) {
        _DAT_0080cc6c = 4;
        _DAT_0080cc72 = 0;
        _DAT_0080c996 = 1;
        if (the_can_1_bit_timing_0_register_0_255 != 0) {
          DAT_0080bdf1 = DAT_0080bdf1 | 1;
          return uVar1;
        }
        DAT_0080bdf1 = DAT_0080bdf1 & 0xfe;
        return uVar1;
      }
    }
    else if (_DAT_0080cc6c == 3) {
      if ((_DAT_008096a6 != 0) || (engine_operating_mode == IDLE)) {
        _DAT_0080cc6c = 0;
        return uVar1;
      }
    }
    else if ((_DAT_0080cc6c == 4) && (engine_operating_mode == IDLE)) {
      _DAT_0080cc6c = 0;
    }
  }
  return uVar1;
}



//
// Function: FUN_00018e9c @ 0x00018e9c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00018e9c(void)

{
  _DAT_0080cc6e = _DAT_008036fc;
  _DAT_0080cc6c = 0;
  _DAT_0080c996 = 0;
  return;
}



//
// Function: FUN_00018eb4 @ 0x00018eb4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00018eb4(void)

{
  _DAT_00809672 = 0;
  _DAT_0080966e = 0x806fb0;
  _DAT_0080965c = 0;
  _DAT_00809676 = 0;
  _DAT_0080967a = 0;
  _DAT_0080967e = 0;
  _DAT_0080966a = 0;
  return;
}



//
// Function: FUN_00018ee4 @ 0x00018ee4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00018ee4(void)

{
  _DAT_0080d2bc = &DAT_00808b00;
  _DAT_0080d2b4 = &DAT_00808b00;
  _track_the_time_when_throttle_is_less_than_a_threshold_0_30 = 0x808b01;
  DAT_00808b00 = 0;
  ci_tooth_count_error_incremented_when_ci_pulse_width_is_wrong_0_255 = 0;
  _DAT_0080d3e6 = &DAT_00808b00;
  _dummy_variable_0_65535 = 0x808c01;
  DAT_00808c00 = 0;
  DAT_0080d2ce = 0;
  _DAT_0080d3ea = &DAT_00808c00;
  _DAT_0080d3ee = 0x808cff;
  _DAT_0080d2c2 = &DAT_00808c00;
  _enables_input_of_eps_period_data_to_pptb_0_1 = &DAT_00808c00;
  return;
}



//
// Function: FUN_00018f6c @ 0x00018f6c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00018f6c(void)

{
  _fuel_arbitrator_threshold_5 = _oil_pressure_precrank_status;
  _DAT_0080d4cc = _oil_pressure_precrank_status;
  return;
}



//
// Function: activeParamReadFunction @ 0x00018f82
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short activeParamReadFunction(void)

{
  ushort uVar1;
  ushort extraout_D0w;
  ushort extraout_D0w_00;
  ushort extraout_D0w_01;
  ushort extraout_D0w_02;
  ushort extraout_D0w_03;
  ushort extraout_D0w_04;
  ushort unaff_D2w;
  ushort uVar2;
  ushort unaff_D3w;
  
  uVar1 = _fuel_timing_mode_selector;
  if (_active_derate_value != 0) {
    if (_fuel_timing_mode_selector != 0) {
      _DAT_008003f6 = current_engine_rpm;
      _DAT_008003fe = _active_derate_value;
      tableInterpolationLookup((short *)&DAT_008003f0);
      unaff_D3w = extraout_D0w;
      if ((_active_derate_value != 0) && (_active_derate_value != 400)) {
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
    if (uVar1 < 0x4000) {
      _DAT_0080040a = current_engine_rpm;
      _DAT_00800412 = _active_derate_value;
      tableInterpolationLookup((short *)&DAT_00800404);
      unaff_D2w = extraout_D0w_02;
      if ((_active_derate_value != 0) && (_active_derate_value != 400)) {
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
    if ((uVar1 != 0) && (uVar2 = unaff_D3w, uVar1 != 0x4000)) {
      uVar2 = unaff_D2w + (short)((uint)uVar1 * ((uint)unaff_D3w - (uint)unaff_D2w) >> 0xe);
    }
    return _DAT_008037ae + uVar2;
  }
  return mask_used_for_can_msg_object_15_0_ffffffff._0_2_;
}



//
// Function: FUN_00019076 @ 0x00019076
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00019076(void)

{
  _DAT_008003f2 = 0x807f42;
  _DAT_008003f0 = 2;
  _DAT_008003fa = 0x807f68;
  _DAT_008003f8 = 2;
  _DAT_00800400 = &lower_limitation_of_intake_manifold_temperature_to_inhibit_50_to_293;
  _DAT_00800406 = 0x808002;
  _DAT_00800404 = 2;
  _DAT_0080040e = 0x808028;
  _DAT_0080040c = 2;
  _DAT_00800414 = 0x808032;
  _fuel_timing_mode_selector = 0x4000;
  return;
}



//
// Function: FUN_000190d8 @ 0x000190d8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000190d8(undefined4 param_1)

{
  if ((param_1._0_2_ & 0xff) == _DAT_0080cfb6) {
    FUN_00019598();
    return;
  }
  FUN_0000c1f0();
  return;
}



//
// Function: FUN_00019108 @ 0x00019108
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00019108(undefined4 param_1)

{
  undefined4 unaff_D2;
  
  if ((_DAT_0080cfb6 < (param_1._0_2_ & 0xff)) && ((byte)((uint)param_1 >> 0x10) <= _DAT_0080cfb8))
  {
    FUN_0001965a(CONCAT22(param_1._0_2_,(short)((uint)unaff_D2 >> 0x10)) & 0xffffff);
  }
  return;
}



//
// Function: FUN_0001913e @ 0x0001913e
// ERROR: Failed to decompile
//

//
// Function: FUN_0001917c @ 0x0001917c
//

undefined8 FUN_0001917c(void)

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
        FUN_00019108(CONCAT22((short)CONCAT31(uVar3,bVar2 - 2),uVar4));
      }
      else {
        FUN_000190d8(CONCAT22((short)CONCAT31(uVar3,bVar2 - 2),uVar4));
      }
    }
  }
  return CONCAT44(CONCAT22(uVar4,uStack_1a),in_D1);
}



//
// Function: FUN_0001920a @ 0x0001920a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001920a(void)

{
  _DAT_00808e32 = FUN_0001917c;
  return;
}



//
// Function: FUN_00019216 @ 0x00019216
//

void FUN_00019216(void)

{
  FUN_0000c1f0();
  return;
}



//
// Function: FUN_00019228 @ 0x00019228
//

void FUN_00019228(undefined4 param_1)

{
  undefined2 in_D0w;
  undefined2 in_stack_00000000;
  
  FUN_0000c1f2(CONCAT22(CONCAT11((char)((ushort)in_D0w >> 8),(char)((uint)param_1 >> 0x10)),
                        in_stack_00000000));
  return;
}



//
// Function: FUN_0001923a @ 0x0001923a
//

undefined8 FUN_0001923a(void)

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
        FUN_00019228(CONCAT22((short)CONCAT31((int3)((uint)pbVar1 >> 8),bVar2 - 2),uVar3));
      }
      else {
        FUN_00019216();
      }
    }
  }
  return CONCAT44(CONCAT22(uVar3,uStack_1a),in_D1);
}



//
// Function: FUN_000192c4 @ 0x000192c4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000192c4(void)

{
  _DAT_00808e36 = FUN_0001923a;
  return;
}



//
// Function: FUN_000192d0 @ 0x000192d0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000192d0(void)

{
  DAT_0080d2da = 1;
  _DAT_00fff45a = 0xfc8a;
  _DAT_00fff458 = _DAT_00fff458 & 0x7fff | 0x4000;
  return;
}



//
// Function: FUN_000192f2 @ 0x000192f2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000192f2(void)

{
  byte *pbVar1;
  undefined4 in_D0;
  undefined4 in_D1;
  byte bVar2;
  
  pbVar1 = _track_the_time_when_throttle_is_less_than_a_threshold_0_30;
  if ((tpu_cfsr0 & 0x40) != 0) {
    DAT_0080d2da = 0;
    _DAT_00fff458 = _DAT_00fff458 & 0x8fff;
    bVar2 = (byte)tpu_cfsr1;
    if (DAT_0080d2d0 == '\x01') {
      *_dummy_variable_0_65535 = bVar2;
      _dummy_variable_0_65535 =
           (byte *)CONCAT31(_dummy_variable_0_65535,flag_indicating_eps_sensor_not_used_0_1 + 1);
      *_DAT_0080d2c2 = *_DAT_0080d2c2 + 1;
      DAT_0080d2d3 = bVar2 + DAT_0080d2d3;
      if (_enables_input_of_eps_period_data_to_pptb_0_1 == _dummy_variable_0_65535) {
        if (_DAT_0080d2c2 == _enables_input_of_eps_period_data_to_pptb_0_1) {
          *_DAT_0080d2c2 = 0;
          DAT_0080d2d3 = 0;
          _dummy_variable_0_65535 =
               (byte *)CONCAT31(_dummy_variable_0_65535,(char)dummy_variable_0_65535 + '\x01');
        }
        else {
          DAT_0080d2ce = '\x01';
          tpu_cier = tpu_cier & 0xffdf;
          if (_DAT_0080d2b4 != _DAT_0080d2bc) {
            FUN_000192d0();
            DAT_0080d2da = 1;
          }
        }
      }
      else {
        FUN_000192d0();
      }
    }
    else {
      switch(_DAT_0080d2d6) {
      case 0:
        if (bVar2 == *_track_the_time_when_throttle_is_less_than_a_threshold_0_30) {
          _track_the_time_when_throttle_is_less_than_a_threshold_0_30 =
               (byte *)CONCAT31(_track_the_time_when_throttle_is_less_than_a_threshold_0_30,
                                (char)
                                flag_shows_posibility_of_esp_transitioning_between_normal_false_true
                                + '\x01');
          tpu_cfsr1 = (word)*_track_the_time_when_throttle_is_less_than_a_threshold_0_30;
          FUN_000192d0();
          DAT_0080d2d3 = *_track_the_time_when_throttle_is_less_than_a_threshold_0_30 + DAT_0080d2d3
          ;
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
          *_dummy_variable_0_65535 = bVar2;
          _dummy_variable_0_65535 =
               (byte *)CONCAT31(_dummy_variable_0_65535,flag_indicating_eps_sensor_not_used_0_1 + 1)
          ;
          *_DAT_0080d2c2 = *_DAT_0080d2c2 + 1;
          if (_dummy_variable_0_65535 == _enables_input_of_eps_period_data_to_pptb_0_1) {
            DAT_0080d2ce = '\x01';
            tpu_cier = tpu_cier & 0xffdf;
          }
          else {
            FUN_000192d0();
          }
        }
        else {
          DAT_0080d2d0 = '\x01';
          DAT_0080d2d3 = 0;
          FUN_000192d0();
        }
        break;
      case 1:
        _track_the_time_when_throttle_is_less_than_a_threshold_0_30 =
             (byte *)CONCAT31(_track_the_time_when_throttle_is_less_than_a_threshold_0_30,
                              (char)
                              flag_shows_posibility_of_esp_transitioning_between_normal_false_true +
                              '\x01');
        tpu_cfsr1 = (word)*_track_the_time_when_throttle_is_less_than_a_threshold_0_30;
        FUN_000192d0();
        DAT_0080d2d3 = *_track_the_time_when_throttle_is_less_than_a_threshold_0_30 + DAT_0080d2d3;
        DAT_0080d2d1 = DAT_0080d2d1 + 1;
        if (DAT_0080d2d1 == *_DAT_0080d2bc) {
          _DAT_0080d2d6 = 2;
        }
        break;
      case 2:
        tpu_cfsr1 = ~(ushort)DAT_0080d2d3 + 1 & 0xff;
        FUN_000192d0();
        _track_the_time_when_throttle_is_less_than_a_threshold_0_30 =
             (byte *)CONCAT31(_track_the_time_when_throttle_is_less_than_a_threshold_0_30,
                              (char)
                              flag_shows_posibility_of_esp_transitioning_between_normal_false_true +
                              '\x01');
        _DAT_0080d2d6 = 3;
        break;
      case 3:
        _DAT_0080d2bc = _track_the_time_when_throttle_is_less_than_a_threshold_0_30;
        _track_the_time_when_throttle_is_less_than_a_threshold_0_30 =
             (byte *)CONCAT31(_track_the_time_when_throttle_is_less_than_a_threshold_0_30,
                              (char)
                              flag_shows_posibility_of_esp_transitioning_between_normal_false_true +
                              '\x01');
        DAT_0080d2d3 = 0;
        ci_tooth_count_error_incremented_when_ci_pulse_width_is_wrong_0_255 = 0;
        if (((((_DAT_00805e00 & 4) != 0) && ((_DAT_008068d2 & 4) != 0)) &&
            ((_DAT_00805e00 & 4) != 0)) && ((_DAT_00805e40 & 4) == 0)) {
          _DAT_00805e00 = _DAT_00805e00 & 0xfffb;
        }
        DAT_0080d2d0 = '\x01';
        if (DAT_0080d2ce == '\0') {
          tpu_cier = tpu_cier | 0x20;
        }
        else {
          tpu_cier = tpu_cier & 0xffdf;
        }
        if (_DAT_0080d2b4 != pbVar1) {
          DAT_0080d2da = 1;
          _DAT_00fff458 = _DAT_00fff458 | 0x4000;
          _DAT_00fff45a = 0xfcbe;
        }
      }
    }
  }
  return CONCAT44(in_D0,in_D1);
}



//
// Function: FUN_0001958c @ 0x0001958c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001958c(void)

{
  _DAT_00808f02 = FUN_000192f2;
  return;
}



//
// Function: FUN_00019598 @ 0x00019598
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00019598(void)

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
  uVar2 = CONCAT22(uVar1,_DAT_00805dfc) & 0xffff0200;
  if ((((_DAT_00805dfc & 0x200) != 0) &&
      (uVar2 = CONCAT22(uVar1,_DAT_008068ce) & 0xffff0200, (_DAT_008068ce & 0x200) != 0)) &&
     (uVar2 = CONCAT22(uVar1,_DAT_00805dfc) & 0xffff0200, (_DAT_00805dfc & 0x200) != 0)) {
    uVar2 = CONCAT22(uVar1,_DAT_00805e3c) & 0xffff0200;
    if ((_DAT_00805e3c & 0x200) == 0) {
      _DAT_00805dfc = _DAT_00805dfc & 0xfdff;
    }
  }
  return uVar2;
}



//
// Function: FUN_0001965a @ 0x0001965a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001965a(uint param_1)

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
    _DAT_0080cf80 = (dword *)((int)_DAT_0080cf80 + 0x12);
    if ((dword *)0x80ce4e < _DAT_0080cf80) {
      _DAT_0080cf80 = &average_pulse_period_time_period_over_1_cyl_of_primary_s_1000_65535;
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
// Function: FUN_00019738 @ 0x00019738
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00019738(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  _DAT_00800418 = _DAT_00800418 + 1;
  return CONCAT44(in_D0,in_D1);
}



//
// Function: FUN_0001976e @ 0x0001976e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0001976e(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  _DAT_0080061a = _DAT_0080061a + 1;
  return CONCAT44(in_D0,in_D1);
}



//
// Function: FUN_0001977e @ 0x0001977e
//

void FUN_0001977e(void)

{
  undefined4 *puVar1;
  
  for (puVar1 = (undefined4 *)&DAT_00808dc2; puVar1 < (undefined4 *)0x8091c2; puVar1 = puVar1 + 1) {
    *puVar1 = FUN_0001976e;
  }
  return;
}



//
// Function: FUN_000197c8 @ 0x000197c8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_000197c8(void)

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
// Function: FUN_0001984e @ 0x0001984e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001984e(undefined4 param_1)

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
  DAT_0080d418 = DAT_0080d446 + '\x06';
  if (_DAT_0080d2b4 < _DAT_0080d2bc) {
    uVar2 = (_DAT_0080d2bc - _DAT_0080d2b4) - 2;
  }
  else {
    uVar2 = (_DAT_0080d2bc - _DAT_0080d2b4) + 0xfe;
  }
  if ((int)(uint)(byte)(DAT_0080062b + 5 + cVar3) < (int)uVar2) {
    *_DAT_0080d40c = 0xc0;
    _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    *_DAT_0080d40c = DAT_0080d446 + '\x03';
    _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    *_DAT_0080d40c = DAT_0080d407;
    _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    *_DAT_0080d40c = DAT_0080d445 << 4;
    _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    *_DAT_0080d40c = cVar1;
    _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    return uVar2 & 0xffffff00;
  }
  _DAT_00805e00 = _DAT_00805e00 | 4;
  _DAT_00805e40 = _DAT_00805e40 | 4;
  return 1;
}



//
// Function: FUN_00019952 @ 0x00019952
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00019952(void)

{
  *_DAT_0080d410 = DAT_0080d418;
  *_DAT_0080d40c = 0;
  _DAT_0080d2b4 = _DAT_0080d40c;
  _DAT_0080d410 = _DAT_0080d40c;
  FUN_00013242();
  DAT_0080d444 = DAT_0080d444 + 1;
  if (DAT_0080d444 < DAT_0080d445) {
    DAT_0080d446 = DAT_0080062a;
  }
  else {
    DAT_0080d446 = DAT_0080062b;
  }
  _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
  *_DAT_0080d40c = 0x80;
  _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
  DAT_0080d418 = DAT_0080d446 + '\x05';
  *_DAT_0080d40c = 0xc0;
  _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
  *_DAT_0080d40c = DAT_0080d446 + '\x02';
  _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
  *_DAT_0080d40c = DAT_0080d407;
  _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
  *_DAT_0080d40c = DAT_0080d444 & 0xf | DAT_0080d445 << 4;
  _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
  return;
}



//
// Function: FUN_00019a0a @ 0x00019a0a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00019a0a(void)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  char cVar4;
  char cVar6;
  undefined2 uVar5;
  undefined4 unaff_D2;
  byte bVar7;
  byte bVar8;
  char *pcVar9;
  undefined2 uVar10;
  
  uVar10 = (undefined2)((uint)unaff_D2 >> 0x10);
  _DAT_0080d414 = _enables_input_of_eps_period_data_to_pptb_0_1;
  _DAT_0080d410 = _DAT_0080d2b4;
  _DAT_0080d40c = _DAT_0080d2b4;
  DAT_0080d409 = 1;
  bVar1 = *_enables_input_of_eps_period_data_to_pptb_0_1;
  if (bVar1 < 0x15) {
    DAT_0080d417 = (char)_enables_input_of_eps_period_data_to_pptb_0_1;
    cVar6 = DAT_0080d417;
    _DAT_0080d414 = (undefined3)((uint)_enables_input_of_eps_period_data_to_pptb_0_1 >> 8);
    _DAT_0080d414 = (byte *)CONCAT31(_DAT_0080d414,DAT_0080d417 + '\x01');
    cVar2 = *_DAT_0080d414;
    _DAT_0080d414 = (byte *)CONCAT31(_DAT_0080d414,cVar6 + '\x02');
    bVar8 = 1;
    DAT_0080d418 = 0;
    FUN_00019c3c();
    if (DAT_0080d419 != '\0') {
LAB_00019c2a:
      if (bVar8 < bVar1) {
        DAT_0080d407 = *_DAT_0080d414;
        _DAT_0080d414 = (byte *)CONCAT31(_DAT_0080d414,DAT_0080d417 + '\x01');
        cVar6 = FUN_00027168();
        if (cVar6 == '\0') goto LAB_00019c30;
        bVar8 = cVar6 + bVar8;
        cVar4 = DAT_0080d417;
        if (DAT_0080d407 == 0) {
          DAT_0080d407 = *_DAT_0080d414;
          _DAT_0080d414 = (byte *)CONCAT31(_DAT_0080d414,DAT_0080d417 + '\x01');
          uVar5 = FUN_000271b0();
          DAT_0080d41a = (undefined1)uVar5;
          bVar7 = '\x01' << (DAT_0080d407 & 7);
          sVar3 = (short)((int)(uint)DAT_0080d407 >> 3);
          if (((bVar7 & *(byte *)((int)&
                                       maximum_time_between_tailshaft_pulses_allowed_before_vehicle_0_04_40
                                 + (int)sVar3)) != 0) &&
             ((bVar7 & *(byte *)(sVar3 + 0x8055fe)) == 0)) {
            FUN_0000cb1e();
          }
        }
        else if (DAT_0080d407 == 0x80) {
          DAT_0080d407 = *_DAT_0080d414;
          _DAT_0080d414 = (byte *)CONCAT31(_DAT_0080d414,DAT_0080d417 + '\x01');
          cVar6 = *_DAT_0080d414;
          _DAT_0080d414 = (byte *)CONCAT31(_DAT_0080d414,cVar4 + '\x02');
          if (cVar6 == -0x80) {
            uVar5 = FUN_000271b0();
            DAT_0080d41a = (undefined1)uVar5;
            bVar7 = '\x01' << (DAT_0080d407 & 7);
            sVar3 = (short)((int)(uint)DAT_0080d407 >> 3);
            if (((bVar7 & *(byte *)((int)&
                                         maximum_time_between_tailshaft_pulses_allowed_before_vehicle_0_04_40
                                   + (int)sVar3)) != 0) &&
               ((bVar7 & *(byte *)(sVar3 + 0x8055fe)) == 0)) {
              FUN_0000cb1e();
            }
          }
        }
        else if (DAT_0080d407 == 0xc3) {
          _DAT_0080d414 = (byte *)CONCAT31(_DAT_0080d414,DAT_0080d417 + '\x01');
          cVar6 = *_DAT_0080d414;
          _DAT_0080d414 = (byte *)CONCAT31(_DAT_0080d414,cVar4 + '\x02');
          DAT_0080d447 = *_DAT_0080d414;
          _DAT_0080d414 = (byte *)CONCAT31(_DAT_0080d414,cVar4 + '\x03');
          DAT_0080d448 = *_DAT_0080d414;
          _DAT_0080d414 = (byte *)CONCAT31(_DAT_0080d414,cVar4 + '\x04');
          if ((cVar6 == -0x80) && ((DAT_0080d448 & 0xc0) < 0xc0)) {
            bVar7 = 0;
            pcVar9 = &DAT_008089e0;
            while( true ) {
              if ((*pcVar9 == '\0') || (9 < bVar7)) goto LAB_00019c2a;
              if (cVar2 == *pcVar9) break;
              bVar7 = bVar7 + 1;
              pcVar9 = pcVar9 + 1;
            }
            _DAT_0080d48e = (ushort)DAT_0080d448;
            if (((DAT_0080d448 & 0xc0) == 0x80) || ((DAT_0080d448 & 0xc0) == 0x40)) {
              _DAT_0080d48c = 2;
              _DAT_0080d492 = (ushort)DAT_0080d447;
            }
            else {
              FUN_00011ba0((uint)CONCAT12(DAT_0080d447,uVar10));
            }
            DAT_0080d407 = 0xc4;
            uVar5 = FUN_000271b0();
            DAT_0080d41a = (undefined1)uVar5;
            FUN_0000cb1e();
          }
        }
        else {
          _DAT_0080d414 = (byte *)CONCAT31(_DAT_0080d414,cVar6 + -1 + DAT_0080d417);
        }
        goto LAB_00019c2a;
      }
LAB_00019c30:
      FUN_00019cbc();
    }
  }
  return;
}



//
// Function: FUN_00019c3c @ 0x00019c3c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00019c3c(void)

{
  byte bVar1;
  
  bVar1 = (crank_tooth_count_error_incremented_when_eps_tooth_count_wro_0_65535 - DAT_0080d2b7) - 2;
  if (bVar1 < 5) {
    DAT_0080d419 = 0;
    _DAT_00805e00 = _DAT_00805e00 | 4;
    _DAT_00805e40 = _DAT_00805e40 | 4;
    return;
  }
  if (0x15 < bVar1) {
    DAT_0080d419 = 0x13;
    return;
  }
  DAT_0080d419 = (crank_tooth_count_error_incremented_when_eps_tooth_count_wro_0_65535 -
                 DAT_0080d2b7) + -4;
  return;
}



//
// Function: FUN_00019cbc @ 0x00019cbc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00019cbc(void)

{
  if (1 < DAT_0080d418) {
    *_DAT_0080d410 = DAT_0080d418;
    *_DAT_0080d40c = 0;
    _DAT_0080d2b4 = _DAT_0080d40c;
    FUN_00013242();
  }
  return;
}



//
// Function: FUN_00019cf0 @ 0x00019cf0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00019cf0(undefined4 param_1)

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
  local_9 = *_enables_input_of_eps_period_data_to_pptb_0_1;
  local_8._3_1_ = (char)_enables_input_of_eps_period_data_to_pptb_0_1;
  cVar8 = (char)local_8;
  local_8._0_3_ = (undefined3)((uint)_enables_input_of_eps_period_data_to_pptb_0_1 >> 8);
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
        uVar2 = FUN_00025476((uint)CONCAT12(cVar8,uVar12));
        if ((char)uVar2 != -1) {
          FUN_0000a626((uint)CONCAT12((char)uVar2,uVar12));
        }
      }
      else {
        FUN_0000a626(CONCAT22(2,uVar12));
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
      pointer_to_intake_man_temp_rpm_fault_log_data_0_2_32._2_1_ = 2;
      if (local_e._0_2_ == 0x15) {
        _DAT_0080d458 = 1;
      }
      cVar3 = FUN_0000eaf0((short)((uint)&local_e >> 0x10));
      if (cVar3 != '\0') {
        FUN_0000a626(CONCAT22(8,uVar12));
        return;
      }
    }
    else {
      pointer_to_intake_man_temp_rpm_fault_log_data_0_2_32._2_1_ = 4;
    }
    uVar1 = addressRangeValidator(local_e,(uint)CONCAT12(bVar6,uVar12));
    bVar4 = (byte)uVar1;
    if ((bVar4 == 10) || (bVar4 == 4)) {
      FUN_0000a626(CONCAT22(10,uVar12));
      return;
    }
    if (bVar4 == 9) {
      FUN_0000a626(CONCAT22(9,uVar12));
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
// Function: FUN_00019e62 @ 0x00019e62
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

void FUN_00019e62(undefined4 param_1)

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
  bVar9 = *_enables_input_of_eps_period_data_to_pptb_0_1;
  local_8._3_1_ = (char)_enables_input_of_eps_period_data_to_pptb_0_1;
  local_8._0_3_ = (undefined3)((uint)_enables_input_of_eps_period_data_to_pptb_0_1 >> 8);
  local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x02');
  bVar1 = *local_8 & 0xf;
  if (bVar1 == 0) {
    if ((int)(bVar9 - 4) % (int)(bVar8 + 1) != 0) {
      FUN_0000a626(CONCAT22(2,uVar12));
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
      FUN_0000a626(CONCAT22(2,uVar12));
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
      uVar5 = FUN_0000fcb0(local_c,CONCAT22((short)CONCAT31((int3)((uint)unaff_D7 >> 8),bVar9 - 4),
                                            uVar12));
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
    FUN_00013242();
  }
  else {
    FUN_0000a626(CONCAT22(4,uVar12));
    _DAT_00805e00 = _DAT_00805e00 | 4;
    _DAT_00805e40 = _DAT_00805e40 | 4;
  }
  return;
}



//
// Function: FUN_0001a192 @ 0x0001a192
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001a192(void)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  byte bVar4;
  undefined4 local_8;
  
  FUN_00010f08();
  if ((_arbitrated_fuel_limit != _DAT_00800638) || (_DAT_0080d092 != _DAT_0080063a)) {
    DAT_0080d03a = '\x01';
    _DAT_00800638 = _arbitrated_fuel_limit;
    _DAT_0080063a = _DAT_0080d092;
  }
  if ((int)_DAT_0080d2b4 < _DAT_0080d2bc) {
    iVar3 = (_DAT_0080d2bc - (int)_DAT_0080d2b4) + -2;
  }
  else {
    iVar3 = (_DAT_0080d2bc - (int)_DAT_0080d2b4) + 0xfe;
  }
  if (iVar3 < 7) {
    _DAT_00805e00 = _DAT_00805e00 | 4;
    _DAT_00805e40 = _DAT_00805e40 | 4;
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
  if (((_engine_fault_register_a & 0x20) == 0) || ((_engine_fault_register_b & 0x20) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if (((_engine_fault_register_a & 8) == 0) || ((_engine_fault_register_b & 8) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (((_engine_fault_register_a & 0x10) == 0) || ((_engine_fault_register_b & 0x10) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        *local_8 = (char)(((uint)_active_derate_value * 0xff) / 400);
        goto LAB_0001a2b8;
      }
    }
  }
  *local_8 = 0;
LAB_0001a2b8:
  local_8 = (byte *)CONCAT31(local_8._0_3_,cVar2 + '\x04');
  bVar4 = _protection_system_enable_flag == 1;
  if (pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._2_2_ == 1) {
    bVar4 = bVar4 | 2;
  }
  if (_DAT_0080c9a6 == 10) {
    bVar4 = bVar4 | 4;
  }
  if (((io_control_flags & 1) == 0) || ((DAT_0080bdf1 & 1) == 0)) {
    bVar4 = bVar4 | 8;
  }
  if (_DAT_008086f0 < _active_derate_value) {
    bVar4 = bVar4 | 0x10;
  }
  if (_derate_threshold_exceeded == 0) {
    bVar4 = bVar4 | 0x20;
  }
  if (DAT_0080d03a == '\x01') {
    bVar4 = bVar4 | 0x40;
  }
  *local_8 = bVar4;
  local_8 = (byte *)CONCAT31(local_8._0_3_,cVar2 + '\x05');
  *local_8 = (char)((int)(uint)param_limit_value >> 7);
  local_8 = (byte *)CONCAT31(local_8._0_3_,cVar2 + '\x06');
  *local_8 = param_config_byte;
  local_8 = (byte *)CONCAT31(local_8._0_3_,cVar2 + '\a');
  *_DAT_0080d2b4 = 6;
  *local_8 = 0;
  _DAT_0080d2b4 = local_8;
  FUN_00013242();
  return;
}



//
// Function: FUN_0001a398 @ 0x0001a398
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001a398(void)

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
    _DAT_00805e00 = _DAT_00805e00 | 4;
    _DAT_00805e40 = _DAT_00805e40 | 4;
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
    FUN_00010e70();
    *local_8 = (char)((ushort)_DAT_0080bd96 >> 8);
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x05');
    sVar1 = the_minimum_speed_a_customer_may_program_to_correspond_with_s_1_5_15 * 2;
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
    sVar1 = the_maximum_speed_a_customer_may_program_to_correspond_with_10_10_25 * 2;
    uStack_d = (undefined1)sVar1;
    *local_8 = uStack_d;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x12');
    local_e = (undefined1)((ushort)sVar1 >> 8);
    *local_8 = local_e;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x13');
    uStack_d = (undefined1)(the_deceleration_value_where_e_braking_will_be_removed_1_0_01 / 10);
    *local_8 = uStack_d;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x14');
    sVar1 = _arbitrator_fuel_value_buffer * 2;
    uStack_d = (undefined1)sVar1;
    *local_8 = uStack_d;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x15');
    local_e = (undefined1)((ushort)sVar1 >> 8);
    *local_8 = local_e;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x16');
    uStack_d = (undefined1)((int)(uint)allowed_rate_of_torque_limit_change_0_2000 >> 7);
    *local_8 = uStack_d;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x17');
    *puVar2 = 0x16;
    *local_8 = 0;
    _DAT_0080d2b4 = local_8;
    FUN_00013242();
  }
  return;
}



//
// Function: FUN_0001a5b0 @ 0x0001a5b0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001a5b0(void)

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
  
  cVar1 = *_enables_input_of_eps_period_data_to_pptb_0_1;
  local_8._3_1_ = (char)_enables_input_of_eps_period_data_to_pptb_0_1;
  cVar5 = (char)local_8;
  local_8._0_3_ = (undefined3)((uint)_enables_input_of_eps_period_data_to_pptb_0_1 >> 8);
  local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x02');
  uVar4 = *local_8 & 3;
  uVar7 = FUN_0001d19c(0x4a,CONCAT12(*local_8,(short)((uint)unaff_D2 >> 0x10)) & 0x3ffff);
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
  if (_fuel_arbitrator_condition_flag == 0) {
    uVar7 = FUN_00029422(0x4a);
    if ((short)uVar7 != 0) {
      return uVar7;
    }
    _DAT_0080d01e = _DAT_0080d01a;
  }
  else if ((_DAT_0080d014 != 0) || (DAT_0080d018 != 'J')) {
    uVar7 = FUN_00029422(0x4a);
    if ((short)uVar7 != 0) {
      return uVar7;
    }
    if (_DAT_0080d01e < _DAT_0080d01a) {
      return _DAT_0080d01a;
    }
    _DAT_0080d01e = _DAT_0080d01a;
  }
  _DAT_0080cff8 = (ushort)*local_8;
  _DAT_0080d012 = 0;
  _DAT_0080d014 = 0;
  DAT_0080d018 = 0x4a;
  sVar6 = unaff_D3w;
  switch(uVar4) {
  case 0:
    _DAT_0080d028 = 0;
    _fuel_arbitrator_condition_flag = 0;
    _DAT_0080cffa = 0;
    _DAT_0080d00c = 0;
    sVar6 = _DAT_008086e8 + 1;
    break;
  case 1:
    FUN_0001d34e(0x4a);
    _DAT_0080d028 = *(short *)(_DAT_0080d01e + 4) + 1;
    _fuel_arbitrator_condition_flag = 1;
    _DAT_0080cffa = 1;
    _DAT_0080d00c = 1;
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar5 + '\x03');
    uVar2 = *local_8;
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar5 + '\x04');
    local_a = CONCAT11(*local_8,uVar2);
    _DAT_0080d00a = (undefined2)((int)(uint)local_a >> 1);
    sVar6 = _DAT_0080d028;
    break;
  case 2:
    FUN_0001d34e(0x4a);
    _DAT_0080d028 = *(short *)(_DAT_0080d01e + 8) + 1;
    _fuel_arbitrator_condition_flag = 2;
    _DAT_0080cffa = 1;
    _DAT_0080d00c = 0;
    local_c = (ushort)(byte)local_c;
    _DAT_0080d008 = local_c << 8;
    _DAT_0080d010 =
         _DAT_0080bd8c +
         (short)(((int)(short)(the_maximum_speed_a_customer_may_program_to_correspond_with_s_1_5_15
                              - _DAT_0080bda0) * (int)_DAT_0080d008) / 0x6400);
    sVar6 = _DAT_0080d028;
    if (_DAT_0080d010 < 0) {
      _DAT_0080d010 = 0;
      sVar6 = _DAT_0080d028;
    }
    break;
  case 3:
    FUN_0001d34e(0x4a);
    _DAT_0080d028 = *(short *)(_DAT_0080d01e + 0xc) + 1;
    _fuel_arbitrator_condition_flag = 3;
    _DAT_0080cffa = 1;
    _DAT_0080d00c = 0;
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar5 + '\x03');
    local_a = (ushort)*local_8;
    _fuel_arbitrator_conditional_limit = local_a << 7;
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar5 + '\x04');
    bVar3 = *local_8;
    if (bVar3 < 0x80) {
      local_c = (ushort)bVar3;
    }
    else {
      local_c = CONCAT11(0xff,bVar3);
    }
    _DAT_0080d00e =
         _DAT_0080bd8c +
         (short)(((int)(short)(the_maximum_speed_a_customer_may_program_to_correspond_with_s_1_5_15
                              - _DAT_0080bda0) * (short)local_c * 8) / 0x6400);
    sVar6 = _DAT_0080d028;
    if (_DAT_0080d00e < 0) {
      _DAT_0080d00e = 0;
      sVar6 = _DAT_0080d028;
    }
  }
  _DAT_0080d032 = sVar6;
  bVar8 = (_DAT_0080cff8 & 4) != 0;
  _DAT_0080d036 = _DAT_0080d032;
  if (bVar8) {
    _DAT_0080d036 = 0;
  }
  _DAT_0080cffe = (ushort)!bVar8;
  bVar8 = (_DAT_0080cff8 & 8) == 0;
  _DAT_0080d02e = _DAT_0080d032;
  if (bVar8) {
    _DAT_0080d02e = 0;
  }
  _arbitrator_special_mode_flag = (ushort)!bVar8;
  bVar8 = (_DAT_0080cff8 & 0x10) == 0;
  if (bVar8) {
    _DAT_0080d016 = 0;
  }
  else {
    _DAT_0080d032 = 0;
  }
  _DAT_0080d002 = (ushort)bVar8;
  return _DAT_0080cff8 & 0xffff0010;
}



//
// Function: FUN_0001a910 @ 0x0001a910
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001a910(void)

{
  undefined4 local_8;
  
  if (*_enables_input_of_eps_period_data_to_pptb_0_1 == '\x02') {
    local_8._3_1_ = (char)_enables_input_of_eps_period_data_to_pptb_0_1;
    local_8 = (byte *)CONCAT31((int3)((uint)_enables_input_of_eps_period_data_to_pptb_0_1 >> 8),
                               (char)local_8 + '\x02');
    if ((*local_8 & 1) != 0) {
      FUN_0001a398();
      DAT_0080d03a = 0;
    }
    if ((*local_8 & 8) != 0) {
      FUN_0001ad50();
    }
    if ((*local_8 & 0x80) == 0) {
      _DAT_0080d004 = 0;
      _DAT_0080d034 = 0;
    }
    else {
      _DAT_0080d004 = 1;
      _DAT_0080d034 = _DAT_008086ee;
    }
  }
  return;
}



//
// Function: FUN_0001a97e @ 0x0001a97e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001a97e(void)

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
  
  cVar1 = *_enables_input_of_eps_period_data_to_pptb_0_1;
  local_8._3_1_ = (char)_enables_input_of_eps_period_data_to_pptb_0_1;
  cVar4 = (char)local_8;
  local_8._0_3_ = (undefined3)((uint)_enables_input_of_eps_period_data_to_pptb_0_1 >> 8);
  local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x02');
  uVar6 = *local_8 & 4;
  if ((*local_8 & 4) == 0) {
    uVar3 = *local_8 & 3;
    uVar6 = FUN_0001d19c(0x4f,CONCAT12(*local_8,(short)((uint)unaff_D2 >> 0x10)) & 0x3ffff);
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
      if (_fuel_arbitrator_condition_flag == 0) {
        uVar6 = FUN_00029422(0x4f);
        if ((short)uVar6 != 0) {
          return uVar6;
        }
        _DAT_0080d01e = _DAT_0080d01a;
      }
      else if ((_DAT_0080d014 != 0) || (DAT_0080d018 != 'O')) {
        uVar6 = FUN_00029422(0x4f);
        if ((short)uVar6 != 0) {
          return uVar6;
        }
        if (_DAT_0080d01e < _DAT_0080d01a) {
          return _DAT_0080d01a;
        }
        _DAT_0080d01e = _DAT_0080d01a;
      }
      _DAT_0080cff8 = (ushort)*local_8;
      _DAT_0080d012 = 0;
      _DAT_0080d014 = 0;
      DAT_0080d018 = 'O';
      iVar7 = (int)(short)uVar3;
      sVar5 = unaff_D3w;
      switch((int)(short)uVar3) {
      case 0:
        _DAT_0080d028 = 0;
        _fuel_arbitrator_condition_flag = 0;
        _DAT_0080cffa = 0;
        _DAT_0080d00c = 0;
        iVar7 = 0;
        sVar5 = _DAT_008086e8 + 1;
        break;
      case 1:
        FUN_0001d34e(0x4f);
        _DAT_0080d028 = *(short *)(_DAT_0080d01e + 4) + 1;
        _fuel_arbitrator_condition_flag = 1;
        _DAT_0080cffa = 2;
        _DAT_0080d00c = 1;
        local_8 = (byte *)CONCAT31(local_8._0_3_,cVar4 + '\x03');
        local_a = (ushort)*local_8;
        _DAT_0080d00a = local_a << 7;
        iVar7 = CONCAT22(extraout_D0u,_DAT_0080d00a);
        sVar5 = _DAT_0080d028;
        break;
      case 2:
        FUN_0001d34e(0x4f);
        _DAT_0080d028 = *(short *)(_DAT_0080d01e + 8) + 1;
        _fuel_arbitrator_condition_flag = 2;
        _DAT_0080cffa = 2;
        _DAT_0080d00c = 0;
        local_8 = (byte *)CONCAT31(local_8._0_3_,cVar4 + '\x03');
        local_c = (ushort)*local_8;
        _DAT_0080d008 = local_c << 8;
        iVar7 = ((int)(short)(the_maximum_speed_a_customer_may_program_to_correspond_with_s_1_5_15 -
                             _DAT_0080bda0) * (int)_DAT_0080d008) / 0x6400;
        _DAT_0080d010 = _DAT_0080bd8c + (short)iVar7;
        iVar7 = CONCAT22((short)((uint)iVar7 >> 0x10),_DAT_0080d010);
        sVar5 = _DAT_0080d028;
        if (_DAT_0080d010 < 0) {
          _DAT_0080d010 = 0;
          sVar5 = _DAT_0080d028;
        }
        break;
      case 3:
        FUN_0001d34e(0x4f);
        _DAT_0080d028 = *(short *)(_DAT_0080d01e + 0xc) + 1;
        _fuel_arbitrator_condition_flag = 3;
        _DAT_0080cffa = 2;
        _DAT_0080d00c = 0;
        _fuel_arbitrator_conditional_limit = _oil_pressure_precrank_status;
        local_8 = (byte *)CONCAT31(local_8._0_3_,cVar4 + '\x03');
        bVar2 = *local_8;
        if (bVar2 < 0x80) {
          local_c = (ushort)bVar2;
        }
        else {
          local_c = CONCAT11(0xff,bVar2);
        }
        iVar7 = ((int)(short)(the_maximum_speed_a_customer_may_program_to_correspond_with_s_1_5_15 -
                             _DAT_0080bda0) * (short)local_c * 0x100) / 0x6400;
        _DAT_0080d00e = _DAT_0080bd8c + (short)iVar7;
        iVar7 = CONCAT22((short)((uint)iVar7 >> 0x10),_DAT_0080d00e);
        sVar5 = _DAT_0080d028;
        if (_DAT_0080d00e < 0) {
          _DAT_0080d00e = 0;
          sVar5 = _DAT_0080d028;
        }
      }
      _DAT_0080d036 = sVar5;
      uVar6 = CONCAT22((short)((uint)iVar7 >> 0x10),_DAT_0080cff8) & 0xffff0010;
      if ((_DAT_0080cff8 & 0x10) == 0) {
        _DAT_0080cffe = 0;
        _DAT_0080d036 = 0;
      }
      else {
        _DAT_0080cffe = 1;
      }
    }
  }
  return uVar6;
}



//
// Function: FUN_0001ac64 @ 0x0001ac64
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001ac64(void)

{
  undefined4 local_8;
  
  if (*_enables_input_of_eps_period_data_to_pptb_0_1 == '\x02') {
    local_8._3_1_ = (char)_enables_input_of_eps_period_data_to_pptb_0_1;
    local_8 = (byte *)CONCAT31((int3)((uint)_enables_input_of_eps_period_data_to_pptb_0_1 >> 8),
                               (char)local_8 + '\x02');
    if ((*local_8 & 1) != 0) {
      FUN_0001a398();
      DAT_0080d03a = 0;
    }
    if ((*local_8 & 8) != 0) {
      FUN_0001ad50();
    }
  }
  return;
}



//
// Function: FUN_0001aca8 @ 0x0001aca8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001aca8(void)

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
    _DAT_00805e00 = _DAT_00805e00 | 4;
    _DAT_00805e40 = _DAT_00805e40 | 4;
  }
  else {
    local_8._3_1_ = (char)_DAT_0080d2b4;
    cVar1 = (char)local_8;
    local_8._0_3_ = (undefined3)((uint)_DAT_0080d2b4 >> 8);
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
    *local_8 = 0x53;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar1 + '\x02');
    uVar3 = 0;
    if (vp44_injection_system_active == 1) {
      uVar3 = 2;
    }
    *local_8 = uVar3;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar1 + '\x03');
    *_DAT_0080d2b4 = 2;
    *local_8 = 0;
    _DAT_0080d2b4 = local_8;
    FUN_00013242();
  }
  return;
}



//
// Function: FUN_0001ad50 @ 0x0001ad50
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001ad50(void)

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
    _DAT_00805e00 = _DAT_00805e00 | 4;
    _DAT_00805e40 = _DAT_00805e40 | 4;
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
    FUN_00013242();
  }
  return;
}



//
// Function: FUN_0001ae20 @ 0x0001ae20
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001ae20(void)

{
  uint uVar1;
  
  uVar1 = _diagnostic_system_flags_2 & 0x100;
  if (((_diagnostic_system_flags_2 & 0x100) != 0) &&
     (uVar1 = _DAT_008086f2 + _DAT_008054a8, uVar1 < loopCounter)) {
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
// Function: FUN_0001ae74 @ 0x0001ae74
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001ae74(undefined4 param_1)

{
  undefined4 in_D0;
  uint uVar1;
  
  uVar1 = CONCAT22((short)((uint)in_D0 >> 0x10),_diagnostic_system_flags_2) & 0xffff0080;
  if ((_diagnostic_system_flags_2 & 0x80) != 0) {
    if (param_1._0_2_ == 1) {
      _DAT_008054a6 = _DAT_008054a6 + 1;
      _DAT_008054b2 = _DAT_008054b2 + 1;
      _DAT_008054b4 = loopCounter;
      _DAT_008054a8 = loopCounter;
      return loopCounter;
    }
    if (param_1._0_2_ == 2) {
      _DAT_008054a6 = _DAT_008054a6 + 1;
      _DAT_008054b8 = _DAT_008054b8 + 1;
      _DAT_008054ba = loopCounter;
      _DAT_008054a8 = loopCounter;
      return loopCounter;
    }
    if (param_1._0_2_ != 3) {
      return (int)param_1._0_2_;
    }
    _DAT_008054a6 = _DAT_008054a6 + 1;
    _DAT_008054ac = _DAT_008054ac + 1;
    _DAT_008054ae = loopCounter;
    _DAT_008054a8 = loopCounter;
    uVar1 = loopCounter;
  }
  return uVar1;
}



//
// Function: FUN_0001aef4 @ 0x0001aef4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001aef4(void)

{
  byte bVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  dword *pdVar5;
  
  bVar1 = 0;
  puVar2 = (undefined2 *)((int)&mask_used_for_can_msg_object_15_0_ffffffff + 2);
  puVar3 = (undefined2 *)&DAT_0080cfc4;
  puVar4 = (undefined2 *)&DAT_0080cfba;
  pdVar5 = &the_can_extended_mask_0x0_0xffffffff;
  do {
    *puVar4 = *(undefined2 *)pdVar5;
    *puVar3 = *puVar2;
    bVar1 = bVar1 + 1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
    pdVar5 = (dword *)((int)pdVar5 + 2);
  } while (bVar1 < 4);
  _DAT_0080cfc2 = mask_used_for_can_msg_object_15_0_ffffffff._2_2_;
  _DAT_0080cfcc = the_can_cpu_interface_register_0_255;
  return;
}



//
// Function: timerSchedulerSetup @ 0x0001af38
// ERROR: Failed to decompile
//

//
// Function: FUN_0001afe4 @ 0x0001afe4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0001afe4(void)

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
// Function: FUN_0001b07c @ 0x0001b07c
//

void FUN_0001b07c(void)

{
  return;
}



//
// Function: FUN_0001b082 @ 0x0001b082
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001b082(int param_1,undefined4 param_2)

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
// Function: FUN_0001b150 @ 0x0001b150
//

void FUN_0001b150(int param_1)

{
  ushort in_stack_00000000;
  
  FUN_0001b082(param_1,(uint)in_stack_00000000);
  return;
}



//
// Function: FUN_0001b160 @ 0x0001b160
//

void FUN_0001b160(int param_1)

{
  undefined2 in_stack_00000000;
  
  FUN_0001b082(param_1,CONCAT22(1,in_stack_00000000));
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
  dword *pdVar4;
  byte bVar5;
  char *pcVar6;
  short *psVar7;
  undefined *puVar8;
  undefined2 local_6;
  
  uVar3 = hardware_timer_register._0_2_;
  pdVar4 = (dword *)(CONCAT22((short)((uint)in_D0 >> 0x10),_DAT_008035ea) & 0xffff0008);
  if ((_DAT_008035ea & 8) != 0) {
    while ((pdVar4 = (dword *)((uint)hardware_timer_register._0_2_ - (uint)uVar3),
           (int)((uint)hardware_timer_register._0_2_ - (uint)uVar3) < 0xfa &&
           ((_DAT_0080cf80 != _DAT_0080cf84 || (pdVar4 = _DAT_0080cf80, DAT_0080cf89 == '\x01')))))
    {
      bVar5 = *(byte *)((int)_DAT_0080cf84 + 1);
      if (bVar5 < 0xf0) {
        local_6 = (ushort)bVar5 << 8;
      }
      else {
        local_6 = CONCAT11(bVar5,*(undefined1 *)((int)_DAT_0080cf84 + 2));
      }
      bVar2 = false;
      pcVar6 = &DAT_0080cfa4;
      do {
        if (*pcVar6 == -2) goto LAB_0001b262;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while ((char)*_DAT_0080cf84 != cVar1);
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
      _DAT_0080cf84 = (dword *)((int)_DAT_0080cf84 + 0x12);
      if ((dword *)0x80ce4e < _DAT_0080cf84) {
        _DAT_0080cf84 = &average_pulse_period_time_period_over_1_cyl_of_primary_s_1000_65535;
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
  return (uint)pdVar4;
}



//
// Function: FUN_0001b314 @ 0x0001b314
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0001b314(void)

{
  ushort uVar1;
  
  uVar1 = _diagnostic_system_flags_2 & 0x1000;
  if (((((_diagnostic_system_flags_2 & 0x1000) != 0) && (_DAT_0080cfa8 == 2)) &&
      (_DAT_0080cfaa == 1)) &&
     (((_fuel_arbitrator_condition_flag == 1 && (_DAT_0080cffa == 1)) &&
      (uVar1 = cached_parameter_value, _DAT_0080894c <= cached_parameter_value)))) {
    _DAT_0080cfb0 = 0;
    _retarder_mode_table_count = 3;
    _DAT_0080cffe = 0;
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
  char cVar6;
  undefined4 unaff_D2;
  short sVar7;
  ushort uVar8;
  undefined2 uVar9;
  
  uVar9 = (undefined2)((uint)unaff_D2 >> 0x10);
  if (0x6e4 < param_3) {
    return 2;
  }
  sVar7 = (short)param_3;
  uVar3 = addressLookupFunction
                    (CONCAT22((short)CONCAT31((int3)((uint)in_D0 >> 8),
                                              **(undefined1 **)(param_1 + 6)),uVar9));
  uVar8 = sVar7 + ((ushort)uVar3 & 0xff);
  if (uVar8 < 8) {
    uVar8 = 8;
  }
  if (uVar8 == *(ushort *)(param_1 + 4)) {
    bVar2 = false;
  }
  else {
    if (uVar8 + 10 != (uint)*(ushort *)(param_1 + 4)) {
      return 2;
    }
    bVar2 = true;
  }
  puVar1 = (undefined1 *)(*(int *)(param_1 + 6) + (uVar3 & 0xff));
  uVar4 = addressRangeValidator((uint)param_2,CONCAT22(sVar7,uVar9));
  uVar5 = uVar4 & 0xff;
  uVar3 = uVar5;
  if (uVar5 < 6) {
    uVar3 = (uint)(&switchD_0001b416::switchdataD_0001b41a)[uVar5];
    switch(uVar5) {
    case 0:
      uVar3 = memcpy(param_2,puVar1,CONCAT22(sVar7,uVar9));
      return uVar3 & 0xffffff00;
    case 3:
      if (_security_bypass_flag != 0xff) {
        if (!bVar2) {
          return 3;
        }
        cVar6 = systemSecurityCheck();
        if (cVar6 != '\0') {
          return 3;
        }
      }
      uVar3 = memcpy(param_2,puVar1,CONCAT22(sVar7,uVar9));
      return uVar3 & 0xffffff00;
    case 4:
      return 10;
    case 5:
      if ((points_to_water_in_fuel_fuel_maximum_threshold_0_2_32._2_2_ == 1) &&
         (amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535 != 0)) {
        return 7;
      }
      if (_security_bypass_flag != 0xff) {
        if (!bVar2) {
          return 3;
        }
        cVar6 = systemSecurityCheck();
        if (cVar6 != '\0') {
          return 3;
        }
      }
      if (amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535 == 1) {
        cVar6 = circularBufferWrite((short)((uint)puVar1 >> 0x10),sVar7);
        if (cVar6 == '\x01') {
          return 0xb;
        }
      }
      uVar3 = memcpy(param_2 + -0x7fcb08,puVar1,CONCAT22(sVar7,uVar9));
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
// Function: FUN_0001b56e @ 0x0001b56e
//

void FUN_0001b56e(int param_1)

{
  undefined4 unaff_A2;
  undefined1 local_6 [2];
  
  memcpy(local_6,(undefined1 *)(*(int *)(param_1 + 6) + 1),
         CONCAT22(2,(short)((uint)unaff_A2 >> 0x10)));
  FUN_0001b532(param_1);
  return;
}



//
// Function: FUN_0001b5b6 @ 0x0001b5b6
//

void FUN_0001b5b6(int param_1)

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
// Function: FUN_0001b604 @ 0x0001b604
//

void FUN_0001b604(int param_1)

{
  undefined4 unaff_A2;
  undefined1 local_6 [2];
  
  memcpy(local_6,(undefined1 *)(*(int *)(param_1 + 6) + 1),
         CONCAT22(2,(short)((uint)unaff_A2 >> 0x10)));
  FUN_0001b532(param_1);
  return;
}



//
// Function: FUN_0001b668 @ 0x0001b668
//

void FUN_0001b668(int param_1)

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
// Function: FUN_0001b6ce @ 0x0001b6ce
//

void FUN_0001b6ce(int param_1)

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
// Function: FUN_0001b716 @ 0x0001b716
//

void FUN_0001b716(int param_1)

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
// Function: FUN_0001b7e8 @ 0x0001b7e8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0001b7e8(int param_1)

{
  byte bVar1;
  undefined3 extraout_var;
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
  if ((('\x01' << (bVar1 & 7) &
       *(byte *)((int)&can_number_of_retarder_destination_non_specific_rx_objects_0_14 +
                ((int)(uint)bVar1 >> 3))) == 0) || (_security_bypass_flag != -0x4ade)) {
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
// Function: FUN_0001b8b8 @ 0x0001b8b8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001b8b8(undefined4 param_1)

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
// Function: FUN_0001b916 @ 0x0001b916
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001b916(undefined4 param_1)

{
  if (param_1._1_1_ == '\0') {
    _DAT_0080556c = 1;
    _DAT_00805570 = _DAT_0080cffa;
    DAT_0080553a = 0;
    DAT_0080553b = DAT_0080d018;
    _DAT_0080553c = _DAT_0080cffa;
    _DAT_0080553e = 1;
    _DAT_00805540 = _fuel_arbitrator_condition_flag;
    _DAT_00805542 = 0;
    _DAT_00805544 = 0;
    _DAT_00805546 = 0;
    _DAT_00805548 = 0;
    _DAT_0080554a = loopCounter;
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
  _DAT_00805564 = loopCounter;
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
  uVar2 = CONCAT22(uVar1,_diagnostic_system_flags_2) & 0xffff0800;
  if ((_diagnostic_system_flags_2 & 0x800) != 0) {
    uVar2 = CONCAT22(uVar1,_fuel_arbitrator_condition_flag);
    if (((_fuel_arbitrator_condition_flag != _DAT_008007ac) ||
        (uVar2 = CONCAT22(uVar1,_DAT_0080d014), _DAT_0080d014 != _DAT_008007b0)) ||
       (uVar2 = CONCAT31((int3)(uVar2 >> 8),DAT_0080d018), DAT_0080d018 != DAT_008007b2)) {
      if (_fuel_arbitrator_condition_flag == 0) {
        if ((_DAT_008007ac != 0) && (_DAT_008007b0 == 1)) {
          _DAT_0080556c = 0;
          _DAT_0080554e = loopCounter - _DAT_0080554a;
          uVar2 = FUN_0001b8b8((uint)uVar4);
        }
      }
      else if (_DAT_0080d014 == 1) {
        if (_DAT_0080556c == 1) {
          if (DAT_0080d018 == DAT_008007b2) {
            if (_DAT_0080553e < 5) {
              uVar2 = (uint)_DAT_0080553e;
              _DAT_0080553e = _DAT_0080553e + 1;
              *(short *)(&DAT_00805540 + uVar2 * 2) = _fuel_arbitrator_condition_flag;
            }
            else {
              uVar2 = 0;
              for (puVar3 = (undefined2 *)&DAT_00805540; puVar3 < &DAT_00805548; puVar3 = puVar3 + 1
                  ) {
                *puVar3 = puVar3[1];
              }
              _DAT_00805548 = _fuel_arbitrator_condition_flag;
            }
          }
          else {
            _DAT_0080554e = loopCounter - _DAT_0080554a;
            FUN_0001b8b8((uint)uVar4);
            uVar2 = FUN_0001b916((uint)uVar4);
          }
        }
        else {
          uVar2 = FUN_0001b916((uint)uVar4);
        }
      }
      else if (_DAT_008007b0 == 1) {
        _DAT_0080556c = 0;
        uVar2 = FUN_0001b8b8((uint)uVar4);
      }
    }
    _DAT_008007ac = _fuel_arbitrator_condition_flag;
    _DAT_008007b0 = _DAT_0080d014;
    DAT_008007b2 = DAT_0080d018;
    uVar2 = CONCAT22((short)(uVar2 >> 0x10),_DAT_0080cfa8);
    if ((_DAT_0080cfa8 != _DAT_008007ae) || (uVar2 = (uint)_DAT_0080cfac, uVar2 != DAT_008007b3)) {
      if (_DAT_0080cfa8 == 0) {
        if (_DAT_008007ae != 0) {
          _DAT_0080556e = 0;
          _DAT_00805568 = loopCounter - _DAT_00805564;
          uVar2 = FUN_0001b8b8(CONCAT22(1,uVar4));
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
          _DAT_00805568 = loopCounter - _DAT_00805564;
          FUN_0001b8b8(CONCAT22(1,uVar4));
          uVar2 = FUN_0001b916(CONCAT22(1,uVar4));
        }
      }
      else {
        uVar2 = FUN_0001b916(CONCAT22(1,uVar4));
      }
    }
    _DAT_008007ae = _DAT_0080cfa8;
    DAT_008007b3 = DAT_0080cfad;
  }
  return uVar2;
}



//
// Function: FUN_0001bc1e @ 0x0001bc1e
//

undefined4 FUN_0001bc1e(undefined4 *param_1)

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
// Function: FUN_0001bc52 @ 0x0001bc52
//

undefined2 FUN_0001bc52(undefined2 *param_1)

{
  undefined2 local_6;
  
  local_6._1_1_ = (undefined1)*param_1;
  local_6._0_1_ = (undefined1)((ushort)*param_1 >> 8);
  local_6 = CONCAT11((undefined1)local_6,local_6._0_1_);
  return local_6;
}



//
// Function: FUN_0001bc74 @ 0x0001bc74
//

uint FUN_0001bc74(void)

{
  uint in_D0;
  uint uVar1;
  
  uVar1 = in_D0 & 0xffffff00;
  if ((io_control_source_register & 0x10) != 0) {
    uVar1 = 0x40;
  }
  if ((io_control_source_register & 2) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  if ((io_control_source_register & 0x40) != 0) {
    uVar1 = uVar1 | 4;
  }
  return uVar1;
}



//
// Function: FUN_0001bc9c @ 0x0001bc9c
//

undefined4 FUN_0001bc9c(undefined1 *param_1)

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
// Function: FUN_0001bd76 @ 0x0001bd76
//

undefined4 FUN_0001bd76(byte *param_1,undefined1 *param_2,uint param_3)

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
  msg_header = (j1939_header_t *)FUN_0001cb18(CONCAT22(uVar10 + bVar8 + 1,uVar7));
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
// Function: FUN_0001bedc @ 0x0001bedc
// ERROR: Failed to decompile
//

//
// Function: FUN_0001bf18 @ 0x0001bf18
//

void FUN_0001bf18(int param_1)

{
  undefined4 unaff_A2;
  undefined1 *puVar1;
  undefined1 local_a [4];
  undefined1 local_6 [2];
  
  puVar1 = local_6;
  memcpy(puVar1,(undefined1 *)(*(int *)(param_1 + 6) + 1),
         CONCAT22(2,(short)((uint)unaff_A2 >> 0x10)));
  memcpy(local_a,(undefined1 *)(*(int *)(param_1 + 6) + 3),CONCAT22(4,(short)puVar1));
  FUN_0001bedc(param_1);
  return;
}



//
// Function: FUN_0001bf64 @ 0x0001bf64
//

void FUN_0001bf64(int param_1)

{
  undefined4 unaff_A2;
  undefined1 local_6 [2];
  
  memcpy(local_6,(undefined1 *)(*(int *)(param_1 + 6) + 1),
         CONCAT22(2,(short)((uint)unaff_A2 >> 0x10)));
  FUN_0001bedc(param_1);
  return;
}



//
// Function: FUN_0001bfc8 @ 0x0001bfc8
//

void FUN_0001bfc8(int param_1)

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
  FUN_0001bedc(param_1);
  return;
}



//
// Function: FUN_0001c02e @ 0x0001c02e
//

void FUN_0001c02e(byte *param_1)

{
  undefined4 unaff_A2;
  uint local_c;
  undefined1 *local_8;
  
  memcpy((undefined1 *)&local_8,(undefined1 *)(*(int *)(param_1 + 6) + 1),
         CONCAT22(4,(short)((uint)unaff_A2 >> 0x10)));
  local_c = (uint)*(byte *)(*(int *)(param_1 + 6) + 5);
  FUN_0001bd76(param_1,local_8,local_c);
  return;
}



//
// Function: FUN_0001c076 @ 0x0001c076
//

void FUN_0001c076(byte *param_1)

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
  FUN_0001bd76(param_1,local_8,local_c);
  return;
}



//
// Function: systemFunction5xCaller @ 0x0001c0c2
//

void systemFunction5xCaller(void)

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
  
  local_12 = CONCAT31(CONCAT21(0x18ec,param_1._1_1_),j1939_source_address_primary);
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
// Function: FUN_0001c440 @ 0x0001c440
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001c440(undefined4 param_1)

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
  
  local_12 = CONCAT31(CONCAT21(0x18ec,param_1._1_1_),j1939_source_address_primary);
  local_e = 8;
  local_c = &uStack_1c;
  uStack_1c = 0x13;
  uStack_1f = (undefined1)_DAT_00800f6a;
  uStack_1b = uStack_1f;
  local_20 = (undefined1)((ushort)_DAT_00800f6a >> 8);
  uStack_1a = local_20;
  bStack_19 = vp44_sequence_number;
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
  
  local_12 = CONCAT31(CONCAT21(0x18ec,param_1._1_1_),j1939_source_address_primary);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  if ((((vp44_response_buffer == 1) && (bVar3 != vp44_expected_sequence)) || (bVar2 != 0xef)) ||
     (0x6a4 < local_8)) {
    messageErrorHandler((uint)CONCAT21(CONCAT11(uVar4,bVar3),bVar2) << 8);
  }
  else {
    vp44_response_buffer = 1;
    _vp44_message_data = rx_msg->id;
    vp44_message_id = local_6;
    vp44_sequence_number = pbVar1[3];
    _DAT_00800f6a = local_8;
                    /* Constant: VP44_FUEL_TEMP_OFFSET = 112 */
    _vp44_timeout_counter = 0x70;
    vp44_retry_flag = 1;
    vp44_retry_count = vp44_sequence_number;
    if (5 < vp44_sequence_number) {
      vp44_retry_count = 5;
    }
    cVar5 = vp44MessageTransmitter(CONCAT22(CONCAT11(uVar4,bVar3),CONCAT11(uVar4,1)),0xef00);
    if (cVar5 != '\0') {
      messageErrorHandler(CONCAT22(CONCAT11(extraout_var,bVar3),vp44_message_id));
      vp44_response_buffer = 0;
    }
  }
  return;
}



//
// Function: FUN_0001c60e @ 0x0001c60e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001c60e(int param_1)

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
  
  if (((*(short *)(param_1 + 4) == 8) && (bVar2 = *(byte *)(param_1 + 3), vp44_response_buffer == 1)
      ) && (bVar2 == vp44_expected_sequence)) {
    bVar1 = **(byte **)(param_1 + 6);
    if (bVar1 == vp44_retry_flag) {
      if (bVar1 == vp44_sequence_number) {
        bVar8 = DAT_00800f6b + bVar1 * -7 + 7;
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
      vp44_retry_flag = vp44_retry_flag + 1;
      vp44_retry_count = vp44_retry_count - 1;
      if (vp44_retry_count == 0) {
        if (bVar1 == vp44_sequence_number) {
          FUN_0001c440(CONCAT22((short)CONCAT31((int3)((uint)puVar3 >> 8),bVar2),vp44_message_id));
          vp44_response_buffer = 0;
          _DAT_00800f6c = 0x800f78;
          FUN_0002729a(&vp44_message_data);
          return;
        }
        iVar5 = ((uint)vp44_sequence_number - (uint)vp44_retry_flag) + 1;
        if (iVar5 < 6) {
          vp44_retry_count = (vp44_sequence_number - vp44_retry_flag) + 1;
          iVar5 = CONCAT31((int3)((uint)iVar5 >> 8),vp44_retry_count);
        }
        else {
          vp44_retry_count = 5;
        }
        uVar4 = (undefined3)((uint)iVar5 >> 8);
        cVar6 = vp44MessageTransmitter
                          (CONCAT22((short)CONCAT31(uVar4,bVar2),
                                    (short)CONCAT31(uVar4,vp44_retry_flag)),vp44_message_id);
        if (cVar6 != '\0') {
          messageErrorHandler(CONCAT22((short)CONCAT31(extraout_var_00,bVar2),vp44_message_id));
          vp44_response_buffer = 0;
          return;
        }
      }
      else {
        _vp44_timeout_counter = 0x19;
      }
    }
    else {
      uVar4 = (undefined3)((uint)in_D0 >> 8);
      cVar6 = vp44MessageTransmitter
                        (CONCAT22((short)CONCAT31(uVar4,bVar2),
                                  (short)CONCAT31(uVar4,vp44_retry_flag)),vp44_message_id);
      if (cVar6 != '\0') {
        messageErrorHandler(CONCAT22((short)CONCAT31(extraout_var,bVar2),vp44_message_id));
        vp44_response_buffer = 0;
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
  else if (((vp44_response_buffer == 1) && (bVar1 == vp44_expected_sequence)) &&
          (local_6 == vp44_message_id)) {
    vp44_response_buffer = 0;
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
// Function: FUN_0001c87e @ 0x0001c87e
//

void FUN_0001c87e(void)

{
  can_std_rx_desc_t *unaff_A2;
  
  diagnosticParamRequestHandler(unaff_A2);
  return;
}



//
// Function: FUN_0001c88c @ 0x0001c88c
//

void FUN_0001c88c(void)

{
  can_std_rx_desc_t *unaff_A2;
  
  vp44FuelTempHandler(unaff_A2);
  return;
}



//
// Function: FUN_0001c89a @ 0x0001c89a
//

void FUN_0001c89a(void)

{
  can_std_rx_desc_t *unaff_A2;
  
  diagnosticStatusRequestHandler(unaff_A2);
  return;
}



//
// Function: FUN_0001c8a8 @ 0x0001c8a8
//

void FUN_0001c8a8(void)

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44ResponseTimeoutHandler(void)

{
  if (_vp44_timeout_counter == 0) {
    vp44_response_buffer = 0;
    return;
  }
  _vp44_timeout_counter = _vp44_timeout_counter + -1;
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
  if (vp44_response_buffer == 1) {
    vp44ResponseTimeoutHandler();
  }
  return;
}



//
// Function: FUN_0001cb18 @ 0x0001cb18
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0001cb18(undefined4 param_1)

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
// Function: FUN_0001cb6e @ 0x0001cb6e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001cb6e(void)

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
// Function: FUN_0001cbc2 @ 0x0001cbc2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001cbc2(void)

{
  undefined2 uVar1;
  undefined4 unaff_A2;
  
  uVar1 = _fuel_arbitrator_condition_flag;
  _DAT_0080161c = _fuel_arbitrator_condition_flag;
  _fuel_arbitrator_condition_flag = 0;
  _DAT_0080cffa = 0;
  _DAT_0080d00c = 0;
  FUN_0001ae74(CONCAT22(uVar1,(short)((uint)unaff_A2 >> 0x10)));
  _DAT_0080d028 = 0;
  _DAT_0080d026 = 0;
  return;
}



//
// Function: FUN_0001cbfe @ 0x0001cbfe
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001cbfe(void)

{
  _DAT_0080cfa8 = 0;
  _DAT_0080cfaa = 0;
  _DAT_0080cfb0 = 0;
  _retarder_mode_table_count = 3;
  _DAT_0080cffe = 0;
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
  bool bVar1;
  bool bVar2;
  bool bVar3;
  ushort uVar4;
  undefined2 uVar5;
  undefined3 uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 unaff_D2;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  
  uVar5 = (undefined2)((uint)unaff_D2 >> 0x10);
  bVar3 = false;
  bVar2 = false;
  bVar1 = false;
  if ((_DAT_00801622 != _arbitrator_special_mode_flag) && (_arbitrator_special_mode_flag == 1)) {
    _DAT_0080d030 = _DAT_008086e6 + 1;
    bVar1 = true;
  }
  if (_DAT_0080d02e != 0) {
    _DAT_0080d02e = _DAT_0080d02e + -1;
    bVar1 = true;
  }
  bVar9 = _DAT_0080d02e == 1;
  if (bVar9) {
    _arbitrator_special_mode_flag = 0;
    _DAT_0080d03c = 0;
    _DAT_0080d02e = 0;
    _DAT_0080d030 = 0;
  }
  if (_DAT_0080d030 != 0) {
    _DAT_0080d030 = _DAT_0080d030 + -1;
  }
  if (_DAT_0080d030 == 1) {
    _arbitrator_special_mode_flag = 0;
    _DAT_0080d03c = 1;
    _DAT_0080d02e = _DAT_008086ea + 1;
  }
  if (((_DAT_0080d034 != 0) && (_DAT_0080d034 = _DAT_0080d034 + -1, _DAT_00801628 != _DAT_0080d004))
     && (_DAT_0080d004 == 1)) {
    bVar1 = true;
  }
  bVar10 = _DAT_0080d034 == 1;
  if (bVar10) {
    _DAT_0080d004 = 0;
    _DAT_0080d034 = 0;
  }
  if (((_DAT_0080d032 != 0) && (_DAT_0080d032 = _DAT_0080d032 + -1, _DAT_0080162a != _DAT_0080d002))
     && (_DAT_0080d002 == 1)) {
    bVar1 = true;
  }
  bVar11 = _DAT_0080d032 == 1;
  if (bVar11) {
    _DAT_0080d002 = 0;
    _DAT_0080d032 = 0;
  }
  if (((_DAT_0080d036 != 0) && (_DAT_0080d036 = _DAT_0080d036 + -1, _DAT_0080162c != _DAT_0080cffe))
     && (_DAT_0080cffe == 1)) {
    bVar1 = true;
  }
  bVar12 = _DAT_0080d036 == 1;
  if (bVar12) {
    _DAT_0080cffe = 0;
    _DAT_0080d036 = 0;
  }
  bVar12 = bVar12 || (bVar11 || (bVar10 || bVar9));
  uVar4 = _fuel_arbitrator_condition_flag >> 0xf;
  if (((_fuel_arbitrator_condition_flag == _DAT_0080161c) && (_DAT_0080d014 == _DAT_0080161e)) &&
     (DAT_0080d018 == DAT_00801620)) {
    if (_DAT_0080d028 != 0) {
      _DAT_0080d028 = _DAT_0080d028 + -1;
    }
    if (_DAT_0080d026 != 0) {
      _DAT_0080d026 = _DAT_0080d026 + -1;
    }
    uVar7 = (uint)_fuel_arbitrator_condition_flag;
    uVar8 = uVar7;
    if (uVar7 < 4) {
      uVar8 = CONCAT22(uVar4,(&switchD_0001ce60::switchdataD_0001ce64)[uVar7]);
      uVar6 = (undefined3)(uVar8 >> 8);
      switch(uVar7) {
      case 1:
        if (_DAT_0080d028 == 1) {
          uVar8 = FUN_0001cbc2();
          bVar12 = true;
        }
        else if (_DAT_0080d026 == 1) {
          FUN_0001d228(CONCAT22(_DAT_0080d014,(short)CONCAT31(uVar6,DAT_0080d018)),CONCAT22(1,uVar5)
                      );
          uVar8 = FUN_0001cbc2();
        }
        break;
      case 2:
        if (_DAT_0080d028 == 1) {
          uVar8 = FUN_0001cbc2();
          bVar12 = true;
        }
        else if ((_DAT_0080d026 == 1) && (_DAT_0080d002 == 0)) {
          FUN_0001d228(CONCAT22(_DAT_0080d014,(short)CONCAT31(uVar6,DAT_0080d018)),CONCAT22(2,uVar5)
                      );
          uVar8 = FUN_0001cbc2();
        }
        break;
      case 3:
        if (_DAT_0080d028 == 1) {
          uVar8 = FUN_0001cbc2();
          bVar12 = true;
        }
      }
    }
  }
  else {
    uVar7 = (uint)_fuel_arbitrator_condition_flag;
    uVar8 = uVar7;
    if (uVar7 < 4) {
      uVar8 = (uint)uVar4 << 0x10;
      switch(uVar7) {
      case 0:
        _DAT_0080d026 = 0;
        break;
      case 1:
        _DAT_0080d026 = *(short *)(_DAT_0080d01e + 6) + 1;
        uVar8 = CONCAT22(uVar4,_DAT_0080d026);
        bVar1 = true;
        break;
      case 2:
        _DAT_0080d026 = *(short *)(_DAT_0080d01e + 10) + 1;
        uVar8 = CONCAT22(uVar4,_DAT_0080d026);
        bVar1 = true;
        break;
      case 3:
        _DAT_0080d026 = 0;
        bVar1 = true;
      }
    }
    if (_DAT_0080161e == 0) {
      uVar8 = FUN_0001ae74(CONCAT22(_DAT_0080161c,uVar5));
    }
  }
  if (bVar12) {
    if (_DAT_0080d014 == 1) {
      bVar3 = true;
    }
    else {
      bVar2 = true;
    }
  }
  else if (bVar1) {
    if (_DAT_0080d014 == 1) {
      DAT_0080162f = '\x01';
    }
    else {
      DAT_00801630 = '\x01';
    }
  }
  _DAT_0080161c = _fuel_arbitrator_condition_flag;
  _DAT_0080161e = _DAT_0080d014;
  DAT_00801620 = DAT_0080d018;
  _DAT_00801622 = _arbitrator_special_mode_flag;
  _DAT_00801628 = _DAT_0080d004;
  _DAT_0080162a = _DAT_0080d002;
  _DAT_0080162c = _DAT_0080cffe;
  uVar8 = CONCAT22((short)(uVar8 >> 0x10),_DAT_0080cfa8);
  if (_DAT_0080cfa8 == _DAT_00801624) {
    uVar8 = (uint)_DAT_0080cfac;
    if (uVar8 == DAT_00801626) {
      if (_DAT_0080d02c != 0) {
        _DAT_0080d02c = _DAT_0080d02c + -1;
      }
      if (_DAT_0080d02a != 0) {
        _DAT_0080d02a = _DAT_0080d02a + -1;
      }
      if (_DAT_0080cfa8 == 2) {
        if (_DAT_0080d02c == 1) {
          uVar8 = FUN_0001cbfe();
          bVar3 = true;
        }
        else if (_DAT_0080d02a == 1) {
          FUN_0001d268(CONCAT22(_DAT_0080cfac,uVar5));
          uVar8 = FUN_0001cbfe();
        }
      }
      else if ((_DAT_0080cfa8 == 3) && (_DAT_0080d02c == 1)) {
        uVar8 = FUN_0001cbfe();
        bVar3 = true;
      }
      goto LAB_0001d026;
    }
  }
  if (_DAT_0080cfa8 == 2) {
    _DAT_0080d02a = *(short *)(_DAT_0080d022 + 0x10) + 1;
    uVar8 = CONCAT22((short)(uVar8 >> 0x10),_DAT_0080d02a);
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
  if (bVar2) {
    uVar8 = (uint)_DAT_00805578;
    if ((int)uVar8 < (int)(_DAT_0080875e - 1)) {
      _DAT_00805578 = _DAT_00805578 + 1;
    }
    else {
      _DAT_00805e00 = _DAT_00805e00 | 8;
      _DAT_00805e40 = _DAT_00805e40 | 8;
      _DAT_00805578 = 0;
    }
    DAT_00801630 = '\0';
  }
  else if (DAT_00801630 == '\x01') {
    uVar5 = (undefined2)(uVar8 >> 0x10);
    uVar4 = _DAT_00805e00;
    if (((_DAT_00805e00 & 8) == 0) || (uVar4 = _DAT_008068d2, (_DAT_008068d2 & 8) == 0)) {
      uVar8 = CONCAT22(uVar5,uVar4) & 0xffff0008;
      DAT_00801630 = '\0';
    }
    else {
      uVar8 = CONCAT22(uVar5,_DAT_00805e00) & 0xffff0008;
      if ((_DAT_00805e00 & 8) != 0) {
        uVar8 = CONCAT22(uVar5,_DAT_00805e40) & 0xffff0008;
        if ((_DAT_00805e40 & 8) == 0) {
          _DAT_00805e00 = _DAT_00805e00 & 0xfff7;
          DAT_00801630 = '\0';
          _DAT_00805578 = 0;
        }
      }
    }
  }
  if (bVar3) {
    uVar8 = (uint)_DAT_0080557a;
    if ((int)uVar8 < (int)(_DAT_0080875e - 1)) {
      _DAT_0080557a = _DAT_0080557a + 1;
    }
    else {
      _DAT_00805dfc = _DAT_00805dfc | 0x400;
      _DAT_00805e3c = _DAT_00805e3c | 0x400;
    }
    DAT_0080162f = 0;
    return uVar8;
  }
  if (DAT_0080162f == '\x01') {
    uVar5 = (undefined2)(uVar8 >> 0x10);
    uVar4 = _DAT_00805dfc;
    if (((_DAT_00805dfc & 0x400) == 0) || (uVar4 = _DAT_008068ce, (_DAT_008068ce & 0x400) == 0)) {
      uVar8 = CONCAT22(uVar5,uVar4) & 0xffff0400;
      DAT_0080162f = '\0';
    }
    else {
      uVar8 = CONCAT22(uVar5,_DAT_00805dfc) & 0xffff0400;
      if ((_DAT_00805dfc & 0x400) != 0) {
        uVar8 = CONCAT22(uVar5,_DAT_00805e3c) & 0xffff0400;
        if ((_DAT_00805e3c & 0x400) == 0) {
          _DAT_00805dfc = _DAT_00805dfc & 0xfbff;
          DAT_0080162f = 0;
          _DAT_0080557a = 0;
          return uVar8;
        }
      }
    }
  }
  return uVar8;
}



//
// Function: FUN_0001d19c @ 0x0001d19c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001d19c(undefined4 param_1,undefined4 param_2)

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
// Function: FUN_0001d1ec @ 0x0001d1ec
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001d1ec(undefined4 param_1)

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
// Function: FUN_0001d228 @ 0x0001d228
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001d228(undefined4 param_1,undefined4 param_2)

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
// Function: FUN_0001d268 @ 0x0001d268
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001d268(undefined4 param_1)

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
// Function: FUN_0001d29c @ 0x0001d29c
//

void FUN_0001d29c(void)

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
// Function: FUN_0001d34e @ 0x0001d34e
//

void FUN_0001d34e(undefined4 param_1)

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
// Function: FUN_0001d3b8 @ 0x0001d3b8
//

void FUN_0001d3b8(undefined4 param_1)

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
// Function: FUN_0001d40c @ 0x0001d40c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001d40c(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 in_D0;
  uint uVar3;
  
  if ((_DAT_0080d04c & 0x20) == 0) {
    io_control_source_register = io_control_source_register & 0xdf;
  }
  else {
    io_control_source_register = io_control_source_register | 0x20;
  }
  if ((_DAT_0080d04c & 4) == 0) {
    io_control_source_register = io_control_source_register & 0xef;
  }
  else {
    io_control_source_register = io_control_source_register | 0x10;
  }
  if ((_DAT_0080d04c & 0x40) == 0) {
    io_control_source_register = io_control_source_register & 0xf7;
  }
  else {
    io_control_source_register = io_control_source_register | 8;
  }
  if ((_DAT_0080d04c & 1) == 0) {
    io_control_source_register = io_control_source_register & 0xfd;
  }
  else {
    io_control_source_register = io_control_source_register | 2;
  }
  uVar1 = (short)((uint)in_D0 >> 0x10);
  if ((_DAT_0080d04c & 8) == 0) {
    uVar2 = 0;
    uVar1 = 0;
    if ((DAT_0080bdf1 & 4) == 0) {
      io_control_source_register = io_control_source_register & 0xfe;
      goto LAB_0001d486;
    }
  }
  uVar2 = uVar1;
  io_control_source_register = io_control_source_register | 1;
LAB_0001d486:
  if ((_DAT_0080d04c & 2) == 0) {
    io_control_source_register = io_control_source_register & 0xbf;
  }
  else {
    io_control_source_register = io_control_source_register | 0x40;
  }
  uVar3 = CONCAT22(uVar2,_DAT_0080d04c) & 0xffff0010;
  if ((_DAT_0080d04c & 0x10) == 0) {
    uVar3 = DAT_0080bdf1 & 8;
    if ((DAT_0080bdf1 & 8) == 0) {
      io_control_source_register = io_control_source_register & 0xfb;
      return uVar3;
    }
  }
  io_control_source_register = io_control_source_register | 4;
  return uVar3;
}



//
// Function: FUN_0001d4bc @ 0x0001d4bc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001d4bc(void)

{
  uint uVar1;
  
  if ((io_control_source_register & 1) == 0) {
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
  if ((io_control_source_register & 2) == 0) {
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
  if ((io_control_source_register & 4) == 0) {
    accumulated_backup_eps_period_between_vss_interrupts_0_65535._0_2_ = 0;
  }
  else if (accumulated_backup_eps_period_between_vss_interrupts_0_65535._0_2_ == 0) {
    accumulated_backup_eps_period_between_vss_interrupts_0_65535._0_2_ = 1;
  }
  else if (accumulated_backup_eps_period_between_vss_interrupts_0_65535._0_2_ == 1) {
    if ((DAT_0080bdca & 4) != 0) {
      accumulated_backup_eps_period_between_vss_interrupts_0_65535._0_2_ = 2;
      _DAT_008016a6 = 0;
    }
  }
  else if (accumulated_backup_eps_period_between_vss_interrupts_0_65535._0_2_ == 2) {
    if (_DAT_008016a6 < 10) {
      _DAT_008016a6 = _DAT_008016a6 + 1;
    }
    else {
      accumulated_backup_eps_period_between_vss_interrupts_0_65535._0_2_ = 1;
      _DAT_008016a6 = 0;
    }
  }
  if ((io_control_source_register & 0x40) == 0) {
    accumulated_backup_eps_period_between_vss_interrupts_0_65535._2_2_ = 0;
  }
  else if (accumulated_backup_eps_period_between_vss_interrupts_0_65535._2_2_ == 0) {
    accumulated_backup_eps_period_between_vss_interrupts_0_65535._2_2_ = 1;
  }
  else if (accumulated_backup_eps_period_between_vss_interrupts_0_65535._2_2_ == 1) {
    if ((DAT_0080bdca & 0x40) != 0) {
      accumulated_backup_eps_period_between_vss_interrupts_0_65535._2_2_ = 2;
      _DAT_008016a8 = 0;
    }
  }
  else if (accumulated_backup_eps_period_between_vss_interrupts_0_65535._2_2_ == 2) {
    if (_DAT_008016a8 < 10) {
      _DAT_008016a8 = _DAT_008016a8 + 1;
    }
    else {
      accumulated_backup_eps_period_between_vss_interrupts_0_65535._2_2_ = 1;
      _DAT_008016a8 = 0;
    }
  }
  if ((io_control_source_register & 0x10) == 0) {
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
  if ((io_control_source_register & 0x20) == 0) {
    number_of_backup_eps_interrupts_between_vss_interrupts_0_65535 = 0;
  }
  else if (number_of_backup_eps_interrupts_between_vss_interrupts_0_65535 == 0) {
    number_of_backup_eps_interrupts_between_vss_interrupts_0_65535 = 1;
  }
  else if (number_of_backup_eps_interrupts_between_vss_interrupts_0_65535 == 1) {
    if ((DAT_0080bdca & 0x20) != 0) {
      number_of_backup_eps_interrupts_between_vss_interrupts_0_65535 = 2;
      _DAT_008016ac = 0;
    }
  }
  else if (number_of_backup_eps_interrupts_between_vss_interrupts_0_65535 == 2) {
    if (_DAT_008016ac < 10) {
      _DAT_008016ac = _DAT_008016ac + 1;
    }
    else {
      number_of_backup_eps_interrupts_between_vss_interrupts_0_65535 = 1;
      _DAT_008016ac = 0;
    }
  }
  if ((io_control_source_register & 8) == 0) {
    _DAT_0080d04a = 0;
    return io_control_source_register & 8;
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
// Function: FUN_0001d7d2 @ 0x0001d7d2
//

void FUN_0001d7d2(void)

{
  FUN_0001d40c();
  FUN_0001d4bc();
  return;
}



//
// Function: FUN_0001d7dc @ 0x0001d7dc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001d7dc(void)

{
  io_control_source_register = io_control_source_register & 0xfe;
  _DAT_008016a2 = 0;
  return;
}



//
// Function: FUN_0001d7ec @ 0x0001d7ec
//

void FUN_0001d7ec(void)

{
  DAT_00801670 = 1;
  DAT_00801671 = 1;
  DAT_00801683 = 0x7d;
  DAT_00801672 = 0;
  return;
}



//
// Function: FUN_0001d80c @ 0x0001d80c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001d80c(void)

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
// Function: FUN_0001d8cc @ 0x0001d8cc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001d8cc(void)

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
// Function: FUN_0001d904 @ 0x0001d904
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0001d904(void)

{
  undefined1 uVar1;
  
  uVar1 = 1;
  if (_DAT_0080cc72 == 0) {
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
// Function: FUN_0001d9ea @ 0x0001d9ea
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001d9ea(undefined4 param_1)

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
        in_D0 = FUN_0001d8cc();
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
        in_D0 = FUN_0001d8cc();
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
        in_D0 = FUN_0001d8cc();
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
// Function: FUN_0001dae8 @ 0x0001dae8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0001dae8(undefined4 param_1)

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
// Function: FUN_0001db2e @ 0x0001db2e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0001db2e(undefined4 param_1)

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
// Function: FUN_0001db66 @ 0x0001db66
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001db66(void)

{
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  byte bVar2;
  uint uVar1;
  undefined4 unaff_D2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((uint)unaff_D2 >> 0x10);
  if (((DAT_0080bdc7 & 0x80) != 0) && (engine_operating_mode == IDLE)) {
    DAT_00801684 = 1;
    if (((DAT_0080bdc7 & 0x80) == 0) || (DAT_00801687 != '\0')) {
      if (((DAT_0080bdc7 & 0x20) == 0) || (DAT_00801685 != '\0')) {
        uVar1 = 0;
        if (((DAT_0080bdc7 & 0x40) != 0) && (DAT_00801686 == '\0')) {
          bVar2 = FUN_0001db2e((uint)CONCAT12(DAT_00801683,uVar3));
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
        bVar2 = FUN_0001dae8((uint)CONCAT12(DAT_00801683,uVar3));
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
      bVar2 = FUN_0001dae8((uint)CONCAT12(DAT_00801683,uVar3));
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
      uVar1 = FUN_0001d9ea(CONCAT22(*(undefined2 *)(&DAT_008065cc + (uint)DAT_00801683 * 6),uVar3));
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
// Function: FUN_0001dd00 @ 0x0001dd00
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001dd00(void)

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
// Function: FUN_0001dfc2 @ 0x0001dfc2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001dfc2(void)

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
// Function: FUN_0001e050 @ 0x0001e050
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001e050(void)

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
// Function: FUN_0001e0d6 @ 0x0001e0d6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001e0d6(void)

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
// Function: FUN_0001e140 @ 0x0001e140
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001e140(void)

{
  uint uVar1;
  char cVar2;
  
  if (DAT_00801670 != '\0') {
    FUN_0001d80c();
    return;
  }
  uVar1 = FUN_0001db66();
  if ((char)uVar1 != '\0') {
    cVar2 = FUN_0001d904();
    if (cVar2 != '\0') {
      DAT_00801683 = 0x7d;
      FUN_0001dd00();
    }
  }
  if (_DAT_008016a0 < 0x191) {
    _DAT_008016a0 = _DAT_008016a0 + 1;
  }
  if (((99 < _DAT_008016a0) && (_DAT_008016a0 < 400)) &&
     (eps_period_backup_time_between_the_two_most_recent_eps_200_16777216._0_2_ != 0)) {
    FUN_0001dfc2();
  }
  if ((eps_period_backup_time_between_the_two_most_recent_eps_200_16777216._2_2_ != 0) ||
     (DAT_0080169a != '\0')) {
    FUN_0001e050();
  }
  if (((_DAT_0080373c != 0) &&
      (eps_period_backup_time_between_the_two_most_recent_eps_200_16777216._0_2_ != 0)) &&
     (engine_operating_mode == HIGH_RPM_RUNNING)) {
    FUN_0001e0d6();
  }
  DAT_00801685 = -((DAT_0080bdc7 & 0x20) != 0) & 1;
  DAT_00801686 = -((DAT_0080bdc7 & 0x40) != 0) & 1;
  DAT_00801687 = -((DAT_0080bdc7 & 0x80) != 0) & 1;
  return;
}



//
// Function: FUN_0001e210 @ 0x0001e210
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001e210(void)

{
  uint uVar1;
  
  if (diagnostic_status_register == 6) {
    cam_sync_lost_duration_0_20 = coreTableInterpolation();
    uVar1 = ((uint)_DAT_0080878a * (uint)cam_sync_lost_duration_0_20) / 0x7800;
    if ((uint)_DAT_0080878c < (uint)_DAT_00808790 + (uVar1 & 0xffff)) {
      backup_signal_edge_time_stamp_0_65535 = _DAT_00808790;
    }
    else {
      backup_signal_edge_time_stamp_0_65535 = _DAT_0080878c - (short)uVar1;
    }
    if (_derate_threshold_exceeded == 1) {
      if (_DAT_008016b8 == 1) {
        main_signal_edge_time_stamp_0_65535 = _DAT_0080878e + main_signal_edge_time_stamp_0_65535;
        if (backup_signal_edge_time_stamp_0_65535 < main_signal_edge_time_stamp_0_65535) {
          main_signal_edge_time_stamp_0_65535 = backup_signal_edge_time_stamp_0_65535;
        }
      }
      else {
        main_signal_edge_time_stamp_0_65535 = _DAT_00808792;
      }
    }
    else if (_derate_threshold_exceeded == 0) {
      main_signal_edge_time_stamp_0_65535 = mask_used_for_can_msg_object_15_0_ffffffff._0_2_;
    }
    cached_parameter_value = main_signal_edge_time_stamp_0_65535;
  }
  _DAT_008016b8 = _derate_threshold_exceeded;
  return;
}



//
// Function: FUN_0001e2d2 @ 0x0001e2d2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001e2d2(undefined4 param_1)

{
  if ((((_DAT_00808794 != 0) && (diagnostic_status_register == 0)) &&
      ((((_engine_fault_register_a & 2) != 0 && ((_engine_fault_register_b & 2) != 0)) ||
       (((_engine_fault_register_a & 4) != 0 && ((_engine_fault_register_b & 4) != 0)))))) &&
     (diagnostic_status_register = 6, param_1._0_2_ != 6)) {
    FUN_0001e33a();
  }
  return;
}



//
// Function: FUN_0001e33a @ 0x0001e33a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001e33a(void)

{
  main_signal_edge_time_stamp_0_65535 = _current_fuel_demand_value;
  _DAT_008016b4 = (uint)_current_engine_rpm_raw << 0x10;
  return;
}



//
// Function: FUN_0001e358 @ 0x0001e358
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001e358(void)

{
  _DAT_008016b4 = 0;
  _DAT_008016b0 = 0x808788;
  return;
}



//
// Function: FUN_0001e36a @ 0x0001e36a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001e36a(void)

{
  _DAT_008016c0 = current_engine_rpm;
  _DAT_0080d058 = lookupTableInterpolation((short *)&DAT_008016ba);
  _DAT_008016cc = current_engine_rpm;
  eps_main_lost_duration_0_20 = lookupTableInterpolation((short *)&DAT_008016c6);
  return;
}



//
// Function: FUN_0001e3a8 @ 0x0001e3a8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001e3a8(void)

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
// Function: FUN_0001e3dc @ 0x0001e3dc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001e3dc(void)

{
  ushort unaff_D2w;
  ushort unaff_D3w;
  undefined8 uVar1;
  
  if (_DAT_0080965a != 0) {
    _DAT_008016ee = _DAT_0080d06c;
    uVar1 = tableInterpolationLookup((short *)&DAT_008016e8);
    unaff_D3w = (ushort)((ulonglong)uVar1 >> 0x20);
  }
  if (_DAT_0080965a < 0x4000) {
    _DAT_00801702 = _DAT_0080d06c;
    uVar1 = tableInterpolationLookup((short *)&DAT_008016fc);
    unaff_D2w = (ushort)((ulonglong)uVar1 >> 0x20);
  }
  if (_DAT_0080965a == 0x4000) {
    _DAT_008016e6 = unaff_D3w;
    return;
  }
  if (_DAT_0080965a == 0) {
    _DAT_008016e6 = unaff_D2w;
    return;
  }
  _DAT_008016e6 =
       unaff_D2w + (short)((uint)_DAT_0080965a * ((uint)unaff_D3w - (uint)unaff_D2w) >> 0xe);
  return;
}



//
// Function: FUN_0001e462 @ 0x0001e462
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001e462(void)

{
  bool bVar1;
  word wVar2;
  short sVar4;
  int iVar3;
  undefined4 local_8;
  
  if (_fuel_arbitrator_condition_flag == 0) {
    _DAT_0080d092 = _DAT_0080d096;
  }
  else {
    _DAT_0080d092 = _DAT_00808836;
  }
  sVar4 = coreTableInterpolation();
  wVar2 = eps_external_lost_duration_0_20;
  _DAT_0080d06c = _DAT_0080d092 + sVar4;
  if (_DAT_008087e0 < _DAT_0080d06c) {
    _DAT_0080d06c = _DAT_008087e0;
  }
  _DAT_0080d06c = _DAT_0080d06c - _DAT_008087e8;
  if ((diagnostic_state_buffer_t_00809654.diagnostic_mode == 0xb) ||
     (current_engine_rpm < _DAT_0080d096)) {
    eps_external_lost_duration_0_20 = FUN_00035608();
    sVar4 = _DAT_0080d078;
    if ((short)_DAT_008087cc < (short)eps_external_lost_duration_0_20) {
      eps_external_lost_duration_0_20 = _DAT_008087cc;
      _DAT_008016d6 = (short)_DAT_008087cc * 0x10000 + -0x80000000;
    }
    else if ((short)eps_external_lost_duration_0_20 < (short)_DAT_008087ce) {
      eps_external_lost_duration_0_20 = _DAT_008087ce;
      _DAT_008016d6 = (short)_DAT_008087ce * 0x10000 + -0x80000000;
    }
    FUN_0001eb2a();
    if (((int)((int)_DAT_008087d6 + (uint)_DAT_0080d092) < (int)(uint)current_engine_rpm) &&
       (_diagnostic_rpm_threshold_status < _DAT_008087d8)) {
      _DAT_008016e2 = (uint)_DAT_008087d4 << 0x10;
      eps_external_lost_duration_0_20 = 0;
      _DAT_008016d6 = -0x80000000;
    }
    else {
      _DAT_0080d060 =
           (short)(((int)(short)eps_external_lost_duration_0_20 * (int)_DAT_0080d078) / 0x3c0);
      iVar3 = (int)_DAT_0080d07c * ((int)(short)eps_external_lost_duration_0_20 - (int)(short)wVar2)
      ;
      if (iVar3 < 0x783f0f) {
        if (iVar3 < -0x783fff) {
          _DAT_0080d062 = -0x8000;
        }
        else {
          _DAT_0080d062 =
               (short)((((int)(short)eps_external_lost_duration_0_20 - (int)(short)wVar2) *
                       (int)_DAT_0080d07c) / 0xf0);
        }
      }
      else {
        _DAT_0080d062 = 0x7fff;
      }
      FUN_0001e3dc();
      eps_raw_period_backup_raw_time_between_teeth_not_norm_d_to_1_200000._2_2_ =
           _DAT_008016e6 + _DAT_008087c0;
      if ((short)eps_raw_period_backup_raw_time_between_teeth_not_norm_d_to_1_200000._2_2_ < 0) {
        eps_raw_period_backup_raw_time_between_teeth_not_norm_d_to_1_200000._2_2_ = 0;
      }
      cam_sync_backup_lost_duration_duration_in_no_sync_state_0_20 = _DAT_008016e6 + _DAT_008087d0;
      local_8._2_2_ = (word)(((int)_DAT_0080d078 - (int)sVar4) * 0x44 >> 3);
      iVar3 = _DAT_008016e2 +
              (int)(short)eps_external_lost_duration_0_20 * (int)(short)(_DAT_0080d07a << 2) +
              (int)(short)eps_external_lost_duration_0_20 * (int)(short)local_8._2_2_ * -8 +
              _fuel_delivery_offset_correction * -0x10000;
      _DAT_008016e2 = (short)((uint)iVar3 >> 0x10);
      if (_DAT_008016e2 < (short)cam_sync_backup_lost_duration_duration_in_no_sync_state_0_20) {
        bVar1 = _DAT_008016e2 < (short)_DAT_008087d2;
        _DAT_008016e2 = iVar3;
        if (bVar1) {
          _DAT_008016e2 = (uint)_DAT_008087d2 << 0x10;
        }
      }
      else {
        _DAT_008016e2 = (uint)cam_sync_backup_lost_duration_duration_in_no_sync_state_0_20 << 0x10;
      }
      eps_raw_period_backup_raw_time_between_teeth_not_norm_d_to_1_200000._0_2_ = _DAT_008016e2;
      local_8 = (int)_DAT_008016e2 + (int)_DAT_0080d062 + (int)_DAT_0080d060;
      if ((_vp44_flag_register_1 & 0x200) != 0) {
        local_8 = (uint)fsmxthfl_calc_input + local_8;
      }
      if ((int)(uint)eps_raw_period_backup_raw_time_between_teeth_not_norm_d_to_1_200000._2_2_ <
          local_8) {
        eps_backup_lost_duration_0_20 =
             eps_raw_period_backup_raw_time_between_teeth_not_norm_d_to_1_200000._2_2_;
      }
      else if (local_8 < (int)(uint)_DAT_008087c2) {
        eps_backup_lost_duration_0_20 = _DAT_008087c2;
      }
      else {
        eps_backup_lost_duration_0_20 = local_8._2_2_;
      }
      if (diagnostic_state_buffer_t_00809654.diagnostic_mode == 0xb) {
        _diagnostic_rpm_threshold_status = eps_backup_lost_duration_0_20;
      }
    }
  }
  return;
}



//
// Function: FUN_0001e78e @ 0x0001e78e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001e78e(void)

{
  word wVar1;
  undefined *puVar2;
  word wStack_6;
  
  puVar2 = (undefined *)((uint)_DAT_008087e4 * (uint)_active_derate_value);
  if (&DAT_00009c40 < puVar2) {
    puVar2 = &DAT_00009c40;
  }
  _DAT_008016de = (int)puVar2 << 0x10;
  wStack_6 = (word)((int)_DAT_008087ca * ((int)_DAT_0080d06c - (int)(short)current_engine_rpm) >> 9)
  ;
  if ((short)_DAT_008087cc < (short)wStack_6) {
    wStack_6 = _DAT_008087cc;
  }
  else if ((short)wStack_6 < (short)_DAT_008087ce) {
    wStack_6 = _DAT_008087ce;
  }
  _DAT_008016d6 = (short)wStack_6 * 0x10000 + -0x80000000;
  eps_external_lost_duration_0_20 = wStack_6;
  FUN_0001eb86();
  FUN_0001e3dc();
  crank_sync_backup_lost_duration_amount_of_time_crank_sync_lost_1_20 =
       _DAT_008016e6 + _DAT_008087c4;
  _DAT_008016e2 =
       _current_fuel_demand_value -
       (short)(((int)(short)eps_external_lost_duration_0_20 * (int)_DAT_00808804) / 0x3c0);
  if ((_vp44_flag_register_1 & 0x200) != 0) {
    _DAT_008016e2 = _DAT_008016e2 - fsmxthfl_calc_input;
  }
  wVar1 = crank_sync_backup_lost_duration_amount_of_time_crank_sync_lost_1_20;
  if (((short)_DAT_008016e2 <=
       (short)crank_sync_backup_lost_duration_amount_of_time_crank_sync_lost_1_20) &&
     (wVar1 = _DAT_008016e2, (short)_DAT_008016e2 < (short)_DAT_008087c6)) {
    _DAT_008016e2 = _DAT_008087c6;
    wVar1 = _DAT_008016e2;
  }
  _DAT_008016e2 = wVar1;
  _DAT_008016e4 = 0;
  return;
}



//
// Function: FUN_0001e8a6 @ 0x0001e8a6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001e8a6(void)

{
  _DAT_008016da = 0x8087e2;
  _DAT_008016d2 = 0x8087c8;
  FUN_0001eb94();
  _DAT_008016ea = 0x807f42;
  _DAT_008016e8 = 2;
  _DAT_008016f6 = 400;
  _DAT_008016f2 = 0x807f68;
  _DAT_008016f0 = 2;
  _DAT_008016f8 = &lower_limitation_of_intake_manifold_temperature_to_inhibit_50_to_293;
  _DAT_008016fe = 0x808002;
  _DAT_008016fc = 2;
  _DAT_0080170a = 400;
  _DAT_00801706 = 0x808028;
  _DAT_00801704 = 2;
  _DAT_0080170c = 0x808032;
  return;
}



//
// Function: FUN_0001e92e @ 0x0001e92e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001e92e(void)

{
  undefined2 uVar1;
  uint uVar2;
  word wVar3;
  
  wVar3 = eps_external_lost_duration_0_20;
  if ((short)eps_external_lost_duration_0_20 < 0) {
    wVar3 = -eps_external_lost_duration_0_20;
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
    if (((int)(uint)current_engine_rpm <= (int)uVar2) ||
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
      uVar2 = CONCAT22(uVar1,_DAT_008035d6) & 0xffff1000;
      if (((_DAT_008035d6 & 0x1000) != 0) &&
         ((uVar2 = CONCAT22(uVar1,eps_external_lost_duration_0_20),
          _DAT_008087f8 < (short)eps_external_lost_duration_0_20 ||
          ((uVar2 = CONCAT22(uVar1,eps_external_lost_duration_0_20),
           _DAT_008087f6 < (short)eps_external_lost_duration_0_20 &&
           (uVar2 = (int)_DAT_008087ee + (uint)current_engine_rpm,
           (int)uVar2 < (int)(uint)_DAT_00801712)))))) {
        _DAT_0080d07e = 1;
      }
    }
    else if ((_DAT_0080d07e == 1) &&
            ((uVar2 = (int)_DAT_008087f6 - (int)_DAT_008087fc,
             (int)(short)eps_external_lost_duration_0_20 < (int)uVar2 ||
             ((uVar2 = CONCAT22((short)(uVar2 >> 0x10),eps_external_lost_duration_0_20),
              (short)eps_external_lost_duration_0_20 < _DAT_008087f8 &&
              (uVar2 = (int)_DAT_008087ee + (uint)_DAT_00801712,
              (int)uVar2 < (int)(uint)current_engine_rpm)))))) {
      _DAT_0080d07e = 0;
    }
  }
  if (_DAT_0080d07e == 1) {
    _DAT_00801710 = 1;
    _DAT_0080d08a = 0x8087fe;
  }
  _DAT_00801712 = current_engine_rpm;
  return uVar2;
}



//
// Function: FUN_0001eade @ 0x0001eade
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001eade(void)

{
  _DAT_00801712 = current_engine_rpm;
  _DAT_00801714 = 0;
  _DAT_00801716 = 0;
  return;
}



//
// Function: FUN_0001eaf6 @ 0x0001eaf6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001eaf6(void)

{
  _DAT_00801710 = 0;
  return;
}



//
// Function: FUN_0001eafe @ 0x0001eafe
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001eafe(undefined4 param_1)

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
// Function: FUN_0001eb2a @ 0x0001eb2a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001eb2a(void)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_D2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((uint)unaff_D2 >> 0x10);
  FUN_0001e92e();
  iVar1 = FUN_0001ee2c();
  uVar2 = FUN_0001eafe(CONCAT22((short)iVar1,uVar3));
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
// Function: FUN_0001eb86 @ 0x0001eb86
//

void FUN_0001eb86(void)

{
  FUN_0001eade();
  FUN_0001ecee();
  return;
}



//
// Function: FUN_0001eb94 @ 0x0001eb94
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001eb94(void)

{
  FUN_0001eaf6();
  _DAT_0080d07e = 0;
  _DAT_0080d084 = _DAT_00808804;
  _DAT_0080d086 = _DAT_00808806;
  _DAT_0080d088 = _DAT_00808808;
  return;
}



//
// Function: FUN_0001ebcc @ 0x0001ebcc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001ebcc(void)

{
  undefined2 uStack_6;
  
  if ((diagnostic_state_buffer_t_00809654.diagnostic_mode == 0xb) && (_DAT_0080d076 == 1)) {
    if ((_DAT_0080880e < (short)eps_external_lost_duration_0_20) ||
       (((short)eps_external_lost_duration_0_20 < _DAT_00808810 || (_DAT_008096aa != 0)))) {
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
               ((_DAT_008035d6 & 0x4000) != 0)) &&
              ((int)uStack_6 < (int)_DAT_0080880a - (int)_DAT_00808814)) {
        if (((_DAT_008035d6 & 0x2000) == 0) || (_DAT_0080880c < uStack_6)) {
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
// Function: FUN_0001ecee @ 0x0001ecee
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001ecee(void)

{
  _DAT_00801718 = 0;
  return;
}



//
// Function: FUN_0001ecf6 @ 0x0001ecf6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001ecf6(void)

{
  if (((_diagnostic_system_flags_1 & 8) == 0) ||
     (((_DAT_00805e00 & 2) != 0 && ((_DAT_008068d2 & 2) != 0)))) {
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
  if ((vp44_status_flags_2 & 1) == 0) {
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
// Function: FUN_0001ee02 @ 0x0001ee02
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0001ee02(void)

{
  if ((vp44_status_flags_2 & 1) == 0) {
    _DAT_0080557c = 0;
  }
  _DAT_0080d098 = 0;
  _DAT_0080171c = _DAT_0080557c;
  return vp44_status_flags_2 & 1;
}



//
// Function: FUN_0001ee2c @ 0x0001ee2c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0001ee2c(void)

{
  ushort uVar1;
  undefined4 in_D0;
  
  uVar1 = (ushort)((uint)in_D0 >> 0x10);
  if ((_fuel_arbitrator_condition_flag != 0) && (uVar1 = 0, (_DAT_008035d6 & 0x8000) != 0)) {
    _DAT_0080d080 = 4;
    _DAT_0080d08e = 0x808822;
    return 1;
  }
  return (uint)uVar1 << 0x10;
}



//
// Function: FUN_0001ee5c @ 0x0001ee5c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001ee5c(void)

{
  bool bVar1;
  bool bVar2;
  
  bVar2 = _DAT_0080926e < _DAT_0080882e;
  if ((vp44_status_flags_2 & 0x4000) == 0) {
    bVar1 = false;
  }
  else if (_DAT_0080d098 == 0) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (engine_operating_mode == IDLE) {
    _DAT_0080171e = 0;
    if (bVar2) {
      _DAT_0080d094 = _DAT_00808830;
    }
    else {
      _DAT_0080d094 = 0;
    }
  }
  else if (engine_operating_mode != LOW_RPM_RUNNING) {
    if ((bVar2) && (_DAT_0080171e < _DAT_00808832)) {
      _DAT_0080171e = _DAT_0080171e + 1;
    }
    if ((engine_operating_mode == HIGH_RPM_RUNNING) &&
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
// Function: FUN_0001ef18 @ 0x0001ef18
//

void FUN_0001ef18(void)

{
  FUN_0001ecf6();
  return;
}



//
// Function: FUN_0001ef20 @ 0x0001ef20
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001ef20(void)

{
  byte bVar1;
  word *pwVar2;
  
  if (_DAT_00801722 == 2) {
    if (_DAT_00fffd24 == 5) {
      if ((qadc_qadcivr & 1) == 0) {
        if (circular_buffer_count == 0) {
          _DAT_00801722 = 0;
          _DAT_00801720 = _DAT_0080c402;
          _DAT_00fffd24 = 3;
          DAT_00fffd42 = 0xbd;
          _DAT_00fffd26 = _DAT_0080c402;
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
    pwVar2 = &qadc_portqa;
    bVar1 = 4;
    do {
      if (amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535 != 0) {
        *(word *)(_DAT_00801730 + (uint)_DAT_00801720) = *pwVar2;
      }
      _DAT_00801720 = _DAT_00801720 + 2;
      if (0xfff < _DAT_00801720) {
        _DAT_00801720 = 0;
        DAT_00801734 = 1;
        bVar1 = 0x10;
      }
      pwVar2 = pwVar2 + 1;
      bVar1 = bVar1 + 1;
    } while (bVar1 < 0x10);
    if (circular_buffer_count == 0) {
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
    _DAT_00fffd28 = (&circular_buffer_metadata)[(short)_DAT_0080c3fa];
    DAT_00fffd44 = 0xfd;
    _DAT_00fffd2a = (ushort)(&circular_buffer_data)[(short)_DAT_0080c3fa];
    DAT_00fffd45 = 0x3d;
    _DAT_00801722 = 2;
    circular_buffer_count = circular_buffer_count - 1;
    _DAT_0080c3fa = _DAT_0080c3fa + 1 & 0x1ff;
  }
  return;
}



//
// Function: FUN_0001f068 @ 0x0001f068
//

undefined8 FUN_0001f068(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  tpu_cpr1._1_1_ = (byte)tpu_cpr1 & 0x7f;
  FUN_0001ef20();
  tpu_hssr1 = tpu_hssr1 | 0x8000;
  return CONCAT44(in_D0,in_D1);
}



//
// Function: FUN_0001f08e @ 0x0001f08e
//

void FUN_0001f08e(void)

{
  return;
}



//
// Function: FUN_0001f090 @ 0x0001f090
//

/* WARNING: Removing unreachable block (ram,0x0001f19e) */
/* WARNING: Removing unreachable block (ram,0x0001f1b0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001f090(void)

{
  ushort uVar1;
  
  FUN_0001f08e();
  _DAT_00808f06 = FUN_0001f068;
  tpu_hsqr1._0_1_ = 0x7b;
  tpu_hsqr1._1_1_ = 0xfe;
  tpu_hsqr0._1_1_ = 0xff;
  tpu_hssr0 = 0x8004;
  tpu_cpr0 = tpu_cpr0 & 0xf0f0 | 0xf02;
  tpu_hssr1 = tpu_hssr1 & 0x8000 | 0x1001;
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
  amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535 = 1;
  _DAT_00801730 = &can_message_buffer_start;
  _DAT_00801722 = 0;
  if (DAT_00801734 == '\0') {
    do {
    } while( true );
  }
  tpu_cpr0 = tpu_cpr0 | 0x8000;
  tpu_hssr1 = tpu_hssr1 & 0xff00 | 0x8023;
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
// Function: FUN_0001f1fa @ 0x0001f1fa
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001f1fa(void)

{
  short sVar1;
  short sVar2;
  
  _DAT_0080173c = current_engine_rpm;
  _DAT_00801748 = _DAT_0080926e;
  sVar1 = lookupTableInterpolation((short *)&DAT_00801742);
  sVar2 = lookupTableInterpolation((short *)&DAT_00801736);
  fsmxthfl_calc_input = sVar1 + sVar2;
  return;
}



//
// Function: FUN_0001f23e @ 0x0001f23e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001f23e(void)

{
  _DAT_0080173c = current_engine_rpm;
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
// Function: FUN_0001f28c @ 0x0001f28c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001f28c(void)

{
  crank_initial_advace_break_speed_0_1000 = 0;
  eps_period_backup_time_between_the_two_most_recent_eps_200_16777216._2_2_ = 0;
  crank_initial_fuel_break_speed_0_1000 = 0;
  _DAT_0080557e = 0;
  _DAT_00805586 = 0;
  _DAT_00805582 = 0;
  _DAT_0080558a = 0;
  eps_period_backup_time_between_the_two_most_recent_eps_200_16777216._0_2_ = 0;
  _DAT_0080558e = 0;
  _DAT_00805590 = _DAT_0080175c;
  return;
}



//
// Function: FUN_0001f2ce @ 0x0001f2ce
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001f2ce(void)

{
  short sVar1;
  short sVar2;
  
  _DAT_0080175c = (short)((_DAT_00805590 + 2) % 3);
  *(undefined4 *)((short)(_DAT_0080175c * 2) * 8 + 0x80559c) = _DAT_00805f2c;
  *(int *)((short)(_DAT_0080175c * 2) * 8 + 0x8055a0) =
       _fueling_val_to_be_added_to_crank_initial_fuel_val_0_100;
  *(undefined4 *)((short)(_DAT_0080175c * 2) * 8 + 0x8055ce) = _DAT_00805f6c;
  *(int *)((short)(_DAT_0080175c * 2) * 8 + 0x8055d2) = _crank_exit_fuel_adjustment_0_100;
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
  *(uint *)(sVar1 + 0x8055d6) = (uint)timing_command_before_cranking_is_envoked_0_120 << 7;
  if (0x63ff < crank_adjusted_initial_fuel_0_100) {
    *(undefined4 *)((short)(_DAT_0080175c * 2) * 8 + 0x8055a8) = _DAT_00805582;
    *(undefined4 *)((short)(_DAT_0080175c * 2) * 8 + 0x8055da) = _DAT_0080558a;
    return;
  }
  sVar2 = _DAT_0080175c << 4;
  *(int *)(sVar2 + 0x8055a8) =
       _fueling_val_to_be_added_to_crank_initial_fuel_val_0_100 +
       (*(int *)(sVar1 + 0x8055a4) - _DAT_0080557e);
  *(int *)((short)(_DAT_0080175c * 2) * 8 + 0x8055da) =
       _crank_exit_fuel_adjustment_0_100 + (*(int *)(sVar2 + 0x8055d6) - _DAT_00805586);
  return;
}



//
// Function: FUN_0001f4f8 @ 0x0001f4f8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001f4f8(void)

{
  undefined4 in_D0;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  undefined1 *puVar5;
  
  puVar5 = &stack0xffffffe0;
  uVar3 = CONCAT22((short)((uint)in_D0 >> 0x10),vp44_status_flags_2) & 0xffff2000;
  if ((vp44_status_flags_2 & 0x2000) != 0) {
    if ((ushort)(((uint)_DAT_0080373a << 8) / 10) <= crank_adjusted_initial_fuel_0_100) {
      eps_period_backup_time_between_the_two_most_recent_eps_200_16777216._0_2_ = 1;
    }
    _fueling_val_to_be_added_to_crank_initial_fuel_val_0_100 =
         _DAT_00805f2c - *(int *)((short)(_DAT_00805590 * 2) * 8 + 0x80559c);
    _crank_exit_fuel_adjustment_0_100 =
         _DAT_00805f6c - *(int *)((short)(_DAT_00805590 * 2) * 8 + 0x8055ce);
    if ((current_engine_rpm != 0) && (_DAT_00805f40 != 0)) {
      if (_DAT_0080888a < _DAT_00801758) {
        _DAT_0080558e = _DAT_0080558e | 2;
      }
      else {
        _DAT_00801758 = _DAT_00801758 + 1;
      }
    }
    if (((current_engine_rpm != 0) && ((_DAT_00805df2 & 0x800) != 0)) &&
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
      uVar4 = (ushort)((uint)uVar4 * (uint)param_scaling_factor >> 8);
      if (-(uint)uVar4 - 1 < _DAT_0080557e) {
        _DAT_0080558e = _DAT_0080558e | 8;
      }
      _DAT_0080557e = uVar4 + _DAT_0080557e;
      uVar1 = FUN_000357d2(_DAT_0080557e,0x6400,(uint)_DAT_0080d0c0 * 0x465);
      uVar4 = (short)_DAT_00805f6c - _DAT_00801754;
      _DAT_00801752 = _DAT_00805f6c;
      uVar4 = (ushort)((uint)uVar4 * (uint)param_scaling_factor >> 8);
      if (-(uint)uVar4 - 1 < _DAT_00805586) {
        _DAT_0080558e = _DAT_0080558e | 8;
      }
      _DAT_00805586 = uVar4 + _DAT_00805586;
      uVar2 = FUN_000357d2(_DAT_00805586,0x6400,
                           (uint)timing_command_before_cranking_is_envoked_0_120 << 7);
      puVar5 = &stack0xffffffe0;
      if ((uVar1 < uVar2) || (uVar3 = (uint)crank_adjusted_initial_rpm_0_1000, uVar1 < uVar3)) {
        if ((uVar1 < crank_adjusted_initial_rpm_0_1000) &&
           (uVar3 = (uint)crank_adjusted_initial_rpm_0_1000, uVar2 < uVar3)) {
          _DAT_0080d0ac = 3;
          crank_adjusted_initial_fuel_0_100 = crank_adjusted_initial_rpm_0_1000;
        }
        else {
          uVar3 = (uint)crank_adjusted_initial_rpm_0_1000;
          _DAT_0080d0ac = 2;
          crank_adjusted_initial_fuel_0_100 = (word)uVar2;
        }
      }
      else {
        _DAT_0080d0ac = 1;
        crank_adjusted_initial_fuel_0_100 = (word)uVar1;
      }
    }
    else if (_DAT_00803734 == 1) {
      puVar5 = &stack0xffffffd4;
      uVar3 = FUN_000357d2(_DAT_00805f2c - *(int *)((short)(_DAT_00805590 * 2) * 8 + 0x80559c),
                           0x6400,(uint)_DAT_00803736 * 0x465);
      crank_adjusted_initial_fuel_0_100 = (word)uVar3;
      _DAT_0080d0ac = 1;
    }
    else {
      crank_adjusted_initial_fuel_0_100 = crank_adjusted_initial_rpm_0_1000;
      _DAT_0080d0ac = 3;
    }
    if (((_DAT_00805582 == 0) && (_DAT_0080558a == 0)) &&
       (0x63ff < crank_adjusted_initial_fuel_0_100)) {
      _DAT_00805582 = _DAT_00805f2c - *(int *)((short)(_DAT_00805590 * 2) * 8 + 0x80559c);
      uVar3 = _DAT_00805f6c - *(int *)((short)(_DAT_00805590 * 2) * 8 + 0x8055ce);
      _DAT_0080558a = uVar3;
    }
    if ((_DAT_00801756 == 1) ||
       (eps_period_backup_time_between_the_two_most_recent_eps_200_16777216._2_2_ == 1)) {
      *(undefined4 *)(puVar5 + -4) = 0x1f7b4;
      FUN_0001f2ce();
      *(undefined4 *)(puVar5 + -4) = 0x1f7b8;
      uVar3 = FUN_0001f28c();
    }
    _DAT_00801756 = crank_initial_advace_break_speed_0_1000;
  }
  return uVar3;
}



//
// Function: FUN_0001f7cc @ 0x0001f7cc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001f7cc(void)

{
  short local_1c [4];
  undefined4 local_14;
  short local_10 [4];
  undefined4 local_8;
  
  _DAT_0080174e = _DAT_00805f2c;
  _DAT_00801752 = _DAT_00805f6c;
  param_scaling_factor = 0x100;
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
    timing_command_before_cranking_is_envoked_0_120 = lookupTableInterpolation(local_1c);
    local_10[3] = _DAT_00803738;
    _DAT_0080d0c0 = lookupTableInterpolation(local_10);
  }
  return;
}



//
// Function: FUN_0001f860 @ 0x0001f860
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001f860(void)

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
// Function: FUN_0001f8aa @ 0x0001f8aa
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001f8aa(void)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  
  if ((fsmxthfl_calc_input < _current_fuel_demand_value) &&
     (fsmxthfl_calc_input < _calculated_fuel_timing_value)) {
    uVar2 = FUN_000357d2((uint)_current_fuel_demand_value - (uint)fsmxthfl_calc_input,0x6400,
                         (uint)_calculated_fuel_timing_value - (uint)fsmxthfl_calc_input);
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
  if (fsmxthfl_calc_input < _current_fuel_demand_value) {
    if ((_DAT_0080cc5a < current_engine_rpm) && (_arbitrator_status_flag != 0)) {
      iVar1 = ((uint)_DAT_0080cc54 + (uint)current_engine_rpm) - (uint)_DAT_0080cc5a;
      uVar2 = iVar1 * 0x1111;
      if ((uint)_DAT_0080cc56 * (uint)_DAT_0080cc58 < uVar2 ||
          (uint)_DAT_0080cc56 * (uint)_DAT_0080cc58 + iVar1 * -0x1111 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = _DAT_0080cc56 - (short)(uVar2 / _DAT_0080cc58);
        if (0x1700 < uVar3) {
          uVar3 = 0x1700;
        }
      }
      if (uVar3 <= fsmxthfl_calc_input) {
        asthrfes_calc_input = 0;
        return;
      }
      uVar3 = uVar3 - fsmxthfl_calc_input;
    }
    else {
      if (_calculated_fuel_timing_value <= fsmxthfl_calc_input) {
        asthrfes_calc_input = 0;
        return;
      }
      uVar3 = _calculated_fuel_timing_value - fsmxthfl_calc_input;
    }
    uVar2 = (uint)(ushort)(_current_fuel_demand_value - fsmxthfl_calc_input) * 0x6400;
    if (uVar2 < (uint)uVar3 * 0x7f80) {
      asthrfes_calc_input = (word)(uVar2 / uVar3);
    }
    else {
      asthrfes_calc_input = 0x7f80;
    }
  }
  else {
    asthrfes_calc_input = 0;
  }
  return;
}



//
// Function: FUN_0001fa00 @ 0x0001fa00
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001fa00(void)

{
  char cVar2;
  uint uVar1;
  byte bVar3;
  
  if (DAT_0080d41a < 0x14) {
    *_DAT_0080d40c = DAT_0080d407;
    _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    cVar2 = (char)_DAT_00804f44;
    *_DAT_0080d40c = cVar2;
    _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    bVar3 = 1;
    for (; cVar2 != '\0'; cVar2 = cVar2 + -1) {
      *_DAT_0080d40c = (&DAT_00804e7c)[(short)(ushort)bVar3] | 0x80;
      _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      bVar3 = bVar3 + 1;
    }
    DAT_0080d418 = DAT_0080d41a + DAT_0080d418;
    DAT_0080d419 = DAT_0080d419 - DAT_0080d41a;
    return;
  }
  uVar1 = FUN_0001984e(0xe000f);
  if ((char)uVar1 == '\0') {
    bVar3 = 1;
    while (DAT_0080d444 <= DAT_0080d445) {
      while (cVar2 = DAT_0080d446 + -1, DAT_0080d446 != '\0') {
        DAT_0080d446 = cVar2;
        *_DAT_0080d40c = (&DAT_00804e7c)[(short)(ushort)bVar3] & 0x80;
        bVar3 = bVar3 + 1;
        _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      }
      if (DAT_0080d444 == DAT_0080d445) {
        DAT_0080d446 = cVar2;
        FUN_00019cbc();
        _DAT_0080d410 = _DAT_0080d40c;
        DAT_0080d444 = DAT_0080d444 + 1;
        DAT_0080d418 = '\0';
      }
      else {
        DAT_0080d446 = cVar2;
        FUN_00019952();
      }
    }
  }
  return;
}



//
// Function: FUN_0001fafe @ 0x0001fafe
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001fafe(void)

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
    *_DAT_0080d40c = DAT_0080d407;
    _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    if (DAT_0080d409 == '\0') {
      *_DAT_0080d40c = (char)_DAT_00804f40 * '\x02';
      _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      uVar4 = _DAT_00804f40;
      uVar6 = 1;
      while ((char)uVar4 != '\0') {
        uVar5 = (ushort)(byte)((char)uVar6 + 1);
        sVar2 = (ushort)(byte)(&DAT_00804e7c)[(short)uVar6] * 6;
        uVar6 = uVar5;
        if (((*(ushort *)(&DAT_008065ce + sVar2) & 0x2000) == 0) && ((&DAT_008065d0)[sVar2] != '\0')
           ) {
          *_DAT_0080d40c = (&DAT_008065d0)[sVar2];
          _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
          *_DAT_0080d40c = (byte)((int)(uint)*(ushort *)(&DAT_008065ce + sVar2) >> 7) & 0x3f;
          _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
          uVar4 = (ushort)(byte)((char)uVar4 - 1);
        }
      }
    }
    else {
      *_DAT_0080d40c = ((char)_DAT_00804f42 + (char)_DAT_00804f40) * '\x03';
      _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      uVar4 = _DAT_00804f40;
      uVar6 = 1;
      while ((char)uVar4 != '\0') {
        uVar5 = (ushort)(byte)((char)uVar6 + 1);
        bVar7 = (&DAT_00804e7c)[(short)uVar6];
        sVar2 = (ushort)bVar7 * 6;
        uVar6 = uVar5;
        if (((*(ushort *)(&DAT_008065ce + sVar2) & 0x2000) == 0) && ((&DAT_008065d0)[sVar2] != '\0')
           ) {
          *_DAT_0080d40c = (&DAT_008065d0)[sVar2];
          _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
          *_DAT_0080d40c = (byte)((int)(uint)*(ushort *)(&DAT_008065ce + sVar2) >> 7) & 0x3f | 0x80;
          _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
          *_DAT_0080d40c = (&DAT_00804fcd)[(short)((ushort)bVar7 * 5) * 2];
          _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
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
          *_DAT_0080d40c = (&DAT_008065d0)[sVar2];
          _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
          *_DAT_0080d40c = (byte)((int)(uint)*(ushort *)(&DAT_008065ce + sVar2) >> 7) & 0x3f | 0xc0;
          _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
          *_DAT_0080d40c = (&DAT_00804fcd)[(short)((ushort)bVar7 * 5) * 2];
          _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
          uVar4 = (ushort)(byte)((char)uVar4 - 1);
        }
      }
    }
    DAT_0080d418 = DAT_0080d41a + DAT_0080d418;
    DAT_0080d419 = DAT_0080d419 - DAT_0080d41a;
    return;
  }
  if (DAT_0080d409 == '\0') {
    uVar3 = FUN_0001984e(0xe000e);
    if ((char)uVar3 == '\0') {
      uVar4 = 1;
      while (DAT_0080d444 <= DAT_0080d445) {
        while (DAT_0080d446 != '\0') {
          uVar6 = (ushort)(byte)((char)uVar4 + 1);
          sVar2 = (ushort)(byte)(&DAT_00804e7c)[(short)uVar4] * 6;
          uVar4 = uVar6;
          if (((*(ushort *)(&DAT_008065ce + sVar2) & 0x2000) == 0) &&
             ((&DAT_008065d0)[sVar2] != '\0')) {
            *_DAT_0080d40c = (&DAT_008065d0)[sVar2];
            _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
            *_DAT_0080d40c = (byte)((int)(uint)*(ushort *)(&DAT_008065ce + sVar2) >> 7) & 0x3f;
            _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
            DAT_0080d446 = DAT_0080d446 + -2;
          }
        }
        if (DAT_0080d444 == DAT_0080d445) {
          FUN_00019cbc();
          _DAT_0080d410 = _DAT_0080d40c;
          DAT_0080d444 = DAT_0080d444 + 1;
          DAT_0080d418 = '\0';
        }
        else {
          FUN_00019952();
        }
      }
      return;
    }
  }
  else {
    uVar3 = FUN_0001984e(0xc000f);
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
            *_DAT_0080d40c = (&DAT_008065d0)[sVar2];
            _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
            *_DAT_0080d40c =
                 bVar7 | (byte)((int)(uint)*(ushort *)(&DAT_008065ce + sVar2) >> 7) & 0x3f | 0x80;
            _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
            *_DAT_0080d40c = (&DAT_00804fcd)[(short)((ushort)bVar1 * 5) * 2];
            _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
            uVar4 = (ushort)(byte)((char)uVar4 - 1);
            DAT_0080d446 = DAT_0080d446 + -3;
          }
        }
        if (DAT_0080d444 == DAT_0080d445) {
          FUN_00019cbc();
          _DAT_0080d410 = _DAT_0080d40c;
          DAT_0080d444 = DAT_0080d444 + 1;
          DAT_0080d418 = '\0';
        }
        else {
          FUN_00019952();
        }
      }
    }
  }
  return;
}



//
// Function: FUN_0001fec4 @ 0x0001fec4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001fec4(void)

{
  char cVar1;
  uint uVar2;
  byte bVar3;
  undefined1 *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  
  if (DAT_0080d41a < 0x14) {
    *_DAT_0080d40c = DAT_0080d407;
    _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    *_DAT_0080d40c = DAT_0080d41a - 2;
    _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    bVar3 = 0;
    puVar4 = &DAT_0000444b;
    do {
      *_DAT_0080d40c = *puVar4;
      _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      bVar3 = bVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (bVar3 < 4);
    *_DAT_0080d40c = 0x2a;
    _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    bVar3 = 0;
    puVar4 = &DAT_0000444f;
    do {
      *_DAT_0080d40c = *puVar4;
      _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      bVar3 = bVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (bVar3 < 4);
    *_DAT_0080d40c = 0x2a;
    _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    bVar3 = 0;
    puVar4 = &DAT_0000445f;
    do {
      *_DAT_0080d40c = *puVar4;
      _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      bVar3 = bVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (bVar3 < 0xc);
    DAT_0080d418 = DAT_0080d41a + DAT_0080d418;
    DAT_0080d419 = DAT_0080d419 - DAT_0080d41a;
    return;
  }
  uVar2 = FUN_0001984e(0xe000f);
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
        *_DAT_0080d40c = *puVar6;
        _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
        puVar6 = puVar6 + 1;
      }
      if (DAT_0080d444 == DAT_0080d445) {
        DAT_0080d446 = cVar1;
        FUN_00019cbc();
        _DAT_0080d410 = _DAT_0080d40c;
        DAT_0080d444 = DAT_0080d444 + 1;
        DAT_0080d418 = '\0';
      }
      else {
        DAT_0080d446 = cVar1;
        FUN_00019952();
      }
    }
  }
  return;
}



//
// Function: FUN_0002003c @ 0x0002003c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002003c(void)

{
  uint uVar1;
  byte bVar2;
  char *pcVar3;
  
  if (DAT_0080d41a < 0x14) {
    *_DAT_0080d40c = DAT_0080d407;
    _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    *_DAT_0080d40c = 0x14;
    _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    pcVar3 = s_CAPACITY_39442720003948543000394_00004499 + 0x1e;
    for (bVar2 = 0; bVar2 < 0x14; bVar2 = bVar2 + 1) {
      *_DAT_0080d40c = *pcVar3;
      _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      pcVar3 = pcVar3 + 1;
    }
    DAT_0080d418 = DAT_0080d41a + DAT_0080d418;
    DAT_0080d419 = DAT_0080d419 - DAT_0080d41a;
    return;
  }
  uVar1 = FUN_0001984e(0xe000f);
  if ((char)uVar1 == '\0') {
    pcVar3 = s_CAPACITY_39442720003948543000394_00004499 + 0x1e;
    while (DAT_0080d444 <= DAT_0080d445) {
      for (bVar2 = 0; bVar2 < DAT_0080d446; bVar2 = bVar2 + 1) {
        *_DAT_0080d40c = *pcVar3;
        _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
        pcVar3 = pcVar3 + 1;
      }
      if (DAT_0080d444 == DAT_0080d445) {
        FUN_00019cbc();
        _DAT_0080d410 = _DAT_0080d40c;
        DAT_0080d444 = DAT_0080d444 + 1;
        DAT_0080d418 = '\0';
      }
      else {
        FUN_00019952();
      }
    }
  }
  return;
}



//
// Function: FUN_0002011c @ 0x0002011c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002011c(void)

{
  char cVar1;
  uint uVar2;
  byte bVar3;
  undefined1 *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  
  if (DAT_0080d41a < 0x14) {
    *_DAT_0080d40c = DAT_0080d407;
    _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    *_DAT_0080d40c = DAT_0080d41a - 2;
    _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    *_DAT_0080d40c = 0x80;
    _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    bVar3 = 0;
    puVar4 = &DAT_00004404;
    do {
      *_DAT_0080d40c = *puVar4;
      _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      bVar3 = bVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (bVar3 < 5);
    *_DAT_0080d40c = 0x2a;
    _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    bVar3 = 0;
    puVar4 = &DAT_00004409;
    do {
      *_DAT_0080d40c = *puVar4;
      _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      bVar3 = bVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (bVar3 < 0x11);
    *_DAT_0080d40c = 0x2a;
    _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
    bVar3 = 0;
    puVar4 = &DAT_0000441a;
    do {
      *_DAT_0080d40c = *puVar4;
      _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      bVar3 = bVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (bVar3 < 4);
    DAT_0080d418 = DAT_0080d41a + DAT_0080d418;
    DAT_0080d419 = DAT_0080d419 - DAT_0080d41a;
    return;
  }
  uVar2 = FUN_0001984e(0xe000f);
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
        *_DAT_0080d40c = *puVar6;
        _DAT_0080d40c = (char *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
        puVar6 = puVar6 + 1;
      }
      if (DAT_0080d444 == DAT_0080d445) {
        DAT_0080d446 = cVar1;
        FUN_00019cbc();
        _DAT_0080d410 = _DAT_0080d40c;
        DAT_0080d444 = DAT_0080d444 + 1;
        DAT_0080d418 = '\0';
      }
      else {
        DAT_0080d446 = cVar1;
        FUN_00019952();
      }
    }
  }
  return;
}



//
// Function: FUN_000202a4 @ 0x000202a4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000202a4(void)

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
    uVar5 = FUN_00017ce2(&hour_meter_ecm_run_time_none,&local_5);
    if ((char)uVar5 != '\0') break;
    iVar4 = (uint)(local_5 & 0x7f) * 6;
    if ((((&DAT_008065d0)[iVar4] != '\0') && ((*(ushort *)(&DAT_008065ce + iVar4) & 0x800) == 0)) &&
       (((uint)DAT_000202a2 & 1 << ((int)(*(ushort *)(&DAT_008065ce + iVar4) & 0x780) >> 7)) != 0))
    {
      bVar1 = (&DAT_008065d0)[iVar4];
      bVar7 = '\x01' << (bVar1 & 7);
      sVar3 = (short)((int)(uint)bVar1 >> 3);
      if ((bVar7 & *(byte *)((int)&
                                  maximum_time_between_tailshaft_pulses_allowed_before_vehicle_0_04_40
                            + (int)sVar3)) != 0) {
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
  
  tpu_dscr._0_1_ = 0;
  tpu_cier = 0;
  REG_SIM_PICR = 0;
  REG_SIM_PITR = 0;
  can1_cantbsel = 0;
  _DAT_00fff400 = 0x1201;
  _DAT_00fff408 = 8;
  _DAT_00fff410 = 0x200;
  _DAT_00fff458 = 4;
  _DAT_00fff418 = 8;
  _DAT_00fff41a = 0;
  _DAT_00fff41c = 0;
  _DAT_00fff420 = 1;
  _DAT_00fff448 = 1;
  _DAT_00fff450 = 1;
  _DAT_00fff42a = 0xffff;
  _DAT_00fff42c = 0;
  _DAT_00fff428 = 8;
  _DAT_00fff432 = 0xffff;
  _DAT_00fff434 = 0;
  _DAT_00fff430 = 8;
  _DAT_00fff43a = 0xffff;
  _DAT_00fff43c = 0;
  _DAT_00fff438 = 8;
  _DAT_00fff442 = 0xffff;
  _DAT_00fff444 = 0;
  _DAT_00fff440 = 8;
  _DAT_00fff460 = 0x104;
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x576;
  FUN_0002939c();
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x57c;
  clearWorkingMemory();
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x582;
  firmwareDataCopyToWorkingMemory();
  points_to_water_in_fuel_fuel_maximum_threshold_0_2_32._0_2_ = 0xeeee;
  sim_data_direction_control = sim_data_direction_control | 8;
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x598;
  FUN_0001977e();
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x5ac;
  FUN_00026e7e();
  tpu_tpumcr = 5;
  tpu_dscr._0_1_ = 0x13;
  tpu_dscr._1_1_ = 0x50;
  cVar1 = '\0';
  cVar2 = '\0';
  cVar3 = '\0';
  bVar4 = 0;
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x5ca;
  FUN_0001f090();
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x5d0;
  FUN_0002622e();
  _DAT_0080fffe = (ushort)(byte)(in_XF << 4 | cVar1 << 3 | cVar2 << 2 | cVar3 << 1 | bVar4);
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x5e0;
  FUN_0000f1ae();
  if (_DAT_0080367e == 0) {
    _DAT_00805df2 = _DAT_00805df2 & 0xfbff;
  }
  else {
    _DAT_00805df2 = _DAT_00805df2 | 0x400;
    _DAT_00805e32 = _DAT_00805e32 | 0x400;
  }
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x61c;
  FUN_00012356();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x622;
  FUN_0000ac1c();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x628;
  FUN_00012376();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x62e;
  FUN_0002b46a();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x634;
  FUN_0000a5c0();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x63a;
  dmaDescriptorSetup2();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x640;
  FUN_0000bf9c();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x646;
  FUN_0002b4fe();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x64c;
  dmaControllerSetup1();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x652;
  FUN_00014664();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x658;
  FUN_000148f8();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x65e;
  FUN_000188f6();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x664;
  FUN_00018b6e();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x66a;
  FUN_000137ac();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x670;
  FUN_0000e02c();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x676;
  FUN_00013890();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x67c;
  FUN_000138fe();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x682;
  FUN_00014536();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x688;
  scheduler_init();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x68e;
  FUN_00028546();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x694;
  FUN_0002c240();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x69a;
  FUN_0000eacc();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6a0;
  FUN_0000c33e();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6a6;
  FUN_0000ebd2();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6ac;
  FUN_000103a2();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6b2;
  FUN_0001078e();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6b8;
  FUN_00011c0c();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6be;
  FUN_000140ce();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6c4;
  FUN_00016af2();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6ca;
  FUN_0001832a();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6d0;
  FUN_0001842a();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6d6;
  FUN_00018f6c();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6dc;
  FUN_00018e9c();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6e2;
  FUN_0001d7ec();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6e8;
  FUN_0001d7dc();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6ee;
  FUN_0001e3a8();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6f4;
  FUN_0001ee02();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x6fa;
  FUN_0001f23e();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x700;
  FUN_0001f7cc();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x706;
  FUN_00033254();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x70c;
  FUN_0002621c();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x712;
  FUN_000281e8();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x718;
  FUN_00028bda();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x71e;
  FUN_00010f76();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x724;
  FUN_00018eb4();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x72a;
  FUN_000265a4();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x730;
  FUN_0001e8a6();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x736;
  FUN_0002f8b8();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x73c;
  FUN_00019076();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x742;
  FUN_0001aef4();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x748;
  FUN_0000c272();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x74e;
  FUN_0001958c();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x754;
  FUN_000283c0();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x75a;
  FUN_000284aa();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x760;
  FUN_0001f860();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x766;
  FUN_000192c4();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x76c;
  FUN_0001920a();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x772;
  FUN_000207b6();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x778;
  FUN_000256a4();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x77e;
  FUN_0001b07c();
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x786;
  FUN_0002622e();
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x78c;
  FUN_0002fe20();
  _DAT_0080c812 = 0;
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x7a4;
  FUN_00017c6e();
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x7ae;
  FUN_0000c264();
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x7b4;
  FUN_00020f14();
  return;
}



//
// Function: FUN_00020780 @ 0x00020780
//

/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00020780(void)

{
  FUN_0002622e();
  FUN_0002fe20();
  _DAT_0080c812 = 0;
  _DAT_0080fffc = 0x207a4;
  FUN_00017c6e();
  _DAT_0080fffc = 0x207ae;
  FUN_0000c264();
  _DAT_0080fffc = 0x207b4;
  FUN_00020f14();
  return;
}



//
// Function: FUN_000207b6 @ 0x000207b6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000207b6(void)

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
  FUN_0000c144();
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
  _DAT_0080cf84 = &average_pulse_period_time_period_over_1_cyl_of_primary_s_1000_65535;
  _DAT_0080cf80 = &average_pulse_period_time_period_over_1_cyl_of_primary_s_1000_65535;
  FUN_0001cb6e();
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
  systemFunction5xCaller();
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
  bVar5 = j1939_source_address_primary << 3;
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
  bVar5 = j1939_source_address_secondary << 3;
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
  systemFunction5xCaller();
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
  bVar5 = j1939_source_address_primary << 3;
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
  bVar5 = j1939_source_address_secondary << 3;
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
// Function: FUN_00020de4 @ 0x00020de4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00020de4(void)

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
  
  REG_SIM_SWSR = 0xaa;
  DAT_00ffd00f = 0xaa;
  cVar3 = '\x01';
  cVar4 = '\0';
  cVar5 = '\0';
  bVar6 = 0;
  FUN_00012356();
  uVar7 = (ushort)(byte)(in_XF << 4 | cVar3 << 3 | cVar4 << 2 | cVar5 << 1 | bVar6);
  local_6 = _DAT_0080368e + 1;
  FUN_00013144(0x80368e,(undefined1 *)&local_6,CONCAT22(2,uVar7));
  uVar2 = 0;
  while ((uVar2 < 1000 && (_DAT_0080368e != local_6))) {
    FUN_00013240();
    FUN_0002baf0(CONCAT22(500,uVar7));
    uVar2 = uVar2 + 1;
  }
  local_6 = _DAT_0080368c + _DAT_0080368e;
  FUN_00013144(0x803686,(undefined1 *)&local_6,CONCAT22(2,uVar7));
  uVar2 = 0;
  while ((uVar2 < 1000 && (_DAT_00803686 != local_6))) {
    FUN_00013240();
    sVar1 = 0;
    do {
      uVar7 = 0;
      do {
        REG_SIM_SWSR = 0xaa;
        DAT_00ffd00f = 0xaa;
        uVar7 = uVar7 + 1;
      } while (uVar7 < 0xa0);
      sVar1 = sVar1 + 1;
    } while (sVar1 == 0);
    uVar2 = uVar2 + 1;
  }
  REG_SIM_SWSR = 0xaa;
  DAT_00ffd00f = 0xaa;
  FUN_00020780();
  return;
}



//
// Function: FUN_00020f14 @ 0x00020f14
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00020f14(void)

{
  uint uVar1;
  undefined4 unaff_D2;
  short sVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  byte bVar6;
  uint unaff_D7;
  undefined2 *puVar7;
  undefined2 *puVar8;
  char in_XF;
  char cVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  byte bVar13;
  ushort uVar14;
  undefined2 uVar15;
  dword local_a;
  ushort local_6;
  
  uVar15 = (undefined2)((uint)unaff_D2 >> 0x10);
  FUN_00028b78();
  REG_SIM_SWSR = 0xaa;
  DAT_00ffd00f = 0xaa;
  amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535 = 1;
  uVar14 = (ushort)(byte)(in_XF << 4);
  uVar5 = 0;
  while ((uVar5 < 1000 && (uVar1 = FUN_00013134(), (char)uVar1 == '\0'))) {
    FUN_00013240();
    FUN_0002baf0(CONCAT22(500,uVar14));
    uVar5 = uVar5 + 1;
  }
  sim_data_direction_control = sim_data_direction_control | 4;
  ioControlAndCanPinSwitching();
  if (points_to_engine_sync_fuel_pressure_fuel_minimun_threshold_0_2_32._0_2_ != 0) {
    puVar7 = (undefined2 *)&DAT_008062cc;
    if (points_to_engine_sync_fuel_pressure_fuel_minimun_threshold_0_2_32._2_2_ == 2) {
      puVar8 = (undefined2 *)&DAT_00007e3e;
    }
    else {
      puVar8 = (undefined2 *)&DAT_00005e3e;
    }
    for (; puVar7 < (undefined2 *)0x8062ce; puVar7 = puVar7 + 1) {
      *puVar7 = *puVar8;
      puVar8 = puVar8 + 1;
    }
  }
  sVar2 = points_to_engine_sync_fuel_pressure_fuel_minimun_threshold_0_2_32._2_2_;
  REG_SIM_SWSR = 0xaa;
  DAT_00ffd00f = 0xaa;
  bVar13 = 1;
  do {
    if (((sVar2 == 2) && (bVar13 == 1)) || ((sVar2 == 1 && (bVar13 == 2)))) {
      REG_SIM_SWSR = 0xaa;
      DAT_00ffd00f = 0xaa;
      uVar1 = FUN_0000ed52();
      unaff_D7 = uVar1 & 0xffff;
      REG_SIM_SWSR = 0xaa;
      DAT_00ffd00f = 0xaa;
    }
    else if (((sVar2 == 1) && (bVar13 == 1)) || ((sVar2 == 2 && (bVar13 == 2)))) {
      REG_SIM_SWSR = 0xaa;
      DAT_00ffd00f = 0xaa;
      uVar1 = FUN_0000ef80();
      unaff_D7 = uVar1 & 0xffff;
      REG_SIM_SWSR = 0xaa;
      DAT_00ffd00f = 0xaa;
    }
    if ((short)unaff_D7 == 1) {
      FUN_00020de4();
    }
    if (_DAT_00803686 != _DAT_00803688) {
      FUN_00013144(0x803688,&DAT_00803686,
                   CONCAT22(2,(ushort)(byte)((_DAT_00803686 < _DAT_00803688) << 4 |
                                             ((short)(_DAT_00803686 - _DAT_00803688) < 0) << 3 |
                                             SBORROW2(_DAT_00803686,_DAT_00803688) << 1 |
                                            _DAT_00803686 < _DAT_00803688)));
      uVar5 = 0;
      while( true ) {
        REG_SIM_SWSR = 0xaa;
        DAT_00ffd00f = 0xaa;
        if ((999 < uVar5) || (_DAT_00803686 == _DAT_00803688)) break;
        FUN_00013240();
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
      REG_SIM_SWSR = 0xaa;
      DAT_00ffd00f = 0xaa;
      vp44_status_data_collector();
      FUN_0002baf0(CONCAT22(10000,uVar15));
      bVar6 = bVar6 + 1;
    }
    if ((vp44_communication_status & 1) != 0) {
      FUN_00020de4();
    }
    bVar6 = bVar13 + 1;
    cVar12 = bVar13 - 1;
    bVar13 = bVar6;
  } while (bVar6 < 3);
  uVar14 = (ushort)(byte)((bVar6 < 2) << 4 | (cVar12 < '\0') << 3 | (bVar6 == 2) << 2 |
                          SBORROW1(bVar6,'\x02') << 1 | bVar6 < 2);
  local_a = loopCounter;
  FUN_00013144(0x80352c,(undefined1 *)&local_a,CONCAT22(4,uVar14));
  uVar5 = 0;
  while( true ) {
    REG_SIM_SWSR = 0xaa;
    DAT_00ffd00f = 0xaa;
    if ((999 < uVar5) || (_DAT_0080352c == local_a)) break;
    FUN_00013240();
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
  FUN_00013144(0x80367e,(undefined1 *)&local_6,
               CONCAT22(2,(ushort)(byte)(((uVar14 & 0x10) != 0) << 4 | ((uVar14 & 8) != 0) << 3 |
                                         ((uVar14 & 4) != 0) << 2 | ((uVar14 & 2) != 0) << 1 |
                                        (uVar14 & 1) != 0)));
  uVar5 = 0;
  while ((uVar5 < 1000 && (_DAT_0080367e != local_6))) {
    FUN_00013240();
    sVar2 = 0;
    do {
      uVar14 = 0;
      do {
        REG_SIM_SWSR = 0xaa;
        DAT_00ffd00f = 0xaa;
        uVar14 = uVar14 + 1;
      } while (uVar14 < 0xa0);
      sVar2 = sVar2 + 1;
    } while (sVar2 == 0);
    uVar5 = uVar5 + 1;
  }
  FUN_000253a6();
  sim_data_direction_control = sim_data_direction_control & 0xf3;
  REG_SIM_SWSR = 0xaa;
  DAT_00ffd00f = 0xaa;
  ioControlAndCanPinSwitching();
  local_6 = 0;
  sVar2 = hardware_timer_register._0_2_;
  do {
    while ((ushort)(hardware_timer_register._0_2_ - sVar2) < 500) {
      REG_SIM_SWSR = 0xaa;
      DAT_00ffd00f = 0xaa;
      vp44_status_data_collector();
      if ((vp44_communication_status & 1) != 0) {
        sim_data_direction_control = sim_data_direction_control & 0xfb | 8;
        REG_SIM_SWSR = 0xaa;
        DAT_00ffd00f = 0xaa;
        ioControlAndCanPinSwitching();
        FUN_00020de4();
      }
    }
    local_6 = local_6 + 1;
    sVar2 = hardware_timer_register._0_2_;
  } while (local_6 < 0x28);
  sim_data_direction_control = sim_data_direction_control & 0xfb | 8;
  REG_SIM_SWSR = 0xaa;
  DAT_00ffd00f = 0xaa;
  ioControlAndCanPinSwitching();
  REG_SIM_SWSR = 0xaa;
  DAT_00ffd00f = 0xaa;
  bVar13 = 0;
  while( true ) {
    cVar12 = bVar13 < 4;
    cVar11 = SBORROW1(bVar13,'\x04');
    cVar9 = (char)(bVar13 - 4) < '\0';
    if (!(bool)cVar12) break;
    REG_SIM_SWSR = 0xaa;
    DAT_00ffd00f = 0xaa;
    vp44_status_data_collector();
    FUN_0002baf0(CONCAT22(10000,uVar15));
    bVar13 = bVar13 + 1;
  }
  cVar10 = (vp44_communication_status & 1) == 0;
  bVar13 = cVar12;
  if (!(bool)cVar10) {
    FUN_00020de4();
  }
  local_6 = 1;
  FUN_00013144(0x80367e,(undefined1 *)&local_6,
               CONCAT22(2,(ushort)(byte)(cVar12 << 4 | cVar9 << 3 | cVar10 << 2 | cVar11 << 1 |
                                        bVar13)));
  uVar5 = 0;
  while ((uVar5 < 1000 && (_DAT_0080367e != local_6))) {
    FUN_00013240();
    sVar2 = 0;
    do {
      uVar14 = 0;
      do {
        REG_SIM_SWSR = 0xaa;
        DAT_00ffd00f = 0xaa;
        uVar14 = uVar14 + 1;
      } while (uVar14 < 0xa0);
      sVar2 = sVar2 + 1;
    } while (sVar2 == 0);
    uVar5 = uVar5 + 1;
  }
  while ((vp44_communication_status & 1) == 0) {
    vp44_status_data_collector();
  }
  FUN_00020de4();
  return;
}



//
// Function: FUN_00024d06 @ 0x00024d06
//

short FUN_00024d06(int param_1)

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
      REG_SIM_SWSR = 0xaa;
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
// Function: FUN_00024e58 @ 0x00024e58
//

void FUN_00024e58(int param_1,undefined4 param_2)

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
    REG_SIM_SWSR = 0xaa;
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
// Function: FUN_00024efc @ 0x00024efc
//

void FUN_00024efc(void)

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
  sVar1 = FUN_00024d06((int)local_c0a);
  FUN_00024e58((int)local_c0a,CONCAT22(sVar1,uVar3));
  return;
}



//
// Function: FUN_00024f36 @ 0x00024f36
//

void FUN_00024f36(undefined4 param_1)

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
// Function: FUN_00024f50 @ 0x00024f50
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte FUN_00024f50(void)

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
  FUN_00024f36(CONCAT22(1,(short)((uint)unaff_D2 >> 0x10)));
  uVar1 = _DAT_00fff206 & 1;
  _DAT_00fff208 = _DAT_00fff208 | 0x700;
  _DAT_00fff206 = 0x400;
  uVar4 = 1;
  FUN_00024f36(CONCAT22(1,uVar5));
  uVar2 = _DAT_00fff206 & 1;
  _DAT_00fff208 = _DAT_00fff208 | 0x700;
  _DAT_00fff206 = 0x300;
  uVar5 = 1;
  FUN_00024f36(CONCAT22(1,uVar4));
  uVar3 = _DAT_00fff206 & 2;
  _DAT_00fff208 = _DAT_00fff208 | 0x700;
  _DAT_00fff206 = 0x200;
  FUN_00024f36(CONCAT22(1,uVar5));
  return -((_DAT_00fff206 & 1) != 0) & 1U &
         -(uVar3 != 0) & 1U & -(uVar2 != 0) & 1U & -(uVar1 != 0) & 1U;
}



//
// Function: FUN_00025020 @ 0x00025020
//

void FUN_00025020(void)

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
    FUN_00024f36(CONCAT22(2,uVar2));
  }
  return;
}



//
// Function: FUN_0002504e @ 0x0002504e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte FUN_0002504e(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 unaff_D2;
  undefined2 uVar3;
  undefined2 uVar4;
  
  _DAT_00fff208 = _DAT_00fff208 | 0x700;
  _DAT_00fff206 = 0x200;
  uVar4 = 1;
  FUN_00024f36(CONCAT22(1,(short)((uint)unaff_D2 >> 0x10)));
  uVar1 = _DAT_00fff206 & 1;
  _DAT_00fff208 = _DAT_00fff208 | 0x700;
  _DAT_00fff206 = 0x300;
  uVar3 = 1;
  FUN_00024f36(CONCAT22(1,uVar4));
  uVar2 = _DAT_00fff206 & 2;
  _DAT_00fff208 = _DAT_00fff208 | 0x700;
  _DAT_00fff206 = 0x600;
  FUN_00024f36(CONCAT22(1,uVar3));
  DAT_00807c86 = -((DAT_00ffd001 & 1) != 0) & 1U &
                 -((_DAT_00fff206 & 1) != 0) & 1U & -(uVar2 == 0) & 1U & -(uVar1 != 0) & 1U;
  return DAT_00807c86;
}



//
// Function: FUN_00025108 @ 0x00025108
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00025108(void)

{
  byte bVar1;
  
  tpu_hssr0 = 0x8004;
  tpu_hsqr1._0_1_ = 0x7b;
  tpu_hsqr1._1_1_ = 0xfe;
  tpu_hsqr0._1_1_ = 0xff;
  tpu_hssr1 = tpu_hssr1 & 0x8000 | 0x1028;
  tpu_cpr0 = tpu_cpr0 & 0xf0ff | 0xf00;
  _DAT_00fffd20 = 3;
  DAT_00fffd40 = 0xbd;
  _DAT_00fffd22 = 0;
  DAT_00fffd41 = 0xfd;
  for (bVar1 = 2; bVar1 < 0x10; bVar1 = bVar1 + 1) {
    *(undefined2 *)(&DAT_00fffd20 + (uint)bVar1 * 2) = 0;
    (&DAT_00fffd40)[bVar1] = 0xbd;
  }
  tpu_hssr1 = tpu_hssr1 | 0x8000;
  do {
    do {
    } while (((byte)tpu_cpr1 & 0x80) == 0);
  } while (((byte)tpu_cpr1 & 0xf) != 0xf);
  if (((uint)qadc_qadcivr | (uint)qadc_qadcilr << 8) != 0x600d) {
    return 1;
  }
  return 0x6000;
}



//
// Function: FUN_000251f4 @ 0x000251f4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000251f4(void)

{
  byte bVar2;
  undefined4 uVar1;
  code *pcVar3;
  
  DAT_00ffd008 = 0x40;
  DAT_00ffd00e = 0x80;
  FUN_00025020();
  sim_ddrd._1_1_ = (byte)sim_ddrd | 8;
  sim_ddir._1_1_ = (byte)sim_ddir | 8;
  tpu_cpr1._1_1_ = (byte)tpu_cpr1 & 0x7f;
  tpu_hssr1 = tpu_hssr1 & 0x7fff;
  tpu_cpr0 = tpu_cpr0 & 0x7ff0;
  tpu_cier = 0;
  REG_SIM_PICR = 0;
  REG_SIM_PITR = 0;
  can1_cantbsel = 0;
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
  _DAT_00fff458 = 4;
  _DAT_00fff460 = 0x104;
  tpu_tpumcr = 5;
  tpu_dscr._0_1_ = 0x13;
  tpu_dscr._1_1_ = 0x50;
  FUN_00025356();
  bVar2 = FUN_00024f50();
  if (bVar2 == 0) {
    bVar2 = FUN_0002504e();
    if (bVar2 == 0) {
      uVar1 = FUN_00025108();
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
  FUN_00024efc();
  pcVar3 = (code *)&SUB_00824b32;
LAB_00025350:
  (*pcVar3)();
  return;
}



//
// Function: FUN_00025356 @ 0x00025356
//

void FUN_00025356(void)

{
  dword *pdVar1;
  dword *pdVar2;
  
  pdVar2 = (dword *)&DAT_00800000;
  while (pdVar2 < &engine_speed_constant_1_backup_conversion_factor_from_tcnts_0_2_29) {
    pdVar1 = pdVar2 + 0x40;
    if (&engine_speed_constant_1_backup_conversion_factor_from_tcnts_0_2_29 < pdVar1) {
      pdVar1 = &engine_speed_constant_1_backup_conversion_factor_from_tcnts_0_2_29;
    }
    for (; pdVar2 < pdVar1; pdVar2 = pdVar2 + 1) {
      *pdVar2 = 0;
    }
    REG_SIM_SWSR = 0xaa;
    DAT_00ffd00f = 0xaa;
  }
  return;
}



//
// Function: FUN_000253a6 @ 0x000253a6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000253a6(void)

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
    sim_data_direction_control = sim_data_direction_control | 2;
    ioControlAndCanPinSwitching();
    iVar1 = FUN_0001802e(0);
    if (iVar1 == 0) {
      pcVar4 = (code *)0x0;
      pcVar3 = (code *)&DAT_000214ea;
      while (pcVar3 < FUN_000253a6) {
        pcVar2 = (code *)auStack_104;
        for (; (pcVar2 < &stack0xfffffffc && (pcVar3 < FUN_000253a6)); pcVar3 = pcVar3 + 1) {
          *pcVar2 = *pcVar3;
          pcVar2 = pcVar2 + 1;
        }
        FUN_00018174((int)pcVar4,auStack_104,CONCAT22((short)pcVar2 - (short)auStack_104,uVar5));
        pcVar4 = pcVar2 + ((int)pcVar4 - (int)auStack_104);
      }
    }
    sim_data_direction_control = sim_data_direction_control & 0xfd;
    ioControlAndCanPinSwitching();
  }
  return;
}



//
// Function: FUN_0002544a @ 0x0002544a
//

void FUN_0002544a(undefined1 *param_1,undefined4 param_2)

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
// Function: FUN_00025476 @ 0x00025476
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00025476(undefined4 param_1)

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
     (((uint)bVar5 + (uint)_memory_patch_count < 0xb &&
      (in_D0 = (int)&timer_used_to_disable_rsg_when_gear_ratio_changes_0_100 - (int)_DAT_0080d3e2,
      (int)(uint)bVar3 <= (int)in_D0)))) {
    pbVar8 = &CMSYRSFG;
    for (bVar5 = 0; bVar5 < bVar7; bVar5 = bVar5 + 1) {
      local_8 = *(undefined1 **)(pbVar8 + 4);
      uVar4 = (ushort)pbVar8[8];
      if ((pbVar8[9] == 5) || (pbVar8[9] == 3)) {
        *(undefined1 **)
         (&timer_used_to_disable_rsg_when_gear_ratio_changes_0_100 +
         (short)(_memory_patch_count * 3)) = *(undefined1 **)pbVar8;
        sVar1 = _memory_patch_count * 3;
        _memory_patch_count = _memory_patch_count + 1;
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
  sim_mcr = 0x604f;
  sim_avr = 0x7f08;
  sim_ddir._1_1_ = 0xa9;
  sim_ddrd._1_1_ = 0xfe;
  sim_dpard._1_1_ = 1;
  sim_picr._1_1_ = 0xff;
  sim_swsr2._1_1_ = 0xc9;
  uRam00fffa1f = 0x30;
  sim_csbar0._1_1_ = 0x9e;
  sim_csbar9 = 0x2bbf;
  sim_csor9 = 0;
  sim_csbar10 = 5;
  sim_csor10 = 0x6830;
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
// Function: FUN_000256a4 @ 0x000256a4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

word FUN_000256a4(void)

{
  byte bVar1;
  
  _DAT_0080d452 = &tracks_progress_of_fan_on_due_to_ac_0_3600;
  _DAT_0080d45a = 200;
  _DAT_0080d44a = &timer_used_to_disable_rsg_when_gear_ratio_changes_0_100;
  _memory_patch_count = 0;
  _DAT_0080d3e2 = &tracks_progress_of_fan_on_due_to_ac_0_3600;
  FUN_00018ee4();
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
  tpu_ticr = 0x34;
  tpu_cier = 0x102c;
  return tpu_cfsr0;
}



//
// Function: FUN_00025768 @ 0x00025768
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00025768(void)

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
    if (_DAT_0080d400 < 0x10) {
      bVar6 = DAT_0080d401 + 4;
      DAT_0080d404 = '\0';
      bVar5 = DAT_0080d401;
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
      *local_8 = DAT_0080d3f9;
      local_8 = (byte *)CONCAT31(local_8._0_3_,cVar2 + '\x04');
      *local_8 = DAT_0080d3f8;
      local_8 = (byte *)CONCAT31(local_8._0_3_,cVar2 + '\x05');
      for (bVar4 = 0; bVar4 < bVar5; bVar4 = bVar4 + 1) {
        bVar1 = *_DAT_0080d3fa;
        _DAT_0080d3fa = _DAT_0080d3fa + 1;
        *local_8 = bVar1;
        local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
      }
      _DAT_0080d400 = _DAT_0080d400 - bVar5;
      *_DAT_0080d2b4 = bVar6;
      *local_8 = 0;
      _DAT_0080d2b4 = local_8;
      FUN_00013242();
    }
    else {
      DAT_0080d404 = '\0';
      FUN_0000a626(CONCAT22(4,(short)((uint)unaff_D2 >> 0x10)));
      _DAT_00805e00 = _DAT_00805e00 | 4;
      _DAT_00805e40 = _DAT_00805e40 | 4;
    }
  }
  return;
}



//
// Function: FUN_0002588c @ 0x0002588c
//

void FUN_0002588c(void)

{
  if (DAT_0080d405 != '\0') {
    FUN_0000e1ce();
  }
  DAT_0080d404 = 0;
  DAT_0080d405 = 0;
  return;
}



//
// Function: FUN_000258aa @ 0x000258aa
//

void FUN_000258aa(void)

{
  if (DAT_0080d405 != '\0') {
    FUN_0000e1ce();
  }
  DAT_0080d404 = 0;
  DAT_0080d405 = 0;
  return;
}



//
// Function: FUN_000258c8 @ 0x000258c8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000258c8(void)

{
  _DAT_0080d3e2 = &tracks_progress_of_fan_on_due_to_ac_0_3600;
  _DAT_0080d458 = 0;
  _memory_patch_count = 0;
  return;
}



//
// Function: memoryPatchingSystem @ 0x000258e0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint memoryPatchingSystem(void)

{
  byte *pbVar1;
  byte bVar2;
  byte *pbVar3;
  byte bVar4;
  char cVar5;
  uint in_D0;
  undefined4 uVar6;
  char cVar8;
  uint uVar7;
  byte bVar9;
  byte bVar10;
  word *pwVar11;
  uint *puVar12;
  word *pwVar14;
  uint *puVar13;
  
  if (_memory_patch_count == 0) {
    return in_D0 & 0xffffff00;
  }
  if ((points_to_water_in_fuel_fuel_maximum_threshold_0_2_32._2_2_ == 1) &&
     (amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535 != 0)) {
    puVar13 = (uint *)((int)&timer_used_to_disable_rsg_when_gear_ratio_changes_0_100 +
                      (int)(short)((_memory_patch_count & 0xff) * 6));
    cVar8 = DAT_0080d44f;
    while( true ) {
      puVar12 = (uint *)((int)puVar13 + -6);
      cVar5 = cVar8 + -1;
      if (cVar8 == '\0') break;
      pbVar1 = (byte *)*puVar12;
      pbVar3 = (byte *)((int)puVar13 + -1);
      if ((((byte *)0xffffff < pbVar1) ||
          ((&system_protected_range_start < pbVar1 && (pbVar1 < &system_protected_range_end)))) ||
         ((puVar13 = puVar12, cVar8 = cVar5, &system_protected_range_start < pbVar1 + *pbVar3 &&
          (pbVar1 + *pbVar3 < &system_protected_range_end)))) {
        FUN_000258c8();
        return 7;
      }
    }
  }
  if ((_DAT_0080d3f4 == 0) &&
     ((_DAT_0080d458 == 0 || (uVar6 = FUN_0000fd02(), (short)uVar6 != _DAT_0080d456)))) {
    FUN_000258c8();
    return 0x14;
  }
  if (10 < _memory_patch_count) {
    FUN_000258c8();
    return 4;
  }
  _DAT_0080d3e2 = &tracks_progress_of_fan_on_due_to_ac_0_3600;
  bVar10 = 0;
  pwVar14 = &timer_used_to_disable_rsg_when_gear_ratio_changes_0_100;
  do {
    if (_memory_patch_count <= bVar10) {
      uVar7 = FUN_000258c8();
      return uVar7 & 0xffffff00;
    }
    pwVar11 = *(word **)pwVar14;
    bVar4 = *(byte *)((int)pwVar14 + 5);
    if (pwVar11 < &indicator_as_to_the_calibration_status_of_the_ecm_see_ces15005) {
      for (bVar9 = 0; bVar9 < bVar4; bVar9 = bVar9 + 1) {
        if (((&system_protected_range_start < pwVar11) && (pwVar11 < &system_protected_range_end))
           && (_DAT_0080d3f4 == 0)) {
          points_to_engine_sync_fuel_pressure_fuel_minimun_threshold_0_2_32._0_2_ = 0;
        }
        bVar2 = *(byte *)_DAT_0080d3e2;
        _DAT_0080d3e2 = (word *)((int)_DAT_0080d3e2 + 1);
        *(byte *)pwVar11 = bVar2;
        pwVar11 = (word *)((int)pwVar11 + 1);
      }
    }
    else {
      if ((amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535 == 1) &&
         (cVar8 = circularBufferWrite((short)((uint)_DAT_0080d3e2 >> 0x10),bVar4), cVar8 == '\x01'))
      {
        FUN_000258c8();
        return 4;
      }
      pwVar11 = pwVar11 + -0x3fe584;
      for (bVar9 = 0; bVar9 < bVar4; bVar9 = bVar9 + 1) {
        bVar2 = *(byte *)_DAT_0080d3e2;
        _DAT_0080d3e2 = (word *)((int)_DAT_0080d3e2 + 1);
        *(byte *)pwVar11 = bVar2;
        pwVar11 = (word *)((int)pwVar11 + 1);
      }
    }
    pwVar14 = (word *)((int)pwVar14 + 6);
    bVar10 = bVar10 + 1;
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
  short sVar3;
  int iVar4;
  int iVar5;
  word wVar6;
  uint uVar7;
  ushort uVar8;
  ushort local_10;
  ushort local_c;
  ushort uStack_6;
  
  if (pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._2_2_ == 1) {
    if (_oil_pressure_protection_state != 1) {
      FUN_00025ece();
    }
    wVar6 = pointer_to_oil_pressure_fuel_min_threshold_0_2_32._2_2_;
    sVar3 = _oil_pressure_calculated_value;
    if (_oil_pressure_previous_threshold != pointer_to_oil_pressure_fuel_max_threshold_0_2_32._0_2_)
    {
      uStack_6 = (ushort)((uint)_oil_pressure_cal_factor_1 *
                          (uint)pointer_to_oil_pressure_fuel_max_threshold_0_2_32._0_2_ >> 10);
      uVar7 = (uint)_oil_pressure_cal_factor_2 * (uint)(ushort)(uStack_6 + 0x200);
      if (uVar7 < 0xf99999) {
        if (uVar7 < 0x41894) {
          _oil_pressure_calculated_limit = 0x20c;
        }
        else {
          uStack_6 = (ushort)(uVar7 >> 9);
          _oil_pressure_calculated_limit = uStack_6;
        }
      }
      else {
        _oil_pressure_calculated_limit = 0x7ccc;
      }
    }
    _oil_pressure_previous_threshold = pointer_to_oil_pressure_fuel_max_threshold_0_2_32._0_2_;
    _oil_pressure_calculated_value = FUN_00035608();
    if (_oil_pressure_max_threshold < _oil_pressure_calculated_value) {
      _oil_pressure_calculated_value = _oil_pressure_max_threshold;
    }
    if (_oil_pressure_calculated_value < _oil_pressure_min_threshold) {
      _oil_pressure_calculated_value = _oil_pressure_min_threshold;
    }
    uVar7 = (uint)_oil_pressure_protection_multiplier *
            ((uint)_oil_pressure_calculated_limit * (uint)_oil_pressure_cal_factor_3 >> 10 & 0xffff)
    ;
    if (uVar7 < 0x1000000) {
      uStack_6 = (ushort)(uVar7 >> 10);
      uVar8 = uStack_6;
    }
    else {
      uVar8 = 0x4000;
    }
    mask_for_input_of_the_oil_pressure_input_0_65535 =
         (word)(((int)_oil_pressure_calculated_value *
                (int)(short)_oil_pressure_protection_multiplier) / 0x3c0);
    if (0x1700 < (short)mask_for_input_of_the_oil_pressure_input_0_65535) {
      mask_for_input_of_the_oil_pressure_input_0_65535 = 0x1700;
    }
    if ((short)mask_for_input_of_the_oil_pressure_input_0_65535 < -0x1700) {
      mask_for_input_of_the_oil_pressure_input_0_65535 = 0xe900;
    }
    amount_of_time_since_oil_pressure_failure_was_detected_0_65535 =
         (word)(((int)_oil_pressure_timing_factor *
                ((int)_oil_pressure_calculated_value - (int)sVar3)) / 0xf0);
    if (0x1c4a < (short)amount_of_time_since_oil_pressure_failure_was_detected_0_65535) {
      amount_of_time_since_oil_pressure_failure_was_detected_0_65535 = 0x1c4a;
    }
    if ((short)amount_of_time_since_oil_pressure_failure_was_detected_0_65535 < -0x1c4a) {
      amount_of_time_since_oil_pressure_failure_was_detected_0_65535 = 0xe3b6;
    }
    pointer_to_oil_pressure_fuel_min_threshold_0_2_32._2_2_ =
         amount_of_time_since_oil_pressure_failure_was_detected_0_65535 +
         mask_for_input_of_the_oil_pressure_input_0_65535;
    if (0x1700 < (short)pointer_to_oil_pressure_fuel_min_threshold_0_2_32._2_2_) {
      pointer_to_oil_pressure_fuel_min_threshold_0_2_32._2_2_ = 0x1700;
    }
    if ((short)pointer_to_oil_pressure_fuel_min_threshold_0_2_32._2_2_ < -0x1700) {
      pointer_to_oil_pressure_fuel_min_threshold_0_2_32._2_2_ = 0xe900;
    }
    if (fsmxthfl_calc_input < _oil_pressure_rpm_limit_reference) {
      uStack_6 = (ushort)((uint)uVar8 *
                          ((uint)_oil_pressure_rpm_limit_reference - (uint)fsmxthfl_calc_input) >>
                         0xe);
      pointer_to_oil_pressure_fuel_min_threshold_0_2_32._0_2_ = uStack_6;
    }
    else {
      pointer_to_oil_pressure_fuel_min_threshold_0_2_32._0_2_ = 0;
    }
    uStack_6 = (ushort)((uint)uVar8 * (0x7fff - (uint)_DAT_00808920) >> 0xe);
    uVar1 = uStack_6 + _DAT_00808920;
    iVar4 = (uint)_DAT_0080891c * (uint)uVar1 * 2;
    iVar5 = (uint)_DAT_0080891e * (uint)uVar1 * 2;
    if (_DAT_0080c9a6 != 4) {
      pointer_to_oil_pressure_fuel_min_threshold_0_2_32._2_2_ =
           mask_for_input_of_the_oil_pressure_input_0_65535;
      if (fsmxthfl_calc_input < _current_fuel_demand_value) {
        uStack_6 = (ushort)((uint)uVar8 *
                            ((uint)_current_fuel_demand_value - (uint)fsmxthfl_calc_input) >> 0xe);
        pointer_to_oil_pressure_fuel_min_threshold_0_2_32._0_2_ = uStack_6;
      }
      else {
        pointer_to_oil_pressure_fuel_min_threshold_0_2_32._0_2_ = 0;
      }
      iVar2 = (uint)_current_fuel_demand_value * (uint)uVar1 * 2;
      _DAT_008018a0 = (word)((uint)iVar2 >> 0x10);
      _DAT_008018a2 = (undefined2)iVar2;
      _DAT_008018a0 =
           CONCAT22((_fuel_delivery_offset_correction + _DAT_008018a0) -
                    pointer_to_oil_pressure_fuel_min_threshold_0_2_32._0_2_,_DAT_008018a2);
    }
    iVar2 = ((int)(short)wVar6 - (int)pointer_to_oil_pressure_fuel_min_threshold_0_2_32._0_2_) *
            (0x7fff - (short)_DAT_00808920) * 2 + _DAT_008018a0;
    _DAT_008018a0 = (word)((uint)iVar2 >> 0x10);
    sVar3 = _DAT_008018a0 - _fuel_delivery_offset_correction;
    _DAT_008018a2 = (undefined2)iVar2;
    _DAT_008018a0 = CONCAT22(sVar3,_DAT_008018a2);
    local_c = (ushort)((uint)iVar4 >> 0x10);
    if (sVar3 < (short)local_c) {
      local_10 = (ushort)((uint)iVar5 >> 0x10);
      if (sVar3 < (short)local_10) {
        _DAT_008018a0 = (uint)local_10 << 0x10;
      }
    }
    else {
      _DAT_008018a0 = (uint)local_c << 0x10;
    }
    time_duration_since_oil_pressure_fault_was_detected_0_65535 = _DAT_008018a0;
    uVar7 = ((int)(short)_DAT_008018a0 +
            (int)(short)pointer_to_oil_pressure_fuel_min_threshold_0_2_32._2_2_) * 0x8000;
    if (iVar5 >> 1 < (int)uVar7) {
      if ((int)uVar7 < iVar4 >> 1) {
        _oil_pressure_rpm_limit_reference = (ushort)(uVar7 / uVar1);
      }
      else {
        _oil_pressure_rpm_limit_reference = _DAT_0080891c;
      }
    }
    else {
      _oil_pressure_rpm_limit_reference = _DAT_0080891e;
    }
    if ((pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._2_2_ == 1) &&
       (pointer_to_oil_pressure_fuel_max_threshold_0_2_32._2_2_ < _DAT_0080d494)) {
      _DAT_0080d494 = pointer_to_oil_pressure_fuel_max_threshold_0_2_32._2_2_;
      _DAT_0080d496 = 0x22;
    }
  }
  else {
    _oil_pressure_rpm_limit_reference = 0;
  }
  _oil_pressure_protection_state = pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._2_2_;
  return;
}



//
// Function: FUN_00025ece @ 0x00025ece
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00025ece(void)

{
  int iVar1;
  uint uVar2;
  undefined2 uStack_6;
  
  pointer_to_oil_pressure_fuel_min_threshold_0_2_32._2_2_ = 0;
  FUN_000260ec();
  _DAT_0080189c = 0x80000000;
  _oil_pressure_calculated_value = 0;
  uVar2 = FUN_000357d2((uint)_oil_pressure_cal_factor_2,
                       ((uint)_oil_pressure_cal_factor_1 *
                        (uint)pointer_to_oil_pressure_fuel_max_threshold_0_2_32._0_2_ >> 10) + 0x200
                       ,1);
  if (uVar2 < 0xf99999) {
    uStack_6 = (ushort)(uVar2 >> 9);
    _oil_pressure_calculated_limit = uStack_6;
  }
  else {
    _oil_pressure_calculated_limit = 0x7ccc;
  }
  uVar2 = ((uint)_oil_pressure_calculated_limit * (uint)_oil_pressure_cal_factor_3 >> 10 & 0xffff) *
          (int)_oil_pressure_protection_multiplier;
  if (uVar2 < 0x1000000) {
    uStack_6 = (ushort)(uVar2 >> 10);
  }
  else {
    uStack_6 = 0x4000;
  }
  uStack_6 = (ushort)((uint)uStack_6 * (0x7fff - (uint)_DAT_00808920) >> 0xe);
  _DAT_008018a0 = (uint)_current_fuel_demand_value * (uint)(ushort)(uStack_6 + _DAT_00808920) * 2;
  iVar1 = _DAT_008018a0;
  _DAT_008018a0 = (word)((uint)_DAT_008018a0 >> 0x10);
  time_duration_since_oil_pressure_fault_was_detected_0_65535 = _DAT_008018a0;
  _oil_pressure_rpm_limit_reference = _current_fuel_demand_value;
  _DAT_008018a0 = iVar1;
  return;
}



//
// Function: FUN_00025fda @ 0x00025fda
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00025fda(void)

{
  undefined4 local_8;
  
  if (param_scale_factor < param_ref_base) {
    local_8 = 0;
  }
  else {
    local_8 = (uint)param_scale_factor - (uint)param_ref_base;
  }
  pointer_to_oil_pressure_fuel_max_threshold_0_2_32._2_2_ =
       param_ref_base +
       (short)(((uint)_DAT_0080380e * (local_8 & 0xffff)) /
              (uint)the_deceleration_value_where_e_braking_will_be_removed_1_0_01);
  _DAT_0080189c = 0x80000000;
  _DAT_00801898 = 0x808916;
  FUN_000260fe();
  return;
}



//
// Function: oil_pressure_protection_controller @ 0x0002604e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void oil_pressure_protection_controller(void)

{
  ushort uVar1;
  
  if (pointer_to_oil_pressure_fuel_max_threshold_0_2_32._0_2_ <
      pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._0_2_) {
    uVar1 = pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._0_2_ -
            pointer_to_oil_pressure_fuel_max_threshold_0_2_32._0_2_;
  }
  else {
    uVar1 = pointer_to_oil_pressure_fuel_max_threshold_0_2_32._0_2_ -
            pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._0_2_;
  }
  if (uVar1 <= _oil_pressure_rate_limit_step) {
    pointer_to_oil_pressure_fuel_max_threshold_0_2_32._0_2_ =
         pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._0_2_;
    return;
  }
  _oil_pressure_calculation_buffer =
       (uint)pointer_to_oil_pressure_fuel_max_threshold_0_2_32._0_2_ << 0x10;
  uVar1 = coreTableInterpolation();
  if (uVar1 <= pointer_to_oil_pressure_fuel_max_threshold_0_2_32._0_2_) {
    if ((int)(uint)_oil_pressure_rate_limit_step <
        (int)((uint)pointer_to_oil_pressure_fuel_max_threshold_0_2_32._0_2_ - (uint)uVar1)) {
      pointer_to_oil_pressure_fuel_max_threshold_0_2_32._0_2_ = uVar1;
      return;
    }
    pointer_to_oil_pressure_fuel_max_threshold_0_2_32._0_2_ =
         pointer_to_oil_pressure_fuel_max_threshold_0_2_32._0_2_ - _oil_pressure_rate_limit_step;
    return;
  }
  if ((int)(uint)_oil_pressure_rate_limit_step <=
      (int)((uint)uVar1 - (uint)pointer_to_oil_pressure_fuel_max_threshold_0_2_32._0_2_)) {
    pointer_to_oil_pressure_fuel_max_threshold_0_2_32._0_2_ = uVar1;
    return;
  }
  pointer_to_oil_pressure_fuel_max_threshold_0_2_32._0_2_ =
       _oil_pressure_rate_limit_step + pointer_to_oil_pressure_fuel_max_threshold_0_2_32._0_2_;
  return;
}



//
// Function: FUN_000260ec @ 0x000260ec
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000260ec(void)

{
  pointer_to_oil_pressure_fuel_max_threshold_0_2_32._0_2_ = current_engine_rpm;
  _oil_pressure_calculation_buffer = 0;
  return;
}



//
// Function: FUN_000260fe @ 0x000260fe
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000260fe(void)

{
  _oil_pressure_calculation_buffer = 0;
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
  
  if ((((diagnostic_status_register == 1) || (diagnostic_status_register == 2)) ||
      (diagnostic_status_register == 0x1e)) || (diagnostic_status_register == 3)) {
    delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535 = diagnostic_status_register;
    amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535 = cached_parameter_value;
    amount_of_time_over_oil_pressure_fuel_shutdown_threshold_0_65535 = 0;
    true_oil_pressure_precrank_error_1_true_0_false = _oil_pressure_precrank_status;
    return in_D0;
  }
  if (pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._2_2_ == 1) {
    in_D0 = _diagnostic_system_flags_1 & 0x10;
    if ((_diagnostic_system_flags_1 & 0x10) != 0) {
      if ((diagnostic_status_register == 7) || (diagnostic_status_register == 8)) {
        uVar1 = (uint)cached_parameter_value;
        if (_oil_pressure_rpm_limit_reference <= cached_parameter_value) {
          uVar1 = _diagnostic_system_flags_2 & 0x2000;
          if ((_diagnostic_system_flags_2 & 0x2000) != 0) {
            amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535 = cached_parameter_value
            ;
            delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535 =
                 diagnostic_status_register;
            true_oil_pressure_precrank_error_1_true_0_false = _oil_pressure_error_status;
            amount_of_time_over_oil_pressure_fuel_shutdown_threshold_0_65535 = 1;
            return uVar1;
          }
        }
        amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535 =
             _oil_pressure_rpm_limit_reference;
        delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535 = 4;
        amount_of_time_over_oil_pressure_fuel_shutdown_threshold_0_65535 = 0;
        true_oil_pressure_precrank_error_1_true_0_false = _oil_pressure_precrank_status;
        return uVar1;
      }
      if ((diagnostic_status_register != 6) && (diagnostic_status_register != 5)) {
        return in_D0;
      }
      amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535 =
           _oil_pressure_rpm_limit_reference;
      delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535 = 4;
      amount_of_time_over_oil_pressure_fuel_shutdown_threshold_0_65535 = 0;
      true_oil_pressure_precrank_error_1_true_0_false = _oil_pressure_precrank_status;
      return in_D0;
    }
  }
  delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535 = diagnostic_status_register;
  amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535 = cached_parameter_value;
  amount_of_time_over_oil_pressure_fuel_shutdown_threshold_0_65535 = 0;
  true_oil_pressure_precrank_error_1_true_0_false = _oil_pressure_precrank_status;
  return in_D0;
}



//
// Function: FUN_0002621c @ 0x0002621c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002621c(void)

{
  amount_of_time_over_oil_pressure_fuel_shutdown_threshold_0_65535 = 0;
  true_oil_pressure_precrank_error_1_true_0_false = _oil_pressure_precrank_status;
  return;
}



//
// Function: FUN_0002622e @ 0x0002622e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0002622e(void)

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
    _DAT_00fff42a = _DAT_00fff42a & 0xffff0000;
  }
  else {
    uVar1 = ((((uint)_DAT_00808934 *
              (uint)delay_before_warning_about_shutdown_from_oil_press_rpm_0_65535) / 0x6400 &
             0xffff) * 8000) / 1000 & 0xffff | ((uint)_DAT_00808934 * 8000) / 1000 << 0x10;
    _DAT_00fff42a = uVar1;
  }
  uVar1 = uVar1 & 0xffff0000;
  if ((_DAT_00805670 & 2) == 0) {
    _DAT_00fff432 = _DAT_00fff432 & 0xffff0000;
  }
  else {
    uVar1 = ((((uint)_DAT_00808936 * (uint)time_since_rpm_crossed_oil_pres_start_mon_rpm_0_65535) /
              0x6400 & 0xffff) * 8000) / 1000 & 0xffff | ((uint)_DAT_00808936 * 8000) / 1000 << 0x10
    ;
    _DAT_00fff432 = uVar1;
  }
  if (5 < amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535) {
    uVar1 = uVar1 & 0xffff0000;
    if ((_DAT_00805670 & 4) == 0) {
      _DAT_00fff43a = _DAT_00fff43a & 0xffff0000;
    }
    else {
      uVar1 = ((((uint)_DAT_00808938 * (uint)errors_allowed_timer_running_flag_for_oil_pres_0_1) /
                0x6400 & 0xffff) * 8000) / 1000 & 0xffff |
              ((uint)_DAT_00808938 * 8000) / 1000 << 0x10;
      _DAT_00fff43a = uVar1;
    }
  }
  if (5 < amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535) {
    uVar1 = uVar1 & 0xffff0000;
    if ((_DAT_00805670 & 8) == 0) {
      _DAT_00fff442 = _DAT_00fff442 & 0xffff0000;
    }
    else {
      uVar1 = ((((uint)_DAT_0080893a *
                (uint)pointer_to_oil_pressure_fuel_fault_log_data_0_2_32._0_2_) / 0x6400 & 0xffff) *
              8000) / 1000 & 0xffff | ((uint)_DAT_0080893a * 8000) / 1000 << 0x10;
      _DAT_00fff442 = uVar1;
    }
  }
  uVar1 = CONCAT22((short)(uVar1 >> 0x10),_DAT_00805670) & 0xffff0010;
  if (((_DAT_00805670 & 0x10) == 0) ||
     (pointer_to_oil_pressure_fuel_fault_log_data_0_2_32._2_2_ == 0)) {
    _DAT_00fff41a = 0x7fff;
  }
  else if (pointer_to_oil_pressure_fuel_fault_log_data_0_2_32._2_2_ < 0x6400) {
    _DAT_00fff414 = -(short)(((uint)_DAT_0080893c * 8000) / 1000) - 1;
    uVar1 = (_DAT_00fff414 & 0x7fff) +
            (((((uint)_DAT_0080893c * (uint)pointer_to_oil_pressure_fuel_fault_log_data_0_2_32._2_2_
               ) / 0x6400 & 0xffff) * 8000) / 1000 & 0xffff) | 0x7fff0000;
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
// Function: FUN_000265a4 @ 0x000265a4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000265a4(void)

{
  _DAT_00fff450 = 1;
  _DAT_00fff448 = 1;
  _DAT_00fff420 = 1;
  return;
}



//
// Function: FUN_000265be @ 0x000265be
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_000265be(void)

{
  uint in_D0;
  uint uVar1;
  
  if (amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535 < 6) {
    amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535 =
         amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535 + 1;
    in_D0 = FUN_00026aca();
  }
  if (_DAT_00808934 != 0) {
    if ((_DAT_00fff450 & 0x8000) == 0) {
      if ((delay_before_warning_about_shutdown_from_oil_press_rpm_0_65535 == 0) ||
         ((_DAT_00805670 & 1) == 0)) {
        if ((_DAT_00fff450 & 0x80) == 0) {
          in_D0 = _DAT_00805e00 & 0xffff0010;
          if (((_DAT_00805e00 & 0x10) != 0) &&
             (in_D0 = _DAT_00805e40 & 0xffff0010, (_DAT_00805e40 & 0x10) == 0)) {
            pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._0_2_ = 0;
            _DAT_00805e00 = _DAT_00805e00 & 0xffef;
          }
        }
        else {
          in_D0 = (uint)pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._0_2_;
          if (pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._0_2_ < _DAT_00808940) {
            pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._0_2_ =
                 pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._0_2_ + 1;
          }
          else {
            _DAT_00805e00 = _DAT_00805e00 | 0x10;
            _DAT_00805e40 = _DAT_00805e40 | 0x10;
          }
        }
      }
      else if (delay_before_warning_about_shutdown_from_oil_press_rpm_0_65535 < 0x6400) {
        in_D0 = _DAT_00fff428 & 0xffff8000;
        if ((((_DAT_00fff428 & 0x8000) != 0) &&
            (in_D0 = _DAT_00805e00 & 0xffff0010, (_DAT_00805e00 & 0x10) != 0)) &&
           (in_D0 = _DAT_00805e40 & 0xffff0010, (_DAT_00805e40 & 0x10) == 0)) {
          _DAT_00fff428 = _DAT_00fff428 & 0x7fff;
          pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._0_2_ = 0;
          _DAT_00805e00 = _DAT_00805e00 & 0xffef;
        }
      }
      else if ((_DAT_00fff450 & 0x80) == 0) {
        in_D0 = (uint)pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._0_2_;
        if (pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._0_2_ < _DAT_00808940) {
          pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._0_2_ =
               pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._0_2_ + 1;
        }
        else {
          _DAT_00805e00 = _DAT_00805e00 | 0x10;
          _DAT_00805e40 = _DAT_00805e40 | 0x10;
        }
      }
      else {
        in_D0 = _DAT_00805e00 & 0xffff0010;
        if (((_DAT_00805e00 & 0x10) != 0) &&
           (in_D0 = _DAT_00805e40 & 0xffff0010, (_DAT_00805e40 & 0x10) == 0)) {
          pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._0_2_ = 0;
          _DAT_00805e00 = _DAT_00805e00 & 0xffef;
        }
      }
    }
    else {
      in_D0 = _DAT_00805e00 & 0xffff0010;
      if (((_DAT_00805e00 & 0x10) != 0) &&
         (in_D0 = _DAT_00805e40 & 0xffff0010, (_DAT_00805e40 & 0x10) == 0)) {
        _DAT_00fff450 = _DAT_00fff450 & 0x7fff;
        _DAT_00805e00 = _DAT_00805e00 & 0xffef;
        pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._0_2_ = 0;
      }
    }
  }
  if (_DAT_00808936 != 0) {
    if ((_DAT_00fff448 & 0x8000) == 0) {
      if ((time_since_rpm_crossed_oil_pres_start_mon_rpm_0_65535 == 0) || ((_DAT_00805670 & 2) == 0)
         ) {
        if ((_DAT_00fff448 & 0x80) == 0) {
          in_D0 = _DAT_00805e00 & 0xffff0020;
          if ((_DAT_00805e00 & 0x20) != 0) {
            in_D0 = _DAT_00805e40 & 0xffff0020;
            if ((_DAT_00805e40 & 0x20) == 0) {
              _DAT_00805e00 = _DAT_00805e00 & 0xffdf;
              pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._2_2_ = 0;
            }
          }
        }
        else {
          in_D0 = (uint)pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._2_2_;
          if (pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._2_2_ < _DAT_00808942) {
            pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._2_2_ =
                 pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._2_2_ + 1;
          }
          else {
            _DAT_00805e00 = _DAT_00805e00 | 0x20;
            _DAT_00805e40 = _DAT_00805e40 | 0x20;
          }
        }
      }
      else if (time_since_rpm_crossed_oil_pres_start_mon_rpm_0_65535 < 0x6400) {
        in_D0 = _DAT_00fff430 & 0xffff8000;
        if ((((_DAT_00fff430 & 0x8000) != 0) &&
            (in_D0 = _DAT_00805e00 & 0xffff0020, (_DAT_00805e00 & 0x20) != 0)) &&
           (in_D0 = _DAT_00805e40 & 0xffff0020, (_DAT_00805e40 & 0x20) == 0)) {
          _DAT_00fff430 = _DAT_00fff430 & 0x7fff;
          _DAT_00805e00 = _DAT_00805e00 & 0xffdf;
          pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._2_2_ = 0;
        }
      }
      else if ((_DAT_00fff448 & 0x80) == 0) {
        in_D0 = (uint)pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._2_2_;
        if (_DAT_00808942 < pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._2_2_) {
          _DAT_00805e00 = _DAT_00805e00 | 0x20;
          _DAT_00805e40 = _DAT_00805e40 | 0x20;
        }
        else {
          pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._2_2_ =
               pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._2_2_ + 1;
        }
      }
      else {
        in_D0 = _DAT_00805e00 & 0xffff0020;
        if ((_DAT_00805e00 & 0x20) != 0) {
          in_D0 = _DAT_00805e40 & 0xffff0020;
          if ((_DAT_00805e40 & 0x20) == 0) {
            _DAT_00805e00 = _DAT_00805e00 & 0xffdf;
            pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._2_2_ = 0;
          }
        }
      }
    }
    else {
      in_D0 = _DAT_00805e00 & 0xffff0020;
      if (((_DAT_00805e00 & 0x20) != 0) &&
         (in_D0 = _DAT_00805e40 & 0xffff0020, (_DAT_00805e40 & 0x20) == 0)) {
        _DAT_00fff448 = _DAT_00fff448 & 0x7fff;
        _DAT_00805e00 = _DAT_00805e00 & 0xffdf;
        pointer_to_oil_pressure_rpm_fault_log_data_0_2_32._2_2_ = 0;
      }
    }
  }
  if (_DAT_0080893c != 0) {
    if ((_DAT_00fff420 & 0x8000) == 0) {
      if ((pointer_to_oil_pressure_fuel_fault_log_data_0_2_32._2_2_ == 0) ||
         ((_DAT_00805670 & 0x10) == 0)) {
        if ((_DAT_00fff420 & 0x80) != 0) {
          uVar1 = (uint)mask_for_input_of_water_in_fuel_0_65535;
          if (_DAT_00808948 <= mask_for_input_of_water_in_fuel_0_65535) {
            _DAT_00805e00 = _DAT_00805e00 | 0x100;
            _DAT_00805e40 = _DAT_00805e40 | 0x100;
            return uVar1;
          }
          mask_for_input_of_water_in_fuel_0_65535 = mask_for_input_of_water_in_fuel_0_65535 + 1;
          return uVar1;
        }
        in_D0 = _DAT_00805e00 & 0xffff0100;
        if (((_DAT_00805e00 & 0x100) != 0) &&
           (in_D0 = _DAT_00805e40 & 0xffff0100, (_DAT_00805e40 & 0x100) == 0)) {
          mask_for_input_of_water_in_fuel_0_65535 = 0;
          _DAT_00805e00 = _DAT_00805e00 & 0xfeff;
          return in_D0;
        }
      }
      else if (pointer_to_oil_pressure_fuel_fault_log_data_0_2_32._2_2_ < 0x6400) {
        in_D0 = _DAT_00fff418 & 0xffff8000;
        if ((((_DAT_00fff418 & 0x8000) != 0) &&
            (in_D0 = _DAT_00805e00 & 0xffff0100, (_DAT_00805e00 & 0x100) != 0)) &&
           (in_D0 = _DAT_00805e40 & 0xffff0100, (_DAT_00805e40 & 0x100) == 0)) {
          _DAT_00fff418 = _DAT_00fff418 & 0x7fff;
          _DAT_00805e00 = _DAT_00805e00 & 0xfeff;
          mask_for_input_of_water_in_fuel_0_65535 = 0;
          return in_D0;
        }
      }
      else {
        if ((_DAT_00fff420 & 0x80) == 0) {
          uVar1 = (uint)mask_for_input_of_water_in_fuel_0_65535;
          if (_DAT_00808948 <= mask_for_input_of_water_in_fuel_0_65535) {
            _DAT_00805e00 = _DAT_00805e00 | 0x100;
            _DAT_00805e40 = _DAT_00805e40 | 0x100;
            return uVar1;
          }
          mask_for_input_of_water_in_fuel_0_65535 = mask_for_input_of_water_in_fuel_0_65535 + 1;
          return uVar1;
        }
        in_D0 = _DAT_00805e00 & 0xffff0100;
        if ((_DAT_00805e00 & 0x100) != 0) {
          in_D0 = _DAT_00805e40 & 0xffff0100;
          if ((_DAT_00805e40 & 0x100) == 0) {
            _DAT_00805e00 = _DAT_00805e00 & 0xfeff;
            mask_for_input_of_water_in_fuel_0_65535 = 0;
            return in_D0;
          }
        }
      }
    }
    else {
      in_D0 = _DAT_00805e00 & 0xffff0100;
      if (((_DAT_00805e00 & 0x100) != 0) &&
         (in_D0 = _DAT_00805e40 & 0xffff0100, (_DAT_00805e40 & 0x100) == 0)) {
        _DAT_00fff420 = _DAT_00fff420 & 0x7fff;
        _DAT_00805e00 = _DAT_00805e00 & 0xfeff;
        mask_for_input_of_water_in_fuel_0_65535 = 0;
      }
    }
  }
  return in_D0;
}



//
// Function: FUN_00026aca @ 0x00026aca
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00026aca(void)

{
  uint uVar1;
  
  if (amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535 == 1) {
    uVar1 = 0;
    if ((_DAT_00805670 & 4) == 0) {
      _DAT_00fff43a = _DAT_00fff43a & 0xffff0000;
    }
    else {
      uVar1 = ((((uint)_DAT_00808938 * 0x6400) / 0x6400 & 0xffff) * 8000) / 1000 & 0xffff |
              ((uint)_DAT_00808938 * 8000) / 1000 << 0x10;
      _DAT_00fff43a = uVar1;
    }
    if ((_DAT_00805670 & 8) != 0) {
      _DAT_00fff442 =
           ((((uint)_DAT_0080893a * 0x6400) / 0x6400 & 0xffff) * 8000) / 1000 & 0xffff |
           ((uint)_DAT_0080893a * 8000) / 1000 << 0x10;
      return _DAT_00fff442;
    }
    _DAT_00fff442 = _DAT_00fff442 & 0xffff0000;
    return CONCAT22((short)(uVar1 >> 0x10),_DAT_00805670) & 0xffff0008;
  }
  if ((amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535 != 3) &&
     (amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535 != 5)) {
    return (uint)amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535;
  }
  if ((((_DAT_00fff438 & 0x80) == 0) || (((byte)sim_picr & 2) == 0)) &&
     (((_DAT_00fff438 & 0x80) != 0 || (((byte)sim_picr & 2) != 0)))) {
    _DAT_00805e00 = _DAT_00805e00 | 0x40;
    _DAT_00805e40 = _DAT_00805e40 | 0x40;
  }
  else if (((_DAT_00805e00 & 0x40) != 0) && ((_DAT_00805e40 & 0x40) == 0)) {
    _DAT_00805e00 = _DAT_00805e00 & 0xffbf;
  }
  if (((_DAT_00fff440 & 0x80) == 0) || (((byte)sim_picr & 4) == 0)) {
    if ((_DAT_00fff440 & 0x80) == 0) {
      if (((byte)sim_picr & 4) == 0) goto LAB_00026cc4;
    }
    _DAT_00805e00 = _DAT_00805e00 | 0x80;
    _DAT_00805e40 = _DAT_00805e40 | 0x80;
  }
  else {
LAB_00026cc4:
    if (((_DAT_00805e00 & 0x100) != 0) && ((_DAT_00805e40 & 0x100) == 0)) {
      _DAT_00805e00 = _DAT_00805e00 & 0xff7f;
    }
  }
  uVar1 = 0;
  if ((_DAT_00805670 & 4) == 0) {
    _DAT_00fff43a = _DAT_00fff43a & 0xffff0000;
  }
  else {
    uVar1 = ((uint)_DAT_00808938 * 8000) / 1000 << 0x10;
    _DAT_00fff43a = uVar1;
  }
  if ((_DAT_00805670 & 8) != 0) {
    _DAT_00fff442 = ((uint)_DAT_0080893a * 8000) / 1000 << 0x10;
    return _DAT_00fff442;
  }
  _DAT_00fff442 = _DAT_00fff442 & 0xffff0000;
  return CONCAT22((short)(uVar1 >> 0x10),_DAT_00805670) & 0xffff0008;
}



//
// Function: FUN_00026d98 @ 0x00026d98
//

void FUN_00026d98(void)

{
  if ((io_control_flags & 1) == 0) {
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
  if ((io_control_flags & 0x80) == 0) {
    DAT_0080d0c5 = DAT_0080d0c5 & 0xef;
  }
  else {
    DAT_0080d0c5 = DAT_0080d0c5 | 0x10;
  }
  if ((can_pin_switching_control_flags & 0x20) == 0) {
    DAT_0080d0c5 = DAT_0080d0c5 & 0xdf;
  }
  else {
    DAT_0080d0c5 = DAT_0080d0c5 | 0x20;
  }
  if ((io_control_source_register & 1) == 0) {
    DAT_0080d0c4 = DAT_0080d0c4 & 0xef;
  }
  else {
    DAT_0080d0c4 = DAT_0080d0c4 | 0x10;
  }
  if ((io_control_source_register & 2) == 0) {
    DAT_0080d0c4 = DAT_0080d0c4 & 0xdf;
  }
  else {
    DAT_0080d0c4 = DAT_0080d0c4 | 0x20;
  }
  if ((io_control_source_register & 4) == 0) {
    DAT_0080d0c4 = DAT_0080d0c4 & 0xbf;
  }
  else {
    DAT_0080d0c4 = DAT_0080d0c4 | 0x40;
  }
  if ((io_control_source_register & 0x10) != 0) {
    DAT_0080d0c4 = DAT_0080d0c4 | 0x80;
    return;
  }
  DAT_0080d0c4 = DAT_0080d0c4 & 0x7f;
  return;
}



//
// Function: FUN_00026e7e @ 0x00026e7e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00026e7e(void)

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
  byte *pbVar1;
  byte *pbVar2;
  
  pbVar2 = &DAT_00800000;
  while (pbVar2 < &byte_16_sent_from_secondary_processor_to_main_processor_0_255) {
    pbVar1 = pbVar2 + 0x100;
    if (&byte_16_sent_from_secondary_processor_to_main_processor_0_255 < pbVar1) {
      pbVar1 = &byte_16_sent_from_secondary_processor_to_main_processor_0_255;
    }
    for (; pbVar2 <= pbVar1; pbVar2 = pbVar2 + 4) {
      pbVar2[0] = 0;
      pbVar2[1] = 0;
      pbVar2[2] = 0;
      pbVar2[3] = 0;
    }
    REG_SIM_SWSR = 0xaa;
    DAT_00ffd00f = 0xaa;
  }
  return;
}



//
// Function: FUN_00026f10 @ 0x00026f10
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_00026f10(void)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  int *piVar4;
  int *piVar5;
  
  _DAT_008018ae = &DAT_008062d2;
  _DAT_008018b2 = 0x808ab2;
  _DAT_008018b6 = &firmware_data_source;
  _DAT_008018ba = &DAT_008062cc;
  _DAT_008018be = 0x8062ce;
  if (points_to_engine_sync_fuel_pressure_fuel_minimun_threshold_0_2_32._2_2_ == 2) {
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
  amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535 = 1;
  points_to_engine_sync_fuel_pressure_fuel_minimun_threshold_0_2_32._0_2_ = 1;
  _DAT_008018d6 = 1;
  return;
}



//
// Function: FUN_00026ff4 @ 0x00026ff4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00026ff4(void)

{
  undefined4 *puVar1;
  short *psVar2;
  
  if ((_DAT_008018d6 == 0) &&
     (amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535 != 0)) {
    FUN_00026f10();
  }
  if (points_to_engine_sync_fuel_pressure_fuel_minimun_threshold_0_2_32._2_2_ == 0) {
    amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535 = 0;
  }
  if (amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535 != 0) {
    if (((short *)_DAT_008018c6[1] <= _DAT_008018ce) ||
       ((_DAT_008018c6 == (undefined4 *)&DAT_008018ba &&
        (points_to_engine_sync_fuel_pressure_fuel_minimun_threshold_0_2_32._0_2_ == 0)))) {
      puVar1 = _DAT_008018c6 + 3;
      if ((puVar1 == (undefined4 *)&DAT_008018ba) &&
         (points_to_engine_sync_fuel_pressure_fuel_minimun_threshold_0_2_32._0_2_ == 0)) {
        puVar1 = _DAT_008018c6 + 6;
      }
      _DAT_008018c6 = puVar1;
      if ((undefined4 *)0x8018c5 < _DAT_008018c6) {
        _DAT_008018c6 = (undefined4 *)&DAT_008018ae;
        if (_DAT_008018d2 == 0) {
          if (((_DAT_00805df2 & 2) != 0) && ((_DAT_00805e32 & 2) == 0)) {
            _DAT_00805df2 = _DAT_00805df2 & 0xfffd;
          }
        }
        else {
          _DAT_00805df2 = _DAT_00805df2 | 2;
          _DAT_00805e32 = _DAT_00805e32 | 2;
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
  _DAT_008018d6 = amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535;
  return;
}



//
// Function: FUN_00027168 @ 0x00027168
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_00027168(void)

{
  char cVar1;
  
  if (DAT_0080d407 < 0x80) {
    cVar1 = '\x02';
  }
  else if (DAT_0080d407 < 0xc0) {
    cVar1 = '\x03';
  }
  else if (DAT_0080d407 < 0xfe) {
    if (*_DAT_0080d414 < 0x13) {
      cVar1 = *_DAT_0080d414 + 2;
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
// Function: FUN_000271b0 @ 0x000271b0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_000271b0(void)

{
  short sVar1;
  
  if (DAT_0080d407 < 0x80) {
    return 2;
  }
  if (DAT_0080d407 < 0xc0) {
    return 3;
  }
  if (DAT_0080d407 == 0xc1) {
    return CONCAT11((char)((ushort)_DAT_00804f44 >> 8),(char)_DAT_00804f44 + '\x02');
  }
  if (DAT_0080d407 == 0xc2) {
    if (DAT_0080d409 == '\0') {
      return CONCAT11((char)((ushort)_DAT_00804f40 >> 8),(char)_DAT_00804f40 * '\x02' + '\x02');
    }
    sVar1 = (_DAT_00804f42 + _DAT_00804f40) * 3;
    return CONCAT11((char)((ushort)sVar1 >> 8),(char)sVar1 + '\x02');
  }
  if (DAT_0080d407 == 0xc4) {
    if ((DAT_0080d448 & 0xc0) != 0) {
      return 4;
    }
    if (_DAT_0080d490 == 0) {
      return 2;
    }
    return 7;
  }
  if (DAT_0080d407 == 0xea) {
    return 0x18;
  }
  if (DAT_0080d407 != 0xed) {
    if (DAT_0080d407 != 0xf3) {
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
// Function: FUN_0002729a @ 0x0002729a
//

void FUN_0002729a(byte *param_1)

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
      in_D0 = FUN_0001b7e8((int)param_1);
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
// Function: FUN_00027314 @ 0x00027314
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00027314(int param_1)

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
// Function: FUN_00027342 @ 0x00027342
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00027342(int param_1)

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
// Function: FUN_000273d4 @ 0x000273d4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000273d4(int param_1)

{
  if (((*(byte *)(param_1 + 3) == the_can_bus_configuration_register_0_255) ||
      (the_can_bus_configuration_register_0_255 == 0xff)) && (*(short *)(param_1 + 4) == 8)) {
    DAT_008019a2 = **(byte **)(param_1 + 6);
    DAT_008019a6 = *(byte *)(*(int *)(param_1 + 6) + 4);
    if (_DAT_0080d03c == 0) {
      if ((DAT_008019a6 & 3) == 1) {
        if ((_fuel_arbitrator_condition_flag == 1) && (_DAT_0080cffa == 1)) {
          _arbitrator_special_mode_flag = 1;
          _DAT_0080d02e = _DAT_008086e4 + 1;
        }
      }
      else if ((DAT_008019a6 & 3) != 3) {
        _arbitrator_special_mode_flag = 0;
        _DAT_0080d02e = 0;
        _DAT_0080d030 = 0;
      }
    }
    if ((DAT_008019a6 & 0xc) == 4) {
      _DAT_0080d004 = 1;
      _DAT_0080d034 = _DAT_008086ee + 1;
    }
    else if ((DAT_008019a6 & 0xc) != 0xc) {
      _DAT_0080d004 = 0;
      _DAT_0080d034 = 0;
    }
    if (((DAT_008019a2 & 0x30) == 0x10) || ((DAT_008019a2 & 3) == 1)) {
      _DAT_0080d002 = 0;
      _DAT_0080d032 = 0;
      return;
    }
    _DAT_0080d002 = 1;
    _DAT_0080d032 = _DAT_008086ec + 1;
    _DAT_0080d016 = 1;
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
// Function: FUN_00027528 @ 0x00027528
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00027528(int param_1)

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
      uVar6 = FUN_0001d34e(CONCAT22(1,(short)CONCAT31(uVar5,cVar1)));
    }
    else {
      uVar6 = FUN_0001d19c(CONCAT22(1,(short)CONCAT31(uVar5,cVar1)),
                           CONCAT12(DAT_008019aa,uVar8) & 0x3ffff);
      if ((short)uVar6 != 0) {
        return;
      }
    }
    uVar5 = (undefined3)(uVar6 >> 8);
    if (_fuel_arbitrator_condition_flag == 0) {
      uVar6 = FUN_00029422(CONCAT22(1,(short)CONCAT31(uVar5,cVar1)));
      if ((short)uVar6 != 0) {
        return;
      }
      _DAT_0080d01e = _DAT_0080d01a;
    }
    else if (_DAT_0080d014 == 1) {
      if (cVar1 != DAT_0080d018) {
        if (bVar4 == 0) {
          return;
        }
        uVar6 = FUN_00029422(CONCAT22(1,(short)CONCAT31(uVar5,cVar1)));
        if ((short)uVar6 != 0) {
          return;
        }
        if (DAT_008019b2 < bVar2) {
          return;
        }
        if (bVar2 == DAT_008019b2) {
          if (_fuel_arbitrator_condition_flag != 3) {
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
      uVar6 = FUN_00029422(CONCAT22(1,(short)CONCAT31(uVar5,cVar1)));
      if ((short)uVar6 != 0) {
        return;
      }
      if (_DAT_0080d01e < _DAT_0080d01a) {
        return;
      }
      _DAT_0080d01e = _DAT_0080d01a;
    }
    _DAT_0080cff8 = (ushort)DAT_008019aa;
    DAT_008019b2 = bVar2;
    _DAT_0080d014 = 1;
    DAT_0080d018 = cVar1;
    switch(bVar3) {
    case 0:
      _DAT_0080d028 = 0;
      _fuel_arbitrator_condition_flag = 0;
      _DAT_0080cffa = 0;
      _DAT_0080d00c = 0;
      return;
    case 1:
      _DAT_0080d028 = *(short *)(_DAT_0080d01e + 4) + 1;
      _fuel_arbitrator_condition_flag = 1;
      uVar7 = FUN_00010d78(CONCAT22(CONCAT11((char)((ushort)_DAT_0080d028 >> 8),
                                             *(undefined1 *)(param_1 + 3)),uVar8));
      _DAT_0080cffa = (short)uVar7;
      _DAT_0080d00c = 1;
      _DAT_0080d00a = CONCAT11(DAT_008019ab,DAT_008019ac);
      _DAT_008019b4 = _DAT_0080d00a;
      if (24000 < _DAT_0080d00a) {
        _DAT_0080d00a = 24000;
      }
      _DAT_0080d012 = (short)((int)(DAT_008019aa & 0xc) >> 2);
      return;
    case 2:
      _DAT_0080d028 = *(short *)(_DAT_0080d01e + 8) + 1;
      _fuel_arbitrator_condition_flag = 2;
      uVar7 = FUN_00010d78(CONCAT22(CONCAT11((char)((ushort)_DAT_0080d028 >> 8),
                                             *(undefined1 *)(param_1 + 3)),uVar8));
      _DAT_0080cffa = (short)uVar7;
      _DAT_0080d00c = 0;
      DAT_008019b6 = DAT_008019ad;
      _DAT_0080d008 = (ushort)DAT_008019ad * 0x100 + -32000;
      _DAT_0080d010 =
           param_ref_base +
           (short)(((int)_DAT_0080d008 *
                   ((int)(short)param_scale_factor - (int)(short)param_ref_base)) / 0x6400);
      if (_DAT_0080d010 < 0) {
        _DAT_0080d010 = 0;
        return;
      }
      return;
    case 3:
      _DAT_0080d028 = *(short *)(_DAT_0080d01e + 0xc) + 1;
      _fuel_arbitrator_condition_flag = 3;
      uVar7 = FUN_00010d78(CONCAT22(CONCAT11((char)((ushort)_DAT_0080d028 >> 8),
                                             *(undefined1 *)(param_1 + 3)),uVar8));
      _DAT_0080cffa = (undefined2)uVar7;
      _DAT_0080d00c = 0;
      _DAT_008019b4 = CONCAT11(DAT_008019ab,DAT_008019ac);
      _fuel_arbitrator_conditional_limit = _DAT_008019b4;
      DAT_008019b6 = DAT_008019ad;
      _DAT_0080d00e =
           param_ref_base +
           (short)(((int)(short)((ushort)DAT_008019ad * 0x100 + -32000) *
                   ((int)(short)param_scale_factor - (int)(short)param_ref_base)) / 0x6400);
      if (_DAT_0080d00e < 0) {
        _DAT_0080d00e = 0;
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
// Function: FUN_000278be @ 0x000278be
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000278be(int param_1)

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
// Function: FUN_000279ee @ 0x000279ee
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_000279ee(undefined4 param_1)

{
  uint in_D0;
  ushort uVar2;
  ushort uVar3;
  uint uVar1;
  
  if (param_1._0_2_ == 0) {
    return in_D0 & 0xffffff00;
  }
  if (_DAT_008037d4 != 1) {
    _DAT_00801a60 = current_engine_rpm;
    uVar3 = lookupTableInterpolation((short *)&retarder_mode3_threshold_table);
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
  _DAT_00801a48 = current_engine_rpm;
  uVar2 = lookupTableInterpolation((short *)&retarder_mode1_threshold_table);
  uVar3 = (ushort)(((uint)param_1._0_2_ * (uint)_DAT_00807978) / 0x6400);
  if (uVar3 < uVar2) {
    return 1;
  }
  _DAT_00801a54 = current_engine_rpm;
  uVar2 = lookupTableInterpolation((short *)&retarder_mode2_threshold_table);
  if (uVar3 < uVar2) {
    return 2;
  }
  return 3;
}



//
// Function: FUN_00027aca @ 0x00027aca
//

short FUN_00027aca(undefined4 param_1)

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
// Function: FUN_00027afa @ 0x00027afa
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00027afa(int param_1)

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
        uVar4 = FUN_0001d3b8((uint)CONCAT12(bVar1,uVar7));
      }
      else {
        uVar4 = FUN_0001d1ec((uint)CONCAT12(bVar1,uVar7));
        if ((short)uVar4 != 0) {
          return;
        }
      }
      if (_DAT_0080cfa8 == 0) {
        uVar4 = FUN_00029422(CONCAT22(1,(short)CONCAT31((int3)(uVar4 >> 8),bVar1)));
        if ((short)uVar4 != 0) {
          return;
        }
        _DAT_0080d022 = _DAT_0080d01a;
      }
      else if (bVar1 != _DAT_0080cfac) {
        if (bVar3 == 0) {
          return;
        }
        uVar4 = FUN_00029422(CONCAT22(1,(ushort)bVar1));
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
        _retarder_mode_table_count = 3;
        _DAT_0080cffe = 0;
        return;
      }
      if (bVar3 == 2) {
        sVar8 = FUN_00027aca((uint)CONCAT12(DAT_00801a3d,uVar7));
        _DAT_0080cfb4 = sVar8;
        if (((((_diagnostic_system_flags_2 & 0x1000) == 0) ||
             (bVar1 != the_can_bus_configuration_register_0_255)) ||
            (_fuel_arbitrator_condition_flag != 1)) ||
           (((_DAT_0080cffa != 1 || (cached_parameter_value < _DAT_0080894c)) || (sVar8 == 0)))) {
          _DAT_0080d02c = *(short *)(_DAT_0080d022 + 0xe) + 1;
          _DAT_0080cfa8 = 2;
          uVar10 = CONCAT11((char)((ushort)_DAT_0080d02c >> 8),*(undefined1 *)(param_1 + 3));
          uVar5 = FUN_00010d78(CONCAT22(uVar10,uVar7));
          _DAT_0080cfaa = (undefined2)uVar5;
          _retarder_mode_table_count = 3;
          uVar4 = FUN_000279ee(CONCAT22(sVar8,uVar10));
          _DAT_0080cfb0 = (ushort)uVar4 & 0xff;
          if ((uVar4 & 0xff) == 0) {
            _DAT_0080cffe = 1;
            _DAT_0080d036 = *(short *)(_DAT_0080d022 + 0xe) + 1;
          }
          else {
            _DAT_0080cffe = 0;
            _DAT_0080d036 = 0;
          }
        }
        else {
          _DAT_0080d02c = 0;
          _DAT_0080cfa8 = 0;
          _DAT_0080cfaa = 0;
          _DAT_0080cfb0 = 0;
          _retarder_mode_table_count = 3;
          _DAT_0080cffe = 0;
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
      uVar5 = FUN_00010d78((uint)CONCAT12(*(byte *)(param_1 + 3),uVar7));
      _DAT_0080cfaa = (undefined2)uVar5;
      _DAT_0080cfb0 = 0;
      uVar7 = (undefined2)CONCAT31((int3)((uint)uVar5 >> 8),DAT_00801a3d);
      sVar8 = FUN_00027aca(CONCAT22(uVar7,uVar6));
      _DAT_0080d02c = *(short *)(_DAT_0080d022 + 0x12) + 1;
      uVar4 = FUN_000279ee(CONCAT22(sVar8,uVar7));
      _retarder_mode_table_count = (ushort)uVar4 & 0xff;
      bVar9 = (uVar4 & 0xff) != 0;
      if (bVar9) {
        _DAT_0080d036 = 0;
      }
      else {
        _DAT_0080d036 = *(short *)(_DAT_0080d022 + 0x12) + 1;
      }
      _DAT_0080cffe = (ushort)!bVar9;
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
  _retarder_mode_table_count = 3;
  retarder_mode1_data_ptr = 0x807952;
  retarder_mode1_output_ptr = 0x807998;
  retarder_mode1_threshold_table = 2;
  retarder_mode2_data_ptr = 0x807952;
  retarder_mode2_output_ptr = 0x8079a2;
  retarder_mode2_threshold_table = 2;
  retarder_mode3_data_ptr = 0x80797a;
  retarder_mode3_output_ptr = 0x8079ac;
  retarder_mode3_threshold_table = 2;
  return;
}



//
// Function: FUN_00027e3e @ 0x00027e3e
//

void FUN_00027e3e(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 2);
  if ((bVar1 != j1939_source_address_primary) && (bVar1 != 0xff)) {
    if ((bVar1 == j1939_source_address_secondary) || (bVar1 == 0xff)) {
      FUN_00027afa(param_1);
    }
    return;
  }
  FUN_00027528(param_1);
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
// Function: FUN_00027e9c @ 0x00027e9c
//

void FUN_00027e9c(undefined4 param_1)

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
// Function: FUN_00027ef0 @ 0x00027ef0
//

void FUN_00027ef0(undefined4 param_1)

{
  short sVar1;
  undefined4 unaff_D2;
  
  sVar1 = param_1._0_2_ * 10;
  (&DAT_00804fcd)[sVar1] = 0;
  *(undefined4 *)(sVar1 + 0x804fc4) = 0;
  *(undefined4 *)
   ((int)&ivs_switch_status_when_throttle_validation_process_error_true_false + (int)sVar1) = 0;
  if (*(char *)(sVar1 + 0x804fcc) == '\x02') {
    FUN_00027e9c(CONCAT22(param_1._0_2_,(short)((uint)unaff_D2 >> 0x10)));
  }
  *(undefined1 *)(sVar1 + 0x804fcc) = 0;
  return;
}



//
// Function: FUN_00027f4c @ 0x00027f4c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00027f4c(undefined4 param_1)

{
  short sVar1;
  
  if ((*(ushort *)(&DAT_008065ce + (short)(param_1._2_2_ * 3) * 2) & 0x10) != 0) {
    sVar1 = param_1._0_2_ * 0x30;
    *(short *)(&DAT_00805a36 + sVar1) = param_1._2_2_;
    *(word *)(&DAT_00805a3e + sVar1) = asthrfes_calc_input;
    *(undefined2 *)(&DAT_00805a38 + sVar1) = _DAT_008096a6;
    *(undefined2 *)(sVar1 + 0x805a3a) = _current_engine_rpm_raw;
    *(undefined2 *)(sVar1 + 0x805a40) = _active_derate_value;
    *(undefined2 *)(&DAT_00805a42 + sVar1) = _diagnostic_sensor_reading;
    *(dword *)(sVar1 + 0x805a32) = loopCounter;
    *(undefined2 *)(&DAT_00805a44 + sVar1) = _DAT_0080926e;
    *(undefined2 *)(sVar1 + 0x805a46) = _DAT_008091ea;
    *(undefined2 *)(sVar1 + 0x805a48) = _DAT_00809242;
    *(undefined2 *)(sVar1 + 0x805a3c) = _DAT_0080bdc0;
    *(undefined2 *)(sVar1 + 0x805a4a) = _DAT_0080bdc2;
    *(dword *)(sVar1 + 0x805a4c) = engineRunCounter;
    *(undefined2 *)(sVar1 + 0x805a50) = _DAT_0080c9a6;
    *(undefined2 *)(sVar1 + 0x805a52) = _DAT_00809308;
    *(undefined2 *)(sVar1 + 0x805a54) = _current_fuel_demand_value;
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
    *(word *)(sVar1 + 0x80567e) = asthrfes_calc_input;
    *(undefined2 *)(sVar1 + 0x805678) = _DAT_008096a6;
    *(undefined2 *)(sVar1 + 0x80567a) = _current_engine_rpm_raw;
    *(undefined2 *)(sVar1 + 0x805680) = _active_derate_value;
    *(undefined2 *)(sVar1 + 0x805682) = _diagnostic_sensor_reading;
    *(dword *)(sVar1 + 0x805672) = loopCounter;
    *(undefined2 *)(sVar1 + 0x805684) = _DAT_0080926e;
    *(undefined2 *)(sVar1 + 0x805686) = _DAT_008091ea;
    *(undefined2 *)(sVar1 + 0x805688) = _DAT_00809242;
    *(undefined2 *)(sVar1 + 0x80567c) = _DAT_0080bdc0;
    *(undefined2 *)(sVar1 + 0x80568a) = _DAT_0080bdc2;
    *(dword *)(sVar1 + 0x80568c) = engineRunCounter;
    *(undefined2 *)(sVar1 + 0x805690) = _DAT_0080c9a6;
    *(undefined2 *)(sVar1 + 0x805692) = _DAT_00809308;
    *(undefined2 *)(sVar1 + 0x805694) = _current_fuel_demand_value;
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
// Function: FUN_000281e8 @ 0x000281e8
//

void FUN_000281e8(void)

{
  char cVar1;
  short sVar2;
  
  cVar1 = '\0';
  if (loopCounter == 0) {
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
// Function: FUN_00028220 @ 0x00028220
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00028220(void)

{
  char cVar1;
  undefined4 in_D0;
  int iVar2;
  undefined4 in_D1;
  
  DAT_0080d2da = 0;
  _DAT_00fff458 = _DAT_00fff458 & 0xfff;
  if (((DAT_0080d2d0 == '\x01') && (*_DAT_0080d2c2 != 0)) && (DAT_0080d2ce == '\0')) {
    if (*_DAT_0080d2c2 < 3) {
      _dummy_variable_0_65535 =
           (byte *)CONCAT31(_dummy_variable_0_65535,(char)dummy_variable_0_65535 + '\x01');
      *_DAT_0080d2c2 = 0;
      DAT_0080d2d3 = 0;
    }
    else if (DAT_0080d2d3 == 0) {
      *_DAT_0080d2c2 = *_DAT_0080d2c2 - 1;
      _DAT_0080d2c2 = (byte *)CONCAT31(_DAT_0080d2c2,flag_indicating_eps_sensor_not_used_0_1 - 1);
      *_DAT_0080d2c2 = 0;
    }
    else {
      _dummy_variable_0_65535 =
           (byte *)CONCAT31(_dummy_variable_0_65535,(char)dummy_variable_0_65535 + '\x01');
      if (*_dummy_variable_0_65535 < 7) {
        if ((int)_DAT_0080d2c2 < _enables_input_of_eps_period_data_to_pptb_0_1) {
          iVar2 = (_enables_input_of_eps_period_data_to_pptb_0_1 - (int)_DAT_0080d2c2) + -2;
        }
        else {
          iVar2 = (_enables_input_of_eps_period_data_to_pptb_0_1 - (int)_DAT_0080d2c2) + 0xfe;
        }
        if (3 < iVar2) {
          DAT_0080d2db = DAT_0080d2db + '\x01';
          *_DAT_0080d2c2 = 2;
          _DAT_0080d2c2 = (byte *)CONCAT31(_DAT_0080d2c2,(char)dummy_variable_0_65535 + '\x01');
          *_DAT_0080d2c2 = 6;
          _DAT_0080d2c2 = (byte *)CONCAT31(_DAT_0080d2c2,(char)dummy_variable_0_65535 + '\x01');
          *_DAT_0080d2c2 = 0x74;
          cVar1 = (char)dummy_variable_0_65535;
          _DAT_0080d2c2 = (byte *)CONCAT31(_DAT_0080d2c2,(char)dummy_variable_0_65535 + '\x01');
          _dummy_variable_0_65535 = (byte *)CONCAT31(_dummy_variable_0_65535,cVar1 + '\x02');
        }
      }
      *_DAT_0080d2c2 = 0;
      DAT_0080d2d3 = 0;
    }
  }
  if (DAT_0080d2d0 == '\0') {
    DAT_0080d2d3 = 0;
    DAT_0080d2d0 = '\x01';
    flag_shows_posibility_of_esp_transitioning_between_normal_false_true._1_1_ = (char)_DAT_0080d2bc
    ;
    _track_the_time_when_throttle_is_less_than_a_threshold_0_30 =
         (byte *)CONCAT31((int3)((uint)_DAT_0080d2bc >> 8),
                          (char)flag_shows_posibility_of_esp_transitioning_between_normal_false_true
                          + '\x01');
    DAT_0080d2da = 1;
    _DAT_00fff45a = 0xfcbe;
    _DAT_00fff458 = _DAT_00fff458 & 0x7fff | 0x4000;
  }
  else if (_DAT_0080d2b4 != _DAT_0080d2bc) {
    if ((tpu_cfsr0 & 0x20) == 0) {
      tpu_cfsr1 = (word)*_track_the_time_when_throttle_is_less_than_a_threshold_0_30;
      DAT_0080d2d0 = '\0';
      _DAT_0080d2d6 = 0;
      DAT_0080d2d1 = 1;
      DAT_0080d2d3 = *_track_the_time_when_throttle_is_less_than_a_threshold_0_30;
      tpu_cier = tpu_cier | 0x20;
    }
    else {
      DAT_0080d2da = 1;
      _DAT_00fff45a = 0xfc8a;
      _DAT_00fff458 = _DAT_00fff458 & 0x7fff | 0x4000;
    }
  }
  return CONCAT44(in_D0,in_D1);
}



//
// Function: FUN_000283c0 @ 0x000283c0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000283c0(void)

{
  _DAT_00808fee = FUN_00028220;
  _DAT_00fff458 = _DAT_00fff458 & 0xfff;
  return;
}



//
// Function: FUN_000283dc @ 0x000283dc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000283dc(void)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  undefined4 local_8;
  
  uVar3 = current_engine_rpm;
  if (_DAT_0080d460 == 1) {
    uVar3 = _DAT_0080d45e;
  }
  if ((uVar3 != 0) && (uVar3 < _DAT_00801a66)) {
    uVar3 = _DAT_00801a66;
  }
  if ((uVar3 == 0) ||
     (0x10c5 < mask_used_by_a_tool_to_id_the_trip_faults_found_in_the_trip_in_0_03f)) {
    _DAT_0080d462 = 0x4230bdc0;
    local_8 = FUN_000357d2(16000000,0x4230bdc0,32000000);
    local_8 = local_8 & 0xffff;
  }
  else {
    _DAT_0080d462 =
         ((uint)mask_used_by_a_tool_to_id_the_trip_faults_found_in_the_trip_in_0_03f * 1000000) /
         (uint)uVar3;
    uVar2 = FUN_000357d2(16000000,_DAT_0080d462,32000000);
    local_8 = uVar2 & 0xffff;
    uVar1 = local_8;
    local_8 = CONCAT22((short)((int)uVar1 >> 1),(short)uVar2);
  }
  _DAT_00ffffc4 = local_8;
  return;
}



//
// Function: FUN_000284aa @ 0x000284aa
//

/* WARNING: Removing unreachable block (ram,0x00028528) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000284aa(void)

{
  can1_cantbsel = can1_cantbsel & 0xefff;
  can1_canidmr2 = can1_canidmr2 & 0xefff;
  can1_canidac = can1_canidac & 0xfff0 | 0xb;
  _DAT_00ffffc0 = 0x92;
  _DAT_00ffffc4 = 0xffff;
  can1_canidar2 = can1_canidar2 & 0xfcff | 0x200;
  can1_canidmr0 = can1_canidmr0 & 0xfcff | 0x100;
  _DAT_00801a66 =
       (word)((int)((uint)mask_used_by_a_tool_to_id_the_trip_faults_found_in_the_trip_in_0_03f *
                   0x1e84) >> 10);
  if (_DAT_00801a66 < road_speed_below_which_esp_distance_does_not_accumulate_0_10) {
    _DAT_00801a66 = road_speed_below_which_esp_distance_does_not_accumulate_0_10;
  }
  return;
}



//
// Function: FUN_0002853c @ 0x0002853c
//

undefined8 FUN_0002853c(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  return CONCAT44(in_D0,in_D1);
}



//
// Function: FUN_00028546 @ 0x00028546
//

void FUN_00028546(void)

{
  return;
}



//
// Function: FUN_00028548 @ 0x00028548
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00028548(uint *param_1,uint *param_2)

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
// Function: FUN_00028588 @ 0x00028588
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00028588(void)

{
  _DAT_00804bcc = _DAT_00805f44 + 1;
  _DAT_00805f48 = _DAT_00805f48 + 1;
  _DAT_00805f44 = _DAT_00804bcc;
  if (_DAT_0080d46a != 0) {
    FUN_00028548((uint *)&DAT_00805f24,(uint *)&DAT_00805f38);
    FUN_00028548((uint *)0x805f58,(uint *)&DAT_00804bd0);
  }
  return;
}



//
// Function: FUN_000285c8 @ 0x000285c8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000285c8(void)

{
  _DAT_00805f4c = _DAT_00805f4c + 1;
  _DAT_00804bd4 = _DAT_00805f64 + 1;
  _DAT_00805f64 = _DAT_00804bd4;
  if (_DAT_0080d46a != 0) {
    FUN_00028548((uint *)&DAT_00805f28,(uint *)&DAT_00805f3c);
    FUN_00028548((uint *)0x805f5c,(uint *)0x805f60);
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
  
  bVar1 = io_control_flags & 1;
  if (((io_control_flags & 1) == 0) && (bVar1 = DAT_0080bdf1 & 1, (DAT_0080bdf1 & 1) == 0)) {
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
  
  if (_current_engine_rpm_raw != 0) {
    if (_DAT_00805f8a < _current_engine_rpm_raw) {
      _DAT_00805f8a = _current_engine_rpm_raw;
    }
    if ((_current_engine_rpm_raw < _DAT_00803818) || (_DAT_00808a66 == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = (short)((int)((uint)_current_engine_rpm_raw - (uint)_DAT_00803818) /
                     (int)(uint)_DAT_00808a66) + 1;
      if (0x18 < uVar1) {
        uVar1 = 0x18;
      }
    }
    *(int *)(&DAT_00805eb4 + (short)uVar1 * 4) = *(int *)(&DAT_00805eb4 + (short)uVar1 * 4) + 1;
  }
  DAT_00801a84 = DAT_00801a84 + '\x01';
  if (DAT_00801a84 == '\n') {
    DAT_00801a84 = '\0';
    if (_current_engine_rpm_raw != 0) {
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
  if (_DAT_0080c9a6 == 0xb) {
    if (_DAT_00801a7a != 0) {
      _DAT_00801a7a = _DAT_00801a7a - 1;
    }
    if (_DAT_00801a78 != 0) {
      _DAT_00801a78 = _DAT_00801a78 - 1;
    }
    if (_DAT_00801a7c != 0) {
      _DAT_00801a7c = _DAT_00801a7c - 1;
    }
    _DAT_00801a74 = 0;
  }
  else {
    _DAT_00801a74 = _DAT_00801a74 + 1;
    if (_DAT_00808a68 < _DAT_008092b0) {
      if (if_the_engine_load_exceeds_this_threshold_the_engine_is_deemed_0_127_5 < _DAT_0080d0c8) {
        _DAT_00801a78 = minimum_time_the_engine_must_idle_before_shutdown_if_high_loa_0_1800;
      }
      if (_DAT_00808a62 < _current_engine_rpm_raw) {
        _DAT_00801a7a = minimum_idle_time_if_the_engine_was_at_high_speed_to_avoid_ho_0_1800;
      }
      if (_DAT_00808a5c < _DAT_00801a74) {
        _DAT_00801a7c = minimum_time_the_engine_must_idle_before_shutdown_if_at_high_0_1800;
      }
    }
  }
  if (((engine_operating_mode == FAULT_EMERGENCY) && (_DAT_00801a7e != 8)) &&
     ((_DAT_00801a7a != 0 || _DAT_00801a78 != 0 || (_DAT_00801a7c != 0)))) {
    _DAT_00805f88 = _DAT_00805f88 + 1;
    _DAT_00801a78 = 0;
    _DAT_00801a7a = 0;
    _DAT_00801a7c = 0;
  }
  _DAT_00801a7e = engine_operating_mode;
  if (_DAT_0080c9a6 == 0x12) {
    _DAT_00805f84 = _DAT_00805f84 + 1;
  }
  return;
}



//
// Function: FUN_0002880e @ 0x0002880e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0002880e(void)

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
    fuel_total_when_the_weighted_fuel_value_reaches_the_fu_0_0_1000000_0 = 0;
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
  uVar3 = _diagnostic_system_flags_1 & 0x200;
  if (uVar3 != 0) {
    if (_current_engine_rpm_raw == 0) {
      _DAT_0080d47a = 0;
    }
    else if ((_DAT_0080c9a6 == 0xb) && (_DAT_008096a6 == 0)) {
      _DAT_0080d47a = 1;
    }
    else if (pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._2_2_ == 1) {
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
        _DAT_0080d46a = FUN_000357d2(_DAT_00805f8c - _DAT_00801a70,0x800000,_DAT_00808a6a);
        _DAT_00801a70 = _DAT_00805f8c;
      }
      else {
        _DAT_0080d46a = FUN_000357d2((uint)_DAT_0080c9ca,0x5000000,0x39c2c30);
      }
      if (_DAT_0080d46a == 0) {
        _DAT_0080d476 = 0;
        _DAT_0080d478 = 0;
      }
      else {
        DAT_0080d468 = DAT_0080d469;
        uVar1 = FUN_000357d2(_DAT_0080d46a,0x232893,0x800000);
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
        uVar2 = FUN_00028548((uint *)0x805f1c,(uint *)&DAT_00805f6c);
        if ((short)uVar2 != 0) {
          _DAT_00805f40 = _DAT_00805f40 | 0x20;
        }
        uVar2 = FUN_00028548((uint *)&DAT_00805f20,(uint *)&DAT_00805f34);
        if ((short)uVar2 != 0) {
          _DAT_00805f40 = _DAT_00805f40 | 0x800;
        }
        _DAT_00804bb8 = _DAT_00805f6c;
        _DAT_00804bbc = _DAT_00805f34;
        if (DAT_0080d468 == '\0') {
          _DAT_00801a68 = 0;
        }
        else if (the_minimum_time_a_fault_must_be_present_before_logged_in_trip_in_0_30 <
                 _DAT_00801a68) {
          _DAT_00805f40 = _DAT_00805f40 | 0x41;
        }
        else {
          _DAT_00801a68 = _DAT_00801a68 + 1;
        }
      }
      if (_DAT_0080d47a == 3) {
        FUN_00028548(&fuel_total_when_the_weighted_fuel_value_reaches_the_fu_0_0_1000000_0,
                     (uint *)&DAT_00805f30);
      }
      else if (_DAT_0080d47a == 1) {
        FUN_00028588();
      }
      else if (_DAT_0080d47a == 2) {
        FUN_000285c8();
      }
      FUN_0002860c();
      if (fuel_timing_control_value != 0) {
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
  if ((_diagnostic_system_flags_1 & 0x200) != 0) {
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
  return _diagnostic_system_flags_1 & 0x200;
}



//
// Function: FUN_00028bda @ 0x00028bda
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00028bda(void)

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
// Function: FUN_0002939c @ 0x0002939c
//

void FUN_0002939c(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((can1_canmcr & 0x400) != 0x400) {
    qsm_qilr = 0xffe0;
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
    can1_canmcr = 0x407;
    can1_cantbsel = 0;
    can1_cantaak = 0x440;
  }
  return;
}



//
// Function: FUN_00029422 @ 0x00029422
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00029422(undefined4 param_1)

{
  uint in_D0;
  byte bVar1;
  short *psVar2;
  
  psVar2 = (short *)&DAT_008086f8;
  bVar1 = 0;
  while (((param_1._0_2_ != *psVar2 || ((char)param_1 != *(char *)((int)psVar2 + 3))) &&
         ((param_1._0_2_ != 1 || ((*psVar2 != 1 || (*(char *)((int)psVar2 + 3) != -1))))))) {
    in_D0 = 0;
    psVar2 = psVar2 + 10;
    bVar1 = bVar1 + 1;
    if (4 < bVar1) {
      return 1;
    }
  }
  _DAT_0080d01a = psVar2;
  return in_D0 & 0xffff0000;
}



//
// Function: FUN_00029476 @ 0x00029476
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00029476(int param_1,undefined4 param_2)

{
  _DAT_00801a86 = CONCAT13((char)((_can_priority_table_start & 7) << 2),0xe8ff00);
  _DAT_00801a88 = CONCAT11(*(undefined1 *)(param_1 + 3),*(undefined1 *)(param_1 + 2));
  can_buffer_setup1_data = (byte)((uint)param_2 >> 0x10);
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
  _can_buffer_setup1_size = 8;
  can_buffer_setup1_data_ptr = (dword)&can_buffer_setup1_data;
  can_buffer_setup1_unused_ptr = 0x801a9c;
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
  ambient_conditions_data_start = (byte)((((uint)_DAT_008092f2 * 2 >> 7) * 0x1afa) / 1000);
  sendCanMessage((j1939_header_t *)&ambient_conditions_msg_header);
  return;
}



//
// Function: ambientConditionsPGN_65269_Builder @ 0x0002956a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ambientConditionsPGN_65269_Builder(void)

{
  ambient_conditions_msg_header = CONCAT13((char)((_DAT_008037b8 & 7) << 2),0xfef500);
  ambient_conditions_msg_length = 8;
  ambient_conditions_data_ptr = (dword)&ambient_conditions_data_start;
  ambient_conditions_unused_ptr = (dword)&ambient_conditions_buffer_end;
  ambient_conditions_msg_header =
       CONCAT31(ambient_conditions_msg_header._0_3_,j1939_source_address_primary);
  ambient_barometric_pressure = 0xff;
  ambient_cab_interior_temp = 0xff;
  ambient_air_temp = 0xff;
  engine_air_inlet_temp = 0xff;
  road_surface_temp = 0xff;
  ambient_conditions_reserved = 0xffff;
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
  
  if ((vp44_communication_status & 0x20) == 0) {
    j1939_pgn_65265_data_byte1 = 0xf3;
  }
  else {
    j1939_pgn_65265_data_byte1 = 0xf7;
  }
  if ((-(8 < _DAT_008096a6) & 1U) < 0x9d) {
    local_6 = _DAT_008096a6;
  }
  else {
    local_6 = 0x9c00;
  }
  uVar1 = (uint)local_6;
  local_6._1_1_ = (byte)(uVar1 * 0x19c >> 8);
  ambient_temp_calc_low = (byte)local_6;
  local_6._0_1_ = (byte)(uVar1 * 0x19c >> 0x10);
  ambient_temp_calc_high = local_6._0_1_;
  if ((DAT_0080bdc7 & 4) == 0) {
    ambient_sensor_status1 = 0;
  }
  else {
    ambient_sensor_status1 = 4;
  }
  if ((DAT_0080bdc7 & 8) != 0) {
    ambient_sensor_status1 = ambient_sensor_status1 | 0x10;
  }
  if ((sensor_status_register & 0x10) != 0) {
    ambient_sensor_status1 = ambient_sensor_status1 | 4;
  }
  if (_protection_system_enable_flag == 1) {
    ambient_sensor_status1 = ambient_sensor_status1 | 1;
  }
  if ((sensor_status_register & 2) == 0) {
    ambient_sensor_status2 = 0;
  }
  else {
    ambient_sensor_status2 = 0x40;
  }
  if ((sensor_status_register & 1) != 0) {
    ambient_sensor_status2 = ambient_sensor_status2 | 0x10;
  }
  if ((sensor_status_register & 8) != 0) {
    ambient_sensor_status2 = ambient_sensor_status2 | 4;
  }
  if ((sensor_status_register & 4) != 0) {
    ambient_sensor_status2 = ambient_sensor_status2 | 1;
  }
  ambient_temp_processed = (byte)((uint)_target_boost_pressure_base * 0x19c >> 0x10);
  if (_protection_system_enable_flag == 1) {
    ambient_status_final = 0x3f;
  }
  else {
    ambient_status_final = 0x1f;
  }
  sendCanMessage((j1939_header_t *)&j1939_pgn_65265_header);
  return;
}



//
// Function: j1939MessageSetup_PGN_65265 @ 0x00029796
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void j1939MessageSetup_PGN_65265(void)

{
  j1939_pgn_65265_header = CONCAT13((char)((_DAT_008037ba & 7) << 2),0xfef100);
  j1939_pgn_65265_header = CONCAT31(j1939_pgn_65265_header._0_3_,j1939_source_address_primary);
  _j1939_pgn_65265_size = 7;
  j1939_pgn_65265_data_ptr = (dword)&j1939_pgn_65265_data_byte1;
  j1939_pgn_65265_unused_ptr = 0x801acc;
  j1939_pgn_65265_data_byte1 = 0xf3;
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
  _DAT_00801ace = CONCAT31(_DAT_00801ace,j1939_source_address_primary);
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
  bVar2 = FUN_0000a5e2(CONCAT22(uVar1,(short)((uint)unaff_D2 >> 0x10)));
  cVar3 = (char)((uint)param_2 >> 0x10);
  if (cVar3 == '\0') {
    sVar5 = bVar2 + 1;
  }
  else {
    sVar5 = bVar2 + 2;
  }
  msg_header = (j1939_header_t *)FUN_0001cb18(CONCAT22(sVar5,uVar1));
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
      uVar2 = FUN_0001bc74();
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
  _DAT_00801afa = CONCAT31(_DAT_00801afa,j1939_source_address_primary);
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
    uVar2 = FUN_0001bc74();
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
  _DAT_00802200 = CONCAT31(_DAT_00802200,j1939_source_address_primary);
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
          uVar4 = FUN_0001bc52((undefined2 *)(iVar8 + iVar2 + 0x80567a));
          puVar10[8] = (char)uVar4;
          puVar10[7] = (char)((ushort)uVar4 >> 8);
          puVar10[9] = (char)((ushort)*(undefined2 *)((short)(sVar9 + sVar3) + 0x80567e) >> 8);
          puVar10[10] = (char)(((short)((int)(uint)*(ushort *)((short)(sVar9 + sVar3) + 0x805684) >>
                                       7) * 5 + -0xa0) / 9) + '(';
          if (_DAT_008084c4 == 1) {
            local_6 = (undefined2)
                      ((uint)*(ushort *)((short)(sVar9 + sVar3) + 0x805678) * 0x19c >> 8);
            uVar4 = FUN_0001bc52(&local_6);
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
  _DAT_00802906 = CONCAT31(_DAT_00802906,j1939_source_address_primary);
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
  _DAT_00803000 = FUN_0001bc52((undefined2 *)&DAT_008084ca);
  if (_DAT_0080cfce == 1) {
    local_6 = local_6 & 0xfeff;
  }
  else if ((_DAT_008084ca & 0x100) == 0) {
    local_6 = local_6 | 0x100;
  }
  else if ((_DAT_0080cfce == 0) && ((_DAT_008084ca & 0x100) != 0)) {
    local_6 = local_6 | 0x100;
  }
  _DAT_00803002 = FUN_0001bc52(&local_6);
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
  _DAT_00802fee = CONCAT31(_DAT_00802fee,j1939_source_address_primary);
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
  _DAT_00803016 = FUN_0001bc52((undefined2 *)((int)&param_1 + 2));
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
  _DAT_00803006 = CONCAT31(_DAT_00803006,j1939_source_address_primary);
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
  _DAT_0080301e = CONCAT31(_DAT_0080301e,j1939_source_address_primary);
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
  
  if (_fuel_arbitrator_condition_flag == 0) {
    switch(_DAT_0080c9a6) {
    case 3:
    case 7:
    case 8:
      j1939_tx_msg_buffer = 0xf1;
      break;
    case 4:
      j1939_tx_msg_buffer = 0xf3;
      break;
    default:
      j1939_tx_msg_buffer = 0xfe;
      break;
    case 9:
      j1939_tx_msg_buffer = 0xf2;
      break;
    case 10:
      j1939_tx_msg_buffer = 0xf4;
      break;
    case 0xb:
      j1939_tx_msg_buffer = 0xf0;
      break;
    case 0xc:
      j1939_tx_msg_buffer = 0xf9;
      break;
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x15:
      j1939_tx_msg_buffer = 0xf8;
      break;
    case 0x18:
      j1939_tx_msg_buffer = 0xfa;
    }
  }
  else if (_DAT_0080cffa == 1) {
    j1939_tx_msg_buffer = 0xf6;
  }
  else if (_DAT_0080cffa == 3) {
    j1939_tx_msg_buffer = 0xf5;
  }
  else if (_DAT_0080cffa == 2) {
    j1939_tx_msg_buffer = 0xf7;
  }
  else {
    j1939_tx_msg_buffer = 0xfe;
  }
  paramSystemModeController();
                    /* Constant: VP44_FUEL_OFFSET = 125 */
  j1939_vp44_fuel_high = (char)(param_table_aux >> 8) + 0x7d;
  param_lookup_1();
  j1939_vp44_fuel_low = (char)(param_table_main >> 8) + 0x7d;
  bStack_5 = (byte)current_engine_rpm;
  j1939_vp44_rpm_low = bStack_5;
  local_6 = (byte)(current_engine_rpm >> 8);
  j1939_vp44_rpm_high = local_6;
  sendCanMessage((j1939_header_t *)&vp44_cmd_msg_buffer);
  return;
}



//
// Function: vp44Command0x100Builder @ 0x0002a418
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44Command0x100Builder(void)

{
                    /* Constant: VP44_MSG_HEADER = 0xF00400 */
  _vp44_cmd_msg_buffer = CONCAT13((char)((_DAT_008037ca & 7) << 2),0xf00400);
  _vp44_cmd_msg_buffer = CONCAT31(_vp44_cmd_msg_buffer,j1939_source_address_primary);
  _vp44_timing_byte4 = 5;
  _vp44_timing_byte6 = &j1939_tx_msg_buffer;
  _DAT_00803048 = 0x80304c;
  return;
}



//
// Function: FUN_0002a45c @ 0x0002a45c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002a45c(void)

{
  bool bVar1;
  
  if (((_engine_fault_register_a & 0x20) == 0) || ((_engine_fault_register_b & 0x20) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if (((_engine_fault_register_a & 8) == 0) || ((_engine_fault_register_b & 8) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (_DAT_008086f0 < _active_derate_value) {
        diagnostic_status_data = 0xf4;
      }
      else {
        diagnostic_status_data = 0xf0;
      }
      DAT_0080304f = (char)((int)(uint)_active_derate_value >> 1) +
                     (char)((int)(uint)_active_derate_value >> 3);
      goto LAB_0002a4ea;
    }
  }
  diagnostic_status_data = 0xf8;
  DAT_0080304f = -2;
LAB_0002a4ea:
  if (_derate_threshold_exceeded == 0) {
    diagnostic_status_data = diagnostic_status_data | 1;
  }
  param_lookup_2();
  DAT_00803050 = (undefined1)(param_table_ctrl >> 8);
  sendCanMessage((j1939_header_t *)&can_param_msg_buf_2);
  return;
}



//
// Function: cumminsProprietaryDM_983_Builder @ 0x0002a51e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cumminsProprietaryDM_983_Builder(void)

{
  _can_param_msg_buf_2 = CONCAT13((char)((_can_priority_dm983 & 7) << 2),0xf00300);
  _can_param_msg_buf_2 = CONCAT31(_can_param_msg_buf_2,j1939_source_address_primary);
  _DAT_0080305a = 3;
  _DAT_0080305c = &diagnostic_status_data;
  _DAT_00803060 = &diagnostic_buffer_unused;
  diagnosticDataBufferSetup();
  canTransmissionController();
  return;
}



//
// Function: configParamCanBuilder @ 0x0002a57e
//

void configParamCanBuilder(void)

{
  undefined1 local_6;
  undefined1 uStack_5;
  
  param_lookup_3();
  can_param_msg_buf_1 = (char)(param_table_ext >> 8) + 0x7d;
  uStack_5 = (undefined1)param_limit_value;
  DAT_00803067 = uStack_5;
  local_6 = (undefined1)(param_limit_value >> 8);
  DAT_00803068 = local_6;
  DAT_00803069 = param_config_byte;
  sendCanMessage((j1939_header_t *)&can_param_msg_buf_3);
  return;
}



//
// Function: secondaryParamPGN_65247_Builder @ 0x0002a5da
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void secondaryParamPGN_65247_Builder(void)

{
  _can_param_msg_buf_3 = CONCAT13((char)((_DAT_008037ce & 7) << 2),0xfedf00);
  _can_param_msg_buf_3 = CONCAT31(_can_param_msg_buf_3,j1939_source_address_primary);
  _DAT_00803072 = 4;
  _DAT_00803074 = &can_param_msg_buf_1;
  _DAT_00803078 = 0x80307c;
  return;
}



//
// Function: FUN_0002a61e @ 0x0002a61e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte FUN_0002a61e(void)

{
  byte bVar1;
  ushort uVar2;
  word *pwVar3;
  undefined2 local_6;
  
  bVar1 = DAT_008030a8 & 0xf0;
  if (bVar1 == 0) {
    FUN_0000d984();
    local_6._1_1_ = (undefined1)_DAT_0080d092;
    DAT_0080307e = (undefined1)local_6;
    local_6._0_1_ = (undefined1)((ushort)_DAT_0080d092 >> 8);
    DAT_0080307f = local_6._0_1_;
    DAT_00803080 = (char)(param_table_calc >> 8) + '}';
    local_6._1_1_ = (undefined1)_DAT_0080cfe8;
    DAT_00803081 = (undefined1)local_6;
    local_6._0_1_ = (undefined1)((ushort)_DAT_0080cfe8 >> 8);
    DAT_00803082 = local_6._0_1_;
    DAT_00803083 = (char)(calculated_2 >> 8) + '}';
    local_6._1_1_ = (undefined1)_DAT_008086c6;
    DAT_00803084 = (undefined1)local_6;
    local_6._0_1_ = (undefined1)((ushort)_DAT_008086c6 >> 8);
    DAT_00803085 = local_6._0_1_;
    DAT_00803086 = (char)(calculated_3 >> 8) + '}';
    local_6._1_1_ = (undefined1)_DAT_008086c8;
    DAT_00803087 = (undefined1)local_6;
    local_6._0_1_ = (undefined1)((ushort)_DAT_008086c8 >> 8);
    DAT_00803088 = local_6._0_1_;
    DAT_00803089 = (char)(calculated_4 >> 8) + '}';
    local_6._1_1_ = (undefined1)_DAT_0080cfea;
    DAT_0080308a = (undefined1)local_6;
    local_6._0_1_ = (undefined1)((ushort)_DAT_0080cfea >> 8);
    DAT_0080308b = local_6._0_1_;
    DAT_0080308c = (char)(result_buffer >> 8) + '}';
    if (_DAT_0080cc58 == 0) {
      local_6 = _arbitrated_fuel_limit;
    }
    else {
      local_6 = (short)(((uint)_DAT_0080cc58 * ((uint)_DAT_0080cc56 - (uint)param_ref_base)) /
                       0x1111) - (_DAT_0080cc54 - _arbitrated_fuel_limit);
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
    local_6._1_1_ = (undefined1)_diagnostic_mode_parameter;
    DAT_00803093 = (undefined1)local_6;
    local_6._0_1_ = (undefined1)((ushort)_diagnostic_mode_parameter >> 8);
    DAT_00803094 = local_6._0_1_;
    DAT_00803095 = (undefined1)(_DAT_008086e6 / 10);
    DAT_00803096 = (undefined1)(_DAT_00808836 / 0x50);
    if (allowed_rate_of_torque_limit_change_0_2000 < 0x4e21) {
      DAT_00803097 = (undefined1)(allowed_rate_of_torque_limit_change_0_2000 / 0x50);
    }
    else {
      DAT_00803097 = 0x20;
    }
    uVar2 = param_table_calc;
    for (pwVar3 = &calculated_2; pwVar3 < (ushort *)((int)&result_buffer + 1); pwVar3 = pwVar3 + 1)
    {
      if (uVar2 < *pwVar3) {
        uVar2 = *pwVar3;
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
  _DAT_0080309a = CONCAT31(_DAT_0080309a,j1939_source_address_primary);
  _DAT_0080309e = 0x1c;
  _DAT_008030a0 = &DAT_0080307e;
  _DAT_008030a4 = &DAT_008030a8;
  DAT_0080308f = 0xff;
  DAT_00803090 = 0xff;
  DAT_00803098 = 0x7d;
  FUN_0000dbc2();
  return;
}



//
// Function: FUN_0002a856 @ 0x0002a856
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002a856(void)

{
  coolant_level = (byte)((int)((uint)(((int)(uint)_DAT_008092b0 >> 7) * 0x1afa) / 1000) >> 1);
  engine_oil_level = (byte)((int)((uint)(((int)(uint)_DAT_00809242 >> 7) * 0x1afa) / 1000) >> 2);
  sendCanMessage((j1939_header_t *)&engine_fluid_level_msg_header);
  return;
}



//
// Function: engineFluidLevelPGN_65263_Builder @ 0x0002a8da
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engineFluidLevelPGN_65263_Builder(void)

{
  engine_fluid_level_msg_header = CONCAT13((char)((_DAT_008037d2 & 7) << 2),0xfeef00);
  engine_fluid_level_msg_length = 8;
  engine_fluid_level_data_ptr = (dword)&fuel_delivery_pressure;
  engine_fluid_level_unused_ptr = (dword)&engine_fluid_level_buffer_end;
  engine_fluid_level_msg_header =
       CONCAT31(engine_fluid_level_msg_header._0_3_,j1939_source_address_primary);
  fuel_delivery_pressure = 0xff;
  coolant_pressure = 0xffff;
  extended_crankcase_pressure = 0xff;
  engine_oil_pressure = 0xff;
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
    engine_temp_processed1 = 0;
  }
  else if (sVar2 < 0xd2) {
    local_6._1_1_ = (char)iVar1;
    engine_temp_processed1 = (char)local_6 + 0x28;
  }
  else {
    engine_temp_processed1 = 0xfa;
  }
  iVar1 = ((short)(_DAT_00809200 + -0x1900 >> 7) * 5 + -0xa0) / 9;
  sVar2 = (short)iVar1;
  if (sVar2 < -0x28) {
    engine_temp_processed2 = 0;
  }
  else if (sVar2 < 0xd2) {
    local_6._1_1_ = (char)iVar1;
    engine_temp_processed2 = (char)local_6 + 0x28;
  }
  else {
    engine_temp_processed2 = 0xfa;
  }
  local_6 = (short)(((short)(_DAT_008092b0 + -0x1900 >> 7) * 5 + -0xa0) / 9);
  if (local_6 < -0x111) {
    engine_fluid_calc_result = 0;
  }
  else if (local_6 < 0x6c7) {
    local_6 = (local_6 + 0x111) * 0x20;
    engine_fluid_calc_result = FUN_0001bc52(&local_6);
  }
  else {
    local_6 = -0x500;
    engine_fluid_calc_result = FUN_0001bc52(&local_6);
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
  _DAT_008030c8 = &engine_temp_processed1;
  _DAT_008030cc = 0x8030d8;
  _DAT_008030c2 = CONCAT31(_DAT_008030c2,j1939_source_address_primary);
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
  if ((_diagnostic_system_flags_2 & 0x1000) == 0) {
    torque_control_status_byte = 0;
  }
  else {
    torque_control_status_byte = 0x40;
  }
  if (_DAT_008096a0 != 0) {
    torque_control_status_byte = torque_control_status_byte | 0x10;
  }
  switch(_DAT_008096a2) {
  case 1:
  case 4:
    if (_DAT_008096b0 == 1) {
      torque_control_status_byte = torque_control_status_byte | 6;
    }
    else if (_DAT_008096b0 == 3) {
      torque_control_status_byte = torque_control_status_byte | 5;
    }
    else if (_DAT_008096b0 == 2) {
      torque_control_status_byte = torque_control_status_byte | 7;
    }
    else {
      torque_control_status_byte = torque_control_status_byte | 0xe;
    }
    break;
  case 2:
    torque_control_status_byte = torque_control_status_byte | 2;
    break;
  case 3:
    torque_control_status_byte = torque_control_status_byte | 1;
  }
  if (_DAT_008037d4 == 0) {
    torque_control_data_byte2 = 0xff;
  }
  else {
    FUN_0000dc28();
    torque_control_data_byte2 = 0x7d - (char)((ushort)_DAT_00809d40 >> 8);
  }
  sendCanMessage((j1939_header_t *)&cummins_tsc_msg_header);
  return;
}



//
// Function: cumminsProprietaryTSC_PGN_15728640_Builder @ 0x0002aba4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cumminsProprietaryTSC_PGN_15728640_Builder(void)

{
  cummins_tsc_msg_header = CONCAT13((char)((_DAT_008037d6 & 7) << 2),0xf00000);
  cummins_tsc_msg_header = CONCAT31(cummins_tsc_msg_header._0_3_,j1939_source_address_secondary);
  FUN_0000dd72();
  cummins_tsc_msg_length = 2;
  cummins_tsc_data_ptr = (dword)&torque_control_status_byte;
  cummins_tsc_unused_ptr = (dword)&torque_control_buffer_end;
  return;
}



//
// Function: FUN_0002abf2 @ 0x0002abf2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002abf2(void)

{
  uint local_8;
  
  local_8 = FUN_000357d2(_DAT_00804bbc,0x39c2c3,1000000);
  local_8 = FUN_000357d2(local_8,2,8);
  _DAT_00803100 = FUN_0001bc1e(&local_8);
  local_8 = _DAT_00804bb8 >> 2;
  local_8 = FUN_000357d2(local_8,0x39c2c3,1000000);
  _DAT_00803104 = FUN_0001bc1e(&local_8);
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
  _DAT_008030f2 = CONCAT31(_DAT_008030f2,j1939_source_address_primary);
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
  byte local_6;
  byte bStack_5;
  
  uVar1 = FUN_000357d2((uint)_DAT_0080d478,0xe10,8000);
  uVar1 = uVar1 / 10;
  if (0xc8c < uVar1) {
    uVar1 = 0xc8c;
  }
  sVar2 = (short)uVar1 * 0x14;
  bStack_5 = (byte)sVar2;
  fuel_economy_data_byte1 = bStack_5;
  local_6 = (byte)((ushort)sVar2 >> 8);
  fuel_economy_data_byte2 = local_6;
  uVar1 = ((uint)_DAT_00804bc8 * 0x2136) / 10000;
  bStack_5 = (byte)uVar1;
  fuel_economy_data_byte3 = bStack_5;
  local_6 = (byte)(uVar1 >> 8);
  fuel_economy_data_byte4 = local_6;
  uVar1 = ((uint)_DAT_00804bca * 0x2136) / 10000;
  bStack_5 = (byte)uVar1;
  fuel_economy_data_byte5 = bStack_5;
  local_6 = (byte)(uVar1 >> 8);
  fuel_economy_data_byte6 = local_6;
  sendCanMessage((j1939_header_t *)&fuel_economy_msg_header);
  return;
}



//
// Function: fuelEconomyPGN_65266_Builder @ 0x0002ada8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fuelEconomyPGN_65266_Builder(void)

{
  fuel_economy_msg_header = CONCAT13((char)((_DAT_008037dc & 7) << 2),0xfef200);
  fuel_economy_msg_header = CONCAT31(fuel_economy_msg_header._0_3_,j1939_source_address_primary);
  fuel_economy_msg_length = 6;
  fuel_economy_data_ptr = (dword)&fuel_economy_data_byte1;
  fuel_economy_unused_ptr = (dword)&fuel_economy_buffer_end;
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
  local_8 = FUN_000357d2(local_8,0x39c2c3,1000000);
  _DAT_00803136 = FUN_0001bc1e(&local_8);
  local_8 = FUN_000357d2(_DAT_00804bcc,0x14,0x40);
  _DAT_0080313a = FUN_0001bc1e(&local_8);
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
  _DAT_00803128 = CONCAT31(_DAT_00803128,j1939_source_address_primary);
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
  _DAT_00803140 = CONCAT31(_DAT_00803140,j1939_source_address_primary);
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
  DAT_00803167 = (undefined1)((short)(((_diagnostic_sensor_reading >> 7) * 0x1afa) / 1000) >> 1);
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
  _DAT_00803158 = CONCAT31(_DAT_00803158,j1939_source_address_primary);
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
  _DAT_00803170 = CONCAT31(_DAT_00803170,j1939_source_address_primary);
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
  byte local_6;
  byte bStack_5;
  
  bVar1 = retarder_config_buffer_end & 0xf0;
  if (bVar1 == 0) {
    if (_DAT_008037d4 == 3) {
      retarder_steps_at_idle = 0x14;
    }
    else {
      retarder_steps_at_idle = 3;
    }
    if (_DAT_008037d4 == 0) {
      retarder_percent_torque_idle = 0xff;
    }
    else if (_DAT_008037d4 == 1) {
      retarder_percent_torque_idle = 3;
    }
    else {
      retarder_percent_torque_idle = 2;
    }
    bStack_5 = (byte)_DAT_0080894e;
    retarder_speed_point2_low = bStack_5;
    local_6 = (byte)((ushort)_DAT_0080894e >> 8);
    retarder_speed_point2_high = local_6;
    retarder_percent_torque_point2 = 0x7d - (char)((ushort)_DAT_00808956 >> 8);
    bStack_5 = (byte)_DAT_0080895e;
    retarder_speed_point3_low = bStack_5;
    local_6 = (byte)((ushort)_DAT_0080895e >> 8);
    retarder_speed_point3_high = local_6;
    retarder_percent_torque_point3 = 0x7d - (char)((ushort)_DAT_00808958 >> 8);
    bStack_5 = (byte)_DAT_00808952;
    retarder_speed_point4_low = bStack_5;
    local_6 = (byte)((ushort)_DAT_00808952 >> 8);
    retarder_speed_point4_high = local_6;
    retarder_percent_torque_point4 = 0x7d - (char)((ushort)_DAT_0080895a >> 8);
    bStack_5 = (byte)_DAT_00808954;
    retarder_speed_point5_low = bStack_5;
    local_6 = (byte)((ushort)_DAT_00808954 >> 8);
    retarder_speed_point5_high = local_6;
    retarder_percent_torque_point5 = 0x7d - (char)((ushort)_DAT_0080895c >> 8);
    bStack_5 = (byte)_DAT_00808950;
    retarder_reference_torque_low = bStack_5;
    local_6 = (byte)((ushort)_DAT_00808950 >> 8);
    retarder_reference_torque_high = local_6;
    bStack_5 = (byte)_DAT_0080894a;
    retarder_config_byte17 = bStack_5;
    local_6 = (byte)((ushort)_DAT_0080894a >> 8);
    retarder_config_byte18 = local_6;
    bVar1 = sendCanMessage((j1939_header_t *)&retarder_config_msg_header);
  }
  return bVar1;
}



//
// Function: retarderConfigPGN_65249_Builder @ 0x0002b1f6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void retarderConfigPGN_65249_Builder(void)

{
  retarder_config_msg_header = CONCAT13((char)((_DAT_008037e8 & 7) << 2),0xfee100);
  retarder_config_msg_header =
       CONCAT31(retarder_config_msg_header._0_3_,j1939_source_address_secondary);
  retarder_config_msg_length = 0x12;
  retarder_config_data_ptr = (dword)&retarder_steps_at_idle;
  retarder_config_unused_ptr = (dword)&retarder_config_buffer_end;
  return;
}



//
// Function: FUN_0002b23a @ 0x0002b23a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b23a(void)

{
  undefined4 local_8;
  
  local_8 = FUN_000357d2(_DAT_00804bc4,0x3268,10000);
  _DAT_008031b8 = FUN_0001bc1e(&local_8);
  local_8 = FUN_000357d2(_DAT_00804bc0,0x3268,10000);
  _DAT_008031bc = FUN_0001bc1e(&local_8);
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
  _DAT_008031aa = CONCAT31(_DAT_008031aa,j1939_source_address_primary);
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
  _DAT_008031d6 = FUN_0001bc52(&local_6);
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
  _DAT_008031c2 = CONCAT31(_DAT_008031c2,j1939_source_address_primary);
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
  
  local_8 = FUN_000357d2(_DAT_00804bd8,0x14,0x40);
  _DAT_008031e8 = FUN_0001bc1e(&local_8);
  local_8 = FUN_000357d2(_DAT_00804bd4,0x14,0x40);
  _DAT_008031ec = FUN_0001bc1e(&local_8);
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
  _DAT_008031da = CONCAT31(_DAT_008031da,j1939_source_address_primary);
  canTransmissionController();
  return;
}



//
// Function: incrementCounters @ 0x0002b452
//

void incrementCounters(void)

{
  loopCounter = loopCounter + 1;
  if (engine_operating_mode != IDLE) {
    engineRunCounter = engineRunCounter + 1;
  }
  return;
}



//
// Function: FUN_0002b46a @ 0x0002b46a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b46a(void)

{
  loopCounter = _DAT_0080352c;
  return;
}



//
// Function: FUN_0002b476 @ 0x0002b476
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b476(void)

{
  if ((diagnostic_status_register == 0) && (_fuel_arbitrator_condition_flag == 2)) {
    diagnostic_status_register = 1;
    cached_parameter_value = _DAT_0080d010;
  }
  return;
}



//
// Function: FUN_0002b49a @ 0x0002b49a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b49a(void)

{
  if ((diagnostic_status_register == 0) && ((_DAT_008035dc & 1) != 0)) {
    diagnostic_status_register = 5;
    cached_parameter_value = _DAT_0080381c;
  }
  return;
}



//
// Function: engine_protection_coordinator @ 0x0002b4c2
//

void engine_protection_coordinator(void)

{
  word wVar1;
  undefined4 unaff_D2;
  word wVar2;
  undefined2 uVar3;
  
  wVar1 = diagnostic_status_register;
  uVar3 = (undefined2)((uint)unaff_D2 >> 0x10);
  diagnostic_status_register = 0;
  FUN_0000be7c();
  FUN_0002b476();
  wVar2 = wVar1;
  FUN_0000be96(CONCAT22(wVar1,uVar3));
  FUN_0002b49a();
  FUN_0001e2d2(CONCAT22(wVar1,wVar2));
  FUN_0000c084(CONCAT22(wVar1,wVar2));
  FUN_000181bc();
  return;
}



//
// Function: FUN_0002b4fe @ 0x0002b4fe
//

void FUN_0002b4fe(void)

{
  FUN_0000c100();
  FUN_0001e358();
  FUN_00025fda();
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
  
  if ((char)time_fault_conditions_must_exist_before_logging_a_throttle_faul_0_2000 == '\0') {
    _DAT_00808ec2 = &LAB_00015946;
    can1_cantxerr = can1_cantxerr & 0xfff0 | 0xc;
    _DAT_00ffff04 = _DAT_00807cd6 / 6;
    _DAT_00ffff02 = 0xe;
    _DAT_00ffff00 = 0xb;
    can1_canidar1 = can1_canidar1 & 0xfffc | 1;
    can1_canidar3 = can1_canidar3 & 0xfffc | 1;
    can1_canidmr1 = can1_canidmr1 & 0xfffc | 2;
    can1_cantbsel = can1_cantbsel & 0xfffe | 1;
    can1_canidmr2 = can1_canidmr2 & 0xfffe;
    return;
  }
  if ((char)time_fault_conditions_must_exist_before_logging_a_throttle_faul_0_2000 != '\x01') {
    return;
  }
  DAT_0080d49e = DAT_00808a78 + -1;
  iVar1 = 0;
  iVar2 = 0;
  uVar3 = (uint)intake_manifold_temperature_at_maximum_fueling_condition_50_293._0_1_;
  piVar4 = (int *)&DAT_0080d4a8;
  do {
    *piVar4 = iVar2 / 6;
    iVar2 = uVar3 * 0x10000 + iVar2;
    iVar1 = iVar1 + 1;
    piVar4 = piVar4 + 1;
  } while (iVar1 < 6);
  _DAT_0080d4a4 =
       (uint)intake_manifold_temperature_at_maximum_fueling_condition_50_293._0_1_ << 0x10;
  FUN_0002b880();
  return;
}



//
// Function: FUN_0002b6c2 @ 0x0002b6c2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b6c2(void)

{
  if ((char)time_fault_conditions_must_exist_before_logging_a_throttle_faul_0_2000 == '\0') {
    can1_canidmr2 = can1_canidmr2 & 0xfffe;
    can1_cantxerr = can1_cantxerr & 0xfff0 | 0xc;
    _DAT_00ffff04 = 1;
    _DAT_00ffff02 = 0xe;
    _DAT_00ffff00 = 0xb;
    can1_canidar1 = can1_canidar1 & 0xfffc | 1;
    can1_canidar3 = can1_canidar3 & 0xfffc | 1;
    can1_cantbsel = can1_cantbsel & 0xfffe | 1;
    can1_canidmr1 = can1_canidmr1 & 0xfffc | 2;
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
          _user_specified_number_of_engine_data_samples_taken_by_trending_f_0_100 +
          _enable_flag_that_indicates_presence_of_an_ambient_air_press_true_false +
          *(int *)(&DAT_0080d4a8 + (short)(ushort)(byte)(DAT_00808a78 - 1U) * 4) + 0x100;
  uVar3 = (iVar1 >> 0x10 & 0xffffU) %
          (maximum_allowed_timing_advance_for_this_algorithm_0_20._0_1_ + 2);
  _DAT_00ffff38 = (ushort)uVar3;
  uVar2 = (ushort)(iVar1 >> 1) & 0x7f00;
  if (uVar3 == maximum_allowed_timing_advance_for_this_algorithm_0_20._0_1_ + 1) {
    _DAT_00ffff38 = _DAT_00ffff38 - 1 | uVar2 | 0x8000;
  }
  else {
    _DAT_00ffff38 = _DAT_00ffff38 | uVar2;
  }
  uVar3 = (_time_that_trigger_must_be_satisfied_to_allow_trending_data_co_0_3600 + iVar1 >> 0x10 &
          0xffffU) % (maximum_allowed_timing_advance_for_this_algorithm_0_20._0_1_ + 2);
  _DAT_00ffff3a = (ushort)uVar3;
  uVar2 = (ushort)(_time_that_trigger_must_be_satisfied_to_allow_trending_data_co_0_3600 + iVar1 >>
                  1) & 0x7f00;
  if (maximum_allowed_timing_advance_for_this_algorithm_0_20._0_1_ + 1 == uVar3) {
    _DAT_00ffff3a = _DAT_00ffff3a - 1 | uVar2 | 0x8000;
  }
  else {
    _DAT_00ffff3a = _DAT_00ffff3a | uVar2;
  }
  can1_canidmr2 = can1_canidmr2 & 0xfff7;
  can1_cantxerr = can1_cantxerr & 0xfff | 0x8000;
  _DAT_00ffff30 = 0x880;
  can1_canidar1 = can1_canidar1 & 0xff3f;
  can1_canidar3 = can1_canidar3 & 0xff3f | 0x80;
  can1_canidmr1 = can1_canidmr1 & 0xff3f | 0x40;
  can1_cantbsel = can1_cantbsel & 0xfff7 | 8;
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
          _user_specified_number_of_engine_data_samples_taken_by_trending_f_0_100 +
          _enable_flag_that_indicates_presence_of_an_ambient_air_press_true_false +
          *(int *)(&DAT_0080d4a8 + (short)(ushort)DAT_0080d49e * 4) + 0x100;
  uVar3 = (iVar1 >> 0x10 & 0xffffU) %
          (maximum_allowed_timing_advance_for_this_algorithm_0_20._0_1_ + 2);
  _DAT_00ffff38 = (ushort)uVar3;
  uVar2 = (ushort)(iVar1 >> 1) & 0x7f00;
  if (uVar3 == maximum_allowed_timing_advance_for_this_algorithm_0_20._0_1_ + 1) {
    _DAT_00ffff38 = _DAT_00ffff38 - 1 | uVar2 | 0x8000;
  }
  else {
    _DAT_00ffff38 = _DAT_00ffff38 | uVar2;
  }
  uVar3 = (_time_that_trigger_must_be_satisfied_to_allow_trending_data_co_0_3600 + iVar1 >> 0x10 &
          0xffffU) % (maximum_allowed_timing_advance_for_this_algorithm_0_20._0_1_ + 2);
  _DAT_00ffff3a = (ushort)uVar3;
  uVar2 = (ushort)(_time_that_trigger_must_be_satisfied_to_allow_trending_data_co_0_3600 + iVar1 >>
                  1) & 0x7f00;
  if (maximum_allowed_timing_advance_for_this_algorithm_0_20._0_1_ + 1 == uVar3) {
    _DAT_00ffff3a = _DAT_00ffff3a - 1 | uVar2 | 0x8000;
  }
  else {
    _DAT_00ffff3a = _DAT_00ffff3a | uVar2;
  }
  can1_canidmr2 = can1_canidmr2 & 0xfff7;
  can1_cantxerr = can1_cantxerr & 0xfff | 0x8000;
  _DAT_00ffff30 = 0x880;
  can1_canidar1 = can1_canidar1 & 0xff3f;
  can1_canidar3 = can1_canidar3 & 0xff3f | 0x80;
  can1_canidmr1 = can1_canidmr1 & 0xff3f | 0x40;
  _DAT_00808ece = FUN_0002ba56;
  can1_cantbsel = can1_cantbsel & 0xfff7 | 8;
  return;
}



//
// Function: FUN_0002b9b8 @ 0x0002b9b8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b9b8(void)

{
  if ((char)time_fault_conditions_must_exist_before_logging_a_throttle_faul_0_2000 == '\0') {
    _DAT_00ffff04 = _DAT_00807cd6 / 6;
    can1_cantbsel = can1_cantbsel & 0xfff7;
    can1_canidmr2 = can1_canidmr2 & 0xfff7;
    can1_cantxerr = can1_cantxerr & 0xfff | 0xa000;
    _DAT_00ffff34 = 0;
    _DAT_00ffff38 = 0x19b;
    _DAT_00ffff30 = 0x8e;
    can1_canidar1 = can1_canidar1 & 0xff3f;
    can1_canidar3 = can1_canidar3 & 0xff3f | 0x80;
    can1_canidmr1 = can1_canidmr1 & 0xff3f | 0x40;
  }
  if ((DAT_0080c79b != '\0') &&
     ((char)time_fault_conditions_must_exist_before_logging_a_throttle_faul_0_2000 == '\x01')) {
    FUN_0002b744();
  }
  return;
}



//
// Function: FUN_0002ba56 @ 0x0002ba56
//

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
  can1_canidmr2 = can1_canidmr2 & 0xfff7;
  return CONCAT44(in_D0,in_D1);
}



//
// Function: FUN_0002baf0 @ 0x0002baf0
//

void FUN_0002baf0(undefined4 param_1)

{
  while (param_1._0_2_ != 0) {
    REG_SIM_SWSR = 0xaa;
    DAT_00ffd00f = 0xaa;
  }
  return;
}



//
// Function: FUN_0002bb2e @ 0x0002bb2e
//

void FUN_0002bb2e(undefined4 param_1)

{
  while (param_1._0_2_ != 0) {
    REG_SIM_SWSR = 0xaa;
    DAT_00ffd00f = 0xaa;
  }
  return;
}



//
// Function: FUN_0002bb6c @ 0x0002bb6c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002bb6c(void)

{
  _DAT_008031f6 = 2;
  _DAT_008031f8 = &lower_limit_at_which_loading_trigger_is_satisfied_in_trendin_0_127_5;
  _DAT_008031fc = _DAT_008091ea;
  _DAT_008031fe = &count_minimum_for_percent_load_to_be_low_0_100;
  if (upper_limit_at_which_loading_trigger_is_satisfied_in_trendin_0_127_5 <
      _current_fuel_demand_value) {
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
// Function: FUN_0002bbc0 @ 0x0002bbc0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002bbc0(void)

{
  if (upper_limit_at_which_loading_trigger_is_satisfied_in_trendin_0_127_5 <
      _current_fuel_demand_value) {
    _DAT_0080d4c0 = 0;
    return;
  }
  _DAT_0080d4c0 = current_engine_rpm / _DAT_00808a82 + _DAT_008031f4 + -0xc4;
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
  _DAT_0080d4c2 = _DAT_0080c9ae;
  if (_DAT_0080c9ae < _DAT_0080d4c0) {
    _DAT_0080c9ae = _DAT_0080d4c0;
    _DAT_0080c9b0 = 1;
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
  
  uVar1 = vp44_status_flags_2 & 0x80;
  if ((((vp44_status_flags_2 & 0x80) != 0) && (uVar1 = DAT_0080bdc7 & 2, (DAT_0080bdc7 & 2) == 0))
     && (uVar1 = _rpm_derate_timer,
        _rpm_derate_timer <= time_duration_from_overlimit_reached_to_starting_rpm_derate_0_65535)) {
    _rpm_derate_timer = time_duration_from_overlimit_reached_to_starting_rpm_derate_0_65535;
    _rpm_derate_status = 0;
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
    _diagnostic_mode_buffer = diagnostic_state_buffer_t_00809654.diagnostic_mode;
  }
  switch(diagnostic_state_buffer_t_00809654.diagnostic_mode) {
  case 9:
    if ((_protection_system_enable_flag == 0) ||
       ((((_current_fuel_demand_value <
           amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535 &&
          (amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535 < _DAT_00809696)) &&
         ((amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535 < _DAT_00809694 &&
          (_active_derate_value != 0)))) ||
        (((delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535 == 2 ||
          (delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535 == 1)) ||
         (delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535 == 5)))))) {
      _diagnostic_rpm_threshold_status =
           amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535;
      diagnostic_state_buffer_t_00809654.diagnostic_mode =
           delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535;
      return;
    }
    if ((current_engine_rpm <= _DAT_0080d092) &&
       ((uint)_DAT_00803820 + (uint)_target_boost_pressure_base < (uint)_boost_pressure_feedback)) {
      diagnostic_state_buffer_t_00809654.diagnostic_mode = 0xb;
      _DAT_0080966a = 1;
      FUN_0001e78e();
    }
    if ((((_DAT_00809696 == _DAT_00809698) &&
         (((_current_fuel_demand_value <=
            amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535 &&
           (0xc < _active_derate_value)) ||
          (_boost_pressure_max_target <= _target_boost_pressure_base)))) ||
        (_DAT_00809696 < _DAT_00809698)) &&
       ((_DAT_00809696 < _DAT_00809694 && (_DAT_00809696 < _diagnostic_rpm_threshold_status)))) {
      diagnostic_state_buffer_t_00809654.diagnostic_mode = 10;
      FUN_0002d210();
      return;
    }
    if ((((_DAT_00809694 < _diagnostic_rpm_threshold_status) ||
         (_DAT_00809694 <= amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535)) &&
        (_DAT_00809694 < _DAT_00809696)) && (_DAT_00809694 < _DAT_00809698)) {
      diagnostic_state_buffer_t_00809654.diagnostic_mode = 0xc;
      return;
    }
    break;
  case 10:
    if (((((current_engine_rpm < 8000) ||
          (delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535 == 2)) ||
         (delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535 == 1)) ||
        (_DAT_008096aa != 0)) ||
       ((amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535 <
         _current_fuel_demand_value &&
        (((_protection_system_enable_flag == 0 || (_diagnostic_mode_buffer == 7)) ||
         ((_diagnostic_mode_buffer == 8 ||
          (delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535 == 5)))))))) {
      _diagnostic_rpm_threshold_status =
           amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535;
      diagnostic_state_buffer_t_00809654.diagnostic_mode =
           delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535;
      return;
    }
    if ((_DAT_00809694 < _diagnostic_rpm_threshold_status) && (_DAT_00809694 <= _DAT_00809696)) {
      diagnostic_state_buffer_t_00809654.diagnostic_mode = 0xc;
      return;
    }
    if ((((((_protection_system_enable_flag != 0) && (_diagnostic_mode_buffer == 9)) &&
          (amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535 <
           _current_fuel_demand_value)) &&
         ((_DAT_00809698 < _DAT_00809696 ||
          ((_DAT_00809698 == _DAT_00809696 &&
           (_target_boost_pressure_base < _boost_pressure_max_target)))))) &&
        (_DAT_00809698 < _DAT_00809694)) && (_DAT_00809698 < _diagnostic_rpm_threshold_status)) {
      diagnostic_state_buffer_t_00809654.diagnostic_mode = 9;
      FUN_0002d210();
      return;
    }
    break;
  case 0xb:
    if ((((uint)amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535 <=
          _diagnostic_rpm_threshold_status + 0xe) &&
        (((uint)current_engine_rpm <=
          (uint)time_duration_to_warn_driver_before_shutdown_due_to_intake_t_0_65535 +
          (uint)_DAT_0080d092 || (_active_derate_value != 0)))) ||
       (((_DAT_0080c99c != 0 ||
         ((_active_derate_value == 0 &&
          (((delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535 == 7 ||
            (delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535 == 8)) &&
           (_protection_system_enable_flag == 0)))))) ||
        ((_fuel_arbitrator_condition_flag == 3 &&
         (_DAT_0080d00e <= _diagnostic_rpm_threshold_status)))))) {
      if ((_protection_system_enable_flag != 0) &&
         ((((uint)_boost_pressure_feedback < (uint)_DAT_00803820 + (uint)_target_boost_pressure_base
           || ((uint)time_duration_to_warn_driver_before_shutdown_due_to_intake_t_0_65535 +
               (uint)_DAT_0080d092 < (uint)current_engine_rpm)) &&
          ((_DAT_0080c99c == 0 &&
           ((_fuel_arbitrator_condition_flag != 3 ||
            (_diagnostic_rpm_threshold_status < _DAT_0080d00e)))))))) {
        diagnostic_state_buffer_t_00809654.diagnostic_mode = 9;
        FUN_0002d210();
      }
      _DAT_00803202 = 0;
      return;
    }
    _DAT_00803202 = _DAT_00803202 + 1;
    if (_DAT_00806e1e == 0) {
      _diagnostic_rpm_threshold_status =
           amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535;
      diagnostic_state_buffer_t_00809654.diagnostic_mode =
           delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535;
      _DAT_00803202 = 0;
      return;
    }
    if (_DAT_00803202 == _DAT_00806e1e) {
      _diagnostic_rpm_threshold_status =
           amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535;
      diagnostic_state_buffer_t_00809654.diagnostic_mode =
           delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535;
      _DAT_00803202 = 0;
      return;
    }
    break;
  case 0xc:
    if ((amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535 <
         _diagnostic_rpm_threshold_status) &&
       (((_protection_system_enable_flag == 0 ||
         (delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535 == 2)) ||
        (((delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535 == 1 ||
          ((delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535 == 5 ||
           (_diagnostic_mode_buffer == 7)))) || (_diagnostic_mode_buffer == 8)))))) {
      _DAT_00803204 = _DAT_00803204 + 1;
      if (_DAT_00806e1c == 0) {
        _diagnostic_rpm_threshold_status =
             amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535;
        diagnostic_state_buffer_t_00809654.diagnostic_mode =
             delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535;
        _DAT_00803204 = 0;
        return;
      }
      if (_DAT_00803204 == _DAT_00806e1c) {
        _diagnostic_rpm_threshold_status =
             amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535;
        diagnostic_state_buffer_t_00809654.diagnostic_mode =
             delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535;
        _DAT_00803204 = 0;
        return;
      }
    }
    else {
      _DAT_00803204 = 0;
      if ((_DAT_00809696 < _diagnostic_rpm_threshold_status) && (_DAT_00809696 < _DAT_00809694)) {
        diagnostic_state_buffer_t_00809654.diagnostic_mode = 10;
        FUN_0002d210();
        return;
      }
      if ((((amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535 <=
             _current_fuel_demand_value) && (_diagnostic_mode_buffer == 9)) &&
          (_DAT_00809698 < _diagnostic_rpm_threshold_status)) &&
         ((_DAT_00809698 < _DAT_00809694 && (_protection_system_enable_flag != 0)))) {
        diagnostic_state_buffer_t_00809654.diagnostic_mode = 9;
        FUN_0002d210();
        return;
      }
    }
    break;
  default:
    if (((current_engine_rpm <= _DAT_0080d092) &&
        (_diagnostic_rpm_threshold_status < eps_backup_lost_duration_0_20)) ||
       ((((uint)current_engine_rpm <= (uint)_DAT_00806e1a + (uint)_DAT_0080d092 &&
         ((_active_derate_value == 0 &&
          (_diagnostic_rpm_threshold_status < eps_backup_lost_duration_0_20)))) &&
        ((delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535 == 7 ||
         (delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535 == 8)))))) {
      diagnostic_state_buffer_t_00809654.diagnostic_mode = 0xb;
      _DAT_0080966a = 1;
      FUN_0001e78e();
      return;
    }
    if ((_DAT_00809694 <= amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535) &&
       (_DAT_00809694 <= _DAT_00809696)) {
      diagnostic_state_buffer_t_00809654.diagnostic_mode = 0xc;
      FUN_0001883a();
      return;
    }
    if ((((_DAT_00809696 < amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535) &&
         (_DAT_00809696 <= _DAT_00809694)) && (7999 < current_engine_rpm)) &&
       (((_DAT_008096aa == 0 &&
         (delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535 != 2)) &&
        (delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535 != 1)))) {
      diagnostic_state_buffer_t_00809654.diagnostic_mode = 10;
      FUN_0002d210();
      return;
    }
    if (((_protection_system_enable_flag != 0) &&
        (amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535 <= _DAT_00809698)) &&
       ((amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535 <=
         _current_fuel_demand_value &&
        (((delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535 != 2 &&
          (delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535 != 1)) &&
         (delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535 != 5)))))) {
      diagnostic_state_buffer_t_00809654.diagnostic_mode = 9;
      FUN_0002d210();
      return;
    }
    _diagnostic_rpm_threshold_status =
         amount_of_time_over_oil_pressure_rpm_shutdown_threshold_0_65535;
    diagnostic_state_buffer_t_00809654.diagnostic_mode =
         delay_before_warning_about_shutdown_from_oil_press_fuel_0_65535;
  }
  return;
}



//
// Function: FUN_0002c240 @ 0x0002c240
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002c240(void)

{
  diagnostic_state_buffer_t_00809654.diagnostic_mode = 0xb;
  _diagnostic_mode_buffer = 7;
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
  
  if (_DAT_0080c7ca < _software_padding_0_255) {
    _DAT_00809692 = shutdown_threshold_for_intake_temp_rpm_0_65535;
  }
  else {
    _DAT_00809692 = fault_index_indicating_epf_imt_rpm_error_found_0_ffff + _DAT_00809692;
    if (shutdown_threshold_for_intake_temp_fuel_0_65535 < _DAT_00809692) {
      _DAT_00809692 = shutdown_threshold_for_intake_temp_fuel_0_65535;
    }
  }
  if (_protection_system_enable_flag == 0) {
    if (_DAT_0080968c < time_to_reach_full_derate_during_intake_temp_engine_prote_0_0039_256) {
      _DAT_0080968c = _DAT_0080968c + 1;
    }
  }
  else {
    _DAT_0080968c = 0;
  }
  if (_DAT_00809690 < _DAT_008096a6) {
    _DAT_00809690 = coreTableInterpolation();
  }
  if ((determines_how_engine_position_is_sync_d_to_cam_0 <= _DAT_0080c7c8) &&
     (time_to_reach_full_derate_during_intake_temp_engine_prote_0_0039_256 <= _DAT_0080968c)) {
    _DAT_00809690 = _DAT_008096a6;
  }
  if ((_DAT_00803210 == 2) && (_oil_pressure_mode_selector == 0)) {
    _DAT_00809690 = _DAT_008096a6;
  }
  _DAT_00803210 = _oil_pressure_mode_selector;
  if (_protection_system_enable_flag == 0) {
    if (_DAT_00803746 < _DAT_00809690) {
      _DAT_00809690 = _DAT_00803746;
    }
  }
  else if (_target_boost_pressure_base < _DAT_00809690) {
    _DAT_00809690 = _target_boost_pressure_base;
  }
  iVar2 = rpmFuelCalculation((uint)_DAT_00803746 - (uint)_DAT_00809690,
                             (uint)
                             time_to_reach_full_derate_during_intake_temp_engine_prote_0_0039_256,
                             0x80);
  uVar4 = (uint)shutdown_delay_for_intake_temperature_shutdown_0_255 - iVar2;
  if ((int)(uint)shutdown_delay_for_intake_temperature_shutdown_0_255 < (int)uVar4) {
    uVar4 = (uint)shutdown_delay_for_intake_temperature_shutdown_0_255;
  }
  else if ((int)uVar4 < (int)(uint)delay_after_rpm_reached_before_intake_temp_errors_0_255) {
    uVar4 = (uint)delay_after_rpm_reached_before_intake_temp_errors_0_255;
  }
  _DAT_0080968e = (short)uVar4;
  sVar1 = _oil_pressure_mode_selector >> 0xf;
  if (_oil_pressure_mode_selector == 0) {
    if (((((vp44_status_flags_2 & 0x20) == 0) ||
         (_DAT_008096a8 < minimum_threshold_for_intake_temperature_rpm_limiting_50_293)) ||
        (maximum_temperature_threshold_for_imt_tvo_limiting_50_to_293 < _DAT_008096a8)) ||
       (_DAT_00809692 < _DAT_008096a6)) {
      _DAT_0080c7cc = 0;
    }
    else {
      _DAT_0080c7cc = 1;
    }
    uVar3 = (uint)_DAT_008096a6;
    if (((fault_index_indicating_epf_imt_fuel_error_found_0_ffff <= _DAT_008096a6) &&
        ((uVar3 = (uint)_DAT_00809690 - (uVar4 & 0xffff), (int)(uint)_DAT_008096a6 < (int)uVar3 ||
         (uVar3 = CONCAT22((short)(uVar3 >> 0x10),_DAT_0080c7c0),
         crank_exited_initial_fueling_offset_100_100 <= _DAT_0080c7c0)))) &&
       (uVar3 = CONCAT22((short)(uVar3 >> 0x10),_DAT_008096a8),
       _DAT_008096a8 <= rpm_to_reach_before_imt_errors_0_8000)) {
      _DAT_0080c7ce = 1;
      return uVar3;
    }
    _DAT_0080c7ce = 0;
    return uVar3;
  }
  if (_oil_pressure_mode_selector == 1) {
    uVar4 = vp44_status_flags_2 & 0x20;
    if (((vp44_status_flags_2 & 0x20) != 0) &&
       (((uVar4 = (uint)_DAT_008096a8,
         _DAT_008096a8 < minimum_threshold_for_intake_temperature_rpm_limiting_50_293 ||
         (uVar4 = (uint)_DAT_008096a8,
         maximum_temperature_threshold_for_imt_tvo_limiting_50_to_293 < _DAT_008096a8)) ||
        (uVar4 = (uint)_DAT_008096a6, _DAT_00809692 < _DAT_008096a6)))) {
      _DAT_0080c7cc = 1;
      return uVar4;
    }
    _DAT_0080c7cc = 0;
    return uVar4;
  }
  if (_oil_pressure_mode_selector != 2) {
    return (int)_oil_pressure_mode_selector;
  }
  uVar4 = CONCAT22(sVar1,_DAT_008096a6);
  if ((((_DAT_008096a6 < _DAT_00809690) &&
       (uVar4 = CONCAT22(sVar1,_DAT_008096a6),
       fault_index_indicating_epf_imt_fuel_error_found_0_ffff <= _DAT_008096a6)) &&
      (uVar4 = CONCAT22(sVar1,_DAT_008096a8), _DAT_008096a8 <= rpm_to_reach_before_imt_errors_0_8000
      )) && ((uVar4 = CONCAT22(sVar1,_DAT_0080c7c8),
             _DAT_0080c7c8 < determines_how_engine_position_is_sync_d_to_cam_0 ||
             (uVar4 = CONCAT22(sVar1,_DAT_0080968c),
             _DAT_0080968c < time_to_reach_full_derate_during_intake_temp_engine_prote_0_0039_256)))
     ) {
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
  _DAT_00803208 = &minimum_temperature_threshold_for_imt_fuel_limiting_50_to_293;
  return;
}



//
// Function: FUN_0002c4f0 @ 0x0002c4f0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0002c4f0(void)

{
  if ((_DAT_008035e0 & 0x8000) == 0) {
    _DAT_008096b2 = 0;
  }
  return _DAT_008035e0 & 0x8000;
}



//
// Function: FUN_0002c506 @ 0x0002c506
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0002c506(void)

{
  if ((_DAT_008035e0 & 0x8000) != 0) {
    _DAT_008096b2 = 0;
  }
  return _DAT_008035e0 & 0x8000;
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
  _DAT_008096c6 = lookupTableInterpolation((short *)&protection_table_size);
  if (diagnostic_state_buffer_t_00809654.diagnostic_mode == 9) {
    if ((((_DAT_008096b6 == 1) || (_DAT_008096b6 == 3)) || (_DAT_008096b6 == 2)) ||
       (_DAT_008096b6 == 4)) {
      _water_in_fuel_protection_active = 0;
    }
    else {
      if (_target_boost_pressure_base < _boost_pressure_feedback) {
        uVar1 = _boost_pressure_feedback - _target_boost_pressure_base;
      }
      else {
        uVar1 = _target_boost_pressure_base - _boost_pressure_feedback;
      }
      if (((uVar1 < time_from_overlimit_reached_to_starting_fuel_derate_0_65535) &&
          (param_1._0_2_ <= _selected_oil_pressure_threshold)) &&
         (shutdown_threshold_for_intake_temp_rpm_20_255 <= param_1._0_2_)) {
        _water_in_fuel_protection_active = 1;
      }
    }
  }
  if ((_water_in_fuel_protection_active == 0) &&
     (diagnostic_state_buffer_t_00809654.diagnostic_mode == 9)) {
    _boost_pressure_protection_active = 0;
  }
  else if (_selected_oil_pressure_threshold < param_1._0_2_) {
    uVar1 = _boost_pressure_monitor_value;
    if (diagnostic_state_buffer_t_00809654.diagnostic_mode == 9) {
      uVar1 = _oil_pressure_monitor_value;
    }
    sStack_6 = (short)((uint)uVar1 * ((uint)param_1._0_2_ - (uint)_selected_oil_pressure_threshold)
                      >> 10);
    if (sStack_6 < 0xa01) {
      _boost_pressure_protection_active = sStack_6;
    }
    else {
      _boost_pressure_protection_active = 0xa00;
    }
  }
  else if (param_1._0_2_ < shutdown_threshold_for_intake_temp_rpm_20_255) {
    sVar2 = _intake_temp_protection_calc2;
    if (diagnostic_state_buffer_t_00809654.diagnostic_mode == 9) {
      sVar2 = _intake_temp_protection_calc1;
    }
    sStack_6 = (short)((int)sVar2 *
                       ((int)(short)param_1._0_2_ -
                       (int)(short)shutdown_threshold_for_intake_temp_rpm_20_255) >> 10);
    if (sStack_6 < -0xa00) {
      _boost_pressure_protection_active = -0xa00;
    }
    else {
      _boost_pressure_protection_active = sStack_6;
    }
  }
  else {
    _boost_pressure_protection_active = 0;
  }
  if (_boost_pressure_control_output < 1) {
    if (-(int)_boost_pressure_control_output ==
        (int)_DAT_008070b4 + (int)(short)shutdown_delay_for_oil_pressure_shutdown_0_255 ||
        -((int)_DAT_008070b4 + (int)(short)shutdown_delay_for_oil_pressure_shutdown_0_255) <
        (int)_boost_pressure_control_output) {
      if (-((int)(short)shutdown_delay_for_oil_pressure_shutdown_0_255 - (int)_DAT_008070b4) <
          (int)_boost_pressure_control_output) {
        _protection_status_flag1 = 0;
      }
    }
    else {
      _protection_status_flag1 = 1;
    }
  }
  else if ((int)_DAT_008070b4 + (int)(short)shutdown_delay_for_oil_pressure_shutdown_0_255 <
           (int)_boost_pressure_control_output) {
    _protection_status_flag1 = 1;
  }
  else if ((int)_boost_pressure_control_output <
           (int)(short)shutdown_delay_for_oil_pressure_shutdown_0_255 - (int)_DAT_008070b4) {
    _protection_status_flag1 = 0;
  }
  if (_protection_status_flag1 != 0) {
    if (_protection_status_flag2 == 0) {
      if ((uint)_current_fuel_demand_value < shutdown_threshold_for_intake_temp_rpm_20_255 + 0x3a) {
        _protection_status_flag1 = 0;
      }
    }
    else if (_current_fuel_demand_value < shutdown_threshold_for_intake_temp_rpm_20_255) {
      _protection_status_flag1 = 0;
    }
  }
  if (_protection_status_flag1 == 0) {
    _DAT_008096e2 = &time_duration_from_overlimit_reached_to_starting_rpm_derate_0_65535;
  }
  else {
    _DAT_008096e2 = &dont_log_oil_pressure_faults_until_running_and_time_expired_0_255;
  }
  _DAT_008096cc = *_DAT_008096e2;
  _DAT_008096c8 = _DAT_008096e2[1];
  _DAT_008096c2 = _DAT_008096e2[2];
  _DAT_008096ca = _DAT_008096e2[3];
  if (_protection_status_flag1 != _protection_status_flag2) {
    _oil_pressure_protection_active = 1;
  }
  _protection_status_flag2 = _protection_status_flag1;
  return;
}



//
// Function: update_engine_protection_thresholds @ 0x0002c7e0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void update_engine_protection_thresholds(void)

{
  _intake_temp_calc_result = _intake_temp_protection_calc2;
  _boost_pressure_calc_result = _boost_pressure_monitor_value;
  if ((_water_in_fuel_protection_active == 1) && (_protection_system_enable_flag == 1)) {
    _oil_pressure_timer = _oil_pressure_monitor_value;
    _boost_pressure_timer = _intake_temp_protection_calc1;
  }
  else {
    _oil_pressure_timer = 0;
    _boost_pressure_timer = 0;
  }
  if (_oil_pressure_mode_selector == 0) {
    _selected_oil_pressure_threshold = minimum_threshold_for_oil_pressure_rpm_limiting_0_65535;
  }
  else if (_oil_pressure_mode_selector == 2) {
    _selected_oil_pressure_threshold =
         time_to_shutdown_after_low_oil_pressure_error_declared_0_65535;
  }
  else if (_oil_pressure_mode_selector == 1) {
    _selected_oil_pressure_threshold = _custom_oil_pressure_threshold;
  }
  _oil_pressure_threshold_active = _selected_oil_pressure_threshold;
  _oil_pressure_threshold_backup = _selected_oil_pressure_threshold;
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
  
  _protection_table_size = 2;
  _DAT_00803214 = &time_to_shutdown_after_low_oil_pressure_error_declared_0_100;
  _DAT_0080321a = &min_threshold_for_water_in_fuel_fuel_limiting_0_3;
  _oil_pressure_protection_active = 0;
  _boost_pressure_protection_active = 0;
  _water_in_fuel_protection_active = 0;
  local_16 = 0x808002;
  local_18 = 2;
  local_a = 400;
  local_e = 0x808028;
  local_10 = 2;
  local_8 = 0x808032;
  uVar2 = FUN_0002c870(CONCAT22(_DAT_00803746 - _DAT_00803822,(short)((uint)unaff_D2 >> 0x10)));
  local_12 = (undefined2)uVar2;
  sVar3 = _DAT_00803822;
  _oil_pressure_monitor_value = FUN_0002c8fe();
  uVar2 = FUN_0002c870(CONCAT22(_DAT_00803748 - _DAT_00803826,sVar3));
  local_12 = (undefined2)uVar2;
  _boost_pressure_monitor_value = FUN_0002c8fe((short)((uint)&local_18 >> 0x10));
  if (shutdown_duration_threshold_for_boost_pressure_fuel_0_65535 <
      shutdown_threshold_for_intake_temp_rpm_20_255) {
    uVar1 = shutdown_threshold_for_intake_temp_rpm_20_255 -
            shutdown_duration_threshold_for_boost_pressure_fuel_0_65535;
    _intake_temp_protection_calc1 = FUN_0002c968();
    _intake_temp_protection_calc2 = FUN_0002c968((short)((uint)uVar1 * 0x1164 >> 0x10),uVar1);
  }
  else {
    _intake_temp_protection_calc1 = 0;
    _intake_temp_protection_calc2 = 0;
  }
  _oil_pressure_threshold_active = minimum_threshold_for_oil_pressure_rpm_limiting_0_65535;
  _oil_pressure_threshold_backup = minimum_threshold_for_oil_pressure_rpm_limiting_0_65535;
  _intake_temp_threshold_active = shutdown_threshold_for_intake_temp_rpm_20_255;
  _intake_temp_threshold_backup = shutdown_threshold_for_intake_temp_rpm_20_255;
  _oil_pressure_timer = 0;
  _boost_pressure_timer = 0;
  _intake_temp_calc_result = _intake_temp_protection_calc2;
  _boost_pressure_calc_result = _boost_pressure_monitor_value;
  _protection_status_flag1 = 0;
  _protection_status_flag2 = 0;
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
  
  iVar1 = (uint)_DAT_0080382c *
          (int)(short)(((int)_boost_pressure_control_output * (int)_DAT_008096c6) / 1000);
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
  word wVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  word wStack_a;
  int local_8;
  
  uVar8 = (undefined2)((uint)unaff_D2 >> 0x10);
  uVar7 = 0x322a;
  sVar5 = _current_fuel_demand_value;
  _boost_pressure_raw_reading = coreTableInterpolation(0x80);
  _boost_pressure_filtered_value = coreTableInterpolation(0x80,sVar5,uVar7);
  sVar5 = _boost_pressure_current_delta;
  _boost_pressure_current_delta = FUN_0003574e();
  uVar2 = _boost_pressure_command;
  sVar5 = _boost_pressure_current_delta - sVar5;
  if (sVar5 < 0x67) {
    if (sVar5 < -0x66) {
      sVar5 = -0x66;
    }
  }
  else {
    sVar5 = 0x66;
  }
  if ((((short)fault_when_epf_boost_pressure_fuel_error_found_0_65535 < sVar5) ||
      ((int)sVar5 < -(int)(short)fault_when_epf_boost_pressure_fuel_error_found_0_65535)) ||
     (_epf_fault_timer == 0)) {
    _epf_fault_timer = fault_when_epf_engine_boost_pressure_rpm_error_found_0_65535;
  }
  else {
    if (_epf_fault_timer == fault_when_epf_engine_boost_pressure_rpm_error_found_0_65535) {
      _boost_pressure_baseline = _boost_pressure_filtered_value;
    }
    if (_epf_fault_timer != 0) {
      _epf_fault_timer = _epf_fault_timer - 1;
    }
  }
  if ((_epf_fault_timer == 0) &&
     (shutdown_duration_threshold_for_fuel_pressure_rpm_0_65535 <= _boost_pressure_current_delta)) {
    boost_pressure_control_active = '\x01';
    _boost_pressure_target = _boost_pressure_baseline;
  }
  else if (boost_pressure_control_active == '\0') {
    _boost_pressure_target = _current_fuel_demand_value;
  }
  if ((diagnostic_state_buffer_t_00809654.diagnostic_mode == 9) ||
     (diagnostic_state_buffer_t_00809654.diagnostic_mode == 10)) {
    if (_diagnostic_boost_mode_flag == 1) {
      FUN_0002d210();
    }
    else {
      if (diagnostic_state_buffer_t_00809654.diagnostic_mode == 9) {
        _boost_pressure_command = _target_boost_pressure_base;
        if (uVar2 < _target_boost_pressure_base) {
          if ((ushort)(delay_after_rpm_is_reached_before_water_in_fuel_errors_0_8000 + uVar2) <
              _target_boost_pressure_base) {
            _boost_pressure_command =
                 delay_after_rpm_is_reached_before_water_in_fuel_errors_0_8000 + uVar2;
          }
        }
        else if ((_target_boost_pressure_base < uVar2) &&
                ((uint)fault_when_epf_water_in_fuel_fuel_error_found_0_65535 +
                 (uint)_target_boost_pressure_base < (uint)uVar2)) {
          _boost_pressure_command = uVar2 - fault_when_epf_water_in_fuel_fuel_error_found_0_65535;
        }
        _boost_pressure_setpoint = _boost_pressure_command;
        if (((_water_in_fuel_sensor_flag1 == 1) && ((sensor_status_register & 2) == 0)) ||
           ((_water_in_fuel_sensor_flag2 == 1 && ((sensor_status_register & 8) == 0)))) {
          FUN_0002d210();
        }
      }
      else {
        _boost_pressure_setpoint = _boost_pressure_max_target;
      }
      _boost_pressure_error = _boost_pressure_setpoint - _boost_pressure_feedback;
      if ((short)max_threshold_for_boost_pressure_fuel_limiting_0_100 < (short)_boost_pressure_error
         ) {
        _boost_pressure_error = max_threshold_for_boost_pressure_fuel_limiting_0_100;
      }
      else if ((short)_boost_pressure_error <
               (short)min_threshold_for_boost_fuel_pressure_rpm_limiting_0_65535) {
        _boost_pressure_error = min_threshold_for_boost_fuel_pressure_rpm_limiting_0_65535;
      }
      FUN_0002c51a(CONCAT22(_boost_pressure_raw_reading,uVar8));
      if ((int)(short)_boost_pressure_error < _boost_pressure_protection_active + 0xa00) {
        if (_boost_pressure_protection_active + -0xa00 < (int)(short)_boost_pressure_error) {
          _boost_pressure_control_output = _boost_pressure_error - _boost_pressure_protection_active
          ;
        }
        else {
          _boost_pressure_control_output = -0xa00;
        }
      }
      else {
        _boost_pressure_control_output = 0xa00;
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
      wStack_a = (word)((int)sVar5 * (int)_DAT_008096c6 >> 5);
      iVar3 = (uint)_DAT_0080382c * (int)(short)wStack_a;
      wVar6 = shutdown_severity_threshold_for_water_in_fuel_fueling_0_3;
      if ((iVar3 < (short)shutdown_severity_threshold_for_water_in_fuel_fueling_0_3 * 0x16) &&
         (wVar6 = shutdown_severity_threshold_for_water_in_fuel_rpm_0_3,
         (short)shutdown_severity_threshold_for_water_in_fuel_rpm_0_3 * 0x16 < iVar3)) {
        wVar6 = (word)(iVar3 / 0x16);
      }
      iVar3 = (int)sVar4 * (int)_DAT_008096cc >> 0xc;
      if (iVar3 < 0x7fff) {
        if (iVar3 < -0x7fff) {
          _DAT_008096f4 = -0x8000;
        }
        else {
          wStack_a = (word)iVar3;
          _DAT_008096f4 = wStack_a;
        }
      }
      else {
        _DAT_008096f4 = 0x7fff;
      }
      wStack_a = (word)((int)(short)wVar6 * (int)_DAT_008096c2 >> 0xf);
      _DAT_008096e8 = wStack_a;
      local_8 = (int)(short)min_threshold_for_boost_pressure_fuel_limiting_0_100 *
                ((int)_current_fuel_demand_value - (int)(short)_DAT_00803222) * 2;
      if (local_8 < 0x6e66667) {
        if (local_8 < -0x6e66666) {
          local_8 = -0x6e66666;
        }
      }
      else {
        local_8 = 0x6e66666;
      }
      _DAT_008096f0 = local_8._0_2_;
      if (_oil_pressure_protection_active != 0) {
        _oil_pressure_protection_active = 0;
        iVar3 = ((int)(short)wStack_a + ((int)(short)_DAT_00803222 - (int)_DAT_008096f4)) -
                (int)_DAT_00803268;
        if ((int)(uint)start_duration_for_boost_pressure_rpm_derate_0_65535 < iVar3) {
          _DAT_00803252 = start_duration_for_boost_pressure_rpm_derate_0_65535;
        }
        else if (iVar3 < (int)(uint)shutdown_duration_threshold_for_boost_pressure_fuel_0_65535) {
          _DAT_00803252 = shutdown_duration_threshold_for_boost_pressure_fuel_0_65535;
        }
        else {
          _DAT_00803252 = (ushort)iVar3;
        }
        _DAT_00803252 = (uint)_DAT_00803252 << 0x10;
      }
      local_8 = local_8 + (((int)sVar4 * (int)_DAT_008096c8 * 4 + _DAT_00803252) -
                          ((int)(short)wVar6 * (int)_DAT_008096ca >> 4));
      _DAT_00803252 = (ushort)((uint)local_8 >> 0x10);
      if ((short)_DAT_00803252 < (short)start_duration_for_boost_pressure_rpm_derate_0_65535) {
        bVar1 = (short)_DAT_00803252 <
                (short)shutdown_duration_threshold_for_boost_pressure_fuel_0_65535;
        _DAT_00803252 = local_8;
        if (bVar1) {
          _DAT_00803252 = (uint)shutdown_duration_threshold_for_boost_pressure_fuel_0_65535 << 0x10;
        }
      }
      else {
        _DAT_00803252 = (uint)start_duration_for_boost_pressure_rpm_derate_0_65535 << 0x10;
      }
      _DAT_008096f2 = _DAT_00803252;
      if (_DAT_0080326c == 0) {
        _DAT_00803278 =
             sVar5 * 0x20 -
             (short)(((int)(short)start_duration_for_engine_sync_fuel_pressure_rpm_derate_0_65535 *
                     (int)_boost_pressure_control_output) / 0x19);
        if ((_DAT_0080710a < _DAT_00803278) &&
           (_boost_pressure_control_output <
            (short)start_duration_for_engine_sync_fuel_pressure_fueling_derate_0_65535)) {
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
          _DAT_00803274 =
               time_duration_to_warn_driver_before_shutdown_due_to_boost_pres_0_65535 * sVar5;
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
          _DAT_0080326c = shutdown_severity_threshold_for_boost_pressure_fueling_0_100;
          _DAT_00803268 = _DAT_00803274;
          _DAT_00803272 = 4;
        }
      }
      else {
        _DAT_0080326c = _DAT_0080326c - 1;
      }
      if (_DAT_00803268 < 1) {
        if (_DAT_00803268 < 0) {
          if (-(int)(short)shutdown_severity_threshold_for_boost_pressure_rpm_0_100 <
              (int)_DAT_00803268) {
            _DAT_00803268 = 0;
          }
          else {
            _DAT_00803268 = shutdown_severity_threshold_for_boost_pressure_rpm_0_100 + _DAT_00803268
            ;
          }
        }
      }
      else if (_DAT_00803268 < (short)shutdown_severity_threshold_for_boost_pressure_rpm_0_100) {
        _DAT_00803268 = 0;
      }
      else {
        _DAT_00803268 = _DAT_00803268 - shutdown_severity_threshold_for_boost_pressure_rpm_0_100;
      }
      iVar3 = (int)_DAT_00803268 +
              (((int)_DAT_008096f2 + (int)_DAT_008096f4) - (int)(short)wStack_a);
      if (iVar3 < 0x2e00) {
        if (iVar3 < -0x24b) {
          _DAT_00803222 = 0xfdb4;
        }
        else {
          wStack_a = (word)iVar3;
          _DAT_00803222 = wStack_a;
        }
      }
      else {
        _DAT_00803222 = 0x2e00;
      }
      if ((short)_DAT_00803222 < (short)start_duration_for_boost_pressure_rpm_derate_0_65535) {
        if ((short)time_to_reach_full_derate_during_boost_press_eng_prote_1_256_65535_256 <
            (short)_DAT_00803222) {
          _DAT_008096e6 = _DAT_00803222;
        }
        else {
          _DAT_008096e6 = time_to_reach_full_derate_during_boost_press_eng_prote_1_256_65535_256;
        }
      }
      else {
        _DAT_008096e6 = start_duration_for_boost_pressure_rpm_derate_0_65535;
      }
      _diagnostic_rpm_threshold_status = _DAT_008096e6;
    }
  }
  _DAT_0080326a = diagnostic_state_buffer_t_00809654.diagnostic_mode;
  update_engine_protection_thresholds();
  _water_in_fuel_sensor_flag1 = (byte)-((sensor_status_register & 2) != 0) & 1;
  _water_in_fuel_sensor_flag2 = (byte)-((sensor_status_register & 8) != 0) & 1;
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
    _boost_pressure_error = _boost_pressure_max_target - _boost_pressure_feedback;
    if ((short)_boost_pressure_error < (short)max_threshold_for_boost_pressure_fuel_limiting_0_100)
    {
      if ((short)_boost_pressure_error <
          (short)min_threshold_for_boost_fuel_pressure_rpm_limiting_0_65535) {
        _boost_pressure_error = min_threshold_for_boost_fuel_pressure_rpm_limiting_0_65535;
      }
    }
    else {
      _boost_pressure_error = max_threshold_for_boost_pressure_fuel_limiting_0_100;
    }
  }
  else {
    _boost_pressure_command = _boost_pressure_feedback;
    _boost_pressure_setpoint = _boost_pressure_feedback;
    _boost_pressure_error = 0;
  }
  _boost_pressure_control_output = _boost_pressure_error;
  FUN_0002c51a(CONCAT22(_boost_pressure_raw_reading,(short)((uint)unaff_D2 >> 0x10)));
  if ((int)(short)_boost_pressure_error < _boost_pressure_protection_active + 0xa00) {
    if (_boost_pressure_protection_active + -0xa00 < (int)(short)_boost_pressure_error) {
      _boost_pressure_control_output = _boost_pressure_error - _boost_pressure_protection_active;
    }
    else {
      _boost_pressure_control_output = -0xa00;
    }
  }
  else {
    _boost_pressure_control_output = 0xa00;
  }
  uVar1 = FUN_0002cb08();
  sVar2 = (short)uVar1;
  _DAT_0080323a = (int)sVar2 << 0x10;
  _DAT_0080323e = (int)sVar2 << 0x10;
  _DAT_0080324a = (uint)_boost_pressure_feedback << 0x10;
  _DAT_0080324e = (uint)_boost_pressure_feedback << 0x10;
  _boost_pressure_current_delta = _boost_pressure_feedback;
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
    sVar2 = _boost_pressure_target;
    if (diagnostic_state_buffer_t_00809654.diagnostic_mode == 10) {
      sVar2 = _current_fuel_demand_value - shutdown_delay_for_boost_pressure_shutdown_0_255;
    }
    _DAT_00803268 = _current_fuel_demand_value - sVar2;
    _DAT_00803252 = sVar2 - local_8._2_2_;
  }
  else {
    _DAT_00803268 = 0;
    _DAT_00803252 = _current_fuel_demand_value - local_8._2_2_;
  }
  if ((short)_DAT_00803252 < (short)start_duration_for_boost_pressure_rpm_derate_0_65535) {
    if ((short)_DAT_00803252 < (short)shutdown_duration_threshold_for_boost_pressure_fuel_0_65535) {
      _DAT_00803252 = shutdown_duration_threshold_for_boost_pressure_fuel_0_65535;
    }
  }
  else {
    _DAT_00803252 = start_duration_for_boost_pressure_rpm_derate_0_65535;
  }
  _DAT_00803254 = 0;
  _DAT_008096f2 = _DAT_00803252;
  _DAT_00803222 = _current_fuel_demand_value;
  _diagnostic_boost_mode_flag = 0;
  _DAT_00803272 = 4;
  return;
}



//
// Function: FUN_0002d3fa @ 0x0002d3fa
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002d3fa(void)

{
  _diagnostic_boost_mode_flag = 0;
  _DAT_00803232 = 0x8070e6;
  _DAT_00803236 = &start_duration_for_boost_pressure_fueling_derate_0_65535;
  _DAT_00803242 = &fault_when_epf_water_in_fuel_rpm_error_found_0_65535;
  _DAT_00803246 = &time_duration_to_warn_driver_before_shutdown_due_to_water_in_f_0_65535;
  _DAT_0080322a = &maximum_threshold_for_oil_pressure_fueling_limiting_0_100;
  _DAT_0080325a = &delay_after_rpm_is_reached_before_boost_pressure_errors_0_8000;
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
  
  bVar5 = (sensor_status_register & 4) != 0;
  if ((DAT_0080327a == '\0') && (bVar5)) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  DAT_0080327a = bVar5;
  bVar5 = (sensor_status_register & 1) != 0;
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
  if ((_diagnostic_system_flags_1 & 0x40) == 0) {
    _DAT_008096b6 = 0;
    uVar4 = _diagnostic_system_flags_1 & 0x40;
  }
  else {
    if ((_DAT_0080971e == 0) || (shutdown_delay_for_engine_sync_fuel_pressure_shutdown_0_255 == 0))
    {
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
    uVar4 = sensor_status_register & 0x10;
    if (((((((sensor_status_register & 0x10) == 0) ||
           (uVar4 = _boost_pressure_feedback, _boost_pressure_feedback < _DAT_00807944)) ||
          (uVar4 = DAT_0080bdc7 & 4, (DAT_0080bdc7 & 4) != 0)) ||
         ((uVar4 = _current_engine_rpm_raw,
          _current_engine_rpm_raw < shutdown_threshold_for_intake_temp_fuel_50_293 ||
          (uVar4 = DAT_0080bdc7 & 8, (DAT_0080bdc7 & 8) != 0)))) || ((bVar2 || (bVar1)))) ||
       ((_DAT_0080d002 != 0 && (_DAT_0080d016 == 1)))) {
      if (_DAT_008096fc == 0) {
        _DAT_008096b6 = 0;
      }
      else {
        _DAT_008096b6 = 8;
      }
    }
    else if (bVar3) {
      if ((_active_derate_value < 0xc) || (diagnostic_state_buffer_t_00809654.diagnostic_mode == 9))
      {
        bVar5 = false;
      }
      else {
        bVar5 = true;
      }
      if ((_protection_system_enable_flag == 0) || (bVar5)) {
        uVar4 = _boost_pressure_feedback;
        if (shutdown_duration_threshold_for_fuel_pressure_rpm_0_65535 <= _boost_pressure_feedback) {
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
    else if ((sensor_status_register & 8) == 0) {
      if (bVar5) {
        if (_protection_system_enable_flag == 0) {
          uVar4 = _boost_pressure_feedback;
          if ((shutdown_duration_threshold_for_fuel_pressure_rpm_0_65535 <= _boost_pressure_feedback
              ) && (_DAT_008096fc != 0)) {
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
      else if (((sensor_status_register & 2) != 0) && (_protection_system_enable_flag != 0)) {
        _DAT_008096b6 = 4;
      }
    }
    else if (_protection_system_enable_flag != 0) {
      _DAT_008096b6 = 3;
    }
  }
  if (_DAT_008096b6 == 0x100) {
    if (_protection_system_enable_flag != 0) {
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
    _boost_pressure_feedback = _DAT_008096a6;
    return;
  }
  uVar1 = ((uint)current_engine_rpm << 0x10) / ((uint)_DAT_00803830 * (uint)_DAT_0080971c >> 10) >>
          2;
  if (uVar1 < 0x8001) {
    _boost_pressure_feedback = (ushort)uVar1;
  }
  else {
    _boost_pressure_feedback = 0x8000;
  }
  if (_DAT_0080327e < _boost_pressure_feedback) {
    if ((int)(uint)time_to_reach_full_derate_during_fuel_press_eng_protec_1_256_65535_256 <
        (int)((uint)_boost_pressure_feedback - (uint)_DAT_0080327e)) {
      _boost_pressure_feedback =
           time_to_reach_full_derate_during_fuel_press_eng_protec_1_256_65535_256 + _DAT_0080327e;
    }
  }
  else if ((_boost_pressure_feedback < _DAT_0080327e) &&
          ((int)(uint)time_to_reach_full_derate_during_fuel_press_eng_protec_1_256_65535_256 <
           (int)((uint)_DAT_0080327e - (uint)_boost_pressure_feedback))) {
    _boost_pressure_feedback =
         _DAT_0080327e - time_to_reach_full_derate_during_fuel_press_eng_protec_1_256_65535_256;
  }
  _DAT_0080327e = _boost_pressure_feedback;
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
  if (_target_boost_pressure_base < param_1._0_2_) {
    _target_boost_pressure_base = shutdown_duration_threshold_for_fuel_pressure_fuel_0_65535;
    return;
  }
  _target_boost_pressure_base = _target_boost_pressure_base - param_1._0_2_;
  if (_target_boost_pressure_base < shutdown_duration_threshold_for_fuel_pressure_fuel_0_65535) {
    _target_boost_pressure_base = shutdown_duration_threshold_for_fuel_pressure_fuel_0_65535;
  }
  return;
}



//
// Function: FUN_0002d782 @ 0x0002d782
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002d782(undefined4 param_1)

{
  if ((int)(uint)_target_boost_pressure_base < (int)((uint)_DAT_00803746 - (uint)param_1._0_2_)) {
    _target_boost_pressure_base = param_1._0_2_ + _target_boost_pressure_base;
    return;
  }
  _target_boost_pressure_base = _DAT_00803746;
  return;
}



//
// Function: FUN_0002d7b4 @ 0x0002d7b4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002d7b4(void)

{
  undefined4 unaff_A2;
  undefined2 uVar1;
  
  uVar1 = (undefined2)((uint)unaff_A2 >> 0x10);
  switch(_DAT_008096b6) {
  case 0:
    _protection_system_enable_flag = 0;
    _DAT_008096fc = 0;
    return;
  case 1:
    _target_boost_pressure_base = FUN_0002d74a(CONCAT22(_boost_pressure_feedback,_DAT_00803746));
    _protection_system_enable_flag = 1;
    _DAT_008096fc = 1;
    _DAT_008096fa = _target_boost_pressure_base;
    break;
  case 2:
    _protection_system_enable_flag = 1;
    _target_boost_pressure_base = _DAT_008096fa;
    break;
  case 3:
    FUN_0002d75e(CONCAT22(min_threshold_for_engine_sync_fuel_pressure_rpm_limiting_0_65535,uVar1));
    break;
  case 4:
    FUN_0002d782(CONCAT22(time_to_reach_full_derate_during_fuel_press_eng_protec_1_256_65535_256,
                          uVar1));
    break;
  case 5:
    FUN_0002d75e(CONCAT22(_DAT_00807114,uVar1));
    break;
  case 6:
    FUN_0002d782(CONCAT22(_DAT_00807116,uVar1));
    break;
  case 8:
    _protection_system_enable_flag = 0;
    return;
  }
  if ((_DAT_008096b6 == 3) || (_DAT_00803280 != 3)) {
    if ((_DAT_008096b6 != 4) && (_DAT_00803280 == 4)) {
      if (_DAT_008096fa < _boost_pressure_feedback) {
        _target_boost_pressure_base = FUN_0002d74a(CONCAT22(_boost_pressure_feedback,_DAT_00803746))
        ;
      }
      else {
        _target_boost_pressure_base = _DAT_008096fa;
      }
    }
  }
  else if (_boost_pressure_feedback < _DAT_008096fa) {
    if (_boost_pressure_feedback < shutdown_duration_threshold_for_fuel_pressure_rpm_0_65535) {
      _protection_system_enable_flag = 0;
    }
    else {
      _target_boost_pressure_base = _boost_pressure_feedback;
    }
  }
  else {
    _target_boost_pressure_base = _DAT_008096fa;
  }
  if (_DAT_008096b6 == 7) {
    _DAT_008096fa = _target_boost_pressure_base;
  }
  if ((_DAT_00803746 < _DAT_008096fa) ||
     (_DAT_008096fa < shutdown_duration_threshold_for_fuel_pressure_rpm_0_65535)) {
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
  
  uVar1 = _diagnostic_system_flags_1 & 0x8000;
  if ((_diagnostic_system_flags_1 & 0x8000) != 0) {
    _DAT_00805f90 = _target_boost_pressure_base;
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
  if ((shutdown_duration_threshold_for_fuel_pressure_rpm_0_65535 < _DAT_00805f90) &&
     (_DAT_00805f90 < _DAT_00803746)) {
    _DAT_008096fc = 1;
    _target_boost_pressure_base = _DAT_00805f90;
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
  
  if (current_engine_rpm < _arbitrated_fuel_limit) {
    _DAT_00809694 = 0x1700;
  }
  else if (_DAT_0080cc58 == 0) {
    _DAT_00809694 = 0;
  }
  else {
    _DAT_00803282 =
         (uint)(ushort)((_DAT_0080cc54 + current_engine_rpm) - _arbitrated_fuel_limit) << 0x10;
    uVar1 = _DAT_00803282 / ((uint)_DAT_0080cc58 * 0xf);
    _DAT_00803282 = (short)(uVar1 >> 0x10);
    _DAT_00803282 = uVar1;
    if ((_DAT_00803282 == 0) && (_DAT_00803284 = (ushort)uVar1, _DAT_00803284 < _DAT_0080cc56)) {
      _DAT_00809694 = _DAT_0080cc56 - _DAT_00803284;
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
  
  if (_protection_system_enable_flag != 1) {
    _DAT_00809698 = 0x1700;
    return;
  }
  if (_target_boost_pressure_base < _boost_pressure_feedback) {
    if (_boost_pressure_timer == 0) {
      _DAT_00809698 = 0;
      return;
    }
    _DAT_00803286 = 1;
    _DAT_00803288 = _boost_pressure_timer;
    iVar1 = (uint)_boost_pressure_feedback - (uint)_target_boost_pressure_base;
  }
  else {
    if (_oil_pressure_timer == 0) {
      _DAT_00809698 = 0x1700;
      return;
    }
    _DAT_00803286 = 0;
    _DAT_00803288 = _oil_pressure_timer;
    iVar1 = (uint)_target_boost_pressure_base - (uint)_boost_pressure_feedback;
  }
  _DAT_00803282 = iVar1 * 0x400;
  if (_DAT_00803286 == 0) {
    _DAT_00803282 = (uint)_oil_pressure_threshold_backup + _DAT_00803282 / _DAT_00803288;
  }
  else {
    _DAT_00803282 = (uint)_intake_temp_threshold_backup - _DAT_00803282 / _DAT_00803288;
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
  
  if (((_diagnostic_system_flags_1 & 0x80) == 0) || (_DAT_008096aa != 0)) {
    _DAT_00809696 = 0x1700;
    return _diagnostic_system_flags_1 & 0x80;
  }
  if (_boost_pressure_max_target < _boost_pressure_feedback) {
    if (_intake_temp_calc_result == 0) {
      _DAT_00809696 = 0;
      return (uint)_boost_pressure_feedback;
    }
    _DAT_00803286 = 1;
    _DAT_00803288 = _intake_temp_calc_result;
    iVar1 = (uint)_boost_pressure_feedback - (uint)_boost_pressure_max_target;
  }
  else {
    if (_boost_pressure_calc_result == 0) {
      _DAT_00809696 = 0x1700;
      return (uint)_boost_pressure_feedback;
    }
    _DAT_00803286 = 0;
    _DAT_00803288 = _boost_pressure_calc_result;
    iVar1 = (uint)_boost_pressure_max_target - (uint)_boost_pressure_feedback;
  }
  _DAT_00803282 = iVar1 * 0x400;
  if (_DAT_00803286 == 0) {
    uVar2 = (uint)_oil_pressure_threshold_active;
    _DAT_00803282 = uVar2 + _DAT_00803282 / _DAT_00803288;
  }
  else {
    uVar2 = (uint)_intake_temp_threshold_active - _DAT_00803282 / _DAT_00803288;
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
// Function: FUN_0002dc1e @ 0x0002dc1e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002dc1e(void)

{
  ushort uVar1;
  
  if ((_DAT_008071ae <= _DAT_008096a6) && (engine_operating_mode != IDLE)) {
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
    if (((fault_index_indicating_fuel_temperature_rpm_error_detected_0_ffff < _DAT_00803292) &&
        (_DAT_00803292 < time_duration_to_warn_driver_before_shutdown_due_to_fuel_tem_0_65535)) &&
       (uVar1 <= fault_index_indicating_temperature_fueling_error_detected_0_ffff)) {
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
      if (_DAT_00803292 < fault_index_indicating_fuel_temperature_rpm_error_detected_0_ffff) {
        _DAT_0080971a = fault_index_indicating_fuel_temperature_rpm_error_detected_0_ffff;
      }
      else if (time_duration_to_warn_driver_before_shutdown_due_to_fuel_tem_0_65535 < _DAT_00803292)
      {
        _DAT_0080971a = time_duration_to_warn_driver_before_shutdown_due_to_fuel_tem_0_65535;
      }
      _DAT_008096a8 = _DAT_0080971a;
      _DAT_0080328e = (uint)_DAT_0080971a << 0x10;
    }
    if ((current_engine_rpm < 8000) &&
       (start_duration_for_ambient_air_pressure_rpm_derate_0_65535 < _DAT_008096a6)) {
      _DAT_00809720 = start_duration_for_ambient_air_pressure_fueling_derate_0_65535;
    }
    else if (_DAT_00809720 != 0) {
      _DAT_00809720 = _DAT_00809720 - 1;
    }
    if ((_DAT_0080d002 == 0 && _DAT_00809722 == 0) && (_DAT_00809720 == 0)) {
      _DAT_008096aa = 0;
    }
    else {
      _DAT_008096aa = 1;
      _DAT_00803294 = 1;
    }
    if ((((_DAT_0080971c == _DAT_00803296) && (_DAT_008096aa == 0)) && (_DAT_00803294 == 1)) &&
       (time_to_reach_full_derate_during_ambient_air_eng_protc_1_256_65535_256 <
        _current_fuel_demand_value)) {
      _DAT_00809724 = _DAT_0080971c;
      _DAT_00803294 = 0;
    }
    _DAT_00803296 = _DAT_0080971c;
    return;
  }
  _DAT_0080971a = threshold_for_fuel_temperature_rpm_limiting_to_initiate_shutdo_0_255;
  _DAT_008096a8 = threshold_for_fuel_temperature_rpm_limiting_to_initiate_shutdo_0_255;
  _DAT_0080971c = threshold_for_fuel_temperature_rpm_limiting_to_initiate_shutdo_0_255;
  _DAT_00809724 = threshold_for_fuel_temperature_rpm_limiting_to_initiate_shutdo_0_255;
  _DAT_008096aa = 1;
  _DAT_0080328e = (uint)threshold_for_fuel_temperature_rpm_limiting_to_initiate_shutdo_0_255 << 0x10
  ;
  return;
}



//
// Function: FUN_0002ddea @ 0x0002ddea
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002ddea(void)

{
  _DAT_0080d002 = 0;
  _DAT_0080971a = threshold_for_fuel_temperature_rpm_limiting_to_initiate_shutdo_0_255;
  _DAT_008096a8 = threshold_for_fuel_temperature_rpm_limiting_to_initiate_shutdo_0_255;
  _DAT_0080971c = threshold_for_fuel_temperature_rpm_limiting_to_initiate_shutdo_0_255;
  _DAT_0080328e = (uint)threshold_for_fuel_temperature_rpm_limiting_to_initiate_shutdo_0_255 << 0x10
  ;
  _DAT_0080328a = &threshold_for_fuel_temperature_fuel_limiting_to_initiate_shutd_0_255;
  _DAT_00803296 = threshold_for_fuel_temperature_rpm_limiting_to_initiate_shutdo_0_255;
  return;
}



//
// Function: FUN_0002de2e @ 0x0002de2e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0002de2e(void)

{
  ushort in_D0w;
  
  if (((_DAT_008096aa != 0) && (in_D0w = _DAT_008096a6, _boost_pressure_max_target < _DAT_008096a6))
     && (in_D0w = _diagnostic_system_flags_1 & 0x80, (_diagnostic_system_flags_1 & 0x80) != 0)) {
    _DAT_0080972c = _DAT_008071a6;
    return in_D0w;
  }
  _DAT_0080972c = max_number_of_shutdowns_before_restart_is_not_allowed_0_255;
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
// Function: FUN_0002de92 @ 0x0002de92
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002de92(void)

{
  short sVar1;
  
  _DAT_008032b8 = (short)((_DAT_00805590 + 2) % 3);
  *(undefined4 *)((short)(_DAT_008032b8 * 2) * 8 + 0x805fb4) = _DAT_0080626c;
  *(int *)((short)(_DAT_008032b8 * 2) * 8 + 0x805fb8) = _DAT_00809726;
  if (_DAT_00803734 == 0) {
    sVar1 = _DAT_008032b8 << 4;
    *(uint *)(sVar1 + 0x805fbc) = (uint)_DAT_0080972a * 0x280;
    if (crank_adjusted_initial_fuel_0_100 < 0x6400) {
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
// Function: FUN_0002dfd0 @ 0x0002dfd0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0002dfd0(void)

{
  undefined4 in_D0;
  uint uVar1;
  ushort uVar2;
  
  uVar1 = CONCAT22((short)((uint)in_D0 >> 0x10),vp44_status_flags_2) & 0xffff2000;
  if ((vp44_status_flags_2 & 0x2000) != 0) {
    if ((((current_engine_rpm == 0) &&
         (points_to_water_in_fuel_fuel_maximum_threshold_0_2_32._2_2_ == 2)) &&
        (_DAT_0080329e <= min_threshold_for_ambient_air_pressure_fuel_limiting_0_15)) &&
       (_DAT_0080329a < 0xc)) {
      DAT_00803298 = 0;
      if (_DAT_0080329c == 1) {
        if (_DAT_0080329e == min_threshold_for_ambient_air_pressure_fuel_limiting_0_15) {
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
      if (_derate_threshold_exceeded == 1) {
        DAT_00803298 = DAT_00803298 | 8;
      }
      if (_DAT_008032a0 == 1) {
        DAT_00803298 = DAT_00803298 | 4;
      }
      if ((&DAT_0002de86)[(short)_DAT_0080329a] == DAT_00803298) {
        _DAT_008032a0 = _derate_threshold_exceeded;
        _DAT_008032a2 = (ushort)((DAT_0080bdc7 & 8) != 0);
        _DAT_0080329a = _DAT_0080329a + 1;
        if (4 < _DAT_0080329a) {
          _DAT_0080329c = 1;
        }
      }
      if ((_DAT_0080329a == 0xc) && (crank_initial_fuel_break_speed_0_1000 = 1, _DAT_008032ba == 1))
      {
        eps_period_backup_time_between_the_two_most_recent_eps_200_16777216._2_2_ = 1;
      }
    }
    if (((current_engine_rpm != 0) && ((_engine_fault_register_a & 0x100) != 0)) &&
       ((_engine_fault_register_b & 0x100) != 0)) {
      if (_DAT_008032b4 == _DAT_0080888a) {
        _DAT_0080558e = _DAT_0080558e | 1;
      }
      else {
        _DAT_008032b4 = _DAT_008032b4 + 1;
      }
    }
    if (((current_engine_rpm != 0) && ((_engine_fault_register_a & 0x200) != 0)) &&
       ((_engine_fault_register_b & 0x200) != 0)) {
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
      param_scaling_factor = lookupTableInterpolation((short *)&DAT_008032a8);
      uVar2 = (short)_DAT_0080626c - _DAT_008032a6;
      _DAT_008032a4 = _DAT_0080626c;
      uVar2 = (ushort)((uint)uVar2 * (uint)param_scaling_factor >> 8);
      if (-(uint)uVar2 - 1 < _DAT_00805faa) {
        _DAT_0080558e = _DAT_0080558e | 8;
      }
      _DAT_00805faa = uVar2 + _DAT_00805faa;
      uVar1 = FUN_000357d2(_DAT_00805faa,0x6400,(uint)_DAT_0080972a * 0x280);
      crank_adjusted_initial_rpm_0_1000 = (word)uVar1;
      if ((_DAT_00805fae == 0) && (0x63ff < crank_adjusted_initial_fuel_0_100)) {
        _DAT_00805fae = _DAT_00809726;
      }
    }
    else if (_DAT_00803734 == 3) {
      uVar1 = FUN_000357d2(uVar1,0x6400,(uint)_DAT_0080384a * 0x280);
      crank_adjusted_initial_rpm_0_1000 = (word)uVar1;
    }
    else {
      crank_adjusted_initial_rpm_0_1000 = 0;
    }
    if ((crank_initial_advace_break_speed_0_1000 == 1) ||
       ((crank_initial_fuel_break_speed_0_1000 == 1 && (_DAT_008032ba == 1)))) {
      uVar1 = FUN_0002de92();
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
  word *local_8;
  
  uVar1 = 0;
  _DAT_008032a4 = _DAT_0080626c;
  _DAT_008032ba = 1;
  _DAT_008032a8 = 2;
  _DAT_008032aa = &delay_after_rpm_is_reached_before_ambient_air_pressure_errors_0_8000;
  _DAT_008032b0 = 0x807188;
  local_10[0] = 2;
  local_10[1] = 0x80;
  local_10[2] = -0x7774;
  local_8 = &max_threshold_for_ambient_air_pressure_fuel_limiting_0_15;
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
  _DAT_00809730 = FUN_000357d2((uint)_DAT_0080385a * 0xe1000,500000,_DAT_00803856);
  return;
}



//
// Function: FUN_0002e3ee @ 0x0002e3ee
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0002e3ee(void)

{
  int iVar1;
  uint uVar2;
  undefined4 in_D0;
  uint uVar3;
  undefined *puVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  
  uVar3 = CONCAT22((short)((uint)in_D0 >> 0x10),_diagnostic_system_flags_1) & 0xffff0100;
  if ((_diagnostic_system_flags_1 & 0x100) == 0) {
    _boost_pressure_max_target = _DAT_00803748;
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
    uVar2 = (int)_DAT_00809746 - 1;
    uVar3 = uVar2;
    if (uVar2 < 6) {
      uVar3 = CONCAT22((short)(uVar2 >> 0x10),(&switchD_0002e4d8::switchdataD_0002e4dc)[uVar2]);
      uVar5 = (ushort)puVar4;
      switch(uVar2) {
      case 0:
        uVar3 = (uint)_DAT_008096a8;
        if (_DAT_0080973e < (int)uVar3) {
          _DAT_00809746 = 2;
          _boost_pressure_max_target = uVar6;
        }
        else {
          _DAT_00809746 = 6;
          _boost_pressure_max_target = uVar6;
        }
        break;
      case 1:
        _DAT_008032c2 = 0x64000000;
        _DAT_0080974a = 0x6400;
        _DAT_00809746 = 3;
        _boost_pressure_max_target = uVar6;
        break;
      case 2:
        _DAT_0080974a = coreTableInterpolation();
        uVar3 = (uint)_DAT_008096a8;
        if ((_DAT_0080973e < (int)uVar3) && (uVar5 <= _DAT_008071bc)) {
          uVar3 = (uint)_DAT_0080974a;
          if (_DAT_0080974a <= _DAT_008071b2) {
            _DAT_00809746 = 4;
          }
        }
        else {
          _DAT_00809746 = 1;
        }
        break;
      case 3:
        _boost_pressure_max_target = _DAT_008096a6;
        if ((uVar7 <= _DAT_008096a6) && (uVar7 = _boost_pressure_max_target, uVar6 < _DAT_008096a6))
        {
          uVar7 = uVar6;
        }
        _boost_pressure_max_target = uVar7;
        _DAT_00809746 = 5;
        break;
      case 4:
        if (uVar7 < _boost_pressure_max_target) {
          _boost_pressure_max_target = _boost_pressure_max_target - _DAT_008071b4;
        }
        uVar3 = (uint)_DAT_008096a8;
        if ((_DAT_0080973e < (int)uVar3) && (uVar5 <= _DAT_008071bc)) {
          uVar3 = (uint)_DAT_0080d0c8;
          if (_DAT_008071b8 < _DAT_0080d0c8) {
            _DAT_00809746 = 2;
          }
        }
        else {
          _DAT_00809746 = 1;
        }
        break;
      case 5:
        _DAT_00809748 = 0;
        uVar3 = (uint)_DAT_008096a8;
        if ((_DAT_0080973e < (int)uVar3) ||
           (_boost_pressure_max_target = uVar6, _DAT_008071ba < uVar5)) {
          _DAT_00809746 = 1;
          _boost_pressure_max_target = uVar6;
        }
      }
    }
    if ((DAT_0080bdc7 & 8) != 0) {
      _DAT_00809746 = 5;
    }
    if (_DAT_00809746 != 6) {
      _DAT_00809748 = 1;
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
  
  _DAT_00809746 = 1;
  _DAT_00809748 = 1;
  _boost_pressure_max_target = _DAT_00803748;
  _DAT_0080974a = _DAT_0080d0c8;
  _DAT_008032c2 = 0x64000000;
  _DAT_008032be = 0x8071b6;
  _DAT_0080973e = ((uint)_DAT_00803828 * (int)(&DAT_00006400 + _DAT_008071b0)) / 0x6400;
  if (time_duration_to_warn_driver_before_shutdown_due_to_fuel_tem_0_65535 < _DAT_0080973e) {
    _DAT_0080973e = (uint)time_duration_to_warn_driver_before_shutdown_due_to_fuel_tem_0_65535;
  }
  else {
    _DAT_0080973e = _DAT_0080973e & 0xffff;
  }
  uVar1 = ((int)(&DAT_00006400 + _DAT_008071b0) * (uint)_DAT_0080386c) / 0x6400;
  if (time_duration_to_warn_driver_before_shutdown_due_to_fuel_tem_0_65535 < uVar1) {
    _DAT_00809742 = (uint)time_duration_to_warn_driver_before_shutdown_due_to_fuel_tem_0_65535;
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
  if ((_protection_system_enable_flag == 1) &&
     (((_DAT_0080c9a6 == 9 && (cached_parameter_value < _current_fuel_demand_value)) ||
      ((_DAT_0080c9a6 != 9 &&
       ((cached_parameter_value < _DAT_00809698 || (_active_derate_value == 0)))))))) {
    _DAT_0080627e = _DAT_0080627e + 1;
    _DAT_008062a6 = _DAT_008062a6 + 1;
    FUN_0002e6c2((uint *)&DAT_0080629e,(uint *)&DAT_008062aa);
  }
  if (_DAT_0080c9a6 == 10) {
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
  if ((fuel_timing_control_value != 0) && (_DAT_008071d4 < _DAT_0080972e)) {
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
  
  if ((_DAT_008062ca < _DAT_008096a6) && (_active_derate_value != 0)) {
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
  if ((_DAT_0080cc6c == 4) && (DAT_008032c6 == '\0')) {
    _DAT_008062c2 = _DAT_008062c2 + 1;
    DAT_008032c6 = '\x01';
    DAT_008032c7 = '\0';
  }
  if ((_DAT_0080cc6c == 3) && (DAT_008032c7 == '\0')) {
    _DAT_008062c6 = _DAT_008062c6 + 1;
    DAT_008032c7 = '\x01';
    DAT_008032c6 = '\0';
  }
  if ((_DAT_0080cc6c != 4) && (_DAT_0080cc6c != 3)) {
    DAT_008032c7 = '\0';
    DAT_008032c6 = '\0';
  }
  return;
}



//
// Function: FUN_0002e8f2 @ 0x0002e8f2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0002e8f2(void)

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
    _clutch_transitions_counter_0_100 = 0;
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
  uVar2 = _diagnostic_system_flags_1 & 0x200;
  if (uVar2 != 0) {
    _DAT_0080974c = FUN_000357d2((uint)_DAT_008032c8 + (uint)_DAT_0080972e,0x20000,36000);
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
        _DAT_00809750 = FUN_000357d2(_DAT_0080974c,0x200000,_DAT_0080d46a);
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
    uVar1 = FUN_0002e6c2((uint *)&DAT_00806258,
                         (uint *)&counts_time_percent_load_is_low_for_const_freq_alg_0_100);
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
    if ((((_engine_fault_register_a & 0x100) == 0) || ((_engine_fault_register_b & 0x100) == 0)) &&
       (((_engine_fault_register_a & 0x200) == 0 || ((_engine_fault_register_b & 0x200) == 0)))) {
      _DAT_008032d2 = 0;
    }
    else if (the_minimum_time_a_fault_must_be_present_before_logged_in_trip_in_0_30 < _DAT_008032d2)
    {
      _DAT_00806278 = _DAT_00806278 | 0x13;
    }
    else {
      _DAT_008032d2 = _DAT_008032d2 + 1;
    }
    if (_DAT_00805f34 == 0) {
      if (_DAT_00806274 == 0) {
        _clutch_transitions_counter_0_100 = 0;
      }
      else {
        _clutch_transitions_counter_0_100 = 0xffffffff;
      }
    }
    else if (_DAT_00806274 / _DAT_00805f34 < 0x3ff) {
      _clutch_transitions_counter_0_100 = FUN_000357d2(_DAT_00806274,0x400000,_DAT_00805f34);
    }
    else {
      _clutch_transitions_counter_0_100 = 0xffffffff;
    }
    _DAT_00804bc0 = _DAT_00803870 + _DAT_0080626c;
    _DAT_00804bc4 = _DAT_00806274;
    if (_clutch_transitions_counter_0_100 >> 0x11 < 0x10000) {
      _DAT_00804bca = (ushort)(_clutch_transitions_counter_0_100 >> 0x11);
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
    if (_current_engine_rpm_raw != 0) {
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
  
  can1_canidmr2 = can1_canidmr2 & 0xfffb;
  _DAT_00809760 = _DAT_008071aa;
  _DAT_00809758 = _DAT_00ffff28;
  _DAT_00ffff28 = _DAT_00ffff28 & 0xffff;
  if (_engine_rpm_source_selector == 0) {
    if (_DAT_0080c758 == 0) {
      _DAT_0080975c = 0;
    }
    else {
      _DAT_0080975c = _DAT_0080c750 / _DAT_0080c758;
    }
    _DAT_0080c750 = 0;
    _DAT_0080c758 = 0;
  }
  else if (_engine_rpm_source_selector == 1) {
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
  can1_canidmr2 = can1_canidmr2 & 0xfffb;
  _DAT_00808eca = FUN_0002ed06;
  can1_cantxerr = can1_cantxerr & 0xf0ff | 0xd00;
  _DAT_00ffff22 = _DAT_0080385a << 8;
  _DAT_00ffff26 = 0;
  _DAT_00ffff28 = 0;
  _DAT_00ffff20 = 0xb;
  can1_canidar1 = can1_canidar1 & 0xffcf | 0x30;
  can1_canidar3 = can1_canidar3 & 0xffcf | 0x30;
  can1_cantbsel = can1_cantbsel & 0xfffb | 4;
  can1_canidmr1 = can1_canidmr1 & 0xffcf | 0x20;
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
// Function: FUN_0002eeac @ 0x0002eeac
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002eeac(void)

{
  bool bVar1;
  uint uVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined *puVar5;
  
  if (DAT_008032dc == '\0') {
    if (((((_engine_fault_register_a & 0x100) != 0) && ((_engine_fault_register_b & 0x100) != 0)) ||
        (((_engine_fault_register_a & 0x200) != 0 && ((_engine_fault_register_b & 0x200) != 0)))) &&
       (_DAT_0080387e < _fuel_arbitrator_threshold_2)) {
      _fuel_arbitrator_threshold_2 = _DAT_0080387e;
    }
    uVar2 = FUN_000357d2((uint)_DAT_00803748,
                         (uint)_DAT_00803828 *
                         ((uint)_DAT_0080385c * (uint)_DAT_0080374a >> 7 & 0xffff) >> 0xb & 0xffff,
                         0x100);
    uVar2 = FUN_000357d2(uVar2,8,0x3c);
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
  if (((((vp44_status_flags_2 & 0x100) != 0) && (_DAT_0080385e != 0)) && (_DAT_0080972e == 0)) &&
     ((_DAT_008071ea < _DAT_008096a6 && ((DAT_0080bdc7 & 8) == 0)))) {
    _DAT_00805fe4 = 2;
    _fuel_arbitrator_threshold_2 = _DAT_0080387e;
    _engine_fault_register_a = _engine_fault_register_a | 0x100;
    _engine_fault_register_c = _engine_fault_register_c | 0x100;
  }
  if ((((vp44_status_flags_2 & 0x200) != 0) &&
      (pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._2_2_ == 0)) &&
     ((_DAT_0080385e != 0 && (_DAT_008096a6 == 0)))) {
    if ((_DAT_008032e0 == 0) && (_derate_threshold_exceeded == 1)) {
      _DAT_00805ff4 = _DAT_00805ff4 + 1;
    }
    if (blank_spot_for_esdn_backwards_compatibility_0_0_1 < current_engine_rpm) {
      if ((~DAT_008032dd & (DAT_0080bdc7 & 8) != 0) != 0) {
        _DAT_00805ff6 = _DAT_00805ff6 + 1;
      }
      if ((~DAT_008032de & (DAT_0080bdc7 & 4) != 0) != 0) {
        _DAT_00805ff8 = _DAT_00805ff8 + 1;
      }
    }
    if ((fueling_value_above_which_wet_stack_timing_is_set_to_zero_0_100 <= _DAT_00805ff4) &&
       ((_DAT_008071d6 <= _DAT_00805ff6 || (_DAT_008071d8 <= _DAT_00805ff8)))) {
      _DAT_00805fe4 = 1;
      _fuel_arbitrator_threshold_2 = _DAT_0080387e;
      _engine_fault_register_a = _engine_fault_register_a | 0x100;
      _engine_fault_register_c = _engine_fault_register_c | 0x100;
    }
  }
  if (((_DAT_0080972e != 0) || (pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._2_2_ == 1)) ||
     (((vp44_status_flags_2 & 0x100) == 0 && ((vp44_status_flags_2 & 0x200) == 0)))) {
    if (((_engine_fault_register_a & 0x100) != 0) && ((_engine_fault_register_c & 0x100) == 0)) {
      _engine_fault_register_a = _engine_fault_register_a & 0xfeff;
      _fuel_arbitrator_threshold_2 = _oil_pressure_precrank_status;
    }
    _DAT_00805ff4 = 0;
    _DAT_00805ff8 = 0;
    _DAT_00805ff6 = 0;
  }
  if (((_DAT_0080385e != 0) && (pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._2_2_ == 0)) &&
     ((vp44_status_flags_1 & 0x80) != 0)) {
    if (((_engine_fault_register_a & 0x100) == 0) || ((_engine_fault_register_b & 0x100) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (((_engine_fault_register_a & 0x200) == 0) || ((_engine_fault_register_b & 0x200) == 0)) {
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
                    _engine_fault_register_a = _engine_fault_register_a | 0x200;
                    _engine_fault_register_c = _engine_fault_register_c | 0x200;
                    _DAT_00805fe4 = 3;
                    _fuel_arbitrator_threshold_2 = _DAT_0080387e;
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
            uVar4 = _current_engine_rpm_raw;
            _DAT_008032e6 = coreTableInterpolation();
            _DAT_008032e8 = coreTableInterpolation(0x80,uVar4,puVar5);
            if (_DAT_008071ee < _DAT_00805fe6) {
              _engine_fault_register_a = _engine_fault_register_a | 0x200;
              _engine_fault_register_c = _engine_fault_register_c | 0x200;
              _DAT_00805fe4 = 4;
              _fuel_arbitrator_threshold_2 = _DAT_0080387e;
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
            uVar4 = _current_engine_rpm_raw;
            _DAT_008032ea = coreTableInterpolation();
            _DAT_008032ec = coreTableInterpolation(0x80,uVar4,puVar5);
            if (_DAT_008071f8 < _DAT_00805fe8) {
              _engine_fault_register_a = _engine_fault_register_a | 0x200;
              _engine_fault_register_c = _engine_fault_register_c | 0x200;
              _DAT_00805fe4 = 5;
              _fuel_arbitrator_threshold_2 = _DAT_0080387e;
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
        if (((_engine_fault_register_a & 0x200) != 0) && ((_engine_fault_register_c & 0x200) == 0))
        {
          _engine_fault_register_a = _engine_fault_register_a & 0xfdff;
          _fuel_arbitrator_threshold_2 = _oil_pressure_precrank_status;
          FUN_0002ee28();
        }
      }
      else if (_DAT_008096a6 == 0 && current_engine_rpm == 0) {
        _DAT_00805fee = _DAT_00805fee + 1;
      }
      else {
        _DAT_00805fee = 0;
      }
      goto LAB_0002f5b6;
    }
  }
  if ((((vp44_status_flags_1 & 0x80) == 0) && ((_engine_fault_register_a & 0x200) != 0)) &&
     ((_engine_fault_register_c & 0x200) == 0)) {
    _engine_fault_register_a = _engine_fault_register_a & 0xfdff;
    _fuel_arbitrator_threshold_2 = _oil_pressure_precrank_status;
  }
  FUN_0002ee28();
LAB_0002f5b6:
  DAT_008032dd = -((DAT_0080bdc7 & 8) != 0) & 1;
  DAT_008032de = -((DAT_0080bdc7 & 4) != 0) & 1;
  _DAT_008032e0 = _derate_threshold_exceeded;
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
// Function: FUN_0002f662 @ 0x0002f662
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0002f662(void)

{
  ushort uVar1;
  
  uVar1 = _DAT_00809766;
  if (pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._2_2_ == 1) {
    if ((_diagnostic_system_flags_2 & 0x8000) == 0) {
      _DAT_00809766 = 0;
      _fuel_arbitrator_threshold_4 = _oil_pressure_precrank_status;
      return _diagnostic_system_flags_2 & 0x8000;
    }
    if (_DAT_00807204 <= _DAT_008096a6) {
      _DAT_00809766 = 0;
      _fuel_arbitrator_threshold_4 = _oil_pressure_precrank_status;
      return _DAT_008096a6;
    }
    if (_DAT_00809766 <= _DAT_00807206) {
      _DAT_00809766 = _DAT_00809766 + 1;
      return uVar1;
    }
    _fuel_arbitrator_threshold_4 = _DAT_0080387e;
    return _DAT_00809766;
  }
  if ((_diagnostic_system_flags_2 & 0x8000) != 0) {
    if (_DAT_00807204 <= _DAT_008096a6) {
      _DAT_00809766 = 0;
      _fuel_arbitrator_threshold_4 = _oil_pressure_precrank_status;
      return _DAT_008096a6;
    }
    if (_DAT_00809766 <= _DAT_00807206) {
      _DAT_00809766 = _DAT_00809766 + 1;
      return uVar1;
    }
    _fuel_arbitrator_threshold_4 = _DAT_0080387e;
    return _DAT_00809766;
  }
  if (_DAT_00807204 <= _DAT_008096a6) {
    _DAT_00809766 = 0;
    _fuel_arbitrator_threshold_4 = _oil_pressure_precrank_status;
    return _DAT_008096a6;
  }
  if (_DAT_00809766 <= _DAT_00807206) {
    _DAT_00809766 = _DAT_00809766 + 1;
    return uVar1;
  }
  _fuel_arbitrator_threshold_4 = _DAT_0080387e;
  return _DAT_00809766;
}



//
// Function: FUN_0002f748 @ 0x0002f748
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002f748(void)

{
  _fuel_arbitrator_threshold_4 = _oil_pressure_precrank_status;
  return;
}



//
// Function: FUN_0002f754 @ 0x0002f754
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002f754(void)

{
  if (_DAT_00808a74 < _DAT_0080c9ae) {
    _DAT_0080d488 = _DAT_0080c9ae;
    _DAT_0080c9ae = _DAT_00808a74;
    _DAT_0080c9b0 = 4;
  }
  return;
}



//
// Function: FUN_0002f778 @ 0x0002f778
//

void FUN_0002f778(void)

{
  FUN_00030cb0();
  FUN_0000ebb0();
  FUN_0000b0fe();
  FUN_00010366();
  FUN_0002bc06();
  FUN_0000a428();
  FUN_0002f754();
  FUN_00013ecc();
  FUN_000317c2();
  return;
}



//
// Function: FUN_0002f7ac @ 0x0002f7ac
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002f7ac(void)

{
  _DAT_0080d486 = _DAT_0080c9ae;
  if (_DAT_0080c9a6 == 0x1b) {
    _DAT_0080d482 = _DAT_00808a76;
    _DAT_0080c9b4 = 10;
    _DAT_0080c9b2 = 0;
  }
  else if (_DAT_0080c9a6 == 0x19) {
    _DAT_0080d482 = _DAT_00808a70;
    _DAT_0080c9b4 = 9;
    _DAT_0080c9b2 = 0;
  }
  else if (_DAT_0080c9a6 == 0x1a) {
    _DAT_0080d482 = 0;
    _DAT_0080c9b4 = 8;
    _DAT_0080c9b2 = 0;
  }
  else if ((_DAT_008035d6 & 8) == 0) {
    _DAT_0080d482 = _DAT_0080c9ae;
    _DAT_0080c9b4 = _DAT_0080c9b0;
  }
  else {
    _DAT_0080d482 = _DAT_0080381a;
    _DAT_0080c9b4 = 7;
    _DAT_0080c9b2 = 0;
  }
  _DAT_0080d48a = _DAT_0080c9b2;
  _DAT_0080c9b2 = 0;
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
  if ((_fuel_arbitrator_condition_flag == 3) && (_DAT_0080d00e < _DAT_0080d494)) {
    _DAT_0080d494 = _DAT_0080d00e;
    _DAT_0080d496 = 0x14;
  }
  return;
}



//
// Function: FUN_0002f884 @ 0x0002f884
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002f884(void)

{
  _DAT_0080d494 = max_number_of_shutdowns_before_restart_is_not_allowed_0_255;
  FUN_0000a30c();
  FUN_0000b0b0();
  FUN_0000b556();
  FUN_00018620();
  FUN_0001542a();
  FUN_0002f85c();
  FUN_0002f83e();
  FUN_0002de68();
  return;
}



//
// Function: FUN_0002f8b8 @ 0x0002f8b8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002f8b8(void)

{
  FUN_0000b528();
  FUN_0000b05c();
  dmaDescriptorSetup1();
  FUN_00018590();
  _DAT_0080d498 = max_number_of_shutdowns_before_restart_is_not_allowed_0_255;
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
// Function: FUN_0002f96e @ 0x0002f96e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002f96e(void)

{
  if (_vp44_extended_processing_enable != 0) {
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
  if (_vp44_extended_processing_enable != 0) {
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
  if (((((((_diagnostic_system_flags_1 & 0x40) != 0) && (_DAT_00803332 != 0)) &&
        (_DAT_00807944 <= _boost_pressure_feedback)) &&
       (((DAT_0080bdc7 & 4) == 0 &&
        (shutdown_threshold_for_intake_temp_fuel_50_293 < _current_engine_rpm_raw)))) &&
      (((DAT_0080bdc7 & 8) == 0 &&
       ((_DAT_0080971e == 0 || (shutdown_delay_for_engine_sync_fuel_pressure_shutdown_0_255 == 0))))
      )) && ((_DAT_008096b4 != 2 && (_DAT_008096b4 != 1)))) {
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
  if ((((_diagnostic_system_flags_1 & 0x40) != 0) && (_DAT_00803332 != 0)) && (_DAT_008096fc != 0))
  {
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
  if (_protection_system_enable_flag == 0) {
    if (shutdown_duration_threshold_for_fuel_pressure_rpm_0_65535 <= _boost_pressure_feedback) {
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
    if ((int)((uint)_boost_pressure_feedback - (uint)_target_boost_pressure_base) <
        (int)(uint)_DAT_00807350) {
      uVar1 = 6;
    }
    else if (shutdown_duration_threshold_for_fuel_pressure_rpm_0_65535 <= _boost_pressure_feedback)
    {
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
  if (_protection_system_enable_flag != 0) {
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
  if ((_protection_system_enable_flag == 0) && (_DAT_008096fc != 0)) {
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
  
  if (_protection_system_enable_flag != 0) {
    return 7;
  }
  if (_DAT_008096fc != 0) {
    return 8;
  }
  return in_D0 & 0xffff0000;
}



//
// Function: FUN_0002fce4 @ 0x0002fce4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002fce4(void)

{
  if (((_DAT_00803342 == 9) && (diagnostic_state_buffer_t_00809654.diagnostic_mode == 8)) &&
     (_diagnostic_rpm_threshold_status < _DAT_00803344)) {
    _DAT_00803340 = _DAT_00803344;
  }
  if (_DAT_0080725a < _DAT_00803340) {
    _DAT_00803340 = _DAT_00803340 - _DAT_0080725a;
  }
  else {
    _DAT_00803340 = 0;
  }
  if (((_diagnostic_rpm_threshold_status < _DAT_00803340) &&
      (diagnostic_state_buffer_t_00809654.diagnostic_mode == 8)) &&
     ((_DAT_008096aa == 0 || (_DAT_0080725c != 0)))) {
    _diagnostic_rpm_threshold_status = _DAT_00803340;
  }
  _DAT_00803342 = diagnostic_state_buffer_t_00809654.diagnostic_mode;
  _DAT_00803344 = _current_fuel_demand_value;
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
// Function: FUN_0002fd74 @ 0x0002fd74
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002fd74(void)

{
  bool bVar1;
  
  if (vp44_injection_system_active == 1) {
    _DAT_0080976c = 0;
  }
  if (_DAT_0080976c < _DAT_0080725e) {
    _DAT_0080976c = _DAT_0080976c + 1;
    if (((_DAT_00805df2 & 0x8000) == 0) || ((_DAT_008068c4 & 0x8000) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (((_DAT_00805dfe & 0x1000) == 0) || ((_DAT_008068d0 & 0x1000) == 0)) {
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
// Function: FUN_0002fe20 @ 0x0002fe20
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0002fe20(void)

{
  if ((_vp44_flag_register_1 & 0x40) != 0) {
    _DAT_00809a04 = 0;
    io_control_flags = io_control_flags & 0xf9;
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
  return _vp44_flag_register_1 & 0x40;
}



//
// Function: FUN_0002ff3a @ 0x0002ff3a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0002ff3a(void)

{
  bool bVar1;
  undefined4 in_D0;
  uint uVar2;
  uint uVar3;
  
  if ((_vp44_flag_register_1 & 0x40) == 0) {
    return CONCAT22((short)((uint)in_D0 >> 0x10),_vp44_flag_register_1) & 0xffff0040;
  }
  if ((_DAT_00807272 < _DAT_008096a6) && (_DAT_00809a04 == 4)) {
    _DAT_00809a0c = 2;
    _DAT_00809a04 = 5;
    goto LAB_000300ac;
  }
  if (((_DAT_00805dfc & 0x1000) == 0) || ((_DAT_008068ce & 0x1000) == 0)) {
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
    if (((_DAT_00805dfc & 0x800) == 0) || ((_DAT_008068ce & 0x800) == 0)) {
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
    if (((engine_operating_mode == FAULT_EMERGENCY) || (engine_operating_mode == IDLE)) &&
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
  else if (((engine_operating_mode == LOW_RPM_RUNNING) ||
           (engine_operating_mode == TRANSITIONAL_MODE_6)) && (_DAT_00809a04 == 2)) {
    _DAT_00809a04 = 3;
  }
  else if ((((engine_operating_mode == HIGH_RPM_RUNNING) ||
            (engine_operating_mode == VP44_INJECTION_ACTIVE)) ||
           ((engine_operating_mode == TRANSITIONAL_MODE_7 ||
            (engine_operating_mode == HIGH_PERFORMANCE)))) &&
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
      uVar3 = FUN_000301a6();
      break;
    case 2:
      uVar3 = FUN_00030226();
      break;
    case 3:
      uVar3 = FUN_000302c6();
      break;
    case 4:
      uVar3 = FUN_00030314();
      break;
    case 5:
      uVar3 = FUN_00030896();
    }
  }
  if (_DAT_00809a0a == 1) {
    io_control_flags = io_control_flags & 0xfb | 2;
  }
  else if (_DAT_00809a0a == 2) {
    io_control_flags = io_control_flags & 0xfd | 4;
  }
  else if (_DAT_00809a0a == 3) {
    io_control_flags = io_control_flags | 6;
  }
  else if (_DAT_00809a0a == 4) {
    io_control_flags = io_control_flags & 0xf9;
  }
  if (((_DAT_00809a0a == 1) || (_DAT_00809a0a == 2)) || (_DAT_00809a0a == 3)) {
    if (((_DAT_0080334e != 1) && (_DAT_0080334e != 2)) && (_DAT_0080334e != 3)) {
      _DAT_0080335a = _DAT_00807266;
    }
    if (_DAT_0080335a == 0) {
      io_control_flags = io_control_flags & 0xf9;
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
// Function: FUN_000301a6 @ 0x000301a6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000301a6(void)

{
  _DAT_0080337a = _DAT_00809a10;
  _DAT_008033ac = lookupTableInterpolation((short *)&DAT_00803374);
  if (_DAT_008033ac != 0) {
    _DAT_00803352 = _DAT_008033ac;
    io_control_flags = io_control_flags | 6;
    DAT_0080bdf1 = DAT_0080bdf1 | 4;
    DAT_00809a03 = DAT_00809a03 & 0xfe;
    DAT_00809a03 = DAT_00809a03 | 2;
    DAT_00803366 = 0;
    return;
  }
  _DAT_00809a0c = 6;
  io_control_flags = io_control_flags & 0xf9;
  DAT_00803366 = 1;
  return;
}



//
// Function: FUN_00030226 @ 0x00030226
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00030226(void)

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
    io_control_flags = io_control_flags & 0xf9;
    if (DAT_00803366 == '\0') {
      DAT_0080bdf1 = DAT_0080bdf1 & 0xfb;
    }
    if (_DAT_008033ac != 0) {
      DAT_00809a03 = DAT_00809a03 & 0xfd;
      DAT_00809a03 = DAT_00809a03 | 8;
    }
  }
  else {
    io_control_flags = io_control_flags | 6;
    DAT_0080bdf1 = DAT_0080bdf1 | 4;
    _DAT_00803352 = _DAT_00803352 + -1;
  }
  _DAT_00803356 = _DAT_00807260;
  _DAT_00803364 = 100;
  return;
}



//
// Function: FUN_000302c6 @ 0x000302c6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000302c6(void)

{
  io_control_flags = io_control_flags & 0xf9;
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
// Function: FUN_00030314 @ 0x00030314
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00030314(void)

{
  bool bVar1;
  byte bVar2;
  undefined2 *puVar3;
  undefined8 uVar4;
  
  if ((_DAT_00803350 != 4) && (DAT_0080bdf1 = DAT_0080bdf1 & 0xfb, _DAT_00804a0a != 0)) {
    _DAT_00809a0c = 8;
    _DAT_00804a0a = _DAT_00804a0a + -1;
    FUN_00030896();
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
        FUN_00030896();
        return;
      }
      io_control_flags = io_control_flags & 0xf9;
      return;
    }
    if ((_DAT_00807274 < _DAT_0080926e) && (_DAT_00807276 < _DAT_008033b4)) {
      _DAT_00809a0c = 7;
      FUN_00030896();
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
  if (_DAT_00807262 <= _current_fuel_demand_value) {
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
      FUN_00030896();
    }
    else {
      FUN_0003068a();
    }
  }
  else {
    _DAT_00809a0c = 9;
    FUN_00030896();
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
    uVar2 = CONCAT22(uVar1,current_engine_rpm);
    if (_DAT_0080726c < current_engine_rpm) {
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
    if ((int)(uint)current_engine_rpm < (int)uVar2) {
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
    if (uVar2 < current_engine_rpm) {
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
    if ((int)(uint)current_engine_rpm < (int)uVar2) {
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
    io_control_flags = io_control_flags & 0xf9;
    return;
  }
  if (_DAT_008033a0 == 0) {
    io_control_flags = io_control_flags | 6;
    return;
  }
  if (_DAT_00809a08 == 1) {
    io_control_flags = io_control_flags & 0xfb | 2;
    return;
  }
  io_control_flags = io_control_flags & 0xfd | 4;
  return;
}



//
// Function: FUN_00030896 @ 0x00030896
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00030896(void)

{
  _DAT_00809a04 = 5;
  io_control_flags = io_control_flags & 0xf9;
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
  
  uVar1 = _vp44_flag_register_1 & 0x40;
  if (uVar1 != 0) {
    if (((_DAT_00805df2 & 0x4000) == 0) || ((_DAT_008068c4 & 0x4000) == 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) {
      if (((_DAT_00805df2 & 0x2000) == 0) || ((_DAT_008068c4 & 0x2000) == 0)) {
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
    if (((_engine_fault_status_register_1 & 2) == 0) ||
       ((_engine_fault_confirmation_register & 2) == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    if (uVar1 == 0) {
      if (((_engine_fault_status_register_1 & 1) == 0) ||
         ((_engine_fault_confirmation_register & 1) == 0)) {
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
// Function: FUN_000309da @ 0x000309da
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_000309da(void)

{
  ushort uVar1;
  short sVar2;
  
  uVar1 = _vp44_flag_register_1 & 0x40;
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
    if (((_engine_fault_status_register_3 & 0x100) == 0) || ((_DAT_008068e8 & 0x100) == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    if (uVar1 == 0) {
      if (((_engine_fault_status_register_3 & 0x80) == 0) || ((_DAT_008068e8 & 0x80) == 0)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
      if (uVar1 == 0) {
        if (((_engine_fault_status_register_3 & 0x40) == 0) || ((_DAT_008068e8 & 0x40) == 0)) {
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
  io_control_flags = io_control_flags | 0x10;
  _DAT_008033c0 = _DAT_008077bc;
  DAT_008033bf = 1;
  DAT_008033be = 0;
  return;
}



//
// Function: FUN_00030ac0 @ 0x00030ac0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00030ac0(void)

{
  if (DAT_008077c6 != '\0') {
    if (DAT_008077c7 == '\0') {
      io_control_flags = io_control_flags & 0xef;
      return;
    }
    io_control_flags = io_control_flags | 0x10;
    return;
  }
  switch(engine_operating_mode) {
  case IDLE:
  case FAULT_EMERGENCY:
    _DAT_008033ba = 1;
    break;
  case LOW_RPM_RUNNING:
  case TRANSITIONAL_MODE_6:
  case TRANSITIONAL_MODE_7:
    _DAT_008033ba = 2;
    break;
  case HIGH_RPM_RUNNING:
  case VP44_INJECTION_ACTIVE:
    _DAT_008033ba = 3;
    break;
  case HIGH_PERFORMANCE:
    _DAT_008033ba = 4;
  }
  if (engine_control_system_ready != 0) {
    DAT_008033bf = 0;
    _DAT_008033bc = 1;
    io_control_flags = io_control_flags & 0xef;
    return;
  }
  if (_DAT_008033ba == 3) {
    if (_DAT_008033bc != 3) {
      DAT_008033be = '\x01';
      DAT_008033bf = '\x01';
      io_control_flags = io_control_flags | 0x10;
    }
  }
  else if ((_DAT_008033bc == _DAT_008033ba) && (_DAT_008033c0 != 0)) {
    _DAT_008033c0 = _DAT_008033c0 + -1;
  }
  else if (_DAT_008033ba == 1) {
    if (_DAT_008033bc == 1) {
      if (DAT_008033bf != '\0') {
        DAT_008033bf = '\0';
        io_control_flags = io_control_flags & 0xef;
      }
    }
    else {
      if (DAT_008033be == '\0') {
        _DAT_008033c0 = _DAT_008077c2;
      }
      else {
        _DAT_008033c0 = _DAT_008077c4;
      }
      io_control_flags = io_control_flags | 0x10;
      DAT_008033bf = '\x01';
    }
  }
  else if (_DAT_008033ba == 2) {
    if (_DAT_008033bc == 2) {
      if (DAT_008033bf == '\0') {
        DAT_008033bf = '\x01';
        io_control_flags = io_control_flags | 0x10;
        _DAT_008033c0 = _DAT_008077c0;
      }
      else {
        DAT_008033bf = '\0';
        io_control_flags = io_control_flags & 0xef;
        _DAT_008033c0 = _DAT_008077be;
      }
    }
    else {
      DAT_008033bf = '\0';
      io_control_flags = io_control_flags & 0xef;
      _DAT_008033c0 = _DAT_008077be;
    }
  }
  else if (_DAT_008033ba == 4) {
    DAT_008033bf = '\0';
    io_control_flags = io_control_flags & 0xef;
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
// Function: FUN_00030c78 @ 0x00030c78
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00030c78(void)

{
  undefined4 in_D0;
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = CONCAT22((short)((uint)in_D0 >> 0x10),_vp44_flag_register_1) & 0xffff0001;
  if ((_vp44_flag_register_1 & 1) != 0) {
    _DAT_008033c8 = _diagnostic_sensor_reading;
    _DAT_008033d0 = current_engine_rpm;
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
  
  uVar1 = _vp44_flag_register_1 & 1;
  if (((_vp44_flag_register_1 & 1) != 0) && (_DAT_0080c9b0 == 0)) {
    _DAT_00809a34 = _DAT_0080c9ae;
    uVar1 = _DAT_00809a32;
    if (_DAT_0080c9ae < _DAT_00809a32) {
      _DAT_0080c9ae = _DAT_00809a32;
      _DAT_0080c9b0 = 0xb;
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
  delay_before_warning_about_shutdown_from_oil_press_rpm_0_65535 = 0;
  if ((_DAT_00805670 & 1) != 0) {
    _DAT_00fff42a = ((uint)_DAT_00808934 * 8000) / 1000 << 0x10;
    return _DAT_00fff42a;
  }
  _DAT_00fff42a = _DAT_00fff42a & 0xffff0000;
  return CONCAT22((short)((uint)in_D0 >> 0x10),_DAT_00805670) & 0xffff0001;
}



//
// Function: FUN_00030d40 @ 0x00030d40
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00030d40(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = (uint)_DAT_00803880;
  if (uVar1 < 0x10) {
    uVar3 = (uint)(ushort)(_DAT_00803880 >> 0xf) << 0x10;
    switch(uVar1) {
    default:
      uVar3 = (uint)_active_derate_value * 0x50 >> 2;
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
      _DAT_00809a36 = (ushort)((uint)asthrfes_calc_input * 0x50 >> 8);
      break;
    case 9:
    case 10:
      _DAT_00809a36 = _DAT_00809a38;
      break;
    case 0xb:
    case 0xc:
    case 0xd:
      uVar3 = 0;
      _DAT_00809a36 = (ushort)((uint)param_table_aux * 0x50 >> 8);
      break;
    case 0xe:
    case 0xf:
      iVar2 = rpmFuelCalculation((uint)_current_fuel_demand_value,(int)_DAT_00807396,0x3a);
      iVar2 = (uint)current_engine_rpm + (iVar2 >> 3);
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
      iVar2 = rpmFuelCalculation((uint)_current_fuel_demand_value,(int)_DAT_00807398,0x3a);
      iVar2 = (uint)current_engine_rpm + (iVar2 >> 3);
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
      if (current_engine_rpm < _DAT_0080739a) {
        if (_DAT_00803880 == 0xe) {
          uVar3 = 0;
          _DAT_00809a36 = (ushort)((uint)asthrfes_calc_input * 0x50 >> 8);
        }
        else {
          uVar3 = 0;
          _DAT_00809a36 = (ushort)((uint)param_table_aux * 0x50 >> 8);
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
      (((_protection_system_enable_flag == 1 &&
        (diagnostic_state_buffer_t_00809654.diagnostic_mode == 0xc)) && (_active_derate_value < 0xc)
       ))))) {
    if ((_DAT_00807392 < _DAT_00809a3e) || (_DAT_0080738e < _DAT_00809a36)) {
      _DAT_00809a3c = 0x6400;
    }
    else if ((_DAT_00809a40 < _DAT_00807394) && (_DAT_00809a36 < _DAT_00807390)) {
      _DAT_00809a3c = 0;
    }
    delay_before_warning_about_shutdown_from_oil_press_rpm_0_65535 = _DAT_00809a3c;
    if ((_DAT_00805670 & 1) == 0) {
      _DAT_00fff42a = _DAT_00fff42a & 0xffff0000;
      return CONCAT22((short)(uVar3 >> 0x10),_DAT_00805670) & 0xffff0001;
    }
    _DAT_00fff42a =
         ((((uint)_DAT_00808934 * (uint)_DAT_00809a3c) / 0x6400 & 0xffff) * 8000) / 1000 & 0xffff |
         ((uint)_DAT_00808934 * 8000) / 1000 << 0x10;
    return _DAT_00fff42a;
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
    delay_before_warning_about_shutdown_from_oil_press_rpm_0_65535 = _DAT_00809a3c;
    if ((_DAT_00805670 & 1) == 0) {
      _DAT_00fff42a = _DAT_00fff42a & 0xffff0000;
      return CONCAT22(_DAT_00809a3a >> 9,_DAT_00805670) & 0xffff0001;
    }
    _DAT_00fff42a =
         ((((uint)_DAT_00808934 * (uVar1 & 0xffff)) / 0x6400 & 0xffff) * 8000) / 1000 & 0xffff |
         ((uint)_DAT_00808934 * 8000) / 1000 << 0x10;
    return _DAT_00fff42a;
  }
  if ((_DAT_00803880 == 0xe) || (_DAT_00803880 == 0xf)) {
    uVar3 = (uint)_active_derate_value * 0x50 >> 2;
    _DAT_00809a36 = (ushort)uVar3;
  }
  if (_DAT_0080738e < _DAT_00809a36) {
    _DAT_00809a3c = 0x6400;
  }
  if (_DAT_00809a36 < _DAT_00807390) {
    _DAT_00809a3c = 0;
  }
  delay_before_warning_about_shutdown_from_oil_press_rpm_0_65535 = _DAT_00809a3c;
  if ((_DAT_00805670 & 1) == 0) {
    _DAT_00fff42a = _DAT_00fff42a & 0xffff0000;
    return CONCAT22((short)(uVar3 >> 0x10),_DAT_00805670) & 0xffff0001;
  }
  _DAT_00fff42a =
       ((((uint)_DAT_00808934 * (uint)_DAT_00809a3c) / 0x6400 & 0xffff) * 8000) / 1000 & 0xffff |
       ((uint)_DAT_00808934 * 8000) / 1000 << 0x10;
  return _DAT_00fff42a;
}



//
// Function: FUN_000311ea @ 0x000311ea
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_000311ea(void)

{
  ushort uVar1;
  word wVar2;
  
  if ((_vp44_flag_register_1 & 0x100) == 0) {
    return 0;
  }
  if (((_DAT_00805df4 & 0x200) == 0) || ((_DAT_008068c6 & 0x200) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  if (uVar1 == 0) {
    if (((_DAT_00805df4 & 0x400) == 0) || ((_DAT_008068c6 & 0x400) == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    if (uVar1 == 0) {
      if (((_DAT_00805df4 & 0x2000) == 0) || ((_DAT_008068c6 & 0x2000) == 0)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
      if (uVar1 == 0) {
        wVar2 = 0;
        if (((_DAT_0080c9a6 != 0x10) ||
            (wVar2 = _diagnostic_sensor_reading, _diagnostic_sensor_reading <= _DAT_0080782a)) ||
           (wVar2 = current_engine_rpm, current_engine_rpm <= _DAT_00807828)) {
          if (_DAT_008033d6 == 0) {
            return wVar2;
          }
          _DAT_008033d6 = _DAT_008033d6 - 1;
          if (_DAT_008033d6 != 0) {
            return wVar2;
          }
          _DAT_00805df4 = _DAT_00805df4 & 0xf7ff;
          return wVar2;
        }
        if (added_to_final_fuel_command_for_cylinder_1_300_to_300 <= _DAT_008033d6) {
          return _DAT_008033d6;
        }
        _DAT_008033d6 = _DAT_008033d6 + 1;
        if (_DAT_008033d6 != added_to_final_fuel_command_for_cylinder_1_300_to_300) {
          return _DAT_008033d6;
        }
        _DAT_00805df4 = _DAT_00805df4 | 0x800;
        _DAT_00805e34 = _DAT_00805e34 | 0x800;
        return _DAT_008033d6;
      }
    }
  }
  _DAT_008033d6 = 0;
  _DAT_00805df4 = _DAT_00805df4 & 0xf7ff;
  return uVar1;
}



//
// Function: FUN_00031306 @ 0x00031306
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_00031306(void)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = _DAT_0080d04c;
  if ((_vp44_flag_register_1 & 2) == 0) {
    _engine_fault_register_a = _engine_fault_register_a & 0xdfff;
    uVar2 = 0;
  }
  else {
    if (_DAT_008093a2 == 1) {
      _DAT_0080d04c = _DAT_0080d04c | 0x10;
      _engine_fault_register_a = _engine_fault_register_a | 0x2000;
      _engine_fault_register_c = _engine_fault_register_c | 0x2000;
      return _vp44_flag_register_1 & 2;
    }
    _DAT_0080d04c = _DAT_0080d04c & 0xffef;
    uVar2 = _engine_fault_register_a & 0x2000;
    if (uVar2 != 0) {
      uVar2 = _engine_fault_register_c & 0x2000;
      if (uVar2 == 0) {
        _engine_fault_register_a = _engine_fault_register_a & 0xdfff;
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
  if ((_DAT_00803838 != 0) && ((sensor_status_register & 0x40) != 0)) {
    _DAT_008096a0 = _DAT_008096a0 | 2;
  }
  return;
}



//
// Function: FUN_000313c4 @ 0x000313c4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_000313c4(uint param_1)

{
  ushort uVar1;
  
  if (((param_1 & 0x10000) == 0) || ((_DAT_00805dfc & 0x20) != 0)) {
    io_control_flags = io_control_flags | 1;
  }
  else {
    io_control_flags = io_control_flags & 0xfe;
  }
  uVar1 = param_1._0_2_ & 2;
  if (((param_1 & 0x20000) != 0) && (uVar1 = _DAT_00805df2 & 1, (_DAT_00805df2 & 1) == 0)) {
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
  
  uVar1 = _DAT_008096b4 | _protection_system_enable_flag;
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
     ((int)(short)_retarder_mode_table_count < (int)(uint)_DAT_008096fe)) {
    _DAT_008096fe = _retarder_mode_table_count;
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
  if (((rpm_to_reach_before_for_engine_sync_fuel_pressure_errors_0_8000 < current_engine_rpm) &&
      (_diagnostic_sensor_reading < fault_when_epf_engine_sync_fuel_pressure_rpm_error_found_0_65535
      )) && (_current_fuel_demand_value <=
             time_from_fuel_temperature_overlimit_reached_to_start_of_fue_0_65535)) {
    uVar2 = 1;
  }
  else if ((current_engine_rpm <= _DAT_00803836) ||
          (time_from_fuel_temperature_overlimit_reached_to_start_of_fue_0_65535 <
           _current_fuel_demand_value)) {
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
  uVar2 = pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._2_2_ | _active_derate_value;
  if ((uVar2 == 0) &&
     ((uVar2 = DAT_0080bdc7 & 4, (DAT_0080bdc7 & 4) == 0 ||
      ((uVar2 = DAT_0080bdc7 & 4, (DAT_0080bdc7 & 4) != 0 &&
       (uVar2 = _diagnostic_system_flags_2 & 0x40, (_diagnostic_system_flags_2 & 0x40) == 0)))))) {
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
// Function: FUN_000315f6 @ 0x000315f6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000315f6(void)

{
  bool bVar1;
  
  switch(_DAT_008033de) {
  case 0:
    if (_DAT_008096fe != 0) {
      if (((_DAT_00805df4 & 0x400) == 0) && ((_DAT_00805df4 & 0x200) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((bVar1) && (fault_when_epf_engine_sync_fuel_pressure_fuel_error_found_0_65535 != 0)) {
        _DAT_008033de = 1;
        _DAT_008033d8 = 0;
      }
      else if (((uint)(&vp44_status_flags_1)[(short)((int)(uint)_DAT_0080712c >> 4)] &
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
      if (delay_after_rpm_is_reached_before_eng_sync_fuel_pressure_errors_0_8000 == 0) {
        _DAT_008033de = 0;
      }
      else {
        _DAT_008033de = 4;
        _DAT_008033d8 = 0;
      }
    }
    else if (fault_when_epf_engine_sync_fuel_pressure_fuel_error_found_0_65535 <= _DAT_008033d8) {
      _DAT_008033de = 3;
    }
    break;
  case 2:
    if (_DAT_008096fe == 0) {
      if (delay_after_rpm_is_reached_before_eng_sync_fuel_pressure_errors_0_8000 == 0) {
        _DAT_008033de = 0;
      }
      else {
        _DAT_008033de = 4;
        _DAT_008033d8 = 0;
      }
    }
    else {
      if (((_DAT_00805df4 & 0x400) == 0) && ((_DAT_00805df4 & 0x200) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((bVar1) && (fault_when_epf_engine_sync_fuel_pressure_fuel_error_found_0_65535 != 0)) {
        _DAT_008033de = 1;
        _DAT_008033d8 = 0;
      }
      else if ((_DAT_008033da != 0) &&
              ((_DAT_0080712e <= current_engine_rpm || (_DAT_008033dc != 0)))) {
        _DAT_008033de = 3;
      }
    }
    break;
  case 3:
    if (_DAT_008096fe == 0) {
      if (delay_after_rpm_is_reached_before_eng_sync_fuel_pressure_errors_0_8000 == 0) {
        _DAT_008033de = 0;
      }
      else {
        _DAT_008033de = 4;
        _DAT_008033d8 = 0;
      }
    }
    break;
  case 4:
    if (delay_after_rpm_is_reached_before_eng_sync_fuel_pressure_errors_0_8000 <= _DAT_008033d8) {
      _DAT_008033de = 0;
    }
  }
  _DAT_008033d8 = _DAT_008033d8 + 1;
  return;
}



//
// Function: FUN_00031768 @ 0x00031768
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00031768(void)

{
  undefined4 unaff_A2;
  ushort uVar1;
  
  uVar1 = (ushort)((uint)unaff_A2 >> 0x10);
  FUN_000314c6();
  FUN_000314ee();
  FUN_000315f6();
  vp44_injection_system_active = (word)(_DAT_008033de != 0);
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
  if (_DAT_0080c9a6 == 0x18) {
    _DAT_00809704 = _DAT_0080c9ae;
    _DAT_0080c9ae = _DAT_00808a72;
    _DAT_0080c9b0 = 6;
    _DAT_0080c9b2 = 0;
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
  
  vp44_injection_system_active = 0;
  FUN_000313c4((uint)in_stack_00000000);
  _DAT_008033de = 0;
  _DAT_00809700 = 5;
  _DAT_008096a2 = 5;
  return;
}



//
// Function: FUN_00031814 @ 0x00031814
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_00031814(void)

{
  bool bVar1;
  ushort uVar2;
  
  _DAT_00809706 = 0;
  _DAT_008033ee = 0;
  _DAT_008033f0 = 0;
  if (threshold_for_fuel_temperature_fuel_limiting_to_initiate_shu_0_65535 <= current_engine_rpm) {
    _DAT_008033ee = 0;
    _DAT_008033f0 = 0;
    _DAT_00809706 = 0;
    return current_engine_rpm;
  }
  if ((vp44_communication_status & 1) == 0) {
    _DAT_008033ee = 0;
    _DAT_008033f0 = 0;
    _DAT_00809706 = 0;
    return vp44_communication_status & 1;
  }
  if ((_DAT_00809712 == 1) || (_DAT_00809712 == 3)) {
    _DAT_00809706 = 1;
  }
  if (_DAT_0080926e < time_to_reach_full_derate_w_fuel_temperature_engine_prot_0_0039_256) {
    if (((_engine_fault_status_register_1 & 1) == 0) ||
       ((_engine_fault_confirmation_register & 1) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) goto LAB_000318d6;
    if (((_engine_fault_status_register_1 & 2) == 0) ||
       ((_engine_fault_confirmation_register & 2) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) ||
       ((_DAT_008033ea == 1 &&
        (time_from_fuel_temperature_overlimit_reached_to_start_of_rpm_0_65535 <= _DAT_0080926e))))
    goto LAB_000318d6;
  }
  else {
LAB_000318d6:
    _DAT_00809706 = 1;
    _DAT_008033ee = 1;
  }
  if ((_DAT_008035e0 & 0x1000) == 0) {
    if (_DAT_008091ea < minimum_temperature_threshold_for_fuel_temperature_fuel_limi_0_65535) {
      if (((_DAT_00805df2 & 0x2000) == 0) || ((_DAT_008068c4 & 0x2000) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((_DAT_00805df2 & 0x4000) == 0) || ((_DAT_008068c4 & 0x4000) == 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if ((!bVar1) &&
           ((_DAT_008033ea != 1 ||
            (_DAT_008091ea < time_to_reach_full_derate_w_fuel_temperature_engine_prot_0_0039_256))))
        goto LAB_00031956;
      }
    }
    _DAT_00809706 = 1;
    _DAT_008033ee = 1;
  }
LAB_00031956:
  if (((_DAT_008035e0 & 0x4000) != 0) && ((vp44_communication_status & 0x10) != 0)) {
    _DAT_00809706 = 1;
    _DAT_008033f0 = 1;
  }
  if (((_DAT_008035e0 & 0x400) != 0) &&
     (((DAT_0080bdcf & 1) != 0 || ((_DAT_008033ea == 1 && (_DAT_0080970e < _DAT_0080383c)))))) {
    _DAT_00809706 = 1;
  }
  if ((_DAT_008035e0 & 0x2000) != 0) {
    if ((((_DAT_00803838 == 0) || (_DAT_008096fe != 3)) ||
        (_DAT_008091ea <= shutdown_delay_for_fuel_temperature_shutdown_0_65535)) ||
       ((_DAT_0080926e <= threshold_for_fuel_temperature_rpm_limiting_to_initiate_shut_0_65535 ||
        (_DAT_00809710 < rpm_threshold_that_must_be_crossed_in_order_to_log_fuel_temp_0_4500)))) {
      if ((((_DAT_00803838 == 0) &&
           ((_DAT_008096fe == 1 &&
            (shutdown_delay_for_fuel_temperature_shutdown_0_65535 < _DAT_008091ea)))) &&
          (threshold_for_fuel_temperature_rpm_limiting_to_initiate_shut_0_65535 < _DAT_0080926e)) &&
         (rpm_threshold_that_must_be_crossed_in_order_to_log_fuel_temp_0_4500 <= _DAT_00809710)) {
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
  uVar2 = _DAT_008035e0 & 0x1000;
  if (((_DAT_008035e0 & 0x1000) == 0) &&
     (uVar2 = _DAT_00809718,
     _DAT_00809718 < minimum_threshold_for_fuel_temperature_rpm_limiting_0_65535)) {
    _DAT_00809706 = 1;
    _DAT_008033ee = 1;
  }
  return uVar2;
}



//
// Function: FUN_00031a76 @ 0x00031a76
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_00031a76(void)

{
  bool bVar1;
  
  _DAT_00809708 = 0;
  if (threshold_for_fuel_temperature_fuel_limiting_to_initiate_shu_0_65535 <= current_engine_rpm) {
    _DAT_00809708 = 0;
    return current_engine_rpm;
  }
  if ((vp44_communication_status & 1) == 0) {
    _DAT_00809708 = 0;
    return vp44_communication_status & 1;
  }
  if ((_DAT_008035e0 & 0x1000) == 0) {
    _DAT_00809708 = 0;
    return _DAT_008035e0 & 0x1000;
  }
  if ((_DAT_00809712 == 2) || (_DAT_00809712 == 3)) {
    _DAT_00809708 = 1;
  }
  if (_DAT_008091ea < minimum_temperature_threshold_for_fuel_temperature_fuel_limi_0_65535) {
    if (((_DAT_00805df2 & 0x2000) == 0) || ((_DAT_008068c4 & 0x2000) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (((_DAT_00805df2 & 0x4000) == 0) || ((_DAT_008068c4 & 0x4000) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((!bVar1) &&
         ((_DAT_008033ec == 0 ||
          (_DAT_008091ea < time_to_reach_full_derate_w_fuel_temperature_engine_prot_0_0039_256))))
      goto LAB_00031b34;
    }
  }
  _DAT_00809708 = 1;
LAB_00031b34:
  if (((_DAT_008035e0 & 0x4000) != 0) && ((vp44_communication_status & 0x10) != 0)) {
    _DAT_00809708 = 1;
  }
  if (_DAT_00809716 != 0) {
    _DAT_00809708 = 1;
  }
  if (_DAT_00809718 < minimum_threshold_for_fuel_temperature_rpm_limiting_0_65535) {
    _DAT_00809708 = 1;
  }
  return _DAT_00809718;
}



//
// Function: FUN_00031b78 @ 0x00031b78
//

void FUN_00031b78(uint param_1)

{
  byte bVar1;
  
  bVar1 = (byte)param_1;
  if (param_1._0_2_ == 0) {
    if (maximum_threshold_for_fuel_temperature_fuel_limiting_0_65535 == 0) {
      (&io_control_source_register)[(int)(param_1 & 0xffff) >> 3] =
           ~('\x01' << (bVar1 & 7)) & (&io_control_source_register)[(int)(param_1 & 0xffff) >> 3];
      return;
    }
    (&io_control_source_register)[(int)(param_1 & 0xffff) >> 3] =
         '\x01' << (bVar1 & 7) | (&io_control_source_register)[(int)(param_1 & 0xffff) >> 3];
    return;
  }
  if (maximum_threshold_for_fuel_temperature_fuel_limiting_0_65535 == 0) {
    (&io_control_source_register)[(int)(param_1 & 0xffff) >> 3] =
         '\x01' << (bVar1 & 7) | (&io_control_source_register)[(int)(param_1 & 0xffff) >> 3];
    return;
  }
  (&io_control_source_register)[(int)(param_1 & 0xffff) >> 3] =
       ~('\x01' << (bVar1 & 7)) & (&io_control_source_register)[(int)(param_1 & 0xffff) >> 3];
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
  _DAT_00809718 = minimum_threshold_for_fuel_temperature_rpm_limiting_0_65535;
  _DAT_00809710 = rpm_threshold_that_must_be_crossed_in_order_to_log_fuel_temp_0_4500;
  _DAT_0080970e = _DAT_0080383c;
  FUN_00031b78(0xf);
  FUN_00031b78(CONCAT22(_DAT_00809708,0x18));
  return;
}



//
// Function: FUN_00031c60 @ 0x00031c60
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00031c60(void)

{
  undefined2 uVar1;
  uint uVar2;
  bool bVar3;
  
  _DAT_008033ea = _DAT_00809706;
  _DAT_008033ec = _DAT_00809708;
  if (engine_operating_mode == IDLE) {
    _DAT_00809706 = 0;
    _DAT_00809708 = 0;
    FUN_00031b78(0xf);
    _DAT_0080970a = (ushort)io_control_flags;
    return (uint)io_control_flags;
  }
  FUN_00031814();
  FUN_00031b78(CONCAT22(_DAT_00809706,0xf));
  _DAT_0080970a = (ushort)io_control_flags;
  _DAT_008033e8 = _DAT_008033e6;
  bVar3 = (DAT_0080bdcf & 1) != 0;
  if ((_DAT_008035e0 & 0x400) != 0) {
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
  if ((_DAT_008035e0 & 0x800) != 0) {
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
  if ((_DAT_008035e0 & 0x2000) != 0) {
    if (((_DAT_008096fe != 3) ||
        (_DAT_008091ea <= shutdown_delay_for_fuel_temperature_shutdown_0_65535)) ||
       (_DAT_0080926e <= threshold_for_fuel_temperature_rpm_limiting_to_initiate_shut_0_65535)) {
      _DAT_00809710 = 0;
    }
    if (((_DAT_00803838 == 0) && (_DAT_008096fe != 1)) ||
       ((_DAT_008091ea <= shutdown_delay_for_fuel_temperature_shutdown_0_65535 ||
        (_DAT_0080926e <= threshold_for_fuel_temperature_rpm_limiting_to_initiate_shut_0_65535)))) {
      _DAT_00809710 = 0;
    }
    if (((_DAT_008096fe == 3) &&
        (shutdown_delay_for_fuel_temperature_shutdown_0_65535 < _DAT_008091ea)) &&
       ((threshold_for_fuel_temperature_rpm_limiting_to_initiate_shut_0_65535 < _DAT_0080926e &&
        (_DAT_00809710 < rpm_threshold_that_must_be_crossed_in_order_to_log_fuel_temp_0_4500)))) {
      _DAT_00809710 = _DAT_00809710 + 1;
    }
    if ((((_DAT_00803838 == 0) && (_DAT_008096fe == 1)) &&
        (shutdown_delay_for_fuel_temperature_shutdown_0_65535 < _DAT_008091ea)) &&
       ((threshold_for_fuel_temperature_rpm_limiting_to_initiate_shut_0_65535 < _DAT_0080926e &&
        (_DAT_00809710 < rpm_threshold_that_must_be_crossed_in_order_to_log_fuel_temp_0_4500)))) {
      _DAT_00809710 = _DAT_00809710 + 1;
    }
  }
  if (_DAT_00809714 != 0) {
    _DAT_00809714 = _DAT_00809714 + -1;
  }
  if ((_DAT_008035e0 & 0x1000) == 0) {
    if (((_DAT_00809706 == 0) || (_DAT_008033ea != 0)) ||
       (_DAT_008091ea < minimum_temperature_threshold_for_fuel_temperature_fuel_limi_0_65535)) {
      if (_DAT_00809718 < minimum_threshold_for_fuel_temperature_rpm_limiting_0_65535) {
        _DAT_00809718 = _DAT_00809718 + 1;
      }
    }
    else {
      _DAT_00809718 = 0;
    }
  }
  if (_DAT_00809706 != 0) {
    if (time_threshold_that_must_be_crossed_in_order_to_log_fuel_tempe_0_255 < _DAT_008096a6) {
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
  FUN_00031a76();
  FUN_00031b78(CONCAT22(_DAT_00809708,0x18));
  uVar1 = 0;
  _DAT_0080970c = (ushort)DAT_0080bdf1;
  if ((_DAT_00809708 != 0) && (uVar1 = 0xffff, _DAT_00805f96 != -1)) {
    _DAT_00805f96 = _DAT_00805f96 + 1;
  }
  if (_DAT_00809716 != 0) {
    _DAT_00809716 = _DAT_00809716 + -1;
  }
  uVar2 = CONCAT22(uVar1,_DAT_008035e0) & 0xffff1000;
  if ((_DAT_008035e0 & 0x1000) != 0) {
    if (((_DAT_00809708 != 0) && (_DAT_008033ec == 0)) &&
       (uVar2 = CONCAT22(uVar1,_DAT_008091ea),
       minimum_temperature_threshold_for_fuel_temperature_fuel_limi_0_65535 <= _DAT_008091ea)) {
      _DAT_00809718 = 0;
      return uVar2;
    }
    uVar2 = CONCAT22((short)(uVar2 >> 0x10),_DAT_00809718);
    if (_DAT_00809718 < minimum_threshold_for_fuel_temperature_rpm_limiting_0_65535) {
      _DAT_00809718 = _DAT_00809718 + 1;
    }
  }
  return uVar2;
}



//
// Function: FUN_00031fb8 @ 0x00031fb8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00031fb8(void)

{
  if (_vp44_extended_processing_enable == 0) {
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
      sensor_status_register = sensor_status_register | 0x10;
    }
    else if (_DAT_008033f6 == 0) {
      sensor_status_register = sensor_status_register & 0xef;
    }
    if (_DAT_008033f6 == 2) {
      if (_DAT_008033f2 < _DAT_0080734e) {
        sensor_status_register = sensor_status_register & 0xfd | 4;
        _DAT_008033f2 = _DAT_008033f2 + 1;
      }
      else {
        sensor_status_register = sensor_status_register | 6;
      }
    }
    else {
      sensor_status_register = sensor_status_register & 0xf9;
      _DAT_008033f2 = 0;
    }
    if (_DAT_008033f6 == 3) {
      sensor_status_register = sensor_status_register | 1;
    }
    else {
      sensor_status_register = sensor_status_register & 0xfe;
    }
    if (_DAT_008033f6 == 1) {
      sensor_status_register = sensor_status_register | 8;
    }
    else {
      sensor_status_register = sensor_status_register & 0xf7;
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
  if (_vp44_extended_processing_enable == 0) {
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
// Function: FUN_0003211a @ 0x0003211a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0003211a(void)

{
  ushort uVar1;
  
  uVar1 = _vp44_flag_register_1 & 0x10;
  if (uVar1 != 0) {
    if (current_engine_rpm < added_to_final_fuel_command_for_cylinder_6_300_to_300) {
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
      _DAT_0080340c = _DAT_0080340c - 1;
    }
    if (_DAT_00809b04 == 0) {
      if ((_DAT_00809b0c < (short)added_to_final_fuel_command_for_cylinder_3_300_to_300) ||
         ((_DAT_0080c9a6 != 0x10 && (_DAT_0080c9a6 != 0x13)))) {
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
        _DAT_0080340e = added_to_final_fuel_command_for_cylinder_4_300_to_300;
      }
    }
    else if (_DAT_0080340e == 0) {
      _DAT_00809b02 = _DAT_00803410;
      _DAT_00809b04 = 0;
    }
    else {
      _DAT_00809b02 = 0;
      _DAT_0080340e = _DAT_0080340e - 1;
    }
    if ((DAT_00803412 != '\0') && ((DAT_0080bdc9 & 0x20) == 0)) {
      _DAT_0080340c = added_to_final_fuel_command_for_cylinder_2_300_to_300;
    }
    _DAT_00803414 = *(short *)(&DAT_008033fc + (short)(ushort)DAT_00803413 * 2);
    if (_DAT_00803414 == 1) {
      if (_DAT_00809b06 < added_to_final_fuel_command_for_cylinder_5_300_to_300) {
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
      _engine_fault_register_a = _engine_fault_register_a & 0xfbff;
    }
    else {
      _engine_fault_register_a = _engine_fault_register_a | 0x400;
      _engine_fault_register_c = _engine_fault_register_c | 0x400;
    }
    uVar1 = (byte)-((DAT_0080bdc9 & 0x20) != 0) & 1;
    DAT_00803412 = (char)uVar1;
    if (_DAT_00809b02 == 1) {
      io_control_flags = io_control_flags | 8;
      return uVar1;
    }
    io_control_flags = io_control_flags & 0xf7;
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
  _DAT_0080341a = dzg_angular_duration_angular_high_duration_of_dzg_pulse_at_tpu_0_60._0_2_;
  _DAT_00803422 = watchdog_fueling_enforced_above_this_speed_0_to_5000;
  return;
}



//
// Function: FUN_00032380 @ 0x00032380
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00032380(void)

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
    if (dzg_angle_after_cyl_tdc_angle_after_cyl_tdc_to_put_dzg_first_60_60._2_2_ < _DAT_0080926e) {
      bVar7 = _index_of_first_tdc_after_missed_pulse_1_6 < _DAT_00803416;
      _DAT_00803416 = _DAT_00803416 + 1;
      if (bVar7) {
        _DAT_00803416 = 0;
        _DAT_0080341c = 1;
        if ((int)((uint)dzg_angular_duration_angular_high_duration_of_dzg_pulse_at_tpu_0_60._2_2_ -
                 (uint)dzg_angular_duration_angular_high_duration_of_dzg_pulse_at_tpu_0_60._0_2_) <
            0) {
          iVar3 = -((uint)dzg_angular_duration_angular_high_duration_of_dzg_pulse_at_tpu_0_60._2_2_
                   - (uint)dzg_angular_duration_angular_high_duration_of_dzg_pulse_at_tpu_0_60._0_2_
                   );
        }
        else {
          iVar3 = (uint)dzg_angular_duration_angular_high_duration_of_dzg_pulse_at_tpu_0_60._2_2_ -
                  (uint)dzg_angular_duration_angular_high_duration_of_dzg_pulse_at_tpu_0_60._0_2_;
        }
        _DAT_00803418 =
             (ushort)(iVar3 / (int)(uint)dzg_angle_after_cyl_tdc_angle_after_cyl_tdc_to_put_dzg_first_60_60
                                         ._0_2_);
        _DAT_0080341a = dzg_angular_duration_angular_high_duration_of_dzg_pulse_at_tpu_0_60._2_2_;
      }
    }
    else {
      _DAT_00803416 = 0;
    }
    break;
  case 1:
    if (_DAT_0080926e < dzg_angle_after_cyl_tdc_angle_after_cyl_tdc_to_put_dzg_first_60_60._2_2_) {
      bVar7 = _index_of_first_tdc_after_missed_pulse_1_6 < _DAT_00803416;
      _DAT_00803416 = _DAT_00803416 + 1;
      if (bVar7) {
        _DAT_00803416 = 0;
        _DAT_0080341c = 0;
        if ((int)((uint)dzg_angular_duration_angular_high_duration_of_dzg_pulse_at_tpu_0_60._2_2_ -
                 (uint)dzg_angular_duration_angular_high_duration_of_dzg_pulse_at_tpu_0_60._0_2_) <
            0) {
          iVar3 = -((uint)dzg_angular_duration_angular_high_duration_of_dzg_pulse_at_tpu_0_60._2_2_
                   - (uint)dzg_angular_duration_angular_high_duration_of_dzg_pulse_at_tpu_0_60._0_2_
                   );
        }
        else {
          iVar3 = (uint)dzg_angular_duration_angular_high_duration_of_dzg_pulse_at_tpu_0_60._2_2_ -
                  (uint)dzg_angular_duration_angular_high_duration_of_dzg_pulse_at_tpu_0_60._0_2_;
        }
        _DAT_00803418 =
             (ushort)(iVar3 / (int)(uint)dzg_angle_after_cyl_tdc_angle_after_cyl_tdc_to_put_dzg_first_60_60
                                         ._0_2_);
        _DAT_0080341a = dzg_angular_duration_angular_high_duration_of_dzg_pulse_at_tpu_0_60._0_2_;
      }
    }
    else if ((time_that_must_elasp_since_last_event_to_consider_an_abuse_0_100000._0_2_ <
              _DAT_0080926e) || (_DAT_00807d90 < _DAT_0080926e)) {
      bVar7 = _index_of_first_tdc_after_missed_pulse_1_6 < _DAT_00803416;
      _DAT_00803416 = _DAT_00803416 + 1;
      if (bVar7) {
        _DAT_00803416 = 0;
        _DAT_0080341c = 2;
        if ((int)((uint)watchdog_fueling_debounce_counts_0_to_255 -
                 (uint)dzg_angular_duration_angular_high_duration_of_dzg_pulse_at_tpu_0_60._2_2_) <
            0) {
          iVar3 = -((uint)watchdog_fueling_debounce_counts_0_to_255 -
                   (uint)dzg_angular_duration_angular_high_duration_of_dzg_pulse_at_tpu_0_60._2_2_);
        }
        else {
          iVar3 = (uint)watchdog_fueling_debounce_counts_0_to_255 -
                  (uint)dzg_angular_duration_angular_high_duration_of_dzg_pulse_at_tpu_0_60._2_2_;
        }
        _DAT_00803418 =
             (ushort)(iVar3 / (int)(uint)dzg_angle_after_cyl_tdc_angle_after_cyl_tdc_to_put_dzg_first_60_60
                                         ._0_2_);
        _DAT_0080341a = watchdog_fueling_debounce_counts_0_to_255;
      }
    }
    else {
      _DAT_00803416 = 0;
    }
    break;
  case 2:
    if ((_DAT_0080926e < time_that_must_elasp_since_last_event_to_consider_an_abuse_0_100000._0_2_)
       && (_DAT_0080926e < _DAT_00807d90)) {
      bVar7 = _index_of_first_tdc_after_missed_pulse_1_6 < _DAT_00803416;
      _DAT_00803416 = _DAT_00803416 + 1;
      if (bVar7) {
        _DAT_00803416 = 0;
        _DAT_0080341c = 1;
        if ((int)((uint)watchdog_fueling_debounce_counts_0_to_255 -
                 (uint)dzg_angular_duration_angular_high_duration_of_dzg_pulse_at_tpu_0_60._2_2_) <
            0) {
          iVar3 = -((uint)watchdog_fueling_debounce_counts_0_to_255 -
                   (uint)dzg_angular_duration_angular_high_duration_of_dzg_pulse_at_tpu_0_60._2_2_);
        }
        else {
          iVar3 = (uint)watchdog_fueling_debounce_counts_0_to_255 -
                  (uint)dzg_angular_duration_angular_high_duration_of_dzg_pulse_at_tpu_0_60._2_2_;
        }
        _DAT_00803418 =
             (ushort)(iVar3 / (int)(uint)dzg_angle_after_cyl_tdc_angle_after_cyl_tdc_to_put_dzg_first_60_60
                                         ._0_2_);
        _DAT_0080341a = dzg_angular_duration_angular_high_duration_of_dzg_pulse_at_tpu_0_60._2_2_;
      }
    }
    else if (time_abuse_event_must_be_continuously_present_before_it_will_b_0_100 < _DAT_0080926e) {
      bVar7 = _index_of_first_tdc_after_missed_pulse_1_6 < _DAT_00803416;
      _DAT_00803416 = _DAT_00803416 + 1;
      if (bVar7) {
        _DAT_00803416 = 0;
        _DAT_0080341c = 3;
        if ((int)((uint)max_allowed_fueling_at_high_rpm_and_min_throttle_0_to_200 -
                 (uint)watchdog_fueling_debounce_counts_0_to_255) < 0) {
          iVar3 = -((uint)max_allowed_fueling_at_high_rpm_and_min_throttle_0_to_200 -
                   (uint)watchdog_fueling_debounce_counts_0_to_255);
        }
        else {
          iVar3 = (uint)max_allowed_fueling_at_high_rpm_and_min_throttle_0_to_200 -
                  (uint)watchdog_fueling_debounce_counts_0_to_255;
        }
        _DAT_00803418 =
             (ushort)(iVar3 / (int)(uint)dzg_angle_after_cyl_tdc_angle_after_cyl_tdc_to_put_dzg_first_60_60
                                         ._0_2_);
        _DAT_0080341a = max_allowed_fueling_at_high_rpm_and_min_throttle_0_to_200;
      }
    }
    else {
      _DAT_00803416 = 0;
    }
    break;
  case 3:
    if (_DAT_0080926e < time_abuse_event_must_be_continuously_present_before_it_will_b_0_100) {
      bVar7 = _index_of_first_tdc_after_missed_pulse_1_6 < _DAT_00803416;
      _DAT_00803416 = _DAT_00803416 + 1;
      if (bVar7) {
        _DAT_00803416 = 0;
        _DAT_0080341c = 2;
        if ((int)((uint)max_allowed_fueling_at_high_rpm_and_min_throttle_0_to_200 -
                 (uint)watchdog_fueling_debounce_counts_0_to_255) < 0) {
          iVar3 = -((uint)max_allowed_fueling_at_high_rpm_and_min_throttle_0_to_200 -
                   (uint)watchdog_fueling_debounce_counts_0_to_255);
        }
        else {
          iVar3 = (uint)max_allowed_fueling_at_high_rpm_and_min_throttle_0_to_200 -
                  (uint)watchdog_fueling_debounce_counts_0_to_255;
        }
        _DAT_00803418 =
             (ushort)(iVar3 / (int)(uint)dzg_angle_after_cyl_tdc_angle_after_cyl_tdc_to_put_dzg_first_60_60
                                         ._0_2_);
        _DAT_0080341a = watchdog_fueling_debounce_counts_0_to_255;
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
  pointer_to_oil_pressure_fuel_fault_log_data_0_2_32._0_2_ = _DAT_00809b08;
  if (5 < amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535) {
    if ((_DAT_00805670 & 8) == 0) {
      _DAT_00fff442 = _DAT_00fff442 & 0xffff0000;
    }
    else {
      _DAT_00fff442 =
           ((((uint)_DAT_0080893a * (uint)_DAT_00809b08) / 0x6400 & 0xffff) * 8000) / 1000 & 0xffff
           | ((uint)_DAT_0080893a * 8000) / 1000 << 0x10;
    }
  }
  if (_DAT_00803424 == 0) {
    if (eps_main_lost_duration_0_20 < _DAT_00809242) {
      bVar7 = _index_of_first_tdc_after_missed_pulse_1_6 < _DAT_0080341e;
      _DAT_0080341e = _DAT_0080341e + 1;
      if (bVar7) {
        _DAT_0080341e = 0;
        _DAT_00803424 = 1;
        if ((int)((uint)default_value_for_vp44_fuel_temperature_when_sensor_is_fail_40_to_300 -
                 (uint)watchdog_fueling_enforced_above_this_speed_0_to_5000) < 0) {
          iVar3 = -((uint)default_value_for_vp44_fuel_temperature_when_sensor_is_fail_40_to_300 -
                   (uint)watchdog_fueling_enforced_above_this_speed_0_to_5000);
        }
        else {
          iVar3 = (uint)default_value_for_vp44_fuel_temperature_when_sensor_is_fail_40_to_300 -
                  (uint)watchdog_fueling_enforced_above_this_speed_0_to_5000;
        }
        _DAT_00803420 =
             (ushort)(iVar3 / (int)(uint)dzg_angle_after_cyl_tdc_angle_after_cyl_tdc_to_put_dzg_first_60_60
                                         ._0_2_);
        _DAT_00803422 = default_value_for_vp44_fuel_temperature_when_sensor_is_fail_40_to_300;
      }
    }
    else {
      _DAT_0080341e = 0;
    }
  }
  else if (_DAT_00803424 == 1) {
    if (_DAT_00809242 < eps_main_lost_duration_0_20) {
      bVar7 = _index_of_first_tdc_after_missed_pulse_1_6 < _DAT_0080341e;
      _DAT_0080341e = _DAT_0080341e + 1;
      if (bVar7) {
        _DAT_0080341e = 0;
        _DAT_00803424 = 0;
        if ((int)((uint)default_value_for_vp44_fuel_temperature_when_sensor_is_fail_40_to_300 -
                 (uint)watchdog_fueling_enforced_above_this_speed_0_to_5000) < 0) {
          iVar3 = -((uint)default_value_for_vp44_fuel_temperature_when_sensor_is_fail_40_to_300 -
                   (uint)watchdog_fueling_enforced_above_this_speed_0_to_5000);
        }
        else {
          iVar3 = (uint)default_value_for_vp44_fuel_temperature_when_sensor_is_fail_40_to_300 -
                  (uint)watchdog_fueling_enforced_above_this_speed_0_to_5000;
        }
        _DAT_00803420 =
             (ushort)(iVar3 / (int)(uint)dzg_angle_after_cyl_tdc_angle_after_cyl_tdc_to_put_dzg_first_60_60
                                         ._0_2_);
        _DAT_00803422 = watchdog_fueling_enforced_above_this_speed_0_to_5000;
      }
    }
    else if (_DAT_0080d058 < _DAT_00809242) {
      bVar7 = _index_of_first_tdc_after_missed_pulse_1_6 < _DAT_0080341e;
      _DAT_0080341e = _DAT_0080341e + 1;
      if (bVar7) {
        _DAT_0080341e = 0;
        _DAT_00803424 = 2;
        if ((int)((uint)_DAT_0080784a -
                 (uint)default_value_for_vp44_fuel_temperature_when_sensor_is_fail_40_to_300) < 0) {
          iVar3 = -((uint)_DAT_0080784a -
                   (uint)default_value_for_vp44_fuel_temperature_when_sensor_is_fail_40_to_300);
        }
        else {
          iVar3 = (uint)_DAT_0080784a -
                  (uint)default_value_for_vp44_fuel_temperature_when_sensor_is_fail_40_to_300;
        }
        _DAT_00803420 =
             (ushort)(iVar3 / (int)(uint)dzg_angle_after_cyl_tdc_angle_after_cyl_tdc_to_put_dzg_first_60_60
                                         ._0_2_);
        _DAT_00803422 = _DAT_0080784a;
      }
    }
    else {
      _DAT_0080341e = 0;
    }
  }
  else if (_DAT_00803424 == 2) {
    if (_DAT_00809242 < _DAT_0080d058) {
      bVar7 = _index_of_first_tdc_after_missed_pulse_1_6 < _DAT_0080341e;
      _DAT_0080341e = _DAT_0080341e + 1;
      if (bVar7) {
        _DAT_0080341e = 0;
        _DAT_00803424 = 1;
        if ((int)((uint)_DAT_0080784a -
                 (uint)default_value_for_vp44_fuel_temperature_when_sensor_is_fail_40_to_300) < 0) {
          iVar3 = -((uint)_DAT_0080784a -
                   (uint)default_value_for_vp44_fuel_temperature_when_sensor_is_fail_40_to_300);
        }
        else {
          iVar3 = (uint)_DAT_0080784a -
                  (uint)default_value_for_vp44_fuel_temperature_when_sensor_is_fail_40_to_300;
        }
        _DAT_00803420 =
             (ushort)(iVar3 / (int)(uint)dzg_angle_after_cyl_tdc_angle_after_cyl_tdc_to_put_dzg_first_60_60
                                         ._0_2_);
        _DAT_00803422 = default_value_for_vp44_fuel_temperature_when_sensor_is_fail_40_to_300;
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
  errors_allowed_timer_running_flag_for_oil_pres_0_1 = _DAT_00809b0a;
  if (5 < amount_of_time_since_water_in_fuel_low_failure_was_detected_0_65535) {
    uVar2 = CONCAT22((short)(uVar2 >> 0x10),_DAT_00805670) & 0xffff0004;
    if ((_DAT_00805670 & 4) != 0) {
      _DAT_00fff43a =
           ((((uint)_DAT_00808938 * (uint)_DAT_00809b0a) / 0x6400 & 0xffff) * 8000) / 1000 & 0xffff
           | ((uint)_DAT_00808938 * 8000) / 1000 << 0x10;
      return _DAT_00fff43a;
    }
    _DAT_00fff43a = _DAT_00fff43a & 0xffff0000;
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
// Function: FUN_00032b16 @ 0x00032b16
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00032b16(void)

{
  _DAT_00809b0e = _DAT_0080972e - _DAT_0080342e;
  _DAT_00809b0c = FUN_00035608();
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
  
  if ((((vp44_status_flags_2 & 0x8000) != 0) && ((_DAT_00803430 & 0x400) != 0)) &&
     ((_DAT_00803430 & 0x800) == 0)) {
    _DAT_00803438 = _DAT_00803806;
    return _DAT_00803430 & 0x800;
  }
  if ((((_DAT_00803430 & 0x80) != 0) && ((_DAT_00803430 & 0x40) == 0)) &&
     (((_DAT_00803430 & 0x400) == 0 && (((_DAT_00803430 & 8) == 0 && ((_DAT_00803430 & 2) == 0))))))
  {
    _DAT_00803438 = _DAT_00803706;
    return _DAT_00803430 & 2;
  }
  uVar1 = _DAT_00803430 & 0x200;
  if ((uVar1 != 0) &&
     ((((uVar1 = _DAT_00803430 & 0x100, uVar1 == 0 && (uVar1 = _DAT_00803430 & 0x400, uVar1 == 0))
       && (uVar1 = _DAT_00803430 & 8, uVar1 == 0)) && (uVar1 = _DAT_00803430 & 2, uVar1 == 0)))) {
    _DAT_00803438 = _DAT_0080370a;
  }
  return uVar1;
}



//
// Function: FUN_00032c1c @ 0x00032c1c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00032c1c(void)

{
  bool bVar1;
  
  _DAT_00803430 = _DAT_00803430 * 2 & 0x2aaaa;
  if ((sensor_status_register & 2) != 0) {
    _DAT_00803430 = _DAT_00803430 | 1;
  }
  if ((sensor_status_register & 8) != 0) {
    _DAT_00803430 = _DAT_00803430 | 4;
  }
  if ((sensor_status_register & 0x10) != 0) {
    _DAT_00803430 = _DAT_00803430 | 0x10;
  }
  if ((sensor_status_register & 1) != 0) {
    _DAT_00803430 = _DAT_00803430 | 0x40;
  }
  if ((sensor_status_register & 4) != 0) {
    _DAT_00803430 = _DAT_00803430 | 0x100;
  }
  if ((sensor_status_register & 0x20) != 0) {
    _DAT_00803430 = _DAT_00803430 | 0x400;
  }
  if ((DAT_0080bdc8 & 0x10) != 0) {
    _DAT_00803430 = _DAT_00803430 | 0x1000;
  }
  if ((DAT_0080bdc7 & 8) != 0) {
    _DAT_00803430 = _DAT_00803430 | 0x10000;
  }
  if ((DAT_0080bdc7 & 4) != 0) {
    _DAT_00803430 = _DAT_00803430 | 0x4000;
  }
  switch(_DAT_0080d17c) {
  case 0:
    if ((((_diagnostic_system_flags_1 & 0x10) == 0) || (_DAT_0080343e <= _DAT_00808932)) ||
       (_DAT_0080343c == 0)) {
      if ((((_DAT_00808932 < _DAT_00803440) && (_DAT_0080343a == 0)) ||
          ((_DAT_008037f8 < _DAT_008096a6 ||
           (((_engine_fault_register_a & 0x200) != 0 && ((_engine_fault_register_b & 0x200) != 0))))
          )) || (((_engine_fault_register_a & 0x100) != 0 &&
                 ((_engine_fault_register_b & 0x100) != 0)))) {
        _DAT_0080d17c = 2;
      }
      else if ((_DAT_0080343a == 0) || (_DAT_00803440 <= _DAT_00808932)) {
        if ((_DAT_00803430 & 0x1000) == 0) {
          _DAT_00803440 = _DAT_00803440 + 1;
          _DAT_0080343e = 0;
        }
        else {
          _DAT_0080343e = _DAT_0080343e + 1;
          _DAT_00803440 = 0;
          if (((_DAT_00803430 & 0x2000) == 0) && (_DAT_0080343c < _DAT_008037fc)) {
            _DAT_0080343c = _DAT_0080343c + 1;
          }
        }
      }
      else {
        _DAT_0080d17c = 3;
        _DAT_00803438 = _DAT_0080343a;
      }
    }
    else {
      _DAT_0080d17c = 1;
      _DAT_00803438 = **(ushort **)(&DAT_00803442 + (short)_DAT_0080343c * 4);
    }
    break;
  case 1:
    if ((_DAT_00803430 & 0x1000) == 0) {
      _DAT_0080d17c = 0;
      _DAT_0080343c = 0;
    }
    else if ((_DAT_008037f8 < _DAT_008096a6) ||
            (((_engine_fault_register_a & 0x100) != 0 && ((_engine_fault_register_b & 0x100) != 0)))
            ) {
      _DAT_0080d17c = 2;
    }
    else {
      _DAT_00803440 = 0;
      _DAT_0080343e = 0;
      _DAT_0080343c = 0;
    }
    break;
  case 2:
    if (((_DAT_008096a6 < _DAT_008037f8) && (_DAT_0080892c <= current_engine_rpm)) &&
       (current_engine_rpm <= _DAT_0080892a)) {
      if (((_engine_fault_register_a & 0x200) == 0) || ((_engine_fault_register_b & 0x200) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((_engine_fault_register_a & 0x100) == 0) || ((_engine_fault_register_b & 0x100) == 0))
        {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if ((!bVar1) && ((_DAT_00803430 & 0x1000) != 0)) {
          _DAT_0080d17c = 0;
          _DAT_0080343c = _DAT_0080343c + 1;
          break;
        }
      }
    }
    if (((((_diagnostic_system_flags_1 & 0x10) != 0) && ((_DAT_00803430 & 0x10) != 0)) &&
        (_DAT_008096a6 <= _DAT_008037f8)) &&
       ((_DAT_0080892c <= current_engine_rpm && (current_engine_rpm <= _DAT_0080892a)))) {
      if (((_engine_fault_register_a & 0x200) == 0) || ((_engine_fault_register_b & 0x200) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((_engine_fault_register_a & 0x100) == 0) || ((_engine_fault_register_b & 0x100) == 0))
        {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if ((((!bVar1) && (((_DAT_00803430 & 0x4000) == 0 || ((vp44_status_flags_2 & 0x1000) == 0)))
             ) && (((_DAT_00803430 & 0x10000) == 0 || ((vp44_status_flags_2 & 0x800) == 0)))) &&
           (((((_DAT_00803430 & 0x80) != 0 && ((_DAT_00803430 & 0x40) == 0)) ||
             (((_DAT_00803430 & 0x200) != 0 && ((_DAT_00803430 & 0x100) == 0)))) ||
            ((((_DAT_00803430 & 0x800) == 0 && ((_DAT_00803430 & 0x400) != 0)) &&
             ((vp44_status_flags_2 & 0x8000) != 0)))))) {
          _DAT_0080d17c = 3;
          if ((_DAT_00803430 & 0x400) == 0) {
            if (((_DAT_00803430 & 0x80) == 0) || ((_DAT_00803430 & 0x40) != 0)) {
              if (((_DAT_00803430 & 0x200) != 0) && ((_DAT_00803430 & 0x100) == 0)) {
                _DAT_00803438 = _DAT_0080370a;
              }
            }
            else {
              _DAT_00803438 = _DAT_00803706;
            }
          }
          break;
        }
      }
    }
    _DAT_00803434 = 0;
    _DAT_0080343c = 0;
    _DAT_00803440 = 0;
    _DAT_0080343e = 0;
    _DAT_0080343a = 0;
    break;
  case 3:
    if (_DAT_008096a6 <= _DAT_008037f8) {
      if (((_engine_fault_register_a & 0x200) == 0) || ((_engine_fault_register_b & 0x200) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((_engine_fault_register_a & 0x100) == 0) || ((_engine_fault_register_b & 0x100) == 0))
        {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if ((!bVar1) && ((_DAT_00803430 & 0x1000) != 0)) {
          _DAT_0080d17c = 0;
          _DAT_0080343c = _DAT_0080343c + 1;
          _DAT_0080343a = _DAT_00803438;
          break;
        }
      }
    }
    if ((((((_DAT_00803430 & 0x10) == 0) || (_DAT_008037f8 < _DAT_008096a6)) ||
         (((_engine_fault_register_a & 0x100) != 0 && ((_engine_fault_register_b & 0x100) != 0))))
        || (((vp44_status_flags_2 & 0x1000) != 0 && ((_DAT_00803430 & 0x4000) != 0)))) ||
       (((vp44_status_flags_2 & 0x800) != 0 && ((_DAT_00803430 & 0x10000) != 0)))) {
      _DAT_0080d17c = 2;
    }
    else {
      _DAT_00803440 = 0;
      _DAT_0080343e = 0;
      _DAT_0080343c = 0;
      FUN_00032b72();
      if ((_DAT_00803430 & 1) == 0) {
        if ((_DAT_00803430 & 4) == 0) {
          if (((_DAT_00803430 & 2) != 0) || ((_DAT_00803430 & 8) != 0)) {
            _DAT_00803438 = current_engine_rpm;
            if (fsmxthfl_calc_input <= _current_fuel_demand_value) {
              _DAT_00803438 =
                   (short)(((uint)(ushort)(_current_fuel_demand_value - fsmxthfl_calc_input) *
                           (uint)_oil_pressure_cal_factor_3) / 0x1d70) + current_engine_rpm;
            }
            if (_DAT_008036a2 < _DAT_00803438) {
              _DAT_00803438 = _DAT_008036a2;
            }
            else if (_DAT_00803438 < _DAT_008037fa) {
              _DAT_00803438 = _DAT_008037fa;
            }
          }
        }
        else if (_DAT_00803438 < (ushort)(_DAT_00808924 + _DAT_008037fa)) {
          _DAT_00803438 = _DAT_008037fa;
        }
        else {
          _DAT_00803438 = _DAT_00803438 - _DAT_00808924;
        }
      }
      else if ((ushort)(_DAT_008036a2 - _DAT_00808924) < _DAT_00803438) {
        _DAT_00803438 = _DAT_008036a2;
      }
      else {
        _DAT_00803438 = _DAT_00808924 + _DAT_00803438;
      }
    }
  }
  if (((ushort)(_DAT_008037f6 + _DAT_00803436) < _DAT_00803438) && (_DAT_00803434 == 0)) {
    _DAT_00803436 = _DAT_008037f6 + _DAT_00803436;
  }
  else {
    _DAT_00803436 = _DAT_00803438;
    _DAT_00803434 = 1;
  }
  pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._0_2_ = _DAT_00803436;
  if ((_DAT_0080d17c != 3) && (_DAT_0080d17c != 1)) {
    pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._2_2_ = 0;
    return;
  }
  pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._2_2_ = 1;
  return;
}



//
// Function: FUN_00033254 @ 0x00033254
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00033254(void)

{
  _DAT_0080d17c = 2;
  pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._2_2_ = 0;
  pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._0_2_ = 0;
  _DAT_00803442 = 0x8036a0;
  _DAT_00803446 = 0x8036a0;
  _DAT_0080344a = 0x8037fe;
  _DAT_0080344e = 0x803800;
  _DAT_00803452 = 0x803802;
  _DAT_00803456 = 0x803804;
  _DAT_0080343a = 0;
  _DAT_00803440 = 0;
  _DAT_0080343e = 0;
  _DAT_0080343c = 0;
  _DAT_00803434 = 0;
  _DAT_00803436 = 0;
  _DAT_00803432 = _DAT_00803432 | 0x2000;
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
  engine_control_system_ready = 0;
  vp44_fso_fault_active_flag = 0;
  vp44_fso_fault_detection_enable = 1;
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
  _DAT_0080345c = &temporary_timing_command_at_idle_for_static_timing_check_0_100;
  _DAT_00803462 = 2;
  _DAT_00803464 = &fuel_limit_when_timing_fault_is_active_0_to_300;
  _DAT_0080346a = &max_112_messages_received_after_pump_should_be_off_for_stuck_0_to_255;
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
  _DAT_00805e14 = _DAT_00805e14 & 0xfb6e;
  _DAT_00803494 = 0x28f0000;
  _DAT_00803490 = 0x807404;
  _DAT_0080349c = 0x28f0000;
  _DAT_00803498 = 0x807404;
  FUN_00035548();
  return;
}



//
// Function: FUN_00033524 @ 0x00033524
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00033524(void)

{
  bool bVar1;
  word wVar2;
  byte bVar3;
  undefined **ppuVar4;
  undefined *local_2a;
  undefined2 local_26;
  undefined *puStack_24;
  undefined1 local_6;
  undefined1 uStack_5;
  
  ppuVar4 = (undefined **)&stack0xffffffe0;
  if (DAT_00809af1 == '\0') {
    bVar3 = 0;
  }
  else {
    bVar3 = DAT_00809af1 - 1;
  }
  if (maximum_increase_in_timing_command_allowed_per_loop_0_to_60 < _current_engine_fuel_demand) {
    DAT_008034a7 = DAT_008034a7 + 1;
    wVar2 = maximum_increase_in_timing_command_allowed_per_loop_0_to_60;
    if ((byte)in_range_fuel_temp_fault_enabled_when_coolant_temp_is_above_50_to_255 < DAT_008034a7)
    {
      _DAT_00805e14 = _DAT_00805e14 | 0x400;
      _DAT_00805e54 = _DAT_00805e54 | 0x400;
      DAT_008034a7 = 0;
    }
  }
  else {
    DAT_008034a7 = 0;
    wVar2 = _current_engine_fuel_demand;
  }
  local_6 = (undefined1)((uint)((int)(uint)wVar2 >> 1) >> 8);
  DAT_00809a98 = local_6;
  uStack_5 = (undefined1)((int)(uint)wVar2 >> 1);
  DAT_00809a97 = uStack_5;
  if ((short)maximum_decrease_in_timing_command_allowed_per_loop_0_to_60 < (short)_DAT_00809a52) {
    DAT_008034a9 = DAT_008034a9 + 1;
    wVar2 = maximum_decrease_in_timing_command_allowed_per_loop_0_to_60;
    if ((byte)in_range_fuel_temp_fault_enabled_when_coolant_temp_is_above_50_to_255 < DAT_008034a9)
    {
      _DAT_00805e14 = _DAT_00805e14 | 0x400;
      _DAT_00805e54 = _DAT_00805e54 | 0x400;
      DAT_008034a9 = 0;
    }
  }
  else if ((short)_DAT_00809a52 <
           (short)pump_ram_address_contents_requested_below_this_speed_0_to_5000) {
    DAT_008034a8 = DAT_008034a8 + 1;
    wVar2 = pump_ram_address_contents_requested_below_this_speed_0_to_5000;
    if ((byte)in_range_fuel_temp_fault_enabled_when_coolant_temp_is_above_50_to_255 < DAT_008034a8)
    {
      _DAT_00805e14 = _DAT_00805e14 | 0x400;
      _DAT_00805e54 = _DAT_00805e54 | 0x400;
      DAT_008034a8 = 0;
    }
  }
  else {
    DAT_008034a9 = 0;
    DAT_008034a8 = 0;
    wVar2 = _DAT_00809a52;
  }
  local_6 = (undefined1)(wVar2 >> 8);
  DAT_00809a96 = local_6;
  uStack_5 = (undefined1)wVar2;
  DAT_00809a95 = uStack_5;
  if ((short)_debounce_for_fuel_quantity_feedback_pulse_fault_detection_0_to_255 <
      (short)_DAT_0080739e) {
    DAT_008034ab = DAT_008034ab + 1;
    wVar2 = _debounce_for_fuel_quantity_feedback_pulse_fault_detection_0_to_255;
    if ((byte)in_range_fuel_temp_fault_enabled_when_coolant_temp_is_above_50_to_255 < DAT_008034ab)
    {
      _DAT_00805e14 = _DAT_00805e14 | 0x400;
      _DAT_00805e54 = _DAT_00805e54 | 0x400;
      DAT_008034ab = 0;
    }
  }
  else if ((short)_DAT_0080739e <
           (short)feedback_pulse_fault_disabled_when_fueling_is_below_this_para_0_to_300) {
    DAT_008034aa = DAT_008034aa + 1;
    wVar2 = feedback_pulse_fault_disabled_when_fueling_is_below_this_para_0_to_300;
    if ((byte)in_range_fuel_temp_fault_enabled_when_coolant_temp_is_above_50_to_255 < DAT_008034aa)
    {
      _DAT_00805e14 = _DAT_00805e14 | 0x400;
      _DAT_00805e54 = _DAT_00805e54 | 0x400;
      DAT_008034aa = 0;
    }
  }
  else {
    DAT_008034ab = 0;
    DAT_008034aa = 0;
    wVar2 = _DAT_0080739e;
  }
  local_6 = (undefined1)(wVar2 >> 8);
  DAT_00809a94 = local_6;
  uStack_5 = (undefined1)wVar2;
  DAT_00809a93 = uStack_5;
  if ((&DAT_00809aea)[(short)(ushort)bVar3] == '\0') {
    _DAT_00809a54 = 0;
  }
  else {
    _DAT_00809a54 = _DAT_00809a6c + *(short *)(&DAT_00809a7c + (short)(ushort)bVar3 * 2);
    if ((int)(uint)intercept_used_to_convert_final_timing_to_vp44_units_360_to_360 <
        (int)(short)_DAT_00809a54) {
      DAT_008034a6 = DAT_008034a6 + 1;
      if ((byte)in_range_fuel_temp_fault_enabled_when_coolant_temp_is_above_50_to_255 < DAT_008034a6
         ) {
        _DAT_00805e14 = _DAT_00805e14 | 0x400;
        _DAT_00805e54 = _DAT_00805e54 | 0x400;
        DAT_008034a6 = 0;
      }
      _DAT_00809a54 = intercept_used_to_convert_final_timing_to_vp44_units_360_to_360;
    }
    else if ((short)_DAT_00809a54 < 0) {
      DAT_008034a5 = DAT_008034a5 + 1;
      if ((byte)in_range_fuel_temp_fault_enabled_when_coolant_temp_is_above_50_to_255 < DAT_008034a5
         ) {
        _DAT_00805e14 = _DAT_00805e14 | 0x400;
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
  _DAT_00805f8c = _DAT_00805f8c + (uint)_current_fuel_demand_value;
  puStack_24 = (undefined *)0x3381e;
  FUN_00035488();
  if (((_DAT_00805e14 & 0x20) == 0) || ((_DAT_008068e6 & 0x20) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    puStack_24 = &DAT_00809a8c;
    local_26 = 2;
    ppuVar4 = &local_2a;
    local_2a = &DAT_00ffc800;
    FUN_0001913e();
  }
  if ((_DAT_008073b2 <= _current_engine_fuel_demand) &&
     (_current_engine_fuel_demand <= _DAT_008073b0)) {
    *(undefined4 *)((int)ppuVar4 + -4) = 0x33876;
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
  DAT_00809aa1 = *(byte *)(param_1 + 7);
  DAT_00809aa2 = *(undefined1 *)(param_1 + 8);
  DAT_00809aa3 = *(undefined1 *)(param_1 + 9);
  DAT_00809aa4 = *(byte *)(param_1 + 10);
  DAT_00809aa5 = *(undefined1 *)(param_1 + 0xb);
  DAT_00809aa6 = *(undefined1 *)(param_1 + 0xc);
  DAT_00809aa7 = *(undefined1 *)(param_1 + 0xd);
  DAT_00809aa8 = *(undefined1 *)(param_1 + 0xe);
  DAT_00809a5e = DAT_00809aa2;
  vp44_status_register = DAT_00809aa1;
  DAT_00809af0 = (undefined1)((int)(DAT_00809aa4 & 0xe0) >> 5);
  local_6 = CONCAT11(DAT_00809aa4,DAT_00809aa3) & 0x1fff;
  _DAT_00809a5c = local_6;
  local_6 = CONCAT11(DAT_00809aa6,DAT_00809aa5);
  _DAT_00809a4e = local_6 << 2;
  _engine_rpm_calculation_param_3 = _DAT_00809a4e;
  _engine_fault_timer_3 = _DAT_00807cde;
  local_6 = CONCAT11(DAT_00809aa8,DAT_00809aa7);
  iVar1 = (short)local_6 * 0xe66;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0x7ff;
  }
  _DAT_00809a58 = (short)(iVar1 >> 0xb) + -0x1cb6;
  uVar2 = vp44_communication_status & 1;
  if (((vp44_communication_status & 1) == 0) &&
     (uVar2 = _current_engine_fuel_demand,
     _current_engine_fuel_demand < pump_ram_address_contents_requested_above_this_speed_0_to_5000))
  {
    DAT_0080348a = 1;
    DAT_0080348b = DAT_0080348b + '\x01';
    _engine_fault_timer_3 = _DAT_00807cde;
    return _current_engine_fuel_demand;
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
// Function: FUN_00033c48 @ 0x00033c48
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00033c48(void)

{
  undefined8 uVar1;
  
  _DAT_0080c9c8 = _current_fuel_demand_value;
  _DAT_00803460 = _current_engine_fuel_demand;
  _DAT_00803468 = _current_fuel_demand_value;
  uVar1 = tableInterpolationLookup(_DAT_0080346e);
  _DAT_00809a6c = (short)((ulonglong)uVar1 >> 0x20);
  return;
}



//
// Function: FUN_00033c84 @ 0x00033c84
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00033c84(void)

{
  short sVar1;
  ushort uVar2;
  undefined8 uVar3;
  
  _DAT_00803478 = _current_engine_fuel_demand;
  _DAT_00803480 = _current_fuel_demand_value;
  uVar3 = tableInterpolationLookup(_DAT_00803486);
  _DAT_00809a5a = (short)((ulonglong)uVar3 >> 0x20);
  uVar2 = _DAT_00807400;
  if ((vp44_fso_circuit_fault_flag == 0) && (uVar2 = _DAT_0080d482, DAT_0080348e != '\0')) {
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
       lift_pump_run_time_when_stopping_after_cranking_0_to_120 +
       (short)((int)(((int)(short)lift_pump_on_time_duration_during_cranking_0_to_120 -
                     (int)(short)lift_pump_run_time_when_stopping_after_cranking_0_to_120) *
                    ((uint)_current_engine_fuel_demand -
                    (uint)_flag_to_override_prime_pump_control_0_to_ff)) /
              (int)((uint)lift_pump_run_time_when_stopping_after_running_0_to_120 -
                   (uint)_flag_to_override_prime_pump_control_0_to_ff));
  return;
}



//
// Function: FUN_00033dca @ 0x00033dca
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00033dca(void)

{
  if (_derate_threshold_exceeded == 0) {
    sim_data_direction_control = sim_data_direction_control & 0xbf;
  }
  else {
    sim_data_direction_control = sim_data_direction_control | 0x40;
  }
  if ((_derate_threshold_exceeded != _DAT_008034ae) && (DAT_008034a4 < 2)) {
    DAT_008034a4 = DAT_008034a4 + 1;
  }
  _DAT_008034ae = _derate_threshold_exceeded;
  return;
}



//
// Function: FUN_00033e0e @ 0x00033e0e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00033e0e(void)

{
  bool bVar1;
  int iVar2;
  
  if (vp44_fso_fault_detection_enable != 0) {
    if ((vp44_status_register & 0x20) == 0) {
      DAT_008034b5 = DAT_008034b5 + 1;
      if (DAT_008073b5 <= DAT_008034b5) {
        _DAT_00805e14 = _DAT_00805e14 & 0xfff7;
        DAT_008034b5 = 0;
      }
      DAT_008034b4 = 0;
    }
    else {
      DAT_008034b4 = DAT_008034b4 + 1;
      if (DAT_008073b5 <= DAT_008034b4) {
        _DAT_00805e14 = _DAT_00805e14 | 8;
        _DAT_00805e54 = _DAT_00805e54 | 8;
        DAT_008034b4 = 0;
      }
      DAT_008034b5 = 0;
    }
    if ((vp44_status_register & 0x40) == 0) {
      DAT_008034b7 = DAT_008034b7 + 1;
      if (DAT_008073b5 <= DAT_008034b7) {
        _engine_fault_status_register_3 = _engine_fault_status_register_3 & 0xff7f;
        DAT_008034b7 = 0;
      }
      DAT_008034b6 = 0;
    }
    else {
      DAT_008034b6 = DAT_008034b6 + 1;
      if (DAT_008073b5 <= DAT_008034b6) {
        _engine_fault_status_register_4 = _engine_fault_status_register_4 | 0x80;
        _engine_fault_status_register_3 = _engine_fault_status_register_3 & 0xfeff | 0x80;
        DAT_008034b6 = 0;
      }
      DAT_008034b7 = 0;
    }
    if (((vp44_status_register & 0x20) == 0) || ((vp44_status_register & 0x40) == 0)) {
      if (_DAT_008073c2 < _DAT_00809a58) {
        DAT_008034b8 = DAT_008034b8 + 1;
        if (DAT_008073b5 <= DAT_008034b8) {
          _engine_fault_status_register_4 = _engine_fault_status_register_4 | 0x40;
          _engine_fault_status_register_3 = _engine_fault_status_register_3 & 0xfeff | 0x40;
          DAT_008034b8 = 0;
        }
      }
      else {
        DAT_008034b8 = 0;
      }
    }
    if (((_engine_fault_status_register_3 & 0x80) == 0) || ((_DAT_008068e8 & 0x80) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (((_DAT_00805e14 & 8) == 0) || ((_DAT_008068e6 & 8) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((_engine_fault_status_register_3 & 0x800) == 0) || ((_DAT_008068e8 & 0x800) == 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (!bVar1) {
          if (((_engine_fault_status_register_3 & 0x400) == 0) || ((_DAT_008068e8 & 0x400) == 0)) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          if (!bVar1) {
            if (((_engine_fault_status_register_3 & 0x200) == 0) || ((_DAT_008068e8 & 0x200) == 0))
            {
              bVar1 = false;
            }
            else {
              bVar1 = true;
            }
            if (((!bVar1) && (_DAT_00809a58 < _DAT_008073c4)) && (_DAT_008073b8 < _DAT_0080926e)) {
              if (_DAT_00809a58 == _DAT_008034b0) {
                DAT_008034ba = DAT_008034ba + 1;
                if (_DAT_008073c6 <= DAT_008034ba) {
                  _engine_fault_status_register_3 = _engine_fault_status_register_3 | 0x100;
                  _engine_fault_status_register_4 = _engine_fault_status_register_4 | 0x100;
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
        _engine_fault_status_register_3 = _engine_fault_status_register_3 & 0xffbf;
        DAT_008034b9 = 0;
      }
    }
    else {
      DAT_008034b9 = 0;
    }
    if (((_engine_fault_status_register_3 & 0x100) != 0) && ((_DAT_008068e8 & 0x100) != 0)) {
      if ((int)_DAT_00809a58 - (int)_DAT_008034b2 < 0) {
        iVar2 = -((int)_DAT_00809a58 - (int)_DAT_008034b2);
      }
      else {
        iVar2 = (int)_DAT_00809a58 - (int)_DAT_008034b2;
      }
      if ((int)(uint)_DAT_008073c8 < iVar2) {
        _engine_fault_status_register_3 = _engine_fault_status_register_3 & 0xfeff;
      }
    }
    if (((_engine_fault_status_register_3 & 0x80) == 0) || ((_DAT_008068e8 & 0x80) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    _DAT_00809a48 = 0x1700;
    if ((bVar1) && (_DAT_0080740a < 0x1700)) {
      _DAT_00809a48 = _DAT_0080740a;
    }
    if (((_engine_fault_status_register_3 & 0x40) == 0) || ((_DAT_008068e8 & 0x40) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) && (_DAT_0080740c < _DAT_00809a48)) {
      _DAT_00809a48 = _DAT_0080740c;
    }
    if (((_engine_fault_status_register_3 & 0x100) == 0) || ((_DAT_008068e8 & 0x100) == 0)) {
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
  if (vp44_fso_fault_detection_enable != 0) {
    if ((vp44_status_register & 1) != 0) {
      if ((_debounce_counts_for_vp44_micro_error_0_to_255 < _current_engine_fuel_demand) &&
         (_current_engine_fuel_demand <= _debounce_for_vp44_fso_circuit_fault_detection_0_to_255)) {
        vp44_fso_range1_fault_counter = vp44_fso_range1_fault_counter + 1;
        if (DAT_00807425 <= vp44_fso_range1_fault_counter) {
          _engine_fault_status_register_3 = _engine_fault_status_register_3 | 0x20;
          _engine_fault_status_register_4 = _engine_fault_status_register_4 | 0x20;
          vp44_fso_fault_active_flag = 1;
          vp44_fso_circuit_fault_flag = 1;
          vp44_fso_range1_fault_counter = 0;
        }
      }
      else if (_debounce_for_vp44_fso_circuit_fault_detection_0_to_255 < _current_engine_fuel_demand
              ) {
        vp44_fso_range2_fault_counter = vp44_fso_range2_fault_counter + 1;
        if (vp44_fso_stuck_low_detection_disabled_above_this_fueling_0_to_300._0_1_ <=
            vp44_fso_range2_fault_counter) {
          _engine_fault_status_register_3 = _engine_fault_status_register_3 | 0x20;
          _engine_fault_status_register_4 = _engine_fault_status_register_4 | 0x20;
          vp44_fso_fault_active_flag = 1;
          vp44_fso_circuit_fault_flag = 1;
          vp44_fso_range2_fault_counter = 0;
        }
      }
      else {
        vp44_fso_range1_fault_counter = 0;
        vp44_fso_range2_fault_counter = 0;
      }
      vp44_fso_recovery_counter = 0;
      return;
    }
    vp44_fso_recovery_counter = vp44_fso_recovery_counter + 1;
    if (DAT_00807425 <= vp44_fso_recovery_counter) {
      _engine_fault_status_register_3 = _engine_fault_status_register_3 & 0xffdf;
      vp44_fso_circuit_fault_flag = 0;
      vp44_fso_recovery_counter = 0;
    }
    vp44_fso_range1_fault_counter = 0;
    vp44_fso_range2_fault_counter = 0;
  }
  return;
}



//
// Function: vp44FsoCircuitFaultDetectionBit1 @ 0x000342f6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44FsoCircuitFaultDetectionBit1(void)

{
  if (vp44_fso_fault_detection_enable != 0) {
    if ((vp44_status_register & 2) != 0) {
      if ((_debounce_counts_for_vp44_micro_error_0_to_255 < _current_engine_fuel_demand) &&
         (_current_engine_fuel_demand <= _debounce_for_vp44_fso_circuit_fault_detection_0_to_255)) {
        vp44_fso_bit1_range1_fault_counter = vp44_fso_bit1_range1_fault_counter + 1;
        if (DAT_00807425 <= vp44_fso_bit1_range1_fault_counter) {
          _engine_fault_status_register_3 = _engine_fault_status_register_3 | 0x10;
          _engine_fault_status_register_4 = _engine_fault_status_register_4 | 0x10;
          _DAT_00809af8 = target_angle_during_which_sync_pulse_is_held_low_0_to_120;
          vp44_fso_bit1_range1_fault_counter = 0;
        }
      }
      else if (_debounce_for_vp44_fso_circuit_fault_detection_0_to_255 < _current_engine_fuel_demand
              ) {
        vp44_fso_bit1_range2_fault_counter = vp44_fso_bit1_range2_fault_counter + 1;
        if (vp44_fso_stuck_low_detection_disabled_above_this_fueling_0_to_300._0_1_ <=
            vp44_fso_bit1_range2_fault_counter) {
          _engine_fault_status_register_3 = _engine_fault_status_register_3 | 0x10;
          _engine_fault_status_register_4 = _engine_fault_status_register_4 | 0x10;
          _DAT_00809af8 = target_angle_during_which_sync_pulse_is_held_low_0_to_120;
          vp44_fso_bit1_range2_fault_counter = 0;
        }
      }
      else {
        vp44_fso_bit1_range1_fault_counter = 0;
        vp44_fso_bit1_range2_fault_counter = 0;
      }
      vp44_fso_bit1_recovery_counter = 0;
      return;
    }
    vp44_fso_bit1_recovery_counter = vp44_fso_bit1_recovery_counter + 1;
    if (DAT_00807425 <= vp44_fso_bit1_recovery_counter) {
      _engine_fault_status_register_3 = _engine_fault_status_register_3 & 0xffef;
      _DAT_00809af8 = 0x1700;
      vp44_fso_bit1_recovery_counter = 0;
    }
    vp44_fso_bit1_range1_fault_counter = 0;
    vp44_fso_bit1_range2_fault_counter = 0;
  }
  return;
}



//
// Function: FUN_000343f8 @ 0x000343f8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000343f8(void)

{
  if (vp44_fso_fault_detection_enable != 0) {
    if ((vp44_status_register & 0x10) != 0) {
      if ((_reserved_location_for_future_pump_setup_information_0_to_ff <
           _current_engine_fuel_demand) &&
         (_current_engine_fuel_demand <=
          vp44_fso_stuck_low_detection_enabled_above_this_speed_0_to_5000)) {
        DAT_008034c1 = DAT_008034c1 + 1;
        if (DAT_00807424 <= DAT_008034c1) {
          _engine_fault_status_register_3 = _engine_fault_status_register_3 | 8;
          _engine_fault_status_register_4 = _engine_fault_status_register_4 | 8;
          DAT_008034c1 = 0;
        }
      }
      else if (vp44_fso_stuck_low_detection_enabled_above_this_speed_0_to_5000 <
               _current_engine_fuel_demand) {
        DAT_008034c2 = DAT_008034c2 + 1;
        if ((byte)vp44_fso_stuck_low_detection_disabled_above_this_fueling_0_to_300 <= DAT_008034c2)
        {
          _engine_fault_status_register_3 = _engine_fault_status_register_3 | 8;
          _engine_fault_status_register_4 = _engine_fault_status_register_4 | 8;
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
    if ((vp44_status_register & 8) == 0) {
      DAT_008034c3 = DAT_008034c3 + 1;
      if (DAT_00807425 <= DAT_008034c3) {
        _engine_fault_status_register_3 = _engine_fault_status_register_3 & 0xfff7;
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
  
  if (vp44_fso_fault_detection_enable != 0) {
    _DAT_00809afa = coreTableInterpolation();
    sVar1 = _DAT_00809afa;
    if (_DAT_00809a4e != 0) {
      sVar1 = coreTableInterpolation();
    }
    _DAT_00809af4 = sVar1;
    _DAT_00809afc = _DAT_00809afa - _DAT_00809af4;
    if (((_engine_fault_status_register_3 & 0x800) == 0) || ((_DAT_008068e8 & 0x800) == 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) {
      if (((_engine_fault_status_register_3 & 0x400) == 0) || ((_DAT_008068e8 & 0x400) == 0)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (!bVar2) {
        if (((_engine_fault_status_register_3 & 0x200) == 0) || ((_DAT_008068e8 & 0x200) == 0)) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if (!bVar2) {
          if ((vp44_status_register & 0x80) == 0) {
            _DAT_00805e14 = _DAT_00805e14 & 0xfffb;
            DAT_008034c4 = 0;
          }
          else {
            DAT_008034c4 = DAT_008034c4 + 1;
            if (DAT_00807403 <= DAT_008034c4) {
              _DAT_00805e14 = _DAT_00805e14 | 4;
              _DAT_00805e54 = _DAT_00805e54 | 4;
              DAT_008034c4 = 0;
            }
          }
          if (((_DAT_00805e14 & 4) == 0) || ((_DAT_008068e6 & 4) == 0)) {
            bVar2 = false;
          }
          else {
            bVar2 = true;
          }
          if (!bVar2) {
            switch(engine_operating_mode) {
            case LOW_RPM_RUNNING:
            case TRANSITIONAL_MODE_6:
            case TRANSITIONAL_MODE_7:
              if (max_retarded_timing_allowed_to_detect_static_timing_erro_0_to_ffffffff._2_2_ <
                  _DAT_00809afc) {
                DAT_008034c6 = DAT_008034c6 + 1;
                if (DAT_00807402 <= DAT_008034c6) {
                  _DAT_00805e14 = _DAT_00805e14 | 2;
                  _DAT_00805e54 = _DAT_00805e54 | 2;
                  DAT_008034c6 = 0;
                }
                DAT_008034c8 = 0;
              }
              else {
                if ((_DAT_00809afc <
                     min_retarded_timing_allowed_to_detect_static_timing_erro_0_to_ffffffff._2_2_)
                   && (DAT_008034c8 = DAT_008034c8 + 1, DAT_00807402 <= DAT_008034c8)) {
                  _DAT_00805e14 = _DAT_00805e14 & 0xfffd;
                  DAT_008034c8 = 0;
                }
                DAT_008034c6 = 0;
              }
              DAT_008034c5 = 0;
              DAT_008034c7 = 0;
              return;
            case HIGH_RPM_RUNNING:
              if (max_retarded_timing_allowed_to_detect_static_timing_erro_0_to_ffffffff._0_2_ <
                  _DAT_00809afc) {
                DAT_008034c5 = DAT_008034c5 + 1;
                if (DAT_00807402 <= DAT_008034c5) {
                  _DAT_00805e14 = _DAT_00805e14 | 2;
                  _DAT_00805e54 = _DAT_00805e54 | 2;
                  DAT_008034c5 = 0;
                }
                DAT_008034c7 = 0;
              }
              else {
                if ((_DAT_00809afc <
                     min_retarded_timing_allowed_to_detect_static_timing_erro_0_to_ffffffff._0_2_)
                   && (DAT_008034c7 = DAT_008034c7 + 1, DAT_00807402 <= DAT_008034c7)) {
                  _DAT_00805e14 = _DAT_00805e14 & 0xfffd;
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
// Function: FUN_00034782 @ 0x00034782
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00034782(void)

{
  bool bVar1;
  ushort uVar2;
  
  if (vp44_fso_fault_detection_enable == 0) {
    return;
  }
  if ((((DAT_00809a5e & 1) == 0) ||
      (_DAT_00809a68 <= (short)lift_pump_off_time_duration_during_cranking_0_to_120)) ||
     ((int)(uint)_DAT_00809af6 <= (int)_DAT_00809a68)) {
    _engine_fault_status_register_3 = _engine_fault_status_register_3 & 0xfffd;
    DAT_008034ce = 0;
  }
  else {
    DAT_008034ce = DAT_008034ce + 1;
    if ((byte)lift_pump_run_time_after_key_on_0_to_120 <= DAT_008034ce) {
      _engine_fault_status_register_3 = _engine_fault_status_register_3 | 2;
      _engine_fault_status_register_4 = _engine_fault_status_register_4 | 2;
      DAT_008034ce = 0;
    }
  }
  if ((DAT_008073ef != '\0') && (DAT_008034c9 == '\0')) {
    if ((((slope_used_to_convert_final_timing_to_vp44_units_50_to_50 < _DAT_0080926e) &&
         ((_DAT_008073dc < _current_engine_fuel_demand &&
          (_current_engine_fuel_demand < _DAT_008073da)))) &&
        (_current_fuel_demand_value < _DAT_008073d8)) && (_derate_threshold_exceeded == 0)) {
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
          _DAT_00805e14 = _DAT_00805e14 | 0x40;
          _DAT_00805e54 = _DAT_00805e54 | 0x40;
        }
        else if ((_DAT_008073ce < _DAT_00809a76) && (_DAT_00809a76 < _DAT_008073ca)) {
          _DAT_00805e14 = _DAT_00805e14 & 0xffbf;
        }
      }
    }
    else {
      _DAT_008034ca = 0;
      _DAT_008034cc = 0;
    }
  }
  if (((_DAT_00805e14 & 0x40) == 0) || ((_DAT_008068e6 & 0x40) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if (((_engine_fault_status_register_3 & 2) == 0) || ((_DAT_008068e8 & 2) == 0)) {
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
// Function: FUN_00034976 @ 0x00034976
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00034976(void)

{
  if (vp44_fso_fault_detection_enable != 0) {
    if ((DAT_00809a5e & 4) != 0) {
      if ((_DAT_008073b6 < _current_fuel_demand_value) &&
         (time_period_to_disable_imt_epf_due_to_exh_brake_0_65535 < _DAT_00809af4)) {
        _DAT_008034d0 = _DAT_008034d0 + 1;
        if (DAT_008073b4 < _DAT_008034d0) {
          _engine_fault_status_register_3 = _engine_fault_status_register_3 | 1;
          _engine_fault_status_register_4 = _engine_fault_status_register_4 | 1;
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
      _engine_fault_status_register_3 = _engine_fault_status_register_3 & 0xfffe;
      _DAT_00809a44 = 0x1700;
      _DAT_008034d2 = 0;
    }
    _DAT_008034d0 = 0;
  }
  return;
}



//
// Function: FUN_00034a32 @ 0x00034a32
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00034a32(void)

{
  bool bVar1;
  
  if (vp44_fso_fault_detection_enable == 0) {
    return;
  }
  if ((DAT_00809a5e & 0x20) == 0) {
    DAT_008034d8 = DAT_008034d8 + 1;
    if (DAT_00807425 < DAT_008034d8) {
      _DAT_00805e14 = _DAT_00805e14 & 0x7fff;
      _DAT_00809a4a = 0x1700;
      DAT_008034d8 = 0;
    }
    _DAT_008034d4 = 0;
    _DAT_008034d6 = 0;
    return;
  }
  if (engine_operating_mode == IDLE) {
    DAT_008034d8 = 0;
    return;
  }
  if (engine_operating_mode == FAULT_EMERGENCY) {
    DAT_008034d8 = 0;
    return;
  }
  if (((_engine_fault_status_register_1 & 0x1000) == 0) ||
     ((_engine_fault_confirmation_register & 0x1000) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if (((_engine_fault_status_register_1 & 0x4000) == 0) ||
       ((_engine_fault_confirmation_register & 0x4000) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      _DAT_008034d4 = _DAT_008034d4 + 1;
      if (in_range_fuel_temp_fault_enabled_when_coolant_temp_is_above_50_to_255._0_1_ <
          _DAT_008034d4) {
        _DAT_00805e14 = _DAT_00805e14 | 0x8000;
        _DAT_00805e54 = _DAT_00805e54 | 0x8000;
        _DAT_008034d4 = 0;
      }
      goto LAB_00034af2;
    }
  }
  _DAT_008034d4 = 0;
LAB_00034af2:
  _DAT_008034d6 = _DAT_008034d6 + 1;
  if (in_range_fuel_temp_fault_enabled_when_coolant_temp_is_above_50_to_255._0_1_ < _DAT_008034d6) {
    _DAT_00809a4a = _DAT_008073f0;
    _DAT_008034d6 = 0;
  }
  DAT_008034d8 = 0;
  return;
}



//
// Function: FUN_00034b46 @ 0x00034b46
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00034b46(void)

{
  bool bVar1;
  
  if ((vp44_fso_fault_detection_enable != 0) && (1 < DAT_008034a4)) {
    if (((_engine_fault_status_register_3 & 0x800) == 0) || ((_DAT_008068e8 & 0x800) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (((_engine_fault_status_register_3 & 0x400) == 0) || ((_DAT_008068e8 & 0x400) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((_engine_fault_status_register_3 & 0x200) == 0) || ((_DAT_008068e8 & 0x200) == 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (!bVar1) {
          if ((vp44_status_register & 4) != 0) {
            if (_derate_threshold_exceeded != 0) {
              if (required_change_to_clear_in_range_fuel_temp_fault_0_to_300 <
                  _current_engine_fuel_demand) {
                _DAT_008034da = _DAT_008034da + 1;
                if (DAT_008073de < _DAT_008034da) {
                  _DAT_00805e14 = _DAT_00805e14 | 0x4000;
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
              _DAT_00805e14 = _DAT_00805e14 & 0xdfff;
              _DAT_008034e0 = 0;
            }
            _DAT_008034da = 0;
            return;
          }
          if (_derate_threshold_exceeded == 0) {
            if (required_change_to_clear_in_range_fuel_temp_fault_0_to_300 <
                _current_engine_fuel_demand) {
              _DAT_008034de = _DAT_008034de + 1;
              if (DAT_008073de < _DAT_008034de) {
                _DAT_00805e14 = _DAT_00805e14 | 0x2000;
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
              _DAT_00805e14 = _DAT_00805e14 | 0x2000;
              _DAT_00805e54 = _DAT_00805e54 | 0x2000;
              _DAT_008034de = 0;
            }
            _DAT_008034e0 = 0;
            return;
          }
          _DAT_008034e0 = _DAT_008034e0 + 1;
          if (DAT_008073de < _DAT_008034e0) {
            _DAT_00805e14 = _DAT_00805e14 & 0xbfff;
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
// Function: FUN_00034d16 @ 0x00034d16
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00034d16(void)

{
  if (vp44_fso_fault_detection_enable != 0) {
    if ((DAT_00809a5e & 8) != 0) {
      _DAT_008034e2 = _DAT_008034e2 + 1;
      if (DAT_008073ba < _DAT_008034e2) {
        _DAT_00805e14 = _DAT_00805e14 | 0x1000;
        _DAT_00805e54 = _DAT_00805e54 | 0x1000;
        _DAT_008034e2 = 0;
      }
      _DAT_008034e4 = 0;
      return;
    }
    _DAT_008034e4 = _DAT_008034e4 + 1;
    if (DAT_008073ba < _DAT_008034e4) {
      _DAT_00805e14 = _DAT_00805e14 & 0xefff;
      _DAT_008034e4 = 0;
    }
    _DAT_008034e2 = 0;
  }
  return;
}



//
// Function: FUN_00034d9e @ 0x00034d9e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00034d9e(void)

{
  bool bVar1;
  
  if (vp44_fso_fault_detection_enable != 0) {
    if ((DAT_00809a5e & 0x80) == 0) {
      _DAT_00805e12 = _DAT_00805e12 & 0xf7ff;
    }
    else {
      if (((_DAT_00805e14 & 0x400) == 0) || ((_DAT_008068e6 & 0x400) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((_engine_fault_status_register_3 & 0x800) == 0) || ((_DAT_008068e8 & 0x800) == 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (!bVar1) {
          if (((_engine_fault_status_register_3 & 0x400) == 0) || ((_DAT_008068e8 & 0x400) == 0)) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          if (!bVar1) {
            if (((_engine_fault_status_register_3 & 0x200) == 0) || ((_DAT_008068e8 & 0x200) == 0))
            {
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
// Function: FUN_00034e7a @ 0x00034e7a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00034e7a(void)

{
  bool bVar1;
  int iVar2;
  
  if (vp44_fso_fault_detection_enable == 0) {
    return;
  }
  if (_DAT_008034a2 < fuel_temp_in_range_fault_detection_enabled_below_this_value_40_to_400) {
    _DAT_008034a2 = _DAT_008034a2 + 1;
  }
  if (((_DAT_00805e12 & 0x800) == 0) || ((_DAT_008068e4 & 0x800) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if (((_engine_fault_status_register_3 & 0x800) == 0) || ((_DAT_008068e8 & 0x800) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (((_engine_fault_status_register_3 & 0x400) == 0) || ((_DAT_008068e8 & 0x400) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((_engine_fault_status_register_3 & 0x200) == 0) || ((_DAT_008068e8 & 0x200) == 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (!bVar1) {
          if ((((_DAT_00809a54 == 0) &&
               (fuel_is_limited_to_this_when_fuel_temp_sensor_faults_are_acti_0_to_300 <
                _current_engine_fuel_demand)) &&
              (requested_location_on_pump_cam_for_soi_100_to_100 < _DAT_00809a5c)) &&
             (DAT_008034e6 = DAT_008034e6 + 1, DAT_0080739c <= DAT_008034e6)) {
            _DAT_00805e14 = _DAT_00805e14 | 1;
            _DAT_00805e54 = _DAT_00805e54 | 1;
            vp44_fso_fault_active_flag = 1;
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
    if (((_engine_fault_status_register_3 & 0x800) == 0) || ((_DAT_008068e8 & 0x800) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (((_engine_fault_status_register_3 & 0x400) == 0) || ((_DAT_008068e8 & 0x400) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((_engine_fault_status_register_3 & 0x200) == 0) || ((_DAT_008068e8 & 0x200) == 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (!bVar1) {
          if (_current_engine_fuel_demand <=
              upper_limit_for_abnormally_high_fuel_temp_fault_40_to_300) {
            return;
          }
          if ((int)((uint)_current_engine_fuel_demand - (uint)_DAT_00809a4e) < 0) {
            iVar2 = -((uint)_current_engine_fuel_demand - (uint)_DAT_00809a4e);
          }
          else {
            iVar2 = (uint)_current_engine_fuel_demand - (uint)_DAT_00809a4e;
          }
          if (iVar2 <= (int)(uint)target_angular_position_of_sync_pulse_after_tdc_0_to_60) {
            return;
          }
          if ((byte)(DAT_008034e7 + 1) < DAT_0080739c) {
            DAT_008034e7 = DAT_008034e7 + 1;
            return;
          }
          _DAT_00805e12 = _DAT_00805e12 | 0x8000;
          _DAT_00805e52 = _DAT_00805e52 | 0x8000;
          vp44_fso_fault_active_flag = 1;
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
  if (vp44_fso_fault_detection_enable != 0) {
    if (((DAT_00809a6b & 1) == 0) && ((DAT_00809a6b & 2) == 0)) {
      _DAT_00805e14 = _DAT_00805e14 & 0xfdff;
      _DAT_00809a46 = 0x1700;
    }
    else {
      _DAT_00805e14 = _DAT_00805e14 | 0x200;
      _DAT_00805e54 = _DAT_00805e54 | 0x200;
      _DAT_00809a46 = _DAT_008073e2;
    }
    if ((DAT_00809a6b & 4) == 0) {
      _DAT_00805e14 = _DAT_00805e14 & 0xfeff;
      _DAT_00809a42 = 0x1700;
    }
    else {
      _DAT_00805e14 = _DAT_00805e14 | 0x100;
      _DAT_00805e54 = _DAT_00805e54 | 0x100;
      _DAT_00809a42 = _DAT_008073e0;
    }
    if ((DAT_00809a6b & 8) != 0) {
      _DAT_00805e14 = _DAT_00805e14 | 0x80;
      _DAT_00805e54 = _DAT_00805e54 | 0x80;
      vp44_fso_fault_active_flag = 1;
    }
    if ((DAT_00809a6b & 0x10) != 0) {
      _DAT_00805e14 = _DAT_00805e14 | 0x10;
      _DAT_00805e54 = _DAT_00805e54 | 0x10;
      vp44_fso_fault_active_flag = 1;
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
// Function: FUN_00035228 @ 0x00035228
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00035228(void)

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
  
  if (vp44_fso_fault_detection_enable != 0) {
    if (((_DAT_00805e14 & 0x20) == 0) || ((_DAT_008068e6 & 0x20) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (DAT_0080348a != '\0') {
        _engine_fault_status_register_3 = _engine_fault_status_register_3 & 0xf1ff;
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
          _engine_fault_status_register_3 = _engine_fault_status_register_3 | 0x800;
          _engine_fault_status_register_4 = _engine_fault_status_register_4 | 0x800;
          break;
        case 2:
          _engine_fault_status_register_3 = _engine_fault_status_register_3 | 0x200;
          _engine_fault_status_register_4 = _engine_fault_status_register_4 | 0x200;
          break;
        case 4:
        case 5:
          _engine_fault_status_register_3 = _engine_fault_status_register_3 | 0x400;
          _engine_fault_status_register_4 = _engine_fault_status_register_4 | 0x400;
          break;
        default:
          _engine_fault_status_register_3 = _engine_fault_status_register_3 | 0x800;
          _engine_fault_status_register_4 = _engine_fault_status_register_4 | 0x800;
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
// Function: FUN_000353ec @ 0x000353ec
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte FUN_000353ec(void)

{
  byte bVar1;
  
  bVar1 = DAT_0080348b;
  if (lift_pump_run_time_after_key_on_0_to_120._0_1_ < DAT_0080348b) {
    _DAT_00805e12 = _DAT_00805e12 | 0x1000;
    _DAT_00805e52 = _DAT_00805e52 | 0x1000;
    DAT_0080348b = lift_pump_run_time_after_key_on_0_to_120._0_1_;
    return bVar1;
  }
  if ((vp44_communication_status & 1) == 0) {
    _DAT_00805e12 = _DAT_00805e12 & 0xefff;
  }
  return vp44_communication_status & 1;
}



//
// Function: FUN_0003544a @ 0x0003544a
//

void FUN_0003544a(void)

{
  engine_control_system_ready = (ushort)vp44_fso_fault_active_flag;
  if (((engine_operating_mode != HIGH_PERFORMANCE) && (engine_operating_mode != FAULT_EMERGENCY)) &&
     (vp44_fso_fault_active_flag != 1)) {
    vp44_fso_fault_detection_enable = 1;
    return;
  }
  vp44_fso_fault_detection_enable = 0;
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
  uVar2 = _vp44_flag_register_1 & 0x2000;
  if ((((((_vp44_flag_register_1 & 0x2000) != 0) && (_fuel_arbitrator_condition_flag != 1)) &&
       (_fuel_arbitrator_condition_flag != 2)) &&
      ((pointer_to_oil_pressure_rpm_limit_threshold_0_2_32._2_2_ == 0 &&
       (_protection_system_enable_flag == 0)))) &&
     ((_derate_threshold_exceeded == 0 &&
      ((uVar2 = _DAT_00809b00, _DAT_008077b8 < _DAT_00809b00 &&
       (uVar2 = _current_engine_fuel_demand, _DAT_008077ba < _current_engine_fuel_demand)))))) {
    if (_DAT_008034e8 < _DAT_008077b6) {
      _DAT_008034e8 = _DAT_008034e8 + 1;
      return uVar1;
    }
    _DAT_00805e14 = _DAT_00805e14 | 0x20;
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
  _DAT_00805e14 = _DAT_00805e14 & 0xffdf;
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
// Function: FUN_00035608 @ 0x00035608
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
// Function: FUN_000357d2 @ 0x000357d2
//

undefined4 FUN_000357d2(uint param_1,uint param_2,uint param_3)

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



// Export complete - 766 functions processed
