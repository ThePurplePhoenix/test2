//
// Created by shinj on 12/2/2020.
//

#include "../headers/GameManager.h"

GameManager::GameManager(){
    isWhiteTurn = true;  // white gets first move
    gameboard = new Board(); // initialize gameboard with default pieces & positions
    gameIsOver = false;  //game has just begun
    whiteIsInCheck = false;
    blackIsInCheck = false;
}

void GameManager::startGame(){
    while(!gameIsOver){
        gameboard->print();
        move();
    }
}

void GameManager::move() {
    Piece* pieceToMove=nullptr;
    int xPos=0;
    int yPos=0;


    // user indicates desired piece to move on board
    do{
        cout << "Select Piece: (x,y) " << endl;
        cin >> xPos >> yPos;
    }
    while(!isValidSelectPiece(xPos, yPos));

    pieceToMove = gameboard->getBoard()[xPos][yPos];


    int newX=0;
    int newY=0;
    // user indicates desired place on board to move
    do{
        cout << "Where do you wish to move: (x,y) "<< endl;
        cin >> newX >> newY;
    }
    while(!pieceToMove->movement(newX, newY, gameboard));

    // update board
    gameboard->updateBoard(newX, newY, pieceToMove);
    if(isWhiteTurn){
        isWhiteTurn=false;
    }else{
        isWhiteTurn =true;
    }
}

// when we implement actual "checks", we will need to include
// limitations and more conditionals within move()

bool GameManager::isValidSelectPiece(int startX, int startY){
    // out of bounds
    if(startX > 7 || startX < 0 || startY > 7 || startY < 0){
        return false;
    }
    // no piece exists at location
    if(gameboard->getBoard().at(startX).at(startY) == nullptr){
        return false;
    }

    // cannot move opponents pieces
    Piece* selectPiece = gameboard->getBoard().at(startX).at(startY);

    if(isWhiteTurn && !selectPiece->getColor()){
        return false;
    }
    else if(!isWhiteTurn && selectPiece->getColor()){
        return false;
    }

    // piece has no possible moves
    /*
    if(!selectPiece.hasPossibleMoves()){
        return false;
    }
    */

    return true;
}