#ifndef _LAB3_HXX_
#define _LAB3_HXX_

#include <sys/types.h>
class izdanie {
private:
  char *name;

public:
  izdanie();
  izdanie(char *name);
  ~izdanie();
  char *get_name();
  void set_name(char *);
};

class book : public izdanie {
private:
  char *author;
  char *theme;
  char *izdanie;

public:
  book();
  book(char *name, char *author, char *theme, char *izdanie);
  ~book();
  char *get_author();
  void set_author(char *);
  char *get_theme();
  void set_theme(char *);
  char *get_izdanie();
  void set_izdanie(char *);
};

class textbook final : public book {
private:
  uint form;

public:
  textbook();
  textbook(char *name, char *author, char *theme, char *izdanie,
           const uint form);
  ~textbook();
  uint get_form();
  void set_form(const uint);
};

class journal final : book {
private:
  float price;

public:
  journal();
  journal(char *name, char *author, char *theme, char *izdanie,
          const float price);
  ~journal();
  float get_price();
  void set_price(const float);
};

#endif
