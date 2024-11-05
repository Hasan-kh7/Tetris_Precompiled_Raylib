#ifndef TETROMINO_H
#define TETROMINO_H

#include "raylib.h" 
#include "Colors.h"
#include "Grid.h"
#include "Position.h"

#include <vector>
#include <map>


class Tetromino {
public:
	Tetromino();
	void drawTetromino(int offSetX , int offSetY);
	void Move(int rows , int cols);
	std::vector<Position> GetCellsPositions();
	void rotateTetromino();
	void undoRotateTetromino();
	int id;
	std::map<int, std::vector<Position>> cells;
private:
	int rowOffSet;
	int colOffSet;
	int rotationState;
	int cellSize;
	
	std::vector<Color> blockColors;
	

};
#endif // !TETROMINO_H
