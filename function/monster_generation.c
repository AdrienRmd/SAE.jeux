

#include "monster_generation.h"
#include <stdlib.h>
#include <string.h>

void set_monster(Monster *monster, const char *language, int monster_id)
{
    char monster_buffer[128];
    char filename[256];
    int current_line = 1;
    int found = 0;

    sprintf(filename, "%s/monstre/monster.txt", language);

    // Search for the monster by checking each block of 9 lines
    while (!found && current_line < 1000)
    {
        // Try to read ID from current position
        if (value_line(filename, current_line, monster_buffer, sizeof(monster_buffer)))
        {
            int found_id = atoi(monster_buffer);

            if (found_id == monster_id)
            {
                // Found the correct monster, load its data
                found = 1;
                monster->id = monster_id;

                // Load the remaining 8 lines of monster data
                value_line(filename, current_line + 1, monster_buffer, sizeof(monster_buffer));
                strcpy(monster->name, monster_buffer);

                value_line(filename, current_line + 2, monster_buffer, sizeof(monster_buffer));
                monster->hp = atoi(monster_buffer);

                value_line(filename, current_line + 3, monster_buffer, sizeof(monster_buffer));
                monster->att = atoi(monster_buffer);

                value_line(filename, current_line + 4, monster_buffer, sizeof(monster_buffer));
                monster->def = atoi(monster_buffer);

                value_line(filename, current_line + 5, monster_buffer, sizeof(monster_buffer));
                monster->dodge = atoi(monster_buffer);

                value_line(filename, current_line + 6, monster_buffer, sizeof(monster_buffer));
                monster->spe = atoi(monster_buffer);

                value_line(filename, current_line + 7, monster_buffer, sizeof(monster_buffer));
                monster->luck = atoi(monster_buffer);

                value_line(filename, current_line + 8, monster_buffer, sizeof(monster_buffer));
                monster->rarity = atoi(monster_buffer);
            }
            else
            {
                // Move to next monster (skip 9 lines, but check for empty line)
                current_line += 9;

                // Check if next line is empty (line number 10, 20, 30, etc.)
                char temp_buffer[128];
                if (value_line(filename, current_line, temp_buffer, sizeof(temp_buffer)))
                {
                    if (strlen(temp_buffer) == 0)
                    {
                        current_line++; // Skip the empty line
                    }
                }
            }
        }
        else
        {
            // Can't read from file, break
            break;
        }
    }
}