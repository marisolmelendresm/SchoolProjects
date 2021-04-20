//
// Created by Marisol on 28/05/2020.
//

#include "Dice.h"

Dice::Dice(){
    srand(time(NULL));
}

int Dice::roll(){
    int num;
    num = 1+rand()%(6);
    return num;
}
