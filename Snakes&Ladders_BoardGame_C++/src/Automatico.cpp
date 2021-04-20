//
// Created by Marisol on 02/06/2020.
//

#include "Automatico.h"

Automatico::Automatico() {
}

Automatico::Automatico(int b, int p, int lim, int s, int l, int pe, int re):Game(b, p, lim, s, l, pe, re) {}

void Automatico::start() {
    int numPlay = getNumplay();
    int numBox = getNumbox();
    int numS = getnumS();
    int numL = getnumL();
    int limT = getlimT();
    int pen = getpen();
    int rew = getrew();
    //Jugadores
    Player players[numPlay];
    for (int ll = 0; ll < numPlay; ll++){
        players[ll] = Player(ll+1, 1);
    }
    Tablero board(numBox, numS, numL);
    board.generarTablero(pen, rew);
    int nTurn = 0;
    bool win = false;
    int dado;
    int posAct;
    int numJ;
    char finalType;
    int posFin;
    Dice dice;
    while ((nTurn <= limT) && !win){
        nTurn++;
        for (int y = 0; y < numPlay; y++){
            numJ = players[y].getNum();
            dado = dice.roll();
            posAct = players[y].advance(dado);
            finalType = board.getBox(posAct) -> getT();
            posFin = players[y].finalPos(finalType, pen, rew);
            cout << nTurn << " " << numJ << " " << posAct << " " << finalType << " " << posFin << endl;

        }
        for (int x = 0; x < numPlay; x++){
            if (players[x].getPos() >= numBox){
                win = true;
                cout <<"Player " << players[x].getNum() << " is the winner!" << endl;
            }
        }

    }
    cout << "--GAME OVER--";
}