# SAE.jeux - Neo-Terra

## Project Overview
Neo-Terra is a post-apocalyptic text-based role-playing game developed in C as part of SAE S1.01 project. The game features multilingual support (French/English), character customization, biome exploration, and turn-based combat mechanics.

## Features Implemented
- **Multilingual Support**: French and English language options
- **Character Customization**: Name, race, class selection with stat modifications
- **Biome System**: 25 unique biomes with varying difficulty levels and environmental effects
- **Combat System**: Turn-based combat with dodge mechanics and damage calculations
- **Monster System**: 75 unique monsters across different rarity levels
- **Inventory Management**: Equipment and consumable items with stat bonuses
- **Progressive Difficulty**: Floor-based progression system

## Authors
[Add author names here]

## Compilation and Execution
```bash
# Compile
make all

# Run
./neo_terra.exe  # Windows
./neo_terra      # Linux/macOS
```

## Project Structure
- `function/` - Core game logic and systems
- `structure/` - Data structures and type definitions
- `player/` - Player data and management
- `fr/` - French language resources
- `en/` - English language resources
- `.kilocode/` - Project development rules and guidelines

## Language Support
The game supports both French and English languages. All user-facing text is stored in language-specific resource files, and the codebase follows English-only commenting standards as per project requirements.

## Game Flow
1. **Language Selection**: Choose between French and English
2. **Character Creation**: Name, race, class, and difficulty selection
3. **Biome Exploration**: Navigate through different environments
4. **Combat Encounters**: Turn-based battles with various monsters
5. **Progression**: Advance through floors with increasing difficulty

## Technical Implementation
- **Modular Architecture**: Clear separation of concerns between modules
- **Resource Management**: Dynamic loading of language-specific content
- **Statistical Systems**: Complex damage calculations and stat modifications
- **File I/O**: Persistent player data and game state management