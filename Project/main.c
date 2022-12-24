#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define nom_fic "../annuaire.txt"
#include "Fonctions.H"
int main()
{
    FILE*annuaire = fopen(nom_fic,"r+");
    Remplissage_BD(annuaire);
    int Max = Taille_BD();
    affichage_BD(Max);
    return 0;
}
