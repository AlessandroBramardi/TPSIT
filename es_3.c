#include <stdio.h>
#include <stdlib.h>
#define DIM_MAX 3

void scambio(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void bubbleSort3(int vett[], int n)
{
    int k, sup, sca;
    sup = n - 1;
    while (sup > 0)
    {
        sca = 0;
        for (k = 0; k < sup; k++)
        {
            if (*(vett + k) > *(vett + k + 1))
            {
                scambio((vett + k), (vett + k + 1));
                sca = k;
            }
        }
        sup = sca;
    }
}

int main()
{
    int vet[DIM_MAX];
    for (int k = 0; k < DIM_MAX; k++)
    {
        printf("Inserisci un valore per la cella [%d]: ", k);
        scanf("%d", (vet + k));
    }
    printf("Vettore disordinato: \n");
    for (int i = 0; i < DIM_MAX; i++)
    {
        printf("%d ", *(vet + i));
    }
    bubbleSort3(vet, DIM_MAX);
    printf(" \nVettore ordinato: \n");
    for (int j = 0; j < DIM_MAX; j++)
    {
        printf("%d ", *(vet + j));
    }
}