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

void cercaAnno(int anno_scelta, Struttura film[], int cont){
    for(Struttura *k=film;k<film+cont;k++){
        if(anno_scelta==k->anno_uscita){
            printf("%d %s %s %d %s\n",k->n,k->titolo,k->genere,k->anno_uscita,k->disponibilita);
        }
    }
}

int contaRighe(char riga[],Struttura film[], int cont){
    int n=0;
    FILE* fp2=fopen("listafilm.csv","r");
    while(fgets(riga,LUNG_RIGA,fp2)){
        n++;
    }
    fclose(fp2);
    return n;;
}

int main() {
    Struttura* film;
    char fileName[]="./listafilm.csv";
    char riga[LUNG_RIGA];
    FILE* fp;
    char* campo;
    int c=0;
    int scelta;
    int n_righe=contaRighe(riga,film,DIM);
    film=(Struttura*)malloc(n_righe*sizeof(Struttura));
    Struttura *cont=film;
    printf("Numero righe: %d\n",n_righe);
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
