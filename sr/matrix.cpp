#include "matrix.h"
#include <random>

fcs_math::Matrix::Matrix(std::vector<std::vector<int>> matr2) {
    unsigned short int nrows = matr2.size(),
            ncols = matr2[0].size();

    matr = new std::vector<std::vector<int>>(nrows, std::vector<int>(ncols, 0));

    for (int i = 0; i < nrows; i++)
        for (int j = 0; j < ncols; j++)
            (*matr)[i][j] = matr2[i][j];
    this->nrows = nrows;
    this->ncols = ncols;
}

fcs_math::Matrix::Matrix(int n, int m, int* fill_num) {
    matr = new std::vector<std::vector<int>>(n, std::vector<int>(m, 0));

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (fill_num == nullptr) {
                (*matr)[i][j] = dist6(rng);
            } else {
                (*matr)[i][j] = *fill_num;
            }
        }
    }
    this->nrows = n;
    this->ncols = m;
}


void fcs_math::Matrix::print() {
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            std::cout << (*matr)[i][j] << " ";
        }
        std::cout << "\n";
    }
}

fcs_math::Matrix::Matrix(Matrix &m) {
    auto size = m.get_size();
    unsigned short int nrows = size.nrows,
            ncols = size.ncols;

    matr = new std::vector<std::vector<int>>(nrows, std::vector<int>(ncols, 0));
    *matr = m.get_data();
    this->nrows = nrows;
    this->ncols = ncols;
}


const fcs_math::Size fcs_math::Matrix::get_size() {
    auto size = Size();
    size.nrows = nrows;
    size.ncols = ncols;
    return size;
}

const std::vector<std::vector<int>> fcs_math::Matrix::get_data() {
    return *matr;
}

fcs_math::Matrix::~Matrix() {
    delete matr;
    matr = nullptr;
}



