// CppPkmGen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <ctime>
#include "Trainer.h"
#include "Pokemon.h"
#include "NumberGenerator.h"

Trainer trainer;
int runtime = 0;
bool gen7;
int catchOne();

int main()
{
    srand(time(0));

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
        if (s_gen7 == "Y") {
            gen7 = true;
            gen7InputOK = true;
        }
        else if (s_gen7 == "N") {
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
    int goes = 1000;

    for (int i = 0; i < goes; i++) {
        sum += catchOne();
    }

    int avg = sum / goes;

    printf("That took an average of %d attempts, and a total of %d attempts!", avg, sum);
    
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
    printf("%d) You caught a X after %d tries!\n", runtime, catches);
    return catches;
}

void rngDebug() {
    long qSum = 0;
    NumberGenerator g = NumberGenerator();
    for (int j = 0; j < 10000; j++) {
        int t_num = g.u16Gen();
        std::cout << t_num << std::endl;
        qSum = qSum + t_num;
    }
    std::cout << qSum / 10000 << std::endl;
}
