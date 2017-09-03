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

      aluno[k].qtd_arestas = j; /*atribuicao para o total de arestas que o aluno vai ter*/

      fscanf(fp, "\n%[^\n]s\n", str_lida);/*pulando para a prox linha*/
      k++; /* incrementacao para salvar os proximos valores do prox. loop em um novo aluno*/
    }
  }
  fclose(fp);

  return aluno;
}


listaVertices* InsereVerticesLidos(listaVertices* grafo){

  Aluno* aluno = malloc(sizeof(Aluno)*50);  /* quantidade de aluno total. */
  LerRegistros(aluno);

  int i=0;
  Vertice aux[50];
  for(i=0;i<49;i++){
    strcpy(aux[i].nome,aluno[i].nome);
    aux[i].matricula = aluno[i].vert;
    InsereVertice(&aux[i],grafo);
  }

  int j,k[50], m;
  Vertice aux2[50];

  for(i=0;i<50;i++){
    for(j=0; j < (aluno[i].qtd_arestas) && (aluno[i].arestas[j] != 0) ; j++){
      /*printf("Aluno %s | Valor de j = %d | Repete = %d\n", aluno[i].nome, j, aluno[i].qtd_arestas);*/
      
      m = aluno[i].arestas[j];
      /*printf("nome %s | Valor da aresta: %d\n", aluno[m-1].nome, aluno[i].arestas[j]);*/

      strcpy(aux2[i].nome,aluno[m-1].nome);
      aux2[i].matricula = aluno[i].arestas[j];
      InsereAresta(&aux[i], &aux2[i], grafo);
    }
  }

  printf("nome %s \n", aluno[4].nome);  
 

  return grafo;
}
