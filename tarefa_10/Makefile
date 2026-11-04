ALL: main

main: main.o lde.o
	gcc main.o lde.o -o main

main.o: main.c lde.h
	gcc -c main.c

lde.o: lde.c lde.h
	gcc -c lde.c

clean:
	rm -f *.o main