/* touch_lg4946_asc.h
 *
 * Copyright (C) 2015 LGE.
 *
 * Author: daehyun.gil@lge.com
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef LGE_TOUCH_LG4946_ASC_H
#define LGE_TOUCH_LG4946_ASC_H

#define MAX_DELTA		(0x2AD)
#define TOUCH_MAX_W		(0xC53)
#define TOUCH_MAX_R		(0x2A1)
#define ONHAND_W		(0xC56)
#define ONHAND_R		(0x2A5)

#define MIN_DELTA_CNT		(1)
#define MAX_DELTA_CNT		(10)
#define LOW_DELTA_LIMIT		(10)
#define HIGH_DELTA_LIMIT	(2000)
#define LOW_DELTA_THRES_LIMIT	(100)
#define HIGH_DELTA_THRES_LIMIT	(2000)
#define SENSITIVITY_LOW_LIMIT	(300)
#define SENSITIVITY_HIGH_LIMIT	(1000)
#define TEMP_SENSITIVITY	(700)

enum {
	ASC_OFF = 0,
	ASC_ON,
};

enum {
	ASC_READ_MAX_DELTA = 0,
	ASC_GET_FW_SENSITIVITY,
	ASC_WRITE_SENSITIVITY,
	ASC_WRITE_ONHAND,
};

enum {
	DELTA_CHK_OFF = 0,
	DELTA_CHK_ON,
};

enum {
	NORMAL_SENSITIVITY = 0,
	ACUTE_SENSITIVITY,
	OBTUSE_SENSITIVITY,
};

enum {
	NOT_IN_HAND = 0,
	IN_HAND,
};

enum {
	DPC_FLAT_STATIC = 4,	/* NOT_IN_HAND */
	DPC_ANGLE_STATIC = 5,	/* NOT_IN_HAND */
	DPC_HIDDEN_STATE = 6,	/* NOT_IN_HAND */
	DPC_IN_HAND = 7,	/* IN_HAND */
	DPC_FACING = 11,	/* IN_HAND */
	DPC_UNKNOWN = 12,	/* NOT_IN_HAND */
};

struct lg4946_asc_info {
	bool	use_asc;
	u32	low_delta_thres;
	u32	high_delta_thres;
	u32	max_delta_cnt;

	bool	use_delta_chk;
	bool	delta_updated;
	u32	curr_delta_cnt;
	u32	delta[MAX_DELTA_CNT];
	u8	curr_sensitivity;

	u16	normal_s;
	u16	acute_s;
	u16	obtuse_s;

	struct lg4946_data	*d;
	struct delayed_work	finger_input_work;
};

bool lg4946_asc_usable(struct device *dev);
bool lg4946_asc_delta_chk_usable(struct device *dev);
void lg4946_asc_toggle_delta_check(struct device *dev);
void lg4946_asc_write_onhand(struct device *dev, u32 value);
void lg4946_asc_control(struct device *dev, bool on_off);
void lg4946_asc_register_sysfs(struct device *dev);
void lg4946_asc_init(struct device *dev);

#endif /* LGE_TOUCH_LG4946_ASC_H */

