#include<iostream>
#include<cmath>
#include<time.h>
#include<Windows.h>

using namespace std;
double function(double x)
{
	return (1 / (1 + pow(x, 2)) - 3 * x);
}
double F1(double x)
{
	return  (-2 * x) / (pow((1 + pow(x, 2)), 2)) - 3;
}
double F2(double x)
{
	return (8*pow(x,2)-2*(pow(x,2)+1))/pow(x*x+1,3);
}
double g(float x0)
{
	return 1 / (3 + 3 * pow(x0, 2));
}
void task3()
{
	int a, b, v;
	double f1, f2, f;
	double eps;
	float rez;
	double x, seconds;
	float x0;
	cout << "Укажите точность: " << endl;
	cin >> eps;
	cout << "Укажите начальный отрезок" << endl;
	cin >> a;
	cout << "Укажите конечный отрезок" << endl;
	cin >> b;
	cout << "_____________________________________________" << endl;
	printf("| Значение x |     Функция f(x)   |  Точность|\n");
	cout << "----------------------------------------------" << endl;
	for (double x = a; x < b + 1; x += eps)
	{
		printf("|%12lf|%20lf|%10lf|\n", x, function(x), eps);
		cout << "----------------------------------------------" << endl;
	}
	cout << "Каким методом вы хотите найти приближенный корень?\n1)Метод половинного деления\n2)Метод хорд\n3)Метод Ньютона(Метод касательных)\n4)Метод простых итераций\n5)Метод секущих\n6)Метод хорд и касательных" << endl;
	cin >> v;
	switch (v)
	{
	case 1:

		double h;
		int n, t, z;
		if ((function(a) * function(b)) < 0)
		{
			f1 = function(a);
			n = 1;
			t = (a + b) / 2;
			f2 = function(t);
			if (f1 * f2 < 0)
			{
				b = t;
			}
			else
			{
				a = t;
				f1 = f2;
			}
			n = n + 1;
			while (abs(a - b) > eps)
			{
				t = (a + b) / 2;
				f2 = function(t);
				if (f1 * f2 < 0)
				{
					b = t;
				}
				else
				{
					a = t;
					f1 = f2;
				}
				n = n + 1;
			}
			x = (a + b) / 2;
			f = function(x);
			cout << "x= " << x << " f= " << f << " n= " << n << endl;
		}
		else cout << "На этом отрезке нет корней" << endl;
		break;
	case 2:
		if ((function(a) * function(b)) < 0)
		{
			f1 = function(a);
			f2 = function(b);
			n = 1;
			if (f1 * f2 > 0)
			{
				x = b;
				z = a;
			}
			else
			{
				x = a;
				int z = b;
			}
			f2 = function(z);
			f1 = function(x);
			h = (x - z) / ((f1 - f2) * f1);
			x = x - h;
			n += 1;
			while (fabs(h) > eps)
			{
				f1 = function(x);
				h = (x - z) / ((f1 - f2) * f1);
				x = x - h;
				n += 1;
			}
			f1 = function(x);
			cout << "x= " << x << " f1= " << f1 << " n = " << n;
		}
		else cout << "На этом отрезке нет корней" << endl;

		break;
	case 3:
		if (a == 0)a = 0.001f;
		if (b == 0)b = 0.001f;
		n = 1;
		f = function(b);
		f2 = F2(b);


		if (f * f2 > 0) x = b;
		else x = a;

		do {
			f = function(x);
			f1 = F1(x);

			h = f / f1;
			x = x - h;

			n++;
		} while (fabs(h) > eps);
		cout << "x= " << x << " f(x) = " << function(x) << " eps= " << eps << " n= " << n << endl;
		break;
	
	case 4:
	
		x = a;
		n = 1;

		do {
			x0 = x;
			x = g(x0);
			n++;
		} while (fabs(x0 - x) > eps);
		cout << "x= " << x << " f(x)= " << function(x) << " eps = " << eps << " n = " << n << endl;
		break;
	case 5:
	    rez = a;
		n = 1;

		do
		{
			x = rez;
			rez = b - ((b - a) / (function(b) - function(a))) * function(b);
			a = b;
			b = rez;
			n++;
		} while (fabs(x - rez) >= eps);
		cout << "rez = " << rez << " f(rez) = " << rez << " eps = " << eps << " n = " << n << endl;
		break;
	case 6:
		n = 1;
		float xh, xk;
		if (function(a) * F2(a) > 0) {
			xk = a;
			xh = b;
		}
		else {
			xk = b;
			xh = a;
		}

		do
		{
			xk = xk - (function(xk)) / (F1(xk));
			xh = (xh - (function(xh)) / (function(xk) - function(xh)) * (xk - xh));
			n++;
		} while (fabs(xk - xh) > eps);
		cout << "xk = " << xk << " f(xk) = " << function(xk) << " eps= " << eps << " n= " << n << endl;
	

	}
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	task3();
}

#include <iostream>
using namespace std;

void ex_1_1(float a, float b, float eps); //Метод деления пополам
void ex_1_2(float a, float b, float eps); //Метод хорд
void ex_2_1(float a, float b, float eps); //Метод касательных
void ex_2_2(float a, float b, float eps); //Метод простых итераций
void ex_3_1(float a, float b, float eps); //Метод секущих
void ex_3_2(float a, float b, float eps); //Комбинированный метод хорд и касательных

