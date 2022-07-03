#include  "Student.h"

	//Get-methods
	const std::string& Student::get_specialty()const
	{
		return specialty;
	}
	const std::string& Student::get_group()const
	{
		return group;
	}
	unsigned int Student::get_year()const
	{
		return year;
	}
	float Student::get_rating()const
	{
		return rating;
	}
	float Student::get_attendance()const
	{
		return attendance;
	}

	//Set-methods
	void Student::set_specialty(const std::string& specialty)
	{
		this->specialty = specialty;
	}
	void Student::set_group(const std::string& group)
	{
		this->group = group;
	}
	void Student::set_year(unsigned int year)
	{
		this->year = year;
	}
	void Student::set_rating(float rating)
	{
		this->rating = rating;
	}
	void Student::set_attendance(float attendance)
	{
		this->attendance = attendance;
	}

	//Constructor and Destructor
	Student::Student(human_parameters, student_parameters) :Human(human_arguments)
	{
		set_specialty(specialty);
		set_group(group);
		set_year(year);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	Student::~Student() { cout << "SDestructor:\t" << this << endl; }

	//Methods
	void Student::info()const
	{
		Human::info();
		cout << specialty << " " << group << " " << year << " " << rating << " " << attendance << endl;
	}