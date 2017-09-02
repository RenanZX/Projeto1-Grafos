#include "OrganizaArquivo.h"


void LerRegistros(){
  char arq[30] = "amigos_tag20172.txt";
  FILE *fp;
  fp = fopen(arq, "r+");

  if(fp == NULL){
      printf("O arquivo nao existe!!! \n");
  } else {
  
    int vert;
    char arestas[30];
    char nome[60];
    char str_lida[300];

    /*para cada loop, ele le uma linha inteira correspondete a 1 aluno.*/
    while (fscanf(fp, "%[^\n]s", str_lida)!=EOF){
      /*o sscanf serve para quebrar uma string inteira em diferente variaveis.
        Nesse caso ele quebra a str_lida em 3 variaveis int str str.*/
      sscanf(str_lida, "%d %*s %[^|]| %[^\n]", &vert, arestas, nome);
      printf("\nVertice = %d\n", vert);
      printf("Arestas = %s\n", arestas);
      printf("Nome = %s\n", nome);

      fscanf(fp, "\n%[^\n]s\n", str_lida);
    }
  }
  fclose(fp);
}
