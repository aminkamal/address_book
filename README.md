# Address Book C++

Sample C++ application, uses two Tries to store first and last names with an optional phone number.

A Trie data structure was the most suitable one for this problem as retrievals are expected to be the most common operations. Tries allows for efficient lookups of prefixes (first names starting with a certain prefix in an address book which can contain a huge number of other unrelated prefixes/names).

Additionally, by simplyfing the problem to only handle ASCII names, it's easier to get a sorted output without expensive sorting operations.

It supports the following
- Adding a new entry
- Finding exact entry matches in either first name or last name
- Finding partial matches starting from the beginning, e.g. Mar would match Mark and Marianne
- Deleting an entry, soft delete, it just removes the end of word marker from the list
- Listing first or last names sorted alphabetically

Potential improvements
- Reduce memory consumption by removing the value member variable in `trienode.h` and reconstructing strings on the go.
- Deleting an entry to free unused trie nodes (e.g. by using reference counting)
- Supporting duplicate names or names with similar last names, because this isn't supported at the moment
- Finding partial matches that can start from anywhere in the string, and not just from the beginning

# Running

To run the application, use:

```
make run
```
it has some examples, so you should see something on stdout.

To test the shared library and using it from a C program, run:
```
make client
```

To check the program using Valgrind, run:
```
make valgrind
```
