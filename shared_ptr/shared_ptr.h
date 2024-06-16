#ifndef SHARED_PTR_SHARED_PTR_H
#define SHARED_PTR_SHARED_PTR_H
#include <iostream>
#include <utility>

template <typename T>
class SharedPtr {
 private:
  T* ptr_;
  int* counter_;

  void Release() {
    if (counter_) {
      (*counter_)--;
      if (*counter_ == 0) {
        delete ptr_;
        delete counter_;
      }
    }
  }

 public:
  // Конструктор по умолчанию
  SharedPtr() : ptr_(nullptr), counter_(nullptr) {}

  // Конструктор от указателя
  explicit SharedPtr(T* p) : ptr_(p), counter_(new int(1)) {}

  // Конструктор копирования
  SharedPtr(const SharedPtr& other) : ptr_(other.ptr_), counter_(other.counter_) {
    if (ptr_) {
      (*counter_)++;
    }
  }

  // Оператор копирующего присваивания
  SharedPtr& operator=(const SharedPtr& other) {
    if (this != &other) {
      Release();
      ptr_ = other.ptr_;
      counter_ = other.counter_;
      if (ptr_) {
        (*counter_)++;
      }
    }
    return *this;
  }

  // Перемещающий конструктор
  SharedPtr(SharedPtr&& other) noexcept : ptr_(other.ptr_), counter_(other.counter_) {
    other.ptr_ = nullptr;
    other.counter_ = nullptr;
  }

  // Оператор перемещающего присваивания
  SharedPtr& operator=(SharedPtr&& other) noexcept {
    if (this != &other) {
      Release();
      ptr_ = other.ptr_;
      counter_ = other.counter_;
      other.ptr_ = nullptr;
      other.counter_ = nullptr;
    }
    return *this;
  }

  // Деструктор
  ~SharedPtr() {
    Release();
  }

  // Метод Reset
  void Reset(T* p = nullptr) {
    Release();
    ptr_ = p;
    if (ptr_) {
      counter_ = new int(1);
    } else {
      counter_ = nullptr;
    }
  }

  // Метод Swap
  void Swap(SharedPtr& other) {
    std::swap(ptr_, other.ptr_);
    std::swap(counter_, other.counter_);
  }

  // Метод Get
  T* Get() const {
    return ptr_;
  }

  // Метод UseCount
  int UseCount() const {
    return ptr_ ? *counter_ : 0;
  }

  // Оператор разыменовывания
  T& operator*() const {
    return *ptr_;
  }

  // Оператор "стрелочка"
  T* operator->() const {
    return ptr_;
  }

  // Явный оператор приведения к bool
  explicit operator bool() const {
    return ptr_ != nullptr;
  }
};

#endif  // SHARED_PTR_SHARED_PTR_H
