//
// Created by Marisol on 28/05/2020.
//

#ifndef SNAKESPOLIM_TABLERO_H
#define SNAKESPOLIM_TABLERO_H

#include "Box.h"
#include "Normal.h"
#include "Snake.h"
#include "Ladder.h"

#include <vector>

class Tablero {
private:
    int numBox;
    int numS;
    int numL;
    vector<Box*> tablero;
public:
    Tablero();
    Tablero(int, int, int);
    void generarTablero(int, int);
    Box* getBox(int);
};

#endif //SNAKESPOLIM_TABLERO_H
