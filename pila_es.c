#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node{
    char c;
    struct Node* next;
}Node;

int is_empty(Node*head){
    if(head==NULL)return 1;
    else return 0;
}

void push(Node**head, Node* element){
    if(is_empty(*head)){
        *head=element;
        element->next=NULL;
    }else{
        element->next=*head;
        *head = element;
    }       
}

Node* pop(Node**head){
    Node * ret = *head;
    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}

bool isPalindroma(int lunghezza, char * str){
    Node * head = NULL;

    for(int k=0;k<lunghezza;k++){
        Node * element=(Node*)malloc(sizeof(Node));
        element->c=str[k];
        push(&head,element);
    }

    for(int k=0;k<lunghezza;k++){
        Node* element = pop(&head);
        if(element->c != str[k]){
            return false;
        }
    }
    return true;
}


int main(){
    char str[100];
    int lunghezza;
    Node * head = NULL;
    printf("Inserisci una stringa: \n");
    fflush(stdin);
    scanf("%s",str);
    lunghezza=strlen(str);
    if(isPalindroma(lunghezza,str)){
        printf("La stringa e' palindroma \n");
    }else{
        printf("La stringa non e' palindroma");
    }

}


