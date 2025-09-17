//Задание 2. При помощи опции ordered и директивы omp ordered внутри параллельного цикла гарантировать 
//выполнения операций в том порядке, как они выполнялись бы в последовательном цикле.

#include <iostream>
#include <omp.h>
#include <locale.h>
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, ".ACP");
	int thread_id;

	// Параллельный цикл с использованием ordered
#pragma omp parallel for ordered num_threads(4) private (thread_id)
	for (int i = 0; i < 10; i++) {
		// Эта часть выполняется параллельно
		thread_id = omp_get_thread_num();
		cout << "\nПоток " << thread_id << " обрабатывает итерацию " << i << " (параллельная часть)" << endl;

		// Эта часть выполняется в последовательном порядке
#pragma omp ordered
		{
			cout << "=== Упорядоченный вывод: итерация " << i << " (поток " << thread_id << ")" << endl;
		}
	}
}
