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
	cout << "�������� ��������:\n �������� ��������:\n 1)����� ��������� ������\n 2)��������� ������������ ����� �����, ������� ������ �����.���������� ���������� ����������� ����������.\n 3)����� ���������� ���������� � ������������� ����������� ������������� �����, ��� ����� �������� �� ��������� ������.\n" << endl;
	cin >> v;
	switch (v)
	{
	case 1:
		cout << "������� ����� a" << endl;
		cin >> a;
		cout << "������� ����� b" << endl;
		cin >> b;
		cout << "������� ����� c" << endl;
		cin >> c;
		printf("%.0lf / %.0lf = %lf\n", a, b, a / b);
		printf("������ �� %.0lf = %lf\n", c, sqrt(c));
		x = round((a / b) * 100) / 100;
		y = round(sqrt(c) * 100) / 100;
		printf("���������� ���������� ����������� ��� ������ ���� �����: %lf\n", fabs((a / b) - x));
		printf("���������� ���������� ����������� ������� �����: %lf\n", fabs(sqrt(c) - y));
		if (fabs((a / b) - x) < fabs(sqrt(c) - y))
		{
			cout << "1 ��������� ������" << endl;
		}
		else cout << "2 ��������� ������" << endl;
		break;
	case 2:
		cout << "������� �����: " << endl;
		cin >> chislo;
		cout << "������� ����������� � ���������: ";
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
		
		cout << endl << "������� c" << endl;
		double exact_value;
		cout << "������� ��������: " << endl;
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
		cout << "���������� ���������� �����������: " << abs_error_c << setprecision(6) << endl;
		cout << "���������� ������������� �����������: " << rel_error_c << "%" << endl;

	}

}