
#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "GameData.h"

typedef enum Result {
    XWon,
    OWon,
    Draw,
    inProgress
} Result;

Result checkForWinner(Game* game);

Result checkRow(Mark board[9]);

Result checkColumn(Mark board[9]);

Result checkDiagonal(Mark board[9]);

void updateBoard(Game* game, int move);

#endif
