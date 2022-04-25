#pragma once
#include "Move.h"
class Tackle : private Move
{
private:
    int power;
    int accuracy;
    const char* type;
public:
    Tackle();
    void damage();
    void special();
};