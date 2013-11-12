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

#ifndef PLATFORM_PIO_H
#define PLATFORM_PIO_H

typedef volatile struct _d940_pio
{
	unsigned long int PER;
	unsigned long int PDR;
	unsigned long int PSR;
	unsigned long int RESERVED_0;
	unsigned long int OER;
	unsigned long int ODR;
	unsigned long int OSR;
	unsigned long int RESERVED_1;
	unsigned long int IFER;
	unsigned long int IFDR;
	unsigned long int IFSR;
	unsigned long int RESERVED_2;
	unsigned long int SODR;
	unsigned long int SOCR;
	unsigned long int ODSR;
	unsigned long int PDSR;
	unsigned long int IER;
	unsigned long int IDR;
	unsigned long int IMR;
	unsigned long int ISR;
	unsigned long int MDER;
	unsigned long int MDDR;
	unsigned long int MDSR;
	unsigned long int RESERVED_3;
	unsigned long int PUDR;
	unsigned long int PUER;
	unsigned long int PUSR;
	unsigned long int RESERVED_4;
	unsigned long int ASR;
	unsigned long int BSR;
	unsigned long int ABSR;
	unsigned long int RESERVED_5[9];
	unsigned long int OWER;
	unsigned long int OWDR;
	unsigned long int OWSR;
	unsigned long int RESERVED_6;
}
* d940_pio_t;

extern d940_pio_t PLATFORM_PIOA_BASE;
extern d940_pio_t PLATFORM_PIOB_BASE;
extern d940_pio_t PLATFORM_PIOC_BASE;

#endif

