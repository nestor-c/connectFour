#include "Board.h"
#include <iomanip>
Board::Board(int h, int w):height(h),width(w){
	grid = new char*[height];

    for (int i=0;i<height;i++){
        grid[i] = new char[width];
    }

	//Initiallize grid
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			grid[i][j] = '0';
		}
    }

};
int* Board::pileChips(int col, char player){
	int coords[2];
	if (grid != NULL && (player == 'X' || player == 'T')){
		if(grid[0][col] != '0') {
			std::cout << "Column full. Choose another column." << std::endl;
		}
		for(int i= height-1; i >= 0 ; i--){
			if (grid[i][col] != '0') continue;
			else {
				grid[i][col] = player;
				coords[0] = i; // Rows
				coords[1] = col; // Col
				return coords;
			}
		}
	}
}
Board::~Board(){
    for (int i=0;i<height;i++){
        delete[] grid[i];
    }
    delete grid;
}
int Board::getGridSize(){
    return gridSize;
}
int Board::displayPosition(int r, int c){
    return grid[r][c];
}
int Board::_H(){ return height;}
int Board::_W(){ return width;}
void Board::printBoard(){	
	displayOptions();
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			std::cout << grid[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
void Board::displayOptions(){
	std::cout << "Your options: " <<std::endl;
	for (int i = 0; i < width; i++){
		grid[0][i] == '0' ? std::cout << i << " " : std:: cout << "  ";
	}	
	std::cout << std::endl << std::endl;
}