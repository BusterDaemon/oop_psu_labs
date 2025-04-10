#ifndef _TRANSFORM_HPP_
#define _TRANSFORM_HPP_

#include <stdint.h>
#include <string>

class transformer11to9 {
private:
  std::string number;
  uint64_t base9number, base10number;
  uint64_t from11to10(const char);
  uint64_t to10whole(const std::string);
  uint64_t from10to9(const uint64_t);

public:
  transformer11to9(const std::string);
  uint64_t transformation();
  uint64_t get_base9();
  uint64_t get_base10();
  std::string get_base11();
};

#endif