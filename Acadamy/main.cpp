#include <iostream>
#include <fstream>
#include <string>//это не обязательно. ибо в новой студие она сама подключает эту библиотеку 
using namespace std;

enum Defaults//enum - перечисление. набор целочисленных констант 
{
	type_width = 18,
	last_name_width = 15,
	first_name_width = 12,
	age_width = 5,
	specialty_width = 25,
	group_width = 8,
	year_width = 3,
	rating_width = 8,
	attendance_width = 8,
	experience_width = 5,
	subject_width = 25,
};



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
		//return os << last_name << " " << first_name << " " << age;
		os.width(Defaults::last_name_width);
		os << std::left;
		os << last_name;
		os.width(Defaults::first_name_width);
		os << first_name;
		os.width(Defaults::age_width);
		os << age;
		return os;
	}
	virtual std::ofstream& print(std::ofstream& ofs)const
	{
		ofs.width(Defaults::type_width);
		ofs << std::left;
		ofs << std::string(typeid(*this).name()) + ":";
		ofs.width(Defaults::last_name_width);
		ofs << last_name;
		ofs.width(Defaults::first_name_width);
		ofs << first_name;
		ofs.width(Defaults::age_width);
		ofs << age;
		return ofs;
	}
	virtual std::ifstream& scan(std::ifstream& ifs)
	{
		ifs >> last_name >> first_name >> age;
		return ifs;
	}
};

std::ostream& operator<< (std::ostream& os, const Human& obj)
{
	return obj.print(os);
}
std::ofstream& operator<< (std::ofstream& ofs, const Human& obj)
{
	obj.print(ofs);
	return ofs;
}
std::ifstream& operator>>(std::ifstream& ifs, Human& obj)
	{
		obj.scan(ifs);
		return ifs;
	}

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
		/*return Human::print(os) << " " << specialty << " " << group << " " << year << " " << rating << " " << attendance;*/
		Human::print(os);
		os.width(Defaults::specialty_width);
		os << specialty;
		os.width(Defaults::group_width);
		os << group;
		os.width(Defaults::year_width);
		os << year;
		os.width(Defaults::rating_width);
		os << rating;
		os.width(Defaults::attendance_width);
		os << attendance;
		return os;
	}
	std::ofstream& print(std::ofstream& ofs)const
	{
		Human::print(ofs);
		ofs.width(Defaults::specialty_width);
		ofs << specialty;
		ofs.width(Defaults::group_width);
		ofs << group;
		ofs.width(Defaults::year_width);
		ofs << year;
		ofs.width(Defaults::rating_width);
		ofs << rating;
		ofs.width(Defaults::attendance_width);
		ofs << attendance;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Human::scan(ifs);
		char specialty[Defaults::specialty_width] = {};
		ifs.read(specialty, Defaults::specialty_width);
		for (int i = Defaults::specialty_width - 1; specialty[i] == ' '; i--)
		{
			specialty[i] = 0;
		}
		this->specialty = specialty;
		ifs >> group;
		ifs >> year;
		ifs >> rating;
		ifs >> attendance;
		return ifs;
	}
};


////							define для учителя								   ////
////-------------------------------------------------------------------------------////

#define teacher_parameters const std::string& specialty, unsigned int experience 
#define teacher_arguments specialty, experience 

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
		//return Human::print(os) << " " << specialty << " " << experience;
		Human::print(os);
		os.width(Defaults::specialty_width);
		os << specialty;
		os.width(Defaults::experience_width);
		os << experience;
		return os;
	}
	std::ofstream& print(std::ofstream& ofs)const
	{
		//return Human::print(os) << " " << specialty << " " << experience;
		Human::print(ofs);
		ofs.width(Defaults::specialty_width);
		ofs << specialty;
		ofs.width(Defaults::experience_width);
		ofs << experience;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Human::scan(ifs);
		char specialty[Defaults::specialty_width] = {};
		ifs.read(specialty, Defaults::specialty_width);
		for (int i = Defaults::specialty_width - 1; specialty[i] == ' '; i--)
		{
			specialty[i] = 0;
		}
		this->specialty = specialty;
		ifs >> experience;
		return ifs;
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
		//return Student::print(os) << " " << subject;
		Student::print(os);
		os.width(Defaults::subject_width);
		os << subject;
		return os;
	}
	std::ofstream& print(std::ofstream& ofs)const
	{
		//return Student::print(os) << " " << subject;
		Student::print(ofs);
		ofs.width(Defaults::subject_width);
		ofs << subject;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Student::scan(ifs);
		std::getline(ifs, subject);
		return ifs;
	}
};
Human* HumanFactory(const std::string type)
{
	if (type.find("class Teacher") != std::string::npos)
		return new Teacher("", "", 0, "", 0);
	if (type.find("class Graduete") != std::string::npos)
		return new Graduete("", "", 0, "", "", 0, 0, 0, "");
	if (type.find("class Student") != std::string::npos)
		return new Student("", "", 0, "", "", 0, 0, 0);
	return nullptr;
}

Human** load(const char filename[], int& n)
{
	Human** group = nullptr;
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		std::string buffer;
		n = 0;
		//1) Вычисляем размер массива
		for(; !fin.eof();n++)std::getline(fin, buffer);
		n--;
		//2) Выделяем память под массив
		group = new Human*[n]{};
		//3)Возращаемся к началу файла, для того чтобы прочитать его содержимое 
		std::cout << fin.tellg() << endl;
		fin.clear();
		fin.seekg(0);
		std::cout << fin.tellg() << endl;

		//4) Считываем объекты из файла в массив
		for (int i = 0; i < n; i++)
		{
			std::getline(fin, buffer, ':');
			group[i] = HumanFactory(buffer);
			if(group[i]) fin >> *group[i];
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
 	return group;
}



////-------------------------------------------------------------------------------////

//#define Inheritance_Check
//#define Polimorphism_Check
#define FILE_READ_CHECK

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

#ifdef Polimorphism_Check
	Human* group[] =
	{
		//Upcast - преобразование по базовому типу:
		new Student("Pinkman", "Jessie", 25, "Chemistry", "SPU_110", 1, 70, 90),
		new Teacher("Rombova", "Margarita", 56, "Chemistry", 15),
		new Graduete("Pinkman", "Jessie", 25, "Chemistry", "SPU_110", 1, 70, 90, "Chemistry it's my life"),
		new Teacher("Diaz", "Richard",50, "Weapon distribution", 20)
	};

	std::ofstream fout("Academy.txt");

	for (int i = 0; i < (sizeof(group) / sizeof(group[0])); i++)
	{
		cout << *group[i] << endl;
		fout << *group[i] << endl;
	}
	fout.close();
	for (int i = 0; i < (sizeof(group) / sizeof(group[0])); i++)
	{
		delete group[i];
	}

	system("start notepad Academy.txt");
#endif 

#ifdef FILE_READ_CHECK
	int n = 0;
	Human** group = load("Academy.txt", n);
	for (int i = 0; i < n; i++)
	{
		cout << *group[i] << endl;
	}
	for (int i = 0; i < n; i++)
	{
		delete group[i];
	}
	delete[] group;
#endif // FILE_READ_CHECK


}