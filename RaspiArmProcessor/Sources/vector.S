.section .reset,#alloc,#execinstr
	.align 4
	.global _start

	.extern reset_handler
	.extern irq_handler
	.extern fiq_handler
	.extern swi_handler
	.extern undef_handler
	.extern data_abort_handler
	.extern prefetch_abort_handler

_start:
	b	reset_handler
	b undef_handler
	b swi_handler
	b	prefetch_abort_handler
	b data_abort_handler
	nop
	b irq_handler
	b fiq_handler

