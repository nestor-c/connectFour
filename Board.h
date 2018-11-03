#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>

class Board {   
  
    private:
        int height;
        int width;
        int gridSize = height * width;
        int** grid;
    public:
        Board(int h=6,int w=7);
        ~Board();
        int getGridSize();
        int _H();
        int _W();
        int display(int, int);
		void changeValue(int,int);
		void pileChips(int, int);      
};
#endif