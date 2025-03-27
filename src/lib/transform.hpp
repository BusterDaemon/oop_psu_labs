#ifndef _TRANSFORM_HPP_
#define _TRANSFORM_HPP_

#include <stdint.h>

class transformer11to9 {
private:
  uint64_t number;
  uint64_t base11number;

public:
  transformer11to9(const uint64_t);
  uint64_t transformation();
  uint64_t get_base11();
};

#endif