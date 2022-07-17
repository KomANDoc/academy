#include <iostream>
#include <cmath>

using namespace std;

const double pi = 3.141592653589793238463;

class Shapes
{
public:
	int getP() {};
	int getS() {};
};

class Rectangle:public Shapes
{
	int f_side;
	int s_side;
public:

	Rectangle()
	{
		this->f_side = 1;
		this->s_side = 1;
	}
	Rectangle(int f_side, int s_side)
	{
		this->f_side = f_side;
		this->s_side = s_side;
	}
	~Rectangle(){}

	const int getP()const
	{
		return this->f_side * 2 + this->s_side * 2;
	}
	const int getS()const
	{
		return this->f_side * this->s_side;
	}
	void info()
	{
		cout << "������ - " << this->f_side << endl;
		cout << "������ - " << this->s_side << endl;
		cout << "�������� - " << this->getP() << endl;
		cout << "������� - " << this->getS() << endl;
	}
};

class Square :public Shapes
{
	int side;
public:

	Square()
	{
		this->side = 1;
	}
	Square(int side)
	{
		this->side = side;
	}
	~Square(){}

	const int getP()const
	{
		return 4 * this->side;
	}
	const int getS()const
	{
		return this->side * this->side;
	}
	void info()
	{
		cout << "������� - " << this->side << endl;
		cout << "�������� - " << this->getP() << endl;
		cout << "������� - " << this->getS() << endl;
	}
};

class Equilateral_Triangle:public Shapes
{
	double side;
public:
	Equilateral_Triangle()
	{
		this->side = 1;
	}
	Equilateral_Triangle(double side)
	{
		this->side = side;
	}
	~Equilateral_Triangle() {}

	const double getS()const
	{
		return (this->side * sqrt((pow(this->side, 2) - pow((this->side / 2), 2))))/2;
		//return (pow(this->side,2)/2) * sin(60);
	}
	const double getP()const
	{
		return this->side * 3;
	}
	void info()
	{
		cout << "������� ��������������� ������������ - " << this->side << endl;
		cout << "������� ��������������� ������������ - " << this->getS() << endl;
		cout << "�������� ��������������� ������������ - " << this->getP() << endl;
	}
};

class Circle :public Shapes
{
double side;
public:
	Circle()
	{
		this->side = 1;
	}
	Circle(double side)
	{
		this->side = side;
	}
	~Circle() {}

	const double getRadius()const
	{
		return this->side / (2 * pi);
	}
	const double getS()const
	{
		return pi * pow(this->getRadius(), 2);
	}
	void info()
	{
		cout << "����� ���������� - " << this->side << endl;
		cout << "������ ���������� - " << this->getRadius() << endl;
		cout << "������� ���������� - " << this->getS() << endl;
	}
};





void main()
{
	setlocale(LC_ALL, "RU");


	Rectangle A(12, 5);
	A.info();

	Equilateral_Triangle B(15);
	B.info();

	Circle C(17);
	C.info();
}
