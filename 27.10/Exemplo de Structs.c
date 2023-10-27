#include "stdio.h"

typedef struct
{
    char nome[20];
    int codigo;
    float salario;
}Pessoa;


Pessoa pessoa;
//Pessoa é um tipo de dado composto ; pessoa é variável

int main()
{
    printf("Digite seu nome...: ");
    fgets(pessoa.nome,sizeof(pessoa.nome),stdin);
    printf("Digite seu codigo.: ");
    scanf("%d", &pessoa.codigo);
    printf("Digite seu salario: ");
    scanf("%f", &pessoa.salario);

    printf("\nNome...: %s", pessoa.nome);
    printf("Codigo.: %d\n", pessoa.codigo);
    printf("Salario: %2.f\n", pessoa.salario);

    return 0;
    
    //quando sai do numérico para caractere, é necessário usar o fflush para limpar a variável;
    //Exemplo: o campo "código" desse exercício vir antes do campo "nome". Sem o fflush, o programa pula o nome.
    //printf("Digite seu codigo.: ");
    //scanf("%d", &pessoa.codigo);
    //fflush(stdin);
    //printf("Digite seu nome...: ");
    //fgets(pessoa.nome,sizeof(pessoa.nome),stdin);
}

