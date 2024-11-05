#include "Tetromino.h"



Tetromino::Tetromino()
	:cellSize(grid::CELL_SIZE),rotationState(0),blockColors(Colors::Colors)
	,rowOffSet(0),colOffSet(0)
{
	
}
void Tetromino::drawTetromino(int offSetX , int offSetY)
{
	std::vector<Position> tiles = GetCellsPositions();
	for(Position item: tiles)
	{
		DrawRectangle(item.col * cellSize + offSetX,item.row*cellSize + offSetY,cellSize-1,cellSize-1,blockColors[id]);
	}
}

void Tetromino::Move(int rows, int cols)
{
	rowOffSet += rows;
	colOffSet += cols;
}

std::vector<Position> Tetromino::GetCellsPositions()
{
	const std::vector<Position> tiles = cells[rotationState];
	std::vector<Position> movedTiles;
	movedTiles.reserve(tiles.size());
	for(Position item : tiles)
	{
		movedTiles.emplace_back(item.row + rowOffSet, item.col + colOffSet);
	}
	return movedTiles;
}

void Tetromino::rotateTetromino()
{
	rotationState++;
	if (rotationState == (cells.size()))
	{
		rotationState = 0;
	}
}

void Tetromino::undoRotateTetromino()
{
	rotationState--;
	if (rotationState == -1)
	{
		rotationState = (cells.size())-1;
	} 
}
