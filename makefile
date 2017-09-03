all:programa clean
programa:main.o grafo.o OrganizaArquivo.o
	gcc main.o grafo.o OrganizaArquivo.o -Wall -o Projeto1

main.o:main.c grafo.c grafo.h OrganizaArquivo.c OrganizaArquivo.h
	gcc -c main.c

grafo.o:grafo.c grafo.h
	gcc -c grafo.c

OrganizaArquivo.o:OrganizaArquivo.c OrganizaArquivo.h
	gcc -c OrganizaArquivo.c

clean:
	rm -rf *.o