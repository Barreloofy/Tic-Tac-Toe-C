
#include "GameData.h"


Game gameCreate(void) {
    Game game;
    int i;
    for (i = 0; i < 9; i++) {
        game.board[i] = empty;
    }
    game.turnCount = 0;
    return game;
}

char markToChar(Mark mark) {
    switch (mark) {
        case X:
            return 'X';
        case O:
            return 'O';
        case empty:
            return ' ';
    }
}
