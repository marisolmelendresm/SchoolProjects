//
// Created by Marisol on 28/05/2020.
//

#ifndef SNAKESPOLIM_BOX_H
#define SNAKESPOLIM_BOX_H


using namespace std;

class Box{
private:
    int num;
public:
    Box();
    Box(int);
    virtual int move();
    virtual char getT();
};


#endif //SNAKESPOLIM_BOX_H
