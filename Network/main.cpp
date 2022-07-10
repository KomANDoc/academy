#define _CRT_SECURE_NO_WARNINGS //Чтобы не жаловалось на рисковую команду strcat(...)
#include <iostream>
#include <fstream>
using namespace std;
//#define First_hw
#define Second_hw

void main()
{
	setlocale(LC_ALL, "RU");
	const int SIZE = 256;

	/////-----------------------------------------------------------------------/////
#ifdef First_hw

	ifstream fin("201 RAW.txt");
	std::ofstream fout;
	fout.open("File.txt");

	char ip[SIZE] = {};
	char mac[SIZE] = {};

	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> ip;
			fin >> mac;
			fout << mac << "\t" << ip << endl;
		}
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}

	fout.close();
	system("start notepad 201 RAW.txt");
	system("start notepad File.txt");

#endif 

	/////-----------------------------------------------------------------------/////

#ifdef Second_hw
	ifstream fin("File.txt");
	std::ofstream fout;
	fout.open("201_RAW.txt");

	char buffer[SIZE] = {};
	int i = 1;

	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> buffer;
			fout << "host 201-" << i
				<< "\n{\n\thardware ethernet\t" << buffer;

			fin >> buffer;
			fout << ";\n\tfixed-address\t\t" << buffer
				<< ";\n}\n" << endl;
			i++;
		}
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}

	fin.close();
	fout.close();
	system("start notepad 201_RAW.txt");
#endif // Second_hw

}