#ifndef _H_ORGANIZAARQUIVO
#define _H_ORGANIZAARQUIVO

#include "grafo.h"

typedef struct {
  int vert, qtd_arestas;
  int arestas[51];
  char nome[50];
}Aluno;

Aluno* LerRegistros(Aluno* aluno);
listaVertices* InsereVerticesLidos(listaVertices* grafo);
/*
void ImprimirGrafoGrauDecrescente();//a implementar
void ImprimirCliqueMaximal()//a implementar
void ImprimirCliqueMaximo();//a implementar
*/

#endif