#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct film{
    char* nome;
    char* titolo;
    int anno;
    struct film* next;
}Film;


int is_empty(Film* head) {
    return head == NULL; 
}

int calcolaLunghezza(Film* head){
    Film* h = head;
    int lung = 0;
    while (h != NULL)
    {
        lung++;
        h = h ->next;
    }
    return lung; 
}


void enqueue(Film** head, Film** tail, Film* elem){
    if(is_empty(*head)){
        *head = elem;
    }
    else{
        (*tail)->next = elem;
    }
    *tail = elem;
    elem->next = NULL;
}

Film* dequeue(Film** head, Film** tail){
    Film* ret = *head;
    if(is_empty(*head)){
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


void stampaCoda(Film* head){
    Film* h = head;
    while (h != NULL)
    {
        printf("%s, %s, %d ", h->nome, h->cognome, h->eta);
        h = h ->next;
    }
}

void uscitaProgramma(Film * head){
    if(head->next != NULL){
        uscitaProgramma(head->nome);
    }
    free(head);
}



int main() {
    Persona * head = NULL;
    Persona * tail = NULL;
    Persona * elemento = (Persona*) malloc(sizeof(Persona));
    elemento->nome = "Alessandro";
    elemento->cognome = "Brama";
    elemento->eta = 18;
    elemento->next = NULL;
    enqueue(&head, &tail,elemento);
    Persona * elemento2 = (Persona*) malloc(sizeof(Persona));
    elemento2->nome = "Marco";
    elemento2->cognome = "Borgis";
    elemento2->eta = 17;
    elemento2->next = NULL;
    enqueue(&head, &tail,elemento2);
    stampaCoda(head);
    printf("Dimensione della coda: %d", calcolaLunghezza(head));
    Persona* temp = dequeue(&head, &tail);
    printf("\n%s", temp->cognome);
    free(elemento);
    free(elemento2);
    
    return 0;
}
