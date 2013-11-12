#ifndef PLATFORM_ENDIAN_H
#define PLATFORM_ENDIAN_H

#define PLATFORM_ENDIANNESS PLATFORM_LITTLE_ENDIAN

typedef enum _platform_endianness
{
  PLATFORM_LITTLE_ENDIAN,
  PLATFORM_BIG_ENDIAN
}
platform_endianness_t;

#endif
