#include "grafo.h"
#include "OrganizaArquivo.h"
#include <stdio.h>

int main(){
	listaVertices* grafo = CriarLista();
	Vertice v1,v2,v3,v4;
	strcpy(v1.nome,"a");
	v1.matricula = 1;
	strcpy(v2.nome,"b");
	v2.matricula = 2;
	strcpy(v3.nome,"c");
	v3.matricula = 3;
	strcpy(v4.nome,"mdeode");
	v4.matricula = 4;

	InsereVertice(&v1,grafo);
	InsereVertice(&v2,grafo);
	InsereVertice(&v3,grafo);
	InsereVertice(&v4,grafo);
	InsereAresta(&v1,&v2,grafo);
	InsereAresta(&v1,&v4,grafo);
	InsereAresta(&v2,&v3,grafo);
	InsereAresta(&v3,&v1,grafo);
	InsereAresta(&v3,&v2,grafo);
	imprimirgrafo(grafo);
	ExcluirGrafo(grafo);
	if(ListaVazia(grafo) == 1){
		printf("grafo vazio\n");
	}

	 Aluno* aluno = malloc(sizeof(Aluno)*50);  /* quantidade de aluno total. */
	LerRegistros(aluno);
	printf("nome = %s", aluno[22].nome);

	return 0;
}
