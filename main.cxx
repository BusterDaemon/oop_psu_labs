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
    std::cout << "5. Создать объект по-умолчанию\n";
    std::cout << "6. Создать измененную копию товара\n";
    std::cout << "7. Выйти из программы\n";

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

      product tovar(name, manuf, price, god_do, kolvo);
      if (goods.size() > 0) {
        for (auto p = goods.begin(); p < goods.end(); p++) {
          if (*p == tovar) {
            found = true;
            std::cout << "Такой товар уже существует!\n";
            break;
          }
        }
      }
      if (!found) {
        goods.push_back(tovar);
      }
    }

    if (varik == 2) {
      if (goods.size() == 0) {
        std::cout << "Список пуст, операция отменена\n";
        continue;
      }

      std::cout << "Введите наименование, которое хотите найти\n";
      std::cin >> name;

      if (goods.size() > 0) {
        for (auto p = goods.begin(); p != goods.end(); ++p) {
          if (p->get_name() == name) {
            found = true;
            Observer obs;
            obs.GetInfo(*p);
          }
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
          Observer obs;
          obs.GetInfo(*p);
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
          Observer obs;
          obs.GetInfo(*p);
        }
      }
    }

    if (varik == 5) {
      product defa;

      std::string name, manuf;
      float price;
      int goden, count;

      std::cout << "Введите новое имя: ";
      std::cin >> name;
      std::cout << "Введите нового производителя: ";
      std::cin >> manuf;
      std::cout << "Введите новую цену: ";
      std::cin >> price;
      std::cout << "Введите новый срок годности(в днях): ";
      std::cin >> goden;
      std::cout << "Введите новое количество: ";
      std::cin >> count;

      product tmp(name, manuf, price, goden, count);
      if (defa != tmp) {
        defa = tmp;
      } else {
        std::cout << "Зачем?\n";
        continue;
      }

      goods.push_back(defa);
    }
    if (varik == 6) {
      product defa;

      std::string name, manuf;
      float price;
      int goden, count;

      std::cout << "Введите наименование, которое хотите найти\n";
      std::cin >> name;

      for (int i = 0; i < goods.size(); i++) {
        if (goods[i].get_name() == name) {
          found = true;
          Observer obs;
          obs.GetInfo(goods[i]);

          defa = goods[i];
          break;
        }
      }

      if (found == false) {
        std::cout << "Такого товара не существует!\n";
        continue;
      }

      std::cout << "Введите новое имя: ";
      std::cin >> name;
      std::cout << "Введите нового производителя: ";
      std::cin >> manuf;
      std::cout << "Введите новую цену: ";
      std::cin >> price;
      std::cout << "Введите новый срок годности(в днях): ";
      std::cin >> goden;
      std::cout << "Введите новое количество: ";
      std::cin >> count;

      defa.set_name(name);
      defa.set_manufacturer(manuf);
      defa.set_price(price);
      defa.set_goden(goden);
      defa.set_count(count);

      goods.push_back(defa);
    }

    if (varik == 7) {
      break;
    }

    name.clear();
    found = false;
  }

  return 0;
}