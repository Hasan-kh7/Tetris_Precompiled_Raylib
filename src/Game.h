#ifndef GAME_H
#define GAME_H

#include "Tetromino.h"
#include "Grid.h"


class Game
{
public:
	Game();
	~Game();
	void drawGame();
	void handlePlayerInput();
	void moveTetrominoDown();
private:
	std::vector<Tetromino> getAllBlocks();
	Tetromino getRandomPiece();
	bool isTetrominoOutSide();
	void moveTetrominoLeft();
	void moveTetrominoRight();
	void lockTetromino();
	bool isTetrominoFits();
	void rotate();
	void reset();
	void updateScore(int linesCleared ,int moveDownPoints);

public:
	bool isGameOver;
	int score;
	Music mainMusic;
private:
	grid::Grid gameGrid;
	std::vector<Tetromino> tetrominos;
	Tetromino currentTetromino;
	Tetromino nextTetromino;
	Sound rotateTetrominoSound;
	Sound clearFullRowSound;
};
#endif // !GAME_H
