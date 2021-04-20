//
// Created by Marisol on 28/05/2020.
//

#ifndef SNAKESPOLIM_LADDER_H
#define SNAKESPOLIM_LADDER_H

#include "Box.h"


class Ladder: public Box {
private:
    int reward;
public:
    Ladder();
    Ladder(int, int);
    virtual int move();
    virtual char getT();
};


#endif //SNAKESPOLIM_LADDER_H
