//Задание 4. То же самое, что в задании 3, но с принудительной
//установкой нужного числа потоков (Разработать программу, в которой при входе в 
//параллельную область каждый из потоков OpenMP должен распечатать сообщение).

#include <iostream>
#include <cmath>
#include <omp.h>
#include <locale.h>

using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, ".ACP");
    
    cout << "Последовательная область 1" << endl;
    cout << "Количество потоков OMP = ";
    
    int N;
    cin >> N;
    cout << endl;
    
    N = abs(N);
    N = N ? N : 1;
    
    omp_set_dynamic(0); // Запрещает динамическую установку числа
    // потоков в следующих параллельных областях
    
    omp_set_num_threads(N); // Задает нужное число потоков
    // в следующей параллельной области
    
    #pragma omp parallel
    {
        cout << "Параллельная область 1" << endl;
    }
    
    cout << "Последовательная область 2" << endl;
    
    omp_set_dynamic(1); // Разрешает динамическую установку числа
    // потоков в следующих параллельных областях
    
    omp_set_num_threads(N);
    
    #pragma omp parallel
    {
        cout << "Параллельная область 2" << endl;
    }
    
    cout << "Последовательная область 3" << endl;
}

