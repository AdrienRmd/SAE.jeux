# Documentation du Module de Génération de Biomes

## Overview

Ce module gère la génération et la gestion des biomes dans The Final Dawn. Il fournit les structures de données et fonctions nécessaires pour créer des environnements de jeu variés et équilibrés.

## Classification des Biomes

### Catégories de Difficulté

#### Biomes Faciles (IDs 1-5)
- **Plage d'IDs** : 1-5
- **Niveau de difficulté** : 0.80-1.50
- **Public cible** : Joueurs débutants
- **Ressources** : Communes et abondantes
- **Monstres** : Faible puissance (IDs 1-15)

#### Biomes Moyens (IDs 6-10)
- **Plage d'IDs** : 6-10
- **Niveau de difficulté** : 1.00-1.40
- **Public cible** : Joueurs intermédiaires
- **Ressources** : Équilibrées et variées
- **Monstres** : Puissance modérée (IDs 16-30)

#### Biomes Difficiles (IDs 11-15)
- **Plage d'IDs** : 11-15
- **Niveau de difficulté** : 1.80-2.50
- **Public cible** : Joueurs expérimentés
- **Ressources** : Rares et précieuses
- **Monstres** : Haute puissance (IDs 31-45)

#### Lieux de Commerce (IDs 16-20)
- **Plage d'IDs** : 16-20
- **Niveau de difficulté** : Variable selon fonction
- **Public cible** : Tous les joueurs
- **Ressources** : Commerce et services
- **Monstres** : Gardiens et protecteurs (IDs 46-60)

#### Lieux Spéciaux (IDs 21-25)
- **Plage d'IDs** : 21-25
- **Niveau de difficulté** : 0.85-3.00
- **Public cible** : Joueurs avancés
- **Ressources** : Uniques et légendaires
- **Monstres** : Boss et gardiens puissants (IDs 61-75)

## Structure de Données Lieu

```c
/**
 * @brief Generic location structure for game environments
 * 
 * This structure represents any location in the game world,
 * including biomes, buildings, and special areas.
 */
typedef struct {
    char* description;           // Detailed description of the location
    Temperature temperature;      // Temperature type (affects player stats)
    Meteo meteo;              // Weather type (impacts player stats)
    Commerce commerce;          // Trading system for commercial locations
    Consommable consommable;    // Unique consumable for each biome
    Ressources ressources;       // Resource gathering system
    char* monstre_presence;    // List of monster names/presence
    int difficulty_biome;       // Difficulty coefficient (example: 1.5 boosts monster stats by 1.5x, stackable)
} Lieu;
```

## Description Détaillée des Champs

### `description`
- **Type** : `char*`
- **Purpose** : Description textuelle détaillée du lieu
- **Usage** : Affichage lors de l'arrivée du joueur
- **Exemple** : "Une plaine verdoyante s'étend à l'infini, avec quelques arbres épars"

### `temperature`
- **Type** : `Temperature` (enum)
- **Purpose** : Type de température affectant les statistiques
- **Impact** : Modificateurs sur les stats du joueur (0.75x à 1.00x)
- **Values** : tres_froid(1) à brulant(7)

### `meteo`
- **Type** : `Meteo` (enum)
- **Purpose** : Conditions météorologiques actuelles
- **Impact** : Modificateurs sur les stats (0.70x à 1.00x)
- **Values** : ensoleillé(1) à blizzard(11)

### `commerce`
- **Type** : `Commerce` (struct)
- **Purpose** : Système de commerce pour les lieux appropriés
- **Usage** : Vente/achat d'objets dans villages, marchés
- **Fields** : nombre_consommable, nombre_objet, coeff_vente

### `consommable`
- **Type** : `Consommable` (struct)
- **Purpose** : Objet consommable unique par biome
- **Usage** : Récupération et utilisation par le joueur
- **Spécificité** : Adapté aux conditions du biome

### `ressources`
- **Type** : `Ressources` (struct)
- **Purpose** : Système de collecte de ressources
- **Actions** : Pillage, récolte, fouille
- **Types** : Matériaux, plantes, minerais spécifiques

