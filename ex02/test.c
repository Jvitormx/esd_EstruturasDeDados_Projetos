#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct pessoa
{
    int idade;
    char *nome;
};

typedef struct pessoa TPessoa;
typedef struct pessoa *PTPessoa;

PTPessoa pessoax1(char **lista);

int main(void)
{
    int i;
    TPessoa *pessoas;
    char *lista[] = {"Pedro", "Manuel", "Carlos"};
    pessoas = pessoax1(lista);

    for (i = 0; i < 3; i++)
    {
        printf("pessoa %d: %d - %s\n", i + 1, pessoas[i].idade, pessoas[i].nome);
    }
}

PTPessoa pessoax1(char **lista)
{
    PTPessoa pessoas;
    pessoas = (PTPessoa)malloc(sizeof(TPessoa) * 3);

    int i, j, rand_num;
    for (i = 0; i < 3; i++)
    {
        rand_num = rand() % 3;
        pessoas[i].idade = i + 1;
        for (j = 0; j < 3; j++)
        {
            pessoas[i].nome = (char *)malloc(sizeof(strlen(lista[rand_num]) + 1));
            strcpy(pessoas[i].nome, lista[rand_num]);
        }
    }

    return pessoas;
}