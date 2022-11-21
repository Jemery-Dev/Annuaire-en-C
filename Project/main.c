#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    FILE * fichier = fopen("../annuaire.csv","r+");
    if (!fichier){
        printf("Erreur, impossible d'ouvrir le fichier");
    }
    else{
        char buffer[1024];
        int colonne = 0;
        int ligne = 0;

        while(fgets(buffer, 512, fichier)){
            colonne=0;

            char* valeur = strtok(buffer, ", ");

            while(valeur){
                if(colonne == 0){
                    printf("\n Nom : ");
                }
                if(colonne ==1){
                    printf("\n Prénom : ");
                    }
                if(colonne ==2){
                    printf("\n Code postal : ");
                    }
                if(colonne ==3){
                    printf("\n Ville :");
                    }
                if(colonne ==4){
                    printf("\n Numero : ");
                    }
                if(colonne ==5){
                    printf("\n Email : ");
                    }
                if(colonne ==6){
                    printf("\n Metier : ");
                    }
                printf("%s", valeur);
                valeur = strtok(NULL, ", ");
                colonne++;
                ligne++;
                }
                printf("\n");

            }
            fclose(fichier);
        }
        return 0;
    }
