#include <stdbool.h>

#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

typedef struct {
    char playerMark;
    bool isOccupied;
} Field;


typedef struct {
    Field *fields;
} Board;

void updateField(Board *board, int fieldNumber, char newPlayerMark);

#endif // BOARD_H_INCLUDED
