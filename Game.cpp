#include "Game.h"

Game::Game(){
    displayGame();
};

// Game::~Game(){
   
// };

void Game::displayGame(){
    for(int i=0;i<gameBoard._H();i++){
		if (i>=0) std::cout << std::endl;
        for(int j=0;j<gameBoard._W();j++){
            std::cout << gameBoard.display(i,j) << " ";
        }
    }  
}

void Game::dropChip(int row, int col, int player){
}

