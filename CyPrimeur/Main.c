#include "Header.h"

int main(){
    int choix1, choix2;
    char rep;
    //struct fruit stock[MAX_STOCK_SIZE];
    do{
        system("clear");
        const char* fichier = "logo.txt";
        includeFile(fichier);
        const char* nomFichier = "StockFruits.txt";
        int tailleStock = obtenirTailleStock(nomFichier);
        if (tailleStock >= 0) {
        //printf("La taille du stock est de %d.\n", tailleStock);// voir la taille du stock
        }                          
        printf("\nMenu\n");                        
        printf("1 Creer un compte \n");           
        printf("2 Supprimer compte \n");         
        printf("3 Connexion \n");               
        printf("4 Modifier votre pseudo\n");
        printf("5 Modifier votre mot de passe\n");
            do {
            printf("\n  Entrez votre choix : ");
            if(scanf("%d", &choix1) != 1){
                printf("Saisie invalide. Veuillez choisir entre 1 et 6.\n");
                choix1 = -1;
                scanf("%*s");
                
            }
            else if(choix1<1 || choix1>6){
                printf("Saisie invalide. Veuillez choisir entre 1 et 6.\n");
            }
            }while (choix1<1 || choix1>6);               
            switch(choix1){
                case 1:
                    creercompte();
                    break;
                case 2:
                    supprimercompte();
                    break;
                case 3:
                    login();
                    break;
                case 4:
                    modifierpseudo();
                    break;
                case 5:
                    modifiermdp();
                    break;
                case 6:
                    printf("1 Creer compte gerant\n");
                    printf("2 Se connecter a un compte gerant\n");
                        do {
                        printf("\n  Entrez votre choix : ");
                        if(scanf("%d", &choix2) != 1){
                            printf("Saisie invalide. Veuillez choisir entre 1 et 2.\n");
                            choix2 = -1;
                            scanf("%*s");
                        
                        }
                        else if(choix2<1 || choix2>2){
                            printf("Saisie invalide. Veuillez choisir entre 1 et 2.\n");
                        }
                        }while (choix2<1 || choix2>2); 
                        switch (choix2){
                        case 1:
                            creercomptegerant();
                            break;
                        case 2:
                            logingerant();
                            break;
                        default :;
                        }
                default :;
            }
        printf(" \n Voulez-vous continuer O/N : ");
        scanf(" %c",&rep);
        fflush(stdin);
    }while(tolower(rep) == 'o');
    return 0;
}
