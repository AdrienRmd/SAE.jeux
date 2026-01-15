// structure biome generation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "generation_biome.h"
#include "other.h"
#include "file_manipulation.h"

// fonction qui genere les biomes avec la struc biome avec la struc Biome
/*typedef struct
{
    int id_biome;                    // Identifiant unique du biome
    char *description;               // Description détaillée
    float difficulty_biome;          // Coefficient de difficulté (entre 0.80 et 3.00)
    Temperature minimum_temperature; // Type de température (affecte les stats)
    Temperature maximum_temperature; // Type de température (affecte les stats)
    Meteo minimum_meteo;             // Type de météo (joue sur les stats)
    Meteo maximum_meteo;             // Type de météo (joue sur les stats)

} Biome;

Pour la Temperature et la Meteo, on tirera aléatoirement entre le minimum et le maximum
Id biome est dans le fichier fr/biomes/biome.txt
id se trouve a la ligne 1, puis la ligne 11, puis la ligne 21, sa va de 10 en 10 dans le fichier txt

Quand l'id est correct, sa suit cette structure c'est a dire premier id puis deuxieme ligne description etc

    int id_biome;                    // Identifiant unique du biome
    char *description;               // Description détaillée
    float difficulty_biome;          // Coefficient de difficulté (entre 0.80 et 3.00)
    Temperature minimum_temperature; // Type de température (affecte les stats)
    Temperature maximum_temperature; // Type de température (affecte les stats)
    Meteo minimum_meteo;             // Type de météo (joue sur les stats)
    Meteo maximum_meteo;             // Type de météo (joue sur les stats)

 */

// ouvrir le fichier biome.txt
// lire le fichier ligne par ligne jusqu'a trouver l'id_biome
// remplir la struc biome avec les informations du fichier

int generation_temperature(int minimum_temperature, int maximum_temperature)
{
    return random_number(minimum_temperature, maximum_temperature);
};

void generation_biome(Biome *biome, int id_biome, char *lang)
// la fonction retourne un biome
{

    int temperature, meteo;
    FILE *file;
    char line[50];
    int numero_ligne = 1;
    float difficulty_biome;

    // genere les valeurs aléatoires pour la temperature et la meteo

    // si la langue est francais ou anglais
    // ouvrir le fichier biome.txt correspondant
    // et lire les informations du biome
    if (strcmp(lang, "fr") == 0)
    {
        // chemin du fichier biome en francais
        file = fopen("fr/biomes/biome.txt", "r");
    }
    else
    {
        // chemin du fichier biome en anglais
        file = fopen("en/biomes/biome.txt", "r");
    }

    // verifier si le fichier a bien ete ouvert
    if (file == NULL)
    {
        printf("Error: Cannot open biome file\n");
        return;
    }

    // lire le fichier ligne par ligne jusqu'a trouver l'id_biome correspondant
    while (fgets(line, sizeof(line), file)) // la condition s'arrete a la fin du fichier
    {
        // verifier si la ligne correspond a l'id_biome (les IDs sont aux lignes 1, 11, 21...)
        if (numero_ligne == id_biome)
        {
            // remplir la struc biome avec les informations du fichier
            biome->id_biome = id_biome;
            fgets(line, sizeof(line), file); // lire la description

            // supprimer le retour a la ligne
            line[strcspn(line, "\n")] = '\0';  // strcspn trouve la position du premier '\n' et le remplace par '\0'
            biome->description = strdup(line); // strdup pour allouer de la memoire et copier la chaine
            fgets(line, sizeof(line), file);

            biome->difficulty_biome = atof(line); // atof pour convertir en float
            fgets(line, sizeof(line), file);

            biome->minimum_temperature = atoi(line); // atoi pour convertir en int
            fgets(line, sizeof(line), file);

            biome->maximum_temperature = atoi(line);
            fgets(line, sizeof(line), file);

            biome->minimum_meteo = atoi(line);
            fgets(line, sizeof(line), file);

            biome->maximum_meteo = atoi(line);

            break;
        }

        // passer a la ligne suivante en sautant de 10 en 10
        numero_ligne = numero_ligne + 10;

        // si on a depasse l'id recherche, on sort de la boucle
        if (numero_ligne > id_biome)
        {
            break;
        }

        // avancer dans le fichier jusqu'a la prochaine ligne d'ID
        for (int i = 0; i < 9 && fgets(line, sizeof(line), file); i++)
        {
            // sauter les 9 lignes suivantes
        }
    }

    fclose(file); // fermer le fichier
}
