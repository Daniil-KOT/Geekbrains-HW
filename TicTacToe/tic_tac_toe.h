#pragma once

enum Piece
{
	EMPTY = '_',
	CROSS = 'X',
	ZERO = 'O'
};

enum Progress
{
	IN_PROGRESS,
	AI_WON,
	USER_WON,
	DRAW
};

struct Coordinates
{
	size_t x;
	size_t y;
};

struct Game
{
	Piece user;
	Piece ai;
	Progress progress;
	size_t turn;
	const size_t size = 3;
	Piece** ptrField;
};

void initGame(Game& g);

void deInitGame(Game& g);

void crtField(Game& g);

void clearScreen();

Progress checkWin(Game& g);

Coordinates getUserCoord(Game& g);

Coordinates getAICoord(Game& g);