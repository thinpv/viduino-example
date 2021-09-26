/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "../lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "../custom/custom.h"


void setup_scr_screen(lv_ui *ui){

	//Write codes screen
	ui->screen = lv_obj_create(NULL, NULL);

	//Write codes screen_btn_1
	ui->screen_btn_1 = lv_btn_create(ui->screen, NULL);

	//Write style LV_BTN_PART_MAIN for screen_btn_1
	static lv_style_t style_screen_btn_1_main;
	lv_style_init(&style_screen_btn_1_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_btn_1_main
	lv_style_set_radius(&style_screen_btn_1_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_screen_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_btn_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_btn_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_screen_btn_1_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_screen_btn_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_screen_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_screen_btn_1_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_btn_1, LV_BTN_PART_MAIN, &style_screen_btn_1_main);
	lv_obj_set_pos(ui->screen_btn_1, 18, 5);
	lv_obj_set_size(ui->screen_btn_1, 100, 50);
	lv_btn_set_checkable(ui->screen_btn_1, true);
	ui->screen_btn_1_label = lv_label_create(ui->screen_btn_1, NULL);
	lv_label_set_text(ui->screen_btn_1_label, "RELAY 1");
	lv_obj_set_style_local_text_color(ui->screen_btn_1_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->screen_btn_1_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_12);

	//Write codes screen_cb_1
	ui->screen_cb_1 = lv_checkbox_create(ui->screen, NULL);
	lv_checkbox_set_text(ui->screen_cb_1, "Rơ le 2");

	//Write style LV_CHECKBOX_PART_BG for screen_cb_1
	static lv_style_t style_screen_cb_1_bg;
	lv_style_init(&style_screen_cb_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_cb_1_bg
	lv_style_set_radius(&style_screen_cb_1_bg, LV_STATE_DEFAULT, 6);
	lv_style_set_bg_color(&style_screen_cb_1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_cb_1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_cb_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_cb_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_cb_1_bg, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_screen_cb_1_bg, LV_STATE_DEFAULT, &lv_font_simsun_20);
	lv_style_set_text_letter_space(&style_screen_cb_1_bg, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_cb_1, LV_CHECKBOX_PART_BG, &style_screen_cb_1_bg);

	//Write style LV_CHECKBOX_PART_BULLET for screen_cb_1
	static lv_style_t style_screen_cb_1_bullet;
	lv_style_init(&style_screen_cb_1_bullet);

	//Write style state: LV_STATE_DEFAULT for style_screen_cb_1_bullet
	lv_style_set_radius(&style_screen_cb_1_bullet, LV_STATE_DEFAULT, 6);
	lv_style_set_bg_color(&style_screen_cb_1_bullet, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_cb_1_bullet, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_cb_1_bullet, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_cb_1_bullet, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen_cb_1_bullet, LV_STATE_DEFAULT, lv_color_make(0x02, 0xa2, 0xb1));
	lv_style_set_border_width(&style_screen_cb_1_bullet, LV_STATE_DEFAULT, 1);
	lv_obj_add_style(ui->screen_cb_1, LV_CHECKBOX_PART_BULLET, &style_screen_cb_1_bullet);
	lv_obj_set_pos(ui->screen_cb_1, 27, 75);

	//Write codes screen_sw_1
	ui->screen_sw_1 = lv_switch_create(ui->screen, NULL);

	//Write style LV_SWITCH_PART_BG for screen_sw_1
	static lv_style_t style_screen_sw_1_bg;
	lv_style_init(&style_screen_sw_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_sw_1_bg
	lv_style_set_radius(&style_screen_sw_1_bg, LV_STATE_DEFAULT, 100);
	lv_style_set_bg_color(&style_screen_sw_1_bg, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_color(&style_screen_sw_1_bg, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_dir(&style_screen_sw_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_sw_1_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_sw_1, LV_SWITCH_PART_BG, &style_screen_sw_1_bg);

	//Write style LV_SWITCH_PART_INDIC for screen_sw_1
	static lv_style_t style_screen_sw_1_indic;
	lv_style_init(&style_screen_sw_1_indic);

	//Write style state: LV_STATE_DEFAULT for style_screen_sw_1_indic
	lv_style_set_radius(&style_screen_sw_1_indic, LV_STATE_DEFAULT, 100);
	lv_style_set_bg_color(&style_screen_sw_1_indic, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_color(&style_screen_sw_1_indic, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_dir(&style_screen_sw_1_indic, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_sw_1_indic, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_sw_1, LV_SWITCH_PART_INDIC, &style_screen_sw_1_indic);

	//Write style LV_SWITCH_PART_KNOB for screen_sw_1
	static lv_style_t style_screen_sw_1_knob;
	lv_style_init(&style_screen_sw_1_knob);

	//Write style state: LV_STATE_DEFAULT for style_screen_sw_1_knob
	lv_style_set_radius(&style_screen_sw_1_knob, LV_STATE_DEFAULT, 100);
	lv_style_set_bg_color(&style_screen_sw_1_knob, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_sw_1_knob, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_sw_1_knob, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_sw_1_knob, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_sw_1, LV_SWITCH_PART_KNOB, &style_screen_sw_1_knob);
	lv_obj_set_pos(ui->screen_sw_1, 39, 134);
	lv_obj_set_size(ui->screen_sw_1, 40, 20);
	lv_switch_set_anim_time(ui->screen_sw_1, 600);

	//Init events for screen
	events_init_screen(ui);
}
