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
