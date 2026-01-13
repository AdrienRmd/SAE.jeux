# Documentation des Biomes - The Final Dawn

## Overview

Ce document décrit le système de biomes implémenté dans The Final Dawn, comprenant 25 environnements distincts avec leurs caractéristiques climatiques, niveaux de difficulté et monstres associés.

## Structure des Données

Chaque biome est défini par 10 paramètres :

1. **id_biome** : Identifiant unique (1-25)
2. **description** : Nom du biome
3. **difficulty_biome** : Coefficient de difficulté (0.80-3.00)
4. **minimum_temperature** : Température minimale (1-7)
5. **maximum_temperature** : Température maximale (1-7)
6. **minimum_meteo** : Météo minimale (1-11)
7. **maximum_meteo** : Météo maximale (1-11)
8. **id_monstre_1** : Premier monstre associé
9. **id_monstre_2** : Deuxième monstre associé
10. **id_monstre_3** : Troisième monstre associé

## Échelles de Valeurs

### Température
- `1` : Très froid (coefficient 0.75)
- `2` : Froid (coefficient 0.90)
- `3` : Frais (coefficient 0.95)
- `4` : Tempéré (coefficient 1.00)
- `5` : Chaud (coefficient 0.95)
- `6` : Très chaud (coefficient 0.90)
- `7` : Brûlant (coefficient 0.75)

### Météo
- `1` : Ensoleillé (coefficient 1.00)
- `2` : Nuageux (coefficient 1.00)
- `3` : Pluie (coefficient 0.95)
- `4` : Brouillard (coefficient 0.90)
- `5` : Orage (coefficient 0.85)
- `6` : Vent fort (coefficient 0.85)
- `7` : Neige (coefficient 0.80)
- `8` : Tempête (coefficient 0.75)
- `9` : Tempête de sable (coefficient 0.75)
- `10` : Tempête de neige (coefficient 0.70)
- `11` : Blizzard (coefficient 0.70)

## Classification des Biomes

### Biomes Faciles (ID: 1-5)

#### 1. Plaine
- **Difficulté** : 0.80 (très facile)
- **Température** : 3-5 (frais à chaud)
- **Météo** : 1-2 (ensoleillé à nuageux)
- **Monstres** : 1, 2, 3
- **Description** : Terrain herbeux relativement sûr, idéal pour les débutants

#### 2. Désert
- **Difficulté** : 1.20 (facile à modéré)
- **Température** : 5-7 (chaud à brûlant)
- **Météo** : 1-9 (ensoleillé à tempête de sable)
- **Monstres** : 4, 5, 6
- **Description** : Aride et dangereux, ressources rares

#### 3. Champ de fleur
- **Difficulté** : 0.90 (très facile)
- **Température** : 4-4 (tempéré)
- **Météo** : 1-3 (ensoleillé à pluie)
- **Monstres** : 7, 8, 9
- **Description** : Zone magnifique mais parfois trompeuse

#### 4. Prairie
- **Difficulté** : 0.85 (facile)
- **Température** : 3-4 (frais à tempéré)
- **Météo** : 2-3 (nuageux à pluie)
- **Monstres** : 10, 11, 12
- **Description** : Terrain ouvert avec visibilité limitée

#### 5. Banquise
- **Difficulté** : 1.50 (modéré)
- **Température** : 1-2 (très froid à froid)
- **Météo** : 7-10 (neige à tempête de neige)
- **Monstres** : 13, 14, 15
- **Description** : Glaciale et périlleuse, nécessite équipement spécial

### Biomes Moyens (ID: 6-10)

#### 6. Lac
- **Difficulté** : 1.00 (modéré)
- **Température** : 3-4 (frais à tempéré)
- **Météo** : 2-3 (nuageux à pluie)
- **Monstres** : 16, 17, 18
- **Description** : Zone aquatique avec ressources variées

#### 7. Marais
- **Difficulté** : 1.10 (modéré)
- **Température** : 4-5 (tempéré à chaud)
- **Météo** : 4-3 (brouillard à pluie)
- **Monstres** : 19, 20, 21
- **Description** : Humide et dangereux, créatures amphibies

