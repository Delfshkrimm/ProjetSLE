#include <Processor/Processor.h>
#include <Platform/Platform.h>

void cpu_trap_disable (interrupt_id_t id)
{
  uint32_t mask = 1 << id;
  PLATFORM_AIC_BASE -> IDCR = mask;
}

