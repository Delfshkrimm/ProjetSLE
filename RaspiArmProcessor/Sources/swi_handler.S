.section .excep,#alloc,#execinstr
	.align 4
	.global swi_handler

swi_handler:
	b swi_handler
