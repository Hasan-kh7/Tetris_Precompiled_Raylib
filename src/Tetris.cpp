#include "Tetris.h"
#include "raylib.h"

Tetris::Tetris()
	:game(Game())
{
	InitWindow(500, 620, "Tetris !");
	SetTargetFPS(60);

	font = LoadFontEx("fonts/monogram.ttf", 64, 0, 0);

	runGame();
}

void Tetris::runGame()
{
	while (WindowShouldClose() == false)
	{
		UpdateMusicStream(game.mainMusic);
		game.handlePlayerInput();
		if ((eventTriggered(0.2)))
		{
			game.moveTetrominoDown();
		}
		BeginDrawing();
		ClearBackground(Colors::DarkBlue);
		DrawTextEx(font, "Score", { 355,15 }, 38, 2, Colors::white);
		DrawRectangleRounded({ 320,65,170,60 }, 0.3f, 6, Colors::LightBlue);



		char scoreText[10];
		sprintf(scoreText, "%d", game.score);
		Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

		DrawTextEx(font, scoreText, { 320 + (170 - textSize.x) / 2,65 }, 38, 2, Colors::white);
		DrawTextEx(font, "Next", { 370,175 }, 38, 2, Colors::white);
		DrawTextEx(font, "Tetromino", { 320,220 }, 38, 2, Colors::white);
		DrawRectangleRounded({ 320,265,170,180 }, 0.3f, 6, Colors::LightBlue);
		if (game.isGameOver)
		{
			DrawTextEx(font, "Game Over", { 320,480 }, 38, 2, Colors::Red);
		}
		game.drawGame();
		EndDrawing();
	}

	CloseWindow();
}

bool Tetris::eventTriggered(float interval)
{

		double currentTime = GetTime();
		if (currentTime - lastUpdateTime >= interval)
		{
			lastUpdateTime = currentTime;
			return true;
		}
		return false;
	
}

