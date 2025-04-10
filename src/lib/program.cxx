#include "program.hpp"
#include "excepts.hpp"
#include "transform.hpp"
#include <iostream>
#include <stdexcept>

int program::run() {
  std::string uinput;
  uint64_t result = 0;

  while (true) {
    std::cout << "Введите 11-ричное число для преобразования: ";
    std::cin >> uinput;
    try {
      transformer11to9 trans(uinput);
      result = trans.transformation();

      std::cout << "\nИсходное число: " << trans.get_base11()
                << "\nЧисло в основании 10: " << trans.get_base10()
                << "\nПреобразованное число в основании 9: " << result
                << "\n\n";
    } catch (const TransformerExcepts &e) {
      std::cerr << "Ошибка преобразования: " << e.what()
                << "\nКод ошибки: " << e.code() << "\n";
      continue;
    } catch (const std::length_error &e) {
      std::cerr << "Ошибка выполнения программы: " << e.what() << "\n";
      continue;
    }
  }

  return 0;
}