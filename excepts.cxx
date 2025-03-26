#include "excepts.hxx"

MemoryExcept::MemoryExcept(MemoryType m) noexcept {
  this->bad_mem = m;
  switch (this->bad_mem) {
  case MemoryType::OUT_OF_BOUNDS:
    this->reason = "Возможный выход за пределы массива\0";
    break;
  case MemoryType::NO_ELEMENTS_ARRAY:
    this->reason = "Массив пустой или имеет неверно указанный размер\0";
    break;
  }
}
const char *MemoryExcept::what() const noexcept { return this->reason; }