#include <cstdlib>
#include <ctime>
#include "Trainer.h"

Trainer::Trainer(const char* name) {
	this->name = name;
	srand(time(NULL));
	trainerID = (unsigned short) (rand() % 65536);
	secretID = (unsigned short)(rand() % 65536);
}

Trainer::Trainer() {
	const char* test = "o";
	name = test;
	srand(time(0));
	trainerID = (unsigned short)(rand() % 65536);
	secretID = (unsigned short)(rand() % 65536);
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