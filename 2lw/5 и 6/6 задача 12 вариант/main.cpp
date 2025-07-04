#include <iostream>
#include <fstream>
#include <chrono>
#include "6ex.h"

int main() {
    std::ofstream file("results.csv");
    file << "место время\n";

    for (int places = 4; places <= 8; places++) {
        auto start_time = std::chrono::high_resolution_clock::now();  // Засекаем время

        ShipLoad ship(places, 8); // Количество контейнеров - 8
        ship.optimize();

        auto end_time = std::chrono::high_resolution_clock::now();  // Останавливаем таймер
        double elapsed_time = std::chrono::duration<double, std::milli>(end_time - start_time).count(); // Время в миллисекундах

        std::cout << "Places: " << places << ", Time: " << elapsed_time << " ms\n";
        file << places << "," << elapsed_time << "\n";  // Запись в файл
    }

    file.close();
    std::cout << "рез сохр.csv\n";
    return 0;
}
