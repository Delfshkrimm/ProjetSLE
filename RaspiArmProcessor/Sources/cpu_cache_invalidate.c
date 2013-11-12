#include <stdint.h>
#include <Processor/Processor.h>

void cpu_cache_invalidate (cpu_cache_t cache_type,
    void * address, int32_t words)
{
  register int32_t count = 0;
  register uint32_t adjusted_address = (uint32_t)address & 0xFFFFFFF0UL;

  switch (cache_type) 
  {
    case CPU_CACHE_INSTRUCTION :
      {
        if (words == CPU_CACHE_ALL)
        {
          __asm__ volatile ("mcr p15, 0, %0, c7, c5, 0" : : "r"(count));
        }
        else
        {
          count = words >> CPU_DCACHE_SIZE_LOG2;
          count += (words - (count << CPU_DCACHE_SIZE_LOG2) != 0) ? 1 : 0;

          for (register int32_t i = 0; i < count; i += 1)
          {
            __asm__ volatile ("mcr p15, 0, %0, c7, c5, 1" : : "r"(count));
            address += 1 << CPU_ICACHE_SIZE_LOG2;
          }
        }

        break;
      }

     case CPU_CACHE_DATA :
      {
        if (words == CPU_CACHE_ALL)
        {
          __asm__ volatile ("mcr p15, 0, %0, c7, c6, 0" : : "r"(count));
        }
        else
        {
          count = words >> CPU_DCACHE_SIZE_LOG2;
          count += (words - (count << CPU_DCACHE_SIZE_LOG2) != 0) ? 1 : 0;

          for (register int32_t i = 0; i < count; i += 1)
          {
            __asm__ volatile ("mcr p15, 0, %0, c7, c6, 1"
                :
                : "r"(adjusted_address));

            adjusted_address += 4 << CPU_DCACHE_SIZE_LOG2;
          }
        }

        break;
      }
  }
}
