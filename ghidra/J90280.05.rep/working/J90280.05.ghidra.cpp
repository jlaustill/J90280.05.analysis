// Ghidra C++ Decompilation Export - J90280.05 Firmware
// Generated with renamed functions, variables, and meaningful types
// Sat Aug 23 14:35:43 MDT 2025


//
// Function: FUN_00008000 @ 0x00008000
//

/* WARNING: Control flow encountered bad instruction data */

void FUN_00008000(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//
// Function: FUN_0000a16a @ 0x0000a16a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000a16a(void)

{
  _DAT_008091ca = _DAT_0080c406 - sensor_data_buffer._12_2_;
  sensor_data_buffer._12_2_ = _DAT_0080c406;
  _DAT_008091cc = FUN_00035608();
  if (_DAT_008091cc < _DAT_008062fa) {
    _DAT_008091cc = _DAT_008062fa;
    sensor_data_buffer._42_4_ = _DAT_008062fa * 0x10000 + -0x80000000;
  }
  else if (_DAT_008062f8 < _DAT_008091cc) {
    _DAT_008091cc = _DAT_008062f8;
    sensor_data_buffer._42_4_ = _DAT_008062f8 * 0x10000 + -0x80000000;
  }
  _DAT_008091ce = FUN_00035608();
  return;
}



//
// Function: FUN_0000a204 @ 0x0000a204
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0000a204(void)

{
  ushort uVar1;
  
  uVar1 = _DAT_008035da & 0x1000;
  if ((_DAT_008035da & 0x1000) != 0) {
    if (_DAT_008062d8 < _DAT_008091cc) {
      _DAT_008091da = 1;
      sensor_data_buffer._2_2_ = _DAT_008062fe;
    }
    else if (sensor_data_buffer._2_2_ == 0) {
      _DAT_008091da = 0;
    }
    else {
      sensor_data_buffer._2_2_ = sensor_data_buffer._2_2_ + -1;
    }
    if ((((_DAT_008091e0 == 0) || (_DAT_008091da != 0)) || (_DAT_0080c406 < _DAT_008062dc)) ||
       ((_DAT_008062d8 < _DAT_008091cc || (_DAT_008091ce < _DAT_008062da)))) {
      if (_DAT_008091de == 0) {
        if (sensor_data_buffer._6_2_ == 0) {
          _DAT_008091d0 = 0;
        }
        else {
          sensor_data_buffer._6_2_ = sensor_data_buffer._6_2_ + -1;
        }
      }
      else {
        _DAT_008091d0 = 1;
        sensor_data_buffer._6_2_ = _DAT_008062d4;
      }
    }
    else {
      _DAT_008091d0 = 1;
      sensor_data_buffer._6_2_ = _DAT_008062d4;
    }
    if (_DAT_008091d0 == 1) {
      sensor_data_buffer._20_2_ = _DAT_0080c406;
      _DAT_008091c4 = FUN_00035560((short *)(sensor_data_buffer + 0xe));
      return _DAT_008091c4;
    }
    uVar1 = _DAT_008091c4;
    if (_DAT_008091c4 < _DAT_00807f3c) {
      uVar1 = _DAT_008062d6 + _DAT_008091c4;
      _DAT_008091c4 = uVar1;
      if (_DAT_00807f3c < uVar1) {
        _DAT_008091c4 = _DAT_00807f3c;
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
  
  uVar1 = _DAT_008035da & 0x2000;
  if ((_DAT_008035da & 0x2000) != 0) {
    if (_DAT_00806302 < (short)_DAT_008091cc) {
      _DAT_008091dc = 1;
      sensor_data_buffer._4_2_ = _DAT_00806300;
    }
    else if (sensor_data_buffer._4_2_ == 0) {
      _DAT_008091dc = 0;
    }
    else {
      sensor_data_buffer._4_2_ = sensor_data_buffer._4_2_ + -1;
    }
    uVar1 = _DAT_008091cc;
    if ((((_DAT_008091e0 == 0) || (_DAT_008091dc != 0)) ||
        (uVar1 = _DAT_0080926e, _DAT_0080926e <= _DAT_008062ea)) ||
       ((uVar1 = _DAT_008091cc, _DAT_00806302 < (short)_DAT_008091cc ||
        (uVar1 = _DAT_008091ce, (short)_DAT_008091ce < _DAT_008062f0)))) {
      if (_DAT_008091de == 0) {
        if (sensor_data_buffer._8_2_ == 0) {
          _DAT_008091d2 = 0;
        }
        else {
          sensor_data_buffer._8_2_ = sensor_data_buffer._8_2_ + -1;
        }
      }
      else {
        _DAT_008091d2 = 1;
        sensor_data_buffer._8_2_ = _DAT_008062ec;
      }
    }
    else {
      _DAT_008091d2 = 1;
      sensor_data_buffer._8_2_ = _DAT_008062ec;
    }
    if (_DAT_008091d2 == 1) {
      sensor_data_buffer._32_2_ = _DAT_0080c406;
      _DAT_008091c6 = FUN_00035560((short *)(sensor_data_buffer + 0x1a));
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
  
  uVar1 = _DAT_008035da & 0x4000;
  if ((_DAT_008035da & 0x4000) != 0) {
    if (_DAT_008062e8 < (short)_DAT_008091cc) {
      _DAT_008091d8 = 1;
      sensor_data_buffer._0_2_ = _DAT_008062fc;
    }
    else if (sensor_data_buffer._0_2_ == 0) {
      _DAT_008091d8 = 0;
    }
    else {
      sensor_data_buffer._0_2_ = sensor_data_buffer._0_2_ + -1;
    }
    uVar1 = _DAT_008091cc;
    if ((((_DAT_008091e0 == 0) || (_DAT_008091d8 != 0)) ||
        (uVar1 = _DAT_0080c406, _DAT_008062e6 < _DAT_0080c406)) ||
       ((uVar1 = _DAT_008091cc, _DAT_008062e8 < (short)_DAT_008091cc ||
        (uVar1 = _DAT_008091ce, (short)_DAT_008091ce < _DAT_008062e4)))) {
      if (_DAT_008091de == 0) {
        if (sensor_data_buffer._10_2_ == 0) {
          _DAT_008091d4 = 0;
        }
        else {
          sensor_data_buffer._10_2_ = sensor_data_buffer._10_2_ + -1;
        }
      }
      else {
        _DAT_008091d4 = 1;
        sensor_data_buffer._10_2_ = _DAT_008062e0;
      }
    }
    else {
      _DAT_008091d4 = 1;
      sensor_data_buffer._10_2_ = _DAT_008062e0;
    }
    if (_DAT_008091d4 != 0) {
      _DAT_008091c8 = _DAT_008062de;
      return uVar1;
    }
    uVar1 = _DAT_008091c8;
    if (_DAT_008091c8 < _DAT_008037b4) {
      uVar1 = _DAT_008062e2 + _DAT_008091c8;
      _DAT_008091c8 = uVar1;
      if (_DAT_008037b4 < uVar1) {
        _DAT_008091c8 = _DAT_008037b4;
      }
    }
  }
  return uVar1;
}



//
// Function: FUN_0000a53e @ 0x0000a53e
//

void FUN_0000a53e(void)

{
  sensor_data_buffer[0x2a] = 0x80;
  sensor_data_buffer[0x2b] = 0;
  sensor_data_buffer[0x2c] = 0;
  sensor_data_buffer[0x2d] = 0;
  sensor_data_buffer[0x26] = 0;
  sensor_data_buffer[0x27] = 0x80;
  sensor_data_buffer[0x28] = 0x62;
  sensor_data_buffer[0x29] = 0xf4;
  sensor_data_buffer[0x32] = 0x80;
  sensor_data_buffer[0x33] = 0;
  sensor_data_buffer[0x34] = 0;
  sensor_data_buffer[0x35] = 0;
  sensor_data_buffer[0x2e] = 0;
  sensor_data_buffer[0x2f] = 0x80;
  sensor_data_buffer[0x30] = 0x62;
  sensor_data_buffer[0x31] = 0xf6;
  sensor_data_buffer[0xc] = 0;
  sensor_data_buffer[0xd] = 0;
  return;
}



//
// Function: FUN_0000a56e @ 0x0000a56e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000a56e(void)

{
  sensor_data_buffer[0xe] = 0;
  sensor_data_buffer[0xf] = 2;
  sensor_data_buffer[0x10] = 0;
  sensor_data_buffer[0x11] = 0x80;
  sensor_data_buffer[0x12] = 99;
  sensor_data_buffer[0x13] = 4;
  sensor_data_buffer[0x16] = 0;
  sensor_data_buffer[0x17] = 0x80;
  sensor_data_buffer[0x18] = 99;
  sensor_data_buffer[0x19] = 0x18;
  _DAT_008091c4 = _DAT_00807f3c;
  return;
}



//
// Function: FUN_0000a598 @ 0x0000a598
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000a598(void)

{
  sensor_data_buffer[0x1a] = 0;
  sensor_data_buffer[0x1b] = 2;
  sensor_data_buffer[0x1c] = 0;
  sensor_data_buffer[0x1d] = 0x80;
  sensor_data_buffer[0x1e] = 99;
  sensor_data_buffer[0x1f] = 0x2c;
  sensor_data_buffer[0x22] = 0;
  sensor_data_buffer[0x23] = 0x80;
  sensor_data_buffer[0x24] = 99;
  sensor_data_buffer[0x25] = 0x40;
  _DAT_008091c6 = 0x400;
  return;
}



//
// Function: FUN_0000a5c0 @ 0x0000a5c0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000a5c0(void)

{
  _DAT_008091e0 = 1;
  _DAT_008091c8 = _DAT_008037b4;
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
  undefined *puVar8;
  byte *pbVar9;
  short *psVar10;
  
  sVar5 = 0;
  puVar8 = &DAT_008091e2;
  iVar7 = 0x8068ea;
  uVar4 = 1;
  pbVar9 = sensor_data_buffer + 0x36;
  psVar10 = (short *)&DAT_00809526;
  uVar6 = _DAT_008035de;
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
      if ((uVar4 & uVar6) == 0) {
        *(undefined2 *)(puVar8 + 0x10) =
             *(undefined2 *)((uint)*(ushort *)(iVar7 + 0x10) * 2 + 0xfff2b0);
        if (*(ushort *)(iVar7 + 0xc) < *(ushort *)(puVar8 + 0x10)) {
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
          *(short *)(puVar8 + 0xc) = *(short *)(iVar7 + 8) + *(short *)(puVar8 + 0xc);
          if (*(short *)(iVar7 + 10) <= *(short *)(puVar8 + 0xc)) {
            *(undefined2 *)(puVar8 + 0xc) = *(undefined2 *)(iVar7 + 10);
            puVar8[0xe] = 1;
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
          if (*(ushort *)(puVar8 + 0x10) < *(ushort *)(iVar7 + 0xe)) {
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
              *(short *)(puVar8 + 0xc) = *(short *)(iVar7 + 8) + *(short *)(puVar8 + 0xc);
              if (*(short *)(iVar7 + 10) <= *(short *)(puVar8 + 0xc)) {
                *(undefined2 *)(puVar8 + 0xc) = *(undefined2 *)(iVar7 + 10);
                puVar8[0xe] = 1;
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
          *(short *)(puVar8 + 0xc) = *(short *)(puVar8 + 0xc) - *(short *)(iVar7 + 6);
          if (*(short *)(puVar8 + 0xc) < 0) {
            *(undefined2 *)(puVar8 + 0xc) = 0;
          }
        }
LAB_0000a964:
        if (*(short *)(puVar8 + 0xc) <= *(short *)(iVar7 + 4)) {
          puVar8[0xe] = 0;
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
        if (puVar8[0xe] == '\0') {
          psVar10[3] = *(short *)(puVar8 + 0x10);
          sVar2 = FUN_00035560(psVar10);
          *(short *)(puVar8 + 10) = sVar2;
          if (*(char *)(iVar7 + 0x13) != '\0') {
            if (*(short *)(puVar8 + 10) == 4) {
              if (*pbVar9 == 4) {
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
                *pbVar9 = *pbVar9 + 1;
              }
            }
            else if (*pbVar9 == 0) {
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
              *pbVar9 = *pbVar9 - 1;
            }
          }
          uVar3 = FUN_000356f8();
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
    pbVar9 = pbVar9 + 1;
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
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  
  _DAT_0080952e = 0x806b76;
  _DAT_00809528 = 0x806b42;
  _DAT_00809526 = 2;
  _DAT_0080953a = 0x806bd6;
  _DAT_00809534 = 0x806baa;
  _DAT_00809532 = 2;
  _DAT_00809546 = 0x806c14;
  _DAT_00809540 = 0x806c02;
  _DAT_0080953e = 2;
  _DAT_00809552 = 0x806c2c;
  _DAT_0080954c = 0x806c26;
  _DAT_0080954a = 2;
  _DAT_0080955e = 0x806c3e;
  _DAT_00809558 = 0x806c32;
  _DAT_00809556 = 2;
  _DAT_0080956a = 0x806c54;
  _DAT_00809564 = 0x806c4a;
  _DAT_00809562 = 2;
  _DAT_00809576 = 0x806c92;
  _DAT_00809570 = 0x806c5e;
  _DAT_0080956e = 2;
  _DAT_00809582 = 0x806ccc;
  _DAT_0080957c = 0x806cc6;
  _DAT_0080957a = 2;
  _DAT_0080958e = 0x806cd8;
  _DAT_00809588 = 0x806cd2;
  _DAT_00809586 = 2;
  _DAT_0080959a = 0x806ce4;
  _DAT_00809594 = 0x806cde;
  _DAT_00809592 = 2;
  _DAT_008095a6 = 0x806cf8;
  _DAT_008095a0 = 0x806cea;
  _DAT_0080959e = 2;
  _DAT_008095b2 = 0x806d10;
  _DAT_008095ac = 0x806d06;
  _DAT_008095aa = 2;
  _DAT_008095be = 0x806d24;
  _DAT_008095b8 = 0x806d1a;
  _DAT_008095b6 = 2;
  _DAT_008095ca = 0x806d34;
  _DAT_008095c4 = 0x806d2e;
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
      FUN_0000a6fa();
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
    if ((((uint)*(ushort *)(&DAT_00805df2 + (short)((int)(uint)*(byte *)(iVar4 + 0x15) >> 4) * 2) &
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
      if ((((uint)*(ushort *)(&DAT_00805df2 + (short)((int)(uint)*(byte *)(iVar4 + 0x14) >> 4) * 2)
           & 1 << (*(byte *)(iVar4 + 0x14) & 0xf)) == 0) ||
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
// Function: FUN_0000afa0 @ 0x0000afa0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0000afa0(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined8 uVar3;
  
  if ((_DAT_008035ec & 8) == 0) {
    sensor_data_buffer._86_2_ = current_engine_param;
    sensor_data_buffer._94_2_ = _DAT_00809258;
    uVar3 = FUN_000357f6((short *)(sensor_data_buffer + 0x50));
    _DAT_00809658 = (short)((ulonglong)uVar3 >> 0x20);
  }
  else {
    _DAT_00809658 = _DAT_00806f9e;
  }
  uVar2 = _DAT_00803614 & 0x4000;
  if (((((_DAT_00803614 & 0x4000) == 0) ||
       (((_DAT_00805df6 & 2) != 0 && (uVar2 = _DAT_008068c8 & 2, uVar2 != 0)))) ||
      (((_DAT_00805df6 & 1) != 0 && (uVar2 = _DAT_008068c8 & 1, uVar2 != 0)))) ||
     (((_DAT_00805df6 & 0x10) != 0 && (uVar2 = _DAT_008068c8 & 0x10, uVar2 != 0)))) {
    uVar1 = 0;
  }
  else {
    sensor_data_buffer[0x6a] = DAT_0080926e;
    sensor_data_buffer[0x6b] = DAT_0080926e_1;
    uVar1 = FUN_00035560((short *)(sensor_data_buffer + 100));
    uVar2 = uVar1;
  }
  _DAT_00809658 = uVar1 + _DAT_00809658;
  return uVar2;
}



//
// Function: FUN_0000b05c @ 0x0000b05c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000b05c(void)

{
  sensor_data_buffer[0x52] = 0;
  sensor_data_buffer[0x53] = 0x80;
  sensor_data_buffer[0x54] = 0x6e;
  sensor_data_buffer[0x55] = 0x34;
  sensor_data_buffer[0x50] = 0;
  sensor_data_buffer[0x51] = 2;
  sensor_data_buffer[0x5a] = 0;
  sensor_data_buffer[0x5b] = 0x80;
  sensor_data_buffer[0x5c] = 0x6e;
  sensor_data_buffer[0x5d] = 0x20;
  sensor_data_buffer[0x58] = 0;
  sensor_data_buffer[0x59] = 2;
  sensor_data_buffer[0x60] = 0;
  sensor_data_buffer[0x61] = 0x80;
  sensor_data_buffer[0x62] = 0x6e;
  sensor_data_buffer[99] = 0x5a;
  sensor_data_buffer._106_2_ = _DAT_0080926e;
  sensor_data_buffer[0x66] = 0;
  sensor_data_buffer[0x67] = 0x80;
  sensor_data_buffer[0x68] = 0x88;
  sensor_data_buffer[0x69] = 0x62;
  sensor_data_buffer[0x6c] = 0;
  sensor_data_buffer[0x6d] = 0x80;
  sensor_data_buffer[0x6e] = 0x88;
  sensor_data_buffer[0x6f] = 0x76;
  sensor_data_buffer[100] = 0;
  sensor_data_buffer[0x65] = 2;
  return;
}



//
// Function: FUN_0000b0b0 @ 0x0000b0b0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000b0b0(void)

{
  if (_DAT_00809658 < _DAT_0080d494) {
    _DAT_0080d494 = _DAT_00809658;
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
    sensor_data_buffer[0x70] = 0;
    sensor_data_buffer[0x71] = 0;
    return;
  }
  _DAT_0080d480 = _DAT_00808a6e;
  _DAT_00809668 = 1;
  sensor_data_buffer[0x70] = 0;
  sensor_data_buffer[0x71] = 4;
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
  _DAT_0080c9b2 = sensor_data_buffer._112_2_ | _DAT_0080c9b2 & 0xfffb;
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
// Function: FUN_0000b18c @ 0x0000b18c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0000b18c(void)

{
  undefined4 uVar1;
  
  if (((_DAT_0080c810 == 1) || (_DAT_0080c810 == 2)) || (_DAT_0080c810 == 6)) {
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
        if (((_DAT_008035d4 & 0x4000) == 0) || (_DAT_0080c990 != 1)) {
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
  if ((_DAT_008035ec & 0x10) == 0) {
    _DAT_0080c9aa = _DAT_0080965a;
  }
  return _DAT_008035ec & 0x10;
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
  _DAT_0080966c = FUN_000356f8();
  if (_DAT_0080966c <= _DAT_00806fb2) {
    return 0;
  }
  if (_DAT_00806fb4 < _DAT_0080966c) {
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
  
  if (((_DAT_0080c9a6 != 10) && (_DAT_0080969a != 1)) && (_DAT_0080d17a != 1)) {
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
  if ((_DAT_008035d4 & 0x400) != 0) {
    iVar1 = FUN_0000b314();
    uVar3 = (ushort)iVar1;
    _DAT_00809666 = uVar3;
  }
  if ((_DAT_008035d4 & 0x800) != 0) {
    iVar1 = FUN_0000b35c();
    _DAT_00809660 = (ushort)iVar1;
    uVar3 = _DAT_00809660 | uVar3;
  }
  if ((_DAT_008035d4 & 0x1000) != 0) {
    _DAT_00809662 = FUN_0000b27e();
    uVar3 = _DAT_00809662 | uVar3;
  }
  uVar2 = _DAT_008035d4 & 0xffff2000;
  if ((_DAT_008035d4 & 0x2000) != 0) {
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
  if (((_DAT_008035d6 & 0x20) == 0) || (_DAT_0080c810 != 3)) {
    _DAT_00809682 = _DAT_00807f3c;
    return CONCAT44(CONCAT22(uVar1,_DAT_008035d6),in_D1) & 0xffff0020ffffffff;
  }
  if ((((_DAT_00805df4 & 4) == 0) || ((_DAT_008068c6 & 4) == 0)) &&
     (((_DAT_00805df4 & 8) == 0 || ((_DAT_008068c6 & 8) == 0)))) {
    sensor_data_buffer._122_2_ = current_engine_param;
    sensor_data_buffer._130_2_ = _DAT_008092f2;
    uVar3 = FUN_000357f6((short *)(sensor_data_buffer + 0x74));
    _DAT_00809682 = (short)(uVar3 >> 0x20);
    return uVar3;
  }
  uVar2 = CONCAT22(uVar1,current_engine_param);
  if (_DAT_00806fb6 < current_engine_param) {
    _DAT_00809682 = _DAT_00806fb8;
    return CONCAT44(uVar2,in_D1);
  }
  _DAT_00809682 = _DAT_00807f3c;
  return CONCAT44(uVar2,in_D1);
}



//
// Function: FUN_0000b528 @ 0x0000b528
//

void FUN_0000b528(void)

{
  sensor_data_buffer[0x74] = 0;
  sensor_data_buffer[0x75] = 2;
  sensor_data_buffer[0x76] = 0;
  sensor_data_buffer[0x77] = 0x80;
  sensor_data_buffer[0x78] = 0x6f;
  sensor_data_buffer[0x79] = 0xba;
  sensor_data_buffer[0x7c] = 0;
  sensor_data_buffer[0x7d] = 2;
  sensor_data_buffer[0x7e] = 0;
  sensor_data_buffer[0x7f] = 0x80;
  sensor_data_buffer[0x80] = 0x6f;
  sensor_data_buffer[0x81] = 0xe0;
  sensor_data_buffer[0x84] = 0;
  sensor_data_buffer[0x85] = 0x80;
  sensor_data_buffer[0x86] = 0x6f;
  sensor_data_buffer[0x87] = 0xea;
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

void FUN_0000b574(void)

{
  sensor_data_buffer[0x96] = 0;
  sensor_data_buffer[0x97] = 2;
  sensor_data_buffer[0x98] = 0;
  sensor_data_buffer[0x99] = 0x80;
  sensor_data_buffer[0x9a] = 0x78;
  sensor_data_buffer[0x9b] = 0x86;
  sensor_data_buffer[0x9e] = 0;
  sensor_data_buffer[0x9f] = 0x80;
  sensor_data_buffer[0xa0] = 0x78;
  sensor_data_buffer[0xa1] = 0x92;
  return;
}



//
// Function: FUN_0000b594 @ 0x0000b594
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000b594(void)

{
  ushort uVar1;
  
  if (sensor_data_buffer._146_2_ == 7) {
    sensor_data_buffer._166_2_ = sensor_data_buffer._168_2_;
  }
  else {
    sensor_data_buffer._166_2_ = _DAT_00809cfe;
  }
  sensor_data_buffer._168_2_ = _DAT_00809d1a - sensor_data_buffer._166_2_;
  if ((int)(short)sensor_data_buffer._168_2_ < (int)-(uint)_DAT_00807884) {
    sensor_data_buffer._168_2_ = (undefined2)-(uint)_DAT_00807884;
  }
  if ((int)(uint)_DAT_00807884 < (int)(short)sensor_data_buffer._168_2_) {
    sensor_data_buffer._168_2_ = _DAT_00807884;
  }
  sensor_data_buffer._168_2_ = sensor_data_buffer._166_2_ + sensor_data_buffer._168_2_;
  if ((int)((int)(short)sensor_data_buffer._168_2_ - (uint)_DAT_00809cfe) < 0) {
    sensor_data_buffer._156_2_ = -(sensor_data_buffer._168_2_ - _DAT_00809cfe);
  }
  else {
    sensor_data_buffer._156_2_ = sensor_data_buffer._168_2_ - _DAT_00809cfe;
  }
  uVar1 = FUN_00035560((short *)(sensor_data_buffer + 0x96));
  sensor_data_buffer[0xa2] = (char)(uVar1 >> 8);
  sensor_data_buffer[0xa3] = (char)uVar1;
  _DAT_00809cfe =
       (short)((int)((uint)_DAT_00809cfe * (uint)uVar1 +
                    (uint)_DAT_00809d1a * (0x4000 - (uint)uVar1)) >> 0xe);
  return;
}



//
// Function: FUN_0000b656 @ 0x0000b656
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000b656(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sStack_6;
  
  FUN_0002f8dc();
  if ((((diagnostic_status_register == 7) || (diagnostic_status_register == 3)) ||
      (diagnostic_status_register == 2)) || (diagnostic_status_register == 0x1e)) {
    sVar6 = _DAT_00809d04;
    if (diagnostic_status_register != sensor_data_buffer._146_2_) {
      iVar3 = (uint)_DAT_00809d1e * ((int)_DAT_00809d32[3] + (int)_DAT_00809d32[2]);
      if (iVar3 == 0) {
        _DAT_00809cfe = current_engine_param;
      }
      else {
        iVar3 = (int)(((uint)_DAT_0080c9a4 - (uint)_DAT_00809768) * (0x400 - (uint)_DAT_00809d1c) *
                     0x80) / iVar3;
        if (iVar3 < 0x30d4) {
          if (iVar3 < -0x30d3) {
            puVar4 = (undefined *)0xffff8300;
          }
          else {
            puVar4 = (undefined *)((iVar3 << 8) / 100);
          }
        }
        else {
          puVar4 = &DAT_00007d00;
        }
        puVar4 = puVar4 + current_engine_param;
        if ((int)puVar4 < 0x10000) {
          if ((int)puVar4 < 0) {
            _DAT_00809cfe = 0;
          }
          else {
            _DAT_00809cfe = (ushort)puVar4;
          }
        }
        else {
          _DAT_00809cfe = 0xffff;
        }
      }
      _DAT_00809d12 = (uint)_DAT_00809cfe << 0x10;
      iVar3 = (uint)_DAT_00809cfe - (uint)current_engine_param;
      if (iVar3 < 32000) {
        if (iVar3 < -31999) {
          sVar6 = -32000;
        }
        else {
          sStack_6 = (short)iVar3;
          sVar6 = sStack_6;
        }
      }
      else {
        sVar6 = 32000;
      }
    }
    if (diagnostic_status_register == 7) {
      FUN_0000b594();
    }
    else {
      _DAT_00809cfe = FUN_000356f8();
      sensor_data_buffer._162_2_ = (undefined2)((int)(uint)*_DAT_00809d0e >> 2);
    }
    iVar3 = (uint)_DAT_00809cfe - (uint)current_engine_param;
    if (iVar3 < 32000) {
      if (iVar3 < -31999) {
        _DAT_00809d04 = -32000;
      }
      else {
        sStack_6 = (short)iVar3;
        _DAT_00809d04 = sStack_6;
      }
    }
    else {
      _DAT_00809d04 = 32000;
    }
    if (_DAT_00809d2a == 1) {
      _DAT_00809d00 = 1;
      sensor_data_buffer._142_4_ = (uint)_DAT_00809cc0 << 0x10;
      sensor_data_buffer[0x88] = DAT_00809cc2;
      sensor_data_buffer[0x89] = DAT_00809cc2_1;
      sensor_data_buffer[0xa4] = DAT_00809768;
      sensor_data_buffer[0xa5] = DAT_00809768_1;
      sVar6 = _DAT_00809cbe;
      sVar7 = _DAT_00809cc4;
      _DAT_00809d0c = _DAT_00809cc8;
      sVar5 = _DAT_00809cc6;
    }
    else if ((sensor_data_buffer._148_2_ == _DAT_0080c9a4) &&
            (diagnostic_status_register == sensor_data_buffer._146_2_)) {
      _DAT_00809d00 = 0;
      sVar7 = _DAT_00809d08;
      sVar5 = _DAT_00809d0a;
    }
    else {
      _DAT_00809d00 = 1;
      if (_DAT_008078b0 == _DAT_008078b2) {
        sensor_data_buffer[0x8e] = 0;
        sensor_data_buffer[0x8f] = 0;
        sensor_data_buffer[0x90] = 0;
        sensor_data_buffer[0x91] = 0;
        sVar5 = 0;
      }
      else if (_DAT_00809768 < _DAT_0080c9a4) {
        puVar4 = (undefined *)
                 FUN_000357e4((uint)_DAT_0080c9a4 - (uint)_DAT_00809768,0x100 - _DAT_008078b4,
                              (int)_DAT_008078b0 - (int)_DAT_008078b2);
        if (0x1700 < (int)puVar4) {
          puVar4 = &DAT_00001700;
        }
        sVar5 = (short)puVar4;
        sensor_data_buffer._142_4_ = (int)puVar4 << 0x10;
      }
      else {
        puVar4 = (undefined *)
                 FUN_000357e4((uint)_DAT_00809768 - (uint)_DAT_0080c9a4,0x100 - _DAT_008078b4,
                              (int)_DAT_008078b0 - (int)_DAT_008078b2);
        if (0x1700 < (int)puVar4) {
          puVar4 = &DAT_00001700;
        }
        sensor_data_buffer._142_4_ = (uint)(ushort)-(short)puVar4 << 0x10;
        sVar5 = -(short)puVar4;
      }
      sensor_data_buffer[0x88] = current_engine_param._0_1_;
      sensor_data_buffer[0x89] = (undefined1)current_engine_param;
      sVar7 = 0;
      _DAT_00809d0c = _DAT_0080c9a4 - _DAT_00809768;
      sensor_data_buffer[0xa4] = DAT_00809768;
      sensor_data_buffer[0xa5] = DAT_00809768_1;
    }
    iVar3 = (uint)current_engine_param - (int)(short)sensor_data_buffer._136_2_;
    if (iVar3 < 8000) {
      if (iVar3 < -7999) {
        _DAT_00809cfc = -8000;
      }
      else {
        sStack_6 = (short)iVar3;
        _DAT_00809cfc = sStack_6;
      }
    }
    else {
      _DAT_00809cfc = 8000;
    }
    sensor_data_buffer[0x88] = current_engine_param._0_1_;
    sensor_data_buffer[0x89] = (undefined1)current_engine_param;
    _DAT_00809cfa = _DAT_00809d04 - sVar6;
    if (_DAT_00809cfa < 32000) {
      if (_DAT_00809cfa < -31999) {
        _DAT_00809cfa = -32000;
      }
    }
    else {
      _DAT_00809cfa = 32000;
    }
    sensor_data_buffer._138_4_ =
         ((int)sVar6 * ((int)_DAT_00809d32[3] + (int)_DAT_00809d32[2]) +
         (int)_DAT_00809cfa * ((int)_DAT_00809d32[2] + (int)*_DAT_00809d32)) -
         (int)_DAT_00809cfc * (int)_DAT_00809d32[1] >> 9;
    if ((int)sensor_data_buffer._138_4_ < 0xe6000) {
      if ((int)sensor_data_buffer._138_4_ < -0xe5fff) {
        sensor_data_buffer[0x8a] = 0xff;
        sensor_data_buffer[0x8b] = 0xf1;
        sensor_data_buffer[0x8c] = 0xa0;
        sensor_data_buffer[0x8d] = 0;
      }
    }
    else {
      sensor_data_buffer[0x8a] = 0;
      sensor_data_buffer[0x8b] = 0xe;
      sensor_data_buffer[0x8c] = 0x60;
      sensor_data_buffer[0x8d] = 0;
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
    sStack_6 = (short)((int)sVar7 * (int)_DAT_0080787e >> 10) +
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
    iVar3 = (int)sVar7 * (_DAT_00809d1c - 0x400) * 0x10 +
            ((int)((uint)_DAT_00809d1c * ((int)sensor_data_buffer._142_4_ >> 9)) >> 3) +
            ((int)(sensor_data_buffer._138_4_ * (uint)_DAT_00809d1e) >> 1);
    if (iVar3 < -0x5c00000) {
      sensor_data_buffer[0x8e] = 0xe9;
      sensor_data_buffer[0x8f] = 0;
      sensor_data_buffer[0x90] = 0;
      sensor_data_buffer[0x91] = 0;
    }
    else if (iVar3 < 0x5c00000) {
      sensor_data_buffer._142_4_ = iVar3 * 4;
    }
    else {
      sensor_data_buffer[0x8e] = 0x17;
      sensor_data_buffer[0x8f] = 0;
      sensor_data_buffer[0x90] = 0;
      sensor_data_buffer[0x91] = 0;
    }
    uVar2 = sensor_data_buffer._142_4_;
    DAT_00809d06 = sensor_data_buffer[0x8e];
    DAT_00809d06_1 = sensor_data_buffer[0x8f];
    _DAT_00809d0a = _DAT_00809d08 + sensor_data_buffer._142_2_;
    if (_DAT_00809d0a < -0x16ff) {
      _DAT_00809d0a = -0x1700;
    }
    else if (0x1700 < _DAT_00809d0a) {
      _DAT_00809d0a = 0x1700;
    }
    iVar3 = (int)_DAT_00809d0c * (int)_DAT_00809d32[8] +
            ((int)_DAT_00809d0a * (int)_DAT_00809d32[6] - (int)sVar5 * (int)_DAT_00809d32[7]);
    iVar1 = iVar3 >> 8;
    if (iVar1 < -0x16ff) {
      _DAT_00809d0c = -0x1700;
    }
    else if (iVar1 < 0x1700) {
      sStack_6 = (short)((uint)iVar3 >> 8);
      _DAT_00809d0c = sStack_6;
    }
    else {
      _DAT_00809d0c = 0x1700;
    }
    sensor_data_buffer._164_2_ =
         (undefined2)
         ((int)((uint)(ushort)sensor_data_buffer._164_2_ * (uint)(ushort)sensor_data_buffer._162_2_
               + (uint)_DAT_00809768 * (0x4000 - (uint)(ushort)sensor_data_buffer._162_2_)) >> 0xe);
    if (0x1700 < (ushort)sensor_data_buffer._164_2_) {
      sensor_data_buffer[0xa4] = 0x17;
      sensor_data_buffer[0xa5] = 0;
    }
    sensor_data_buffer._148_2_ = sensor_data_buffer._164_2_ + _DAT_00809d0c;
    if ((short)sensor_data_buffer._148_2_ < (short)_DAT_00809d26) {
      _DAT_00809d02 = sensor_data_buffer._148_2_;
      if ((short)sensor_data_buffer._148_2_ <= (short)_DAT_00809d28) {
        _DAT_00809d02 = _DAT_00809d28;
      }
    }
    else {
      _DAT_00809d02 = _DAT_00809d26;
    }
    cached_parameter_value = _DAT_00809d02;
    sensor_data_buffer._142_4_ = uVar2;
  }
  sensor_data_buffer[0x92] = diagnostic_status_register._0_1_;
  sensor_data_buffer[0x93] = (undefined1)diagnostic_status_register;
  return;
}



//
// Function: FUN_0000bdd4 @ 0x0000bdd4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000bdd4(void)

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
// Function: FUN_0000be7c @ 0x0000be7c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000be7c(void)

{
  if ((diagnostic_status_register == 0) && (_DAT_00809d18 == 0x1e)) {
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
  if ((diagnostic_status_register == 0) && (_DAT_00809d18 == 2)) {
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
  if ((_DAT_00809d18 == 0) && (_DAT_0080cffc == 1)) {
    _DAT_00809d18 = 2;
    _DAT_00809d1a = _DAT_0080d00a;
  }
  return;
}



//
// Function: FUN_0000bf2e @ 0x0000bf2e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000bf2e(void)

{
  _DAT_00809d2c = _DAT_00807882;
  _DAT_00809d2e = *_DAT_00809d36;
  _DAT_00809d30 = *_DAT_00809d3a;
  _DAT_00809d16 =
       _DAT_00809d2e +
       (short)(((uint)_DAT_00809d4c * ((uint)_DAT_00809d30 - (uint)_DAT_00809d2e)) / 400);
  _DAT_00809d18 = 0;
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
  _DAT_00809d36 = 0x8036b6;
  _DAT_00809d3a = 0x8036b8;
  _DAT_00809d2c = _DAT_00807882;
  return;
}



//
// Function: FUN_0000bfbc @ 0x0000bfbc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000bfbc(void)

{
  uint uVar1;
  
  if (_DAT_00809d2c == 1) {
    sensor_data_buffer._190_2_ = _DAT_00809d1a;
    _DAT_00809d24 = FUN_00035560((short *)(sensor_data_buffer + 0xb8));
  }
  else if (_DAT_00809d2c == 0) {
    sensor_data_buffer._178_2_ = _DAT_00809d1a;
    _DAT_00809d24 = FUN_00035560((short *)(sensor_data_buffer + 0xac));
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
  if (_DAT_00809d18 == 0) {
    _DAT_00809d1a = _DAT_00809d16;
    _DAT_00809d18 = 7;
  }
  return;
}



//
// Function: FUN_0000c100 @ 0x0000c100
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000c100(void)

{
  sensor_data_buffer[0xac] = 0;
  sensor_data_buffer[0xad] = 2;
  sensor_data_buffer[0xae] = 0;
  sensor_data_buffer[0xaf] = 0x80;
  sensor_data_buffer[0xb0] = 0x78;
  sensor_data_buffer[0xb1] = 0xb6;
  sensor_data_buffer[0xb4] = 0;
  sensor_data_buffer[0xb5] = 0x80;
  sensor_data_buffer[0xb6] = 0x78;
  sensor_data_buffer[0xb7] = 0xc6;
  sensor_data_buffer[0xb8] = 0;
  sensor_data_buffer[0xb9] = 2;
  sensor_data_buffer[0xba] = 0;
  sensor_data_buffer[0xbb] = 0x80;
  sensor_data_buffer[0xbc] = 0x78;
  sensor_data_buffer[0xbd] = 0xd6;
  sensor_data_buffer[0xc0] = 0;
  sensor_data_buffer[0xc1] = 0x80;
  sensor_data_buffer[0xc2] = 0x78;
  sensor_data_buffer[0xc3] = 0xe6;
  _DAT_00809d2c = 0;
  return;
}



//
// Function: FUN_0000c144 @ 0x0000c144
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000c144(void)

{
  sensor_data_buffer._196_4_ = &DAT_00ffc800;
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

void FUN_0000c1f2(undefined4 param_1)

{
  char cVar1;
  
  cVar1 = (char)((uint)param_1 >> 0x10);
  if (cVar1 == '\x01') {
    FUN_00033524();
    FUN_00033880(sensor_data_buffer._196_4_ + 0x10);
    return;
  }
  if (cVar1 == '\x03') {
    FUN_00033a3a(sensor_data_buffer._196_4_ + 0x30);
    return;
  }
  if (cVar1 == '\x05') {
    FUN_00033b8c();
    FUN_00033bf2(sensor_data_buffer._196_4_ + 0x50);
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
  FUN_0002c99a();
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
  _DAT_0080969a = 0;
  _DAT_0080969c = 0;
  _DAT_008096a6 = 0;
  _DAT_008096a8 = 0;
  _DAT_008096aa = 0;
  _DAT_008096ac = _DAT_008037b4;
  return;
}



//
// Function: FUN_0000c368 @ 0x0000c368
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000c368(void)

{
  sensor_data_buffer[200] = sensor_data_buffer[200] + 1;
  if (4 < sensor_data_buffer[200]) {
    sensor_data_buffer[200] = 0;
  }
  if (sensor_data_buffer[200] == 1) {
    if (((DAT_0080bdca & 0x80) != 0) == ((DAT_0080bdf3 & 0x20) != 0)) {
      if (((_DAT_00805dfc & 0x80) != 0) && ((_DAT_00805e3c & 0x80) == 0)) {
        _DAT_00805dfc = _DAT_00805dfc & 0xff7f;
        sensor_data_buffer[0xc9] = 0;
      }
    }
    else if (sensor_data_buffer[0xc9] < _DAT_00807946) {
      sensor_data_buffer[0xc9] = sensor_data_buffer[0xc9] + 1;
    }
    else {
      _DAT_00805dfc = _DAT_00805dfc | 0x80;
      _DAT_00805e3c = _DAT_00805e3c | 0x80;
    }
    if (((DAT_0080bdcb & 0x80) != 0) == ((DAT_0080bdef & 0x80) != 0)) {
      if (((_DAT_00805dfc & 0x40) != 0) && ((_DAT_00805e3c & 0x40) == 0)) {
        _DAT_00805dfc = _DAT_00805dfc & 0xffbf;
        sensor_data_buffer[0xca] = 0;
      }
    }
    else if (sensor_data_buffer[0xca] < _DAT_00807946) {
      sensor_data_buffer[0xca] = sensor_data_buffer[0xca] + 1;
    }
    else {
      _DAT_00805dfc = _DAT_00805dfc | 0x40;
      _DAT_00805e3c = _DAT_00805e3c | 0x40;
    }
    if (((DAT_0080bdcb & 1) != 0) == ((DAT_0080bdef & 1) != 0)) {
      if (((_DAT_00805dfc & 0x20) != 0) && ((_DAT_00805e3c & 0x20) == 0)) {
        _DAT_00805dfc = _DAT_00805dfc & 0xffdf;
        sensor_data_buffer[0xcb] = 0;
      }
    }
    else if (sensor_data_buffer[0xcb] < _DAT_00807946) {
      sensor_data_buffer[0xcb] = sensor_data_buffer[0xcb] + 1;
    }
    else {
      _DAT_00805dfc = _DAT_00805dfc | 0x20;
      _DAT_00805e3c = _DAT_00805e3c | 0x20;
    }
    if (((DAT_0080bdcb & 2) != 0) == ((DAT_0080bdef & 2) != 0)) {
      if (((_DAT_00805dfa & 0x4000) != 0) && ((_DAT_00805e3a & 0x4000) == 0)) {
        _DAT_00805dfa = _DAT_00805dfa & 0xbfff;
        sensor_data_buffer[0xcc] = 0;
      }
    }
    else if (sensor_data_buffer[0xcc] < _DAT_00807946) {
      sensor_data_buffer[0xcc] = sensor_data_buffer[0xcc] + 1;
    }
    else {
      _DAT_00805dfa = _DAT_00805dfa | 0x4000;
      _DAT_00805e3a = _DAT_00805e3a | 0x4000;
    }
    if (((DAT_0080bdcb & 4) != 0) == ((DAT_0080bdef & 4) != 0)) {
      if ((_DAT_00805dfa & 0x8000) != 0) {
        if ((_DAT_00805e3a & 0x8000) == 0) {
          _DAT_00805dfa = _DAT_00805dfa & 0x7fff;
          sensor_data_buffer[0xcd] = 0;
        }
      }
    }
    else if (sensor_data_buffer[0xcd] < _DAT_00807946) {
      sensor_data_buffer[0xcd] = sensor_data_buffer[0xcd] + 1;
    }
    else {
      _DAT_00805dfa = _DAT_00805dfa | 0x8000;
      _DAT_00805e3a = _DAT_00805e3a | 0x8000;
    }
    if (((DAT_0080bdcb & 0x20) != 0) == ((DAT_0080bdef & 0x20) != 0)) {
      if (((_DAT_00805e00 & 0x2000) != 0) && ((_DAT_00805e40 & 0x2000) == 0)) {
        _DAT_00805e00 = _DAT_00805e00 & 0xdfff;
        sensor_data_buffer[0xce] = 0;
      }
    }
    else if (sensor_data_buffer[0xce] < _DAT_00807946) {
      sensor_data_buffer[0xce] = sensor_data_buffer[0xce] + 1;
    }
    else {
      _DAT_00805e00 = _DAT_00805e00 | 0x2000;
      _DAT_00805e40 = _DAT_00805e40 | 0x2000;
    }
    if (((DAT_0080bdcb & 0x10) != 0) == ((DAT_0080bdef & 0x10) != 0)) {
      if (((_DAT_00805dfc & 0x100) != 0) && ((_DAT_00805e3c & 0x100) == 0)) {
        _DAT_00805dfc = _DAT_00805dfc & 0xfeff;
        sensor_data_buffer[0xcf] = 0;
      }
    }
    else if (sensor_data_buffer[0xcf] < _DAT_00807946) {
      sensor_data_buffer[0xcf] = sensor_data_buffer[0xcf] + 1;
    }
    else {
      _DAT_00805dfc = _DAT_00805dfc | 0x100;
      _DAT_00805e3c = _DAT_00805e3c | 0x100;
    }
    if (((DAT_0080bdcb & 0x40) != 0) == ((DAT_0080bdef & 0x40) != 0)) {
      if (((_DAT_00805dfe & 0x4000) != 0) && ((_DAT_00805e3e & 0x4000) == 0)) {
        _DAT_00805dfe = _DAT_00805dfe & 0xbfff;
        sensor_data_buffer[0xd0] = 0;
      }
    }
    else if (sensor_data_buffer[0xd0] < _DAT_00807946) {
      sensor_data_buffer[0xd0] = sensor_data_buffer[0xd0] + 1;
    }
    else {
      _DAT_00805dfe = _DAT_00805dfe | 0x4000;
      _DAT_00805e3e = _DAT_00805e3e | 0x4000;
    }
    if (((DAT_0080bdcb & 8) != 0) != ((DAT_0080bdef & 8) != 0)) {
      if (sensor_data_buffer[0xd1] < _DAT_00807946) {
        sensor_data_buffer[0xd1] = sensor_data_buffer[0xd1] + 1;
        return;
      }
      _DAT_00805dfe = _DAT_00805dfe | 0x800;
      _DAT_00805e3e = _DAT_00805e3e | 0x800;
      return;
    }
    if (((_DAT_00805dfe & 0x800) != 0) && ((_DAT_00805e3e & 0x800) == 0)) {
      _DAT_00805dfe = _DAT_00805dfe & 0xf7ff;
      sensor_data_buffer[0xd1] = 0;
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
  
  if (_DAT_0080c810 == 3) {
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
         (in_D0 = (uint)_DAT_0080794e + (uint)_DAT_0080d092, _DAT_0080c406 <= in_D0)) {
        uVar1 = (undefined2)(in_D0 >> 0x10);
        in_D0 = CONCAT22(uVar1,asthrfes_calc_input);
        if (asthrfes_calc_input <= _DAT_0080794c) {
          if ((ushort)sensor_data_buffer._210_2_ < _DAT_00807948) {
            sensor_data_buffer._210_2_ = sensor_data_buffer._210_2_ + 1;
          }
          if (sensor_data_buffer._210_2_ == _DAT_00807948) {
            if (_DAT_00807950 < _DAT_00809258) {
              if ((ushort)sensor_data_buffer._212_2_ < _DAT_0080794a) {
                sensor_data_buffer._212_2_ = sensor_data_buffer._212_2_ + 1;
              }
            }
            else if (sensor_data_buffer._212_2_ != 0) {
              sensor_data_buffer._212_2_ = sensor_data_buffer._212_2_ + -1;
            }
          }
          if (sensor_data_buffer._212_2_ == _DAT_0080794a) {
            _DAT_00805df4 = _DAT_00805df4 | 0x2000;
            _DAT_00805e34 = _DAT_00805e34 | 0x2000;
          }
          if (sensor_data_buffer._212_2_ != 0) {
            return CONCAT22(uVar1,sensor_data_buffer._212_2_);
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
  sensor_data_buffer[0xd4] = 0;
  sensor_data_buffer[0xd5] = 0;
  sensor_data_buffer[0xd2] = 0;
  sensor_data_buffer[0xd3] = 0;
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
      if (((bVar3 & *(byte *)(sVar1 + 0x8089be)) != 0) &&
         ((bVar3 & *(byte *)(sVar1 + 0x8055fe)) == 0)) {
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
    bVar1 = sensor_data_buffer[0xd6] + 1;
    bVar2 = sensor_data_buffer[0xd6] & 1;
    uVar3 = 0;
    sensor_data_buffer[0xd6] = bVar1;
    if (bVar2 == 0) {
      FUN_0001aca8();
      uVar3 = extraout_D0u;
    }
  }
  uVar4 = CONCAT22(uVar3,_DAT_008035ea) & 0xffff0002;
  if ((_DAT_008035ea & 2) != 0) {
    sensor_data_buffer[0xd7] = sensor_data_buffer[0xd7] + 1;
    uVar4 = sensor_data_buffer[0xd7] & 1;
    if (((sensor_data_buffer[0xd7] & 1) == 0) &&
       (uVar4 = _DAT_00809d3e & 1, (_DAT_00809d3e & 1) != 0)) {
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
          if ((_DAT_008035da & 2) != 0) {
            bVar5 = bVar5 | 8;
          }
          if ((_DAT_0080cc6a != 0) && ((_DAT_008035da & 4) != 0)) {
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
          if (param_system_mode == 10) {
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
        *_DAT_0080d40c = DAT_0080d407;
        _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
        *_DAT_0080d40c = bVar5;
        _DAT_0080d40c = (byte *)CONCAT31(_DAT_0080d40c,DAT_0080d40f + '\x01');
      }
    }
    else if (DAT_0080d407 < 0x69) {
      if (DAT_0080d407 == 0x59) {
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
      else if (DAT_0080d407 == 0x5b) {
        local_6._1_1_ = (byte)(((uint)_DAT_00809d4c * 0xfa) / 400);
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
        if ((ushort)((int)(uint)_DAT_00809258 >> 4) < 0xff) {
          local_6._1_1_ = (byte)((int)(uint)_DAT_00809258 >> 4);
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
        local_6 = (short)((int)(uint)_DAT_0080d178 >> 1);
        break;
      case 0xbc:
        local_6 = (short)((int)(uint)_DAT_0080d092 >> 1);
        break;
      case 0xbd:
        local_6 = (short)((int)(uint)_DAT_00807d5e >> 1);
        break;
      case 0xbe:
        local_6 = (short)((int)(uint)_DAT_0080c406 >> 1);
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
// Function: param_system_update @ 0x0000d57c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void param_system_update(void)

{
  uint uVar1;
  undefined4 unaff_D2;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((uint)unaff_D2 >> 0x10);
  if ((param_system_mode == 2) || (param_system_mode == 1)) {
    _DAT_0080cff6 = activeParamReadFunction();
  }
  else if ((param_system_mode == 0xb) || (param_system_mode == 0xc)) {
    if (diagnostic_status_register == 8) {
      _DAT_0080cff6 = cached_parameter_value;
    }
    else {
      _DAT_0080cff6 = activeParamReadFunction();
    }
  }
  else {
    _DAT_0080cff6 = _DAT_00809652;
  }
  if ((short)(param_scale_factor - param_ref_base.base_reference) < 1) {
    param_table_main.calculated_2 = 0;
    return;
  }
  if ((short)(_DAT_0080cff6 - param_ref_base.base_reference) < 1) {
    param_table_main.calculated_2 = 0;
    return;
  }
  uVar1 = param_address_calc((short)(_DAT_0080cff6 - param_ref_base.base_reference) * 0x6400,
                             CONCAT22(param_scale_factor - param_ref_base.base_reference,uVar2));
  param_table_main.calculated_2 = (word)uVar1;
  if (32000 < param_table_main.calculated_2) {
    param_table_main.calculated_2 = 32000;
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
  
  if ((short)(param_scale_factor - param_ref_base.base_reference) < 1) {
    param_table_main.calculated_1 = 0;
    return;
  }
  if ((short)(_DAT_0080c9a4 - param_ref_base.base_reference) < 1) {
    param_table_main.calculated_1 = 0;
    return;
  }
  uVar1 = param_address_calc((short)(_DAT_0080c9a4 - param_ref_base.base_reference) * 0x6400,
                             CONCAT22(param_scale_factor - param_ref_base.base_reference,
                                      (short)((uint)unaff_D2 >> 0x10)));
  param_table_main.calculated_1 = (word)uVar1;
  if (32000 < param_table_main.calculated_1) {
    param_table_main.calculated_1 = 32000;
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
  uVar3 = (uint)_DAT_0080c9a4;
  uVar2 = (uint)param_ref_base.base_reference;
  if ((int)(uVar3 - uVar2) < 1) {
    param_table_main.calculated_3 = 0;
    return;
  }
  sensor_data_buffer._222_2_ = current_engine_param;
  uVar4 = FUN_000357f6((short *)(sensor_data_buffer + 0xd8));
  sVar1 = (short)((ulonglong)uVar4 >> 0x20) - param_ref_base.base_reference;
  if (sVar1 < 1) {
    param_table_main.calculated_3 = 0;
    return;
  }
  uVar2 = param_address_calc((uVar3 - uVar2) * 0x6400,CONCAT22(sVar1,uVar5));
  param_table_main.calculated_3 = (word)uVar2;
  if (32000 < param_table_main.calculated_3) {
    param_table_main.calculated_3 = 32000;
  }
  return;
}



//
// Function: FUN_0000d71a @ 0x0000d71a
//

void FUN_0000d71a(void)

{
  sensor_data_buffer._222_2_ = current_engine_param;
  sensor_data_buffer[0xd8] = 0;
  sensor_data_buffer[0xd9] = 2;
  sensor_data_buffer[0xda] = 0;
  sensor_data_buffer[0xdb] = 0x80;
  sensor_data_buffer[0xdc] = 0x7f;
  sensor_data_buffer[0xdd] = 0x42;
  sensor_data_buffer[0xe6] = 1;
  sensor_data_buffer[0xe7] = 0x90;
  sensor_data_buffer[0xe0] = 0;
  sensor_data_buffer[0xe1] = 2;
  sensor_data_buffer[0xe2] = 0;
  sensor_data_buffer[0xe3] = 0x80;
  sensor_data_buffer[0xe4] = 0x7f;
  sensor_data_buffer[0xe5] = 0x68;
  sensor_data_buffer[0xe8] = 0;
  sensor_data_buffer[0xe9] = 0x80;
  sensor_data_buffer[0xea] = 0x7f;
  sensor_data_buffer[0xeb] = 0x72;
  return;
}



//
// Function: param_lookup_3 @ 0x0000d756
//

void param_lookup_3(void)

{
  uint uVar1;
  undefined4 unaff_D2;
  
  if ((int)((uint)fsmxthfl_calc_input - (uint)param_ref_base.base_reference) < 1) {
    param_table_main.calculated_4 = 0;
    return;
  }
  if ((short)(param_scale_factor - param_ref_base.base_reference) < 1) {
    param_table_main.calculated_4 = 0;
    return;
  }
  uVar1 = param_address_calc(((uint)fsmxthfl_calc_input - (uint)param_ref_base.base_reference) *
                             0x6400,CONCAT22(param_scale_factor - param_ref_base.base_reference,
                                             (short)((uint)unaff_D2 >> 0x10)));
  param_table_main.calculated_4 = (word)uVar1;
  if (32000 < param_table_main.calculated_4) {
    param_table_main.calculated_4 = 32000;
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
  
  if (_DAT_0080c9aa != 0) {
    sensor_data_buffer[0xf2] = param_1._0_1_;
    sensor_data_buffer[0xf3] = param_1._1_1_;
    uVar1 = FUN_000357f6((short *)(sensor_data_buffer + 0xec));
    unaff_D2w = (ushort)((ulonglong)uVar1 >> 0x20);
  }
  if (_DAT_0080c9aa < 0x4000) {
    can_message_buffer[6] = param_1._0_1_;
    can_message_buffer[7] = param_1._1_1_;
    uVar1 = FUN_000357f6((short *)can_message_buffer);
    unaff_D3w = (ushort)((ulonglong)uVar1 >> 0x20);
  }
  if (_DAT_0080c9aa == 0x4000) {
    return _DAT_008037ae + unaff_D2w;
  }
  if (_DAT_0080c9aa == 0) {
    return _DAT_008037ae + unaff_D3w;
  }
  return _DAT_008037ae +
         (short)((uint)_DAT_0080c9aa * (uint)unaff_D2w >> 0xe) +
         (short)((uint)unaff_D3w * (0x4000 - (uint)_DAT_0080c9aa) >> 0xe);
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
  
  if ((short)(param_1._0_2_ - param_ref_base.base_reference) < 1) {
    uVar1 = 0;
  }
  else if ((short)(param_scale_factor - param_ref_base.base_reference) < 1) {
    uVar1 = 0;
  }
  else {
    uVar1 = (ushort)((uint)((short)(param_1._0_2_ - param_ref_base.base_reference) * 0x6400) /
                    (uint)(int)(short)(param_scale_factor - param_ref_base.base_reference));
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
         _DAT_0080cc4e +
         ((short)(((uint)_DAT_0080cc58 * ((uint)_DAT_0080cc56 - (param_1 & 0xffff))) / 0x1111) -
         _DAT_0080cc54);
    if (param_2._1_1_ == '\x01') {
      _DAT_0080cfea = _DAT_0080cfe8;
      return;
    }
    _DAT_0080cfea = _DAT_008086ca;
    return;
  }
  _DAT_0080cfe8 = _DAT_0080cc4e;
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
  if ((((_DAT_0080cc4a == 2) || (_DAT_0080cc4a == 4)) || (_DAT_0080cc4a == 5)) ||
     (_DAT_0080cc4a == 1)) {
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
  if (_DAT_0080c9aa == 0x4000) {
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
    _DAT_0080cfe8 = _DAT_0080cc4e;
    if (_DAT_008086ca < _DAT_0080cc4e) {
      _DAT_0080cfea = _DAT_008086ca;
    }
    else {
      _DAT_0080cfea = _DAT_0080cc4e;
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
    if (_DAT_0080cc4e < _DAT_008086d8) {
      FUN_0000d90a(CONCAT22(_DAT_0080cc4e,_DAT_008086d0),CONCAT22(1,uVar4));
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
    if (_DAT_0080cc4e < _DAT_008086de) {
      FUN_0000d90a(CONCAT22(_DAT_0080cc4e,_DAT_008086d0),CONCAT22(1,uVar4));
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
  param_table_main.param_table_1 = param_interpolate(CONCAT22(_DAT_0080cfec,uVar4));
  uVar2 = _DAT_0080cfee;
  param_table_main.param_table_2 = param_interpolate(CONCAT22(_DAT_0080cfee,uVar3));
  uVar3 = _DAT_0080cff0;
  param_table_main.param_table_3 = param_interpolate(CONCAT22(_DAT_0080cff0,uVar2));
  uVar2 = _DAT_0080cff2;
  param_table_main.param_table_4 = param_interpolate(CONCAT22(_DAT_0080cff2,uVar3));
  param_table_main.result_buffer = param_interpolate(CONCAT22(_DAT_0080cff4,uVar2));
  return;
}



//
// Function: FUN_0000dbc2 @ 0x0000dbc2
//

void FUN_0000dbc2(void)

{
  sensor_data_buffer[0xec] = 0;
  sensor_data_buffer[0xed] = 2;
  sensor_data_buffer[0xee] = 0;
  sensor_data_buffer[0xef] = 0x80;
  sensor_data_buffer[0xf0] = 0x7f;
  sensor_data_buffer[0xf1] = 0x42;
  sensor_data_buffer[0xfa] = 1;
  sensor_data_buffer[0xfb] = 0x90;
  sensor_data_buffer[0xf4] = 0;
  sensor_data_buffer[0xf5] = 2;
  sensor_data_buffer[0xf6] = 0;
  sensor_data_buffer[0xf7] = 0x80;
  sensor_data_buffer[0xf8] = 0x7f;
  sensor_data_buffer[0xf9] = 0x68;
  sensor_data_buffer[0xfc] = 0;
  sensor_data_buffer[0xfd] = 0x80;
  sensor_data_buffer[0xfe] = 0x7f;
  sensor_data_buffer[0xff] = 0x72;
  can_message_buffer[0] = 0;
  can_message_buffer[1] = 2;
  can_message_buffer[2] = 0;
  can_message_buffer[3] = 0x80;
  can_message_buffer[4] = 0x80;
  can_message_buffer[5] = 2;
  can_message_buffer[0xe] = 1;
  can_message_buffer[0xf] = 0x90;
  can_message_buffer[8] = 0;
  can_message_buffer[9] = 2;
  can_message_buffer[10] = 0;
  can_message_buffer[0xb] = 0x80;
  can_message_buffer[0xc] = 0x80;
  can_message_buffer[0xd] = 0x28;
  can_message_buffer[0x10] = 0;
  can_message_buffer[0x11] = 0x80;
  can_message_buffer[0x12] = 0x80;
  can_message_buffer[0x13] = 0x32;
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
    can_message_buffer[0x16] = 0;
    can_message_buffer[0x17] = 0x80;
    can_message_buffer[0x18] = 0x79;
    can_message_buffer[0x19] = 0x7a;
    can_message_buffer[0x22] = 0;
    can_message_buffer[0x23] = 0x80;
    can_message_buffer[0x24] = 0x79;
    can_message_buffer[0x25] = 0x7a;
    can_message_buffer[0x28] = 0;
    can_message_buffer[0x29] = 0x80;
    can_message_buffer[0x2a] = 0x79;
    can_message_buffer[0x2b] = 0x8e;
    if (uVar3 == 2) {
      can_message_buffer[0x1c] = 0;
      can_message_buffer[0x1d] = 0x80;
      can_message_buffer[0x1e] = 0x79;
      can_message_buffer[0x1f] = 0x84;
    }
    else if (uVar3 == 3) {
      can_message_buffer[0x1c] = 0;
      can_message_buffer[0x1d] = 0x80;
      can_message_buffer[0x1e] = 0x79;
      can_message_buffer[0x1f] = 0x84;
    }
    else if (uVar3 == 4) {
      can_message_buffer[0x1c] = 0;
      can_message_buffer[0x1d] = 0x80;
      can_message_buffer[0x1e] = 0x79;
      can_message_buffer[0x1f] = 0x8e;
    }
  }
  else {
    can_message_buffer[0x16] = 0;
    can_message_buffer[0x17] = 0x80;
    can_message_buffer[0x18] = 0x79;
    can_message_buffer[0x19] = 0x52;
    can_message_buffer[0x22] = 0;
    can_message_buffer[0x23] = 0x80;
    can_message_buffer[0x24] = 0x79;
    can_message_buffer[0x25] = 0x52;
    can_message_buffer[0x28] = 0;
    can_message_buffer[0x29] = 0x80;
    can_message_buffer[0x2a] = 0x79;
    can_message_buffer[0x2b] = 0x70;
    if (uVar3 == 2) {
      can_message_buffer[0x1c] = 0;
      can_message_buffer[0x1d] = 0x80;
      can_message_buffer[0x1e] = 0x79;
      can_message_buffer[0x1f] = 0x66;
    }
    else if (uVar3 == 3) {
      can_message_buffer[0x1c] = 0;
      can_message_buffer[0x1d] = 0x80;
      can_message_buffer[0x1e] = 0x79;
      can_message_buffer[0x1f] = 0x5c;
    }
    else if (uVar3 == 4) {
      can_message_buffer[0x1c] = 0;
      can_message_buffer[0x1d] = 0x80;
      can_message_buffer[0x1e] = 0x79;
      can_message_buffer[0x1f] = 0x70;
    }
  }
  can_message_buffer._26_2_ = current_engine_param;
  sVar1 = FUN_00035560((short *)(can_message_buffer + 0x14));
  if (0 < sVar1) {
    can_message_buffer._38_2_ = *(undefined2 *)(can_message_buffer._34_4_ + 8);
    sVar2 = FUN_00035560((short *)(can_message_buffer + 0x20));
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

void FUN_0000dd72(void)

{
  can_message_buffer[0x14] = 0;
  can_message_buffer[0x15] = 2;
  can_message_buffer[0x16] = 0;
  can_message_buffer[0x17] = 0x80;
  can_message_buffer[0x18] = 0x79;
  can_message_buffer[0x19] = 0x52;
  can_message_buffer[0x1c] = 0;
  can_message_buffer[0x1d] = 0x80;
  can_message_buffer[0x1e] = 0x79;
  can_message_buffer[0x1f] = 0x70;
  can_message_buffer[0x20] = 0;
  can_message_buffer[0x21] = 2;
  can_message_buffer[0x22] = 0;
  can_message_buffer[0x23] = 0x80;
  can_message_buffer[0x24] = 0x79;
  can_message_buffer[0x25] = 0x52;
  can_message_buffer[0x28] = 0;
  can_message_buffer[0x29] = 0x80;
  can_message_buffer[0x2a] = 0x79;
  can_message_buffer[0x2b] = 0x70;
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
  puVar3 = (uint *)can_message_buffer._56_4_;
  for (puVar2 = local_18; puVar2 < &stack0xfffffffc; puVar2 = puVar2 + 1) {
    if (puVar2 == local_18) {
      *puVar2 = (uint)can_message_buffer._52_4_ >> 2;
    }
    else {
      *puVar2 = *puVar3 >> 2;
      puVar3 = puVar3 + -1;
    }
    if (puVar3 < (uint)can_message_buffer._60_4_) {
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
  
  if (can_message_buffer._56_4_ == can_message_buffer._60_4_) {
    uVar3 = *_DAT_00800140 >> 2;
    uVar2 = _DAT_00800140[-1] >> 2;
  }
  else if (can_message_buffer._60_4_ + 4 == can_message_buffer._56_4_) {
    uVar3 = *(uint *)can_message_buffer._60_4_ >> 2;
    uVar2 = *_DAT_00800140 >> 2;
  }
  else {
    uVar3 = *(uint *)(can_message_buffer._56_4_ + -4) >> 2;
    uVar2 = *(uint *)(can_message_buffer._56_4_ + -8) >> 2;
  }
  iVar4 = _DAT_008079ce;
  if (_DAT_0080926e < _DAT_008079b8) {
    iVar4 = _DAT_008079ca;
  }
  uVar1 = uVar2 * _DAT_008079c8 >> 8;
  if (((uVar1 <= (uint)can_message_buffer._52_4_ >> 2) ||
      (uVar1 = uVar3 - uVar2, iVar4 <= (int)uVar1)) && (iVar4 <= (int)uVar3)) {
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
      can_message_buffer._52_4_ = _DAT_0080c75c;
      if (_DAT_0080c41a == &DAT_0080c430) {
        can_message_buffer._56_4_ = _DAT_0080c77e;
      }
      else {
        can_message_buffer._56_4_ = _DAT_0080c41a + -4;
      }
      can_message_buffer._60_4_ = &DAT_0080c430;
      _DAT_00800140 = _DAT_0080c77e;
      uVar2 = can_message_buffer._48_4_;
    }
    else {
      can_message_buffer._52_4_ = _DAT_0080c760;
      if (_DAT_0080c41e == &DAT_0080c5c0) {
        can_message_buffer._56_4_ = _DAT_0080c782;
      }
      else {
        can_message_buffer._56_4_ = _DAT_0080c41e + -4;
      }
      can_message_buffer._60_4_ = &DAT_0080c5c0;
      _DAT_00800140 = _DAT_0080c782;
      uVar2 = can_message_buffer._44_4_;
    }
    if (_DAT_00807ce6 < _DAT_0080c404) {
      if ((uint)can_message_buffer._52_4_ < uVar2) {
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
    }
    else if ((uint)can_message_buffer._52_4_ < uVar2) {
      uVar2 = FUN_0000de50();
      uVar3 = (undefined2)uVar2;
    }
    else if ((_DAT_0080926e < _DAT_008079b6) && (_DAT_0080c404 <= _DAT_008079be)) {
      uVar2 = FUN_0000ddb4();
      uVar3 = (undefined2)uVar2;
    }
    else {
      uVar3 = 0;
    }
    if (cVar4 == '\0') {
      can_message_buffer._48_4_ = can_message_buffer._52_4_ * (uint)_DAT_008079c6 >> 8;
    }
    else {
      can_message_buffer._44_4_ = can_message_buffer._52_4_ * (uint)_DAT_008079c6 >> 8;
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
  uint uVar1;
  
  uVar1 = can_message_buffer._52_4_ * (uint)_DAT_008079c6 >> 8;
  can_message_buffer[0x30] = (char)(uVar1 >> 0x18);
  can_message_buffer[0x31] = (char)(uVar1 >> 0x10);
  can_message_buffer[0x32] = (char)(uVar1 >> 8);
  can_message_buffer[0x33] = (char)uVar1;
  uVar1 = can_message_buffer._52_4_ * (uint)_DAT_008079c6 >> 8;
  can_message_buffer[0x2c] = (char)(uVar1 >> 0x18);
  can_message_buffer[0x2d] = (char)(uVar1 >> 0x10);
  can_message_buffer[0x2e] = (char)(uVar1 >> 8);
  can_message_buffer[0x2f] = (char)uVar1;
  return;
}



//
// Function: sendJ1939SingleFrame @ 0x0000e052
// ERROR: Failed to decompile
//

//
// Function: sendJ1939Msg @ 0x0000e180
//

void sendJ1939Msg(undefined4 *param_1)

{
  if (*(ushort *)(param_1 + 1) < 9) {
    sendJ1939SingleFrame(*param_1);
    return;
  }
  sendJ1939MultiFrame(param_1);
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
  if (_DAT_0080d44e != 0) {
    _DAT_0080d44e = _DAT_0080d44e + -1;
    _DAT_0080d3e2 = _DAT_0080d3e2 - (uint)*(ushort *)((short)(_DAT_0080d44e * 3) * 2 + 0x80d3aa);
  }
  return;
}



//
// Function: FUN_0000e200 @ 0x0000e200
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0000e200(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = _DAT_008035de & 0x400;
  if ((_DAT_008035de & 0x400) == 0) {
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
        if (((((((uint)*(ushort *)(&DAT_00805df2 + (short)((int)uVar3 >> 4) * 2) &
                1 << (uVar3 & 0xf)) == 0) ||
              (uVar1 = (uint)*(ushort *)(&DAT_008068c4 + ((int)uVar3 >> 4) * 2),
              (uVar1 & 1 << (uVar3 & 0xf)) == 0)) &&
             ((((uint)*(ushort *)(&DAT_00805df2 + (short)((int)uVar2 >> 4) * 2) & 1 << (uVar2 & 0xf)
               ) == 0 ||
              (uVar1 = (uint)*(ushort *)(&DAT_008068c4 + ((int)uVar2 >> 4) * 2),
              (uVar1 & 1 << (uVar2 & 0xf)) == 0)))) &&
            (((_DAT_00805dfa & 0x20) == 0 ||
             (uVar1 = _DAT_008068cc & 0xffff0020, (_DAT_008068cc & 0x20) == 0)))) &&
           ((((_DAT_00805dfa & 8) == 0 ||
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
        if (((_DAT_00805dfa & 0x20) != 0) && ((_DAT_00805e3a & 0x20) == 0)) {
          _DAT_00805dfa = _DAT_00805dfa & 0xffdf;
        }
        if (((_DAT_00805dfa & 8) != 0) && ((_DAT_00805e3a & 8) == 0)) {
          _DAT_00805dfa = _DAT_00805dfa & 0xfff7;
        }
        if (((_DAT_00805dfa & 0x10) != 0) && ((_DAT_00805e3a & 0x10) == 0)) {
          _DAT_00805dfa = _DAT_00805dfa & 0xffef;
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
  ushort uVar8;
  uint uVar9;
  
  uVar7 = _DAT_008035de & 0x400;
  if ((((_DAT_008035de & 0x400) != 0) || (DAT_00800152 != '\0')) || (_DAT_00809d60 != 0)) {
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
  if (((((uint)*(ushort *)(&DAT_00805df2 + sVar4 * 2) & 1 << (uVar7 & 0xf)) == 0) ||
      (((uint)*(ushort *)(&DAT_008068c4 + sVar4 * 2) & 1 << (uVar7 & 0xf)) == 0)) &&
     ((((uint)*(ushort *)(&DAT_00805df2 + sVar5 * 2) & 1 << (uVar9 & 0xf)) == 0 ||
      (((uint)*(ushort *)(&DAT_008068c4 + sVar5 * 2) & 1 << (uVar9 & 0xf)) == 0)))) {
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
    if (((_DAT_00805dfa & 0x20) != 0) && ((_DAT_00805e3a & 0x20) == 0)) {
      _DAT_00805dfa = _DAT_00805dfa & 0xffdf;
    }
    if (((_DAT_00805dfa & 8) != 0) && ((_DAT_00805e3a & 8) == 0)) {
      _DAT_00805dfa = _DAT_00805dfa & 0xfff7;
    }
    if (((_DAT_00805dfa & 0x10) != 0) && ((_DAT_00805e3a & 0x10) == 0)) {
      _DAT_00805dfa = _DAT_00805dfa & 0xffef;
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
      _DAT_00805dfa = _DAT_00805dfa | 8;
      _DAT_00805e3a = _DAT_00805e3a | 8;
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
      _DAT_00805dfa = _DAT_00805dfa | 0x10;
      _DAT_00805e3a = _DAT_00805e3a | 0x10;
      _DAT_00809d52 = 0;
    }
  }
  else {
    _DAT_00800146 = 0;
  }
  if (((_DAT_00809d4e == 2) || (_DAT_00809d4e == 3)) &&
     ((uVar7 = (uint)uVar1 << 0x10, (_DAT_00805dfa & 0x10) == 0 ||
      (uVar7 = CONCAT22(uVar1,_DAT_008068cc) & 0xffff0010, (_DAT_008068cc & 0x10) == 0)))) {
    uVar2 = (undefined2)(uVar7 >> 0x10);
    uVar7 = CONCAT22(uVar2,_DAT_00805dfa) & 0xffff0008;
    if (((_DAT_00805dfa & 8) == 0) ||
       (uVar7 = CONCAT22(uVar2,_DAT_008068cc) & 0xffff0008, (_DAT_008068cc & 8) == 0)) {
      if (_DAT_00800148 < uVar8) {
        _DAT_00800148 = _DAT_00800148 + 1;
        return CONCAT44(uVar7,uVar9);
      }
      _DAT_00805dfa = _DAT_00805dfa | 0x20;
      _DAT_00805e3a = _DAT_00805e3a | 0x20;
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
// Function: FUN_0000eacc @ 0x0000eacc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0000eacc(void)

{
  _DAT_00809d56 = _DAT_008079d8 + 4;
  if ((_DAT_008035d6 & 4) != 0) {
    DAT_00800152 = 1;
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
  if ((_DAT_0080c9a6 != 0xb) && (_DAT_008079ec < _DAT_0080c9a4)) {
    _DAT_00809d66 = 0;
    _DAT_0080016c = 0;
    return;
  }
  _DAT_00800166 = _DAT_0080926e;
  _DAT_00809d66 = FUN_00035560((short *)&DAT_00800160);
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
  _DAT_00800162 = 0x8079ee;
  _DAT_00800168 = 0x807a00;
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
  puVar3 = &DAT_00004000;
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
// Function: FUN_0000eca4 @ 0x0000eca4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000eca4(void)

{
  ushort extraout_D0u;
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  sVar1 = FUN_0000e1b8((short *)&DAT_00006000,(short *)&DAT_00007e42);
  if (sVar1 != _DAT_00803502) {
    return 1;
  }
  puVar3 = &DAT_00006000;
  for (puVar2 = (undefined4 *)&DAT_00804882; puVar2 < (undefined4 *)0x80488c; puVar2 = puVar2 + 1) {
    *puVar2 = *puVar3;
    DAT_00fffa27 = 0xaa;
    DAT_00ffd00f = 0xaa;
    puVar3 = puVar3 + 1;
  }
  puVar3 = &DAT_00006400;
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
    DAT_00fffa27 = 0xaa;
    DAT_00ffd00f = 0xaa;
    sVar2 = FUN_00018174(0x4000,&DAT_00804882,CONCAT22(10,uVar6));
    if (sVar2 == 1) {
      DAT_00fffa27 = 0xaa;
      DAT_00ffd00f = 0xaa;
      sVar2 = FUN_00018174(0x4400,&DAT_0080488e,CONCAT22(0x1a42,uVar6));
      cVar3 = sVar2 == 0;
      if (sVar2 == 1) {
        DAT_00fffa27 = 0xaa;
        DAT_00ffd00f = 0xaa;
        local_6 = FUN_0000e1b8((short *)&DAT_00004000,&DAT_00005e42);
        DAT_00fffa27 = 0xaa;
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
        _DAT_0080d1a0 = 1;
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
    DAT_00fffa27 = 0xaa;
    DAT_00ffd00f = 0xaa;
    sVar2 = FUN_00018174(0x6000,&DAT_00804882,CONCAT22(10,uVar6));
    if (sVar2 == 1) {
      DAT_00fffa27 = 0xaa;
      DAT_00ffd00f = 0xaa;
      sVar2 = FUN_00018174(0x6400,&DAT_0080488e,CONCAT22(0x1a42,uVar6));
      cVar3 = sVar2 == 0;
      if (sVar2 == 1) {
        DAT_00fffa27 = 0xaa;
        DAT_00ffd00f = 0xaa;
        local_6 = FUN_0000e1b8((short *)&DAT_00006000,(short *)&DAT_00007e42);
        DAT_00fffa27 = 0xaa;
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
        _DAT_0080d1a0 = 2;
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
  
  _DAT_0080d1a0 = 0;
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
  bVar7 = _DAT_00803686 < _DAT_00803688;
  bVar3 = (short)(_DAT_00803686 - _DAT_00803688) < 0;
  bVar4 = _DAT_00803686 == _DAT_00803688;
  if (bVar4) {
    uVar8 = (ushort)(byte)(bVar7 << 4 | bVar3 << 3 | bVar4 << 2 |
                           SBORROW2(_DAT_00803686,_DAT_00803688) << 1 | bVar7);
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
    bVar4 = (uVar8 & 0x10) != 0;
    bVar7 = (uVar8 & 8) != 0;
    bVar5 = (uVar8 & 4) != 0;
    bVar6 = (uVar8 & 2) != 0;
    bVar3 = (uVar8 & 1) != 0;
    _DAT_00805df2 = _DAT_00805df2 & 0xf7ff;
  }
  else {
    uVar8 = (ushort)(byte)(bVar7 << 4 | bVar3 << 3 | bVar4 << 2 |
                           SBORROW2(_DAT_00803686,_DAT_00803688) << 1 | bVar7);
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
    bVar4 = _DAT_0080368a < _DAT_008088c0;
    bVar6 = SBORROW2(_DAT_0080368a,_DAT_008088c0);
    bVar7 = (short)(_DAT_0080368a - _DAT_008088c0) < 0;
    bVar5 = _DAT_0080368a == _DAT_008088c0;
    bVar3 = bVar4;
    if (bVar4) {
      _DAT_00805df2 = _DAT_00805df2 & 0xf7ff;
    }
    else {
      _DAT_00805df2 = _DAT_00805df2 | 0x800;
      _DAT_00805e32 = _DAT_00805e32 | 0x800;
    }
  }
  uVar8 = (ushort)(byte)(bVar4 << 4 | bVar7 << 3 | bVar5 << 2 | bVar6 << 1 | bVar3);
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
// Function: FUN_0000f4ea @ 0x0000f4ea
//

void FUN_0000f4ea(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = &DAT_00037eae;
  for (puVar2 = (undefined4 *)&DAT_008062d2; puVar2 < (undefined4 *)0x808ab2; puVar2 = puVar2 + 1) {
    DAT_00fffa27 = 0xaa;
    DAT_00ffd00f = 0xaa;
    *puVar2 = *puVar1;
    puVar1 = puVar1 + 1;
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
  
  uVar1 = ((uint)_DAT_0080c9a4 * 0x6400) / 0x1700;
  _DAT_0080d186 = (short)uVar1;
  uVar2 = ((uint)_DAT_0080d482 * 0x6400) / 0x1700;
  _DAT_0080d188 = (short)uVar2;
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
  if (5 < _DAT_0080d19a) {
    uVar3 = uVar3 & 0xffff0000;
    if ((_DAT_00805670 & 4) == 0) {
      _DAT_00fff43a = _DAT_00fff43a & 0xffff0000;
    }
    else {
      uVar3 = ((((uint)_DAT_00808938 * (uint)_DAT_0080d18a) / 0x6400 & 0xffff) * 8000) / 1000 &
              0xffff | ((uint)_DAT_00808938 * 8000) / 1000 << 0x10;
      _DAT_00fff43a = uVar3;
    }
  }
  if (5 < _DAT_0080d19a) {
    uVar3 = uVar3 & 0xffff0000;
    if ((_DAT_00805670 & 8) == 0) {
      _DAT_00fff442 = _DAT_00fff442 & 0xffff0000;
    }
    else {
      uVar3 = ((((uint)_DAT_0080893a * (uint)_DAT_0080d18c) / 0x6400 & 0xffff) * 8000) / 1000 &
              0xffff | ((uint)_DAT_0080893a * 8000) / 1000 << 0x10;
      _DAT_00fff442 = uVar3;
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
    _DAT_0080d19c = 1;
    _DAT_0080d1a2 = 0xeeee;
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
  _DAT_0080d19c = 0;
  _DAT_0080d3f4 = 1;
  _DAT_0080d1a2 = 0xaaaa;
  return 0;
}



//
// Function: FUN_0000f8b6 @ 0x0000f8b6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0000f8b6(void)

{
  _DAT_0080d19c = 1;
  if (_DAT_0080d1a2 == -0x5556) {
    _DAT_0080d1a2 = -0x1112;
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
  int local_8;
  
  uVar3 = (ushort)((uint)unaff_A2 >> 0x10);
  if (_DAT_0080c810 == 1) {
    while (uVar1 = FUN_00013134(), (char)uVar1 == '\0') {
      FUN_00013240();
      FUN_0002bb2e(CONCAT22(500,uVar3));
    }
    local_8 = _DAT_0080d4c4;
    FUN_00013144(0x80352c,(undefined1 *)&local_8,CONCAT22(4,uVar3));
    if (_DAT_0080d19c == 0) {
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
    DAT_0080bdf0 = DAT_0080bdf0 & 0xef;
    FUN_000122d0();
    _DAT_0080fffc = 0xf9d2;
    uVar2 = (*DAT_00000008)();
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
// Function: FUN_0000f9f0 @ 0x0000f9f0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000f9f0(void)

{
  undefined4 uVar1;
  
  if (_DAT_0080d1a4 == 1) {
    return 7;
  }
  uVar1 = FUN_000131d6();
  if ((char)uVar1 == '\x01') {
    DAT_0080d3f3 = 0;
    return 0xb;
  }
  DAT_0080d406 = 1;
  _DAT_0080d19e = 0;
  return CONCAT31((int3)((uint)uVar1 >> 8),0xff);
}



//
// Function: FUN_0000fa40 @ 0x0000fa40
//

void FUN_0000fa40(void)

{
  FUN_0002725a();
  FUN_0002725a();
  FUN_0002725a();
  FUN_0002725a();
  FUN_0002725a();
  FUN_0002725a();
  FUN_0002725a();
  FUN_0002725a();
  return;
}



//
// Function: FUN_0000fb4c @ 0x0000fb4c
//

/* WARNING: Control flow encountered bad instruction data */

void FUN_0000fb4c(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
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
    uVar1 = *(ushort *)((int)&PTR_DAT_0000fab0 + (short)((uVar1 ^ *param_1) & 0xff) * 2) ^
            uVar1 >> 8;
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
    uVar1 = *(ushort *)((int)&PTR_DAT_0000fab0 + (short)((uVar1 ^ *pbVar4) & 0xff) * 2) ^ uVar1 >> 8
    ;
    pbVar4 = pbVar4 + 1;
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
  ushort unaff_D2w;
  ushort uVar7;
  int iVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  uint uVar11;
  
  uVar5 = _DAT_008035da & 0x800;
  if (((((_DAT_008035da & 0x800) == 0) || (uVar5 = _DAT_0080965a, _DAT_0080965a < _DAT_00807c1e)) ||
      (uVar5 = _DAT_0080c9a4, _DAT_0080c9a4 < _DAT_00807c26)) ||
     ((uVar5 = current_engine_param, current_engine_param <= _DAT_00807c24 ||
      (_DAT_00807c1c <= current_engine_param)))) {
    _DAT_008001b0 = 0;
    _DAT_00809d6a = 0;
    _DAT_00809d6e = 0;
    return uVar5;
  }
  _DAT_008001aa = current_engine_param;
  _DAT_00800196 = current_engine_param;
  _DAT_0080018a = current_engine_param;
  _DAT_00800176 = current_engine_param;
  _DAT_0080017e = _DAT_0080c9a4;
  if (_DAT_00807c28 != 0 || _DAT_00807c0e != 0) {
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
          if (_DAT_00807c28 == 0) goto LAB_0000fff4;
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
        if (_DAT_00807c28 == 0) {
          _DAT_008001b2 = _DAT_008092f2 + _DAT_00809258;
        }
        else {
          _DAT_008001b2 = _DAT_00809258;
        }
        _DAT_0080019e = _DAT_008001b2;
        uVar5 = FUN_00035560((short *)&DAT_00800184);
        uVar9 = FUN_000357f6((short *)&DAT_00800190);
        uVar10 = FUN_000357f6((short *)&DAT_00800170);
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
        if (_DAT_00807c10 < uVar7) {
          if ((uVar3 != 0) && (uVar5 != 0)) {
            iVar8 = FUN_000357e4((int)(short)(uVar6 - _DAT_00809d6c),0x4444,
                                 (uint)uVar5 * (uint)uVar3);
          }
          _DAT_00809d6e = 1;
          if (iVar8 < 0xab) {
            if (iVar8 < -0xaa) {
              unaff_D2w = 0xff56;
            }
            else {
              unaff_D2w = (ushort)iVar8;
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
        if ((!bVar2) || (_DAT_00807c28 != 0)) {
          if (((_DAT_00805df4 & 8) == 0) || ((_DAT_008068c6 & 8) == 0)) {
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
      if (_DAT_00807c2a == 0) {
        if (_DAT_00807c14 < _DAT_00807c12) {
          uVar4 = 0x7fffffff;
        }
        else {
          uVar4 = 0x80000000;
        }
      }
      else {
        iVar8 = FUN_000357e4(((uint)current_engine_param * (uint)_DAT_0080c9a4) / 0x1266 & 0xffff,
                             (uint)_DAT_00807c12 - (uint)_DAT_00807c14,(uint)_DAT_00807c2a);
        uVar4 = (uint)_DAT_00807c14 + iVar8;
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
        uVar5 = FUN_00035560((short *)&DAT_008001a4);
        iVar8 = FUN_000357e4((uint)uVar5,(int)sVar1,0x7800);
        if (iVar8 < 0xab) {
          if (iVar8 < -0xaa) {
            unaff_D2w = 0xff56;
          }
          else {
            unaff_D2w = (ushort)iVar8;
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
          ((current_engine_param < _DAT_00807c1a && (_DAT_00807c20 < current_engine_param)))) {
    _DAT_00809d6a = unaff_D2w;
    if ((int)(uint)_DAT_00807c18 < (int)(short)unaff_D2w) {
      _DAT_00809d6a = _DAT_00807c18;
    }
  }
  else {
    _DAT_00809d6a = 0;
  }
  if (_DAT_00807c0e != 0) {
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
        if ((!bVar2) || (_DAT_00807c28 != 0)) {
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
          if (_DAT_00807c28 != 0) {
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
  _DAT_0080018a = current_engine_param;
  _DAT_00800186 = 0x807a12;
  _DAT_0080018c = 0x807a2e;
  _DAT_00800184 = 2;
  _DAT_00800196 = current_engine_param;
  _DAT_00800192 = 0x807a4a;
  _DAT_00800190 = 2;
  _DAT_0080019e = _DAT_008001b2;
  _DAT_0080019a = 0x807a66;
  _DAT_00800198 = 2;
  _DAT_008001a0 = 0x807a6e;
  _DAT_008001aa = current_engine_param;
  _DAT_008001a6 = 0x807abc;
  _DAT_008001ac = 0x807ad8;
  _DAT_008001a4 = 2;
  _DAT_00800176 = current_engine_param;
  _DAT_00800172 = 0x807af4;
  _DAT_00800170 = 2;
  _DAT_0080017e = _DAT_0080c9a4;
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
// Function: FUN_00010504 @ 0x00010504
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00010504(undefined4 param_1)

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
              uVar4 = FUN_00010466();
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
                uVar4 = FUN_00010466();
              }
              else if (_DAT_00804be2 == 2) {
                _DAT_008001b8 = 2;
                _DAT_008001b4 = _DAT_00809d76;
                uVar4 = FUN_00010466();
              }
            }
            break;
          case 1:
            if (_DAT_00804be0 == 0) {
              uVar4 = FUN_00010466();
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
                uVar4 = FUN_00010466();
              }
              else if (_DAT_00804be2 == 2) {
                _DAT_008001b8 = 2;
                _DAT_008001b4 = _DAT_00809d76;
                _DAT_00809d82 = _DAT_00809d72;
                _DAT_00809d7a = _DAT_00809d72;
                _DAT_008001bc = 0;
                uVar4 = FUN_00010466();
              }
            }
            break;
          case 2:
            uVar4 = FUN_00010466();
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
// Function: FUN_0001078e @ 0x0001078e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001078e(void)

{
  _DAT_00809d72 = 0x809d8c;
  _DAT_00809d88 = &DAT_00804be8;
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
  ushort *puVar7;
  undefined8 uVar8;
  
  uVar3 = CONCAT22((short)((uint)in_D0 >> 0x10),_DAT_00803618) & 0xffff0001;
  if (((_DAT_00803618 & 1) != 0) && (_DAT_0080c810 != 1)) {
    if (_DAT_00804a1c == 0) {
      _DAT_00804a14 = _DAT_00809688;
    }
    if ((_DAT_00809b10 == 0) && ((_DAT_00809b14 == 0 || (_DAT_008001cc <= _DAT_00809b14)))) {
      _DAT_00804a0c = _DAT_00809688;
    }
    else if ((_DAT_00809b14 == 0) && (_DAT_008001cc <= _DAT_00809b10)) {
      _DAT_00804a10 = _DAT_00809688;
    }
    if ((current_engine_param < _DAT_00807852) && (_DAT_00807854 <= current_engine_param)) {
      _DAT_008001ca = _DAT_0080c9d8;
    }
    else {
      if (current_engine_param < _DAT_00807852) {
        _DAT_008001f0 = _DAT_00807854;
      }
      else {
        _DAT_008001f0 = _DAT_00807852;
      }
      _DAT_008001dc = _DAT_008001f0;
      if (_DAT_0080965a == 0x4000) {
        uVar8 = FUN_000357f6((short *)&DAT_008001d6);
        _DAT_008001ca = (ushort)((ulonglong)uVar8 >> 0x20);
      }
      else if (_DAT_0080965a == 0) {
        uVar8 = FUN_000357f6((short *)&DAT_008001ea);
        _DAT_008001ca = (ushort)((ulonglong)uVar8 >> 0x20);
      }
      else {
        uVar8 = FUN_000357f6((short *)&DAT_008001d6);
        _DAT_008001d2 = (ushort)((ulonglong)uVar8 >> 0x20);
        uVar8 = FUN_000357f6((short *)&DAT_008001ea);
        _DAT_008001d4 = (ushort)((ulonglong)uVar8 >> 0x20);
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
           (int)(((uint)_DAT_0080c9a4 - (uint)fsmxthfl_calc_input) * 10000) /
           (int)((uint)_DAT_008001ca - (uint)fsmxthfl_calc_input);
    }
    if ((int)_DAT_008001c6 < 0) {
      _DAT_00809b18 = 0;
      if (current_engine_param < _DAT_00807852) {
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
        if (current_engine_param <= *puVar7) {
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
// Function: FUN_00010c98 @ 0x00010c98
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010c98(void)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  
  if (_DAT_00809b10 < _DAT_008001cc) {
    _DAT_00804a18 = (undefined2)((uint)(&LAB_00004650 + _DAT_00809b10 * 0x3c) / 36000);
  }
  else {
    _DAT_00804a18 = _DAT_008001d0;
  }
  if (_DAT_00809b14 < _DAT_008001cc) {
    _DAT_00804a1a = (undefined2)((uint)(&LAB_00004650 + _DAT_00809b14 * 0x3c) / 36000);
  }
  else {
    _DAT_00804a1a = _DAT_008001d0;
  }
  bVar1 = 1;
  piVar2 = (int *)&DAT_00809b1e;
  piVar3 = (int *)&DAT_00809be8;
  do {
    *(short *)(&DAT_00804a20 + (short)(ushort)bVar1 * 2) =
         (short)((uint)(&LAB_00004650 + *piVar2 * 0x3c) / 36000);
    *(short *)(&DAT_00804a86 + (short)(ushort)bVar1 * 2) =
         (short)((uint)(&LAB_00004650 + *piVar3 * 0x3c) / 36000);
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
// Function: FUN_00010da4 @ 0x00010da4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010da4(undefined4 param_1)

{
  undefined8 uVar1;
  undefined2 uVar2;
  
  lookup_table_rpm[2] = param_1._0_2_;
  uVar2 = 0x80;
  uVar1 = FUN_000357f6((short *)&DAT_008001fe);
  FUN_00012966((short)((short)((ulonglong)uVar1 >> 0x20) - (lookup_table_rpm[0x15] + param_1._2_2_))
               * 0x6400,CONCAT22(_DAT_00807c38 - _DAT_0080bda0,uVar2));
  return;
}



//
// Function: FUN_00010e02 @ 0x00010e02
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010e02(void)

{
  lookup_table_rpm[0xc] = _DAT_0080d092;
  _DAT_0080bd9a = FUN_00035560((short *)(lookup_table_rpm + 9));
  lookup_table_rpm[0xc] = _DAT_00807c3c;
  _DAT_0080bd9e = FUN_00035560((short *)(lookup_table_rpm + 9));
  lookup_table_rpm[0xc] = _DAT_00807c3e;
  _DAT_0080bda0 = FUN_00035560((short *)(lookup_table_rpm + 9));
  lookup_table_rpm[0xc] = _DAT_00807c40;
  _DAT_0080bda2 = FUN_00035560((short *)(lookup_table_rpm + 9));
  lookup_table_rpm[0xc] = _DAT_00807c3a;
  _DAT_0080bd9c = FUN_00035560((short *)(lookup_table_rpm + 9));
  return;
}



//
// Function: FUN_00010e70 @ 0x00010e70
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010e70(void)

{
  lookup_table_rpm[0x12] = _DAT_0080926e;
  lookup_table_rpm[0x15] = FUN_00035560((short *)(lookup_table_rpm + 0xf));
  FUN_00010e02();
  _DAT_0080bd96 = FUN_00010da4(CONCAT22(_DAT_0080d092,_DAT_0080bd9a));
  _DAT_0080bd98 = FUN_00010da4(CONCAT22(_DAT_00807c3a,_DAT_0080bd9c));
  _DAT_0080bd90 = FUN_00010da4(CONCAT22(_DAT_00807c3c,_DAT_0080bd9e));
  _DAT_0080bd92 = FUN_00010da4(CONCAT22(_DAT_00807c3e,_DAT_0080bda0));
  _DAT_0080bd94 = FUN_00010da4(CONCAT22(_DAT_00807c40,_DAT_0080bda2));
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
  lookup_table_rpm[0xc] = _DAT_00807c3e;
  uVar2 = 0x80;
  _DAT_0080bda0 = FUN_00035560((short *)(lookup_table_rpm + 9));
  iVar1 = FUN_00012966(((int)_DAT_0080c9a4 - (int)(short)_DAT_0080bd8c) * 0x6400,
                       CONCAT22(_DAT_00807c38 - _DAT_0080bda0,uVar2));
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
  lookup_table_rpm[0] = 0x80;
  lookup_table_rpm[1] = 0x7f42;
  lookup_table_rpm[6] = 400;
  lookup_table_rpm[3] = 2;
  lookup_table_rpm[4] = 0x80;
  lookup_table_rpm[5] = 0x7f68;
  lookup_table_rpm[7] = 0x80;
  lookup_table_rpm[8] = 0x7f72;
  lookup_table_rpm[0xf] = 2;
  lookup_table_rpm[0x10] = 0x80;
  lookup_table_rpm[0x11] = 0x8862;
  lookup_table_rpm[0x13] = 0x80;
  lookup_table_rpm[0x14] = 0x8876;
  lookup_table_rpm[9] = 2;
  lookup_table_rpm[10] = 0x80;
  lookup_table_rpm[0xb] = 0x883a;
  lookup_table_rpm[0xd] = 0x80;
  lookup_table_rpm[0xe] = 0x884e;
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
        FUN_00027ef0(CONCAT22(param_1._0_2_,(short)((uint)unaff_D2 >> 0x10)) & 0xffffff);
        if (((&DAT_008065d0)[(uint)bVar3 * 6] != '\0') &&
           ((*(ushort *)(&DAT_008065ce + (uint)bVar3 * 6) & 0x40) == 0)) {
          _DAT_00804f42 = _DAT_00804f42 + -1;
        }
        DAT_00804e9c = DAT_00804e9c + -1;
        _DAT_00804efc = _DAT_00804efc + -1;
        (&DAT_00804e9c)[(short)lookup_table_rpm[0x18]] = (&DAT_00804e9c)[_DAT_00804f3e];
        iVar1 = (int)_DAT_00804f3e;
        _DAT_00804f3e = _DAT_00804f3e + -1;
        *(undefined2 *)(&DAT_00804efc + (short)lookup_table_rpm[0x18] * 2) =
             *(undefined2 *)(&DAT_00804efc + iVar1 * 2);
        lookup_table_rpm[0x18] = lookup_table_rpm[0x18] - 1;
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
  uVar1 = lookup_table_rpm[0x18] + 1;
  if (_DAT_00804f3e < uVar1) {
    lookup_table_rpm[0x18] = 0;
  }
  else {
    unaff_D2 = (uint)(byte)(&DAT_00804e9c)[(short)uVar1];
    lookup_table_rpm[0x18] = uVar1;
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
  uVar2 = *(ushort *)(&DAT_00805df2 + (short)lookup_table_rpm[0x19] * 2);
  uVar3 = *(ushort *)(&DAT_00805e32 + (short)lookup_table_rpm[0x19] * 2);
  *(undefined2 *)(&DAT_00805e32 + (short)lookup_table_rpm[0x19] * 2) = 0;
  uVar7 = 1;
  uVar8 = 0;
  do {
    if ((uVar7 & (uVar3 | uVar2)) == 0) {
      if (((((uVar7 & *(ushort *)(&DAT_00805e72 + (short)lookup_table_rpm[0x19] * 2)) != 0) &&
           (uVar4 = *(ushort *)((short)(uVar8 + lookup_table_rpm[0x19] * 0x10) * 2 + 0x806374),
           uVar4 < 0x7d)) &&
          ((uVar7 & *(ushort *)(&DAT_008068c4 + (short)lookup_table_rpm[0x19] * 2)) != 0)) &&
         ((*(char *)((short)uVar4 + 0x804f46) != '\0' &&
          (*(char *)((short)uVar4 + 0x804f46) = *(char *)((short)uVar4 + 0x804f46) + -1,
          *(char *)((short)uVar4 + 0x804f46) == '\0')))) {
        *(undefined1 *)((short)(uVar4 * 5) * 2 + 0x804fcc) = 2;
        *(undefined4 *)((short)(uVar4 * 5) * 2 + 0x804fc4) = _DAT_0080d4c4;
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
              FUN_00017ca6((uint *)0x80bda4,CONCAT22(uVar4,uVar9) & 0xffffff);
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
      uVar4 = *(ushort *)((short)(uVar8 + lookup_table_rpm[0x19] * 0x10) * 2 + 0x806374);
      if ((((uVar4 < 0x7d) &&
           ((uVar7 & *(ushort *)(&DAT_00805e72 + (short)lookup_table_rpm[0x19] * 2)) == 0)) &&
          (DAT_00804e7c != 0x1f)) &&
         ((uVar7 & *(ushort *)(&DAT_008068c4 + (short)lookup_table_rpm[0x19] * 2)) != 0)) {
        if ((&DAT_00804fcd)[(short)(uVar4 * 5) * 2] != -1) {
          (&DAT_00804fcd)[(short)(uVar4 * 5) * 2] = (&DAT_00804fcd)[(short)(uVar4 * 5) * 2] + '\x01'
          ;
        }
        if (*(char *)((short)uVar4 + 0x804f46) == '\0') {
          FUN_0001124a(CONCAT22(uVar4,uVar9));
          *(undefined1 *)((short)(uVar4 * 5) * 2 + 0x804fcc) = 3;
          *(undefined4 *)((short)(uVar4 * 5) * 2 + 0x804fc4) = _DAT_0080d4c4;
          *(undefined4 *)((short)(uVar4 * 5) * 2 + 0x804fc8) = 0;
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
            FUN_00017ca6((uint *)0x80bda4,(uint)(uint3)(CONCAT12((char)uVar4,uVar9) | 0x800000));
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
  *(ushort *)(&DAT_00805e72 + (short)lookup_table_rpm[0x19] * 2) = uVar3 | uVar2;
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
      (((*(short *)(&DAT_00805df2 + (short)lookup_table_rpm[0x19] * 2) == 0 &&
        (*(short *)(&DAT_00805e32 + (short)lookup_table_rpm[0x19] * 2) == 0)) &&
       (*(short *)(&DAT_00805e72 + (short)lookup_table_rpm[0x19] * 2) == 0)) && (iVar2 < 0x20));
      iVar2 = iVar2 + 1) {
    lookup_table_rpm[0x19] = lookup_table_rpm[0x19] + 1;
    if (0x1f < lookup_table_rpm[0x19]) {
      lookup_table_rpm[0x19] = 0;
    }
  }
  if (iVar2 < 0x20) {
    FUN_000115b2();
    lookup_table_rpm[0x19] = lookup_table_rpm[0x19] + 1;
    if (0x1f < lookup_table_rpm[0x19]) {
      lookup_table_rpm[0x19] = 0;
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
  if (0x18 < (uint)(_DAT_0080d4c4 - lookup_table_rpm._44_4_)) {
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
    FUN_000111a2();
    lookup_table_rpm[0x16] = _DAT_0080d4c4;
    lookup_table_rpm[0x17] = _DAT_0080d4c6;
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
  
  FUN_00017d1a((undefined4 *)0x80bda4,0x80bdb6,CONCAT22(10,in_stack_00000000));
  return;
}



//
// Function: FUN_00011c28 @ 0x00011c28
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_00011c28(void)

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
  *(uint *)(&DAT_00800264 + (short)(ushort)DAT_00800242 * 4) = _DAT_00807c7a ^ local_10;
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
  DAT_0080bdc6 = ((byte)local_c | (byte)local_8 & DAT_0080bdc6) & ~ram0x0080023e[1] |
                 DAT_0080378a & ram0x0080023e[1];
  local_8._2_1_ = (byte)(uVar2 >> 8);
  local_c._2_1_ = (byte)(uVar1 >> 8);
  DAT_0080bdc7 = *ram0x0080023e & DAT_0080378b |
                 ~*ram0x0080023e & (local_c._2_1_ | local_8._2_1_ & DAT_0080bdc7);
  local_8._1_1_ = (byte)(uVar2 >> 0x10);
  local_c._1_1_ = (byte)(uVar1 >> 0x10);
  DAT_0080bdc8 = (local_c._1_1_ | local_8._1_1_ & DAT_0080bdc8) & ~ram0x0080023e[3] |
                 DAT_0080378c & ram0x0080023e[3];
  local_8._0_1_ = (byte)(uVar2 >> 0x18);
  local_c._0_1_ = (byte)(uVar1 >> 0x18);
  DAT_0080bdc9 = DAT_0080378d & ram0x0080023e[2] |
                 ~ram0x0080023e[2] & (local_c._0_1_ | local_8._0_1_ & DAT_0080bdc9);
  uVar2 = _DAT_00800260 | _DAT_0080025c | _DAT_00800258 | _DAT_00800254;
  uVar1 = _DAT_00800260 & _DAT_0080025c & _DAT_00800258 & _DAT_00800254;
  local_8._3_1_ = (byte)uVar2;
  local_c._3_1_ = (byte)uVar1;
  DAT_0080bdca = ((byte)local_c | (byte)local_8 & DAT_0080bdca) & ~ram0x0080023e[5] |
                 DAT_0080378e & ram0x0080023e[5];
  local_8._2_1_ = (byte)(uVar2 >> 8);
  local_c._2_1_ = (byte)(uVar1 >> 8);
  DAT_0080bdcb = DAT_0080378f & ram0x0080023e[4] |
                 ~ram0x0080023e[4] & (local_c._2_1_ | local_8._2_1_ & DAT_0080bdcb);
  if (_DAT_0080374e != 0) {
    local_8._1_1_ = (byte)(uVar2 >> 0x10);
    local_c._1_1_ = (byte)(uVar1 >> 0x10);
    DAT_0080bdcc = (local_c._1_1_ | local_8._1_1_ & DAT_0080bdcc) & ~ram0x0080023e[7] |
                   DAT_00803790 & ram0x0080023e[7];
  }
  local_8._0_1_ = (byte)(uVar2 >> 0x18);
  local_c._0_1_ = (byte)(uVar1 >> 0x18);
  DAT_0080bdcd = (local_c._0_1_ | local_8._0_1_ & DAT_0080bdcd) & ~ram0x0080023e[6] |
                 DAT_00803791 & ram0x0080023e[6];
  local_8 = _DAT_00800270 | _DAT_0080026c | _DAT_00800268 | _DAT_00800264;
  local_c = _DAT_00800270 & _DAT_0080026c & _DAT_00800268 & _DAT_00800264;
  DAT_0080bdce = ((byte)local_c | (byte)local_8 & DAT_0080bdce) & ~ram0x0080023e[9] |
                 DAT_00803792 & ram0x0080023e[9];
  if ((lookup_table_rpm[0x1a] != 0) && ((DAT_0080bdc6 & 1) == 0)) {
    local_12 = _DAT_00803678 + 1;
    FUN_00013144(0x803678,(undefined1 *)&local_12,CONCAT22(2,(short)((uint)unaff_D2 >> 0x10)));
  }
  lookup_table_rpm[0x1a] = (byte)-((DAT_0080bdc6 & 1) != 0) & 1;
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
      lookup_table_rpm[0x1b] = 0;
      if (_DAT_0080374c == 1) {
        DAT_0080bdcc = DAT_0080bdcc & 0xfd;
      }
      else {
        DAT_0080bdcc = DAT_0080bdcc & 0xf7;
      }
    }
    else {
      lookup_table_rpm[0x1b] = lookup_table_rpm[0x1b] + 1;
      if ((0x18 < lookup_table_rpm[0x1b]) &&
         (lookup_table_rpm[0x1b] = 0x19, (DAT_0080bdcc & 0x20) == 0)) {
        if (_DAT_0080374c == 1) {
          DAT_0080bdcc = DAT_0080bdcc | 2;
        }
        else {
          DAT_0080bdcc = DAT_0080bdcc | 8;
        }
      }
    }
    if ((DAT_0080bdc6 & 2) == 0) {
      lookup_table_rpm[0x1c] = 0;
      if (_DAT_0080374c == 1) {
        DAT_0080bdcc = DAT_0080bdcc & 0xf7;
      }
      else {
        DAT_0080bdcc = DAT_0080bdcc & 0xfd;
      }
    }
    else {
      lookup_table_rpm[0x1c] = lookup_table_rpm[0x1c] + 1;
      if ((0x18 < lookup_table_rpm[0x1c]) &&
         (lookup_table_rpm[0x1c] = 0x19, (DAT_0080bdcc & 0x20) == 0)) {
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
    lookup_table_rpm[0x1d] = lookup_table_rpm[0x1d] + 1;
    if (0x31 < lookup_table_rpm[0x1d]) {
      _DAT_00805dfa = _DAT_00805dfa | 0x800;
      _DAT_00805e3a = _DAT_00805e3a | 0x800;
    }
  }
  else {
    lookup_table_rpm[0x1d] = 0;
    if (((_DAT_00805dfa & 0x800) != 0) && ((_DAT_00805e3a & 0x800) == 0)) {
      _DAT_00805dfa = _DAT_00805dfa & 0xf7ff;
    }
  }
  if (((DAT_0080bdc7 & 0x20) == 0) || ((DAT_0080bdc7 & 0x40) == 0)) {
    lookup_table_rpm[0x1e] = 0;
    if (((_DAT_00805e00 & 2) != 0) && ((_DAT_00805e40 & 2) == 0)) {
      _DAT_00805e00 = _DAT_00805e00 & 0xfffd;
    }
  }
  else {
    lookup_table_rpm[0x1e] = lookup_table_rpm[0x1e] + 1;
    if (0x31 < lookup_table_rpm[0x1e]) {
      _DAT_00805e00 = _DAT_00805e00 | 2;
      _DAT_00805e40 = _DAT_00805e40 | 2;
    }
  }
  FUN_00012482();
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
// Function: FUN_000122d0 @ 0x000122d0
//

void FUN_000122d0(void)

{
  DAT_00ffd004 = DAT_0080bdee;
  DAT_00ffd006 = DAT_0080bdef & 0xfe | ~DAT_0080bdef & 1;
  DAT_00fffa11 = DAT_0080bdf0;
  if ((~DAT_0080bdf3 & 0x20) == 0) {
    stack_area._24_2_ = stack_area._24_2_ & 0xf3ff | 0x800;
  }
  else {
    stack_area._24_2_ = stack_area._24_2_ & 0xf3ff | 0x400;
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
  
  ram0x0080023e = 0x8035ee;
  bVar1 = 0;
  do {
    FUN_00011c28();
    bVar1 = bVar1 + 1;
  } while (bVar1 < 4);
  return;
}



//
// Function: FUN_00012376 @ 0x00012376
//

void FUN_00012376(void)

{
  DAT_00ffd008 = 0xf;
  DAT_00ffd009 = 0x80;
  DAT_00ffd00a = 0x80;
  DAT_00ffd004 = 0;
  DAT_0080bdf0 = DAT_0080bdf0 | 0x10;
  stack_area._10_2_ = stack_area._10_2_ & 0xdfff;
  stack_area._32_2_ = stack_area._32_2_ & 0xdfff;
  stack_area._12_2_ = stack_area._12_2_ & 0xff0f | 0xe0;
  register_map[0xd0] = 1;
  register_map[0xd1] = 0x13;
  stack_area._28_2_ = stack_area._28_2_ & 0xf3ff | 0x400;
  do {
  } while ((register_map._210_2_ & 0x8000) != 0);
  do {
  } while ((register_map._210_2_ & 0x8000) == 0);
  do {
  } while ((register_map._210_2_ & 0x8000) != 0);
  DAT_00ffd006 = DAT_00ffd006 & 0x7f | 0x80;
  stack_area._24_2_ = stack_area._24_2_ & 0xf3ff | 0x400;
  DAT_0080bdf3 = DAT_0080bdf3 | 0x20;
  DAT_0080bdee = DAT_0080bdee & 0xfa | 0x80;
  DAT_0080bdef = DAT_0080bdef | 1;
  DAT_0080bdf1 = DAT_0080bdf1 | 1;
  FUN_000122d0();
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
  
  uVar4 = _DAT_00fff404;
  uVar12 = (ushort)((uint)unaff_D2 >> 0x10);
  if ((DAT_0080d406 != '\0') && (uVar5 = FUN_00013134(), (char)uVar5 != '\0')) {
    DAT_0080d406 = '\0';
    FUN_0000a626((uint)uVar12);
  }
  do {
    if ((499 < (int)((uint)_DAT_00fff404 - (uint)uVar4)) ||
       ((_DAT_0080d2c2 == _DAT_0080d2ca && (DAT_0080d2ce != '\x01')))) {
      return;
    }
    cVar1 = *_DAT_0080d2ca;
    local_8._3_1_ = (char)_DAT_0080d2ca;
    cVar7 = (char)local_8;
    local_8._0_3_ = (undefined3)((uint)_DAT_0080d2ca >> 8);
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
          cVar7 = FUN_00027e98();
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
              uVar5 = FUN_000258e0();
              cVar7 = (char)uVar5;
              break;
            case 0x52:
              cVar7 = FUN_0000f9e4();
              break;
            case 0x53:
              cVar7 = '\x04';
              break;
            case 0x54:
              uVar6 = FUN_0000f9f0();
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
            uVar6 = FUN_0000fcb0((byte *)CONCAT22((short)((uint)_DAT_0080d2ca >> 0x10),
                                                  (short)local_c),(uint)CONCAT12(cVar1 + -4,uVar12))
            ;
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
    _DAT_0080d2ca = (char *)CONCAT31(_DAT_0080d2ca,cVar1 + '\x01' + DAT_0080d2cd);
    DAT_0080d2ce = '\0';
    _DAT_00fffc0a = _DAT_00fffc0a | 0x20;
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
  if (*_DAT_0080d2ca == '\x06') {
    local_8._3_1_ = (char)_DAT_0080d2ca;
    cVar4 = (char)local_8;
    local_8._0_3_ = (undefined3)((uint)_DAT_0080d2ca >> 8);
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
        uVar6 = FUN_0002b544((uint)_DAT_0080d3fa,CONCAT22(_DAT_0080d400,uVar11));
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
  short *psVar1;
  undefined1 uVar2;
  byte bVar3;
  short sVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  char cVar7;
  undefined4 unaff_D2;
  byte bVar8;
  ushort uVar9;
  undefined2 local_a;
  undefined4 local_8;
  
  uVar9 = (ushort)((uint)unaff_D2 >> 0x10);
  local_8._3_1_ = (char)_DAT_0080d2ca;
  cVar7 = (char)local_8;
  local_8._0_3_ = (undefined3)((uint)_DAT_0080d2ca >> 8);
  local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x02');
  bVar3 = *local_8 & 0xf;
  if (DAT_0080d405 == '\x01') {
    if ((uint)*_DAT_0080d2ca - (uint)bVar3 == 4) {
      local_8 = (byte *)CONCAT31(local_8._0_3_,cVar7 + '\x03');
      uVar2 = *local_8;
      local_8 = (byte *)CONCAT31(local_8._0_3_,cVar7 + '\x04');
      local_a = CONCAT11(*local_8,uVar2);
      local_8 = (byte *)CONCAT31(local_8._0_3_,cVar7 + '\x05');
      if (local_a == _DAT_0080d3f8) {
        switch(_DAT_0080d3f8) {
        case 0x15:
        case 0x17:
        case 0x18:
        case 0x19:
          for (bVar8 = 0; bVar8 < bVar3; bVar8 = bVar8 + 1) {
            puVar5 = _DAT_0080d3fa + 1;
            *_DAT_0080d3fa = *local_8;
            _DAT_0080d3fa = puVar5;
            local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
          }
          _DAT_0080d402 = _DAT_0080d402 - bVar3;
          if (_DAT_0080d402 == 0) {
            DAT_0080d405 = '\0';
          }
          break;
        default:
          uVar6 = FUN_0002b544((uint)_DAT_0080d3fa,CONCAT22(_DAT_0080d402,uVar9));
          if (((char)uVar6 == '\x03') || ((char)uVar6 == '\x05')) {
            psVar1 = (short *)((short)(_DAT_0080d44e * 3) * 2 + 0x80d3a4);
            *psVar1 = (ushort)bVar3 + *psVar1;
            for (bVar8 = 0; bVar8 < bVar3; bVar8 = bVar8 + 1) {
              puVar5 = _DAT_0080d3e2 + 1;
              *_DAT_0080d3e2 = *local_8;
              _DAT_0080d3e2 = puVar5;
              local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
            }
            _DAT_0080d402 = _DAT_0080d402 - bVar3;
            if (_DAT_0080d402 == 0) {
              DAT_0080d405 = '\0';
            }
          }
          else {
            for (bVar8 = 0; bVar8 < bVar3; bVar8 = bVar8 + 1) {
              puVar5 = _DAT_0080d3fa + 1;
              *_DAT_0080d3fa = *local_8;
              _DAT_0080d3fa = puVar5;
              local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
            }
            _DAT_0080d402 = _DAT_0080d402 - bVar3;
            if (_DAT_0080d402 == 0) {
              DAT_0080d405 = '\0';
            }
          }
        }
        FUN_0000a626((uint)uVar9);
      }
      else {
        _DAT_0080d44e = _DAT_0080d44e - 1;
        _DAT_0080d3e2 =
             _DAT_0080d3e2 + -(uint)*(ushort *)((short)(_DAT_0080d44e * 3) * 2 + 0x80d3aa);
        DAT_0080d405 = '\0';
        FUN_0000a626(CONCAT22(4,uVar9));
      }
    }
    else {
      FUN_0000a626(CONCAT22(4,uVar9));
    }
  }
  else if ((uint)*_DAT_0080d2ca - (uint)bVar3 == 6) {
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar7 + '\x03');
    uVar2 = *local_8;
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar7 + '\x04');
    _DAT_0080d3f8 = CONCAT11(*local_8,uVar2);
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar7 + '\x05');
    uVar2 = *local_8;
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar7 + '\x06');
    _DAT_0080d402 = CONCAT11(*local_8,uVar2);
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar7 + '\a');
    cVar7 = FUN_0000eaf0(0x80);
    if (cVar7 == '\0') {
      switch(_DAT_0080d3f8) {
      case 0x15:
      case 0x17:
      case 0x18:
      case 0x19:
        for (bVar8 = 0; bVar8 < bVar3; bVar8 = bVar8 + 1) {
          puVar5 = _DAT_0080d3fa + 1;
          *_DAT_0080d3fa = *local_8;
          _DAT_0080d3fa = puVar5;
          local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
        }
        _DAT_0080d402 = _DAT_0080d402 - bVar3;
        if (_DAT_0080d402 != 0) {
          DAT_0080d405 = '\x01';
        }
        break;
      default:
        uVar6 = FUN_0002b544((uint)_DAT_0080d3fa,CONCAT22(_DAT_0080d402,uVar9));
        cVar7 = (char)uVar6;
        if ((cVar7 == '\x05') || (cVar7 == '\x03')) {
          if ((10 < _DAT_0080d44e + 1) ||
             (0x80d3a5 - (int)_DAT_0080d3e2 <= (int)(uint)_DAT_0080d402)) {
            FUN_0000a626(CONCAT22(0xe,uVar9));
            return;
          }
          *(undefined1 **)(&DAT_0080d3a6 + (short)(_DAT_0080d44e * 3) * 2) = _DAT_0080d3fa;
          sVar4 = _DAT_0080d44e * 3;
          _DAT_0080d44e = _DAT_0080d44e + 1;
          *(ushort *)(sVar4 * 2 + 0x80d3aa) = (ushort)bVar3;
          for (bVar8 = 0; bVar8 < bVar3; bVar8 = bVar8 + 1) {
            puVar5 = _DAT_0080d3e2 + 1;
            *_DAT_0080d3e2 = *local_8;
            _DAT_0080d3e2 = puVar5;
            local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
          }
          _DAT_0080d402 = _DAT_0080d402 - bVar3;
          if (_DAT_0080d402 != 0) {
            DAT_0080d405 = '\x01';
          }
        }
        else {
          if (cVar7 != '\0') {
            if (cVar7 != '\n') {
              FUN_0000a626(CONCAT22(9,uVar9));
              return;
            }
            FUN_0000a626(CONCAT22(10,uVar9));
            return;
          }
          for (bVar8 = 0; bVar8 < bVar3; bVar8 = bVar8 + 1) {
            puVar5 = _DAT_0080d3fa + 1;
            *_DAT_0080d3fa = *local_8;
            _DAT_0080d3fa = puVar5;
            local_8 = (byte *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
          }
          if (_DAT_0080d402 != 0) {
            DAT_0080d405 = '\x01';
          }
        }
      }
      FUN_0000a626((uint)uVar9);
    }
    else {
      FUN_0000a626(CONCAT22(8,uVar9));
    }
  }
  else {
    FUN_0000a626(CONCAT22(4,uVar9));
  }
  return;
}



//
// Function: FUN_00013134 @ 0x00013134
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00013134(void)

{
  uint in_D0;
  
  if (_DAT_0080c3fe == 0) {
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
  short sVar1;
  uint uVar2;
  
  if ((uint)param_3._0_2_ + (uint)_DAT_0080c3fe < 0x201) {
    _DAT_0080c402 = (short)(param_1 + -0x8034f6) + -2;
    uVar2 = CONCAT22((short)((uint)(param_1 + -0x8034f6) >> 0x10),_DAT_0080c402);
    *(short *)((uint)_DAT_0080c3fc * 2 + 0x80bdfa) = _DAT_0080c402;
    for (; param_3._0_2_ != 0; param_3._0_2_ = param_3._0_2_ - 1) {
      *(undefined1 *)((short)_DAT_0080c3fc + 0x80c1fa) = *param_2;
      sVar1 = (short)(param_1 + -0x8034f6) + -2;
      uVar2 = CONCAT22((short)((uint)(param_1 + -0x8034f6) >> 0x10),sVar1);
      *(short *)((uint)_DAT_0080c3fc * 2 + 0x80bdfa) = sVar1;
      _DAT_0080c3fc = _DAT_0080c3fc + 1 & 0x1ff;
      _DAT_0080c3fe = _DAT_0080c3fe + 1;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    return uVar2 & 0xffffff00;
  }
  return 1;
}



//
// Function: FUN_000131d6 @ 0x000131d6
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
  if (((DAT_0080d2d0 == '\x01') && ((_DAT_00fffc0c & 0x20) == 0)) && (DAT_0080d2da == '\0')) {
    _DAT_00fffc0e = (ushort)*_DAT_0080d2b8;
    DAT_0080d2da = '\x01';
    _DAT_00fff45a = 0xfc8a;
    _DAT_00fff458 = _DAT_00fff458 & 0x7fff | 0x4000;
    DAT_0080d2d0 = '\0';
    _DAT_0080d2d6 = 0;
    DAT_0080d2d1 = 1;
    DAT_0080d2d3 = *_DAT_0080d2b8;
    _DAT_00fffc0a = _DAT_00fffc0a | 0x20;
  }
  return;
}



//
// Function: FUN_000132c8 @ 0x000132c8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_000132c8(void)

{
  uint uVar1;
  
  if (_DAT_0080c422 == 0) {
    if (_DAT_0080c418 != 0) {
      _DAT_0080c418 = 0;
      FUN_00013890();
    }
  }
  else {
    _DAT_0080c422 = _DAT_0080c422 + -1;
    _DAT_0080c418 = (ushort)(_DAT_00807cba / _DAT_0080c40a);
  }
  if (_DAT_0080c424 == 0) {
    if (_DAT_0080c416 != 0) {
      _DAT_0080c416 = 0;
      FUN_000138fe();
    }
  }
  else {
    _DAT_0080c424 = _DAT_0080c424 + -1;
    if ((_DAT_00807ce2 & 0xc) != 0) {
      _DAT_0080c416 = (ushort)(_DAT_00807cbe / _DAT_0080c40e);
    }
  }
  if (_DAT_0080c426 == 0) {
    if (_DAT_0080c428 != 0) {
      _DAT_0080c428 = 0;
    }
  }
  else {
    _DAT_0080c426 = _DAT_0080c426 + -1;
  }
  if ((_DAT_0080c422 == 0) && (current_engine_param != 0)) {
    if (_DAT_0080c76c < _DAT_00807cee) {
      _DAT_0080c76c = _DAT_0080c76c + 1;
    }
    else {
      _DAT_00805df6 = _DAT_00805df6 | 0x1000;
      _DAT_00805e36 = _DAT_00805e36 | 0x1000;
    }
  }
  else if ((_DAT_0080c422 != 0) &&
          ((_DAT_0080c76c = 0, (_DAT_00805df6 & 0x1000) != 0 && ((_DAT_00805e36 & 0x1000) == 0)))) {
    _DAT_00805df6 = _DAT_00805df6 & 0xefff;
  }
  if ((((_DAT_00807ce2 & 0xc) == 0) || (_DAT_0080c424 != 0)) || (current_engine_param == 0)) {
    if (((_DAT_0080c424 != 0) && (_DAT_0080c76e = 0, (_DAT_00805df6 & 0x400) != 0)) &&
       ((_DAT_00805e36 & 0x400) == 0)) {
      _DAT_00805df6 = _DAT_00805df6 & 0xfbff;
    }
  }
  else if (_DAT_0080c76e < _DAT_00807cf0) {
    _DAT_0080c76e = _DAT_0080c76e + 1;
  }
  else {
    _DAT_00805df6 = _DAT_00805df6 | 0x400;
    _DAT_00805e36 = _DAT_00805e36 | 0x400;
  }
  if ((_DAT_0080c426 == 0) && (current_engine_param != 0)) {
    if (_DAT_0080c770 < _DAT_00807cf2) {
      _DAT_0080c770 = _DAT_0080c770 + 1;
    }
    else {
      _DAT_00805e16 = _DAT_00805e16 | 4;
      _DAT_00805e56 = _DAT_00805e56 | 4;
    }
  }
  else if ((_DAT_0080c426 != 0) &&
          ((_DAT_0080c770 = 0, (_DAT_00805e16 & 4) != 0 && ((_DAT_00805e56 & 4) == 0)))) {
    _DAT_00805e16 = _DAT_00805e16 & 0xfffb;
  }
  if (((DAT_0080c7b3 == '\x01') && (_DAT_0080c76a = 0, (_DAT_00805df6 & 0x4000) != 0)) &&
     ((_DAT_00805e36 & 0x4000) == 0)) {
    _DAT_00805df6 = _DAT_00805df6 & 0xbfff;
  }
  if ((DAT_0080c7b3 == '\0') && (current_engine_param != 0)) {
    if (_DAT_0080c76a < _DAT_00807cec) {
      _DAT_0080c76a = _DAT_0080c76a + 1;
    }
    else {
      _DAT_00805df6 = _DAT_00805df6 | 0x4000;
      _DAT_00805e36 = _DAT_00805e36 | 0x4000;
    }
  }
  else if ((DAT_0080c7b3 == '\0') &&
          ((_DAT_0080c76a = 0, (_DAT_00805df6 & 0x4000) != 0 && ((_DAT_00805e36 & 0x4000) == 0)))) {
    _DAT_00805df6 = _DAT_00805df6 & 0xbfff;
  }
  if ((((DAT_0080c7b2 == '\x01') || (DAT_0080c7b2 == '\0')) &&
      (_DAT_0080c768 = 0, (_DAT_00805df6 & 0x800) != 0)) && ((_DAT_00805e36 & 0x800) == 0)) {
    _DAT_00805df6 = _DAT_00805df6 & 0xf7ff;
  }
  (*_DAT_0080c78e)();
  uVar1 = (uint)_DAT_0080c42a;
  if (_DAT_0080c42a == 0) {
    if (_DAT_0080c422 == 0) {
      _DAT_0080c404 = 0;
      current_engine_param = 0;
      _DAT_0080c406 = 0;
    }
    else {
      _DAT_0080c404 = _DAT_0080c418;
      current_engine_param = FUN_000356f8();
      uVar1 = _DAT_00807cc2 / _DAT_0080c776;
      _DAT_0080c406 = (ushort)uVar1;
    }
  }
  else if (_DAT_0080c42a == 1) {
    if (_DAT_0080c424 == 0) {
      _DAT_0080c404 = 0;
      current_engine_param = 0;
      _DAT_0080c406 = 0;
    }
    else {
      _DAT_0080c404 = _DAT_0080c416;
      current_engine_param = FUN_000356f8();
      uVar1 = _DAT_00807cc2 / _DAT_0080c77a;
      _DAT_0080c406 = (ushort)uVar1;
    }
  }
  else if (_DAT_0080c42a == 2) {
    if (_DAT_0080c426 == 0) {
      _DAT_0080c404 = 0;
      current_engine_param = 0;
      _DAT_0080c406 = 0;
    }
    else {
      _DAT_0080c404 = _DAT_0080c428;
      uVar1 = FUN_000356f8();
      _DAT_0080c406 = (ushort)uVar1;
      current_engine_param = _DAT_0080c406;
    }
  }
  if (_DAT_00809cba != 0) {
    _DAT_0080c406 = _DAT_00809cb8;
    _DAT_0080c404 = _DAT_00809cb8;
    current_engine_param = _DAT_00809cb8;
  }
  if (_DAT_0080c810 == 1) {
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
  if (_DAT_0080c406 < 0x800) {
    _DAT_0080c772 = _DAT_00807cb8;
    _DAT_0080c774 = _DAT_00807cdc;
    return uVar1;
  }
  if (_DAT_0080c406 < 0xff8) {
    _DAT_0080c772 = (short)((int)(uint)_DAT_00807cb8 >> 1);
    _DAT_0080c774 = (short)((int)(uint)_DAT_00807cdc >> 1);
    return (int)(uint)_DAT_00807cdc >> 1;
  }
  if (0x17ff < _DAT_0080c406) {
    _DAT_0080c772 = (short)((int)(uint)_DAT_00807cb8 >> 3);
    _DAT_0080c774 = (short)((int)(uint)_DAT_00807cdc >> 3);
    return (int)(uint)_DAT_00807cdc >> 3;
  }
  _DAT_0080c772 = (short)((int)(uint)_DAT_00807cb8 >> 2);
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
  _DAT_00800280 = 0x807cb6;
  _DAT_0080c772 = _DAT_00807cb8;
  _DAT_0080c78e = &LAB_000137d8;
  _DAT_0080c42a = 0;
  return;
}



//
// Function: FUN_00013890 @ 0x00013890
//

void FUN_00013890(void)

{
  switch(DAT_00807cf7) {
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000138fe(void)

{
  if (_DAT_00807d10 == 1) {
    FUN_00016ba8();
    return;
  }
  if (_DAT_00807d10 != 2) {
    if (_DAT_00807d10 != 0) {
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
  if (((_DAT_0080c810 == 2) || (_DAT_0080c810 == 6)) || (_DAT_0080c810 == 7)) {
    _DAT_0080c800 = _DAT_0080c80e + _DAT_0080c802;
    if (_DAT_00807d3e < _DAT_0080c800) {
      _DAT_0080c800 = _DAT_00807d3e;
    }
    _DAT_0080c7fe = _DAT_0080c80c + _DAT_0080c7f6;
    if (_DAT_00807d3a < _DAT_0080c7fe) {
      _DAT_0080c7fe = _DAT_00807d3a;
    }
    if (current_engine_param < _DAT_0080c800) {
      _DAT_0080c7e8 = _DAT_0080c7fe;
      return;
    }
    if ((_DAT_0080c800 <= current_engine_param) && (current_engine_param <= _DAT_0080c7fc)) {
      _DAT_0080c7e8 =
           (short)((((uint)current_engine_param - (uint)_DAT_0080c800) *
                   ((uint)_DAT_0080c806 + (uint)_DAT_00807d36)) /
                  (uint)(ushort)(_DAT_0080c7fc - _DAT_0080c800)) +
           (short)(((uint)_DAT_0080c7fe * ((uint)_DAT_0080c7fc - (uint)current_engine_param)) /
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
    uVar2 = FUN_000357f6((short *)&DAT_008002a2);
    _DAT_0080c7ec = (short)((ulonglong)uVar2 >> 0x20);
  }
  else if (_DAT_0080965a == 0) {
    _DAT_008002bc = _DAT_0080c7fc;
    _DAT_008002c4 = _DAT_0080c806 + _DAT_00807d36;
    uVar2 = FUN_000357f6((short *)&DAT_008002b6);
    _DAT_0080c7ec =
         (short)((uint)(ushort)((ulonglong)uVar2 >> 0x20) * (0x4000 - (uint)_DAT_0080965a) >> 0xe);
  }
  else {
    _DAT_008002a8 = _DAT_0080c7fc;
    _DAT_008002b0 = _DAT_0080c806 + _DAT_00807d36;
    uVar2 = FUN_000357f6((short *)&DAT_008002a2);
    _DAT_008002bc = _DAT_0080c7fc;
    _DAT_008002c4 = _DAT_0080c806 + _DAT_00807d36;
    uVar3 = FUN_000357f6((short *)&DAT_008002b6);
    _DAT_0080c7ec =
         (short)((uint)_DAT_0080965a * (uint)(ushort)((ulonglong)uVar2 >> 0x20) >> 0xe) +
         (short)((uint)(ushort)((ulonglong)uVar3 >> 0x20) * (0x4000 - (uint)_DAT_0080965a) >> 0xe);
  }
  if ((uint)_DAT_0080c806 + (uint)_DAT_00807d36 < (uint)_DAT_00808a84) {
    _DAT_0080029c = _DAT_008091ea;
    sVar1 = FUN_00035560((short *)&DAT_00800296);
    _DAT_0080c7f4 =
         sVar1 - (short)((int)((int)&LAB_00004caa - (uint)_DAT_00807d2c) / (int)_DAT_00808a82);
    if ((short)_DAT_0080c7f4 < 0) {
      _DAT_0080c7f4 = 0;
    }
  }
  else {
    _DAT_0080c7f4 = 0;
  }
  _DAT_00800290 = _DAT_0080926e;
  _DAT_0080c7f2 = FUN_00035560((short *)&DAT_0080028a);
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
  if (((_DAT_0080c810 == 2) || (_DAT_0080c810 == 6)) || (_DAT_0080c810 == 7)) {
    FUN_00013a1e();
    if (current_engine_param < _DAT_0080c804) {
      _DAT_0080c7ea = _DAT_0080c7f8;
      return;
    }
    if ((_DAT_0080c804 <= current_engine_param) && (current_engine_param <= _DAT_0080c7fc)) {
      _DAT_0080c7ea =
           _DAT_0080c7f8 +
           (short)(((int)(short)(_DAT_0080c808 - _DAT_0080c7f8) *
                   (int)(short)(current_engine_param - _DAT_0080c804)) /
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
  if (((_DAT_00805df6 & 1) == 0) ||
     (uVar3 = CONCAT22((short)(in_D0 >> 0x10),_DAT_008068c8) & 0xffff0001, (_DAT_008068c8 & 1) == 0)
     ) {
    uVar2 = (undefined2)(uVar3 >> 0x10);
    uVar3 = CONCAT22(uVar2,_DAT_00805df6) & 0xffff0002;
    if ((((_DAT_00805df6 & 2) == 0) ||
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
// Function: FUN_00013e82 @ 0x00013e82
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00013e82(void)

{
  if ((_DAT_00807d52 < _DAT_0080c7ee) && (_DAT_00800288 == 0)) {
    _DAT_0080c7fa = _DAT_00807d4a + _DAT_00807d48;
    _DAT_00800288 = 1;
  }
  if (current_engine_param == 0) {
    _DAT_0080c7fa = _DAT_00807d48;
  }
  _DAT_008002ca = _DAT_0080c810;
  return;
}



//
// Function: FUN_00013ecc @ 0x00013ecc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00013ecc(void)

{
  if (((_DAT_0080c810 == 2) || (_DAT_0080c810 == 6)) || (_DAT_0080c810 == 7)) {
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
  if (((_DAT_008002cc == 1) && (_DAT_0080c810 == 2)) ||
     ((_DAT_008002cc == 3 && (_DAT_0080c810 == 7)))) {
    FUN_00013c6a();
    FUN_00013d86();
    FUN_00013d66();
  }
  FUN_00013e82();
  _DAT_008002cc = _DAT_0080c810;
  return;
}



//
// Function: FUN_00013f46 @ 0x00013f46
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00013f46(void)

{
  if ((_DAT_0080c810 == 6) && (current_engine_param < _DAT_0080c800)) {
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
  if ((_DAT_008002ce == 7) && (_DAT_0080c810 == 1)) {
    _DAT_0080c80c = 0;
    _DAT_0080c80e = 0;
  }
  _DAT_008002ce = _DAT_0080c810;
  return;
}



//
// Function: FUN_00013fe2 @ 0x00013fe2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00013fe2(void)

{
  if ((((_DAT_0080c810 == 2) || (_DAT_0080c810 == 6)) && (_DAT_00807d58 < current_engine_param)) &&
     (_DAT_0080c806 = _DAT_00807d5a + _DAT_0080c806, _DAT_00807d5c < _DAT_0080c806)) {
    _DAT_0080c806 = _DAT_00807d5c;
  }
  if ((_DAT_008002d0 != 3) && (_DAT_0080c810 == 3)) {
    _DAT_0080c806 = 0;
  }
  _DAT_008002d0 = _DAT_0080c810;
  return;
}



//
// Function: FUN_0001403e @ 0x0001403e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001403e(void)

{
  if (_DAT_0080c810 == 3) {
    _DAT_0080c7ee = _DAT_0080c7ee + 1;
  }
  if (_DAT_0080c810 == 1) {
    _DAT_0080c7ee = 0;
    _DAT_00800288 = 0;
  }
  if (_DAT_0080c810 == 2) {
    _DAT_0080c7f0 = _DAT_0080c7f0 + 1;
  }
  else if ((_DAT_008002d2 == 7) && (_DAT_0080c810 == 1)) {
    _DAT_0080c7f0 = 0;
  }
  _DAT_008002d2 = _DAT_0080c810;
  return;
}



//
// Function: FUN_00014090 @ 0x00014090
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00014090(void)

{
  if (((_DAT_008002d4 == 3) && (_DAT_0080c810 == 7)) && (_DAT_00807d52 < _DAT_0080c7ee)) {
    _DAT_0080c80c = _DAT_00807d54;
    _DAT_0080c80e = _DAT_00807d56;
  }
  _DAT_008002d4 = _DAT_0080c810;
  return;
}



//
// Function: FUN_000140ce @ 0x000140ce
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000140ce(void)

{
  _DAT_0080028c = 0x8079ee;
  _DAT_00800292 = 0x807a00;
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
// Function: FUN_00014174 @ 0x00014174
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00014174(void)

{
  switch(_DAT_0080c810) {
  case 1:
    if ((_DAT_00807d64 < current_engine_param) && (_DAT_00804d84 == 0)) {
      _DAT_0080c810 = 2;
    }
    else if ((((DAT_0080bdc6 & 1) == 0) && (_DAT_0080d450 == 0)) || (_DAT_0080c996 == 1)) {
      _DAT_0080c810 = 8;
    }
    break;
  case 2:
    if (_DAT_00807d64 < current_engine_param) {
      if (current_engine_param < _DAT_0080c7fc) {
        if (_DAT_00807d4c < _DAT_0080c7f0) {
          _DAT_0080c810 = 6;
        }
        else if ((((DAT_0080bdc6 & 1) == 0) && (_DAT_0080d450 == 0)) || (_DAT_0080c996 == 1)) {
          _DAT_0080c810 = 8;
        }
      }
      else {
        _DAT_0080c810 = 3;
      }
    }
    else {
      _DAT_0080c810 = 1;
    }
    break;
  case 3:
    if (_DAT_0080969e == 1) {
      _DAT_0080c810 = 4;
    }
    else if (_DAT_0080c7fa < current_engine_param) {
      if ((((DAT_0080bdc6 & 1) == 0) && (_DAT_0080d450 == 0)) || (_DAT_0080c996 == 1)) {
        _DAT_0080c810 = 8;
      }
      else if (current_engine_param < _DAT_00807d5e) {
        _DAT_008002d6 = 0;
      }
      else {
        _DAT_008002d6 = _DAT_008002d6 + 1;
        if (_DAT_00807d62 < _DAT_008002d6) {
          _DAT_0080c810 = 5;
          _DAT_008002d6 = 0;
        }
      }
    }
    else {
      _DAT_0080c810 = 7;
    }
    break;
  case 4:
    if (_DAT_0080969e == 0) {
      _DAT_0080c810 = 3;
    }
    else if ((((DAT_0080bdc6 & 1) == 0) && (_DAT_0080d450 == 0)) || (_DAT_0080c996 == 1)) {
      _DAT_0080c810 = 8;
    }
    break;
  case 5:
    if (current_engine_param < _DAT_00807d60) {
      _DAT_0080c810 = 3;
    }
    else if ((((DAT_0080bdc6 & 1) == 0) && (_DAT_0080d450 == 0)) || (_DAT_0080c996 == 1)) {
      _DAT_0080c810 = 8;
    }
    _DAT_00805df6 = _DAT_00805df6 | 0x8000;
    _DAT_00805e36 = _DAT_00805e36 | 0x8000;
    if (_DAT_00804d80 == 0) {
      _DAT_00804d80 = 1;
      *(undefined4 *)((short)_DAT_00804d82 * 8 + 0x804c68) = _DAT_0080d4c4;
      *(undefined2 *)((short)_DAT_00804d82 * 8 + 0x804c6e) = 0;
      *(word *)((short)_DAT_00804d82 * 8 + 0x804c6c) = current_engine_param;
    }
    else if (*(ushort *)((short)_DAT_00804d82 * 8 + 0x804c6c) < current_engine_param) {
      *(word *)((short)_DAT_00804d82 * 8 + 0x804c6c) = current_engine_param;
    }
    break;
  case 6:
    if (_DAT_00807d64 < current_engine_param) {
      if (current_engine_param < _DAT_0080c7fc) {
        if ((((DAT_0080bdc6 & 1) == 0) && (_DAT_0080d450 == 0)) || (_DAT_0080c996 == 1)) {
          _DAT_0080c810 = 8;
        }
      }
      else {
        _DAT_0080c810 = 3;
      }
    }
    else {
      _DAT_0080c810 = 1;
    }
    break;
  case 7:
    if (_DAT_00807d64 < current_engine_param) {
      if (current_engine_param < _DAT_0080c7fc) {
        if ((((DAT_0080bdc6 & 1) == 0) && (_DAT_0080d450 == 0)) || (_DAT_0080c996 == 1)) {
          _DAT_0080c810 = 8;
        }
      }
      else {
        _DAT_0080c810 = 3;
      }
    }
    else {
      _DAT_0080c810 = 1;
    }
    break;
  case 8:
    if ((((_DAT_0080c996 == 1) && (current_engine_param == 0)) ||
        ((_DAT_0080c996 == 0 && ((DAT_0080bdc6 & 1) != 0)))) &&
       ((_DAT_0080c810 = 1, current_engine_param == 0 && (_DAT_0080c996 == 1)))) {
      _DAT_0080c996 = 0;
    }
    if (((current_engine_param == 0) && ((DAT_0080bdc6 & 1) == 0)) && (_DAT_0080d450 == 0)) {
      _DAT_0080c812 = 1;
    }
    break;
  default:
    _DAT_0080c810 = 1;
  }
  if (((_DAT_0080c810 != 5) && ((_DAT_00805df6 & 0x8000) != 0)) && ((_DAT_00805e36 & 0x8000) == 0))
  {
    _DAT_00805df6 = _DAT_00805df6 & 0x7fff;
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
// Function: FUN_00014536 @ 0x00014536
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00014536(void)

{
  _DAT_0080c810 = 1;
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
  
  if ((_DAT_008035d8 & 0x10) == 0) {
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
  
  uVar3 = _DAT_008035d8 & 0x10;
  if ((((((_DAT_008035d8 & 0x10) != 0) && (uVar3 = _DAT_008035d8 & 1, (_DAT_008035d8 & 1) != 0)) &&
       (uVar3 = _DAT_008035d8 & 0x20, (_DAT_008035d8 & 0x20) != 0)) &&
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
  
  uVar1 = _DAT_008035d8 & 1;
  if ((((_DAT_008035d8 & 1) != 0) && (uVar1 = _DAT_008035d8 & 0x20, (_DAT_008035d8 & 0x20) != 0)) &&
     (_DAT_00804e76 != 0xff)) {
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
      if (((uint)*(ushort *)(&DAT_008035d4 + (short)((int)uVar2 >> 4) * 2) & 1 << (uVar2 & 0xf)) ==
          0) {
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
  _DAT_0080c992 = FUN_000356f8(0x80);
  return;
}



//
// Function: FUN_00014cfc @ 0x00014cfc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00014cfc(void)

{
  _DAT_008002e2 = (uint)_DAT_008037b4 << 0x10;
  _DAT_008002de = 0x807e6e;
  _DAT_0080c992 = _DAT_008037b4;
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
  if ((((_DAT_008035d8 & 1) == 0) || (_DAT_0080c810 == 8)) || (_DAT_0080c810 == 1)) {
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
    if ((_DAT_008002e6 == 0) && (current_engine_param != 0)) {
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
  _DAT_008002e6 = current_engine_param;
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
      if (_DAT_008002ee[0xb] < current_engine_param) {
        *(undefined2 *)(_DAT_008002f2 + 9) = 1;
      }
      else if (current_engine_param == 0) {
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
            uVar1 = FUN_0001462e(CONCAT22(*(undefined2 *)*puVar6,**(undefined2 **)((int)puVar6 + 10)
                                         ),CONCAT22(**(undefined2 **)((int)puVar6 + 0xe),uVar9));
            uVar3 = (ushort)uVar1;
          }
          else {
            uVar3 = 0;
          }
        }
        else {
          uVar3 = FUN_000145d4((int)puVar7,(int)puVar6,puVar8,(uint)uVar9);
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
    if (current_engine_param == 0) {
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
    lookup_table_fuel[2] = current_engine_param;
    _DAT_0080c98e = FUN_00035560((short *)&DAT_008002fe);
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
// Function: FUN_0001562e @ 0x0001562e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001562e(void)

{
  _DAT_008002fa = 0;
  _DAT_008002fc = 0;
  _DAT_008002fe = 2;
  lookup_table_fuel[0] = 0x80;
  lookup_table_fuel[1] = 0x7e72;
  lookup_table_fuel[3] = 0x80;
  lookup_table_fuel[4] = 0x7ea4;
  _DAT_0080c98e = _DAT_00807f3c;
  _DAT_0080c990 = 0;
  return;
}



//
// Function: FUN_0001566a @ 0x0001566a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001566a(void)

{
  ushort uVar1;
  int *piVar2;
  
  stack_area._28_2_ = stack_area._28_2_ & 0xffcf;
  stack_area._10_2_ = stack_area._10_2_ & 0xfbff;
  stack_area._32_2_ = stack_area._32_2_ & 0xfbff;
  _DAT_0080c77e = (int *)((uint)DAT_00807cce * 4 + 0x80c42c);
  for (piVar2 = (int *)&DAT_0080c430; piVar2 <= _DAT_0080c77e; piVar2 = piVar2 + 1) {
    *piVar2 = _DAT_00807cc6;
  }
  _DAT_0080c786 = &DAT_0080c430;
  if (DAT_00807cd0 < 2) {
    _DAT_0080c41a = &DAT_0080c430;
  }
  else {
    _DAT_0080c41a = &DAT_0080c430 + (uint)DAT_00807cd0 * 4;
  }
  _DAT_0080c776 = _DAT_00807cc6 * (uint)DAT_00807cce;
  _DAT_0080c40a = _DAT_00807cc6 * (uint)DAT_00807cd0;
  _DAT_00808eea = FUN_00015796;
  uVar1 = stack_area._14_2_ & 0xf0ff | 0xd00;
  stack_area[0xe] = (char)(uVar1 >> 8);
  stack_area[0xf] = (char)uVar1;
  register_map[0xa2] = (char)((ushort)((ushort)DAT_00807cda << 8) >> 8);
  register_map[0xa3] = (char)((ushort)DAT_00807cda << 8);
  register_map[0xa6] = 0;
  register_map[0xa7] = 0;
  register_map[0xa8] = 0;
  register_map[0xa9] = 0;
  register_map[0xaa] = 0;
  register_map[0xab] = 0;
  register_map[0xa0] = 0;
  register_map[0xa1] = 0xb;
  uVar1 = stack_area._20_2_ & 0xffcf | 0x30;
  stack_area[0x14] = (char)(uVar1 >> 8);
  stack_area[0x15] = (char)uVar1;
  uVar1 = stack_area._24_2_ & 0xffcf | 0x30;
  stack_area[0x18] = (char)(uVar1 >> 8);
  stack_area[0x19] = (char)uVar1;
  uVar1 = stack_area._10_2_ | 0x400;
  stack_area[10] = (char)(uVar1 >> 8);
  stack_area[0xb] = (char)uVar1;
  uVar1 = stack_area._28_2_ & 0xffcf | 0x20;
  stack_area[0x1c] = (char)(uVar1 >> 8);
  stack_area[0x1d] = (char)uVar1;
  if (DAT_00807cf7 == '\0') {
    _DAT_0080c78e = &LAB_0001416c;
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
  ushort uVar1;
  undefined4 uVar2;
  undefined4 in_D0;
  undefined4 in_D1;
  undefined2 uVar3;
  undefined2 uStack_1e;
  
  uVar2 = register_map._168_4_;
  uVar3 = (undefined2)((uint)in_D0 >> 0x10);
  uStack_1e = (undefined2)in_D0;
  _DAT_0080c75c = register_map._168_4_;
  register_map._168_4_ = register_map._168_4_ & 0xffff;
  _DAT_0080c776 = uVar2 + (_DAT_0080c776 - *(int *)_DAT_0080c41a);
  *(undefined4 *)_DAT_0080c41a = uVar2;
  if (_DAT_0080c41a < _DAT_0080c77e) {
    _DAT_0080c41a = _DAT_0080c41a + 4;
  }
  else {
    _DAT_0080c41a = &DAT_0080c430;
  }
  if (_DAT_0080c412 < -(uint)_DAT_00807cd2 - 1) {
    _DAT_0080c412 = _DAT_00807cd2 + _DAT_0080c412;
  }
  _DAT_0080c40a = _DAT_0080c75c + (_DAT_0080c40a - *(int *)_DAT_0080c786);
  if (_DAT_0080c786 < _DAT_0080c77e) {
    _DAT_0080c786 = _DAT_0080c786 + 4;
  }
  else {
    _DAT_0080c786 = &DAT_0080c430;
  }
  if ((int)(uint)_DAT_0080c7ae < (int)(DAT_00807cce - 1)) {
    _DAT_0080c7ae = _DAT_0080c7ae + 1;
  }
  else {
    _DAT_0080c7ae = 0;
  }
  _DAT_0080c422 = _DAT_0080c772;
  if (_DAT_00807d10 == 1) {
    if (DAT_0080c7d4 == '\0') {
      if (DAT_0080c7d3 < DAT_00807d20) {
        DAT_0080c7d3 = DAT_0080c7d3 + 1;
      }
      else {
        _DAT_00805df2 = _DAT_00805df2 | 1;
        _DAT_00805e32 = _DAT_00805e32 | 1;
      }
      DAT_0080c7b2 = 2;
      _DAT_00805df6 = _DAT_00805df6 | 0x800;
      _DAT_00805e36 = _DAT_00805e36 | 0x800;
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
  FUN_00010504(CONCAT22(1,uVar3));
  if ((_DAT_0080c75c < -_DAT_0080c750 - 1U) &&
     (_DAT_0080c750 = _DAT_0080c75c + _DAT_0080c750, _DAT_0080c758 != -1)) {
    _DAT_0080c758 = _DAT_0080c758 + 1;
  }
  FUN_00015e96();
  FUN_0000c260();
  uVar1 = stack_area._32_2_ & 0xfbff;
  stack_area[0x20] = (char)(uVar1 >> 8);
  stack_area[0x21] = (char)uVar1;
  return CONCAT44(CONCAT22(uVar3,uStack_1e),in_D1);
}



//
// Function: FUN_00015968 @ 0x00015968
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00015968(void)

{
  ushort uVar1;
  int *piVar2;
  
  stack_area._28_2_ = stack_area._28_2_ & 0xffcf;
  stack_area._10_2_ = stack_area._10_2_ & 0xfbff;
  stack_area._32_2_ = stack_area._32_2_ & 0xfbff;
  _DAT_0080c77e = (int *)((uint)DAT_00807cce * 4 + 0x80c42c);
  for (piVar2 = (int *)&DAT_0080c430; piVar2 <= _DAT_0080c77e; piVar2 = piVar2 + 1) {
    *piVar2 = _DAT_00807cc6;
  }
  _DAT_0080c786 = &DAT_0080c430;
  if (DAT_00807cd0 < 2) {
    _DAT_0080c41a = &DAT_0080c430;
  }
  else {
    _DAT_0080c41a = &DAT_0080c430 + (uint)DAT_00807cd0 * 4;
  }
  _DAT_0080c776 = _DAT_00807cc6 * (uint)DAT_00807cce;
  _DAT_0080c40a = _DAT_00807cc6 * (uint)DAT_00807cd0;
  _DAT_00808eea = FUN_00015b4a;
  uVar1 = stack_area._14_2_ & 0xf0ff | 0xd00;
  stack_area[0xe] = (char)(uVar1 >> 8);
  stack_area[0xf] = (char)uVar1;
  register_map[0xa2] = (char)((ushort)((ushort)DAT_00807cda << 8) >> 8);
  register_map[0xa3] = (char)((ushort)DAT_00807cda << 8);
  register_map[0xa6] = 0;
  register_map[0xa7] = 0;
  register_map[0xa8] = 0;
  register_map[0xa9] = 0;
  register_map[0xaa] = 0;
  register_map[0xab] = 0;
  register_map[0xa0] = 0;
  register_map[0xa1] = 0xb;
  uVar1 = stack_area._20_2_ & 0xffcf | 0x30;
  stack_area[0x14] = (char)(uVar1 >> 8);
  stack_area[0x15] = (char)uVar1;
  uVar1 = stack_area._24_2_ & 0xffcf | 0x30;
  stack_area[0x18] = (char)(uVar1 >> 8);
  stack_area[0x19] = (char)uVar1;
  uVar1 = stack_area._10_2_ | 0x400;
  stack_area[10] = (char)(uVar1 >> 8);
  stack_area[0xb] = (char)uVar1;
  uVar1 = stack_area._28_2_ & 0xffcf | 0x20;
  stack_area[0x1c] = (char)(uVar1 >> 8);
  stack_area[0x1d] = (char)uVar1;
  if (DAT_00807cf7 == '\0') {
    _DAT_0080c78e = &LAB_0001416c;
  }
  return;
}



//
// Function: FUN_00015a8a @ 0x00015a8a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00015a8a(void)

{
  stack_area._32_2_ = stack_area._32_2_ & 0xfffe;
  stack_area._18_2_ = stack_area._18_2_ & 0xfff0 | 9;
  _DAT_00808ec2 = &LAB_00015c30;
  register_map[0] = 0;
  register_map[1] = 7;
  register_map._2_2_ = DAT_00807d02 | 0x100;
  register_map[4] = 1;
  register_map[5] = 0;
  register_map[6] = DAT_00807d03;
  register_map[7] = DAT_00807d04;
  register_map[8] = 0;
  register_map[9] = 0;
  register_map[10] = 0;
  register_map[0xb] = 0;
  register_map[0xc] = 0;
  register_map[0xd] = 0;
  stack_area._22_2_ = stack_area._22_2_ & 0xfffc | 3;
  stack_area._26_2_ = stack_area._26_2_ & 0xfffc | 1;
  stack_area._10_2_ = stack_area._10_2_ & 0xfffe | 1;
  stack_area._30_2_ = stack_area._30_2_ & 0xfffc | 1;
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
  ushort uVar1;
  undefined4 uVar2;
  undefined4 in_D0;
  undefined4 in_D1;
  undefined2 uVar3;
  undefined2 uStack_1e;
  
  uVar2 = register_map._168_4_;
  uVar3 = (undefined2)((uint)in_D0 >> 0x10);
  uStack_1e = (undefined2)in_D0;
  _DAT_0080c75c = register_map._168_4_;
  register_map._168_4_ = register_map._168_4_ & 0xffff;
  _DAT_0080c776 = uVar2 + (_DAT_0080c776 - *(int *)_DAT_0080c41a);
  *(undefined4 *)_DAT_0080c41a = uVar2;
  if (_DAT_0080c41a < _DAT_0080c77e) {
    _DAT_0080c41a = _DAT_0080c41a + 4;
  }
  else {
    _DAT_0080c41a = &DAT_0080c430;
  }
  if (_DAT_0080c412 < -(uint)_DAT_00807cd2 - 1) {
    _DAT_0080c412 = _DAT_00807cd2 + _DAT_0080c412;
  }
  _DAT_0080c40a = _DAT_0080c75c + (_DAT_0080c40a - *(int *)_DAT_0080c786);
  if (_DAT_0080c786 < _DAT_0080c77e) {
    _DAT_0080c786 = _DAT_0080c786 + 4;
  }
  else {
    _DAT_0080c786 = &DAT_0080c430;
  }
  _DAT_0080c422 = _DAT_0080c772;
  FUN_00010504(CONCAT22(1,uVar3));
  if ((_DAT_0080c75c < -_DAT_0080c750 - 1U) &&
     (_DAT_0080c750 = _DAT_0080c75c + _DAT_0080c750, _DAT_0080c758 != -1)) {
    _DAT_0080c758 = _DAT_0080c758 + 1;
  }
  FUN_00015e96();
  FUN_0000c260();
  uVar1 = stack_area._32_2_ & 0xfbff;
  stack_area[0x20] = (char)(uVar1 >> 8);
  stack_area[0x21] = (char)uVar1;
  return CONCAT44(CONCAT22(uVar3,uStack_1e),in_D1);
}



//
// Function: FUN_00015e96 @ 0x00015e96
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00015e96(void)

{
  ushort uVar1;
  
  if (_DAT_0080c424 == 0) {
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
  
  if (_DAT_0080c422 == 0) {
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
  ushort uVar1;
  short sVar2;
  int *piVar3;
  
  stack_area._28_2_ = stack_area._28_2_ & 0xffcf;
  stack_area._10_2_ = stack_area._10_2_ & 0xfbff;
  stack_area._32_2_ = stack_area._32_2_ & 0xfbff;
  _DAT_0080c77e = (int *)((uint)DAT_00807cce * 4 + 0x80c42c);
  for (piVar3 = (int *)&DAT_0080c430; piVar3 <= _DAT_0080c77e; piVar3 = piVar3 + 1) {
    *piVar3 = _DAT_00807cc6;
  }
  _DAT_0080c786 = &DAT_0080c430;
  if (DAT_00807cd0 < 2) {
    _DAT_0080c41a = &DAT_0080c430;
  }
  else {
    _DAT_0080c41a = &DAT_0080c430 + (uint)DAT_00807cd0 * 4;
  }
  _DAT_0080c776 = _DAT_00807cc6 * (uint)DAT_00807cce;
  _DAT_0080c40a = _DAT_00807cc6 * (uint)DAT_00807cd0;
  _DAT_00808eea = FUN_00016192;
  uVar1 = stack_area._14_2_ & 0xf0ff | 0xd00;
  stack_area[0xe] = (char)(uVar1 >> 8);
  stack_area[0xf] = (char)uVar1;
  sVar2 = _DAT_00807cd6 / DAT_00807cce << 8;
  register_map[0xa2] = (char)((ushort)sVar2 >> 8);
  register_map[0xa3] = (char)sVar2;
  register_map[0xa6] = 0;
  register_map[0xa7] = 0;
  register_map[0xa8] = 0;
  register_map[0xa9] = 0;
  register_map[0xaa] = 0;
  register_map[0xab] = 0;
  register_map[0xa0] = 0;
  register_map[0xa1] = 0xb;
  uVar1 = stack_area._20_2_ & 0xffcf | 0x30;
  stack_area[0x14] = (char)(uVar1 >> 8);
  stack_area[0x15] = (char)uVar1;
  uVar1 = stack_area._24_2_ & 0xffcf | 0x30;
  stack_area[0x18] = (char)(uVar1 >> 8);
  stack_area[0x19] = (char)uVar1;
  uVar1 = stack_area._10_2_ | 0x400;
  stack_area[10] = (char)(uVar1 >> 8);
  stack_area[0xb] = (char)uVar1;
  uVar1 = stack_area._28_2_ & 0xffcf | 0x20;
  stack_area[0x1c] = (char)(uVar1 >> 8);
  stack_area[0x1d] = (char)uVar1;
  if (DAT_00807cf7 == '\0') {
    _DAT_0080c78e = &LAB_0001416c;
  }
  return;
}



//
// Function: FUN_000160e2 @ 0x000160e2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000160e2(void)

{
  stack_area._32_2_ = stack_area._32_2_ & 0xfffe;
  stack_area._18_2_ = stack_area._18_2_ & 0xfff0 | 9;
  register_map[0] = 0;
  register_map[1] = 4;
  register_map._2_2_ = DAT_00807d02 | 0x100;
  register_map[6] = DAT_00807d03;
  register_map[7] = DAT_00807d04;
  register_map[0xfc] = 0xc0;
  register_map[0xfd] = 0;
  stack_area._22_2_ = stack_area._22_2_ & 0xfffc | 3;
  stack_area._26_2_ = stack_area._26_2_ & 0xfffc | 1;
  stack_area._30_2_ = stack_area._30_2_ & 0xfffc | 2;
  _DAT_00808ec2 = &LAB_00016370;
  stack_area._10_2_ = stack_area._10_2_ & 0xfffe | 1;
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
  ushort uVar1;
  undefined4 uVar2;
  undefined4 in_D0;
  undefined4 in_D1;
  undefined2 uVar3;
  undefined2 uStack_1e;
  
  uVar2 = register_map._168_4_;
  uVar3 = (undefined2)((uint)in_D0 >> 0x10);
  uStack_1e = (undefined2)in_D0;
  _DAT_0080c75c = register_map._168_4_;
  register_map._168_4_ = register_map._168_4_ & 0xffff;
  _DAT_0080c776 = uVar2 + (_DAT_0080c776 - *(int *)_DAT_0080c41a);
  *(undefined4 *)_DAT_0080c41a = uVar2;
  if (_DAT_0080c41a < _DAT_0080c77e) {
    _DAT_0080c41a = _DAT_0080c41a + 4;
  }
  else {
    _DAT_0080c41a = &DAT_0080c430;
  }
  if (_DAT_0080c412 < -(uint)_DAT_00807cd2 - 1) {
    _DAT_0080c412 = _DAT_00807cd2 + _DAT_0080c412;
  }
  _DAT_0080c40a = _DAT_0080c75c + (_DAT_0080c40a - *(int *)_DAT_0080c786);
  if (_DAT_0080c786 < _DAT_0080c77e) {
    _DAT_0080c786 = _DAT_0080c786 + 4;
  }
  else {
    _DAT_0080c786 = &DAT_0080c430;
  }
  if ((int)(uint)_DAT_0080c7ae < (int)(DAT_00807cce - 1)) {
    _DAT_0080c7ae = _DAT_0080c7ae + 1;
  }
  else {
    _DAT_0080c7ae = 0;
  }
  _DAT_0080c422 = _DAT_0080c772;
  if (_DAT_00807d10 == 1) {
    if (DAT_0080c7d4 == '\0') {
      if (DAT_0080c7d3 < DAT_00807d20) {
        DAT_0080c7d3 = DAT_0080c7d3 + 1;
      }
      else {
        _DAT_00805df2 = _DAT_00805df2 | 1;
        _DAT_00805e32 = _DAT_00805e32 | 1;
      }
      DAT_0080c7b2 = 2;
      _DAT_00805df6 = _DAT_00805df6 | 0x800;
      _DAT_00805e36 = _DAT_00805e36 | 0x800;
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
  FUN_00010504(CONCAT22(1,uVar3));
  FUN_00010504(CONCAT22(1,uVar3));
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
  uVar1 = stack_area._32_2_ & 0xfbff;
  stack_area[0x20] = (char)(uVar1 >> 8);
  stack_area[0x21] = (char)uVar1;
  return CONCAT44(CONCAT22(uVar3,uStack_1e),in_D1);
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
  
  uVar1 = CONCAT22((short)((uint)in_D0 >> 0x10),_DAT_00807ce2) & 0xffff0001;
  if ((_DAT_00807ce2 & 1) != 0) {
    stack_area._28_2_ = stack_area._28_2_ & 0xffcf;
    stack_area._10_2_ = stack_area._10_2_ & 0xfbff;
    stack_area._32_2_ = stack_area._32_2_ & 0xfbff;
    _DAT_0080c77e = (int *)((uint)DAT_00807cce * 4 + 0x80c42c);
    for (piVar2 = (int *)&DAT_0080c430; piVar2 <= _DAT_0080c77e; piVar2 = piVar2 + 1) {
      *piVar2 = _DAT_00807cc6;
    }
    _DAT_0080c786 = &DAT_0080c430;
    if (DAT_00807cd0 < 2) {
      _DAT_0080c41a = &DAT_0080c430;
    }
    else {
      _DAT_0080c41a = &DAT_0080c430 + (uint)DAT_00807cd0 * 4;
    }
    _DAT_0080c776 = _DAT_00807cc6 * (uint)DAT_00807cce;
    uVar1 = _DAT_00807cc6 * (uint)DAT_00807cd0;
    lookup_table_fuel._50_4_ = &DAT_0080c430;
    _DAT_00808eea = FUN_00016552;
    stack_area._14_2_ = stack_area._14_2_ & 0xf0ff | 0xd00;
    register_map[0xa2] = 1;
    register_map[0xa3] = 0;
    register_map[0xa6] = 0;
    register_map[0xa7] = 0;
    register_map[0xa8] = 0;
    register_map[0xa9] = 0;
    register_map[0xaa] = 0;
    register_map[0xab] = 0;
    register_map[0xa0] = 0;
    register_map[0xa1] = 7;
    stack_area._20_2_ = stack_area._20_2_ & 0xffcf | 0x20;
    stack_area._24_2_ = stack_area._24_2_ & 0xffcf | 0x30;
    stack_area._10_2_ = stack_area._10_2_ | 0x400;
    stack_area._28_2_ = stack_area._28_2_ & 0xffcf | 0x20;
    _DAT_0080c792 = &LAB_00016814;
    _DAT_0080c40a = uVar1;
  }
  if (DAT_00807cf7 == '\0') {
    _DAT_0080c78e = &LAB_0001416c;
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
  ushort uVar1;
  undefined4 uVar2;
  undefined4 in_D0;
  int iVar3;
  undefined4 in_D1;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uStack_22;
  
  uVar2 = register_map._168_4_;
  uVar5 = (undefined2)((uint)in_D0 >> 0x10);
  uStack_22 = (undefined2)in_D0;
  register_map._168_4_ = register_map._168_4_ & 0xffff;
  uVar4 = SUB42(uVar2,2);
  iVar3 = FUN_00016622(uVar2,CONCAT22(register_map._164_2_,uVar5));
  if (DAT_0080c7b2 == '\x01') {
    if (iVar3 == 0) {
      register_map[0xa0] = 0xff;
      register_map[0xa1] = 0xff;
      stack_area._24_2_ = stack_area._24_2_ & 0xffcf | 0x20;
    }
  }
  else {
    register_map[0xa0] = 0x80;
    register_map[0xa1] = 0x80;
    stack_area._24_2_ = stack_area._24_2_ & 0xffcf | 0x20;
  }
  FUN_00010504(CONCAT22(1,uVar4));
  if ((_DAT_0080c75c < -_DAT_0080c750 - 1U) &&
     (_DAT_0080c750 = _DAT_0080c75c + _DAT_0080c750, _DAT_0080c758 != -1)) {
    _DAT_0080c758 = _DAT_0080c758 + 1;
  }
  FUN_00015e96();
  FUN_0000c260();
  uVar1 = stack_area._32_2_ & 0xfbff;
  stack_area[0x20] = (char)(uVar1 >> 8);
  stack_area[0x21] = (char)uVar1;
  return CONCAT44(CONCAT22(uVar5,uStack_22),in_D1);
}



//
// Function: FUN_00016622 @ 0x00016622
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00016622(int param_1,undefined4 param_2)

{
  short sVar5;
  int iVar1;
  uint unaff_A2;
  int iVar2;
  int iVar3;
  int iVar4;
  
  _DAT_0080c75c = param_1;
  _DAT_0080c764 = param_2._0_2_;
  sVar5 = FUN_0000def4(unaff_A2 >> 0x10);
  if (sVar5 != 0) {
    if ((uint)DAT_00807cce == lookup_table_fuel._34_4_) {
      DAT_0080c7b2 = '\x01';
    }
    else {
      if (DAT_0080c7b2 == '\x01') {
        DAT_0080c7b2 = '\x02';
      }
      if ((_DAT_0080c404 < _DAT_00807ce6) && (_DAT_0080c7b8 < DAT_00807d0e)) {
        _DAT_0080c7b8 = _DAT_0080c7b8 + 1;
      }
      else if (((DAT_0080c7b2 == '\x02') && (_DAT_0080c7a2 <= _DAT_0080c7a4)) ||
              ((DAT_0080c7b6 == '\x02' && (_DAT_0080c7a2 <= _DAT_0080c7a6)))) {
        _DAT_00805df6 = _DAT_00805df6 | 0x800;
        _DAT_00805e36 = _DAT_00805e36 | 0x800;
      }
    }
    iVar1 = _DAT_0080c75c;
    _DAT_0080c75c = SUB42(_DAT_0080c75c,2);
    DAT_0080c75c_2 = (undefined2)_DAT_0080c75c;
    lookup_table_fuel[0x15] = _DAT_0080c75c;
    lookup_table_fuel[0x16] = DAT_0080c75c_2;
    lookup_table_fuel[0x11] = 0;
    lookup_table_fuel[0x12] = 0;
    _DAT_0080c422 = _DAT_0080c772;
    _DAT_0080c75c = iVar1;
    return 0;
  }
  lookup_table_fuel._34_4_ = lookup_table_fuel._34_4_ + 1;
  if (lookup_table_fuel._34_4_ == 1) {
    _DAT_0080c75c = lookup_table_fuel._42_4_ + _DAT_0080c75c;
    _DAT_0080c7ae = 0;
  }
  else if ((_DAT_0080c7ae < DAT_00807cce) || (DAT_0080c7b2 != '\x01')) {
    _DAT_0080c7ae = _DAT_0080c7ae + 1;
  }
  else {
    DAT_0080c7b2 = '\x02';
  }
  _DAT_0080c776 = _DAT_0080c75c + (_DAT_0080c776 - *_DAT_0080c41a);
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
  _DAT_0080c40a = _DAT_0080c75c + (_DAT_0080c40a - *_DAT_0080c786);
  if (_DAT_0080c786 < _DAT_0080c77e) {
    _DAT_0080c786 = _DAT_0080c786 + 1;
  }
  else {
    _DAT_0080c786 = (int *)&DAT_0080c430;
  }
  if (_DAT_0080c7a6 != 0 || _DAT_0080c7a4 != 0) {
    iVar4._0_2_ = lookup_table_fuel[0x11];
    iVar4._2_2_ = lookup_table_fuel[0x12];
    _DAT_0080c422 = _DAT_0080c772;
    return iVar4;
  }
  if ((_DAT_00805df6 & 0x800) == 0) {
    iVar3._0_2_ = lookup_table_fuel[0x11];
    iVar3._2_2_ = lookup_table_fuel[0x12];
    _DAT_0080c422 = _DAT_0080c772;
    _DAT_0080c7b8 = 0;
    return iVar3;
  }
  if ((_DAT_00805e36 & 0x800) != 0) {
    iVar2._0_2_ = lookup_table_fuel[0x11];
    iVar2._2_2_ = lookup_table_fuel[0x12];
    _DAT_0080c422 = _DAT_0080c772;
    _DAT_0080c7b8 = 0;
    return iVar2;
  }
  iVar1._0_2_ = lookup_table_fuel[0x11];
  iVar1._2_2_ = lookup_table_fuel[0x12];
  _DAT_00805df6 = _DAT_00805df6 & 0xf7ff;
  _DAT_0080c422 = _DAT_0080c772;
  _DAT_0080c7b8 = 0;
  return iVar1;
}



//
// Function: FUN_0001685c @ 0x0001685c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0001685c(void)

{
  ushort uVar1;
  
  uVar1 = _DAT_008035ec & 0x10;
  if (uVar1 != 0) {
    if (_DAT_0080379c == 0) {
      if (_DAT_0080c7c6 == 2) {
        _DAT_00800342 = _DAT_00807f22;
      }
      else {
        _DAT_00800342 = _DAT_00807f16;
      }
      if (_DAT_00809d4c < _DAT_00800342) {
        if (_DAT_0080c7c8 < _DAT_00807f26) {
          _DAT_0080c7c8 = _DAT_0080c7c8 + 1;
        }
      }
      else {
        _DAT_0080c7c8 = 0;
      }
      if (((_DAT_00809d4c < _DAT_00807f16) && (_DAT_00807f26 <= _DAT_0080c7c8)) ||
         (_DAT_0080c7c6 == 2)) {
        _DAT_0080c7ca = 0;
      }
      else if (_DAT_0080c7ca < _DAT_00807f28) {
        _DAT_0080c7ca = _DAT_0080c7ca + 1;
      }
      _DAT_00800346 = _DAT_00800344 - current_engine_param;
      _DAT_00800344 = current_engine_param;
      _DAT_0080c7c2 = FUN_00035608();
      if ((int)(uint)_DAT_00807f14 < (int)_DAT_0080c7c2) {
        if (_DAT_0080c7c0 < _DAT_00807f12) {
          _DAT_0080c7c0 = _DAT_0080c7c0 + 1;
        }
      }
      else {
        _DAT_0080c7c0 = 0;
      }
      FUN_0002c252();
      if (_DAT_0080c7c6 == 0) {
        if ((((int)((uint)_DAT_0080c9d8 - (uint)_DAT_00807f24) <= (int)(uint)_DAT_0080c9a4) &&
            (_DAT_0080c7ce != 0)) &&
           (((DAT_0080bdc7 & 8) == 0 &&
            ((_DAT_0080926e < _DAT_00807f1a && (_DAT_008091ea < _DAT_00807f1c)))))) {
          _DAT_0080c7c4 = 0x4000;
          _DAT_0080c7c6 = 2;
        }
        if ((((((_DAT_008035ec & 0x20) != 0) && ((DAT_0080bdc7 & 8) == 0)) && (_DAT_0080c7cc != 0))
            && ((_DAT_0080965a < _DAT_00807f0e && (_DAT_00807f16 <= _DAT_00809d4c)))) &&
           ((_DAT_0080926e < _DAT_00807f1a && (_DAT_008091ea < _DAT_00807f1c)))) {
          _DAT_0080c7c4 = _DAT_00807f18;
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
        if ((((_DAT_0080c7cc != 0) || (_DAT_00807f0e <= _DAT_0080965a)) ||
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
        _DAT_0080c7c4 = _DAT_00807f18;
      }
    }
    uVar1 = 0x4000 - _DAT_0080c7c4;
    _DAT_0080c9aa = uVar1;
  }
  return uVar1;
}



//
// Function: FUN_00016af2 @ 0x00016af2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00016af2(void)

{
  _DAT_0080c7c6 = 0;
  ram0x0080033e = 0x80000000;
  lookup_table_fuel[0x1d] = 0x80;
  lookup_table_fuel[0x1e] = 0x7f10;
  return;
}



//
// Function: FUN_00016b0e @ 0x00016b0e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_00016b0e(void)

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
// Function: FUN_00016ba8 @ 0x00016ba8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00016ba8(void)

{
  ushort uVar1;
  int *piVar2;
  
  stack_area._30_2_ = stack_area._30_2_ & 0xfff3;
  stack_area._10_2_ = stack_area._10_2_ & 0xfffd;
  stack_area._32_2_ = stack_area._32_2_ & 0xfffd;
  DAT_0080c7b2 = 0;
  DAT_0080c7b3 = 0;
  _DAT_0080c782 = (int *)((uint)DAT_00807ccf * 4 + 0x80c5bc);
  for (piVar2 = (int *)&DAT_0080c5c0; piVar2 <= _DAT_0080c782; piVar2 = piVar2 + 1) {
    *piVar2 = _DAT_00807cca;
  }
  _DAT_0080c78a = &DAT_0080c5c0;
  if (DAT_00807cd1 < 2) {
    _DAT_0080c41e = &DAT_0080c5c0;
  }
  else {
    _DAT_0080c41e = &DAT_0080c5c0 + (uint)DAT_00807cd1 * 4;
  }
  _DAT_0080c77a = _DAT_00807cca * (uint)DAT_00807ccf;
  _DAT_0080c40e = _DAT_00807cca * (uint)DAT_00807cd1;
  _DAT_00808ec6 = FUN_00016cb4;
  uVar1 = stack_area._18_2_ & 0xff0f | 0xd0;
  stack_area[0x12] = (char)(uVar1 >> 8);
  stack_area[0x13] = (char)uVar1;
  register_map[0x12] = 1;
  register_map[0x13] = 0;
  register_map[0x16] = 0;
  register_map[0x17] = 0;
  register_map[0x18] = 0;
  register_map[0x19] = 0;
  register_map[0x1a] = 0;
  register_map[0x1b] = 0;
  register_map[0x10] = 0;
  register_map[0x11] = 0x4f;
  uVar1 = stack_area._22_2_ & 0xfff3;
  stack_area[0x16] = (char)(uVar1 >> 8);
  stack_area[0x17] = (char)uVar1;
  uVar1 = stack_area._26_2_ & 0xfff3 | 0xc;
  stack_area[0x1a] = (char)(uVar1 >> 8);
  stack_area[0x1b] = (char)uVar1;
  uVar1 = stack_area._10_2_ | 2;
  stack_area[10] = (char)(uVar1 >> 8);
  stack_area[0xb] = (char)uVar1;
  uVar1 = stack_area._30_2_ & 0xfff3 | 8;
  stack_area[0x1e] = (char)(uVar1 >> 8);
  stack_area[0x1f] = (char)uVar1;
  return;
}



//
// Function: FUN_00016cb4 @ 0x00016cb4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00016cb4(void)

{
  ushort uVar1;
  undefined4 in_D0;
  undefined4 in_D1;
  
  DAT_0080c7d0 = register_map[0x1b];
  register_map[0x18] = 0;
  register_map[0x19] = 0;
  DAT_0080c7d4 = DAT_00807d1d;
  if (register_map[0x1b] == _DAT_00807d18) {
    if (DAT_0080c7d2 == 0) {
      if (((_DAT_00805df2 & 1) != 0) && ((_DAT_00805e32 & 1) == 0)) {
        _DAT_00805df2 = _DAT_00805df2 & 0xfffe;
      }
    }
    else {
      DAT_0080c7d2 = DAT_0080c7d2 - 1;
    }
    if (_DAT_0080c7ae == _DAT_00807d14) {
      DAT_0080c7b2 = 1;
      DAT_0080c7b3 = 1;
      if (((_DAT_00805df6 & 0x800) != 0) && ((_DAT_00805e36 & 0x800) == 0)) {
        _DAT_00805df6 = _DAT_00805df6 & 0xf7ff;
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
      _DAT_0080c7ae = _DAT_00807d14;
      if (DAT_0080c7d1 < DAT_00807d1e) {
        DAT_0080c7d1 = DAT_0080c7d1 + 1;
      }
      else {
        _DAT_00805df2 = _DAT_00805df2 | 1;
        _DAT_00805e32 = _DAT_00805e32 | 1;
        _DAT_00805df6 = _DAT_00805df6 | 0x800;
        _DAT_00805e36 = _DAT_00805e36 | 0x800;
      }
    }
  }
  else if (register_map[0x1b] == _DAT_00807d1a) {
    if (DAT_0080c7d2 == 0) {
      if (((_DAT_00805df2 & 1) != 0) && ((_DAT_00805e32 & 1) == 0)) {
        _DAT_00805df2 = _DAT_00805df2 & 0xfffe;
      }
    }
    else {
      DAT_0080c7d2 = DAT_0080c7d2 - 1;
    }
    if (_DAT_0080c7ae == _DAT_00807d16) {
      DAT_0080c7b2 = 1;
      DAT_0080c7b3 = 1;
      if (((_DAT_00805df6 & 0x800) != 0) && ((_DAT_00805e36 & 0x800) == 0)) {
        _DAT_00805df6 = _DAT_00805df6 & 0xf7ff;
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
      _DAT_0080c7ae = _DAT_00807d16;
      if (DAT_0080c7d1 < DAT_00807d1e) {
        DAT_0080c7d1 = DAT_0080c7d1 + 1;
      }
      else {
        _DAT_00805df2 = _DAT_00805df2 | 1;
        _DAT_00805e32 = _DAT_00805e32 | 1;
        _DAT_00805df6 = _DAT_00805df6 | 0x800;
        _DAT_00805e36 = _DAT_00805e36 | 0x800;
      }
    }
  }
  else if (DAT_0080c7d2 < DAT_00807d1f) {
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
  uVar1 = stack_area._32_2_ & 0xfffd;
  stack_area[0x20] = (char)(uVar1 >> 8);
  stack_area[0x21] = (char)uVar1;
  return CONCAT44(in_D0,in_D1);
}



//
// Function: FUN_00016f98 @ 0x00016f98
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00016f98(void)

{
  int *piVar1;
  
  stack_area._30_2_ = stack_area._30_2_ & 0xfff3;
  stack_area._10_2_ = stack_area._10_2_ & 0xfffd;
  stack_area._32_2_ = stack_area._32_2_ & 0xfffd;
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
  _DAT_0080c77a = _DAT_00807cca * (uint)DAT_00807ccf;
  _DAT_0080c40e = _DAT_00807cca * (uint)DAT_00807cd1;
  if ((_DAT_00807ce2 & 8) != 0) {
    _DAT_00808ec6 = FUN_000170b4;
    stack_area._18_2_ = stack_area._18_2_ & 0xff0f | 0xd0;
    register_map[0x12] = 1;
    register_map[0x13] = 0;
    register_map[0x16] = 0;
    register_map[0x17] = 0;
    register_map[0x18] = 0;
    register_map[0x19] = 0;
    register_map[0x1a] = 0;
    register_map[0x1b] = 0;
    register_map[0x10] = 0;
    register_map[0x11] = 0xb;
    stack_area._22_2_ = stack_area._22_2_ & 0xfff3 | 0xc;
    stack_area._26_2_ = stack_area._26_2_ & 0xfff3 | 0xc;
    stack_area._10_2_ = stack_area._10_2_ | 2;
    stack_area._30_2_ = stack_area._30_2_ & 0xfff3 | 8;
    stack_area._32_2_ = stack_area._32_2_ & 0xfffd;
  }
  return CONCAT22((short)(_DAT_00807cca * (uint)DAT_00807cd1 >> 0x10),_DAT_00807ce2) & 0xffff0008;
}



//
// Function: FUN_000170b4 @ 0x000170b4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000170b4(void)

{
  ushort uVar1;
  undefined4 in_D0;
  undefined4 in_D1;
  
  if ((_DAT_00807ce2 & 8) != 0) {
    _DAT_0080c424 = _DAT_0080c774;
    _DAT_0080c760 = register_map._24_4_;
    DAT_0080c7b4 = 1;
    if (((_DAT_00805df6 & 0x800) != 0) && ((_DAT_00805e36 & 0x800) == 0)) {
      _DAT_00805df6 = _DAT_00805df6 & 0xf7ff;
    }
    _DAT_0080c5c0 = register_map._24_4_;
    _DAT_0080c40e = register_map._24_4_;
  }
  register_map._24_4_ = register_map._24_4_ & 0xffff;
  if ((_DAT_0080c760 < -_DAT_0080c754 - 1U) &&
     (_DAT_0080c754 = _DAT_0080c760 + _DAT_0080c754, _DAT_0080c75a != -1)) {
    _DAT_0080c75a = _DAT_0080c75a + 1;
  }
  FUN_0002b6c2();
  FUN_0000c262();
  uVar1 = stack_area._32_2_ & 0xfffd;
  stack_area[0x20] = (char)(uVar1 >> 8);
  stack_area[0x21] = (char)uVar1;
  return CONCAT44(in_D0,in_D1);
}



//
// Function: FUN_00017164 @ 0x00017164
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00017164(void)

{
  ushort uVar1;
  int *piVar2;
  
  _DAT_0080c782 = (int *)((uint)DAT_00807ccf * 4 + 0x80c5bc);
  for (piVar2 = (int *)&DAT_0080c5c0; piVar2 <= _DAT_0080c782; piVar2 = piVar2 + 1) {
    *piVar2 = _DAT_00807cca;
  }
  _DAT_0080c78a = &DAT_0080c5c0;
  if (DAT_00807cd1 < 2) {
    _DAT_0080c41e = &DAT_0080c5c0;
  }
  else {
    _DAT_0080c41e = &DAT_0080c5c0 + (uint)DAT_00807cd1 * 4;
  }
  _DAT_0080c77a = _DAT_00807cca * (uint)DAT_00807ccf;
  _DAT_0080c40e = _DAT_00807cca * (uint)DAT_00807cd1;
  uVar1 = stack_area._32_2_ & 0xfffd;
  stack_area[0x20] = (char)(uVar1 >> 8);
  stack_area[0x21] = (char)uVar1;
  uVar1 = stack_area._18_2_ & 0xff0f | 0xd0;
  stack_area[0x12] = (char)(uVar1 >> 8);
  stack_area[0x13] = (char)uVar1;
  register_map[0x12] = 1;
  register_map[0x13] = 0;
  register_map[0x16] = 0;
  register_map[0x17] = 0;
  register_map[0x18] = 0;
  register_map[0x19] = 0;
  register_map[0x1a] = 0;
  register_map[0x1b] = 0;
  register_map[0x10] = 0;
  register_map[0x11] = 0xb;
  uVar1 = stack_area._22_2_ & 0xfff3 | 0xc;
  stack_area[0x16] = (char)(uVar1 >> 8);
  stack_area[0x17] = (char)uVar1;
  uVar1 = stack_area._26_2_ & 0xfff3 | 0xc;
  stack_area[0x1a] = (char)(uVar1 >> 8);
  stack_area[0x1b] = (char)uVar1;
  uVar1 = stack_area._30_2_ & 0xfff3 | 8;
  stack_area[0x1e] = (char)(uVar1 >> 8);
  stack_area[0x1f] = (char)uVar1;
  _DAT_00808ec6 = FUN_00017278;
  uVar1 = stack_area._10_2_ & 0xfffd | 2;
  stack_area[10] = (char)(uVar1 >> 8);
  stack_area[0xb] = (char)uVar1;
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
  ushort uVar1;
  undefined4 in_D0;
  undefined4 in_D1;
  
  if ((_DAT_0080c760 < -_DAT_0080c754 - 1U) &&
     (_DAT_0080c754 = _DAT_0080c760 + _DAT_0080c754, _DAT_0080c75a != -1)) {
    _DAT_0080c75a = _DAT_0080c75a + 1;
  }
  FUN_0002b6c2();
  FUN_0000c262();
  uVar1 = stack_area._32_2_ & 0xfffd;
  stack_area[0x20] = (char)(uVar1 >> 8);
  stack_area[0x21] = (char)uVar1;
  return CONCAT44(in_D0,in_D1);
}



//
// Function: FUN_000172bc @ 0x000172bc
//

void FUN_000172bc(void)

{
  FUN_000122d0();
  return;
}



//
// Function: FUN_000172c4 @ 0x000172c4
//

void FUN_000172c4(void)

{
  FUN_0001b1f4();
  FUN_0001cc38();
  FUN_0001b9da();
  FUN_0001cad6();
  FUN_00035298();
  return;
}



//
// Function: FUN_000172e4 @ 0x000172e4
//

void FUN_000172e4(void)

{
  FUN_0001b314();
  FUN_0001afe4();
  FUN_0001d29c();
  return;
}



//
// Function: FUN_000172f8 @ 0x000172f8
//

void FUN_000172f8(void)

{
  ushort in_stack_00000000;
  
  FUN_00010504((uint)in_stack_00000000);
  FUN_00011c28();
  FUN_000132c8();
  FUN_0002bc2a();
  FUN_0000e200();
  FUN_0001848e();
  FUN_0000afa0();
  FUN_0000bf2e();
  FUN_0002b4c2();
  return;
}



//
// Function: FUN_00017334 @ 0x00017334
//

void FUN_00017334(void)

{
  FUN_0000b656();
  FUN_000181cc();
  FUN_0002604e();
  FUN_00025a90();
  FUN_00026110();
  FUN_0002bc62();
  FUN_0001892a();
  FUN_0001863e();
  return;
}



//
// Function: FUN_00017366 @ 0x00017366
//

void FUN_00017366(void)

{
  FUN_000132c8();
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
// Function: FUN_000173f4 @ 0x000173f4
//

void FUN_000173f4(void)

{
  return;
}



//
// Function: FUN_000173f6 @ 0x000173f6
//

void FUN_000173f6(void)

{
  FUN_0002e336();
  FUN_0002d6a2();
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
// Function: FUN_00017434 @ 0x00017434
//

void FUN_00017434(void)

{
  FUN_0002cb6a();
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
// Function: FUN_00017440 @ 0x00017440
//

void FUN_00017440(void)

{
  FUN_0000a16a();
  FUN_0000a204();
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
// Function: FUN_000174ae @ 0x000174ae
//

void FUN_000174ae(void)

{
  FUN_0001685c();
  FUN_00016b0e();
  FUN_000341ea();
  FUN_000342f6();
  return;
}



//
// Function: FUN_000174c8 @ 0x000174c8
//

void FUN_000174c8(void)

{
  FUN_0000c8c2();
  FUN_000343f8();
  FUN_000344e8();
  return;
}



//
// Function: FUN_000174dc @ 0x000174dc
//

void FUN_000174dc(void)

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
// Function: FUN_000175ba @ 0x000175ba
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000175ba(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  FUN_00017b88();
  switch(_DAT_00800358) {
  case 0:
    FUN_000172bc();
    FUN_000172c4();
    FUN_000172f8();
    FUN_000173f4();
    FUN_00017440();
    FUN_000174ae();
    FUN_0002b452();
    _DAT_0080035c = &DAT_00809782;
    _DAT_00800358 = 1;
    break;
  case 1:
    FUN_000172bc();
    FUN_000172e4();
    FUN_00017334();
    FUN_000173f6();
    FUN_0001744e();
    FUN_000174c8();
    FUN_0000c368();
    _DAT_00800358 = 2;
    break;
  case 2:
    FUN_000172bc();
    FUN_000172c4();
    FUN_00017366();
    FUN_00017404();
    FUN_0001745c();
    FUN_000174dc();
    FUN_000283dc();
    _DAT_00800358 = 3;
    break;
  case 3:
    FUN_000172bc();
    FUN_000172e4();
    FUN_000173b0();
    FUN_00017412();
    FUN_00017464();
    FUN_000174fc();
    _DAT_00800358 = 4;
    break;
  case 4:
    FUN_000172bc();
    FUN_000172c4();
    FUN_000172f8();
    FUN_00017426();
    FUN_0001746c();
    FUN_00017504();
    FUN_00026ff4();
    _DAT_00800358 = 5;
    break;
  case 5:
    FUN_000172bc();
    FUN_000172e4();
    FUN_00017334();
    FUN_00017434();
    FUN_00017486();
    FUN_00017512();
    _DAT_00800358 = 6;
    break;
  case 6:
    FUN_000172bc();
    FUN_000172c4();
    FUN_00017366();
    FUN_0001743c();
    FUN_0001748e();
    FUN_0001752c();
    FUN_0000eb5a();
    _DAT_00800358 = 7;
    break;
  case 7:
    FUN_000172bc();
    FUN_000172e4();
    FUN_000173b0();
    FUN_0001743e();
    FUN_00017496();
    FUN_00017534();
    FUN_0002bb6c();
    _DAT_00800358 = 8;
    break;
  case 8:
    FUN_000172bc();
    FUN_000172c4();
    FUN_000172f8();
    FUN_000173f4();
    FUN_0001749e();
    FUN_0001753c();
    FUN_0000fd68();
    _DAT_00800358 = 9;
    break;
  case 9:
    FUN_000172bc();
    FUN_000172e4();
    FUN_00017334();
    FUN_000173f6();
    FUN_000174a6();
    FUN_00017544();
    FUN_0000b18c();
    _DAT_00800358 = 10;
    break;
  case 10:
    FUN_000172bc();
    FUN_000172c4();
    FUN_00017366();
    FUN_00017404();
    FUN_00017440();
    FUN_0001754c();
    FUN_00026d98();
    _DAT_00800358 = 0xb;
    break;
  case 0xb:
    FUN_000172bc();
    FUN_000172e4();
    FUN_000173b0();
    FUN_00017412();
    FUN_0001744e();
    FUN_00017554();
    FUN_00013f46();
    _DAT_00800358 = 0xc;
    break;
  case 0xc:
    FUN_000172bc();
    FUN_000172c4();
    FUN_000172f8();
    FUN_00017426();
    FUN_0001745c();
    FUN_00017568();
    FUN_00013fe2();
    _DAT_00800358 = 0xd;
    break;
  case 0xd:
    FUN_000172bc();
    FUN_000172e4();
    FUN_00017334();
    FUN_00017434();
    FUN_00017464();
    FUN_00017570();
    FUN_0001403e();
    _DAT_00800358 = 0xe;
    break;
  case 0xe:
    FUN_000172bc();
    FUN_000172c4();
    FUN_00017366();
    FUN_0001743c();
    FUN_0001746c();
    FUN_0001757e();
    FUN_000183a6();
    _DAT_00800358 = 0xf;
    break;
  case 0xf:
    FUN_000172bc();
    FUN_000172e4();
    FUN_000173b0();
    FUN_0001743e();
    FUN_00017486();
    FUN_00017586();
    FUN_0001e36a();
    FUN_0002fd74();
    FUN_00014546();
    _DAT_00800358 = 0x10;
    break;
  case 0x10:
    FUN_000172bc();
    FUN_000172c4();
    FUN_000172f8();
    FUN_000173f4();
    FUN_0001748e();
    FUN_00017588();
    FUN_00018428();
    _DAT_00800358 = 0x11;
    break;
  case 0x11:
    FUN_000172bc();
    FUN_000172e4();
    FUN_00017334();
    FUN_000173f6();
    FUN_00017496();
    FUN_00017590();
    _DAT_00800358 = 0x12;
    break;
  case 0x12:
    FUN_000172bc();
    FUN_000172c4();
    FUN_00017366();
    FUN_00017404();
    FUN_0001749e();
    FUN_0001759e();
    FUN_00031c60();
    _DAT_00800358 = 0x13;
    break;
  case 0x13:
    FUN_000172bc();
    FUN_000172e4();
    FUN_000173b0();
    FUN_00017412();
    FUN_000174a6();
    FUN_000175a6();
    _DAT_00800358 = 0x14;
    break;
  case 0x14:
    FUN_000172bc();
    FUN_000172c4();
    FUN_000172f8();
    FUN_00017426();
    FUN_00017440();
    FUN_000174ae();
    _DAT_00800358 = 0x15;
    break;
  case 0x15:
    FUN_000172bc();
    FUN_000172e4();
    FUN_00017334();
    FUN_00017434();
    FUN_0001744e();
    FUN_000174c8();
    _DAT_00800358 = 0x16;
    break;
  case 0x16:
    FUN_000172bc();
    FUN_000172c4();
    FUN_00017366();
    FUN_0001743c();
    FUN_0001745c();
    FUN_000174dc();
    _DAT_00800358 = 0x17;
    break;
  case 0x17:
    FUN_000172bc();
    FUN_000172e4();
    FUN_000173b0();
    FUN_0001743e();
    FUN_00017464();
    FUN_000174fc();
    _DAT_00800358 = 0x18;
    break;
  case 0x18:
    FUN_000172bc();
    FUN_000172c4();
    FUN_000172f8();
    FUN_000173f4();
    FUN_0001746c();
    FUN_00017504();
    _DAT_00800358 = 0x19;
    break;
  case 0x19:
    FUN_000172bc();
    FUN_000172e4();
    FUN_00017334();
    FUN_000173f6();
    FUN_00017486();
    FUN_00017512();
    _DAT_00800358 = 0x1a;
    break;
  case 0x1a:
    FUN_000172bc();
    FUN_000172c4();
    FUN_00017366();
    FUN_00017404();
    FUN_0001748e();
    FUN_0001752c();
    _DAT_00800358 = 0x1b;
    break;
  case 0x1b:
    FUN_000172bc();
    FUN_000172e4();
    FUN_000173b0();
    FUN_00017412();
    FUN_00017496();
    FUN_00017534();
    _DAT_00800358 = 0x1c;
    break;
  case 0x1c:
    FUN_000172bc();
    FUN_000172c4();
    FUN_000172f8();
    FUN_00017426();
    FUN_0001749e();
    FUN_0001753c();
    _DAT_00800358 = 0x1d;
    break;
  case 0x1d:
    FUN_000172bc();
    FUN_000172e4();
    FUN_00017334();
    FUN_00017434();
    FUN_000174a6();
    FUN_00017544();
    _DAT_00800358 = 0x1e;
    break;
  case 0x1e:
    FUN_000172bc();
    FUN_000172c4();
    FUN_00017366();
    FUN_0001743c();
    FUN_00017440();
    FUN_0001754c();
    _DAT_00800358 = 0x1f;
    break;
  case 0x1f:
    FUN_000172bc();
    FUN_000172e4();
    FUN_000173b0();
    FUN_0001743e();
    FUN_0001744e();
    FUN_00017554();
    _DAT_00800358 = 0x20;
    break;
  case 0x20:
    FUN_000172bc();
    FUN_000172c4();
    FUN_000172f8();
    FUN_000173f4();
    FUN_0001745c();
    FUN_00017568();
    _DAT_00800358 = 0x21;
    break;
  case 0x21:
    FUN_000172bc();
    FUN_000172e4();
    FUN_00017334();
    FUN_000173f6();
    FUN_00017464();
    FUN_00017570();
    _DAT_00800358 = 0x22;
    break;
  case 0x22:
    FUN_000172bc();
    FUN_000172c4();
    FUN_00017366();
    FUN_00017404();
    FUN_0001746c();
    FUN_0001757e();
    _DAT_00800358 = 0x23;
    break;
  case 0x23:
    FUN_000172bc();
    FUN_000172e4();
    FUN_000173b0();
    FUN_00017412();
    FUN_00017486();
    FUN_00017586();
    _DAT_00800358 = 0x24;
    break;
  case 0x24:
    FUN_000172bc();
    FUN_000172c4();
    FUN_000172f8();
    FUN_00017426();
    FUN_0001748e();
    FUN_00017588();
    _DAT_00800358 = 0x25;
    break;
  case 0x25:
    FUN_000172bc();
    FUN_000172e4();
    FUN_00017334();
    FUN_00017434();
    FUN_00017496();
    FUN_00017590();
    _DAT_00800358 = 0x26;
    break;
  case 0x26:
    FUN_000172bc();
    FUN_000172c4();
    FUN_00017366();
    FUN_0001743c();
    FUN_0001749e();
    FUN_0001759e();
    _DAT_00800358 = 0x27;
    break;
  case 0x27:
    FUN_000172bc();
    FUN_000172e4();
    FUN_000173b0();
    FUN_0001743e();
    FUN_000174a6();
    FUN_000175a6();
    _DAT_00800358 = 0;
    break;
  default:
    _DAT_00800358 = 0;
  }
  FUN_00017bf2();
  DAT_00fffa27 = 0xaa;
  DAT_00ffd00f = 0xaa;
  return CONCAT44(in_D0,in_D1);
}



//
// Function: FUN_00017b3a @ 0x00017b3a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00017b3a(void)

{
  _DAT_0080976e = 0;
  _DAT_0080977a = 5;
  _DAT_0080977c = 200;
  _DAT_0080977e = 0x9b7;
  _DAT_00809780 = 500;
  _DAT_00809776 = 0;
  _DAT_00800356 = 0;
  _DAT_00fffa22 = 0x152;
  _DAT_00808f0a = FUN_000175ba;
  _DAT_00fffa24 = 0x27;
  return;
}



//
// Function: FUN_00017b88 @ 0x00017b88
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00017b88(void)

{
  undefined4 *puVar1;
  
  if (_DAT_0080976e != 0) {
    if (_DAT_00800356 == 0) {
      for (puVar1 = (undefined4 *)&DAT_00809782; puVar1 < (undefined4 *)0x809a02;
          puVar1 = puVar1 + 4) {
        *puVar1 = 0;
        *(undefined2 *)(puVar1 + 1) = 0;
        *(undefined2 *)((int)puVar1 + 6) = 0xffff;
        *(undefined2 *)(puVar1 + 2) = 0;
        *(undefined2 *)((int)puVar1 + 10) = 0;
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
// Function: FUN_00017bf2 @ 0x00017bf2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00017bf2(void)

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
// Function: FUN_00017c6e @ 0x00017c6e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00017c6e(void)

{
  while (_DAT_0080c812 == 0) {
    if (_DAT_0080976e != 0) {
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
  if (_DAT_0080c810 == 1) {
    _DAT_0080c9a4 = 0;
    _DAT_0080c9a6 = 0x1a;
  }
  else {
    if (_DAT_0080c810 == 8) {
      _DAT_0080c9a6 = 0x1b;
      _DAT_0080c9a4 = _DAT_0080849e;
    }
    else if (_DAT_0080c810 == 5) {
      _DAT_0080c9a6 = 0x19;
      _DAT_0080c9a4 = _DAT_00807f40;
    }
    else {
      uVar1 = _DAT_008035d6 & 2;
      if (uVar1 == 0) {
        if (_DAT_0080c810 == 4) {
          _DAT_0080c9a6 = 0x18;
          _DAT_0080c9a4 = _DAT_00807f3e;
        }
        else if ((_DAT_0080c810 == 2) || (_DAT_0080c810 == 6)) {
          _DAT_0080c9a6 = 0x16;
          _DAT_0080c9a4 = _DAT_0080c7e8;
        }
        else if (_DAT_0080c810 == 3) {
          if ((_DAT_00800360 == 2) || (_DAT_00800360 == 6)) {
            uVar1 = FUN_0001e78e();
            _DAT_00809652 = _DAT_0080c7e8;
          }
          if (((param_system_mode == 0xb) && (_DAT_0080d496 == 0x14)) ||
             (uVar1 = _DAT_00809652, _DAT_00809652 < _DAT_0080d494)) {
            _DAT_0080c9a6 = param_system_mode;
            _DAT_0080c9a4 = _DAT_00809652;
          }
          else {
            _DAT_0080c9a6 = _DAT_0080d496;
            _DAT_0080c9a4 = _DAT_0080d494;
          }
        }
        else {
          _DAT_0080c9a4 = unaff_D2w;
          if (_DAT_0080c810 == 7) {
            if (((param_system_mode == 0xb) && (_DAT_0080d496 == 0x14)) ||
               (uVar1 = _DAT_00809652, _DAT_00809652 < _DAT_0080d494)) {
              _DAT_0080c9a6 = param_system_mode;
              _DAT_0080c9a4 = _DAT_00809652;
            }
            else {
              _DAT_0080c9a6 = _DAT_0080d496;
              _DAT_0080c9a4 = _DAT_0080d494;
            }
            if (_DAT_0080c9a4 < _DAT_0080c7e8) {
              _DAT_0080c9a6 = 0x16;
              _DAT_0080c9a4 = _DAT_0080c7e8;
            }
          }
        }
      }
      else {
        _DAT_0080c9a6 = 0x17;
        _DAT_0080c9a4 = _DAT_008037a0;
      }
    }
    if (_DAT_00807f3c < _DAT_0080c9a4) {
      _DAT_0080c9a4 = _DAT_00807f3c;
    }
    else if (_DAT_0080c9a4 < _DAT_0080849e) {
      _DAT_0080c9a4 = _DAT_0080849e;
    }
  }
  _DAT_00800360 = _DAT_0080c810;
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
  
  DAT_00fffa27 = 0xaa;
  DAT_00ffd00f = 0xaa;
  uVar4 = 0;
  *_DAT_00800362 = 0x2020;
  *_DAT_00800362 = 0xd0d0;
  _DAT_00000000 = 0;
  uVar2 = 0;
  do {
    uVar1 = uVar2 + 1;
    if (40000 < uVar2) {
      _DAT_00000000 = 0xffff;
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
        while ((uVar2 = uVar4 + 1, uVar4 < 40000 && ((_DAT_00000000 & 0x80) != 0x80))) {
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
        _DAT_00000000 = 0xffff;
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
    DAT_00fffa27 = 0xaa;
    DAT_00ffd00f = 0xaa;
    if (_DAT_0080036a <= _DAT_00800362) {
      if ((_DAT_00000000 & 0x10) != 0x10) {
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
    _DAT_00000000 = 0xffff;
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
// Function: FUN_000181cc @ 0x000181cc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000181cc(void)

{
  if (diagnostic_status_register == 8) {
    _DAT_0080c9a8 = activeParamReadFunction();
    cached_parameter_value = _DAT_0080c9a8;
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
    sVar1 = _DAT_0080c9a4;
    if (_DAT_0080ccf2 == 1) {
      _DAT_00800374 = _DAT_0080c9a4;
      sVar1 = FUN_00035560((short *)&DAT_0080036e);
    }
    if (_DAT_0080965a == 0x4000) {
      _DAT_00800380 = current_engine_param;
      _DAT_00800388 = sVar1;
      FUN_000357f6((short *)&DAT_0080037a);
      _DAT_0080c9ac = extraout_D0w;
    }
    else if (_DAT_0080965a == 0) {
      _DAT_00800394 = current_engine_param;
      _DAT_0080039c = sVar1;
      FUN_000357f6((short *)&DAT_0080038e);
      _DAT_0080c9ac = extraout_D0w_00;
    }
    else {
      _DAT_00800380 = current_engine_param;
      _DAT_00800388 = sVar1;
      FUN_000357f6((short *)&DAT_0080037a);
      _DAT_00800394 = current_engine_param;
      _DAT_0080039c = sVar1;
      FUN_000357f6((short *)&DAT_0080038e);
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
  if ((_DAT_008035d8 & 0x4000) != 0) {
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
  _DAT_00800376 = 0x807ca8;
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
  
  if (_DAT_0080c9a4 < _DAT_0080845a) {
    _DAT_0080c9cc = 0;
    return;
  }
  uVar1 = FUN_000357d2((uint)current_engine_param * 0x280,(uint)_DAT_0080c9a4 - (uint)_DAT_0080845a,
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0001842c(void)

{
  ushort uVar1;
  
  uVar1 = DAT_0080bdc6 & 1;
  if (((((DAT_0080bdc6 & 1) != 0) && (_DAT_0080c9c6 == 0)) &&
      ((_DAT_0080969e == 0 || (uVar1 = _DAT_008035d4 & 0x40, (_DAT_008035d4 & 0x40) == 0)))) &&
     (((_DAT_0080c810 == 5 && (uVar1 = _DAT_008035ec & 2, (_DAT_008035ec & 2) == 0)) ||
      (_DAT_0080c810 != 5)))) {
    DAT_0080bdf3 = DAT_0080bdf3 | 0x20;
    return uVar1;
  }
  DAT_0080bdf3 = DAT_0080bdf3 & 0xdf;
  return uVar1;
}



//
// Function: FUN_0001848e @ 0x0001848e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001848e(void)

{
  ushort uVar1;
  short sVar2;
  ushort unaff_D3w;
  ushort unaff_D4w;
  undefined8 uVar3;
  
  uVar1 = _DAT_0080c9aa;
  if (_DAT_0080c9aa != 0) {
    _DAT_008003b6 = current_engine_param;
    uVar3 = FUN_000357f6((short *)&DAT_008003b0);
    unaff_D4w = (ushort)((ulonglong)uVar3 >> 0x20);
  }
  if (uVar1 < 0x4000) {
    _DAT_008003ca = current_engine_param;
    uVar3 = FUN_000357f6((short *)&DAT_008003c4);
    unaff_D3w = (ushort)((ulonglong)uVar3 >> 0x20);
  }
  _DAT_0080c9d8 = unaff_D4w;
  if ((uVar1 != 0x4000) && (_DAT_0080c9d8 = unaff_D3w, uVar1 != 0)) {
    _DAT_0080c9d8 = unaff_D3w + (short)((uint)uVar1 * ((uint)unaff_D4w - (uint)unaff_D3w) >> 0xe);
  }
  if (((((_DAT_00803614 & 0x8000) == 0) ||
       (((_DAT_00805df6 & 2) != 0 && ((_DAT_008068c8 & 2) != 0)))) ||
      (((_DAT_00805df6 & 1) != 0 && ((_DAT_008068c8 & 1) != 0)))) ||
     (((_DAT_00805df6 & 0x10) != 0 && ((_DAT_008068c8 & 0x10) != 0)))) {
    sVar2 = 0;
  }
  else {
    _DAT_008003aa = _DAT_0080926e;
    sVar2 = FUN_00035560((short *)&DAT_008003a4);
  }
  _DAT_0080c9d8 = sVar2 + _DAT_0080c9d8;
  if (_DAT_0080c9d8 < _DAT_0080849e) {
    _DAT_0080c9d8 = _DAT_0080849e;
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
// Function: FUN_00018620 @ 0x00018620
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00018620(void)

{
  if (_DAT_0080c9d8 < _DAT_0080d494) {
    _DAT_0080d494 = _DAT_0080c9d8;
    _DAT_0080d496 = 0x13;
  }
  return;
}



//
// Function: FUN_0001863e @ 0x0001863e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001863e(void)

{
  short sVar1;
  int iVar2;
  
  sVar1 = _DAT_0080cc3c;
  if (param_system_mode == 0xc) {
    if (((int)((int)_DAT_00808472 + (uint)_DAT_0080cc4c) < (int)(uint)current_engine_param) &&
       (_DAT_00809652 < _DAT_00808474)) {
      _DAT_008003e0 = (uint)_DAT_00808470 << 0x10;
      _DAT_0080cc3c = 0;
      _DAT_008003dc = -0x80000000;
    }
    else {
      _DAT_0080cc3c = FUN_00035608();
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
// Function: FUN_0001883a @ 0x0001883a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001883a(void)

{
  _DAT_0080cc3c =
       (short)((int)((int)_DAT_00808466 * ((uint)_DAT_0080cc4c - (uint)current_engine_param)) >> 9);
  if (_DAT_00808468 < _DAT_0080cc3c) {
    _DAT_0080cc3c = _DAT_00808468;
  }
  else if (_DAT_0080cc3c < _DAT_0080846a) {
    _DAT_0080cc3c = _DAT_0080846a;
  }
  _DAT_008003dc = _DAT_0080cc3c * 0x10000 + -0x80000000;
  _DAT_008003e0 = _DAT_0080c9a4 - (short)(((int)_DAT_0080cc3c * (int)_DAT_0080cc44) / 0x3c0);
  if (_DAT_00808478 < _DAT_008003e0) {
    _DAT_008003e0 = _DAT_00808478;
  }
  else if (_DAT_008003e0 < _DAT_00808476) {
    _DAT_008003e0 = _DAT_00808476;
  }
  _DAT_008003e2 = 0;
  if (_DAT_0080847e != 0) {
    FUN_0001863e();
  }
  return;
}



//
// Function: FUN_000188f6 @ 0x000188f6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000188f6(void)

{
  _DAT_0080cc44 = _DAT_0080845e;
  _DAT_0080cc46 = _DAT_00808462;
  _DAT_0080cc48 = _DAT_00808460;
  _DAT_008003dc = 0x80000000;
  _DAT_008003d8 = 0x808464;
  return;
}



//
// Function: FUN_0001892a @ 0x0001892a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001892a(void)

{
  uint uVar1;
  ushort uVar2;
  
  if (_DAT_0080d000 == 1) {
    _DAT_0080cc4c = _DAT_0080875c;
    _DAT_0080cc4a = 8;
    _DAT_0080cc5c = 0;
    return;
  }
  _DAT_0080cc54 = *_DAT_0080cc5e;
  _DAT_0080cc56 = *_DAT_0080cc62;
  _DAT_0080cc58 = *_DAT_0080cc66;
  if (_DAT_0080cc54 < _DAT_0080c992) {
    _DAT_0080cc4a = 6;
    _DAT_0080cc4e = _DAT_0080cc54;
  }
  else {
    _DAT_0080cc4e = _DAT_0080c992;
    _DAT_0080cc4a = 5;
  }
  if ((_DAT_0080cffc == 3) && (_DAT_0080d006 <= _DAT_0080cc4e)) {
    _DAT_0080cc4e = _DAT_0080d006;
    _DAT_0080cc4a = 9;
  }
  if (_DAT_008096ae <= _DAT_0080cc4e) {
    _DAT_0080cc4e = _DAT_008096ae;
    _DAT_0080cc4a = 4;
  }
  if (_DAT_008091c8 <= _DAT_0080cc4e) {
    _DAT_0080cc4e = _DAT_008091c8;
    _DAT_0080cc4a = 3;
  }
  if (_DAT_008096ac <= _DAT_0080cc4e) {
    _DAT_0080cc4e = _DAT_008096ac;
    _DAT_0080cc4a = 2;
  }
  if (_DAT_0080ccf6 <= _DAT_0080cc4e) {
    _DAT_0080cc4e = _DAT_0080ccf6;
    _DAT_0080cc4a = 1;
  }
  if (_DAT_0080cc52 <= _DAT_0080cc4e) {
    _DAT_0080cc4e = _DAT_0080cc52;
    _DAT_0080cc4a = 7;
  }
  if (_DAT_0080d17e <= _DAT_0080cc4e) {
    _DAT_0080cc4e = _DAT_0080d17e;
    _DAT_0080cc4a = 0xb;
  }
  if (_DAT_0080848c < _DAT_0080cc4e) {
    _DAT_0080cc4e = _DAT_0080848c;
  }
  if (_DAT_0080cc4a == 9) {
    if ((uint)_DAT_0080cc4e < (uint)_DAT_00806e1a + (uint)_DAT_0080d092) {
      _DAT_0080cc4e = _DAT_00806e1a + _DAT_0080d092;
    }
  }
  else if (_DAT_0080cc4e < _DAT_0080848a) {
    _DAT_0080cc4e = _DAT_0080848a;
  }
  if (_DAT_0080cc5a < _DAT_0080cc4e) {
    _DAT_0080cc5a = _DAT_00808480 + _DAT_0080cc5a;
  }
  if (_DAT_0080cc4e < _DAT_0080cc5a) {
    _DAT_0080cc5a = _DAT_0080cc4e;
  }
  if (((_DAT_0080cc58 != 0) && (_DAT_0080cc56 != 0)) &&
     ((_DAT_0080cc4a != 9 || (_DAT_0080d014 != 1)))) {
    _DAT_0080cc5c = 1;
    uVar2 = _DAT_00808486;
    if ((_DAT_00809652 <= _DAT_00808486) && (uVar2 = _DAT_00809652, _DAT_00809652 < _DAT_00808488))
    {
      uVar2 = _DAT_00808488;
    }
    uVar1 = ((uint)_DAT_0080cc58 * ((uint)_DAT_0080cc56 - (uint)uVar2)) / 0x1111;
    if ((int)(uVar1 & 0xffff) < (int)((uint)_DAT_0080cc54 - (uint)_DAT_0080cc5a)) {
      _DAT_0080cc50 = 0;
    }
    else {
      _DAT_0080cc50 = (short)uVar1 - (short)((uint)_DAT_0080cc54 - (uint)_DAT_0080cc5a);
    }
    if (_DAT_0080cc50 <= _DAT_0080cc5a) {
      _DAT_0080cc4c = _DAT_0080cc5a;
      return;
    }
    _DAT_0080cc4c = _DAT_0080cc50;
    return;
  }
  _DAT_0080cc4c = _DAT_0080cc5a;
  _DAT_0080cc5c = 0;
  return;
}



//
// Function: FUN_00018b6e @ 0x00018b6e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00018b6e(void)

{
  _DAT_0080cc5e = &DAT_0080369a;
  _DAT_0080cc66 = 0x8036d8;
  _DAT_0080cc62 = 0x8036da;
  _DAT_0080cc5a = _DAT_0080369a;
  _DAT_0080cc4a = 6;
  _DAT_0080cc4e = _DAT_008037b4;
  _DAT_0080cc52 = _DAT_008037b4;
  _DAT_008096ae = _DAT_008037b4;
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
// Function: FUN_00018c62 @ 0x00018c62
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_00018c62(void)

{
  ushort uVar1;
  
  uVar1 = _DAT_008035da & 2;
  if ((_DAT_008035da & 2) != 0) {
    uVar1 = FUN_00018bbe();
    if (_DAT_0080cc6c == 0) {
      _DAT_0080cc6e = _DAT_008036fc;
      _DAT_0080cc72 = 0;
      _DAT_0080cc6a = 0;
      _DAT_008003ec = _DAT_00809d4c;
      if (_DAT_00808494 == 0) {
        DAT_0080bdf1 = DAT_0080bdf1 | 1;
      }
      else {
        DAT_0080bdf1 = DAT_0080bdf1 & 0xfe;
      }
      if (((_DAT_0080d17a == 0) || (uVar1 = _DAT_008035d8 & 8, (_DAT_008035d8 & 8) != 0)) &&
         ((_DAT_008096a6 == 0 &&
          ((_DAT_0080c810 == 3 && (uVar1 = _DAT_0080926e, _DAT_00808490 < _DAT_0080926e)))))) {
        if (((_DAT_00805dfa & 0x100) == 0) || ((_DAT_008068cc & 0x100) == 0)) {
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
      if ((((_DAT_0080d17a != 0) && ((_DAT_008035d8 & 8) == 0)) || (_DAT_0080c810 != 3)) ||
         (((_DAT_0080926e <= _DAT_00808490 || (_DAT_008003e6 != 0)) ||
          ((_DAT_008003ea != 0 || (_DAT_008003ee != 0)))))) {
        _DAT_0080cc6c = 0;
      }
      uVar1 = _DAT_0080cc6e;
      if (_DAT_0080cc6e <= _DAT_00808496) {
        _DAT_0080cc6c = 2;
        _DAT_0080cc72 = 1;
        return _DAT_0080cc6e;
      }
    }
    else if (_DAT_0080cc6c == 2) {
      _DAT_0080cc6e = _DAT_0080cc6e - 1;
      uVar1 = _DAT_008035da & 4;
      if ((_DAT_008035da & 4) == 0) {
        if ((((_DAT_0080d17a != 0) && (uVar1 = _DAT_008035d8 & 8, (_DAT_008035d8 & 8) == 0)) ||
            (_DAT_008096a6 != 0)) ||
           (((_DAT_0080c810 != 3 || (_DAT_008003e6 != 0)) ||
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
        if (_DAT_00808494 != 0) {
          DAT_0080bdf1 = DAT_0080bdf1 | 1;
          return uVar1;
        }
        DAT_0080bdf1 = DAT_0080bdf1 & 0xfe;
        return uVar1;
      }
    }
    else if (_DAT_0080cc6c == 3) {
      if ((_DAT_008096a6 != 0) || (_DAT_0080c810 == 1)) {
        _DAT_0080cc6c = 0;
        return uVar1;
      }
    }
    else if ((_DAT_0080cc6c == 4) && (_DAT_0080c810 == 1)) {
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
  _DAT_0080d2b8 = 0x808b01;
  DAT_00808b00 = 0;
  DAT_0080d2c0 = 0;
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
// Function: FUN_00018f6c @ 0x00018f6c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00018f6c(void)

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
  
  uVar1 = _DAT_0080c9aa;
  if (_DAT_00809d4c != 0) {
    if (_DAT_0080c9aa != 0) {
      _DAT_008003f6 = current_engine_param;
      _DAT_008003fe = _DAT_00809d4c;
      FUN_000357f6((short *)&DAT_008003f0);
      unaff_D3w = extraout_D0w;
      if ((_DAT_00809d4c != 0) && (_DAT_00809d4c != 400)) {
        _DAT_008003fe = 0;
        FUN_000357f6((short *)&DAT_008003f0);
        _DAT_008003fe = 400;
        FUN_000357f6((short *)&DAT_008003f0);
        if (extraout_D0w < extraout_D0w_00) {
          unaff_D3w = extraout_D0w_00;
        }
        if (extraout_D0w_01 < unaff_D3w) {
          unaff_D3w = extraout_D0w_01;
        }
      }
    }
    if (uVar1 < 0x4000) {
      calibration_data[5] = current_engine_param;
      calibration_data[9] = _DAT_00809d4c;
      FUN_000357f6((short *)(calibration_data + 2));
      unaff_D2w = extraout_D0w_02;
      if ((_DAT_00809d4c != 0) && (_DAT_00809d4c != 400)) {
        calibration_data[9] = 0;
        FUN_000357f6((short *)(calibration_data + 2));
        calibration_data[9] = 400;
        FUN_000357f6((short *)(calibration_data + 2));
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
  return _DAT_0080849e;
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
  calibration_data[0] = 0x80;
  calibration_data[1] = 0x7f72;
  calibration_data[3] = 0x80;
  calibration_data[4] = 0x8002;
  calibration_data[2] = 2;
  calibration_data[7] = 0x80;
  calibration_data[8] = 0x8028;
  calibration_data[6] = 2;
  calibration_data[10] = 0x80;
  calibration_data[0xb] = 0x8032;
  _DAT_0080c9aa = 0x4000;
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
  
  pbVar1 = _DAT_0080d2b8;
  if ((_DAT_00fffc0c & 0x40) != 0) {
    DAT_0080d2da = 0;
    _DAT_00fff458 = _DAT_00fff458 & 0x8fff;
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
        if (bVar2 == *_DAT_0080d2b8) {
          _DAT_0080d2b8 = (byte *)CONCAT31(_DAT_0080d2b8,DAT_0080d2bb + '\x01');
          _DAT_00fffc0e = (ushort)*_DAT_0080d2b8;
          FUN_000192d0();
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
        _DAT_0080d2b8 = (byte *)CONCAT31(_DAT_0080d2b8,DAT_0080d2bb + '\x01');
        _DAT_00fffc0e = (ushort)*_DAT_0080d2b8;
        FUN_000192d0();
        DAT_0080d2d3 = *_DAT_0080d2b8 + DAT_0080d2d3;
        DAT_0080d2d1 = DAT_0080d2d1 + 1;
        if (DAT_0080d2d1 == *_DAT_0080d2bc) {
          _DAT_0080d2d6 = 2;
        }
        break;
      case 2:
        _DAT_00fffc0e = ~(ushort)DAT_0080d2d3 + 1 & 0xff;
        FUN_000192d0();
        _DAT_0080d2b8 = (byte *)CONCAT31(_DAT_0080d2b8,DAT_0080d2bb + '\x01');
        _DAT_0080d2d6 = 3;
        break;
      case 3:
        _DAT_0080d2bc = _DAT_0080d2b8;
        _DAT_0080d2b8 = (byte *)CONCAT31(_DAT_0080d2b8,DAT_0080d2bb + '\x01');
        DAT_0080d2d3 = 0;
        DAT_0080d2c0 = 0;
        if (((((_DAT_00805e00 & 4) != 0) && ((_DAT_008068d2 & 4) != 0)) &&
            ((_DAT_00805e00 & 4) != 0)) && ((_DAT_00805e40 & 4) == 0)) {
          _DAT_00805e00 = _DAT_00805e00 & 0xfffb;
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
  undefined1 *puVar4;
  
  if (DAT_0080cf89 == '\0') {
    iVar1 = (param_1 >> 0x10 & 0xff) * 0x10;
    do {
      (&DAT_00ffd801)[iVar1] = 0xfd;
      *_DAT_0080cf80 = *(uint *)(&DAT_00ffd802 + iVar1) >> 3;
      *(short *)(_DAT_0080cf80 + 1) = (short)((int)((byte)(&DAT_00ffd806)[iVar1] & 0xf0) >> 4);
      *(uint *)((int)_DAT_0080cf80 + 6) = (int)_DAT_0080cf80 + 10;
      uVar2 = 0;
      puVar3 = (undefined1 *)(iVar1 + 0xffd807);
      puVar4 = (undefined1 *)((int)_DAT_0080cf80 + 10);
      do {
        *puVar4 = *puVar3;
        uVar2 = uVar2 + 1;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      } while (uVar2 < 8);
    } while (((&DAT_00ffd801)[iVar1] & 2) != 0);
    _DAT_0080cf80 = (uint *)((int)_DAT_0080cf80 + 0x12);
    if ((uint *)0x80ce4e < _DAT_0080cf80) {
      _DAT_0080cf80 = (uint *)0x80ccf8;
    }
    if (_DAT_0080cf80 == _DAT_0080cf84) {
      DAT_0080cf89 = '\x01';
      puVar3 = &DAT_00ffd810 + (uint)_DAT_0080cfb6 * 0x10;
      uVar2 = _DAT_0080cfb6;
      while (uVar2 = uVar2 + 1, uVar2 <= _DAT_0080cfb8) {
        *puVar3 = 0xf7;
        *puVar3 = 0xfd;
        puVar3 = puVar3 + 0x10;
      }
    }
  }
  return;
}



//
// Function: FUN_00019738 @ 0x00019738
//

undefined8 FUN_00019738(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  calibration_data[0xc] = calibration_data[0xc] + 1;
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
  _DAT_0080d414 = _DAT_0080d2ca;
  _DAT_0080d410 = _DAT_0080d2b4;
  _DAT_0080d40c = _DAT_0080d2b4;
  DAT_0080d409 = 1;
  bVar1 = *_DAT_0080d2ca;
  if (bVar1 < 0x15) {
    DAT_0080d417 = (char)_DAT_0080d2ca;
    cVar6 = DAT_0080d417;
    _DAT_0080d414 = (undefined3)((uint)_DAT_0080d2ca >> 8);
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
          if (((bVar7 & *(byte *)(sVar3 + 0x8089be)) != 0) &&
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
            if (((bVar7 & *(byte *)(sVar3 + 0x8089be)) != 0) &&
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
  
  bVar1 = (DAT_0080d2bf - DAT_0080d2b7) - 2;
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
  DAT_0080d419 = (DAT_0080d2bf - DAT_0080d2b7) + -4;
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
  uint *puVar9;
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
  puVar9 = (uint *)&DAT_0080d0ce;
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
      DAT_0080d164 = 2;
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
      DAT_0080d164 = 4;
    }
    uVar1 = FUN_0002b544(local_e,(uint)CONCAT12(bVar6,uVar12));
    cVar3 = (char)uVar1;
    if ((cVar3 == '\n') || (cVar3 == '\x04')) {
      FUN_0000a626(CONCAT22(10,uVar12));
      return;
    }
    if (cVar3 == '\t') {
      FUN_0000a626(CONCAT22(9,uVar12));
      return;
    }
    *puVar9 = local_e;
    puVar9[1] = (uint)local_8;
    *(byte *)(puVar9 + 2) = bVar6;
    *(char *)((int)puVar9 + 9) = cVar3;
    puVar9 = (uint *)((int)puVar9 + 10);
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
  bVar9 = *_DAT_0080d2ca;
  local_8._3_1_ = (char)_DAT_0080d2ca;
  local_8._0_3_ = (undefined3)((uint)_DAT_0080d2ca >> 8);
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
  if ((_DAT_0080cc4e != _DAT_00800638) || (_DAT_0080d092 != _DAT_0080063a)) {
    DAT_0080d03a = '\x01';
    _DAT_00800638 = _DAT_0080cc4e;
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
  if (((_DAT_00805dfa & 0x20) == 0) || ((_DAT_008068cc & 0x20) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if (((_DAT_00805dfa & 8) == 0) || ((_DAT_008068cc & 8) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (((_DAT_00805dfa & 0x10) == 0) || ((_DAT_008068cc & 0x10) == 0)) {
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
  if (_DAT_0080c9a6 == 10) {
    bVar4 = bVar4 | 4;
  }
  if (((DAT_0080bdef & 1) == 0) || ((DAT_0080bdf1 & 1) == 0)) {
    bVar4 = bVar4 | 8;
  }
  if (_reference_table_array < _DAT_00809d4c) {
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
    sVar1 = _DAT_00807c3e * 2;
    uStack_d = (undefined1)sVar1;
    *local_8 = uStack_d;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\f');
    local_e = (undefined1)((ushort)sVar1 >> 8);
    *local_8 = local_e;
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\r');
    *local_8 = (char)((ushort)_DAT_0080bd92 >> 8);
    local_8 = (undefined1 *)CONCAT31(local_8._0_3_,cVar3 + '\x0e');
    sVar1 = _DAT_00807c40 * 2;
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
    sVar1 = _DAT_0080cc4c * 2;
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
  
  cVar1 = *_DAT_0080d2ca;
  local_8._3_1_ = (char)_DAT_0080d2ca;
  cVar5 = (char)local_8;
  local_8._0_3_ = (undefined3)((uint)_DAT_0080d2ca >> 8);
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
  if (_DAT_0080cffc == 0) {
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
    _DAT_0080cffc = 0;
    _DAT_0080cffa = 0;
    _DAT_0080d00c = 0;
    sVar6 = _DAT_008086e8 + 1;
    break;
  case 1:
    FUN_0001d34e(0x4a);
    _DAT_0080d028 = *(short *)(_DAT_0080d01e + 4) + 1;
    _DAT_0080cffc = 1;
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
    _DAT_0080cffc = 2;
    _DAT_0080cffa = 1;
    _DAT_0080d00c = 0;
    local_c = (ushort)(byte)local_c;
    _DAT_0080d008 = local_c << 8;
    _DAT_0080d010 =
         _DAT_0080bd8c +
         (short)(((int)(short)(_DAT_00807c38 - _DAT_0080bda0) * (int)_DAT_0080d008) / 0x6400);
    sVar6 = _DAT_0080d028;
    if (_DAT_0080d010 < 0) {
      _DAT_0080d010 = 0;
      sVar6 = _DAT_0080d028;
    }
    break;
  case 3:
    FUN_0001d34e(0x4a);
    _DAT_0080d028 = *(short *)(_DAT_0080d01e + 0xc) + 1;
    _DAT_0080cffc = 3;
    _DAT_0080cffa = 1;
    _DAT_0080d00c = 0;
    local_8 = (byte *)CONCAT31(local_8._0_3_,cVar5 + '\x03');
    local_a = (ushort)*local_8;
    _DAT_0080d006 = local_a << 7;
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
         (short)(((int)(short)(_DAT_00807c38 - _DAT_0080bda0) * (short)local_c * 8) / 0x6400);
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
  _DAT_0080d000 = (ushort)!bVar8;
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
  
  if (*_DAT_0080d2ca == '\x02') {
    local_8._3_1_ = (char)_DAT_0080d2ca;
    local_8 = (byte *)CONCAT31((int3)((uint)_DAT_0080d2ca >> 8),(char)local_8 + '\x02');
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
  
  cVar1 = *_DAT_0080d2ca;
  local_8._3_1_ = (char)_DAT_0080d2ca;
  cVar4 = (char)local_8;
  local_8._0_3_ = (undefined3)((uint)_DAT_0080d2ca >> 8);
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
      if (_DAT_0080cffc == 0) {
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
        _DAT_0080cffc = 0;
        _DAT_0080cffa = 0;
        _DAT_0080d00c = 0;
        iVar7 = 0;
        sVar5 = _DAT_008086e8 + 1;
        break;
      case 1:
        FUN_0001d34e(0x4f);
        _DAT_0080d028 = *(short *)(_DAT_0080d01e + 4) + 1;
        _DAT_0080cffc = 1;
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
        _DAT_0080cffc = 2;
        _DAT_0080cffa = 2;
        _DAT_0080d00c = 0;
        local_8 = (byte *)CONCAT31(local_8._0_3_,cVar4 + '\x03');
        local_c = (ushort)*local_8;
        _DAT_0080d008 = local_c << 8;
        iVar7 = ((int)(short)(_DAT_00807c38 - _DAT_0080bda0) * (int)_DAT_0080d008) / 0x6400;
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
        _DAT_0080cffc = 3;
        _DAT_0080cffa = 2;
        _DAT_0080d00c = 0;
        _DAT_0080d006 = _DAT_008037b4;
        local_8 = (byte *)CONCAT31(local_8._0_3_,cVar4 + '\x03');
        bVar2 = *local_8;
        if (bVar2 < 0x80) {
          local_c = (ushort)bVar2;
        }
        else {
          local_c = CONCAT11(0xff,bVar2);
        }
        iVar7 = ((int)(short)(_DAT_00807c38 - _DAT_0080bda0) * (short)local_c * 0x100) / 0x6400;
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
  
  if (*_DAT_0080d2ca == '\x02') {
    local_8._3_1_ = (char)_DAT_0080d2ca;
    local_8 = (byte *)CONCAT31((int3)((uint)_DAT_0080d2ca >> 8),(char)local_8 + '\x02');
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
    if (_DAT_0080969e == 1) {
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
  
  uVar1 = _DAT_008035d8 & 0x100;
  if (((_DAT_008035d8 & 0x100) != 0) &&
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
// Function: FUN_0001ae74 @ 0x0001ae74
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001ae74(undefined4 param_1)

{
  undefined4 in_D0;
  uint uVar1;
  
  uVar1 = CONCAT22((short)((uint)in_D0 >> 0x10),_DAT_008035d8) & 0xffff0080;
  if ((_DAT_008035d8 & 0x80) != 0) {
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
// Function: FUN_0001aef4 @ 0x0001aef4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001aef4(void)

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
// Function: FUN_0001af38 @ 0x0001af38
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
// Function: FUN_0001b172 @ 0x0001b172
//

void FUN_0001b172(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  uVar3 = 0xb07e;
  FUN_0002725a(1);
  uVar2 = 0xb07e;
  uVar1 = 0x10;
  FUN_0002725a(1,uVar3);
  FUN_0002725a(1,uVar1,uVar2);
  FUN_0002725a();
  return;
}



//
// Function: FUN_0001b1b4 @ 0x0001b1b4
// ERROR: Failed to decompile
//

//
// Function: FUN_0001b1f4 @ 0x0001b1f4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001b1f4(void)

{
  char cVar1;
  bool bVar2;
  ushort uVar3;
  undefined4 in_D0;
  uint uVar4;
  byte bVar5;
  char *pcVar6;
  short *psVar7;
  undefined1 *puVar8;
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
// Function: FUN_0001b314 @ 0x0001b314
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0001b314(void)

{
  ushort uVar1;
  
  uVar1 = _DAT_008035d8 & 0x1000;
  if (((((_DAT_008035d8 & 0x1000) != 0) && (_DAT_0080cfa8 == 2)) && (_DAT_0080cfaa == 1)) &&
     (((_DAT_0080cffc == 1 && (_DAT_0080cffa == 1)) &&
      (uVar1 = cached_parameter_value, _DAT_0080894c <= cached_parameter_value)))) {
    _DAT_0080cfb0 = 0;
    _DAT_0080cfb2 = 3;
    _DAT_0080cffe = 0;
    _DAT_0080d036 = 0;
    _DAT_0080d038 = 0;
  }
  return uVar1;
}



//
// Function: FUN_0001b37a @ 0x0001b37a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001b37a(int param_1,undefined1 *param_2,uint param_3)

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
  uVar3 = FUN_0001b7ca(CONCAT22((short)CONCAT31((int3)((uint)in_D0 >> 8),
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
  uVar4 = FUN_0002b544((uint)param_2,CONCAT22(sVar7,uVar9));
  uVar5 = uVar4 & 0xff;
  uVar3 = uVar5;
  if (uVar5 < 6) {
    uVar3 = (uint)(&switchD_0001b416::switchdataD_0001b41a)[uVar5];
    switch(uVar5) {
    case 0:
      uVar3 = FUN_0001f1e0(param_2,puVar1,CONCAT22(sVar7,uVar9));
      return uVar3 & 0xffffff00;
    case 3:
      if (_DAT_00803586 != 0xff) {
        if (!bVar2) {
          return 3;
        }
        cVar6 = FUN_00027e98();
        if (cVar6 != '\0') {
          return 3;
        }
      }
      uVar3 = FUN_0001f1e0(param_2,puVar1,CONCAT22(sVar7,uVar9));
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
        cVar6 = FUN_00027e98();
        if (cVar6 != '\0') {
          return 3;
        }
      }
      if (_DAT_0080d19c == 1) {
        cVar6 = FUN_000131d6((short)((uint)puVar1 >> 0x10),sVar7);
        if (cVar6 == '\x01') {
          return 0xb;
        }
      }
      uVar3 = FUN_0001f1e0(param_2 + -0x7fcb08,puVar1,CONCAT22(sVar7,uVar9));
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
  
  FUN_0001f1e0(local_6,(undefined1 *)(*(int *)(param_1 + 6) + 1),
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
  FUN_0001f1e0(puVar1,(undefined1 *)(*(int *)(param_1 + 6) + 1),
               CONCAT22(2,(short)((uint)unaff_A2 >> 0x10)));
  FUN_0001f1e0(local_a,(undefined1 *)(*(int *)(param_1 + 6) + 3),CONCAT22(4,(short)puVar1));
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
  
  FUN_0001f1e0(local_6,(undefined1 *)(*(int *)(param_1 + 6) + 1),
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
  FUN_0001f1e0(puVar2,(undefined1 *)(*(int *)(param_1 + 6) + 1),
               CONCAT22(2,(short)((uint)unaff_A2 >> 0x10)));
  puVar1 = local_a;
  FUN_0001f1e0(puVar1,(undefined1 *)(*(int *)(param_1 + 6) + 3),CONCAT22(4,(short)puVar2));
  FUN_0001f1e0(local_e,(undefined1 *)(*(int *)(param_1 + 6) + 7),CONCAT22(4,(short)puVar1));
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
  
  FUN_0001f1e0((undefined1 *)&local_8,(undefined1 *)(*(int *)(param_1 + 6) + 1),
               CONCAT22(4,(short)((uint)unaff_A2 >> 0x10)));
  local_c = (uint)*(byte *)(*(int *)(param_1 + 6) + 5);
  FUN_0001b37a(param_1,local_8,local_c);
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
  FUN_0001f1e0((undefined1 *)ppuVar1,(undefined1 *)(*(int *)(param_1 + 6) + 1),
               CONCAT22(4,(short)((uint)unaff_A2 >> 0x10)));
  FUN_0001f1e0((undefined1 *)&local_c,(undefined1 *)(*(int *)(param_1 + 6) + 5),
               CONCAT22(4,(short)ppuVar1));
  FUN_0001b37a(param_1,local_8,local_c);
  return;
}



//
// Function: FUN_0001b762 @ 0x0001b762
//

void FUN_0001b762(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  uVar3 = 0xb56e;
  FUN_0002725a(1);
  uVar2 = 0xb56e;
  uVar1 = 0x45;
  FUN_0002725a(1,uVar3);
  FUN_0002725a(1,uVar1,uVar2);
  FUN_0002725a();
  FUN_0002725a();
  FUN_0002725a();
  return;
}



//
// Function: FUN_0001b7ca @ 0x0001b7ca
//

uint FUN_0001b7ca(undefined4 param_1)

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
  cVar2 = FUN_00027e98();
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
    _DAT_00805540 = _DAT_0080cffc;
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
// Function: FUN_0001b9da @ 0x0001b9da
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001b9da(void)

{
  undefined2 uVar1;
  undefined4 in_D0;
  uint uVar2;
  undefined4 unaff_A2;
  undefined2 *puVar3;
  ushort uVar4;
  
  uVar4 = (ushort)((uint)unaff_A2 >> 0x10);
  uVar1 = (undefined2)((uint)in_D0 >> 0x10);
  uVar2 = CONCAT22(uVar1,_DAT_008035d8) & 0xffff0800;
  if ((_DAT_008035d8 & 0x800) != 0) {
    uVar2 = CONCAT22(uVar1,_DAT_0080cffc);
    if (((_DAT_0080cffc != _DAT_008007ac) ||
        (uVar2 = CONCAT22(uVar1,_DAT_0080d014), _DAT_0080d014 != _DAT_008007b0)) ||
       (uVar2 = CONCAT31((int3)(uVar2 >> 8),DAT_0080d018), DAT_0080d018 != DAT_008007b2)) {
      if (_DAT_0080cffc == 0) {
        if ((_DAT_008007ac != 0) && (_DAT_008007b0 == 1)) {
          _DAT_0080556c = 0;
          _DAT_0080554e = _DAT_0080d4c4 - _DAT_0080554a;
          uVar2 = FUN_0001b8b8((uint)uVar4);
        }
      }
      else if (_DAT_0080d014 == 1) {
        if (_DAT_0080556c == 1) {
          if (DAT_0080d018 == DAT_008007b2) {
            if (_DAT_0080553e < 5) {
              uVar2 = (uint)_DAT_0080553e;
              _DAT_0080553e = _DAT_0080553e + 1;
              *(short *)(&DAT_00805540 + uVar2 * 2) = _DAT_0080cffc;
            }
            else {
              uVar2 = 0;
              for (puVar3 = (undefined2 *)&DAT_00805540; puVar3 < &DAT_00805548; puVar3 = puVar3 + 1
                  ) {
                *puVar3 = puVar3[1];
              }
              _DAT_00805548 = _DAT_0080cffc;
            }
          }
          else {
            _DAT_0080554e = _DAT_0080d4c4 - _DAT_0080554a;
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
    _DAT_008007ac = _DAT_0080cffc;
    _DAT_008007b0 = _DAT_0080d014;
    DAT_008007b2 = DAT_0080d018;
    uVar2 = CONCAT22((short)(uVar2 >> 0x10),_DAT_0080cfa8);
    if ((_DAT_0080cfa8 != _DAT_008007ae) || (uVar2 = (uint)_DAT_0080cfac, uVar2 != DAT_008007b3)) {
      if (_DAT_0080cfa8 == 0) {
        if (_DAT_008007ae != 0) {
          _DAT_0080556e = 0;
          _DAT_00805568 = _DAT_0080d4c4 - _DAT_00805564;
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
          _DAT_00805568 = _DAT_0080d4c4 - _DAT_00805564;
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
    uVar3 = sendJ1939SingleFrame(local_12,(short)((uint)&local_1a >> 0x10));
    uVar3 = CONCAT31((int3)((uint)uVar3 >> 8),0xff);
  }
  else {
    uVar3 = 8;
  }
  return uVar3;
}



//
// Function: FUN_0001bd58 @ 0x0001bd58
//

void FUN_0001bd58(void)

{
  FUN_0002725a();
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
  undefined2 uVar8;
  byte *pbVar7;
  undefined4 unaff_D2;
  byte bVar9;
  undefined1 uVar10;
  ushort uVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined2 uVar14;
  
  uVar14 = (undefined2)((uint)unaff_D2 >> 0x10);
  cVar2 = **(char **)(param_1 + 6);
  if (0x6e4 < param_3) {
    return 2;
  }
  uVar5 = FUN_0001b7ca(CONCAT22((short)CONCAT31((int3)((uint)in_D0 >> 8),cVar2),uVar14));
  bVar9 = (byte)uVar5;
  if (bVar9 < 8) {
    bVar9 = 8;
  }
  if (((ushort)bVar9 != *(ushort *)(param_1 + 4)) &&
     ((ushort)(bVar9 + 10) != *(short *)(param_1 + 4))) {
    return 2;
  }
  uVar11 = (ushort)param_3;
  uVar6 = FUN_0002b544((uint)param_2,CONCAT22(uVar11,uVar14));
  uVar4 = (undefined3)((uint)uVar6 >> 8);
  if (((char)uVar6 == '\n') || ((char)uVar6 == '\t')) {
    return uVar6;
  }
  if ((cVar2 == 'C') && (uVar11 < 0x100)) {
    uVar10 = 0x44;
    *(undefined1 *)(*(int *)(param_1 + 6) + 3) = *(undefined1 *)(*(int *)(param_1 + 6) + 6);
  }
  else {
    uVar4 = 0;
    uVar10 = (&LAB_0001bd6c)[(short)(ushort)(byte)(cVar2 + 0xbd)];
  }
  uVar8 = (undefined2)CONCAT31(uVar4,uVar10);
  uVar5 = FUN_0001b7ca(CONCAT22(uVar8,uVar14));
  bVar9 = (char)uVar5 - 1;
  pbVar7 = (byte *)FUN_0001cb18(CONCAT22(uVar11 + bVar9 + 1,uVar8));
  if (pbVar7 == (byte *)0x0) {
    return 4;
  }
  pbVar7[0] = 0;
  pbVar7[1] = 0xef;
  pbVar7[2] = 0;
  pbVar7[3] = 0;
  bVar3 = *param_1;
  *pbVar7 = *pbVar7 & 0xe3;
  *pbVar7 = bVar3 & 0x1c | *pbVar7;
  pbVar7[2] = param_1[3];
  pbVar7[3] = param_1[2];
  iVar1 = *(int *)(param_1 + 6);
  puVar12 = *(undefined1 **)(pbVar7 + 6) + 1;
  **(undefined1 **)(pbVar7 + 6) = uVar10;
  puVar13 = puVar12;
  FUN_0001f1e0(puVar12,(undefined1 *)(iVar1 + 1),(uint)CONCAT12(bVar9,uVar14));
  if (register_map + 0xff < param_2) {
    param_2 = param_2 + -0x7fcb08;
  }
  FUN_0001f1e0(puVar12 + bVar9,param_2,CONCAT22(uVar11,(short)((uint)puVar13 >> 0x10)));
  uVar6 = sendJ1939Msg((undefined4 *)pbVar7);
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
  FUN_0001f1e0(puVar1,(undefined1 *)(*(int *)(param_1 + 6) + 1),
               CONCAT22(2,(short)((uint)unaff_A2 >> 0x10)));
  FUN_0001f1e0(local_a,(undefined1 *)(*(int *)(param_1 + 6) + 3),CONCAT22(4,(short)puVar1));
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
  
  FUN_0001f1e0(local_6,(undefined1 *)(*(int *)(param_1 + 6) + 1),
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
  FUN_0001f1e0(puVar2,(undefined1 *)(*(int *)(param_1 + 6) + 1),
               CONCAT22(2,(short)((uint)unaff_A2 >> 0x10)));
  puVar1 = local_a;
  FUN_0001f1e0(puVar1,(undefined1 *)(*(int *)(param_1 + 6) + 3),CONCAT22(4,(short)puVar2));
  FUN_0001f1e0(local_e,(undefined1 *)(*(int *)(param_1 + 6) + 7),CONCAT22(4,(short)puVar1));
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
  
  FUN_0001f1e0((undefined1 *)&local_8,(undefined1 *)(*(int *)(param_1 + 6) + 1),
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
  FUN_0001f1e0((undefined1 *)ppuVar1,(undefined1 *)(*(int *)(param_1 + 6) + 1),
               CONCAT22(4,(short)((uint)unaff_A2 >> 0x10)));
  FUN_0001f1e0((undefined1 *)&local_c,(undefined1 *)(*(int *)(param_1 + 6) + 5),
               CONCAT22(4,(short)ppuVar1));
  FUN_0001bd76(param_1,local_8,local_c);
  return;
}



//
// Function: FUN_0001c0c2 @ 0x0001c0c2
//

void FUN_0001c0c2(void)

{
  FUN_0002725a();
  FUN_0002725a();
  FUN_0002725a();
  FUN_0002725a();
  FUN_0002725a();
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
  undefined1 *puVar5;
  char *pcVar6;
  undefined1 local_8;
  undefined1 uStack_7;
  char cStack_5;
  
  puVar1 = _DAT_00800f4e;
  bVar3 = *(byte *)((int)param_1 + 1);
  uVar4 = *(ushort *)((int)param_1 + 1);
  cStack_5 = (char)uVar4;
  if ((bVar3 < 0xf0) && (cStack_5 != -1)) {
    if (diagnostic_message_state == 0) {
      diagnostic_message_state = 1;
      DAT_00800f35 = cStack_5;
      _DAT_00800f36 = uVar4 & 0xff00;
      _DAT_00800f3c = *(ushort *)(param_1 + 1);
      DAT_00800f38 = (char)((int)(_DAT_00800f3c - 1) / 7) + '\x01';
      DAT_00800f3a = 0;
      _DAT_00800f3e = *(undefined4 *)((int)param_1 + 6);
      _DAT_00800f48 = *param_1 & 0xff00ffff | 0xec0000;
      _DAT_00800f4c = 8;
      _DAT_00800f46 = 0x37;
      _diagnostic_response_buffer = *(char **)((int)param_1 + 10);
      puVar5 = _DAT_00800f4e + 1;
      *_DAT_00800f4e = 0x10;
      uVar4 = _DAT_00800f3c;
      uStack_7 = (undefined1)_DAT_00800f3c;
      *puVar5 = uStack_7;
      local_8 = (undefined1)(uVar4 >> 8);
      puVar1[2] = local_8;
      puVar1[3] = DAT_00800f38;
      puVar1[4] = 0xff;
      puVar1[5] = 0;
      puVar1[6] = bVar3;
      puVar1[7] = 0;
      sendJ1939SingleFrame(_DAT_00800f48);
      if (DAT_00800f3b == '\0') {
        *_diagnostic_response_buffer = '\x12';
        _DAT_00800f48 = *param_1 & 0xff00ffff | 0xeb0000;
      }
      else {
        *_diagnostic_response_buffer = DAT_00800f3b;
        diagnostic_message_state = 0;
      }
    }
    else {
      **(undefined1 **)((int)param_1 + 10) = 8;
    }
  }
  else {
    if ((byte)*param_1 == _DAT_0080cfc2) {
      pcVar6 = &DAT_00800ee4;
    }
    else {
      if ((byte)*param_1 != _DAT_0080cfcc) {
        **(undefined1 **)((int)param_1 + 10) = 3;
        return;
      }
      pcVar6 = &DAT_00800f04;
    }
    if (*pcVar6 == '\x01') {
      **(undefined1 **)((int)param_1 + 10) = 2;
    }
    else {
      *pcVar6 = '\x01';
      *(undefined2 *)(pcVar6 + 2) = *(undefined2 *)(param_1 + 1);
      pcVar6[1] = (char)((int)(*(ushort *)(pcVar6 + 2) - 1) / 7) + '\x01';
      pcVar6[6] = '\x01';
      pcVar6[4] = '\0';
      pcVar6[5] = '\x01';
      *(undefined4 *)(pcVar6 + 8) = *(undefined4 *)((int)param_1 + 6);
      *(uint *)(pcVar6 + 0x12) = *param_1 & 0xff0000ff | 0xecff00;
      pcVar6[0x16] = '\0';
      pcVar6[0x17] = '\b';
      pcVar6[0x10] = '\0';
      pcVar6[0x11] = '\x05';
      *(undefined4 *)(pcVar6 + 0xc) = *(undefined4 *)((int)param_1 + 10);
      puVar1 = *(undefined1 **)(pcVar6 + 0x18);
      *puVar1 = 0x20;
      uVar2 = *(undefined2 *)(pcVar6 + 2);
      uStack_7 = (undefined1)uVar2;
      puVar1[1] = uStack_7;
      local_8 = (undefined1)((ushort)uVar2 >> 8);
      puVar1[2] = local_8;
      puVar1[3] = pcVar6[1];
      puVar1[4] = 0xff;
      puVar1[5] = cStack_5;
      puVar1[6] = bVar3;
      puVar1[7] = 0;
      sendJ1939SingleFrame(*(undefined4 *)(pcVar6 + 0x12));
      if (pcVar6[7] == '\0') {
        **(char **)(pcVar6 + 0xc) = '\x10';
        *(uint *)(pcVar6 + 0x12) = *param_1 & 0xff0000ff | 0xebff00;
      }
      else {
        **(char **)(pcVar6 + 0xc) = pcVar6[7];
        *pcVar6 = '\0';
      }
    }
  }
  return;
}



//
// Function: diagnosticParamRequestHandler @ 0x0001c33e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticParamRequestHandler(int param_1)

{
  byte bVar1;
  byte bVar2;
  short local_6;
  
  bVar1 = *(byte *)(*(int *)(param_1 + 6) + 2);
  local_6 = (ushort)*(byte *)(*(int *)(param_1 + 6) + 6) << 8;
  if ((((diagnostic_message_state == 1) && (*(char *)(param_1 + 3) == DAT_00800f35)) &&
      (bVar1 <= DAT_00800f38)) && (local_6 == _DAT_00800f36)) {
    bVar2 = *(byte *)(*(int *)(param_1 + 6) + 1);
    if (bVar2 == 0) {
      _DAT_00800f46 = 0x37;
    }
    else {
      DAT_00800f39 = bVar1;
      DAT_00800f3a = bVar2;
      if ((int)(uint)DAT_00800f38 < (int)((uint)bVar2 + (uint)bVar1 + -1)) {
        DAT_00800f3a = (DAT_00800f38 - bVar1) + 1;
      }
    }
  }
  return;
}



//
// Function: FUN_0001c3d2 @ 0x0001c3d2
//

void FUN_0001c3d2(undefined4 param_1)

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
  sendJ1939SingleFrame(local_12);
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
  undefined1 uStack_19;
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
  uStack_1f = (undefined1)_DAT_00800f6a;
  uStack_1b = uStack_1f;
  local_20 = (undefined1)((ushort)_DAT_00800f6a >> 8);
  uStack_1a = local_20;
  uStack_19 = DAT_00800f5f;
  uStack_18 = 0xff;
  uStack_17 = 0;
  local_1e = (undefined1)((uint)param_1 >> 8);
  uStack_16 = local_1e;
  local_15 = 0;
  sendJ1939SingleFrame(local_12);
  return;
}



//
// Function: FUN_0001c4c0 @ 0x0001c4c0
//

undefined1 FUN_0001c4c0(undefined4 param_1,undefined2 param_2)

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
  sendJ1939SingleFrame(local_12);
  return local_13;
}



//
// Function: vp44FuelTempHandler @ 0x0001c538
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vp44FuelTempHandler(undefined4 *param_1)

{
  int iVar1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  undefined1 extraout_var;
  undefined2 in_D0w;
  char cVar5;
  undefined2 local_8;
  short local_6;
  
  iVar1 = *(int *)((int)param_1 + 6);
  bVar2 = *(byte *)(iVar1 + 6);
  local_6 = (ushort)bVar2 << 8;
  cVar3 = *(char *)((int)param_1 + 3);
  local_8 = CONCAT11(*(undefined1 *)(iVar1 + 2),*(undefined1 *)(iVar1 + 1));
  uVar4 = (undefined1)((ushort)in_D0w >> 8);
  if ((((DAT_00800f5e == '\x01') && (cVar3 != DAT_00800f69)) || (bVar2 != 0xef)) ||
     (0x6a4 < local_8)) {
    FUN_0001c3d2((uint)CONCAT21(CONCAT11(uVar4,cVar3),bVar2) << 8);
  }
  else {
    DAT_00800f5e = '\x01';
    _DAT_00800f66 = *param_1;
    _DAT_00800f60 = local_6;
    DAT_00800f5f = *(byte *)(iVar1 + 3);
    _DAT_00800f6a = local_8;
                    /* Constant: VP44_FUEL_TEMP_OFFSET = 112 */
    _DAT_00800f64 = 0x70;
    DAT_00800f62 = 1;
    DAT_00800f63 = DAT_00800f5f;
    if (5 < DAT_00800f5f) {
      DAT_00800f63 = 5;
    }
    cVar5 = FUN_0001c4c0(CONCAT22(CONCAT11(uVar4,cVar3),CONCAT11(uVar4,1)),0xef00);
    if (cVar5 != '\0') {
      FUN_0001c3d2(CONCAT22(CONCAT11(extraout_var,cVar3),_DAT_00800f60));
      DAT_00800f5e = '\0';
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
  char cVar2;
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
  
  if (((*(short *)(param_1 + 4) == 8) && (cVar2 = *(char *)(param_1 + 3), DAT_00800f5e == '\x01'))
     && (cVar2 == DAT_00800f69)) {
    bVar1 = **(byte **)(param_1 + 6);
    if (bVar1 == DAT_00800f62) {
      if (bVar1 == DAT_00800f5f) {
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
      DAT_00800f62 = DAT_00800f62 + 1;
      DAT_00800f63 = DAT_00800f63 + -1;
      if (DAT_00800f63 == '\0') {
        if (bVar1 == DAT_00800f5f) {
          FUN_0001c440(CONCAT22((short)CONCAT31((int3)((uint)puVar3 >> 8),cVar2),_DAT_00800f60));
          DAT_00800f5e = 0;
          _DAT_00800f6c = 0x800f78;
          FUN_0002729a(&DAT_00800f66);
          return;
        }
        iVar5 = ((uint)DAT_00800f5f - (uint)DAT_00800f62) + 1;
        if (iVar5 < 6) {
          DAT_00800f63 = (DAT_00800f5f - DAT_00800f62) + '\x01';
          iVar5 = CONCAT31((int3)((uint)iVar5 >> 8),DAT_00800f63);
        }
        else {
          DAT_00800f63 = '\x05';
        }
        uVar4 = (undefined3)((uint)iVar5 >> 8);
        cVar6 = FUN_0001c4c0(CONCAT22((short)CONCAT31(uVar4,cVar2),
                                      (short)CONCAT31(uVar4,DAT_00800f62)),_DAT_00800f60);
        if (cVar6 != '\0') {
          FUN_0001c3d2(CONCAT22((short)CONCAT31(extraout_var_00,cVar2),_DAT_00800f60));
          DAT_00800f5e = 0;
          return;
        }
      }
      else {
        _DAT_00800f64 = 0x19;
      }
    }
    else {
      uVar4 = (undefined3)((uint)in_D0 >> 8);
      cVar6 = FUN_0001c4c0(CONCAT22((short)CONCAT31(uVar4,cVar2),(short)CONCAT31(uVar4,DAT_00800f62)
                                   ),_DAT_00800f60);
      if (cVar6 != '\0') {
        FUN_0001c3d2(CONCAT22((short)CONCAT31(extraout_var,cVar2),_DAT_00800f60));
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticStatusRequestHandler(int param_1)

{
  undefined2 local_6;
  
  if ((diagnostic_message_state == 1) && (DAT_00800f35 == *(char *)(param_1 + 3))) {
    local_6 = (ushort)*(byte *)(*(int *)(param_1 + 6) + 6) << 8;
    if (local_6 == _DAT_00800f36) {
      *_diagnostic_response_buffer = 9;
      diagnostic_message_state = 0;
    }
  }
  return;
}



//
// Function: diagnosticErrorHandler @ 0x0001c7ca
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diagnosticErrorHandler(int param_1)

{
  undefined2 local_6;
  
  local_6 = (ushort)*(byte *)(*(int *)(param_1 + 6) + 6) << 8;
  if (((diagnostic_message_state == 1) && (*(char *)(param_1 + 3) == DAT_00800f35)) &&
     (local_6 == _DAT_00800f36)) {
    *_diagnostic_response_buffer = 10;
    diagnostic_message_state = 0;
  }
  else if (((DAT_00800f5e == '\x01') && (*(char *)(param_1 + 3) == DAT_00800f69)) &&
          (local_6 == _DAT_00800f60)) {
    DAT_00800f5e = '\0';
  }
  return;
}



//
// Function: canMessageDispatcher @ 0x0001c846
//

void canMessageDispatcher(int param_1)

{
  char cVar1;
  
  if (*(short *)(param_1 + 4) == 8) {
    cVar1 = **(char **)(param_1 + 6);
                    /* Constant: CAN_MSG_ALT_HANDLER = 17 */
    if (cVar1 == '\x11') {
      diagnosticParamRequestHandler(param_1);
      return;
    }
    if (cVar1 == '\x10') {
      vp44FuelTempHandler((undefined4 *)param_1);
      return;
    }
    if (cVar1 == '\x13') {
      diagnosticStatusRequestHandler(param_1);
      return;
    }
                    /* Constant: CAN_MSG_ERROR_DEFAULT = 255 */
    if (cVar1 != -1) {
      return;
    }
    diagnosticErrorHandler(param_1);
  }
  return;
}



//
// Function: FUN_0001c87e @ 0x0001c87e
//

void FUN_0001c87e(void)

{
  int unaff_A2;
  
  diagnosticParamRequestHandler(unaff_A2);
  return;
}



//
// Function: canMessageDispatcher @ 0x0001c88c
//

void canMessageDispatcher(void)

{
  undefined4 *unaff_A2;
  
  vp44FuelTempHandler(unaff_A2);
  return;
}



//
// Function: FUN_0001c89a @ 0x0001c89a
//

void FUN_0001c89a(void)

{
  int unaff_A2;
  
  diagnosticStatusRequestHandler(unaff_A2);
  return;
}



//
// Function: FUN_0001c8a8 @ 0x0001c8a8
//

void FUN_0001c8a8(void)

{
  int unaff_A2;
  
  diagnosticErrorHandler(unaff_A2);
  return;
}



//
// Function: FUN_0001c8b6 @ 0x0001c8b6
//

void FUN_0001c8b6(uint param_1)

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
  sendJ1939SingleFrame(*(undefined4 *)(&DAT_00800ef6 + iVar3));
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
// Function: FUN_0001c996 @ 0x0001c996
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001c996(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  byte bVar6;
  byte *pbVar7;
  byte *pbVar8;
  
  bVar6 = DAT_00800f3a;
  bVar3 = DAT_00800f39;
  if (DAT_00800f3a == 0) {
    if (_DAT_00800f46 == 0) {
      *_diagnostic_response_buffer = 6;
      diagnostic_message_state = 0;
      return;
    }
    _DAT_00800f46 = _DAT_00800f46 + -1;
    return;
  }
  if (DAT_00800f3a < 0xb) {
    DAT_00800f3a = '\0';
    _DAT_00800f46 = 0x70;
  }
  else {
    bVar6 = 10;
    DAT_00800f39 = DAT_00800f39 + 10;
    DAT_00800f3a = DAT_00800f3a - 10;
  }
  pbVar8 = (byte *)(_DAT_00800f3e + (uint)bVar3 * 7 + -7);
  bVar5 = 0;
  cVar4 = bVar3 * '\a' + -7;
  while( true ) {
    pbVar7 = _DAT_00800f4e;
    if (bVar6 <= bVar5) {
      return;
    }
    if (bVar3 == DAT_00800f38) {
      bVar2 = (DAT_00800f3d - cVar4) + 1;
      _DAT_00800f4c = (ushort)bVar2;
    }
    else {
      bVar2 = 8;
    }
    cVar4 = cVar4 + '\a';
    *_DAT_00800f4e = bVar3;
    for (bVar1 = 0; pbVar7 = pbVar7 + 1, (int)(uint)bVar1 < (int)(bVar2 - 1); bVar1 = bVar1 + 1) {
      *pbVar7 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    }
    sendJ1939SingleFrame(_DAT_00800f48);
    if (DAT_00800f3b != '\0') break;
    *_diagnostic_response_buffer = 0x13;
    bVar5 = bVar5 + 1;
    bVar3 = bVar3 + 1;
  }
  *_diagnostic_response_buffer = 7;
  diagnostic_message_state = 0;
  return;
}



//
// Function: FUN_0001cabe @ 0x0001cabe
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001cabe(void)

{
  if (_DAT_00800f64 == 0) {
    DAT_00800f5e = 0;
    return;
  }
  _DAT_00800f64 = _DAT_00800f64 + -1;
  return;
}



//
// Function: FUN_0001cad6 @ 0x0001cad6
//

void FUN_0001cad6(void)

{
  ushort in_stack_00000000;
  
  if (DAT_00800ee4 == '\x01') {
    FUN_0001c8b6((uint)in_stack_00000000);
  }
  if (DAT_00800f04 == '\x01') {
    FUN_0001c8b6(CONCAT22(1,in_stack_00000000));
  }
  if (diagnostic_message_state == 1) {
    FUN_0001c996();
  }
  if (DAT_00800f5e == '\x01') {
    FUN_0001cabe();
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
  _DAT_00800f4e = 0x800f56;
  _DAT_00800f6c = 0x800f78;
  FUN_0001b1b4();
  FUN_0001b1b4();
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
  
  uVar1 = _DAT_0080cffc;
  _DAT_0080161c = _DAT_0080cffc;
  _DAT_0080cffc = 0;
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
  _DAT_0080cfb2 = 3;
  _DAT_0080cffe = 0;
  _DAT_0080d02c = 0;
  _DAT_0080d02a = 0;
  _DAT_0080d036 = 0;
  _DAT_0080d038 = 0;
  return;
}



//
// Function: FUN_0001cc38 @ 0x0001cc38
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001cc38(void)

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
  if ((_DAT_00801622 != _DAT_0080d000) && (_DAT_0080d000 == 1)) {
    _DAT_0080d030 = _DAT_008086e6 + 1;
    bVar1 = true;
  }
  if (_DAT_0080d02e != 0) {
    _DAT_0080d02e = _DAT_0080d02e + -1;
    bVar1 = true;
  }
  bVar9 = _DAT_0080d02e == 1;
  if (bVar9) {
    _DAT_0080d000 = 0;
    _DAT_0080d03c = 0;
    _DAT_0080d02e = 0;
    _DAT_0080d030 = 0;
  }
  if (_DAT_0080d030 != 0) {
    _DAT_0080d030 = _DAT_0080d030 + -1;
  }
  if (_DAT_0080d030 == 1) {
    _DAT_0080d000 = 0;
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
  uVar4 = _DAT_0080cffc >> 0xf;
  if (((_DAT_0080cffc == _DAT_0080161c) && (_DAT_0080d014 == _DAT_0080161e)) &&
     (DAT_0080d018 == DAT_00801620)) {
    if (_DAT_0080d028 != 0) {
      _DAT_0080d028 = _DAT_0080d028 + -1;
    }
    if (_DAT_0080d026 != 0) {
      _DAT_0080d026 = _DAT_0080d026 + -1;
    }
    uVar7 = (uint)_DAT_0080cffc;
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
    uVar7 = (uint)_DAT_0080cffc;
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
  _DAT_0080161c = _DAT_0080cffc;
  _DAT_0080161e = _DAT_0080d014;
  DAT_00801620 = DAT_0080d018;
  _DAT_00801622 = _DAT_0080d000;
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
// Function: FUN_0001d4bc @ 0x0001d4bc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001d4bc(void)

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
  DAT_0080bdee = DAT_0080bdee & 0xfe;
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
  if (((DAT_0080bdc7 & 0x80) != 0) && (_DAT_0080c810 == 1)) {
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
  if (((99 < _DAT_008016a0) && (_DAT_008016a0 < 400)) && (_DAT_0080d04e != 0)) {
    FUN_0001dfc2();
  }
  if ((_DAT_0080d050 != 0) || (DAT_0080169a != '\0')) {
    FUN_0001e050();
  }
  if (((_DAT_0080373c != 0) && (_DAT_0080d04e != 0)) && (_DAT_0080c810 == 3)) {
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
    _DAT_0080d056 = FUN_000356f8();
    uVar1 = ((uint)_DAT_0080878a * (uint)_DAT_0080d056) / 0x7800;
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
    cached_parameter_value = _DAT_0080d052;
  }
  _DAT_008016b8 = _DAT_00809d50;
  return;
}



//
// Function: FUN_0001e2d2 @ 0x0001e2d2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001e2d2(undefined4 param_1)

{
  if ((((_DAT_00808794 != 0) && (diagnostic_status_register == 0)) &&
      ((((_DAT_00805dfa & 2) != 0 && ((_DAT_008068cc & 2) != 0)) ||
       (((_DAT_00805dfa & 4) != 0 && ((_DAT_008068cc & 4) != 0)))))) &&
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
  _DAT_0080d052 = _DAT_0080c9a4;
  _DAT_008016b4 = (uint)_DAT_0080c406 << 0x10;
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
  _DAT_008016c0 = current_engine_param;
  _DAT_0080d058 = FUN_00035560((short *)&DAT_008016ba);
  _DAT_008016cc = current_engine_param;
  _DAT_0080d05a = FUN_00035560((short *)&DAT_008016c6);
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
    uVar1 = FUN_000357f6((short *)&DAT_008016e8);
    unaff_D3w = (ushort)((ulonglong)uVar1 >> 0x20);
  }
  if (_DAT_0080965a < 0x4000) {
    _DAT_00801702 = _DAT_0080d06c;
    uVar1 = FUN_000357f6((short *)&DAT_008016fc);
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
  short sVar2;
  short sVar4;
  int iVar3;
  undefined4 local_8;
  
  if (_DAT_0080cffc == 0) {
    _DAT_0080d092 = _DAT_0080d096;
  }
  else {
    _DAT_0080d092 = _DAT_00808836;
  }
  sVar4 = FUN_000356f8();
  sVar2 = _DAT_0080d05e;
  _DAT_0080d06c = _DAT_0080d092 + sVar4;
  if (_DAT_008087e0 < _DAT_0080d06c) {
    _DAT_0080d06c = _DAT_008087e0;
  }
  _DAT_0080d06c = _DAT_0080d06c - _DAT_008087e8;
  if ((param_system_mode == 0xb) || (current_engine_param < _DAT_0080d096)) {
    _DAT_0080d05e = FUN_00035608();
    sVar4 = _DAT_0080d078;
    if (_DAT_008087cc < _DAT_0080d05e) {
      _DAT_0080d05e = _DAT_008087cc;
      _DAT_008016d6 = _DAT_008087cc * 0x10000 + -0x80000000;
    }
    else if (_DAT_0080d05e < _DAT_008087ce) {
      _DAT_0080d05e = _DAT_008087ce;
      _DAT_008016d6 = _DAT_008087ce * 0x10000 + -0x80000000;
    }
    FUN_0001eb2a();
    if (((int)((int)_DAT_008087d6 + (uint)_DAT_0080d092) < (int)(uint)current_engine_param) &&
       (_DAT_00809652 < _DAT_008087d8)) {
      _DAT_008016e2 = (uint)_DAT_008087d4 << 0x10;
      _DAT_0080d05e = 0;
      _DAT_008016d6 = -0x80000000;
    }
    else {
      _DAT_0080d060 = (short)(((int)_DAT_0080d05e * (int)_DAT_0080d078) / 0x3c0);
      iVar3 = (int)_DAT_0080d07c * ((int)_DAT_0080d05e - (int)sVar2);
      if (iVar3 < 0x783f0f) {
        if (iVar3 < -0x783fff) {
          _DAT_0080d062 = -0x8000;
        }
        else {
          _DAT_0080d062 = (short)((((int)_DAT_0080d05e - (int)sVar2) * (int)_DAT_0080d07c) / 0xf0);
        }
      }
      else {
        _DAT_0080d062 = 0x7fff;
      }
      FUN_0001e3dc();
      _DAT_0080d066 = _DAT_008016e6 + _DAT_008087c0;
      if ((short)_DAT_0080d066 < 0) {
        _DAT_0080d066 = 0;
      }
      _DAT_0080d068 = _DAT_008016e6 + _DAT_008087d0;
      local_8._2_2_ = (ushort)(((int)_DAT_0080d078 - (int)sVar4) * 0x44 >> 3);
      iVar3 = _DAT_008016e2 + (int)_DAT_0080d05e * (int)(short)(_DAT_0080d07a << 2) +
              (int)_DAT_0080d05e * (int)(short)local_8._2_2_ * -8 + _DAT_0080c9c4 * -0x10000;
      _DAT_008016e2 = (short)((uint)iVar3 >> 0x10);
      if (_DAT_008016e2 < (short)_DAT_0080d068) {
        bVar1 = _DAT_008016e2 < (short)_DAT_008087d2;
        _DAT_008016e2 = iVar3;
        if (bVar1) {
          _DAT_008016e2 = (uint)_DAT_008087d2 << 0x10;
        }
      }
      else {
        _DAT_008016e2 = (uint)_DAT_0080d068 << 0x10;
      }
      _DAT_0080d064 = _DAT_008016e2;
      local_8 = (int)_DAT_008016e2 + (int)_DAT_0080d062 + (int)_DAT_0080d060;
      if ((_DAT_00803614 & 0x200) != 0) {
        local_8 = (uint)fsmxthfl_calc_input + local_8;
      }
      if ((int)(uint)_DAT_0080d066 < local_8) {
        _DAT_0080d05c = _DAT_0080d066;
      }
      else if (local_8 < (int)(uint)_DAT_008087c2) {
        _DAT_0080d05c = _DAT_008087c2;
      }
      else {
        _DAT_0080d05c = local_8._2_2_;
      }
      if (param_system_mode == 0xb) {
        _DAT_00809652 = _DAT_0080d05c;
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
  short sVar1;
  undefined1 *puVar2;
  short sStack_6;
  
  puVar2 = (undefined1 *)((uint)_DAT_008087e4 * (uint)_DAT_00809d4c);
  if (&LAB_00009c3e_2 < puVar2) {
    puVar2 = &LAB_00009c3e_2;
  }
  _DAT_008016de = (int)puVar2 << 0x10;
  sStack_6 = (short)((int)_DAT_008087ca * ((int)_DAT_0080d06c - (int)(short)current_engine_param) >>
                    9);
  if (_DAT_008087cc < sStack_6) {
    sStack_6 = _DAT_008087cc;
  }
  else if (sStack_6 < _DAT_008087ce) {
    sStack_6 = _DAT_008087ce;
  }
  _DAT_008016d6 = sStack_6 * 0x10000 + -0x80000000;
  _DAT_0080d05e = sStack_6;
  FUN_0001eb86();
  FUN_0001e3dc();
  _DAT_0080d06a = _DAT_008016e6 + _DAT_008087c4;
  _DAT_008016e2 = _DAT_0080c9a4 - (short)(((int)_DAT_0080d05e * (int)_DAT_00808804) / 0x3c0);
  if ((_DAT_00803614 & 0x200) != 0) {
    _DAT_008016e2 = _DAT_008016e2 - fsmxthfl_calc_input;
  }
  sVar1 = _DAT_0080d06a;
  if ((_DAT_008016e2 <= _DAT_0080d06a) && (sVar1 = _DAT_008016e2, _DAT_008016e2 < _DAT_008087c6)) {
    _DAT_008016e2 = _DAT_008087c6;
    sVar1 = _DAT_008016e2;
  }
  _DAT_008016e2 = sVar1;
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
// Function: FUN_0001e92e @ 0x0001e92e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001e92e(void)

{
  undefined2 uVar1;
  uint uVar2;
  short sVar3;
  
  sVar3 = _DAT_0080d05e;
  if (_DAT_0080d05e < 0) {
    sVar3 = -_DAT_0080d05e;
  }
  uVar2 = (uint)sVar3;
  if ((int)(uint)_DAT_008087f0 < (int)uVar2) {
    _DAT_00801714 = 0;
    _DAT_00801716 = 0;
  }
  else {
    if (_DAT_00801714 < _DAT_008087ec) {
      _DAT_00801714 = _DAT_00801714 + 1;
    }
    uVar2 = CONCAT22(sVar3 >> 0xf,_DAT_008096a6);
    if (_DAT_008096a6 < _DAT_008087f4) {
      uVar2 = CONCAT22(sVar3 >> 0xf,_DAT_00801716);
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
    if (((int)(uint)current_engine_param <= (int)uVar2) ||
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
         ((uVar2 = CONCAT22(uVar1,_DAT_0080d05e), _DAT_008087f8 < _DAT_0080d05e ||
          ((uVar2 = CONCAT22(uVar1,_DAT_0080d05e), _DAT_008087f6 < _DAT_0080d05e &&
           (uVar2 = (int)_DAT_008087ee + (uint)current_engine_param,
           (int)uVar2 < (int)(uint)_DAT_00801712)))))) {
        _DAT_0080d07e = 1;
      }
    }
    else if ((_DAT_0080d07e == 1) &&
            ((uVar2 = (int)_DAT_008087f6 - (int)_DAT_008087fc, (int)_DAT_0080d05e < (int)uVar2 ||
             ((uVar2 = CONCAT22((short)(uVar2 >> 0x10),_DAT_0080d05e), _DAT_0080d05e < _DAT_008087f8
              && (uVar2 = (int)_DAT_008087ee + (uint)_DAT_00801712,
                 (int)uVar2 < (int)(uint)current_engine_param)))))) {
      _DAT_0080d07e = 0;
    }
  }
  if (_DAT_0080d07e == 1) {
    _DAT_00801710 = 1;
    _DAT_0080d08a = 0x8087fe;
  }
  _DAT_00801712 = current_engine_param;
  return uVar2;
}



//
// Function: FUN_0001eade @ 0x0001eade
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001eade(void)

{
  _DAT_00801712 = current_engine_param;
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
  
  if ((param_system_mode == 0xb) && (_DAT_0080d076 == 1)) {
    if ((_DAT_0080880e < _DAT_0080d05e) || ((_DAT_0080d05e < _DAT_00808810 || (_DAT_008096aa != 0)))
       ) {
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
  if (((_DAT_008035da & 8) == 0) || (((_DAT_00805e00 & 2) != 0 && ((_DAT_008068d2 & 2) != 0)))) {
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
// Function: FUN_0001ee02 @ 0x0001ee02
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0001ee02(void)

{
  if ((_DAT_008035ec & 1) == 0) {
    _DAT_0080557c = 0;
  }
  _DAT_0080d098 = 0;
  _DAT_0080171c = _DAT_0080557c;
  return _DAT_008035ec & 1;
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
  if ((_DAT_0080cffc != 0) && (uVar1 = 0, (_DAT_008035d6 & 0x8000) != 0)) {
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
  if ((_DAT_008035ec & 0x4000) == 0) {
    bVar1 = false;
  }
  else if (_DAT_0080d098 == 0) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (_DAT_0080c810 == 1) {
    _DAT_0080171e = 0;
    if (bVar2) {
      _DAT_0080d094 = _DAT_00808830;
    }
    else {
      _DAT_0080d094 = 0;
    }
  }
  else if (_DAT_0080c810 != 2) {
    if ((bVar2) && (_DAT_0080171e < _DAT_00808832)) {
      _DAT_0080171e = _DAT_0080171e + 1;
    }
    if ((_DAT_0080c810 == 3) && ((_DAT_00808832 <= _DAT_0080171e || (!bVar2)))) {
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
  undefined2 *puVar2;
  
  if (_DAT_00801722 == 2) {
    if (_DAT_00fffd24 == 5) {
      if ((_DAT_00fffd06 & 1) == 0) {
        if (_DAT_0080c3fe == 0) {
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
    if (_DAT_0080c3fe == 0) {
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
    _DAT_0080c3fe = _DAT_0080c3fe + -1;
    _DAT_0080c3fa = _DAT_0080c3fa + 1 & 0x1ff;
  }
  return;
}



//
// Function: FUN_0001f068 @ 0x0001f068
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0001f068(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  DAT_00fffc1f = DAT_00fffc1f & 0x7f;
  FUN_0001ef20();
  _DAT_00fffc1a = _DAT_00fffc1a | 0x8000;
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
// Function: FUN_0001f1e0 @ 0x0001f1e0
//

void FUN_0001f1e0(undefined1 *param_1,undefined1 *param_2,undefined4 param_3)

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
  
  _DAT_0080173c = current_engine_param;
  _DAT_00801748 = _DAT_0080926e;
  sVar1 = FUN_00035560((short *)&DAT_00801742);
  sVar2 = FUN_00035560((short *)&DAT_00801736);
  fsmxthfl_calc_input = sVar1 + sVar2;
  return;
}



//
// Function: FUN_0001f23e @ 0x0001f23e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001f23e(void)

{
  _DAT_0080173c = current_engine_param;
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
  _DAT_0080d0b4 = 0;
  _DAT_0080d050 = 0;
  _DAT_0080d0b2 = 0;
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
// Function: FUN_0001f2ce @ 0x0001f2ce
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001f2ce(void)

{
  short sVar1;
  short sVar2;
  
  _DAT_0080175c = (short)((_DAT_00805590 + 2) % 3);
  *(undefined4 *)((short)(_DAT_0080175c * 2) * 8 + 0x80559c) = _DAT_00805f2c;
  *(int *)((short)(_DAT_0080175c * 2) * 8 + 0x8055a0) = _DAT_0080d0bc;
  *(undefined4 *)((short)(_DAT_0080175c * 2) * 8 + 0x8055ce) = _DAT_00805f6c;
  *(int *)((short)(_DAT_0080175c * 2) * 8 + 0x8055d2) = _DAT_0080d0b6;
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
  if (0x63ff < jcthkctd_calc_input) {
    *(undefined4 *)((short)(_DAT_0080175c * 2) * 8 + 0x8055a8) = _DAT_00805582;
    *(undefined4 *)((short)(_DAT_0080175c * 2) * 8 + 0x8055da) = _DAT_0080558a;
    return;
  }
  sVar2 = _DAT_0080175c << 4;
  *(int *)(sVar2 + 0x8055a8) = _DAT_0080d0bc + (*(int *)(sVar1 + 0x8055a4) - _DAT_0080557e);
  *(int *)((short)(_DAT_0080175c * 2) * 8 + 0x8055da) =
       _DAT_0080d0b6 + (*(int *)(sVar2 + 0x8055d6) - _DAT_00805586);
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
  uVar3 = CONCAT22((short)((uint)in_D0 >> 0x10),_DAT_008035ec) & 0xffff2000;
  if ((_DAT_008035ec & 0x2000) != 0) {
    if ((ushort)(((uint)_DAT_0080373a << 8) / 10) <= jcthkctd_calc_input) {
      _DAT_0080d04e = 1;
    }
    _DAT_0080d0bc = _DAT_00805f2c - *(int *)((short)(_DAT_00805590 * 2) * 8 + 0x80559c);
    _DAT_0080d0b6 = _DAT_00805f6c - *(int *)((short)(_DAT_00805590 * 2) * 8 + 0x8055ce);
    if ((current_engine_param != 0) && (_DAT_00805f40 != 0)) {
      if (_DAT_0080888a < _DAT_00801758) {
        _DAT_0080558e = _DAT_0080558e | 2;
      }
      else {
        _DAT_00801758 = _DAT_00801758 + 1;
      }
    }
    if (((current_engine_param != 0) && ((_DAT_00805df2 & 0x800) != 0)) &&
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
      uVar2 = FUN_000357d2(_DAT_00805586,0x6400,(uint)_DAT_0080d0ba << 7);
      puVar5 = &stack0xffffffe0;
      if ((uVar1 < uVar2) || (uVar3 = (uint)_DAT_0080d0b0, uVar1 < uVar3)) {
        if ((uVar1 < _DAT_0080d0b0) && (uVar3 = (uint)_DAT_0080d0b0, uVar2 < uVar3)) {
          _DAT_0080d0ac = 3;
          jcthkctd_calc_input = _DAT_0080d0b0;
        }
        else {
          uVar3 = (uint)_DAT_0080d0b0;
          _DAT_0080d0ac = 2;
          jcthkctd_calc_input = (word)uVar2;
        }
      }
      else {
        _DAT_0080d0ac = 1;
        jcthkctd_calc_input = (word)uVar1;
      }
    }
    else if (_DAT_00803734 == 1) {
      puVar5 = &stack0xffffffd4;
      uVar3 = FUN_000357d2(_DAT_00805f2c - *(int *)((short)(_DAT_00805590 * 2) * 8 + 0x80559c),
                           0x6400,(uint)_DAT_00803736 * 0x465);
      jcthkctd_calc_input = (word)uVar3;
      _DAT_0080d0ac = 1;
    }
    else {
      jcthkctd_calc_input = _DAT_0080d0b0;
      _DAT_0080d0ac = 3;
    }
    if (((_DAT_00805582 == 0) && (_DAT_0080558a == 0)) && (0x63ff < jcthkctd_calc_input)) {
      _DAT_00805582 = _DAT_00805f2c - *(int *)((short)(_DAT_00805590 * 2) * 8 + 0x80559c);
      uVar3 = _DAT_00805f6c - *(int *)((short)(_DAT_00805590 * 2) * 8 + 0x8055ce);
      _DAT_0080558a = uVar3;
    }
    if ((_DAT_00801756 == 1) || (_DAT_0080d050 == 1)) {
      *(undefined4 *)(puVar5 + -4) = 0x1f7b4;
      FUN_0001f2ce();
      *(undefined4 *)(puVar5 + -4) = 0x1f7b8;
      uVar3 = FUN_0001f28c();
    }
    _DAT_00801756 = _DAT_0080d0b4;
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
    _DAT_0080d0ba = FUN_00035560(local_1c);
    local_10[3] = _DAT_00803738;
    _DAT_0080d0c0 = FUN_00035560(local_10);
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
  
  if ((fsmxthfl_calc_input < _DAT_0080c9a4) && (fsmxthfl_calc_input < _DAT_0080c9d8)) {
    uVar2 = FUN_000357d2((uint)_DAT_0080c9a4 - (uint)fsmxthfl_calc_input,0x6400,
                         (uint)_DAT_0080c9d8 - (uint)fsmxthfl_calc_input);
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
  if (fsmxthfl_calc_input < _DAT_0080c9a4) {
    if ((_DAT_0080cc5a < current_engine_param) && (_DAT_0080cc5c != 0)) {
      iVar1 = ((uint)_DAT_0080cc54 + (uint)current_engine_param) - (uint)_DAT_0080cc5a;
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
      if (_DAT_0080c9d8 <= fsmxthfl_calc_input) {
        asthrfes_calc_input = 0;
        return;
      }
      uVar3 = _DAT_0080c9d8 - fsmxthfl_calc_input;
    }
    uVar2 = (uint)(ushort)(_DAT_0080c9a4 - fsmxthfl_calc_input) * 0x6400;
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
    uVar5 = FUN_00017ce2((uint *)0x80bda4,&local_5);
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
// Function: EcuStartup @ 0x00020462
//

/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void EcuStartup(void)

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
  stack_area[10] = 0;
  stack_area[0xb] = 0;
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
  FUN_00026ec4();
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x582;
  FUN_0000f4ea();
  _DAT_0080d1a2 = 0xeeee;
  DAT_0080bdf0 = DAT_0080bdf0 | 8;
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x598;
  FUN_0001977e();
  _DAT_0080fffc = 2;
  _DAT_0080fffe = 0x5ac;
  FUN_00026e7e();
  _DAT_00fffc00 = 5;
  DAT_00fffc04 = 0x13;
  DAT_00fffc05 = 0x50;
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
  FUN_0000a598();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x640;
  FUN_0000bf9c();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x646;
  FUN_0002b4fe();
  _DAT_0080fffa = 2;
  _DAT_0080fffc = 0x64c;
  FUN_0000a53e();
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
  FUN_00017b3a();
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
  hardwareControllersInit();
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
// Function: hardwareControllersInit @ 0x000207b6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void hardwareControllersInit(void)

{
  byte bVar1;
  undefined1 *puVar2;
  
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
  ecuSystemInit();
  return;
}



//
// Function: ecuSystemInit @ 0x00020918
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ecuSystemInit(void)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  undefined *puVar6;
  undefined1 *puVar7;
  
  _DAT_0080cf7c = 0x80ce60;
  _DAT_0080cf78 = 0x80ce60;
  _DAT_0080cf84 = 0x80ccf8;
  _DAT_0080cf80 = 0x80ccf8;
  FUN_0001cb6e();
  _DAT_0080cfa2 = 4;
  bVar3 = 0;
  puVar6 = &DAT_0080cfa4;
  do {
    *puVar6 = 0xfe;
    bVar3 = bVar3 + 1;
    puVar6 = puVar6 + 1;
  } while (bVar3 < 4);
  FUN_000294ea();
  FUN_00029796();
  engineParamCanBuilder();
  FUN_0002a51e();
  FUN_0002a5da();
  FUN_0002a7f8();
  FUN_0002aba4();
  FUN_0002ada8();
  FUN_0002b1f6();
  FUN_00027dd4();
  FUN_0002956a();
  FUN_0002a8da();
  FUN_0002aee2();
  FUN_0002afca();
  FUN_0002b060();
  FUN_0002b338();
  FUN_00029a86();
  FUN_0002a222();
  FUN_0001af38(0,100);
  FUN_0001af38(0,0x14);
  FUN_0001af38(0,0x32);
  FUN_0001af38(0,0xfa);
  FUN_0001af38(0,5000);
  FUN_0001af38(1,100);
  FUN_0001af38(0,100);
  FUN_0001af38(1,5000);
  FUN_0001af38(0,1000);
  FUN_0001af38(0,500);
  FUN_0001af38(0,100);
  FUN_0001af38(0,1000);
  FUN_0001af38(0,500);
  FUN_0001af38(0,1000);
  FUN_0001af38(0,1000);
  FUN_00027300();
  FUN_00027e86();
  FUN_00027514();
  FUN_0002793e();
  FUN_000273c0();
  FUN_0001c0c2();
  FUN_0001bd58();
  FUN_0001b762();
  FUN_0000fa40();
  FUN_0001b172();
  _DAT_0080cfb6 = _DAT_00809d48 + 1;
  _DAT_00809d48 = _DAT_00809d48 + 8;
  _DAT_0080cf8c = &DAT_00ffd800 + (uint)_DAT_0080cfb6 * 0x10;
  _DAT_0080cfb8 = _DAT_00809d48;
  *_DAT_0080cf8c = 0x55;
  _DAT_0080cf8c[1] = 0xfb;
  *_DAT_0080cf8c = 0xef;
  _DAT_0080cf8c[6] = 4;
  puVar7 = &DAT_00ffd810 + (uint)_DAT_0080cfb6 * 0x10;
  uVar2 = (uint)_DAT_0080cfc2;
  bVar5 = DAT_0080cfc3 << 3;
  bVar3 = 0;
  for (bVar4 = 0; bVar4 < _DAT_008088de; bVar4 = bVar4 + 1) {
    *puVar7 = 0x99;
    puVar7[6] = 4;
    puVar7[1] = 0xdf;
    puVar7[2] = *(undefined1 *)(bVar3 + 0x8088ea);
    puVar7[3] = (byte)((int)(uVar2 & 0xe0) >> 5) | *(byte *)((byte)(bVar3 + 1) + 0x8088ea) & 0xf8;
    bVar1 = bVar3 + 3;
    puVar7[4] = bVar5 | *(byte *)((byte)(bVar3 + 2) + 0x8088ea) & 7;
    bVar3 = bVar3 + 4;
    puVar7[5] = *(undefined1 *)(bVar1 + 0x8088ea);
    puVar7 = puVar7 + 0x10;
  }
  for (bVar4 = 0; bVar4 < _DAT_008088e0; bVar4 = bVar4 + 1) {
    *puVar7 = 0x99;
    puVar7[1] = 0xdf;
    puVar7[6] = 4;
    puVar7[2] = *(undefined1 *)(bVar3 + 0x8088ea);
    puVar7[3] = *(undefined1 *)((byte)(bVar3 + 1) + 0x8088ea);
    bVar5 = bVar3 + 3;
    puVar7[4] = *(undefined1 *)((byte)(bVar3 + 2) + 0x8088ea);
    bVar3 = bVar3 + 4;
    puVar7[5] = *(undefined1 *)(bVar5 + 0x8088ea);
    puVar7 = puVar7 + 0x10;
  }
  uVar2 = (uint)_DAT_0080cfcc;
  bVar5 = DAT_0080cfcd << 3;
  for (bVar4 = 0; bVar4 < _DAT_008088e2; bVar4 = bVar4 + 1) {
    *puVar7 = 0x99;
    puVar7[1] = 0xdf;
    puVar7[6] = 4;
    puVar7[2] = *(undefined1 *)(bVar3 + 0x8088ea);
    puVar7[3] = (byte)((int)(uVar2 & 0xe0) >> 5) | *(byte *)((byte)(bVar3 + 1) + 0x8088ea) & 0xf8;
    bVar1 = bVar3 + 3;
    puVar7[4] = bVar5 | *(byte *)((byte)(bVar3 + 2) + 0x8088ea) & 7;
    bVar3 = bVar3 + 4;
    puVar7[5] = *(undefined1 *)(bVar1 + 0x8088ea);
    puVar7 = puVar7 + 0x10;
  }
  for (bVar4 = 0; bVar4 < _DAT_008088e4; bVar4 = bVar4 + 1) {
    *puVar7 = 0x99;
    puVar7[1] = 0xdf;
    puVar7[6] = 4;
    puVar7[2] = *(undefined1 *)(bVar3 + 0x8088ea);
    puVar7[3] = *(undefined1 *)((byte)(bVar3 + 1) + 0x8088ea);
    bVar5 = bVar3 + 3;
    puVar7[4] = *(undefined1 *)((byte)(bVar3 + 2) + 0x8088ea);
    bVar3 = bVar3 + 4;
    puVar7[5] = *(undefined1 *)(bVar5 + 0x8088ea);
    puVar7 = puVar7 + 0x10;
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
  
  DAT_00fffa27 = 0xaa;
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
  int local_a;
  ushort local_6;
  
  uVar15 = (undefined2)((uint)unaff_D2 >> 0x10);
  FUN_00028b78();
  DAT_00fffa27 = 0xaa;
  DAT_00ffd00f = 0xaa;
  _DAT_0080d19c = 1;
  uVar14 = (ushort)(byte)(in_XF << 4);
  uVar5 = 0;
  while ((uVar5 < 1000 && (uVar1 = FUN_00013134(), (char)uVar1 == '\0'))) {
    FUN_00013240();
    FUN_0002baf0(CONCAT22(500,uVar14));
    uVar5 = uVar5 + 1;
  }
  DAT_0080bdf0 = DAT_0080bdf0 | 4;
  FUN_000122d0();
  if (_DAT_0080d19e != 0) {
    puVar7 = (undefined2 *)&DAT_008062cc;
    if (_DAT_0080d1a0 == 2) {
      puVar8 = &DAT_00007e3e;
    }
    else {
      puVar8 = (undefined2 *)&LAB_00005e3e;
    }
    for (; puVar7 < (undefined2 *)0x8062ce; puVar7 = puVar7 + 1) {
      *puVar7 = *puVar8;
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
      uVar1 = FUN_0000ed52();
      unaff_D7 = uVar1 & 0xffff;
      DAT_00fffa27 = 0xaa;
      DAT_00ffd00f = 0xaa;
    }
    else if (((sVar2 == 1) && (bVar13 == 1)) || ((sVar2 == 2 && (bVar13 == 2)))) {
      DAT_00fffa27 = 0xaa;
      DAT_00ffd00f = 0xaa;
      uVar1 = FUN_0000ef80();
      unaff_D7 = uVar1 & 0xffff;
      DAT_00fffa27 = 0xaa;
      DAT_00ffd00f = 0xaa;
    }
    if ((short)unaff_D7 == 1) {
      FUN_00020de4();
    }
    if (_DAT_00803686 != _DAT_00803688) {
      FUN_00013144(0x803688,&DAT_00803686,
                   CONCAT22(2,(ushort)(byte)((_DAT_00803686 < _DAT_00803688) << 4 |
                                             ((short)(_DAT_00803686 - _DAT_00803688) < 0) << 3 |
                                             (_DAT_00803686 == _DAT_00803688) << 2 |
                                             SBORROW2(_DAT_00803686,_DAT_00803688) << 1 |
                                            _DAT_00803686 < _DAT_00803688)));
      uVar5 = 0;
      while( true ) {
        DAT_00fffa27 = 0xaa;
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
      DAT_00fffa27 = 0xaa;
      DAT_00ffd00f = 0xaa;
      FUN_00011c28();
      FUN_0002baf0(CONCAT22(10000,uVar15));
      bVar6 = bVar6 + 1;
    }
    if ((DAT_0080bdc6 & 1) != 0) {
      FUN_00020de4();
    }
    bVar6 = bVar13 + 1;
    cVar12 = bVar13 - 1;
    bVar13 = bVar6;
  } while (bVar6 < 3);
  uVar14 = (ushort)(byte)((bVar6 < 2) << 4 | (cVar12 < '\0') << 3 | (bVar6 == 2) << 2 |
                          SBORROW1(bVar6,'\x02') << 1 | bVar6 < 2);
  local_a = _DAT_0080d4c4;
  FUN_00013144(0x80352c,(undefined1 *)&local_a,CONCAT22(4,uVar14));
  uVar5 = 0;
  while( true ) {
    DAT_00fffa27 = 0xaa;
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
        DAT_00fffa27 = 0xaa;
        DAT_00ffd00f = 0xaa;
        uVar14 = uVar14 + 1;
      } while (uVar14 < 0xa0);
      sVar2 = sVar2 + 1;
    } while (sVar2 == 0);
    uVar5 = uVar5 + 1;
  }
  FUN_000253a6();
  DAT_0080bdf0 = DAT_0080bdf0 & 0xf3;
  DAT_00fffa27 = 0xaa;
  DAT_00ffd00f = 0xaa;
  FUN_000122d0();
  local_6 = 0;
  sVar2 = _DAT_00fff404;
  do {
    while ((ushort)(_DAT_00fff404 - sVar2) < 500) {
      DAT_00fffa27 = 0xaa;
      DAT_00ffd00f = 0xaa;
      FUN_00011c28();
      if ((DAT_0080bdc6 & 1) != 0) {
        DAT_0080bdf0 = DAT_0080bdf0 & 0xfb | 8;
        DAT_00fffa27 = 0xaa;
        DAT_00ffd00f = 0xaa;
        FUN_000122d0();
        FUN_00020de4();
      }
    }
    local_6 = local_6 + 1;
    sVar2 = _DAT_00fff404;
  } while (local_6 < 0x28);
  DAT_0080bdf0 = DAT_0080bdf0 & 0xfb | 8;
  DAT_00fffa27 = 0xaa;
  DAT_00ffd00f = 0xaa;
  FUN_000122d0();
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
    FUN_00011c28();
    FUN_0002baf0(CONCAT22(10000,uVar15));
    bVar13 = bVar13 + 1;
  }
  cVar10 = (DAT_0080bdc6 & 1) == 0;
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
        DAT_00fffa27 = 0xaa;
        DAT_00ffd00f = 0xaa;
        uVar14 = uVar14 + 1;
      } while (uVar14 < 0xa0);
      sVar2 = sVar2 + 1;
    } while (sVar2 == 0);
    uVar5 = uVar5 + 1;
  }
  while ((DAT_0080bdc6 & 1) == 0) {
    FUN_00011c28();
  }
  FUN_00020de4();
  return;
}



//
// Function: FUN_00022270 @ 0x00022270
// ERROR: Failed to decompile
//

//
// Function: FUN_00022330 @ 0x00022330
//

/* WARNING: Control flow encountered bad instruction data */

void FUN_00022330(void)

{
  int unaff_D3;
  undefined4 *unaff_A2;
  
  if ((short)unaff_D3 < 0 || *(short *)(uint)*(ushort *)((int)unaff_A2 + 0x5db9) < (short)unaff_D3)
  {
    __m68k_trap(6);
  }
  if (unaff_D3 < 0 || *(int *)*unaff_A2 < unaff_D3) {
    __m68k_trap(6);
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//
// Function: FUN_00022aac @ 0x00022aac
//

/* WARNING: Control flow encountered bad instruction data */

void FUN_00022aac(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//
// Function: FUN_00022ef1 @ 0x00022ef1
//

/* WARNING: Control flow encountered bad instruction data */

void FUN_00022ef1(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//
// Function: FUN_00022fa3 @ 0x00022fa3
//

/* WARNING: Control flow encountered bad instruction data */

void FUN_00022fa3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//
// Function: FUN_00023013 @ 0x00023013
//

/* WARNING: Control flow encountered bad instruction data */

void FUN_00023013(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//
// Function: FUN_00023b6b @ 0x00023b6b
//

/* WARNING: Control flow encountered bad instruction data */

void FUN_00023b6b(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//
// Function: FUN_00023c60 @ 0x00023c60
//

/* WARNING: Control flow encountered bad instruction data */

void FUN_00023c60(void)

{
  int unaff_A3;
  bool in_NF;
  
  if (in_NF) {
    FUN_00023c60();
  }
  *(char *)(unaff_A3 + -1) = *(char *)(unaff_A3 + -1) + '\b';
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//
// Function: FUN_0002403a @ 0x0002403a
//

/* WARNING: Control flow encountered bad instruction data */

void FUN_0002403a(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//
// Function: FUN_00024918 @ 0x00024918
//

/* WARNING: Control flow encountered bad instruction data */

void FUN_00024918(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//
// Function: FUN_0002499a @ 0x0002499a
//

/* WARNING: Control flow encountered bad instruction data */

void FUN_0002499a(void)

{
  bool in_NF;
  
  if (in_NF) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//
// Function: FUN_00024c31 @ 0x00024c31
//

/* WARNING: Control flow encountered bad instruction data */

void FUN_00024c31(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//
// Function: FUN_00024cf6 @ 0x00024cf6
//

/* WARNING: Control flow encountered bad instruction data */

void FUN_00024cf6(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
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
// Function: FUN_00024e58 @ 0x00024e58
//

void FUN_00024e58(int param_1,undefined4 param_2)

{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  byte *pbVar4;
  byte *local_8;
  
  bVar2 = 0;
  pbVar4 = &DAT_0002170d;
  local_8 = sensor_data_buffer;
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
        if (&LAB_00024d02_2 < pbVar4) {
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
    *local_8 = (byte)uVar3;
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
  if ((undefined *)((uint)_DAT_00fffd06 | (uint)_DAT_00fffd04 << 8) != &DAT_0000600d) {
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
  DAT_00fffa15 = DAT_00fffa15 | 8;
  DAT_00fffa11 = DAT_00fffa11 | 8;
  DAT_00fffc1f = DAT_00fffc1f & 0x7f;
  _DAT_00fffc1a = _DAT_00fffc1a & 0x7fff;
  _DAT_00fffc1c = _DAT_00fffc1c & 0x7ff0;
  _DAT_00fffc0a = 0;
  _DAT_00fffa22 = 0;
  _DAT_00fffa24 = 0;
  stack_area[10] = 0;
  stack_area[0xb] = 0;
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
  _DAT_00fffc00 = 5;
  DAT_00fffc04 = 0x13;
  DAT_00fffc05 = 0x50;
  FUN_00025356();
  bVar2 = FUN_00024f50();
  if (bVar2 == 0) {
    bVar2 = FUN_0002504e();
    if (bVar2 == 0) {
      uVar1 = FUN_00025108();
      if ((char)uVar1 == '\0') {
        if ((_FUN_000294ea == -0x6789abcd) || (_FUN_000294ea == -0x6789abce)) {
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
  byte *pbVar1;
  byte *pbVar2;
  
  pbVar2 = sensor_data_buffer;
  while (pbVar2 < (byte *)0x807eb0) {
    pbVar1 = pbVar2 + 0x100;
    if ((byte *)0x807eb0 < pbVar1) {
      pbVar1 = (byte *)0x807eb0;
    }
    for (; pbVar2 < pbVar1; pbVar2 = pbVar2 + 4) {
      pbVar2[0] = 0;
      pbVar2[1] = 0;
      pbVar2[2] = 0;
      pbVar2[3] = 0;
    }
    DAT_00fffa27 = 0xaa;
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
    DAT_0080bdf0 = DAT_0080bdf0 | 2;
    FUN_000122d0();
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
    DAT_0080bdf0 = DAT_0080bdf0 & 0xfd;
    FUN_000122d0();
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
  undefined *puVar8;
  undefined4 *puVar9;
  undefined1 *puVar10;
  undefined4 local_8;
  
  puVar8 = &DAT_0080d0ce;
  bVar3 = 0;
  bVar5 = 0;
  for (bVar6 = 0; bVar7 = (byte)((uint)param_1 >> 0x10), bVar6 < bVar7; bVar6 = bVar6 + 1) {
    if ((puVar8[9] == '\x05') || (puVar8[9] == '\x03')) {
      bVar5 = bVar5 + 1;
      bVar3 = puVar8[8] + bVar3;
    }
    in_D0 = 0;
    puVar8 = puVar8 + 10;
  }
  if ((bVar5 == 0) ||
     (((uint)bVar5 + (uint)_DAT_0080d44e < 0xb &&
      (in_D0 = (int)&DAT_0080d3a6 - (int)_DAT_0080d3e2, (int)(uint)bVar3 <= (int)in_D0)))) {
    puVar9 = (undefined4 *)&DAT_0080d0ce;
    for (bVar5 = 0; bVar5 < bVar7; bVar5 = bVar5 + 1) {
      local_8 = (undefined1 *)puVar9[1];
      uVar4 = (ushort)*(byte *)(puVar9 + 2);
      if ((*(char *)((int)puVar9 + 9) == '\x05') || (*(char *)((int)puVar9 + 9) == '\x03')) {
        *(undefined1 **)(&DAT_0080d3a6 + (short)(_DAT_0080d44e * 3) * 2) = (undefined1 *)*puVar9;
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
        puVar10 = (undefined1 *)*puVar9;
        for (bVar3 = 0; bVar3 < uVar4; bVar3 = bVar3 + 1) {
          *puVar10 = *local_8;
          local_8 = (undefined1 *)CONCAT31(local_8._0_3_,(char)local_8 + '\x01');
          puVar10 = puVar10 + 1;
        }
      }
      in_D0 = 0;
      puVar9 = (undefined4 *)((int)puVar9 + 10);
    }
    uVar2 = in_D0 & 0xffffff00;
  }
  else {
    uVar2 = 0xe;
  }
  return uVar2;
}



//
// Function: FUN_000256a4 @ 0x000256a4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_000256a4(void)

{
  byte bVar1;
  
  _DAT_0080d452 = &DAT_0080d2de;
  _DAT_0080d45a = 200;
  _DAT_0080d44a = &DAT_0080d3a6;
  _DAT_0080d44e = 0;
  _DAT_0080d3e2 = &DAT_0080d2de;
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
  _DAT_00fffc08 = 0x34;
  _DAT_00fffc0a = 0x102c;
  return _DAT_00fffc0c;
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
  _DAT_0080d3e2 = &DAT_0080d2de;
  _DAT_0080d458 = 0;
  _DAT_0080d44e = 0;
  return;
}



//
// Function: FUN_000258e0 @ 0x000258e0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_000258e0(void)

{
  undefined1 uVar1;
  byte *pbVar2;
  byte bVar3;
  char cVar4;
  uint in_D0;
  undefined4 uVar5;
  char cVar7;
  uint uVar6;
  byte bVar8;
  byte bVar9;
  undefined1 *puVar10;
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
      uVar6 = *puVar11;
      pbVar2 = (byte *)((int)puVar12 + -1);
      if (((0xffffff < uVar6) || ((0x8062cb < uVar6 && (uVar6 < 0x8062cf)))) ||
         ((puVar12 = puVar11, cVar7 = cVar4, 0x8062cb < uVar6 + *pbVar2 &&
          (uVar6 + *pbVar2 < 0x8062cf)))) {
        FUN_000258c8();
        return 7;
      }
    }
  }
  if ((_DAT_0080d3f4 == 0) &&
     ((_DAT_0080d458 == 0 || (uVar5 = FUN_0000fd02(), (short)uVar5 != _DAT_0080d456)))) {
    FUN_000258c8();
    return 0x14;
  }
  if (10 < _DAT_0080d44e) {
    FUN_000258c8();
    return 4;
  }
  _DAT_0080d3e2 = &DAT_0080d2de;
  bVar9 = 0;
  puVar12 = (uint *)&DAT_0080d3a6;
  do {
    if (_DAT_0080d44e <= bVar9) {
      uVar6 = FUN_000258c8();
      return uVar6 & 0xffffff00;
    }
    puVar10 = (undefined1 *)*puVar12;
    bVar3 = *(byte *)((int)puVar12 + 5);
    if (puVar10 < (undefined1 *)0x1000000) {
      for (bVar8 = 0; bVar8 < bVar3; bVar8 = bVar8 + 1) {
        if ((((undefined1 *)0x8062cb < puVar10) && (puVar10 < (undefined1 *)0x8062cf)) &&
           (_DAT_0080d3f4 == 0)) {
          _DAT_0080d19e = 0;
        }
        uVar1 = *_DAT_0080d3e2;
        _DAT_0080d3e2 = _DAT_0080d3e2 + 1;
        *puVar10 = uVar1;
        puVar10 = puVar10 + 1;
      }
    }
    else {
      if ((_DAT_0080d19c == 1) &&
         (cVar7 = FUN_000131d6((short)((uint)_DAT_0080d3e2 >> 0x10),bVar3), cVar7 == '\x01')) {
        FUN_000258c8();
        return 4;
      }
      puVar10 = puVar10 + -0x7fcb08;
      for (bVar8 = 0; bVar8 < bVar3; bVar8 = bVar8 + 1) {
        uVar1 = *_DAT_0080d3e2;
        _DAT_0080d3e2 = _DAT_0080d3e2 + 1;
        *puVar10 = uVar1;
        puVar10 = puVar10 + 1;
      }
    }
    puVar12 = (uint *)((int)puVar12 + 6);
    bVar9 = bVar9 + 1;
  } while( true );
}



//
// Function: FUN_00025a90 @ 0x00025a90
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00025a90(void)

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
      FUN_00025ece();
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
    _DAT_0080d168 = FUN_00035608();
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
    if (fsmxthfl_calc_input < _DAT_0080d166) {
      uStack_6 = (ushort)((uint)uVar8 * ((uint)_DAT_0080d166 - (uint)fsmxthfl_calc_input) >> 0xe);
      _DAT_0080d170 = uStack_6;
    }
    else {
      _DAT_0080d170 = 0;
    }
    uStack_6 = (ushort)((uint)uVar8 * (0x7fff - (uint)_DAT_00808920) >> 0xe);
    uVar1 = uStack_6 + _DAT_00808920;
    iVar3 = (uint)_DAT_0080891c * (uint)uVar1 * 2;
    iVar4 = (uint)_DAT_0080891e * (uint)uVar1 * 2;
    if (_DAT_0080c9a6 != 4) {
      _DAT_0080d172 = _DAT_0080d16a;
      if (fsmxthfl_calc_input < _DAT_0080c9a4) {
        uStack_6 = (ushort)((uint)uVar8 * ((uint)_DAT_0080c9a4 - (uint)fsmxthfl_calc_input) >> 0xe);
        _DAT_0080d170 = uStack_6;
      }
      else {
        _DAT_0080d170 = 0;
      }
      iVar2 = (uint)_DAT_0080c9a4 * (uint)uVar1 * 2;
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
// Function: FUN_00025ece @ 0x00025ece
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00025ece(void)

{
  int iVar1;
  uint uVar2;
  undefined2 uStack_6;
  
  _DAT_0080d172 = 0;
  FUN_000260ec();
  _DAT_0080189c = 0x80000000;
  _DAT_0080d168 = 0;
  uVar2 = FUN_000357d2((uint)_DAT_008036a8,((uint)_DAT_008036aa * (uint)_DAT_0080d174 >> 10) + 0x200
                       ,1);
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
  _DAT_008018a0 = (uint)_DAT_0080c9a4 * (uint)(ushort)(uStack_6 + _DAT_00808920) * 2;
  iVar1 = _DAT_008018a0;
  _DAT_008018a0 = (undefined2)((uint)_DAT_008018a0 >> 0x10);
  _DAT_0080d16e = _DAT_008018a0;
  _DAT_0080d166 = _DAT_0080c9a4;
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
  
  if (param_scale_factor < param_ref_base.base_reference) {
    local_8 = 0;
  }
  else {
    local_8 = (uint)param_scale_factor - (uint)param_ref_base.base_reference;
  }
  _DAT_0080d176 =
       param_ref_base.base_reference +
       (short)(((uint)_DAT_0080380e * (local_8 & 0xffff)) / (uint)_DAT_00807c32);
  _DAT_0080189c = 0x80000000;
  _DAT_00801898 = 0x808916;
  FUN_000260fe();
  return;
}



//
// Function: FUN_0002604e @ 0x0002604e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002604e(void)

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
  uVar1 = FUN_000356f8();
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
// Function: FUN_000260ec @ 0x000260ec
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000260ec(void)

{
  _DAT_0080d174 = current_engine_param;
  _DAT_008018aa = 0;
  return;
}



//
// Function: FUN_000260fe @ 0x000260fe
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000260fe(void)

{
  _DAT_008018aa = 0;
  _DAT_008018a6 = 0x808928;
  return;
}



//
// Function: FUN_00026110 @ 0x00026110
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00026110(void)

{
  uint in_D0;
  uint uVar1;
  
  if ((((diagnostic_status_register == 1) || (diagnostic_status_register == 2)) ||
      (diagnostic_status_register == 0x1e)) || (diagnostic_status_register == 3)) {
    _DAT_0080d184 = diagnostic_status_register;
    _DAT_0080d182 = cached_parameter_value;
    _DAT_0080d180 = 0;
    _DAT_0080d17e = _DAT_008037b4;
    return in_D0;
  }
  if (_DAT_0080d17a == 1) {
    in_D0 = _DAT_008035da & 0x10;
    if ((_DAT_008035da & 0x10) != 0) {
      if ((diagnostic_status_register == 7) || (diagnostic_status_register == 8)) {
        uVar1 = (uint)cached_parameter_value;
        if (_DAT_0080d166 <= cached_parameter_value) {
          uVar1 = _DAT_008035d8 & 0x2000;
          if ((_DAT_008035d8 & 0x2000) != 0) {
            _DAT_0080d182 = cached_parameter_value;
            _DAT_0080d184 = diagnostic_status_register;
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
      if ((diagnostic_status_register != 6) && (diagnostic_status_register != 5)) {
        return in_D0;
      }
      _DAT_0080d182 = _DAT_0080d166;
      _DAT_0080d184 = 4;
      _DAT_0080d180 = 0;
      _DAT_0080d17e = _DAT_008037b4;
      return in_D0;
    }
  }
  _DAT_0080d184 = diagnostic_status_register;
  _DAT_0080d182 = cached_parameter_value;
  _DAT_0080d180 = 0;
  _DAT_0080d17e = _DAT_008037b4;
  return in_D0;
}



//
// Function: FUN_0002621c @ 0x0002621c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002621c(void)

{
  _DAT_0080d180 = 0;
  _DAT_0080d17e = _DAT_008037b4;
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
    uVar1 = ((((uint)_DAT_00808934 * (uint)_DAT_0080d186) / 0x6400 & 0xffff) * 8000) / 1000 & 0xffff
            | ((uint)_DAT_00808934 * 8000) / 1000 << 0x10;
    _DAT_00fff42a = uVar1;
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
      _DAT_00fff43a = _DAT_00fff43a & 0xffff0000;
    }
    else {
      uVar1 = ((((uint)_DAT_00808938 * (uint)_DAT_0080d18a) / 0x6400 & 0xffff) * 8000) / 1000 &
              0xffff | ((uint)_DAT_00808938 * 8000) / 1000 << 0x10;
      _DAT_00fff43a = uVar1;
    }
  }
  if (5 < _DAT_0080d19a) {
    uVar1 = uVar1 & 0xffff0000;
    if ((_DAT_00805670 & 8) == 0) {
      _DAT_00fff442 = _DAT_00fff442 & 0xffff0000;
    }
    else {
      uVar1 = ((((uint)_DAT_0080893a * (uint)_DAT_0080d18c) / 0x6400 & 0xffff) * 8000) / 1000 &
              0xffff | ((uint)_DAT_0080893a * 8000) / 1000 << 0x10;
      _DAT_00fff442 = uVar1;
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
  
  if (_DAT_0080d19a < 6) {
    _DAT_0080d19a = _DAT_0080d19a + 1;
    in_D0 = FUN_00026aca();
  }
  if (_DAT_00808934 != 0) {
    if ((_DAT_00fff450 & 0x8000) == 0) {
      if ((_DAT_0080d186 == 0) || ((_DAT_00805670 & 1) == 0)) {
        if ((_DAT_00fff450 & 0x80) == 0) {
          in_D0 = _DAT_00805e00 & 0xffff0010;
          if (((_DAT_00805e00 & 0x10) != 0) &&
             (in_D0 = _DAT_00805e40 & 0xffff0010, (_DAT_00805e40 & 0x10) == 0)) {
            _DAT_0080d190 = 0;
            _DAT_00805e00 = _DAT_00805e00 & 0xffef;
          }
        }
        else {
          in_D0 = (uint)_DAT_0080d190;
          if (_DAT_0080d190 < _DAT_00808940) {
            _DAT_0080d190 = _DAT_0080d190 + 1;
          }
          else {
            _DAT_00805e00 = _DAT_00805e00 | 0x10;
            _DAT_00805e40 = _DAT_00805e40 | 0x10;
          }
        }
      }
      else if (_DAT_0080d186 < 0x6400) {
        in_D0 = _DAT_00fff428 & 0xffff8000;
        if ((((_DAT_00fff428 & 0x8000) != 0) &&
            (in_D0 = _DAT_00805e00 & 0xffff0010, (_DAT_00805e00 & 0x10) != 0)) &&
           (in_D0 = _DAT_00805e40 & 0xffff0010, (_DAT_00805e40 & 0x10) == 0)) {
          _DAT_00fff428 = _DAT_00fff428 & 0x7fff;
          _DAT_0080d190 = 0;
          _DAT_00805e00 = _DAT_00805e00 & 0xffef;
        }
      }
      else if ((_DAT_00fff450 & 0x80) == 0) {
        in_D0 = (uint)_DAT_0080d190;
        if (_DAT_0080d190 < _DAT_00808940) {
          _DAT_0080d190 = _DAT_0080d190 + 1;
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
          _DAT_0080d190 = 0;
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
        _DAT_0080d190 = 0;
      }
    }
  }
  if (_DAT_00808936 != 0) {
    if ((_DAT_00fff448 & 0x8000) == 0) {
      if ((_DAT_0080d188 == 0) || ((_DAT_00805670 & 2) == 0)) {
        if ((_DAT_00fff448 & 0x80) == 0) {
          in_D0 = _DAT_00805e00 & 0xffff0020;
          if ((_DAT_00805e00 & 0x20) != 0) {
            in_D0 = _DAT_00805e40 & 0xffff0020;
            if ((_DAT_00805e40 & 0x20) == 0) {
              _DAT_00805e00 = _DAT_00805e00 & 0xffdf;
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
            _DAT_00805e00 = _DAT_00805e00 | 0x20;
            _DAT_00805e40 = _DAT_00805e40 | 0x20;
          }
        }
      }
      else if (_DAT_0080d188 < 0x6400) {
        in_D0 = _DAT_00fff430 & 0xffff8000;
        if ((((_DAT_00fff430 & 0x8000) != 0) &&
            (in_D0 = _DAT_00805e00 & 0xffff0020, (_DAT_00805e00 & 0x20) != 0)) &&
           (in_D0 = _DAT_00805e40 & 0xffff0020, (_DAT_00805e40 & 0x20) == 0)) {
          _DAT_00fff430 = _DAT_00fff430 & 0x7fff;
          _DAT_00805e00 = _DAT_00805e00 & 0xffdf;
          _DAT_0080d192 = 0;
        }
      }
      else if ((_DAT_00fff448 & 0x80) == 0) {
        in_D0 = (uint)_DAT_0080d192;
        if (_DAT_00808942 < _DAT_0080d192) {
          _DAT_00805e00 = _DAT_00805e00 | 0x20;
          _DAT_00805e40 = _DAT_00805e40 | 0x20;
        }
        else {
          _DAT_0080d192 = _DAT_0080d192 + 1;
        }
      }
      else {
        in_D0 = _DAT_00805e00 & 0xffff0020;
        if ((_DAT_00805e00 & 0x20) != 0) {
          in_D0 = _DAT_00805e40 & 0xffff0020;
          if ((_DAT_00805e40 & 0x20) == 0) {
            _DAT_00805e00 = _DAT_00805e00 & 0xffdf;
            _DAT_0080d192 = 0;
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
            _DAT_00805e00 = _DAT_00805e00 | 0x100;
            _DAT_00805e40 = _DAT_00805e40 | 0x100;
            return uVar1;
          }
          _DAT_0080d198 = _DAT_0080d198 + 1;
          return uVar1;
        }
        in_D0 = _DAT_00805e00 & 0xffff0100;
        if (((_DAT_00805e00 & 0x100) != 0) &&
           (in_D0 = _DAT_00805e40 & 0xffff0100, (_DAT_00805e40 & 0x100) == 0)) {
          _DAT_0080d198 = 0;
          _DAT_00805e00 = _DAT_00805e00 & 0xfeff;
          return in_D0;
        }
      }
      else if (_DAT_0080d18e < 0x6400) {
        in_D0 = _DAT_00fff418 & 0xffff8000;
        if ((((_DAT_00fff418 & 0x8000) != 0) &&
            (in_D0 = _DAT_00805e00 & 0xffff0100, (_DAT_00805e00 & 0x100) != 0)) &&
           (in_D0 = _DAT_00805e40 & 0xffff0100, (_DAT_00805e40 & 0x100) == 0)) {
          _DAT_00fff418 = _DAT_00fff418 & 0x7fff;
          _DAT_00805e00 = _DAT_00805e00 & 0xfeff;
          _DAT_0080d198 = 0;
          return in_D0;
        }
      }
      else {
        if ((_DAT_00fff420 & 0x80) == 0) {
          uVar1 = (uint)_DAT_0080d198;
          if (_DAT_00808948 <= _DAT_0080d198) {
            _DAT_00805e00 = _DAT_00805e00 | 0x100;
            _DAT_00805e40 = _DAT_00805e40 | 0x100;
            return uVar1;
          }
          _DAT_0080d198 = _DAT_0080d198 + 1;
          return uVar1;
        }
        in_D0 = _DAT_00805e00 & 0xffff0100;
        if ((_DAT_00805e00 & 0x100) != 0) {
          in_D0 = _DAT_00805e40 & 0xffff0100;
          if ((_DAT_00805e40 & 0x100) == 0) {
            _DAT_00805e00 = _DAT_00805e00 & 0xfeff;
            _DAT_0080d198 = 0;
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
        _DAT_0080d198 = 0;
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
  
  if (_DAT_0080d19a == 1) {
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
  if ((_DAT_0080d19a != 3) && (_DAT_0080d19a != 5)) {
    return (uint)_DAT_0080d19a;
  }
  if ((((_DAT_00fff438 & 0x80) == 0) || ((DAT_00fffa19 & 2) == 0)) &&
     (((_DAT_00fff438 & 0x80) != 0 || ((DAT_00fffa19 & 2) != 0)))) {
    _DAT_00805e00 = _DAT_00805e00 | 0x40;
    _DAT_00805e40 = _DAT_00805e40 | 0x40;
  }
  else if (((_DAT_00805e00 & 0x40) != 0) && ((_DAT_00805e40 & 0x40) == 0)) {
    _DAT_00805e00 = _DAT_00805e00 & 0xffbf;
  }
  if (((_DAT_00fff440 & 0x80) == 0) || ((DAT_00fffa19 & 4) == 0)) {
    if ((_DAT_00fff440 & 0x80) == 0) {
      if ((DAT_00fffa19 & 4) == 0) goto LAB_00026cc4;
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
// Function: FUN_00026ec4 @ 0x00026ec4
//

void FUN_00026ec4(void)

{
  byte *pbVar1;
  byte *pbVar2;
  
  pbVar2 = sensor_data_buffer;
  while (pbVar2 < (byte *)0x80d5ca) {
    pbVar1 = pbVar2 + 0x100;
    if ((byte *)0x80d5ca < pbVar1) {
      pbVar1 = (byte *)0x80d5ca;
    }
    for (; pbVar2 <= pbVar1; pbVar2 = pbVar2 + 4) {
      pbVar2[0] = 0;
      pbVar2[1] = 0;
      pbVar2[2] = 0;
      pbVar2[3] = 0;
    }
    DAT_00fffa27 = 0xaa;
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
  _DAT_008018b6 = &DAT_00037eae;
  _DAT_008018ba = &DAT_008062cc;
  _DAT_008018be = 0x8062ce;
  if (_DAT_0080d1a0 == 2) {
    _DAT_008018c2 = &DAT_00007e3e;
  }
  else {
    _DAT_008018c2 = (undefined2 *)&LAB_00005e3e;
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
  _DAT_008018ca = &DAT_00037eae;
  _DAT_008018d2 = 0;
  _DAT_0080d19c = 1;
  _DAT_0080d19e = 1;
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
  
  if ((_DAT_008018d6 == 0) && (_DAT_0080d19c != 0)) {
    FUN_00026f10();
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
  _DAT_008018d6 = _DAT_0080d19c;
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
// Function: FUN_0002725a @ 0x0002725a
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
// Function: FUN_00027300 @ 0x00027300
//

void FUN_00027300(void)

{
  FUN_0001b1b4();
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
// Function: FUN_0002732e @ 0x0002732e
//

void FUN_0002732e(void)

{
  FUN_0002787e();
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
// Function: FUN_000273c0 @ 0x000273c0
//

void FUN_000273c0(void)

{
  FUN_0001b1b4();
  return;
}



//
// Function: FUN_000273d4 @ 0x000273d4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000273d4(int param_1)

{
  if (((*(byte *)(param_1 + 3) == _DAT_008084a4) || (_DAT_008084a4 == 0xff)) &&
     (*(short *)(param_1 + 4) == 8)) {
    DAT_008019a2 = **(byte **)(param_1 + 6);
    DAT_008019a6 = *(byte *)(*(int *)(param_1 + 6) + 4);
    if (_DAT_0080d03c == 0) {
      if ((DAT_008019a6 & 3) == 1) {
        if ((_DAT_0080cffc == 1) && (_DAT_0080cffa == 1)) {
          _DAT_0080d000 = 1;
          _DAT_0080d02e = _DAT_008086e4 + 1;
        }
      }
      else if ((DAT_008019a6 & 3) != 3) {
        _DAT_0080d000 = 0;
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
// Function: FUN_00027514 @ 0x00027514
//

void FUN_00027514(void)

{
  FUN_0001b1b4();
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
    if (_DAT_0080cffc == 0) {
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
          if (_DAT_0080cffc != 3) {
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
      _DAT_0080cffc = 0;
      _DAT_0080cffa = 0;
      _DAT_0080d00c = 0;
      return;
    case 1:
      _DAT_0080d028 = *(short *)(_DAT_0080d01e + 4) + 1;
      _DAT_0080cffc = 1;
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
      _DAT_0080cffc = 2;
      uVar7 = FUN_00010d78(CONCAT22(CONCAT11((char)((ushort)_DAT_0080d028 >> 8),
                                             *(undefined1 *)(param_1 + 3)),uVar8));
      _DAT_0080cffa = (short)uVar7;
      _DAT_0080d00c = 0;
      DAT_008019b6 = DAT_008019ad;
      _DAT_0080d008 = (ushort)DAT_008019ad * 0x100 + -32000;
      _DAT_0080d010 =
           param_ref_base.base_reference +
           (short)(((int)_DAT_0080d008 *
                   ((int)(short)param_scale_factor - (int)(short)param_ref_base.base_reference)) /
                  0x6400);
      if (_DAT_0080d010 < 0) {
        _DAT_0080d010 = 0;
        return;
      }
      return;
    case 3:
      _DAT_0080d028 = *(short *)(_DAT_0080d01e + 0xc) + 1;
      _DAT_0080cffc = 3;
      uVar7 = FUN_00010d78(CONCAT22(CONCAT11((char)((ushort)_DAT_0080d028 >> 8),
                                             *(undefined1 *)(param_1 + 3)),uVar8));
      _DAT_0080cffa = (undefined2)uVar7;
      _DAT_0080d00c = 0;
      _DAT_008019b4 = CONCAT11(DAT_008019ab,DAT_008019ac);
      _DAT_0080d006 = _DAT_008019b4;
      DAT_008019b6 = DAT_008019ad;
      _DAT_0080d00e =
           param_ref_base.base_reference +
           (short)(((int)(short)((ushort)DAT_008019ad * 0x100 + -32000) *
                   ((int)(short)param_scale_factor - (int)(short)param_ref_base.base_reference)) /
                  0x6400);
      if (_DAT_0080d00e < 0) {
        _DAT_0080d00e = 0;
        return;
      }
    }
  }
  return;
}



//
// Function: FUN_0002787e @ 0x0002787e
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
// Function: FUN_0002793e @ 0x0002793e
//

void FUN_0002793e(void)

{
  FUN_0001b1b4();
  FUN_00029868();
  FUN_0002aa74();
  FUN_0002ac7a();
  FUN_0002ae60();
  FUN_0002b29e();
  FUN_0002b3fc();
  FUN_0002787e();
  FUN_0002787e();
  FUN_0002787e();
  FUN_0002787e();
  FUN_0002787e();
  FUN_0002787e();
  FUN_00029a86();
  FUN_00029bf4();
  FUN_0002732e();
  FUN_0002a090();
  FUN_0002a1a0();
  FUN_0002a29c();
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
    _DAT_00801a60 = current_engine_param;
    uVar3 = FUN_00035560((short *)&DAT_00801a5a);
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
  _DAT_00801a48 = current_engine_param;
  uVar2 = FUN_00035560((short *)&DAT_00801a42);
  uVar3 = (ushort)(((uint)param_1._0_2_ * (uint)_DAT_00807978) / 0x6400);
  if (uVar3 < uVar2) {
    return 1;
  }
  _DAT_00801a54 = current_engine_param;
  uVar2 = FUN_00035560((short *)&DAT_00801a4e);
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
        _DAT_0080cfb2 = 3;
        _DAT_0080cffe = 0;
        return;
      }
      if (bVar3 == 2) {
        sVar8 = FUN_00027aca((uint)CONCAT12(DAT_00801a3d,uVar7));
        _DAT_0080cfb4 = sVar8;
        if (((((_DAT_008035d8 & 0x1000) == 0) || (bVar1 != _DAT_008084a4)) || (_DAT_0080cffc != 1))
           || (((_DAT_0080cffa != 1 || (cached_parameter_value < _DAT_0080894c)) || (sVar8 == 0))))
        {
          _DAT_0080d02c = *(short *)(_DAT_0080d022 + 0xe) + 1;
          _DAT_0080cfa8 = 2;
          uVar10 = CONCAT11((char)((ushort)_DAT_0080d02c >> 8),*(undefined1 *)(param_1 + 3));
          uVar5 = FUN_00010d78(CONCAT22(uVar10,uVar7));
          _DAT_0080cfaa = (undefined2)uVar5;
          _DAT_0080cfb2 = 3;
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
          _DAT_0080cfb2 = 3;
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
      _DAT_0080cfb2 = (ushort)uVar4 & 0xff;
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
// Function: FUN_00027dd4 @ 0x00027dd4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00027dd4(void)

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
// Function: FUN_00027e3e @ 0x00027e3e
//

void FUN_00027e3e(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 2);
  if ((cVar1 != DAT_0080cfc3) && (cVar1 != -1)) {
    if ((cVar1 == DAT_0080cfcd) || (cVar1 == -1)) {
      FUN_00027afa(param_1);
    }
    return;
  }
  FUN_00027528(param_1);
  return;
}



//
// Function: FUN_00027e86 @ 0x00027e86
//

void FUN_00027e86(void)

{
  FUN_0001b1b4();
  return;
}



//
// Function: FUN_00027e98 @ 0x00027e98
//

undefined1 FUN_00027e98(void)

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
  *(undefined4 *)(sVar1 + 0x804fc8) = 0;
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
    *(undefined2 *)(sVar1 + 0x805a3a) = _DAT_0080c406;
    *(undefined2 *)(sVar1 + 0x805a40) = _DAT_00809d4c;
    *(undefined2 *)(&DAT_00805a42 + sVar1) = _DAT_00809258;
    *(undefined4 *)(sVar1 + 0x805a32) = _DAT_0080d4c4;
    *(undefined2 *)(&DAT_00805a44 + sVar1) = _DAT_0080926e;
    *(undefined2 *)(sVar1 + 0x805a46) = _DAT_008091ea;
    *(undefined2 *)(sVar1 + 0x805a48) = _DAT_00809242;
    *(undefined2 *)(sVar1 + 0x805a3c) = _DAT_0080bdc0;
    *(undefined2 *)(sVar1 + 0x805a4a) = _DAT_0080bdc2;
    *(undefined4 *)(sVar1 + 0x805a4c) = _DAT_00809688;
    *(undefined2 *)(sVar1 + 0x805a50) = _DAT_0080c9a6;
    *(undefined2 *)(sVar1 + 0x805a52) = _DAT_00809308;
    *(undefined2 *)(sVar1 + 0x805a54) = _DAT_0080c9a4;
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
    *(undefined2 *)(sVar1 + 0x80567a) = _DAT_0080c406;
    *(undefined2 *)(sVar1 + 0x805680) = _DAT_00809d4c;
    *(undefined2 *)(sVar1 + 0x805682) = _DAT_00809258;
    *(undefined4 *)(sVar1 + 0x805672) = _DAT_0080d4c4;
    *(undefined2 *)(sVar1 + 0x805684) = _DAT_0080926e;
    *(undefined2 *)(sVar1 + 0x805686) = _DAT_008091ea;
    *(undefined2 *)(sVar1 + 0x805688) = _DAT_00809242;
    *(undefined2 *)(sVar1 + 0x80567c) = _DAT_0080bdc0;
    *(undefined2 *)(sVar1 + 0x80568a) = _DAT_0080bdc2;
    *(undefined4 *)(sVar1 + 0x80568c) = _DAT_00809688;
    *(undefined2 *)(sVar1 + 0x805690) = _DAT_0080c9a6;
    *(undefined2 *)(sVar1 + 0x805692) = _DAT_00809308;
    *(undefined2 *)(sVar1 + 0x805694) = _DAT_0080c9a4;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000281e8(void)

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
    _DAT_00fff45a = 0xfcbe;
    _DAT_00fff458 = _DAT_00fff458 & 0x7fff | 0x4000;
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
  
  uVar3 = current_engine_param;
  if (_DAT_0080d460 == 1) {
    uVar3 = _DAT_0080d45e;
  }
  if ((uVar3 != 0) && (uVar3 < _DAT_00801a66)) {
    uVar3 = _DAT_00801a66;
  }
  if ((uVar3 == 0) || (0x10c5 < _DAT_00808a4e)) {
    _DAT_0080d462 = 0x4230bdc0;
    local_8 = FUN_000357d2(16000000,0x4230bdc0,32000000);
    local_8 = local_8 & 0xffff;
  }
  else {
    _DAT_0080d462 = ((uint)_DAT_00808a4e * 1000000) / (uint)uVar3;
    uVar2 = FUN_000357d2(16000000,_DAT_0080d462,32000000);
    local_8 = uVar2 & 0xffff;
    uVar1 = local_8;
    local_8 = CONCAT22((short)((int)uVar1 >> 1),(short)uVar2);
  }
  register_map[0xc4] = local_8._0_1_;
  register_map[0xc5] = local_8._1_1_;
  register_map[0xc6] = local_8._2_1_;
  register_map[199] = (undefined1)local_8;
  return;
}



//
// Function: FUN_000284aa @ 0x000284aa
//

/* WARNING: Removing unreachable block (ram,0x00028528) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000284aa(void)

{
  ushort uVar1;
  
  uVar1 = stack_area._10_2_ & 0xefff;
  stack_area[10] = (char)(uVar1 >> 8);
  stack_area[0xb] = (char)uVar1;
  uVar1 = stack_area._32_2_ & 0xefff;
  stack_area[0x20] = (char)(uVar1 >> 8);
  stack_area[0x21] = (char)uVar1;
  uVar1 = stack_area._12_2_ & 0xfff0 | 0xb;
  stack_area[0xc] = (char)(uVar1 >> 8);
  stack_area[0xd] = (char)uVar1;
  register_map[0xc0] = 0;
  register_map[0xc1] = 0x92;
  register_map[0xc4] = 0;
  register_map[0xc5] = 0;
  register_map[0xc6] = 0xff;
  register_map[199] = 0xff;
  uVar1 = stack_area._24_2_ & 0xfcff | 0x200;
  stack_area[0x18] = (char)(uVar1 >> 8);
  stack_area[0x19] = (char)uVar1;
  uVar1 = stack_area._28_2_ & 0xfcff | 0x100;
  stack_area[0x1c] = (char)(uVar1 >> 8);
  stack_area[0x1d] = (char)uVar1;
  _DAT_00801a66 = (ushort)((int)((uint)_DAT_00808a4e * 0x1e84) >> 10);
  if (_DAT_00801a66 < _DAT_00808a50) {
    _DAT_00801a66 = _DAT_00808a50;
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
  
  if (_DAT_0080c406 != 0) {
    if (_DAT_00805f8a < _DAT_0080c406) {
      _DAT_00805f8a = _DAT_0080c406;
    }
    if ((_DAT_0080c406 < _DAT_00803818) || (_DAT_00808a66 == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = (short)((int)((uint)_DAT_0080c406 - (uint)_DAT_00803818) / (int)(uint)_DAT_00808a66) +
              1;
      if (0x18 < uVar1) {
        uVar1 = 0x18;
      }
    }
    *(int *)(&DAT_00805eb4 + (short)uVar1 * 4) = *(int *)(&DAT_00805eb4 + (short)uVar1 * 4) + 1;
  }
  DAT_00801a84 = DAT_00801a84 + '\x01';
  if (DAT_00801a84 == '\n') {
    DAT_00801a84 = '\0';
    if (_DAT_0080c406 != 0) {
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
      if (_DAT_00808a62 < _DAT_0080c406) {
        _DAT_00801a7a = _DAT_00808a64;
      }
      if (_DAT_00808a5c < _DAT_00801a74) {
        _DAT_00801a7c = _DAT_00808a60;
      }
    }
  }
  if (((_DAT_0080c810 == 8) && (_DAT_00801a7e != 8)) &&
     ((_DAT_00801a7a != 0 || _DAT_00801a78 != 0 || (_DAT_00801a7c != 0)))) {
    _DAT_00805f88 = _DAT_00805f88 + 1;
    _DAT_00801a78 = 0;
    _DAT_00801a7a = 0;
    _DAT_00801a7c = 0;
  }
  _DAT_00801a7e = _DAT_0080c810;
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
  uVar3 = _DAT_008035da & 0x200;
  if (uVar3 != 0) {
    if (_DAT_0080c406 == 0) {
      _DAT_0080d47a = 0;
    }
    else if ((_DAT_0080c9a6 == 0xb) && (_DAT_008096a6 == 0)) {
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
        else if (_DAT_00808a54 < _DAT_00801a68) {
          _DAT_00805f40 = _DAT_00805f40 | 0x41;
        }
        else {
          _DAT_00801a68 = _DAT_00801a68 + 1;
        }
      }
      if (_DAT_0080d47a == 3) {
        FUN_00028548((uint *)&DAT_00805f18,(uint *)&DAT_00805f30);
      }
      else if (_DAT_0080d47a == 1) {
        FUN_00028588();
      }
      else if (_DAT_0080d47a == 2) {
        FUN_000285c8();
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
  if ((_DAT_008035da & 0x200) != 0) {
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
  return _DAT_008035da & 0x200;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002939c(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((stack_area._0_2_ & 0x400) != 0x400) {
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
    stack_area[0] = 4;
    stack_area[1] = 7;
    stack_area[10] = 0;
    stack_area[0xb] = 0;
    stack_area[8] = 4;
    stack_area[9] = 0x40;
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
  byte *pbVar2;
  
  pbVar2 = &param_ref_base.config_byte;
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
  _DAT_00801a86 = CONCAT13((char)((_DAT_008037b6 & 7) << 2),0xe8ff00);
  _DAT_00801a88 = CONCAT11(*(undefined1 *)(param_1 + 3),*(undefined1 *)(param_1 + 2));
  DAT_00801a94 = (undefined1)((uint)param_2 >> 0x10);
  DAT_00801a99 = **(undefined1 **)(param_1 + 6);
  DAT_00801a9a = *(undefined1 *)(*(int *)(param_1 + 6) + 1);
  DAT_00801a9b = *(undefined1 *)(*(int *)(param_1 + 6) + 2);
  sendJ1939Msg((undefined4 *)&DAT_00801a86);
  return;
}



//
// Function: FUN_000294ea @ 0x000294ea
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000294ea(void)

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
  sendJ1939Msg((undefined4 *)&DAT_00801a9e);
  return;
}



//
// Function: FUN_0002956a @ 0x0002956a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002956a(void)

{
  _DAT_00801a9e = CONCAT13((char)((_DAT_008037b8 & 7) << 2),0xfef500);
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
// Function: FUN_000295d4 @ 0x000295d4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000295d4(void)

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
  sendJ1939Msg((undefined4 *)&DAT_00801ab6);
  return;
}



//
// Function: FUN_00029796 @ 0x00029796
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00029796(void)

{
  _DAT_00801ab6 = CONCAT13((char)((_DAT_008037ba & 7) << 2),0xfef100);
  _DAT_00801ab6 = CONCAT31(_DAT_00801ab6,DAT_0080cfc3);
  _DAT_00801aba = 7;
  _DAT_00801abc = &DAT_00801ac4;
  _DAT_00801ac0 = 0x801acc;
  DAT_00801ac4 = 0xf3;
  DAT_00801acb = 0xff;
  FUN_0002787e();
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
  sendJ1939Msg((undefined4 *)&DAT_00801ace);
  return;
}



//
// Function: FUN_00029868 @ 0x00029868
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00029868(void)

{
  _DAT_00801ace = CONCAT13((char)((_DAT_008037bc & 7) << 2),0xfeeb00);
  _DAT_00801ad2 = 0x1c;
  _DAT_00801ad4 = &DAT_00801adc;
  _DAT_00801ad8 = 0x801af8;
  _DAT_00801ace = CONCAT31(_DAT_00801ace,DAT_0080cfc3);
  FUN_0002787e();
  return;
}



//
// Function: FUN_000298d8 @ 0x000298d8
//

byte * FUN_000298d8(byte *param_1,undefined4 param_2)

{
  undefined4 in_D0;
  undefined2 uVar2;
  byte bVar3;
  byte *pbVar1;
  undefined4 unaff_D2;
  char cVar4;
  byte bVar5;
  short sVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  
  uVar2 = (undefined2)CONCAT31((int3)((uint)in_D0 >> 8),**(undefined1 **)(param_1 + 6));
  bVar3 = FUN_0000a5e2(CONCAT22(uVar2,(short)((uint)unaff_D2 >> 0x10)));
  cVar4 = (char)((uint)param_2 >> 0x10);
  if (cVar4 == '\0') {
    sVar6 = bVar3 + 1;
  }
  else {
    sVar6 = bVar3 + 2;
  }
  pbVar1 = (byte *)FUN_0001cb18(CONCAT22(sVar6,uVar2));
  if (pbVar1 != (byte *)0x0) {
    pbVar1[0] = 0;
    pbVar1[1] = 0xef;
    pbVar1[2] = 0;
    pbVar1[3] = 0;
    bVar5 = *param_1;
    *pbVar1 = *pbVar1 & 0xe3;
    *pbVar1 = bVar5 & 0x1c | *pbVar1;
    pbVar1[2] = param_1[3];
    pbVar1[3] = param_1[2];
    puVar8 = *(undefined1 **)(pbVar1 + 6);
    if (cVar4 == '\0') {
      puVar7 = puVar8 + 1;
      *puVar8 = 0xc;
    }
    else {
      *puVar8 = 0xd;
      puVar7 = puVar8 + 2;
      puVar8[1] = (&LAB_000298be)[(short)(param_2._0_2_ & 0xff)];
    }
    puVar8 = *(undefined1 **)(param_1 + 6);
    for (bVar5 = 0; bVar5 < bVar3; bVar5 = bVar5 + 1) {
      *puVar7 = *puVar8;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    pbVar1 = (byte *)sendJ1939Msg((undefined4 *)pbVar1);
  }
  return pbVar1;
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
    bVar3 = sendJ1939Msg((undefined4 *)&DAT_00801afa);
  }
  return bVar3;
}



//
// Function: FUN_00029a86 @ 0x00029a86
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00029a86(void)

{
  _DAT_00801afa = CONCAT13((char)((_DAT_008037be & 7) << 2),0xfeca00);
  _DAT_00801b00 = &DAT_00801b08;
  _DAT_00801b04 = &DAT_008021fe;
  _DAT_00801afa = CONCAT31(_DAT_00801afa,DAT_0080cfc3);
  DAT_00801b09 = 0xff;
  DAT_00801b0d = DAT_00801b0d & 0x7f;
  FUN_0002787e();
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
    bVar3 = sendJ1939Msg((undefined4 *)&DAT_00802200);
  }
  return bVar3;
}



//
// Function: FUN_00029bf4 @ 0x00029bf4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00029bf4(void)

{
  _DAT_00802200 = CONCAT13((char)((_DAT_008037c0 & 7) << 2),0xfecb00);
  _DAT_00802206 = &DAT_0080220e;
  _DAT_0080220a = &DAT_00802904;
  _DAT_00802200 = CONCAT31(_DAT_00802200,DAT_0080cfc3);
  DAT_0080220f = 0xff;
  DAT_00802213 = DAT_00802213 & 0x7f;
  FUN_0002787e();
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
    bVar5 = sendJ1939Msg((undefined4 *)&DAT_00802906);
  }
  return bVar5;
}



//
// Function: FUN_0002a090 @ 0x0002a090
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002a090(void)

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
  FUN_0002787e();
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
  _can_tx_queue = FUN_0001bc52((undefined2 *)&DAT_008084ca);
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
  sendJ1939Msg((undefined4 *)&DAT_00802fee);
  return;
}



//
// Function: FUN_0002a1a0 @ 0x0002a1a0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002a1a0(void)

{
  _DAT_00802fee = CONCAT13((char)((_DAT_008037c4 & 7) << 2),0xfece00);
  _DAT_00802ff2 = 8;
  _DAT_00802ff4 = &DAT_00802ffc;
  _DAT_00802ff8 = 0x803004;
  _DAT_00802fee = CONCAT31(_DAT_00802fee,DAT_0080cfc3);
  FUN_0002787e();
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
  sendJ1939Msg((undefined4 *)&DAT_00803006);
  return;
}



//
// Function: FUN_0002a222 @ 0x0002a222
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002a222(void)

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
// Function: FUN_0002a29c @ 0x0002a29c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002a29c(void)

{
  _DAT_0080301e = CONCAT13((char)((_DAT_008037c8 & 7) << 2),0xfed200);
  _DAT_00803022 = 2;
  _DAT_00803024 = &DAT_0080302c;
  _DAT_00803028 = 0x803034;
  _DAT_0080301e = CONCAT31(_DAT_0080301e,DAT_0080cfc3);
  FUN_0002787e();
  return;
}



//
// Function: FUN_0002a2f2 @ 0x0002a2f2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002a2f2(void)

{
  undefined1 local_6;
  undefined1 uStack_5;
  
  if (_DAT_0080cffc == 0) {
    switch(_DAT_0080c9a6) {
    case 3:
    case 7:
    case 8:
      DAT_00803036 = 0xf1;
      break;
    case 4:
      DAT_00803036 = 0xf3;
      break;
    default:
      DAT_00803036 = 0xfe;
      break;
    case 9:
      DAT_00803036 = 0xf2;
      break;
    case 10:
      DAT_00803036 = 0xf4;
      break;
    case 0xb:
      DAT_00803036 = 0xf0;
      break;
    case 0xc:
      DAT_00803036 = 0xf9;
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
      DAT_00803036 = 0xf8;
      break;
    case 0x18:
      DAT_00803036 = 0xfa;
    }
  }
  else if (_DAT_0080cffa == 1) {
    DAT_00803036 = 0xf6;
  }
  else if (_DAT_0080cffa == 3) {
    DAT_00803036 = 0xf5;
  }
  else if (_DAT_0080cffa == 2) {
    DAT_00803036 = 0xf7;
  }
  else {
    DAT_00803036 = 0xfe;
  }
  param_system_update();
                    /* Constant: CAN_PARAM_OFFSET = 0x7d */
  DAT_00803037 = (char)(param_table_main.calculated_2 >> 8) + '}';
  param_lookup_1();
  DAT_00803038 = (char)(param_table_main.calculated_1 >> 8) + '}';
  uStack_5 = (undefined1)current_engine_param;
  DAT_00803039 = uStack_5;
  local_6 = (undefined1)(current_engine_param >> 8);
  DAT_0080303a = local_6;
  sendJ1939Msg((undefined4 *)&can_param_msg_buf_4);
  return;
}



//
// Function: engineParamCanBuilder @ 0x0002a418
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void engineParamCanBuilder(void)

{
  _can_param_msg_buf_4 = CONCAT13((char)((_DAT_008037ca & 7) << 2),0xf00400);
  _can_param_msg_buf_4 = CONCAT31(_can_param_msg_buf_4,DAT_0080cfc3);
  _DAT_00803042 = 5;
  _DAT_00803044 = &DAT_00803036;
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
  
  if (((_DAT_00805dfa & 0x20) == 0) || ((_DAT_008068cc & 0x20) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if (((_DAT_00805dfa & 8) == 0) || ((_DAT_008068cc & 8) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (_reference_table_array < _DAT_00809d4c) {
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
  DAT_00803050 = (undefined1)(param_table_main.calculated_3 >> 8);
  sendJ1939Msg((undefined4 *)&can_param_msg_buf_2);
  return;
}



//
// Function: FUN_0002a51e @ 0x0002a51e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002a51e(void)

{
  _can_param_msg_buf_2 = CONCAT13((char)((_DAT_008037cc & 7) << 2),0xf00300);
  _can_param_msg_buf_2 = CONCAT31(_can_param_msg_buf_2,DAT_0080cfc3);
  _DAT_0080305a = 3;
  _DAT_0080305c = &DAT_0080304e;
  _DAT_00803060 = 0x803064;
  FUN_0000d71a();
  FUN_0002787e();
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
  can_param_msg_buf_1 = (char)(param_table_main.calculated_4 >> 8) + 0x7d;
  uStack_5 = (undefined1)param_limit_value;
  DAT_00803067 = uStack_5;
  local_6 = (undefined1)(param_limit_value >> 8);
  DAT_00803068 = local_6;
  DAT_00803069 = param_config_byte;
  sendJ1939Msg((undefined4 *)&can_param_msg_buf_3);
  return;
}



//
// Function: FUN_0002a5da @ 0x0002a5da
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002a5da(void)

{
  _can_param_msg_buf_3 = CONCAT13((char)((_DAT_008037ce & 7) << 2),0xfedf00);
  _can_param_msg_buf_3 = CONCAT31(_can_param_msg_buf_3,DAT_0080cfc3);
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
    DAT_00803080 = (char)(param_table_main.param_table_1 >> 8) + '}';
    local_6._1_1_ = (undefined1)_DAT_0080cfe8;
    DAT_00803081 = (undefined1)local_6;
    local_6._0_1_ = (undefined1)((ushort)_DAT_0080cfe8 >> 8);
    DAT_00803082 = local_6._0_1_;
    DAT_00803083 = (char)(param_table_main.param_table_2 >> 8) + '}';
    local_6._1_1_ = (undefined1)_DAT_008086c6;
    DAT_00803084 = (undefined1)local_6;
    local_6._0_1_ = (undefined1)((ushort)_DAT_008086c6 >> 8);
    DAT_00803085 = local_6._0_1_;
    DAT_00803086 = (char)(param_table_main.param_table_3 >> 8) + '}';
    local_6._1_1_ = (undefined1)_DAT_008086c8;
    DAT_00803087 = (undefined1)local_6;
    local_6._0_1_ = (undefined1)((ushort)_DAT_008086c8 >> 8);
    DAT_00803088 = local_6._0_1_;
    DAT_00803089 = (char)(param_table_main.param_table_4 >> 8) + '}';
    local_6._1_1_ = (undefined1)_DAT_0080cfea;
    DAT_0080308a = (undefined1)local_6;
    local_6._0_1_ = (undefined1)((ushort)_DAT_0080cfea >> 8);
    DAT_0080308b = local_6._0_1_;
    DAT_0080308c = (char)(param_table_main.result_buffer >> 8) + '}';
    if (_DAT_0080cc58 == 0) {
      local_6 = _DAT_0080cc4e;
    }
    else {
      local_6 = (short)(((uint)_DAT_0080cc58 *
                        ((uint)_DAT_0080cc56 - (uint)param_ref_base.base_reference)) / 0x1111) -
                (_DAT_0080cc54 - _DAT_0080cc4e);
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
    uVar2 = param_table_main.param_table_1;
    for (pwVar3 = &param_table_main.param_table_2;
        pwVar3 < (ushort *)((int)&param_table_main.result_buffer + 1); pwVar3 = pwVar3 + 1) {
      if (uVar2 < *pwVar3) {
        uVar2 = *pwVar3;
      }
    }
    DAT_00803099 = (char)(uVar2 >> 8) + '}';
    bVar1 = sendJ1939Msg((undefined4 *)&DAT_0080309a);
  }
  return bVar1;
}



//
// Function: FUN_0002a7f8 @ 0x0002a7f8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002a7f8(void)

{
  _DAT_0080309a = CONCAT13((char)((_DAT_008037d0 & 7) << 2),0xfee300);
  _DAT_0080309a = CONCAT31(_DAT_0080309a,DAT_0080cfc3);
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
  DAT_008030be = (undefined1)((int)((uint)(((int)(uint)_DAT_008092b0 >> 7) * 0x1afa) / 1000) >> 1);
  DAT_008030bb = (undefined1)((int)((uint)(((int)(uint)_DAT_00809242 >> 7) * 0x1afa) / 1000) >> 2);
  sendJ1939Msg((undefined4 *)&DAT_008030aa);
  return;
}



//
// Function: FUN_0002a8da @ 0x0002a8da
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002a8da(void)

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
// Function: FUN_0002a93a @ 0x0002a93a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002a93a(void)

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
    _DAT_008030d2 = FUN_0001bc52(&local_6);
  }
  else {
    local_6 = -0x500;
    _DAT_008030d2 = FUN_0001bc52(&local_6);
  }
  sendJ1939Msg((undefined4 *)&DAT_008030c2);
  return;
}



//
// Function: FUN_0002aa74 @ 0x0002aa74
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002aa74(void)

{
  _DAT_008030c2 = CONCAT13((char)((_DAT_008037d8 & 7) << 2),0xfeee00);
  _DAT_008030c6 = 8;
  _DAT_008030c8 = &DAT_008030d0;
  _DAT_008030cc = 0x8030d8;
  _DAT_008030c2 = CONCAT31(_DAT_008030c2,DAT_0080cfc3);
  _DAT_008030d4 = 0xffff;
  DAT_008030d6 = 0xff;
  DAT_008030d7 = 0xff;
  FUN_0002787e();
  return;
}



//
// Function: FUN_0002aade @ 0x0002aade
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002aade(void)

{
  if ((_DAT_008035d8 & 0x1000) == 0) {
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
    FUN_0000dc28();
    DAT_008030db = '}' - (char)((ushort)_DAT_00809d40 >> 8);
  }
  sendJ1939Msg((undefined4 *)&DAT_008030e2);
  return;
}



//
// Function: FUN_0002aba4 @ 0x0002aba4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002aba4(void)

{
  _DAT_008030e2 = CONCAT13((char)((_DAT_008037d6 & 7) << 2),0xf00000);
  _DAT_008030e2 = CONCAT31(_DAT_008030e2,DAT_0080cfcd);
  FUN_0000dd72();
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
  
  local_8 = FUN_000357d2(_DAT_00804bbc,0x39c2c3,1000000);
  local_8 = FUN_000357d2(local_8,2,8);
  _DAT_00803100 = FUN_0001bc1e(&local_8);
  local_8 = _DAT_00804bb8 >> 2;
  local_8 = FUN_000357d2(local_8,0x39c2c3,1000000);
  _DAT_00803104 = FUN_0001bc1e(&local_8);
  sendJ1939Msg((undefined4 *)&DAT_008030f2);
  return;
}



//
// Function: FUN_0002ac7a @ 0x0002ac7a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002ac7a(void)

{
  _DAT_008030f2 = CONCAT13((char)((_DAT_008037da & 7) << 2),0xfee900);
  _DAT_008030f6 = 8;
  _DAT_008030f8 = &DAT_00803100;
  _DAT_008030fc = 0x803108;
  _DAT_008030f2 = CONCAT31(_DAT_008030f2,DAT_0080cfc3);
  FUN_0002787e();
  return;
}



//
// Function: FUN_0002acd0 @ 0x0002acd0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002acd0(void)

{
  uint uVar1;
  short sVar2;
  undefined1 local_6;
  undefined1 uStack_5;
  
  uVar1 = FUN_000357d2((uint)_DAT_0080d478,0xe10,8000);
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
  sendJ1939Msg((undefined4 *)&DAT_00803114);
  return;
}



//
// Function: FUN_0002ada8 @ 0x0002ada8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002ada8(void)

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
  local_8 = FUN_000357d2(local_8,0x39c2c3,1000000);
  _DAT_00803136 = FUN_0001bc1e(&local_8);
  local_8 = FUN_000357d2(_DAT_00804bcc,0x14,0x40);
  _DAT_0080313a = FUN_0001bc1e(&local_8);
  sendJ1939Msg((undefined4 *)&DAT_00803128);
  return;
}



//
// Function: FUN_0002ae60 @ 0x0002ae60
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002ae60(void)

{
  _DAT_00803128 = CONCAT13((char)((_DAT_008037de & 7) << 2),0xfedc00);
  _DAT_0080312c = 8;
  _DAT_0080312e = &DAT_00803136;
  _DAT_00803132 = 0x80313e;
  _DAT_00803128 = CONCAT31(_DAT_00803128,DAT_0080cfc3);
  FUN_0002787e();
  return;
}



//
// Function: FUN_0002aee2 @ 0x0002aee2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002aee2(void)

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
  sendJ1939Msg((undefined4 *)&DAT_00803158);
  return;
}



//
// Function: FUN_0002afca @ 0x0002afca
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002afca(void)

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
// Function: FUN_0002b060 @ 0x0002b060
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b060(void)

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
// Function: FUN_0002b0cc @ 0x0002b0cc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte FUN_0002b0cc(void)

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
    bVar1 = sendJ1939Msg((undefined4 *)&DAT_0080319a);
  }
  return bVar1;
}



//
// Function: FUN_0002b1f6 @ 0x0002b1f6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b1f6(void)

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
  
  local_8 = FUN_000357d2(_DAT_00804bc4,0x3268,10000);
  _DAT_008031b8 = FUN_0001bc1e(&local_8);
  local_8 = FUN_000357d2(_DAT_00804bc0,0x3268,10000);
  _DAT_008031bc = FUN_0001bc1e(&local_8);
  sendJ1939Msg((undefined4 *)&DAT_008031aa);
  return;
}



//
// Function: FUN_0002b29e @ 0x0002b29e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b29e(void)

{
  _DAT_008031aa = CONCAT13((char)((_DAT_008037ea & 7) << 2),0xfee000);
  _DAT_008031ae = 8;
  _DAT_008031b0 = &DAT_008031b8;
  _DAT_008031b4 = 0x8031c0;
  _DAT_008031aa = CONCAT31(_DAT_008031aa,DAT_0080cfc3);
  FUN_0002787e();
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
  sendJ1939Msg((undefined4 *)&DAT_008031c2);
  return;
}



//
// Function: FUN_0002b338 @ 0x0002b338
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b338(void)

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
  
  local_8 = FUN_000357d2(_DAT_00804bd8,0x14,0x40);
  _DAT_008031e8 = FUN_0001bc1e(&local_8);
  local_8 = FUN_000357d2(_DAT_00804bd4,0x14,0x40);
  _DAT_008031ec = FUN_0001bc1e(&local_8);
  sendJ1939Msg((undefined4 *)&DAT_008031da);
  return;
}



//
// Function: FUN_0002b3fc @ 0x0002b3fc
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b3fc(void)

{
  _DAT_008031da = CONCAT13((char)((_DAT_008037ee & 7) << 2),0xfee700);
  _DAT_008031de = 8;
  _DAT_008031e0 = &DAT_008031e8;
  _DAT_008031e4 = 0x8031f0;
  _DAT_008031da = CONCAT31(_DAT_008031da,DAT_0080cfc3);
  FUN_0002787e();
  return;
}



//
// Function: FUN_0002b452 @ 0x0002b452
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b452(void)

{
  _DAT_0080d4c4 = _DAT_0080d4c4 + 1;
  if (_DAT_0080c810 != 1) {
    _DAT_00809688 = _DAT_00809688 + 1;
  }
  return;
}



//
// Function: FUN_0002b46a @ 0x0002b46a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b46a(void)

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
  if ((diagnostic_status_register == 0) && (_DAT_0080cffc == 2)) {
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
// Function: FUN_0002b4c2 @ 0x0002b4c2
//

void FUN_0002b4c2(void)

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
// Function: FUN_0002b544 @ 0x0002b544
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0002b544(uint param_1,uint param_2)

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
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  
  if (DAT_00807cf7 == '\0') {
    uVar1 = stack_area._32_2_ & 0xfffe;
    _DAT_00808ec2 = &LAB_00015946;
    uVar2 = stack_area._18_2_ & 0xfff0 | 0xc;
    stack_area[0x12] = (char)(uVar2 >> 8);
    stack_area[0x13] = (char)uVar2;
    register_map._4_2_ = _DAT_00807cd6 / 6;
    register_map[2] = 0;
    register_map[3] = 0xe;
    register_map[0] = 0;
    register_map[1] = 0xb;
    uVar2 = stack_area._22_2_ & 0xfffc | 1;
    stack_area[0x16] = (char)(uVar2 >> 8);
    stack_area[0x17] = (char)uVar2;
    uVar2 = stack_area._26_2_ & 0xfffc | 1;
    stack_area[0x1a] = (char)(uVar2 >> 8);
    stack_area[0x1b] = (char)uVar2;
    uVar2 = stack_area._30_2_ & 0xfffc | 2;
    stack_area[0x1e] = (char)(uVar2 >> 8);
    stack_area[0x1f] = (char)uVar2;
    uVar2 = stack_area._10_2_ & 0xfffe | 1;
    stack_area[10] = (char)(uVar2 >> 8);
    stack_area[0xb] = (char)uVar2;
    stack_area[0x20] = (char)(uVar1 >> 8);
    stack_area[0x21] = (char)uVar1;
    return;
  }
  if (DAT_00807cf7 != '\x01') {
    return;
  }
  DAT_0080d49e = DAT_00808a78 + -1;
  iVar3 = 0;
  iVar4 = 0;
  uVar5 = (uint)DAT_00807cfc;
  piVar6 = (int *)&DAT_0080d4a8;
  do {
    *piVar6 = iVar4 / 6;
    iVar4 = uVar5 * 0x10000 + iVar4;
    iVar3 = iVar3 + 1;
    piVar6 = piVar6 + 1;
  } while (iVar3 < 6);
  _DAT_0080d4a4 = (uint)DAT_00807cfc << 0x10;
  FUN_0002b880();
  return;
}



//
// Function: FUN_0002b6c2 @ 0x0002b6c2
//

void FUN_0002b6c2(void)

{
  if (DAT_00807cf7 == '\0') {
    stack_area._32_2_ = stack_area._32_2_ & 0xfffe;
    stack_area._18_2_ = stack_area._18_2_ & 0xfff0 | 0xc;
    register_map[4] = 0;
    register_map[5] = 1;
    register_map[2] = 0;
    register_map[3] = 0xe;
    register_map[0] = 0;
    register_map[1] = 0xb;
    stack_area._22_2_ = stack_area._22_2_ & 0xfffc | 1;
    stack_area._26_2_ = stack_area._26_2_ & 0xfffc | 1;
    stack_area._10_2_ = stack_area._10_2_ & 0xfffe | 1;
    stack_area._30_2_ = stack_area._30_2_ & 0xfffc | 2;
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
  ushort uVar4;
  ushort uVar5;
  
  DAT_0080d49e = DAT_00808a78 - 1U;
  iVar1 = _DAT_0080d4a4 +
          _DAT_00808a7a +
          _DAT_00807cf8 + *(int *)(&DAT_0080d4a8 + (short)(ushort)(byte)(DAT_00808a78 - 1U) * 4) +
          0x100;
  uVar3 = (iVar1 >> 0x10 & 0xffffU) % (DAT_00807d02 + 2);
  uVar4 = (ushort)uVar3;
  uVar2 = (ushort)(iVar1 >> 1) & 0x7f00;
  if (uVar3 == DAT_00807d02 + 1) {
    uVar4 = uVar4 - 1 | uVar2 | 0x8000;
  }
  else {
    uVar4 = uVar4 | uVar2;
  }
  uVar3 = (_DAT_00808a7e + iVar1 >> 0x10 & 0xffffU) % (DAT_00807d02 + 2);
  uVar5 = (ushort)uVar3;
  uVar2 = (ushort)(_DAT_00808a7e + iVar1 >> 1) & 0x7f00;
  if (DAT_00807d02 + 1 == uVar3) {
    uVar5 = uVar5 - 1 | uVar2 | 0x8000;
  }
  else {
    uVar5 = uVar5 | uVar2;
  }
  uVar2 = stack_area._32_2_ & 0xfff7;
  stack_area[0x20] = (char)(uVar2 >> 8);
  stack_area[0x21] = (char)uVar2;
  uVar2 = stack_area._18_2_ & 0xfff | 0x8000;
  stack_area[0x12] = (char)(uVar2 >> 8);
  stack_area[0x13] = (char)uVar2;
  register_map[0x30] = 8;
  register_map[0x31] = 0x80;
  register_map[0x38] = (char)(uVar4 >> 8);
  register_map[0x39] = (char)uVar4;
  register_map[0x3a] = (char)(uVar5 >> 8);
  register_map[0x3b] = (char)uVar5;
  uVar2 = stack_area._22_2_ & 0xff3f;
  stack_area[0x16] = (char)(uVar2 >> 8);
  stack_area[0x17] = (char)uVar2;
  uVar2 = stack_area._26_2_ & 0xff3f | 0x80;
  stack_area[0x1a] = (char)(uVar2 >> 8);
  stack_area[0x1b] = (char)uVar2;
  uVar2 = stack_area._30_2_ & 0xff3f | 0x40;
  stack_area[0x1e] = (char)(uVar2 >> 8);
  stack_area[0x1f] = (char)uVar2;
  uVar2 = stack_area._10_2_ & 0xfff7 | 8;
  stack_area[10] = (char)(uVar2 >> 8);
  stack_area[0xb] = (char)uVar2;
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
  ushort uVar4;
  ushort uVar5;
  
  iVar1 = _DAT_0080d4a4 +
          _DAT_00808a7a + _DAT_00807cf8 + *(int *)(&DAT_0080d4a8 + (short)(ushort)DAT_0080d49e * 4)
          + 0x100;
  uVar3 = (iVar1 >> 0x10 & 0xffffU) % (DAT_00807d02 + 2);
  uVar4 = (ushort)uVar3;
  uVar2 = (ushort)(iVar1 >> 1) & 0x7f00;
  if (uVar3 == DAT_00807d02 + 1) {
    uVar4 = uVar4 - 1 | uVar2 | 0x8000;
  }
  else {
    uVar4 = uVar4 | uVar2;
  }
  uVar3 = (_DAT_00808a7e + iVar1 >> 0x10 & 0xffffU) % (DAT_00807d02 + 2);
  uVar5 = (ushort)uVar3;
  uVar2 = (ushort)(_DAT_00808a7e + iVar1 >> 1) & 0x7f00;
  if (DAT_00807d02 + 1 == uVar3) {
    uVar5 = uVar5 - 1 | uVar2 | 0x8000;
  }
  else {
    uVar5 = uVar5 | uVar2;
  }
  uVar2 = stack_area._32_2_ & 0xfff7;
  stack_area[0x20] = (char)(uVar2 >> 8);
  stack_area[0x21] = (char)uVar2;
  uVar2 = stack_area._18_2_ & 0xfff | 0x8000;
  stack_area[0x12] = (char)(uVar2 >> 8);
  stack_area[0x13] = (char)uVar2;
  register_map[0x30] = 8;
  register_map[0x31] = 0x80;
  register_map[0x38] = (char)(uVar4 >> 8);
  register_map[0x39] = (char)uVar4;
  register_map[0x3a] = (char)(uVar5 >> 8);
  register_map[0x3b] = (char)uVar5;
  uVar2 = stack_area._22_2_ & 0xff3f;
  stack_area[0x16] = (char)(uVar2 >> 8);
  stack_area[0x17] = (char)uVar2;
  uVar2 = stack_area._26_2_ & 0xff3f | 0x80;
  stack_area[0x1a] = (char)(uVar2 >> 8);
  stack_area[0x1b] = (char)uVar2;
  uVar2 = stack_area._30_2_ & 0xff3f | 0x40;
  stack_area[0x1e] = (char)(uVar2 >> 8);
  stack_area[0x1f] = (char)uVar2;
  _DAT_00808ece = FUN_0002ba56;
  uVar2 = stack_area._10_2_ & 0xfff7 | 8;
  stack_area[10] = (char)(uVar2 >> 8);
  stack_area[0xb] = (char)uVar2;
  return;
}



//
// Function: FUN_0002b9b8 @ 0x0002b9b8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002b9b8(void)

{
  if (DAT_00807cf7 == '\0') {
    register_map._4_2_ = _DAT_00807cd6 / 6;
    stack_area._10_2_ = stack_area._10_2_ & 0xfff7;
    stack_area._32_2_ = stack_area._32_2_ & 0xfff7;
    stack_area._18_2_ = stack_area._18_2_ & 0xfff | 0xa000;
    register_map[0x34] = 0;
    register_map[0x35] = 0;
    register_map[0x36] = 0;
    register_map[0x37] = 0;
    register_map[0x38] = 0;
    register_map[0x39] = 0;
    register_map[0x3a] = 1;
    register_map[0x3b] = 0x9b;
    register_map[0x30] = 0;
    register_map[0x31] = 0x8e;
    stack_area._22_2_ = stack_area._22_2_ & 0xff3f;
    stack_area._26_2_ = stack_area._26_2_ & 0xff3f | 0x80;
    stack_area._30_2_ = stack_area._30_2_ & 0xff3f | 0x40;
  }
  if ((DAT_0080c79b != '\0') && (DAT_00807cf7 == '\x01')) {
    FUN_0002b744();
  }
  return;
}



//
// Function: FUN_0002ba56 @ 0x0002ba56
//

undefined8 FUN_0002ba56(void)

{
  ushort uVar1;
  undefined4 in_D0;
  undefined4 in_D1;
  uint uVar2;
  
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
  uVar2 = (DAT_0080d49e + 1) % 6;
  DAT_0080d49e = (byte)uVar2;
  DAT_00809af1 = (char)((DAT_00808a79 + uVar2) % 6) + '\x01';
  FUN_0002b880();
  uVar1 = stack_area._32_2_ & 0xfff7;
  stack_area[0x20] = (char)(uVar1 >> 8);
  stack_area[0x21] = (char)uVar1;
  return CONCAT44(in_D0,in_D1);
}



//
// Function: FUN_0002baf0 @ 0x0002baf0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002baf0(undefined4 param_1)

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
// Function: FUN_0002bb6c @ 0x0002bb6c
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002bb6c(void)

{
  _DAT_008031f6 = 2;
  _DAT_008031f8 = 0x808a86;
  _DAT_008031fc = _DAT_008091ea;
  _DAT_008031fe = 0x808a9c;
  if (_DAT_00808a84 < _DAT_0080c9a4) {
    _DAT_0080d4c0 = 0;
    return;
  }
  _DAT_008031f4 = FUN_00035560((short *)&DAT_008031f6);
  return;
}



//
// Function: FUN_0002bbac @ 0x0002bbac
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002bbac(void)

{
  short *unaff_A2;
  
  _DAT_008031f4 = FUN_00035560(unaff_A2);
  return;
}



//
// Function: FUN_0002bbc0 @ 0x0002bbc0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002bbc0(void)

{
  if (_DAT_00808a84 < _DAT_0080c9a4) {
    _DAT_0080d4c0 = 0;
    return;
  }
  _DAT_0080d4c0 = current_engine_param / _DAT_00808a82 + _DAT_008031f4 + -0xc4;
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
// Function: FUN_0002bc2a @ 0x0002bc2a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0002bc2a(void)

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
// Function: FUN_0002bc62 @ 0x0002bc62
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002bc62(void)

{
  FUN_0002d96a();
  FUN_0002da0e();
  FUN_0002db10();
  if (((param_system_mode == 7) || (param_system_mode == 8)) || (param_system_mode == 9)) {
    _DAT_00803206 = param_system_mode;
  }
  switch(param_system_mode) {
  case 9:
    if ((_DAT_0080969a == 0) ||
       ((((_DAT_0080c9a4 < _DAT_0080d182 && (_DAT_0080d182 < _DAT_00809696)) &&
         ((_DAT_0080d182 < _DAT_00809694 && (_DAT_00809d4c != 0)))) ||
        (((_DAT_0080d184 == 2 || (_DAT_0080d184 == 1)) || (_DAT_0080d184 == 5)))))) {
      _DAT_00809652 = _DAT_0080d182;
      param_system_mode = _DAT_0080d184;
      return;
    }
    if ((current_engine_param <= _DAT_0080d092) &&
       ((uint)_DAT_00803820 + (uint)_DAT_0080969c < (uint)_DAT_008096f8)) {
      param_system_mode = 0xb;
      _DAT_0080966a = 1;
      FUN_0001e78e();
    }
    if ((((_DAT_00809696 == _DAT_00809698) &&
         (((_DAT_0080c9a4 <= _DAT_0080d182 && (0xc < _DAT_00809d4c)) ||
          (_DAT_0080973c <= _DAT_0080969c)))) || (_DAT_00809696 < _DAT_00809698)) &&
       ((_DAT_00809696 < _DAT_00809694 && (_DAT_00809696 < _DAT_00809652)))) {
      param_system_mode = 10;
      FUN_0002d210();
      return;
    }
    if ((((_DAT_00809694 < _DAT_00809652) || (_DAT_00809694 <= _DAT_0080d182)) &&
        (_DAT_00809694 < _DAT_00809696)) && (_DAT_00809694 < _DAT_00809698)) {
      param_system_mode = 0xc;
      return;
    }
    break;
  case 10:
    if (((((current_engine_param < 8000) || (_DAT_0080d184 == 2)) || (_DAT_0080d184 == 1)) ||
        (_DAT_008096aa != 0)) ||
       ((_DAT_0080d182 < _DAT_0080c9a4 &&
        (((_DAT_0080969a == 0 || (_DAT_00803206 == 7)) ||
         ((_DAT_00803206 == 8 || (_DAT_0080d184 == 5)))))))) {
      _DAT_00809652 = _DAT_0080d182;
      param_system_mode = _DAT_0080d184;
      return;
    }
    if ((_DAT_00809694 < _DAT_00809652) && (_DAT_00809694 <= _DAT_00809696)) {
      param_system_mode = 0xc;
      return;
    }
    if ((((((_DAT_0080969a != 0) && (_DAT_00803206 == 9)) && (_DAT_0080d182 < _DAT_0080c9a4)) &&
         ((_DAT_00809698 < _DAT_00809696 ||
          ((_DAT_00809698 == _DAT_00809696 && (_DAT_0080969c < _DAT_0080973c)))))) &&
        (_DAT_00809698 < _DAT_00809694)) && (_DAT_00809698 < _DAT_00809652)) {
      param_system_mode = 9;
      FUN_0002d210();
      return;
    }
    break;
  case 0xb:
    if ((((uint)_DAT_0080d182 <= _DAT_00809652 + 0xe) &&
        (((uint)current_engine_param <= (uint)_DAT_00807098 + (uint)_DAT_0080d092 ||
         (_DAT_00809d4c != 0)))) ||
       (((_DAT_0080c99c != 0 ||
         ((_DAT_00809d4c == 0 &&
          (((_DAT_0080d184 == 7 || (_DAT_0080d184 == 8)) && (_DAT_0080969a == 0)))))) ||
        ((_DAT_0080cffc == 3 && (_DAT_0080d00e <= _DAT_00809652)))))) {
      if ((_DAT_0080969a != 0) &&
         ((((uint)_DAT_008096f8 < (uint)_DAT_00803820 + (uint)_DAT_0080969c ||
           ((uint)_DAT_00807098 + (uint)_DAT_0080d092 < (uint)current_engine_param)) &&
          ((_DAT_0080c99c == 0 && ((_DAT_0080cffc != 3 || (_DAT_00809652 < _DAT_0080d00e)))))))) {
        param_system_mode = 9;
        FUN_0002d210();
      }
      _DAT_00803202 = 0;
      return;
    }
    _DAT_00803202 = _DAT_00803202 + 1;
    if (_DAT_00806e1e == 0) {
      _DAT_00809652 = _DAT_0080d182;
      param_system_mode = _DAT_0080d184;
      _DAT_00803202 = 0;
      return;
    }
    if (_DAT_00803202 == _DAT_00806e1e) {
      _DAT_00809652 = _DAT_0080d182;
      param_system_mode = _DAT_0080d184;
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
        param_system_mode = _DAT_0080d184;
        _DAT_00803204 = 0;
        return;
      }
      if (_DAT_00803204 == _DAT_00806e1c) {
        _DAT_00809652 = _DAT_0080d182;
        param_system_mode = _DAT_0080d184;
        _DAT_00803204 = 0;
        return;
      }
    }
    else {
      _DAT_00803204 = 0;
      if ((_DAT_00809696 < _DAT_00809652) && (_DAT_00809696 < _DAT_00809694)) {
        param_system_mode = 10;
        FUN_0002d210();
        return;
      }
      if ((((_DAT_0080d182 <= _DAT_0080c9a4) && (_DAT_00803206 == 9)) &&
          (_DAT_00809698 < _DAT_00809652)) &&
         ((_DAT_00809698 < _DAT_00809694 && (_DAT_0080969a != 0)))) {
        param_system_mode = 9;
        FUN_0002d210();
        return;
      }
    }
    break;
  default:
    if (((current_engine_param <= _DAT_0080d092) && (_DAT_00809652 < _DAT_0080d05c)) ||
       ((((uint)current_engine_param <= (uint)_DAT_00806e1a + (uint)_DAT_0080d092 &&
         ((_DAT_00809d4c == 0 && (_DAT_00809652 < _DAT_0080d05c)))) &&
        ((_DAT_0080d184 == 7 || (_DAT_0080d184 == 8)))))) {
      param_system_mode = 0xb;
      _DAT_0080966a = 1;
      FUN_0001e78e();
      return;
    }
    if ((_DAT_00809694 <= _DAT_0080d182) && (_DAT_00809694 <= _DAT_00809696)) {
      param_system_mode = 0xc;
      FUN_0001883a();
      return;
    }
    if ((((_DAT_00809696 < _DAT_0080d182) && (_DAT_00809696 <= _DAT_00809694)) &&
        (7999 < current_engine_param)) &&
       (((_DAT_008096aa == 0 && (_DAT_0080d184 != 2)) && (_DAT_0080d184 != 1)))) {
      param_system_mode = 10;
      FUN_0002d210();
      return;
    }
    if (((_DAT_0080969a != 0) && (_DAT_0080d182 <= _DAT_00809698)) &&
       ((_DAT_0080d182 <= _DAT_0080c9a4 &&
        (((_DAT_0080d184 != 2 && (_DAT_0080d184 != 1)) && (_DAT_0080d184 != 5)))))) {
      param_system_mode = 9;
      FUN_0002d210();
      return;
    }
    _DAT_00809652 = _DAT_0080d182;
    param_system_mode = _DAT_0080d184;
  }
  return;
}



//
// Function: FUN_0002c240 @ 0x0002c240
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002c240(void)

{
  param_system_mode = 0xb;
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
    _DAT_00809690 = FUN_000356f8();
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
  iVar2 = FUN_000357e4((uint)_DAT_00803746 - (uint)_DAT_00809690,(uint)_DAT_00807082,0x80);
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
         (uVar3 = CONCAT22((short)(uVar3 >> 0x10),_DAT_0080c7c0), _DAT_00807f12 <= _DAT_0080c7c0))))
       && (uVar3 = CONCAT22((short)(uVar3 >> 0x10),_DAT_008096a8), _DAT_008096a8 <= _DAT_00807090))
    {
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
  _DAT_008096c6 = FUN_00035560((short *)&DAT_00803212);
  if (param_system_mode == 9) {
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
  if ((_DAT_008096b8 == 0) && (param_system_mode == 9)) {
    _DAT_008096c4 = 0;
  }
  else if (_DAT_008096e0 < param_1._0_2_) {
    uVar1 = _DAT_008096de;
    if (param_system_mode == 9) {
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
    if (param_system_mode == 9) {
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
      if ((uint)_DAT_0080c9a4 < _DAT_0080709c + 0x3a) {
        _DAT_0080321e = 0;
      }
    }
    else if (_DAT_0080c9a4 < _DAT_0080709c) {
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
// Function: FUN_0002c7e0 @ 0x0002c7e0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002c7e0(void)

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
  undefined1 *puVar2;
  ushort local_8;
  ushort uStack_6;
  
  uVar1 = (((uint)_DAT_0080385c * (uint)_DAT_00803828) / 0x3c & 0xffff) * (uint)_DAT_0080374a;
  local_8 = (ushort)(uVar1 >> 0x17);
  if (local_8 == 0) {
    puVar2 = (undefined1 *)((uVar1 >> 7 & 0xffff) * (uint)param_1._0_2_);
    local_8 = (ushort)((uint)puVar2 >> 0x10);
    uStack_6 = local_8;
    if (local_8 < 0x1f41) {
      uStack_6 = 8000;
    }
  }
  else {
    puVar2 = (undefined1 *)((uint)param_1._0_2_ * (uVar1 >> 0xb & 0xffff) >> 0xc);
    if (puVar2 < &LAB_00008c9e_2) {
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
// Function: FUN_0002c99a @ 0x0002c99a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002c99a(void)

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
// Function: FUN_0002cb6a @ 0x0002cb6a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002cb6a(void)

{
  bool bVar1;
  ushort uVar2;
  short sVar4;
  int iVar3;
  undefined4 unaff_D2;
  short sVar5;
  short sVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  ushort uStack_a;
  int local_8;
  
  uVar8 = (undefined2)((uint)unaff_D2 >> 0x10);
  uVar7 = 0x322a;
  sVar5 = _DAT_0080c9a4;
  _DAT_00803228 = FUN_000356f8(0x80);
  _DAT_00803264 = FUN_000356f8(0x80,sVar5,uVar7);
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
    _DAT_00803262 = _DAT_0080c9a4;
  }
  if ((param_system_mode == 9) || (param_system_mode == 10)) {
    if (_DAT_008096ee == 1) {
      FUN_0002d210();
    }
    else {
      if (param_system_mode == 9) {
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
      FUN_0002c51a(CONCAT22(_DAT_00803228,uVar8));
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
      local_8 = (int)_DAT_008070f0 * ((int)_DAT_0080c9a4 - (int)(short)_DAT_00803222) * 2;
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
  _DAT_0080326a = param_system_mode;
  FUN_0002c7e0();
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
  
  if (param_system_mode == 10) {
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
  local_8 = (undefined *)((int)sVar2 * (int)_DAT_008096cc >> 0xc);
  if ((int)local_8 < 0x1700) {
    if ((int)local_8 < -0x16ff) {
      local_8 = (undefined *)0xe900;
    }
  }
  else {
    local_8 = &DAT_00001700;
  }
  if ((_DAT_0080326a == 7) || (_DAT_0080326a == 8)) {
    _DAT_00803252 = _DAT_00803262;
    if (param_system_mode == 10) {
      _DAT_00803252 = _DAT_0080c9a4 - _DAT_008070fa;
    }
    _DAT_00803268 = _DAT_0080c9a4 - _DAT_00803252;
    _DAT_00803252 = _DAT_00803252 - local_8._2_2_;
  }
  else {
    _DAT_00803268 = 0;
    _DAT_00803252 = _DAT_0080c9a4 - local_8._2_2_;
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
  _DAT_00803222 = _DAT_0080c9a4;
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
  if ((_DAT_008035da & 0x40) == 0) {
    _DAT_008096b6 = 0;
    uVar4 = _DAT_008035da & 0x40;
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
         ((uVar4 = _DAT_0080c406, _DAT_0080c406 < _DAT_0080709a ||
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
      if ((_DAT_00809d4c < 0xc) || (param_system_mode == 9)) {
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
// Function: FUN_0002d6a2 @ 0x0002d6a2
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002d6a2(void)

{
  uint uVar1;
  
  if (_DAT_00803832 != 0) {
    _DAT_008096f8 = _DAT_008096a6;
    return;
  }
  uVar1 = ((uint)current_engine_param << 0x10) / ((uint)_DAT_00803830 * (uint)_DAT_0080971c >> 10)
          >> 2;
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
  
  uVar1 = _DAT_008035da & 0x8000;
  if ((_DAT_008035da & 0x8000) != 0) {
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
  
  if (current_engine_param < _DAT_0080cc4e) {
    _DAT_00809694 = 0x1700;
  }
  else if (_DAT_0080cc58 == 0) {
    _DAT_00809694 = 0;
  }
  else {
    _DAT_00803282 = (uint)(ushort)((_DAT_0080cc54 + current_engine_param) - _DAT_0080cc4e) << 0x10;
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
  
  if (((_DAT_008035da & 0x80) == 0) || (_DAT_008096aa != 0)) {
    _DAT_00809696 = 0x1700;
    return _DAT_008035da & 0x80;
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
// Function: FUN_0002dc1e @ 0x0002dc1e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002dc1e(void)

{
  ushort uVar1;
  
  if ((_DAT_008071ae <= _DAT_008096a6) && (_DAT_0080c810 != 1)) {
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
      _DAT_008096a8 = FUN_000356f8();
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
    if ((current_engine_param < 8000) && (_DAT_00807156 < _DAT_008096a6)) {
      _DAT_00809720 = _DAT_00807154;
    }
    else if (_DAT_00809720 != 0) {
      _DAT_00809720 = _DAT_00809720 + -1;
    }
    if ((_DAT_0080d002 == 0 && _DAT_00809722 == 0) && (_DAT_00809720 == 0)) {
      _DAT_008096aa = 0;
    }
    else {
      _DAT_008096aa = 1;
      _DAT_00803294 = 1;
    }
    if ((((_DAT_0080971c == _DAT_00803296) && (_DAT_008096aa == 0)) && (_DAT_00803294 == 1)) &&
       (_DAT_00807158 < _DAT_0080c9a4)) {
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
  _DAT_0080d002 = 0;
  _DAT_0080971a = _DAT_00807150;
  _DAT_008096a8 = _DAT_00807150;
  _DAT_0080971c = _DAT_00807150;
  _DAT_0080328e = (uint)_DAT_00807150 << 0x10;
  _DAT_0080328a = 0x80714e;
  _DAT_00803296 = _DAT_00807150;
  return;
}



//
// Function: FUN_0002de2e @ 0x0002de2e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0002de2e(void)

{
  ushort in_D0w;
  
  if (((_DAT_008096aa != 0) && (in_D0w = _DAT_008096a6, _DAT_0080973c < _DAT_008096a6)) &&
     (in_D0w = _DAT_008035da & 0x80, (_DAT_008035da & 0x80) != 0)) {
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
    if (jcthkctd_calc_input < 0x6400) {
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
  
  uVar1 = CONCAT22((short)((uint)in_D0 >> 0x10),_DAT_008035ec) & 0xffff2000;
  if ((_DAT_008035ec & 0x2000) != 0) {
    if ((((current_engine_param == 0) && (_DAT_0080d1a4 == 2)) && (_DAT_0080329e <= _DAT_0080715c))
       && (_DAT_0080329a < 0xc)) {
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
      if ((_DAT_0080329a == 0xc) && (_DAT_0080d0b2 = 1, _DAT_008032ba == 1)) {
        _DAT_0080d050 = 1;
      }
    }
    if (((current_engine_param != 0) && ((_DAT_00805dfa & 0x100) != 0)) &&
       ((_DAT_008068cc & 0x100) != 0)) {
      if (_DAT_008032b4 == _DAT_0080888a) {
        _DAT_0080558e = _DAT_0080558e | 1;
      }
      else {
        _DAT_008032b4 = _DAT_008032b4 + 1;
      }
    }
    if (((current_engine_param != 0) && ((_DAT_00805dfa & 0x200) != 0)) &&
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
      param_scaling_factor = FUN_00035560((short *)&DAT_008032a8);
      uVar2 = (short)_DAT_0080626c - _DAT_008032a6;
      _DAT_008032a4 = _DAT_0080626c;
      uVar2 = (ushort)((uint)uVar2 * (uint)param_scaling_factor >> 8);
      if (-(uint)uVar2 - 1 < _DAT_00805faa) {
        _DAT_0080558e = _DAT_0080558e | 8;
      }
      _DAT_00805faa = uVar2 + _DAT_00805faa;
      uVar1 = FUN_000357d2(_DAT_00805faa,0x6400,(uint)_DAT_0080972a * 0x280);
      _DAT_0080d0b0 = (undefined2)uVar1;
      if ((_DAT_00805fae == 0) && (0x63ff < jcthkctd_calc_input)) {
        _DAT_00805fae = _DAT_00809726;
      }
    }
    else if (_DAT_00803734 == 3) {
      uVar1 = FUN_000357d2(uVar1,0x6400,(uint)_DAT_0080384a * 0x280);
      _DAT_0080d0b0 = (undefined2)uVar1;
    }
    else {
      _DAT_0080d0b0 = 0;
    }
    if ((_DAT_0080d0b4 == 1) || ((_DAT_0080d0b2 == 1 && (_DAT_008032ba == 1)))) {
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
    _DAT_0080972a = FUN_00035560(local_10);
  }
  return;
}



//
// Function: FUN_0002e336 @ 0x0002e336
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002e336(void)

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
  _DAT_008096a6 = FUN_000356f8();
  return;
}



//
// Function: FUN_0002e3a8 @ 0x0002e3a8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002e3a8(void)

{
  _DAT_00809738 = 0;
  _DAT_00809734 = 0x8071a8;
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
  undefined4 *puVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  
  uVar3 = CONCAT22((short)((uint)in_D0 >> 0x10),_DAT_008035da) & 0xffff0100;
  if ((_DAT_008035da & 0x100) == 0) {
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
      puVar4 = (undefined4 *)((uint)(iVar1 * 0x6400) / (uint)_DAT_008096a8);
      if ((undefined4 *)0x63ff < puVar4) {
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
          _DAT_0080973c = uVar6;
        }
        else {
          _DAT_00809746 = 6;
          _DAT_0080973c = uVar6;
        }
        break;
      case 1:
        _DAT_008032c2 = 0x64000000;
        _DAT_0080974a = 0x6400;
        _DAT_00809746 = 3;
        _DAT_0080973c = uVar6;
        break;
      case 2:
        _DAT_0080974a = FUN_000356f8();
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
        _DAT_0080973c = _DAT_008096a6;
        if ((uVar7 <= _DAT_008096a6) && (uVar7 = _DAT_0080973c, uVar6 < _DAT_008096a6)) {
          uVar7 = uVar6;
        }
        _DAT_0080973c = uVar7;
        _DAT_00809746 = 5;
        break;
      case 4:
        if (uVar7 < _DAT_0080973c) {
          _DAT_0080973c = _DAT_0080973c - _DAT_008071b4;
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
        if ((_DAT_0080973e < (int)uVar3) || (_DAT_0080973c = uVar6, _DAT_008071ba < uVar5)) {
          _DAT_00809746 = 1;
          _DAT_0080973c = uVar6;
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
  _DAT_0080973c = _DAT_00803748;
  _DAT_0080974a = _DAT_0080d0c8;
  _DAT_008032c2 = 0x64000000;
  _DAT_008032be = 0x8071b6;
  _DAT_0080973e = ((uint)_DAT_00803828 * ((int)&DAT_00006400 + (uint)_DAT_008071b0)) / 0x6400;
  if (_DAT_0080714c < _DAT_0080973e) {
    _DAT_0080973e = (uint)_DAT_0080714c;
  }
  else {
    _DAT_0080973e = _DAT_0080973e & 0xffff;
  }
  uVar1 = (((int)&DAT_00006400 + (uint)_DAT_008071b0) * (uint)_DAT_0080386c) / 0x6400;
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
     (((_DAT_0080c9a6 == 9 && (cached_parameter_value < _DAT_0080c9a4)) ||
      ((_DAT_0080c9a6 != 9 && ((cached_parameter_value < _DAT_00809698 || (_DAT_00809d4c == 0)))))))
     ) {
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
  uVar2 = _DAT_008035da & 0x200;
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
    if ((((_DAT_00805dfa & 0x100) == 0) || ((_DAT_008068cc & 0x100) == 0)) &&
       (((_DAT_00805dfa & 0x200) == 0 || ((_DAT_008068cc & 0x200) == 0)))) {
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
      _DAT_00806270 = FUN_000357d2(_DAT_00806274,0x400000,_DAT_00805f34);
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
    if (_DAT_0080c406 != 0) {
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
  ushort uVar1;
  undefined4 in_D0;
  undefined4 in_D1;
  
  uVar1 = stack_area._32_2_ & 0xfffb;
  stack_area[0x20] = (char)(uVar1 >> 8);
  stack_area[0x21] = (char)uVar1;
  _DAT_00809760 = _DAT_008071aa;
  _DAT_00809758 = register_map._40_4_;
  register_map._40_4_ = register_map._40_4_ & 0xffff;
  if (_DAT_0080c42a == 0) {
    if (_DAT_0080c758 == 0) {
      _DAT_0080975c = 0;
    }
    else {
      _DAT_0080975c = _DAT_0080c750 / _DAT_0080c758;
    }
    _DAT_0080c750 = 0;
    _DAT_0080c758 = 0;
  }
  else if (_DAT_0080c42a == 1) {
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
  ushort uVar1;
  
  uVar1 = stack_area._32_2_ & 0xfffb;
  stack_area[0x20] = (char)(uVar1 >> 8);
  stack_area[0x21] = (char)uVar1;
  _DAT_00808eca = FUN_0002ed06;
  uVar1 = stack_area._18_2_ & 0xf0ff | 0xd00;
  stack_area[0x12] = (char)(uVar1 >> 8);
  stack_area[0x13] = (char)uVar1;
  register_map[0x22] = (char)((ushort)(_DAT_0080385a << 8) >> 8);
  register_map[0x23] = (char)(_DAT_0080385a << 8);
  register_map[0x26] = 0;
  register_map[0x27] = 0;
  register_map[0x28] = 0;
  register_map[0x29] = 0;
  register_map[0x2a] = 0;
  register_map[0x2b] = 0;
  register_map[0x20] = 0;
  register_map[0x21] = 0xb;
  uVar1 = stack_area._22_2_ & 0xffcf | 0x30;
  stack_area[0x16] = (char)(uVar1 >> 8);
  stack_area[0x17] = (char)uVar1;
  uVar1 = stack_area._26_2_ & 0xffcf | 0x30;
  stack_area[0x1a] = (char)(uVar1 >> 8);
  stack_area[0x1b] = (char)uVar1;
  uVar1 = stack_area._10_2_ & 0xfffb | 4;
  stack_area[10] = (char)(uVar1 >> 8);
  stack_area[0xb] = (char)uVar1;
  uVar1 = stack_area._30_2_ & 0xffcf | 0x20;
  stack_area[0x1e] = (char)(uVar1 >> 8);
  stack_area[0x1f] = (char)uVar1;
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
  _DAT_008032e6 = FUN_000356f8();
  _DAT_008032e8 = FUN_000356f8();
  _DAT_008032ea = FUN_000356f8();
  _DAT_008032ec = FUN_000356f8();
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
    if (((((_DAT_00805dfa & 0x100) != 0) && ((_DAT_008068cc & 0x100) != 0)) ||
        (((_DAT_00805dfa & 0x200) != 0 && ((_DAT_008068cc & 0x200) != 0)))) &&
       (_DAT_0080387e < _DAT_008096ae)) {
      _DAT_008096ae = _DAT_0080387e;
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
  if (((((_DAT_008035ec & 0x100) != 0) && (_DAT_0080385e != 0)) && (_DAT_0080972e == 0)) &&
     ((_DAT_008071ea < _DAT_008096a6 && ((DAT_0080bdc7 & 8) == 0)))) {
    _DAT_00805fe4 = 2;
    _DAT_008096ae = _DAT_0080387e;
    _DAT_00805dfa = _DAT_00805dfa | 0x100;
    _DAT_00805e3a = _DAT_00805e3a | 0x100;
  }
  if ((((_DAT_008035ec & 0x200) != 0) && (_DAT_0080d17a == 0)) &&
     ((_DAT_0080385e != 0 && (_DAT_008096a6 == 0)))) {
    if ((_DAT_008032e0 == 0) && (_DAT_00809d50 == 1)) {
      _DAT_00805ff4 = _DAT_00805ff4 + 1;
    }
    if (_DAT_008071da < current_engine_param) {
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
      _DAT_00805dfa = _DAT_00805dfa | 0x100;
      _DAT_00805e3a = _DAT_00805e3a | 0x100;
    }
  }
  if (((_DAT_0080972e != 0) || (_DAT_0080d17a == 1)) ||
     (((_DAT_008035ec & 0x100) == 0 && ((_DAT_008035ec & 0x200) == 0)))) {
    if (((_DAT_00805dfa & 0x100) != 0) && ((_DAT_00805e3a & 0x100) == 0)) {
      _DAT_00805dfa = _DAT_00805dfa & 0xfeff;
      _DAT_008096ae = _DAT_008037b4;
    }
    _DAT_00805ff4 = 0;
    _DAT_00805ff8 = 0;
    _DAT_00805ff6 = 0;
  }
  if (((_DAT_0080385e != 0) && (_DAT_0080d17a == 0)) && ((_DAT_008035d4 & 0x80) != 0)) {
    if (((_DAT_00805dfa & 0x100) == 0) || ((_DAT_008068cc & 0x100) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (((_DAT_00805dfa & 0x200) == 0) || ((_DAT_008068cc & 0x200) == 0)) {
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
                    _DAT_00805dfa = _DAT_00805dfa | 0x200;
                    _DAT_00805e3a = _DAT_00805e3a | 0x200;
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
            uVar4 = _DAT_0080c406;
            _DAT_008032e6 = FUN_000356f8();
            _DAT_008032e8 = FUN_000356f8(0x80,uVar4,puVar5);
            if (_DAT_008071ee < _DAT_00805fe6) {
              _DAT_00805dfa = _DAT_00805dfa | 0x200;
              _DAT_00805e3a = _DAT_00805e3a | 0x200;
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
            uVar4 = _DAT_0080c406;
            _DAT_008032ea = FUN_000356f8();
            _DAT_008032ec = FUN_000356f8(0x80,uVar4,puVar5);
            if (_DAT_008071f8 < _DAT_00805fe8) {
              _DAT_00805dfa = _DAT_00805dfa | 0x200;
              _DAT_00805e3a = _DAT_00805e3a | 0x200;
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
        if (((_DAT_00805dfa & 0x200) != 0) && ((_DAT_00805e3a & 0x200) == 0)) {
          _DAT_00805dfa = _DAT_00805dfa & 0xfdff;
          _DAT_008096ae = _DAT_008037b4;
          FUN_0002ee28();
        }
      }
      else if (_DAT_008096a6 == 0 && current_engine_param == 0) {
        _DAT_00805fee = _DAT_00805fee + 1;
      }
      else {
        _DAT_00805fee = 0;
      }
      goto LAB_0002f5b6;
    }
  }
  if ((((_DAT_008035d4 & 0x80) == 0) && ((_DAT_00805dfa & 0x200) != 0)) &&
     ((_DAT_00805e3a & 0x200) == 0)) {
    _DAT_00805dfa = _DAT_00805dfa & 0xfdff;
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
// Function: FUN_0002f662 @ 0x0002f662
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0002f662(void)

{
  ushort uVar1;
  
  uVar1 = _DAT_00809766;
  if (_DAT_0080d17a == 1) {
    if ((_DAT_008035d8 & 0x8000) == 0) {
      _DAT_00809766 = 0;
      _DAT_008096ac = _DAT_008037b4;
      return _DAT_008035d8 & 0x8000;
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
  if ((_DAT_008035d8 & 0x8000) != 0) {
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
  if ((_DAT_0080cffc == 3) && (_DAT_0080d00e < _DAT_0080d494)) {
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
  _DAT_0080d494 = _DAT_00807f3c;
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
  FUN_0000a56e();
  FUN_00018590();
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
  sVar1 = FUN_00035560((short *)&DAT_00803322);
  sVar2 = FUN_00035560((short *)&DAT_00803316);
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
  if (((((((_DAT_008035da & 0x40) != 0) && (_DAT_00803332 != 0)) && (_DAT_00807944 <= _DAT_008096f8)
        ) && (((DAT_0080bdc7 & 4) == 0 && (_DAT_0080709a < _DAT_0080c406)))) &&
      (((DAT_0080bdc7 & 8) == 0 && ((_DAT_0080971e == 0 || (_DAT_0080711e == 0)))))) &&
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
  if ((((_DAT_008035da & 0x40) != 0) && (_DAT_00803332 != 0)) && (_DAT_008096fc != 0)) {
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
// Function: FUN_0002fce4 @ 0x0002fce4
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002fce4(void)

{
  if (((_DAT_00803342 == 9) && (param_system_mode == 8)) && (_DAT_00809652 < _DAT_00803344)) {
    _DAT_00803340 = _DAT_00803344;
  }
  if (_DAT_0080725a < _DAT_00803340) {
    _DAT_00803340 = _DAT_00803340 - _DAT_0080725a;
  }
  else {
    _DAT_00803340 = 0;
  }
  if (((_DAT_00809652 < _DAT_00803340) && (param_system_mode == 8)) &&
     ((_DAT_008096aa == 0 || (_DAT_0080725c != 0)))) {
    _DAT_00809652 = _DAT_00803340;
  }
  _DAT_00803342 = param_system_mode;
  _DAT_00803344 = _DAT_0080c9a4;
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
  
  if (_DAT_0080969e == 1) {
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
// Function: FUN_0002ff3a @ 0x0002ff3a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0002ff3a(void)

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
    if (((_DAT_0080c810 == 8) || (_DAT_0080c810 == 1)) &&
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
  else if (((_DAT_0080c810 == 2) || (_DAT_0080c810 == 6)) && (_DAT_00809a04 == 2)) {
    _DAT_00809a04 = 3;
  }
  else if ((((_DAT_0080c810 == 3) || (_DAT_0080c810 == 4)) ||
           ((_DAT_0080c810 == 7 || (_DAT_0080c810 == 5)))) &&
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
// Function: FUN_000301a6 @ 0x000301a6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000301a6(void)

{
  _DAT_0080337a = _DAT_00809a10;
  _DAT_008033ac = FUN_00035560((short *)&DAT_00803374);
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
// Function: FUN_000302c6 @ 0x000302c6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000302c6(void)

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
    _DAT_00809a06 = FUN_00035560((short *)&DAT_00803368);
    if (_DAT_00809a06 == 6) {
      if (_DAT_00803364 != 0) {
        _DAT_00803364 = _DAT_00803364 + -1;
      }
      if (_DAT_00803364 == 0) {
        _DAT_00809a0c = 6;
        FUN_00030896();
        return;
      }
      DAT_0080bdef = DAT_0080bdef & 0xf9;
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
      uVar4 = FUN_000357f6((short *)&DAT_0080338c);
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
  if (_DAT_00807262 <= _DAT_0080c9a4) {
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
    uVar2 = CONCAT22(uVar1,current_engine_param);
    if (_DAT_0080726c < current_engine_param) {
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
    if ((int)(uint)current_engine_param < (int)uVar2) {
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
    if (uVar2 < current_engine_param) {
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
    if ((int)(uint)current_engine_param < (int)uVar2) {
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
    _DAT_008033ae = FUN_00035560((short *)&DAT_00803380);
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
// Function: FUN_00030896 @ 0x00030896
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00030896(void)

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
    if (((_DAT_00805df6 & 2) == 0) || ((_DAT_008068c8 & 2) == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    if (uVar1 == 0) {
      if (((_DAT_00805df6 & 1) == 0) || ((_DAT_008068c8 & 1) == 0)) {
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
    if (((_DAT_00805e16 & 0x100) == 0) || ((_DAT_008068e8 & 0x100) == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    if (uVar1 == 0) {
      if (((_DAT_00805e16 & 0x80) == 0) || ((_DAT_008068e8 & 0x80) == 0)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
      if (uVar1 == 0) {
        if (((_DAT_00805e16 & 0x40) == 0) || ((_DAT_008068e8 & 0x40) == 0)) {
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
// Function: FUN_00030ac0 @ 0x00030ac0
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00030ac0(void)

{
  if (DAT_008077c6 != '\0') {
    if (DAT_008077c7 == '\0') {
      DAT_0080bdef = DAT_0080bdef & 0xef;
      return;
    }
    DAT_0080bdef = DAT_0080bdef | 0x10;
    return;
  }
  switch(_DAT_0080c810) {
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
// Function: FUN_00030c78 @ 0x00030c78
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00030c78(void)

{
  undefined4 in_D0;
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = CONCAT22((short)((uint)in_D0 >> 0x10),_DAT_00803614) & 0xffff0001;
  if ((_DAT_00803614 & 1) != 0) {
    _DAT_008033c8 = _DAT_00809258;
    _DAT_008033d0 = current_engine_param;
    uVar2 = FUN_000357f6((short *)&DAT_008033c2);
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
  if (((_DAT_00803614 & 1) != 0) && (_DAT_0080c9b0 == 0)) {
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
  _DAT_0080d186 = 0;
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
      _DAT_00809a36 = (ushort)((uint)param_table_main.calculated_2 * 0x50 >> 8);
      break;
    case 0xe:
    case 0xf:
      iVar2 = FUN_000357e4((uint)_DAT_0080c9a4,(int)_DAT_00807396,0x3a);
      iVar2 = (uint)current_engine_param + (iVar2 >> 3);
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
      iVar2 = FUN_000357e4((uint)_DAT_0080c9a4,(int)_DAT_00807398,0x3a);
      iVar2 = (uint)current_engine_param + (iVar2 >> 3);
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
      if (current_engine_param < _DAT_0080739a) {
        if (_DAT_00803880 == 0xe) {
          uVar3 = 0;
          _DAT_00809a36 = (ushort)((uint)asthrfes_calc_input * 0x50 >> 8);
        }
        else {
          uVar3 = 0;
          _DAT_00809a36 = (ushort)((uint)param_table_main.calculated_2 * 0x50 >> 8);
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
     (((param_system_mode == 9 || (param_system_mode == 10)) ||
      (((_DAT_0080969a == 1 && (param_system_mode == 0xc)) && (_DAT_00809d4c < 0xc)))))) {
    if ((_DAT_00807392 < _DAT_00809a3e) || (_DAT_0080738e < _DAT_00809a36)) {
      _DAT_00809a3c = 0x6400;
    }
    else if ((_DAT_00809a40 < _DAT_00807394) && (_DAT_00809a36 < _DAT_00807390)) {
      _DAT_00809a3c = 0;
    }
    _DAT_0080d186 = _DAT_00809a3c;
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
    _DAT_0080d186 = _DAT_00809a3c;
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
  
  if ((_DAT_00803614 & 0x100) == 0) {
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
        if (((_DAT_0080c9a6 != 0x10) || (wVar2 = _DAT_00809258, _DAT_00809258 <= _DAT_0080782a)) ||
           (wVar2 = current_engine_param, current_engine_param <= _DAT_00807828)) {
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
        if (_DAT_0080782c <= _DAT_008033d6) {
          return _DAT_008033d6;
        }
        _DAT_008033d6 = _DAT_008033d6 + 1;
        if (_DAT_008033d6 != _DAT_0080782c) {
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
  if ((_DAT_00803614 & 2) == 0) {
    _DAT_00805dfa = _DAT_00805dfa & 0xdfff;
    uVar2 = 0;
  }
  else {
    if (_DAT_008093a2 == 1) {
      _DAT_0080d04c = _DAT_0080d04c | 0x10;
      _DAT_00805dfa = _DAT_00805dfa | 0x2000;
      _DAT_00805e3a = _DAT_00805e3a | 0x2000;
      return _DAT_00803614 & 2;
    }
    _DAT_0080d04c = _DAT_0080d04c & 0xffef;
    uVar2 = _DAT_00805dfa & 0x2000;
    if (uVar2 != 0) {
      uVar2 = _DAT_00805e3a & 0x2000;
      if (uVar2 == 0) {
        _DAT_00805dfa = _DAT_00805dfa & 0xdfff;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_000313c4(uint param_1)

{
  ushort uVar1;
  
  if (((param_1 & 0x10000) == 0) || ((_DAT_00805dfc & 0x20) != 0)) {
    DAT_0080bdef = DAT_0080bdef | 1;
  }
  else {
    DAT_0080bdef = DAT_0080bdef & 0xfe;
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
  if (((_DAT_00807120 < current_engine_param) && (_DAT_00809258 < _DAT_00807126)) &&
     (_DAT_0080c9a4 <= _DAT_00807130)) {
    uVar2 = 1;
  }
  else if ((current_engine_param <= _DAT_00803836) || (_DAT_00807130 < _DAT_0080c9a4)) {
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
       (uVar2 = _DAT_008035d8 & 0x40, (_DAT_008035d8 & 0x40) == 0)))))) {
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
      if (((_DAT_00805df4 & 0x400) == 0) && ((_DAT_00805df4 & 0x200) == 0)) {
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
              ((_DAT_0080712e <= current_engine_param || (_DAT_008033dc != 0)))) {
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
  
  _DAT_0080969e = 0;
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
  if (_DAT_0080713e <= current_engine_param) {
    _DAT_008033ee = 0;
    _DAT_008033f0 = 0;
    _DAT_00809706 = 0;
    return current_engine_param;
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
    if (((_DAT_00805df6 & 1) == 0) || ((_DAT_008068c8 & 1) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) goto LAB_000318d6;
    if (((_DAT_00805df6 & 2) == 0) || ((_DAT_008068c8 & 2) == 0)) {
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
  if ((_DAT_008035e0 & 0x1000) == 0) {
    if (_DAT_008091ea < _DAT_00807138) {
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
        if ((!bVar1) && ((_DAT_008033ea != 1 || (_DAT_008091ea < _DAT_00807136))))
        goto LAB_00031956;
      }
    }
    _DAT_00809706 = 1;
    _DAT_008033ee = 1;
  }
LAB_00031956:
  if (((_DAT_008035e0 & 0x4000) != 0) && ((DAT_0080bdc6 & 0x10) != 0)) {
    _DAT_00809706 = 1;
    _DAT_008033f0 = 1;
  }
  if (((_DAT_008035e0 & 0x400) != 0) &&
     (((DAT_0080bdcf & 1) != 0 || ((_DAT_008033ea == 1 && (_DAT_0080970e < _DAT_0080383c)))))) {
    _DAT_00809706 = 1;
  }
  if ((_DAT_008035e0 & 0x2000) != 0) {
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
  uVar2 = _DAT_008035e0 & 0x1000;
  if (((_DAT_008035e0 & 0x1000) == 0) && (uVar2 = _DAT_00809718, _DAT_00809718 < _DAT_0080713c)) {
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
  if (_DAT_0080713e <= current_engine_param) {
    _DAT_00809708 = 0;
    return current_engine_param;
  }
  if ((DAT_0080bdc6 & 1) == 0) {
    _DAT_00809708 = 0;
    return DAT_0080bdc6 & 1;
  }
  if ((_DAT_008035e0 & 0x1000) == 0) {
    _DAT_00809708 = 0;
    return _DAT_008035e0 & 0x1000;
  }
  if ((_DAT_00809712 == 2) || (_DAT_00809712 == 3)) {
    _DAT_00809708 = 1;
  }
  if (_DAT_008091ea < _DAT_00807138) {
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
      if ((!bVar1) && ((_DAT_008033ec == 0 || (_DAT_008091ea < _DAT_00807136)))) goto LAB_00031b34;
    }
  }
  _DAT_00809708 = 1;
LAB_00031b34:
  if (((_DAT_008035e0 & 0x4000) != 0) && ((DAT_0080bdc6 & 0x10) != 0)) {
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
// Function: FUN_00031b78 @ 0x00031b78
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00031b78(uint param_1)

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
  if (_DAT_0080c810 == 1) {
    _DAT_00809706 = 0;
    _DAT_00809708 = 0;
    FUN_00031b78(0xf);
    _DAT_0080970a = (ushort)DAT_0080bdef;
    return (uint)DAT_0080bdef;
  }
  FUN_00031814();
  FUN_00031b78(CONCAT22(_DAT_00809706,0xf));
  _DAT_0080970a = (ushort)DAT_0080bdef;
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
  if ((_DAT_008035e0 & 0x1000) == 0) {
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
// Function: FUN_00031fb8 @ 0x00031fb8
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00031fb8(void)

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
// Function: FUN_0003211a @ 0x0003211a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0003211a(void)

{
  ushort uVar1;
  
  uVar1 = _DAT_00803614 & 0x10;
  if (uVar1 != 0) {
    if (current_engine_param < _DAT_00807836) {
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
      if ((_DAT_00809b0c < _DAT_00807830) || ((_DAT_0080c9a6 != 0x10 && (_DAT_0080c9a6 != 0x13)))) {
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
      _DAT_00805dfa = _DAT_00805dfa & 0xfbff;
    }
    else {
      _DAT_00805dfa = _DAT_00805dfa | 0x400;
      _DAT_00805e3a = _DAT_00805e3a | 0x400;
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
      _DAT_00fff442 = _DAT_00fff442 & 0xffff0000;
    }
    else {
      _DAT_00fff442 =
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
  
  if ((((_DAT_008035ec & 0x8000) != 0) && ((_DAT_00803430 & 0x400) != 0)) &&
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
  if ((DAT_0080bdcc & 2) != 0) {
    _DAT_00803430 = _DAT_00803430 | 1;
  }
  if ((DAT_0080bdcc & 8) != 0) {
    _DAT_00803430 = _DAT_00803430 | 4;
  }
  if ((DAT_0080bdcc & 0x10) != 0) {
    _DAT_00803430 = _DAT_00803430 | 0x10;
  }
  if ((DAT_0080bdcc & 1) != 0) {
    _DAT_00803430 = _DAT_00803430 | 0x40;
  }
  if ((DAT_0080bdcc & 4) != 0) {
    _DAT_00803430 = _DAT_00803430 | 0x100;
  }
  if ((DAT_0080bdcc & 0x20) != 0) {
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
    if ((((_DAT_008035da & 0x10) == 0) || (_DAT_0080343e <= _DAT_00808932)) || (_DAT_0080343c == 0))
    {
      if ((((_DAT_00808932 < _DAT_00803440) && (_DAT_0080343a == 0)) ||
          ((_DAT_008037f8 < _DAT_008096a6 ||
           (((_DAT_00805dfa & 0x200) != 0 && ((_DAT_008068cc & 0x200) != 0)))))) ||
         (((_DAT_00805dfa & 0x100) != 0 && ((_DAT_008068cc & 0x100) != 0)))) {
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
            (((_DAT_00805dfa & 0x100) != 0 && ((_DAT_008068cc & 0x100) != 0)))) {
      _DAT_0080d17c = 2;
    }
    else {
      _DAT_00803440 = 0;
      _DAT_0080343e = 0;
      _DAT_0080343c = 0;
    }
    break;
  case 2:
    if (((_DAT_008096a6 < _DAT_008037f8) && (_DAT_0080892c <= current_engine_param)) &&
       (current_engine_param <= _DAT_0080892a)) {
      if (((_DAT_00805dfa & 0x200) == 0) || ((_DAT_008068cc & 0x200) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((_DAT_00805dfa & 0x100) == 0) || ((_DAT_008068cc & 0x100) == 0)) {
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
    if (((((_DAT_008035da & 0x10) != 0) && ((_DAT_00803430 & 0x10) != 0)) &&
        (_DAT_008096a6 <= _DAT_008037f8)) &&
       ((_DAT_0080892c <= current_engine_param && (current_engine_param <= _DAT_0080892a)))) {
      if (((_DAT_00805dfa & 0x200) == 0) || ((_DAT_008068cc & 0x200) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((_DAT_00805dfa & 0x100) == 0) || ((_DAT_008068cc & 0x100) == 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if ((((!bVar1) && (((_DAT_00803430 & 0x4000) == 0 || ((_DAT_008035ec & 0x1000) == 0)))) &&
            (((_DAT_00803430 & 0x10000) == 0 || ((_DAT_008035ec & 0x800) == 0)))) &&
           (((((_DAT_00803430 & 0x80) != 0 && ((_DAT_00803430 & 0x40) == 0)) ||
             (((_DAT_00803430 & 0x200) != 0 && ((_DAT_00803430 & 0x100) == 0)))) ||
            ((((_DAT_00803430 & 0x800) == 0 && ((_DAT_00803430 & 0x400) != 0)) &&
             ((_DAT_008035ec & 0x8000) != 0)))))) {
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
      if (((_DAT_00805dfa & 0x200) == 0) || ((_DAT_008068cc & 0x200) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((_DAT_00805dfa & 0x100) == 0) || ((_DAT_008068cc & 0x100) == 0)) {
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
         (((_DAT_00805dfa & 0x100) != 0 && ((_DAT_008068cc & 0x100) != 0)))) ||
        (((_DAT_008035ec & 0x1000) != 0 && ((_DAT_00803430 & 0x4000) != 0)))) ||
       (((_DAT_008035ec & 0x800) != 0 && ((_DAT_00803430 & 0x10000) != 0)))) {
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
            _DAT_00803438 = current_engine_param;
            if (fsmxthfl_calc_input <= _DAT_0080c9a4) {
              _DAT_00803438 =
                   (short)(((uint)(ushort)(_DAT_0080c9a4 - fsmxthfl_calc_input) *
                           (uint)_DAT_008036a6) / 0x1d70) + current_engine_param;
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
  _DAT_0080d178 = _DAT_00803436;
  if ((_DAT_0080d17c != 3) && (_DAT_0080d17c != 1)) {
    _DAT_0080d17a = 0;
    return;
  }
  _DAT_0080d17a = 1;
  return;
}



//
// Function: FUN_00033254 @ 0x00033254
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00033254(void)

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
  ushort uVar2;
  short sVar3;
  byte bVar4;
  undefined1 **ppuVar5;
  undefined1 *local_2a;
  undefined2 local_26;
  undefined *puStack_24;
  undefined1 local_6;
  undefined1 uStack_5;
  
  ppuVar5 = (undefined1 **)&stack0xffffffe0;
  if (DAT_00809af1 == '\0') {
    bVar4 = 0;
  }
  else {
    bVar4 = DAT_00809af1 - 1;
  }
  if (_DAT_0080742e < _DAT_0080c404) {
    DAT_008034a7 = DAT_008034a7 + 1;
    uVar2 = _DAT_0080742e;
    if (DAT_0080743b < DAT_008034a7) {
      _DAT_00805e14 = _DAT_00805e14 | 0x400;
      _DAT_00805e54 = _DAT_00805e54 | 0x400;
      DAT_008034a7 = 0;
    }
  }
  else {
    DAT_008034a7 = 0;
    uVar2 = _DAT_0080c404;
  }
  local_6 = (undefined1)((uint)((int)(uint)uVar2 >> 1) >> 8);
  DAT_00809a98 = local_6;
  uStack_5 = (undefined1)((int)(uint)uVar2 >> 1);
  DAT_00809a97 = uStack_5;
  if (_DAT_00807430 < _DAT_00809a52) {
    DAT_008034a9 = DAT_008034a9 + 1;
    sVar3 = _DAT_00807430;
    if (DAT_0080743b < DAT_008034a9) {
      _DAT_00805e14 = _DAT_00805e14 | 0x400;
      _DAT_00805e54 = _DAT_00805e54 | 0x400;
      DAT_008034a9 = 0;
    }
  }
  else if (_DAT_00809a52 < _DAT_00807432) {
    DAT_008034a8 = DAT_008034a8 + 1;
    sVar3 = _DAT_00807432;
    if (DAT_0080743b < DAT_008034a8) {
      _DAT_00805e14 = _DAT_00805e14 | 0x400;
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
      _DAT_00805e14 = _DAT_00805e14 | 0x400;
      _DAT_00805e54 = _DAT_00805e54 | 0x400;
      DAT_008034ab = 0;
    }
  }
  else if (_DAT_0080739e < _DAT_00807438) {
    DAT_008034aa = DAT_008034aa + 1;
    sVar3 = _DAT_00807438;
    if (DAT_0080743b < DAT_008034aa) {
      _DAT_00805e14 = _DAT_00805e14 | 0x400;
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
        _DAT_00805e14 = _DAT_00805e14 | 0x400;
        _DAT_00805e54 = _DAT_00805e54 | 0x400;
        DAT_008034a6 = 0;
      }
      _DAT_00809a54 = _DAT_0080742c;
    }
    else if ((short)_DAT_00809a54 < 0) {
      DAT_008034a5 = DAT_008034a5 + 1;
      if (DAT_0080743b < DAT_008034a5) {
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
  _DAT_00805f8c = _DAT_00805f8c + (uint)_DAT_0080c9a4;
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
    ppuVar5 = &local_2a;
    local_2a = &DAT_00ffc800;
    FUN_0001913e();
  }
  if ((_DAT_008073b2 <= _DAT_0080c404) && (_DAT_0080c404 <= _DAT_008073b0)) {
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
  _DAT_0080c428 = _DAT_00809a4e;
  _DAT_0080c426 = _DAT_00807cde;
  local_6 = CONCAT11(DAT_00809aa8,DAT_00809aa7);
  iVar1 = (short)local_6 * 0xe66;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0x7ff;
  }
  _DAT_00809a58 = (short)(iVar1 >> 0xb) + -0x1cb6;
  uVar2 = DAT_0080bdc6 & 1;
  if (((DAT_0080bdc6 & 1) == 0) && (uVar2 = _DAT_0080c404, _DAT_0080c404 < _DAT_00807434)) {
    DAT_0080348a = 1;
    DAT_0080348b = DAT_0080348b + '\x01';
    _DAT_0080c426 = _DAT_00807cde;
    return _DAT_0080c404;
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
  
  _DAT_0080c9c8 = _DAT_0080c9a4;
  _DAT_00803460 = _DAT_0080c404;
  _DAT_00803468 = _DAT_0080c9a4;
  uVar1 = FUN_000357f6(_DAT_0080346e);
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
  
  _DAT_00803478 = _DAT_0080c404;
  _DAT_00803480 = _DAT_0080c9a4;
  uVar3 = FUN_000357f6(_DAT_00803486);
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
                    ((uint)_DAT_0080c404 - (uint)_DAT_0080741c)) /
              (int)((uint)_DAT_0080741a - (uint)_DAT_0080741c));
  return;
}



//
// Function: FUN_00033dca @ 0x00033dca
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00033dca(void)

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
// Function: FUN_00033e0e @ 0x00033e0e
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00033e0e(void)

{
  bool bVar1;
  int iVar2;
  
  if (DAT_008034a1 != '\0') {
    if ((DAT_00809a5f & 0x20) == 0) {
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
    if ((DAT_00809a5f & 0x40) == 0) {
      DAT_008034b7 = DAT_008034b7 + 1;
      if (DAT_008073b5 <= DAT_008034b7) {
        _DAT_00805e16 = _DAT_00805e16 & 0xff7f;
        DAT_008034b7 = 0;
      }
      DAT_008034b6 = 0;
    }
    else {
      DAT_008034b6 = DAT_008034b6 + 1;
      if (DAT_008073b5 <= DAT_008034b6) {
        _DAT_00805e56 = _DAT_00805e56 | 0x80;
        _DAT_00805e16 = _DAT_00805e16 & 0xfeff | 0x80;
        DAT_008034b6 = 0;
      }
      DAT_008034b7 = 0;
    }
    if (((DAT_00809a5f & 0x20) == 0) || ((DAT_00809a5f & 0x40) == 0)) {
      if (_DAT_008073c2 < _DAT_00809a58) {
        DAT_008034b8 = DAT_008034b8 + 1;
        if (DAT_008073b5 <= DAT_008034b8) {
          _DAT_00805e56 = _DAT_00805e56 | 0x40;
          _DAT_00805e16 = _DAT_00805e16 & 0xfeff | 0x40;
          DAT_008034b8 = 0;
        }
      }
      else {
        DAT_008034b8 = 0;
      }
    }
    if (((_DAT_00805e16 & 0x80) == 0) || ((_DAT_008068e8 & 0x80) == 0)) {
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
        if (((_DAT_00805e16 & 0x800) == 0) || ((_DAT_008068e8 & 0x800) == 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (!bVar1) {
          if (((_DAT_00805e16 & 0x400) == 0) || ((_DAT_008068e8 & 0x400) == 0)) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          if (!bVar1) {
            if (((_DAT_00805e16 & 0x200) == 0) || ((_DAT_008068e8 & 0x200) == 0)) {
              bVar1 = false;
            }
            else {
              bVar1 = true;
            }
            if (((!bVar1) && (_DAT_00809a58 < _DAT_008073c4)) && (_DAT_008073b8 < _DAT_0080926e)) {
              if (_DAT_00809a58 == _DAT_008034b0) {
                DAT_008034ba = DAT_008034ba + 1;
                if (_DAT_008073c6 <= DAT_008034ba) {
                  _DAT_00805e16 = _DAT_00805e16 | 0x100;
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
        _DAT_00805e16 = _DAT_00805e16 & 0xffbf;
        DAT_008034b9 = 0;
      }
    }
    else {
      DAT_008034b9 = 0;
    }
    if (((_DAT_00805e16 & 0x100) != 0) && ((_DAT_008068e8 & 0x100) != 0)) {
      if ((int)_DAT_00809a58 - (int)_DAT_008034b2 < 0) {
        iVar2 = -((int)_DAT_00809a58 - (int)_DAT_008034b2);
      }
      else {
        iVar2 = (int)_DAT_00809a58 - (int)_DAT_008034b2;
      }
      if ((int)(uint)_DAT_008073c8 < iVar2) {
        _DAT_00805e16 = _DAT_00805e16 & 0xfeff;
      }
    }
    if (((_DAT_00805e16 & 0x80) == 0) || ((_DAT_008068e8 & 0x80) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    _DAT_00809a48 = 0x1700;
    if ((bVar1) && (_DAT_0080740a < 0x1700)) {
      _DAT_00809a48 = _DAT_0080740a;
    }
    if (((_DAT_00805e16 & 0x40) == 0) || ((_DAT_008068e8 & 0x40) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) && (_DAT_0080740c < _DAT_00809a48)) {
      _DAT_00809a48 = _DAT_0080740c;
    }
    if (((_DAT_00805e16 & 0x100) == 0) || ((_DAT_008068e8 & 0x100) == 0)) {
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
// Function: FUN_000341ea @ 0x000341ea
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000341ea(void)

{
  if (DAT_008034a1 != '\0') {
    if ((DAT_00809a5f & 1) != 0) {
      if ((_DAT_0080741e < _DAT_0080c404) && (_DAT_0080c404 <= _DAT_0080743c)) {
        DAT_008034bb = DAT_008034bb + 1;
        if (DAT_00807425 <= DAT_008034bb) {
          _DAT_00805e16 = _DAT_00805e16 | 0x20;
          _DAT_00805e56 = _DAT_00805e56 | 0x20;
          DAT_008034a0 = 1;
          DAT_0080348f = 1;
          DAT_008034bb = 0;
        }
      }
      else if (_DAT_0080743c < _DAT_0080c404) {
        DAT_008034bc = DAT_008034bc + 1;
        if (DAT_0080743e <= DAT_008034bc) {
          _DAT_00805e16 = _DAT_00805e16 | 0x20;
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
      _DAT_00805e16 = _DAT_00805e16 & 0xffdf;
      DAT_0080348f = 0;
      DAT_008034bd = 0;
    }
    DAT_008034bb = 0;
    DAT_008034bc = 0;
  }
  return;
}



//
// Function: FUN_000342f6 @ 0x000342f6
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000342f6(void)

{
  if (DAT_008034a1 != '\0') {
    if ((DAT_00809a5f & 2) != 0) {
      if ((_DAT_0080741e < _DAT_0080c404) && (_DAT_0080c404 <= _DAT_0080743c)) {
        DAT_008034be = DAT_008034be + 1;
        if (DAT_00807425 <= DAT_008034be) {
          _DAT_00805e16 = _DAT_00805e16 | 0x10;
          _DAT_00805e56 = _DAT_00805e56 | 0x10;
          _DAT_00809af8 = _DAT_00807428;
          DAT_008034be = 0;
        }
      }
      else if (_DAT_0080743c < _DAT_0080c404) {
        DAT_008034bf = DAT_008034bf + 1;
        if (DAT_0080743e <= DAT_008034bf) {
          _DAT_00805e16 = _DAT_00805e16 | 0x10;
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
      _DAT_00805e16 = _DAT_00805e16 & 0xffef;
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
      if ((_DAT_00807422 < _DAT_0080c404) && (_DAT_0080c404 <= _DAT_00807440)) {
        DAT_008034c1 = DAT_008034c1 + 1;
        if (DAT_00807424 <= DAT_008034c1) {
          _DAT_00805e16 = _DAT_00805e16 | 8;
          _DAT_00805e56 = _DAT_00805e56 | 8;
          DAT_008034c1 = 0;
        }
      }
      else if (_DAT_00807440 < _DAT_0080c404) {
        DAT_008034c2 = DAT_008034c2 + 1;
        if (DAT_0080743f <= DAT_008034c2) {
          _DAT_00805e16 = _DAT_00805e16 | 8;
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
        _DAT_00805e16 = _DAT_00805e16 & 0xfff7;
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
    _DAT_00809afa = FUN_000356f8();
    sVar1 = _DAT_00809afa;
    if (_DAT_00809a4e != 0) {
      sVar1 = FUN_000356f8();
    }
    _DAT_00809af4 = sVar1;
    _DAT_00809afc = _DAT_00809afa - _DAT_00809af4;
    if (((_DAT_00805e16 & 0x800) == 0) || ((_DAT_008068e8 & 0x800) == 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) {
      if (((_DAT_00805e16 & 0x400) == 0) || ((_DAT_008068e8 & 0x400) == 0)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (!bVar2) {
        if (((_DAT_00805e16 & 0x200) == 0) || ((_DAT_008068e8 & 0x200) == 0)) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if (!bVar2) {
          if ((DAT_00809a5f & 0x80) == 0) {
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
            switch(_DAT_0080c810) {
            case 2:
            case 6:
            case 7:
              if (_DAT_0080744e < _DAT_00809afc) {
                DAT_008034c6 = DAT_008034c6 + 1;
                if (DAT_00807402 <= DAT_008034c6) {
                  _DAT_00805e14 = _DAT_00805e14 | 2;
                  _DAT_00805e54 = _DAT_00805e54 | 2;
                  DAT_008034c6 = 0;
                }
                DAT_008034c8 = 0;
              }
              else {
                if ((_DAT_00809afc < _DAT_00807452) &&
                   (DAT_008034c8 = DAT_008034c8 + 1, DAT_00807402 <= DAT_008034c8)) {
                  _DAT_00805e14 = _DAT_00805e14 & 0xfffd;
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
                  _DAT_00805e14 = _DAT_00805e14 | 2;
                  _DAT_00805e54 = _DAT_00805e54 | 2;
                  DAT_008034c5 = 0;
                }
                DAT_008034c7 = 0;
              }
              else {
                if ((_DAT_00809afc < _DAT_00807450) &&
                   (DAT_008034c7 = DAT_008034c7 + 1, DAT_00807402 <= DAT_008034c7)) {
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
  
  if (DAT_008034a1 == '\0') {
    return;
  }
  if ((((DAT_00809a5e & 1) == 0) || (_DAT_00809a68 <= _DAT_00807414)) ||
     ((int)(uint)_DAT_00809af6 <= (int)_DAT_00809a68)) {
    _DAT_00805e16 = _DAT_00805e16 & 0xfffd;
    DAT_008034ce = 0;
  }
  else {
    DAT_008034ce = DAT_008034ce + 1;
    if (DAT_00807413 <= DAT_008034ce) {
      _DAT_00805e16 = _DAT_00805e16 | 2;
      _DAT_00805e56 = _DAT_00805e56 | 2;
      DAT_008034ce = 0;
    }
  }
  if ((DAT_008073ef != '\0') && (DAT_008034c9 == '\0')) {
    if ((((_DAT_0080742a < _DAT_0080926e) &&
         ((_DAT_008073dc < _DAT_0080c404 && (_DAT_0080c404 < _DAT_008073da)))) &&
        (_DAT_0080c9a4 < _DAT_008073d8)) && (_DAT_00809d50 == 0)) {
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
    if (((_DAT_00805e16 & 2) == 0) || ((_DAT_008068e8 & 2) == 0)) {
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
  if (DAT_008034a1 != '\0') {
    if ((DAT_00809a5e & 4) != 0) {
      if ((_DAT_008073b6 < _DAT_0080c9a4) && (_DAT_00807410 < _DAT_00809af4)) {
        _DAT_008034d0 = _DAT_008034d0 + 1;
        if (DAT_008073b4 < _DAT_008034d0) {
          _DAT_00805e16 = _DAT_00805e16 | 1;
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
      _DAT_00805e16 = _DAT_00805e16 & 0xfffe;
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
  
  if (DAT_008034a1 == '\0') {
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
  if (_DAT_0080c810 == 1) {
    DAT_008034d8 = 0;
    return;
  }
  if (_DAT_0080c810 == 8) {
    DAT_008034d8 = 0;
    return;
  }
  if (((_DAT_00805df6 & 0x1000) == 0) || ((_DAT_008068c8 & 0x1000) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if (((_DAT_00805df6 & 0x4000) == 0) || ((_DAT_008068c8 & 0x4000) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      _DAT_008034d4 = _DAT_008034d4 + 1;
      if (DAT_0080743a < _DAT_008034d4) {
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
  if (DAT_0080743a < _DAT_008034d6) {
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
  
  if ((DAT_008034a1 != '\0') && (1 < DAT_008034a4)) {
    if (((_DAT_00805e16 & 0x800) == 0) || ((_DAT_008068e8 & 0x800) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (((_DAT_00805e16 & 0x400) == 0) || ((_DAT_008068e8 & 0x400) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((_DAT_00805e16 & 0x200) == 0) || ((_DAT_008068e8 & 0x200) == 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (!bVar1) {
          if ((DAT_00809a5f & 4) != 0) {
            if (_DAT_00809d50 != 0) {
              if (_DAT_0080744a < _DAT_0080c404) {
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
          if (_DAT_00809d50 == 0) {
            if (_DAT_0080744a < _DAT_0080c404) {
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
  if (DAT_008034a1 != '\0') {
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
  
  if (DAT_008034a1 != '\0') {
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
        if (((_DAT_00805e16 & 0x800) == 0) || ((_DAT_008068e8 & 0x800) == 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (!bVar1) {
          if (((_DAT_00805e16 & 0x400) == 0) || ((_DAT_008068e8 & 0x400) == 0)) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          if (!bVar1) {
            if (((_DAT_00805e16 & 0x200) == 0) || ((_DAT_008068e8 & 0x200) == 0)) {
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
    if (((_DAT_00805e16 & 0x800) == 0) || ((_DAT_008068e8 & 0x800) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (((_DAT_00805e16 & 0x400) == 0) || ((_DAT_008068e8 & 0x400) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((_DAT_00805e16 & 0x200) == 0) || ((_DAT_008068e8 & 0x200) == 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (!bVar1) {
          if ((((_DAT_00809a54 == 0) && (_DAT_00807442 < _DAT_0080c404)) &&
              (_DAT_00807420 < _DAT_00809a5c)) &&
             (DAT_008034e6 = DAT_008034e6 + 1, DAT_0080739c <= DAT_008034e6)) {
            _DAT_00805e14 = _DAT_00805e14 | 1;
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
    if (((_DAT_00805e16 & 0x800) == 0) || ((_DAT_008068e8 & 0x800) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (((_DAT_00805e16 & 0x400) == 0) || ((_DAT_008068e8 & 0x400) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (((_DAT_00805e16 & 0x200) == 0) || ((_DAT_008068e8 & 0x200) == 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (!bVar1) {
          if (_DAT_0080c404 <= _DAT_00807444) {
            return;
          }
          if ((int)((uint)_DAT_0080c404 - (uint)_DAT_00809a4e) < 0) {
            iVar2 = -((uint)_DAT_0080c404 - (uint)_DAT_00809a4e);
          }
          else {
            iVar2 = (uint)_DAT_0080c404 - (uint)_DAT_00809a4e;
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
      DAT_008034a0 = 1;
    }
    if ((DAT_00809a6b & 0x10) != 0) {
      _DAT_00805e14 = _DAT_00805e14 | 0x10;
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
// Function: FUN_00035298 @ 0x00035298
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00035298(void)

{
  bool bVar1;
  
  if (DAT_008034a1 != '\0') {
    if (((_DAT_00805e14 & 0x20) == 0) || ((_DAT_008068e6 & 0x20) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      if (DAT_0080348a != '\0') {
        _DAT_00805e16 = _DAT_00805e16 & 0xf1ff;
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
          _DAT_00805e16 = _DAT_00805e16 | 0x800;
          _DAT_00805e56 = _DAT_00805e56 | 0x800;
          break;
        case 2:
          _DAT_00805e16 = _DAT_00805e16 | 0x200;
          _DAT_00805e56 = _DAT_00805e56 | 0x200;
          break;
        case 4:
        case 5:
          _DAT_00805e16 = _DAT_00805e16 | 0x400;
          _DAT_00805e56 = _DAT_00805e56 | 0x400;
          break;
        default:
          _DAT_00805e16 = _DAT_00805e16 | 0x800;
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
// Function: FUN_000353ec @ 0x000353ec
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte FUN_000353ec(void)

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
// Function: FUN_0003544a @ 0x0003544a
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0003544a(void)

{
  _DAT_0080c9c6 = (ushort)DAT_008034a0;
  if (((_DAT_0080c810 != 5) && (_DAT_0080c810 != 8)) && (DAT_008034a0 != 1)) {
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
  if ((((((_DAT_00803614 & 0x2000) != 0) && (_DAT_0080cffc != 1)) && (_DAT_0080cffc != 2)) &&
      ((_DAT_0080d17a == 0 && (_DAT_0080969a == 0)))) &&
     ((_DAT_00809d50 == 0 &&
      ((uVar2 = _DAT_00809b00, _DAT_008077b8 < _DAT_00809b00 &&
       (uVar2 = _DAT_0080c404, _DAT_008077ba < _DAT_0080c404)))))) {
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
// Function: FUN_00035560 @ 0x00035560
//

short FUN_00035560(short *param_1)

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
// Function: FUN_000356f8 @ 0x000356f8
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
// Function: FUN_000357e4 @ 0x000357e4
//

undefined4 FUN_000357e4(int param_1,int param_2,int param_3)

{
  return (int)(((longlong)(int)((ulonglong)((longlong)param_2 * (longlong)param_1) >> 0x20) << 0x20
               | (longlong)(int)((longlong)param_2 * (longlong)param_1)) / (longlong)param_3);
}



//
// Function: FUN_000357f6 @ 0x000357f6
//

undefined8 FUN_000357f6(short *param_1)

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



//
// Function: FUN_00038528 @ 0x00038528
//

/* WARNING: Control flow encountered bad instruction data */

void FUN_00038528(void)

{
  short in_D0w;
  byte in_D1b;
  int unaff_A3;
  int unaff_A4;
  byte *pbVar1;
  
  pbVar1 = (byte *)(unaff_A4 + -1);
  *pbVar1 = (byte)in_D0w;
  *pbVar1 = *pbVar1 | '\x01' << ((in_D1b | 0x15) & 7);
  *(byte *)(unaff_A3 + in_D0w) = *(byte *)(unaff_A3 + in_D0w) | 0x1f;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//
// Function: FUN_00038547 @ 0x00038547
//

/* WARNING: Control flow encountered bad instruction data */

void FUN_00038547(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//
// Function: FUN_0003854f @ 0x0003854f
//

/* WARNING: Control flow encountered bad instruction data */

void FUN_0003854f(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//
// Function: FUN_0003877e @ 0x0003877e
//

/* WARNING: Control flow encountered bad instruction data */

void FUN_0003877e(void)

{
  int unaff_A2;
  
  *(undefined1 *)(unaff_A2 + 0x4b) = *(undefined1 *)(unaff_A2 + 0x4b);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// Export complete - 782 functions processed
