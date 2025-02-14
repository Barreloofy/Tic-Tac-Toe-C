
#include <stdio.h>
#include <string.h>
#include "GameData.h"
#include "GameIO.h"


int main(void);

int startGame(void);

void cleanInputStream(void);

int main(void) {
    printf("Welcome to the CLI Tic-Tac-Toe Game!\n");
    while (1) {
        Game game = gameCreate();
        Result gameResult = inProgress;
        if (startGame() != 0) { break; }
        printBoard(game.board);
        while (gameResult == inProgress) {
            playerInput(&game);
            printBoard(game.board);
            gameResult = checkForWinner(&game);
        }
        printResult(gameResult);
        cleanInputStream();
    }
}


int startGame(void) {
    while (1) {
        char startInput[4];
        printf("Begin a new game of Tic Tac Toe? (yes/no): ");
        fgets(startInput, 4, stdin);
        startInput[strcspn(startInput, "\n")] = 0;
        if (strcmp(startInput, "yes") == 0) {
            printf("Game Begins 3..2..1 Go!\n");
            return 0;
        }
        else if (strcmp(startInput, "no") == 0) {
            char exitInput[4];
            printf("Exit program? (yes/no): ");
            fgets(exitInput, 4, stdin);
            if (strcmp(exitInput, "yes") == 0) {
                return 1;
            }
            else { continue; }
        }
        else { continue; }
    }
}

void cleanInputStream(void) {
    char character;
    while ((character = getchar()) != '\n' && character != EOF) {};
}
