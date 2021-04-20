//
// Created by Marisol on 28/05/2020.
//

#include "Game.h"
#include <iostream>



Game::Game(){
    numBox = 30;
    numPlay = 2;
    limT = 60;
    numS = 3;
    numL = 3;
    pen = -3;
    rew = 3;
}

Game::Game(int b, int p, int lim, int S, int L, int pe,int re) {
    numBox = b;
    numPlay = p;
    limT = lim;
    numS = S;
    numL = L;
    pen = -pe;
    rew = re;
}

void Game::start() {
}

int Game::getNumbox() {
    return numBox;
}

int Game::getNumplay() {
    return numPlay;
}

int Game::getlimT() {
    return limT;
}

int Game::getnumL() {
    return numL;
}

int Game::getnumS() {
    return numS;
}

int Game::getpen() {
    return pen;
}

int Game::getrew() {
    return rew;
}