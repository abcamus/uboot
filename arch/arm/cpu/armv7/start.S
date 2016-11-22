/*
 * armboot - Startup Code for OMAP3530/ARM Cortex CPU-core
 *
 * Copyright (c) 2004	Texas Instruments <r-woodruff2@ti.com>
 *
 * Copyright (c) 2001	Marius Gröger <mag@sysgo.de>
 * Copyright (c) 2002	Alex Züpke <azu@sysgo.de>
 * Copyright (c) 2002	Gary Jennejohn <garyj@denx.de>
 * Copyright (c) 2003	Richard Woodruff <r-woodruff2@ti.com>
 * Copyright (c) 2003	Kshitij <kshitij@ti.com>
 * Copyright (c) 2006-2008 Syed Mohammed Khasim <x0khasim@ti.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <asm-offsets.h>
#include <config.h>
#include <asm/system.h>
#include <linux/linkage.h>

/*************************************************************************
 *
 * Startup Code (reset vector)
 *
 * do important init only if we don't start from memory!
 * setup Memory and board specific bits prior to relocation.
 * relocate armboot to ram
 * setup stack
 *
 *************************************************************************/

	.globl	reset
	.globl	save_boot_params_ret
	.globl	led_on
#define MEM_DLLl_ON

led_on:
	ldr r0, =0x11000100
	mov r1, #1
	str r1, [r0]
	ldr r0, =0x11000060
	mov r1, #0
	str r1, [r0]
	ldr r0, =0x11000104
	mov r1, #1
	str r1, [r0]
	ldr r0, =0x11000064
	mov r0, #0
	str r0, [r0]	
	bx lr

reset:
	/* Allow the board to save important registers */
	b	save_boot_params
save_boot_params_ret:
	/*
	 * disable interrupts (FIQ and IRQ), also set the cpu to SVC32 mode,
	 * except if in HYP mode already
	 */
	mrs	r0, cpsr
	and	r1, r0, #0x1f		@ mask mode bits
	teq	r1, #0x1a		@ test for HYP mode
	bicne	r0, r0, #0x1f		@ clear all mode bits
	orrne	r0, r0, #0x13		@ set SVC mode
	orr	r0, r0, #0xc0		@ disable FIQ and IRQ
	msr	cpsr,r0

/*
 * Setup vector:
 * (OMAP4 spl TEXT_BASE is not 32 byte aligned.
 * Continue to use ROM code vector only in OMAP4 spl)
 */
#if !(defined(CONFIG_OMAP44XX) && defined(CONFIG_SPL_BUILD))
	/* Set V=0 in CP15 SCTLR register - for VBAR to point to vector */
	mrc	p15, 0, r0, c1, c0, 0	@ Read CP15 SCTLR Register
	bic	r0, #CR_V		@ V = 0
	mcr	p15, 0, r0, c1, c0, 0	@ Write CP15 SCTLR Register

	/* Set vector address in CP15 VBAR register */
	ldr	r0, =_start
	mcr	p15, 0, r0, c12, c0, 0	@Set VBAR
#endif

	/* the mask ROM code should have PLL and others stable */
#ifndef CONFIG_SKIP_LOWLEVEL_INIT
	bl	cpu_init_cp15
	bl	cpu_init_crit
#endif

#ifdef CONFIG_LANDROVER
	//bl	landrover_init
#endif

	bl	_main

