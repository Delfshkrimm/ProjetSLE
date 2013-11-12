/*
 * Copyright (C) 2007 TIMA Laboratory                                    
 *                                                                       
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, either version 3 of the License, or     
 * (at your option) any later version.                                   
 *                                                                       
 * This program is distributed in the hope that it will be useful,       
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         
 * GNU General Public License for more details.                          
 *                                                                       
 * You should have received a copy of the GNU General Public License     
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. 
 **/

#ifndef PLATFORM_BMX_H
#define PLATFORM_BMX_H

#include <stdint.h>

typedef struct _d940_bmx
{
  /*
   * Master configurations registers.
   * Start @ 0x0000.
   */

  uint32_t MCFG0;
  uint32_t MCFG1;
  uint32_t MCFG2;
  uint32_t MCFG3;
  uint32_t MCFG4;
  uint32_t MCFG5;
  uint32_t MCFG6;

  uint32_t pad0[9];

  /*
   * Slave configuration registers.
   * Start @ 0x0040.
   */

  uint32_t SCFG0;
  uint32_t SCFG1;
  uint32_t SCFG2;
  uint32_t SCFG3;
  uint32_t SCFG4;

  uint32_t pad1[11];

  /*
   * Priority registers.
   * Start @ 0x0080.
   */

  uint32_t PRAS0;
  uint32_t PRBS0;
  uint32_t PRAS1;
  uint32_t PRBS1;
  uint32_t PRAS2;
  uint32_t PRBS2;
  uint32_t PRAS3;
  uint32_t PRBS3;
  uint32_t PRAS4;
  uint32_t PRBS4;

  uint32_t pad2[22];

  /*
   * Master remap control register.
   * Start @ 0x0100.
   */

  uint32_t MRCR;

  uint32_t pad3[3];

  /*
   * Special function registers.
   * Start @ 0x0100.
   */

  uint32_t SFR0;
  uint32_t SFR1;
  uint32_t SFR2;
  uint32_t SFR3;
  uint32_t SFR4;
  uint32_t SFR5;
  uint32_t SFR6;
  uint32_t SFR7;
  uint32_t SFR8;
  uint32_t SFR9;
  uint32_t SFR10;
}
* d940_bmx_t;

extern d940_bmx_t PLATFORM_BMX_BASE;

#endif

