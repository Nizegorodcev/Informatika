#include<iostream>
#include<cmath>
#include<string>
#include <iomanip>
#include<sstream>
#include<Windows.h>
using namespace std;
template<typename t1, typename t2>
t1 razn(t1 a, t2 b)
{
	return a - b;
}
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int v;
	double a, b, c;
	double x, y;
	double chislo, f,chislo2;
	int ch;
	double okr1, okr2,z;
	cout << "Выберите действие:\n Выберите действие:\n 1)Какое выражение точнее\n 2)Округлить сомнительные цифры числа, оставив верные знаки.Определить абсолютную погрешность результата.\n 3)Найти предельные абсолютную и относительную погрешности приближенного числа, все цифры которого по умолчанию верные.\n" << endl;
	cin >> v;
	switch (v)
	{
	case 1:
		cout << "Введите число a" << endl;
		cin >> a;
		cout << "Введите число b" << endl;
		cin >> b;
		cout << "Введите число c" << endl;
		cin >> c;
		printf("%.0lf / %.0lf = %lf\n", a, b, a / b);
		printf("корень из %.0lf = %lf\n", c, sqrt(c));
		x = round((a / b) * 100) / 100;
		y = round(sqrt(c) * 100) / 100;
		printf("предельная абсолютная погрешность для первых двух чисел: %lf\n", fabs((a / b) - x));
		printf("предельная абсолютная погрешность второго числа: %lf\n", fabs(sqrt(c) - y));
		if (fabs((a / b) - x) < fabs(sqrt(c) - y))
		{
			cout << "1 выражение точнее" << endl;
		}
		else cout << "2 выражение точнее" << endl;
		break;
	case 2:
		cout << "Введите число: " << endl;
		cin >> chislo;
		cout << "Введите погрешность в процентах: ";
		cin >> f;
		for (int i = 1; i < 10; i++)
		{
			okr1 = trunc(f * pow(10, i)) / pow(10, i);
			okr2 = trunc(f * pow(10, i + 1)) / pow(10, i + 1);
			if (okr1 > f / 100)
			{
				z = okr2 - okr1;
				if (z > f / 100)
				{
					continue;
				}
				else
				{
					printf("%lf\n", okr1);
					break;
				}
			}
			else
			{
				printf("%lf\n", okr1);
				break;
			}

		}
		printf("%lf", okr1 * (f / 100));
		break;
	case 3:
		
		cout << endl << "Задание c" << endl;
		double exact_value;
		cout << "Введите значение: " << endl;
		cin >> exact_value;
		double approx_value;

		double num = exact_value;
		int numDigits = 0;
		while (abs(num - round(num)) > 1e-7) {
			num *= 10;
			numDigits++;
		}

		double abs_error_c = 5 / (pow(10, numDigits + 1));
		double rel_error_c = abs_error_c / exact_value * 100;
		cout << "Предельная абсолютная погрешность: " << abs_error_c << setprecision(6) << endl;
		cout << "Предельная относительная погрешность: " << rel_error_c << "%" << endl;

	}

}
