#include "lab1.hxx"
#include <iostream>
#include <string>
#include <vector>

int main(void) {
  int varik = 0;
  std::vector<product> goods;
  std::string name;
  bool found = false;

  goods.reserve(2);

  while (true) {
    std::cout << "Выберите действие\n";
    std::cout << "1. Добавить объект\n";
    std::cout << "2. Вывести товары по наименованию\n";
    std::cout << "3. Вывести товары по наименованию и цене\n";
    std::cout << "4. Вывести товары по сроку хранения\n";
    std::cout << "5. Выйти из программы\n";

    std::cin >> varik;

    if (varik == 1) {
      std::string manuf;
      float price;
      int god_do, kolvo;

      std::cout << "Введите наименование товара\n";
      std::cin >> name;
      std::cout << "Введите производителя товара\n";
      std::cin >> manuf;
      std::cout << "Введите стоимость товара\n";
      std::cin >> price;
      std::cout << "Введите срок годности товара (в днях)\n";
      std::cin >> god_do;
      std::cout << "Введите количество товара\n";
      std::cin >> kolvo;

      product tovar = product(name, manuf, price, god_do, kolvo);
      goods.push_back(tovar);
    }

    if (varik == 2) {
      if (goods.size() == 0) {
        std::cout << "Список пуст, операция отменена\n";
        continue;
      }

      std::cout << "Введите наименование, которое хотите найти\n";
      std::cin >> name;

      for (auto p = goods.begin(); p != goods.end(); ++p) {
        if (p->get_name() == name) {
          found = true;
          std::cout << "Данные найденного товара:\n";
          std::cout << "Производитель: " << p->get_manufacturer() << "\n";
          std::cout << "Стоимость: " << p->get_count() << "\n";
          std::cout << "Срок годности (в днях): " << p->get_goden() << "\n";
          std::cout << "Количество товара: " << p->get_count() << "\n";
          std::cout << "\n";
        }
      }

      if (found == false) {
        std::cout << "Такого товара не существует!\n";
      }
    }

    if (varik == 3) {
      float price = 0;
      std::cout << "Введите наименование, которое хотите найти\n";
      std::cin >> name;

      std::cout << "Введите стоимость для поиска\n";
      std::cin >> price;

      for (auto p = goods.begin(); p != goods.end(); p++) {
        if (p->get_name() == name && p->get_price() == price) {
          found = true;
          std::cout << "Данные найденного товара:\n";
          std::cout << "Производитель: " << p->get_manufacturer() << "\n";
          std::cout << "Стоимость: " << p->get_count() << "\n";
          std::cout << "Срок годности (в днях): " << p->get_goden() << "\n";
          std::cout << "Количество товара: " << p->get_count() << "\n";
          std::cout << "\n";
        }
      }

      if (found == false) {
        std::cout << "Такого товара не существует!\n";
      }
    }

    if (varik == 4) {
      int goden = 0;
      std::cout << "Введите срок годности по которому хотите найти товары\n";
      std::cin >> goden;

      for (auto p = goods.begin(); p != goods.end(); p++) {
        if (p->get_goden() > goden) {
          found = true;
          std::cout << "Данные найденного товара:\n";
          std::cout << "Наименование: " << p->get_name() << "\n";
          std::cout << "Производитель: " << p->get_manufacturer() << "\n";
          std::cout << "Стоимость: " << p->get_count() << "\n";
          std::cout << "Срок годности (в днях): " << p->get_goden() << "\n";
          std::cout << "Количество товара: " << p->get_count() << "\n";
          std::cout << "\n";
        }
      }

      if (found == false) {
        std::cout << "Такого товара не существует!\n";
      }
    }

    if (varik == 5) {
      break;
    }

    name.clear();
    found = false;
  }

  return 0;
}