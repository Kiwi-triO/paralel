//Задание 2. Проиллюстрировать возможность инициализации ло-кальных переменных, объявленных как threadprivate, 
//начальным значени-ем одноименной глобальной переменной из главного потока, при помощи опции copyin

#include <iostream>
#include <omp.h>
#include <locale.h>
using namespace std;

// Объявляем глобальную переменную, которая будет threadprivate
int global_var = 10;
#pragma omp threadprivate(global_var)

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, ".ACP");

	// Инициализируем глобальную переменную в главном потоке
	global_var = 100;
	cout << "Главный поток: global_var = " << global_var << endl;

	// Создаем параллельную область с использованием copyin
#pragma omp parallel copyin(global_var)
	{
		// Получаем номер текущего потока
		int thread_id = omp_get_thread_num();

		// Выводим значение переменной в каждом потоке
		// С опцией copyin все потоки должны получить значение из главного потока
		cout << "Поток " << thread_id << ": global_var = " << global_var << endl;

		// Изменяем значение переменной в каждом потоке
		global_var = 200 + thread_id;
		cout << "Поток " << thread_id << ": измененное global_var = " << global_var << endl;
	}

	// После параллельной области выводим значение в главном потоке
	// Оно должно остаться неизменным, так как threadprivate переменные
	// являются локальными для каждого потока
	cout << "Главный поток после параллельной области: global_var = " << global_var << endl;
}
