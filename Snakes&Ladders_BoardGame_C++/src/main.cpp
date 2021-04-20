#include <iostream>
#include "Automatico.h"
#include "Manual.h"

using namespace std;

int boxes;
int snakes;
int ladders;
int pen;
int rew;
int players;
int maxTurns;
char type;


int main() {

    cout << "Boxes in the board: " << endl;
    cin >> boxes;
    cout << "Snakes: " << endl;
    cin >> snakes;
    cout << "Ladders: " << endl;
    cin >> ladders;
    cout << "Penalty: " << endl;
    cin >> pen;
    cout << "Reward: " << endl;
    cin >> rew;
    cout << "Number of players: " << endl;
    cin >> players;
    cout << "Maximum turns: " << endl;
    cin >> maxTurns;
    cout << "Type of game" << endl << "'A' for automatic" << endl << "'M' for manual" << endl;
    cin >> type;

    if (type == 'A'){
        Automatico juego(boxes, players, maxTurns, snakes, ladders, pen, rew);
        juego.start();
    }
    else {
        Manual juego(boxes, players, maxTurns, snakes, ladders, pen, rew);
        juego.start();
    }


    //Tablero board(30, 3, 3);

    return 0;
}
