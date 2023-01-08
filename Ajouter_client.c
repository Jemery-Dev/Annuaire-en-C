#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define taillec 50
#define taille 900
#include "Fonctions.H"

void ajouter_client(char nom_fic[taillec], char* nom, char* prenom, char* code_postal, char* ville, char* telephone, char* mel, char* profession){
    if(strlen(mel)==0)
    {
        printf("Erreur, la chaine de caracteres mel est vide\n");
    }
    else{
    FILE*annuaire = fopen(nom_fic,"r+");
    remove("resultat_ajouter.txt");
    FILE*temp;
    temp=fopen("temporary.txt","wt");
    Remplissage_BD(annuaire);
    max = max+1;
    strcpy(BD[max].nom,nom);
    strcpy(BD[max].prenom,prenom);
    strcpy(BD[max].code_postal,code_postal);
    strcpy(BD[max].ville,ville);
    strcpy(BD[max].telephone,telephone);
    strcpy(BD[max].mel,mel);
    strcpy(BD[max].profession,profession);
    int repet=0;
        for(int j=0;j<max;j++){
            if (strcmp(mel,BD[j].mel)==0)
            {
                repet=repet+1;
            }
        }
    if (repet==0)
        {
        for(int i=0;i<max;i++)
        {
            fprintf(temp,"%s,%s,%s,%s,%s,%s,%s \n",BD[i].nom,BD[i].prenom,BD[i].code_postal,BD[i].ville,BD[i].telephone,BD[i].mel,BD[i].profession);
        }
        fprintf(temp,"%s,%s,%s,%s,%s,%s,%s",nom,prenom,code_postal,ville,telephone,mel,profession);
        }
        else{
            printf("Le client n'a pas pu etre ajoute car ce mel existe deja\n");
        }
    fclose(annuaire);
    fclose(temp);
    rename("temporary.txt","resultat_ajouter.txt");
    printf("\nFait\n");
    }
    }
