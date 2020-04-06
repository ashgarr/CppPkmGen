#include "NumberGenerator.h"
#include <cstdlib>

unsigned short u16Gen() {
	return (unsigned short) ((rand() % 256) << 8 | (rand() % 256));
}