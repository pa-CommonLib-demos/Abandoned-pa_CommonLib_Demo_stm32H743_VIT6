#ifndef __MAINGUI_H__
#define __MAINGUI_H__
namespace GUI
{
    void initMainGUI();
    void updateRuningTime(int time);
    void updateEncoder(int E1, int E1_d,int E2, int E2_d);
    void updateAdc(double value);
}
#endif // __MAINGUI_H__