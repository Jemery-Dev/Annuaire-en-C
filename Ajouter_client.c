#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define taillec 50
#define taille 700
#include "Fonctions.H"


void supprimer_entrees(char c[taille]){
    int i;
    for(i=0;i<=taillec;i++){
        if (c[i]=='\n' || c[i]==' ') c[i]=NULL;
    }
}

void ajouter_client(FILE*file){
    FILE*temp;
    temp=fopen("temp.txt","wt");
    int nbr_client;
    int max = Taille_BD();
    printf("Entrez le nombre de client que vous voulez ajoutez \n");
    scanf("%d",&nbr_client);
    for(int i=0;nbr_client>i;i++)
    {
        int repet=0;
        printf("Entrez le mel du client :\n");
        scanf("%s",&BD[max+(i+1)].mel);
        for(int j=0;j<max+i;j++){
            if (strcmp(BD[max+(i+1)].mel,BD[j+i].mel)==0)
            {
                repet=repet+1;
            }
        }

        if (repet==0){
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
        }
        else{
            printf("Le client n'a pas pu etre ajoute car ce mel existe deja\n");
        }
    }
    for(int cpt=0;cpt<max+nbr_client;cpt++)
    {
        fprintf(temp,"\n%s,%s,%s,%s,%s,%s,%s",BD[cpt].nom,BD[cpt].prenom,BD[cpt].code_postal,BD[cpt].ville,BD[cpt].telephone,BD[cpt].mel,BD[cpt].profession);
    }
    fclose(file);
    fclose(temp);
    rename("temp.txt","resultat_ajouter_client.txt");
    }
