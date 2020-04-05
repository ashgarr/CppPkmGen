#include "Pokemon.h"
#include <time.h>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iostream>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/random/uniform_int.hpp>

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
	
	//std::time_t now = std::time(0);
	//boost::random::mt19937 gen{ static_cast<std::uint32_t>(clock()) };
	//// BOOST GENS SIGNED INTS
	//boost::random::uniform_int_distribution<> dist(-2147483648, 2147483647);
	//unsigned val = 2147483648 + dist(gen);

	int val = rand() << 16 | rand();
	return val;
}

bool Pokemon::checkShiny(unsigned short trainerID, unsigned short secretID, bool gen7) {
	unsigned short upper = (unsigned short)(personality >> 16);
	unsigned short lower = (unsigned short)(personality & 0xFFFF);
	unsigned short val = (unsigned short)(trainerID ^ secretID ^ upper ^ lower);
	// val = 15;
	// std::cout << val << std::endl;
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