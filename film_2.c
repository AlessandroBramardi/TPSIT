/*
author: Bramardi Alessandro
date:
es.
testo:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define LUNG_MAX 150
#define DIM 20000
#define LUNG_RIGA 200

typedef struct {
    int n;
    char* titolo;
    char* genere;
    int anno_uscita;
    char* disponibilita;
} Struttura;

/*
int leggiFile(Struttura film[]) {
    FILE*fp=fopen("listafilm.csv","r");
    int k=0;
    char riga[LUNG_RIGA];
    char *tok;
    while(fgets(riga,LUNG_RIGA,fp)!=NULL) {
        tok=strtok(riga,",");
        film[k].n=atoi(tok);
        tok=strtok(NULL,",");
        strcpy(film[k].titolo,tok);
        tok=strtok(NULL,",");
        strcpy(film[k].genere,tok);
        tok=strtok(NULL,",");
        film[k].anno_uscita=atoi(tok);
        tok=strtok(NULL,",");
        strcpy(film[k].disponibilita,tok);
        k++;
    }
    fclose(fp);
    return k;
}
*/

void cercaAnno(int anno_scelta, Struttura film[], int cont){
    for(Struttura *k=film;k<film+cont;k++){
        if(anno_scelta==k->anno_uscita){
            printf("%d %s %s %d %s\n",k->n,k->titolo,k->genere,k->anno_uscita,k->disponibilita);
        }
    }
}

int main() {
    Struttura film[DIM];
    char fileName[]="./listafilm.csv";
    char riga[LUNG_RIGA];
    FILE* fp;
    char* campo;
    Struttura *cont=film;
    int c=0;
    int scelta;
    fp=fopen(fileName,"r");
    if(fp==NULL){
        printf("Il file non esiste! \n");
        exit(1);
    }
    while(fgets(riga,LUNG_RIGA,fp)){
        campo=strtok(riga,",");
        cont->n=atoi(campo);
        campo=strtok(NULL,",");
        cont->titolo=strdup(campo);
        campo=strtok(NULL,",");
        cont->genere=strdup(campo);
        campo=strtok(NULL,",");
        cont->anno_uscita=atoi(campo);
        campo=strtok(NULL,",");
        cont->disponibilita=strdup(campo);
        cont++;
        c++;
    }
    
    for(Struttura *k=film; k<film+c; k++) {
        printf("%d %s %s %d %s\n",k->n,k->titolo,k->genere,k->anno_uscita,k->disponibilita);
    }
    
    printf("Inserisci un anno: \n");
    scanf("%d",&scelta);
    cercaAnno(scelta,film,c);
    return 0;
}
