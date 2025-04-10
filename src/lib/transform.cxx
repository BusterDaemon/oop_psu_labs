#include "transform.hpp"
#include "excepts.hpp"
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <string>

transformer11to9::transformer11to9(const uint64_t n) { this->number = n; }

uint64_t transformer11to9::transformation() {
  uint64_t result = 0, converted11;
  std::string num = std::to_string(this->number), converted9;
  size_t len = num.size() - 1;

  if (len < 0)
    throw TransformerExcepts(NumExcepts::NEG_BASE);

  for (auto i : num) {
    converted11 = i - '0';
    result += converted11 * pow(11, len);
    len = len - 1;

    if (len < 0)
      throw NumExcepts::NEG_BASE;
  }
  num = std::to_string(result);
  this->base11number = result;

  uint64_t divid = result, rem = 0;
  do {
    rem = divid % 9;
    divid = divid / 9;
    converted9.insert(converted9.begin(), rem + '0');
  } while (divid != 0);

  result = std::stoul(converted9);

  return result;
}

uint64_t transformer11to9::get_base11() { return this->base11number; }