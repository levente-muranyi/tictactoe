#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "drawing.h"
#include "game.h"

int main()
{
    Board *game = initBoard();
    char playerMark = getPlayerMark();
    while(!isOver(game)) {
        playerTurn(game, playerMark);
        if(playerMark == 'X') computerTurn(game, 'O');
        else computerTurn(game, 'X');
        draw(game);
    }
    return 0;
}
