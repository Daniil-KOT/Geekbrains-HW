#include <iostream>
using namespace std;

// Ex. 1; 4

extern const int a;
extern const int b;
extern const int c;
extern const int d;
int main()
{
    float e = a * (b + (static_cast <float> (c) / d));

    cout << e << endl;

    // Ex. 2

    int NUM, RESULT;

    cout << "Enter the number: ";
    cin >> NUM;
    RESULT = (NUM <= 21) ? 21 - NUM : (NUM - 21) << 1;

    cout << RESULT << endl;

    // Ex. 3

    int array[3][3][3], *ptr;
    ptr = &array[0][0][0];
    ptr += 13;
    *ptr = 3;
    cout << array[1][1][1];


}
