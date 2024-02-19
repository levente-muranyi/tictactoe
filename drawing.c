#include <stdio.h>
#include "board.h"
#include "game.h"

void draw(Board *board) {
    puts("------");
    for(int i = 0; i <= sizeof(board->fields); i++) {
        printf("%c|", board->fields[i].playerMark);
        if((i + 1) % 3 == 0) puts("\n------");
    }
}
