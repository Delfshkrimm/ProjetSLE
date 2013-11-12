#ifndef PROCESSOR_CONTEXT_H
#define PROCESSOR_CONTEXT_H

#include <stdint.h>

typedef volatile uint32_t cpu_context_t [19];
#define CPU_CONTEXT_SIZE sizeof(cpu_context_t) 

extern void cpu_context_init (cpu_context_t *, void *, int32_t, void *, void *);
extern void cpu_context_save (cpu_context_t *, uint32_t *);
extern void cpu_context_load (cpu_context_t *);

#endif

