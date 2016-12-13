#ifndef __DMC_H__
#define __DMC_H__

#ifndef __ASSEMBLY__
struct exynos4_dmc {
	unsigned int concontrol;	// 0x0000
	unsigned int memcontrol;	// 0x0004
	unsigned int memconfig0;	// 0x0008
	unsigned int memconfig1;	// 0x000c
	unsigned int directcmd;		// 0x0010
	unsigned int prechconfig;	// 0x0014
	unsigned int phycontrol0;	// 0x0018
	unsigned int phycontrol1;	// 0x001c
	unsigned int phycontrol2;	// 0x0020
	unsigned int phycontrol3;	// 0x0024
	unsigned int pwrdnconfig;	// 0x0028
	unsigned char res1[0x4];	// 0x002c
	unsigned int timingref;		// 0x0030
	unsigned int timingrow;		// 0x0034
	unsigned int timingdata;	// 0x0038
	unsigned int timingpower;	// 0x003c
	unsigned int phystatus;		// 0x0040
	unsigned int phyzqcontrol;	// 0x0044
	unsigned int chip0status;	// 0x0048
	unsigned int chip1status;	// 0x004c
	unsigned int arefstatus;	// 0x0050
	unsigned int mrstatus;		// 0x0054
	unsigned int phytest0;		// 0x0058
	unsigned int phytest1;		// 0x005c
	unsigned int qoscontrol0;	// 0x0060
	unsigned int qosconfig0;	// 0x0064
	unsigned int qoscontrol1;	// 0x0068
	unsigned int qosconfig1;	// 0x006c
	unsigned int qoscontrol2;	// 0x0070
	unsigned int qosconfig2;	// 0x0074
	unsigned int qoscontrol3;	// 0x0078
	unsigned int qosconfig3;	// 0x007c
	unsigned int qoscontrol4;	// 0x0080
	unsigned int qosconfig4;	// 0x0084
	unsigned int qoscontrol5;	// 0x0088
	unsigned int qosconfig5;	// 0x008c
	unsigned int qoscontrol6;	// 0x0090
	unsigned int qosconfig6;	// 0x0094
	unsigned int qoscontrol7;	// 0x0098
	unsigned int qosconfig7;	// 0x009c
	unsigned int qoscontrol8;	// 0x00a0
	unsigned int qosconfig8;	// 0x00a4
	unsigned int qoscontrol9;	// 0x00a8
	unsigned int qosconfig9;	// 0x00ac
	unsigned int qoscontrol10;	// 0x00b0
	unsigned int qosconfig10;	// 0x00b4
	unsigned int qoscontrol11;	// 0x00b8
	unsigned int qosconfig11;	// 0x00bc
	unsigned int qoscontrol12;	// 0x00c0
	unsigned int qosconfig12;	// 0x00c4
	unsigned int qoscontrol13;	// 0x00c8
	unsigned int qosconfig13;	// 0x00cc
	unsigned int qoscontrol14;	// 0x00d0
	unsigned int qosconfig14;	// 0x00d4
	unsigned int qoscontrol15;	// 0x00d8
	unsigned int qosconfig15;	// 0x00dc
	unsigned int qostimeout0;	// 0x00e0
	unsigned int qostimeout1;	// 0x00e4
	unsigned char res2[0x8];	// 0x00e8
	unsigned int ivcontrol;		// 0x00f0
	unsigned char res3[0x8];	// 0x00f4
	unsigned int perevconfig;	// 0x00fc
	unsigned char res4[0xDF00];	// 0x0100
	unsigned int pmnc_ppc_a;	// 0xe000
	unsigned char res5[0xC];	// 0xe004
	unsigned int cntens_ppc_a;	// 0xe010
	unsigned char res6[0xC];	// 0xe014
	unsigned int cntenc_ppc_a;	// 0xe020
	unsigned char res7[0xC];	// 0xe024
	unsigned int intens_ppc_a;	// 0xe030
	unsigned char res8[0xC];	// 0xe034
	unsigned int intenc_ppc_a;	// 0xe040
	unsigned char res9[0xC];	// 0xe044
	unsigned int flag_ppc_a;	// 0xe050
	unsigned char res10[0xAC];	// 0xe054
	unsigned int ccnt_ppc_a;	// 0xe100
	unsigned char res11[0xC];	// 0xe104
	unsigned int pmcnt0_ppc_a;	// 0xe110
	unsigned char res12[0xC];	// 0xe114
	unsigned int pmcnt1_ppc_a;	// 0xe120
	unsigned char res13[0xC];	// 0xe124
	unsigned int pmcnt2_ppc_a;	// 0xe130
	unsigned char res14[0xC];	// 0xe134
	unsigned int pmcnt3_ppc_a;	// 0xe140
	unsigned char res15[0xEBC];	// 0xe144
	unsigned int pmnc_ppc_m;	// 0xf000
	unsigned char res16[0xC];	// 0xf004
	unsigned int cntens_ppc_m;	// 0xf010
	unsigned char res17[0xC];	// 0xf014
	unsigned int cntenc_ppc_m;	// 0xf020
	unsigned char res18[0xC];	// 0xf024
	unsigned int intens_ppc_m;	// 0xf030
	unsigned char res19[0xC];	// 0xf034
	unsigned int intenc_ppc_m;	// 0xf040
	unsigned char res20[0xC];	// 0xf044
	unsigned int flag_ppc_m;	// 0xf050
	unsigned char res21[0xAC];	// 0xf054
	unsigned int ccnt_ppc_m;	// 0xf100
	unsigned char res22[0xC];	// 0xf104
	unsigned int pmcnt0_ppc_m;	// 0xf110
	unsigned char res23[0xC];	// 0xf114
	unsigned int pmcnt1_ppc_m;	// 0xf120
	unsigned char res24[0xC];	// 0xf124
	unsigned int pmcnt2_ppc_m;	// 0xf130
	unsigned char res25[0xC];	// 0xf134
	unsigned int pmcnt3_ppc_m;	// 0xf140
};

