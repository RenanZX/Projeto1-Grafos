#include "grafo.h"

int poscliques = 0;

listaVertices* CriarLista(){ //cria e retorna um grafo
	listaVertices *grafo = (listaVertices *)malloc(sizeof(listaVertices));
	grafo->primeiro = NULL;
	grafo->ultimo = NULL;
	return grafo;
}

void InsereVertice(char * nome,int matricula,listaVertices *grafo){ //Insere Vertices no final da lista de vertices do grafo
	elemento_vertice * novoelemento = (elemento_vertice *)malloc(sizeof(elemento_vertice)); /*cria um novo elemento*/
	strcpy(novoelemento->nome,nome); /*insere o nome e a matricula recebida como parametro*/
	novoelemento->matricula = matricula;
	novoelemento->nroadjacentes = 0; /*zera o numero de adjacentes ao vertice*/
	novoelemento->cliquepego = 0;
	novoelemento->marcado = 0;
	novoelemento->proximo = NULL;
	novoelemento->primeiroAdj = NULL;
	novoelemento->ultimoAdj = NULL;
	if(grafo->ultimo == NULL){ /*testa se o ultimo e nulo*/
		grafo->ultimo = novoelemento; /*caso seja nulo o novo elemento criado sera este elemento*/
	}else{
		grafo->ultimo->proximo = novoelemento; /*caso contrario o novoelemento sera o proximo depois do ultimo elemento da lista*/
		grafo->ultimo = novoelemento; /*sendo ele o novo ultimo elemento da listaa*/
	}
	if(grafo->primeiro == NULL){ /*caso o primeiro da lista seja nulo,ele tambem sera o primeiro*/
		grafo->primeiro = novoelemento;
	}
}

void InsereAdjacente(int novoadjacentemat,int verticemat,listaVertices* listav){ //insere um novo elemento adjacente no vertice
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
	elemento_adjacente * novoelementoadjv1 = (elemento_adjacente *)malloc(sizeof(elemento_adjacente));//aloca um novo elemento adjacente para a lista do novoadjacentemat
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
	
	elemento_adjacente * novoelementoadjv2 = (elemento_adjacente *)malloc(sizeof(elemento_adjacente));//aloca um novo elemento para a lista do verticemat
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
	vert->nroadjacentes++;//incrementa o numero de adjacentes pertencentes ao vertice
}

int ExisteVertice(int mat,listaVertices *grafo){ //verifica se existe um vertice no grafo
	elemento_vertice * busca = grafo->primeiro;
	while((busca!=NULL)&&(busca->matricula != mat)){ //faz a busca
		busca = busca->proximo;
	}
	if(busca == NULL){
		return 0; //retorna 0 caso nao encontre
	}
	return 1;
}

