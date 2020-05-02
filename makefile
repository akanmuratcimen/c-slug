CC = gcc 
CFLAGS = -W -Wall -Werror -I -std=c11 -g -pedantic -lm
SRCFILES = main.c
OUTPUT = bin/main

main: main.c
	@mkdir -p bin
	@$(CC) $(SRCFILES) -o $(OUTPUT) $(CFLAGS)

clean:
	@rm -rf bin

run:
	./$(OUTPUT)

valgrind:
	valgrind --track-origins=yes --leak-check=full -s ./$(OUTPUT)
