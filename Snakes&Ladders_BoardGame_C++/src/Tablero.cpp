//
// Created by Marisol on 28/05/2020.
//

#include "Tablero.h"

#include<stdlib.h>
#include<time.h>

Tablero::Tablero() {
    numBox = 30;
    numS = 3;
    numL = 3;
}

Tablero::Tablero(int b, int s, int l){
    numBox = b;
    numS = s;
    numL = l;
}

void Tablero::generarTablero(int pen, int rew) {
    //Generar posiciones aleatorias para S y L
    int lis[2] = {numS, numL};
    int numS_l[numS];
    int numL_l[numL];
    int numLista[numS + numL];
    int k = 0;
    for (int j = 0; j <= 1; j++){
        for (int i = 0; i < lis[j]; i++){
            int pos;
            pos = 1+rand()%(numBox);
            for (int l = 0; l < k; l++)
                if (pos == numLista[l]){
                    pos = 1+rand()%(numBox);
                    l = 0;
                }
            numLista[k] = pos;
            k++;
            if (j == 0) { numS_l[i] = pos; }
            else{ numL_l[i] = pos; }
        }
    }
    //Generar tablero
    for (int l = 0; l < numBox; l++){
        tablero.push_back(new Normal(l+1));
        //Verificar si en esa posición debería haber una escalera o serpiente
        for (int ii = 0; ii < numS; ii++){ if (l+1 == numS_l[ii]){ tablero.push_back(new Snake(l+1, pen)); } }
        for (int jj = 0; jj < numL; jj++){ if (l+1 == numL_l[jj]){ tablero.push_back(new Ladder(l+1, rew)); } }
    }
}

Box* Tablero::getBox(int index){
    return(tablero[index]);
}