
#include "GameLogic.h"


Result checkForWinner(Game* game) {
    Result result = checkRow(game->board);
    if (result != inProgress) { return result; }
    result = checkColumn(game->board);
    if (result != inProgress) { return result; }
    result = checkDiagonal(game->board);
    if (result != inProgress) { return result; }
    if (game->turnCount == 9) { return Draw; }
    return result;
}

Result checkRow(Mark board[9]) {
    int i;
    for (i = 0; i <= 6; i += 3) {
        if (board[i] == empty) { continue; }
        if (board[i] == board[i + 1] && board[i] == board[i + 2]) {
            return board[i] == X ? XWon : OWon;
        }
    }
    return inProgress;
}

Result checkColumn(Mark board[9]) {
    int i;
    for (i = 0; i <= 2; i++) {
        if (board[i] == empty) { continue; }
        if (board[i] == board[i + 3] && board[i] == board[i + 6]) {
            return board[i] == X ? XWon : OWon;
        }
    }
    return inProgress;
}

Result checkDiagonal(Mark board[9]) {
    if (board[0] == board[4] && board[0] == board[8]) {
        if (board[0] == empty) { return inProgress; }
        return board[0] == X ? XWon : OWon;
    }
    if (board[2] == board[4] && board[2] == board[6]) {
        if (board[2] == empty) { return inProgress; }
        return board[2] == X ? XWon : OWon;
    }
    return inProgress;
}

void updateBoard(Game* game, int move) {
    if (game->board[move] != empty) { return; }
    game->board[move] = game->turnCount % 2 == 0 ? X : O;
    game->turnCount ++;
}
