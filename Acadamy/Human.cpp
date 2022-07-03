#include "Human.h"


	//Get-methods
	const std::string& Human::get_last_name()const
	{
		return last_name;
	}
	const std::string& Human::get_first_name()const
	{
		return first_name;
	}
	unsigned int Human::get_age()const
	{
		return age;
	}
	//Set-methods
	void Human::set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void Human::set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void Human::set_age(unsigned int age)
	{
		this->age = age;
	}
	//Constractors
	Human::Human(human_parameters)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	Human::~Human() { cout << "HDestructor:\t" << this << endl; }

	void Human::info()const
	{
		cout << last_name << " " << first_name << " " << age << " years\n";
	}