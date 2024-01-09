#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node{
    char c;
    struct node* next;
}Node;

int is_empty(Node*head){
    if(head==NULL)return 1;
    else return 0;
}

void push(Node**head, Node*element){
    if(is_empty(*head)){
        *head = element;
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

void stampaPila(Node* head){
    Node* p = head;
    while(p!=NULL){
        printf("%c ",p->c);
        p=p->next;
    }
}

void controlloPar(char* str){
    Node* head = NULL;
    for(int k=0;k<strlen(str);k++){
        if(str[k] == '(' || str[k] == '[' || str[k] == '{'){
            Node * element = (Node*)malloc(sizeof(Node));
            element->c=str[k];
            push(&head,element);
        }
        if (str[k] == ')' || str[k] == ']' || str[k] == '}') {
            Node* removed = pop(&head);
            if (removed == NULL ||
                (str[k] == ')' && removed->c != '(') ||
                (str[k] == ']' && removed->c != '[') ||
                (str[k] == '}' && removed->c != '{')) {
            }
    }
    }
    if(is_empty(head)==true){
        printf("Parentesi corrette");
    }else{
        printf("Parentesi non corrette!: \n");
        stampaPila(head);
    }
   
}


int main(){
    char str[100];
    printf("Inserire una stringa con parentesi: ");
    fflush(stdin);
    gets(str);
    Node* head = NULL;
    controlloPar(str);
    return 0;
}
