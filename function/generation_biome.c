// Biome structure generation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "generation_biome.h"
#include "other.h"
#include "file_manipulation.h"

// Function that generates biomes with the Biome structure
/*typedef struct
{
    int id_biome;                    // Unique biome identifier
    char *description;               // Detailed description
    float difficulty_biome;          // Difficulty coefficient (between 0.80 and 3.00)
    Temperature minimum_temperature; // Temperature type (affects stats)
    Temperature maximum_temperature; // Temperature type (affects stats)
    Meteo minimum_meteo;             // Weather type (affects stats)
    Meteo maximum_meteo;             // Weather type (affects stats)

} Biome;

For Temperature and Weather, we will randomly draw between minimum and maximum
Biome ID is in the file fr/biomes/biome.txt
ID is found at line 1, then line 11, then line 21, it goes by 10 in the txt file

When the ID is correct, it follows this structure meaning first ID then second line description etc

    int id_biome;                    // Unique biome identifier
    char *description;               // Detailed description
    float difficulty_biome;          // Difficulty coefficient (between 0.80 and 3.00)
    Temperature minimum_temperature; // Temperature type (affects stats)
    Temperature maximum_temperature; // Temperature type (affects stats)
    Meteo minimum_meteo;             // Weather type (affects stats)
    Meteo maximum_meteo;             // Weather type (affects stats)

 */

// Open the biome.txt file
// Read the file line by line until finding the id_biome
// Fill the biome structure with information from the file

int generation_temperature(int minimum_temperature, int maximum_temperature)
{
    return random_number(minimum_temperature, maximum_temperature);
};
