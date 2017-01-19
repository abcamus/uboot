#ifndef __UART_TEST_
#define __UART_TEST_

#include "landrover_setup.h"
#define ELFIN_CLOCK_BASE		0x10030000

#define CLK_SRC_LEFTBUS_OFFSET		0x04200
#define CLK_MUX_STAT_LEFTBUS_OFFSET	0x04400
#define CLK_DIV_LEFTBUS_OFFSET		0x04500

#define CLK_SRC_RIGHTBUS_OFFSET		0x08200
#define CLK_MUX_STAT_RIGHTBUS_OFFSET	0x08400
#define CLK_DIV_RIGHTBUS_OFFSET		0x08500

#define CLK_SRC_CPU_OFFSET		0x14200
#define CLK_MUX_STAT_CPU_OFFSET		0x14400
#define CLK_DIV_CPU0_OFFSET		0x14500
#define CLK_DIV_CPU1_OFFSET		0x14504

#define CLK_SRC_TOP0_OFFSET		0x0C210
#define CLK_SRC_TOP1_OFFSET		0x0C214
#define CLK_SRC_FSYS_OFFSET		0x0C240
#define CLK_SRC_PERIL0_OFFSET		0x0C250
#define CLK_MUX_STAT_TOP_OFFSET		0x0C410
#define CLK_MUX_STAT_TOP1_OFFSET	0x0C414
#define CLK_DIV_TOP_OFFSET		0x0C510
#define CLK_DIV_FSYS1_OFFSET		0x0C544
#define CLK_DIV_FSYS2_OFFSET		0x0C548
#define CLK_DIV_FSYS3_OFFSET		0x0C54C
#define CLK_DIV_PERIL0_OFFSET		0x0C550

#define CLK_SRC_DMC_OFFSET		0x10200
#define CLK_MUX_STAT_DMC_OFFSET		0x10400
#define CLK_DIV_DMC0_OFFSET		0x10500
#define CLK_DIV_DMC1_OFFSET		0x10504

#define CLK_GATE_IP_DMC_OFFSET		0x10900

wait_mux_state:
	ldr r1, [r0, r2]
	cmp r1, r3
	bne wait_mux_state
	mov pc, lr

wait_pll_lock:
	ldr r1, [r0, r2]
	tst r1, #(1<<29)
	beq wait_pll_lock
	mov pc, lr

