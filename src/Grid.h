#ifndef GRID_H
#define GRID_H

#include "raylib.h"
#include <vector>


namespace grid {
	constexpr int GRID_WIDTH = 10;
	constexpr int GRID_HEIGHT = 20;
	constexpr int CELL_SIZE = 30;

	class Grid {
	public:
		Grid();
		void initializeGrid();
		void drawGrid();
		bool isCellOutSide(int row , int col);
		bool isCellEmpty(int row , int col);
		bool isRowFull(int row);
		void clearRow(int row);
		void moveRowDown(int row, int numRows);
		int clearfullRows();

		unsigned int _gridBody[GRID_HEIGHT][GRID_WIDTH];
	private: 
		int numGridRows;
		int numGridCols;
		int gridCellSize;
		std::vector<Color> cellColors;

	};
}

#endif // !GRID_H
