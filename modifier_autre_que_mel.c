#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define taille 700
#define taillec 50
#include "Fonctions.H"

void modifier_autre_que_mel(FILE*file,int max){
    FILE*temp;
    temp=fopen("temp.txt","wt");
    char mel[taillec];

    printf("Entrez le mel du client :\n");
    fgets(mel,taillec,stdin);
    supprimer_entrees(mel);

    int i,vf=0;
    for(i=0;i<max;i++){
        if(Recherche_BD_Mel_lpl(mel,i)==1){
            printf("Entrez le nouveau nom du client ou remettre le meme pour aucun changement\n");
            fgets(BD[i].nom,taillec,stdin);
            supprimer_entrees(BD[i].nom);

            printf("Entrez le nouveau prenom du client ou remettre le meme pour aucun changement\n");
            fgets(BD[i].prenom,taillec,stdin);
            supprimer_entrees(BD[i].prenom);

            printf("Entrez le nouveau code_postal du client ou remettre le meme pour aucun changement\n");
            fgets(BD[i].code_postal,taillec,stdin);
            supprimer_entrees(BD[i].code_postal);

            printf("Entrez la nouvelle ville du client ou remettre le meme pour aucun changement\n");
            fgets(BD[i].ville,taillec,stdin);
            supprimer_entrees(BD[i].ville);

            printf("Entrez le nouveau telephone du client ou remettre le meme pour aucun changement\n");
            fgets(BD[i].telephone,taillec,stdin);
            supprimer_entrees(BD[i].telephone);

            printf("Entrez la nouvelle profession du client ou remettre le meme pour aucun changement\n");
            fgets(BD[i].profession,taillec,stdin);
            supprimer_entrees(BD[i].profession);
            vf=1;
        }
        fprintf(temp,"%s,%s,%s,%s,%s,%s,%s\n",BD[i].nom,BD[i].prenom,BD[i].code_postal,BD[i].ville,BD[i].telephone,BD[i].mel,BD[i].profession);
    }
    fclose(file);
    fclose(temp);
    rename("temp.txt","resultat_modifier_autre_que_mel.txt");
    if (vf==0) printf("L'adresse mail n'a pas ete trouve");
    else printf("adresse mel modifiee");
}
