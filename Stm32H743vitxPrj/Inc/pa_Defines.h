#ifndef __PA_DEFINES_H__
#define __PA_DEFINES_H__

/***********************************************
 * 
 * 
 * 设置mcu宏
 * 
 * 
 * **********************************************/
// #ifndef ESP32
// #define ESP32
// #endif

// #ifndef MSP432P
// #define MSP432P
// #endif

// #ifndef STM32_F4
// #define STM32_F4
// #endif

#ifndef STM32_H7
#define STM32_H7
#endif
/***********************************************
 * 
 * 
 *   Select App.
 * 
 * 
 * **********************************************/
#define RobotArmApp_demo_Test
// #define SvpwmFoc_demo_Test

/***********************************************
 * 
 * 
 *   Include after select
 *
 * 
 * ********************************************/
#ifdef RobotArmApp_demo_Test
#include "pa_CommonLib/src/app/robotArmApp/demos/Test/Defines.h"
#endif
#ifdef SvpwmFoc_demo_Test
#include "pa_CommonLib/src/app/SvpwmFoc/demos/Test/Defines.h"
#endif

#endif // __PA_DEFINES_H__