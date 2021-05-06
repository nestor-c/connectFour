#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include <stdlib.h>
#include <time.h>
#include <string>

class Game {
    private:
        bool win=false;
        char currPlayer;
        Board gameBoard;
        void checkHorizontalWin();
        void checkVerticalWin();
        void checkDiagonalWin();
        void checkWin();
    public:
        Game();
        const char player1 = 'X';
        const char player2 = 'T';
        // ~Game();
        void displayGame();
		void dropChip(int,char);
        char choosePlayer();
        void assignPlayer(char player);
        };
#endif