#include "lab4.cxx"
#include "lab4.hxx"
#include <iostream>
#include <stdexcept>

#define _UINPUT_ADD "\nВведите элемент который хотите добавить: "
#define _UINPUT_SUB "\nВведите элемент который хотите удалить: "

using namespace std;

int main(void) {
  set<uint32_t> setA, setB;
  uint32_t varik = 0, uinput = 0;

  while (true) {
    cout << "Выберите опцию:\n";
    cout << "1. Добавить элемент в множество A.\n";
    cout << "2. Добавить элемент в множество B.\n";
    cout << "3. Удалить элемент из множества A.\n";
    cout << "4. Удалить элемент из множества B.\n";
    cout << "5. Вывести множество A.\n";
    cout << "6. Вывести множество B.\n";
    cout << "7. Проверить множество B на подмножество A.\n";
    cout << "8. Проверить множества A и B на неравенство.\n";
    cout << "9. Очистить множества A и B.\n";
    cout << "10. Выйти из программы.\n\n";
    cout << "Ваше действие: ";
    cin >> varik;

    try {
      switch (varik) {
      case 1:
        cout << _UINPUT_ADD;
        cin >> uinput;
        setA.add_elem(uinput);
        break;
      case 2:
        cout << _UINPUT_ADD;
        cin >> uinput;
        setB.add_elem(uinput);
        break;
      case 3:
        cout << _UINPUT_SUB;
        cin >> uinput;
        setA = setA - uinput;
        break;
      case 4:
        cout << _UINPUT_SUB;
        cin >> uinput;
        setB = setB - uinput;
        break;
      case 5:
        setA.print();
        break;
      case 6:
        setB.print();
        break;
      case 7:
        if (setB > setA)
          cout << "Множество B является подмножеством A\n";
        else
          cout << "Множество B не является подмножеством A\n";
        break;
      case 8:
        if (setA != setB)
          cout << "Множества A и B неравны\n";
        else
          cout << "Множества A и B равны\n";
        break;
      case 9:
        setA.clear();
        setB.clear();
        break;
      }

      if (varik == 10)
        break;

      varik = 0;
      uinput = 0;
    } catch (const std::overflow_error &e) {
      cerr << "Переполнение: " << e.what() << "\n";
    } catch (const std::invalid_argument &e) {
      cerr << "Передан неверный аргумент: " << e.what() << "\n";
    }
  }

  return 0;
}