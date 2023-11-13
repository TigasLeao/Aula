#include "stdio.h"
#include "stdlib.h"

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

typedef struct
{
    int id;
    char tema[50], obra_1[255], obra_2[255], obra_3[255], descricao_1[255], descricao_2[255], descricao_3[255];
} Registro;

// Declaração da função
void apresentarObra(Registro registro, int escolha);

int main()
{
    FILE *arquivo;
    Registro registro;
    int id_busca, encontrou = 0, escolha, escolha2;

    arquivo = fopen("dadosobras.bin", "rb");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    printf("Digite o ID para pesquisa: ");
    scanf("%d", &id_busca);

    while (fread(&registro, sizeof(Registro), 1, arquivo))
    {
        if (registro.id == id_busca)
        {
            encontrou = 1;

            // Loop para permitir que o usuário veja várias obras
            do
            {
                // Limpar a tela antes de apresentar o menu
                system(CLEAR);

                printf("*********\n");
                printf("Voce esta vendo o tema %s \n", &registro.tema);
                printf("Qual obra voce gostaria de ver? (Digite o numero escolhido):\n");
                printf("*********\n\n");
                printf("1. Quando ocorreu. \n\n");
                printf("2. Quanto tempo durou. \n\n");
                printf("3. O que tinha la.\n\n");
                printf("Digite o numero da obra: ");
                scanf("%d", &escolha);

                apresentarObra(registro, escolha);

                // Pergunta se o usuário gostaria de ver outra obra
                printf("\nVoce gostaria de ver mais uma obra? Digite 1 para SIM ou 2 para NAO: ");
                scanf("%d", &escolha2);

            } while (escolha2 == 1);

            printf("Tchau");
        }
    }

    fclose(arquivo);

    if (encontrou == 0)
    {
        printf("Nao ha registro com o valor pesquisado.");
    }

    return 0;
}

// Implementação da função
void apresentarObra(Registro registro, int escolha)
{
    // Implemente a lógica da função aqui
    switch (escolha)
    {
    case 1:
        printf("\nObra 1: %s", registro.obra_1);
        printf("\n%s", registro.descricao_1);
        break;

    case 2:
        printf("\nObra 2: %s", registro.obra_2);
        printf("\n%s", registro.descricao_2);
        break;

    case 3:
        printf("\nObra 3: %s", registro.obra_3);
        printf("\n%s", registro.descricao_3);
        break;

    default:
        printf("\nEscolha invalida.");
        break;
    }
}
