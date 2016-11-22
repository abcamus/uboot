/*
 * Copyright (C) 2011 Samsung Electronics
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/arch/cpu.h>
#include <asm/arch/mmc.h>
#include <asm/arch/periph.h>
#include <asm/arch/pinmux.h>
#include <usb.h>

#define GPL2CON     (*(volatile unsigned long *) 0x11000100)
#define GPL2DAT     (*(volatile unsigned long *) 0x11000104)

#define GPK1CON 	(*(volatile unsigned long *) 0x11000060)
#define GPK1DAT		(*(volatile unsigned long *) 0x11000064)

void delay(int r0)
{
    volatile int count = r0;
    while (count--)
        ;
}

DECLARE_GLOBAL_DATA_PTR;

u32 get_board_rev(void)
{
	return 0;
}

int exynos_init(void)
{	
	GPL2CON = 0x00000001;
	GPK1CON = 0x00000010;
	
	while(1)							
	{
		GPL2DAT = 1;
		GPK1DAT = 0;
		delay(0x80000);
		GPL2DAT = 0;
		GPK1DAT = 0x2;
		delay(0x80000);
	}
	return 0;
}

int board_usb_init(int index, enum usb_init_type init)
{
	return 0;
}

#ifdef CONFIG_BOARD_EARLY_INIT_F
int exynos_early_init_f(void)
{
	return 0;
}
#endif
