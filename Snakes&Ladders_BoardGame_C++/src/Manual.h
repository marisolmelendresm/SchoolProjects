//
// Created by Marisol on 02/06/2020.
//

#ifndef SNAKESPOLIM_MANUAL_H
#define SNAKESPOLIM_MANUAL_H

#include "Game.h"
#include <vector>

class Manual:public Game {
public:
    Manual();
    Manual(int, int, int, int, int, int, int);
    virtual void start();
};


#endif //SNAKESPOLIM_MANUAL_H
