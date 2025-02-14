
#include <stdio.h>
#include "GameData.h"
#include "GameIO.h"


int main(void) {
    Game game = gameCreate();
    Result gameResult = inProgress;
    printWelcome();
    printBoard(game.board);
    while (gameResult == inProgress) {
        playerInput(&game);
        printBoard(game.board);
        gameResult = checkForWinner(&game);
    }
    printResult(gameResult);
}
