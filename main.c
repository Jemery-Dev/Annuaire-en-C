#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fonctions.H"
#define nom_fic "annuaire.csv"
int main()
{
    int i,j,arr=0;
    char nom[taillec],prenom[taillec],code_postal[taillec],ville[taillec],telephone[taillec],mel[taillec],profession[taillec],nv_mel[taillec],nom_champ[taillec],val_chaine[taillec],nom_champ2[taillec],val_chaine2[taillec];
    printf("***Application de Gestion d'Annuaire Numérique \n");
    while(arr==0){
    printf("\n**1-Ajouter Un client\n");
    printf("**2-Modifier Donnees Client\n");
    printf("**3-Supprimer un client\n");
    printf("**4-Afficher la liste de tous les clients,triés ou non par ordre alphabetique \n");
    printf("**5-Filtrer la liste de clients \n");
    printf("**6-Afficher la liste de tous les clients dont des données sont manquantes\n");
    printf("**7-Sauvegarder (recommande apres avoir fait une modification sinon donnees perdues)(optionnel) \n");
    printf("**0-Quitter l'Application \n");

    scanf("%d",&i);
        switch(i){
            case 1: printf("**Entrez les données de ce nouveau client\n");
                    printf("*Nom?\n");
                    getchar();
                    lire(nom,taillec);
                    printf("*Prenom?\n");
                    lire(prenom,taillec);
                    printf("*Code postal?\n");
                    lire(code_postal,taillec);
                    printf("*Ville?\n");
                    lire(ville,taillec);
                    printf("*Telephone?\n");
                    lire(telephone,taillec);
                    printf("*Mel?\n");
                    lire(mel,taillec);
                    printf("*Profession?\n");
                    lire(profession,taillec);
                    ajouter_client(nom_fic,nom,prenom,code_postal,ville,telephone,mel,profession);
                    break;
            case 2: printf("Voulez vous modifier un mail(1) ou un autre champ(2)?\n");
                    scanf("%d",&j);
                    if(j==1){
                        printf("*Quel mail voulez vous modifier?\n");
                        getchar();
                        lire(mel,taillec);
                        printf("*Par quoi voulez vous remplacer?\n");
                        lire(nv_mel,taillec);
                        Modifier_mel_client(nom_fic,mel,nv_mel);
                    }
                    else {
                    if(j==2){
                    printf("*Saisissez l'addresse mail pour modifier.\n");
                    getchar();
                    lire(mel,taillec);
                    printf("*Quel champ voulez vous modifier ?\n");
                    lire(nom_champ,taillec);
                    printf("*Que voulez vous y mettre?\n");
                    lire(val_chaine,taillec);
                    modifier_autres_que_mel(nom_fic,mel,nom_champ,val_chaine);
                    }
                    else printf("Veuillez choisir une option valide\n");}
                    break;
            case 3: printf("*Quelle est l'adresse mail du client que vous souhaitez supprimer?\n");
                    getchar();
                    lire(mel,taillec);
                    supprimer_client(nom_fic,mel);
                    break;
            case 4: printf("Voulez vous afficher la base de donnees comme tel(1)ou trie par ordre alphabetique?(2)\n");
                    scanf("%d",&j);
                    if(j==1){
                    getchar();
                    affichage_BD(nom_fic);
                    }
                    else {if (j==2){
                    getchar();
                    trie_client_par_nom(nom_fic);
                    }
                    else printf("Veuillez saisir un nombrre valide \n");}
                    break;
            case 5: printf("*Avec combien de champs voulez vous filtrer l'annuaire?\n");
                    scanf("%d",&j);
                    if (j==1){
                    getchar();
                    printf("*Filtrer par quel champ?\n");
                    lire(nom_champ,taillec);
                    printf("*Filtrer par quoi?\n");
                    lire(val_chaine,taillec);
                    filtrer_un_champ(nom_fic,nom_champ,val_chaine);
                    }
                    else{
                    if (j==2){
                        getchar();
                        printf("*Filtrer par quel premier champ?\n");
                        lire(nom_champ,taillec);
                        printf("*Filtrer par quoi ?\n");
                        lire(val_chaine,taillec);
                        printf("*Filtrer par quel deuxieme champ?\n");
                        lire(nom_champ2,taillec);
                        printf("*Filtrer par quoi ?\n");
                        lire(val_chaine2,taillec);
                        filtrer_combiner_2_champs(nom_fic,nom_champ,nom_champ2,val_chaine,val_chaine2);
                    }
                    else printf("Veuillez saisir un nombre valide \n");
                    }
                    break;
            case 6: afficher_clients_donnees_manquantes(nom_fic);
                    break;
            case 7: Sauvegarder(nom_fic);
                    printf("Fait\n");
                    break;
            case 0: arr=1;
                    break;
            default:printf("Entrez un nombre valide \n");
                    break;
        }
    }
    return 0;
}

