#include<iostream>
#include <Windows.h>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

namespace Geometry
{
	const double pi = 3.141592653589793238463;

	enum Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,
		yellow = 0x0000FFFF,
		unk = 0x77B12B23,

		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_yellow = 0xEE,
		console_default = 0x07
	};

	enum Defaults
	{
		start_x_min = 0,
		start_x_max = 800,

		start_y_min = 0,
		start_y_max = 500,

		line_width_min = 1,
		line_width_max = 30,

		primary_size_min = 5,
		primery_size_max = 500,
	};

#define SHAPE_TAKE_PARAMETERS Color color, unsigned int start_x, unsigned int start_y, unsigned int line_width, bool filled
#define SHAPE_GIVE_PARAMETERS color, start_x, start_y, line_width, filled

//
//#define Rectangle_example
//#define Square_example
//#define	Equilateral_Triangle_example
#define	Circle_example


	class Shapes
	{
	protected:
		Color color;
		unsigned int start_x;
		unsigned int start_y;
		unsigned int line_width;
		bool filled;
	public:
		Color get_color()const { return color; }
		void set_color(Color color_s) { color = color_s; }

		int get_start_x()const { return start_x; }
		void set_start_x(unsigned int x)
		{
			if (start_x > Defaults::start_x_max) start_x = Defaults::start_x_max;
			if (start_x < Defaults::start_x_min) start_x = Defaults::start_x_min;
			start_x = x;
		}

		int get_start_y()const { return start_y; }
		void set_start_y(unsigned int y)
		{
			if (start_y > Defaults::start_y_max) start_y = Defaults::start_y_max;
			if (start_y < Defaults::start_y_min) start_y = Defaults::start_y_min;
			start_y = y;
		}

		int get_line_width()const { return line_width; }
		void set_line_width(unsigned int width)
		{
			if (line_width > Defaults::line_width_max) line_width = Defaults::line_width_max;
			else if (line_width < Defaults::line_width_min) line_width = Defaults::line_width_min;
			else line_width = width;
		};

		bool get_filled()const { return filled; }
		void set_filled(int number)
		{
			if (number >= 0 and number <= 1)
			{
				filled = (bool)number;
			}
			else
			{
				filled = (bool)0;
			}	
		}

		virtual double get_S()const = 0;
		virtual double get_P()const = 0;
		virtual void draw()const = 0;
		virtual void info()const
		{
			cout << "Площадь фигуры: " << get_S() << endl;
			cout << "Периметр фигуры:" << get_P() << endl;
			this->is_it_filled(); cout << "\n\n";
			draw();
		}
		void is_it_filled()const
		{
			if (this->filled)
			{
				cout << "Фигура заполнена" << endl;
			}
			else
			{
				cout << "Фигура полая" << endl;
			}
		}

		Shapes(SHAPE_TAKE_PARAMETERS) :color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
			set_filled(filled);
		}
		virtual ~Shapes() {}
	};

	/*class Square :public Shapes
	{
		double side;
	public:
		Square(double side, SHAPE_TAKE_PARAMETERS) :Shapes(SHAPE_GIVE_PARAMETERS)
		{
			set_side(side);
		}
		~Square() {}

		double get_side()const { return side; }
		void set_side(double side)
		{
			if (side < Defaults::primary_size_min) side = Defaults::primary_size_min;
			else if (side > Defaults::primery_size_max) side = Defaults::primery_size_max;
			this->side = side;
		}

		double get_S()const
		{
			return side * side;
		}
		double get_P()const
		{
			return side * 4;
		}

		void draw()const
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
			cout << endl;
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны: " << get_side() << endl;
			Shapes::info();
		}
	};*/

	class Rectangle : public Shapes
	{
		double width;
		double height;
	public:
		Rectangle(double height,double width, SHAPE_TAKE_PARAMETERS) :Shapes(SHAPE_GIVE_PARAMETERS)
		{
			set_width(width);
			set_height(height);
		}
		~Rectangle() {}

		double get_width()const { return width; }
		void set_width(double width)
		{
			if (width < Defaults::primary_size_min) width = Defaults::primary_size_min;
			if (width > Defaults::primery_size_max) width = Defaults::primery_size_max;
			this->width = width;
		}

		double get_height()const { return height; }
		void set_height(double height)
		{
			if (height < Defaults::primary_size_min) height = Defaults::primary_size_min;
			if (height > Defaults::primery_size_max) height = Defaults::primery_size_max;
			this->height = height;
		}


		double get_S()const
		{
			return width * height;
		}
		double get_P()const
		{
			return (2 * width + 2 * height);
		}
		void draw()const
		{
			/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
			cout << endl;*/
			HWND hwnd = GetConsoleWindow();

			HDC hdc = GetDC(hwnd);
			if (this->filled)
			{
				HPEN hPen = CreatePen(PS_SOLID, line_width, color);
				HBRUSH hBrush = CreateSolidBrush(color);

				SelectObject(hdc, hPen);
				SelectObject(hdc, hBrush);
				::Rectangle(hdc, start_x, start_y, start_x + width, start_y + height);

				DeleteObject(hPen);
				DeleteObject(hBrush);
				ReleaseDC(hwnd, hdc);
			}
			else
			{
				HPEN hPen = CreatePen(PS_SOLID, line_width, color);

				SelectObject(hdc, hPen);
				::Rectangle(hdc, start_x, start_y, start_x + width, start_y + height);

				DeleteObject(hPen);
				ReleaseDC(hwnd, hdc);
			}
		}
		void info()const 
		{
			cout << typeid(*this).name() << endl;
			cout << "Высота: " << get_height() << endl;
			cout << "Ширина: " << get_width() << endl;
			Shapes::info();
		}
	};

	class Square: public Rectangle
	{
	public:
		Square(double side, SHAPE_TAKE_PARAMETERS) : Rectangle(side, side, SHAPE_GIVE_PARAMETERS) {}
		~Square() {}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны: " << get_height() << endl;
			Shapes::info();
		}
	};
	
	class Triangle : public Shapes
	{
		double side_a;
		double side_b;
		double side_c;
	public:
		Triangle(double side_a, double side_b, double side_c, SHAPE_TAKE_PARAMETERS) :Shapes(SHAPE_GIVE_PARAMETERS) 
		{ 
			set_side_a(side_a);
			set_side_b(side_b);
			set_side_c(side_c);
		}
		virtual ~Triangle() {}

		double get_side_a()const{return side_a;}
		void set_side_a(double side) { side_a = side; }

		double get_side_b()const{return side_b;}
		void set_side_b(double side) { side_b = side; }

		double get_side_c()const{return side_c;}
		void set_side_c(double side) { side_c = side; }

	};

	class Equilateral_Triangle : public Shapes
	{
		double side;
	public:
		Equilateral_Triangle(double side, SHAPE_TAKE_PARAMETERS) :Shapes(SHAPE_GIVE_PARAMETERS){ set_side(side); }
		~Equilateral_Triangle(){};

		double get_side()const { return side; }
		void set_side(double side) { this->side = side; }

		void draw()const
		{
			HWND hwnd = GetConsoleWindow();

			HDC hdc = GetDC(hwnd);
			
			POINT poz[6] = {start_x,start_y, start_x + side, start_y, (start_x + (side / 2)), start_y - (sqrt(3) * (side/2))};
			if (this->filled)
			{
				HPEN hPen = CreatePen(PS_SOLID, line_width, color);
				HBRUSH hBrush = CreateSolidBrush(color);

				SelectObject(hdc, hPen);
				SelectObject(hdc, hBrush);
				::Polygon(hdc, poz,3);

				DeleteObject(hPen);
				DeleteObject(hBrush);
				ReleaseDC(hwnd, hdc);
			}
			else
			{
				HPEN hPen = CreatePen(PS_SOLID, line_width, color);

				SelectObject(hdc, hPen);
				::Polygon(hdc, poz, 3);

				DeleteObject(hPen);
				ReleaseDC(hwnd, hdc);
			}
		}
		void info()const 
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны: " << get_side() << endl;
			Shapes::info();
		}
		double get_S()const { return (side* (sqrt(3) * (side / 2)))/2; }
		double get_P()const { return side*3; }
	};

	class Circle :public Shapes
	{
		double r;
	public:
		Circle(double r, SHAPE_TAKE_PARAMETERS) :Shapes(SHAPE_GIVE_PARAMETERS) { set_r(r); }
		~Circle() {}

		double get_r()const { return r; }
		void set_r(double r) { this->r = r; }

		void draw()const
		{
			HWND hwnd = GetConsoleWindow();

			HDC hdc = GetDC(hwnd);
			if (this->filled)
			{
				HPEN hPen = CreatePen(PS_SOLID, line_width, color);
				HBRUSH hBrush = CreateSolidBrush(color);

				SelectObject(hdc, hPen);
				SelectObject(hdc, hBrush);

				Ellipse(hdc, start_x - r, start_y - r, start_x + r, start_y + r);

				DeleteObject(hPen);
				DeleteObject(hBrush);
				ReleaseDC(hwnd, hdc);
			}
			else
			{
				HPEN hPen = CreatePen(PS_SOLID, line_width, color);

				SelectObject(hdc, hPen);
				
				Ellipse(hdc, start_x - r, start_y - r, start_x + r, start_y + r);

				DeleteObject(hPen);
				ReleaseDC(hwnd, hdc);
			}
		}
		void info()const 
		{
			cout << typeid(*this).name() << endl;
			cout << "Радиус: " << get_r() << endl;
			Shapes::info();
		}
		double get_S()const { return pi*pow(r,2); }
		double get_P()const { return 2*pi*r; }

	};


}

void main()
{
	setlocale(LC_ALL, "");

#ifdef Square_example
	Geometry::Square kub(160, Geometry::Color::green, 500, 270, 5, 0);
	kub.info();
#endif

#ifdef Rectangle_example
	Geometry::Rectangle kvadrat(149, 530, Geometry::Color::blue, 50, 200, 1, 0);
	kvadrat.info();
#endif 

#ifdef Equilateral_Triangle_example
	Geometry::Equilateral_Triangle treug(260, Geometry::Color::green, 500, 430, 5, 0);
	treug.info();
#endif

#ifdef Circle_example
	Geometry::Circle krug(150, Geometry::Color::red, 500, 370, 5, 0);
	krug.info();
#endif
}
