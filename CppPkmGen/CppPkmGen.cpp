// CppPkmGen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <ctime>
#include "Trainer.h"
#include "Pokemon.h"

Trainer trainer;
int runtime = 0;
bool gen7;
int catchOne();

int main()
{
    srand(time(NULL));

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
        a.regen();
    }

    runtime++;
    printf("%d) You caught a X after %d tries!\n", runtime, catches);
    return catches;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
