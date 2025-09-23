#ifndef GPIODEAL_H
#define GPIODEAL_H

#include "mykey.h"
#include "UsbMcu.h"

//读Gpio值
int GetGpioValue(int iGpioNum);

//写Gpio值
void SetGpioValue(int iGpioNum,int iValue);






#endif // GPIODEAL_H
