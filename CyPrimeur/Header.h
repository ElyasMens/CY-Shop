#ifndef HEADER_H
#define HEADER_H
#endif 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <unistd.h>

#define STOCKFRUITPET 2
#define STOCKFRUITMOY 3
#define STOCKFRUITGRA 10
#define STOCKFRUITPETQUANTITEMAX 100
#define STOCKFRUITMOYQUANTITEMAX 50
#define STOCKFRUITGRAQUANTITEMAX 25

#define MAX_STOCK_SIZE 500

struct client {
    char pseudo[95];
    char mdp[30];
};

struct fruit {
    char nom[50];
    int taille;
    float prix;
    int quantite;
    int numeroref;
};




// fonction Account.c

int rech(char pseudo[]);
int rechgerant(char pseudo[]);
void creercompte();
void modifierpseudo();
void modifiermdp();
void supprimercompte();
void login();
int rechlogin(char pseudo[], char mdp[]);
int rechlogingerant(char pseudo[], char mdp[]);
void creercomptegerant();
void logingerant();

// fonction stockage.c

void sommeQuantiteStock(int taille, int* sommeStock);
void voirstock();
//void ajoutFruits();
int rechercheNom(char Nom[]);
void rechercheRef(int Ref);
int panier(char* p_nomProduit);
int comparerQuantiteCroissante(const void* a, const void* b);
void trierFichierParQuantite(const char* nomFichier);
int nbrL(FILE *file);
void achat();
void derniersachats();
int obtenirTailleStock(const char* nomFichier);
void remplirStock(char stock[], struct fruit *tailleStock);
//void sommeStockFctDeTaille(int* taille, int* sommeStock)
//void quantiteDuFruit(fruit* f)
//void nouveauFruit();

// fonction Visuel.c
void includeFile(const char* fichier);