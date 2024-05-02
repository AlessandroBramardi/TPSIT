#include <stdio.h>
#include <stdlib.h>


typedef struct Nodo {
    int dato;
    struct Nodo* prossimo;
} Nodo;

typedef struct Coda {
    Nodo* inizio;
    Nodo* fine;
} Coda;


typedef struct Pila {
    Nodo* cima;
} Pila;


void inizializzaCoda(Coda* coda) {
    coda->inizio = NULL;
    coda->fine = NULL;
}

void inizializzaPila(Pila* pila) {
    pila->cima = NULL;
}


void inserisciCoda(Coda* coda, int dato) {
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuovoNodo->dato = dato;
    nuovoNodo->prossimo = NULL;

    if (coda->fine == NULL) {
        coda->inizio = nuovoNodo;
        coda->fine = nuovoNodo;
    } else {
        coda->fine->prossimo = nuovoNodo;
        coda->fine = nuovoNodo;
    }
}


int estraiCoda(Coda* coda) {
    if (coda->inizio == NULL) {
        printf("La coda è vuota.\n");
        return -1;  
    }

    Nodo* nodoEstratto = coda->inizio;
    int datoEstratto = nodoEstratto->dato;

    coda->inizio = nodoEstratto->prossimo;

    if (coda->inizio == NULL) {
        coda->fine = NULL;
    }

    free(nodoEstratto);
    return datoEstratto;
}

void inserisciPila(Pila* pila, int dato) {
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuovoNodo->dato = dato;
    nuovoNodo->prossimo = pila->cima;
    pila->cima = nuovoNodo;
}


int estraiPila(Pila* pila) {
    if (pila->cima == NULL) {
        printf("La pila è vuota.\n");
        return -1;  
    }

    Nodo* nodoEstratto = pila->cima;
    int datoEstratto = nodoEstratto->dato;

    pila->cima = nodoEstratto->prossimo;

    free(nodoEstratto);
    return datoEstratto;
}

int equalsCoda(Coda* coda1, Coda* coda2) {
    Nodo* nodo1 = coda1->inizio;
    Nodo* nodo2 = coda2->inizio;

    while (nodo1 != NULL && nodo2 != NULL) {
        if (nodo1->dato != nodo2->dato) {
            return 0;  
        }
        nodo1 = nodo1->prossimo;
        nodo2 = nodo2->prossimo;
    }

    return (nodo1 == NULL && nodo2 == NULL);  // Le code sono uguali se entrambe sono NULL alla fine
}

int main() {
    Coda coda1, coda2;
    Pila pila;

    inizializzaCoda(&coda1);
    inizializzaCoda(&coda2);
    inizializzaPila(&pila);

    // Esempio di utilizzo
    inserisciCoda(&coda1, 1);
    inserisciCoda(&coda1, 2);
    inserisciCoda(&coda1, 3);

    inserisciPila(&pila, 3);
    inserisciPila(&pila, 2);
    inserisciPila(&pila, 1);

    printf("Coda 1: %d\n", estraiCoda(&coda1));
    printf("Pila: %d\n", estraiPila(&pila));
    printf("Coda 1: %d\n", estraiCoda(&coda1));

    inserisciCoda(&coda2, 1);
    inserisciCoda(&coda2, 2);
    inserisciCoda(&coda2, 3);

    // Confronto tra code
    if (equalsCoda(&coda1, &coda2)) {
        printf("Le code sono uguali.\n");
    } else {
        printf("Le code non sono uguali.\n");
    }

    return 0;
}
