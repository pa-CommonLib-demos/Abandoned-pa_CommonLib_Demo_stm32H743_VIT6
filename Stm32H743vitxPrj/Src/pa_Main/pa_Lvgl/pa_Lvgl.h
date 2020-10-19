#ifndef __PA_LVGL_H__
#define __PA_LVGL_H__
#include "pa_CommonLib/src/service/graphic/lvgl/lvgl.h"
// void pa_Lvgl_init();
void pa_Lvgl_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
void pa_Lvgl_touchpad_read(lv_indev_t *indev, lv_indev_data_t *data);
#endif // __PA_LVGL_H__