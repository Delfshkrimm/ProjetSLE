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

#include <Private/Timer.h>
#include <Processor/Processor.h>
#include <Platform/Platform.h>

void cpu_timer_get (int32_t id, bigtime_t * value)
{
  uint32_t current_value = 0, deadline = 0;
  uint32_t cpiv, picnt;
  bigtime_t delta;
  interrupt_status_t status;

  status = cpu_trap_mask_and_backup ();
  cpu_read (UINT32, & (PLATFORM_SYSC_BASE -> PIT_PIIR), current_value);
  cpu_read (UINT32, & (PLATFORM_SYSC_BASE -> PIT_MODE), deadline);
  cpu_trap_restore (status);

  cpiv = current_value & 0xFFFFFUL;
  picnt = (current_value & 0xFFF00000UL) >> 20;
  deadline &= 0xFFFFFUL;

  /*
   * On multiplie par 160, qui est le nombre de nanosecondes
   * pour chaque tick @ 100 Mhz en master clock. On refait le calcul complet au
   * cas où nous aurions raté une interruption.
   */

  delta = (cpiv + (picnt * deadline)) * 160;
  *value = cpu_timer_local_counter + delta;
}

