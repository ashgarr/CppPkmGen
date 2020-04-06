#include "Trainer.h"
#include "NumberGenerator.h"

Trainer::Trainer(const char* name) {
	this->name = name;
	trainerID = u16Gen();
	secretID = u16Gen();
}

Trainer::Trainer() {
	const char* test = "o";
	trainerID = u16Gen();
	secretID = u16Gen();
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