#include "Game.h"
Game::Game(){
    currPlayer = choosePlayer();
    int playerNumber;
    int playerChoice;


    currPlayer == 'X' ? playerNumber = 1:playerNumber=2;  
    std::cout <<  "Welcome to connect four! Connect four of the same tokens vertically, horizontally, or diagonally and win!" << std::endl << std::endl;
    std::cout << "Player " << playerNumber << " goes first!" << std::endl << std::endl;

    gameBoard.printBoard();

    while(!win){
        currPlayer == 'X'? playerNumber = 1:playerNumber=2;
        std::cout << "Player("<< currPlayer <<") "<< playerNumber << ": "<< std::endl;
        std::cout << "Choose a column from the available options. Anything with a \'0\' is an open spot" << std::endl;
        std::cin >> playerChoice;
        dropChip(playerChoice, currPlayer);
        checkWin();
    }
};

// Game::~Game(){
   
// };

void Game::displayGame(){
   gameBoard.printBoard();
}

void Game::dropChip(int col, char player){ 
    gameBoard.pileChips(col,player);
    gameBoard.printBoard();
    player == 'X' ? currPlayer = 'T': currPlayer = 'X';
}   

char Game::choosePlayer(){
    srand(time(NULL));
    int chosen = rand() % 2 + 1;
    chosen == 1 ? currPlayer = 'X': currPlayer = 'T'; 
    return currPlayer;
}

void Game::assignPlayer(char player){
    currPlayer = player;
}

void Game::checkWin(){
    checkHorizontalWin();
    checkVerticalWin();
    checkDiagonalWin();
} 
void Game::checkHorizontalWin(char player){
    for (int i = 0; i< gameBoard._H(); i++){
        for (int j = 0; j<gameBoard._W()-1;j++){
            grid[i][j] == grid[i][j+1]
        }
    }
};
void Game::checkVerticalWin(){};
void Game::checkDiagonalWin(){};
