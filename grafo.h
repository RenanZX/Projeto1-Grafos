#ifndef _H_GRAFO
#define _H_GRAFO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vertice{ //Vertice do grafo
	char nome[100];
	int matricula;
}Vertice;

typedef struct ElementoAdjacente
{
	struct Elemento * adjacente;
	struct ElementoAdjacente * proximo;
}elemento_adjacente;

typedef struct Elemento //Elemento da lista de vertices contendo o ponteiro para o conteúdo do vertice e os outros elementos do grafo
{
	Vertice * vertice;
	struct Elemento * proximo;
	struct ElementoAdjacente * primeiroAdj;
	struct ElementoAdjacente * ultimoAdj;
}elemento_vertice;

typedef struct listav //lista de vertices do grafo
{
	elemento_vertice * primeiro;
	elemento_vertice * ultimo;
}listaVertices;

listaVertices* CriarLista(); //cria e retorna um grafo
void InsereVertice(Vertice *v,listaVertices *grafo); //Insere Vertices na lista do grafo
void InsereAdjacente(Vertice* novoadjacente,Vertice* vertice,listaVertices* listav); //insere um novo elemento adjacente no vertice
/*void BuscarVertice(Vertice vertice,listaVertices *grafo); //Busca um vertice no grafo
*/
int ExisteVertice(Vertice* v,listaVertices *grafo); //verifica a existencia de vertices no grafo
int ExisteAdjacente(Vertice* v1,Vertice* adjacente,listaVertices *grafo); //verifica a existencia de adjacentes no vertice v no grafo
int CompararVertices(Vertice *v1,Vertice *v2); // compara dois vertices e retorna 1 caso sejam iguais e 0 caso contrario
int InsereAresta(Vertice *v1,Vertice *v2,listaVertices *grafo); //Insere uma Aresta do vertice V1 para V2 no grafo
int ListaVazia(listaVertices *grafo); //Verifica se a lista de vertices está vazia
int ListaAdjVazia(Vertice *v,listaVertices *grafo); //Verifica se a lista de vertices adjacentes em relação a v no grafo está vazia
void ExcluirGrafo(listaVertices *grafo);//exclui o grafo
void RemoverAresta(Vertice *v1,Vertice *v2,listaVertices *grafo); //remove uma aresta (v1,v2) no grafo
void imprimirgrafo(listaVertices *grafo); //imprime os valores do grafo na tela

/*
Vertice getVertice(listaVertices *grafo); //pega um vertice dentro da lista de vertices do grafo

int MedirGrau(Vertice *v,listaVertices *grafo); //Mede o grau de um vertice no grafo

listaVertices getCliqueMaximo(listaVertices *grafo);

listaVertices getCliqueMaximal(listaVertices *grafo);
*/

#endif
