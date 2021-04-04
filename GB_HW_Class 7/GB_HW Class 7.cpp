#include <iostream>
#include "MyLib.h"
#include <utility>
#include <string>
#include <fstream>

#define CHECKER(a,b) (((a) >= 0 && (a) < b) ? cout << "true" << endl : cout << "false" << endl) // EX.2

//================EX.3=================================

#define ARRAY_SIZE 5
#define ARRAY_SORT(a,b) swap(a,b) 

using namespace std;


void printArr(int arr[], const size_t size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void initArr(int arr[], const size_t size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter array element[" << i << "]: ";
		cin >> arr[i];
	}
}


void arrSort(int arr[], const size_t size)
{
	for (int startVal = 0; startVal < size; startVal++)
	{
		int minVal = startVal;

		for (int currVal = startVal + 1; currVal < size; currVal++)
		{
			if (arr[currVal] < arr[minVal])
			{
				minVal = currVal;
			}
		}
		ARRAY_SORT(arr[startVal], arr[minVal]);
	}
}

//=====================================================

//================EX.4=================================
#pragma pack(push, 1)

struct Employee
{
	long ID;
	int age;
	string name;
	double salary;
};

#pragma pack(pop)

void writeStruct(Employee* emp)
{
	ofstream fout("Emp.txt", ios_base::binary);
	if (fout.is_open())
	{
		fout.write((char*)emp, sizeof ((*emp)));
		fout.close();
	}
}

void printStruct(Employee* emp)
{
	cout << "ID: " << emp->ID << endl;
	cout << "Age: " << emp->age << endl;
	cout << "Name: " << emp->name << endl;
	cout << "Salary: " << emp->salary << endl;
}
//=====================================================



int main()
{
	const size_t SIZE = 5;
	float Arr[SIZE];
	MyLib::initArray(Arr, SIZE);
	MyLib::printArray(Arr, SIZE);
	MyLib::countNums(Arr, SIZE);

//================EX.2=================================

	int a;
	int b = 10;
	cout << "Enter a number: ";
	cin >> a;
	CHECKER(a, b);

//=====================================================

	int arrDef[ARRAY_SIZE];

	initArr(arrDef, ARRAY_SIZE);
	arrSort(arrDef, ARRAY_SIZE);
	printArr(arrDef, ARRAY_SIZE);

//=====================================================

	Employee* emp = new Employee;
	emp->ID = 789256734;
	emp->age = 27;
	emp->name = "John Smith";
	emp->salary = 80000.0;

	cout << sizeof(Employee) << endl;

	printStruct(emp);
	writeStruct(emp);
	delete emp;

//=====================================================

	return 0;

}

