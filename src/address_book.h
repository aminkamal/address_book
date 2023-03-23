#pragma once

#ifdef __cplusplus

#include <string>
#include <iostream>
#include "trienode.h"
#include "address_book_entry.h"

class AddressBook
{
private:
  TrieNode<Entry> root_first_names;
  TrieNode<Entry> root_last_names;
  void Print(const TrieNode<Entry> *root, bool is_first_names_trie, bool swap_first_last_names);
  void ToLowerCase(std::string &str);

public:
  AddressBook();

  void PrintSortedFirstNames();
  
  void PrintSortedLastNames();

  void PrintMatches(std::string name_to_find);

  bool InsertEntry(std::string first_name, std::string last_name, std::string phone_number);

};

  #define ADDRESS_BOOK_API extern "C"
#else
  #define ADDRESS_BOOK_API
  typedef struct address_book AddressBook;

#endif

ADDRESS_BOOK_API AddressBook* create_address_book(void);
ADDRESS_BOOK_API int insert_entry(AddressBook* address_book, const char * first_name, const char * last_name, const char * phone_number);
ADDRESS_BOOK_API void list_first_names(AddressBook* address_book);
ADDRESS_BOOK_API void free_address_book(AddressBook* address_book);
