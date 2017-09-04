#ifndef _H_ORGANIZAARQUIVO
#define _H_ORGANIZAARQUIVO

#include "grafo.h"

typedef struct {
  int vert, qtd_arestas;
  int arestas[51];
  char nome[50];
}Aluno;
Aluno* LerRegistros(Aluno* aluno);
Aluno* GrafoGrauDecrescente(Aluno* aluno);

listaVertices* InsereRegistrosLido(listaVertices* grafo);
/*
void ImprimirCliqueMaximal()//a implementar
void ImprimirCliqueMaximo();//a implementar
*/
#endif