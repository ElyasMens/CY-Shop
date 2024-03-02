#include "Header.h"

void includeFile(const char* fichier) {
    FILE* file = fopen(fichier, "r"); // Ouvrir le fichier en mode lecture

    if (file != NULL) {
        int caractere;

        // Lire et afficher chaque caractère du fichier
        while ((caractere = fgetc(file)) != EOF) {
            printf("%c", caractere);
        }

        fclose(file); // Fermer le fichier
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }
}