void tabl(float a, float b, float c, int d);
float f(float x);
float df_first(float x);
float df_second(float x);
float g(float x);

int main()
{
	setlocale(LC_ALL, "RUS");

	float a, b, eps;
	int v, iter=0;

	do
	{
		cout << "Выберите действие:\n"
			"1-Решение уравнения методом деления отрезка пополам\n"
			"2-Решение уравнения методом хорд\n"
			"3-Решение уравнения методом Ньютона (метод касательных)\n"
			"4-Решение уравнения методом последовательных приближений (метод простых итераций)\n"
			"5-Решение уравнения методом секущих\n"
			"6-Решение уравнения комбинированным методом хорд и касательных\n"
			"0-Выход" << endl;
		cin >> v;
		if (v > 0 && v < 7)
		{
			cout << "Введите a" << endl;
			cin >> a;
			cout << "Введите b" << endl;
			cin >> b;
			cout << "Введите точность" << endl;
			cin >> eps;

			if (f(a) * f(b) >= 0)
			{
				cout << "На этом отрезке корней нет" << endl;
				continue;
			}
		}
		else continue;

		switch (v)
		{
			case 1:
			{
				ex_1_1(a, b, eps);
				break;
			}

			case 2:
			{
				ex_1_2(a, b, eps);
				break;
			}

			case 3:
			{
				ex_2_1(a, b, eps);
				break;
			}

			case 4:
			{
				ex_2_2(a, b, eps);
				break;
			}

			case 5:
			{
				ex_3_1(a, b, eps);
				break;
			}

			case 6:
			{
				ex_3_2(a, b, eps);
				break;
			}
		}

	} while (v != 0);
}

void tabl(float a, float b, float c, int d)
{
	printf("------------------------------------------------------------------\n");
	printf("| Полученное значение x |   Функция f(x)   | Точность | Итераций |\n");
	printf("------------------------------------------------------------------\n");
	printf("|%23lf|%18lf|%10lf|%10d|\n", a, b, c, d);
	printf("------------------------------------------------------------------\n");
}

float f(float x)
{
	return 3 * powf(x, 4) + 4 * powf(x, 3) - 12 * powf(x, 2) + 1;
}

float df_first(float x)
{
	return 12 * powf(x, 3) + 12 * powf(x, 2) - 24 * x;
}

float df_second(float x)
{
	return 36 * x * x + 24 * x - 24;
}

float g(float x) {
	if (x == 0) x = 0.01f;

	return -1.f/(3*powf(x, 3)+4*powf(x, 2)-12*x);
}

void ex_1_1(float a, float b, float eps)
{
	int n=1;
	float f_1 = f(a), f_2, t;

	do {
		t = (a + b) / 2;
		f_2 = f(t);

		if (f_1 * f_2 < 0) b = t;
			else
			{
				a = t;
				f_1 = f_2;
			}
		n++;
	} while (abs(b - a) > eps);

	tabl((a + b) / 2, f((a + b) / 2), eps, n);

}

void ex_1_2(float a, float b, float eps)
{
	float c;
	int n=1;

	do {
		c = (f(b) * a - f(a) * b) / (f(b) - f(a));

		if ((f(a) * f(c)) > 0) a = c;
			else b = c;
		
		n++;
	} while (abs(f(c))>eps);

	tabl(c, f(c), eps, n);
}

void ex_2_1(float a, float b, float eps)
{
	if (a == 0)a = 0.001f;
	if (b == 0)b = 0.001f;
	int n = 1;
	float fu = f(b), f_2 = df_second(b), f_1;
	float x, h;

	if (fu * f_2 > 0) x = b;
	else x = a;

	do {
		fu = f(x);
		f_1 = df_first(x);

		h = fu / f_1;
		x = x - h;

		n++;
	} while (fabs(h)>eps);

	tabl(x, f(x), eps, n);
}

void ex_2_2(float a, float b, float eps)
{
	float x0, x=a;
	int n = 1;

	do {
		x0 = x;
		x = g(x0);
		n++;
	} while (fabs(x0-x) > eps);

	tabl(x, f(x), eps, n);
}

void ex_3_1(float a, float b, float eps)
{
	float x, rez=a;
	int n=1;

	do
	{
		x = rez;
		rez = b - ((b - a) / (f(b) - f(a))) * f(b);

		a = b;
		b = rez;

		n++;
	} while (fabs(x - rez) >= eps);

	tabl(rez, f(rez), eps, n);
}

void ex_3_2(float a, float b, float eps)
{
	int n = 1;
	float xh, xk;

	if (f(a) * df_second(a) > 0) {
		xk = a;
		xh = b;
	} 
	else {
			xk = b;
			xh = a;
	}

	do 
	{
		xk = xk - (f(xk)) / (df_first(xk));
		xh= (xh - (f(xh)) / (f(xk) - f(xh)) * (xk - xh));
	
		n++;
	} while (fabs(xk - xh) > eps);

	tabl(xk, f(xk), eps, n);
}
