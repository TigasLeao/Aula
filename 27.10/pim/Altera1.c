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

  arquivo = fopen("dados.bin","rb+");
  if(arquivo == NULL)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }

  printf("Digite o ID para pesquisa: ");
  scanf("%d", &id_busca);
  fflush(stdin);
  while(fread(&registro, sizeof(Registro),1,arquivo))
  {
    if(registro.id == id_busca)
    {
      encontrou = 1;
      // Faça as alterações desejadas nos dados do registro
      printf("Digite o novo nome...: ");
      fgets(registro.nome,sizeof(registro.nome),stdin);
      fflush(stdin);
      printf("Digite o novo salario: ");
      scanf("%f", &registro.salario);
      // Volta para a posição do arquivo para escrever as alterações
      fseek(arquivo, -(long)sizeof(Registro), SEEK_CUR);
      fwrite(&registro, sizeof(Registro), 1, arquivo);
      printf("Registro alterado com sucesso!\n");
      break; //Finaliza o loop
    }
  }

  fclose(arquivo);

  if(encontrou == 0)
  {
    printf("Nao ha registro com o valor pesquisado.");
  }

  return 0;
}
