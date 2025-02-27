#include "lab3.hxx"
#include <cstdlib>

izdanie::izdanie() { this->name = nullptr; }
izdanie::~izdanie() { free(this->name); }
void izdanie::set_name(char *name) { this->name = name; }
char *izdanie::get_name() { return this->name; }

book::book() {
  this->author = nullptr;
  this->izdanie = nullptr;
  this->theme = nullptr;
}

book::~book() {
  free(this->author);
  free(this->izdanie);
  free(this->theme);
}

void book::set_name(char *name) { this.name = name; }