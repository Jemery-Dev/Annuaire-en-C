#ifndef FONCTIONS_H
#define FONCTIONS_H
#define taille 700
#define taillec 50
// Structure
typedef struct Utilisateur{
    char nom[taillec];
    char prenom[taillec];
    char code_postal[taillec];
    char ville[taillec];
    char telephone[taillec];
    char mel[taillec];
    char profession[taillec];
}Utilisateur;
struct Utilisateur BD[taille];

typedef struct Index{
    int index_nom;
    int index_prenom;
    int index_code_postal;
    int index_ville;
    int index_telephone;
    int index_mel;
    int index_profession;
}Index;
struct Index IBD[taille];
// Fonctions utiles pour gerer la structuration
void Remplissage_BD(FILE*file);
void affichage_BD(int Max);
int Recherche_BD_Nom(char c1[taillec],char c2[taillec],int Max);
int Taille_BD();
#endif // FONCTIONS_H

