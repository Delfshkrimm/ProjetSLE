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

int32_t cpu_timer_handler (void * data)
{
  uint32_t main_freq = 0, pll_clock = 0, master_clock = 0;
  uint32_t plla_config = 0, plla_mula = 0, plla_diva = 0;
  uint32_t clock_freq = 0, value = 0, current_deadline = 0;
  uint32_t cpiv = 0, picnt = 0, cycle_ns = 0;

  /*
   * Get the current master clock.
   */

  cpu_read (UINT32, & (PLATFORM_PMC_BASE -> MCFR), main_freq);
  main_freq = ((uint32_t)(main_freq & 0x0000FFFF)) << 11; 

  cpu_read (UINT32, & (PLATFORM_PMC_BASE -> PLLAR), plla_config);
  plla_mula = ((uint32_t)(plla_config & 0x07FF0000)) >> 16; 
  plla_diva = plla_config & 0x0000000F;

  pll_clock = (plla_mula * main_freq) / plla_diva;
  master_clock = pll_clock >> 1;

  clock_freq = master_clock >> 4;
  cycle_ns = ((bigtime_t)1e9 / clock_freq) + 1;

  /*
   * Get the current value of the timer and
   * add it up to the local counter. Disable the timer.
   */

  cpu_read (UINT32, & (PLATFORM_SYSC_BASE -> PIT_PIVR), value);
  cpu_read (UINT32, & (PLATFORM_SYSC_BASE -> PIT_MODE), current_deadline);

  cpiv = value & 0xFFFFFUL;
  picnt = (value & 0xFFF00000UL) >> 20;
  current_deadline &= 0xFFFFFUL;

  /*
   * On multiplie par 160, qui est le nombre de nanosecondes
   * pour chaque tick @ 100 Mhz en master clock.
   */

  cpu_timer_local_counter += (cpiv + (picnt * current_deadline)) * cycle_ns; 

  /*
   * Check the local deadline. Depending on its value, calls
   * the timer_callback or not.
   */

  if (cpu_timer_local_deadline != 0)
  {
    if (cpu_timer_local_counter >= cpu_timer_local_deadline) 
    {
      cpu_timer_local_deadline = 0;
      return alarm_handler ();
    }
  }

  return 0;
}

