#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void preencheVetor(char nome[], char *vNomes[], int n);
void ordenaVetor(char *vNomes[], int n);
void exibeVetor(char *vNomes[], int n);
void desalocarVetor(char *vNomes[], int n);

int main(void)
{
    char nome[100];
    char *vNomes_est[4];
    char **vNomes_din;
    char opcao;
    int n_est = 4, n_din, validar = 0;

    while (validar == 0)
    {
        printf("vNomes estática [a] | vNomes dinâmica [b] | sair[c]: ");
        scanf("%c", &opcao);

        switch (opcao)
        {
        case 'a':

            // vNomes estática

            preencheVetor(nome, vNomes_est, n_est);
            ordenaVetor(vNomes_est, n_est);
            printf("\n|||||||||||||||||||||||||||\n\n");
            exibeVetor(vNomes_est, n_est);
            desalocarVetor(vNomes_est, n_est);
            break;

        case 'b':

            // vNomes dinâmica

            printf("Quantidade de nomes a serem armazenados: ");
            scanf("%d", &n_din);

            //*vNomes_din = (char *)malloc(sizeof(char *) * n_din);

            preencheVetor(nome, vNomes_din, n_din);
            printf("\n|||||||||||||||||||||||||||\n\n");
            exibeVetor(vNomes_din, n_din);
            // desalocarVetor(vNomes_din, n_din);
            free(vNomes_din);
            break;

        case 'c':

            // sair
            validar = 1;
            break;
        }
    }

    return 0;
}

void exibeVetor(char *vNomes[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("vNomes[%d] %s\n", i, vNomes[i]);
    }
    printf("\n");
}

void ordenaVetor(char *vNomes[], int n)
{
    int i, j, k, tam;
    char *aux;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < (n - 1); j++)
        {
            k = 0;
            while (*vNomes[k] != '\0')
            {
                if (vNomes[j][k] > vNomes[j + 1][k])
                {
                    tam = strlen(vNomes[j]) + 1;
                    aux = (char *)malloc(tam);
                    // aux = v[j];
                    strcpy(aux, vNomes[j]);
                    // v[j] = v[j + 1];
                    free(vNomes[j]);
                    tam = strlen(vNomes[j + 1]) + 1;
                    vNomes[j] = (char *)malloc(tam);
                    strcpy(vNomes[j], vNomes[j + 1]);
                    // v[j + 1] = aux;
                    free(vNomes[j + 1]);
                    tam = strlen(aux) + 1;
                    strcpy(vNomes[j + 1], aux);
                    break;
                }
                k++;
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