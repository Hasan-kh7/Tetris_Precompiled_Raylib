#include "Game.h"

#include <ctime>
#include <random>
#include "TetrominoPiece.h"
Game::Game()
{
	gameGrid = grid::Grid();
	tetrominos = getAllBlocks();
	currentTetromino = getRandomPiece();
	nextTetromino = getRandomPiece();
	isGameOver = false;
	score = 0;
	InitAudioDevice();
	mainMusic = LoadMusicStream("sounds/music.mp3");
	PlayMusicStream(mainMusic);
	rotateTetrominoSound = LoadSound("sounds/rotate.mp3");
	clearFullRowSound = LoadSound("sounds/clear.mp3");
}
Game::~Game()
{
	UnloadMusicStream(mainMusic);
	UnloadSound(rotateTetrominoSound);
	UnloadSound(clearFullRowSound);
	CloseAudioDevice();
}
Tetromino Game::getRandomPiece()
{
	if(tetrominos.empty())
	{
		tetrominos = getAllBlocks();
	}
	srand(time(0));
	int randomIndex = rand() % tetrominos.size();
	Tetromino tetrominoPiece = tetrominos[randomIndex];
	tetrominos.erase(tetrominos.begin() + randomIndex);
	return tetrominoPiece;
}

std::vector<Tetromino> Game::getAllBlocks()
{
	return { I_Tetromino(), J_Tetromino(), L_Tetromino(), O_Tetromino(), S_Tetromino(), T_Tetromino(), Z_Tetromino() };
}

void Game::drawGame()
{
	gameGrid.drawGrid();
	currentTetromino.drawTetromino(11,11);
	nextTetromino.drawTetromino(265, 300);
}

void Game::handlePlayerInput()
{
	int keyPressed = GetKeyPressed();
	if(isGameOver && keyPressed!=0)
	{
		isGameOver = false;
		reset();
	}
	switch (keyPressed)
	{
	case KEY_LEFT:
		moveTetrominoLeft();
		break;
	case KEY_RIGHT:
		moveTetrominoRight();
		break;
	case KEY_DOWN:
		moveTetrominoDown();
		updateScore(0, 1);
		break;
	case KEY_SPACE:
		rotate();
		break;
	}
}

void Game::moveTetrominoLeft()
{
	if(!isGameOver)
	{
	currentTetromino.Move(0, -1);
	if(isTetrominoOutSide() || !isTetrominoFits())
		{
		currentTetromino.Move(0, 1);
		}
	}
}

void Game::moveTetrominoRight()
{
	if (!isGameOver)
	{
		currentTetromino.Move(0, 1);
		if (isTetrominoOutSide() || !isTetrominoFits())
		{
			currentTetromino.Move(0, -1);
		}
	}
}

void Game::moveTetrominoDown()
{
	if (!isGameOver)
	{
		currentTetromino.Move(1, 0);
		if (isTetrominoOutSide() || !isTetrominoFits())
		{
			currentTetromino.Move(-1, 0);
			lockTetromino();
		}
	}
}

void Game::lockTetromino()
{
	std::vector<Position> tiles = currentTetromino.GetCellsPositions();
	for (Position item : tiles )
	{
		gameGrid._gridBody[item.row][item.col] = currentTetromino.id;
	}
	currentTetromino = nextTetromino;
	if(!isTetrominoFits())
	{
		isGameOver = true;
		currentTetromino.cells.clear();
		StopMusicStream(mainMusic);
	}
	nextTetromino = getRandomPiece();
	int rowsCleared = gameGrid.clearfullRows();
	if(rowsCleared > 0 )
	{
		PlaySound(clearFullRowSound);
		updateScore(rowsCleared, 0);
	}
}

bool Game::isTetrominoOutSide()
{
	std::vector<Position> tiles = currentTetromino.GetCellsPositions();
	for (Position item : tiles)
	{
		if (gameGrid.isCellOutSide(item.row, item.col))
		{
			return true;
		}
	}
	return false;
}

bool Game::isTetrominoFits()
{
	std::vector<Position> tiles = currentTetromino.GetCellsPositions();
	for(Position item : tiles)
	{
		if (!gameGrid.isCellEmpty(item.row, item.col))
		{
			return false;
		}
	}
	return true;
}

void Game::rotate()
{
	if (!isGameOver)
	{
		currentTetromino.rotateTetromino();
		if (isTetrominoOutSide() || !isTetrominoFits())
		{
			currentTetromino.undoRotateTetromino();
		}
		else
		{
			PlaySound(rotateTetrominoSound);
		}
	}
}

void Game::reset()
{
	gameGrid.initializeGrid();
	tetrominos = getAllBlocks();
	currentTetromino = getRandomPiece();
	nextTetromino = getRandomPiece();
	score = 0;
	PlayMusicStream(mainMusic);
}

void Game::updateScore(int linesCleared, int moveDownPoints)
{
	switch (linesCleared)
	{
	case 1 :
		score += 100;
		break;
	case 2:
		score += 300;
		break;
	case 3:
		score += 500;
		break;
	case 4:
		score += 800;
		break;
	default:
			break;
	}
	score += moveDownPoints;
}


 