#include <Processor/Processor.h>

void cpu_power_wake_on_interrupt (void)
{
  register int32_t id = 0;

  __asm__ volatile (
      "mrc p15,0,%0,c7,c0,4"
      : "=r"(id)
      :
      );
}
