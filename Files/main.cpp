#define _CRT_SECURE_NO_WARNINGS //����� �� ���������� �� �������� ������� strcat(...)
#include <iostream>
#include <fstream>
using namespace std;

#define WRITE_IN_FILE
//#define WRITE_WITH_FILE 
//#define OPEN_FILE
void main ()
{
	setlocale(LC_ALL, "RU");

#ifdef WRITE_IN_FILE
	cout << "Hello Files" << endl;
	std::ofstream fout;		//1) ������� �����
	fout.open("File.txt");	//2) ��������� �����
	fout << "Hello File";//3) ���������� �����
	fout.close();			//4) ����� ������������� ������, ��� ����������� ����� �������
	/*fout.open("File.txt", std::ios_base::app);//��������� �������� ���� ����� �� ������ ���
	fout << "Hello Files, � ������ ";
	fout.close();*/
	system("notepad File.txt");
#endif

#ifdef WRITE_WITH_FILE 
	ifstream fin("File.txt");//������� � ������� ����� fin ����� ������������ 
	if (fin.is_open())//����� ������ �������� ���������� �����
	{
		//TODO: ������ ����
		const int SIZE = 256; //������ ������ ������
		char buffer[SIZE] = {};//����� ������
		while (!fin.eof())// .eof - End of File
		{
			//fin >> buffer;
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
	fin.close();

	system("start notepad File.txt");//start ����� ������� �� �������� �� ��������� �����, ������ ����� �������   
#endif 

#ifdef OPEN_FILE
	char sz_filename[FILENAME_MAX] = {};
	cout << "������� ��� �����: "; cin.getline(sz_filename, FILENAME_MAX);
	if (strstr(sz_filename, ".txt") == NULL)
	{
		strcat(sz_filename, ".txt");
		//������� strcat (str1, str2) ��������� ������������ ����� (�������)
		//� ������, � ����������� str1 ��������� ���������� str2,
		//���� � str1 ���������� ������ � ��������� ������
		//����� ������
		//Runtime check failure #2 ��� Heap corruption detected
	}

	ifstream fin(sz_filename);
	if (fin.is_open())
	{
		const int SIZE = 256;
		char buffer[SIZE] = {};
		while (!fin.eof())
		{
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
	fin.close();

	char sz_comand[FILENAME_MAX] = "start notepad ";
	strcat(sz_comand, sz_filename);//������� ����� � �������
	system(sz_comand);
#endif
}