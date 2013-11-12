.section .text
	.align 4
	.global cpu_context_load

cpu_context_load:

  @ We restore the common registers
  add r0, r0, #8
	ldmia	r0, {r2 - r10, fp, ip, sp}

  @ We get the new r0, r1 and pc values and push them
  sub r0, r0, #8
  ldr r1, [r0, #56]
  push {r1}
  ldr r1, [r0, #4]
  push {r1}
  ldr r1, [r0]
  push {r1}

  @ We load the cpsr and spsr
	ldr	r1, [r0, #60]
	msr	cpsr, r1

  @ And now we restore the registers
  pop {r0, r1, pc}
