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

#ifndef PLATFORM_AIC_H
#define PLATFORM_AIC_H

#include <stdint.h>

typedef struct _d940_aic
{
	uint32_t SMR[32];
	uint32_t SVR[32];
	uint32_t IVR;
	uint32_t FVR;
	uint32_t ISR;
	uint32_t IPR;
	uint32_t IMR;
	uint32_t CISR;
	uint32_t RESERVED_0;
	uint32_t RESERVED_1;
	uint32_t IECR;
	uint32_t IDCR;
	uint32_t ICCR;
	uint32_t ISCR;
	uint32_t EOICR;
	uint32_t SPU;
	uint32_t DCR;
	uint32_t RESERVED_2;
	uint32_t FFER;
	uint32_t FFDR;
	uint32_t FFSR;
}
* d940_aic_t;

extern d940_aic_t PLATFORM_AIC_BASE;

#endif

