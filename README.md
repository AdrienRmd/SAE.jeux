# The Final Dawn - Jeu d'aventure post-apocalyptique

## Qu'est-ce que c'est ?

Un jeu d'aventure en mode texte développé en C pour le projet SAE de première année d'IUT. Vous incarnez un survivant dans le monde post-apocalyptique de Neo-Terra, où vous devez explorer des biomes dangereux, combattre des monstres et survivre dans un monde en ruines.

## Comment ça marche ?

### Prérequis
- Un compilateur C (gcc recommandé)
- Un terminal/invite de commandes

### Installation et lancement
```bash
# Compiler le jeu
make all

# Lancer le jeu
./the_final_dawn.exe    # Sur Windows
./the_final_dawn        # Sur Linux/macOS
```

### Nettoyer les fichiers de compilation
```bash
make clean
```

## 🌍 Fonctionnalités principales

### 🌐 Multilingue
- **Français** : Choisissez `fr` au début
- **Anglais** : Choisissez `en` au début

### 👤 Personnalisation du personnage
- Choisissez votre nom
- Sélectionnez votre race (humain, nain, elfe)
- Choisissez votre classe (combattant, voleur, archer)
- Définissez la difficulté (facile, moyen, difficile)

### 🗺️ Système de biomes
- Exploration de différents environnements
- Génération aléatoire des biomes
- Chaque biome a ses caractéristiques uniques

### 📊 Statistiques du joueur
- Points de vie (HP)
- Attaque, défense, esquive
- Vitesse, chance
- Expérience et niveau
- Argent

## 📁 Structure du projet

```
SAE_jeux/
├── main.c                    # Point d'entrée du jeu
├── makefile                  # Script de compilation
├── structure/                # Structures de données
│   └── structure.h          # Player, Monster
├── function/                 # Fonctions du jeu
│   ├── gamef.c/.h           # Logique principale
│   ├── file_manipulation.c/.h  # Gestion des fichiers
│   └── other.c/.h           # Fonctions utilitaires
├── fr/                       # Contenu français
│   └── intro-FR.txt
├── en/                       # Contenu anglais
│   └── intro-EN.txt
└── README.md                 # Ce fichier !
```

## Comment jouer ?

1. **Démarrage** : Lancez le jeu et choisissez votre langue
2. **Création** : Personnalisez votre personnage
3. **Aventure** : Explorez les différents biomes
4. **Survie** : Affrontez les défis et progressez

## Fonctionnalités techniques

### Architecture modulaire
- Séparation claire des responsabilités
- Fonctions documentées en anglais
- Code portable (Windows/Linux/macOS)

### Gestion des ressources
- Fichiers de langue externes
- Système de biomes configurables
- Gestion des monstres et équipements

## Auteurs

Projet réalisé par des étudiants de première année d'IUT dans le cadre de la SAE développement en C.

## Notes importantes

- Le jeu utilise uniquement les bibliothèques standard C
- Tous les commentaires du code sont en anglais
- Le projet est conçu pour être éducatif et évolutif

---

**Bon jeu dans Neo-Terra ! 🎮**