#include <iostream>
using namespace std;

// Ex. 2

enum Pieces
{
	BLANK,
	X,
	O
};

// Ex. 4

const int fieldSize = 3;

struct TicTacToeField
{
	char field[fieldSize][fieldSize];
	Pieces PlayingPiece;
	char turn;
};

// Ex. 5.1

union Variable 
{
	int a;
	float b;
	char c;
};

struct MyVariant
{
	unsigned int IsInt : 1;
	unsigned int IsChar : 1;
	unsigned int IsFloat : 1;
	Variable record;
};

int main()
{
	// Ex. 1

	short int a = 1000;
	int b = 200;
	long long c = 951'000'000'000;
	float pi1 = 3.14;
	double pi2 = 3.1415;
	char letter = 'x';
	bool isNum = true;

	// Ex. 3

	Pieces piece[3] = { BLANK, X, O };

	cout << "piece[0] is " << piece[0] << endl;

	// Ex 5.2

	MyVariant myBool;

	myBool.record.c = 'C';

	myBool.IsChar = 1;
	myBool.IsInt = 0;
	myBool.IsFloat = 0;

	cout << "The character is " << myBool.record.c << endl;

	return 0;

}