struct exynos5_dmc {
	unsigned int concontrol;
	unsigned int memcontrol;
	unsigned int memconfig0;
	unsigned int memconfig1;
	unsigned int directcmd;
	unsigned int prechconfig;
	unsigned int phycontrol0;
	unsigned char res1[0xc];
	unsigned int pwrdnconfig;
	unsigned int timingpzq;
	unsigned int timingref;
	unsigned int timingrow;
	unsigned int timingdata;
	unsigned int timingpower;
	unsigned int phystatus;
	unsigned char res2[0x4];
	unsigned int chipstatus_ch0;
	unsigned int chipstatus_ch1;
	unsigned char res3[0x4];
	unsigned int mrstatus;
	unsigned char res4[0x8];
	unsigned int qoscontrol0;
	unsigned char resr5[0x4];
	unsigned int qoscontrol1;
	unsigned char res6[0x4];
	unsigned int qoscontrol2;
	unsigned char res7[0x4];
	unsigned int qoscontrol3;
	unsigned char res8[0x4];
	unsigned int qoscontrol4;
	unsigned char res9[0x4];
	unsigned int qoscontrol5;
	unsigned char res10[0x4];
	unsigned int qoscontrol6;
	unsigned char res11[0x4];
	unsigned int qoscontrol7;
	unsigned char res12[0x4];
	unsigned int qoscontrol8;
	unsigned char res13[0x4];
	unsigned int qoscontrol9;
	unsigned char res14[0x4];
	unsigned int qoscontrol10;
	unsigned char res15[0x4];
	unsigned int qoscontrol11;
	unsigned char res16[0x4];
	unsigned int qoscontrol12;
	unsigned char res17[0x4];
	unsigned int qoscontrol13;
	unsigned char res18[0x4];
	unsigned int qoscontrol14;
	unsigned char res19[0x4];
	unsigned int qoscontrol15;
	unsigned char res20[0x14];
	unsigned int ivcontrol;
	unsigned int wrtra_config;
	unsigned int rdlvl_config;
	unsigned char res21[0x8];
	unsigned int brbrsvconfig;
	unsigned int brbqosconfig;
	unsigned int membaseconfig0;
	unsigned int membaseconfig1;
	unsigned char res22[0xc];
	unsigned int wrlvl_config;
	unsigned char res23[0xc];
	unsigned int perevcontrol;
	unsigned int perev0config;
	unsigned int perev1config;
	unsigned int perev2config;
	unsigned int perev3config;
	unsigned char res24[0xdebc];
	unsigned int pmnc_ppc_a;
	unsigned char res25[0xc];
	unsigned int cntens_ppc_a;
	unsigned char res26[0xc];
	unsigned int cntenc_ppc_a;
	unsigned char res27[0xc];
	unsigned int intens_ppc_a;
	unsigned char res28[0xc];
	unsigned int intenc_ppc_a;
	unsigned char res29[0xc];
	unsigned int flag_ppc_a;
	unsigned char res30[0xac];
	unsigned int ccnt_ppc_a;
	unsigned char res31[0xc];
	unsigned int pmcnt0_ppc_a;
	unsigned char res32[0xc];
	unsigned int pmcnt1_ppc_a;
	unsigned char res33[0xc];
	unsigned int pmcnt2_ppc_a;
	unsigned char res34[0xc];
	unsigned int pmcnt3_ppc_a;
};

