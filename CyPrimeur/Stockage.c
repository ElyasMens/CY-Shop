#include "Header.h"


void sommeQuantiteStock(int taille, int* sommeStock) { //somme les quantite en fonction de leur taille
    FILE *StockFruits;
    struct fruit f;
    *sommeStock = 0;

    StockFruits = fopen("StockFruits.txt", "r");
    if (StockFruits == NULL) {
        printf("Probleme pour lire le fichier stock de fruits.\n");
        
    }

    while (fscanf(StockFruits, "%49s; %d; %f; %d; %d\n", f.nom, &f.taille, &f.prix, &f.quantite, &f.numeroref) != EOF) {
        if (f.taille == taille) {
            *sommeStock += f.quantite;
        }
    }

    fclose(StockFruits);
}

/*
void nouveauFruit(){
    FILE *StockFruits;
    fruit f;
    int nbFruitActuelFctDeTaille=0; //stock en fct de la tailee
    affichage(); 
    printf("Ajout d un nouveau produit");
    affichage();
  //---------------------------------------------------//
 //            ouverture du fichier StockFruits       //
//---------------------------------------------------//
    StockFruits = fopen("StockFruits.txt", "a");
    if (StockFruits == NULL) {
        printf("Erreur lors de l'ouverture du StockFruits.\n");
        return;
    }
   //---------------------------------------------------//
  // Saisie des caractéristiques du fruit a rajouter   //
 //---------------------------------------------------//
//                    nom du fruit                   //   

    
    printf("    \nEntrez le nom du fruit : ");
    scanf("%49s", f.nom);
   
  //---------------------------------------------------//
 //                 taille du fruit                   //
    do{
        printf("    \nEntrez la taille du fruit.    \n1.Petit 2.Moyen 3.Grand : ");
        if(scanf("%d",&f.taille)!=1){
        f.taille = -1;
        scanf("%*s");
        printf("Saisie invalide. Veuillez renseigner une taille entre 1 et 3.\n");
        }else if(f.taille < 1 || f.taille >3){
            printf("Veuillez renseigner une taille entre 1 et 3.\n");
        }
 
    }while(f.taille < 1 || f.taille >3);
 //---------------------------------------------------------------------------------------------------------//    
//renvoie au programme si L emplacement pour les fruits d une certaine taille est atteinte                 //
    sommeStockFctDeTaille(&(f.taille), &nbFruitActuelFctDeTaille );
    switch (f.taille){
    case 1 :
        if (nbFruitActuelFctDeTaille >= STOCKFRUITPET){
            printf("Le stockage maximal pour les fruits de petite taille a ete atteint (%d)", STOCKFRUITPET);
            printf("\nRetour au menu gerant");
            attente();
            main(); //logingerant();
        }
        
    case 2 :
        if (nbFruitActuelFctDeTaille >= STOCKFRUITMOY){
            printf("Le stockage maximal pour les fruits de petite taille a ete atteint (%d)", STOCKFRUITMOY);
            printf("\nRetour au menu gerant");        
            attente();
            main(); //logingerant();
        }
        
    case 3 :
        if (nbFruitActuelFctDeTaille >= STOCKFRUITMOY){
            printf("Le stockage maximal pour les fruits de petite taille a ete atteint (%d)", STOCKFRUITGRA);
            printf("\nRetour au menu gerant");    
            attente();
            main(); //logingerant();
        }
           
    default:
        break;
    }
 //---------------------------------------------------//
//                  prix du fruit                    //

    do {
        printf("    \nEntrez le prix du fruit %s: ", f.nom);
        if(scanf("%2f", &f.prix)!=1.00){
            f.prix = -1;
            scanf("%*s");
            printf("Saisie invalide. Veuillez renseigner un prix superieur a 10 centmes.\n");
        }else if(f.prix<0.10){
            printf("Saisie invalide. Veuillez renseigner un prix superieur a 10 centmes.\n");
        }
    }while(f.prix < 0.10);
    
 //---------------------------------------------------//
//                 quantité du fruit                 //

   quantiteDuFruit(&f);
   
 //---------------------------------------------------//
//                 référence du fruit                //
    do{
        printf("    \nEntrez le numero de reference du fruit : ");
        if(scanf("%d", &f.numeroref)!=1 ){
            scanf("%*s");
        printf("Saisie invalide. Veuillez renseigner un numero de reference valide.\n");

        }
        else if(f.numeroref<1){
            printf("Veuillez renseigner un numero de reference positif.\n");
            
        }
    }while(f.numeroref <1);
   //---------------------------------------------------//
  //            remplissage du fichier fruit           //
 //     nom; taille; prix; quantite; numeroref        //
//---------------------------------------------------//
        fprintf(StockFruits, "%s; %d; %.2f; %d; %d\n", f.nom, f.taille, f.prix, f.quantite, f.numeroref);
        fclose(StockFruits);

        printf("Les informations ont ete enregistrees dans le fichier fruits.\n");
        return;
    }

*/

