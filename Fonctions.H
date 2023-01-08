#ifndef FONCTIONS_H
#define FONCTIONS_H
#define taille 900
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

int max;
// Fonctions utiles pour gerer la structuration
void Remplissage_BD(FILE*file);
void affichage_BD(char nom_fic[taillec]);
int Recherche_BD_Mel_lpl(char c[taillec],int i);
void permute(Utilisateur *a,Utilisateur *b);
void supprimer_entrees(char c[taillec]);
int lire(char *chaine,int longeur);
void Sauvegarder(char nom_fic[taillec]);

// Fonctions Gheribi Abd-el-rahmen
void Modifier_mel_client(char nom_fic[taillec],char mel_p[taillec],char nv_mel_p[taillec]);
void supprimer_client(char nom_fic[taillec],char mel_p[taillec]);
void afficher_clients_donnees_manquantes(char nom_fic[taillec]);
void filtrer_combiner_2_champs(char nom_fic[taillec],char nom_champ1[taillec],char nom_champ2[taillec],char val_chaine1[taillec],char val_chaine2[taillec]);


//Fonctions Jeremy
void ajouter_client(char nom_fic[taillec], char* nom, char* prenom, char* code_postal, char* ville, char* telephone, char* mel, char* profession);
void modifier_autres_que_mel(char nom_fic[taillec],char* mel, char* nom_champ, char* val_chaine);
void trie_client_par_nom(char nom_fic[taillec]);
void filtrer_un_champ(char nom_fic[taillec],char* nom_champ, char* val_chaine);
#endif // FONCTIONS_H

