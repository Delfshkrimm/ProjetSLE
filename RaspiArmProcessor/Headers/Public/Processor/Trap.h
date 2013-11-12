#ifndef PROCESSOR_TRAP_H
#define PROCESSOR_TRAP_H

#include <stdint.h>

#define CPU_TRAP_COUNT 32

typedef enum exception_id
{
  cpu_trap_data_abort,
  cpu_trap_prefetch_abort,
  cpu_trap_undefined
}
exception_id_t;

typedef uint32_t interrupt_id_t;
typedef uint32_t interrupt_status_t;
typedef int32_t (* exception_handler_t) (void);
typedef int32_t (* interrupt_handler_t) (void * data);

extern void cpu_trap_attach_esr (int32_t cpuid, exception_id_t id,
    exception_handler_t isr);
extern void cpu_trap_attach_isr (int32_t cpuid, interrupt_id_t id,
    uint32_t mode, interrupt_handler_t isr);

extern interrupt_status_t cpu_trap_mask_and_backup (void);
extern void cpu_trap_restore (interrupt_status_t backup);

extern void cpu_trap_enable (interrupt_id_t id);
extern void cpu_trap_disable (interrupt_id_t id);

#endif

