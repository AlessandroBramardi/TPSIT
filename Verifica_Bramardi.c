#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG_MAX 200

typedef struct{
    char* data;
    char* cognome;
    int importo;
}Gita;

typedef struct{
    char * cognome;
    int importo;
}Io;

int contaRighe(char file[], char riga[]){
    int n = 0;
    FILE *fp2 = fopen(file, "r");
    while (fgets(riga, LUNG_MAX, fp2))
    {
        n++;
    }
    fclose(fp2);
    return n;
}

void caricaGita(char file[], char riga[], Gita alunno[]){
    char *campo;
    Gita *cont = alunno;
    FILE *fp = fopen(file, "r");
    if (fp == NULL)
    {
        printf("impossibile aprire file!");
        exit(1);
    }
    while (fgets(riga, LUNG_MAX, fp))
    {
        campo = strtok(riga, ";");
        cont->data = strdup(campo);
        campo = strtok(NULL, ";");
        cont->cognome = strdup(campo);
        campo = strtok(NULL, ";");
        cont->importo = atoi(campo); // atof float
        cont++;
    }
    fclose(fp);
}

void totaleInc(Gita alunno[], int n){
    int somma=0;
    Gita* k;
    for(k=alunno;k<alunno+n;k++){
        somma=somma+k->importo;
    }
    if(somma<2200){
        int s_mancanti=2200-somma;
        printf("Importo insufficente! \n");
        printf("Mancano %d euro \n",s_mancanti);
    }else{
        printf("Importo totale raggiunto");
    }
}

void ricercaCognome(Gita alunno[], int n){
    Io* alunno_br;
    alunno_br->cognome="Bramardi";
    int imp_agg;
    printf("Inserire l'importo aggiunto:");
        scanf("%d",&imp_agg);
    for(Gita*k=alunno;k<alunno+n;k++){
        if(strcmp(alunno_br->cognome,k->cognome)==0){
            alunno_br->importo=k->importo;
        }
    }
    alunno_br->importo=alunno_br->importo+imp_agg;
    if(alunno_br->importo==100){
        printf("Importo pagato!");
    }else{
        printf("L'alunno %s deve ancora pagare %d \n",alunno_br->cognome,100-alunno_br->importo);
    }
}

void stampaSitua(Gita*alunno, int n){
    for (Gita *k = alunno; k < alunno + n; k++)
    {
        printf("Data: %s Cognome: %s importo: %d ", k->data, k->cognome, k->importo);
        if(k->importo<100){
            printf("DA CONTROLLARE");
        }
        printf("\n");
    }
}

int main(){
    Gita* alunno;
    char riga[LUNG_MAX];
    char file[LUNG_MAX]="4AROB_GITA.csv";
    int n_righe=contaRighe(file,riga);
    alunno = (Gita *)malloc(n_righe * sizeof(Gita));
    caricaGita(file,riga,alunno);
    totaleInc(alunno,n_righe);
    ricercaCognome(alunno,n_righe);
    printf("Situazione pagamento gita: \n");
    stampaSitua(alunno,n_righe);
    free(alunno);
}

