//�����: ������ �������
//����� ������: 
//������������ ������ ����� �����, ��� �������� ����� ���������� �� ���� �������� --name ��� �������� -n. 
//�������� ������� ��������� - �� ��'�, ��� ������� ����������� �������� � ����� �����������.
//���� �������� ��������, ��� �������� �� ������ ��'� �����������, � ������ ����� �����������. 
//���� ��������� �� ������ - �������� ����� ��'� ����������� � ���������.
//������ ������ �����: �������� ���� � ��������� ������, ��� � ������� ���������� --name ��� -n.
#include <iostream>
#include <string>

using namespace std;

int main(int argv, char** argc) {
	string name = "";
	if ((argv > 2) && ((strcmp(argc[1], "-n") == 0) || (strcmp(argc[1], "--name") == 0))) {
		for (int i = 2; i < argv; ++i) {
			name += argc[i];
			if (argv - i > 1) name += " ";
		}
	}
	else {
		cout << "Enter your name: ";
		cin >> name;
	}
	cout << "Hello " << name << "!" << endl;
	system("pause");
	return 0;
}