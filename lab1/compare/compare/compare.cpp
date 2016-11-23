// compare.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> 
#include <string> 
#include <fstream> 

using namespace std;

bool CompareFiles(ifstream & file1, ifstream & file2, int & numberStr)
{
	string s1, s2;

	while (!file1.eof() || !file2.eof())
	{
		getline(file1, s1);
		getline(file2, s2);
		numberStr++;
		if (s1 != s2)
			return false;
	}
	return true;
}


int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: Compare.exe <input file> <input file>\n";
		return 1;
	}

	ifstream file1(argv[1]), file2(argv[2]);

	if (!file1.is_open())
	{
		cout << argv[1] << " not found" << endl;
		return 1;
	}

	if (!file2.is_open())
	{
		cout << argv[2] << " not found." << endl;
		return 1;
	}

	int numberStr = 0;

	if (!CompareFiles(file1, file2, numberStr))
	{
		cout << "File is different. Line number is " << numberStr << endl;
		return 1;
	}
	cout << "Files are equal" << endl;
	return 0;
}


/*#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: copyfile.exe <input file> <output file>\n";
		return 1;
	}

	// Объявили переменную типа ifstream 
	// (input file stream, поток для чтения из файла), проинициализировав его
	// именем входного файла
	ifstream input(argv[1]);

	// вызываем метод is_open() у объекта input,
	// который вернет true, если файл был открыт
	if (!input.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	// создали поток для записи в выходной файл
	ofstream output(argv[2]);
	if (!output.is_open())
	{
		cout << "Failed to open " << argv[2] << " for writing\n";
		return 1;
	}

	char ch;
	// Считываем в переменную ch символ из входного потока
	// возвращаем значение, приводимое к bool, которое сигнализирует об успехе
	while (input.get(ch))
	{
		if (!output.put(ch))
		{
			cout << "Failed to save data on disk\n";
			return 1;
		}
	}

	if (!output.flush()) // Если не удалось сбросить данные на диск
	{
		cout << "Failed to save data on disk\n";
		return 1;
	}

	return 0;
}*/



/*int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}*/

