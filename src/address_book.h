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
