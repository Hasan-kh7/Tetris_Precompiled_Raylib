#include "Tetromino.h"
#include "Position.h"


class L_Tetromino : public Tetromino
{
public:
	L_Tetromino()
	{
		id = 1;
		cells[0] = { Position(0, 2), Position(1, 0), Position(1, 1) ,Position(1, 2) };
		cells[1] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2) };
		cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0) };
		cells[3] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1) };
		Move(0, 3);
	}
};

class J_Tetromino : public Tetromino
{
public:
	J_Tetromino()
	{
		id = 2;
		cells[0] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2) };
		cells[1] = { Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1) };
		cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2) };
		cells[3] = { Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1) };
		Move(0, 3);
	}
};

class I_Tetromino : public Tetromino
{
public:
	I_Tetromino()
	{
		id = 3;
		cells[0] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3) };
		cells[1] = { Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2) };
		cells[2] = { Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3) };
		cells[3] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1) };
		Move(-1, 3);
	}
};

class O_Tetromino : public Tetromino
{
public:
	O_Tetromino()
	{
		id = 4;
		cells[0] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
		Move(0, 4);
	}
};

class S_Tetromino : public Tetromino
{
public:
	S_Tetromino()
	{
		id = 5;
		cells[0] = { Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1) };
		cells[1] = { Position(0, 1), Position(1,1), Position(1, 2), Position(2, 2) };
		cells[2] = { Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1) };
		cells[3] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1) };
		Move(0, 3);
	}
};

class T_Tetromino : public Tetromino
{
public:
	T_Tetromino()
	{
		id = 6;
		cells[0] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2) };
		cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1) };
		cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1) };
		cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1) };
		Move(0, 3);
	}
};

class Z_Tetromino : public Tetromino
{
public:
	Z_Tetromino()
	{
		id = 7;
		cells[0] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2) };
		cells[1] = { Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1) };
		cells[2] = { Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2) };
		cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0) };
		Move(0, 3);
	}
};