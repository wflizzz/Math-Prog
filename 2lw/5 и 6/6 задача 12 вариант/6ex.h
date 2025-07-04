#pragma once
#include <ctime>
#include <cstdlib>

struct Container {
    int weight;  
    int profit;  
};

struct Place {
    int min_weight;  
    int max_weight;  
};

class ShipLoad {
public:
    ShipLoad(int num_places, int num_containers);  // Конструктор, принимающий количество мест и контейнеров
    ~ShipLoad();  // Деструктор для освобождения ресурсов
    int optimize(); // Функция оптимизации загрузки корабля, возвращающая результат оптимизации

private:
    int num_places;  
    int num_containers; 
    Container* containers;  // Указатель на массив контейнеров
    Place* places;  // Указатель на массив мест на корабле
};