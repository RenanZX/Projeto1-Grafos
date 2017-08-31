#include "grafo.h"

listaVertices* CriarLista(){ //cria e retorna um grafo
	listaVertices *grafo = (listaVertices *)malloc(sizeof(listaVertices));
	grafo->primeiro = NULL;
	grafo->ultimo = NULL;
	return grafo;
}

void InsereVertice(Vertice *v,listaVertices *grafo){ //Insere Vertices no final da lista de vertices do grafo
	elemento_vertice * novoelemento = (elemento_vertice *)malloc(sizeof(elemento_vertice));
	novoelemento->vertice = v;
	novoelemento->proximo = NULL;
	novoelemento->primeiroAdj = NULL;
	novoelemento->ultimoAdj = NULL;
	if(grafo->ultimo == NULL){
		grafo->ultimo = novoelemento;
	}else{
		grafo->ultimo->proximo = novoelemento;
		grafo->ultimo = novoelemento;
	}
	if(grafo->primeiro == NULL){
		grafo->primeiro = novoelemento;
	}
}

void InsereAdjacente(Vertice* novoadjacente,Vertice* vertice,listaVertices* listav){ //insere um novo elemento adjacente
	elemento_vertice * ptr = listav->primeiro;
	while((ptr!=NULL)&&(CompararVertices(ptr->vertice,novoadjacente)!=1)){
		ptr = ptr->proximo;
	}
	if(ptr == NULL){
		return;
	}
	elemento_vertice * vert = listav->primeiro;
	while((vert!=NULL)&&(CompararVertices(vert->vertice,vertice)!=1)){
		vert = vert->proximo;
	}
	if(vert == NULL){
		return;
	}
	elemento_adjacente * novoelemento = (elemento_adjacente *)malloc(sizeof(elemento_adjacente));
	novoelemento->adjacente = ptr;
	novoelemento->proximo = NULL;
	if(vert->ultimoAdj == NULL){
		vert->ultimoAdj = novoelemento;
	}else{
		vert->ultimoAdj->proximo = novoelemento;
		vert->ultimoAdj = novoelemento;
	}
	if(vert->primeiroAdj == NULL){
		vert->primeiroAdj = novoelemento;
	}
}

/*void BuscarVertice(Vertice vertice,listaVertices *grafo){ //Busca um vertice no grafo

}*/

int ExisteVertice(Vertice* v,listaVertices *grafo){
	elemento_vertice * busca = grafo->primeiro;
	while((busca!=NULL)&&(CompararVertices(busca->vertice,v)!=1)){
		busca = busca->proximo;
	}
	if(busca == NULL){
		return 0;
	}
	return 1;
}

int ExisteAdjacente(Vertice* v1,Vertice* adjacente,listaVertices *grafo){
	elemento_vertice* busca = grafo->primeiro;
	while((busca!=NULL)&&(CompararVertices(busca->vertice,v1)!=1)){
		busca = busca->proximo;
	}
	if(busca == NULL){
		return 0;
	}
	elemento_adjacente* buscadjacente = busca->primeiroAdj;
	while((buscadjacente!=NULL)&&(CompararVertices(buscadjacente->adjacente->vertice,adjacente)!=1)){
		buscadjacente = buscadjacente->proximo;
	}
	if(buscadjacente == NULL){
		return 0;
	}
	return 1;
}

int CompararVertices(Vertice *v1,Vertice *v2){
	if((strcmp(v1->nome,v2->nome) == 0)&&(v1->matricula == v2->matricula)){
		return 1;
	}
	return 0;
}

int InsereAresta(Vertice *v1,Vertice *v2,listaVertices *grafo){ //Insere uma Aresta do vertice V1 para V2 no grafo
	if((!ExisteVertice(v1,grafo))||(!ExisteVertice(v2,grafo))){
		return 0;
	}
	if(!ExisteAdjacente(v1,v2,grafo)){
		InsereAdjacente(v2,v1,grafo);
		InsereAdjacente(v1,v2,grafo);
	}
	return 1;
}

