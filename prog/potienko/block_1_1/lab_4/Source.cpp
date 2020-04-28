//�����: ������ �������
//����� ������: 
//���������� ������� ����� �������(������� ����� �� ������� ���������). 
//���� ������� ������ ������ ���������(� ��������). ���� �������� ������� �������(�������� ���� 1-�� �����, ���� ���� ������ � �.�.).
//�������� ������� ������� ������ �������� ������� � ������: ����������� ���� - "|", ������������� ���� - "-", ������� - "+". 
//����� ������� �� �������� ������� �������� � ����, �� ��� ���������� ���������.
//������ ������ �����: �������� ����� � ��������� ������ �������, ������ �������(� ��������), ��� �������.
#include <iostream>

using namespace std;

int rows = 0, cols = 0;
int width = 0;

void WriteSeparator() {
	for (int i = 0; i < cols; ++i) {
		cout << '+';
		for (int j = 0; j < width; ++j) cout << '-';
	}
	cout << '+' << endl;
}

int main() {
	cout << "Enter number of rows: ";
	cin >> rows;
	cout << "Enter number of columns: ";
	cin >> cols;
	//��������� ��������� ����� ��������� (a * b)
	int** table = new int*[cols];
	for (int i = 0; i < rows; ++i) table[i] = new int[rows];
	cout << "Enter width of cell: ";
	cin >> width;
	for (int i = 0; i < rows; ++i) {
		cout << "Enter data for " << i + 1 << " line: ";
		for (int j = 0; j < cols; ++j) cin >> table[i][j];
	}
	for (int i = 0; i < rows; ++i) {
		WriteSeparator();
		cout << '|';
		for (int j = 0; j < cols; ++j) {
			cout.width(width);
			cout << table[i][j] << '|';
		}
		cout << endl;
	}
	WriteSeparator();
	//��������� � ���'�� ��������� �����
	for (int i = 0; i < rows; ++i) delete[] table[i];
	delete[] table;
	system("pause");
	return 0;
}