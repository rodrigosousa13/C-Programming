ALL: main

main: main.o abb.o
	gcc main.o abb.o -o main

main.o: main.c abb.h
	gcc -c main.c

abb.o: abb.c abb.h
	gcc -c abb.c

clean:
	rm -f *.o main