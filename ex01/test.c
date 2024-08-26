#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char nome[100];
    char *vNomes[2];
    char *aux;

    int i, tam, n = 2, j, k;
    for (i = 0; i < n; i++)
    {
        printf("nome: ");
        scanf(" %s", nome);
        tam = strlen(nome) + 1;
        vNomes[i] = (char *)malloc(tam);
        strcpy(vNomes[i], nome);
    }

    printf("%c %c\n", vNomes[0][0], vNomes[0][1]);
    printf("%c %c\n", vNomes[1][0], vNomes[1][1]);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < (n - 1); j++)
        {
            k = 0;
            while (vNomes[j][k] != '\0')
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

    for (i = 0; i < n; i++)
    {
        printf("vNomes[%d] %s\n", i, vNomes[i]);
    }
    printf("\n");
}