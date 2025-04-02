#include "lab6.hxx"
#include <cstdint>
#include <iostream>
#include <stdint.h>
#include <utility>

lab6program::~lab6program() {
  if (!this->A.empty())
    this->A.clear();
  if (!this->B.empty())
    this->B.clear();
}

bool lab6program::dup_check(uint32_t k, uint32_t v,
                            const std::multimap<uint32_t, uint32_t> &s) {
  auto range = s.equal_range(k);
  for (auto it = range.first; it != range.second; it++) {
    if (it->second == v)
      return true;
  }
  return false;
}

void lab6program::insert() {
  uint32_t inp_k = 0, inp_v = 0;
  bool dup_found = false;
  std::cout << "Введите ключ: ";
  std::cin >> inp_k;
  std::cout << "Введите значение: ";
  std::cin >> inp_v;

  if (!this->dup_check(inp_k, inp_v, this->A))
    this->A.insert(std::make_pair(inp_k, inp_v));
  else
    std::cout << "Такая пара уже существует!\n\n";
}

void lab6program::delete_key() {
  uint32_t inp_k = 0;
  std::cout << "Введите ключ для удаления: ";
  std::cin >> inp_k;
  auto it = this->A.find(inp_k);

  if (it != this->A.end())
    this->A.erase(it);
  else
    std::cout << "Такого ключа нету!\n\n";
}

void lab6program::update_key() {
  if (this->A.empty()) {
    std::cout << "Множество пустое! Обновлять нечего!\n";
    return;
  }

  uint32_t inp_k = 0, inp_v = 0;
  std::cout << "Введите ключ по которому нужно изменить значение: ";
  std::cin >> inp_k;
  auto it = this->A.find(inp_k);

  if (it == this->A.end()) {
    std::cout << "Такого ключа нету!\n\n";
    return;
  }

  std::cout << "Введите новое значение для данного ключа: ";
  std::cin >> inp_v;
  if (!this->dup_check(inp_k, inp_v, this->A)) {
    for (auto it = this->A.begin(); it != this->A.end(); it++) {
      if (it->first == inp_k) {
        it->second = inp_v;
        break;
      }
    }
  } else
    std::cout << "Новое значение не должно повторяться!\n";
}

void lab6program::clone_a() {
  if (this->A.size() == 0) {
    std::cout << "Клонировать нечего!\n";
    return;
  }

  for (auto it = this->A.begin(); it != this->A.end(); it++) {
    this->B.insert(std::make_pair(it->first, it->second));
  }
}

void lab6program::delete_keys() {
  if (this->A.size() == 0) {
    std::cout << "Удалять нечего!\n";
    return;
  }

  uint32_t n = 0, k = 0, j = 0;
  std::cout << "Введите по какому ключу хотите удалить элементы: ";
  std::cin >> k;

  auto range = this->A.equal_range(k);
  if (range.first == range.second) {
    std::cout << "Нету такого ключа!\n";
    return;
  }

  std::cout << "Введите сколько ключей хотите удалить: ";
  std::cin >> n;

  this->A.erase(this->A.lower_bound(k), this->A.upper_bound(k + n));

  for (auto it = this->B.begin(); it != this->B.end(); it++) {
    if (!dup_check(it->first, it->second, this->A))
      this->A.insert(std::make_pair(it->first, it->second));
  }
}

void lab6program::print_single_mmap(
    const std::multimap<uint32_t, uint32_t> &s) {
  if (s.empty()) {
    std::cout << "Множество пустое!\n";
    return;
  }
  for (auto it = s.begin(); it != s.end(); it++)
    std::cout << "{ " << it->first << ": " << it->second << " }\n";
}

void lab6program::print_both_multimap() {
  std::cout << "Множество A:\n";
  this->print_single_mmap(this->A);

  std::cout << "Множество B:\n";
  this->print_single_mmap(this->B);
}

void lab6program::run() {
  uint8_t varik = 0;
  while (true) {
    std::cout << "Выберите действие:\n";
    std::cout << "1. Добавить пару в основной контейнер\n";
    std::cout << "2. Удалить пару из основного контейнера\n";
    std::cout << "3. Изменить пару в основном контейнере\n";
    std::cout << "4. Клонировать основной контейнер\n";
    std::cout
        << "5. Удалить n пар элементов в контейнере и вставить из копии\n";
    std::cout << "6. Вывести оба контейнера\n";
    std::cout << "7. Выйти из программы\n\n";

    std::cin >> varik;
    varik = varik - '0';

    switch (varik) {
    case (uint8_t)ProgramActions::INSERT_SET_A_ELEM:
      this->insert();
      break;
    case (uint8_t)ProgramActions::DELETE_ELEM_SET_A:
      this->delete_key();
      break;
    case (uint8_t)ProgramActions::UPDATE_SET_A_ELEM:
      this->update_key();
      break;
    case (uint8_t)ProgramActions::CLONE_SET_A:
      this->clone_a();
      break;
    case (uint8_t)ProgramActions::DELETE_N_ELEM_SET_A_INSERT_FROM_B:
      this->delete_keys();
      break;
    case (uint8_t)ProgramActions::PRINT_BOTH_SETS:
      this->print_both_multimap();
      break;
    }

    if (varik == (uint8_t)ProgramActions::EXIT) {
      break;
    }

    varik = 0;
  }
}