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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the 
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program.If not, see <http://www.gnu.org/licenses/>. 
 */

#include <stdint.h>
#include <Platform/PDC.h>

#ifndef PLATFORM_MCI_H
#define PLATFORM_MCI_H

#define MCI_INITIAL_SPEED 400000

typedef volatile struct _d940_mci
{
	uint32_t CR;
	uint32_t MR;
	uint32_t DTR;
	uint32_t SDCR;
	uint32_t ARGR;
	uint32_t CMDR;
	uint32_t BLKR;
	uint32_t RESERVED_0;
	uint32_t RESPR[4];
	uint32_t RDR;
	uint32_t TDR;
	uint32_t RESERVED_1[2];
	uint32_t SR;
	uint32_t IER;
	uint32_t IDR;
	uint32_t IMR;
	uint32_t RESERVED_2[44];
	d940_pdc_t PDC;
}
* d940_mci_t;

extern d940_mci_t PLATFORM_MCI_BASE;

#endif

