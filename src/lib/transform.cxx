#include "transform.hpp"
#include "excepts.hpp"
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <string>

transformer11to9::transformer11to9(const std::string n) { this->number = n; }

uint64_t transformer11to9::from11to10(const char n) {
  if (n >= '0' && n <= '9')
    return n - '0';
  if (n == 'A' || n == 'a')
    return 10;

  throw TransformerExcepts(NumExcepts::ILLEGAL_CHAR);
}

uint64_t transformer11to9::to10whole(const std::string n) {
  uint64_t cnvt = 0, res = 0, len = n.length() - 1;
  for (auto i : n) {
    cnvt = this->from11to10(i);
    res += cnvt * pow(11, len);
    len = len - 1;

    if (len < 0)
      throw NumExcepts::NEG_BASE;
  }

  return res;
}

uint64_t transformer11to9::transformation() {
  for (auto c : this->number) {
    if (!((c >= '0' && c <= '9') || (c == 'A' || c == 'a')))
      throw NumExcepts::ILLEGAL_CHAR;
  }

  uint64_t dec = this->to10whole(this->number);
  this->base10number = dec;
  uint64_t base9 = this->from10to9(dec);
  this->base9number = base9;

  return base9;
}

uint64_t transformer11to9::from10to9(const uint64_t n) {
  uint64_t div = n, rem = 0;
  uint64_t const base = 9;
  std::string res;

  do {
    rem = div % base;
    div = div / base;
    res.insert(res.begin(), rem + '0');
  } while (div != 0);

  return std::stoul(res, nullptr, 10);
}

uint64_t transformer11to9::get_base9() { return this->base9number; }
uint64_t transformer11to9::get_base10() { return this->base10number; }
std::string transformer11to9::get_base11() { return this->number; }