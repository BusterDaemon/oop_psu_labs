#include "lab4.hxx"
#include <stdlib.h>

template <typename T> set<T>::set() {
  this->count = 0;
  this->elements = nullptr;
}

template <typename T> set<T>::set(T elem) {
  this->count = 1;
  this->elements = (T *)malloc(sizeof(T));
  *this->elements = elem;
}

template <typename T> set<T>::~set() {
  for (size_t i = 0; i < this->count; i++) {
    free(this->elements + i);
  }
}

template <typename T> void set<T>::add_elem(T elem) {
  this->count += 1;
  if (this->elements != nullptr) {
    T *ptr = (T *)realloc(this->elements, this->count * sizeof(T));
    *(ptr + this->count - 1) = elem;
    return;
  }

  
}