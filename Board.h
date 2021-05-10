#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>

class Board {   
  
    private:
        int height;
        int width;
        int gridSize = height * width;
        char** grid;
    public:
        Board(int h=6,int w=7);
        ~Board();
        int getGridSize();
        int _H();
        int _W();
        int displayPosition(int, int);
		void changeValue(int,int);
		int* pileChips(int, char);      
        void printBoard();
        void displayOptions();
};
#endif