#include "Arduino.h"

#include <lvgl.h>
#include <lv_conf.h>
#include "lv_demo_benchmark.h"
#include <touchscreen.h>
#include "FrameBuffer.h"

/*Change to your screen resolution*/
static const uint32_t screenWidth  = 480;
static const uint32_t screenHeight = 272;

static FrameBuffer framebuffer;
static TouchScreen touchscreen;
//static lv_disp_buf_t disp_buf;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * 10];
static int temp_touch;

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
	framebuffer.areaPresent(area->x1, area->y1, area->x2 - area->x1 + 1, area->y2 - area->y1 + 1, (pixel_format *)color_p);
	lv_disp_flush_ready(disp);
}

/* Reading input device (simulated encoder here) */
static void read_encoder(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
	touchscreen.read();
	temp_touch = touchscreen.getStatus();
	data->point.x = touchscreen.getX();
	data->point.y = touchscreen.getY();
	if (temp_touch == TOUCHSCREEN_STATUS_RELEASE)
		data->state = LV_INDEV_STATE_REL;
	else
		data->state = LV_INDEV_STATE_PR;
	if (temp_touch > 1)
	{
		Serial.print(data->point.x);
		Serial.print(" - ");
		Serial.print(data->point.y);
		Serial.print(" --> ");
		Serial.println(temp_touch);
	}
	//return false;
}

#if LV_USE_LOG != 0
/* Serial debugging */
void my_print( const char * dsc )
{
   Serial.printf( "LOG: %s\r\n", dsc );
}
#endif

void setup()
{
	Serial.begin(115200);
	Serial.println("setup start");

	lv_init();

#if LV_USE_LOG != 0
   lv_log_register_print_cb( my_print ); /* register print function for debugging */
#endif

	framebuffer.begin();

	lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * 10 );

  /*Initialize the display*/
   static lv_disp_drv_t disp_drv;
   lv_disp_drv_init( &disp_drv );
   /*Change the following line to your display resolution*/
   disp_drv.hor_res = screenWidth;
   disp_drv.ver_res = screenHeight;
   disp_drv.flush_cb = my_disp_flush;
   disp_drv.draw_buf = &draw_buf;
   lv_disp_drv_register( &disp_drv );

   /*Initialize the (dummy) input device driver*/
   static lv_indev_drv_t indev_drv;
   lv_indev_drv_init( &indev_drv );
   indev_drv.type = LV_INDEV_TYPE_POINTER;
   indev_drv.read_cb = read_encoder;
   lv_indev_drv_register( &indev_drv );

	lv_demo_benchmark();

	touchscreen.begin();
	touchscreen.calibrate(screenWidth, screenHeight);

	Serial.println("setup done");
}

void loop()
{
	/* let the GUI do its work */
	lv_task_handler();
}
