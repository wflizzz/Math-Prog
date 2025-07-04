#include <iostream>
#include <ctime>
#include "Auxil.h"

#define CYCLE_COUNT 5  
#define FIB_TESTS 7    

int cycles[CYCLE_COUNT] = { 10000, 50000, 100000, 500000, 1000000 };
int fib_tests[FIB_TESTS] = { 10, 20, 30, 40, 50, 100, 200 };

long long fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    setlocale(LC_ALL, "rus");

    std::cout << "Зависимость времени от количества циклов\n";
    for (int i = 0; i < CYCLE_COUNT; i++) {
        double av1 = 0, av2 = 0;
        clock_t t1 = clock();

        for (int j = 0; j < cycles[i]; j++) {
            av1 += auxil::iget(-100, 100);
            av2 += auxil::dget(-100, 100);
        }

        clock_t t2 = clock();
        double elapsed_time = (double)(t2 - t1) / CLOCKS_PER_SEC;

        std::cout << "Циклы: " << cycles[i] << ", Время (сек): " << elapsed_time << std::endl;
    }

    std::cout << "\nВремя вычисления чисел Фибоначчи\n";
    for (int i = 0; i < FIB_TESTS; i++) {
        clock_t t1 = clock();
        long long fib = fibonacci(fib_tests[i]);
        clock_t t2 = clock();
        double elapsed_time = (double)(t2 - t1) / CLOCKS_PER_SEC;

        
    }

    system("pause");
    return 0;
}
