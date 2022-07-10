#define _CRT_SECURE_NO_WARNINGS //Чтобы не жаловалось на рисковую команду strcat(...)
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
	std::ofstream fout;		//1) создаем поток
	fout.open("File.txt");	//2) Открываем поток
	fout << "Hello File";//3) Используев поток
	fout.close();			//4) После использования потока, его обязательно нужно закрыть
	/*fout.open("File.txt", std::ios_base::app);//позволяет дописать файл файлы не очищая его
	fout << "Hello Files, Я Андрей ";
	fout.close();*/
	system("notepad File.txt");
#endif

#ifdef WRITE_WITH_FILE 
	ifstream fin("File.txt");//открыть и создать поток fin можно одновременно 
	if (fin.is_open())//Важно делать проверку открытости вайла
	{
		//TODO: читаем файл
		const int SIZE = 256; //Размер буфера чтения
		char buffer[SIZE] = {};//Буфер чтения
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

	system("start notepad File.txt");//start чтобы консоль не зависила от открытого файла, создаёт новый процесс   
#endif 

#ifdef OPEN_FILE
	char sz_filename[FILENAME_MAX] = {};
	cout << "Введите имя файла: "; cin.getline(sz_filename, FILENAME_MAX);
	if (strstr(sz_filename, ".txt") == NULL)
	{
		strcat(sz_filename, ".txt");
		//Функция strcat (str1, str2) выполняет конкатенацию строк (слияние)
		//а именно, к содержимому str1 добавляет содержимое str2,
		//Если в str1 достаточно памяти в противном случае
		//выдаёт ошибку
		//Runtime check failure #2 или Heap corruption detected
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
	strcat(sz_comand, sz_filename);//Слияние файла и команды
	system(sz_comand);
#endif
}