#### 8. Canyon
- **Difficulté** : 1.30 (modéré à difficile)
- **Température** : 5-6 (chaud à très chaud)
- **Météo** : 1-6 (ensoleillé à vent fort)
- **Monstres** : 22, 23, 24
- **Description** : Terrain accidenté, passages difficiles

#### 9. Jungle
- **Difficulté** : 1.40 (difficile)
- **Température** : 5-7 (chaud à brûlant)
- **Météo** : 3-5 (pluie à orage)
- **Monstres** : 25, 26, 27
- **Description** : Dense et humide, faune dangereuse

#### 10. Mer
- **Difficulté** : 1.25 (modéré à difficile)
- **Température** : 3-4 (frais à tempéré)
- **Météo** : 2-8 (nuageux à tempête)
- **Monstres** : 28, 29, 30
- **Description** : Étendue aquatique avec dangers maritimes

### Biomes Difficiles (ID: 11-15)

#### 11. Prairie volcanique
- **Difficulté** : 2.00 (difficile)
- **Température** : 6-7 (très chaud à brûlant)
- **Météo** : 6-8 (vent fort à tempête)
- **Monstres** : 31, 32, 33
- **Description** : Terre volcanique active, très dangereuse

#### 12. Forêt noire
- **Difficulté** : 1.80 (difficile)
- **Température** : 3-4 (frais à tempéré)
- **Météo** : 4-5 (brouillard à orage)
- **Monstres** : 34, 35, 36
- **Description** : Forêt sombre et maléfique

#### 13. Prairie démoniaque
- **Difficulté** : 2.50 (très difficile)
- **Température** : 7-7 (brûlant)
- **Météo** : 8-9 (tempête à tempête de sable)
- **Monstres** : 37, 38, 39
- **Description** : Terre corrompue par les démons

#### 14. Marais sombres
- **Difficulté** : 2.20 (difficile à très difficile)
- **Température** : 4-5 (tempéré à chaud)
- **Météo** : 4-8 (brouillard à tempête)
- **Monstres** : 40, 41, 42
- **Description** : Version corrompue des marais

#### 15. Montagne
- **Difficulté** : 1.90 (difficile)
- **Température** : 2-3 (froid à frais)
- **Météo** : 6-7 (vent fort à neige)
- **Monstres** : 43, 44, 45
- **Description** : Haute altitude, conditions extrêmes

### Biomes Minages Spéciaux (ID: 16-20)

#### 16. Volcan
- **Difficulté** : 2.80 (très difficile)
- **Température** : 7-7 (brûlant)
- **Météo** : 8-9 (tempête à tempête de sable)
- **Monstres** : 46, 47, 48
- **Description** : Volcan actif, ressources rares mais danger maximal

#### 17. Forêt
- **Difficulté** : 1.15 (modéré)
- **Température** : 3-4 (frais à tempéré)
- **Météo** : 2-3 (nuageux à pluie)
- **Monstres** : 49, 50, 51
- **Description** : Forêt standard, ressources variées

#### 18. Grotte
- **Difficulté** : 1.60 (difficile)
- **Température** : 2-4 (froid à tempéré)
- **Météo** : 4-4 (brouillard)
- **Monstres** : 52, 53, 54
- **Description** : Souterrain, obscurité permanente

#### 19. Village
- **Difficulté** : 0.95 (facile)
- **Température** : 4-4 (tempéré)
- **Météo** : 1-2 (ensoleillé à nuageux)
- **Monstres** : 55, 56, 57
- **Description** : Zone de civilisation, commerce possible

#### 20. Mine
- **Difficulté** : 1.70 (difficile)
- **Température** : 2-3 (froid à frais)
- **Météo** : 4-6 (brouillard à vent fort)
- **Monstres** : 58, 59, 60
- **Description** : Souterrain, ressources minérales

### Lieux Spéciaux (ID: 21-25)

#### 21. Salle coffre
- **Difficulté** : 1.00 (modéré)
- **Température** : 4-4 (tempéré)
- **Météo** : 2-2 (nuageux)
- **Monstres** : 61, 62, 63
- **Description** : Pièce au trésor, gardiens présents

