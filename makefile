CC = gcc
CFLAGS = -W -Wall -Werror -I src -std=c11 -pedantic -lm
TESTFLAGS = -W -Wall -Werror -I src -std=c11
PROFILE_FLAGS = -fprofile-arcs -ftest-coverage
TEST_LIBS = -lcheck -lpthread -lm -lrt -lsubunit
COV_LIBS = -lgcov -coverage
SRCFILES = main.c
OUTPUT = c-slug 

main:
	@$(CC) $(SRCFILES) -O3 -o $(OUTPUT) $(CFLAGS)

create_bin_dir:
	@mkdir -p bin

slug_ascii_tests: create_bin_dir
	@$(CC) test/slug_ascii_tests.c \
		$(TEST_FLAGS) $(PROFILE_FLAGS) $(COV_LIBS) $(TEST_LIBS) \
		-I ./src -o bin/slug_ascii_tests 

slug_unicode_tests: create_bin_dir
	@$(CC) test/slug_unicode_tests.c \
		$(TEST_FLAGS) $(PROFILE_FLAGS) $(COV_LIBS) $(TEST_LIBS) \
		-I ./src -o bin/slug_unicode_tests 

clean_coverage:
	@rm -f *.html *.gcda *gcno

test: clean_coverage | slug_ascii_tests slug_unicode_tests
	@./bin/slug_ascii_tests
	@./bin/slug_unicode_tests

coverage: clean_coverage | test
	@gcovr -r . --filter src/ --html --html-details \
		-o coverage_report.html
	
.PHONY: clean

clean: clean_coverage
	@rm -rf bin $(OUTPUT)

valgrind:
	valgrind --track-origins=yes --leak-check=full -s ./$(OUTPUT)

