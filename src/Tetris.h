#ifndef TETRIS_H
#define TETRIS_H

#include "Game.h"
#include "raylib.h"


class Tetris
{
public:
	Tetris();
	void runGame();

private:
	bool eventTriggered(float interval);


private:
	Font font;
	Game game;
	double lastUpdateTime = 0;
};
#endif // !TETRIS_H
