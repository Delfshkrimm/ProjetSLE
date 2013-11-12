#include <Processor/Processor.h>

void cpu_trap_restore (interrupt_status_t backup)
{
  __asm__ volatile ("msr cpsr, %0" : : "r"(backup));
}

