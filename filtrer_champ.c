#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define taillec 50
#define taille 700
#include "Fonctions.H"
void filtrer_un_champ(FILE*file)
{
    char nom_champ[taillec];
    char val_chaine[taillec];
    int max=Taille_BD();
    FILE *resultat = fopen("resultat_filtrer_un_champ.txt", "w");

    printf("Entrez le nom du champ parmi : nom prenom code_postal ville numero_telephone mail profession\n");
    fgets(nom_champ,taillec,stdin);
    supprimer_entrees(nom_champ);

    printf("Entrez une chaine non vide\n");
    fgets(val_chaine,taillec,stdin);
    supprimer_entrees(val_chaine);

    if(strlen(val_chaine)==0)
    {
        printf("Erreur, la chaine de caracteres val_chaine est vide\n");
    }
    else{
    for(int i=0;i<max;i++){
    int filtrer=0;
    if (strcmp(nom_champ, "nom") == 0 && strstr(BD[i].nom, val_chaine) != NULL){
            filtrer = 1;
    }
        else if (strcmp(nom_champ, "prenom") == 0 && strstr(BD[i].prenom, val_chaine) != NULL){
            filtrer = 1;
    }
        else if (strcmp(nom_champ, "code postal") == 0 && strstr(BD[i].code_postal, val_chaine) != NULL){
            filtrer = 1;
    }
        else if (strcmp(nom_champ, "ville") == 0 && strstr(BD[i].ville, val_chaine) != NULL){
            filtrer = 1;
    }
        else if (strcmp(nom_champ, "numero_telephone") == 0 && strstr(BD[i].telephone, val_chaine) != NULL){
            filtrer = 1;
    }
         else if (strcmp(nom_champ, "mail") == 0 && strstr(BD[i].mel, val_chaine) != NULL){
            filtrer = 1;
    }
        else if (strcmp(nom_champ, "profession") == 0 && strstr(BD[i].profession, val_chaine) != NULL){
            filtrer = 1;
    }

    if (filtrer==1){
        fprintf(resultat, "%s;%s;%s;%s;%s;%s;%s\n", BD[i].nom, BD[i].prenom, BD[i].code_postal, BD[i].ville, BD[i].telephone, BD[i].mel, BD[i].profession);
    }
    }
    }
    fclose(resultat);
    fclose(file);
}

