#include "Pokemon.h"
#include <cstdlib>
#include "NumberGenerator.h"
#include <algorithm>

Pokemon::Pokemon(int id) {
	this->id = id;
	genIVs();
	this->personality = personalityGen();
}

void Pokemon::regen() {
	genIVs();
	this->personality = personalityGen();
}

int Pokemon::getHP() {
	return hpIV;
}

unsigned Pokemon::getPersonality() {
	return personality;
}

void Pokemon::genIVs() {
	hpIV = (rand() % 32);
	atIV = (rand() % 32);
	deIV = (rand() % 32);
	saIV = (rand() % 32);
	sdIV = (rand() % 32);
	spIV = (rand() % 32);
}

unsigned Pokemon::personalityGen() {
	int val = u16Gen() << 16 | u16Gen();
	return val;
}

bool Pokemon::checkShiny(unsigned short trainerID, unsigned short secretID, bool gen7) {
	unsigned short upper = (unsigned short)(personality >> 16);
	unsigned short lower = (unsigned short)(personality & 0xFFFF);
	unsigned short val = (unsigned short)(trainerID ^ secretID ^ upper ^ lower);
	if (gen7) {
		return val < 16;
	}
	else {
		return val < 8;
	}
}

int Pokemon::getShinyVal(unsigned short trainerID, unsigned short secretID) {
	unsigned short upper = (unsigned short)(personality >> 16);
	unsigned short lower = (unsigned short)(personality & 0xFFFF);
	return (unsigned short)(trainerID ^ secretID ^ upper ^ lower);
}

bool Pokemon::capture() {
	int hpMax = 200;
	int hpCurrent = 1;
	int catchRate = 200;
	float ballBonus = 1;
	float statusBonus = 1;

	double a = (((3 * hpMax - 2 * hpCurrent) * catchRate * ballBonus) / (3 * hpMax)) * statusBonus;

	a = std::min(a, 255.0);

	return (rand() % 255) < a;
}