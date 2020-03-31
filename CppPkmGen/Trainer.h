#pragma once
class Trainer
{
private:
	const char* name;
	unsigned short trainerID;
	unsigned short secretID;
public:
	Trainer(const char* tname);
	Trainer();
	const char* getName();
	unsigned short getTrainerID();
	unsigned short getSecretID();
};

