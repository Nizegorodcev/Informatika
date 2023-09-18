#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
double Newton_Leybnits(double a, double b) {
	return sqrt(b * b + 1) - sqrt(a * a + 1);
}
double F(double value) {
	return value / pow(value * value + 1, 0.5);
}
double function1(double a, double b, int n) //Метод  левых прямоугольников
{
	double h = (b - a) / n;
	double integral = 0;
	for (int i = 1; i < n; i++) {
		double x_i = a + i * h;
		integral += F(x_i);
	}
	integral = h * integral;
	return integral;
}
double function2(double a, double b, int n) //Метод  правых прямоугольников
{
	double h = (b - a) / n;
	double integral = 0;
	for (int i = 1; i <= n; i++) {
		double x_i = a + i * h;
		integral += F(x_i);
	}
	integral = h * integral;
	return integral;
}
double function3(double a, double b, int n) //Метод  средних прямоугольников
{
	double h = (b - a) / n;
	double integral = 0;
	for (int i = 1; i < n; i++) {
		double x_i = a + (i+0.5) * h;
		integral += F(x_i);
	}
	integral = h * integral;
	return integral;
}
double function4(double a, double b, int n) //Метод Трапеций
{
	double h = (b - a) / n;
	double S = 0;
	for (int i = 1; i < n - 1; i++) {
		S = S + F(a + i * h);
	}
	double L = h * ((F(a) + F(b)) / 2 + S);
	return L;
}
double function5(double a, double b, int n) //Метод Симпсона
{
	if (n % 2 != 0) {
		cout << "n должно быть четным" << endl;
		return 0;
	}
	double h = (b - a) / n;
	double S = 0;
	double S1 = 0;
	double S2 = 0;
	for (int i = 1; i < n - 1; i++) {
		if (i % 2 == 0) {
			S1 = S1 + F(a + i * h);
		}
		else {
			S2 = S2 + F(a + i * h);
		}
	}
	double L = h / 3 * (F(a) + F(b) + 2 * S1 + 4 * S2);
	return L;
}
void main() {
	setlocale(LC_ALL, "rus");
	int choose;
	double a = 2.2;
	double b = 3.4;
	int n1 = 10;
	int n2 = 50;
	int n3 = 100;
	double res,res1,res2;
	double res0 = Newton_Leybnits(a, b);
	while (true) {
		cout << "Каким методом хотите найти?\n1)Метод левых прямоугольников\n2)Метод правых прямоугольников\n3)Метод средних прямоугольников\n4)Метод трапеций\n5)Метод Симпсона\n0)Выход" << endl;
		cin >> choose;
		switch (choose) {
		case 1:
			res = function1(a, b, n1);
			cout << "Результат для n=10:"<<res << endl;
			cout << "Абсолютная погрешность для n=10 " << std::setprecision(4) << fabs(res0 - res) << endl;
			res1 = function1(a, b, n2);
			cout << "Результат для n=50:" << res1 << endl;
			cout << "Абсолютная погрешность для n=50 " << setprecision(4) <<fabs(res0 - res1) << endl;
			res2 = function1(a, b, n3);
			cout << "Результат для n=100:" << res2 << endl;
			cout << "Абсолютная погрешность для n=100 " << setprecision(4) <<fabs(res0 - res2) << endl;
			break;
		case 2:
			res = function2(a, b, n1);
			cout << "Результат для n=10:" << res << endl;
			cout << "Абсолютная погрешность для n=10 " << std::setprecision(4) << fabs(res0 - res) << endl;
			res1 = function2(a, b, n2);
			cout << "Результат для n=50:" << res1 << endl;
			cout << "Абсолютная погрешность для n=50 " << setprecision(4) << fabs(res0 - res1) << endl;
			res2 = function2(a, b, n3);
			cout << "Результат для n=100:" << res2 << endl;
			cout << "Абсолютная погрешность для n=100 " << setprecision(4) << fabs(res0 - res2) << endl;
			break;
		case 3:
			res = function3(a, b, n1);
			cout << "Результат для n=10:" << res << endl;
			cout << "Абсолютная погрешность для n=10 " << std::setprecision(4) << fabs(res0 - res) << endl;
			res1 = function3(a, b, n2);
			cout << "Результат для n=50:" << res1 << endl;
			cout << "Абсолютная погрешность для n=50 " << setprecision(4) << fabs(res0 - res1) << endl;
			res2 = function3(a, b, n3);
			cout << "Результат для n=100:" << res2 << endl;
			cout << "Абсолютная погрешность для n=100 " << setprecision(4) << fabs(res0 - res2) << endl;
			break;
		case 4:
			res = function4(a, b, n1);
			cout << "Результат для n=10:" << res << endl;
			cout << "Абсолютная погрешность для n=10 " << std::setprecision(4) << fabs(res0 - res) << endl;
			res1 = function4(a, b, n2);
			cout << "Результат для n=50:" << res1 << endl;
			cout << "Абсолютная погрешность для n=50 " << setprecision(4) << fabs(res0 - res1) << endl;
			res2 = function4(a, b, n3);
			cout << "Результат для n=100:" << res2 << endl;
			cout << "Абсолютная погрешность для n=100 " << setprecision(4) << fabs(res0 - res2) << endl;
			break;
		case 5:
			res = function5(a, b, n1);
			cout << "Результат для n=10:" << res << endl;
			cout << "Абсолютная погрешность для n=10 " << std::setprecision(4) << fabs(res0 - res) << endl;
			res1 = function5(a, b, n2);
			cout << "Результат для n=50:" << res1 << endl;
			cout << "Абсолютная погрешность для n=50 " << setprecision(4) << fabs(res0 - res1) << endl;
			res2 = function5(a, b, n3);
			cout << "Результат для n=100:" << res2 << endl;
			cout << "Абсолютная погрешность для n=100 " << setprecision(4) << fabs(res0 - res2) << endl;
			break;
		}
		if (choose == 0) break;
		else continue;
	}
	
	
}