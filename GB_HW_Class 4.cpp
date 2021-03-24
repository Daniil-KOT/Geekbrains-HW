#include <iostream>
using namespace std;

void EX1()
{
    int a, b;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;

    if (a + b >= 10 && a + b <= 20)
        cout << "True" << endl;
    else
        cout << "False" << endl;

}

void EX2()
{
    const int a = 5;
    const int b = 5;
    if (a == 10 && b == 10 || a + b == 10)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}

void EX3()
{
    for (int i = 1; i <= 50; i += 2)
        cout << i << endl;
}

void EX4()
{
    int X;
    bool prime = true;
    cout << "Enter the number: ";
    cin >> X;

    for (int i = 2; i < X; i++)
    {
        if (X % i == 0)
        {
            prime = false;
            break;
        }
    }
    if (prime == true)
        cout << "The number is prime." << endl;
    else
        cout << "The number is not prime." << endl;
}

void EX5()
{
    int year;
    cout << "Enter the year 1 to 3000: ";
    cin >> year;
    if (year % 4 == 0 && year % 100 != 0)
        cout << "This is a leap year.";
    else if (year % 400 == 0)
        cout << "This is a leap year.";
    else
        cout << "This year is not leap.";
}

int main()
{
    EX1();
    EX2();
    EX3();
    EX4();
    EX5();
}
