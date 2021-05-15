#include "Game.h"

Game::Game(){
    player1 = 'X';
    player2 = 'T';
    win = false;
    play();
    mainLoop();
}

/* Game::~Game(){
   
}; */

void Game::displayGame(){
   gameBoard.printBoard();
}

void Game::dropChip(int col, char player){ 
    gameBoard.pileChips(col,player);
    gameBoard.printBoard();
    return ; 
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
    if (checkHorizontalWin() || checkVerticalWin() || checkDiagonalWin())
        win = true; 
} 

bool Game::checkHorizontalWin(){ 
    int row = gameBoard.showLastMove().first;
    int count = 0;
    for (int i=0;i<gameBoard._W();i++){
        if (gameBoard.displayPosition(row ,i) == currPlayer){
            ++count;
            if (count == 4) {
                std::cout << currPlayer << " horizontal win!" << std::endl;
                return true;
            }
        } else {
            count = 0;
        }
    }
    return false;
}

bool Game::checkVerticalWin(){
    int count = 1;
    for (int i=gameBoard._H()-1;i>gameBoard.showLastMove().first;i--){
        if (gameBoard.displayPosition(i,gameBoard.showLastMove().second) == currPlayer){
            ++count;
            if (count == 4){
                std::cout << "Vertical win for " << currPlayer << "! " << std::endl;
                return true;
            }
        } else {
            count = 1;
        }
    }
   return false;
}

bool Game::checkDiagonalWin(){
    int row = gameBoard.showLastMove().first;
    int col = gameBoard.showLastMove().second;
   
    int count = 1;
    //forward, up
    if (row != 0 && col != gameBoard._W()-1){
        for (int i = row-1, j = col+1;i>=0 && j<gameBoard._W(); i--, j++){
            if  (gameBoard.displayPosition(i,j) == currPlayer) {
                ++count;
                if (count == 4){ 
                    std::cout << " Diagonal win!" << std::endl;
                    return true;
                }
            }
            else count = 1;
        }
    }
    //Backward, down
    if (col != 0 && row != gameBoard._H()){
        for (int i = row+1, j = col-1;i<gameBoard._H() && j>=0; i++, j--){
            if  (gameBoard.displayPosition(i,j) == currPlayer) {
            ++count; 
                if (count == 4){ 
                    std::cout << " Diagonal win!" << std::endl;
                    return true;
                }
            }
            else count = 1;  
        }   
    }

    count = 1;
    //Backward, up
    if (row != 0 && col != 0){
        for (int i = row-1, j = col-1;i>=0 && j>=0; i--, j--){
            if  (gameBoard.displayPosition(i,j) == currPlayer){
              ++count; 
                if (count == 4){ 
                    std::cout << " Diagonal win!" << std::endl;
                    return true;
                }
            }
            else count = 1; 
        }
    }
    //Forward, down
    if (row != gameBoard._H()-1  && col != gameBoard._W()-1){
        for (int i = row+1, j = col+1;i<gameBoard._H() && j<gameBoard._W(); i++, j++){
            if  (gameBoard.displayPosition(i,j) == currPlayer){ 
                ++count;
                if (count == 4){ 
                    std::cout << " Diagonal win!" << std::endl;
                    return true;
                }
            }
            else count = 1;    
        }
    }
    return false;
}

void Game::play(){
    currPlayer = choosePlayer();
    currPlayer == 'X' ? playerNumber = 1:playerNumber=2;  
    
    std::cout <<  "Welcome to connect four! Connect four of the same tokens vertically, horizontally, or diagonally and win!" << std::endl << std::endl;
    std::cout << "Player " << playerNumber << " goes first!" << std::endl << std::endl;
    gameBoard.printBoard();
}

int Game::takeInput(){
        currPlayer == 'X'? playerNumber = 1:playerNumber=2;
        int playerChoice;
        std::cout << "Player("<< currPlayer <<") "<< playerNumber << ": "<< std::endl;
        std::cout << "Choose a column from the available options. Anything with a \'0\' is an open spot" << std::endl;
        std::cin >> playerChoice;
        return playerChoice;
}

void Game::mainLoop(){ 
     while(!win){
        int playerChoice = takeInput();
        currPlayer == 'X'? playerNumber = 1:playerNumber=2;

        //Continue taking input until a valid option is chosen
        while(gameBoard.checkFull(playerChoice)){
            playerChoice = takeInput();
            gameBoard.printBoard();
        }
        dropChip(playerChoice, currPlayer);  
        checkWin();
        currPlayer == 'X' ? currPlayer = 'T': currPlayer = 'X';
    }
}

