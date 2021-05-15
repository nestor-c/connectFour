#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <utility>

class Board {   
  
    private:
        int height;
        int width;
        int gridSize;
        char** grid;
        std::pair <int,int> lastMove;
        
    public:
        bool checkFull(int);
        Board(int h=6,int w=7);
        ~Board();
        int getGridSize();
        int _H();
        int _W();
        int displayPosition(int, int);
		void changeValue(int,int);
		void pileChips(int, char);      
        void printBoard();
        void displayOptions();
        std::pair<int, int> showLastMove();
};
#endif
