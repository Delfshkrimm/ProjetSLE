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

#ifndef PLATFORM_SYSC_H
#define PLATFORM_SYSC_H

#include <stdint.h>

typedef volatile struct _d940_sysc
{
	uint32_t RSTC_CONTROL;
	uint32_t RSTC_STATUS;
	uint32_t RSTC_MODE;
	uint32_t RESERVED[5];
	uint32_t RTT_MODE;
	uint32_t RTT_ALARM;
	uint32_t RTT_VALUE;
	uint32_t RTT_STATUS;
	uint32_t PIT_MODE;
	uint32_t PIT_STATUS;
	uint32_t PIT_PIVR;
	uint32_t PIT_PIIR;
	uint32_t WDT_CONTROL;
	uint32_t WDT_MODE;
	uint32_t WDT_STATUS;
}
* d940_sysc_t;

extern d940_sysc_t PLATFORM_SYSC_BASE;

#endif

