
#ifndef GAMEDATA_H
#define GAMEDATA_H


typedef enum Mark {
    X,
    O,
    empty
} Mark;

typedef struct Game {
    enum Mark board[9];
    int turnCount;
} Game;

struct Game gameCreate(void);

char markToChar(enum Mark mark);

#endif
