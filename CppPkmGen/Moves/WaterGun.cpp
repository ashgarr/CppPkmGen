#include "WaterGun.h"
#include <iostream>

WaterGun::WaterGun() {
    power = 40;
    accuracy = 100;
    type = "water";
}

void WaterGun::damage() {
    std::cout << "dealt water gun damage" << std::endl;
}

void WaterGun::special() {
    std::cout << "applied water gun status" << std::endl;
}