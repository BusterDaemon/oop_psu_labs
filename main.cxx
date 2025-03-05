#include "./lib/io.hxx"
#include "./lib/lab3.hxx"
#include <iostream>
#include <memory>
#include <stdlib.h>
#include <sys/types.h>

using namespace std;

int main(void) {
  uint publisher_count = 0, book_count = 0, textbook_count = 0,
       journals_count = 0;
  uint varik = 0;

  std::unique_ptr<izdanie[]> uniq_publish(nullptr);
  std::unique_ptr<book[]> uniq_book(nullptr);
  std::unique_ptr<textbook[]> uniq_txtbook(nullptr);
  std::unique_ptr<journal[]> uniq_journal(nullptr);

  while (true) {
    cout << "Выберите действие:\n";
    cout << "1. Добавить издателя\n";
    cout << "2. Добавить книгу\n";
    cout << "3. Добавить учебник\n";
    cout << "4. Добавить журнал\n";
    cout << "5. Просмотреть издателей\n";
    cout << "6. Просмотреть книги\n";
    cout << "7. Просмотреть учебники\n";
    cout << "8. Просмотреть журналы\n";
    cout << "9. Выйти из программы\n\n";
    cin >> varik;

    switch (varik) {
    case 1:
      add_izdanie(uniq_publish, &publisher_count);
      break;
    case 2:
      add_book(uniq_book, &book_count);
      break;
    case 3:
      add_textbook(uniq_txtbook, &textbook_count);
      break;
    case 4:
      add_journal(uniq_journal, &journals_count);
      break;
    case 5:
      read_izd(uniq_publish, publisher_count);
      break;
    case 6:
      read_books(uniq_book, book_count);
      break;
    case 7:
      read_textbooks(uniq_txtbook, textbook_count);
      break;
    case 8:
      read_journal(uniq_journal, journals_count);
      break;
    }

    if (varik == 9) {
      break;
    }

    varik = 0;
  }

  return 0;
}