/*
 * Copyright (C) 2011 Samsung Electronics
 *
 * Configuration settings for the Samsung LANDROVER(EXYNOS4410) board.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_LANDROVER_H
#define __CONFIG_LANDROVER_H

#include <configs/exynos4-common.h>

#define CONFIG_SUPPORT_EMMC_BOOT
/*
 * #define CONFIG_EXYNOS_FB
#define CONFIG_LCD
 */
#define CONFIG_EXYNOS_FB
#define CONFIG_LCD
#define CONFIG_FB_ADDR	0x40000000
#define LCD_TEST_PATTERN
#define LCD_BPP		LCD_COLOR16

/*
#define CONFIG_USE_IRQ
 */
#ifdef CONFIG_USE_IRQ
#define CONFIG_STACKSIZE_IRQ		0x1000
#define CONFIG_STACKSIZE_FIQ		0x1000
#endif
#define CONFIG_SYS_PROMPT		"landrover > "
#define BOOT_MICROPY

#ifdef BOOT_MICROPY
#define CONFIG_SYS_THUMB_BUILD
#endif

/* High Level Configuration Options */
#define CONFIG_EXYNOS4210		1	/* which is a EXYNOS4210 SoC */
#define CONFIG_LANDROVER			1	/* working with LANDROVER*/

#define CONFIG_SYS_DCACHE_OFF		1

/* LANDROVER has 4 bank of DRAM */
#define CONFIG_NR_DRAM_BANKS		4
#define CONFIG_SYS_SDRAM_BASE		0x40000000
#define PHYS_SDRAM_1			CONFIG_SYS_SDRAM_BASE
#define SDRAM_BANK_SIZE			(256 << 20)	/* 256 MB */

/* memtest works on */
#define CONFIG_SYS_MEMTEST_START	CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_SDRAM_BASE + 0x6000000)
#define CONFIG_SYS_LOAD_ADDR		(CONFIG_SYS_SDRAM_BASE + 0x00100000)

#define CONFIG_SYS_TEXT_BASE	0x43e00000

#define MACH_TYPE_LANDROVER		0xffffffff
#define CONFIG_MACH_TYPE		MACH_TYPE_LANDROVER

/* select serial console configuration */
#define CONFIG_SERIAL2
#define CONFIG_BAUDRATE			115200

/* Console configuration */
#define CONFIG_SYS_CONSOLE_INFO_QUIET
#define CONFIG_SYS_CONSOLE_IS_IN_ENV
#define CONFIG_DEFAULT_CONSOLE		"console=ttySAC1,115200n8\0"

#define CONFIG_SYS_MEM_TOP_HIDE	(1 << 20)	/* ram console */

#define CONFIG_SYS_MONITOR_BASE	0x00000000

/* Power Down Modes */
#define S5P_CHECK_SLEEP			0x00000BAD
#define S5P_CHECK_DIDLE			0xBAD00000
#define S5P_CHECK_LPA			0xABAD0000

#undef CONFIG_CMD_PING
#define CONFIG_CMD_ELF
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_EXT2
#define CONFIG_CMD_FS_GENERIC
#define CONFIG_CMD_BOOTZ
#define CONFIG_SUPPORT_RAW_INITRD
#undef CONFIG_CMD_NET
#undef CONFIG_CMD_NFS

/* MMC SPL */
#define COPY_BL2_FNPTR_ADDR		0x02020030
#define CONFIG_SPL_TEXT_BASE	0x02023400	/*0x02021410*/

#define CONFIG_EXTRA_ENV_SETTINGS \
	"loadaddr=0x40007000\0" \
	"rdaddr=0x48000000\0" \
	"kerneladdr=0x40007000\0" \
	"ramdiskaddr=0x48000000\0" \
	"console=ttySAC2,115200n8\0" \
	"mmcdev=0\0" \
	"bootenv=uEnv.txt\0" \
	"dtb_addr=0x41000000\0" \
	"dtb_name=exynos4412-landrover.dtb\0" \
	"loadbootenv=load mmc ${mmcdev} ${loadaddr} ${bootenv}\0" \
	"bootargs=console=ttySAC2,115200n8 earlyprintk\0" \
	"importbootenv=echo Importing environment from mmc ...; " \
	"env import -t $loadaddr $filesize\0" \
    "loadbootscript=load mmc ${mmcdev} ${loadaddr} boot.scr\0" \
    "bootscript=echo Running bootscript from mmc${mmcdev} ...; " \
    "source ${loadaddr}\0"
#define CONFIG_BOOTCOMMAND \
	"if mmc rescan; then " \
		"echo SD/MMC found on device ${mmcdev};" \
		"if run loadbootenv; then " \
			"echo Loaded environment from ${bootenv};" \
			"run importbootenv;" \
		"fi;" \
		"if test -n $uenvcmd; then " \
			"echo Running uenvcmd ...;" \
			"run uenvcmd;" \
		"fi;" \
		"if run loadbootscript; then " \
			"run bootscript; " \
		"fi; " \
	"fi;" \
	"mmc read ${loadaddr} 0x1000 0x4000; mmc read ${dtb_addr} 0x800 0xa0; bootm ${loadaddr} - ${dtb_addr}" \
	"load mmc ${mmcdev} ${loadaddr} uImage; load mmc ${mmcdev} ${dtb_addr} ${dtb_name}; bootm ${loadaddr} - ${dtb_addr}"

#define CONFIG_IDENT_STRING		" for LANDROVER"

#define CONFIG_CLK_1000_400_200

/* MIU (Memory Interleaving Unit) */
#define CONFIG_MIU_2BIT_21_7_INTERLEAVED

#define CONFIG_ENV_IS_IN_MMC
#define CONFIG_SYS_MMC_ENV_DEV		0
#define CONFIG_ENV_SIZE			(16 << 10)	/* 16 KB */
#define RESERVE_BLOCK_SIZE		(512)
#define BL1_SIZE			(16 << 10) /*16 K reserved for BL1*/
#define CONFIG_ENV_OFFSET		(RESERVE_BLOCK_SIZE + BL1_SIZE)

#define CONFIG_SPL_LDSCRIPT	"board/samsung/common/exynos-uboot-spl.lds"
#define CONFIG_SPL_MAX_FOOTPRINT	(14 * 1024)

#define CONFIG_SPL_STACK			0x02040000
#define UBOOT_SIZE					(2 << 20)
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_TEXT_BASE+UBOOT_SIZE-0x1000)

/* U-boot copy size (512KB) from boot Media to DRAM.*/
#define COPY_BL2_SIZE		0x80000
#define BL2_START_OFFSET	((CONFIG_ENV_OFFSET + CONFIG_ENV_SIZE)/512)
#define BL2_SIZE_BLOC_COUNT	(COPY_BL2_SIZE/512)

#endif	/* __CONFIG_H */
