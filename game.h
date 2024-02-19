#include "board.h"
#include "drawing.h"

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

bool isOver(Board *board);
char getPlayerMark();
void playerTurn(Board *board, char playerMark);
void computerTurn(Board *board, char computerMark);

#endif // GAME_H_INCLUDED
