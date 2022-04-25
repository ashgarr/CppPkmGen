#include "DamageCaluclator.h"
#include "Pokemon.h"
#include "Moves/AllMoves.h"

int DamageCalculator(Pokemon attacker, Pokemon defender, int power, const char* type) {
    double startingPower = ((((2 * attacker.getLevel() / 5.0) + 2) * power * (attacker.getAtk() / defender.getDef())) / 50) + 2;
    double stabModify =
}

double stabCalc(Pokemon attacker, const char* type) {
    if type == attacker.
}