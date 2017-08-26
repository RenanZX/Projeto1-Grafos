all:programa clean
programa:main.o grafo.o
	gcc main.o grafo.o -Wall -o programa

main.o:main.c grafo.c grafo.h
	gcc -c main.c

grafo.o:grafo.c grafo.h
	gcc -c grafo.c

clean:
	rm -rf *.o