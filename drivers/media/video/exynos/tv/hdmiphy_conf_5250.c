/*
 * Samsung HDMI Physical interface driver
 *
 * Copyright (C) 2010-2011 Samsung Electronics Co.Ltd
 * Author: Jiun Yu <jiun.yu@samsung.com>
 *
 * This program is free software; you can redistribute  it and/or modify it
 * under  the terms of  the GNU General  Public License as published by the
 * Free Software Foundation;  either version 2 of the  License, or (at your
 * option) any later version.
 */

#include "hdmi.h"

static const u8 hdmiphy_conf27[32] = {
	0x01, 0x51, 0x2d, 0x75, 0x40, 0x01, 0x00, 0x08,
	0x82, 0xa0, 0x0e, 0xd9, 0x45, 0xa0, 0xac, 0x80,
	0x08, 0x80, 0x11, 0x04, 0x02, 0x22, 0x44, 0x86,
	0x54, 0xe3, 0x24, 0x00, 0x00, 0x00, 0x01, 0x00,
};

static const u8 hdmiphy_conf27_027[32] = {
	0x01, 0xd1, 0x2d, 0x72, 0x40, 0x64, 0x12, 0x08,
	0x43, 0xa0, 0x0e, 0xd9, 0x45, 0xa0, 0xac, 0x80,
	0x08, 0x80, 0x11, 0x04, 0x02, 0x22, 0x44, 0x86,
	0x54, 0xe3, 0x24, 0x00, 0x00, 0x00, 0x01, 0x00,
};

static const u8 hdmiphy_conf74_175[32] = {
	0x01, 0xd1, 0x1f, 0x10, 0x40, 0x5b, 0xef, 0x08,
	0x81, 0xa0, 0xb9, 0xd8, 0x45, 0xa0, 0xac, 0x80,
	0x5a, 0x80, 0x11, 0x04, 0x02, 0x22, 0x44, 0x86,
	0x54, 0xa6, 0x24, 0x01, 0x00, 0x00, 0x01, 0x00,
};

static const u8 hdmiphy_conf74_25[32] = {
	0x01, 0xd1, 0x1f, 0x10, 0x40, 0x40, 0xf8, 0x08,
	0x81, 0xa0, 0xba, 0xd8, 0x45, 0xa0, 0xac, 0x80,
	0x3c, 0x80, 0x11, 0x04, 0x02, 0x22, 0x44, 0x86,
	0x54, 0xa5, 0x24, 0x01, 0x00, 0x00, 0x01, 0x00,
};

static const u8 hdmiphy_conf148_352[32] = {
	0x01, 0xd2, 0x3e, 0x00, 0x40, 0x5b, 0xef, 0x08,
	0x81, 0xa0, 0xb9, 0xd8, 0x45, 0xa0, 0xac, 0x80,
	0x3c, 0x80, 0x11, 0x04, 0x02, 0x22, 0x44, 0x86,
	0x54, 0x4b, 0x25, 0x03, 0x00, 0x00, 0x01, 0x00,
};

static const u8 hdmiphy_conf148_5[32] = {
	0x01, 0xd1, 0x1f, 0x00, 0x40, 0x40, 0xf8, 0x08,
	0x81, 0xa0, 0xba, 0xd8, 0x45, 0xa0, 0xac, 0x80,
	0x3c, 0x80, 0x11, 0x04, 0x02, 0x22, 0x44, 0x86,
	0x54, 0x4b, 0x25, 0x03, 0x00, 0x00, 0x01, 0x00,
};

const struct hdmiphy_conf hdmiphy_conf[] = {
	{ V4L2_DV_480P59_94, hdmiphy_conf27 },
	{ V4L2_DV_480P60, hdmiphy_conf27_027 },
	{ V4L2_DV_576P50, hdmiphy_conf27 },
	{ V4L2_DV_720P50, hdmiphy_conf74_25 },
	{ V4L2_DV_720P59_94, hdmiphy_conf74_175 },
	{ V4L2_DV_720P60, hdmiphy_conf74_25 },
	{ V4L2_DV_1080I50, hdmiphy_conf74_25 },
	{ V4L2_DV_1080I59_94, hdmiphy_conf74_175 },
	{ V4L2_DV_1080I60, hdmiphy_conf74_25 },
	{ V4L2_DV_1080P24, hdmiphy_conf74_25 },
	{ V4L2_DV_1080P25, hdmiphy_conf74_25 },
	{ V4L2_DV_1080P30, hdmiphy_conf74_175 },
	{ V4L2_DV_1080P50, hdmiphy_conf148_5 },
	{ V4L2_DV_1080P59_94, hdmiphy_conf148_352 },
	{ V4L2_DV_1080P60, hdmiphy_conf148_5 },
	{ V4L2_DV_720P60_FP, hdmiphy_conf148_5 },
	{ V4L2_DV_720P60_SB_HALF, hdmiphy_conf74_25 },
	{ V4L2_DV_720P60_TB, hdmiphy_conf74_25 },
	{ V4L2_DV_720P59_94_FP, hdmiphy_conf148_5 },
	{ V4L2_DV_720P59_94_SB_HALF, hdmiphy_conf74_25 },
	{ V4L2_DV_720P59_94_TB, hdmiphy_conf74_25 },
	{ V4L2_DV_720P50_FP, hdmiphy_conf148_5 },
	{ V4L2_DV_720P50_SB_HALF, hdmiphy_conf74_25 },
	{ V4L2_DV_720P50_TB, hdmiphy_conf74_25 },
	{ V4L2_DV_1080P24_FP, hdmiphy_conf148_5 },
	{ V4L2_DV_1080P24_SB_HALF, hdmiphy_conf74_25 },
	{ V4L2_DV_1080P24_TB, hdmiphy_conf74_25 },
	{ V4L2_DV_1080P23_98_FP, hdmiphy_conf148_5 },
	{ V4L2_DV_1080P23_98_SB_HALF, hdmiphy_conf74_25 },
	{ V4L2_DV_1080P23_98_TB, hdmiphy_conf74_25 },
	{ V4L2_DV_1080I60_SB_HALF, hdmiphy_conf74_25 },
	{ V4L2_DV_1080I59_94_SB_HALF, hdmiphy_conf74_25 },
	{ V4L2_DV_1080I50_SB_HALF, hdmiphy_conf74_25 },
	{ V4L2_DV_1080P60_SB_HALF, hdmiphy_conf148_5 },
	{ V4L2_DV_1080P60_TB, hdmiphy_conf148_5 },
	{ V4L2_DV_1080P30_FP, hdmiphy_conf148_5 },
	{ V4L2_DV_1080P30_SB_HALF, hdmiphy_conf74_25 },
	{ V4L2_DV_1080P30_TB, hdmiphy_conf74_25 },
};

const int hdmiphy_conf_cnt = ARRAY_SIZE(hdmiphy_conf);
