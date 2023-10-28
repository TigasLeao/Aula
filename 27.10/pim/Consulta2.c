#include "stdio.h"
#include "stdlib.h"

#define YELLOW "\x1B[33m"
#define CYAN "\x1B[36m"
#define BLUE_BG "\x1B[44m"
#define RESET "\x1B[0m"


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
  int r=1;

  arquivo = fopen("dados.bin","rb");
  if(arquivo == NULL)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }

  while(fread(&registro, sizeof(Registro),1,arquivo))
  {
      printf(CYAN "Registro #%d\n",r);
      printf(RESET);
      printf("ID.....: %d\n",registro.id);
      printf("Nome...: %s",registro.nome);
      printf("Salario: %.2f\n",registro.salario);
      printf("-------------------------------\n");
      r++;
  }

  fclose(arquivo);

  return 0;
}
