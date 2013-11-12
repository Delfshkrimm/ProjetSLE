#ifndef PROCESSOR_ENDIAN_H
#define PROCESSOR_ENDIAN_H

#include <Platform/Platform.h>

#define CPU_ENDIANNESS CPU_LITTLE_ENDIAN

typedef enum _cpu_endianness
{
  CPU_LITTLE_ENDIAN,
  CPU_BIG_ENDIAN
}
cpu_endianness_t;

#define SWITCH_ENDIAN_64(x)                                                \
  x =  ((x & 0x00000000000000ff) << 56) | ((x & 0x000000000000ff00) << 40) \
     | ((x & 0x0000000000ff0000) << 24) | ((x & 0x00000000ff000000) <<  8) \
     | ((x & 0xff00000000000000) >> 56) | ((x & 0x00ff000000000000) >> 40) \
     | ((x & 0x0000ff0000000000) >> 24) | ((x & 0x000000ff00000000) >>  8)

#define SWITCH_ENDIAN_32(x)                                       \
  x =  ((x & 0x000000ff) << 24) | ((x & 0x0000ff00) << 8)  |      \
  ((x & 0x00ff0000) >> 8)  | ((x & 0xff000000) >> 24)       

#define SWITCH_ENDIAN_16(x) x = ((x & 0x00ff) << 8) |  ((x & 0xff00) >> 8)

#define cpu_data_is_big_endian(type,data) SWITCH_ENDIAN_##type(data)
#define cpu_data_is_little_endian(type,data)

#ifndef PLATFORM_ENDIANNESS
  #error "PLATFORM_ENDIANNESS not defined."
#endif

#if PLATFORM_ENDIANNESS == PLATFORM_BIG_ENDIAN
  #define cpu_platform_to_cpu(type,value) SWITCH_ENDIAN_##type(data)
  #define cpu_cpu_to_platform(type,value) SWITCH_ENDIAN_##type(data)
#elif PLATFORM_ENDIANNESS == PLATFORM_LITTLE_ENDIAN
  #define cpu_platform_to_cpu(type,value)
  #define cpu_cpu_to_platform(type,value)
#else
  #error "ERROR : Platform endianness not recognized."
#endif

#define cpu_data_concat(size,result,lvalue,hvalue)      \
{                                                       \
  result = (hvalue << size) | lvalue;                   \
}

#define cpu_data_split(size,value,lvalue,hvalue)        \
{                                                       \
  hvalue = value >> size;                               \
  lvalue = value - (hvalue << size);                    \
}

#endif

