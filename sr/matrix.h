#include <vector>
#include <iostream>

//#ifndef SR_MATRIX_H
//#define SR_MATRIX_H

namespace fcs_math {

    struct Size {
        int nrows, ncols;
    };

    class Matrix {
    protected:
        std::vector<std::vector<int>> *matr;
        int nrows;
        int ncols;

    public:
        Matrix(std::vector<std::vector<int>> matr2);
        Matrix(Matrix &m);
        Matrix(int n, int m, int* fill_num = nullptr);
        void print();

        const Size get_size();

        const std::vector<std::vector<int>> get_data();

        ~Matrix();

        Matrix *add(Matrix &M);

        Matrix *mult(Matrix &M);

        Matrix *mult(int num);

        Matrix *subtract(Matrix &m);
    };
}
//#endif //SR_MATRIX_H
