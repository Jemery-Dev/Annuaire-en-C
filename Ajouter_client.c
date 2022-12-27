#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define taillec 50
#define taille 700
#include "Fonctions.H"
#define resultat "./resultat_ajouter.txt"


void supprimer_entrees(char c[taille]){
    int i;
    for(i=0;i<=taillec;i++){
        if (c[i]=='\n' || c[i]==' ') c[i]=NULL;
    }
}

void ajouter_client(FILE*file){
    FILE*resultat_ajouter = fopen(resultat,"a");
    char characteres;
    int nbr_client;
    int max = Taille_BD();
    int repet=0;
    int i,j;
    printf("Entrez le nombre de client que vous voulez ajoutez \n");
    scanf("%d",&nbr_client);
    for(i=0;nbr_client>i;i++)
    {
        printf("Entrez le mel du client :\n");
        scanf("%s",&BD[max+(i+1)].mel);
        // On regarde si il y a déjà le même mel pour deux clients
        repet=0;
        for(j=0;j<max+i;j++){
            if (strcmp(BD[max+(i+1)].mel,BD[j+i].mel)==0)
            {
                repet=repet+1;
            }
        }

        if (repet==0){
            // Création d'un nouveau fichier resultat_ajouter.txt
            characteres = fgetc(file);
            while (characteres != EOF)
            {
                fputc(characteres, resultat);
                characteres = fgetc(file);
            }

            fflush(stdin);
            printf("Entrez le nom du client :\n");
            fgets(BD[max+1].nom,taillec,stdin);
            supprimer_entrees(BD[max+(i+1)].nom);

            printf("Entrez le prenom du client :\n");
            fgets(BD[max+1].prenom,taillec,stdin);
            supprimer_entrees(BD[max+(i+1)].prenom);

            printf("Entrez le code postal du client :\n");
            fgets(BD[max+1].code_postal,taillec,stdin);
            supprimer_entrees(BD[max+(i+1)].code_postal);

            printf("Entrez le ville du client :\n");
            fgets(BD[max+1].ville,taillec,stdin);
            supprimer_entrees(BD[max+(i+1)].ville);

            printf("Entrez le telephone du client :\n");
            fgets(BD[max+1].telephone,taillec,stdin);
            supprimer_entrees(BD[max+(i+1)].telephone);

            printf("Entrez la profession du client :\n");
            fgets(BD[max+1].profession,taillec,stdin);
            supprimer_entrees(BD[max+(i+1)].profession);

            fseek(resultat,SEEK_SET,SEEK_END);
            fprintf(resultat,"\n%s,%s,%s,%s,%s,%s,%s",BD[max+(i+1)].nom,BD[max+(i+1)].prenom,BD[max+(i+1)].code_postal,BD[max+(i+1)].ville,BD[max+(i+1)].telephone,BD[max+(i+1)].mel,BD[max+(i+1)].profession);
            printf("Le client a ete ajoute avec succès\n");
        }
        else{
            printf("Le client n'a pas pu etre ajoute car ce mel existe deja\n");
        }
    }
}
