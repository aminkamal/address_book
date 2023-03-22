#pragma once

#include "trienode.h"

struct Entry
{
  TrieNode<Entry> *name_reference;
  std::string phone_number;
};
