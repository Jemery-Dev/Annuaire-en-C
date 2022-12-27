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
void Remplissage(FILE*file);
void affichage_BD(int Max);
void Recherche_BD();
int Taille_BD();

// Fonctions de la SAE

void ajouter_client(FILE*file);
void supprimer_entrees(char c[taille]);
#endif // FONCTIONS_H

