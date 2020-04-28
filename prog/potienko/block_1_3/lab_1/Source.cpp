//�����: ������ �������
//����� ������:
//������� f(x), ��������� �� ��������(a; b), ������ ���������� �������� ��
//����������� �����. �������� �� �������� ������� ������ ������� ��������� x
//�� ��������� � ��� ������� � ��� ������� �������� f(x), �������� �� �������� �� ��
//��������� � ���� ������� x, � ����� ������ �� ���� � ������� ������� �
//��������� �������� ���.
//�������� ��������� x ���� ���������� �� ��������� ���������. � ��������� ��
//�������� ��������� ������� ��� ���������(a; b), ����� �� �������� ��������.
//�������� �� ���������� ���������� �������� ���������, ����� ���������� ���
//������������� � ����������� �� ���������� ��������, ���� ���������� �� �����
//��������� ��������.
//� ������� �� ��������� �������� ��������� ����� ������� ��� �����. ������
//������ ���������, ����� ���������� x, f_lib(x), f_sum(x), difference, N_adds.
//������ � ������� �����, ���������� �� ���� ������������ �� ������� � ����
//�� ������ ����.
//ϳ��� ������ ������� �������� ������� �������� ����������� �� ���� ��
//������������ �� �.
//��� ������ ������� ��� ����������� ������ �1 - 1 - 4, �� �������� �� �� �������
//������. ���, ���� ������� �� �������� ����������� ������ 1 - 3 - 1 ��� �����
//�������� ������� �������.

#include <iostream>
#include <string>
#include "iolib.h"
#include "mathlib.h"
#include "table.h"

using namespace std;


double row[6];

int main(int argv, char** argc) {
	string userAnswer = "y";
	while (userAnswer == "y") {
		double x = -2.0;
		int m = 0;
		while (!F_check(x)) {
			cout << "Enter x in range (-1, 1): ";
			while (!TryToReadDouble(x)) {
				cout << "Error! Expected double" << endl;
				cout << "Enter x in range (-1, 1): ";
			}
			//������ ������� ����� ����� x
			if (!F_check(x)) cout << "Error! x should be in range (-1, 1)" << endl;
		}
		cout << "Enter natural m >> ";
		while (!TryToReadNatural(m)) {	
			cout << "Error! Expected natural number" << endl;
			cout << "Enter natural m: ";
		}
		//������ ������� ���������� m
		memset(row, 0, sizeof(double) * 5);
		row[0] = x;
		row[1] = double(m);
		row[2] = F_lib(x, m);
		int n_adds = 0;
		row[3] = F_sum(x, m, n_adds);
		row[4] = fabs(row[2] - row[3]);
		row[5] = double(n_adds);
		DrawTable(row);
		cout << "Do you want to continue? (y\\n): ";
		cin >> userAnswer;
	}
	system("pause");
	return 0;
}