#### 22. Marché
- **Difficulté** : 0.90 (facile)
- **Température** : 4-4 (tempéré)
- **Météo** : 1-2 (ensoleillé à nuageux)
- **Monstres** : 64, 65, 66
- **Description** : Zone commerciale, échanges possibles

#### 23. Ruines
- **Difficulté** : 1.35 (modéré à difficile)
- **Température** : 3-4 (frais à tempéré)
- **Météo** : 4-2 (brouillard à nuageux)
- **Monstres** : 67, 68, 69
- **Description** : Vestiges de l'ancien monde

#### 24. Casino
- **Difficulté** : 0.85 (facile)
- **Température** : 4-4 (tempéré)
- **Météo** : 2-2 (nuageux)
- **Monstres** : 70, 71, 72
- **Description** : Lieu de jeux et hasard

#### 25. Salle coffre légendaire
- **Difficulté** : 3.00 (extrême)
- **Température** : 4-4 (tempéré)
- **Météo** : 1-1 (ensoleillé)
- **Monstres** : 73, 74, 75
- **Description** : Trésor légendaire, défenseurs puissants

## Système de Monstres

### Assignation des IDs
- **Total** : 75 monstres uniques (25 biomes × 3 monstres)
- **Progression** : IDs séquentiels de 1 à 75
- **Répartition** : Chaque biome possède 3 monstres distincts

### Difficulté des Monstres
- **Biomes faciles** : Monstres de niveaux 1-15
- **Biomes moyens** : Monstres de niveaux 16-30
- **Biomes difficiles** : Monstres de niveaux 31-45
- **Biomes spéciaux** : Monstres de niveaux 46-75

## Équilibre du Gameplay

### Progression Recommandée
1. **Début** : Plaine, Champ de fleur, Prairie
2. **Exploration** : Désert, Lac, Village
3. **Défis** : Canyon, Jungle, Forêt
4. **Expert** : Biomes difficiles et spéciaux

### Adaptation des Stats
Les coefficients de température et météo modifient les caractéristiques du joueur :
- **Température extrême** : Réduction de 25% des stats
- **Météo défavorable** : Réduction de 15-30% des stats
- **Conditions optimales** : Stats normales ou bonus

### Ressources par Biome
Chaque biome offre des ressources spécifiques adaptées à son environnement :
- **Biomes froids** : Équipement thermique, minerais rares
- **Biomes chauds** : Ressources de survie, objets de protection
- **Biomes spéciaux** : Équipement unique, matériaux légendaires

## Utilisation dans le Code

### Chargement des Données
```c
// Exemple de chargement d'un biome
Biome load_biome(int id) {
    FILE* file = fopen("fr/biomes/biome.txt", "r");
    Biome biome;
    
    // Sauter au biome correspondant
    for (int i = 1; i < id; i++) {
        skip_biome_lines(file);
    }
    
    // Lire les 10 lignes du biome
    fscanf(file, "%d", &biome.id_biome);
    // ... lecture des autres paramètres
    
    return biome;
}
```

### Application des Modificateurs
```c
// Application des coefficients de température
float apply_temperature_modifier(float base_stats, Temperature temp) {
    switch (temp) {
        case tres_froid:
        case brulant:
            return base_stats * 0.75f;
        case froid:
        case tres_chaud:
            return base_stats * 0.90f;
        case frais:
        case chaud:
            return base_stats * 0.95f;
        case tempere:
        default:
            return base_stats;
    }
}
```

## Maintenance et Évolution

### Ajout de Nouveaux Biomes
1. Ajouter une entrée dans l'énumération `Terrain`
2. Créer 10 lignes dans `biome.txt`
3. Assigner 3 nouveaux IDs de monstres
4. Mettre à jour cette documentation

### Équilibrage
- Surveiller les taux de réussite par biome
- Ajuster les coefficients de difficulté
- Modifier les répartitions de monstres si nécessaire

---

*Dernière mise à jour : 13/01/2026*
*Version : 1.0*