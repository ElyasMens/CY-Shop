#include "Header.h"

// Permet de rechercher si le pseudo saisi existe dans le fichier compte.txt (renvoie 1 si le pseudo saisi par l'utilisateur existe sinon -1)
int rech(char pseudo[]){
    struct client compte ;
    FILE *F;
    F=fopen("compte.txt","r");
    do{
        fscanf(F,"%s ;%s \n",compte.pseudo,compte.mdp);
        fflush(stdin);
        if(strcmp(compte.pseudo, pseudo) == 0){
            fclose(F);
            return 1;
        }
    }while(!feof(F));

    fclose(F);
    return -1;
}
// Permet de rechercher si le pseudo gérant saisi existe dans le fichier comptegerant.txt (renvoie 1 si le pseudo gérant saisi par l'utilisateur existe sinon -1)
int rechgerant(char pseudo[]){
    struct client compte ;
    FILE *F;
    F=fopen("comptegerant.txt","r");
    do{
        fscanf(F,"%s ;%s \n",compte.pseudo,compte.mdp);
        fflush(stdin);
        if(strcmp(compte.pseudo, pseudo) == 0){
            fclose(F);
            return 1;
        }
    }while(!feof(F));

    fclose(F);
    return -1;
}

// Permet de créer un compte
void creercompte(){
    struct client compte ;
    FILE*F;
    char pseudo[95];
    F=fopen("compte.txt","a");
    printf("\n Entrez un pseudo : ");
    scanf("%s",pseudo);
    fflush(stdin);
    while(rech(pseudo) == 1){
        printf("\n Ce pseudo existe deja :");
        printf("\n Entrez un nouveau pseudo : ");
        scanf("%s",pseudo);
    }
    strcpy(compte.pseudo, pseudo);
    printf("\n Entrez un mot de passe : ");
    scanf("%s",compte.mdp);
    fflush(stdin);
    fprintf(F,"%s ;%s \n",compte.pseudo,compte.mdp);
    fclose(F);
}


// Permet de modifier le pseudo d'un compte dans le fichier compte.txt
void modifierpseudo(){
    struct client compte ;
    char rep;
    char pseudo[100];
    char nvpseudo[100];
    char mdp[100];
    printf("Entrez le pseudo du compte a modifier \n\n");
    scanf("%s",pseudo);
    fflush(stdin);
    if(rech(pseudo) == 1){
        printf("Entrez votre mot de passe\n\n");
        scanf("%s",mdp);
        if(rechlogin(pseudo,mdp)==1){
            printf(" Voulez vous vraiment modifier votre pseudo o/n ?\n");
            scanf("%s",&rep);
            fflush(stdin);
            if( rep == 'o' || rep == 'O'){
                FILE* Fich,*F;
                F = fopen("compte.txt","r");
                Fich = fopen("tempcompte.txt","a");
                printf("Saisissez votre nouveau pseudo\n");
                scanf("%s",nvpseudo);
                if(rech(nvpseudo)!=1){
                    do{
                        fscanf(F,"%s ;%s \n",compte.pseudo,compte.mdp);
                        if(strcmp(pseudo, compte.pseudo) == 0){
                            fprintf(Fich,"%s ;%s \n",nvpseudo,compte.mdp);  // Modifier le pseudo demande
                        }
                        else{
                        fprintf(Fich,"%s ;%s \n",compte.pseudo,compte.mdp);
                    }}while(!feof(F));
                }
                else{
                    printf("Ce pseudo est deja utilise\n");
                }
                fclose(Fich);
                fclose(F);
                remove("compte.txt");
                rename("tempcompte.txt","compte.txt");
                printf("Modification de pseudo effectuee avec succes \n");
            }
        }
        else{
            printf("Le mot de passe saisi est incorrect\n\n");
        }
    }
    else{
        printf("\n Ce pseudo n'existe pas");
    }
}

// Permet de modifier le mot de passe d'un compte dans le fichier compte.txt
void modifiermdp(){
    struct client compte ;
    char rep;
    char pseudo[100];
    char mdp[100];
    char nvmdp[100];
    printf("Entrez le pseudo du compte dont vous souhaitez modifier le mot de passe \n\n");
    scanf("%s",pseudo);
    fflush(stdin);
    if(rech(pseudo) == 1){
        printf("Saisissez votre mot de passe actuel\n");
        scanf("%s",mdp);
        if(rechlogin(pseudo,mdp)==1){
            printf(" Voulez vous vraiment modifier votre mot de passe o/n ?\n");
            scanf("%s",&rep);
            fflush(stdin);
            if( rep == 'o' || rep == 'O'){
                FILE* Fich,*F;
                F = fopen("compte.txt","r");
                Fich = fopen("tempcompte.txt","a");
                printf("Saisissez votre nouveau mot de passe \n");
                scanf("%s",nvmdp);
                do{
                    fscanf(F,"%s ;%s \n",compte.pseudo,compte.mdp);
                    if(strcmp(pseudo, compte.pseudo) == 0){
                        fprintf(Fich,"%s ;%s \n",compte.pseudo,nvmdp);  // Modification du mot de passe du compte demande
                    }
                    else{
                    fprintf(Fich,"%s ;%s \n",compte.pseudo,compte.mdp);
                }}while(!feof(F));
                fclose(Fich);
                fclose(F);
                remove("compte.txt");
                rename("tempcompte.txt","compte.txt");
                printf("Modification effectuee avec succes \n");
        }
    }
    else{
        printf("Le mot de passe saisi est incorrect\n");
    }
    }
    else{
        printf("\n Ce pseudo n'existe pas");
    }
}

