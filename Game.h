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
        void mainLoop();
        void checkPlayerChoice();
        void checkHorizontalWin(char player);
        void checkVerticalWin(char player);
        void checkDiagonalWin(char player, int,int);
        void checkWin(int*);
    public:
        Game();
        const char player1 = 'X';
        const char player2 = 'T';
        // ~Game();
        void displayGame();
		int* dropChip(int,char);
        char choosePlayer();
        void assignPlayer(char player);
        void play();
        };
        
#endif