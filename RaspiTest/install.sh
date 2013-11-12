#!/bin/bash
XDIR=/opt/toolchains/dnaos/arm/bin

export APES_CC_FLAGS="-Wall -Werror -Wno-format -std=c99"
export APES_AS_FLAGS="-Wall -Werror -Wno-format -std=c99"
export MJPEG_CC_FLAGS="-DNB_DECODER=2 -DDISPATCH_TIME -DINFO -DVERBOSE"

APES_CC_OPTIMIZATIONS="-g3 -mlittle-endian -O3 -march=armv6zk"
# -march=armv6zk -mfpu=fpa
export APES_CC_OPTIMIZATIONS

APES_AS_OPTIMIZATIONS="-g3 -mlittle-endian -O3 -march=armv6zk"
# -march=armv6zk  -mfpu=fpa
export APES_AS_OPTIMIZATIONS

export APES_ASSEMBLER="$XDIR/arm-sls-dnaos-gcc"
export APES_COMPILER="$XDIR/arm-sls-dnaos-gcc"
export APES_LINKER="$XDIR/arm-sls-dnaos-gcc"
export APES_LINKER_FLAGS="-mlittle-endian -T$PWD/ldscript -march=armv6zk"
#  -march=armv6zk -mfpu=fpa

# export DNACORE_CC_FLAGS="-DDNA_ENABLE_LOG=VERBOSE_LEVEL"
unset DNACORE_CC_FLAGS
