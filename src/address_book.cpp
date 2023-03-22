#include "address_book.h"
#include <algorithm>

AddressBook::AddressBook()
  : root_first_names('\0'), root_last_names('\0')
{
}

void AddressBook::Print(
  const TrieNode<Entry> *root,
  bool is_first_names_trie = true,
  bool swap_first_last_names = false
)
{
  for (int i = 0; i < MAX_CHARS; i++)
  {
    if (root->children[i] != nullptr)
      Print(root->children[i], is_first_names_trie, swap_first_last_names);
  }

  if (root->is_end_marker)
  {
    std::string name_1 = root->value;
    std::string name_2 = root->entry_.name_reference->value;
    std::string phone_number = "Unspecified";

    if (is_first_names_trie)
    {
      phone_number = root->entry_.phone_number;
    }
    else
    {
      phone_number = root->entry_.name_reference->entry_.phone_number;
    }

    if (swap_first_last_names)
      std::swap(name_1, name_2);

    std::cout
        << name_1
        << "\t\t" << name_2
        << "\t\t" << phone_number
        << std::endl;
  }
}

void AddressBook::PrintSortedFirstNames()
{
  std::cout << "Contents of first names trie:" << std::endl;
  std::cout << "First name\tLast name\tPhone" << std::endl;
  Print(&root_first_names);
  std::cout << std::endl;
}

void AddressBook::PrintSortedLastNames()
{
  std::cout << "Contents of last names trie:" << std::endl;
  std::cout << "Last name\tFirst name\tPhone" << std::endl;
  Print(&root_last_names, false);
  std::cout << std::endl;
}

void AddressBook::PrintMatches(std::string name_to_find)
{
  std::cout << "Matched results:" << std::endl;
  std::cout << "First name\tLast name\tPhone" << std::endl;

  auto first_name_pos = root_first_names.FindAny(name_to_find);
  auto last_name_pos = root_last_names.FindAny(name_to_find);

  if (first_name_pos != nullptr)
  {
    Print(first_name_pos);
  }

  if (last_name_pos != nullptr)
  {
    Print(last_name_pos, false, true);
  }
}

void AddressBook::ToLowerCase(std::string &str)
{
  std::transform(str.begin(), str.end(), str.begin(),
    [](unsigned char c){ return std::tolower(c); });
}

bool AddressBook::InsertEntry(
  std::string first_name, std::string last_name, std::string phone_number
)
{
  TrieNode<Entry>* last_name_ref = nullptr;

  ToLowerCase(first_name);

  ToLowerCase(last_name);

  auto first_name_ref = root_first_names.Insert(first_name);

  if (!last_name.empty())
  {
    last_name_ref = root_last_names.Insert(last_name);
  }

  first_name_ref->SetEntry({last_name_ref, phone_number});
  last_name_ref->SetEntry({first_name_ref});

  return true;
}