struct exynos5420_dmc {
	unsigned int concontrol;
	unsigned int memcontrol;
	unsigned int cgcontrol;
	unsigned char res500[0x4];
	unsigned int directcmd;
	unsigned int prechconfig0;
	unsigned int phycontrol0;
	unsigned int prechconfig1;
	unsigned char res1[0x8];
	unsigned int pwrdnconfig;
	unsigned int timingpzq;
	unsigned int timingref;
	unsigned int timingrow0;
	unsigned int timingdata0;
	unsigned int timingpower0;
	unsigned int phystatus;
	unsigned int etctiming;
	unsigned int chipstatus;
	unsigned char res3[0x8];
	unsigned int mrstatus;
	unsigned char res4[0x8];
	unsigned int qoscontrol0;
	unsigned char resr5[0x4];
	unsigned int qoscontrol1;
	unsigned char res6[0x4];
	unsigned int qoscontrol2;
	unsigned char res7[0x4];
	unsigned int qoscontrol3;
	unsigned char res8[0x4];
	unsigned int qoscontrol4;
	unsigned char res9[0x4];
	unsigned int qoscontrol5;
	unsigned char res10[0x4];
	unsigned int qoscontrol6;
	unsigned char res11[0x4];
	unsigned int qoscontrol7;
	unsigned char res12[0x4];
	unsigned int qoscontrol8;
	unsigned char res13[0x4];
	unsigned int qoscontrol9;
	unsigned char res14[0x4];
	unsigned int qoscontrol10;
	unsigned char res15[0x4];
	unsigned int qoscontrol11;
	unsigned char res16[0x4];
	unsigned int qoscontrol12;
	unsigned char res17[0x4];
	unsigned int qoscontrol13;
	unsigned char res18[0x4];
	unsigned int qoscontrol14;
	unsigned char res19[0x4];
	unsigned int qoscontrol15;
	unsigned char res20[0x4];
	unsigned int timing_set_sw;
	unsigned int timingrow1;
	unsigned int timingdata1;
	unsigned int timingpower1;
	unsigned char res300[0x4];
	unsigned int wrtra_config;
	unsigned int rdlvl_config;
	unsigned char res21[0x4];
	unsigned int brbrsvcontrol;
	unsigned int brbrsvconfig;
	unsigned int brbqosconfig;
	unsigned char res301[0x14];
	unsigned int wrlvl_config0;
	unsigned int wrlvl_config1;
	unsigned int wrlvl_status;
	unsigned char res23[0x4];
	unsigned int ppcclockon;
	unsigned int perevconfig0;
	unsigned int perevconfig1;
	unsigned int perevconfig2;
	unsigned int perevconfig3;
	unsigned char res24[0xc];
	unsigned int control_io_rdata;
	unsigned char res240[0xc];
	unsigned int cacal_config0;
	unsigned int cacal_config1;
	unsigned int cacal_status;
	unsigned char res302[0xa4];
	unsigned int bp_control0;
	unsigned int bp_config0_r;
	unsigned int bp_config0_w;
	unsigned char res303[0x4];
	unsigned int bp_control1;
	unsigned int bp_config1_r;
	unsigned int bp_config1_w;
	unsigned char res304[0x4];
	unsigned int bp_control2;
	unsigned int bp_config2_r;
	unsigned int bp_config2_w;
	unsigned char res305[0x4];
	unsigned int bp_control3;
	unsigned int bp_config3_r;
	unsigned int bp_config3_w;
	unsigned char res306[0xddb4];
	unsigned int pmnc_ppc;
	unsigned char res25[0xc];
	unsigned int cntens_ppc;
	unsigned char res26[0xc];
	unsigned int cntenc_ppc;
	unsigned char res27[0xc];
	unsigned int intens_ppc;
	unsigned char res28[0xc];
	unsigned int intenc_ppc;
	unsigned char res29[0xc];
	unsigned int flag_ppc;
	unsigned char res30[0xac];
	unsigned int ccnt_ppc;
	unsigned char res31[0xc];
	unsigned int pmcnt0_ppc;
	unsigned char res32[0xc];
	unsigned int pmcnt1_ppc;
	unsigned char res33[0xc];
	unsigned int pmcnt2_ppc;
	unsigned char res34[0xc];
	unsigned int pmcnt3_ppc;
};