// Permet de rechercher un fruit et ses informations par son nom (qui est saisi par l'utilisateur) dans le fichier StockFruits.txt (renvoie 1 si le fruit existe dans le fichier sinon 0)
int rechercheNom(char Nom[]) {
    FILE* F;
    F = fopen("StockFruits.txt", "r");
    if (F == NULL) {
        printf("Le fichier StockFruits.txt ne peut pas etre ouvert.\n");  
    }

    char ligne[100]; // Variable pour stocker une ligne du fichier
    int found = 0; // Variable pour indiquer si le fruit recherché a été trouvé
    while (fgets(ligne, sizeof(ligne), F) != NULL) {
        char nom[50];
        sscanf(ligne, "%[^;]", nom);
        if (strcmp(nom, Nom) == 0) {
            printf("%s\n", ligne);
            return 1;
        }
    }
    if (!found) {
        printf("Le fruit '%s' n'a pas ete trouve dans le fichier.\n", Nom);
    }
    fclose(F);
    return 0;
}

// Permet de rechercher un fruit et ses informations par son numéro de référence (qui est saisi par l'utilisateur) dans le fichier StockFruits.txt (renvoie 1 si le fruit existe dans le fichier sinon 0)
void rechercheRef(int Ref) {
    FILE* F;
    F = fopen("StockFruits.txt", "r");
    if (F == NULL) {
        printf("Le fichier StockFruits.txt ne peut pas etre ouvert.n");    
        return;
    }

    char ligne[100]; // Variable pour stocker une ligne du fichier
    int found = 0; // Variable pour indiquer si le fruit recherché a été trouvé

    while (fgets(ligne, sizeof(ligne), F) != NULL) {
        int ref;
        sscanf(ligne, "%*[^;];%*[^;];%*[^;];%*[^;];%d", &ref);
        if (Ref == ref) {
            printf("%s\n", ligne);
            found = 1; // Le fruit a été trouvé
            break; // Sortie de la boucle puisque le fruit a été trouvé
        }
    }

    fclose(F);

    if (!found) {
        printf("Le fruit de numero de reference '%d' n'a pas ete trouve dans le fichier.\n", Ref);
    }
}


// Permet d'afficher les 3 derniers achats de l'utilisateur au pseudo saisi par l'utilisateur en afficahant les 3 dernières lignes du fichier au nom de l'utilisateur créé dans la fonction panier 
void derniersachats() {
    FILE* F;
    char pseudo[100];
    char lignes[3][100];
    int j;
    int i = 0;
    
    printf("Saisir le pseudo de l'utilisateur connecte :\n ");
    scanf("%s", pseudo);
    
    char nomFichier[100];
    strcpy(nomFichier, pseudo);  // Copier le pseudo dans nomFichier
    
    size_t pseudoLen = strlen(pseudo);
    if (pseudoLen > sizeof(nomFichier) - 5) {
        pseudoLen = sizeof(nomFichier) - 5;  // S'assurer que pseudoLen ne dépasse pas la taille de nomFichier - 5
    }
    
    strncpy(nomFichier + pseudoLen, ".txt", 5);  // Ajouter l'extension ".txt" à la fin de nomFichier
    
    char contenu[1000];
    
    // Vérifier si le fichier existe avant de l'ouvrir
    if (access(nomFichier, F_OK) != -1) {
        F = fopen(nomFichier, "r");
        
        char ligne[100];
        while (fgets(ligne, sizeof(ligne), F) != NULL) {
            strcpy(lignes[i % 3], ligne);
            i++;
        }
        
        fclose(F);
        
        printf("\nVos 3 derniers achats :\n\n");
        for (j = 0; j < 3; j++) {
            printf("%s\n", lignes[(i - j - 1) % 3]);
        }
    } else {
        F = fopen(nomFichier, "w");
        if (F != NULL) {
            printf("Le fichier %s a été créé.\n", nomFichier);
            fclose(F);
        } else {
            printf("Impossible de créer le fichier %s.\n", nomFichier);
        }
    }
}

