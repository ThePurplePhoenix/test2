//
// Created by shinj on 12/4/2020.
//

#include "../headers/Board.h"
#include <string>

using namespace std;


bool Board::isFree(int x, int y){
    if(vectorBoard[x][y] == nullptr )
        return true;
    else
        return false;
}

bool Board::isFoe(int x, int y, int new_x, int new_y) {
    if(vectorBoard[x][y]->getColor() == true && vectorBoard[new_x][new_y]->getColor() == false){ //white
        return true;
    } else if(vectorBoard[x][y]->getColor() == false && vectorBoard[new_x][new_y]->getColor() == true){ //black
        return true;
    } else return false;

}


void Board::setEmptyBoard(){
    for(int i=0; i<8; i++){
        vectorBoard.push_back(vector<Piece*>());
        for(int j=0;j<8;j++){
            vectorBoard.at(i).push_back(nullptr);
        }
    }
}

// vectorBoard
Board::Board(){
    setEmptyBoard();
    /*
    Piece* WR1 = new Rook(true);
    Piece* WK1 = new Knight(true);
    Piece* WB1 = new Bishop(true);
    Piece* WK = new King(true);
    Piece* WQ = new Queen(true);
    Piece* WB2 = new Bishop(true);
    Piece* WK2 = new Knight(true);
    Piece* WR2 = new Rook(true);


    vectorBoard.at(0).at(7) = WR1;
    vectorBoard.at(1).at(7) = WK1;
    vectorBoard.at(2).at(7) = WB1;
    vectorBoard.at(3).at(7) = WK;
    vectorBoard.at(4).at(7) = WQ;
    vectorBoard.at(5).at(7) = WB2;
    vectorBoard.at(6).at(7) = WK2;
    vectorBoard.at(7).at(7) = WR2;
    */

    Piece* WP0 = new Pawn(0 , 6, true, "WP");
    vectorBoard[0][6] = WP0;

    Piece* WP1 = new Pawn(1 , 6, true, "WP");
    vectorBoard[1][6] = WP1;

    Piece* WP2 = new Pawn(2 , 6, true, "WP");
    vectorBoard[2][6] = WP2;

    Piece* WP3 = new Pawn(3 , 6, true, "WP");
    vectorBoard[3][6] = WP3;

    Piece* WP4 = new Pawn(4 , 6, true, "WP");
    vectorBoard[4][6] = WP4;

    Piece* WP5 = new Pawn(5 , 6, true, "WP");
    vectorBoard[5][6] = WP5;

    Piece* WP6 = new Pawn(6 , 6, true, "WP");
    vectorBoard[6][6] = WP6;

    Piece* WP7 = new Pawn(7 , 6, true, "WP");
    vectorBoard[7][6] = WP7;


    /*
    Piece* BR1 = new Rook(false);
    Piece* BK1 = new Knight(false);
    Piece* BB1 = new Bishop(false);
    Piece* BK = new King(false);
    Piece* BQ = new Queen(false);
    Piece* BB2 = new Bishop(false);
    Piece* BK2 = new Knight(false);
    Piece* BR2 = new Rook(false);

    vectorBoard.at(0).at(0) = BR1;
    vectorBoard.at(1).at(0) = BK1;
    vectorBoard.at(2).at(0) = BB1;
    vectorBoard.at(3).at(0) = BK;
    vectorBoard.at(4).at(0) = BQ;
    vectorBoard.at(5).at(0) = BB2;
    vectorBoard.at(6).at(0) = BK2;
    vectorBoard.at(7).at(0) = BR2;
    */

    Piece* BP0 = new Pawn(0 , 1, false, "BP");
    vectorBoard[0][1] = BP0;

    Piece* BP1 = new Pawn(1 , 1, false, "BP");
    vectorBoard[1][1] = BP1;

    Piece* BP2 = new Pawn(2 , 1, false, "BP");
    vectorBoard[2][1] = BP2;

    Piece* BP3 = new Pawn(3 , 1, false, "BP");
    vectorBoard[3][1] = BP3;

    Piece* BP4 = new Pawn(4 , 1, false, "BP");
    vectorBoard[4][1] = BP4;

    Piece* BP5 = new Pawn(5 , 1, true, "BP");
    vectorBoard[5][1] = BP5;

    Piece* BP6 = new Pawn(6 , 1, true, "BP");
    vectorBoard[6][1] = BP6;

    Piece* BP7 = new Pawn(0 , 6, true, "BP");
    vectorBoard[7][1] = BP7;

        //Piece* BP = new Pawn(false);
        //vectorBoard.at(i).at(6) = BP;
}



void Board::print(){
    string border = "  |----|----|----|----|----|----|----|----|";
    string bound = "  =========================================";
    cout << bound << endl;
    for(int y=0;y<8;y++){
        cout << y << " | ";
        for(int x=0;x<8;x++){
            if(vectorBoard.at(x).at(y) != nullptr){
                cout << vectorBoard[x][y]->getName();
            }else{
                cout << "  ";
            }
            cout << " | ";
        }
        cout << endl;
        if(y < 7)
            cout << border << endl;
    }
    cout << bound << endl;
    cout << "    ";
    for(int i=0; i< 8;i++){
        cout << i << "    ";
    }
}

void Board::updateBoard(int newX, int newY, Piece* movePiece){
    int temp,temp2;
    temp = movePiece->getPosX();
    temp2 = movePiece->getPosY();

    movePiece->setPosX(newX);
    movePiece->setPosY(newY);

    vectorBoard.at(newX).at(newY) = movePiece;
    vectorBoard.at(temp).at(temp2) = nullptr;
}

vector<vector<Piece *>> Board::getBoard() {
    return vectorBoard;
}

