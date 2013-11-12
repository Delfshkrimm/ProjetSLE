#include <Platform/MINIUART.h>
/* TODO: Use the GPIO stuff when available */
#if 0
#include <Processor/GPIO.h>
#endif

#define GPFSEL1     0x20200004
#define GPSET0      0x2020001C
#define GPCLR0      0x20200028
#define GPPUD       0x20200094
#define GPPUDCLK0   0x20200098

//GPIO14  TXD0 and TXD1
//GPIO15  RXD0 and RXD1
//alt function 5 for uart1
//alt function 0 for uart0

static bool uart_initialized = 0;

static uart_init(void)
{
   volatile unsigned int ra;
   cpu_write(UINT32, &PLATFORM_MINIUART_BASE->AUX_ENABLES,      MINIUART_AUX_UART_ENABLE);
   cpu_write(UINT32, &PLATFORM_MINIUART_BASE->AUX_MU_IER_REG,   MINIUART_IER_IR_DISABLE);
   cpu_write(UINT32, &PLATFORM_MINIUART_BASE->AUX_MU_CNTL_REG,  MINIUART_CNTL_RXTX_DISABLE);
   cpu_write(UINT32, &PLATFORM_MINIUART_BASE->AUX_MU_LCR_REG,   MINIUART_LCR_8BITS);
   cpu_write(UINT32, &PLATFORM_MINIUART_BASE->AUX_MU_MCR_REG,   MINIUART_MCR_MAGIC);
   cpu_write(UINT32, &PLATFORM_MINIUART_BASE->AUX_MU_IIR_REG,   MINIUART_IIR_RX_CLEAR|MINIUART_IIR_TX_CLEAR);
   cpu_write(UINT32, &PLATFORM_MINIUART_BASE->AUX_MU_BAUD_REG,  MINIUART_BAUD_115200);

   /* TODO: Update once GPIO done */
   cpu_read(UINT32, GPFSEL1, ra);
   ra &= ~(7 << 12);               //gpio14
   ra |= 2 << 12;                  //alt5
   cpu_write(UINT32, GPFSEL1, ra);

   cpu_write(UINT32, GPPUD, 0);
   for (ra = 0; ra < 150; ra++);
   cpu_write(UINT32, GPPUDCLK0, (1 << 14));
   for (ra = 0; ra < 150; ra++);
   cpu_write(UINT32, GPPUDCLK0, 0);

   cpu_write(UINT32, &PLATFORM_MINIUART_BASE->AUX_MU_CNTL_REG, MINIUART_CNTL_RX_ENABLE|MINIUART_CNTL_TX_ENABLE);
}

void platform_debug_puts (char *string)
{
  uint32_t res = 0;

  for (int32_t i = 0; string[i] != '\0'; i += 1)
  {
    do cpu_read (UINT32, &PLATFORM_MINIUART_BASE->AUX_MU_LSR_REG, res);
    while ((res & MINIUART_LSR_TX_IDLE) != MINIUART_LSR_TX_IDLE);

    cpu_write (UINT32, &PLATFORM_MINIUART_BASE->AUX_MU_IO_REG, string[i]);
  }
}
