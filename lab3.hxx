#ifndef _LAB3_HXX_
#define _LAB3_HXX_

#include <sys/types.h>
class izdanie {
private:
  char *name;

public:
  izdanie();
  ~izdanie();
  char *get_name();
  void set_name(const char *name);
};

class book : public izdanie {
private:
  char *author;
  char *theme;
  char *izdanie;

public:
  book();
  ~book();
  char *get_author();
  void set_author(const char *author);
  char *get_theme();
  void set_theme(const char *theme);
  char *get_izdanie();
  void set_izdanie(const char *izdanie);
};

class textbook : public book {
private:
  uint form;

public:
  textbook();
  ~textbook();
  uint get_form();
  void set_form(const uint form);
};

class journal : book {
private:
  float price;

public:
  journal();
  ~journal();
  float get_price();
  void set_price(const float price);
};

#endif
