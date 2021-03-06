#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>
#include "tic_tac_toe.h"

using namespace std;

inline void clearScreen()
{
	system("cls");
}

int main()
{
	Game gm;
	initGame(gm);

	clearScreen();
	crtField(gm);

	int difficulty;
	cout << "Hello! Welcome to the TicTacToe game!" << endl << "Please, enter the difficulty level (1 = Easy, 2 = Normal, 3 = Hard): ";
	cin >> difficulty;


	while (gm.progress == IN_PROGRESS)
	{
		if (gm.turn % 2 == 0)
		{
			Coordinates coord = getUserCoord(gm);
			gm.ptrField[coord.y][coord.x] = gm.user;
		}
		else
		{
			Coordinates coord = getAICoord(gm, difficulty);
			gm.ptrField[coord.y][coord.x] = gm.ai;
		}

		gm.turn++;

		clearScreen();
		crtField(gm);

		gm.progress = checkWin(gm);
	}

	if (gm.progress == USER_WON)
		cout << "Congratulations! You have won!" << endl;
	else if (gm.progress == AI_WON)
		cout << "Sorry, you have lost. :(" << endl;
	else
		cout << "It's a draw!" << endl;

	deInitGame(gm);

	return 0;
}
