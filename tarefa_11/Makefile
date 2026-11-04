ALL: main

main: main.o lista_polimorfica.o
	gcc main.o lista_polimorfica.o -o main

main.o: main.c lista_polimorfica.h
	gcc -c main.c

lista_polimorfica.o: lista_polimorfica.c lista_polimorfica.h
	gcc -c lista_polimorfica.c

clean:
	rm -f *.o main