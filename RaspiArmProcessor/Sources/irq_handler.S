.section .excep,#alloc,#execinstr
	.align 4
	.global irq_handler
	.extern PLATFORM_AIC_BASE

irq_handler:
	@ Save scratch registers and SPSR
	push {r0-r10, fp, ip, lr}
	mrs	r0, spsr
	push {r0}

	@ Fetch the current interruption source
	ldr r0, =PLATFORM_AIC_BASE
	ldr r0, [r0]
	ldr r1, [r0, #0x10C]
	ldr r2, [r0, #0x110]
	and r0, r1, r2

	@ Compute the value
	mov r1, #0
__itn_compute:
	ands r2, r0, #0x1
	bne __itn_compute_end
	add r1, r1, #1
	mov r0, r0, lsr #1
	b __itn_compute
__itn_compute_end:
	mov r0, r1
	mov r1, sp

	@ Move to SVC mode
	mrs r2, cpsr
	orr r2, r2, #0x3
	msr cpsr, r2

	@ Save previous IRQ SP
	push {r1}

	@ Save current SVC LR
	push {lr}

	@ Branch to IRQ dispatcher
	ldr r1, =PLATFORM_AIC_BASE
	ldr r1, [r1]
	mov lr, pc
	ldr pc, [r1, #0x100]

	@ Restore SVC LR
	pop {lr}

	@ Load previous IRQ SP
	pop {r2}

	@ Move back to IRQ mode
	mrs r1, cpsr
	bic r1, r1, #0x1
	msr cpsr, r1

	@ Restore previous IRQ SP
	mov sp, r2

	@ Restore SPSR
	pop {r1}
	msr	spsr, r1

	@ Acnkowlegde the end of IT
	ldr r1, =PLATFORM_AIC_BASE
	ldr r1, [r1]
	str r1, [r1, #0x130]

	@ Restore the registers
	pop {r0 - r10, fp, ip, lr}

	@ Return
	subs pc, lr, #0x4

