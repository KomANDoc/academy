#pragma once
#include "Human.h"


////							define для студента								   ////
////-------------------------------------------------------------------------------////


#define student_parameters	const std::string specialty, const std::string group, unsigned int year, float rating, float attendance
#define student_arguments	specialty, group, year, rating, attendance

////-------------------------------------------------------------------------------////

class Student :public Human
{
	std::string specialty;
	std::string group;
	unsigned int year;
	float rating;
	float attendance;

public:

	//Get-methods
	const std::string& get_specialty()const;
	const std::string& get_group()const;
	unsigned int get_year()const;
	float get_rating()const;
	float get_attendance()const;

	//Set-methods
	void set_specialty(const std::string& specialty);
	void set_group(const std::string& group);
	void set_year(unsigned int year);
	void set_rating(float rating);
	void set_attendance(float attendance);

	//Constructor and Destructor
	Student(human_parameters, student_parameters);
	virtual ~Student();
	//Methods
	virtual void info()const;

};