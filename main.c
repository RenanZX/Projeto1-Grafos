#include "grafo.h"
#include "OrganizaArquivo.h"
#include <stdio.h>

int main(){
	listaVertices* grafo = CriarLista();

	/*InsereVertice("a",1,grafo);
	InsereVertice("b",2,grafo);
	InsereVertice("c",3,grafo);
	InsereVertice("d",4,grafo);
	InsereVertice("e",5,grafo);
	InsereVertice("f",6,grafo);
	InsereAresta(1,2,grafo);
	InsereAresta(1,3,grafo);
	InsereAresta(1,4,grafo);
	InsereAresta(1,5,grafo);
	InsereAresta(2,3,grafo);
	InsereAresta(2,4,grafo);
	InsereAresta(2,5,grafo);
	InsereAresta(2,6,grafo);
	InsereAresta(3,4,grafo);
	InsereAresta(3,5,grafo);
	InsereAresta(4,5,grafo);
	InsereAresta(5,6,grafo);*/

	InsereRegistrosLido(grafo);

	listaVertices* gr = getCliqueMaximal(grafo,49);

	ImprimirGrafo(grafo);

	//RemoveVertice(6,grafo);
	//imprimirgrafo(grafo);
	printf("vertice removido\n");
	ExcluirGrafo(grafo);
	//ExcluirGrafo(gr);
	if(ListaVazia(grafo) == 1){
		printf("grafo vazio\n");
	}
	return 0;
}
