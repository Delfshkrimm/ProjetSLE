.section .excep,#alloc,#execinstr
	.align 4
	.global undef_handler

undef_handler:
	b undef_handler
