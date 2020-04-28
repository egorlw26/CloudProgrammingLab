//�����: ������ �������
//����� ������: 
//�������� ��������, ��� ���� �������� ������, �� ����� ��������� ������� ������.
//f(x) = 1 / (sin(1 / 5) - log3(x)) <=> 1 / (sin(1 / 5) - log(x) / log(3))
//������ ������� ������: � ��������� ��������� ����� ����� x, ������� ������� �� ����� ����� ����� f(x)

#include <iostream>
#include <cmath>

#define Zero 1e-15

using namespace std;

//���������� ���������� �� ��������
double Eval(double x) {
	return (1.0f / (sin(1.0f / 5.0f) - log(x) / log(3.0f)));
}

int main(int argv, char** argc) {
	cout << "Enter argument for function f(x) >> ";
	double x = 0;
	cin >> x;
	cout.precision(15);
	//�������� ��������� � ������� ����������� x � ������� ���������� ������� f(x)
	if ((x > 0) && (abs(sin(1.0f / 5.0f) - log(x) / log(3.0f)) > Zero)) cout << Eval(x) << endl;
	system("pause");
	return 0;
}