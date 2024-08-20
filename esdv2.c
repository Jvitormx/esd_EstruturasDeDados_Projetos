#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void preencheVetor(char nome[], char *vNomes[], int n);
void ordenaVetor(int v[], int n);
void exibeVetor(char nome[], char *vNomes[], int n);
void desalocarVetor(char *vNomes[], int n);

int main(void)
{
    char nome[100];
    char *vNomes[6];
    int n = 6;

    preencheVetor(nome, vNomes, n);
    printf("|||||||||||||||||||||||||||\n\n");
    exibeVetor(nome, vNomes, n);
    desalocarVetor(vNomes, n);

    return 0;
}

void exibeVetor(char nome[], char *vNomes[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("vNomes[%d] %s\n", i, vNomes[i]);
    }
    printf("\n");
}

void ordenaVetor(int v[], int n)
{
    int i, j, aux;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < (n - 1); j++)
        {
            if (v[j] > v[j + 1])
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

void desalocarVetor(char *vNomes[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        free(vNomes[i]);
    }
}

void preencheVetor(char nome[], char *vNomes[], int n)
{
    int i, tam;
    for (i = 0; i < n; i++)
    {
        printf("nome: ");
        scanf(" %s", nome);
        tam = strlen(nome) + 1;
        vNomes[i] = (char *)malloc(tam);
        strcpy(vNomes[i], nome);
    }
}