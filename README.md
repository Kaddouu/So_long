# so_long

so_long est un projet du cursus 42 qui consiste à réaliser un petit jeu en 2D avec une interface graphique minimaliste, en utilisant la bibliothèque MiniLibX. Le but est de parcourir une carte, de collecter tous les objets, puis d'atteindre la sortie.

## Objectifs du projet
- Découvrir la programmation graphique avec MiniLibX.
- Manipuler les fichiers, la gestion d'événements clavier et l'affichage d'images.
- Implémenter un algorithme de parcours de carte pour vérifier la validité du niveau.
- Gérer les erreurs et la robustesse du code.

![So_Long](https://github.com/user-attachments/assets/6d7d40aa-7581-479c-a26f-c990eff04156)

## Fonctionnalités principales
- Lecture et validation d'une carte au format texte.
- Affichage graphique de la carte, du joueur, des collectibles, des murs et de la sortie.
- Déplacement du joueur avec les touches du clavier.
- Collecte des objets et ouverture de la sortie une fois tous les objets ramassés.
- Gestion des conditions de victoire et d'échec.
- Fermeture propre du programme (croix de la fenêtre, touche ESC, etc).

## Structure du projet (exemple)
- `so_long.c` : Point d'entrée du programme.
- `map.c` : Lecture et validation de la carte.
- `render.c` : Affichage graphique avec MiniLibX.
- `player.c` : Gestion des déplacements du joueur.
- `utils.c` : Fonctions utilitaires.
- `images/` : Ressources graphiques (sprites).
- `libft/` : Fonctions utilitaires (libft).

## Compilation

Utilisez la commande suivante pour compiler le projet :

```sh
make
```

## Utilisation

Lancez le jeu avec :

```sh
./so_long maps/map.ber
```

Remplacez `maps/map.ber` par le chemin de votre carte.

## Auteurs
- [Votre nom ou pseudo]

## Remerciements
Merci à l'équipe pédagogique de 42 et à la communauté pour leur aide et leurs ressources.
