#include <lvgl.h>
#include <lv_conf.h>
#include "lv_demo_stress.h"
#include "FrameBuffer.h"

#define CAPACITOR_TOUCH
//#define RESISTIVE_TOUCH

#ifdef CAPACITOR_TOUCH
#define INT_PIN 6
#define RST_PIN 13

#include <Wire.h>
#include "Goodix.h"
#endif

#ifdef RESISTIVE_TOUCH
#include <touchscreen.h>
#endif

#ifdef CAPACITOR_TOUCH
Goodix touch = Goodix();
GTPoint gtPoint;
#endif

#ifdef RESISTIVE_TOUCH
static TouchScreen touchscreen;
static int temp_touch;
#endif

/*Change to your screen resolution*/
static const uint32_t screenWidth  = 480;
static const uint32_t screenHeight = 272;

static FrameBuffer framebuffer;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * 10];

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  framebuffer.areaPresent(area->x1, area->y1, area->x2 - area->x1 + 1, area->y2 - area->y1 + 1, (pixel_format *)color_p);
  lv_disp_flush_ready(disp);
}

/* Reading input device (simulated encoder here) */
static void read_encoder(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
#ifdef CAPACITOR_TOUCH
  int rs = touch.OnePiontScan(&gtPoint);
  if (rs > 0)
  {
    data->point.x = gtPoint.x;
    data->point.y = gtPoint.y;
    data->state = LV_INDEV_STATE_PR;
    Serial.print(data->point.x);
    Serial.print(" - ");
    Serial.println(data->point.y);
  }
  else
  {
    data->state = LV_INDEV_STATE_REL;
  }
#endif

#ifdef RESISTIVE_TOUCH
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
#endif
}

void setup()
{
  Serial.begin(115200);
  Serial.println("setup start");

  lv_init();

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

  lv_demo_stress();

#ifdef CAPACITOR_TOUCH
  Wire.begin(400000);
  if (touch.begin(INT_PIN, RST_PIN) != true)
  {
    Serial.println("Touch init failed");
  }
  Wire.beginTransmission(touch.i2cAddr);
  int error = Wire.endTransmission();
  if (error != 0)
  {
    Serial.print(": ERROR #");
    Serial.println(error);
  }
  touch.fwResolution(screenWidth, screenHeight);
#endif

#ifdef RESISTIVE_TOUCH
  touchscreen.begin();
  touchscreen.calibrate(screenWidth, screenHeight);
#endif

  Serial.println("setup done");
}

void loop()
{
  /* let the GUI do its work */
  lv_task_handler();
}
