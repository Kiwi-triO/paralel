//Задание 2. Проиллюстрировать возможность директивы single, осуществив из параллельной области 
//печать сообщения лишь одним по-током (не обязательно главным)

#include <iostream>
#include <omp.h>
#include <locale.h>

using namespace std;

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, ".ACP"); // Установка локали для корректного отображения кириллицы

	// Устанавливаем количество потоков
	omp_set_num_threads(4);

	// Создаем параллельную область
#pragma omp parallel
	{
		// Каждый поток выводит сообщение о своем запуске
#pragma omp critical
		{
			cout << "Поток " << omp_get_thread_num() << " запущен" << endl;
		}

		// Используем директиву single для выполнения кода только одним потоком
		// Без барьера синхронизации в конце (nowait)
#pragma omp single nowait
		{
			cout << "=== Это сообщение напечатано потоком " << omp_get_thread_num()
				<< " (директива single) ===\n" << endl;
		}

		// Все потоки выполняют эту часть кода
#pragma omp for
		for (int i = 0; i < 10; i++) {
#pragma omp critical
			{
				cout << "Поток " << omp_get_thread_num() << " обрабатывает итерацию " << i << endl;
			}
		}
	}
}
