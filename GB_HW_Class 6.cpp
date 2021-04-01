#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;


//===================================================================================


int initInt()
{
    while (true)
    {
        int number;
        cout << "Enter the size of the array: ";
        cin >> number;
        if (cin.fail())
        {
            cout << "Error! Enter an integer number." << endl;
            cin.clear();
            cin.ignore(9999999, '\n');
        }
        else
        {
            return number;
        }
    }
}

void EX1()
{
    int* ptrArr;
    int size = initInt();
    if (size > 0)
    {
        ptrArr = new (nothrow) int[size];
        if (ptrArr != nullptr)
        {
            int j = 1;
            for (int i = 0; i < size; i++)
            {
                ptrArr[i] = j;
                j = j << 1;
                cout << "ptrArr[" << i << "] = " << ptrArr[i] << endl;
            }
            delete[] ptrArr;
            ptrArr = nullptr;
        }
    }
    cout << endl;
}


//===================================================================================


void EX2()
{
    const int ARR_LINES = 4;
    const int ARR_COLUMNS = 4;
    int** ptrArr;
    ptrArr = new int* [ARR_LINES];
    srand(time(0));
    for (int i = 0; i < ARR_LINES; i++)
    {
        ptrArr[i] = new int[ARR_COLUMNS];
    }
    for (int i = 0; i < ARR_LINES; i++)
    {
        for (int j = 0; j < ARR_COLUMNS; j++)
        {
            ptrArr[i][j] = rand() % 1000;
            cout << "ptrArr[" << i << "][" << j << "] = " << ptrArr[i][j] << endl;
        }
    }
    cout << endl;
}


//===================================================================================


void initFileEX3(string text)
{
    string filename;
    cout << "Enter the file name: ";
    cin >> filename;
    string format = ".txt";
    ofstream fout(filename + format);
        fout << text;
}


//===================================================================================


string readText(string& fileName)
{
    ifstream fin;
    string text;
    fin.open(fileName);
    if (fin.is_open())
    {
        const size_t BUFF_SIZE = 100;
        char chars[BUFF_SIZE];
        while (!fin.eof())
        {
            fin.getline(chars, BUFF_SIZE);
            text += chars;
        }
    }
    else
    {
        cout << "Error. Unable to read file." << endl;
    }
    fin.close();
    return text;
}

bool writeText(string& fileName, string& text)
{
    ofstream fout;
    fout.open(fileName);
    if (fout.is_open())
    {
        fout << text;
        fout.close();
        return true;
    }
    else
    {
        fout.close();
        return false;
    }
}

void mergeFilesEX4()
{
    string fileName1, fileName2, fileName3, fileText1, fileText2, fileText3;
    string format = ".txt";
    cout << "Enter files to be merged." << endl;
    cin >> fileName1 >> fileName2;
    fileName1 += format;
    fileName2 += format;
    cout << "Enter the final file name." << endl;
    cin >> fileName3;
    fileName3 += format;
    fileText1 = readText(fileName1);
    fileText2 = readText(fileName2);
    fileText3 = fileText1 + fileText2;
    if (writeText(fileName3, fileText3))
    {
        cout << "Merge completed" << endl;
    }
    else
    {
        cout << "Merge failed!" << endl;
    }
}


//===================================================================================


bool findTextEX5()
{
    string fileName, findWord, text;
    string format = ".txt";
    cout << "Enter the file name where the word has to be found: " << endl;
    cin >> fileName;
    fileName += format;
    cout << "Enter the word that has to be found: ";
    cin >> findWord;
    text = readText(fileName);
    int temp = text.find(findWord);
    if (temp >= 0)
    {
        cout << "Word: " << findWord << " has been found." << endl;
        return true;
    } 
    else
    {
        cout << "Word: " << findWord << " has not been found." << endl;
        return false;
    }
}


//===================================================================================


int main()
{
    EX1();

    EX2();

    string text1 = "no matter what's written here.";
    string text2 = "it is only a test.";
    initFileEX3(text1);
    initFileEX3(text2);

    mergeFilesEX4();

    findTextEX5();
}


