// compare.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> 
#include <string> 
#include <fstream> 
#include <Windows.h>

using namespace std;

bool CompareFiles(ifstream & file1, ifstream & file2, int & LineNumber)
{
	string lineFile1, lineFile2;

	while (!file1.eof() || !file2.eof())
	{
		getline(file1, lineFile1);
		getline(file2, lineFile2);

		LineNumber++;
		if (lineFile1 != lineFile2)
			return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	if (argc != 3)
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

	int LineNumber = 0;

	if (!CompareFiles(file1, file2, LineNumber))
	{
		cout << "File is different. Line number is " << LineNumber << endl;
		return 1;
	}

	cout << "Files are equal" << endl;
	return 0;
}



	