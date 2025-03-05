#include "io.hxx"
#include "lab3.hxx"
#include <iostream>
#include <memory>
#include <string>
#include <sys/types.h>
#include <utility>
using namespace std;

void add_izdanie(std::unique_ptr<izdanie[]> &izd, uint *cur_size) {
  std::string name;
  cout << "Введите название издателя: ";
  cin >> name;

  izdanie new_izd(name);

  uint new_size = *cur_size + 1;

  std::unique_ptr<izdanie[]> upd_izd(new izdanie[new_size]);

  if (*cur_size > 0) {
    for (size_t i = 0; i < *cur_size; i++) {
      upd_izd[i] = std::move(izd[i]);
    }
  }

  upd_izd[*cur_size] = std::move(new_izd);

  izd = std::move(upd_izd);
  *cur_size = new_size;
}

void add_book(std::unique_ptr<book[]> &books, uint *cur_size) {
  std::string name, author, theme, izdanie;
  cout << "Введите название книги: ";
  cin >> name;
  cout << "Введите автора книги: ";
  cin >> author;
  cout << "Введите тематику книги: ";
  cin >> theme;
  cout << "Введите издание книги: ";
  cin >> izdanie;

  book new_book(name, author, theme, izdanie);
  uint new_size = *cur_size + 1;
  std::unique_ptr<book[]> upd_book(new book[new_size]);

  if (*cur_size > 0) {
    for (size_t i = 0; i < *cur_size; i++) {
      upd_book[i] = std::move(books[i]);
    }
  }

  upd_book[*cur_size] = std::move(new_book);
  books = std::move(upd_book);
  *cur_size = new_size;
}

void add_textbook(std::unique_ptr<textbook[]> &textbooks, uint *cur_size) {
  std::string name, author, theme, izdanie;
  uint form = 0, new_size = *cur_size + 1;

  cout << "Введите название учебника: ";
  cin >> name;
  cout << "Введите автора учебника: ";
  cin >> author;
  cout << "Введите тематику учебника: ";
  cin >> theme;
  cout << "Введите издание учебника: ";
  cin >> izdanie;
  cout << "Введите предназначенный класс учебника: ";
  cin >> form;

  textbook txtbook(name, author, theme, izdanie, form);
  std::unique_ptr<textbook[]> upd_txtbooks(new textbook[new_size]);

  if (*cur_size > 0) {
    for (size_t i = 0; i < *cur_size; i++) {
      upd_txtbooks[i] = std::move(textbooks[i]);
    }
  }

  upd_txtbooks[*cur_size] = std::move(txtbook);
  textbooks = std::move(upd_txtbooks);
  *cur_size = new_size;
}

void add_journal(std::unique_ptr<journal[]> &journals, uint *cur_size) {
  std::string name, author, theme, izdanie;
  float price = 0;
  uint new_size = *cur_size + 1;
  cout << "Введите название журнала: ";
  cin >> name;
  cout << "Введите автора журнала: ";
  cin >> author;
  cout << "Введите тематику журнала: ";
  cin >> theme;
  cout << "Введите издание журнала: ";
  cin >> izdanie;
  cout << "Введите стоимость журнала: ";
  cin >> price;

  journal new_journal(name, author, theme, izdanie, price);
  std::unique_ptr<journal[]> upd_journal(new journal[new_size]);

  if (*cur_size > 0) {
    for (size_t i = 0; i < *cur_size; i++) {
      upd_journal[i] = std::move(journals[i]);
    }
  }

  upd_journal[*cur_size] = std::move(new_journal);
  journals = std::move(upd_journal);
  *cur_size = new_size;
}

void read_izd(std::unique_ptr<izdanie[]> &izd, uint cur_size) {
  if (izd == nullptr || cur_size < 1)
    return;

  cout << "Список издателей:\n";
  for (size_t i = 0; i < cur_size; i++)
    cout << i + 1 << ". " << izd[i].get_name() << "\n";
  cout << "\n";
}

void read_books(std::unique_ptr<book[]> &books, uint cur_size) {
  if (books == nullptr || cur_size < 1)
    return;

  cout << "Список книг:\n";
  for (size_t i = 0; i < cur_size; i++) {
    cout << i + 1 << ". " << books[i].get_name() << "\n";
    cout << "Автор: " << books[i].get_author() << "\n";
    cout << "Тема: " << books[i].get_theme() << "\n";
    cout << "Издание: " << books[i].get_izdanie() << "\n\n";
  }
}

void read_textbooks(std::unique_ptr<textbook[]> &textbooks, uint cur_size) {
  if (textbooks == nullptr || cur_size < 1)
    return;

  cout << "Список учебников:\n";
  for (size_t i = 0; i < cur_size; i++) {
    cout << i + 1 << ". " << textbooks[i].get_name() << "\n";
    cout << "Автор: " << textbooks[i].get_author() << "\n";
    cout << "Тема: " << textbooks[i].get_theme() << "\n";
    cout << "Издание: " << textbooks[i].get_izdanie() << "\n";
    cout << "Для " << textbooks[i].get_form() << " классов\n\n";
  }
}

void read_journal(std::unique_ptr<journal[]> &jrls, uint cur_size) {
  if (jrls == nullptr || cur_size < 1)
    return;

  cout << "Список учебников:\n";
  for (size_t i = 0; i < cur_size; i++) {
    cout << i + 1 << ". " << jrls[i].get_name() << "\n";
    cout << "Автор: " << jrls[i].get_author() << "\n";
    cout << "Тема: " << jrls[i].get_theme() << "\n";
    cout << "Издание: " << jrls[i].get_izdanie() << "\n";
    cout << "Стоимость: " << jrls[i].get_price() << "€\n\n";
  }
}