#include <iostream>
#include <string>//это не обязательно. ибо в новой студие она сама подключает эту библиотеку 
#include "Human.h"
#include "Student.h"
#include "Teacher.h"
#include "Graduete.h"
using namespace std;


//#define Inheritance_Check


void main()
{

#ifdef Inheritance_Check
	setlocale(LC_ALL, "RU");
	Human h("Montana", "Antonio", 25);
	h.info();

	Student Jessie("Pinkman", "Jessie", 25, "Chemistry", "SPU_110", 1, 70, 90);
	Jessie.info();

	Teacher Margarita("Rombova", "Margarita", 56, "Chemistry", 15);
	Margarita.info();

	Graduete Jess("Pinkman", "Jessie", 25, "Chemistry", "SPU_110", 1, 70, 90, "Chemistry");
	Jess.info();
#endif 


	Human* group[] =
	{
		//Upcast - преобразование по базовому типу:
		new Student("Pinkman", "Jessie", 25, "Chemistry", "SPU_110", 1, 70, 90),
		new Teacher("Rombova", "Margarita", 56, "Chemistry", 15),
		new Graduete("Pinkman", "Jessie", 25, "Chemistry", "SPU_110", 1, 70, 90, "Chemistry")
	};

	for (int i = 0; i < (sizeof(group) / sizeof(group[0])); i++)
	{
		group[i]->info();
	}
	for (int i = 0; i < (sizeof(group) / sizeof(group[0])); i++)
	{
		delete group[i];
	}


}