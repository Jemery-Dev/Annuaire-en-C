#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define taillec 50
#define taille 700
#include "Fonctions.H"

void permute(Utilisateur *a,Utilisateur *b){
    Utilisateur temp = *a;
    strcpy(a->nom, b->nom);
    strcpy(a->prenom, b->prenom);
    strcpy(a->code_postal, b->code_postal);
    strcpy(a->ville, b->ville);
    strcpy(a->telephone, b->telephone);
    strcpy(a->mel, b->mel);
    strcpy(a->profession, b->profession);
    *b = temp;
}

void trie_client_par_nom(char nom_fic[taillec]){
    remove("resultat_afficher_tries_nom.txt");
    FILE*annuaire = fopen(nom_fic,"r+");
    Remplissage_BD(annuaire);

    int i;
    int j;
    FILE*temp;
    temp=fopen("temp.txt","wt");

    for(i=0;i<max;i++)
        {
        for(j=0;j<max;j++)
        {
            switch(strcmp(BD[i].nom,BD[j].nom))
            {
            case -1:
                permute(&BD[i],&BD[j]);
                break;

            default:
                break;
            }
        }
    }
    for(int cpt=0;cpt<max;cpt++)
        {
            fprintf(temp,"%s,%s,%s,%s,%s,%s,%s\n",BD[cpt].nom,BD[cpt].prenom,BD[cpt].code_postal,BD[cpt].ville,BD[cpt].telephone,BD[cpt].mel,BD[cpt].profession);
        }
        fclose(annuaire);
        fclose(temp);
        rename("temp.txt","resultat_afficher_tries_nom.txt");
        affichage_BD("resultat_afficher_tries_nom.txt");
}
