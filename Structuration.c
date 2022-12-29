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
            IBD[i].index_nom=ftell(file);
            for(j=0;j<taillec;j++){
                    c = fgetc(file);
                     if (c!=',') {BD[i].nom[j] = c;}
                    else {j = j+taillec;
                          v=v+1;
                          i=i-1;}
            }
            break;
        case 1:
            IBD[i].index_prenom=ftell(file);
            for(j=0;j<taillec;j++){
                    c = fgetc(file);
                    if (c!=',') BD[i].prenom[j] = c;
                    else {j = j+taillec;
                          v=v+1;
                          i=i-1;}
            }
            break;
        case 2:
            IBD[i].index_code_postal=ftell(file);
            for(j=0;j<taillec;j++){
                    c = fgetc(file);
                    if (c!=',') BD[i].code_postal[j] = c;
                    else {j = j+taillec;
                          v=v+1;
                          i=i-1;}
            }
            break;
        case 3:
            IBD[i].index_ville=ftell(file);
            for(j=0;j<taillec;j++){
                    c = fgetc(file);
                    if (c!=',') BD[i].ville[j] = c;
                    else {j = j+taillec;
                          v=v+1;
                          i=i-1;}
            }
            break;
        case 4:
            IBD[i].index_telephone=ftell(file);
            for(j=0;j<taillec;j++){
                    c = fgetc(file);
                    if (c!=',') BD[i].telephone[j] = c;
                    else {j = j+taillec;
                          v=v+1;
                          i=i-1;}
            }
            break;
        case 5:
            IBD[i].index_mel=ftell(file);
            for(j=0;j<taillec;j++){
                    c = fgetc(file);
                    if (c!=',') BD[i].mel[j] = c;
                    else {j = j+taillec;
                          v=v+1;
                          i=i-1;}
            }
            break;
        case 6:
            IBD[i].index_profession=ftell(file);
            for(j=0;j<taillec;j++){
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
int Taille_BD(){
    int i;
    for(i=0;i<taille;i++){
            if(BD[i].nom[0]== NULL && BD[i].prenom[0] ==NULL && BD[i].code_postal[0]==NULL && BD[i].ville[0]==NULL && BD[i].telephone[0]== NULL && BD[i].mel[0]==NULL && BD[i].profession[0]==NULL) return i;
    }
    return -1;
}
void affichage_BD(int Max){
    printf("\n");
    int i;
    for(i=0;i<Max;i++){
            printf("nom %d : %s a la %deme positions du curseur\n",i+1,BD[i].nom,IBD[i].index_nom);
            printf("prenom %d : %s a la %deme positions du curseur\n",i+1,BD[i].prenom,IBD[i].index_prenom);
            printf("code postal %d : %s a la %deme positions du curseur\n",i+1,BD[i].code_postal,IBD[i].index_code_postal);
            printf("ville %d : %s a la %deme positions du curseur\n",i+1,BD[i].ville,IBD[i].index_ville);
            printf("telephone %d : %s a la %deme positions du curseur\n",i+1,BD[i].telephone,IBD[i].index_telephone);
            printf("mel %d : %s a la %deme positions du curseur\n",i+1,BD[i].mel,IBD[i].index_mel);
            printf("profession %d : %s a la %deme positions du curseur\n",i+1,BD[i].profession,IBD[i].index_profession);
    }
}

int Recherche_BD_Mel_lpl(char c[taillec],int i){
    if (strcmp(c,BD[i].mel)==0) return 1;
    else return -1;
}
