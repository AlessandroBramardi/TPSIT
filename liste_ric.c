#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dato;
    struct Nodo*next;
}Nodo;

Nodo* aggiungi(Nodo* fine, int x){
    Nodo* newNodo = (Nodo*)malloc(sizeof(Nodo));
    newNodo->dato = x;
    newNodo->next = fine;
    return newNodo;
}

int lunghezza(Nodo* fine) {
    if(fine->next != NULL){
        return 1+ lunghezza(fine->next);
    }
}

void stampa(Nodo* fine) {
    if (fine != NULL) {
        printf("%d ", fine->dato);
        stampa(fine->next);
    } else {
        printf("\n");
    }
}

int main(){
    Nodo* lista= NULL;
    lista=aggiungi(lista,6);
    lista=aggiungi(lista,10);
    lista=aggiungi(lista,2);
    lista=aggiungiFondo(lista,5);
    printf("Lunghezza della lista: %d",lunghezza(lista));
    printf("\n");
    printf("Valori della lista: \n");
    stampa(lista);
    return 0;
}