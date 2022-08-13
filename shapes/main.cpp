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
		unk = 0x00EE00F0,

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
				filled = 0;
			}	
		}

		virtual double get_S()const = 0;
		virtual double get_P()const = 0;
		virtual void draw()const = 0;
		virtual void info()const
		{
			cout << "Площадь фигуры: " << get_S() << endl;
			cout << "Периметр фигуры:" << get_P() << "\n\n";
			draw();
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
			// 1) получаем окно консоли 
			HWND hwnd = GetConsoleWindow();
			// 2) получаем контекст устройства для нашего окна консоли(то на чём будем рисовать) 
			HDC hdc = GetDC(hwnd);
			// 3) создаём корандаш: 
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);//карандаш рисует контур фигуры
			//4) создаём кисть:
			HBRUSH hBrush = CreateSolidBrush(color);//кисть заливает замкнутую фигуру
			//hPen и hBrush - это то, ЧЕМ мы будем рисовать

			//Выбираем, ЧЕМ и на ЧЁМ будем рисовать:
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//Когда мы выбрали, Чем, и на ЧЁМ рисовать, рисуем фигуру

			::Rectangle(hdc, start_x, start_y, start_x + width, start_y + height);

			//Освобождаем занятую память 
			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
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
			cout << "Длина стороны: " << endl;
			Shapes::info();
		}
	};

	class Equilateral_Triangle :public Shapes
	{
		double side;
	public:

	};

	class Circle :public Shapes
	{
		double side;
	public:

	};


}

void main()
{
	setlocale(LC_ALL, "");
	Geometry::Square kub (20, Geometry::Color::green, 600, 50, 2, 1);
	kub.info();
	Geometry::Rectangle kvadrat(300, 170, Geometry::Color::unk, 50, 200, 7, 0);
	kvadrat.info();
}