struct exynos5_phy_control {
	unsigned int phy_con0;
	unsigned int phy_con1;
	unsigned int phy_con2;
	unsigned int phy_con3;
	unsigned int phy_con4;
	unsigned char res1[4];
	unsigned int phy_con6;
	unsigned char res2[4];
	unsigned int phy_con8;
	unsigned int phy_con9;
	unsigned int phy_con10;
	unsigned char res3[4];
	unsigned int phy_con12;
	unsigned int phy_con13;
	unsigned int phy_con14;
	unsigned int phy_con15;
	unsigned int phy_con16;
	unsigned char res4[4];
	unsigned int phy_con17;
	unsigned int phy_con18;
	unsigned int phy_con19;
	unsigned int phy_con20;
	unsigned int phy_con21;
	unsigned int phy_con22;
	unsigned int phy_con23;
	unsigned int phy_con24;
	unsigned int phy_con25;
	unsigned int phy_con26;
	unsigned int phy_con27;
	unsigned int phy_con28;
	unsigned int phy_con29;
	unsigned int phy_con30;
	unsigned int phy_con31;
	unsigned int phy_con32;
	unsigned int phy_con33;
	unsigned int phy_con34;
	unsigned int phy_con35;
	unsigned int phy_con36;
	unsigned int phy_con37;
	unsigned int phy_con38;
	unsigned int phy_con39;
	unsigned int phy_con40;
	unsigned int phy_con41;
	unsigned int phy_con42;
};

struct exynos5420_phy_control {
	unsigned int phy_con0;
	unsigned int phy_con1;
	unsigned int phy_con2;
	unsigned int phy_con3;
	unsigned int phy_con4;
	unsigned int phy_con5;
	unsigned int phy_con6;
	unsigned char res2[0x4];
	unsigned int phy_con8;
	unsigned char res5[0x4];
	unsigned int phy_con10;
	unsigned int phy_con11;
	unsigned int phy_con12;
	unsigned int phy_con13;
	unsigned int phy_con14;
	unsigned int phy_con15;
	unsigned int phy_con16;
	unsigned char res4[0x4];
	unsigned int phy_con17;
	unsigned int phy_con18;
	unsigned int phy_con19;
	unsigned int phy_con20;
	unsigned int phy_con21;
	unsigned int phy_con22;
	unsigned int phy_con23;
	unsigned int phy_con24;
	unsigned int phy_con25;
	unsigned int phy_con26;
	unsigned int phy_con27;
	unsigned int phy_con28;
	unsigned int phy_con29;
	unsigned int phy_con30;
	unsigned int phy_con31;
	unsigned int phy_con32;
	unsigned int phy_con33;
	unsigned int phy_con34;
	unsigned char res6[0x8];
	unsigned int phy_con37;
	unsigned char res7[0x4];
	unsigned int phy_con39;
	unsigned int phy_con40;
	unsigned int phy_con41;
	unsigned int phy_con42;
};