// Permet de supprimer un compte dans le fichier compte.txt
void supprimercompte() {
    struct client compte ;
    char rep;
    char pseudo[100];
    printf("Entrez le pseudo du compte à supprimer :\n\n");
    scanf("%s", pseudo);
    fflush(stdin);
    if (rech(pseudo) == 1) {
        printf("Voulez-vous vraiment supprimer ce compte ? (O/N)\n");
        scanf(" %c", &rep);
        fflush(stdin);
        if (tolower(rep) == 'o') {
            FILE* Fich, *F;
            F = fopen("compte.txt", "r");
            Fich = fopen("tempcompte.txt", "a");
            do {
                fscanf(F, "%s ;%s \n", compte.pseudo, compte.mdp);
                if (strcmp(pseudo, compte.pseudo) != 0) {
                    fprintf(Fich, "%s ;%s \n", compte.pseudo, compte.mdp);
                }
            } while (!feof(F));
            fclose(Fich);
            fclose(F);
            remove("compte.txt");
            rename("tempcompte.txt", "compte.txt");
            printf("Suppression effectuee avec succes.\n");
        }
    } else {
        printf("\nCe pseudo n'existe pas.\n");
    }
}

// Permet de se connecter à un compte déjà créé précédement via la fonction creercompte 
void login(){
    int choix;
    int choix2;
    int choix3;
    int choix4;
    FILE *F;
    struct client compte ;
    F=fopen("compte.txt","r");
    printf("\n Entrez votre pseudo :");
    scanf("%s",compte.pseudo);
    fflush(stdin);
    if(rech(compte.pseudo) == 1){
        printf("\n Ce pseudo existe :");
        printf("\n Entrez votre mot de passe : ");
        scanf("%s",compte.mdp);
        fflush(stdin);
        if(rechlogin(compte.pseudo,compte.mdp) == 1){
            system("clear");
            printf("Connexion reussie\n");
            derniersachats();
            printf("1 Voir stock\n");
            printf("2 Rechercher un fruit par nom\n");
            printf("3 Rechercher un fruit par numero de reference\n");
            do {
            printf("\n  Entrez votre choix : ");
            if(scanf("%d", &choix) != 1){
                printf("Saisie invalide. Veuillez entrer un chiffre entre 1 et 3.\n");
                choix = -1;
                scanf("%*s");
                
            }
            else if(choix<1 || choix>3){
                printf("Saisie invalide. Veuillez entrer un chiffre entre 1 et 3.\n");
            }
            }while (choix<1 || choix>3);
            switch(choix){
            case 1:
                voirstock();
                printf("\nVoulez vous acheter un produit ?\n");
                printf("1 Oui\n");
                printf("2 Non\n");
                do {
                printf("\n  Entrez votre choix : ");
                if(scanf("%d", &choix2) != 1){
                    printf("Saisie invalide. Veuillez entrer un chiffre entre 1 et 2.\n");
                    choix = -1;
                    scanf("%*s");
                }
                else if(choix2<1 || choix2>2){
                    printf("Saisie invalide. Veuillez entrer un chiffre entre 1 et 2.\n");
                }
                }while (choix2<1 || choix2>2);
                switch(choix2){
                    case 1:
                        achat();
                        break;
                    case 2:
                        printf("en cours");
                }
                break;
            case 2:{
                char Nom_recherche[50];
                printf("Entrez le nom du fruit : ");
                scanf("%49s", Nom_recherche);
                rechercheNom(Nom_recherche);
                printf("Voulez vous acheter un produit ?\n");
                printf("1 Oui\n");
                printf("2 Non\n");
                do {
                printf("\n  Entrez votre choix : ");
                if(scanf("%d", &choix3) != 1){
                    printf("Saisie invalide. Veuillez entrer un chiffre entre 1 et 2.\n");
                    choix = -1;
                    scanf("%*s");
                }
                else if(choix3<1 || choix3>2){
                    printf("Saisie invalide. Veuillez entrer un chiffre entre 1 et 2.\n");
                }
                }while (choix3<1 || choix3>2);
                switch(choix3){
                    case 1:
                        achat();
                        break;
                    case 2:
                        printf("en cours");
                        break;
                }
                break;
            }
            case 3:
                {
                int ref_recherche;
                printf("Entrez le numero de reference du fruit : ");
                scanf("%d", &ref_recherche);
                rechercheRef(ref_recherche);
                printf("\nVoulez vous acheter un produit ?\n");
                printf("1 Oui\n");
                printf("2 Non\n");
                do {
                printf("\n  Entrez votre choix : ");
                if(scanf("%d", &choix4) != 1){
                    printf("Saisie invalide. Veuillez entrer un chiffre entre 1 et 2.\n");
                    choix = -1;
                    scanf("%*s");
                }
                else if(choix4<1 || choix4>2){
                    printf("Saisie invalide. Veuillez entrer un chiffre entre 1 et 2.\n");
                }
                }while (choix4<1 || choix4>2);
                switch(choix4){
                    case 1:
                        achat();
                        break;
                    case 2:
                        printf("en cours");
                        break;
                }   
                break;}
            }
        }
        else {
            printf("\n Mot de passe incorrect \n");
        }
    }
    else{
        printf("\n Ce pseudo n'existe pas\n");
    }
    fclose(F);
}

