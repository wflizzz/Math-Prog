#include "Combi.h"
#include <iostream>
#include <algorithm>
#include <ctime>

namespace combi {
    ship_loading::ship_loading() {
        for (int i = 0; i < 8; i++) loaded[i] = -1; // Изначально контейнеры не размещены
        generate_data();
    }
    void ship_loading::generate_data() {
        srand(time(0)); // Инициализация генератора случайных чисел
        for (int i = 0; i < 8; i++) { // Заполняем контейнеры
            containers[i].id = i + 1;
            containers[i].weight = rand() % 101 + 100;  // Вес 100-200 кг
            containers[i].profit = rand() % 91 + 10;   // Доход 10-100 у.е.
        }
        for (int i = 0; i < 5; i++) { // Заполняем места на судне
            places[i].min_weight = rand() % 71 + 50;   // Мин. вес 50-120 кг
            places[i].max_weight = rand() % 701 + 150; // Макс. вес 150-850 кг
            places[i].occupied = false; // Все места изначально свободны
        }
    }
    void ship_loading::optimize_loading() {
        // Сортируем контейнеры по прибыльности (доход вес)
        std::sort(containers, containers + 8, [](const Container& a, const Container& b) {
            return (double)a.profit / a.weight > (double)b.profit / b.weight;
            });
        for (int i = 0; i < 8; i++) { // Перебираем контейнеры
            for (int j = 0; j < 5; j++) { // Перебираем места на судне
                if (!places[j].occupied && // Если место свободно
                    containers[i].weight >= places[j].min_weight && // Вес контейнера подходит
                    containers[i].weight <= places[j].max_weight) {
                    loaded[i] = j; // Запоминаем место, куда загружен контейнер
                    places[j].occupied = true; // Занимаем место
                    break; // Переход к следующему контейнеру
                }
            }
        }
    }
    void ship_loading::print_result() {
        int total_profit = 0;
        std::cout << "Загруженные контейнеры:\n";
        for (int i = 0; i < 8; i++) {
            if (loaded[i] != -1) { // Если контейнер загружен
                std::cout << "Контейнер " << containers[i].id
                    << " -> Место " << loaded[i] + 1
                    << " | Вес: " << containers[i].weight
                    << " кг | Доход: " << containers[i].profit << " у.е.\n";
                total_profit += containers[i].profit;
            }
        }
        std::cout << "Общий доход: " << total_profit << " у.е.\n";
    }
}
