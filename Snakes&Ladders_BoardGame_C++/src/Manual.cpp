//
// Created by Marisol on 02/06/2020.
//

#include "Manual.h"
#include <iostream>

Manual::Manual() {
}

Manual::Manual(int b, int p, int lim, int s, int l, int pe, int re):Game(b, p, lim, s, l, pe, re) {}

void Manual::start() {
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

    //Empezar jugada
    Tablero board(numBox, numS, numL);
    board.generarTablero(pen, rew);
    int nTurn = 0;
    bool win = false;
    int dado;
    int posAct;
    int numJ;
    char finalType;
    int posFin;
    char ans = 'C';
    Dice dice;
    while ((nTurn <= limT) && !win && (ans == 'C')) {
        nTurn++;
        for (int y = 0; y < numPlay; y++) {
            numJ = players[y].getNum();
            dado = dice.roll();
            posAct = players[y].advance(dado);
            finalType = board.getBox(posAct) -> getT();
            posFin = players[y].finalPos(finalType, pen, rew);
            cout << nTurn << " " << numJ << " " << posAct << " " << finalType << " " << posFin << endl;

        }
        if (numJ == numPlay) {
            cout << "Press C to continue, or E to end the game" << endl;
            cin >> ans;
            if (ans == 'E') {
                cout << "Thanks for playing" << endl;
            }
        }
        for (int x = 0; x < numPlay; x++) {
            if (players[x].getPos() >= numBox) {
                win = true;
                cout << "Player " << players[x].getNum() << " is the winner!" << endl;
            }
        }

    }
    cout << "--GAME OVER--";
}