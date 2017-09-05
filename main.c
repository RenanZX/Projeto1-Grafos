#include "grafo.h"
#include "OrganizaArquivo.h"
#include <stdio.h>

int main(){
	listaVertices* grafo = CriarLista();
	listaVertices* subgrafomaximal;
	listaVertices* subgrafomaximo;
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

	/*OrdenaDescrescente(grafo);*/
	InsereRegistrosLido(grafo);
	printf("segmentation\n");
	subgrafomaximo = getCliqueMaximo(grafo);
	subgrafomaximal = getCliqueMaximal(grafo,5);
	/*listaVertices* gr = getCliqueMaximal(grafo,49);*/

	ImprimirGrafo(grafo);
	printf("******CLIQUE MAXIMAL********\n");
	ImprimirGrafo(subgrafomaximal);
	printf("******CLIQUE MAXIMO*********\n");
	ImprimirGrafo(subgrafomaximo);

	//RemoveVertice(6,grafo);
	//imprimirgrafo(grafo);
	//printf("vertice removido\n");
	ExcluirGrafo(grafo);
	ExcluirGrafo(subgrafomaximal);
	ExcluirGrafo(subgrafomaximo);
	//ExcluirGrafo(gr);
	if(ListaVazia(grafo) == 1){
		printf("grafo vazio\n");
	}
	return 0;
}
