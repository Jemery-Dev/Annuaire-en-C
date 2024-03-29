#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define taillec 50
#define taille 700
#include "Fonctions.H"

char*chaine_approriee(char nom_champ[taillec],int i){
    char *p;
    if (strcmp(nom_champ,"nom")==0){
        p=BD[i].nom;
        return p;
    }
    if (strcmp(nom_champ,"prenom")==0){
        p=BD[i].prenom;
        return p;
    }
    if (strcmp(nom_champ,"codepostal")==0){
        p=BD[i].code_postal;
        return p;
    }
    if (strcmp(nom_champ,"ville")==0){
        p=BD[i].ville;
        return p;
    }
    if (strcmp(nom_champ,"telephone")==0){
        p=BD[i].telephone;
        return p;
    }
    if (strcmp(nom_champ,"mel")==0){
        p=BD[i].mel;
        return p;
    }
    if (strcmp(nom_champ,"profession")==0){
        p=BD[i].profession;
        return p;
    }
    return "none";
}

void filtrer_combiner_2_champs(char nom_fic[taillec],char nom_champ1[taillec],char nom_champ2[taillec],char val_chaine1[taillec],char val_chaine2[taillec]){
    remove("resultat_filtrer_combiner_deux_champs.txt");
    FILE*annuaire = fopen(nom_fic,"r+");
    Remplissage_BD(annuaire);
    FILE*temp;
    temp=fopen("temp.txt","wt");
    int i;
    char *c1;
    char *c2;
    for(i=0;i<=max;i++){
        c1 = chaine_approriee(nom_champ1,i);
        c2 = chaine_approriee(nom_champ2,i);
        if(strstr(c1,val_chaine1)!=NULL && strstr(c2,val_chaine2)!=NULL){
            fprintf(temp,"%s,%s,%s,%s,%s,%s,%s\n",BD[i].nom,BD[i].prenom,BD[i].code_postal,BD[i].ville,BD[i].telephone,BD[i].mel,BD[i].profession);
        }
    }
    fclose(temp);
    rename("temp.txt","resultat_filtrer_combiner_deux_champs.txt");
    printf("Fait \n");
    fclose(annuaire);
}

