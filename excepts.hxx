#ifndef _EXCEPTS_HXX_
#define _EXCEPTS_HXX_

#include <exception>
#include <stdint.h>

enum class MemoryType : uint32_t { OUT_OF_BOUNDS = 0xFF00, NO_ELEMENTS_ARRAY };

class MemoryExcept : public std::exception {
private:
  MemoryType bad_mem;
  const char *reason;

public:
  MemoryExcept(MemoryType) noexcept;
  const char *what() const noexcept override;
};

#endif