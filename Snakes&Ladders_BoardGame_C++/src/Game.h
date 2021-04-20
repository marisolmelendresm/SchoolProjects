//
// Created by Marisol on 28/05/2020.
//

#ifndef SNAKESPOLIM_GAME_H
#define SNAKESPOLIM_GAME_H

#include "Player.h"
#include "Dice.h"
#include "Tablero.h"

#include<stdlib.h>

class Game {
private:
    int numBox;
    int numPlay;
    int limT;
    int numS;
    int numL;
    int pen;
    int rew;
public:
    Game();
    Game(int, int, int, int, int, int, int);
    virtual void start() = 0;
    int getNumbox();
    int getNumplay();
    int getlimT();
    int getnumS();
    int getnumL();
    int getpen();
    int getrew();
};


#endif //SNAKESPOLIM_GAME_H
