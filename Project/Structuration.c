#include <stdio.h>
#include <stdlib.h>
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
                     if (c!=',') BD[i].nom[j] = c;
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
                    c = fgetc(file);
                    if (c == EOF) v= 7;
                    if (c!='\n') BD[i].profession[j] = c;
                    else {j = j+taillec;
                          v=0;}
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
            printf("nom %d : %s \n",i+1,BD[i].nom);
            printf("prenom %d : %s \n",i+1,BD[i].prenom);
            printf("code postal %d : %s \n",i+1,BD[i].code_postal);
            printf("ville %d : %s \n",i+1,BD[i].ville);
            printf("telephone %d : %s \n",i+1,BD[i].telephone);
            printf("mel %d : %s \n",i+1,BD[i].mel);
            printf("profession %d : %s \n",i+1,BD[i].profession);
    }
}
