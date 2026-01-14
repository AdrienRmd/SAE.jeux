# Système de Monstres - The Final Dawn

## Structure des Données

```c
/**
 * @brief Monster structure representing game enemies
 * 
 * This structure contains all information about monsters including
 * combat statistics and rarity classification.
 */
typedef struct {
    int id;         // Global unique ID (1, 2, 3, 4...)
    char name[40];  // Monster name
    int pv;         // Health points
    int att;        // Attack power
    int def;        // Defense value
    int dodge;      // Dodge chance
    int spe;        // Special/speed
    int luck;       // Luck stat
    int rarity;     // 0=common, 1=rare, 2=very rare, 3=epic, 4=legendary, 5=mythic
    int table_loot; // Keep for backward compatibility
} Monster;
```

## Système de Rareté

### Niveaux de Rareté
- **0** : Commun (Common) - Monstres de base, faibles récompenses
- **1** : Rare (Rare) - Monstres modérément puissants
- **2** : Très Rare (Very Rare) - Monstres difficiles à trouver
- **3** : Épique (Epic) - Monstres très puissants
- **4** : Légendaire (Legendary) - Monstres exceptionnels
- **5** : Mythique (Mythic) - Monstres extrêmement rares et puissants

### Distribution par Biome
Chaque biome contient **3 monstres uniques** avec des niveaux de rareté variés :
- **Biomes faciles** : Principalement des monstres communs et rares
- **Biomes moyens** : Mix équilibré de raretés
- **Biomes difficiles** : Monstres rares et épiques
- **Biomes spéciaux** : Monstres épiques, légendaires et mythiques

## Progression des Monstres

### Principe Fondamental
Plus l'ID du monstre est élevé, plus le monstre est fort. Cette progression assure une difficulté croissante cohérente dans le jeu.

### Répartition des IDs (75 monstres totaux)

#### Biomes Faciles (IDs 1-15)
- **Plaine** : Monstres 1, 2, 3
- **Désert** : Monstres 4, 5, 6
- **Champ de fleur** : Monstres 7, 8, 9
- **Prairie** : Monstres 10, 11, 12
- **Banquise** : Monstres 13, 14, 15

#### Biomes Moyens (IDs 16-30)
- **Lac** : Monstres 16, 17, 18
- **Marais** : Monstres 19, 20, 21
- **Canyon** : Monstres 22, 23, 24
- **Jungle** : Monstres 25, 26, 27
- **Mer** : Monstres 28, 29, 30

#### Biomes Difficiles (IDs 31-45)
- **Prairie volcanique** : Monstres 31, 32, 33
- **Forêt noire** : Monstres 34, 35, 36
- **Prairie démoniaque** : Monstres 37, 38, 39
- **Marais sombres** : Monstres 40, 41, 42
- **Montagne** : Monstres 43, 44, 45

#### Biomes Minages Spéciaux (IDs 46-60)
- **Volcan** : Monstres 46, 47, 48
- **Forêt** : Monstres 49, 50, 51
- **Grotte** : Monstres 52, 53, 54
- **Village** : Monstres 55, 56, 57
- **Mine** : Monstres 58, 59, 60

#### Lieux Spéciaux (IDs 61-75)
- **Salle coffre** : Monstres 61, 62, 63
- **Marché** : Monstres 64, 65, 66
- **Ruines** : Monstres 67, 68, 69
- **Casino** : Monstres 70, 71, 72
- **Salle coffre légendaire** : Monstres 73, 74, 75

## Statistiques des Monstres

### Plage de Valeurs par Niveau

#### Monstres Communs (IDs 1-25)
- **PV** : 20-50
- **Attaque** : 5-15
- **Défense** : 2-8
- **Esquive** : 5-15%
- **Spécial/Vitesse** : 3-10
- **Chance** : 1-5

#### Monstres Rares (IDs 26-50)
- **PV** : 50-100
- **Attaque** : 15-25
- **Défense** : 8-15
- **Esquive** : 15-25%
- **Spécial/Vitesse** : 10-18
- **Chance** : 5-10

#### Monstres Épiques (IDs 51-70)
- **PV** : 100-200
- **Attaque** : 25-40
- **Défense** : 15-25
- **Esquive** : 25-35%
- **Spécial/Vitesse** : 18-25
- **Chance** : 10-15

#### Monstres Légendaires et Mythiques (IDs 71-75)
- **PV** : 200-500
- **Attaque** : 40-80
- **Défense** : 25-40
- **Esquive** : 35-50%
- **Spécial/Vitesse** : 25-35
- **Chance** : 15-25

## Thèmes des Monstres par Biome

### Biomes Faciles
- **Plaine** : Créatures terrestres de base (loups, sangliers)
- **Désert** : Créatures adaptées à la chaleur (scorpions, serpents)
- **Champ de fleur** : Créatures magiques et insectes
- **Prairie** : Herbivores et petits prédateurs
- **Banquise** : Créatures arctiques (ours polaires, loups blancs)

