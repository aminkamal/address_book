#include <string>
#include <iostream>

#include "trienode.h"
#include "address_book_entry.h"

void Print(const TrieNode<Entry> *root)
{
  for (int i = 0; i < MAX_CHARS; i++)
  {
    if (root->children[i] != nullptr)
      Print(root->children[i]);
  }

  if (root->is_end_marker)
  {
    std::string last_name = "";

    if (root->entry_.name_reference != nullptr)
      last_name = root->entry_.name_reference->value;

    std::cout
        << root->value
        << "\t\t" << last_name
        << "\t\t" << root->entry_.phone_number
        << std::endl;
  }
}

int main(int argc, char **argv)
{
  auto root_fname = new TrieNode<Entry>('\0');
  auto root_lname = new TrieNode<Entry>('\0');

  auto first_name_ref = root_fname->Insert("john");
  auto last_name_ref = root_lname->Insert("cena");

  first_name_ref->SetEntry({last_name_ref, "0795555555"});
  last_name_ref->SetEntry({first_name_ref});

  root_fname->Insert("johanna");

  std::cout << "Contents of first names trie:" << std::endl;
  std::cout << "First name\tLast name\tPhone" << std::endl;
  Print(root_fname);

  std::cout << std::endl;
  std::cout << "Contents of last names trie:" << std::endl;
  std::cout << "First name\tLast name\tPhone" << std::endl;
  Print(root_lname);



  std::cout << std::endl;

  auto first_name = root_fname->FindExact("john");
  auto last_name = root_lname->FindExact("cena");

  if (first_name != nullptr && last_name != nullptr)
  {
    std::cout << "Found firstname="
              << first_name->value
              << ", and lastname="
              << last_name->value
              << ", phone: " << first_name->entry_.phone_number << std::endl;
  }
  else
  {
    std::cout << "Not found" << std::endl;
  }

  return 0;
}
