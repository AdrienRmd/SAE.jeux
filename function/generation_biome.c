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

int generation_temperature(int minimum_temperature, int maximum_temperature)
{
    return random_number(minimum_temperature, maximum_temperature);
};

void generation_biome(Biome *biome, int id_biome, char description, float difficulty_biome,
                      Temperature minimum_temperature, Temperature maximum_temperature,
                      Meteo minimum_meteo, Meteo maximum_meteo, char *lang)
{
    int temperature, meteo;
    FILE *file;
    char line[50];
    int numero_ligne = 1;

    // genere les valeurs aléatoires pour la temperature et la meteo
    temperature = generation_temperature(minimum_temperature, maximum_temperature);
    meteo = generation_meteo(minimum_meteo, maximum_meteo);

    // si la langue est francais ou anglais
    // ouvrir le fichier biome.txt correspondant
    // et lire les informations du biome
    if (lang == "FR")
    {
        // chemin du fichier biome en francais
        file = fopen("fr/biomes/biome.txt", "r");
    }
    else
    {
        // chemin du fichier biome en anglais-6
        file = fopen("en/biomes/biome.txt", "r");
    }

    // lire le fichier ligne par ligne jusqu'a trouver l'id_biome correspondant }
    while (fgets(line, sizeof(line), file))
    {
        // verifier si la ligne correspond a l'id_biome
        if (numero_ligne == id_biome - 1)
        {
            // remplir la struc biome avec les informations du fichier
            biome->id_biome = id_biome;
            fgets(line, sizeof(line), file);

            biome->description = strdup(line);
            fgets(line, sizeof(line), file);

            biome->difficulty_biome = atof(line);
            fgets(line, sizeof(line), file);

            biome->minimum_temperature = atoi(line);
            fgets(line, sizeof(line), file);

            biome->maximum_temperature = atoi(line);
            fgets(line, sizeof(line), file);

            biome->minimum_meteo = atoi(line);
            fgets(line, sizeof(line), file);

            biome->maximum_meteo = atoi(line);

            break;
        }

        numero_ligne = numero_ligne + 10;
    }
}

// la fonction retourne un biome