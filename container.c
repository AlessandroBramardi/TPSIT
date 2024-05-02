#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct container{
    char* codice;
    int peso;
    int tara;
    struct container* next;
}Film;

int chiediDim(int dim_max){
    int x;
    do{
        printf("inserire il numero massimo [%d]: ", dim_max);
        scanf("%d", &x);
    } while (x > dim_max || x <= 0);
    return x;
}

int is_empty(Film* head){
    if(head == NULL)
        return 1;
    else
        return 0;
}

void push(Film **head, Film *element){
    if(is_empty(*head)){
        *head = element;
        element->next = NULL;
    } else {
        element->next = *head;
        *head = element;
    }
}

Film* pop(Film** head){
    Film* ret = *head;
    if(is_empty(*head)){
        return NULL;
    } else {
        *head = ret->next;
    }
    return ret;
}

void stampaPila(Film* head){
    Film* l = head;
    while (l != NULL){
        printf("%s ", l->codice);
        printf("%d ", l->peso);
        printf("%d \n", l->tara);
        l = l->next;
    }
}

int main(){
    char codice[100];
    int peso;
    int tara;

    
    int DIM = 100;
    Film* head = NULL;
    int dim = chiediDim(DIM);
    printf("%d\n", dim);

    for(int k = 0; k < dim; k++){
        printf("inserire il codice, il peso e la tara: ");
        scanf("%s %d %d", codice, &peso, &tara);
        Film* element = (Film*) malloc(sizeof(Film));
        element->codice = strdup(codice);
        element->peso = peso;
        element->tara = tara;
        push(&head, element);
    }
    
    stampaPila(head);
    Film* removed = pop(&head);
    printf("Elemento rimosso: %s %d %d\n", removed->codice, removed->peso, removed->tara);
    stampaPila(head);
    return 0;
}