//������� 4. ������� ������� ����������� ������ �������� ��������� omp atomic, ��������������� �������������� �� ��������� ��
//��� �������� ������������. ��������� ������ ���������, �������� ���������, ������� ������������ ����� ������� � ������������ �������.

#include <stdio.h>
#include <omp.h>
#include <locale.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, ".ACP");
	int count = 0;
#pragma omp parallel
	{
#pragma omp atomic
		count++;
	}
	cout << "����� �������: " << count << endl;
}