#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include <string>

class Game {
    private:
        std::string player1 = "R";
        std::string player2 = "B"; 
        Board gameBoard;
    public:
        Game();
        // ~Game();
        void displayGame();
		void dropChip(int,int,int);
};
#endif