int ExisteAdjacente(int v1,int adjacente,listaVertices *grafo){
	elemento_vertice* busca = grafo->primeiro;
	while((busca!=NULL)&&(busca->matricula != v1)){//faz a busca pelo vertice
		busca = busca->proximo;
	}
	if(busca == NULL){
		return 0; //retorna 0 caso nao encontre
	}
	elemento_adjacente* buscadjacente = busca->primeiroAdj; //faz a busca pelo adjacente
	while((buscadjacente!=NULL)&&(buscadjacente->adjacente->matricula != adjacente)){
		buscadjacente = buscadjacente->proximo;
	}
	if(buscadjacente == NULL){
		return 0; //retorna 0 caso nao encontre
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

void ImprimirGrafo(listaVertices *grafo){
    elemento_vertice * d = grafo->primeiro;
    elemento_adjacente * t;

    while(d!=NULL){
      t = d->primeiroAdj;
      printf("\n lista de Adjacentes do vertice %d\n head ", d->matricula);
      while(t!=NULL){
	      printf("-> %d", t->adjacente->matricula);
				t = t->proximo;
    	}
	  	printf("\n");
    	d = d->proximo;
    }
}

int MedirGrau(int v,listaVertices *grafo){ //Mede o grau de um vertice no grafo
	elemento_vertice* busca = grafo->primeiro;

	while((busca!=NULL)&&(v != busca->matricula)){ /*busca o vertice no grafo*/
		busca = busca->proximo;
	}
	if((busca != NULL)&&(busca->matricula == v)){ /*ao encontrar verifica quantas ligacoes o mesmo possui e retorna o grau*/
		int grauvertice = busca->nroadjacentes;
		return grauvertice;
	}
	return -1; /*caso contrario retorna -1*/
}

void InterligarVertices(listaVertices* l){ /*interliga todos os vertices do grafo*/
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

void ApagarMarcas(listaVertices* grafo){
	elemento_vertice* k = grafo->primeiro;

	while(k!=NULL){
		if(k->marcado == 1){
			k->marcado = 0;
		}
		k = k->proximo;
	}

}

void RemoveVertice(int v,listaVertices * grafo){
	elemento_vertice * k = grafo->primeiro;
	elemento_vertice * removido;
	int achou = 0;

	while((k!=NULL)&&(achou!=1)){
		if(v == k->matricula){
			removido = k;
			k = k->proximo;
			free(removido);
			removido = NULL;
			achou = 1;
		}else{
			k = k->proximo;	
		}
	}

}

void RemoveInicio(listaVertices* grafo){
	elemento_vertice * removido = grafo->primeiro;
	grafo->primeiro = removido->proximo;
	free(removido);
}

listaVertices* UnirListas(listaVertices* l1,listaVertices* l2){
	elemento_vertice* alvo = l1->primeiro;
	elemento_vertice* alvo2 = l2->primeiro;
	listaVertices* retorno = CriarLista();

	while(alvo!=NULL){
		while(alvo2!=NULL){
			if(alvo->matricula!=alvo2->matricula){
				InsereVertice(alvo->nome,alvo->matricula,retorno);
			}
			alvo2 = alvo2->proximo;
		}
		alvo = alvo->proximo;
	}
	return retorno;
}

listaVertices* IntersecionarListas(listaVertices* l1,listaVertices *l2){
	elemento_vertice* alvo = l1->primeiro;
	elemento_vertice* alvo2 = l2->primeiro;
	listaVertices* retorno = CriarLista();

	while(alvo!=NULL){
		while(alvo2!=NULL){
			if(alvo->matricula==alvo2->matricula){
				InsereVertice(alvo->nome,alvo->matricula,retorno);
			}
			alvo2 = alvo2->proximo;
		}
		alvo = alvo->proximo;
	}
	return retorno;
}

listaVertices* IntersecionarListas_v(listaVertices* l1,elemento_vertice * l2){
	elemento_vertice* alvo = l1->primeiro;
	elemento_adjacente* alvo2 = l2->primeiroAdj;
	listaVertices* retorno = CriarLista();

	while(alvo!=NULL){
		while(alvo2!=NULL){
			if(alvo->matricula==alvo2->adjacente->matricula){
				InsereVertice(alvo->nome,alvo->matricula,retorno);
			}
			alvo2 = alvo2->proximo;
		}
		alvo = alvo->proximo;
	}
	return retorno;
}

void CopiarLista(listaVertices* l1,listaVertices* l2){
	elemento_vertice* k = l2->primeiro;

	while(k!=NULL){
		InsereVertice(k->nome,k->matricula,l1);
		k = k->proximo;
	}
}

void BronkerBosh(listaVertices *P,listaVertices * R,listaVertices *X){
	listaVertices* R_verificar;
	listaVertices* X_verificar;
	listaVertices* P_verificar;

	if(ListaVazia(P)==1){
		if(ListaVazia(X)==1){
			cliques[poscliques] = R;
			poscliques++;
		}else{
			ExcluirGrafo(R);
		}
	}else{
		while(P->primeiro!=NULL){
			CopiarLista(R_verificar,R);
			InsereVertice(P->primeiro->nome,P->primeiro->matricula,R_verificar);
			P_verificar = IntersecionarListas_v(P,P->primeiro);
			X_verificar = IntersecionarListas_v(X,P->primeiro);
			BronkerBosh(P,R,X);
			InsereVertice(P->primeiro->nome,P->primeiro->matricula,X);
			RemoveInicio(P);
			ExcluirGrafo(P_verificar);
			ExcluirGrafo(X_verificar);
		}
	}
}


listaVertices *getCliqueMaximal(listaVertices *grafo,int nrovertices){ /*retorna um clique maximal dentro do grafo*/
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

	while((k!=NULL)&&(achou!=1)){ /*procura um vertice que possui adjacentes com a mesma quantidade de ligações deste vertice*/
		if((k->nroadjacentes >= (nrovertices-1))&&(k->cliquepego == 0)){
			counter = nrovertices-1;
			adj = k->primeiroAdj;
			while((adj!=NULL)&&((achou!=-1)&&(counter<=0))){
				if((adj->adjacente->nroadjacentes < (nrovertices-1))||(adj->adjacente->cliquepego == 1)){
					achou = -1;
				}
				adj = adj->proximo;
				counter--;
			}
			if(achou!=-1){
				achou = 1;
				k->cliquepego = 1;
			}
		}
		if(achou!=1){
			k = k->proximo;
			achou = 0;
		}
	}

	elemento_adjacente* marcar = k->primeiroAdj;

	while(marcar!=NULL){
		marcar->adjacente->cliquepego = 1;
		marcar = marcar->proximo;
	}


	if(achou == 1){//caso encontre testa se existe um clique
		achou = 0;
		int pos = 0;
		int counteradj = 0;
		InsereVertice(k->nome,k->matricula,lret);
		adj = k->primeiroAdj;
		v1 = adj->adjacente;
		verificadj = adj;//verificador dos adjacentes
		adj = adj->proximo;
		counter = nrovertices;//contador de vertices a serem verificados
		while((verificadj!=NULL)&&((achou!=-1)&&(counter!=0))){
			while((adj!=NULL)&&((achou!=-1)&&(v1->marcado!=1))){ //verifica se a aresta (v1,v2) existe
				v2 = adj->adjacente;
				verificarcombinacao = v1->primeiroAdj; //e feita uma pesquisa na lista de adjacentes
				while((verificarcombinacao!=NULL)&&(achou!=1)){
					if(v2->matricula == verificarcombinacao->adjacente->matricula){
						achou = 1;
					}else{
						achou = -1;
					}
					verificarcombinacao = verificarcombinacao->proximo;
				}
				if(achou == -1){ /*caso nao encontre v2 na lista de adjacencia de v1 e ainda existam vertices a serem verificados v2 e marcado*/
					achou = 0;
					v2->marcado = 1;
				}
				adj = adj->proximo;
				if(achou!=-1){
					achou = 0;
				}
			}
			if(v1->marcado == 0){
				InsereVertice(v1->nome,v1->matricula,lret); /*ao encontrar pelomenos uma aresta correspondente ao clique o vertice e inserido na lista*/
			}
			if(verificadj->adjacente->marcado == 1){/*o vertice marcado é pulado para nao ser verificado*/
				verificadj = verificadj->proximo;
			}
			verificadj = verificadj->proximo;
			adj = verificadj;
			v1 = adj->adjacente;
			adj = adj->proximo;
			counter--;/*decrementa uma unidade no contador*/
		}
		if(v1->marcado==0){
			InsereVertice(v1->nome,v1->matricula,lret);	
		}
		InterligarVertices(lret);
		ApagarMarcas(grafo);
		if(achou == -1){ /*caso nao encontre o clique retorna uma lista vazia*/
			return NULL;
		}
	}
	return lret; /*caso contrario retorna a lista contendo os vertices do clique*/
}

listaVertices* getCliqueMaximo(listaVertices * grafo){
	elemento_vertice * max = grafo->primeiro;
	int maior = 0;

	while(max!=NULL){
		if(max->nroadjacentes > maior){ //procura o vertice com mais adjacentes
			maior = max->nroadjacentes; //caso encontre um numero de arestas maior que o maior definido,ele e considerado o novo maior
			elemento_adjacente* maxadj = max->primeiroAdj;
			while(maxadj!=NULL){
				if(maxadj->adjacente->nroadjacentes <= maior){
					maior = maxadj->adjacente->nroadjacentes;
				}
				maxadj = maxadj->proximo;
			}
		}
		max = max->proximo; //vai para o proximo
	}
	return getCliqueMaximal(grafo,maior); //retorna o clique Maximal desse vertice
}
