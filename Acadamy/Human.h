#pragma once
#include <iostream>
#include <string>//это не обязательно. ибо в новой студие она сама подключает эту библиотеку 
using namespace std;

////							define для человека								   ////
////-------------------------------------------------------------------------------////
#define human_parameters	const std::string last_name, const std::string first_name,unsigned int age
#define human_arguments		last_name,first_name,age
////-------------------------------------------------------------------------------////

class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;

public:
	//Get-methods
	const std::string& get_last_name()const;
	const std::string& get_first_name()const;
	unsigned int get_age()const;
	//Set-methods
	void set_last_name(const std::string& last_name);
	void set_first_name(const std::string& first_name);
	void set_age(unsigned int age);
	//Constractors
	Human(human_parameters);
	virtual ~Human();

	virtual void info()const;

};