//
// Created by Marisol on 28/05/2020.
//

#include "Ladder.h"

Ladder::Ladder() {
    reward = 3;
}

Ladder::Ladder(int n, int r): Box(n) {
    reward = r;
}

int Ladder::move() {
    return reward;
}

char Ladder::getT() {
    return 'L';
}