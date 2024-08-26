#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N_RESPOSTAS 2

typedef int respQuestionario;

struct pessoa
{
    char *nome;
    respQuestionario respostas[N_RESPOSTAS];
};

typedef struct pessoa TPessoa;
typedef struct pessoa *PTPessoa;

float calcularDistancia(respQuestionario respostasP1[], respQuestionario respostasP2[]);

void encontrarCompatibilidade(char *nome, TPessoa pessoas[], int lim_distancia, int n_pessoas);

PTPessoa inicializarPessoas(char **vNomAux, int n_pessoas);

void desalocarNomes(PTPessoa pessoas, int n_pessoas);

int main(void)
{
    char *vNomAux[] = {"Jose", "Joao", "Maria", "Ana", "Francisca", "Antonio", "Pedro", "Juliana", "Luíz", "Sara",
                       "Gabriel", "Camila", "Sandra", "Rafael", "Bruno", "Mariana",
                       "Leonardo", "Mateus", "Vitor", "Davi"};

    PTPessoa pessoas;

    char nome_pessoa[100];
    int i, n_pessoas;
    float limiar;

    printf("Quantidade de pessoas [MAX 20]: ");
    scanf("%d", &n_pessoas);

    // inicializa pessoas com nomes e respostas
    pessoas = inicializarPessoas(vNomAux, n_pessoas);

    for (i = 0; i < n_pessoas; i++)
    {
        printf("pessoa %d: %s - resp1: %d | resp2: %d\n", i + 1, pessoas[i].nome, pessoas[i].respostas[0], pessoas[i].respostas[1]);
    }

    printf("Nome de pessoa para comparacao: ");
    scanf(" %s", nome_pessoa);

    printf("Limiar de compatibilidade: ");
    scanf("%f", &limiar);

    // mostra pessoas compativeis com pessoa escolhida
    encontrarCompatibilidade(nome_pessoa, pessoas, limiar, n_pessoas);

    desalocarNomes(pessoas, n_pessoas);

    free(pessoas);
}

void desalocarNomes(PTPessoa pessoas, int n_pessoas)
{
    int i;
    for (i = 0; i < n_pessoas; i++)
    {
        free(pessoas[i].nome);
    }
}

float calcularDistancia(respQuestionario respostasP1[], respQuestionario respostasP2[])
{
    float d = sqrt((pow(respostasP2[0] - respostasP1[0], 2.0)) + (pow(respostasP2[1] - respostasP1[1], 2.0)));
    return d;
}

void encontrarCompatibilidade(char *nome, TPessoa pessoas[], int lim_distancia, int n_pessoas)
{
    int i, j;
    float distancia;

    PTPessoa pessoa_escolhida;
    pessoa_escolhida = (PTPessoa)malloc(sizeof(TPessoa));

    // pegando valores da pessoa escolhida
    for (i = 0; i < n_pessoas; i++)
    {
        if (strcmp(nome, pessoas[i].nome) == 0)
        {
            for (j = 0; j < N_RESPOSTAS; j++)
            {
                pessoa_escolhida->respostas[j] = pessoas[i].respostas[j];
            }
        }
    }

    for (i = 0; i < n_pessoas; i++)
    {
        if (strcmp(nome, pessoas[i].nome) != 0)
        {
            // calculando distancia entre as respostas da pessoa escolhida e as demais respostas
            distancia = calcularDistancia(pessoa_escolhida->respostas, pessoas[i].respostas);
            if (distancia < lim_distancia)
            {
                printf("nome: %s\n", pessoas[i].nome);
            }
        }
    }

    free(pessoa_escolhida);
}

PTPessoa inicializarPessoas(char **vNomAux, int n_pessoas)
{
    int i, j, n_rand;
    PTPessoa pessoas;

    pessoas = (PTPessoa)malloc(sizeof(TPessoa) * n_pessoas);

    for (i = 0; i < n_pessoas; i++)
    {
        n_rand = rand() % (n_pessoas);
        pessoas[i].nome = (char *)malloc(sizeof(strlen(vNomAux[n_rand]) + 1) * sizeof(char));
        strcpy(pessoas[i].nome, vNomAux[n_rand]);

        for (j = 0; j < N_RESPOSTAS; j++)
        {
            pessoas[i].respostas[j] = rand() % 10;
        }
    }

    return pessoas;
}