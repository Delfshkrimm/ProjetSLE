#ifndef PROCESSOR_CACHE_H
#define PROCESSOR_CACHE_H

#include <stdint.h>

typedef enum cpu_cache
{
  CPU_CACHE_INSTRUCTION,
  CPU_CACHE_DATA
}
cpu_cache_t;

#define CPU_ICACHE_SIZE_LOG2 3
#define CPU_DCACHE_SIZE_LOG2 3

#define CPU_CACHE_ALL 0xFFFFFFFF

#define cpu_cache_sync()                      \
{                                             \
  volatile register int32_t dummy = 0;        \
                                              \
  __asm__ volatile (                          \
      "mcr p15,0,%0,c7,c10,4"                 \
      :                                       \
      : "r"(dummy)                            \
      );                                      \
}

extern void cpu_cache_invalidate (cpu_cache_t cache_type,
    void * address, int32_t words);

#endif

