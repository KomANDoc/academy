#include <iostream>
#include <string>//��� �� �����������. ��� � ����� ������ ��� ���� ���������� ��� ���������� 
using namespace std;


//#define Inheritance_Check


////							define ��� ��������								   ////
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
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	//Set-methods
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	//Constractors
	Human(human_parameters)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human() { cout << "HDestructor:\t" << this << endl; }
	
	virtual void info()const
	{
		cout << last_name << " " << first_name << " " << age << " years\n";
	}
	virtual std::ostream& print(std::ostream& os)const
	{
		return os << last_name << " " << first_name << " " << age;
	}
};

std::ostream& operator<< (std::ostream& os, const Human& obj)
{
	return obj.print(os);
}

////							define ��� ��������								   ////
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
	const std:: string & get_specialty()const
	{
		return specialty;
	}
	const std::string& get_group()const
	{
		return group;
	}
	unsigned int get_year()const
	{
		return year;
	}
	float get_rating()const
	{
		return rating;
	}
	float get_attendance()const
	{
		return attendance;
	}

	//Set-methods
	void set_specialty(const std::string& specialty)
	{
		this->specialty = specialty;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_year(unsigned int year)
	{
		this->year = year;
	}
	void set_rating(float rating)
	{
		this->rating = rating;
	}
	void set_attendance(float attendance)
	{
		this->attendance = attendance;
	}

	//Constructor and Destructor
	Student(human_parameters,student_parameters):Human(human_arguments)
	{
		set_specialty(specialty);
		set_group(group);
		set_year(year);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student() { cout << "SDestructor:\t" << this << endl; }

	//Methods
	void info()const
	{
		Human::info();
		cout << specialty << " " << group << " " << year << " " << rating << " " << attendance << endl;
	}
	std::ostream& print(std::ostream& os)const
	{
		return Human::print(os) << " " << specialty << " " << group << " " << year << " " << rating << " " << attendance;
	}
};


////							define ��� �������								   ////
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
	const std::string& get_specialty()const
	{
		return specialty;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	//Set - methods
	void set_specialty(const std::string& specialty)
	{
		this->specialty = specialty;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	//Constructor and Destructor
	Teacher(human_parameters, teacher_parameters) :Human(human_arguments)
	{
		set_specialty(specialty);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher() { cout << "TDestructor:\t" << this << endl; }
	//Methods
	void info()const
	{
		Human::info();
		cout << specialty << " " << experience << endl;
	}
	std::ostream& print(std::ostream& os)const
	{
		return Human::print(os) << " " << specialty << " " << experience;
	}
};



////-------------------------------------------------------------------------------////


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
	std::ostream& print(std::ostream& os)const
	{
		return Student::print(os) << " " << subject;
	}
};


////-------------------------------------------------------------------------------////


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
		//Upcast - �������������� �� �������� ����:
		new Student("Pinkman", "Jessie", 25, "Chemistry", "SPU_110", 1, 70, 90),
		new Teacher("Rombova", "Margarita", 56, "Chemistry", 15),
		new Graduete("Pinkman", "Jessie", 25, "Chemistry", "SPU_110", 1, 70, 90, "Chemistry")
	};

	for (int i = 0; i < (sizeof(group) / sizeof(group[0])); i++)
	{
		cout << *group[i] << endl;
	}
	for (int i = 0; i < (sizeof(group) / sizeof(group[0])); i++)
	{
		delete group[i];
	}


}