#pragma once

#include <memory>
#ifndef _IO_HXX_
#define _IO_HXX_

#include "lab3.hxx"
#include <sys/types.h>

void add_izdanie(std::unique_ptr<izdanie[]> &izd, uint *cur_size);
void add_book(std::unique_ptr<book[]> &books, uint *cur_size);
void add_textbook(std::unique_ptr<textbook[]> &textbooks, uint *cur_size);
void add_journal(std::unique_ptr<journal[]> &journal, uint *cur_size);
void read_izd(std::unique_ptr<izdanie[]> &izd, uint cur_size);
void read_books(std::unique_ptr<book[]> &books, uint cur_size);
void read_textbooks(std::unique_ptr<textbook[]> &textbooks, uint cur_size);
void read_journal(std::unique_ptr<journal[]> &jrls, uint cur_size);

#endif