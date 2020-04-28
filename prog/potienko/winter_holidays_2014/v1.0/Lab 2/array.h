#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>
//���������, ��� ������� ��� ������ � ������ ������� ��������� �������
#include <cstdarg>

//�������� ���� ��� �������� ������������ ������
template <class Type>
class Array {
public:
	int length;
	Type* data;
	//����������� �� �����������
	Array() {
		length = 0;
		data = 0;
	}
	//����������� �����, ���� �� ����� ������� ���������
	//������� ��� ����, ��� ����� ���� ������ ������������ �����
	Array(int _length, ...) {
		va_list arguments;
		va_start(arguments, _length);
		length = _length;
		data = new Type[length];
		for (int i = 0; i < length; ++i) {
			data[i] = va_arg(arguments, Type);
		}
		va_end(arguments);
	}
	//���������� �����
	~Array() {
		//�� �� ��������� �������� �� ������ :(
		//delete[] data;
	}
	//�������������� ��������� [] ��� �������� ������������
	Type& operator[](int i) {
		return data[i];
	}
	//�������������� ��������� = ��� �������� ������������
	Array<Type>& operator=(Array<Type>* example) {
		length = example.length;
		for (int i = 0; i < length; ++i) data[i] = example[i];
	}
	//���� ������ �� �����
	void Print() {
		for (int i = 0; i < length - 1; ++i) std::cout << std::fixed << data[i] << ", ";
		if (length > 0) std::cout << std::fixed << data[length - 1] << endl;
	}
	//���� ������ ������
	void Resize(int _length) {
		length = _length;
		data = new Type[length];
	}
	//���������� ������ �������� ���������� ����������
	void Set(Type example) {
		for (int i = 0; i < length; ++i) data[i] = example;
	}
};

const double precision = 1e-2;
//��������� ���� ������ ������ �����
bool IsEqual(Array<double>& first, Array<double>& second) {
	bool result = false;
	//�������� ��������� �������
	if (first.length == second.length) {
		int i = 0;
		//��������� ����� ���� �������� � ������ �������
		while ((abs(first[i] - second[i]) < precision) && (i < first.length)) ++i;
		if (i == first.length) result = true;
	}
	return result;
}

#endif