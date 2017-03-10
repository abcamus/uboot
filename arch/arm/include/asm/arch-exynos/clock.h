/*
 * (C) Copyright 2010 Samsung Electronics
 * Minkyu Kang <mk7.kang@samsung.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __ASM_ARM_ARCH_CLOCK_H_
#define __ASM_ARM_ARCH_CLOCK_H_

#ifndef __ASSEMBLY__
struct exynos4_clock {
	unsigned char	res1[0x4200];
	unsigned int	src_leftbus;
	unsigned char	res2[0x1fc];
	unsigned int	mux_stat_leftbus;
	unsigned char	res4[0xfc];
	unsigned int	div_leftbus;
	unsigned char	res5[0xfc];
	unsigned int	div_stat_leftbus;
	unsigned char	res6[0x1fc];
	unsigned int	gate_ip_leftbus;
	unsigned char	res7[0x1fc];
	unsigned int	clkout_leftbus;
	unsigned int	clkout_leftbus_div_stat;
	unsigned char	res8[0x37f8];
	unsigned int	src_rightbus;
	unsigned char	res9[0x1fc];
	unsigned int	mux_stat_rightbus;
	unsigned char	res10[0xfc];
	unsigned int	div_rightbus;
	unsigned char	res11[0xfc];
	unsigned int	div_stat_rightbus;
	unsigned char	res12[0x1fc];
	unsigned int	gate_ip_rightbus;
	unsigned char	res13[0x1fc];
	unsigned int	clkout_rightbus;
	unsigned int	clkout_rightbus_div_stat;
	unsigned char	res14[0x3608];
	unsigned int	epll_lock;
	unsigned char	res15[0xc];
	unsigned int	vpll_lock;
	unsigned char	res16[0xec];
	unsigned int	epll_con0;
	unsigned int	epll_con1;
	unsigned char	res17[0x8];
	unsigned int	vpll_con0;
	unsigned int	vpll_con1;
	unsigned char	res18[0xe8];
	unsigned int	src_top0;
	unsigned int	src_top1;
	unsigned char	res19[0x8];
	unsigned int	src_cam;
	unsigned int	src_tv;
	unsigned int	src_mfc;
	unsigned int	src_g3d;
	unsigned int	src_image;
	unsigned int	src_lcd0;
	unsigned int	src_lcd1;
	unsigned int	src_maudio;
	unsigned int	src_fsys;
	unsigned char	res20[0xc];
	unsigned int	src_peril0;
	unsigned int	src_peril1;
	unsigned char	res21[0xb8];
	unsigned int	src_mask_top;
	unsigned char	res22[0xc];
	unsigned int	src_mask_cam;
	unsigned int	src_mask_tv;
	unsigned char	res23[0xc];
	unsigned int	src_mask_lcd0;
	unsigned int	src_mask_lcd1;
	unsigned int	src_mask_maudio;
	unsigned int	src_mask_fsys;
	unsigned char	res24[0xc];
	unsigned int	src_mask_peril0;
	unsigned int	src_mask_peril1;
	unsigned char	res25[0xb8];
	unsigned int	mux_stat_top;
	unsigned char	res26[0x14];
	unsigned int	mux_stat_mfc;
	unsigned int	mux_stat_g3d;
	unsigned int	mux_stat_image;
	unsigned char	res27[0xdc];
	unsigned int	div_top;
	unsigned char	res28[0xc];
	unsigned int	div_cam;
	unsigned int	div_tv;
	unsigned int	div_mfc;
	unsigned int	div_g3d;
	unsigned int	div_image;
	unsigned int	div_lcd0;
	unsigned int	div_lcd1;
	unsigned int	div_maudio;
	unsigned int	div_fsys0;
	unsigned int	div_fsys1;
	unsigned int	div_fsys2;
	unsigned int	div_fsys3;
	unsigned int	div_peril0;
	unsigned int	div_peril1;
	unsigned int	div_peril2;
	unsigned int	div_peril3;
	unsigned int	div_peril4;
	unsigned int	div_peril5;
	unsigned char	res29[0x18];
	unsigned int	div2_ratio;
	unsigned char	res30[0x8c];
	unsigned int	div_stat_top;
	unsigned char	res31[0xc];
	unsigned int	div_stat_cam;
	unsigned int	div_stat_tv;
	unsigned int	div_stat_mfc;
	unsigned int	div_stat_g3d;
	unsigned int	div_stat_image;
	unsigned int	div_stat_lcd0;
	unsigned int	div_stat_lcd1;
	unsigned int	div_stat_maudio;
	unsigned int	div_stat_fsys0;
	unsigned int	div_stat_fsys1;
	unsigned int	div_stat_fsys2;
	unsigned int	div_stat_fsys3;
	unsigned int	div_stat_peril0;
	unsigned int	div_stat_peril1;
	unsigned int	div_stat_peril2;
	unsigned int	div_stat_peril3;
	unsigned int	div_stat_peril4;
	unsigned int	div_stat_peril5;
	unsigned char	res32[0x18];
	unsigned int	div2_stat;
	unsigned char	res33[0x29c];
	unsigned int	gate_ip_cam;
	unsigned int	gate_ip_tv;
	unsigned int	gate_ip_mfc;
	unsigned int	gate_ip_g3d;
	unsigned int	gate_ip_image;
	unsigned int	gate_ip_lcd0;
	unsigned int	gate_ip_lcd1;
	unsigned char	res34[0x4];
	unsigned int	gate_ip_fsys;
	unsigned char	res35[0x8];
	unsigned int	gate_ip_gps;
	unsigned int	gate_ip_peril;
	unsigned char	res36[0xc];
	unsigned int	gate_ip_perir;
	unsigned char	res37[0xc];
	unsigned int	gate_block;
	unsigned char	res38[0x8c];
	unsigned int	clkout_cmu_top;
	unsigned int	clkout_cmu_top_div_stat;
	unsigned char	res39[0x37f8];
	unsigned int	src_dmc;
	unsigned char	res40[0xfc];
	unsigned int	src_mask_dmc;
	unsigned char	res41[0xfc];
	unsigned int	mux_stat_dmc;
	unsigned char	res42[0xfc];
	unsigned int	div_dmc0;
	unsigned int	div_dmc1;
	unsigned char	res43[0xf8];
	unsigned int	div_stat_dmc0;
	unsigned int	div_stat_dmc1;
	unsigned char	res44[0x2f8];
	unsigned int	gate_ip_dmc;
	unsigned char	res45[0xfc];
	unsigned int	clkout_cmu_dmc;
	unsigned int	clkout_cmu_dmc_div_stat;
	unsigned char	res46[0x5f8];
	unsigned int	dcgidx_map0;
	unsigned int	dcgidx_map1;
	unsigned int	dcgidx_map2;
	unsigned char	res47[0x14];
	unsigned int	dcgperf_map0;
	unsigned int	dcgperf_map1;
	unsigned char	res48[0x18];
	unsigned int	dvcidx_map;
	unsigned char	res49[0x1c];
	unsigned int	freq_cpu;
	unsigned int	freq_dpm;
	unsigned char	res50[0x18];
	unsigned int	dvsemclk_en;
	unsigned int	maxperf;
	unsigned char	res51[0x2f78];
	unsigned int	apll_lock;
	unsigned char	res52[0x4];
	unsigned int	mpll_lock;
	unsigned char	res53[0xf4];
	unsigned int	apll_con0;
	unsigned int	apll_con1;
	unsigned int	mpll_con0;
	unsigned int	mpll_con1;
	unsigned char	res54[0xf0];
	unsigned int	src_cpu;
	unsigned char	res55[0x1fc];
	unsigned int	mux_stat_cpu;
	unsigned char	res56[0xfc];
	unsigned int	div_cpu0;
	unsigned int	div_cpu1;
	unsigned char	res57[0xf8];
	unsigned int	div_stat_cpu0;
	unsigned int	div_stat_cpu1;
	unsigned char	res58[0x3f8];
	unsigned int	clkout_cmu_cpu;
	unsigned int	clkout_cmu_cpu_div_stat;
	unsigned char	res59[0x5f8];
	unsigned int	armclk_stopctrl;
	unsigned int	atclk_stopctrl;
	unsigned char	res60[0x8];
	unsigned int	parityfail_status;
	unsigned int	parityfail_clear;
	unsigned char	res61[0xe8];
	unsigned int	apll_con0_l8;
	unsigned int	apll_con0_l7;
	unsigned int	apll_con0_l6;
	unsigned int	apll_con0_l5;
	unsigned int	apll_con0_l4;
	unsigned int	apll_con0_l3;
	unsigned int	apll_con0_l2;
	unsigned int	apll_con0_l1;
	unsigned int	iem_control;
	unsigned char	res62[0xdc];
	unsigned int	apll_con1_l8;
	unsigned int	apll_con1_l7;
	unsigned int	apll_con1_l6;
	unsigned int	apll_con1_l5;
	unsigned int	apll_con1_l4;
	unsigned int	apll_con1_l3;
	unsigned int	apll_con1_l2;
	unsigned int	apll_con1_l1;
	unsigned char	res63[0xe0];
	unsigned int	div_iem_l8;
	unsigned int	div_iem_l7;
	unsigned int	div_iem_l6;
	unsigned int	div_iem_l5;
	unsigned int	div_iem_l4;
	unsigned int	div_iem_l3;
	unsigned int	div_iem_l2;
	unsigned int	div_iem_l1;
};

struct exynos4x12_clock {
	unsigned char	res1[0x4200];
	unsigned int	src_leftbus;	// 0x4200
	unsigned char	res2[0x1fc];	// 0x4204
	unsigned int	mux_stat_leftbus;	// 0x4400
	unsigned char	res3[0xfc];		// 0x4404
	unsigned int	div_leftbus;	// 0x4500
	unsigned char	res4[0xfc];
	unsigned int	div_stat_leftbus;	// 0x4600
	unsigned char	res5[0x1fc];
	unsigned int	gate_ip_leftbus;	// 0x4800
	unsigned char	res6[0x12c];	// 0x4804
	unsigned int	gate_ip_image;	// 0x4930
	unsigned char	res7[0xcc];
	unsigned int	clkout_leftbus;		// 0x4a00
	unsigned int	clkout_leftbus_div_stat;	// 0x4a04
	unsigned char	res8[0x37f8];
	unsigned int	src_rightbus;	// 0x8200
	unsigned char	res9[0x1fc];
	unsigned int	mux_stat_rightbus;	// 0x8400
	unsigned char	res10[0xfc];
	unsigned int	div_rightbus;	// 0x8500
	unsigned char	res11[0xfc];
	unsigned int	div_stat_rightbus;	// 0x8600
	unsigned char	res12[0x1fc];
	unsigned int	gate_ip_rightbus;	// 0x8800
	unsigned char	res13[0x15c];
	unsigned int	gate_ip_perir;	// 0x8960
	unsigned char	res14[0x9c];
	unsigned int	clkout_rightbus;	// 0x8a00
	unsigned int	clkout_rightbus_div_stat;
	unsigned char	res15[0x3608];	// 0x8a08
	unsigned int	epll_lock;	// 0xc010
	unsigned char	res16[0xc];
	unsigned int	vpll_lock;	// 0xc020
	unsigned char	res17[0xec];
	unsigned int	epll_con0;	// 0xc110
	unsigned int	epll_con1;	// 0xc114
	unsigned int	epll_con2;	// 0xc118
	unsigned char	res18[0x4];
	unsigned int	vpll_con0;	// 0xc120
	unsigned int	vpll_con1;
	unsigned int	vpll_con2;	// 0xc128
	unsigned char	res19[0xe4];
	unsigned int	src_top0;	// 0xc210
	unsigned int	src_top1;
	unsigned char	res20[0x8];	// 0xc218
	unsigned int	src_cam;	// 0xc220
	unsigned int	src_tv;
	unsigned int	src_mfc;	// 0xc228
	unsigned int	src_g3d;	// 0xc22c
	unsigned char	res21[0x4];
	unsigned int	src_lcd0;	// 0xc234
	unsigned int	src_isp;	// 0xc238
	unsigned int	src_maudio;
	unsigned int	src_fsys;	// 0xc240
	unsigned char	res22[0xc];
	unsigned int	src_peril0;	// 0xc250
	unsigned int	src_peril1;
	unsigned int	src_cam1;	// 0xc258
	unsigned char	res23[0xb4];
	unsigned int	src_mask_top;	// 0xc310
	unsigned char	res24[0xc];
	unsigned int	src_mask_cam;	// 0xc320
	unsigned int	src_mask_tv;	// 0xc324
	unsigned char	res25[0xc];
	unsigned int	src_mask_lcd;	// 0xc334
	unsigned int	src_mask_isp;
	unsigned int	src_mask_maudio;
	unsigned int	src_mask_fsys;	// 0xc340
	unsigned char	res26[0xc];
	unsigned int	src_mask_peril0;	// 0xc350
	unsigned int	src_mask_peril1;	// 0xc354
	unsigned char	res27[0xb8];
	unsigned int	mux_stat_top0;	// 0xc410
	unsigned int	mux_stat_top1;	// 0xc414
	unsigned char	res28[0x10];	// 0xc418
	unsigned int	mux_stat_mfc;	// 0xc428
	unsigned int	mux_stat_g3d;	// 0xc42c
	unsigned char	res29[0x28];	// 0xc430
	unsigned int	mux_stat_cam1;	// 0xc458
	unsigned char	res30[0xb4];	// 0xc45c
	unsigned int	div_top;		// 0xc510
	unsigned char	res31[0xc];		// 0xc514
	unsigned int	div_cam;		// 0xc520
	unsigned int	div_tv;		// 0xc524
	unsigned int	div_mfc;	// 0xc528
	unsigned int	div_g3d;	// 0xc52c
	unsigned char	res32[0x4];	// 0xc530
	unsigned int	div_lcd;	// 0xc534
	unsigned int	div_isp;	// 0xc538
	unsigned int	div_maudio;	// 0xc53c
	unsigned int	div_fsys0;	// 0xc540
	unsigned int	div_fsys1;	// 0xc544
	unsigned int	div_fsys2;	// 0xc548
	unsigned int	div_fsys3;	// 0xc54c
	unsigned int	div_peril0;		// 0xc550
	unsigned int	div_peril1;		// 0xc554
	unsigned int	div_peril2;		// 0xc558
	unsigned int	div_peril3;		// 0xc55c
	unsigned int	div_peril4;		// 0xc560
	unsigned int	div_peril5;		// 0xc564
	unsigned int	div_cam1;		// 0xc568
	unsigned char	res33[0x14];	// 0xc56c
	unsigned int	div2_ratio;		// 0xc580
	unsigned char	res34[0x8c];	// 0xc584
	unsigned int	div_stat_top;	// 0xc610
	unsigned char	res35[0xc];		// 0xc614
	unsigned int	div_stat_cam;	// 0xc620
	unsigned int	div_stat_tv;	// 0xc624
	unsigned int	div_stat_mfc;	// 0xc628
	unsigned int	div_stat_g3d;	// 0xc62c
	unsigned char	res36[0x4];		// 0xc630
	unsigned int	div_stat_lcd;	// 0xc634
	unsigned int	div_stat_isp;	// 0xc638
	unsigned int	div_stat_maudio;	// 0xc63c
	unsigned int	div_stat_fsys0;		// 0xc640
	unsigned int	div_stat_fsys1;		// 0xc644
	unsigned int	div_stat_fsys2;		// 0xc648
	unsigned int	div_stat_fsys3;		// 0xc64c
	unsigned int	div_stat_peril0;	// 0xc650
	unsigned int	div_stat_peril1;	// 0xc654
	unsigned int	div_stat_peril2;	// 0xc658
	unsigned int	div_stat_peril3;	// 0xc65c
	unsigned int	div_stat_peril4;	// 0xc660
	unsigned int	div_stat_peril5;	// 0xc664
	unsigned int	div_stat_cam1;		// 0xc668
	unsigned char	res37[0x14];		// 0xc66c
	unsigned int	div2_stat;		// 0xc680
	unsigned char	res38[0x29c];	// 0xc684
	unsigned int	gate_ip_cam;	// 0xc920
	unsigned int	gate_ip_tv;		// 0xc924
	unsigned int	gate_ip_mfc;	// 0xc928
	unsigned int	gate_ip_g3d;	// 0xc92c
	unsigned char	res39[0x4];		// 0xc930
	unsigned int	gate_ip_lcd;	// 0xc934
	unsigned int	gate_ip_isp;	// 0xc938
	unsigned char	res40[0x4];		// 0xc93c
	unsigned int	gate_ip_fsys;	// 0xc940
	unsigned char	res41[0x8];		// 0xc944
	unsigned int	gate_ip_gps;	// 0xc94c
	unsigned int	gate_ip_peril;	// 0xc950
	unsigned char	res42[0xc];		// 0xc954
	unsigned char	res43[0x4];		// 0xc960
	unsigned char	res44[0xc];		// 0xc964
	unsigned int	gate_block;		// 0xc970
	unsigned char	res45[0x8c];	// 0xc974
	unsigned int	clkout_cmu_top;		// 0xca00
	unsigned int	clkout_cmu_top_div_stat;	// 0xca04
	unsigned char	res46[0x3600];	// 0xca08
	unsigned int	mpll_lock;		// 0x10008
	unsigned char	res47[0xfc];	// 0x1000c
	unsigned int	mpll_con0;		// 0x10108
	unsigned int	mpll_con1;		// 0x1010c
	unsigned char	res48[0xf0];	// 0x10110
	unsigned int	src_dmc;		// 0x10200
	unsigned char	res49[0xfc];	// 0x10204
	unsigned int	src_mask_dmc;	// 0x10300
	unsigned char	res50[0xfc];	// 0x10304
	unsigned int	mux_stat_dmc;	// 0x10400
	unsigned char	res51[0xfc];	// 0x10404
	unsigned int	div_dmc0;		// 0x10500
	unsigned int	div_dmc1;		// 0x10504
	unsigned char	res52[0xf8];	// 0x10508
	unsigned int	div_stat_dmc0;	// 0x10600
	unsigned int	div_stat_dmc1;	// 0x10604
	unsigned char	res53[0xf8];	// 0x10608
	unsigned int	gate_bus_dmc0;	// 0x10700
	unsigned int	gate_bus_dmc1;	// 0x10704
	unsigned char	res54[0x1f8];	// 0x10708
	unsigned int	gate_ip_dmc0;	// 0x10900
	unsigned int	gate_ip_dmc1;	// 0x10904
	unsigned char	res55[0xf8];	// 0x10908
	unsigned int	clkout_cmu_dmc;	// 0x10a00
	unsigned int	clkout_cmu_dmc_div_stat;	// 0x10a04
	unsigned char	res56[0x5f8];	// 0x10a08
	unsigned int	dcgidx_map0;	// 0x11000
	unsigned int	dcgidx_map1;	// 0x11004
	unsigned int	dcgidx_map2;	// 0x11008
	unsigned char	res57[0x14];	// 0x1100c
	unsigned int	dcgperf_map0;	// 0x11020
	unsigned int	dcgperf_map1;	// 0x11024
	unsigned char	res58[0x18];	// 0x11028
	unsigned int	dvcidx_map;		// 0x11040
	unsigned char	res59[0x1c];	// 0x11044
	unsigned int	freq_cpu;	// 0x11060
	unsigned int	freq_dpm;	// 0x11064
	unsigned char	res60[0x18];	// 0x11068
	unsigned int	dvsemclk_en;	// 0x11080
	unsigned int	maxperf;		// 0x11084
	unsigned char	res61[0x8];		// 0x11088
	unsigned int	dmc_freq_ctrl;	// 0x11090
	unsigned int	dmc_pause_ctrl;	// 0x11094
	unsigned int	dddrphy_lock_ctrl;	// 0x11098
	unsigned int	c2c_state;		// 0x1109c
	unsigned char	res62[0x2f60];	// 0x110a0
	unsigned int	apll_lock;		// 0x14000
	unsigned char	res63[0x8];		// 0x14004
	unsigned char	res64[0xf4];	// 0x1400c
	unsigned int	apll_con0;		// 0x14100
	unsigned int	apll_con1;		// 0x14104
	unsigned char	res65[0xf8];	// 0x14108
	unsigned int	src_cpu;		// 0x14200
	unsigned char	res66[0x1fc];	// 0x14204
	unsigned int	mux_stat_cpu;	// 0x14400
	unsigned char	res67[0xfc];	// 0x14404
	unsigned int	div_cpu0;		// 0x14500
	unsigned int	div_cpu1;		// 0x14504
	unsigned char	res68[0xf8];	// 0x14508
	unsigned int	div_stat_cpu0;	// 0x14600
	unsigned int	div_stat_cpu1;	// 0x14604
	unsigned char	res69[0x2f8];	// 0x14608
	unsigned int	clk_gate_ip_cpu;	// 0x14900
	unsigned char	res70[0xfc];		// 0x14904
	unsigned int	clkout_cmu_cpu;		// 0x14a00
	unsigned int	clkout_cmu_cpu_div_stat;	// 0x14a04
	unsigned char	res71[0x5f8];		// 0x14a08
	unsigned int	armclk_stopctrl;	// 0x15000
	unsigned int	atclk_stopctrl;		// 0x15004
	unsigned char	res72[0x10];		// 0x15008
	unsigned char	res73[0x8];		// 0x15018
	unsigned int	pwr_ctrl;		// 0x15020
	unsigned int	pwr_ctrl2;		// 0x15024
	unsigned char	res74[0xd8];	// 0x15028
	unsigned int	apll_con0_l8;	// 0x15100
	unsigned int	apll_con0_l7;	// 0x15104
	unsigned int	apll_con0_l6;	// 0x15108
	unsigned int	apll_con0_l5;	// 0x1510c
	unsigned int	apll_con0_l4;	// 0x15110
	unsigned int	apll_con0_l3;	// 0x15114
	unsigned int	apll_con0_l2;	// 0x15118
	unsigned int	apll_con0_l1;	// 0x1511c
	unsigned int	iem_control;	// 0x15120
	unsigned char	res75[0xdc];	// 0x15124
	unsigned int	apll_con1_l8;	// 0x15200
	unsigned int	apll_con1_l7;	// 0x15204
	unsigned int	apll_con1_l6;	// 0x15208
	unsigned int	apll_con1_l5;	// 0x1520c
	unsigned int	apll_con1_l4;	// 0x15210
	unsigned int	apll_con1_l3;	// 0x15214
	unsigned int	apll_con1_l2;	// 0x15218
	unsigned int	apll_con1_l1;	// 0x1521c
	unsigned char	res76[0xe0];	// 0x15220
	unsigned int	div_iem_l8;		// 0x15300
	unsigned int	div_iem_l7;		// 0x15304
	unsigned int	div_iem_l6;		// 0x15308
	unsigned int	div_iem_l5;		// 0x1530c
	unsigned int	div_iem_l4;		// 0x15310
	unsigned int	div_iem_l3;		// 0x15314
	unsigned int	div_iem_l2;		// 0x15318
	unsigned int	div_iem_l1;		// 0x1531c
	unsigned char	res77[0xe0];	// 0x15320
	unsigned int	l2_status;		// 0x15400
	unsigned char	res78[0xc];		// 0x15404
	unsigned int	cpu_status;		// 0x15410
	unsigned char	res79[0xc];		// 0x15414
	unsigned int	ptm_status;		// 0x15420
	unsigned char	res80[0x2edc];	// 0x15424
	unsigned int	div_isp0;		// 0x18300
	unsigned int	div_isp1;		// 0x18304
	unsigned char	res81[0xf8];	// 0x18308
	unsigned int	div_stat_isp0;	// 0x18400
	unsigned int	div_stat_isp1;	// 0x18404
	unsigned char	res82[0x3f8];	// 0x18408
	unsigned int	gate_ip_isp0;	// 0x18800
	unsigned int	gate_ip_isp1;	// 0x18804
	unsigned char	res83[0x1f8];	// 0x18808
	unsigned int	clkout_cmu_isp;	// 0x18a00
	unsigned int	clkout_cmu_ispd_div_stat;	// 0x18a04
	unsigned char	res84[0xf8];	// 0x18a08
	unsigned int	cmu_isp_spar0;	// 0x18b00
	unsigned int	cmu_isp_spar1;	// 0x18b04
	unsigned int	cmu_isp_spar2;	// 0x18b08
	unsigned int	cmu_isp_spar3;	// 0x18b0c
};

struct exynos5_clock {
	unsigned int	apll_lock;
	unsigned char	res1[0xfc];
	unsigned int	apll_con0;
	unsigned int	apll_con1;
	unsigned char	res2[0xf8];
	unsigned int	src_cpu;
	unsigned char	res3[0x1fc];
	unsigned int	mux_stat_cpu;
	unsigned char	res4[0xfc];
	unsigned int	div_cpu0;
	unsigned int	div_cpu1;
	unsigned char	res5[0xf8];
	unsigned int	div_stat_cpu0;
	unsigned int	div_stat_cpu1;
	unsigned char	res6[0x1f8];
	unsigned int	gate_sclk_cpu;
	unsigned char	res7[0x1fc];
	unsigned int	clkout_cmu_cpu;
	unsigned int	clkout_cmu_cpu_div_stat;
	unsigned char	res8[0x5f8];
	unsigned int	armclk_stopctrl;
	unsigned char	res9[0x0c];
	unsigned int	parityfail_status;
	unsigned int	parityfail_clear;
	unsigned char	res10[0x8];
	unsigned int	pwr_ctrl;
	unsigned int	pwr_ctr2;
	unsigned char	res11[0xd8];
	unsigned int	apll_con0_l8;
	unsigned int	apll_con0_l7;
	unsigned int	apll_con0_l6;
	unsigned int	apll_con0_l5;
	unsigned int	apll_con0_l4;
	unsigned int	apll_con0_l3;
	unsigned int	apll_con0_l2;
	unsigned int	apll_con0_l1;
	unsigned int	iem_control;
	unsigned char	res12[0xdc];
	unsigned int	apll_con1_l8;
	unsigned int	apll_con1_l7;
	unsigned int	apll_con1_l6;
	unsigned int	apll_con1_l5;
	unsigned int	apll_con1_l4;
	unsigned int	apll_con1_l3;
	unsigned int	apll_con1_l2;
	unsigned int	apll_con1_l1;
	unsigned char	res13[0xe0];
	unsigned int	div_iem_l8;
	unsigned int	div_iem_l7;
	unsigned int	div_iem_l6;
	unsigned int	div_iem_l5;
	unsigned int	div_iem_l4;
	unsigned int	div_iem_l3;
	unsigned int	div_iem_l2;
	unsigned int	div_iem_l1;
	unsigned char	res14[0x2ce0];
	unsigned int	mpll_lock;
	unsigned char	res15[0xfc];
	unsigned int	mpll_con0;
	unsigned int	mpll_con1;
	unsigned char	res16[0xf8];
	unsigned int	src_core0;
	unsigned int	src_core1;
	unsigned char	res17[0xf8];
	unsigned int	src_mask_core;
	unsigned char	res18[0x100];
	unsigned int	mux_stat_core1;
	unsigned char	res19[0xf8];
	unsigned int	div_core0;
	unsigned int	div_core1;
	unsigned int	div_sysrgt;
	unsigned char	res20[0xf4];
	unsigned int	div_stat_core0;
	unsigned int	div_stat_core1;
	unsigned int	div_stat_sysrgt;
	unsigned char	res21[0x2f4];
	unsigned int	gate_ip_core;
	unsigned int	gate_ip_sysrgt;
	unsigned char	res22[0x8];
	unsigned int	c2c_monitor;
	unsigned char	res23[0xec];
	unsigned int	clkout_cmu_core;
	unsigned int	clkout_cmu_core_div_stat;
	unsigned char	res24[0x5f8];
	unsigned int	dcgidx_map0;
	unsigned int	dcgidx_map1;
	unsigned int	dcgidx_map2;
	unsigned char	res25[0x14];
	unsigned int	dcgperf_map0;
	unsigned int	dcgperf_map1;
	unsigned char	res26[0x18];
	unsigned int	dvcidx_map;
	unsigned char	res27[0x1c];
	unsigned int	freq_cpu;
	unsigned int	freq_dpm;
	unsigned char	res28[0x18];
	unsigned int	dvsemclk_en;
	unsigned int	maxperf;
	unsigned char	res29[0xf78];
	unsigned int	c2c_config;
	unsigned char	res30[0x24fc];
	unsigned int	div_acp;
	unsigned char	res31[0xfc];
	unsigned int	div_stat_acp;
	unsigned char	res32[0x1fc];
	unsigned int	gate_ip_acp;
	unsigned char	res33[0xfc];
	unsigned int	div_syslft;
	unsigned char	res34[0xc];
	unsigned int	div_stat_syslft;
	unsigned char	res35[0x1c];
	unsigned int	gate_ip_syslft;
	unsigned char	res36[0xcc];
	unsigned int	clkout_cmu_acp;
	unsigned int	clkout_cmu_acp_div_stat;
	unsigned char	res37[0x8];
	unsigned int	ufmc_config;
	unsigned char	res38[0x38ec];
	unsigned int	div_isp0;
	unsigned int	div_isp1;
	unsigned int	div_isp2;
	unsigned char	res39[0xf4];
	unsigned int	div_stat_isp0;
	unsigned int	div_stat_isp1;
	unsigned int	div_stat_isp2;
	unsigned char	res40[0x3f4];
	unsigned int	gate_ip_isp0;
	unsigned int	gate_ip_isp1;
	unsigned char	res41[0xf8];
	unsigned int	gate_sclk_isp;
	unsigned char	res42[0xc];
	unsigned int	mcuisp_pwr_ctrl;
	unsigned char	res43[0xec];
	unsigned int	clkout_cmu_isp;
	unsigned int	clkout_cmu_isp_div_stat;
	unsigned char	res44[0x3618];
	unsigned int	cpll_lock;
	unsigned char	res45[0xc];
	unsigned int	epll_lock;
	unsigned char	res46[0xc];
	unsigned int	vpll_lock;
	unsigned char	res47[0xc];
	unsigned int	gpll_lock;
	unsigned char	res48[0xcc];
	unsigned int	cpll_con0;
	unsigned int	cpll_con1;
	unsigned char	res49[0x8];
	unsigned int	epll_con0;
	unsigned int	epll_con1;
	unsigned int	epll_con2;
	unsigned char	res50[0x4];
	unsigned int	vpll_con0;
	unsigned int	vpll_con1;
	unsigned int	vpll_con2;
	unsigned char	res51[0x4];
	unsigned int	gpll_con0;
	unsigned int	gpll_con1;
	unsigned char	res52[0xb8];
	unsigned int	src_top0;
	unsigned int	src_top1;
	unsigned int	src_top2;
	unsigned int	src_top3;
	unsigned int	src_gscl;
	unsigned char	res53[0x8];
	unsigned int	src_disp1_0;
	unsigned char	res54[0x10];
	unsigned int	src_mau;
	unsigned int	src_fsys;
	unsigned int	src_gen;
	unsigned char	res55[0x4];
	unsigned int	src_peric0;
	unsigned int	src_peric1;
	unsigned char	res56[0x18];
	unsigned int	sclk_src_isp;
	unsigned char	res57[0x9c];
	unsigned int	src_mask_top;
	unsigned char	res58[0xc];
	unsigned int	src_mask_gscl;
	unsigned char	res59[0x8];
	unsigned int	src_mask_disp1_0;
	unsigned char	res60[0x4];
	unsigned int	src_mask_mau;
	unsigned char	res61[0x8];
	unsigned int	src_mask_fsys;
	unsigned int	src_mask_gen;
	unsigned char	res62[0x8];
	unsigned int	src_mask_peric0;
	unsigned int	src_mask_peric1;
	unsigned char	res63[0x18];
	unsigned int	src_mask_isp;
	unsigned char	res67[0x9c];
	unsigned int	mux_stat_top0;
	unsigned int	mux_stat_top1;
	unsigned int	mux_stat_top2;
	unsigned int	mux_stat_top3;
	unsigned char	res68[0xf0];
	unsigned int	div_top0;
	unsigned int	div_top1;
	unsigned char	res69[0x8];
	unsigned int	div_gscl;
	unsigned char	res70[0x8];
	unsigned int	div_disp1_0;
	unsigned char	res71[0xc];
	unsigned int	div_gen;
	unsigned char	res72[0x4];
	unsigned int	div_mau;
	unsigned int	div_fsys0;
	unsigned int	div_fsys1;
	unsigned int	div_fsys2;
	unsigned char	res73[0x4];
	unsigned int	div_peric0;
	unsigned int	div_peric1;
	unsigned int	div_peric2;
	unsigned int	div_peric3;
	unsigned int	div_peric4;
	unsigned int	div_peric5;
	unsigned char	res74[0x10];
	unsigned int	sclk_div_isp;
	unsigned char	res75[0xc];
	unsigned int	div2_ratio0;
	unsigned int	div2_ratio1;
	unsigned char	res76[0x8];
	unsigned int	div4_ratio;
	unsigned char	res77[0x6c];
	unsigned int	div_stat_top0;
	unsigned int	div_stat_top1;
	unsigned char	res78[0x8];
	unsigned int	div_stat_gscl;
	unsigned char	res79[0x8];
	unsigned int	div_stat_disp1_0;
	unsigned char	res80[0xc];
	unsigned int	div_stat_gen;
	unsigned char	res81[0x4];
	unsigned int	div_stat_mau;
	unsigned int	div_stat_fsys0;
	unsigned int	div_stat_fsys1;
	unsigned int	div_stat_fsys2;
	unsigned char	res82[0x4];
	unsigned int	div_stat_peric0;
	unsigned int	div_stat_peric1;
	unsigned int	div_stat_peric2;
	unsigned int	div_stat_peric3;
	unsigned int	div_stat_peric4;
	unsigned int	div_stat_peric5;
	unsigned char	res83[0x10];
	unsigned int	sclk_div_stat_isp;
	unsigned char	res84[0xc];
	unsigned int	div2_stat0;
	unsigned int	div2_stat1;
	unsigned char	res85[0x8];
	unsigned int	div4_stat;
	unsigned char	res86[0x184];
	unsigned int	gate_top_sclk_disp1;
	unsigned int	gate_top_sclk_gen;
	unsigned char	res87[0xc];
	unsigned int	gate_top_sclk_mau;
	unsigned int	gate_top_sclk_fsys;
	unsigned char	res88[0xc];
	unsigned int	gate_top_sclk_peric;
	unsigned char	res89[0x1c];
	unsigned int	gate_top_sclk_isp;
	unsigned char	res90[0xac];
	unsigned int	gate_ip_gscl;
	unsigned char	res91[0x4];
	unsigned int	gate_ip_disp1;
	unsigned int	gate_ip_mfc;
	unsigned int	gate_ip_g3d;
	unsigned int	gate_ip_gen;
	unsigned char	res92[0xc];
	unsigned int	gate_ip_fsys;
	unsigned char	res93[0x8];
	unsigned int	gate_ip_peric;
	unsigned char	res94[0xc];
	unsigned int	gate_ip_peris;
	unsigned char	res95[0x1c];
	unsigned int	gate_block;
	unsigned char	res96[0x1c];
	unsigned int	mcuiop_pwr_ctrl;
	unsigned char	res97[0x5c];
	unsigned int	clkout_cmu_top;
	unsigned int	clkout_cmu_top_div_stat;
	unsigned char	res98[0x37f8];
	unsigned int	src_lex;
	unsigned char	res99[0x1fc];
	unsigned int	mux_stat_lex;
	unsigned char	res100[0xfc];
	unsigned int	div_lex;
	unsigned char	res101[0xfc];
	unsigned int	div_stat_lex;
	unsigned char	res102[0x1fc];
	unsigned int	gate_ip_lex;
	unsigned char	res103[0x1fc];
	unsigned int	clkout_cmu_lex;
	unsigned int	clkout_cmu_lex_div_stat;
	unsigned char	res104[0x3af8];
	unsigned int	div_r0x;
	unsigned char	res105[0xfc];
	unsigned int	div_stat_r0x;
	unsigned char	res106[0x1fc];
	unsigned int	gate_ip_r0x;
	unsigned char	res107[0x1fc];
	unsigned int	clkout_cmu_r0x;
	unsigned int	clkout_cmu_r0x_div_stat;
	unsigned char	res108[0x3af8];
	unsigned int	div_r1x;
	unsigned char	res109[0xfc];
	unsigned int	div_stat_r1x;
	unsigned char	res110[0x1fc];
	unsigned int	gate_ip_r1x;
	unsigned char	res111[0x1fc];
	unsigned int	clkout_cmu_r1x;
	unsigned int	clkout_cmu_r1x_div_stat;
	unsigned char	res112[0x3608];
	unsigned int	bpll_lock;
	unsigned char	res113[0xfc];
	unsigned int	bpll_con0;
	unsigned int	bpll_con1;
	unsigned char	res114[0xe8];
	unsigned int	src_cdrex;
	unsigned char	res115[0x1fc];
	unsigned int	mux_stat_cdrex;
	unsigned char	res116[0xfc];
	unsigned int	div_cdrex;
	unsigned char	res117[0xfc];
	unsigned int	div_stat_cdrex;
	unsigned char	res118[0x2fc];
	unsigned int	gate_ip_cdrex;
	unsigned char	res119[0x10];
	unsigned int	dmc_freq_ctrl;
	unsigned char	res120[0x4];
	unsigned int	drex2_pause;
	unsigned char	res121[0xe0];
	unsigned int	clkout_cmu_cdrex;
	unsigned int	clkout_cmu_cdrex_div_stat;
	unsigned char	res122[0x8];
	unsigned int	lpddr3phy_ctrl;
	unsigned int	lpddr3phy_con0;
	unsigned int	lpddr3phy_con1;
	unsigned int	lpddr3phy_con2;
	unsigned int	lpddr3phy_con3;
	unsigned int	pll_div2_sel;
	unsigned char	res123[0xf5d8];
};

struct exynos5420_clock {
	unsigned int	apll_lock;			/* 0x10010000 */
	unsigned char	res1[0xfc];
	unsigned int	apll_con0;
	unsigned int	apll_con1;
	unsigned char	res2[0xf8];
	unsigned int	src_cpu;
	unsigned char	res3[0x1fc];
	unsigned int	mux_stat_cpu;
	unsigned char	res4[0xfc];
	unsigned int	div_cpu0;		/* 0x10010500 */
	unsigned int	div_cpu1;
	unsigned char	res5[0xf8];
	unsigned int	div_stat_cpu0;
	unsigned int	div_stat_cpu1;
	unsigned char	res6[0xf8];
	unsigned int	gate_bus_cpu;
	unsigned char	res7[0xfc];
	unsigned int	gate_sclk_cpu;
	unsigned char	res8[0x1fc];
	unsigned int	clkout_cmu_cpu;		/* 0x10010a00 */
	unsigned int	clkout_cmu_cpu_div_stat;
	unsigned char	res9[0x5f8];
	unsigned int	armclk_stopctrl;
	unsigned char	res10[0x4];
	unsigned int	arm_ema_ctrl;
	unsigned int	arm_ema_status;
	unsigned char	res11[0x10];
	unsigned int	pwr_ctrl;
	unsigned int	pwr_ctrl2;
	unsigned char	res12[0xd8];
	unsigned int	apll_con0_l8;		/* 0x1001100 */
	unsigned int	apll_con0_l7;
	unsigned int	apll_con0_l6;
	unsigned int	apll_con0_l5;
	unsigned int	apll_con0_l4;
	unsigned int	apll_con0_l3;
	unsigned int	apll_con0_l2;
	unsigned int	apll_con0_l1;
	unsigned int	iem_control;
	unsigned char	res13[0xdc];
	unsigned int	apll_con1_l8;		/* 0x10011200 */
	unsigned int	apll_con1_l7;
	unsigned int	apll_con1_l6;
	unsigned int	apll_con1_l5;
	unsigned int	apll_con1_l4;
	unsigned int	apll_con1_l3;
	unsigned int	apll_con1_l2;
	unsigned int	apll_con1_l1;
	unsigned char	res14[0xe0];
	unsigned int	clkdiv_iem_l8;
	unsigned int	clkdiv_iem_l7;		/* 0x10011304 */
	unsigned int	clkdiv_iem_l6;
	unsigned int	clkdiv_iem_l5;
	unsigned int	clkdiv_iem_l4;
	unsigned int	clkdiv_iem_l3;
	unsigned int	clkdiv_iem_l2;
	unsigned int	clkdiv_iem_l1;
	unsigned char	res15[0xe0];
	unsigned int	l2_status;
	unsigned char	res16[0x0c];
	unsigned int	cpu_status;		/* 0x10011410 */
	unsigned char	res17[0x0c];
	unsigned int	ptm_status;
	unsigned char	res18[0xbdc];
	unsigned int	cmu_cpu_spare0;
	unsigned int	cmu_cpu_spare1;
	unsigned int	cmu_cpu_spare2;
	unsigned int	cmu_cpu_spare3;
	unsigned int	cmu_cpu_spare4;
	unsigned char	res19[0x1fdc];
	unsigned int	cmu_cpu_version;
	unsigned char	res20[0x20c];
	unsigned int	src_cperi0;		/* 0x10014200 */
	unsigned int	src_cperi1;
	unsigned char	res21[0xf8];
	unsigned int	src_mask_cperi;
	unsigned char	res22[0x100];
	unsigned int	mux_stat_cperi1;
	unsigned char	res23[0xfc];
	unsigned int	div_cperi1;
	unsigned char	res24[0xfc];
	unsigned int	div_stat_cperi1;
	unsigned char	res25[0xf8];
	unsigned int	gate_bus_cperi0;	/* 0x10014700 */
	unsigned int	gate_bus_cperi1;
	unsigned char	res26[0xf8];
	unsigned int	gate_sclk_cperi;
	unsigned char	res27[0xfc];
	unsigned int	gate_ip_cperi;
	unsigned char	res28[0xfc];
	unsigned int	clkout_cmu_cperi;
	unsigned int	clkout_cmu_cperi_div_stat;
	unsigned char	res29[0x5f8];
	unsigned int	dcgidx_map0;		/* 0x10015000 */
	unsigned int	dcgidx_map1;
	unsigned int	dcgidx_map2;
	unsigned char	res30[0x14];
	unsigned int	dcgperf_map0;
	unsigned int	dcgperf_map1;
	unsigned char	res31[0x18];
	unsigned int	dvcidx_map;
	unsigned char	res32[0x1c];
	unsigned int	freq_cpu;
	unsigned int	freq_dpm;
	unsigned char	res33[0x18];
	unsigned int	dvsemclk_en;		/* 0x10015080 */
	unsigned int	maxperf;
	unsigned char	res34[0x2e78];
	unsigned int	cmu_cperi_spare0;
	unsigned int	cmu_cperi_spare1;
	unsigned int	cmu_cperi_spare2;
	unsigned int	cmu_cperi_spare3;
	unsigned int	cmu_cperi_spare4;
	unsigned int	cmu_cperi_spare5;
	unsigned int	cmu_cperi_spare6;
	unsigned int	cmu_cperi_spare7;
	unsigned int	cmu_cperi_spare8;
	unsigned char	res35[0xcc];
	unsigned int	cmu_cperi_version;		/* 0x10017ff0 */
	unsigned char	res36[0x50c];
	unsigned int	div_g2d;
	unsigned char	res37[0xfc];
	unsigned int	div_stat_g2d;
	unsigned char	res38[0xfc];
	unsigned int	gate_bus_g2d;
	unsigned char	res39[0xfc];
	unsigned int	gate_ip_g2d;
	unsigned char	res40[0x1fc];
	unsigned int	clkout_cmu_g2d;
	unsigned int	clkout_cmu_g2d_div_stat;	/* 0x10018a04 */
	unsigned char	res41[0xf8];
	unsigned int	cmu_g2d_spare0;
	unsigned int	cmu_g2d_spare1;
	unsigned int	cmu_g2d_spare2;
	unsigned int	cmu_g2d_spare3;
	unsigned int	cmu_g2d_spare4;
	unsigned char	res42[0x34dc];
	unsigned int	cmu_g2d_version;
	unsigned char	res43[0x30c];
	unsigned int	div_cmu_isp0;
	unsigned int	div_cmu_isp1;
	unsigned int	div_isp2;		/* 0x1001c308 */
	unsigned char	res44[0xf4];
	unsigned int	div_stat_cmu_isp0;
	unsigned int	div_stat_cmu_isp1;
	unsigned int	div_stat_isp2;
	unsigned char	res45[0x2f4];
	unsigned int	gate_bus_isp0;
	unsigned int	gate_bus_isp1;
	unsigned int	gate_bus_isp2;
	unsigned int	gate_bus_isp3;
	unsigned char	res46[0xf0];
	unsigned int	gate_ip_isp0;
	unsigned int	gate_ip_isp1;
	unsigned char	res47[0xf8];
	unsigned int	gate_sclk_isp;
	unsigned char	res48[0x0c];
	unsigned int	mcuisp_pwr_ctrl;		/* 0x1001c910 */
	unsigned char	res49[0x0ec];
	unsigned int	clkout_cmu_isp;
	unsigned int	clkout_cmu_isp_div_stat;
	unsigned char	res50[0xf8];
	unsigned int	cmu_isp_spare0;
	unsigned int	cmu_isp_spare1;
	unsigned int	cmu_isp_spare2;
	unsigned int	cmu_isp_spare3;
	unsigned char	res51[0x34e0];
	unsigned int	cmu_isp_version;
	unsigned char	res52[0x2c];
	unsigned int	cpll_lock;			/* 10020020 */
	unsigned char	res53[0xc];
	unsigned int	dpll_lock;
	unsigned char	res54[0xc];
	unsigned int	epll_lock;
	unsigned char	res55[0xc];
	unsigned int	rpll_lock;
	unsigned char	res56[0xc];
	unsigned int	ipll_lock;
	unsigned char	res57[0xc];
	unsigned int	spll_lock;
	unsigned char	res58[0xc];
	unsigned int	vpll_lock;
	unsigned char	res59[0xc];
	unsigned int	mpll_lock;
	unsigned char	res60[0x8c];
	unsigned int	cpll_con0;			/* 10020120 */
	unsigned int	cpll_con1;
	unsigned int	dpll_con0;
	unsigned int	dpll_con1;
	unsigned int	epll_con0;
	unsigned int	epll_con1;
	unsigned int	epll_con2;
	unsigned char	res601[0x4];
	unsigned int	rpll_con0;
	unsigned int	rpll_con1;
	unsigned int	rpll_con2;
	unsigned char	res602[0x4];
	unsigned int	ipll_con0;
	unsigned int	ipll_con1;
	unsigned char	res61[0x8];
	unsigned int	spll_con0;
	unsigned int	spll_con1;
	unsigned char	res62[0x8];
	unsigned int	vpll_con0;
	unsigned int	vpll_con1;
	unsigned char	res63[0x8];
	unsigned int	mpll_con0;
	unsigned int	mpll_con1;
	unsigned char	res64[0x78];
	unsigned int	src_top0;		/* 0x10020200 */
	unsigned int	src_top1;
	unsigned int	src_top2;
	unsigned int	src_top3;
	unsigned int	src_top4;
	unsigned int	src_top5;
	unsigned int	src_top6;
	unsigned int	src_top7;
	unsigned char	res65[0xc];
	unsigned int	src_disp10;		/* 0x1002022c */
	unsigned char	res66[0x10];
	unsigned int	src_mau;
	unsigned int	src_fsys;
	unsigned char	res67[0x8];
	unsigned int	src_peric0;
	unsigned int	src_peric1;
	unsigned char	res68[0x18];
	unsigned int	src_isp;
	unsigned char	res69[0x0c];
	unsigned int	src_top10;
	unsigned int	src_top11;
	unsigned int	src_top12;
	unsigned char	res70[0x74];
	unsigned int	src_mask_top0;
	unsigned int	src_mask_top1;
	unsigned int	src_mask_top2;
	unsigned char	res71[0x10];
	unsigned int	src_mask_top7;
	unsigned char	res72[0xc];
	unsigned int	src_mask_disp10;	/* 0x1002032c */
	unsigned char	res73[0x4];
	unsigned int	src_mask_mau;
	unsigned char	res74[0x8];
	unsigned int	src_mask_fsys;
	unsigned char	res75[0xc];
	unsigned int	src_mask_peric0;
	unsigned int	src_mask_peric1;
	unsigned char	res76[0x18];
	unsigned int	src_mask_isp;
	unsigned char	res77[0x8c];
	unsigned int	mux_stat_top0;		/* 0x10020400 */
	unsigned int	mux_stat_top1;
	unsigned int	mux_stat_top2;
	unsigned int	mux_stat_top3;
	unsigned int	mux_stat_top4;
	unsigned int	mux_stat_top5;
	unsigned int	mux_stat_top6;
	unsigned int	mux_stat_top7;
	unsigned char	res78[0x60];
	unsigned int	mux_stat_top10;
	unsigned int	mux_stat_top11;
	unsigned int	mux_stat_top12;
	unsigned char	res79[0x74];
	unsigned int	div_top0;		/* 0x10020500 */
	unsigned int	div_top1;
	unsigned int	div_top2;
	unsigned char	res80[0x20];
	unsigned int	div_disp10;
	unsigned char	res81[0x14];
	unsigned int	div_mau;
	unsigned int	div_fsys0;
	unsigned int	div_fsys1;
	unsigned int	div_fsys2;
	unsigned char	res82[0x4];
	unsigned int	div_peric0;
	unsigned int	div_peric1;
	unsigned int	div_peric2;
	unsigned int	div_peric3;
	unsigned int	div_peric4;		/* 0x10020568 */
	unsigned char	res83[0x14];
	unsigned int	div_isp0;
	unsigned int	div_isp1;
	unsigned char	res84[0x8];
	unsigned int	clkdiv2_ratio;
	unsigned char	res850[0xc];
	unsigned int	clkdiv4_ratio;
	unsigned char	res85[0x5c];
	unsigned int	div_stat_top0;
	unsigned int	div_stat_top1;
	unsigned int	div_stat_top2;
	unsigned char	res86[0x20];
	unsigned int	div_stat_disp10;
	unsigned char	res87[0x14];
	unsigned int	div_stat_mau;		/* 0x10020644 */
	unsigned int	div_stat_fsys0;
	unsigned int	div_stat_fsys1;
	unsigned int	div_stat_fsys2;
	unsigned char	res88[0x4];
	unsigned int	div_stat_peric0;
	unsigned int	div_stat_peric1;
	unsigned int	div_stat_peric2;
	unsigned int	div_stat_peric3;
	unsigned int	div_stat_peric4;
	unsigned char	res89[0x14];
	unsigned int	div_stat_isp0;
	unsigned int	div_stat_isp1;
	unsigned char	res90[0x8];
	unsigned int	clkdiv2_stat0;
	unsigned char	res91[0xc];
	unsigned int	clkdiv4_stat;
	unsigned char	res92[0x5c];
	unsigned int	gate_bus_top;		/* 0x10020700 */
	unsigned char	res93[0xc];
	unsigned int	gate_bus_gscl0;
	unsigned char	res94[0xc];
	unsigned int	gate_bus_gscl1;
	unsigned char	res95[0x4];
	unsigned int	gate_bus_disp1;
	unsigned char	res96[0x4];
	unsigned int	gate_bus_wcore;
	unsigned int	gate_bus_mfc;
	unsigned int	gate_bus_g3d;
	unsigned int	gate_bus_gen;
	unsigned int	gate_bus_fsys0;
	unsigned int	gate_bus_fsys1;
	unsigned int	gate_bus_fsys2;
	unsigned int	gate_bus_mscl;
	unsigned int	gate_bus_peric;
	unsigned int	gate_bus_peric1;
	unsigned char	res97[0x8];
	unsigned int	gate_bus_peris0;
	unsigned int	gate_bus_peris1;	/* 0x10020764 */
	unsigned char	res98[0x8];
	unsigned int	gate_bus_noc;
	unsigned char	res99[0xac];
	unsigned int	gate_top_sclk_gscl;
	unsigned char	res1000[0x4];
	unsigned int	gate_top_sclk_disp1;
	unsigned char	res100[0x10];
	unsigned int	gate_top_sclk_mau;
	unsigned int	gate_top_sclk_fsys;
	unsigned char	res101[0xc];
	unsigned int	gate_top_sclk_peric;
	unsigned char	res102[0xc];
	unsigned int	gate_top_sclk_cperi;
	unsigned char	res103[0xc];
	unsigned int	gate_top_sclk_isp;
	unsigned char	res104[0x9c];
	unsigned int	gate_ip_gscl0;
	unsigned char	res105[0xc];
	unsigned int	gate_ip_gscl1;
	unsigned char	res106[0x4];
	unsigned int	gate_ip_disp1;
	unsigned int	gate_ip_mfc;
	unsigned int	gate_ip_g3d;
	unsigned int	gate_ip_gen;		/* 0x10020934 */
	unsigned char	res107[0xc];
	unsigned int	gate_ip_fsys;
	unsigned char	res108[0x8];
	unsigned int	gate_ip_peric;
	unsigned char	res109[0xc];
	unsigned int	gate_ip_peris;
	unsigned char	res110[0xc];
	unsigned int	gate_ip_mscl;
	unsigned char	res111[0xc];
	unsigned int	gate_ip_block;
	unsigned char	res112[0xc];
	unsigned int	bypass;
	unsigned char	res113[0x6c];
	unsigned int	clkout_cmu_top;
	unsigned int	clkout_cmu_top_div_stat;
	unsigned char	res114[0xf8];
	unsigned int	clkout_top_spare0;
	unsigned int	clkout_top_spare1;
	unsigned int	clkout_top_spare2;
	unsigned int	clkout_top_spare3;
	unsigned char	res115[0x34e0];
	unsigned int	clkout_top_version;
	unsigned char	res116[0xc01c];
	unsigned int	bpll_lock;			/* 0x10030010 */
	unsigned char	res117[0xfc];
	unsigned int	bpll_con0;
	unsigned int	bpll_con1;
	unsigned char	res118[0xe8];
	unsigned int	src_cdrex;
	unsigned char	res119[0x1fc];
	unsigned int	mux_stat_cdrex;
	unsigned char	res120[0xfc];
	unsigned int	div_cdrex0;
	unsigned int	div_cdrex1;
	unsigned char	res121[0xf8];
	unsigned int	div_stat_cdrex;
	unsigned char	res1211[0xfc];
	unsigned int	gate_bus_cdrex;
	unsigned int	gate_bus_cdrex1;
	unsigned char	res122[0x1f8];
	unsigned int	gate_ip_cdrex;
	unsigned char	res123[0x10];
	unsigned int	dmc_freq_ctrl;		/* 0x10030914 */
	unsigned char	res124[0x4];
	unsigned int	pause;
	unsigned int	ddrphy_lock_ctrl;
	unsigned char	res125[0xdc];
	unsigned int	clkout_cmu_cdrex;
	unsigned int	clkout_cmu_cdrex_div_stat;
	unsigned char	res126[0x8];
	unsigned int	lpddr3phy_ctrl;
	unsigned int	lpddr3phy_con0;
	unsigned int	lpddr3phy_con1;
	unsigned int	lpddr3phy_con2;
	unsigned int	lpddr3phy_con3;
	unsigned int	lpddr3phy_con4;
	unsigned int	lpddr3phy_con5;		/* 0x10030a28 */
	unsigned int	pll_div2_sel;
	unsigned char	res127[0xd0];
	unsigned int	cmu_cdrex_spare0;
	unsigned int	cmu_cdrex_spare1;
	unsigned int	cmu_cdrex_spare2;
	unsigned int	cmu_cdrex_spare3;
	unsigned int	cmu_cdrex_spare4;
	unsigned char	res128[0x34dc];
	unsigned int	cmu_cdrex_version;		/* 0x10033ff0 */
	unsigned char	res129[0x400c];
	unsigned int	kpll_lock;
	unsigned char	res130[0xfc];
	unsigned int	kpll_con0;
	unsigned int	kpll_con1;
	unsigned char	res131[0xf8];
	unsigned int	src_kfc;
	unsigned char	res132[0x1fc];
	unsigned int	mux_stat_kfc;		/* 0x10038400 */
	unsigned char	res133[0xfc];
	unsigned int	div_kfc0;
	unsigned char	res134[0xfc];
	unsigned int	div_stat_kfc0;
	unsigned char	res135[0xfc];
	unsigned int	gate_bus_cpu_kfc;
	unsigned char	res136[0xfc];
	unsigned int	gate_sclk_cpu_kfc;
	unsigned char	res137[0x1fc];
	unsigned int	clkout_cmu_kfc;
	unsigned int	clkout_cmu_kfc_div_stat;	/* 0x10038a04 */
	unsigned char	res138[0x5f8];
	unsigned int	armclk_stopctrl_kfc;
	unsigned char	res139[0x4];
	unsigned int	armclk_ema_ctrl_kfc;
	unsigned int	armclk_ema_status_kfc;
	unsigned char	res140[0x10];
	unsigned int	pwr_ctrl_kfc;
	unsigned int	pwr_ctrl2_kfc;
	unsigned char	res141[0xd8];
	unsigned int	kpll_con0_l8;
	unsigned int	kpll_con0_l7;
	unsigned int	kpll_con0_l6;
	unsigned int	kpll_con0_l5;
	unsigned int	kpll_con0_l4;
	unsigned int	kpll_con0_l3;
	unsigned int	kpll_con0_l2;
	unsigned int	kpll_con0_l1;
	unsigned int	iem_control_kfc;		/* 0x10039120 */
	unsigned char	res142[0xdc];
	unsigned int	kpll_con1_l8;
	unsigned int	kpll_con1_l7;
	unsigned int	kpll_con1_l6;
	unsigned int	kpll_con1_l5;
	unsigned int	kpll_con1_l4;
	unsigned int	kpll_con1_l3;
	unsigned int	kpll_con1_l2;
	unsigned int	kpll_con1_l1;
	unsigned char	res143[0xe0];
	unsigned int	clkdiv_iem_l8_kfc;		/* 0x10039300 */
	unsigned int	clkdiv_iem_l7_kfc;
	unsigned int	clkdiv_iem_l6_kfc;
	unsigned int	clkdiv_iem_l5_kfc;
	unsigned int	clkdiv_iem_l4_kfc;
	unsigned int	clkdiv_iem_l3_kfc;
	unsigned int	clkdiv_iem_l2_kfc;
	unsigned int	clkdiv_iem_l1_kfc;
	unsigned char	res144[0xe0];
	unsigned int	l2_status_kfc;
	unsigned char	res145[0xc];
	unsigned int	cpu_status_kfc;		/* 0x10039410 */
	unsigned char	res146[0xc];
	unsigned int	ptm_status_kfc;
	unsigned char	res147[0xbdc];
	unsigned int	cmu_kfc_spare0;
	unsigned int	cmu_kfc_spare1;
	unsigned int	cmu_kfc_spare2;
	unsigned int	cmu_kfc_spare3;
	unsigned int	cmu_kfc_spare4;
	unsigned char	res148[0x1fdc];
	unsigned int	cmu_kfc_version;		/* 0x1003bff0 */
};