// Permet de créer un fichier panier individuel qui contient le nom du fruit saisi par l'utilisateur ainsi que la qunatité saisie. Sert également à l'affichage des 3 derniers achats de l'utilisateur et dans la fonction achat (par le renvoie de la quantité et du nom du fruit saisis par l'utilisateur)
int panier(char* p_nomProduit){
    FILE *F;
    char pseudo[95];
    int quantite;
    printf("Pseudo de l'utilisateur connecte : ");
    scanf("%s",pseudo);
    char nomFichier[100];
    sprintf(nomFichier, "%s.txt", pseudo);  // Create the filename with the pseudo
    char contenu[1000];
    F = fopen(nomFichier, "a");  // Open the file in write mode
    if (F == NULL) {
        printf("\nErreur lors de la creation du fichier.");
        return -1;
    }
    
    // Ajouter un nouvel élément au panier
    char nouvelElement[100];
    printf("Ajouter un nouveau produit au panier : ");
    scanf("%s",nouvelElement);
    printf("Combien en voulez vous ?\n");
    scanf("%d",&quantite);

    // Écrire le nouvel élément dans le fichier panier
    fprintf(F, "%s ; %d ;\n", nouvelElement,quantite);
    printf("Le produit a ete ajoute au panier de l'utilisateur '%s'.\n", pseudo);
    fclose(F);
    strcpy(p_nomProduit, nouvelElement);
    return quantite;
}



// Fonction de comparaison pour le tri
int comparerQuantiteCroissante(const void* a, const void* b) {
    const struct fruit* fruitA = (const struct fruit*)a;
    const struct fruit* fruitB = (const struct fruit*)b;
    return fruitA->quantite - fruitB->quantite;
}


