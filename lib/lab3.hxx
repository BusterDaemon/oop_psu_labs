#pragma once

#ifndef _LAB3_HXX_
#define _LAB3_HXX_

#include <string>
#include <sys/types.h>

class izdanie {
private:
  std::string name;

public:
  izdanie();
  izdanie(std::string name);
  ~izdanie();
  std::string get_name();
  void set_name(std::string);
};

class book : public izdanie {
private:
  std::string author;
  std::string theme;
  std::string izdanie;

public:
  book();
  book(std::string name, std::string author, std::string theme,
       std::string izdanie);
  ~book();
  std::string get_author();
  void set_author(std::string);
  std::string get_theme();
  void set_theme(std::string);
  std::string get_izdanie();
  void set_izdanie(std::string);
};

class textbook final : public book {
private:
  uint form;

public:
  textbook();
  textbook(std::string name, std::string author, std::string theme,
           std::string izdanie, const uint form);
  ~textbook();
  uint get_form();
  void set_form(const uint);
};

class journal final : public book {
private:
  float price;

public:
  journal();
  journal(std::string name, std::string author, std::string theme,
          std::string izdanie, const float price);
  ~journal();
  float get_price();
  void set_price(const float);
};

#endif
