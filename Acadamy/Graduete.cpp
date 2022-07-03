#include "Graduete.h"


	//Get-method
	const std::string& Graduete::get_subject()const
	{
		return subject;
	}
	//Set-method
	void Graduete::set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	//Constructor and Destructor
	Graduete::Graduete(human_parameters, student_parameters, const std::string& subject)
		:Student(human_arguments, student_arguments)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	Graduete::~Graduete() { cout << "GDestructor:\t" << this << endl; }
	//Methods
	void Graduete::info()const
	{
		Student::info();
		cout << subject << endl;
	}
