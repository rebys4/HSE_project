#include <iostream>
#include "matrix.h"

int main() {
    std::vector<std::vector<int>> matr = std::vector<std::vector<int>>(5,std::vector<int>(3, 0));
    auto m = fcs_math::Matrix(matr);
    m.print();
    return 0;
}
