#include <stdint.h>
#include <Processor/Processor.h>

void cpu_mp_wait (void)
{
  cpu_mp_synchro = 1;

  /*
   * TODO: add WBFLUSH
   */

  while ((volatile int32_t)cpu_mp_synchro);
}

