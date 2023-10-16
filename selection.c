#include <stdio.h>
#include <stdlib.h>
#define DIM_MAX 5

void scambio(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void selectionSort(int v[],int n) {
    int *k,*kmin,*j;
    for(k = v;k <v + (n-1); k++) {
        kmin = k;
    for(j = k+1; j < v+n; j++){
        if(*kmin > *j) // confronti
            kmin = j;

}
    if(kmin != k)
    scambio(k, kmin); //scambi
}   
}

int main()
{
    int vet[DIM_MAX];
    for (int *k = vet; k < vet+DIM_MAX; k++)
    {
        printf("Inserisci un valore per la cella\n");
        scanf("%d",k);
    }
    printf("Vettore disordinato: \n");
    for (int *i = vet; i < vet+DIM_MAX; i++)
    {
        printf("%d ", *i);
    }
    selectionSort(vet, DIM_MAX);
    printf(" \nVettore ordinato: \n");
    for (int *j = vet; j < vet+DIM_MAX; j++)
    {
        printf("%d ", *j);
    }
}