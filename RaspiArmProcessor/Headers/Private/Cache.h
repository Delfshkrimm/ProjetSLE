#ifndef CPU_CACHE_PRIVATE_H
#define CPU_CACHE_PRIVATE_H

#include <stdint.h>

#define cpu_cache_ttb_word(address, ap, domain, c, b)												\
	(address << 20 | ap << 10 | domain << 5 | 0x1 << 4 | c << 3 | b << 2 | 0x2)

#endif

