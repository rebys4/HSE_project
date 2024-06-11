#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H

#include <iostream>
#include <stdexcept>

class ArrayOutOfRange : public std::out_of_range {
 public:
  ArrayOutOfRange() : std::out_of_range("ArrayOutOfRange") {
  }
};

template <class T, size_t N>
class Array {
 public:
  T array_[N];

  Array() = default;

  Array(std::initializer_list<T> list) {
    size_t i = 0;
    for (const auto& elem : list) {
      if (i < N) {
        array_[i++] = elem;
      } else {
        break;
      }
    }

    for (; i < N; i++) {
      array_[i] = T();
    }
  }

  ~Array() = default;

  T &operator[](size_t n) {
    return array_[n];
  }

  const T &operator[](size_t n) const {
    return array_[n];
  }

  const T &At(size_t idx) const {
    if (idx > N) {
      throw ArrayOutOfRange{};
    }
    return array_[idx];
  }

  T &At(size_t idx) {
    if (idx >= N) {
      throw ArrayOutOfRange{};
    }
    return array_[idx];
  }

  const T &Front() const {
    return array_[0];
  }

  T &Front() {
    return array_[0];
  }

  const T &Back() const {
    return array_[N - 1];
  }

  T &Back() {
    return array_[N - 1];
  }

  const T *Data() const {
    return array_;
  }

  T *Data() {
    return array_;
  }

  size_t Size() const {
    return N;
  }

  bool Empty() const {
    return N == 0;
  }

  void Fill(const T &value) {
    for (size_t i = 0; i < N; i++) {
      array_[i] = value;
    }
  }

  void Swap(Array<T, N> &other) {
    for (size_t i = 0; i < N; i++) {
      std::swap(array_[i], other.array_[i]);
    }
  }
};

#endif  // ARRAY_ARRAY_H
