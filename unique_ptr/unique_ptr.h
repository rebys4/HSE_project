#ifndef UNIQUE_PTR_UNIQUE_PTR_H
#define UNIQUE_PTR_UNIQUE_PTR_H
#include <iostream>
#include <utility>
#include <cassert>

template <class T>
class UniquePtr {
  T* ptr_ = nullptr;

 public:
  UniquePtr() : ptr_(nullptr) {
  }
  explicit UniquePtr(T* ptr) : ptr_(ptr) {
  }
  UniquePtr(UniquePtr& ptr) {
    delete ptr_;
    ptr_ = ptr;
  }

  ~UniquePtr() {
    delete ptr_;
  }

  void Swap(UniquePtr& ptr) {
    std::swap(ptr_, ptr.ptr_);
  }

  T* Release() {
    T* old_ptr = ptr_;
    ptr_ = nullptr;
    return old_ptr;
  }

  void Reset(T* obj = nullptr) {
    if (ptr_ != obj) {
      delete ptr_;
      ptr_ = obj;
    }
  }

  T* Get() const {
    return ptr_;
  }

  UniquePtr(const UniquePtr&) = delete;
  UniquePtr& operator=(const UniquePtr&) = delete;
  UniquePtr(UniquePtr&& other) noexcept : ptr_(other.ptr_) {
    other.ptr_ = nullptr;
  }

  bool operator==(const UniquePtr<T>& ptr) const {
    return ptr_ == ptr;
  }
  bool operator==(std::nullptr_t) {
    return ptr_ == nullptr;
  }

  UniquePtr& operator=(UniquePtr&& ptr) noexcept {
    if (this != &ptr) {
      delete ptr_;
      ptr_ = ptr.ptr_;
      ptr.ptr_ = nullptr;
    }
    return *this;
  }

  T& operator*() const {
    assert(ptr_ != nullptr);
    return *ptr_;
  }

  T* operator->() const {
    assert(ptr_ != nullptr);
    return ptr_;
  };

  explicit operator bool() const {
    return ptr_ != nullptr;
  }
};

#endif  // UNIQUE_PTR_UNIQUE_PTR_H
