

tests : quadratic.o unit_tests.o
	gcc -o tests quadratic.o unit_tests.o -lm

equation: main.o quadratic.o
	gcc -o equation main.o quadratic.o -lm

main.o: main.c quadratic.h
	gcc -c main.c

quadratic.o: quadratic.c quadratic.h
	gcc -c quadratic.c

unit_tests.o: unit_tests.c unit_tests.h quadratic.h
	gcc -c unit_tests.c

clean :
	rm tests main.o quadratic.o unit_tests.o
