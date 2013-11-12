@ cpu_vector_transfer: source, destination, byte_count

.global cpu_vector_transfer

cpu_vector_transfer:
	@ Save registers for further use
	push		{r3-r12}

	@ Return directly if byte_count is 0
	cmp			r2, #0x0
	beq			_cpu_vector_xfer_end

	@ Test if r0 and r1 are aligned on a word frontier
	orrs		r3, r0, #0x3
	orrs		r3, r1, #0x3

	@ If one of them is not aligned, switch to byte transfer
	mov			r11, #0x0
	beq			_cpu_vector_xfer_byte
	
	@ Compute the number of 8-word xfer to perform
	movs		r12, r2, lsr #0x5
	mov			r11, r12, lsl #0x5

	@ If no 8-words are available, jump to the byte copy
	beq			_cpu_vector_xfer_word

	@ Perform the 8-words copy
_cpu_vector_xfer_do_lsm:
	ldmia		r0!, {r3 - r10}
	stmia		r1!, {r3 - r10}
	subs		r12, r12, #1
	bne			_cpu_vector_xfer_do_lsm

	@ Substract the written 8-words from r2
	sub		r2, r2, r11

	@ Compute the remaining number of words to copy
_cpu_vector_xfer_word:
	movs		r12, r2, lsr #0x2
	mov			r11, r12, lsl #0x2

	@ If no words are available, jump to the byte copy
	beq			_cpu_vector_xfer_byte

	@ Perform the words copy
_cpu_vector_xfer_do_word:
	ldr			r3, [r0], #4
	str			r3, [r1], #4
	subs		r12, r12, #1
	bne			_cpu_vector_xfer_do_word

	@ Compute the remaining number of bytes to copy
_cpu_vector_xfer_byte:
	subs		r12, r2, r11

	@ If no bytes are available, jump to the end
	beq			_cpu_vector_xfer_end

	@ Perform the byte copy
_cpu_vector_xfer_do_byte:
	ldrb		r3, [r0], #1
	strb		r3, [r1], #1
	subs		r12, r12, #1
	bne  		_cpu_vector_xfer_do_byte

	@ Restore the registers and return
_cpu_vector_xfer_end:
	pop			{r3 - r12}
	mov pc, lr
