#ifndef _LAB4_HXX_
#define _LAB4_HXX_

#include <memory>
#include <stddef.h>

template <typename T> class set {
private:
  std::unique_ptr<T[]> elements;
  size_t count;

public:
  set();
  set(T elem);
  ~set();
  set(set &&other) noexcept;
  set &operator=(set &&other) noexcept;
  void add_elem(T elem);
  set<T> operator-(const T &elem);
  bool operator>(set other_set);
  bool operator!=(set other_set);
  void print();
};

#endif