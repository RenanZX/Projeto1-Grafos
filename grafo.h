#ifndef _H_GRAFO
#define _H_GRAFO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ElementoAdjacente
{
	struct Elemento * adjacente;
	struct ElementoAdjacente * proximo;
}elemento_adjacente;

typedef struct Elemento //Elemento da lista de vertices contendo o ponteiro para o conteúdo do vertice e os outros elementos do grafo
{
	char nome[1000];
	int matricula;
	int nroadjacentes;
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
void InsereVertice(char * nome,int matricula,listaVertices *grafo); //Insere Vertices na lista do grafo
void InsereAdjacente(int novoadjacentemat,int verticemat,listaVertices* listav); //tendo duas matriculas insere um novo elemento adjacente no vertice
/*void BuscarVertice(Vertice vertice,listaVertices *grafo); //Busca um vertice no grafo
*/
int ExisteVertice(int mat,listaVertices *grafo); //verifica a existencia de vertices apartir da matricula do aluno no grafo
int ExisteAdjacente(int v1,int adjacente,listaVertices *grafo); //verifica a existencia de adjacentes no vertice com matricula v no grafo
int InsereAresta(int v1mat,int v2mat,listaVertices *grafo); //Insere uma Aresta do vertice V1 para V2 no grafo
int ListaVazia(listaVertices *grafo); //Verifica se a lista de vertices está vazia
int ListaAdjVazia(int v,listaVertices *grafo); //Verifica se a lista de vertices adjacentes em relação a v no grafo está vazia
void ExcluirGrafo(listaVertices *grafo);//exclui o grafo
//void RemoverAresta(int v1,int v2,listaVertices *grafo); //remove uma aresta (v1,v2) no grafo
//void RemoveVertice(int v1,listaVertices* l); //remove um vertice do grafo
void imprimirgrafo(listaVertices *grafo); //imprime os valores do grafo na tela
int MedirGrau(int v,listaVertices *grafo); //Mede o grau de um vertice no grafo
void InterligarVertices(listaVertices* l); //Interliga todos os vertices do grafo
listaVertices* getCliqueMaximal(listaVertices *grafo,int nrovertices); //retorna um clique maximal recebendo um grafo e um numero contendo a quantidade de vertices
/*
Vertice getVertice(listaVertices *grafo); //pega um vertice dentro da lista de vertices do grafo

listaVertices getCliqueMaximo(listaVertices *grafo);
*/

#endif
