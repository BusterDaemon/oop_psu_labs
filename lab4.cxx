#include "lab4.hxx"
#include <algorithm>
#include <iostream>
#include <memory>
#include <new>
#include <stddef.h>
#include <stdexcept>
#include <stdint.h>
#include <stdlib.h>
#include <unordered_set>
#include <utility>

#define _BAD_MEMORY_TEXT "Ошибка выделения памяти: "
#define _BAD_ARGUMENT_TEXT "Аргумент не может ссылаться на NULL\n"
#define _BAD_ARG_OR_SIZE_TEXT                                                  \
  "Аргумент не должен ссылаться на NULL или иметь размер меньше 1.\n"
#define _BAD_OUT_OF_INDEX_ARRAY "Выход за пределы массива\n"

template <typename T> set<T>::set() {
  this->count = 0;
  this->elements = nullptr;
}

template <typename T> set<T>::set(T elem) {
  try {
    this->count = 1;
    std::unique_ptr<T[]> set_elem(new T[this->count]);
    set_elem[this->count - 1] = std::move(elem);
    this->elements = std::move(set_elem);
  } catch (const std::bad_alloc &e) {
    std::cerr << _BAD_MEMORY_TEXT << e.what() << "\n";
  }
}

template <typename T> set<T>::~set() {}

template <typename T> set<T>::set(set &&other) noexcept {
  if (other.elements == nullptr)
    throw std::invalid_argument(_BAD_ARGUMENT_TEXT);
  this->elements = std::move(other.elements);
  this->count = other.count;
}

template <typename T> set<T> &set<T>::operator=(set<T> &&other) noexcept {
  if (other.elements == nullptr)
    throw std::invalid_argument(_BAD_ARGUMENT_TEXT);
  if (this != &other) {
    elements = std::move(other.elements);
    count = other.count;
  }
  return *this;
}

template <typename T> void set<T>::add_elem(T elem) {
  try {
    size_t upd_size = this->count + 1;
    std::unique_ptr<T[]> upd_arr(new T[upd_size]);

    for (size_t i = 0; i < this->count; i++) {
      upd_arr[i] = std::move(this->elements[i]);
      if (i >= this->count) {
        throw std::overflow_error(_BAD_OUT_OF_INDEX_ARRAY);
      }
    }

    upd_arr[this->count] = std::move(elem);

    this->elements = std::move(upd_arr);
    this->count = upd_size;
  } catch (const std::bad_alloc &e) {
    std::cerr << _BAD_MEMORY_TEXT << e.what() << "\n";
  }
}

template <typename T> void set<T>::print() {
  if (this->elements == nullptr || this->count < 1) {
    throw std::invalid_argument(_BAD_ARG_OR_SIZE_TEXT);
  }

  for (size_t i = 0; i < this->count; i++) {
    if (i >= this->count)
      throw std::overflow_error(_BAD_OUT_OF_INDEX_ARRAY);

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
    if (i >= this->count)
      throw std::overflow_error(_BAD_OUT_OF_INDEX_ARRAY);

    if (this->elements[i] == elem) {
      occurences = occurences + 1;
    }
  }

  if (occurences == 0) {
    std::cout << "Такого элемента не существует!\n";
    return std::move(*this);
  }

  set<T> upd_set;
  try {
    size_t upd_size = this->count - occurences;
    std::unique_ptr<T[]> upd_arr(new T[upd_size]);
    for (size_t i = 0; i < upd_size; i++) {
      if (i >= upd_size)
        throw std::overflow_error(_BAD_OUT_OF_INDEX_ARRAY);

      if (this->elements[i] != elem)
        upd_arr[i] = std::move(this->elements[i]);
    }

    upd_set.count = upd_size;
    upd_set.elements = std::move(upd_arr);
  } catch (const std::bad_alloc &e) {
    std::cerr << _BAD_MEMORY_TEXT << e.what() << "\n";
  }

  return std::move(upd_set);
}

template <typename T> bool set<T>::operator>(set<T> &other_set) const {
  std::unordered_set<T> main_set;
  const set<T> &main_src = this->count > other_set.count ? *this : other_set;
  const set<T> &sec_src = this->count > other_set.count ? other_set : *this;

  if (sec_src.count == 0)
    return true;

  for (size_t i = 0; i < main_src.count; i++) {
    if (i >= main_src.count)
      throw std::overflow_error(_BAD_OUT_OF_INDEX_ARRAY);

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
    if (i >= this->count)
      throw std::overflow_error(_BAD_OUT_OF_INDEX_ARRAY);
  }

  for (size_t i = 0; i < other_set.count; i++) {
    if (i >= other_set.count)
      throw std::overflow_error(_BAD_OUT_OF_INDEX_ARRAY);
    if (main_set.find(other_set.elements[i]) == main_set.end())
      return true;
  }

  return false;
}

template <typename T> void set<T>::clear() {
  this->count = 0;

  std::unique_ptr<T[]> upd_ptr = nullptr;
  this->elements.reset();
}