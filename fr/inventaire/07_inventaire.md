# Système de statistiques d'inventaire

## Format des statistiques
Chaque objet possède 6 statistiques :
- **PV** : Points de Vie
- **ATT** : Attaque
- **DEF** : Défense
- **DODGE** : Esquive
- **SPEED** : Vitesse
- **CHANCE** : Chance

## Exemple de format
```
Nom de l'objet
PV ATT DEF DODGE SPEED CHANCE
```

## Équipements par rareté

### Équipements Communs (1-10)
- Casques : PV=3-5, ATT=1-3, DEF=6-8, DODGE=1-3, SPEED=1-3, CHANCE=1-3
- Armures : PV=3-5, ATT=1-2, DEF=5-7, DODGE=1-3, SPEED=1-3, CHANCE=1-3
- Armes : PV=2-3, ATT=6-9, DEF=1-2, DODGE=1-3, SPEED=2-3, CHANCE=1-3
- Boucliers : PV=3-5, ATT=1-3, DEF=7-9, DODGE=1-3, SPEED=1-3, CHANCE=1-3
- Amulettes : PV=2-8, ATT=1-8, DEF=1-8, DODGE=1-8, SPEED=1-8, CHANCE=1-8

### Équipements Rares (11-20)
- Casques : PV=7-12, ATT=3-5, DEF=13-15, DODGE=3-5, SPEED=3-5, CHANCE=3-5
- Armures : PV=8-12, ATT=3-5, DEF=11-13, DODGE=3-6, SPEED=3-6, CHANCE=3-6
- Armes : PV=6-12, ATT=13-17, DEF=3-5, DODGE=3-6, SPEED=6-9, CHANCE=3-6
- Boucliers : PV=8-12, ATT=3-5, DEF=13-17, DODGE=3-5, SPEED=3-5, CHANCE=3-5
- Amulettes : PV=6-15, ATT=3-15, DEF=3-15, DODGE=3-15, SPEED=3-15, CHANCE=3-15

### Équipements Très Rares (21-30)
- Casques : PV=12-17, ATT=5-8, DEF=22-25, DODGE=5-8, SPEED=5-8, CHANCE=5-8
- Armures : PV=17-20, ATT=5-8, DEF=20-22, DODGE=6-10, SPEED=5-8, CHANCE=5-8
- Armes : PV=12-17, ATT=22-27, DEF=5-8, DODGE=5-10, SPEED=12-15, CHANCE=5-8
- Boucliers : PV=15-20, ATT=5-8, DEF=22-27, DODGE=5-8, SPEED=5-8, CHANCE=5-8
- Amulettes : PV=12-25, ATT=5-25, DEF=5-25, DODGE=5-25, SPEED=5-25, CHANCE=5-25

### Équipements Épiques (31-40)
- Casques : PV=20-25, ATT=0-10, DEF=30-35, DODGE=0-10, SPEED=0-10, CHANCE=0-10
- Armures : PV=22-25, ATT=5-10, DEF=23-28, DODGE=10-15, SPEED=8-12, CHANCE=5-10
- Armes : PV=18-25, ATT=30-38, DEF=5-10, DODGE=5-20, SPEED=12-20, CHANCE=5-10
- Boucliers : PV=22-28, ATT=5-10, DEF=30-35, DODGE=5-10, SPEED=5-10, CHANCE=5-10
- Amulettes : PV=18-35, ATT=5-35, DEF=5-35, DODGE=5-35, SPEED=5-35, CHANCE=5-35

### Équipements Légendaires (41-50)
- Casques : PV=25-30, ATT=5-10, DEF=40-45, DODGE=5-10, SPEED=5-10, CHANCE=5-10
- Armures : PV=30-35, ATT=8-10, DEF=35-40, DODGE=10-15, SPEED=10-15, CHANCE=10-15
- Armes : PV=20-30, ATT=40-48, DEF=5-10, DODGE=5-20, SPEED=15-20, CHANCE=10-15
- Boucliers : PV=28-35, ATT=5-10, DEF=40-48, DODGE=5-10, SPEED=5-10, CHANCE=5-10
- Amulettes : PV=20-45, ATT=5-45, DEF=5-45, DODGE=5-45, SPEED=5-45, CHANCE=5-45

### Équipements Mythiques (51-60)
- Casques : PV=30-35, ATT=10-15, DEF=50-55, DODGE=10-15, SPEED=10-15, CHANCE=10-15
- Armures : PV=40-45, ATT=10-15, DEF=45-50, DODGE=15-25, SPEED=15-25, CHANCE=15-25
- Armes : PV=30-45, ATT=50-58, DEF=5-15, DODGE=10-25, SPEED=15-25, CHANCE=15-25
- Boucliers : PV=38-45, ATT=10-15, DEF=50-58, DODGE=10-15, SPEED=10-15, CHANCE=10-15
- Amulettes : PV=30-55, ATT=10-55, DEF=10-55, DODGE=10-55, SPEED=10-55, CHANCE=10-55

## Consommables
Tous les consommables ont des statistiques maximum de 10 :
- **Nourriture de base** : PV=5-7, ATT=1-2, DEF=1-2, DODGE=1-3, SPEED=2-4, CHANCE=1-3
- **Boissons** : PV=2-4, ATT=1-2, DEF=1-2, DODGE=1-3, SPEED=4-6, CHANCE=1-3
- **Élixirs** : PV=2-8, ATT=2-8, DEF=2-8, DODGE=2-8, SPEED=2-8, CHANCE=2-8
- **Objets spéciaux** : PV=4-8, ATT=2-5, DEF=2-5, DODGE=2-6, SPEED=3-8, CHANCE=2-8

## Objet spécial : Désaltérant Intense
Apparaît dans tous les biomes avec des statistiques cohérentes :
- **PV** : 5
- **ATT** : 2
- **DEF** : 3
- **DODGE** : 2
- **SPEED** : 4
- **CHANCE** : 3

## Notes d'équilibrage
- Les casques et boucliers favorisent la DEF
- Les armes favorisent l'ATT
- Les armures ont un équilibre PV/DEF
- Les amulettes sont équilibrées selon leur attribut principal
- Les consommables sont limités à 10 pour maintenir l'équilibre du jeu