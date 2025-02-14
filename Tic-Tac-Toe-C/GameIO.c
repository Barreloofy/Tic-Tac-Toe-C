
#include "GameIO.h"


void printBoard(Mark* board) {
    int i;
    printf("\n");
    for (i = 1; i <= 9; i++) {
        char mark = markToChar(board[i - 1]);
        if (i % 3 == 0) {
            if (mark == ' ') {
                printf("| %d |\n", i);
            } else {
                printf("| %c |\n", mark);
            }
            continue;
        }
        if (mark == ' ') {
            printf("| %d |", i);
        } else {
            printf("| %c |", mark);
        }
    }
    printf("\n");
}

void playerInput(Game* game) {
    int input;
    if (game->turnCount % 2 == 0) {
        printf("It's Player X's turn: ");
    }
    else {
        printf("It's Player O's turn: ");
    }
    scanf("%d", &input);
    if (input >= 1 && input <= 9) {
        updateBoard(game, input - 1);
    }
}

void printResult(Result result) {
    switch (result) {
        case XWon:
            printf("Player X won this match!\n");
            break;
        case OWon:
            printf("Player O won this match!\n");
            break;
        case Draw:
            printf("It's a Draw!\n");
            break;
        case inProgress:
            break;
    }
}
