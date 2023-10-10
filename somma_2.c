#include <stdio.h>
#include <stdlib.h>
#define DIM 10


int sommaVet(int vet[]){
    int s=0;
    for(int *k=vet;k<vet+DIM;k++){
        s=s+*k;
    }
    return s;
}

int main(){
    int vet[DIM];
    for(int *k=vet;k<vet+DIM;k++){
        printf("Inserire un numero intero: \n");
        scanf("%d",k);
    }
    int somma=sommaVet(vet);
    printf("Somma: %d",somma);

    return 0;
}