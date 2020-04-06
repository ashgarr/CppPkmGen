#include "NumberGenerator.h"
#include <cstdlib>

NumberGenerator::NumberGenerator() {
	
}

unsigned short NumberGenerator::u16Gen() {
	return (unsigned short) ((rand() % 256) << 8 | (rand() % 256));
}