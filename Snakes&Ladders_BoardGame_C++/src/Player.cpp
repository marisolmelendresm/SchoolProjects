//
// Created by Marisol on 28/05/2020.
//

#include "Player.h"

Player::Player(){
    position = 1;
}

Player::Player(int n, int pos) {
    position = pos;
    number = n;
}

int Player::finalPos(char tipo, int pen, int rew){
    if (tipo == 'S'){
        position = position - pen;
    }
    else{
        if (tipo == 'L'){
            position = position + rew;
        }
    }
    return position;
}

int Player::advance(int dice) {
    position = position + dice;
    return position;
}

int Player::getPos(){
    return position;
}

int Player::getNum(){
    return number;
}