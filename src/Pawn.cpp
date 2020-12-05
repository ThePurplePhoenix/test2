//
// Created by shinj on 12/2/2020.
//

#include "../headers/Piece.h"
#include "../headers/Pawn.h"


using namespace std;

//true is white false is black
bool Pawn::getColor() {
    return white;
}

/*
void Pawn::print() {
    cout << name.substr(0, name.size()-1) << endl;
}*/

//create pawn
Pawn::Pawn(int posX, int posY, bool color,string input){
    curr_x = posX;
    curr_y = posY;
    white = color;
    name = input;
}


//verify that movement is valid
bool Pawn::movement(int new_x, int new_y, Board* board) {

    if(white) {
        //WHITE CASES
        if (new_x == curr_x && new_y == curr_y - 1 && board->isFree(new_x, new_y)) {
            return true;
        } else {
            return false;
        }
    } else {
        //BLACK CASES
        if (new_x == curr_x && new_y == curr_y + 1 && board->isFree(new_x, new_y)) {
            return true;
        } else {
            return false;
        }
    }

    /*
    if(new_y == 8 && board->isFree(new_x, new_y) && curr_y + 1 == new_y && new_x == curr_x) {
        //pawnupgrade(); //implement this later
        return true;
    } else if (curr_y + 1 == new_y && board->isFree(new_x, new_y) ) {
        return true;
    } else if (curr_y + 1 == new_y && !board->isFree(new_x, new_y) && ( curr_x + 1 == new_x || curr_x - 1 == new_x )){
        if(!board->isFree(new_x, new_y) && board->isFoe( curr_x, curr_y ,new_x, new_y)){
            //capturepiece();// implement later
            return true;
        } else {
            return false;
        }
        //return true;
    } else {
        return false;
    }*/
}

