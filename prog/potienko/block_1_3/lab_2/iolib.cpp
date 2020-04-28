#include <iostream>
#include "iolib.h"

using namespace std;

//�������� ������� ����� �����
bool TryToReadDouble(double& x) {
	bool result = 0;
	cin >> x;
	if (cin.good() && (cin.get() == '\n')) result = 1;
	else {
		cin.clear();
		cin.sync();
	}
	return result;
}

//�������� ������� ���������� �����
bool TryToReadNatural(int& m) {
	bool result = 0;
	cin >> m;
	if (cin.good() && (cin.get() == '\n') && (m > 0)) result = 1;
	else {
		cin.clear();
		cin.sync();
	}
	return result;
}