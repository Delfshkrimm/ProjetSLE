#ifndef PROCESSOR_TIMER_H
#define PROCESSOR_TIMER_H

#include <stdint.h>

/****t* time/bigtime_t
 * SUMMARY
 * 64-bit precision time type.
 *
 * SOURCE
 */

typedef int64_t bigtime_t;

/*
 ****/

extern void cpu_timer_set (int32_t id, bigtime_t quantum);
extern void cpu_timer_get (int32_t id, bigtime_t * value);
extern void cpu_timer_cancel (int32_t id);

extern int32_t cpu_timer_handler (void * data);

#endif

