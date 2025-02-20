#include "lab1.hxx"
#include <string>
#include <iostream>

void product::set_name(std::string name) { this->name = name; }

std::string product::get_name() { return this->name; }

void product::set_manufacturer(std::string manuf) {
  this->manufacturer = manuf;
}

std::string product::get_manufacturer() { return this->manufacturer; }

void product::set_price(float price) { this->price = price; }

float product::get_price() { return this->price; }

void product::set_goden(int goden) { this->goden_do = goden; }

int product::get_goden() { return this->goden_do; }

void product::set_count(int count) { this->count = count; }

int product::get_count() { return this->count; }

product::product() {
  this->name = "DEFAULT";
  this->manufacturer = "HELL";
  this->price = 66.6;
  this->goden_do = 666;
  this->count = 666;
}

product::product(std::string name, std::string manuf, float pr, int goden,
                 int count) {
  this->name = name;
  this->manufacturer = manuf;
  this->price = pr;
  this->goden_do = goden;
  this->count = count;
}

product::product(const product &p) {
  name = p.name;
  manufacturer = p.manufacturer;
  price = p.price;
  goden_do = p.goden_do;
  count = p.count;
}

product::~product() {}

product product::operator=(const product &p) {
  this->count = p.count;
  this->goden_do = p.goden_do;
  this->manufacturer = p.manufacturer;
  this->name = p.name;
  this->price = p.price;
  return *this;
}

bool product::operator==(const product &p) {
  if (this->count == p.count && this->goden_do == p.goden_do &&
      this->manufacturer == p.manufacturer && this->name == p.name &&
      this->price == p.price) {
    return true;
  }

  return false;
}

bool product::operator!=(const product &p) {
  if (this->count == p.count && this->goden_do == p.goden_do &&
      this->manufacturer == p.manufacturer && this->name == p.name &&
      this->price == p.price) {
    return false;
  }

  return true;
}

void Observer::GetInfo(const product &p) {
  std::cout << "Наименование: " << p.name << "\n";
  std::cout << "Производитель: " << p.manufacturer << "\n";
  std::cout << "Стоимость: " << p.price << "\n";
  std::cout << "Годен до (в днях): " << p.goden_do << "\n";
  std::cout << "Осталось: " << p.count << "\n\n";
}