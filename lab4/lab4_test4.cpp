//«адание 4. „астным случаем критических секций €вл€етс€ директива omp atomic, непосредственно воздействующа€ на следующий за
//ней оператор присваивани€. »спользу€ данную директиву, написать программу, котора€ подсчитывает число потоков в параллельной области.

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
	cout << "„исло потоков: " << count << endl;
}