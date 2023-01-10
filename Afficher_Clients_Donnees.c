#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define taille 700
#define taillec 50
#include "Fonctions.H"

void afficher_clients_donnees_manquantes(char nom_fic[taillec]){
    remove("resultat_afficher_donnees_manquantes.txt");
    FILE*annuaire = fopen(nom_fic,"r+");
    Remplissage_BD(annuaire);
    int i,vf=0;
    FILE*temp;
    temp=fopen("temp.txt","wt");
    for(i=0;i<=max;i++){
            if(BD[i].nom[0]== '\0' || BD[i].prenom[0] =='\0' || BD[i].code_postal[0]=='\0' || BD[i].ville[0]=='\0' || BD[i].telephone[0]== '\0' || BD[i].mel[0]=='\0' || BD[i].profession[0]=='\0')
                {
                    fprintf(temp,"%s,%s,%s,%s,%s,%s,%s \n",BD[i].nom,BD[i].prenom,BD[i].code_postal,BD[i].ville,BD[i].telephone,BD[i].mel,BD[i].profession);
                    vf =1;
                }
                }
    fclose(temp);
    fclose(annuaire);
    rename("temp.txt","resultat_afficher_donnees_manquantes.txt");
    if(vf=0) printf("aucun utilisateur n'a de donnees manquantes");
    else printf("fichier cree avec les clients auquels ils manquent des données \n");
    fclose(annuaire);
}
