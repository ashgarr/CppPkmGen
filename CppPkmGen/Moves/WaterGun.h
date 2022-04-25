#pragma once
#include "Move.h"
class WaterGun : private Move
{
private:
    int power;
    int accuracy;
    const char* type;
public:
    WaterGun();
    void damage();
    void special();
};