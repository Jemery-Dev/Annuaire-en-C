#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define taille 900
#define taillec 50
#include "Fonctions.H"

void supprimer_client(char nom_fic[taillec],char mel_p[taillec]){
    FILE*annuaire = fopen(nom_fic,"r+");
    Remplissage_BD(annuaire);
    remove("resultat_supprimer.txt");
    FILE*temp;
    temp=fopen("temp.txt","wt");

    int i,vf=0;
    for(i=0;i<=max;i++){
        if(Recherche_BD_Mel_lpl(mel_p,i)==1){
            vf=1;
        }
        else {
        fprintf(temp,"%s,%s,%s,%s,%s,%s,%s \n",BD[i].nom,BD[i].prenom,BD[i].code_postal,BD[i].ville,BD[i].telephone,BD[i].mel,BD[i].profession);}
    }
    fclose(annuaire);

    if (vf==0) printf("non trouve\n ");
    else{
            printf("client bien supprimer \n");
        }
    fclose(temp);
    fclose(annuaire);
    rename("temp.txt","resultat_supprimer.txt");
    }
