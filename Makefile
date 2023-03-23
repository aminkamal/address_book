.PHONY=all run client

all:
	g++ src/main.cpp src/address_book.cpp -o bin/address_book

run: all
	@./bin/address_book

client:
	g++ src/address_book.cpp src/address_book_client.cpp -fPIC -shared -o bin/lib_address_book.so
	gcc c_client/c_client.c -o bin/my_c_program -I. -L. bin/lib_address_book.so
	./bin/my_c_program 

valgrind:
	valgrind --leak-check=yes ./bin/address_book
