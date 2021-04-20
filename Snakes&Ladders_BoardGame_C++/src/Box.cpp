//
// Created by Marisol on 28/05/2020.
//

#include "Box.h"

Box::Box() {
    num = 1;
}

Box::Box(int pos){
    num = pos;
}

int Box::move() {
    return 0;
}

char Box::getT() {
    return 'N';
}