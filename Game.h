#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include <stdlib.h>
#include <time.h>
#include <string>
#include <utility>

class Game {
    private:
        bool win;
        char currPlayer;
        int playerNumber;
        Board gameBoard;
        void mainLoop();
        void checkPlayerChoice();
        bool checkHorizontalWin();
        bool checkVerticalWin();
        bool checkDiagonalWin();
        void checkWin();
        int  takeInput();
    public:
        Game();
        char player1;
        char player2;
        // ~Game();
        void displayGame();
		void dropChip(int,char);
        char choosePlayer();
        void assignPlayer(char player);
        void play();
        };
        
#endif
