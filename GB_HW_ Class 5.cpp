#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void printArr(double arr[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << endl;
	}
	cout << endl;
};

void printArr2(int arr[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << endl;
	}
	cout << endl;
};

void initDoubleArr(double arr[], int size)
{
	srand(static_cast <unsigned> (time(0)));
	for (int i = 0; i < size; i++)
	{
		arr[i] = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);	// generating array of random numbers with floating point
	}

}

void initIntArr(double arr[], int size)
{
	srand(static_cast <unsigned> (time(0)));
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 2;

}

void changeValArr(double arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 1)
			arr[i] = 0;
		else
			arr[i] = 1;
	}
}

void initArr2(int arr[], int size)
{
	int arrVal = 1;
	for (int i = 0; i < size; i++)
	{
		arr[i] = arrVal;
		arrVal += 3;
	}
}

void shiftArr(int arr[], int size, int j)
{
	bool IsPositive;

	if (j > 0)
		IsPositive = true;
	else
	{
		IsPositive = false;
		j = -j;
	};

	j %= size;

	int lastVal = size - 1;

	for (int i = 0; i < j; i++)
	{
		int temp; 
		if (IsPositive)
			temp = arr[lastVal];
		else
			temp = arr[0];

		for (int j = 0; j < lastVal; j++)
		{
			if (IsPositive)
				arr[lastVal - j] = arr[lastVal - j - 1];
			else
				arr[j] = arr[j + 1];
		}

		if (IsPositive)
			arr[0] = temp;
		else
			arr[lastVal] = temp;
	}
}

bool checkBalance(int arr[], int size)
{
	bool isBalanced = false;
	int arrSum = 0;
	for (int i = 0; i < size; i++)
		arrSum += arr[i];
	int rightSum = 0;
	for (int j = 0; j < size; j++)
	{
		rightSum += arr[j];
		if (rightSum == arrSum - rightSum)
			isBalanced = true;
	}
	return isBalanced;
}

int main()
{
	const int FIRST_ARR_SIZE = 5;
	double arr[FIRST_ARR_SIZE];
//=============== EX.1 ==============
	initDoubleArr(arr, FIRST_ARR_SIZE);
	printArr(arr, FIRST_ARR_SIZE);
//===================================

//=============== EX.2 ==============

	initIntArr(arr, FIRST_ARR_SIZE);
	printArr(arr, FIRST_ARR_SIZE);
	changeValArr(arr, FIRST_ARR_SIZE);
	printArr(arr, FIRST_ARR_SIZE);
//===================================

//=============== EX.3 ==============
	const int SECOND_ARR_SIZE = 8;
	int arr2[SECOND_ARR_SIZE];

	initArr2(arr2, SECOND_ARR_SIZE);
	printArr2(arr2, SECOND_ARR_SIZE);
//===================================

//=============== EX.4 ==============
	int j;
	cout << "Enter the number of shifts: " << endl;
	cin >> j;
	shiftArr(arr2, SECOND_ARR_SIZE, j);
	printArr2(arr2, SECOND_ARR_SIZE);
//===================================

//=============== EX.5 ==============
	const int THIRD_ARR_SIZE = 5;
	int arr3[THIRD_ARR_SIZE] = { 1, 1, 1, 2, 1 };
	if (checkBalance(arr3, THIRD_ARR_SIZE))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	
//===================================

	return 0;

}

