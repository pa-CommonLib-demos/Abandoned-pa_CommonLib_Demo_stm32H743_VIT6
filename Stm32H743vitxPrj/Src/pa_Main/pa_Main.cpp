#include "pa_CommonLib/src/drv/pa_CommonDrv/pa_CommonDrv.h"
#include "pa_CommonLib/src/service/display/ili9341/pa_ILI9341.h"
#include "pa_Main.h"
#include "pa_Motor/pa_Motor.h"
#include "pa_CommonLib/src/drv/pa_PWM/pa_PWM.h"
#include "pa_CommonLib/src/app/SvpwmFoc/SvpwmFoc.h"
extern "C"
{
    // #include "pa_CommonLib/src/service/display/st7789/lcd.h"

#include "pa_CommonLib/src/service/input/touchScreen/pa_touchScreen.h"
#include "pa_CommonLib/src/service/TI_Chips/Ads_112c04/Ads_112c04.h"
#include "pa_CommonLib/src/service/graphic/lvgl/lvgl.h"
#include "pa_Lvgl/pa_Lvgl_C.h"
#include "stdio.h"
#include "pa_Lvgl/GUIs/MainGUI/MainGUI.h"
}

void tim_100us_tick();
void tim_1ms_tick();
int cnt = 0;
int run = 0;
SvpwmFoc focMotor1;
// int encoder1 = 0;
// int encoder1_delta = 0;
// int encoder2 = 0;
// int encoder2_delta = 0;
// extern TIM_HandleTypeDef htim3, htim4, htim5;
//
extern uint16_t Global_Touch_X;
extern uint16_t Global_Touch_Y;
void pa_Main()
{
    // pa_set1MsCallback(tim_1ms_tick);
    pa_setTimerCallback(tim_100us_tick, tim_1ms_tick);
    pa_PWM::initPWMs();
    focMotor1.init(0, 1, 2);
    // pa_PWM::initPWMs();
    // HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);
    // HAL_TIM_Encoder_Start(&htim5, TIM_CHANNEL_ALL);

    // HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2,(GPIO_PinState)0);
    // LCD_Init();
    // LCD_Fill(0,0,100,100,GREEN);
    // LCD_ShowString(0,0,(const unsigned char *)"helloWorld",GREEN,BLACK,12,0);
    pa_ILI9341 &ili9341 = pa_ILI9341::instance;
    pa_touchScreen &touch = pa_touchScreen::instance;

    // Ads_112c04 &ads112c04 = Ads_112c04::instance;

    touch.init(240, 320, 210, 3800, 451, 3884, 40);

    // pa_delayMs(100);
    ili9341.init(pa_ILI9341::Rotation::Rotation_VERTICAL_2);
    // pa_delayMs(100);
    // ili9341.flush(0, 0, 235, 100, 0xff00);
    // ili9341.flush(0, 101, 235, 150, 0xff00);
    // pa_delayMs(100);
    // bool a = false;
    // ads112c04.init(Ads_112c04::AxState::DGND,
    //                Ads_112c04::AxState::DGND);
    // ads112c04.configRegister0(Ads_112c04::Gain::GAIN_1);
    // ads112c04.configRegister1(Ads_112c04::SpeedOfSample::SPS_1000,
    //                           Ads_112c04::Mode::Mode_Normal,
    //                           Ads_112c04::ConvMode::Continuous);
    // ads112c04.startConv();
    lv_init();
    pa_Lvgl_init();
    //button
    GUI::initMainGUI();

    // pa_delayMs(100);

    // __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 1000);
    // __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 1000);
    // for (;;){
    // }
    // touch.Hardware_SetCS(0);
    run = 0;
    // encoder1 = encoder2 = 0;
    // encoder1_delta = encoder2_delta = 0;
    for (;;)
    {
        // pa_Motor::setSpeed(0, cnt * 1.0 / 1000);
        // pa_Motor::setSpeed(1, cnt * 1.0 / 1000);
        // double adc;
        // if (ads112c04.getDrdyState())
        // {
        //     adc = ads112c04.readADC();
        // }
        { //lv
            // uint16_t coord[2];
            // pa_touchScreen::instance.readRaw(coord);

            GUI::updateEncoder(Global_Touch_X, Global_Touch_Y, run, (int)focMotor1.getCurEularAngle());
            // GUI::updateEncoder(encoder1, encoder1_delta, encoder2, encoder2_delta);
            // GUI::updateAdc(focMotor1.getCurEularAngle());
            lv_task_handler(); //lvgl刷新显示内容
        }
        // lv_tick_inc(10);
        // cnt++;
        // if (cnt == 1000)
        // {
        //     cnt = 0;
        //     run++;
        // }
        pa_delayMs(5);
        // if (touch.isPressed())
        // {
        //     lv_label_set_text(label, "Pressed");
        // }
        // else
        // {
        //     lv_label_set_text(label, "not Pressed");
        // }
    }
}
void tim_100us_tick()
{
    static bool state = false;

    //200us call foc
    if (state)
    {
        focMotor1.controlTick();
        focMotor1.plusAngleTest(200, 5000);
    }
    state = !state;
}
void tim_1ms_tick()
{
    lv_tick_inc(1);
    cnt++;
    if (cnt == 1000)
    {
        cnt = 0;
        run++;
    }
}
