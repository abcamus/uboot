/*
 * Copyright (C) 2012 Samsung Electronics
 *
 * Author: InKi Dae <inki.dae@samsung.com>
 * Author: Donghwa Lee <dh09.lee@samsung.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _EXYNOS_FB_H_
#define _EXYNOS_FB_H_

#include <asm/arch/fb.h>

#define EXYNOS_GPIO_BASE	0x11400000
#define GPD0CON		(EXYNOS_GPIO_BASE+0xA0)
#define GPD0DAT		(GPD0CON+0x4)
#define GPD0PUD		(GPD0CON+0x8)
#define GPD0DRV		(GPD0CON+0xC)

#define GPF0CON		(EXYNOS_GPIO_BASE+0x180)
#define GPF0DRV		(GPF0CON+0xC)

#define GPF1CON		(EXYNOS_GPIO_BASE+0x1A0)
#define GPF1DRV		(GPF1CON+0xC)

#define GPF2CON		(EXYNOS_GPIO_BASE+0x1C0)
#define GPF2DRV		(GPF2CON+0xC)

#define GPF3CON		(EXYNOS_GPIO_BASE+0x1E0)
#define GPF3DRV		(GPF3CON+0xC)

#define GPC0CON		(EXYNOS_GPIO_BASE+0x60)
#define GPC0DAT		(GPC0CON+0x4)

#define EXYNOS_GPIO_BASE_PART2	0x11000000
#define GPL0CON		(EXYNOS_GPIO_BASE_PART2+0xC0)
#define GPL0DAT		(GPL0CON+0x4)


#define MAX_CLOCK	(86 * 1000000)

enum exynos_cpu_auto_cmd_rate {
	DISABLE_AUTO_FRM,
	PER_TWO_FRM,
	PER_FOUR_FRM,
	PER_SIX_FRM,
	PER_EIGHT_FRM,
	PER_TEN_FRM,
	PER_TWELVE_FRM,
	PER_FOURTEEN_FRM,
	PER_SIXTEEN_FRM,
	PER_EIGHTEEN_FRM,
	PER_TWENTY_FRM,
	PER_TWENTY_TWO_FRM,
	PER_TWENTY_FOUR_FRM,
	PER_TWENTY_SIX_FRM,
	PER_TWENTY_EIGHT_FRM,
	PER_THIRTY_FRM,
};

void exynos_fimd_lcd_init_mem(unsigned long screen_base, unsigned long fb_size,
	unsigned long palette_size);
void exynos_fimd_lcd_init(vidinfo_t *vid);
unsigned long exynos_fimd_calc_fbsize(void);

#endif
