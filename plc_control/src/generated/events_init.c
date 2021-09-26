/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl/lvgl.h"
#include "../../plc.h"


void events_init(lv_ui *ui)
{
}

static void screen_btn_1event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		plc_relay(0, lv_btn_get_state(obj) == LV_BTN_STATE_PRESSED);
	}
		break;
	default:
		break;
	}
}

static void screen_cb_1event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		plc_relay(1, lv_checkbox_get_state(obj) != LV_BTN_STATE_RELEASED);
	}
		break;
	default:
		break;
	}
}

static void screen_sw_1event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		plc_relay(2, lv_switch_get_state(obj) == LV_BTN_STATE_PRESSED);
	}
		break;
	default:
		break;
	}
}

void events_init_screen(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->screen_btn_1, screen_btn_1event_handler);
	lv_obj_set_event_cb(ui->screen_cb_1, screen_cb_1event_handler);
	lv_obj_set_event_cb(ui->screen_sw_1, screen_sw_1event_handler);
}
