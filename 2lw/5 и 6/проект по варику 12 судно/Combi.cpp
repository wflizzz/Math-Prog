#include "Combi.h"
#include <iostream>
#include <algorithm>
#include <ctime>

namespace combi {
    ship_loading::ship_loading() {
        for (int i = 0; i < 8; i++) loaded[i] = -1; // ���������� ���������� �� ���������
        generate_data();
    }
    void ship_loading::generate_data() {
        srand(time(0)); // ������������� ���������� ��������� �����
        for (int i = 0; i < 8; i++) { // ��������� ����������
            containers[i].id = i + 1;
            containers[i].weight = rand() % 101 + 100;  // ��� 100-200 ��
            containers[i].profit = rand() % 91 + 10;   // ����� 10-100 �.�.
        }
        for (int i = 0; i < 5; i++) { // ��������� ����� �� �����
            places[i].min_weight = rand() % 71 + 50;   // ���. ��� 50-120 ��
            places[i].max_weight = rand() % 701 + 150; // ����. ��� 150-850 ��
            places[i].occupied = false; // ��� ����� ���������� ��������
        }
    }
    void ship_loading::optimize_loading() {
        // ��������� ���������� �� ������������ (����� ���)
        std::sort(containers, containers + 8, [](const Container& a, const Container& b) {
            return (double)a.profit / a.weight > (double)b.profit / b.weight;
            });
        for (int i = 0; i < 8; i++) { // ���������� ����������
            for (int j = 0; j < 5; j++) { // ���������� ����� �� �����
                if (!places[j].occupied && // ���� ����� ��������
                    containers[i].weight >= places[j].min_weight && // ��� ���������� ��������
                    containers[i].weight <= places[j].max_weight) {
                    loaded[i] = j; // ���������� �����, ���� �������� ���������
                    places[j].occupied = true; // �������� �����
                    break; // ������� � ���������� ����������
                }
            }
        }
    }
    void ship_loading::print_result() {
        int total_profit = 0;
        std::cout << "����������� ����������:\n";
        for (int i = 0; i < 8; i++) {
            if (loaded[i] != -1) { // ���� ��������� ��������
                std::cout << "��������� " << containers[i].id
                    << " -> ����� " << loaded[i] + 1
                    << " | ���: " << containers[i].weight
                    << " �� | �����: " << containers[i].profit << " �.�.\n";
                total_profit += containers[i].profit;
            }
        }
        std::cout << "����� �����: " << total_profit << " �.�.\n";
    }
}
