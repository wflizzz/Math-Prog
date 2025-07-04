#pragma once

namespace combi {
    struct ship_loading {  // Структура для управления загрузкой судна
        struct Container { // Описание контейнера
            int id;       // Номер контейнера
            int weight;   // Вес контейнера
            int profit;   // Доход от перевозки
        };

        struct Place {  // Описание места на судне
            int min_weight; // Минимальный допустимый вес контейнера
            int max_weight; // Максимальный допустимый вес контейнера
            bool occupied;  // Флаг, занято ли место
        };

        Container containers[8]; // Массив контейнеров 
        Place places[5];         // Массив мест 
        int loaded[8];           // В каком месте находится контейнер 

        ship_loading();      // Конструктор (инициализация)
        void generate_data(); // Генерация случайных данных
        void optimize_loading(); // Оптимальная загрузка
        void print_result();  // Вывод результата
    };
}

