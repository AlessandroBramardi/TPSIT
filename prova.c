#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct El{
    int dato;
    struct El* next;
}El;

int FirstEven(El* l){
    int k=0;
    bool trovato = false;
    while(l!= NULL && trovato == false){
        if(l->dato % 2 == 0){
            trovato=true;
        }else{
            l = l->next;
            k++;
        }
    }
    if(trovato==false){
        k=-1;
    }
    return k;
}

int FirstDispari(El* l){
    int k=0;
    bool trovato = false;
    while(l->next != NULL && trovato==false){
        if(l->dato % 2 != 0){
            trovato = true;
        }else{
            l = l->next;
            k++;
        }
    }
    if(trovato==false){
        k=-1;
    }
    return k;
}

int calcolaLunghezza(El * l){
    int k=0;
    while(l != NULL){
        k++;
        l=l->next;
    }
    return k-1;
}

int calcolaLunghezzaRic(El*l){
    int k=0;
    while(l != NULL){
        k++;
        calcolaLunghezzaRic(l=l->next);
    }
    return k-1;
}

void aggiungiFondo(El** l, int n){
    El* lista = *l;
    while(lista->next != NULL){
        lista = lista->next;
    }
    lista=(El*)malloc(sizeof(El));
    lista = lista->next;
    lista->dato=n;
    lista->next=NULL;
}

void aggiungiInizio(El** l, int n){
    El* head;
    head=(El*)malloc(sizeof(El));
    head->next=*l;
    head->dato=n;
    *l=head;    
}
void stampaLista(El* l){
    while(l != NULL){
        printf("%d ", l->dato);
        l=l->next;
    }
}

El* eliminaFondo(El**l){
    El * lista = *l;
    El * l2 = lista;
    while(lista->next!= NULL){
        l2=lista;
        lista=lista->next;
    }
    //l2->next=NULL;
    return l2;  
}


int main(){
    El* lista = NULL;
    El * l;
    int n;
    do{
        printf("Inserisci un numero \n");
        scanf("%d",&n);
        if(n!=-1){
            if(lista==NULL){
                lista=(El*)malloc(sizeof(El));
                l = lista;
            }else{
                l ->next= (El*)malloc(sizeof(El));
                l = l->next;
            }
            l->dato=n;
            l->next=NULL;
        }
    }while(n!=-1);
    printf("Il primo numero pari si trova nella posizione: %d \n", FirstEven(lista));
    printf("Il primo numero dispari si trova nella posizione: %d \n", FirstDispari(lista));
    printf("La lista e' lunga: %d \n", calcolaLunghezza(lista));
    printf("Lunghezza ricorsiva: %d \n", calcolaLunghezzaRic(lista));
    aggiungiFondo(&lista,10);
    aggiungiInizio(&lista,3);
    stampaLista(lista);
    eliminaFondo(&lista);
    printf("\n");
    stampaLista(lista);
}