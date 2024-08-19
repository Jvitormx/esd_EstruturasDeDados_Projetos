#include <stdlib.h>
#include <stdio.h>

void preencheVetor(int v[], int n);
void ordenaVetor(int v[], int n);
void exibeVetor(int v[], int n);

int main(void)
{

    int x = 5;
    int vet1[] = {4, 7, 8, 3, 2, 5};
    int *vet2;
    int qt2 = 7;

    vet2 = (int *)malloc(sizeof(int) * qt2);
    // preencheVetor(vet1,3);
    preencheVetor(vet2, qt2);
    ordenaVetor(vet2, qt2);
    exibeVetor(vet2, qt2);
    free(vet2);

    return 0;
}

void exibeVetor(int v[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
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

void preencheVetor(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        v[i] = rand() % 100;
    }
}