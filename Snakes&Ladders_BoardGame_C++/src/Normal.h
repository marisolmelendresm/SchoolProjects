//
// Created by Marisol on 28/05/2020.
//

#ifndef SNAKESPOLIM_NORMAL_H
#define SNAKESPOLIM_NORMAL_H

#include "Box.h"

class Normal: public Box {
public:
    Normal();
    Normal(int);
    virtual int move();
    virtual char getT();
};


#endif //SNAKESPOLIM_NORMAL_H
