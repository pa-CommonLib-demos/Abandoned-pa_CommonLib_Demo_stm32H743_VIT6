extern "C"
{
#include "pa_Motor.h"
#include "pa_CommonLib/src/drv/pa_PWM/pa_PWM.h"
}
namespace pa_Motor
{
    void setDirection(int index, char dir)
    {
        switch (index)
        {
        case 0://pwm c7
            if(dir){
                HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6 ,GPIO_PinState::GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PinState::GPIO_PIN_RESET);
            }else{
                HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6 ,GPIO_PinState::GPIO_PIN_RESET);
                HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PinState::GPIO_PIN_SET);
            }
            break;
        case 1://pwm c8
            if(dir){
                HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PinState::GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PinState::GPIO_PIN_RESET);
            }else{
                HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PinState::GPIO_PIN_RESET);
                HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PinState::GPIO_PIN_SET);
            }
            /* code */
            break;
        }
    }
    void setSpeed(int index, double speed)
    {
        setDirection(index, speed < 0);
        if (speed < 0)
        {
            speed = -speed;
        }
        switch (index)
        {
        case 0:
            pa_PWM::setPWMDuty(0, speed);
            break;
        case 1:
            pa_PWM::setPWMDuty(1, speed);
            break;
        }
    }
} // namespace pa_Motor