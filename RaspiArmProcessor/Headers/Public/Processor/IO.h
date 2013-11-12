#ifndef PROCESSOR_IO_H
#define PROCESSOR_IO_H

#include <stdint.h>

/*
 *  * External assembly vector operation.
 *   */

extern void cpu_vector_transfer (void * source,
        void * destination, uint32_t count);

/*
 *  * Write operations.
 *   */

#define cpu_write(type,addr,value) cpu_write_##type(addr,value)

#define cpu_write_UINT8(addr,value)                                   \
    *((volatile uint8_t *)(addr)) = (uint8_t)(value)

#define cpu_write_UINT16(addr,value)                                  \
    *((volatile uint16_t *)(addr)) = (uint16_t)(value)

#define cpu_write_UINT32(addr,value)                                  \
    *((volatile uint32_t *)(addr)) = (uint32_t)(value)

/*
 *  * Read operations.
 *   */

#define cpu_read(type,addr,value) cpu_read_##type(addr,value)

#define cpu_read_UINT8(addr,value)                                    \
    (value) = (__typeof__(value))*((volatile uint8_t *) (addr))

#define cpu_read_UINT16(addr, value)                                  \
    (value) = (__typeof__(value))*((volatile uint16_t *) (addr))

#define cpu_read_UINT32(addr,value)                                   \
    (value) = (__typeof__(value))*((volatile uint32_t *) (addr))

/*
 *  * Uncached operations.
 *   */

#define cpu_uncached_write(type,addr,value) cpu_write(type,addr,value)
#define cpu_uncached_read(type,addr,value) cpu_read(type,addr,value)

#define cpu_vector_write(mode,to,from,len) cpu_vector_write_##mode(to,from,len)

/*
 *  * Vector operations
 *   */

#define cpu_vector_write_DFLOAT(to,from,len)                          \
{                                                                     \
    for (uint32_t i = 0; i < len; i++)                                  \
      ((volatile double *)to)[i] = ((volatile double *)from)[i];        \
}

#define cpu_vector_write_SFLOAT(to,from,len)                          \
{                                                                     \
    for (uint32_t i = 0; i < len; i++)                                  \
      ((volatile float *)to)[i] = ((volatile float *)from)[i];          \
}

#define cpu_vector_write_UINT64(to,from,len)                          \
{                                                                     \
    volatile uint64_t * ulli_to, * ulli_from;                           \
                                                                        \
    ulli_to = (volatile uint64_t *) to;                                 \
    ulli_from = (volatile uint64_t *) from;                             \
                                                                        \
    for (uint32_t i = 0; i < len; i++)                                  \
      ulli_to[i] = ulli_from[i];                                        \
}

#define cpu_vector_write_UINT32(to,from,len)                          \
    cpu_vector_transfer (from, to, len << 2)

#define cpu_vector_write_UINT16(to,from,len)                          \
    cpu_vector_transfer (from, to, len << 1)

#define cpu_vector_write_UINT8(to,from,len)                           \
    cpu_vector_transfer (from, to, len)

#define cpu_vector_read(mode,to,from,len) cpu_vector_write_##mode(to,from,len)

#endif
