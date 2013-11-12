/*
 * Copyright (C) 2007 TIMA Laboratory
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stddef.h>
#include <Private/Cache.h>
#include <Processor/Processor.h>
#include <Platform/Platform.h>

uint32_t CPU_MM_TTB[4096] __attribute__ ((aligned (0x4000), section (".data")));

void cpu_initialize (void)
{
  /*
   * Construct the TTB table.
	 */

	for (register int32_t i = 0; i < 0x200; i += 1)
	{
		CPU_MM_TTB[i] = cpu_cache_ttb_word(i, 0x3, 0x0, 0x0, 0x0);
	}

	for (register int32_t i = 0x200; i < 0x239; i += 1)
	{
		CPU_MM_TTB[i] = cpu_cache_ttb_word(i, 0x3, 0x0, 0x1, 0x0);
	}

	for (register int32_t i = 0x239; i < 0x1000; i += 1)
	{
		CPU_MM_TTB[i] = cpu_cache_ttb_word(i, 0x3, 0x0, 0x0, 0x0);
	}

	/*
	 * Invalidate the caches
	 */

	__asm__ volatile (
			"mov r0, #0\n"
			"mcr p15, 0, r0, c7, c7, 0\n"
			:
			:
			: "r0"
			);

	/*
	 * Write down the TTB
	 */

	__asm__ volatile (
			"mcr p15, 0, %0, c2, c0, 0\n"
			:
			: "r"(CPU_MM_TTB)
			);

	/*
	 * Set domain access control
	 */

	__asm__ volatile (
			"mvn r0, #0\n"
			"mcr p15, 0, r0, c3, c0, 0\n"
			:
			:
			: "r0"
			);

	/*
	 * Activate the caches
	 */

	__asm__ volatile (
			"mrc p15, 0, r0, c1, c0, 0\n"
			"orr r0, r0, #0x5000\n"
			"orr r0, r0, #0x0005\n"
			"mcr p15, 0, r0, c1, c0, 0\n"
			:
			:
			: "r0"
			);

	/*
	 * Flush the TLB's, again
	 */

	__asm__ volatile (
			"mov r0, #0\n"
			"mcr p15, 0, r0, c8, c7, 0\n"
			:
			:
			: "r0"
			);

  /*
   * Disable AIC interrupts.
   */

  PLATFORM_AIC_BASE -> IDCR = 0xFFFFFFFF;
}

