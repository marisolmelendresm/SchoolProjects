//
// Created by Marisol on 28/05/2020.
//

#include "Normal.h"

Normal::Normal() {
}

Normal::Normal(int n):Box(n){
}

int Normal::move(){
    return 0;
}

char Normal::getT() {
    return 'N';
}

