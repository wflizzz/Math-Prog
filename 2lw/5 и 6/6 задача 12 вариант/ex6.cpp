#include "6ex.h"
#include <iostream>

ShipLoad::ShipLoad(int num_places, int num_containers) {
    this->num_places = num_places;
    this->num_containers = num_containers;

    srand(time(0));

    // Создание контейнеров
    containers = new Container[num_containers];
    for (int i = 0; i < num_containers; i++) {
        containers[i].weight = rand() % 101 + 100;  // Вес от 100 до 200 кг
        containers[i].profit = rand() % 91 + 10;   // Доход от 10 до 100 у.е.
    }

    // Создание мест на судне
    places = new Place[num_places];
    for (int i = 0; i < num_places; i++) {
        places[i].min_weight = rand() % 71 + 50;   // Минимальный вес от 50 до 120 кг
        places[i].max_weight = rand() % 701 + 150; // Максимальный вес от 150 до 850 кг
    }
}

ShipLoad::~ShipLoad() {
    delete[] containers;
    delete[] places;
}

// Простая жадная оптимизация загрузки контейнеров
int ShipLoad::optimize() {
    int total_profit = 0;
    int used_places = 0;

    for (int i = 0; i < num_containers && used_places < num_places; i++) {
        for (int j = 0; j < num_places; j++) {
            if (containers[i].weight >= places[j].min_weight &&
                containers[i].weight <= places[j].max_weight) {
                total_profit += containers[i].profit;
                used_places++;
                break;  // Контейнер загружен, идем к следующему
            }
        }
    }
    return total_profit;
}
