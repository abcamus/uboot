/*
 * (C) Copyright 2012 Samsung Electronics
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __TZPC_H_
#define __TZPC_H_

#ifndef __ASSEMBLY__
struct exynos_tzpc {
	unsigned int r0size;		// 0x0000
	char res1[0x7FC];			// 0x0004
	unsigned int decprot0stat;	// 0x0800
	unsigned int decprot0set;	// 0x0804
	unsigned int decprot0clr;	// 0x0808
	unsigned int decprot1stat;	// 0x080c
	unsigned int decprot1set;	// 0x0810
	unsigned int decprot1clr;	// 0x0814
	unsigned int decprot2stat;	// 0x0818
	unsigned int decprot2set;	// 0x081c
	unsigned int decprot2clr;	// 0x0820
	unsigned int decprot3stat;	// 0x0824
	unsigned int decprot3set;	// 0x0828
	unsigned int decprot3clr;	// 0x082c
	char res2[0x7B0];			// 0x0830
	unsigned int periphid0;		// 0x0fe0
	unsigned int periphid1;		// 0x0fe4
	unsigned int periphid2;		// 0x0fe8
	unsigned int periphid3;		// 0x0fec
	unsigned int pcellid0;		// 0x0ff0
	unsigned int pcellid1;		// 0x0ff4
	unsigned int pcellid2;		// 0x0ff8
	unsigned int pcellid3;		// 0x0ffc
};

#define EXYNOS4_NR_TZPC_BANKS		6
#define EXYNOS5_NR_TZPC_BANKS		10

/* TZPC : Register Offsets */
#define TZPC_BASE_OFFSET		0x10000

/*
 * TZPC Register Value :
 * R0SIZE: 0x0 : Size of secured ram
 */
#define R0SIZE			0x0

/*
 * TZPC Decode Protection Register Value :
 * DECPROTXSET: 0xFF : Set Decode region to non-secure
 */
#define DECPROTXSET		0xFF
void tzpc_init(void);

#endif

#endif
