//Задание 6. При помощи операции редукции определить фактическое число порожденных потоков OpenMP

#include <iostream>
#include <omp.h>
#include <locale.h>
using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, ".ACP");
    
    int count = 0;
    
    #pragma omp parallel reduction(+:count)
    {
        count++;
        cout << "Текущее значение count: " << count << endl;
    }
    
    cout << "Количество потоков: " << count << endl;
}
