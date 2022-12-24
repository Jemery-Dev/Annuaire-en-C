#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE * fichier = fopen("../annuaire.csv","r+");
    if (!fichier){
        printf("Erreur, impossible d'ouvrir le fichier");
        exit(1);
    }
    int colonne=0;
    int ligne=0;
    char c;
    char chaine[1024];
    int actuel=0;
        while(c != EOF)
        {
        c = fgetc(fichier);

        if (c == ',')
        {
            colonne++;
            printf("\t");
        }
        else if (c == '\n')
        {
            ligne++;
            colonne=0;
            actuel=0;
            printf("\n");
        }
        else
        {

            chaine[actuel] = c;
            printf("%c", chaine[actuel]);
            actuel++;
        }


    }
    fclose(fichier);
    return 0;
}
