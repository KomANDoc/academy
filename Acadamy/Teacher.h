#pragma once
#include "Human.h"


////							define для учителя								   ////
////-------------------------------------------------------------------------------////

#define teacher_parameters const std::string& specialty, unsigned int experience 
#define teacher_arguments cspecialty, experience 

////-------------------------------------------------------------------------------////


class Teacher :public Human
{
	std::string specialty;
	unsigned int experience;
public:
	//Get - methods
	const std::string& get_specialty()const;
	unsigned int get_experience()const;
	//Set - methods
	void set_specialty(const std::string& specialty);
	void set_experience(unsigned int experience);
	//Constructor and Destructor
	Teacher(human_parameters, teacher_parameters);
	~Teacher();
	//Methods
	void info()const;

};