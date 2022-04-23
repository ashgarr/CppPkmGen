#include "Tackle.h"
#include <iostream>

Tackle::Tackle() {
	power = 40;
	accuracy = 100;
}

void Tackle::damage() {
	std::cout << "dealt damage" << std::endl;
}

void Tackle::special() {
	std::cout << "applied status" << std::endl;
}