### `monstre_presence`
- **Type** : `char*`
- **Purpose** : Liste des monstres présents dans le lieu
- **Format** : Chaîne de caractères avec IDs ou noms
- **Usage** : Détermination des rencontres possibles

### `difficulty_biome`
- **Type** : `int`
- **Purpose** : Coefficient de difficulté du biome
- **Impact** : Boost des stats des monstres (cumulable)
- **Exemple** : difficulty_biome = 1.5 → stats monstres × 1.5
- **Range** : 0.80 (très facile) à 3.00 (extrême)

## Système de Génération

### Algorithmes de Génération

```c
/**
 * @brief Generate a random biome based on player progress
 * @param player_progress Current progress percentage (0-100)
 * @return Generated Lieu structure
 */
Lieu generate_biome_by_progress(int player_progress) {
    Lieu biome;
    
    // Select biome category based on progress
    if (player_progress < 20) {
        // Easy biomes only
        biome.id = rand() % 5 + 1;
    } else if (player_progress < 50) {
        // Easy and medium biomes
        biome.id = rand() % 10 + 1;
    } else if (player_progress < 80) {
        // All biomes except special
        biome.id = rand() % 20 + 1;
    } else {
        // All biomes including special
        biome.id = rand() % 25 + 1;
    }
    
    // Load biome data from files
    load_biome_data(&biome, biome.id);
    
    return biome;
}
```

### Application des Modificateurs

```c
/**
 * @brief Apply biome difficulty to monster stats
 * @param monster Monster to modify
 * @param biome Current biome
 */
void apply_biome_difficulty(Monster* monster, Lieu* biome) {
    float difficulty_multiplier = biome->difficulty_biome;
    
    // Apply to all combat stats
    monster->pv = (int)(monster->pv * difficulty_multiplier);
    monster->att = (int)(monster->att * difficulty_multiplier);
    monster->def = (int)(monster->def * difficulty_multiplier);
    
    // Special and luck are less affected
    monster->spe = (int)(monster->spe * (difficulty_multiplier * 0.5f));
    monster->luck = (int)(monster->luck * (difficulty_multiplier * 0.3f));
}
```

## Système de Ressources

### Types de Collecte

#### Pillage (Looting)
- **Applicable** : Lieux abandonnés, ruines, carcasses
- **Ressources** : Objets fabriqués, matériaux, équipement
- **Risque** : Présence de pièges ou gardiens

#### Récolte (Harvesting)
- **Applicable** : Zones naturelles, forêts, champs
- **Ressources** : Plantes, bois, nourriture
- **Risque** : Faible, dépend des conditions météo

#### Fouille (Searching)
- **Applicable** : Souterrains, grottes, mines
- **Ressources** : Minerais, pierres précieuses, artefacts
- **Risque** : Effondrement, créatures souterraines

### Gestion des Consommables

```c
/**
 * @brief Generate unique consumable for biome
 * @param biome_id Target biome identifier
 * @return Generated consumable structure
 */
Consommable generate_biome_consumable(int biome_id) {
    Consommable consumable;
    
    switch (biome_id) {
        case PLAINE:
            consumable = create_health_potion("Potion de plaine", 25);
            break;
        case DESERT:
            consumable = create_water_flask("Gourde d'eau désertique", 50);
            break;
        case VOLCAN:
            consumable = create_fire_resistance("Pierre de lave", 100);
            break;
        // ... other biomes
        default:
            consumable = create_basic_consumable();
            break;
    }
    
    return consumable;
}
```

## Intégration avec le Système de Jeu

### Boucle de Jeu Principale

