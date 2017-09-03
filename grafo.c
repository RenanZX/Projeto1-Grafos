#include "grafo.h"

listaVertices* CriarLista(){ //cria e retorna um grafo
	listaVertices *grafo = (listaVertices *)malloc(sizeof(listaVertices));
	grafo->primeiro = NULL;
	grafo->ultimo = NULL;
	return grafo;
}

void InsereVertice(char * nome,int matricula,listaVertices *grafo){ //Insere Vertices no final da lista de vertices do grafo
	elemento_vertice * novoelemento = (elemento_vertice *)malloc(sizeof(elemento_vertice));
	strcpy(novoelemento->nome,nome);
	novoelemento->matricula = matricula;
	novoelemento->nroadjacentes = 0;
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

void InsereAdjacente(int novoadjacentemat,int verticemat,listaVertices* listav){ //insere um novo elemento adjacente
	elemento_vertice * ptr = listav->primeiro;

	while((ptr!=NULL)&&(ptr->matricula != novoadjacentemat)){
		ptr = ptr->proximo;
	}
	if(ptr == NULL){
		return;
	}
	elemento_vertice * vert = listav->primeiro;
	while((vert!=NULL)&&(vert->matricula != verticemat)){
		vert = vert->proximo;
	}
	elemento_adjacente * novoelementoadjv1 = (elemento_adjacente *)malloc(sizeof(elemento_adjacente));
	novoelementoadjv1->adjacente = vert;
	novoelementoadjv1->proximo = NULL;
	if(ptr->ultimoAdj == NULL){
		ptr->ultimoAdj = novoelementoadjv1;
	}else{
		ptr->ultimoAdj->proximo = novoelementoadjv1;
		ptr->ultimoAdj = novoelementoadjv1;
	}
	if(ptr->primeiroAdj == NULL){
		ptr->primeiroAdj = novoelementoadjv1;
	}
	ptr->nroadjacentes++;
	
	elemento_adjacente * novoelementoadjv2 = (elemento_adjacente *)malloc(sizeof(elemento_adjacente));
	novoelementoadjv2->adjacente = ptr;
	novoelementoadjv2->proximo = NULL;
	if(vert->ultimoAdj == NULL){
		vert->ultimoAdj = novoelementoadjv2;
	}else{
		vert->ultimoAdj->proximo = novoelementoadjv2;
		vert->ultimoAdj = novoelementoadjv2;
	}
	if(vert->primeiroAdj == NULL){
		vert->primeiroAdj = novoelementoadjv2;
	}
	vert->nroadjacentes++;
}

/*void BuscarVertice(Vertice vertice,listaVertices *grafo){ //Busca um vertice no grafo

}*/

int ExisteVertice(int mat,listaVertices *grafo){
	elemento_vertice * busca = grafo->primeiro;
	while((busca!=NULL)&&(busca->matricula != mat)){
		busca = busca->proximo;
	}
	if(busca == NULL){
		return 0;
	}
	return 1;
}

int ExisteAdjacente(int v1,int adjacente,listaVertices *grafo){
	elemento_vertice* busca = grafo->primeiro;
	while((busca!=NULL)&&(busca->matricula != v1)){
		busca = busca->proximo;
	}
	if(busca == NULL){
		return 0;
	}
	elemento_adjacente* buscadjacente = busca->primeiroAdj;
	while((buscadjacente!=NULL)&&(buscadjacente->adjacente->matricula != adjacente)){
		buscadjacente = buscadjacente->proximo;
	}
	if(buscadjacente == NULL){
		return 0;
	}
	return 1;
}

int InsereAresta(int v1mat,int v2mat,listaVertices *grafo){ //Insere uma Aresta do vertice V1 para V2 no grafo
	if((ExisteVertice(v1mat,grafo)==0)&&(ExisteVertice(v2mat,grafo)==0)){
		return 0;
	}
	if(ExisteAdjacente(v1mat,v2mat,grafo)==0){
		InsereAdjacente(v2mat,v1mat,grafo);
	}
	return 1;
}

int ListaVazia(listaVertices *grafo){ //Verifica se a lista de vertices está vazia
	if(grafo->primeiro == NULL){
		return 1;
	}
	return 0;
}

int ListaAdjVazia(int v,listaVertices *grafo){
	elemento_vertice* busca = grafo->primeiro;
	while((busca!=NULL)&&(busca->matricula != v)){
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
/*
void RemoverAresta(int v1,int v2,listaVertices *grafo){ //remove uma aresta (v1,v2) no grafo
	elemento_vertice *busca = grafo->primeiro;
	int encontrado = 0;

	while((busca != NULL)&&(encontrado!=1)){
		busca = busca->proximo;
		if(busca->matricula == v1){
			encontrado = 1;
		}
	}
	if(encontrado == 1){
		encontrado = 0;
		elemento_adjacente *buscar = busca->primeiroAdj;
		while((buscar != NULL)&&(encontrado!=1)){
			buscar = buscar->proximo;
			if(busca->matricula == v2){
				encontrado = 1;
			}
		}
		if(encontrado==1){
			free(busca);
			busca = NULL;
		}
	}

}
*/
void imprimirgrafo(listaVertices *grafo){
    elemento_vertice * d = grafo->primeiro;
    elemento_adjacente * t;

    while(d!=NULL){
    	printf("valor vertice\n");
    	printf("nome: %s \n",d->nome);
    	printf("matricula %d\n",d->matricula);
      t = d->primeiroAdj;
      printf("adjacentes\n");
      while(t!=NULL){
    	printf("nome: %s \n",t->adjacente->nome);
    	printf("matricula %d\n",t->adjacente->matricula);
		t = t->proximo;
      }
	  printf("\n");
      d = d->proximo;
    }
}
/*
void RemoveVertice(int v1,listaVertices* l){
	elemento_vertice* k = l->primeiro;
	elemento_adjacente* adj;
	elemento_adjacente* deletado;
	elemento_vertice* deletadovertice;

	while((k!=NULL)&&(k->proximo->matricula != v1)){
		k = k->proximo;
	}
	if(k!=NULL){
		deletadovertice = k->proximo;
		adj = k->primeiroAdj;
		while(adj->proximo!=NULL){
			deletado = adj;
			adj = adj->proximo;
			free(deletado);
			deletado = NULL;
		}
		deletadovertice->matricula = 0;
		deletadovertice->nroadjacentes = 0;
		k->proximo = deletadovertice->proximo;
		free(deletadovertice);
		deletadovertice = NULL;
	}
}
*/
int MedirGrau(int v,listaVertices *grafo){ //Mede o grau de um vertice no grafo
	elemento_vertice* busca = grafo->primeiro;

	while((busca!=NULL)&&(v != busca->matricula)){
		busca = busca->proximo;
	}
	if((busca != NULL)&&(busca->matricula == v)){
		int grauvertice = busca->nroadjacentes;
		return grauvertice;
	}
	return -1;
}

void InterligarVertices(listaVertices* l){
	elemento_vertice* k = l->primeiro;
	elemento_vertice* j;
	elemento_adjacente* novoadj;

	while(k->proximo!=NULL){
		j = k->proximo;
		while(j!=NULL){
			novoadj = (elemento_adjacente*)malloc(sizeof(elemento_adjacente));
			novoadj->adjacente = j;
			novoadj->proximo = NULL;
			if((k->primeiroAdj == NULL)||(k->ultimoAdj == NULL)){
				k->primeiroAdj = novoadj;
				k->ultimoAdj = novoadj;
			}else{
				k->ultimoAdj->proximo = novoadj;
				k->ultimoAdj = novoadj;
			}
			k->nroadjacentes++;
			novoadj = (elemento_adjacente*)malloc(sizeof(elemento_adjacente));
			novoadj->adjacente = k;
			novoadj->proximo = NULL;
			if((j->primeiroAdj == NULL)||(j->ultimoAdj == NULL)){
				j->primeiroAdj = novoadj;
				j->ultimoAdj = novoadj;
			}else{
				j->ultimoAdj->proximo = novoadj;
				j->ultimoAdj = novoadj;
			}
			j->nroadjacentes++;
			j = j->proximo;
		}
		k = k->proximo;
	}
}

listaVertices *getCliqueMaximal(listaVertices *grafo,int nrovertices){
	int counter = 0;
	int achou = 0;
	listaVertices* lret  = CriarLista();

	if(nrovertices == 1){
		InsereVertice(grafo->primeiro->nome,grafo->primeiro->matricula,lret);
		return lret;
	}

	elemento_vertice* k = grafo->primeiro;
	elemento_adjacente* adj;
	elemento_adjacente* verificarcombinacao;
	elemento_adjacente* verificadj;
	elemento_vertice* v1;
	elemento_vertice* v2;

	while((k!=NULL)&&(achou!=1)){
		if(k->nroadjacentes >= (nrovertices-1)){
			counter = nrovertices-1;
			adj = k->primeiroAdj;
			while((adj!=NULL)&&((achou!=-1)&&(counter<=0))){
				if(adj->adjacente->nroadjacentes < (nrovertices-1)){
					achou = -1;
				}
				adj = adj->proximo;
				counter--;
			}
			if(achou!=-1){
				achou = 1;
			}
		}
		if(achou!=1){
			k = k->proximo;
		}
	}


	if(achou == 1){
		achou = 0;
		InsereVertice(k->nome,k->matricula,lret);
		adj = k->primeiroAdj;
		v1 = adj->adjacente;
		verificadj = adj;
		counter = nrovertices-1;
		while((verificadj->proximo!=NULL)&&((achou!=-1)&&(counter!=0))){
			while((adj->proximo!=NULL)&&(achou!=-1)){
				v2 = adj->proximo->adjacente;
				verificarcombinacao = v1->primeiroAdj;
				while((verificarcombinacao->proximo!=NULL)&&(achou!=1)){
					if(v2->matricula == verificarcombinacao->adjacente->matricula){
						achou = 1;
					}
					verificarcombinacao = verificarcombinacao->proximo;
				}
				if(verificarcombinacao == NULL){
					achou = -1;
				}
				adj = adj->proximo;
			}
			InsereVertice(v1->nome,v1->matricula,lret);
			verificadj = verificadj->proximo;
			adj = verificadj;
			v1 = adj->adjacente;
			counter--;
		}
		if(achou == -1){
			return NULL;
		}
		InsereVertice(v1->nome,v1->matricula,lret);
		InterligarVertices(lret);
	}
	return lret;
}

/*
Vertice getVertice(listaVertices *grafo){ //pega um vertice dentro da lista de vertices do grafo

}

listaVertices getCliqueMaximo(listaVertices *grafo){

}

listaVertices getCliqueMaximal(listaVertices *grafo){

}*/
