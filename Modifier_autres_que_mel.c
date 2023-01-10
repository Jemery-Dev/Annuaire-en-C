#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define taille 700
#define taillec 50
#include "Fonctions.H"

 void modifier_autres_que_mel(char nom_fic[taillec],char* mel, char* nom_champ, char* val_chaine){
    FILE*annuaire = fopen(nom_fic,"r+");
    Remplissage_BD(annuaire);
    FILE*temp;
    remove("resultat_modifier_autres_que_mel.txt");
    temp=fopen("temporaire.txt","wt");
    int i,vf=0;

    for(i=0;i<=max;i++){
        if(Recherche_BD_Mel_lpl(mel,i)==1){
            if (strcmp(nom_champ, "nom") == 0){
                strcpy(BD[i].nom,val_chaine);
    }
        else if (strcmp(nom_champ, "prénom") == 0){
                strcpy(BD[i].prenom,val_chaine);
    }
        else if (strcmp(nom_champ, "code postal") == 0){
                strcpy(BD[i].code_postal,val_chaine);
    }
        else if (strcmp(nom_champ, "ville") == 0){
                strcpy(BD[i].ville,val_chaine);
    }
        else if (strcmp(nom_champ, "numéro téléphone") == 0){
                strcpy(BD[i].telephone,val_chaine);
    }
        else if (strcmp(nom_champ, "profession") == 0){
                strcpy(BD[i].profession,val_chaine);
    }
        else{
            printf("Le nom du champ n'existe pas");
        }
            vf=1;
        }
        fprintf(temp,"%s,%s,%s,%s,%s,%s,%s\n",BD[i].nom,BD[i].prenom,BD[i].code_postal,BD[i].ville,BD[i].telephone,BD[i].mel,BD[i].profession);
    }
    fclose(annuaire);
    fclose(temp);
    rename("temporaire.txt","resultat_modifier_autres_que_mel.txt");
    if (vf==0) printf("L'adresse mail n'a pas ete trouve \n");
    else printf("Fait\n");
}