```c
/**
 * @brief Main game loop with biome management
 */
void game_loop() {
    GameSession session;
    initialize_game(&session);
    
    while (session.game_state != GAME_OVER) {
        // Generate or load current biome
        if (session.current_biome == NULL) {
            session.current_biome = generate_biome_by_progress(session.progress);
        }
        
        // Apply environmental effects
        apply_environmental_effects(&session.player, session.current_biome);
        
        // Handle player actions
        handle_player_input(&session);
        
        // Check for monster encounters
        if (check_monster_encounter(session.current_biome)) {
            start_combat(&session);
        }
        
        // Update game state
        update_game_session(&session);
    }
}
```

### Gestion des Transitions

```c
/**
 * @brief Handle transition between biomes
 * @param session Current game session
 * @param new_biome_id Target biome ID
 */
void transition_to_biome(GameSession* session, int new_biome_id) {
    // Save current state
    save_biome_state(session->current_biome);
    
    // Load new biome
    session->current_biome = load_biome(new_biome_id);
    
    // Apply transition effects
    apply_transition_effects(&session->player, session->current_biome);
    
    // Display arrival message
    display_biome_arrival(session->current_biome);
}
```

## Optimisation et Performance

### Gestion Mémoire

```c
/**
 * @brief Memory pool for biome generation
 */
typedef struct {
    Lieu* biomes[MAX_CACHED_BIOMES];
    int count;
    int capacity;
} BiomeCache;

/**
 * @brief Get biome from cache or generate new one
 * @param biome_id Biome identifier
 * @return Pointer to biome structure
 */
Lieu* get_cached_biome(int biome_id) {
    // Check cache first
    for (int i = 0; i < biome_cache.count; i++) {
        if (biome_cache.biomes[i]->id == biome_id) {
            return biome_cache.biomes[i];
        }
    }
    
    // Generate and cache new biome
    if (biome_cache.count < biome_cache.capacity) {
        Lieu* new_biome = generate_biome_from_file(biome_id);
        biome_cache.biomes[biome_cache.count++] = new_biome;
        return new_biome;
    }
    
    return NULL; // Cache full
}
```

### Chargement Différé

```c
/**
 * @brief Lazy loading for biome resources
 */
void load_biome_resources_lazy(Lieu* biome) {
    if (biome->resources_loaded) {
        return; // Already loaded
    }
    
    // Load only when needed
    load_biome_textures(biome);
    load_biome_sounds(biome);
    load_biome_models(biome);
    
    biome->resources_loaded = true;
}
```

## Tests et Validation

### Tests Unitaires

```c
/**
 * @brief Test biome generation consistency
 */
void test_biome_generation() {
    for (int i = 1; i <= 25; i++) {
        Lieu biome = load_biome(i);
        
        assert(biome.id == i);
        assert(biome.difficulty_biome >= 0.80 && biome.difficulty_biome <= 3.00);
        assert(validate_temperature_range(biome.temperature));
        assert(validate_meteo_range(biome.meteo));
        assert(biome.monstre_presence != NULL);
    }
}

/**
 * @brief Test difficulty multiplier application
 */
void test_difficulty_application() {
    Monster test_monster = create_test_monster(100, 20, 10);
    Lieu test_biome = create_test_biome(1.5);
    
    Monster original = test_monster;
    apply_biome_difficulty(&test_monster, &test_biome);
    
    assert(test_monster.pv == original.pv * 1.5);
    assert(test_monster.att == original.att * 1.5);
    assert(test_monster.def == original.def * 1.5);
}
```

## Ajouts Futurs

### PNJ (Personnages Non-Joueurs)
- **Structure** : Dialogue, quêtes, comportement
- **Intégration** : Interactions dans villages et lieux spéciaux
- **IA** : Réactions aux actions du joueur

### Événements Dynamiques
- **Type** : Aléatoires ou déclenchés
- **Exemples** : Tempêtes soudaines, apparitions de monstres
- **Impact** : Modification temporaire du biome

### Système de Quêtes
- **Structure** : Objectifs, récompenses, prérequis
- **Intégration** : Liée aux biomes et aux PNJ
- **Progression** : Déblocage de nouvelles zones

---

*Dernière mise à jour : 13/01/2026*
*Version : 1.0*
*Auteurs : Équipe de développement The Final Dawn*