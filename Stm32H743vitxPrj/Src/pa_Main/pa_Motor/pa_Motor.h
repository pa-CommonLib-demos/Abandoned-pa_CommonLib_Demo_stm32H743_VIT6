#ifndef __PA_MOTOR_H__
#define __PA_MOTOR_H__
extern "C"{
    #include "pa_CommonLib/src/drv/pa_CommonDrv/pa_CommonDrv.h"
}

namespace pa_Motor{

    void setSpeed(int index,double speed);

    
}

#endif // __PA_MOTOR_H__