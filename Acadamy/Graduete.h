#pragma once
#include "Student.h"

class Graduete :public Student
{
	std::string subject;
public:
	//Get-method
	const std::string& get_subject()const;
	//Set-method
	void set_subject(const std::string& subject);
	//Constructor and Destructor
	Graduete(human_parameters, student_parameters, const std::string& subject);
	~Graduete();
	//Methods
	void info()const;



};