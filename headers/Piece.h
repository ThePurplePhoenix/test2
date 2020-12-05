//
// Created by shinj on 12/2/2020.
//

#ifndef CHESSGAME_PIECE_H
#define CHESSGAME_PIECE_H

#include "../headers/Board.h"

#include <string>
#include <iostream>
#include "Board.h"
#include "GameManager.h"

class Board;

using namespace std;

class Piece {
public:
    virtual bool getColor() = 0;
    virtual bool movement(int new_x, int new_y, Board* board) = 0;
    int getPosX(){return curr_x;}
    int getPosY(){return curr_y;}
    void setPosX(int input){ curr_x = input;}
    void setPosY(int input){ curr_y = input;}
    string getName(){return name;}

protected:
    int curr_x ;
    int curr_y ;
    string name;
    bool white;
};



class Pawn: public Piece {
private:
    bool firstMove;

public:
    bool getColor() override ; //true is white and false is black
    Pawn(int posX, int posY, bool white, string name);
    bool movement(int new_x, int new_y, Board* board) override ;

};


#endif //CHESSGAME_PIECE_H
