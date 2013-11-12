#include <Private/Timer.h>
#include <Processor/Processor.h>
#include <Platform/Platform.h>

/*
 * Timer-related definitions."
 */

bigtime_t cpu_timer_local_counter = 0;
bigtime_t cpu_timer_local_deadline = 0;