// Permet de comparer le pseudo et le mot de passe saisi par l'utilisateur au contenu du fichier compte.txt (renvoie 1 si une ligne correspond sinon -1)
int rechlogin(char pseudo[], char mdp[]){
    FILE *F;
    struct client compte ;

    F = fopen("compte.txt", "r");
    if (F == NULL) {
        printf("Un probleme sur l'ouverture du fichier compte.txt .\n");
        return -1;
    }

    while (fscanf(F, "%99s ;%99s", compte.pseudo, compte.mdp) == 2) {
        if (strcmp(compte.pseudo, pseudo) == 0 && strcmp(compte.mdp, mdp) == 0) {
            fclose(F);
            return 1;
        }
    }

    fclose(F);
    return -1;
}
// Permet de comparer le pseudo et le mot de passe du gérant saisi par l'utilisateur au contenu du fichier comptegerant.txt (renvoie 1 si une ligne correspond sinon -1)
int rechlogingerant(char pseudo[], char mdp[]){
    FILE *F;
    struct client compte ;

    F = fopen("comptegerant.txt", "r");
    if (F == NULL) {
        printf("Un probleme sur l'ouverture du fichier compte.txt .\n");
        return -1;
    }

    while (fscanf(F, "%99s ;%99s", compte.pseudo, compte.mdp) == 2) {
        if (strcmp(compte.pseudo, pseudo) == 0 && strcmp(compte.mdp, mdp) == 0) {
            fclose(F);
            return 1;
        }
    }

    fclose(F);
    return -1;
}

// Permet de créer un compte gérant 
void creercomptegerant(){
    FILE *F;
    char pseudo[100];
    struct client compte ;
    F=fopen("comptegerant.txt","a");
    printf("\n Entrez le pseudo : ");
    scanf("%s",pseudo);
    fflush(stdin);
    while(rech(pseudo) == 1){
        printf("\n Ce pseudo existe deja :");
        printf("\n Entrez un nouveau pseudo : ");
        scanf("%s",pseudo);
    }
    strcpy(compte.pseudo, pseudo);
    printf("\n Entrez le mot de passe : ");
    scanf("%s",compte.mdp);
    fflush(stdin);
    fprintf(F,"%s ;%s \n",compte.pseudo,compte.mdp);
    fclose(F);
}

// Permet de se connecter à un compte gérant déjà créé précédement via la fonction creercompte 
void logingerant(){
    const char* nomFichier = "StockFruits.txt";
    char choix1;
    char choix2;
    FILE *F;
    struct client compte;
    F=fopen("comptegerant.txt","r");
    printf("\n Entrez votre pseudo :");
    scanf("%s",compte.pseudo);
    fflush(stdin);
    if(rechgerant(compte.pseudo) == 1){
        printf("\n Ce pseudo existe :");
        printf("\n Entrez votre mot de passe : ");
        scanf("%s",compte.mdp);
        fflush(stdin);
        if(rechlogingerant(compte.pseudo,compte.mdp) == 1){
            printf("Connexion reussie\n");
            printf("1 Voir stock\n");
            printf("2 Rechercher un fruit par nom\n");
            printf("3 Rechercher un fruit par numero de reference\n");
            printf("4 Ajouter un produit \n");
            printf("\n  Entrez votre choix : ");
            scanf("%c", &choix1);
            switch(choix1){
            case 1:
                trierFichierParQuantite(nomFichier);
                voirstock();
                printf("1 Ajouter du Stock \n");
                printf("2 Quitter \n");
                switch(choix2){
                    case 1:
                        printf("Saisissez le nom du fruit dont vous voulez modifiez la stock\n");
                        break;

                }
                break;
            case 2:{
                char Nom_recherche[50];
                printf("Entrez le nom du fruit : ");
                scanf("%49s", Nom_recherche);
                rechercheNom(Nom_recherche);
                break;}
            case 3:
                {
                int ref_recherche;
                printf("Entrez le numero de reference du fruit : ");
                scanf("%d", &ref_recherche);
                rechercheRef(ref_recherche);
                break;}
            case 4:
                //ajoutFruits();
                break;
            default : 
                    printf("Saisie invalide.\n Veuillez entrer un chiffre entre 1 et 5.\n");
                        scanf("%*s"); //ignorer les caractère supplémentaire
                        choix1 = '0';
                        break;
            }   
        }
    }
    else if(rechgerant(compte.pseudo) == -1){
        printf("\n Ce pseudo n'existe pas\n");
    }
    fclose(F);
}


