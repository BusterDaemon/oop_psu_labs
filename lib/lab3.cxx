#include "lab3.hxx"
#include <stdlib.h>

izdanie::izdanie() { this->name = "DEFAULT"; }
izdanie::izdanie(std::string name) { this->name = name; }
izdanie::~izdanie() {}
void izdanie::set_name(std::string name) { this->name = name; }
std::string izdanie::get_name() { return this->name; }

book::book() {
  this->set_name("DEFAULT");
  this->author = "AUTHOR";
  this->izdanie = "IZDANIE";
  this->theme = "THEME";
};

book::book(std::string name, std::string author, std::string theme,
           std::string izdanie) {
  this->set_name(name);
  this->author = author;
  this->theme = theme;
  this->izdanie = izdanie;
}

book::~book() {}

void book::set_author(std::string author) { this->author = author; }
std::string book::get_author() { return this->author; }
void book::set_theme(std::string theme) { this->theme = theme; }
std::string book::get_theme() { return this->theme; }
void book::set_izdanie(std::string izd) { this->izdanie = izd; }
std::string book::get_izdanie() { return this->izdanie; }

textbook::textbook() { this->form = 1; }
textbook::textbook(std::string name, std::string author, std::string theme,
                   std::string izdanie, const uint form) {
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
journal::journal(std::string name, std::string author, std::string theme,
                 std::string izdanie, const float price) {
  this->set_name(name);
  this->set_author(author);
  this->set_theme(theme);
  this->set_izdanie(izdanie);
  this->price = price;
}
journal::~journal() {}

void journal::set_price(const float price) { this->price = price; }
float journal::get_price() { return this->price; }