// Permet de trier le fichier StockFruits par ordre croissant de quantité en stock (Pour afficher les 5 Fruits avec le moins de stock dans le mode gérant)
void trierFichierParQuantite(const char* fichier) {
    FILE* fichierPtr = fopen(fichier, "r");
    if (fichierPtr == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    FILE* fichierTemp = fopen("temp.txt", "w");
    if (fichierTemp == NULL) {
        printf("Erreur lors de la création du fichier temporaire.\n");
        fclose(fichierPtr);
        return;
    }

    char ligne[256];
    struct fruit tableauFruits[100]; // Supposons que nous ne dépasserons pas 100 structures

    int i = 0;
    while (fgets(ligne, sizeof(ligne), fichierPtr)) {
        char* token = strtok(ligne, ";");
        strcpy(tableauFruits[i].nom, token);

        token = strtok(NULL, ";");
        tableauFruits[i].taille = atoi(token);

        token = strtok(NULL, ";");
        tableauFruits[i].prix = atof(token);

        token = strtok(NULL, ";");
        tableauFruits[i].quantite = atoi(token);

        token = strtok(NULL, ";");
        tableauFruits[i].numeroref = atoi(token);

        i++;
    }

    fclose(fichierPtr);

    qsort(tableauFruits, i, sizeof(struct fruit), comparerQuantiteCroissante);

    for (int j = 0; j < i; j++) {
        fprintf(fichierTemp, "%s;%d;%.2f;%d;%d\n", tableauFruits[j].nom, tableauFruits[j].taille,
                tableauFruits[j].prix, tableauFruits[j].quantite, tableauFruits[j].numeroref);
    }

    fclose(fichierTemp);

    remove(fichier);               // Supprimer l'ancien fichier
    rename("temp.txt", "StockFruits.txt");   // Renommer le fichier temporaire

    printf("Fichier trie avec succes.\n");
}

// Permet de voir le stock càd le contenu du fichier StockFruits.txt
void voirstock(){
    FILE* F;
    char caractere;

    F = fopen("StockFruits.txt", "r");
    if (F == NULL) {
        printf("Un problème est survenu lors de l'ouverture du fichier StockFruits .\n");
        return;
    }

    while ((caractere = fgetc(F)) != EOF) {
        printf("%c", caractere);
    }

    fclose(F);
}



// Permet l'achat d'un fruit dont le nom et la quantité désirée ont été saisis dans la fonction panier (Modifie la quantité restante en stock après achat en lui retirant la valeur saisie dans la fonction panier)
void achat() {
    FILE *fichier = fopen("StockFruits.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (fichier == NULL || temp == NULL) {
        printf("Erreur lors de l'ouverture des fichiers.\n");
        return;
    }

    struct fruit fruits[100];
    int numFruits = 0;

    char ligne[100];
    while (fgets(ligne, sizeof(ligne), fichier)) {
        sscanf(ligne, "%[^;];%d;%f;%d;%d", fruits[numFruits].nom, &fruits[numFruits].taille,
               &fruits[numFruits].prix, &fruits[numFruits].quantite, &fruits[numFruits].numeroref);
        numFruits++;
    }

    fclose(fichier);

    char nomFruit[50];
    int quantite = panier(nomFruit);
    int fruitTrouve = 0;
    for (int i = 0; i < numFruits; i++) {
        if (strcmp(fruits[i].nom, nomFruit) == 0) {
            if (fruits[i].quantite >= quantite) {
                fruits[i].quantite -= quantite;
                fruitTrouve = 1;
            } else {
                printf("Quantite en stock insuffisante.\n");
                fruitTrouve = 1;
            }
            break;
        }
    }

    if (!fruitTrouve) {
        printf("Fruit introuvable.\n");
        return;
    }

    for (int i = 0; i < numFruits; i++) {
        fprintf(temp, "%s;%d;%.2f;%d;%d\n", fruits[i].nom, fruits[i].taille,
                fruits[i].prix, fruits[i].quantite, fruits[i].numeroref);
    }

    fclose(temp);

    remove("StockFruits.txt");
    rename("temp.txt", "StockFruits.txt");

    printf("Achat effectue avec succes.\n");
}



int obtenirTailleStock(const char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return -1;  // Valeur d'erreur
    }
    
    struct fruit stock[MAX_STOCK_SIZE];
    int tailleStock = 0;
    
    while (fscanf(fichier, "%49[^;];%d;%f;%d;%d\n",
                  stock[tailleStock].nom,
                  &stock[tailleStock].taille,
                  &stock[tailleStock].prix,
                  &stock[tailleStock].quantite,
                  &stock[tailleStock].numeroref) == 5) {
        tailleStock += stock[tailleStock].quantite * stock[tailleStock].taille; // Calcul de la taille du stock
        
        // Incrémentation de tailleStock uniquement si la quantité est supérieure à 0
        if (stock[tailleStock].quantite > 0) {
            tailleStock++;
        }
    }
    
    fclose(fichier);

    return tailleStock; // Ajout du retour de la valeur calculée de la taille du stock
}
   

/*void remplirStock(char stock[], struct fruit *tailleStock) {
    if (*tailleStock >= MAX_STOCK_SIZE) {
        printf("Le stock est plein. Impossible d'ajouter de nouveaux fruits.\n");
        return;
    }
    struct fruit nouvelElement;
    int quantiteMax= MAX_STOCK_SIZE;
    int quantiteAjoutee;
    int tailleFruit;
    printf("taille");
    scanf("%d", &tailleFruit);

    switch (tailleFruit) {
        case 1:
            quantiteAjoutee = 1;
            break;
        case 2:
            quantiteAjoutee = 2;
            break;
        case 3:
            quantiteAjoutee = 3;
            break;
        default:
            printf("Type de fruit invalide.\n");
            return;
    }

    if ((*tailleStock + quantiteAjoutee) > quantiteMax) {
        quantiteAjoutee = quantiteMax - *tailleStock;
    }

    for (int i = 0; i < quantiteAjoutee; i++) {
        

        printf("Nom du fruit %d : ", *tailleStock + i + 1);
        scanf("%s", nouvelElement.nom);

        nouvelElement.taille = tailleFruit * quantiteAjoutee;

        printf("Prix du fruit %d : ", *tailleStock + i + 1);
        scanf("%f", &nouvelElement.prix);

        nouvelElement.quantite = 1;

        printf("Numero de reference du fruit %d : ", *tailleStock + i + 1);
        scanf("%d", &nouvelElement.numeroref);

        stock[*tailleStock] = nouvelElement;
    }

    *tailleStock += quantiteAjoutee;

    printf("Les fruits ont ete ajoutes avec succes au stock.\n");
}
*/