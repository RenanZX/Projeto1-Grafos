#ifndef _H_ORGANIZAARQUIVO
#define _H_ORGANIZAARQUIVO

#include "grafo.h"

typedef struct {
  int vert, qtd_arestas;
  int arestas[51];
  char nome[50];
}Aluno;
Aluno* LerRegistros(Aluno* aluno);
Aluno* OrdenaDescrescente(Aluno* aluno);

listaVertices* InsereRegistrosLido(listaVertices* grafo);
/*
listaVertices LerRegistros(string caminhoArquivo);//a implementar
void ImprimirGrafoGrauDecrescente();//a implementar
void ImprimirCliqueMaximal()//a implementar
void ImprimirCliqueMaximo();//a implementar
*/
#endif