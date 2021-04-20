//
// Created by Marisol on 28/05/2020.
//

#include "Snake.h"

Snake::Snake(){
    penalty = -3;
}

Snake::Snake(int n, int p):Box(n){
    penalty = p;
}

int Snake::move() {
    return penalty;
}

char Snake::getT() {
    return 'S';
}