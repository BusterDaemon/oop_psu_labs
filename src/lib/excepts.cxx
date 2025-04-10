#include "excepts.hpp"

TransformerExcepts::TransformerExcepts(NumExcepts code) {
  this->exceptCode = code;

  switch (this->exceptCode) {
  case NumExcepts::NEG_BASE:
    this->reason = "Основание не может быть отрицательным!\0";
    break;
  case NumExcepts::ILLEGAL_CHAR:
    this->reason = "Недопустимое число 11-ричной системы!\0";
    break;
  }
}

const char *TransformerExcepts::what() const noexcept { return this->reason; }

const uint16_t TransformerExcepts::code() const noexcept {
  return (uint16_t)this->exceptCode;
}