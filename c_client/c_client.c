#include <stdio.h>
#include "../src/address_book.h"

int main(int argc, char *argv[])
{
  printf("Hello from C\n\n");

  struct address_book *my_address_book = create_address_book();

  int inserted = insert_entry(my_address_book, "john", "cena", "07912345678");
  if (inserted)
    printf("Entry inserted successfully into the address book!\n\n");

  list_first_names(my_address_book);

  free_address_book(my_address_book);

  return 0;
}
