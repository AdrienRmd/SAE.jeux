# Traduction anglaise pour le fichier en/intro-EN.txt

## Contenu à copier dans en/intro-EN.txt

```txt
__________________START INTRO EN__________________

Welcome to the post-apocalyptic world of Neo-Terra

# Class messages
language_prompt=Choose language (fr) / Select language (gb) : 
What is your name in the game, survivor? : 
What is your gender (M/F/Non-binary)?
In this new world, what do you want to be?
game difficulty (1 - easy, 2 - medium, 3 - hard) :

# Confirmation messages
Welcome, %name. Your adventure in Neo-Terra begins now.
You have chosen to be a %race. May your destiny guide you through the ruins of the old world.
```

## Notes de traduction

1. **Conversions culturelles appropriées** :
   - "survivant" → "survivor"
   - "genre" → "gender" 
   - "facile/moyen/difficile" → "easy/medium/hard"

2. **Maintien de la structure** :
   - Préservation du format et des placeholders (%nom, %race)
   - Conservation des sections et commentaires
   - Maintien de la cohérence avec le contexte post-apocalyptique

3. **Adaptation linguistique** :
   - "Votre aventure commence maintenant" → "Your adventure begins now" (plus naturel en anglais)
   - "Que votre destin vous guide" → "May your destiny guide you" (formulation idiomatique)

4. **Uniformité terminologique** :
   - "Neo-Terra" reste inchangé (nom propre)
   - "post-apocalyptic" maintenu pour la cohérence thématique
   - "ruins of the old world" traduction littérale mais appropriée

## Recommandations d'implémentation

Pour une gestion multilingue efficace, votre code C devrait :

1. **Charger dynamiquement** le fichier de langue approprié
2. **Utiliser les mêmes clés** dans les deux fichiers pour la cohérence
3. **Gérer les placeholders** (%nom, %race) de manière uniforme
4. **Fournir des valeurs par défaut** si une clé est manquante

Cette traduction maintient l'immersion et la cohérence tout en s'adaptant naturellement à la langue anglaise.