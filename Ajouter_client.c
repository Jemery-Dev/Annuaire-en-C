#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define taillec 50
#define taille 700
#include "Fonctions.H"

void ajouter_client(FILE*file){
    int nbr_client;
    int repet;
    printf("Entrez le nombre de client que vous voulez ajoutez \n");
    scanf("%d",&nbr_client);
    for(int i=0;nbr_client>i;i++)
    {
        char mel[taillec];
        printf("Entrez le mel du client :\n");
        scanf("%s", mel);
        // On regarde si il y a déjà le même mel pour deux clients
        repet=0;
        for(int i=0;i<taille;i++){
            if (strcmp(mel,BD[i].mel)==0)
            {
                repet=repet+1;
            }
        }
        if (repet==0){
        char nom[taillec];
        printf("Entrez le nom du client :\n");
        scanf("%s", nom);
        char prenom[taillec];
        printf("Entrez le prenom du client :\n");
        scanf("%s", prenom);
        char code_postal[taillec];
        printf("Entrez le code postal du client :\n");
        scanf("%s", code_postal);
        char ville[taillec];
        printf("Entrez le ville du client :\n");
        scanf("%s", ville);
        char telephone[taillec];
        printf("Entrez le telephone du client :\n");
        scanf("%s", telephone);
        char profession[taillec];
        printf("Entrez la profession du client :\n");
        scanf("%s", profession);
        file = fopen("annuaire.txt", "a");
        fprintf(file,"\n%s,%s,%s,%s,%s,%s,%s",nom,prenom,code_postal,ville,telephone,mel,profession);
        fclose(file);
        printf("Le client a ete ajoute avec succès\n");
        }
        if (repet>0){
            printf("Le client n'a pas pu etre ajoute car ce mel existe deja\n");
        }
    }
}