struct exynos5420_tzasc {
	unsigned char res1[0xf00];
	unsigned int membaseconfig0;
	unsigned int membaseconfig1;
	unsigned char res2[0x8];
	unsigned int memconfig0;
	unsigned int memconfig1;
};

enum ddr_mode {
	DDR_MODE_DDR2,
	DDR_MODE_DDR3,
	DDR_MODE_LPDDR2,
	DDR_MODE_LPDDR3,

	DDR_MODE_COUNT,
};

enum mem_manuf {
	MEM_MANUF_AUTODETECT,
	MEM_MANUF_ELPIDA,
	MEM_MANUF_SAMSUNG,

	MEM_MANUF_COUNT,
};

/* CONCONTROL register fields */
#define CONCONTROL_DFI_INIT_START_SHIFT	28
#define CONCONTROL_RD_FETCH_SHIFT	12
#define CONCONTROL_RD_FETCH_MASK	(0x7 << CONCONTROL_RD_FETCH_SHIFT)
#define CONCONTROL_AREF_EN_SHIFT	5
#define CONCONTROL_UPDATE_MODE		(1 << 3)

/* PRECHCONFIG register field */
#define PRECHCONFIG_TP_CNT_SHIFT	24

/* PWRDNCONFIG register field */
#define PWRDNCONFIG_DPWRDN_CYC_SHIFT	0
#define PWRDNCONFIG_DSREF_CYC_SHIFT	16

/* PHY_CON0 register fields */
#define PHY_CON0_T_WRRDCMD_SHIFT	17
#define PHY_CON0_T_WRRDCMD_MASK		(0x7 << PHY_CON0_T_WRRDCMD_SHIFT)
#define PHY_CON0_CTRL_DDR_MODE_SHIFT	11
#define PHY_CON0_CTRL_DDR_MODE_MASK	0x3

/* PHY_CON1 register fields */
#define PHY_CON1_RDLVL_RDDATA_ADJ_SHIFT	0

/* PHY_CON4 rgister fields */
#define PHY_CON10_CTRL_OFFSETR3		(1 << 24)

/* PHY_CON12 register fields */
#define PHY_CON12_CTRL_START_POINT_SHIFT	24
#define PHY_CON12_CTRL_INC_SHIFT	16
#define PHY_CON12_CTRL_FORCE_SHIFT	8
#define PHY_CON12_CTRL_START_SHIFT	6
#define PHY_CON12_CTRL_START_MASK	(1 << PHY_CON12_CTRL_START_SHIFT)
#define PHY_CON12_CTRL_DLL_ON_SHIFT	5
#define PHY_CON12_CTRL_DLL_ON_MASK	(1 << PHY_CON12_CTRL_DLL_ON_SHIFT)
#define PHY_CON12_CTRL_REF_SHIFT	1

/* PHY_CON16 register fields */
#define PHY_CON16_ZQ_MODE_DDS_SHIFT	24
#define PHY_CON16_ZQ_MODE_DDS_MASK	(0x7 << PHY_CON16_ZQ_MODE_DDS_SHIFT)

#define PHY_CON16_ZQ_MODE_TERM_SHIFT 21
#define PHY_CON16_ZQ_MODE_TERM_MASK	(0x7 << PHY_CON16_ZQ_MODE_TERM_SHIFT)

#define PHY_CON16_ZQ_MODE_NOTERM_MASK	(1 << 19)

/* PHY_CON42 register fields */
#define PHY_CON42_CTRL_BSTLEN_SHIFT	8
#define PHY_CON42_CTRL_BSTLEN_MASK	(0xff << PHY_CON42_CTRL_BSTLEN_SHIFT)

#define PHY_CON42_CTRL_RDLAT_SHIFT	0
#define PHY_CON42_CTRL_RDLAT_MASK	(0x1f << PHY_CON42_CTRL_RDLAT_SHIFT)

#endif
#endif
