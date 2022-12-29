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
int Recherche_BD_Mel_lpl(char c[taillec],int i);
int Taille_BD();

// Fonction ajouter client
void ajouter_client(FILE*file);
void supprimer_entrees(char c[taille]);
//fonction modifier mel client
void Modifier_mel_client(FILE*file,int max);
// fonction supprimer client
void supprimer_client(FILE*file,int max);
//afficher les donnees des clients dont il manque des données
void afficher_clients_donnees_manquantes(FILE*file,int max);
//Fonction filtrer en fonctions de 2 champs
void filtrer_combiner_2_champs(FILE*file,char nom_champ1[taillec],char nom_champ2[taillec],char val_chaine1[taillec],char val_chaine2[taillec],int max);
#endif // FONCTIONS_H

