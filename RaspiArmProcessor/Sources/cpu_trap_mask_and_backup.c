#include <Processor/Processor.h>

interrupt_status_t cpu_trap_mask_and_backup (void)
{
  interrupt_status_t cpsr = 0;

  __asm__ volatile (
      "mrs r0, cpsr\n"
      "mov %0, r0\n"
      "orr r0, r0, #0xC0\n"
      "msr cpsr, r0\n"
      : "=r"(cpsr)
      :
      : "r0"
      );

  return cpsr;
}

