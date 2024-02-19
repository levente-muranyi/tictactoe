#include <stdbool.h>
#include <time.h>
#include "board.h"

bool isOver(Board *board) {
    for(int i = 0; i < sizeof(board->fields); i += 3) {
        if(board->fields[i].isOccupied && board->fields[i+1].isOccupied && board->fields[i+2].isOccupied && board->fields[i].playerMark == board->fields[i+1].playerMark && board->fields[i+1].playerMark == board->fields[i+2].playerMark)
            return true;
    }

    for(int i = 0; i < 3; i++) {
        if(board->fields[i].isOccupied && board->fields[i+3].isOccupied && board->fields[i+6].isOccupied && board->fields[i].playerMark == board->fields[i+3].playerMark && board->fields[i+3].playerMark == board->fields[i+6].playerMark)
            return true;
    }

    if(board->fields[0].isOccupied && board->fields[4].isOccupied && board->fields[8].isOccupied && board->fields[0].playerMark == board->fields[4].playerMark && board->fields[4].playerMark == board->fields[8].playerMark)
            return true;

    else if(board->fields[2].isOccupied && board->fields[4].isOccupied && board->fields[6].isOccupied && board->fields[2].playerMark == board->fields[4].playerMark && board->fields[4].playerMark == board->fields[6].playerMark)
            return true;

    return false;
}

char getPlayerMark() {
    char playerMark = ' ';
    printf("X/O: ");
    scanf("%c", &playerMark);
    return playerMark;
}

void playerTurn(Board *board, char playerMark) {
    if(playerMark != ' ' && !isOver(board)) {
        int fieldNumber;
        printf("\nPlayer: ");
        scanf("%d", &fieldNumber);
        if(!board->fields[fieldNumber-1].isOccupied && fieldNumber >= 1 && fieldNumber <= 9) updateField(board, fieldNumber-1, playerMark);
        else playerTurn(board, playerMark);
    }
}

void computerTurn(Board *board, char computerMark) {
    if(!isOver(board)) {
        time_t t;
        srand((unsigned) time(&t));
        int fieldNumber = rand() % 9;
        while(board->fields[fieldNumber].isOccupied) fieldNumber = rand() % 9;
        printf("Computer: %d\n\n", fieldNumber + 1);
        updateField(board, fieldNumber, computerMark);
    }
}
