// CppPkmGen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <ctime>
#include "Trainer.h"
#include "Pokemon.h"
#include "Tackle.h"
#include "NumberGenerator.h"

Trainer trainer;
int runtime = 0;
bool gen7;
int catchOne();
int max = -1;
int min = 1000000;
int totalAttempts = 1000;

int main()
{
    srand(time(0));

    Tackle tac = Tackle();
    tac.damage();

    // NAME HARVEST
    std::string s_name;
    std::cout << "What is your name?" << std::endl;
    std::cin >> s_name;
    const char* name = s_name.c_str();

    // GEN 7 HARVEST
    std::string s_gen7;
    std::cout << "Use the Gen 7 math? (Y/N)" << std::endl;
    bool gen7InputOK = false;
    while (!gen7InputOK)
    {
        std::cin >> s_gen7;
        if (s_gen7 == "Y" || s_gen7 == "y") {
            gen7 = true;
            gen7InputOK = true;
        }
        else if (s_gen7 == "N" || s_gen7 == "n") {
            gen7 = false;
            gen7InputOK = true;
        }
        else {
            std::cout << "Please input Y or N." << std::endl;
        }
    }

    // FUNCTION

    trainer = Trainer(name);

    int sum = 0;

    for (int i = 0; i < totalAttempts; i++) {
        sum += catchOne();
    }

    int avg = sum / totalAttempts;

    printf("That took an average of %d attempts, and a total of %d attempts!\n", avg, sum);
    printf("The fastest catch took %d attempts, and the slowest took %d attempts!\n", min, max);
}

int catchOne() {
    bool gotShiny = false;
    int catches = 0;
    Pokemon a = Pokemon(1);

    while (!gotShiny) {
        catches++;
        if (a.checkShiny(trainer.getTrainerID(), trainer.getSecretID(), gen7)) {
            gotShiny = true;
            break;
        }
        //printf("%d\n", a.getShinyVal(trainer.getTrainerID(), trainer.getSecretID()));
        a.regen();
    }

    runtime++;
    if (catches > max) {
        max = catches;
    }
    if (catches < min) {
        min = catches;
    }
    //printf("%d) You caught a shiny X after %d tries!\n", runtime, catches);
    std::cout << runtime << ") You caught a shiny X after " << catches << " tries!" << std::endl;
    return catches;
}

void rngDebug() {
    long qSum = 0;
    for (int j = 0; j < 10000; j++) {
        int t_num = u16Gen();
        std::cout << t_num << std::endl;
        qSum = qSum + t_num;
    }
    std::cout << qSum / 10000 << std::endl;
}
