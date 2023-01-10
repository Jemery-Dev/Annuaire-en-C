#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define taille 700
#define taillec 50
#include "Fonctions.H"

void Remplissage_BD(FILE*file){
    fseek(file,SEEK_SET,SEEK_CUR);
    int i,j,v=0;
    int c;
    for(i=0;i<taille;i++){
        switch(v){
        case 0:
            for(j=0;j<taillec;j++){
                    c = fgetc(file);
                     if (c!=',') {BD[i].nom[j] = c;}
                    else {j = j+taillec;
                          v=v+1;
                          i=i-1;}
            }
            break;
        case 1:
            for(j=0;j<taillec;j++){
                    c = fgetc(file);
                    if (c!=',') BD[i].prenom[j] = c;
                    else {j = j+taillec;
                          v=v+1;
                          i=i-1;}
            }
            break;
        case 2:
            for(j=0;j<taillec;j++){
                    c = fgetc(file);
                    if (c!=',') BD[i].code_postal[j] = c;
                    else {j = j+taillec;
                          v=v+1;
                          i=i-1;}
            }
            break;
        case 3:
            for(j=0;j<taillec;j++){
                    c = fgetc(file);
                    if (c!=',') BD[i].ville[j] = c;
                    else {j = j+taillec;
                          v=v+1;
                          i=i-1;}
            }
            break;
        case 4:
            for(j=0;j<taillec;j++){
                    c = fgetc(file);
                    if (c!=',') BD[i].telephone[j] = c;
                    else {j = j+taillec;
                          v=v+1;
                          i=i-1;}
            }
            break;
        case 5:
            for(j=0;j<taillec;j++){
                    c = fgetc(file);
                    if (c!=',') BD[i].mel[j] = c;
                    else {j = j+taillec;
                          v=v+1;
                          i=i-1;}
            }
            break;
        case 6:
            for(j=0;j<taillec;j++){
                    max = i;
                    c = fgetc(file);
                    if (c == EOF) v= 7;
                    else {if (c!='\n') BD[i].profession[j] = c;
                    else {j = j+taillec;
                          v=0;}};
            }
            break;
        default:
            i=i+taille;
            break;
            }
        }
        }

void affichage_BD(char nom_fic[taillec]){
    FILE*annuaire = fopen(nom_fic,"r+");
    fseek(annuaire,0,SEEK_SET);
    Remplissage_BD(annuaire);
    printf("\n");

    int i;
    for(i=0;i<=max;i++){
            printf("nom %d : %s \n",i+1,BD[i].nom);
            printf("prenom %d : %s \n",i+1,BD[i].prenom);
            printf("code postal %d : %s \n",i+1,BD[i].code_postal);
            printf("ville %d : %s \n",i+1,BD[i].ville);
            printf("telephone %d : %s \n",i+1,BD[i].telephone);
            printf("mel %d : %s \n",i+1,BD[i].mel);
            printf("profession %d : %s \n",i+1,BD[i].profession);
    }
    fclose(annuaire);
}
int Recherche_BD_Mel_lpl(char c[taillec],int i){
    if (strcmp(c,BD[i].mel)==0) return 1;
    else return -1;
}
int lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;

    if (fgets(chaine, longueur, stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

