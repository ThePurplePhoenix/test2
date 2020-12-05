//
// Created by shinj on 12/2/2020.
//

#ifndef CHESSGAME_GAMEMANAGER_H
#define CHESSGAME_GAMEMANAGER_H

#include "../headers/Board.h"
#include "../headers/Pawn.h"

using namespace std;

class Board;

class Pawn;

// singleton-based object which will manage who's turn it is, as well as keep track of status of game
class GameManager {
private:
    Board* gameboard;
    bool isWhiteTurn;
    bool gameIsOver;
    //Piece* pieces;
    Pawn* pawn;
    bool whiteIsInCheck;
    bool blackIsInCheck;

public:
    GameManager();

    void startGame();

    // implementation still required for next sprint, currently pseudo-code for logic of how to have turn-based system
    void move();
    bool isValidSelectPiece(int startX, int startY);
};



#endif //CHESSGAME_GAMEMANAGER_H
