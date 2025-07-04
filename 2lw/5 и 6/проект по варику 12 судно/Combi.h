#pragma once

namespace combi {
    struct ship_loading {  // ��������� ��� ���������� ��������� �����
        struct Container { // �������� ����������
            int id;       // ����� ����������
            int weight;   // ��� ����������
            int profit;   // ����� �� ���������
        };

        struct Place {  // �������� ����� �� �����
            int min_weight; // ����������� ���������� ��� ����������
            int max_weight; // ������������ ���������� ��� ����������
            bool occupied;  // ����, ������ �� �����
        };

        Container containers[8]; // ������ ����������� 
        Place places[5];         // ������ ���� 
        int loaded[8];           // � ����� ����� ��������� ��������� 

        ship_loading();      // ����������� (�������������)
        void generate_data(); // ��������� ��������� ������
        void optimize_loading(); // ����������� ��������
        void print_result();  // ����� ����������
    };
}