#ifdef CONFIG_LANDROVER
ENTRY(landrover_init)
	/* Read booting information */
	ldr	r0, =POWER_BASE
	ldr	r1, [r0,#OMR_OFFSET]
	bic	r2, r1, #0xffffffc1

/* NAND BOOT */
@	cmp	r2, #0x0		@ 512B 4-cycle
@	moveq	r3, #BOOT_NAND

@	cmp	r2, #0x2		@ 2KB 5-cycle
@	moveq	r3, #BOOT_NAND

@	cmp	r2, #0x4		@ 4KB 5-cycle	8-bit ECC
@	moveq	r3, #BOOT_NAND

	cmp     r2, #0xA
    moveq   r3, #BOOT_ONENAND

@	cmp	r2, #0x6		@ 4KB 5-cycle	16-bit ECC
@	moveq	r3, #BOOT_NAND

	/* SD/MMC BOOT */
	cmp     r2, #0x4
    moveq   r3, #BOOT_MMCSD	

	/* eMMC4.3 BOOT */
	cmp		r2, #0x6
	moveq	r3, #BOOT_EMMC43

	/* eMMC441 BOOT */
	cmp		r2, #0x28
	moveq	r3, #BOOT_EMMC441
	
    /* NOR BOOT */
@	cmp     r2, #0x14
@	moveq   r3, #BOOT_NOR	

	/* For second device booting */
	/* OneNAND BOOTONG failed */
@	cmp     r2, #0x8
@	moveq   r3, #BOOT_SEC_DEV

	/* Uart BOOTONG failed */
@	cmp     r2, #(0x1<<4)
@	moveq   r3, #BOOT_SEC_DEV
	
	ldr	r0, =INF_REG_BASE
	str	r3, [r0, #INF_REG3_OFFSET]     

	ldr	sp, =0x02060000
	push	{lr}

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

	ldr     r0, =0x11000c08
	ldr r1, =0x0
	str r1, [r0]

	/* Clear  MASK_WDT_RESET_REQUEST  */
	ldr r0, =0x1002040c
	ldr r1, =0x00
	str r1, [r0]

	/* init system clock */
	bl system_clock_init

	/* Memory initialize */
	bl mem_ctrl_asm_init_ddr3

	bl tzpc_init

	/* for UART */
	bl uart_asm_init
	
	/* Print 'K' */
	ldr	r0, =ELFIN_UART_CONSOLE_BASE
	ldr	r1, =0x4b4b4b4b
	str	r1, [r0, #UTXH_OFFSET]

	/* when we already run in ram, we don't need to relocate U-Boot.
	 * and actually, memory controller must be configured before U-Boot
	 * is running in ram.
	 */
	ldr	r0, =0xff000fff
	bic	r1, pc, r0	/* r0 <- current base addr of code */
	//ldr	r2, _TEXT_BASE	/* r1 <- original base addr in ram */
	ldr r2, =CONFIG_SYS_TEXT_BASE
	bic	r2, r2, r0	/* r0 <- current base addr of code */
	cmp     r1, r2  /* compare r0, r1 */
	beq     after_copy	/* r0 == r1 then skip flash copy */

#if 0
	ldr	r0, =0x11000104  /* GPL2(0)  */
	ldr	r1, =0x00000001	 /* GPL2(0 output high	*/
	str	r1, [r0]
	
	ldr	r0, =0x11000100  /* GPL2(0)  */
	ldr	r1, =0x00000001	 /* GPL2(0 output high	*/
	str	r1, [r0]
#endif

	/* wait ?us */
	mov	r1, #0x10000
9:	subs	r1, r1, #1
	bne	9b
	
	ldr	r0, =INF_REG_BASE
	ldr	r1, [r0, #INF_REG3_OFFSET]
	
	cmp     r1, #BOOT_MMCSD
	beq     mmcsd_boot

mmcsd_boot:
	ldr	r0, =CMU_BASE
	ldr	r2, =CLK_DIV_FSYS2_OFFSET
	ldr	r1, [r0, r2]
	orr r1, r1, #0xf
	str r1, [r0, r2]
	//bl  movi_uboot_copy
	//b   after_copy

	pop	{pc}

ENDPROC(landrover_init)

after_copy:


/*
 * uart_asm_init: Initialize UART in asm mode, 115200bps fixed.
 * void uart_asm_init(void)
 */
	.globl uart_asm_init
uart_asm_init:

	/* set GPIO to enable UART */
	@ GPIO setting for UART0/1
	ldr	r0, =0x11400000
	ldr	r1, =0x22222222
	str r1, [r0]
	@ GPIO setting for UART2/3
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
	ldr	r0, =CHIP_ID_BASE
	ldr	r1, [r0]
	lsr	r1, r1, #8
	and	r1, r1, #3
	cmp	r1, #2
	bne	wake_v310
	
	//mj 
	/* check C2C_CTRL enable bit */
	ldr r3, =SYSC_PMU_BASE
	ldr r1, [r3, #C2C_CTRL_OFFSET]
	and r1, r1, #1
	cmp r1, #0
	bne skip_dmc
	
	/* init system clock */
	/* add by cym 20130218 */
	bl	mem_ctrl_asm_init_ddr3
	/* end add */
skip_dmc:
	/* add by cym 20130218 */
	bl	system_clock_init
	/* end add */
	bl	tzpc_init
	b	exit_wakeup

landrover_lowlevel_init:
	push	{lr}

wake_v310:
	bl system_clock_init
	bl mem_ctrl_asm_init_ddr3

	bl tzpc_init

exit_wakeup:
	/*Load return address and jump to kernel*/
	ldr	r0, =(INF_REG_BASE+INF_REG0_OFFSET)
	ldr	r1, [r0]	/* r1 = physical address of s5pc110_cpu_resume function*/

	mov	pc, r1		/*Jump to kernel */
	nop
	nop

/*
 * Setting TZPC[TrustZone Protection Controller]
 */
tzpc_init:

	ldr	r0, =ELFIN_TZPC0_BASE
 	mov	r1, #0x0
 	str	r1, [r0]
 	mov	r1, #0xff
 	str	r1, [r0, #TZPC_DECPROT0SET_OFFSET]
 	str	r1, [r0, #TZPC_DECPROT1SET_OFFSET]
	@@@;;str	  r1, [r0, #TZPC_DECPROT2SET_OFFSET] 	
	str	r1, [r0, #TZPC_DECPROT3SET_OFFSET]

 	ldr 	r0, =ELFIN_TZPC1_BASE
 	str	r1, [r0, #TZPC_DECPROT0SET_OFFSET]
 	str	r1, [r0, #TZPC_DECPROT1SET_OFFSET]
	str	r1, [r0, #TZPC_DECPROT2SET_OFFSET] 	
	str	r1, [r0, #TZPC_DECPROT3SET_OFFSET]

 	ldr	r0, =ELFIN_TZPC2_BASE
 	str	r1, [r0, #TZPC_DECPROT0SET_OFFSET]
 	str	r1, [r0, #TZPC_DECPROT1SET_OFFSET]
	str	r1, [r0, #TZPC_DECPROT2SET_OFFSET]
	str	r1, [r0, #TZPC_DECPROT3SET_OFFSET] 

 	ldr	r0, =ELFIN_TZPC3_BASE
 	str	r1, [r0, #TZPC_DECPROT0SET_OFFSET]
 	str	r1, [r0, #TZPC_DECPROT1SET_OFFSET]
	str	r1, [r0, #TZPC_DECPROT2SET_OFFSET] 	
	str	r1, [r0, #TZPC_DECPROT3SET_OFFSET]

 	ldr	r0, =ELFIN_TZPC4_BASE
 	str	r1, [r0, #TZPC_DECPROT0SET_OFFSET]
 	str	r1, [r0, #TZPC_DECPROT1SET_OFFSET]
	str	r1, [r0, #TZPC_DECPROT2SET_OFFSET]
	str	r1, [r0, #TZPC_DECPROT3SET_OFFSET]

 	ldr	r0, =ELFIN_TZPC5_BASE
 	str	r1, [r0, #TZPC_DECPROT0SET_OFFSET]
 	str	r1, [r0, #TZPC_DECPROT1SET_OFFSET]
	str	r1, [r0, #TZPC_DECPROT2SET_OFFSET]
	str	r1, [r0, #TZPC_DECPROT3SET_OFFSET]

 	mov	pc, lr

mem_ctrl_asm_init_ddr3:
	push {lr}

/*****************************************************************/
/*DREX0***********************************************************/
/*****************************************************************/

	ldr	r0, =APB_DMC_0_BASE 

	ldr	r1, =0x0
	str	r1, [r0, #DMC_PHYCONTROL2]

	ldr	r1, =0x0
	str	r1, [r0, #0x24]

	ldr	r1, =0xE3855503
	str	r1, [r0, #DMC_PHYZQCONTROL]

	ldr	r1, =0x71101008				
	str	r1, [r0, #DMC_PHYCONTROL0]

	ldr	r1, =0x7110100A				
	str	r1, [r0, #DMC_PHYCONTROL0]

	ldr	r1, =0x20000086				
	str	r1, [r0, #DMC_PHYCONTROL1]

	ldr	r1, =0x71101008				
	str	r1, [r0, #DMC_PHYCONTROL0]

	ldr	r1, =0x2000008E				
	str	r1, [r0, #DMC_PHYCONTROL1]

	ldr	r1, =0x20000086				
	str	r1, [r0, #DMC_PHYCONTROL1]

	ldr	r1, =0x2000008E				
	str	r1, [r0, #DMC_PHYCONTROL1]

	ldr	r1, =0x20000086				
	str	r1, [r0, #DMC_PHYCONTROL1]

	ldr	r1, =0x0FFF30CA
	str	r1, [r0, #DMC_CONCONTROL]

	ldr	r1, =0x00302600				
	str	r1, [r0, #DMC_MEMCONTROL]
#if 0
	ldr	r1, =0x40C01323	
	str	r1, [r0, #DMC_MEMCONFIG0]
#else
	/* 4Gb * 4 */
	/*
	ldr r1, =0x40801323
	str	r1, [r0, #DMC_MEMCONFIG0]
	*/

	/* 2Gb * 8 */

	ldr r1, =0x40801333
	str	r1, [r0, #DMC_MEMCONFIG0]
	
#endif
	ldr	r1, =(0x80000000 | CONFIG_IV_SIZE)
	str	r1, [r0, #DMC_IVCONTROL]

	ldr	r1, =0x64000000			
	str	r1, [r0, #DMC_PRECHCONFIG]

	ldr	r1, =0x9C4000FF			
	str	r1, [r0, #DMC_PHYCONTROL0]

	ldr	r1, =0x000000BB
	str	r1, [r0, #DMC_TIMINGAREF] @TimingAref

#ifdef CONFIG_EVT0_RECOMMEND
	ldr	r1, =0x34A98691
#else	
	ldr	r1, =0x34498691  
#endif

	ldr	r1, =0x7846654F/*0x4046654F*/
	str	r1, [r0, #DMC_TIMINGROW] @TimingRow
	ldr	r1, =0x46400506    				
	str	r1, [r0, #DMC_TIMINGDATA] @TimingData
	ldr	r1, =0x52000A3C    				
	str	r1, [r0, #DMC_TIMINGPOWER] @TimingPower

	/* minimum wait time is 100 nano seconds */
	/* 0x64: wait 250 nano seconds at ARMCLK 1.5 Ghz */
	mov	r2, #0x64
	bl dmc_delay

	ldr	r1, =0x07000000       				
	str	r1, [r0, #DMC_DIRECTCMD] 

	/* minimum wait time is 200 micro seconds */
	/* 0x19000: wait 250 micro seconds at ARMCLK 1.5 Ghz */
	mov	r2, #0x19000
	bl dmc_delay

	ldr	r1, =0x00020000       				
	str	r1, [r0, #DMC_DIRECTCMD]

	/* minimum wait time is 20 micro seconds */
	/* 0x2700: wait 25 micro seconds at ARMCLK 1.5 Ghz */
	mov	r2, #0x2700
	bl dmc_delay

	ldr	r1, =0x00030000       				
	str	r1, [r0, #DMC_DIRECTCMD] 

	/* minimum wait time is 1 micro seconds */
	/* 0x3f0: wait 2.5 micro seconds at ARMCLK 1.5 Ghz */
	mov	r2, #0x3f0
	bl dmc_delay

	ldr	r1, =0x00010000
	str	r1, [r0, #DMC_DIRECTCMD] 
	ldr	r1, =0x00000100       				
	str	r1, [r0, #DMC_DIRECTCMD] 

	mov	r2, #0x3f0
	bl dmc_delay

	ldr	r1, =0x00000420       				
	str	r1, [r0, #DMC_DIRECTCMD]

	mov	r2, #0x3f0
	bl dmc_delay

	ldr	r1, =0x0A000000
	str	r1, [r0, #DMC_DIRECTCMD]

	mov	r2, #0x3f0
	bl dmc_delay

/*****************************************************************/
/*DREX1***********************************************************/
/*****************************************************************/
	ldr	r0, =APB_DMC_1_BASE 

	ldr	r1, =0x0
	str	r1, [r0, #DMC_PHYCONTROL2]

	ldr	r1, =0x0
	str	r1, [r0, #0x24]

	ldr	r1, =0xE3855503
	str	r1, [r0, #DMC_PHYZQCONTROL]

	ldr	r1, =0x71101008				
	str	r1, [r0, #DMC_PHYCONTROL0]

	ldr	r1, =0x7110100A				
	str	r1, [r0, #DMC_PHYCONTROL0]

	ldr	r1, =0x20000086				
	str	r1, [r0, #DMC_PHYCONTROL1]

	ldr	r1, =0x71101008				
	str	r1, [r0, #DMC_PHYCONTROL0]

	ldr	r1, =0x2000008E				
	str	r1, [r0, #DMC_PHYCONTROL1]

	ldr	r1, =0x20000086				
	str	r1, [r0, #DMC_PHYCONTROL1]

	ldr	r1, =0x2000008E				
	str	r1, [r0, #DMC_PHYCONTROL1]

	ldr	r1, =0x20000086				
	str	r1, [r0, #DMC_PHYCONTROL1]

	ldr	r1, =0x0FFF30CA
	str	r1, [r0, #DMC_CONCONTROL]

	ldr	r1, =0x00302600				
	str	r1, [r0, #DMC_MEMCONTROL]
#if 0
	ldr	r1, =0x40C01323	
	str	r1, [r0, #DMC_MEMCONFIG0]
#else
	/* 4Gb * 4 */
	/*
	ldr r1, =0x40801323
	str	r1, [r0, #DMC_MEMCONFIG0]
	*/

	/* 2Gb * 8 */
	ldr r1, =0x40801333
	str	r1, [r0, #DMC_MEMCONFIG0]

#endif
	ldr	r1, =(0x80000000 | CONFIG_IV_SIZE)
	str	r1, [r0, #DMC_IVCONTROL]

	ldr	r1, =0x64000000			
	str	r1, [r0, #DMC_PRECHCONFIG]

	ldr	r1, =0x9C4000FF			
	str	r1, [r0, #DMC_PHYCONTROL0]

	ldr	r1, =0x000000BB
	str	r1, [r0, #DMC_TIMINGAREF] @TimingAref

#ifdef CONFIG_EVT0_RECOMMEND
	ldr	r1, =0x34A98691
#else	
	ldr	r1, =0x34498691  
#endif

	ldr	r1, =0x7846654F/*0x4046654F*/
	str	r1, [r0, #DMC_TIMINGROW] @TimingRow
	ldr	r1, =0x46400506    				
	str	r1, [r0, #DMC_TIMINGDATA] @TimingData
	ldr	r1, =0x52000A3C    				
	str	r1, [r0, #DMC_TIMINGPOWER] @TimingPower

	/* minimum wait time is 100 nano seconds */
	/* 0x64: wait 250 nano seconds at ARMCLK 1.5 Ghz */
	mov	r2, #0x64
	bl dmc_delay

	ldr	r1, =0x07000000       				
	str	r1, [r0, #DMC_DIRECTCMD] 

	/* minimum wait time is 200 micro seconds */
	/* 0x19000: wait 250 micro seconds at ARMCLK 1.5 Ghz */
	mov	r2, #0x19000
	bl dmc_delay

	ldr	r1, =0x00020000       				
	str	r1, [r0, #DMC_DIRECTCMD]

	/* minimum wait time is 20 micro seconds */
	/* 0x2700: wait 25 micro seconds at ARMCLK 1.5 Ghz */
	mov	r2, #0x2700
	bl dmc_delay

	ldr	r1, =0x00030000       				
	str	r1, [r0, #DMC_DIRECTCMD] 

	/* minimum wait time is 1 micro seconds */
	/* 0x3f0: wait 2.5 micro seconds at ARMCLK 1.5 Ghz */
	mov	r2, #0x3f0
	bl dmc_delay

	ldr	r1, =0x00010000
	str	r1, [r0, #DMC_DIRECTCMD] 
	ldr	r1, =0x00000100       				
	str	r1, [r0, #DMC_DIRECTCMD] 

	mov	r2, #0x3f0
	bl dmc_delay

	ldr	r1, =0x00000420       				
	str	r1, [r0, #DMC_DIRECTCMD]

	mov	r2, #0x3f0
	bl dmc_delay

	ldr	r1, =0x0A000000
	str	r1, [r0, #DMC_DIRECTCMD]

	mov	r2, #0x3f0
	bl dmc_delay


	ldr	r0, =APB_DMC_0_BASE

	ldr	r1, =0x7110100A
	ldr	r2, =DMC_PHYCONTROL0
	str	r1, [r0, r2]

	ldr	r1, =0x20000086
	ldr	r2, =DMC_PHYCONTROL1
	str	r1, [r0, r2]

	ldr	r1, =0x7110100B
	ldr	r2, =DMC_PHYCONTROL0
	str	r1, [r0, r2]

	bl wait_phy_state

	ldr	r1, =0x2000008E
	ldr	r2, =DMC_PHYCONTROL1
	str	r1, [r0, r2]
	ldr	r1, =0x20000086
	ldr	r2, =DMC_PHYCONTROL1
	str	r1, [r0, r2]

	bl wait_phy_state

	ldr	r0, =APB_DMC_1_BASE

	ldr	r1, =0x7110100A
	ldr	r2, =DMC_PHYCONTROL0
	str	r1, [r0, r2]

	ldr	r1, =0x20000086
	ldr	r2, =DMC_PHYCONTROL1
	str	r1, [r0, r2]

	ldr	r1, =0x7110100B
	ldr	r2, =DMC_PHYCONTROL0
	str	r1, [r0, r2]

	bl wait_phy_state

	ldr	r1, =0x2000008E
	ldr	r2, =DMC_PHYCONTROL1
	str	r1, [r0, r2]
	ldr	r1, =0x20000086
	ldr	r2, =DMC_PHYCONTROL1
	str	r1, [r0, r2]

	bl wait_phy_state

	ldr	r0, =APB_DMC_0_BASE
	ldr	r2, =DMC_CONCONTROL
	ldr	r1, [r0, r2]
	orr r1, r1, #(1 << 5)
	str r1, [r0, r2]

	ldr	r0, =APB_DMC_1_BASE
	ldr	r2, =DMC_CONCONTROL
	ldr	r1, [r0, r2]
	orr r1, r1, #(1 << 5)
	str r1, [r0, r2]

	ldr	r0, =APB_DMC_0_BASE
	ldr	r2, =DMC_MEMCONTROL
	ldr	r1, [r0, r2]
	orr	r1, r1, #((1 << 4) | (1 << 1) | (1 << 0))
	str	r1, [r0, r2]

	ldr	r0, =APB_DMC_1_BASE
	ldr	r2, =DMC_MEMCONTROL
	ldr	r1, [r0, r2]
	orr	r1, r1, #((1 << 4) | (1 << 1) | (1 << 0))
	str	r1, [r0, r2]

	pop {pc}
/* end modify */

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

wait_phy_state:
	ldr r1, [r0, #DMC_PHYSTATUS]
	tst r1, #(1<<2)
	beq wait_phy_state
	mov pc, lr
/* end add */

dmc_delay:
	push {lr}
1:	subs r2, r2, #1
	bne 1b
	pop {pc}

system_clock_init:
	push {lr}

	ldr r0, =ELFIN_CLOCK_BASE	@0x1003_0000

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

	ldr	r0, =CHIP_ID_BASE
	ldr	r1, [r0]
	lsr	r1, r1, #8
	and	r1, r1, #3
	cmp	r1, #2
	bne	v310_2

	/* check C2C_CTRL enable bit */
	ldr r3, =LANDROVER_POWER_BASE
	ldr r1, [r3, #C2C_CTRL_OFFSET]
	and r1, r1, #1
	cmp r1, #0
	bne v310_2

@ ConControl
#ifdef MEM_DLLl_ON
	ldr	r0, =APB_DMC_0_BASE

	ldr	r1, =0x7F10100A
	ldr	r2, =DMC_PHYCONTROL0
	str	r1, [r0, r2]

	ldr	r1, =0xE0000084
	ldr	r2, =DMC_PHYCONTROL1
	str	r1, [r0, r2]

	ldr	r1, =0x7F10100B
	ldr	r2, =DMC_PHYCONTROL0
	str	r1, [r0, r2]

	bl wait_phy_state

	ldr	r1, =0x0000008C
	ldr	r2, =DMC_PHYCONTROL1
	str	r1, [r0, r2]
	ldr	r1, =0x00000084
	ldr	r2, =DMC_PHYCONTROL1
	str	r1, [r0, r2]

	bl wait_phy_state

	ldr	r0, =APB_DMC_1_BASE

	ldr	r1, =0x7F10100A
	ldr	r2, =DMC_PHYCONTROL0
	str	r1, [r0, r2]

	ldr	r1, =0xE0000084
	ldr	r2, =DMC_PHYCONTROL1
	str	r1, [r0, r2]

	ldr	r1, =0x7F10100B
	ldr	r2, =DMC_PHYCONTROL0
	str	r1, [r0, r2]

	bl wait_phy_state

	ldr	r1, =0x0000008C
	ldr	r2, =DMC_PHYCONTROL1
	str	r1, [r0, r2]
	ldr	r1, =0x00000084
	ldr	r2, =DMC_PHYCONTROL1
	str	r1, [r0, r2]

	bl wait_phy_state
#endif

	ldr	r0, =APB_DMC_0_BASE
	ldr	r1, =0x0FFF30FA
	ldr	r2, =DMC_CONCONTROL
	str	r1, [r0, r2]

	ldr	r0, =APB_DMC_1_BASE
	ldr	r1, =0x0FFF30FA
	ldr	r2, =DMC_CONCONTROL
	str	r1, [r0, r2]

	ldr	r0, =APB_DMC_0_BASE
	ldr	r1, =0x00202533
	ldr	r2, =DMC_MEMCONTROL
	str	r1, [r0, r2]

	ldr	r0, =APB_DMC_1_BASE
	ldr	r1, =0x00202533
	ldr	r2, =DMC_MEMCONTROL
	str	r1, [r0, r2]

v310_2:
	pop	{pc}
#endif		// end of CONFIG_LANDROVER

/*------------------------------------------------------------------------------*/

ENTRY(c_runtime_cpu_setup)
/*
 * If I-cache is enabled invalidate it
 */
#ifndef CONFIG_SYS_ICACHE_OFF
	mcr	p15, 0, r0, c7, c5, 0	@ invalidate icache
	mcr     p15, 0, r0, c7, c10, 4	@ DSB
	mcr     p15, 0, r0, c7, c5, 4	@ ISB
#endif

	bx	lr

ENDPROC(c_runtime_cpu_setup)

/*************************************************************************
 *
 * void save_boot_params(u32 r0, u32 r1, u32 r2, u32 r3)
 *	__attribute__((weak));
 *
 * Stack pointer is not yet initialized at this moment
 * Don't save anything to stack even if compiled with -O0
 *
 *************************************************************************/
ENTRY(save_boot_params)
	b	save_boot_params_ret		@ back to my caller
ENDPROC(save_boot_params)
	.weak	save_boot_params

/*************************************************************************
 *
 * cpu_init_cp15
 *
 * Setup CP15 registers (cache, MMU, TLBs). The I-cache is turned on unless
 * CONFIG_SYS_ICACHE_OFF is defined.
 *
 *************************************************************************/
ENTRY(cpu_init_cp15)
	/*
	 * Invalidate L1 I/D
	 */
	mov	r0, #0			@ set up for MCR
	mcr	p15, 0, r0, c8, c7, 0	@ invalidate TLBs
	mcr	p15, 0, r0, c7, c5, 0	@ invalidate icache
	mcr	p15, 0, r0, c7, c5, 6	@ invalidate BP array
	mcr     p15, 0, r0, c7, c10, 4	@ DSB
	mcr     p15, 0, r0, c7, c5, 4	@ ISB

	/*
	 * disable MMU stuff and caches
	 */
	mrc	p15, 0, r0, c1, c0, 0
	bic	r0, r0, #0x00002000	@ clear bits 13 (--V-)
	bic	r0, r0, #0x00000007	@ clear bits 2:0 (-CAM)
	orr	r0, r0, #0x00000002	@ set bit 1 (--A-) Align
	orr	r0, r0, #0x00000800	@ set bit 11 (Z---) BTB
#ifdef CONFIG_SYS_ICACHE_OFF
	bic	r0, r0, #0x00001000	@ clear bit 12 (I) I-cache
#else
	orr	r0, r0, #0x00001000	@ set bit 12 (I) I-cache
#endif
	mcr	p15, 0, r0, c1, c0, 0

#ifdef CONFIG_ARM_ERRATA_716044
	mrc	p15, 0, r0, c1, c0, 0	@ read system control register
	orr	r0, r0, #1 << 11	@ set bit #11
	mcr	p15, 0, r0, c1, c0, 0	@ write system control register
#endif

#if (defined(CONFIG_ARM_ERRATA_742230) || defined(CONFIG_ARM_ERRATA_794072))
	mrc	p15, 0, r0, c15, c0, 1	@ read diagnostic register
	orr	r0, r0, #1 << 4		@ set bit #4
	mcr	p15, 0, r0, c15, c0, 1	@ write diagnostic register
#endif

#ifdef CONFIG_ARM_ERRATA_743622
	mrc	p15, 0, r0, c15, c0, 1	@ read diagnostic register
	orr	r0, r0, #1 << 6		@ set bit #6
	mcr	p15, 0, r0, c15, c0, 1	@ write diagnostic register
#endif

#ifdef CONFIG_ARM_ERRATA_751472
	mrc	p15, 0, r0, c15, c0, 1	@ read diagnostic register
	orr	r0, r0, #1 << 11	@ set bit #11
	mcr	p15, 0, r0, c15, c0, 1	@ write diagnostic register
#endif
#ifdef CONFIG_ARM_ERRATA_761320
	mrc	p15, 0, r0, c15, c0, 1	@ read diagnostic register
	orr	r0, r0, #1 << 21	@ set bit #21
	mcr	p15, 0, r0, c15, c0, 1	@ write diagnostic register
#endif

	mov	r5, lr			@ Store my Caller
	mrc	p15, 0, r1, c0, c0, 0	@ r1 has Read Main ID Register (MIDR)
	mov	r3, r1, lsr #20		@ get variant field
	and	r3, r3, #0xf		@ r3 has CPU variant
	and	r4, r1, #0xf		@ r4 has CPU revision
	mov	r2, r3, lsl #4		@ shift variant field for combined value
	orr	r2, r4, r2		@ r2 has combined CPU variant + revision

#ifdef CONFIG_ARM_ERRATA_798870
	cmp	r2, #0x30		@ Applies to lower than R3p0
	bge	skip_errata_798870      @ skip if not affected rev
	cmp	r2, #0x20		@ Applies to including and above R2p0
	blt	skip_errata_798870      @ skip if not affected rev

	mrc	p15, 1, r0, c15, c0, 0  @ read l2 aux ctrl reg
	orr	r0, r0, #1 << 7         @ Enable hazard-detect timeout
	push	{r1-r5}			@ Save the cpu info registers
	bl	v7_arch_cp15_set_l2aux_ctrl
	isb				@ Recommended ISB after l2actlr update
	pop	{r1-r5}			@ Restore the cpu info - fall through
skip_errata_798870:
#endif

#ifdef CONFIG_ARM_ERRATA_454179
	cmp	r2, #0x21		@ Only on < r2p1
	bge	skip_errata_454179

	mrc	p15, 0, r0, c1, c0, 1	@ Read ACR
	orr	r0, r0, #(0x3 << 6)	@ Set DBSM(BIT7) and IBE(BIT6) bits
	push	{r1-r5}			@ Save the cpu info registers
	bl	v7_arch_cp15_set_acr
	pop	{r1-r5}			@ Restore the cpu info - fall through

skip_errata_454179:
#endif

#ifdef CONFIG_ARM_ERRATA_430973
	cmp	r2, #0x21		@ Only on < r2p1
	bge	skip_errata_430973

	mrc	p15, 0, r0, c1, c0, 1	@ Read ACR
	orr	r0, r0, #(0x1 << 6)	@ Set IBE bit
	push	{r1-r5}			@ Save the cpu info registers
	bl	v7_arch_cp15_set_acr
	pop	{r1-r5}			@ Restore the cpu info - fall through

skip_errata_430973:
#endif

#ifdef CONFIG_ARM_ERRATA_621766
	cmp	r2, #0x21		@ Only on < r2p1
	bge	skip_errata_621766

	mrc	p15, 0, r0, c1, c0, 1	@ Read ACR
	orr	r0, r0, #(0x1 << 5)	@ Set L1NEON bit
	push	{r1-r5}			@ Save the cpu info registers
	bl	v7_arch_cp15_set_acr
	pop	{r1-r5}			@ Restore the cpu info - fall through

skip_errata_621766:
#endif

	mov	pc, r5			@ back to my caller
ENDPROC(cpu_init_cp15)

#ifndef CONFIG_SKIP_LOWLEVEL_INIT
/*************************************************************************
 *
 * CPU_init_critical registers
 *
 * setup important registers
 * setup memory timing
 *
 *************************************************************************/
ENTRY(cpu_init_crit)
	/*
	 * Jump to board specific initialization...
	 * The Mask ROM will have already initialized
	 * basic memory. Go here to bump up clock rate and handle
	 * wake up conditions.
	 */
	b	lowlevel_init		@ go setup pll,mux,memory
ENDPROC(cpu_init_crit)
#endif
