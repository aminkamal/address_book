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
    // TODO: last name
    std::cout << root->value << " , [PHONE]:" << root->entry_.phone_number << std::endl;
  }
}

int main(int argc, char **argv)
{
  auto root_fname = new TrieNode<Entry>('\0');
  auto root_lname = new TrieNode<Entry>('\0');

  auto first_name_ref = root_fname->Insert("john");
  auto last_name_ref = root_lname->Insert("cena");

  first_name_ref->SetEntry({last_name_ref, "0795555555"});
  last_name_ref->SetEntry({first_name_ref, "0795555555"});

  root_fname->Insert("johanna");

  std::cout << "Contents of first names trie:" << std::endl;
  Print(root_fname);

  std::cout << "Contents of last names trie:" << std::endl;
  Print(root_lname);

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
