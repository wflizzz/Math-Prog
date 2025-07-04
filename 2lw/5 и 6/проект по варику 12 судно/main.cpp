#include <iostream>
#include "Combi.h"

int main() {
    setlocale(LC_ALL, "rus");

    combi::ship_loading loader;
    loader.optimize_loading();
    loader.print_result();

    system("pause");
    return 0;
}
