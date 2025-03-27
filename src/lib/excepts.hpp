#ifndef _EXCEPTS_HPP_
#define _EXCEPTS_HPP_

#include <exception>
#include <stdint.h>

enum class NumExcepts : uint16_t { NEG_BASE = 0xFF00 };

class TransformerExcepts : std::exception {
private:
  NumExcepts exceptCode;
  const char *reason;

public:
  TransformerExcepts(NumExcepts);
  const char *what() const noexcept override;
  const uint16_t code() const noexcept;
};

#endif