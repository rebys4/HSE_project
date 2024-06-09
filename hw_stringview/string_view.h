#include <iostream>
#include <cstdint>
#include <cstring>
#include <stdexcept>
#ifndef HW_STRINGVIEW_STRING_VIEW_H
#define HW_STRINGVIEW_STRING_VIEW_H

class StringViewOutOfRange : public std::out_of_range {
 public:
  StringViewOutOfRange() : std::out_of_range("StringViewOutOfRange") {
  }
};


class StringView {
 private:
  const char* data_;
  size_t size_;

 public:
  StringView();
  StringView(const char* string);  // NOLINT
  StringView(const char* string, size_t size);

  char operator[](size_t index) const;
  char At(size_t index);
  char Front() const;
  char Back() const;
  size_t Size() const;
  size_t Length() const;

  bool Empty() const;
  const char* Data() const;
  void Swap(StringView& string_view);
  void RemovePrefix(size_t prefix_size);
  void RemoveSuffix(size_t suffix_size);
  StringView Substr(size_t pos, size_t count = -1);
};
#endif
