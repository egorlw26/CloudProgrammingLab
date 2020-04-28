//�����: ������ �������
//����� ������: 
//������������ ����������� ������ ��������� �����: ���� ������ ����������� ������ ��� ����������� ��� ������������ 
//�������� ������� �������� � ����������� �� ���� �� ����������. ���� �� ����� ������ ������ "���", 
//��� �������� ������� ����� ������ �������� � ���������
//������ ������� ������: � ��������� ��������� ������, ������� ������� �� ����� ����� ����� f(x)

#include <iostream>
#include <cmath>
#include <string>

#define Zero 1e-15

using namespace std;

//��������� ������� � ��������� ����� �����, ��������� True � ������� �����, ������ False
bool TryToReadDouble(double& x)
{
	bool result = 0;
	cin >> x;
	if (cin.good() && (cin.get() == '\n')) result = 1;
	else {
		cin.clear();
		cin.sync();
	}
	return result;
}

//���������� ���������� �� ��������
double Eval(double x) {
	return (1.0f / (sin(1.0f / 5.0f) - log(x) / log(3.0f)));
}

int main(int argv, char** argc) {
	bool goOn = 1;
	string answer = "";
	while (goOn) {
		cout << "Enter argument for function f(x) >> ";
		double x = 0;
		//����������� ����������� ��� �������, ���� �� ���� ������� ����� �����
		if (TryToReadDouble(x) == 0) cout << "Error while reading!" << endl << "Waiting for a double and got string" << endl;
		else {
			cout.precision(15);
			//�������� ��������� � ������� ����������� x � ������� ���������� ������� f(x)
			if ((x > 0) && (abs(sin(1.0f / 5.0f) - log(x) / log(3.0f)) > Zero)) cout << Eval(x) << endl;
			//����������� ����������� ��� �������, ���� x �� ��������� � ������� ���������� ������� f(x)
			else cout << "Error while evaluating!" << endl << "Argument isn't in domain of function f(x)" << endl;
		}
		//�������� � ����������� �� �� ���� �� ���������� ������ � ���������
		cout << "Do you want to continue? (y//n)";
		cin >> answer;
		goOn = (answer == "y");
	}
	system("pause");
	return 0;
}