/* a96t3x6.h -- Linux driver for A96T3X6 chip as grip sensor
 *
 * Copyright (C) 2017 Samsung Electronics Co.Ltd
 * Author: YunJae Hwang <yjz.hwang@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 */

#ifndef __LINUX_A96T3X6_H
#define __LINUX_A96T3X6_H

//#include <linux/sensor/sensors_core.h>

#define GRIP_ERR(fmt, ...) pr_err("[GRIP_SUB] %s: "fmt, __func__, ##__VA_ARGS__)
#define GRIP_INFO(fmt, ...) pr_info("[GRIP_SUB] %s: "fmt, __func__, ##__VA_ARGS__)
#define GRIP_WARN(fmt, ...) pr_warn("[GRIP_SUB] %s: "fmt, __func__, ##__VA_ARGS__)

#define VENDOR_NAME	"ABOV"
#define MODEL_NAME	"A96T3X6_SUB"
#define MODULE_NAME	"grip_sensor_sub"
#define MODULE_NOTIFIER_NAME	"grip_notifier"

#define NOTIFY_CABLE_USB_FAST	0x01
#define NOTIFY_CABLE_OTG	0x03
#define NOTIFY_CABLE_USB_NORMAL	0x04
#define NOTIFY_CABLE_TA		0x25
#define NOTIFY_CABLE_TA_FAC	0x27

#define UNKNOWN_ON  1
#define UNKNOWN_OFF 2

#define TYPE_USB   1
#define TYPE_HALL  2
#define TYPE_BOOT  3
#define TYPE_FORCE 4

/* registers */
#define REG_LED_CONTROL		0x00
#define REG_FW_VER		0x01
#define REG_THRESHOLD		0x02
#define REG_BTNSTATUS		0x07
#define REG_DIFFDATA		0x0A
#define REG_RAWDATA		0x0E
#define REG_VENDORID		0x12
#define REG_GLOVE		0x13
#define REG_TSPTA		0x13
#define REG_MODEL_NO		0x14
#define REG_SAR_TOTALCAP	0x16
#define REG_SAR_MODE		0x17
#define REG_SAR_TOTALCAP_READ	0x18
#define REG_SW_RESET		0x1A
#define REG_SAR_ENABLE		0x24
#define REG_SAR_SENSING		0x25
#define REG_SAR_NOISE_THRESHOLD	0x26
#define REG_SAR_BASELINE	0x28
#define REG_SAR_DIFFDATA	0x2A
#define REG_SAR_DIFFDATA_D	0x2C
#define REG_SAR_RAWDATA		0x2E
#define REG_SAR_RAWDATA_D	0x30
#define REG_SAR_THRESHOLD	0x32

#define REG_DATA_UPDATE		0x40
#define REG_MODE_CHECK		0x41
#define REG_LED_CTRL_ON		0x60
#define REG_LED_CTRL_OFF	0x70
#define REG_STOP_MODE		0x80
#define REG_GRIP_ALWAYS_ACTIVE	0x20
#define GRIP_ALWAYS_ACTIVE_READY	0x21

#define REG_REF_CAP		0x50
#define REG_GAINDATA		0x52
#define REG_REF_GAINDATA	0x58
/* command */
#define CMD_ON			0x20
#define CMD_OFF			0x10
#define CMD_SW_RESET		0x10

#define BOOT_DELAY		45000
#define RESET_DELAY		150000
#define CRC_FAIL		0
#define CRC_PASS		1
#define FLASH_DELAY		1400000
#define FLASH_MODE		0x18

#define TK_FW_PATH_BIN		"abov/abov_noble.fw"
#define TK_FW_PATH_SDCARD	"/sdcard/Firmware/Gripsub/abov_fw.bin"
#define HALL_PATH		"/sys/class/sec/hall_ic/hall_detect"
#define HALLIC_CERT_PATH	"/sys/class/sec/hall_ic/certify_hall_detect"
#define HALL_CLOSE_STATE	1

/* depends on FW address configuration */
#ifdef CONFIG_SENSORS_A96T365IF
#define USER_CODE_ADDRESS	0x600
#else
#define USER_CODE_ADDRESS	0x800
#endif

#define I2C_M_WR	0 /* for i2c */
#define GRIP_LOG_TIME	15 /* 30s */

#define FIRMWARE_VENDOR_CALL_CNT 8
#define TEST_FIRMWARE_DETECT_VER 0xa0

enum {
	BUILT_IN = 0,
	SDCARD,
};
extern int sensors_create_symlink(struct input_dev *inputdev);
extern void sensors_remove_symlink(struct input_dev *inputdev);
extern int sensors_register(struct device *dev, void *drvdata,
	struct device_attribute *attributes[], char *name);
extern void sensors_unregister(struct device *dev,
	struct device_attribute *attributes[]);
#endif /* LINUX_A96T3X6_H */
