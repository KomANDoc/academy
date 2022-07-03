#include "Teacher.h"


	//Get - methods
	const std::string& Teacher::get_specialty()const
	{
		return specialty;
	}
	unsigned int Teacher::get_experience()const
	{
		return experience;
	}
	//Set - methods
	void Teacher::set_specialty(const std::string& specialty)
	{
		this->specialty = specialty;
	}
	void Teacher::set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	//Constructor and Destructor
	Teacher::Teacher(human_parameters, teacher_parameters) :Human(human_arguments)
	{
		set_specialty(specialty);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	Teacher::~Teacher() { cout << "TDestructor:\t" << this << endl; }
	//Methods
	void Teacher::info()const
	{
		Human::info();
		cout << specialty << " " << experience << endl;
	}