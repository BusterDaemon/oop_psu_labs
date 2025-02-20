#ifndef _LAB4_HXX_
#define _LAB4_HXX_

#include <stddef.h>

template <typename T>
class set {
private:
  T *elements;
  size_t count;

public:
  set();
  set(T elem);
  ~set();
  void add_elem(T elem);
  void operator-();
  void operator>(set other_set);
  void operator!=(set other_set);
  void print();
  T get_elem(size_t index);
};

#endif