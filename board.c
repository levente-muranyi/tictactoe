#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "drawing.h"

void updateField(Board *board, int fieldNumber, char newPlayerMark) {
    if(!board->fields[fieldNumber].isOccupied) {
        board->fields[fieldNumber].playerMark = newPlayerMark;
        board->fields[fieldNumber].isOccupied = true;
    }
}

Board *initBoard() {
    Board *gameBoard = (Board *)malloc(sizeof(Board));
    gameBoard->fields = (Field *)malloc(9 * sizeof(Field));
    for(int i = 0; i <= sizeof(gameBoard->fields); i++) {
        gameBoard->fields[i].isOccupied = false;
        gameBoard->fields[i].playerMark = ' ';
    }
    return gameBoard;
}
