#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include <stdlib.h>
#include <time.h>
#include <string>
#include <utility>

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
        void checkWin(char player,int row, int col);
    public:
        Game();
        const char player1 = 'X';
        const char player2 = 'T';
        // ~Game();
        void displayGame();
		void dropChip(int,char);
        char choosePlayer();
        void assignPlayer(char player);
        void play();
        };
        
#endif