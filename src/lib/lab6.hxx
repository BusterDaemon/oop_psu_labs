#ifndef _LAB6_HXX_
#define _LAB6_HXX_

#include <map>
#include <stdint.h>

enum class ProgramActions : uint8_t {
  INSERT_SET_A_ELEM = 0x01,
  DELETE_ELEM_SET_A,
  UPDATE_SET_A_ELEM,
  CLONE_SET_A,
  DELETE_N_ELEM_SET_A_INSERT_FROM_B,
  PRINT_BOTH_SETS,
  EXIT
};

class lab6program {
private:
  std::multimap<uint32_t, uint32_t> A, B;
  bool dup_check(uint32_t k, uint32_t v,
                 const std::multimap<uint32_t, uint32_t> &);
  void insert();
  void delete_key();
  void update_key();
  void clone_a();
  void delete_keys();
  void print_single_mmap(const std::multimap<uint32_t, uint32_t> &);
  void print_both_multimap();

public:
  ~lab6program();
  void run();
};

#endif