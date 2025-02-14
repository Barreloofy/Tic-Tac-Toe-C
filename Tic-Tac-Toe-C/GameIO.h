
#ifndef GAMEIO_H
#define GAMEIO_H

#include <stdio.h>
#include "GameData.h"
#include "GameLogic.h"

void printBoard(Mark board[9]);

void playerInput(Game* game);

void printResult(Result result);

#endif
