#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Inserisci la dimensione dell'array: ");
    scanf("%d", &n);
    int *vet_int = (int*) malloc(n*sizeof(int));
    for(int *k=vet_int; k<vet_int+n; k++){
        printf("Inserisci un elemento: \n");
        scanf("%d", k);
    }
    printf("Vettore: \n");
    for(int *k=vet_int; k<vet_int+n; k++){
        printf("%d ", *k);
    }
    free(vet_int); //come faccio a sapere se ho effettivamente liberato la memoria?
    return 0;
}