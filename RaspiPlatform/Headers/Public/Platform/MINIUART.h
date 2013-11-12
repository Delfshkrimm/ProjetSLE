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

#ifndef PLATFORM_MINIUART_H
#define PLATFORM_MINIUART_H

#define GPFSEL1 0x20200004
#define GPSET0  0x2020001C
#define GPCLR0  0x20200028
#define GPPUD       0x20200094
#define GPPUDCLK0   0x20200098

typedef volatile struct _raspi_miniuart
{
   uint32_t AUX_IRQ;                /* 00 */  
   uint32_t AUX_ENABLES;            /* 04 */
   uint32_t PAD0[14];               /*    */
   uint32_t AUX_MU_IO_REG;          /* 40 */
   uint32_t AUX_MU_IER_REG;         /* 44 */
   uint32_t AUX_MU_IIR_REG;         /* 48 */
   uint32_t AUX_MU_LCR_REG;         /* 4C */
   uint32_t AUX_MU_MCR_REG;         /* 50 */
   uint32_t AUX_MU_LSR_REG;         /* 54 */
   uint32_t AUX_MU_MSR_REG;         /* 58 */
   uint32_t AUX_MU_SCRATCH;         /* 5C */
   uint32_t AUX_MU_CNTL_REG;        /* 60 */
   uint32_t AUX_MU_STAT_REG;        /* 64 */
   uint32_t AUX_MU_BAUD_REG;        /* 68 */
   uint32_t PAD1[6];                /*    */
   uint32_t AUX_SPI0_CNTL0_REG;     /* 80 */
   uint32_t AUX_SPI0_CNTL1_REG;     /* 84 */
   uint32_t AUX_SPI0_STAT_REG;      /* 88 */
   uint32_t PAD2[1];                /*    */
   uint32_t AUX_SPI0_IO_REG;        /* 90 */
   uint32_t AUX_SPI0_PEEK_REG;      /* 94 */
   uint32_t PAD3[2];                /*    */
   uint32_t AUX_SPI1_CNTL0_REG;     /* C0 */
   uint32_t AUX_SPI1_CNTL1_REG;     /* C4 */
   uint32_t AUX_SPI1_STAT_REG;      /* C8 */
   uint32_t PAD4[1];                /*    */
   uint32_t AUX_SPI1_IO_REG;        /* D0 */
   uint32_t AUX_SPI1_PEEK_REG;      /* D4 */
}
raspi_miniuart_t;

enum
{
   MINIUART_AUX_UART_ENABLE = 0x00000001,
   MINIUART_AUX_SPI1_ENABLE = 0x00000002,
   MINIUART_AUX_SPI2_ENABLE = 0x00000004,
};

enum
{
   MINIUART_IER_IR_DISABLE  = 0x00000000,
   MINIUART_IER_TXIR_ENABLE = 0x00000001,
   MINIUART_IER_RXIR_ENABLE = 0x00000002
};

enum
{
   MINIUART_CNTL_RXTX_DISABLE  = 0x00000000,
   MINIUART_CNTL_RX_ENABLE     = 0x00000001,
   MINIUART_CNTL_TX_ENABLE     = 0x00000002
};

enum
{
   MINIUART_LCR_7BITS     = 0x00000000,
   MINIUART_LCR_8BITS     = 0x00000003
};

enum
{
   MINIUART_MCR_MAGIC     = 0x00000000
};

enum
{
   MINIUART_LSR_TX_IDLE     = 0x00000020,
   MINIUART_LSR_TX_EMPTY    = 0x00000010,
   MINIUART_LSR_RX_OVERRUN  = 0x00000002,
   MINIUART_LSR_RX_READY    = 0x00000001
};

enum
{
   MINIUART_IIR_RX_CLEAR  = 0x00000002,
   MINIUART_IIR_TX_CLEAR  = 0x00000004
};

/* Add your own speed if necessary:
 * ((250,000,000/115200)/8)-1 = 270
 */
enum
{
   MINIUART_BAUD_115200   = 270,
};

#endif

