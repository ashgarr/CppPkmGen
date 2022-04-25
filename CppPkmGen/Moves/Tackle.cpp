#include "Tackle.h"
#include <iostream>

Tackle::Tackle() {
	power = 40;
	accuracy = 100;
    type = "normal";
}

void Tackle::damage() {
	std::cout << "dealt damage" << std::endl;
}

void Tackle::special() {
	std::cout << "applied status" << std::endl;
}