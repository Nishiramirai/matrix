CC = gcc
CFLAGS = -Wall -Wextra -std=c11 
# TEST_FLAGS = -I/opt/homebrew/opt/check/include \
#              -L/opt/homebrew/opt/check/lib \
#              -lcheck
TEST_FLAGS = -lcheck -lm -lpthread -lrt -lsubunit
GCOV_FLAGS = --coverage -fprofile-arcs -ftest-coverage
LCOV_FILTER = --exclude='*/tests/*' --exclude='/usr/*' --ignore-errors unused

all: s21_matrix.a

s21_matrix.a:
	$(CC) $(CFLAGS) -c *.c
	ar rcs s21_matrix.a *.o

test: clean s21_matrix.a 
	$(CC) $(CFLAGS) tests/tests.c -o tests/tests ./s21_matrix.a $(TEST_FLAGS)
	./tests/tests || true

gcov_report: clean
	$(CC) $(CFLAGS) $(GCOV_FLAGS) *.c tests/tests.c -o tests/tests $(TEST_FLAGS)
	-./tests/tests
	lcov --capture --directory . --output-file coverage.info $(LCOV_FILTER)
	genhtml coverage.info --output-directory gcov_report
	open gcov_report/index.html || xdg-open gcov_report/index.html || true

clean:
	rm -rf *.o *.a tests/*.gcno tests/*.gcda coverage.info gcov_report tests/tests