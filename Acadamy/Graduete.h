#pragma once
#include "Student.h"

class Graduete :public Student
{
	std::string subject;
public:
	//Get-method
	const std::string& get_subject()const
	{
		return subject;
	}
	//Set-method
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	//Constructor and Destructor
	Graduete(human_parameters, student_parameters, const std::string& subject)
		:Student(human_arguments, student_arguments)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduete() { cout << "GDestructor:\t" << this << endl; }
	//Methods
	void info()const
	{
		Student::info();
		cout << subject << endl;
	}



};