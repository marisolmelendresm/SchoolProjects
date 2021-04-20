//
// Created by Marisol on 02/06/2020.
//

#ifndef SNAKESPOLIM_AUTOMATICO_H
#define SNAKESPOLIM_AUTOMATICO_H

#include "Game.h"
#include <iostream>

class Automatico:public Game {
public:
    Automatico();
    Automatico(int, int, int, int, int, int, int);
    virtual void start();
};


#endif //SNAKESPOLIM_AUTOMATICO_H
