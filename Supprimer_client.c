#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define taille 700
#define taillec 50
#include "Fonctions.H"

void supprimer_client(FILE*file,int max){
    FILE*temp;
    temp=fopen("temp.txt","wt");
    char mel[taillec];

    printf("mel? \n");
    fgets(mel,taillec,stdin);
    supprimer_entrees(mel);

    int i,vf=0;
    for(i=0;i<max;i++){
        if(Recherche_BD_Mel_lpl(mel,i)==1){
            vf=1;
        }
        else {
        fprintf(temp,"%s,%s,%s,%s,%s,%s,%s \n",BD[i].nom,BD[i].prenom,BD[i].code_postal,BD[i].ville,BD[i].telephone,BD[i].mel,BD[i].profession);}
    }
    fclose(file);

    if (vf==0) printf("non trouve");
    else{
            printf("client bien supprimer");
        }
    fclose(temp);
    remove("annuaire.txt");
    rename("temp.txt","resultat_supprimer.txt");
    }
