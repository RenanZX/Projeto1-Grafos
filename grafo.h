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
	int cliquepego;
	int marcado;
	struct Elemento * proximo;
	struct ElementoAdjacente * primeiroAdj;
	struct ElementoAdjacente * ultimoAdj;
}elemento_vertice;

typedef struct listav //lista de vertices do grafo
{
	elemento_vertice * primeiro;
	elemento_vertice * ultimo;
}listaVertices;

int poscliques;

listaVertices ** cliques;

listaVertices* CriarLista(); //cria e retorna um grafo
void InsereVertice(char * nome,int matricula,listaVertices *grafo); //Insere Vertices na lista do grafo
void InsereAdjacente(int novoadjacentemat,int verticemat,listaVertices* listav); //tendo duas matriculas insere um novo elemento adjacente no vertice
int ExisteVertice(int mat,listaVertices *grafo); //verifica a existencia de vertices apartir da matricula do aluno no grafo
int ExisteAdjacente(int v1,int adjacente,listaVertices *grafo); //verifica a existencia de adjacentes no vertice com matricula v no grafo
int InsereAresta(int v1mat,int v2mat,listaVertices *grafo); //Insere uma Aresta do vertice V1 para V2 no grafo
int ListaVazia(listaVertices *grafo); //Verifica se a lista de vertices está vazia
int ListaAdjVazia(int v,listaVertices *grafo); //Verifica se a lista de vertices adjacentes em relação a v no grafo está vazia
void ExcluirGrafo(listaVertices *grafo);//exclui o grafo
void ImprimirGrafo(listaVertices *grafo); //imprime os valores do grafo na tela
void RemoveVertice(int v,listaVertices* grafo);
void RemoveInicio(listaVertices* grafo);
void CopiarLista(listaVertices* l1 ,listaVertices* l2);
listaVertices* UnirListas(listaVertices* l1,listaVertices* l2);
//void BronkerBosch(listaVertices* P,listaVertices* R,listaVertices *X);
listaVertices* IntersecionarListas(listaVertices* l1,listaVertices *l2);
listaVertices* IntersecionarListas_v(listaVertices* l1,elemento_vertice* l2);
int MedirGrau(int v,listaVertices *grafo); //Mede o grau de um vertice no grafo
void InterligarVertices(listaVertices* l); //Interliga todos os vertices do grafo
void ApagarMarcas(listaVertices* grafo);//apaga marcas do grafo
listaVertices* getCliqueMaximal(listaVertices *grafo,int nrovertices); //retorna um clique maximal recebendo um grafo e um numero contendo a quantidade de vertices
listaVertices* getCliqueMaximo(listaVertices *grafo); //retorna um clique maximo do grafo

#endif
