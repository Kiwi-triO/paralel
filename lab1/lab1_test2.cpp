//Задание 2. Стандартными средствами OpenMP выполнить замер начального времени 
//(в секундах) и конечного времени, а также опреде-лить точность таймера OpenMP.

#include <iostream>
#include <omp.h>
using namespace std;

int main() {
	// Определяем точность таймера OpenMP
	cout << "Timer precision: " << omp_get_wtick() * 1e9 << " ns" << endl;

	// Замер начального времени выполнения
	double start = omp_get_wtime();

	// Параллельная операция для демонстрации
	int sum = 0;
#pragma omp parallel for reduction(+:sum)
	for (int i = 0; i < INT32_MAX; i++) {
		sum += i;
	}

	// Замер конечного времени выполнения
	double end = omp_get_wtime();

	// Вывод результатов измерений
	cout << "Start time: " << start << " s" << endl;
	cout << "End time: " << end << " s" << endl;
	cout << "Elapsed time: " << (end - start) * 1000 << " ms" << endl;
}
