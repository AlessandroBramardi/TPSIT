#include <stdio.h>
#include <stdlib.h>
#define DIM 10


int sommaVet(int vet[]){
    int s=0;
    for(int k=0;k<DIM;k++){
        s=s+*(vet+k);
    }
    return s;
}

int main(){
    int vet[DIM];
    for(int k=0;k<DIM;k++){
        printf("Inserire un numero intero: \n");
        scanf("%d",(vet+k));
    }
    int somma=sommaVet(vet);
    printf("Somma: %d",somma);

    return 0;
}