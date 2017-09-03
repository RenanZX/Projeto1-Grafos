#include "grafo.h"
#include "OrganizaArquivo.h"
#include <stdio.h>

int main(){
	listaVertices* grafo = CriarLista();
	/*Vertice v1,v2,v3,v4;
	strcpy(v1.nome,"a");
	v1.matricula = 1;
	strcpy(v2.nome,"b");
	v2.matricula = 2;
	strcpy(v3.nome,"c");
	v3.matricula = 3;
	strcpy(v4.nome,"d");
	v4.matricula = 4;

	InsereVertice(&v1,grafo);
	InsereVertice(&v2,grafo);
	InsereVertice(&v3,grafo);
	InsereVertice(&v4,grafo);
	InsereAresta(&v1,&v2,grafo);
	InsereAresta(&v1,&v4,grafo);
	InsereAresta(&v2,&v3,grafo);
	InsereAresta(&v3,&v1,grafo);
	InsereAresta(&v3,&v2,grafo);*/

	InsereVerticesLidos(grafo);

	/*Vertice v5;
	strcpy(v5.nome,aluno[0].nome);
	v5.matricula = aluno[0].vert;
	InsereVertice(&v5,grafo);
	InsereAresta(&v5,&v2,grafo);

	Vertice v6;
	strcpy(v6.nome,aluno[1].nome);
	v6.matricula = aluno[1].vert;
	InsereVertice(&v6,grafo);
	InsereAresta(&v6,&v3,grafo);*/

	imprimirgrafo(grafo);
	ExcluirGrafo(grafo);
	if(ListaVazia(grafo) == 1){
		printf("grafo vazio\n");
	}



	

	return 0;
}
