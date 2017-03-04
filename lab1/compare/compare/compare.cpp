// compare.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> 
#include <string> 
#include <fstream> 
#include <Windows.h>

using namespace std;

bool CompareFiles(ifstream & file1, ifstream & file2, int & lineNumber)
{
	string lineFile1, lineFile2;

	while (!file1.eof() || !file2.eof())
	{
		getline(file1, lineFile1);
		getline(file2, lineFile2);

		++lineNumber;
		if (lineFile1 != lineFile2)
		{
			return false;
		}
	}
	return true;
}

void Encoding()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
}

int main(int argc, char* argv[])
{
	Encoding();
	const int validArgNum = 3;
	if (argc != validArgNum)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: compare.exe <input file> <input file>\n";
		return 1;
	}

	ifstream file1(argv[1]), file2(argv[2]);

	if (!file1.is_open())
	{
		cout << argv[1] << " not found." << endl;
		return 1;
	}

	if (!file2.is_open())
	{
		cout << argv[2] << " not found." << endl;
		return 1;
	}

	int lineNumber = 0;

	if (!CompareFiles(file1, file2, lineNumber))
	{
		cout << "File is different. Line number is " << lineNumber << endl;
		return 1;
	}

	cout << "Files are equal" << endl;
	return 0;
}



	