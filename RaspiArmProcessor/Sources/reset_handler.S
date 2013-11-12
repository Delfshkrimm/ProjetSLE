#define FIQ_MODE 0xD1
#define IRQ_MODE 0xD2
#define SVC_MODE 0xD3
#define USR_MODE 0xD0

.section .excep,#alloc,#execinstr
	.align 4
	.global reset_handler
	.extern cpu_initialize
	.extern system_kickstart
	.extern CPU_SVC_STACK_ADDR
	.extern CPU_IRQ_STACK_ADDR
	.extern CPU_FIQ_STACK_ADDR
	.extern PLATFORM_BMX_BASE
	.extern PLATFORM_AIC_BASE

reset_handler:
  @ Disable CPU interrupts
  mrs r0, cpsr
  orr r0, r0, #0xC0
  msr cpsr_c, r0

  @ Set the FIQ processor stack
	ldr	r1, = CPU_FIQ_STACK_ADDR
	mov	r0, #FIQ_MODE
	msr	cpsr_c, r0
	mov	sp, r1
	mov fp, sp

  @ Set the IRQ processor stack
	ldr	r2, = CPU_IRQ_STACK_ADDR
	mov	r0, #IRQ_MODE
	msr	cpsr_c, r0
	mov	sp, r1
	mov fp, sp

  @ Set the SVC processor stack
	ldr	r1, = CPU_SVC_STACK_ADDR
	mov	r0,  #SVC_MODE
	msr cpsr_c, r0
	mov	sp, r1
	mov fp, sp

  @ Deactivate the caches
  mrc p15, 0, r0, c1, c0, 0
	bic r0, r0, #0x1000
	bic r0, r0, #0x0005
	mcr p15, 0, r0, c1, c0, 0

  @ Invalidate the caches

  mov r0, #0
  mcr p15, 0, r0, c7, c7, 0

  @ Flush the write buffer
  mov r0, #0
  mcr p15, 0, r0, c7, c10, 4

  @ Flush the TLB
  mov r0, #0
  mcr p15, 0, r0, c8, c7, 0

  @ Remap the bus matrix
  ldr r0, = __reset_handler_remap_return
  ldr r1, = PLATFORM_BMX_BASE
  ldr r1, [r1]
  mov r2, #0x3
  str r2, [r1, #0x100]
  mov pc, r0
__reset_handler_remap_return:
  nop

  @ Call cpu_initialize
  mov	lr, pc
  ldr	pc, =cpu_initialize

  @ Enable CPU interrupts
  @ mrs r0, cpsr
  @ bic r0, r0, #0xC0
  @ msr cpsr_c, r0

  @ Call system_kickstart
  mov lr, pc
  ldr	pc, =system_kickstart

  @ Hell's pit
__hells_pit:
  b __hells_pit
