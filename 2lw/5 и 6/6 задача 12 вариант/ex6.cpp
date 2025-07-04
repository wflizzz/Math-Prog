#include "6ex.h"
#include <iostream>

ShipLoad::ShipLoad(int num_places, int num_containers) {
    this->num_places = num_places;
    this->num_containers = num_containers;

    srand(time(0));

    // �������� �����������
    containers = new Container[num_containers];
    for (int i = 0; i < num_containers; i++) {
        containers[i].weight = rand() % 101 + 100;  // ��� �� 100 �� 200 ��
        containers[i].profit = rand() % 91 + 10;   // ����� �� 10 �� 100 �.�.
    }

    // �������� ���� �� �����
    places = new Place[num_places];
    for (int i = 0; i < num_places; i++) {
        places[i].min_weight = rand() % 71 + 50;   // ����������� ��� �� 50 �� 120 ��
        places[i].max_weight = rand() % 701 + 150; // ������������ ��� �� 150 �� 850 ��
    }
}

ShipLoad::~ShipLoad() {
    delete[] containers;
    delete[] places;
}

// ������� ������ ����������� �������� �����������
int ShipLoad::optimize() {
    int total_profit = 0;
    int used_places = 0;

    for (int i = 0; i < num_containers && used_places < num_places; i++) {
        for (int j = 0; j < num_places; j++) {
            if (containers[i].weight >= places[j].min_weight &&
                containers[i].weight <= places[j].max_weight) {
                total_profit += containers[i].profit;
                used_places++;
                break;  // ��������� ��������, ���� � ����������
            }
        }
    }
    return total_profit;
}
