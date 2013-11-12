.section .excep,#alloc,#execinstr
	.align 4
	.global fiq_handler

fiq_handler:
	subs pc, lr, #0x4

