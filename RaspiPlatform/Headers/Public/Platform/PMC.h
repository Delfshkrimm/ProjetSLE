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

#ifndef D940_PMC_H
#define D940_PMC_H

#include <stdint.h>

#define PLLA_MULA_160 40
#define PLLA_MULA_200 49

#define PLLA_MULA PLLA_MULA_200

typedef volatile struct _d940_pmc
{
	uint32_t SCER;
	uint32_t SCDR;
	uint32_t SCSR;
	uint32_t RESERVED_0;
	uint32_t PCER;
	uint32_t PCDR;
	uint32_t PCSR;
	uint32_t RESERVED_1;
	uint32_t MOR;
	uint32_t MCFR;
	uint32_t PLLAR;
	uint32_t PLLBR;
	uint32_t MCR;
	uint32_t RESERVED_2[3];
	uint32_t PCK0;
	uint32_t PCK1;
	uint32_t RESERVED_3[6];
	uint32_t IER;
	uint32_t IDR;
	uint32_t SR;
	uint32_t IMR;
	uint32_t RESERVED_4[4];
	uint32_t PLLICPR;
}
* d940_pmc_t;

enum
{
	PMC_SCEDR_UHP 			= 0x00000040,
	PMC_SCEDR_UDP 			= 0x00000080,
	PMC_SCEDR_PCK			 	= 0x00000001,
	PMC_SCEDR_PCK_0 		= 0x00000100,
	PMC_SCEDR_PCK_1 		= 0x00000200,
	PMC_SCEDR_PCK_2 		= 0x00000400,
	PMC_SCEDR_PCK_3 		= 0x00000800,
	PMC_SCEDR_PCK_4 		= 0x00001000
};

extern d940_pmc_t PLATFORM_PMC_BASE;

#endif

