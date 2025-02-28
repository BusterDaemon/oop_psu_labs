#include "lab3.hxx"
#include <cstdlib>

izdanie::izdanie() { this->name = nullptr; }
izdanie::izdanie(char *name) { this->name = name; }
izdanie::~izdanie() { free(this->name); }
void izdanie::set_name(char *name) { this->name = name; }
char *izdanie::get_name() { return this->name; }

book::book() {
  this->author = nullptr;
  this->izdanie = nullptr;
  this->theme = nullptr;
}

book::book(char *name, char *author, char *theme, char *izdanie) {
  this->set_name(name);
  this->author = author;
  this->theme = theme;
  this->izdanie = izdanie;
}

book::~book() {
  free(this->author);
  free(this->izdanie);
  free(this->theme);
}

void book::set_author(char *author) { this->author = author; }
char *book::get_author() { return this->author; }
void book::set_theme(char *theme) { this->theme = theme; }
char *book::get_theme() { return this->theme; }
void book::set_izdanie(char *izd) { this->izdanie = izd; }
char *book::get_izdanie() { return this->izdanie; }

textbook::textbook() { this->form = 1; }
textbook::textbook(char *name, char *author, char *theme, char *izdanie,
                   const uint form) {
  this->set_name(name);
  this->set_author(author);
  this->set_theme(theme);
  this->set_izdanie(izdanie);
  this->form = form;
}
textbook::~textbook() {}

void textbook::set_form(const uint form) { this->form = form; }
uint textbook::get_form() { return this->form; }

journal::journal() { this->price = 0; }
journal::journal(char *name, char *author, char *theme, char *izdanie,
                 const float price) {
  this->set_name(name);
  this->set_author(author);
  this->set_theme(theme);
  this->set_izdanie(izdanie);
  this->price = price;
}
journal::~journal() {}

void journal::set_price(const float price) { this->price = price; }
float journal::get_price() { return this->price; }