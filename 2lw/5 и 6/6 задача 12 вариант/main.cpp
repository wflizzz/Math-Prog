#include <iostream>
#include <fstream>
#include <chrono>
#include "6ex.h"

int main() {
    std::ofstream file("results.csv");
    file << "����� �����\n";

    for (int places = 4; places <= 8; places++) {
        auto start_time = std::chrono::high_resolution_clock::now();  // �������� �����

        ShipLoad ship(places, 8); // ���������� ����������� - 8
        ship.optimize();

        auto end_time = std::chrono::high_resolution_clock::now();  // ������������� ������
        double elapsed_time = std::chrono::duration<double, std::milli>(end_time - start_time).count(); // ����� � �������������

        std::cout << "Places: " << places << ", Time: " << elapsed_time << " ms\n";
        file << places << "," << elapsed_time << "\n";  // ������ � ����
    }

    file.close();
    std::cout << "��� ����.csv\n";
    return 0;
}
