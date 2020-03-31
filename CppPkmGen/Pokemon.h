#pragma once
class Pokemon
{
private:
    int id;
    int hpIV;
    int atIV;
    int deIV;
    int saIV;
    int sdIV;
    int spIV;
    unsigned personality;
    void genIVs();
    unsigned personalityGen();

public:
    Pokemon(int id);
    int getHP();
    unsigned getPersonality();
    bool checkShiny(unsigned short trainerID, unsigned short secretID, bool gen7);
    int getShinyVal(unsigned short trainerID, unsigned short secretID);
};

