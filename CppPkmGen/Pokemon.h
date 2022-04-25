#pragma once
class Pokemon
{
private:
    int id;
    int level;
    int hpIV;
    int atIV;
    int deIV;
    int saIV;
    int sdIV;
    int spIV;
    const char* type;
    unsigned personality;
    void genIVs();
    unsigned personalityGen();

public:
    void regen();
    int getLevel();
    Pokemon(int id);
    const char* getType();
    int getHP();
    int getAtk();
    int getDef();
    unsigned getPersonality();
    bool checkShiny(unsigned short trainerID, unsigned short secretID, bool gen7);
    int getShinyVal(unsigned short trainerID, unsigned short secretID);
};

