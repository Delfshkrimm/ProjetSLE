#ifndef PROCESSOR_SYNCHRONIZATION_H
#define PROCESSOR_SYNCHRONIZATION_H

static inline long int cpu_test_and_set (volatile long int * spinlock)
{
  register long int result, temp = 1; 

  __asm__ volatile ("\n"
      "0:\tswp\t%0,%2,[%1]\n\t"
      : "=&r" (result)
      : "r" (spinlock), "r" (temp)
      : "cc", "memory");

  return result;
}

static inline long int cpu_compare_and_swap (volatile long int * p_val,
    long int oldval, long int newval)
{
  register long int result, tmp;

  __asm__ volatile ("\n"
      "0:\tldr\t%1,[%2]\n\t"
      "mov\t%0,#0\n\t"
      "cmp\t%1,%4\n\t"
      "bne\t1f\n\t"
      "swp\t%0,%3,[%2]\n\t"
      "cmp\t%1,%0\n\t"
      "swpne\t%1,%0,[%2]\n\t"
      "bne\t0b\n\t"
      "mov\t%0,#1\n"
      "1:"
      : "=&r" (result), "=&r" (tmp)
      : "r" (p_val), "r" (newval), "r" (oldval)
      : "cc", "memory");

  return result;
}

#endif

