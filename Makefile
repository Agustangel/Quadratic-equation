
INCLUDES=include
SOURCE=source
TESTS=tests

test: quadratic.o unit_tests.o
	gcc -o test quadratic.o unit_tests.o -lm

equation: main.o quadratic.o
	gcc -o equation main.o quadratic.o -lm

main.o: main.c ${INCLUDES}/quadratic.h
	gcc -I ${INCLUDES} -c main.c

quadratic.o: ${SOURCE}/quadratic.c ${INCLUDES}/quadratic.h
	gcc -I ${INCLUDES} -c ${SOURCE}/quadratic.c

unit_tests.o: ${TESTS}/unit_tests.c ${INCLUDES}/unit_tests.h ${INCLUDES}/quadratic.h
	gcc -I ${INCLUDES} -c ${TESTS}/unit_tests.c

clean:
	rm test main.o quadratic.o unit_tests.o
