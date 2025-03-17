#include "lab4.hxx"
#include <algorithm>
#include <iostream>
#include <memory>
#include <stdlib.h>
#include <unordered_set>
#include <utility>

template <typename T> set<T>::set() {
  this->count = 0;
  this->elements = nullptr;
}

template <typename T> set<T>::set(T elem) {
  this->count = 1;
  std::unique_ptr<T[]> set_elem(new T[this->count]);
  set_elem[this->count - 1] = std::move(elem);
  this->elements = std::move(set_elem);
}

template <typename T> set<T>::~set() {}

template <typename T> set<T>::set(set &&other) noexcept {
  this->elements = std::move(other.elements);
  this->count = other.count;
}

template <typename T> set<T> &set<T>::operator=(set<T> &&other) noexcept {
  if (this != &other) {
    elements = std::move(other.elements);
    count = other.count;
  }
  return *this;
}

template <typename T> void set<T>::add_elem(T elem) {
  size_t upd_size = this->count + 1;
  std::unique_ptr<T[]> upd_arr(new T[upd_size]);

  if (this->elements != nullptr) {
    for (size_t i = 0; i < this->count; i++) {
      upd_arr[i] = std::move(this->elements[i]);
    }
    upd_arr[this->count] = std::move(elem);
    this->count = upd_size;
    this->elements = std::move(upd_arr);
    return;
  }

  upd_arr[this->count - 1] = std::move(elem);
  this->elements = std::move(upd_arr);
}

template <typename T> void set<T>::print() {
  if (this->elements == nullptr || this->count < 1) {
    return;
  }

  for (size_t i = 0; i < this->count; i++) {
    std::cout << this->elements[i];
    if (i < this->count - 1)
      std::cout << ", ";
  }
  std::cout << "\n";
}

template <typename T> set<T> set<T>::operator-(const T &elem) {
  if (this->elements == nullptr || this->count < 1) {
    return std::move(*this);
  }

  uint32_t occurences = 0;
  for (size_t i = 0; i < this->count; i++) {
    if (this->elements[i] == elem) {
      occurences = occurences + 1;
    }
  }

  if (occurences == 0) {
    std::cout << "Такого элемента не существует!\n";
    return std::move(*this);
  }

  set<T> upd_set;

  size_t upd_size = this->count - occurences;
  std::unique_ptr<T[]> upd_arr(new T[upd_size]);
  for (size_t i = 0; i < upd_size; i++) {
    if (this->elements[i] != elem)
      upd_arr[i] = std::move(this->elements[i]);
  }

  upd_set.count = upd_size;
  upd_set.elements = std::move(upd_arr);
  return std::move(upd_set);
}

template <typename T> bool set<T>::operator>(set<T> &other_set) const {
  std::unordered_set<T> main_set;
  const set<T> &main_src = this->count > other_set.count ? *this : other_set;
  const set<T> &sec_src = this->count > other_set.count ? other_set : *this;

  if (sec_src.count == 0)
    return true;

  for (size_t i = 0; i < main_src.count; i++) {
    main_set.insert(main_src.elements[i]);
  }

  return std::all_of(sec_src.elements.get(),
                     sec_src.elements.get() + sec_src.count,
                     [&main_set](const T &elem) {
                       return main_set.find(elem) != main_set.end();
                     });
}

template <typename T> bool set<T>::operator!=(set<T> &other_set) const {
  if (this->count != other_set.count)
    return true;

  std::unordered_set<T> main_set;
  for (size_t i = 0; i < this->count; i++) {
    main_set.insert(this->elements[i]);
  }

  for (size_t i = 0; i < other_set.count; i++) {
    if (main_set.find(other_set.elements[i]) == main_set.end())
      return true;
  }

  return false;
}