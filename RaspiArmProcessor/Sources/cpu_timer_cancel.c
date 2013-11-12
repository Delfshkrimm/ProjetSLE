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
 */

#include <stdint.h>
#include <Private/Timer.h>
#include <Processor/Processor.h>
#include <Platform/Platform.h>

void cpu_timer_cancel (int32_t id)
{
#if 0
  uint32_t value = 0, current_deadline = 0, mode;
  uint32_t cpiv, picnt;
  interrupt_status_t status;

  /*
   * Get the current value of the timer and
   * add it up to the local counter. Disable the timer.
   */

  status = cpu_trap_mask_and_backup ();
  cpu_read (UINT32, & (PLATFORM_SYSC_BASE -> PIT_PIVR), value);
  cpu_read (UINT32, & (PLATFORM_SYSC_BASE -> PIT_MODE), current_deadline);
  cpu_write (UINT32, & (PLATFORM_SYSC_BASE -> PIT_MODE), 0);

  cpiv = value & 0xFFFFFUL;
  picnt = (value & 0xFFF00000UL) >> 20;
  current_deadline &= 0xFFFFFUL;

  /*
   * On multiplie par 160, qui est le nombre de nanosecondes
   * pour chaque tick @ 100 Mhz en master clock.
   */

  cpu_timer_local_counter += (cpiv + (picnt * current_deadline)) * 160;
  cpu_timer_local_deadline = 0;
  cpu_trap_restore (status);

  /*
   * Program the next counter event.
   */

  mode = 0x03FFFFFFUL;
  cpu_write (UINT32, & (PLATFORM_SYSC_BASE -> PIT_MODE), mode);
#else
  cpu_timer_local_deadline = 0;
#endif
}

