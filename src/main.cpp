#include <string>
#include <iostream>

#include "trienode.h"
#include "address_book_entry.h"
#include "address_book.h"

int main(int argc, char **argv)
{
  AddressBook address_book;

  address_book.InsertEntry("John", "Cena", "07912345678");
  address_book.InsertEntry("johanna", "cina", "07999945678");
  address_book.InsertEntry("amelia", "smith", "07199945678");
  address_book.InsertEntry("amzlia", "perry", "07299945678");

  // address_book.PrintSortedFirstNames();

  // address_book.PrintSortedLastNames();

  address_book.PrintMatches("joh");

  return 0;
}
