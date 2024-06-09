#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H
#include <iostream>
#include <stdexcept>

class MatrixIsDegenerateError : public std::runtime_error {
 public:
  MatrixIsDegenerateError() : std::runtime_error("MatrixIsDegenerateError") {
  }
};

class MatrixOutOfRange : public std::out_of_range {
 public:
  MatrixOutOfRange() : std::out_of_range("MatrixOutOfRange") {
  }
};

template <class T, size_t Rows, size_t Cols>
class Matrix {

 public:
  T matrix[Rows][Cols];

  Matrix() {
    for (size_t i = 0; i < Rows; i++) {
      for (size_t j = 0; j < Cols; j++) {
        matrix[i][j] = T{};
      }
    }
  }
  Matrix(std::initializer_list<std::initializer_list<T>> list) {
    size_t i = 0;
    for (auto row = list.begin(); row != list.end(); row++) {
      size_t j = 0;
      for (auto col = row->begin(); col != row->end(); col++) {
        matrix[i][j] = (*col);
        j++;
      }
      i++;
    }
  }

  Matrix(std::initializer_list<T> list) {
    for (size_t i = 0; i < Rows; i++) {
      for (size_t j = 0; j < Cols; j++) {
        matrix[i][j] = *(list.begin() + i * Cols + j);
      }
    }
  }

  size_t RowsNumber() const {
    return Rows;
  }

  size_t ColumnsNumber() const {
    return Cols;
  }

  const T &operator()(size_t i, size_t j) const {
    return matrix[i][j];
  }

  T &At(size_t i, size_t j) const {
    if (i >= Rows || j >= Cols) {
      throw MatrixOutOfRange();
    }
    return (*this(i, j));
  }

//  T& At(size_t i, size_t j) const {
//    if (i >= Rows || j >= Cols) {
//      throw MatrixOutOfRange();
//    }
//    return *(this(i, j));
//  }

  Matrix<T, Rows, Cols> &operator+=(const Matrix<T, Rows, Cols> &matr) {
    Matrix<T, Rows, Cols> out_matr{};
    for (size_t i = 0; i < Rows; i++) {
      for (size_t j = 0; j < Cols; j++) {
        (*this)(i, j) += matr(i, j);
      }
    }
    return *this;
  }
  Matrix<T, Rows, Cols> &operator-=(const Matrix<T, Rows, Cols> &matr) {
    Matrix<T, Rows, Cols> out_matr{};
    for (size_t i = 0; i < Rows; i++) {
      for (size_t j = 0; j < Cols; j++) {
        (*this)(i, j) -= matr(i, j);
      }
    }
    return *this;
  }

  bool operator==(const Matrix<T, Rows, Cols> &matr) const {
    for (size_t i = 0; i < Rows; i++) {
      for (size_t j = 0; j < Cols; j++) {
        if ((*this)(i, j) != matr(i, j)) {
          return false;
        }
      }
    }
    return true;
  }

  bool operator!=(const Matrix<T, Rows, Cols> &other) const {
    return *this != other;
  }

  friend std::istream &operator>>(std::istream &is, Matrix<T, Rows, Cols> &matr) {
    for (size_t i = 0; i < Rows; i++) {
      for (size_t j = 0; j < Cols; j++) {
        is >> matr(i, j);
      }
    }
    return is;
  }

  friend std::ostream &operator<<(std::ostream &os, Matrix<T, Rows, Cols> &matr) {
    for (size_t i = 0; i < Rows; i++) {
      for (size_t j = 0; j < Cols; j++) {
        os << matr(i, j) << " ";
      }
      os << "\n";
    }
    return os;
  }

  template <size_t OtherCols>
  Matrix<T, Rows, OtherCols> operator*(Matrix<T, Cols, OtherCols> &other) {
    Matrix<T, Rows, OtherCols> out_matr{};
    for (size_t i = 0; i < Rows; i++) {
      for (size_t j = 0; j < OtherCols; j++) {
        for (size_t k = 0; k < Rows; k++) {
          out_matr(i, j) += (*this)(i, k) * other(i, j);
        }
      }
    }
    return out_matr;
  }
  template <size_t OtherCols>
  Matrix<T, Rows, OtherCols>& operator*=(const Matrix<T, Cols, OtherCols>& other) {
    Matrix<T, Rows, OtherCols> temp;
    for (size_t i = 0; i < Rows; i++) {
      for (size_t j = 0; j < OtherCols; j++) {
        temp(i, j) = T{};
        for (size_t k = 0; k < Cols; k++) {
          temp(i, j) += (*this)(i, k) * other(k, j);
        }
      }
    }
    *this = temp;
    return *this;
  }
};

template <class T, size_t Cols, size_t Rows>
Matrix<T, Cols, Rows> GetTransposed(Matrix<T, Rows, Cols> &matr) {
  Matrix<T, Cols, Rows> out_matr{};
  for (size_t i = 0; i < Rows; i++) {
    for (size_t j = 0; j < Cols; j++) {
      out_matr(i, j) = matr(j, i);
    }
  }
  return out_matr;
}

template <class T, size_t Rows, size_t Cols>
Matrix<T, Rows, Cols> operator+(Matrix<T, Rows, Cols> &frst, Matrix<T, Rows, Cols> &sec) {
  Matrix<T, Rows, Cols> out_matr{};
  out_matr += frst;
  out_matr += sec;
  return out_matr;
}

template <class T, size_t Rows, size_t Cols>
Matrix<T, Rows, Cols> operator-(Matrix<T, Rows, Cols> &frst, Matrix<T, Rows, Cols> &sec) {
  Matrix<T, Rows, Cols> out_matr{};
  out_matr -= frst;
  out_matr -= sec;
  return out_matr;
}

#endif  // MATRIX_MATRIX_H