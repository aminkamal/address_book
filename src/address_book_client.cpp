#include "address_book.h"

ADDRESS_BOOK_API AddressBook* create_address_book()
{
  return new AddressBook();
}

ADDRESS_BOOK_API void free_address_book(AddressBook *address_book)
{
  delete address_book;
}

ADDRESS_BOOK_API int insert_entry(AddressBook *address_book, const char *first_name, const char *last_name, const char *phone_number)
{
  return address_book->InsertEntry(first_name, last_name, phone_number);
}

ADDRESS_BOOK_API void list_first_names(AddressBook *address_book)
{
  address_book->PrintSortedFirstNames();
}
