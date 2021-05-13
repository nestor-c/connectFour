#include "Game.h"
Game::Game(){
   play();
   mainLoop();
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

    return; 
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

void Game::checkWin(char player, int row, int col){
    checkHorizontalWin(currPlayer);
    checkVerticalWin(currPlayer);
    checkDiagonalWin(currPlayer, row, col);
} 

void Game::checkHorizontalWin(char player){
    for (int i = 0; i< gameBoard._H(); i++){
        int count = 0;
        for (int j = 0; j<gameBoard._W()-1;j++){
            gameBoard.displayPosition(i,j) == player ? ++count : count = 0;
        }
        if (count == 4) win = true;
    }
};
void Game::checkVerticalWin(char player){
    for (int j = 0; j< gameBoard._W(); j++){
        for (int i = 0; i < gameBoard._H(); i++){
            int count = 0;
            gameBoard.displayPosition(i,j) == player ? ++count : count = 0;
            if (count == 4) win = true;
        }
    }
};



void Game::checkDiagonalWin(char player, int row, int col){
    int count = 1;
    //forward, up
    if (row != 0 && col != gameBoard._W()){
        for (int i = row-1, j = col+1;i>=0 && j<gameBoard._W(); i--, j++){
            if  (gameBoard.displayPosition(i,j) == player)  ++count; else count = 1;
            if (count == 4){ win = true; break;}
        }
    }
    //Backward, down
    if (col != 0 && row != gameBoard._H()){
        for (int i = row+1, j = col-1;i<gameBoard._H() && j>=0; i++, j--){
            if  (gameBoard.displayPosition(i,j) == player)  ++count; else count = 1;
            if (count == 4){ win = true; break;}
        }   
    }
    count = 1;
    //Backward, up
    if (row != 0 && col != 0){
        for (int i = row-1, j = col-1;i>=0 && j>=0; i--, j--){
            if  (gameBoard.displayPosition(i,j) == player)  ++count; else count = 1;
            if (count == 4){ win = true; break;}
        }
    }
    //Forward, down
    if (row != gameBoard._H() && col != gameBoard._W()){
        for (int i = row+1, j = col+1;i<gameBoard._H() && j<gameBoard._W(); i++, j++){
            if  (gameBoard.displayPosition(i,j) == player)  ++count; else count = 1;
            if (count == 4){ win = true; break;}
        }
    }
};



void Game::play(){
     currPlayer = choosePlayer();
    int playerNumber;
    
    currPlayer == 'X' ? playerNumber = 1:playerNumber=2;  
    std::cout <<  "Welcome to connect four! Connect four of the same tokens vertically, horizontally, or diagonally and win!" << std::endl << std::endl;
    std::cout << "Player " << playerNumber << " goes first!" << std::endl << std::endl;
    gameBoard.printBoard();
}

void Game::mainLoop(){
    int playerNumber;
    int playerChoice;

     while(!win){
        currPlayer == 'X'? playerNumber = 1:playerNumber=2;
        std::cout << "Player("<< currPlayer <<") "<< playerNumber << ": "<< std::endl;
        std::cout << "Choose a column from the available options. Anything with a \'0\' is an open spot" << std::endl;
        std::cin >> playerChoice;
        dropChip(playerChoice, currPlayer);
        
        checkWin(currPlayer,gameBoard.showLastMove().first, gameBoard.showLastMove().second);
        
    }
}

