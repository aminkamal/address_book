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
  address_book.InsertEntry("no", "phone");

  address_book.PrintSortedFirstNames();

  address_book.PrintSortedLastNames();

  address_book.PrintMatches("joh");

  bool deleted = address_book.DeleteEntry("John");
  if (deleted)
  {
    std::cout << std::endl << "Successfully deleted entry" << std::endl << std::endl;

    address_book.PrintSortedFirstNames();
  }

  return 0;
}
