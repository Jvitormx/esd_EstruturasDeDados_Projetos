#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Definindo quantidade de perguntas ao questionario | plano 2D
#define N_RESPOSTAS 2

typedef int respQuestionario;

struct pessoa
{
    char *nome;
    respQuestionario respostas[N_RESPOSTAS];
};

// definindo tipo pessoa e ponteiro para tipo pessoa
typedef struct pessoa TPessoa;
typedef TPessoa *PTPessoa;

PTPessoa inicializarPessoas(char **vNomAux, int n_pessoas);

float calcularDistancia(respQuestionario respostasP1[], respQuestionario respostasP2[]);

void encontrarCompatibilidade(char *nome, TPessoa pessoas[], int lim_distancia, int n_pessoas);

void desalocarNomes(PTPessoa pessoas, int n_pessoas);

int main(void)
{
    char *vNomAux[] = {"Jose", "Joao", "Maria", "Ana", "Francisca", "Antonio", "Pedro", "Juliana", "Luíz", "Sara",
                       "Gabriel", "Camila", "Sandra", "Rafael", "Bruno", "Mariana",
                       "Leonardo", "Mateus", "Vitor", "Davi"};

    // criando ponteiro para struct pessoas
    PTPessoa pessoas;

    char nome_pessoa[100];
    int i, n_pessoas;
    float limiar;

    printf("Quantidade de pessoas [MAX 20]: ");
    scanf("%d", &n_pessoas);

    if (n_pessoas > 20)
    {
        return 1;
    }

    // atribuindo ao ponteiro criado o endereco que aponta para as structs pessoas inicializadas com nomes e respostas
    pessoas = inicializarPessoas(vNomAux, n_pessoas);

    // exibindo pessoas e suas respostas
    for (i = 0; i < n_pessoas; i++)
    {
        printf("pessoa %d: %s - resp1: %d | resp2: %d\n", i + 1, pessoas[i].nome, pessoas[i].respostas[0], pessoas[i].respostas[1]);
    }

    printf("Nome de pessoa para comparacao: ");
    scanf(" %s", nome_pessoa);

    printf("Limiar de compatibilidade: ");
    scanf("%f", &limiar);

    // exibindo pessoas compativeis com pessoa escolhida
    encontrarCompatibilidade(nome_pessoa, pessoas, limiar, n_pessoas);

    // desalocando memoria atribuida para cada nome alocado nas structs pessoas
    desalocarNomes(pessoas, n_pessoas);

    // desalocando memoria atribuida para as structs pessoas
    free(pessoas);

    return 0;
}

PTPessoa inicializarPessoas(char **vNomAux, int n_pessoas)
{
    int i, j, n_rand;

    // criando ponteiro para struct pessoas
    PTPessoa pessoas;

    // alocando memória para o ponteiro com base no numero determinado de pessoas
    pessoas = (PTPessoa)malloc(sizeof(TPessoa) * n_pessoas);

    for (i = 0; i < n_pessoas; i++)
    {
        // determinando valor aleatorio com base no numero determinado de pessoas
        n_rand = rand() % (n_pessoas);

        // alocando memoria para nome no struct pessoa com base no nome aleatorio do vetor de nomes
        pessoas[i].nome = (char *)malloc(sizeof(strlen(vNomAux[n_rand]) + 1) * sizeof(char));

        // atribuindo nome do vetor de nomes a struct pessoa
        strcpy(pessoas[i].nome, vNomAux[n_rand]);

        // Atribuindo identificador para diferenciar nomes
        pessoas[i].nome[strlen(pessoas[i].nome)] = (rand() % 10) + '0';

        // atribuindo respostas aleatorias para struct pessoa
        for (j = 0; j < N_RESPOSTAS; j++)
        {
            pessoas[i].respostas[j] = rand() % 10;
        }
    }

    // retornando ponteiro pessoas
    return pessoas;
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

    // criando ponteiro para struct da pessoa escolhida
    PTPessoa pessoa_escolhida;

    // alocando memoria para pessoa escolhida
    pessoa_escolhida = (PTPessoa)malloc(sizeof(TPessoa));

    // atribuindo valores das respostas da pessoa escolhida que esta no vetor de pessoas a struct pessoa criada para a pessoa escolhida
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

    // calculando distancia entre as respostas da pessoa escolhida e as demais respostas do vetor pessoas
    for (i = 0; i < n_pessoas; i++)
    {
        if (strcmp(nome, pessoas[i].nome) != 0)
        {
            distancia = calcularDistancia(pessoa_escolhida->respostas, pessoas[i].respostas);

            // verificando se distancia de determinada pessoa em relacao a pessoa escolhida se enquadra no limiar determinado
            if (distancia < lim_distancia)
            {
                // exibindo nome e respostas de cada pessoa que se encaixa no limiar determinado
                printf("nome: %s - resp1: %d | resp2: %d\n", pessoas[i].nome, pessoas[i].respostas[0], pessoas[i].respostas[1]);
            }
        }
    }

    // desalocando memoria da struct pessoa da pessoa escolhida
    free(pessoa_escolhida);
}

void desalocarNomes(PTPessoa pessoas, int n_pessoas)
{
    int i;
    for (i = 0; i < n_pessoas; i++)
    {
        free(pessoas[i].nome);
    }
}