.globl testuart
testuart:
	ldr	sp, =0x02060000

	push	{lr}
	
	ldr	r0, =POWER_BASE
	ldr	r1, [r0,#OMR_OFFSET]
	bic	r2, r1, #0xffffffc1
	
	cmp     r2, #0xA
    moveq   r3, #BOOT_ONENAND

	/* SD/MMC BOOT */
	cmp     r2, #0x4
    moveq   r3, #BOOT_MMCSD	

	/* eMMC4.3 BOOT */
	cmp		r2, #0x6
	moveq	r3, #BOOT_EMMC43

	/* eMMC441 BOOT */
	cmp		r2, #0x28
	moveq	r3, #BOOT_EMMC441

	ldr	r0, =INF_REG_BASE
	str	r3, [r0, #INF_REG3_OFFSET]

	/* check reset status  */
	ldr     r0, =(INF_REG_BASE + INF_REG1_OFFSET)
    ldr     r1, [r0]

	/* AFTR wakeup reset */
	ldr	r2, =S5P_CHECK_DIDLE
	cmp	r1, r2
	beq	exit_wakeup
	
	/* Sleep wakeup reset */
	ldr	r2, =S5P_CHECK_SLEEP
	cmp	r1, r2
	beq	wakeup_reset

	/* PS-Hold high */
	ldr r0, =0x1002330c
	ldr r1, [r0]
	orr r1, r1, #0x300
	str r1, [r0]

	ldr r0, =0x11000c08
	ldr r1, =0x0
	str r1, [r0]

	/* Clear  MASK_WDT_RESET_REQUEST  */
	ldr r0, =0x1002040c
	ldr r1, =0x00
	str r1, [r0]

	bl system_clock_init_scp

	bl uart_asm_init

	mov pc, lr

	.globl system_clock_init_scp 
system_clock_init_scp:
	push	{lr}
	
	ldr	r0, =ELFIN_CLOCK_BASE	@0x1003_0000

@ CMU_CPU MUX / DIV
	ldr	r1, =0x0
	ldr	r2, =CLK_SRC_CPU_OFFSET
	str	r1, [r0, r2]

	ldr r2, =CLK_MUX_STAT_CPU_OFFSET
	ldr r3, =0x01110001
	bl wait_mux_state

	ldr	r1, =CLK_DIV_DMC0_VAL
	ldr	r2, =CLK_DIV_DMC0_OFFSET
	str	r1, [r0, r2]
	ldr	r1, =CLK_DIV_DMC1_VAL
	ldr	r2, =CLK_DIV_DMC1_OFFSET
	str	r1, [r0, r2]

@ CMU_TOP MUX / DIV
	ldr	r1, =0x0
	ldr	r2, =CLK_SRC_TOP0_OFFSET
	str	r1, [r0, r2]

	ldr r2, =CLK_MUX_STAT_TOP_OFFSET
	ldr r3, =0x11111111
	bl wait_mux_state

	ldr	r1, =0x0
	ldr	r2, =CLK_SRC_TOP1_OFFSET
	str	r1, [r0, r2]

	ldr r2, =CLK_MUX_STAT_TOP1_OFFSET
	ldr r3, =0x01111110
	bl wait_mux_state

	ldr	r1, =CLK_DIV_TOP_VAL
	ldr	r2, =CLK_DIV_TOP_OFFSET
	str	r1, [r0, r2]

@ CMU_LEFTBUS MUX / DIV
	ldr	r1, =0x10
	ldr	r2, =CLK_SRC_LEFTBUS_OFFSET
	str	r1, [r0, r2]

	ldr r2, =CLK_MUX_STAT_LEFTBUS_OFFSET
	ldr r3, =0x00000021
	bl wait_mux_state

	ldr	r1, =CLK_DIV_LEFRBUS_VAL
	ldr	r2, =CLK_DIV_LEFTBUS_OFFSET
	str	r1, [r0, r2]

@ CMU_RIGHTBUS MUX / DIV
	ldr	r1, =0x10
	ldr	r2, =CLK_SRC_RIGHTBUS_OFFSET
	str	r1, [r0, r2]

	ldr r2, =CLK_MUX_STAT_RIGHTBUS_OFFSET
	ldr r3, =0x00000021
	bl wait_mux_state

	ldr	r1, =CLK_DIV_RIGHTBUS_VAL
	ldr	r2, =CLK_DIV_RIGHTBUS_OFFSET
	str	r1, [r0, r2]

@ Set PLL locktime
	ldr	r1, =APLL_LOCK_VAL
	ldr	r2, =APLL_LOCK_OFFSET
	str	r1, [r0, r2]

	ldr	r1, =MPLL_LOCK_VAL
	ldr	r2, =MPLL_LOCK_OFFSET
	str	r1, [r0, r2]

	ldr	r1, =EPLL_LOCK_VAL
	ldr	r2, =EPLL_LOCK_OFFSET
	str	r1, [r0, r2]

	ldr	r1, =VPLL_LOCK_VAL
	ldr	r2, =VPLL_LOCK_OFFSET
	str	r1, [r0, r2]

	ldr	r1, =CLK_DIV_CPU0_VAL
	ldr	r2, =CLK_DIV_CPU0_OFFSET
	str	r1, [r0, r2]
	ldr	r1, =CLK_DIV_CPU1_VAL
	ldr	r2, =CLK_DIV_CPU1_OFFSET
	str	r1, [r0, r2]

@ Set APLL
	ldr	r1, =APLL_CON1_VAL
	ldr	r2, =APLL_CON1_OFFSET
	str	r1, [r0, r2]
	ldr	r1, =APLL_CON0_VAL
	ldr	r2, =APLL_CON0_OFFSET
	str	r1, [r0, r2]

	/* check MPLL and if MPLL is not 400 Mhz skip MPLL resetting for C2C operation */
	ldr	r2, =MPLL_CON0_OFFSET
	ldr r1, [r0, r2]
	ldr r3, =0xA0640301
	cmp r1, r3
	bne skip_mpll

@ Set MPLL
	ldr	r1, =MPLL_CON1_VAL
	ldr	r2, =MPLL_CON1_OFFSET
	str	r1, [r0, r2]
	ldr	r1, =MPLL_CON0_VAL
	ldr	r2, =MPLL_CON0_OFFSET
	str	r1, [r0, r2]
skip_mpll:

@ Set EPLL
	ldr     r1, =EPLL_CON2_VAL
	ldr     r2, =EPLL_CON2_OFFSET
	str     r1, [r0, r2]
	ldr     r1, =EPLL_CON1_VAL
	ldr     r2, =EPLL_CON1_OFFSET
	str     r1, [r0, r2]
	ldr     r1, =EPLL_CON0_VAL
	ldr     r2, =EPLL_CON0_OFFSET
	str     r1, [r0, r2]

@ Set VPLL
	ldr     r1, =VPLL_CON2_VAL
	ldr     r2, =VPLL_CON2_OFFSET
	str     r1, [r0, r2]
	ldr     r1, =VPLL_CON1_VAL
	ldr     r2, =VPLL_CON1_OFFSET
	str     r1, [r0, r2]
	ldr     r1, =VPLL_CON0_VAL
	ldr     r2, =VPLL_CON0_OFFSET
	str     r1, [r0, r2]

	ldr r2, =APLL_CON0_OFFSET
	bl wait_pll_lock
	ldr r2, =MPLL_CON0_OFFSET
	bl wait_pll_lock
	ldr r2, =EPLL_CON0_OFFSET
	bl wait_pll_lock
	ldr r2, =VPLL_CON0_OFFSET
	bl wait_pll_lock

	ldr	r1, =0x01000001
	ldr	r2, =CLK_SRC_CPU_OFFSET
	str	r1, [r0, r2]

	ldr r2, =CLK_MUX_STAT_CPU_OFFSET
	ldr r3, =0x02110002
	bl wait_mux_state

	ldr	r1, =0x00011000
	ldr	r2, =CLK_SRC_DMC_OFFSET
	str	r1, [r0, r2]

	ldr r2, =CLK_MUX_STAT_DMC_OFFSET
	ldr r3, =0x11102111
	bl wait_mux_state

	ldr	r1, =0x00000110
	ldr	r2, =CLK_SRC_TOP0_OFFSET
	str	r1, [r0, r2]

	ldr r2, =CLK_MUX_STAT_TOP_OFFSET
	ldr r3, =0x11111221
	bl wait_mux_state

	/* skip MUX_ACLK_200_SUB_SEL, MUX_ACLK_400_MCUISP_SUB_SEL setting for CMU_SYSCLK_ISP function */
	ldr	r1, =0x00011000
	ldr	r2, =CLK_SRC_TOP1_OFFSET
	str	r1, [r0, r2]

	ldr r2, =CLK_MUX_STAT_TOP1_OFFSET
	ldr r3, =0x01122110
	bl wait_mux_state

	pop {pc}


.globl uart_asm_init
uart_asm_init:

	/* set GPIO to enable UART */
	@ GPIO setting for UART for UART0/1
	ldr	r0, =0x11400000
	ldr	r1, =0x22222222
	str   	r1, [r0]
	ldr	r0, =0x11400020
	ldr	r1, =0x222222
	str	r1, [r0]

	ldr	r0, =CMU_BASE	@0x1003_0000
	ldr	r1, =CLK_SRC_PERIL0_VAL		@0x666666
	ldr	r2, =CLK_SRC_PERIL0_OFFSET
	str	r1, [r0, r2]
	ldr	r1, =CLK_DIV_PERIL0_VAL		@0x777777
	ldr	r2, =CLK_DIV_PERIL0_OFFSET
	str	r1, [r0, r2]

	ldr	r0, =ELFIN_UART_CONSOLE_BASE		@0xEC000000
	ldr	r1, =0x111
	str	r1, [r0, #UFCON_OFFSET]

	mov	r1, #0x3
	str	r1, [r0, #ULCON_OFFSET]

	ldr	r1, =0x3c5
	str	r1, [r0, #UCON_OFFSET]

	ldr	r1, =UART_UBRDIV_VAL	@0x2B /*  UDIV(43) = ((82,500,000 / 16 / 115200) - 1) */
	str	r1, [r0, #UBRDIV_OFFSET]

	ldr	r1, =UART_UDIVSLOT_VAL	@0xC /* UFRACVAL(12) = ((((82,500,000 / 16 / 115200) - 1) - 43) * 16) */
	str	r1, [r0, #UDIVSLOT_OFFSET]

	ldr	r1, =0x4f4f4f4f
	str	r1, [r0, #UTXH_OFFSET]		@'O'

	mov	pc, lr

wakeup_reset:
exit_wakeup:
	/*Load return address and jump to kernel*/
	ldr	r0, =(INF_REG_BASE+INF_REG0_OFFSET)
	ldr	r1, [r0]	/* r1 = physical address of s5pc110_cpu_resume function*/

	mov	pc, r1		/*Jump to kernel */
	nop
	nop
#endif
