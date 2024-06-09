#include "string_view.h"

StringView::StringView() : data_(nullptr), size_(0) {
}

StringView::StringView(const char* string) : data_(string), size_(string ? std::strlen(string) : 0) {
}

StringView::StringView(const char* string, size_t size) : data_(string), size_(size) {
}

char StringView::operator[](size_t index) const {
  if (index >= size_) {
    throw StringViewOutOfRange();
  }
  return data_[index];
}

char StringView::At(size_t index) {
  if (index >= size_) {
    throw StringViewOutOfRange();
  }
  return data_[index];
}

char StringView::Front() const {
  if (size_ == 0) {
    throw StringViewOutOfRange();
  }
  return data_[0];
}

char StringView::Back() const {
  if (size_ == 0) {
    throw StringViewOutOfRange();
  }
  return data_[size_ - 1];
}

size_t StringView::Size() const {
  return size_;
}

size_t StringView::Length() const {
  return Size();
}

bool StringView::Empty() const {
  return size_ == 0;
}

const char* StringView::Data() const {
  return data_;
}

void StringView::Swap(StringView& string_view) {
  std::swap(data_, string_view.data_);
  std::swap(size_, string_view.size_);
}

void StringView::RemovePrefix(size_t prefix_size) {
  if (prefix_size > size_) {
    throw StringViewOutOfRange();
  }
  data_ += prefix_size;
  size_ -= prefix_size;
}

void StringView::RemoveSuffix(size_t suffix_size) {
  if (suffix_size > size_) {
    throw StringViewOutOfRange();
  }
  size_ -= suffix_size;
}

StringView StringView::Substr(size_t pos, size_t count) {
  if (pos > size_) {
    throw StringViewOutOfRange();
  }
  count = std::min(count, size_ - pos);
  return {data_ + pos, count};
}