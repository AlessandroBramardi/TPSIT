#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define LIM_MIN 1
#define LIM_MAX 10


typedef struct coda{
    int arrivo;
    int valore;
    struct coda* next;   
}Coda;

typedef struct pila{
    int arrivo;
    int valore;
    struct pila* next;
}Pila;

bool is_empty_coda(Coda* head){
    return head == NULL;
}

void enqueue(Coda** head, Coda** tail, Coda* elem){
    if(is_empty_coda(*head)){
        *head = elem;
    }
    else{
        (*tail)->next = elem;
    }
    *tail = elem;
    elem->next = NULL;
}

Coda* dequeue(Coda** head, Coda** tail){
    Coda* ret = *head;
    if(is_empty_coda(*head)){
        printf("\nErrore coda vuota");
        return NULL;
    }
    else{
        *head = ret->next;
    }
    if(*head == NULL){
        *tail = NULL;
    }
    return ret;
}

void stampaCoda(Coda* head){
    Coda* l = head;
    printf("Stampa della coda \n");
    while (l != NULL){
        printf("%d ", l->arrivo);
        printf("%d ", l->valore);
        printf("\n");
        l = l->next;
    }
}


int is_empty_pila(Pila* head){
    if(head == NULL)
        return 1;
    else
        return 0;
}

void push(Pila **head, Pila *element){
    if(is_empty_pila(*head)){
        *head = element;
        element->next = NULL;
    } else {
        element->next = *head;
        *head = element;
    }
}

Pila* pop(Pila** head){
    Pila* ret = *head;
    if(is_empty_pila(*head)){
        return NULL;
    } else {
        *head = ret->next;
    }
    return ret;
}

void stampaPila(Pila* head){
    Pila* l = head;
    printf("stampa della pila \n");
    while (l != NULL){
        printf("%d ", l->arrivo);
        printf("%d ", l->valore);
        printf("\n");
        l = l->next;
    }
}

void combattimento(Coda ** head_coda, Pila** head_pila, Coda** tail){
    while(is_empty_coda(*head_coda)!=true && is_empty_pila(*head_pila)!=true){
        Pila* removed_pila = pop(head_pila);
        Coda* removed_coda = dequeue(head_coda,tail);
        if(removed_pila->valore==removed_coda->valore){
            printf("I numeri sono pari, eliminati entrambi \n");
        }else if(removed_coda->valore > removed_pila->valore){
            removed_coda->valore=removed_coda->valore-removed_pila->valore; //aggiornamento del valore con i temporanei
            enqueue(head_coda,tail,removed_coda); //reinserisco
        }else{
            removed_pila->valore=removed_pila->valore-removed_coda->valore; //aggiornamento valore
            push(head_pila,removed_pila); //reinserisco
        }
        if(is_empty_coda(*head_coda)==true){ //invece di usare contatore uso la is_empty
            printf("La pila vince!");
            stampaPila(*head_pila);
            free(removed_pila);
            free(removed_coda);
        }else if(is_empty_pila(*head_pila)==true){ //idem per la pila
            printf("La coda vince! \n");
            stampaCoda(*head_coda);
            free(removed_pila);
            free(removed_coda);
        }
    }
}

int main(){
    Pila* head_pila = NULL;
    Coda* head_coda = NULL;
    Coda* tail = NULL;
    srand(time(NULL));
    for(int k = 1;k<6;k++){
        Pila* elemento_pila = (Pila*) malloc(sizeof(Pila));
        Coda* elemento_coda = (Coda*) malloc(sizeof(Coda));
        elemento_pila->arrivo = k; //invece di chiederlo da tastiera con un for che va da 1 a 6 carico k
        elemento_coda->arrivo = k;
        elemento_pila->valore = LIM_MIN + rand() % (LIM_MAX+1-LIM_MIN); //valori random
        elemento_coda->valore = LIM_MIN + rand() % (LIM_MAX+1-LIM_MIN);
        enqueue(&head_coda, &tail,elemento_coda);
        push(&head_pila, elemento_pila);
    }
    stampaPila(head_pila); //a sinistra si vede l'ordine di arrivo a destra il valore
    stampaCoda(head_coda); //idem per la coda
    combattimento(&head_coda,&head_pila,&tail); //funzione del combattimento che chiude il codice
}