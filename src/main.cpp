#include <string>
#include <iostream>
#include <map>

template <class T>
class TrieNode
{
public:
  std::map<char, TrieNode *> children;
  char contents;
  bool is_end_marker;
  T entry_;

  TrieNode(char character)
    : is_end_marker(false), contents(character), entry_({})
  {
  }

  ~TrieNode()
  {
    for (auto &child : children)
    {
      delete child.second;
    }
    children.clear();
  }

  TrieNode *Find(std::string string_to_find)
  {
    TrieNode *at = this;

    for (auto &character : string_to_find)
    {
      auto it = at->children.find(character);
      if (it != at->children.end())
      {
        at = at->children[character];
      }
      else
      {
        return nullptr;
      }
    }

    if (at->is_end_marker)
      return at;

    return nullptr;
  }

  TrieNode* Insert(std::string str)
  {
    TrieNode *at = this;

    for (auto &character : str)
    {
      // std::cout << character << std::endl;
      auto it = at->children.find(character);
      if (it == at->children.end())
      {
        at->children.insert(std::make_pair(character, new TrieNode<T>(character)));
      }
      at = at->children[character];
    }
    at->is_end_marker = true;

    return at;
  }

  void SetEntry(T&& entry)
  {
    entry_ = entry;
  }

};

struct Entry {
  TrieNode<Entry> *first_name_ref;
  TrieNode<Entry> *last_name_ref;
  std::string phone_number;
};

int main(int argc, char **argv)
{
  auto root_fname = new TrieNode<Entry>('\0');
  auto root_lname = new TrieNode<Entry>('\0');

  auto first_name_ref = root_fname->Insert("john");
  auto last_name_ref = root_lname->Insert("cena");
  // root->Insert("johanna");

  first_name_ref->SetEntry({first_name_ref, last_name_ref, "0795555555"});
  last_name_ref->SetEntry({first_name_ref, last_name_ref, "0795555555"});

  auto john = root_fname->Find("john");
  auto cena = root_lname->Find("cena");

  bool has_john_cena = false;
  if (john != nullptr && cena != nullptr)
  {
    has_john_cena = john->entry_.last_name_ref == cena->entry_.last_name_ref;
  }

  if (has_john_cena)
  {
    std::cout << "Contains 'john cena':"
              << has_john_cena
              << ", phone: " << john->entry_.phone_number << std::endl;
  }
  else
  {
    std::cout << "Not found" << std::endl;
  }

  return 0;
}
