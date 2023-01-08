#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define taille 700
#define taillec 50
#include "Fonctions.H"

void Modifier_mel_client(char nom_fic[taillec],char mel_p[taillec],char nv_mel_p[taillec]){
    if(strlen(mel_p)==0)
    {
        printf("Erreur, la chaine de caracteres mel est vide\n");
    }
    else{
    remove("resultat_modifier_mel.txt");
    FILE*annuaire = fopen(nom_fic,"r+");
    Remplissage_BD(annuaire);
    FILE*temp;
    temp=fopen("temp.txt","wt");
    int i,vf=0;
    for(i=0;i<max;i++){
        if(Recherche_BD_Mel_lpl(mel_p,i)==1){
            strcpy(BD[i].mel,nv_mel_p);
            vf=1;
        }
        fprintf(temp,"%s,%s,%s,%s,%s,%s,%s\n",BD[i].nom,BD[i].prenom,BD[i].code_postal,BD[i].ville,BD[i].telephone,BD[i].mel,BD[i].profession);
    }
    fclose(temp);
    rename("temp.txt","resultat_modifier_mel.txt");
    if (vf==0) printf("adresse mel non trouvée");
    else printf("adresse mel modifiee\n");
    fclose(annuaire);
    }

}
