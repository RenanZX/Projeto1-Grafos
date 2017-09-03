#include "grafo.h"
#include "OrganizaArquivo.h"
#include <stdio.h>

int main(){
	listaVertices* grafo = CriarLista();

	InsereVertice("a",1,grafo);
	InsereVertice("b",2,grafo);
	InsereVertice("c",3,grafo);
	InsereVertice("d",4,grafo);
	InsereAresta(1,2,grafo);
	InsereAresta(1,4,grafo);
	InsereAresta(2,3,grafo);
	InsereAresta(3,1,grafo);
	InsereAresta(3,2,grafo);
	imprimirgrafo(grafo);
	ExcluirGrafo(grafo);
	if(ListaVazia(grafo) == 1){
		printf("grafo vazio\n");
	}
	return 0;
}
