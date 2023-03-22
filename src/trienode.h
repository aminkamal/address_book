#pragma once

const int MAX_CHARS = 26;

template <class T>
class TrieNode
{
private:
  const TrieNode* find(const std::string &string_to_find) const
  {
    const TrieNode *at = this;
    for (auto &character : string_to_find)
    {
      if (at->children[character - 'a'] != nullptr)
      {
        at = at->children[character - 'a'];
      }
      else
      {
        return nullptr;
      }
    }

    return at;
  }

public:
  mutable bool is_end_marker;
  char contents;
  T entry_;
  TrieNode *children[MAX_CHARS] = {};
  std::string value;

  TrieNode(char character)
      : is_end_marker(false), contents(character), entry_({})
  {
  }

  ~TrieNode()
  {
    for (auto &child : children)
    {
      delete child;
      child = nullptr;
    }
  }

  const TrieNode* FindAny(std::string string_to_find) const noexcept
  {
    auto at = find(string_to_find);

    if (at != this)
      return at;

    return nullptr;
  }

  const TrieNode* FindExact(std::string string_to_find) const noexcept
  {
    auto at = find(string_to_find);

    if (at->is_end_marker)
      return at;

    return nullptr;
  }

  bool Unset(std::string string_to_find) const noexcept
  {
    auto at = find(string_to_find);

    if (at != this)
    {
      at->is_end_marker = false;
      return true;
    }

    return false;
  }

  TrieNode* Insert(std::string str) noexcept
  {
    TrieNode *at = this;

    for (auto &character : str)
    {
      if (at->children[character - 'a'] == nullptr)
      {
        at->children[character - 'a'] = new TrieNode(character);
      }
      at = at->children[character - 'a'];
    }
    at->is_end_marker = true;
    at->value = str;

    return at;
  }

  void SetEntry(T &&entry) noexcept
  {
    entry_ = entry;
  }
};
