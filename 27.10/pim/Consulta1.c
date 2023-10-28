#include "stdio.h"
#include "stdlib.h"

typedef struct
{
  int id;
  char nome[30];
  float salario;
}Registro;

int main()
{
  FILE *arquivo;
  Registro registro;
  int id_busca,encontrou=0;

  arquivo = fopen("dados.bin","rb");
  if(arquivo == NULL)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }

  printf("Digite o ID para pesquisa: ");
  scanf("%d", &id_busca);

  while(fread(&registro, sizeof(Registro),1,arquivo))
  {
    if(registro.id == id_busca)
    {
      encontrou = 1;
      printf("Registro encontrado:\n");
      printf("ID.....: %d\n",registro.id);
      printf("Nome...: %s",registro.nome);
      printf("Salario: %.2f",registro.salario);
    }
  }

  fclose(arquivo);

  if(encontrou == 0)
  {
    printf("Nao ha registro com o valor pesquisado.");
  }

  return 0;
}
