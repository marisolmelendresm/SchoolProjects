//
// Created by Marisol on 28/05/2020.
//

#ifndef SNAKESPOLIM_SNAKE_H
#define SNAKESPOLIM_SNAKE_H

#include "Box.h"

class Snake: public Box {
private:
    int penalty;
public:
    Snake();
    Snake(int, int);
    virtual int move();
    virtual char getT();
};


#endif //SNAKESPOLIM_SNAKE_H
