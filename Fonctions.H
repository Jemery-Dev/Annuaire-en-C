#ifndef FONCTIONS_H
#define FONCTIONS_H
#define taille 700
#define taillec 50
// Structure
typedef struct Utilisateur{
    int id;
    char nom[taillec];
    char prenom[taillec];
    char code_postal[taillec];
    char ville[taillec];
    char telephone[taillec];
    char mel[taillec];
    char profession[taillec];
}Utilisateur;
struct Utilisateur BD[taille];

// Fonctions utiles pour gerer la structuration
void Remplissage(FILE*file);
void affichage_BD(int Max);
void Recherche_BD();
int Taille_BD();
#endif // FONCTIONS_H

