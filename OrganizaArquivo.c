#include "OrganizaArquivo.h"

Aluno* LerRegistros(Aluno* aluno){

  char arq[30] = "amigos_tag20172.txt";
  FILE *fp;
  fp = fopen(arq, "r+");

  if(fp == NULL){
      printf("O arquivo nao existe!!! \n");
  } else {
  
    char str_arestas[30]; /*string com as arestas adjacentes.*/
    char str_lida[300]; /*string que vai armazenar a cada loop.*/
    char *data;
    int offset; /*nros. de bytes consumido pelo sscanf. Utilizado para criar um array de int a partir de uma string com as arestas*/
    int n=0; /*valor da aresta*/
    int j=0; /*controla o loop para o vetor de arestas do aluno*/
    int k=0; /*controla o aluno correspondete*/
    /* @@@@Aluno aluno[49]; @@@@*/
    /*para cada loop, ele le uma linha inteira correspondete a 1 aluno.*/
    while (fscanf(fp, "%[^\n]s", str_lida)!=EOF){
      /*o sscanf serve para quebrar uma string inteira em diferente variaveis.
        Nesse caso ele quebra a str_lida em 3 variaveis int str str.*/
      sscanf(str_lida, "%d %*s %[^|]| %[^\n]", &aluno[k].vert, str_arestas, aluno[k].nome);

      data = str_arestas;/*utilizada pois nao eh possivel incrementar 'o nome' de um array*/

      j=0; /*zera contagem das arestas para o loop do prox aluno*/
      n=0; /*zera valor da aresta para o loop do prox aluno*/

      /*loop para converter um string em array de int que contem as arestas dos vertices*/
      while (sscanf(data, "%d%n",&n, &offset) == 1){
        aluno[k].arestas[j] = n;
        j++;
        n++;
        data += offset; /*adicionando o numero de bytes que o sscanf ja consomiu para nao ler do comeco novamente*/
      }

      /* if utilizado para atribuir a quantidade correta(n considera 0 vertices como sendo 1) de arestas total do vertice*/
      if(j==1 && aluno[k].arestas[0] < 1){
        aluno[k].qtd_arestas = j-1; /*atribuicao para o total de arestas que o aluno vai ter*/
      } else {
        aluno[k].qtd_arestas = j;
      }

      fscanf(fp, "\n%[^\n]s\n", str_lida);/*pulando para a prox linha*/
      k++; /* incrementacao para salvar os proximos valores do prox. loop em um novo aluno*/
    }
  }
  fclose(fp);

  return aluno;
}


Aluno* GrafoGrauDecrescente(Aluno* aluno){
  int i, fez_troca;
  Aluno aux;
  LerRegistros(aluno);

  /*loop com ubble sort para ordenar de forma decrescente os aluno pelo grau dos vertices*/
  fez_troca=1;
  while(fez_troca){
    fez_troca=0;
    for(i=0;i<50;i++){
      if(aluno[i].qtd_arestas < aluno[i+1].qtd_arestas){
        aux = aluno[i];
        aluno[i] = aluno[i+1];
        aluno[i+1] = aux;
        fez_troca = 1;
      }
    }
  }
  return aluno;
}

listaVertices* InsereRegistrosLido(listaVertices* grafo){

  Aluno* aluno = malloc(sizeof(Aluno)*50);  /* quantidade de aluno total. */
  int i, j;
  
  LerRegistros(aluno);
  GrafoGrauDecrescente(aluno);

  /* loop para adicionar todos os vertices */
  for(i=0;i<49;i++){
       InsereVertice(aluno[i].nome, aluno[i].vert, grafo);
  }

  /* loop para adicionar todas as arestas*/
  for(i=0;i<50;i++){
    for(j=0;j < (aluno[i].qtd_arestas) && (aluno[i].arestas[j] != 0);j++){
      InsereAresta(aluno[i].vert, aluno[i].arestas[j], grafo);
    }
  }

  return grafo;
}
