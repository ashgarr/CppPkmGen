#include "Trainer.h"
#include "NumberGenerator.h"

Trainer::Trainer(const char* name) {
	this->name = name;
	NumberGenerator g = NumberGenerator();
	trainerID = g.u16Gen();
	secretID = g.u16Gen();
}

Trainer::Trainer() {
	const char* test = "o";
	name = test;
	NumberGenerator g = NumberGenerator();
	trainerID = g.u16Gen();
	secretID = g.u16Gen();
}

const char* Trainer::getName() {
	return name;
}

unsigned short Trainer::getTrainerID() {
	return trainerID;
}

unsigned short Trainer::getSecretID() {
	return secretID;
}