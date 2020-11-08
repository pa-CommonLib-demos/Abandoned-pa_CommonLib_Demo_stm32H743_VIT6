#include "pa_UsedDevice.h"

namespace pa_UsedDevice
{
    pa_ILI9341 &ili9341 = pa_ILI9341::instance;
    pa_touchScreen &touch = pa_touchScreen::instance;
    SvpwmFoc focMotor1;
    AS5048A as5048a_1;
}