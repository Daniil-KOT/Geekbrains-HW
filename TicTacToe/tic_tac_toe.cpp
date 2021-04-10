#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>
#include "tic_tac_toe.h"

using namespace std;

int32_t getRandomNum(int32_t min, int32_t max)
{
	const static auto seed = chrono::system_clock::now().time_since_epoch().count();
	static mt19937_64 generator(seed);
	uniform_int_distribution<int32_t> dis(min, max);
	return dis(generator);
}

void initGame(Game& g)
{
	g.ptrField = new Piece * [g.size];
	for (size_t i = 0; i < g.size; i++)
	{
		g.ptrField[i] = new Piece[g.size];
	}

	for (size_t y = 0; y < g.size; y++)
		for (size_t x = 0; x < g.size; x++)
			g.ptrField[y][x] = EMPTY;

	g.progress = IN_PROGRESS;

	if (getRandomNum(0, 1000) > 500)
	{
		g.user = CROSS;
		g.ai = ZERO;
		g.turn = 0;
	}
	else
	{
		g.ai = CROSS;
		g.user = ZERO;
		g.turn = 1;
	}
}

void deInitGame(Game& g)
{
	for (size_t i = 0; i < g.size; i++)
	{
		delete[] g.ptrField[i];
	}
	delete[] g.ptrField;

	g.ptrField = nullptr;

}

void crtField(Game& g)
{
	cout << "     ";

	for (size_t x = 0; x < g.size; x++)
		cout << x + 1 << "  ";

	cout << endl << endl;

	for (size_t y = 0; y < g.size; y++)
	{
		cout << y + 1 << "  |";
		for (size_t x = 0; x < g.size; x++)
		{
			cout << " " << (char)g.ptrField[y][x] << " ";
		}
		cout << "|" << endl << endl;
	}

	cout << endl << "User piece: " << (char)g.user << endl << "AI piece: " << (char)g.ai << endl;
}

inline void clearScreen()
{
	system("cls");
}

Progress checkWin(Game& g)
{
	for (size_t y = 0; y < g.size; y++)
	{
		if (g.ptrField[y][0] == g.ptrField[y][1] && g.ptrField[y][0] == g.ptrField[y][2])
		{
			if (g.ptrField[y][0] == g.user)
			{
				return USER_WON;
			}
			else if (g.ptrField[y][0] == g.ai)
			{
				return AI_WON;
			}
		}
	}
	for (size_t x = 0; x < g.size; x++)
	{
		if (g.ptrField[0][x] == g.ptrField[1][x] && g.ptrField[0][x] == g.ptrField[2][x])
		{
			if (g.ptrField[0][x] == g.user)
			{
				return USER_WON;
			}
			else if (g.ptrField[0][x] == g.ai)
			{
				return AI_WON;
			}
		}
	}

	int d1, d2;

	d1 = g.ptrField[0][0];	// initial pieces 
	d2 = g.ptrField[g.size - 1][0];	// of diagonals

	for (size_t i = 0; i < g.size; i++)
	{
		if (g.ptrField[i][i] != d1)
		{
			d1 = ' ';
			break;
		}
	}

	if (d1 != ' ' && d1 == g.user)
		return USER_WON;
	else if (d1 != ' ' && d1 == g.ai)
		return AI_WON;

	for (size_t i = 0; i < g.size; i++)
	{
		if (g.ptrField[g.size - 1 - i][i] != d2)
		{
			d2 = ' ';
			break;
		}
	}

	if (d2 != ' ' && d2 == g.user)
		return USER_WON;
	else if (d2 != ' ' && d2 == g.ai)
		return AI_WON;

	bool empty = false;

	for (size_t y = 0; y < g.size; y++)
	{
		for (size_t x = 0; x < g.size; x++)
			if (g.ptrField[y][x] == EMPTY)
				empty = true;
	}
	if (empty)
		return IN_PROGRESS;
	else
		return DRAW;
}

Coordinates getUserCoord(Game& g)
{
	Coordinates coord = { 0 };
	do
	{
		cout << "Enter x coordinate: ";
		cin >> coord.x;
		cout << "Enter y coordinate: ";
		cin >> coord.y;
	} while (coord.x > g.size || coord.y > g.size || g.ptrField[coord.y - 1][coord.x - 1] != EMPTY);

	coord.x--;
	coord.y--;

	return coord;
}

Coordinates getAICoord(Game& g)
{
	for (size_t y = 0; y < g.size; y++)
	{
		for (size_t x = 0; x < g.size; x++)
		{
			if (g.ptrField[y][x] == EMPTY)
			{
				g.ptrField[y][x] = g.ai;
				if (checkWin(g) == AI_WON)
				{
					g.ptrField[y][x] = EMPTY;
					return { x, y };
				}
				g.ptrField[y][x] = EMPTY;
			}
		}
	}

	for (size_t y = 0; y < g.size; y++)
	{
		for (size_t x = 0; x < g.size; x++)
		{
			if (g.ptrField[y][x] == EMPTY)
			{
				g.ptrField[y][x] = g.user;
				if (checkWin(g) == USER_WON)
				{
					g.ptrField[y][x] = EMPTY;
					return { x, y };
				}
				g.ptrField[y][x] = EMPTY;
			}
		}
	}

	if (g.ptrField[1][1] == EMPTY)
	{
		return { 1, 1 };
	}
	if (g.ptrField[0][0] == EMPTY)
	{
		return { 0, 0 };
	}
	if (g.ptrField[2][0] == EMPTY)
	{
		return { 0, 2 };
	}
	if (g.ptrField[0][2] == EMPTY)
	{
		return { 2, 0 };
	}
	if (g.ptrField[2][2] == EMPTY)
	{
		return { 2, 2 };
	}
	if (g.ptrField[1][0] == EMPTY)
	{
		return { 0, 1 };
	}
	if (g.ptrField[0][1] == EMPTY)
	{
		return { 1, 0 };
	}
	if (g.ptrField[1][2] == EMPTY)
	{
		return { 2, 1 };
	}
	if (g.ptrField[2][1] == EMPTY)
	{
		return { 1, 2 };
	}
}