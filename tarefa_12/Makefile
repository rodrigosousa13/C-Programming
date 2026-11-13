ALL: main

main: main.o fila.o
	gcc main.o fila.o -o main

main.o: main.c fila.h
	gcc -c main.c

fila.o: fila.c fila.h
	gcc -c fila.c

clean:
	rm -f *.o main