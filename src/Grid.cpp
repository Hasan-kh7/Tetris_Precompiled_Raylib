#include "Grid.h" 
#include "Colors.h"

grid::Grid::Grid()
	:numGridRows(GRID_HEIGHT),numGridCols(GRID_WIDTH),gridCellSize(CELL_SIZE),cellColors(Colors::Colors)
{
	initializeGrid();
}
void grid::Grid::initializeGrid()
{
	for(int row = 0 ; row < numGridRows ; row++)
	{
		for (int col = 0 ; col < numGridCols ; col++)
		{
			_gridBody[row][col] = 0;
		}
	}
}
void grid::Grid::drawGrid() 
{
	for (int row = 0; row < numGridRows; row++)
	{
		for (int col = 0; col < numGridCols; col++)
		{
			int cellValue = _gridBody[row][col];
			DrawRectangle(col * gridCellSize + 11, row * gridCellSize + 11, gridCellSize-1, gridCellSize-1,cellColors[cellValue]);
		}
	}
}

bool grid::Grid::isCellOutSide(int row , int col)
{
	if (row >= 0 && row < numGridRows && col >= 0 && col < numGridCols)
	{
		return false;
	}
	return true;
}

bool grid::Grid::isCellEmpty(int row, int col)
{
	if(_gridBody[row][col] == 0 )
	{
		return true;
	}
	return false;
}

bool grid::Grid::isRowFull(int row)
{
	for(int col = 0 ; col < numGridCols ; col++)
	{
		if(_gridBody[row][col]==0)
		{
			return false;
		}
	}
	return true;
}

void grid::Grid::clearRow(int row)
{
	for(int col=0 ; col< numGridCols ;col++ )
	{
		_gridBody[row][col] = 0; 
	}
}

void grid::Grid::moveRowDown(int row, int numRows)
{
	for(int col=0 ; col < numGridCols ; col++)
	{
		_gridBody[row + numRows][col] = _gridBody[row][col];
		_gridBody[row][col] = 0;
	}
}

int grid::Grid::clearfullRows()
{
	int completedRows = 0;
	for(int row = numGridRows-1;row>=0;row--)
	{
		if(isRowFull(row))
		{
			clearRow(row);
			completedRows++;
		}
		else if (completedRows>0)
		{
			moveRowDown(row, completedRows);
		}
	}
	return completedRows;
}



