#include "matrix.h"

fcs_math::Matrix* fcs_math::Matrix::add(Matrix &m) {
    auto m_size = m.get_size();
    if (m_size.nrows != nrows || m_size.ncols != ncols) {
        return nullptr;
    }
    auto m_data = m.get_data();
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            (*matr)[i][j] += m_data[i][j];
        }
    }
    return this;

}

fcs_math::Matrix* fcs_math::Matrix::mult(Matrix &M) {
    if (this->ncols != M.get_size().nrows) {
        return nullptr;
    }
    auto m_data = M.get_data();
    std::vector<std::vector<int>> res (this->nrows, std::vector<int>(M.get_size().ncols, 0));
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < m_data[0].size(); j++) {
            for (int k = 0; k < ncols; k++) {
                res[i][j] += (*matr)[i][k] * m_data[k][j];
            }
        }
    }
    auto m_res = new Matrix(res);
    return m_res;
}

fcs_math::Matrix* fcs_math::Matrix::mult(int num) {
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            (*matr)[i][j] *= num;
        }
    }
    return this;
}

fcs_math::Matrix* fcs_math::Matrix::subtract(Matrix &m) {
    Matrix m_copy = Matrix(m);
    return this->add(*(m_copy.mult(-1)));
}
