#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int valore;
    struct node* next;   
}Node;

int calcolaLunghezza(Node* lista){
    Node* l = lista;
    int lung = 0;
    while (l != NULL)
    {
        lung++;
        l = l ->next;
    }
    return lung; 
}

int ricorsivaLunghezza(Node* lista, int lung){
    Node* l = lista;
    if(l != NULL){
        lung++;
        lung = ricorsivaLunghezza(l->next, lung);
    }
    return lung;
}

void stampaLista(Node* lista){
    Node* l = lista;
    printf("\nValori lista: ");
    while (l != NULL)
    {
        printf("%d ", l->valore);
        l = l ->next;
    }
}

void stampaListaRicorsiva(Node* lista){
    Node* l = lista;
    if(l != NULL){
        printf("%d ", l->valore);
        stampaListaRicorsiva(l->next);
    }
}

void aggiungiInizio(Node **lista, int x){
    Node* head;
    head = (Node*)malloc(sizeof(Node));
    head->next=*lista;
    head->valore = x;
    *lista = head;
}

void aggiungiFondo(Node** lista, int x){
    Node* l=*lista;
    while(l->next!=NULL){
        l = l->next;
    }
    l->next=(Node*)malloc(sizeof(Node));
    l = l->next;
    l->valore=x;
    l->next=NULL;
}

void eliminaFondo(Node** lista){
    Node *l = *lista;
    Node *l2 = l;
    while(l->next != NULL){
        l2 = l;
        l = l->next;
    }
    l2->next = NULL;
}

int main(){
    int n;
    int lung = 0;
    Node* lista = NULL;
    Node* l;
    do{
        printf("inserire un numero naturale o -1 per terminare: ");
        scanf("%d", &n);
        if(n >= 0){
            if(lista == NULL){
                lista = (Node*) malloc(sizeof(Node));
                l = lista;
            } else {
                l->next = (Node*) malloc(sizeof(Node));
                l = l->next;
            }
            l->valore = n;
            l->next = NULL;
        }
    } while (n >= 0);
    aggiungiInizio(&lista,4);
    aggiungiFondo(&lista,10);
    eliminaFondo(&lista);
    l = lista;
    printf("numeri inseriti: ");
    printf("\n");
    while (l != NULL)
    {
        printf("%d - %p \n", l->valore, l->next);
        l = l->next;
    }
    printf("\n");
    printf("Numero di elementi: %d", calcolaLunghezza(lista));
    printf("\nNumero di elementi con ricorsiva: %d", ricorsivaLunghezza(lista, lung));
    stampaLista(lista);
    printf("\nValori lista ricorsiva: ");
    stampaListaRicorsiva(lista);
    return 0;
}