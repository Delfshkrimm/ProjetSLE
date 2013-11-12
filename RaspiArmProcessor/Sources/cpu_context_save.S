.section .text
	.align 4
	.global cpu_context_save

cpu_context_save:
	stmia r0!, {r0 - r10, fp, ip, sp}
  str r1, [r0], #4
	mrs r1, cpsr
	str	r1, [r0]
	mov pc, lr

