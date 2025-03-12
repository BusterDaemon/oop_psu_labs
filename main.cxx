#include "lab4.cxx"

int main(void) {
  auto s = set<int>(567);
  s.add_elem(765);
  s.add_elem(32);
  s.print();
  s = s - 67;
  s.print();
  return 0;
}