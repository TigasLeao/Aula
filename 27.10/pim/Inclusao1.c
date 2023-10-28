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

  arquivo = fopen("dados.bin","ab");
  if(arquivo == NULL)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }

  printf("Digite o ID.....: ");
  scanf("%d", &registro.id);
  fflush(stdin);
  printf("Digite o nome...: ");
  fgets(registro.nome,sizeof(registro.nome),stdin);
  fflush(stdin);
  printf("Digite o salario: ");
  scanf("%f", &registro.salario);

  fwrite(&registro, sizeof(Registro), 1, arquivo);

  fclose(arquivo);

  printf("Registro incluido com sucesso.");

  return 0;
}