### Biomes Moyens
- **Lac** : Créatures aquatiques (poissons géants, serpents d'eau)
- **Marais** : Créatures amphibies et végétales
- **Canyon** : Oiseaux de proie et créatures volantes
- **Jungle** : Prédateurs tropicaux et créatures exotiques
- **Mer** : Monstres marins et krakens

### Biomes Difficiles
- **Prairie volcanique** : Élémentaires de feu et créatures magmatiques
- **Forêt noire** : Spectres, loups-garous et créatures nocturnes
- **Prairie démoniaque** : Démons et créatures corrompues
- **Marais sombres** : Mortes-vivantes et créatures toxiques
- **Montagne** : Géants, griffons et créatures de haute altitude

### Biomes Spéciaux
- **Volcan** : Dragons et élémentaires supérieurs
- **Forêt** : Entités sylvestres et gardiens
- **Grotte** : Trolls, gobelins et créatures souterraines
- **Village** : Humains corrompus et gardiens
- **Mine** : Nains mécaniques et automates

### Lieux Spéciaux
- **Salle coffre** : Golems de pierre et gardiens magiques
- **Marché** : Voleurs et créatures urbaines
- **Ruines** : Automates anciens et esprits
- **Casino** : Gardiens du casino et tricheurs
- **Salle coffre légendaire** : Dragons légendaires et boss finaux

## Système de Combat

### Calcul des Dégâts
```c
/**
 * @brief Calculate damage dealt by monster to player
 * @param monster Attacking monster
 * @param player_defense Player's defense value
 * @return Total damage dealt
 */
int calculate_monster_damage(Monster* monster, int player_defense) {
    int base_damage = monster->att;
    int damage = base_damage - player_defense;
    
    // Apply dodge chance
    if (rand() % 100 < monster->dodge) {
        return 0; // Attack dodged
    }
    
    // Apply luck factor
    if (rand() % 100 < monster->luck) {
        damage *= 1.5; // Critical hit
    }
    
    return (damage > 0) ? damage : 1; // Minimum 1 damage
}
```

### Comportements Spéciaux
Chaque monstre peut avoir des comportements uniques basés sur ses statistiques :
- **Spe élevé** : Attaques rapides ou multiples
- **Luck élevée** : Coups critiques fréquents
- **Dodge élevé** : Esquive fréquente des attaques
- **PV élevés** : Résistance aux dégâts

## Récompenses et Butin

### Table de Butin
Le champ `table_loot` maintient la compatibilité avec l'ancien système et peut être utilisé pour :
- Référencer des tables de butin spécifiques
- Déterminer les objets uniques
- Gérer les récompenses de quêtes

### Distribution des Récompenses
- **Monstres communs** : Or de base, objets communs
- **Monstres rares** : Or modéré, objets rares
- **Monstres épiques** : Or important, objets épiques
- **Monstres légendaires** : Or très important, objets légendaires
- **Monstres mythiques** : Or exceptionnel, objets mythiques

## Implémentation Technique

### Chargement des Monstres
```c
/**
 * @brief Load monster data from file
 * @param monster_id ID of monster to load
 * @return Monster structure with loaded data
 */
Monster load_monster(int monster_id) {
    Monster monster;
    FILE* file = fopen("fr/monstre/monster.txt", "r");
    
    // Skip to the correct monster
    for (int i = 1; i < monster_id; i++) {
        skip_monster_lines(file);
    }
    
    // Read monster data
    fscanf(file, "%d", &monster.id);
    fscanf(file, "%39s", monster.name);
    fscanf(file, "%d", &monster.pv);
    // ... read other fields
    
    fclose(file);
    return monster;
}
```

### Validation des Données
```c
/**
 * @brief Validate monster statistics
 * @param monster Monster to validate
 * @return 1 if valid, 0 otherwise
 */
int validate_monster(Monster* monster) {
    if (monster->id < 1 || monster->id > 75) return 0;
    if (monster->pv <= 0 || monster->att < 0) return 0;
    if (monster->rarity < 0 || monster->rarity > 5) return 0;
    if (monster->dodge < 0 || monster->dodge > 100) return 0;
    
    return 1;
}
```

## Équilibrage et Maintenance

### Tests d'Équilibrage
- Simuler des combats avec différents niveaux de joueur
- Analyser les taux de réussite par type de monstre
- Ajuster les statistiques si nécessaire

### Ajout de Nouveaux Monstres
1. Assigner un nouvel ID (76, 77, ...)
2. Définir les caractéristiques selon le niveau souhaité
3. Assigner à un biome existant ou créer un nouveau biome
4. Mettre à jour les tables de butin

### Backward Compatibility
Le champ `table_loot` est maintenu pour assurer la compatibilité avec le code existant tout en permettant l'évolution vers un système plus moderne.

---

*Dernière mise à jour : 13/01/2026*
*Version : 1.0*
*Auteurs : Équipe de développement The Final Dawn*
