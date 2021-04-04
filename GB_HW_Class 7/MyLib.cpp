#include <iostream>
using namespace std;

namespace MyLib
{
	float initArray(float arr[], const size_t& size)
	{
		srand(time(0));
		for (int i = 0; i < size; i++)
		{
			arr[i] = static_cast <float> ((rand() % 100 + (-49)) / static_cast <float> (RAND_MAX));
		}
		return arr[size];
	}

	float printArray(float arr[], const size_t& size)
	{
		for (int i = 0; i < size; i++)
			cout << arr[i] << endl;
		return arr[size];
	}

	void countNums(float arr[], const size_t& size)
	{
		int countPositive = 0;
		int countNegative = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] > 0)
			{
				countPositive++;
			}
			else
			{
				countNegative++;
			};
		}
		cout << countPositive << endl << countNegative << endl;
	}
}