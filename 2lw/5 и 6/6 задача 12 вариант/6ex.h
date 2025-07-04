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
    ShipLoad(int num_places, int num_containers);  // �����������, ����������� ���������� ���� � �����������
    ~ShipLoad();  // ���������� ��� ������������ ��������
    int optimize(); // ������� ����������� �������� �������, ������������ ��������� �����������

private:
    int num_places;  
    int num_containers; 
    Container* containers;  // ��������� �� ������ �����������
    Place* places;  // ��������� �� ������ ���� �� �������
};