int ListaVazia(listaVertices *grafo){ //Verifica se a lista de vertices está vazia
	if(grafo->primeiro == NULL){
		return 1;
	}
	return 0;
}

int ListaAdjVazia(Vertice* v,listaVertices *grafo){
	elemento_vertice* busca = grafo->primeiro;
	while((busca!=NULL)&&(CompararVertices(busca->vertice,v)!=1)){
		busca = busca->proximo;
	}
	if((busca == NULL)||(busca->primeiroAdj == NULL)){
		return 0;
	}
	return 1;
}

void ExcluirGrafo(listaVertices *grafo){//exclui o grafo
	elemento_vertice *ptr = grafo->primeiro;
	elemento_vertice *excluido;
	elemento_adjacente *auxiliar;
	elemento_adjacente* excluidoadj;

	while(ptr!=NULL){
		excluido = ptr;
		auxiliar = excluido->primeiroAdj;
		while(auxiliar!=NULL){
			excluidoadj = auxiliar;
			excluidoadj->adjacente = NULL;
			auxiliar = excluidoadj->proximo;
			free(excluidoadj);
			excluidoadj = NULL;
		}
		ptr = excluido->proximo;
		free(excluido);
		excluido = NULL;
	}
	grafo->primeiro = NULL;
	grafo->ultimo = NULL;
}

void RemoverAresta(Vertice *v1,Vertice *v2,listaVertices *grafo){ //remove uma aresta (v1,v2) no grafo
	elemento_vertice *busca = grafo->primeiro;
	int encontrado = 0;

	while((busca != NULL)&&(encontrado!=1)){
		busca = busca->proximo;
		encontrado = CompararVertices(busca->vertice,v1);
	}
	if(encontrado == 1){
		encontrado = 0;
		elemento_adjacente *buscar = busca->primeiroAdj;
		while((buscar != NULL)&&(encontrado!=1)){
			buscar = buscar->proximo;
			encontrado = CompararVertices(buscar->adjacente->vertice,v2);
		}
		if(encontrado==1){
			free(busca);
			busca = NULL;
		}
	}

}

void imprimirgrafo(listaVertices *grafo){
    elemento_vertice * d = grafo->primeiro;
    elemento_adjacente * t;

    while(d!=NULL){
    	printf("valor vertice\n");
    	printf("nome: %s \n",d->vertice->nome);
    	printf("matricula %d\n",d->vertice->matricula);
      t = d->primeiroAdj;
      printf("adjacentes\n");
      while(t!=NULL){
    	printf("nome: %s \n",t->adjacente->vertice->nome);
    	printf("matricula %d\n",t->adjacente->vertice->matricula);
		t = t->proximo;
      }
	  printf("\n");
      d = d->proximo;
    }
}

int MedirGrau(Vertice *v,listaVertices *grafo){ //Mede o grau de um vertice no grafo
	elemento_vertice* busca = grafo->primeiro;

	while((busca!=NULL)&&(v != busca->vertice)){
		busca = busca->proximo;
	}
	if((busca != NULL)&&(busca->vertice == v)){
		elemento_adjacente* k = busca->primeiroAdj;
		int grauvertice = 0;

		while(k!=NULL){
			grauvertice++;
			k = k->proximo;
		}
		return grauvertice;
	}
	return -1;
}
/*
listaVertices getCliqueMaximal(listaVertices *grafo){
	Vertice* v = grafo->primeiro->vertice;
	listaVertices *R = CriarLista();
	elemento_vertice* buscaclique = grafo->primeiro;
	elemento_adjacente* P = buscaclique->primeiroAdj;
	elemento_vertice* X;
	int achou = 0;

	while(achou != 1){
		InsereVertice(v,R);
		
		if(){

		}
	}

	
}
*/
/*
Vertice getVertice(listaVertices *grafo){ //pega um vertice dentro da lista de vertices do grafo

}

listaVertices getCliqueMaximo(listaVertices *grafo){

}

listaVertices getCliqueMaximal(listaVertices *grafo){

}*/
