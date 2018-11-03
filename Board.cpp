#include "Board.h"

Board::Board(int h, int w){
    height = h;
    width = w;
    
	grid = new int*[height];

    for (int i=0;i<height;++i){
        grid[i] = new int[width];
    }
	/* 			
				[
				 const=> [0][1][2][3][4][5][6]    
		grid=>	 const=> [0][1][2][3][4][5][6] 
				 const=> [0][1][2][3][4][5][6] 
				 const=> [0][1][2][3][4][5][6] 
				 const=> [0][1][2][3][4][5][6] 
				 ]
	*/

	//std::cout << "Height: " << height << " " << "Width: " << width << std::endl;

    for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			grid[i][j] = 0;
        }
    }
};

void Board::pileChips(int col, int player){
	if (grid != NULL && (player == 1 || player == 2)){
		if (grid[0][col] != 0) {
			std::cout << "Column full. Choose another column." << std::endl;
		}
		for(int i= height-1; i >= 0 ; i--){
			if (grid[i][col] != 0) continue;
			else {
				grid[i][col] = player;
				break;
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
int Board::display(int r, int c){
    return grid[r][c];
}
int Board::_H(){ return height;}
int Board::_W(){ return width;}