#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

typedef struct
{
  int id;
  char nome[30];
  float salario;
}Registro;

int main()
{
  FILE *arquivo, *novoArquivo;
  Registro registro;
  int id_busca,encontrou=0;
  int op;
  int exclui=0;

  arquivo = fopen("dados.bin","rb");
  if(arquivo == NULL)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }

  novoArquivo = fopen("temp.bin", "wb");
  if (novoArquivo == NULL)
  {
    perror("Erro ao criar o novo arquivo");
    exit(1);
  }
  printf("Digite o ID do registro para exclusao: ");
  scanf("%d", &id_busca);

  while(fread(&registro, sizeof(Registro),1,arquivo))
  {
    if(registro.id == id_busca)
    {
      encontrou = 1;
      printf("Registro encontrado:\n");
      printf("ID.....: %d\n",registro.id);
      printf("Nome...: %s",registro.nome);
      printf("Salario: %.2f\n\n",registro.salario);
    }
  }

  if(encontrou==1)
  {
    fseek(arquivo, 0, SEEK_SET); //posiciona no início do arquivo.
    printf("Deseja realmente excluir este registro?(1-Sim | 2-Nao): ");
    scanf("%d", &op);
    if(op==1)
    {
      // Ler os registros do arquivo original e gravar no novo arquivo, exceto o registro a ser excluído
      while (fread(&registro, sizeof(Registro), 1, arquivo))
      {
        printf("%d %d\n",registro.id,id_busca);getch();
        if (registro.id != id_busca)
        {
          exclui = 1;
          fwrite(&registro, sizeof(Registro), 1, novoArquivo);
        }
      }
    }
  }

  fclose(arquivo);
  fclose(novoArquivo);

  if(encontrou == 0)
  {
    printf("Nao ha registro com o valor pesquisado.");
  }
  if(exclui==1)
  {
    remove("dados.bin");
    if (rename("temp.bin", "dados.bin") != 0)
    {
      perror("Erro ao renomear o arquivo");
      exit(1);
    }
    printf("Registro excluido com sucesso!\n");
    remove("temp.bin");
  }


  return 0;
}
