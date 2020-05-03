CC = gcc
CFLAGS = -W -Wall -Werror -I src -std=c11 -g -pedantic -lm
SRCFILES = main.c
OUTPUT = bin/main

main: main.c
	@mkdir -p bin
	@$(CC) $(SRCFILES) -o $(OUTPUT) $(CFLAGS)

slug_ascii_tests: test/slug_ascii_tests.c
	@$(CC) test/slug_ascii_tests.c -I ./src -o bin/slug_ascii_tests \
		-lcheck -lpthread -lm -lrt -lsubunit

test: slug_ascii_tests
	@./bin/slug_ascii_tests
	
clean:
	@rm -rf bin

run:
	@./$(OUTPUT)

valgrind:
	valgrind --track-origins=yes --leak-check=full -s ./$(OUTPUT)
