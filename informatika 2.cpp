#include<iostream>
#include<Windows.h>
#include <iomanip>
#include<cmath>
using namespace std;
void task5b()
{
	float eps, x_rez = 0, x = 1;
	int i = 1;
	/*
	x-подсчёт каждого элемента
	eps-точность
	x_rez-результат
	i-счётчик итераций
	*/

	cout << "Введите точность" << endl;
	cin >> eps;


	printf("---------------------------------------------------------------------------\n");
	printf("| Точность | Сравниваемое значение | Полученное значение | Номер итерации |\n");
	printf("---------------------------------------------------------------------------\n");
	do
	{
		x = 1.f + 1.f / i;
		x_rez = powf(x, i);
		i++;
		printf("|%10f|%23f|%21f|%16d|\n", eps, exp(1.0), x_rez, i - 1);
		printf("---------------------------------------------------------------------------\n");
	} while (!(x_rez >= exp(1.0) - eps && x_rez <= exp(1.0) + eps));

	cout << "Результат = " << x_rez << endl;

}
void task5a()
{
	float x, eps, x_rez;
	int i = 0;
	/*
	x-вычисление элемента
	eps-точность
	x_rez-результат
	i-счётчик итераций
	*/

	cout << "Введите точность" << endl;
	cin >> eps;

	printf("---------------------------------------------------------------------------\n");
	printf("| Точность | Сравниваемое значение | Полученное значение | Номер итерации |\n");
	printf("---------------------------------------------------------------------------\n");
	do
	{
		x = 1 / pow(2, i);
		x_rez = sinf(x) / x;
		i++;
		printf("|%10f|%23f|%21f|%16d|\n", eps, 1, x_rez, i - 1);
		printf("---------------------------------------------------------------------------\n");
	} while (!(x_rez >= 1 - eps && x_rez <= 1 + eps));

	cout << "Результат = " << x_rez << endl;

}
void task4()
{
	float n, a = 1, b = 1;
	float res=a*b, a_next, b_next;
	cout << "Введите n" << endl;
	cin >> n;
	printf("| Номер итерации | Значение a | Значение b |  Результат  |\n");
	printf("----------------------------------------------------------\n");
	printf("|%16d|%12f|%12f|%13f|\n", 1, a, b, res);
	printf("----------------------------------------------------------\n");

	for (int k = 2; k <= n; k++)
	{
		a_next = 1.f / 2.f * (sqrt(b) + a / 2.f);
		b_next = 2.f * a * a + b;

		printf("|%16d|%12f|%12f|%13f|\n", k, a_next, b_next, res + b_next * a_next);
		printf("----------------------------------------------------------\n");
		a = a_next;
		b = b_next;

		res += a * b;
		cout << "Результат = " << res << endl;
	}

}
void task2()
{
	float a, a_rez, E;
	int i = 0;
	/*
	a-результат, полученный с помощью разложения в ряд
	a_rez-результат, полученный с помощью формулы pow(a, 1/3)
	E-точность
	i-количество итераций
	*/

	cout << "Введите число" << endl;
	cin >> a;
	cout << "Введите точность" << endl;
	cin >> E;

	a_rez = powf(a, 1.f / 3.f);
	float a_lim = a / 3.f;

	printf("_______________________________________________________________________________________________________________\n");
	printf("|  Число  | Точность | Функция pow(a, 1/3) | Предел последовательности | Номер итерации | Разность результатов|\n");
	printf("_______________________________________________________________________________________________________________\n");

	do
	{
		printf("|%9f|%10f|%21f|%27f|%16d|%21f|\n", a, E, a_rez, a_lim, i + 1, fabs(a_rez - a_lim));
		printf("--------------------------------------------------------------------------------------------------------------\n");
		a_lim = (2.f / 3.f) * (a_lim + a / (2.f * a_lim * a_lim));
		i++;
	} while (fabs(a_rez - a_lim) > E);

	cout << a_lim << "  " << a_rez << " при " << i << " - итераций" << endl;
}


double task3(int n, int i)
{
	return sin(n + (i / n));
}
int factorial(int x)
{
	int res = 1;
	for (int i = 1; i < x + 1; i++)
	{
		res *= i;
	}
	return res;
}

double function(int x,int i)
{
	return pow(-1, i) * pow(x, 2 * i) / (factorial((2 * i) + 1));
}
void main()
{
	int x;
	int a;
	int v;
	double R,x0;
	double res1, res2, res3;;
	double e1 = 0.1;
	double e2 = 0.000001;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Выберите действие:\n1)Задание 1\n2)Задание 2\n3)Задание 3\n4)Задание 4\n5)Задание 5-a"<<"6)Задание 5-б" << endl;
	cin >> v;
	switch (v)
	{
	case 1:
		cout << "Введите х" << endl;
		cin >> x;
		res1 = function(x, 0);
		res2 = function(x, 1);
		R = res2 / res1;
		double okrres;
		//Для е1
		cout << "Для е1" << endl;
		res1 = round(res1 * 10) / 10;
		res2 = round(res2 * 10) / 10;
		cout << "|x |f(x)                    |e1           |" << endl;
		cout << "| " << x << "| " << res1 << "                           " << e1 << endl;
		cout << "| " << x << "| " << res2 << "                           " << e1 << endl;
		for (int i = 2; i != 0; i++)
		{
			res3 = R * (function(x, i - 1));
			okrres = round(res3 * 10) / 10;
			cout << "| " << x << "| " << okrres << "                         " << e1 << endl;
			if (fabs(res3 - function(x, i - 1)) < e1 || fabs(res3 - okrres < e1))
			{
				break;
			}
		}
		cout << "Для е2" << endl;
		res1 = function(x, 0);
		res2 = function(x, 1);
		res1 = round(res1 * 1000000) / 1000000;
		res2 = round(res2 * 1000000) / 1000000;
		//Для е2
		cout << "|x |f(x)                    |e2           |" << endl;
		cout << "| " << x << "| " << res1 << "                       " << e2 << endl;
		cout << "| " << x << "| " << res2 << "                       " << e2 << endl;
		for (int i = 2; i != 0; i++)
		{
			res3 = R * (function(x, i - 1));
			okrres = round(res3 * 1000000) / 1000000;
			cout << "| " << x << "| " << okrres << "                     " << e2 << endl;
			if (fabs(res3 - function(x, i - 1)) < e2 || fabs(res3 - okrres < e2))
			{
				break;
			}
		}
		break;
	case 2:
		task2();
		break;
	case 3:
		int n;
		cout << "Введите n" << endl;
		cin >>n;
		double res,min;
		min = task3(n, 0);
		for (int i = 1; i <n+1; i++)
		{
			res = task3(n, i);
			if (min > res)
			{
				min = res;
			}
		}
		cout << "Минимум функции: " << min << endl;
		break;
	case 4:
		task4();
		break;
	case 5:
		task5a();
		break;
	case 6:
		task5b();
		break;
	}
	
}
