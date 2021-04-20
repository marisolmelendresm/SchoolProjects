//
// Created by Marisol on 28/05/2020.
//

#ifndef SNAKESPOLIM_PLAYER_H
#define SNAKESPOLIM_PLAYER_H


class Player {
private:
    int number;
    int position;
public:
    Player();
    Player(int, int);
    int finalPos(char, int, int);
    int advance(int);
    int getNum();
    int getPos();
};


#endif //SNAKESPOLIM_PLAYER_H