/* structure for epll configuration used in audio clock configuration */
struct set_epll_con_val {
	unsigned int freq_out;		/* frequency out */
	unsigned int en_lock_det;	/* enable lock detect */
	unsigned int m_div;		/* m divider value */
	unsigned int p_div;		/* p divider value */
	unsigned int s_div;		/* s divider value */
	unsigned int k_dsm;		/* k value of delta signal modulator */
};
#endif

#define MPLL_FOUT_SEL_SHIFT	4
#define EXYNOS5_EPLLCON0_LOCKED_SHIFT	29  /* EPLL Locked bit position*/
#define TIMEOUT_EPLL_LOCK		1000

#define AUDIO_0_RATIO_MASK		0x0f
#define AUDIO_1_RATIO_MASK		0x0f

#define AUDIO0_SEL_MASK			0xf
#define AUDIO1_SEL_MASK			0xf

#define CLK_SRC_SCLK_EPLL		0x7
#define CLK_SRC_MOUT_EPLL		(1<<12)
#define AUDIO_CLKMUX_ASS		(1<<0)

/* CON0 bit-fields */
#define EPLL_CON0_MDIV_MASK		0x1ff
#define EPLL_CON0_PDIV_MASK		0x3f
#define EPLL_CON0_SDIV_MASK		0x7
#define EPLL_CON0_MDIV_SHIFT		16
#define EPLL_CON0_PDIV_SHIFT		8
#define EPLL_CON0_SDIV_SHIFT		0
#define EPLL_CON0_LOCK_DET_EN_SHIFT	28
#define EPLL_CON0_LOCK_DET_EN_MASK	1

#define MPLL_FOUT_SEL_MASK	0x1
#define BPLL_FOUT_SEL_SHIFT	0
#define BPLL_FOUT_SEL_MASK	0x1
#endif
