# ft_skyscraper
# 🏙️ Rush-01 — Skyscraper Solver (42)

Ce projet consiste à résoudre un puzzle **Skyscraper 4x4**.
Le but est de remplir une grille 4x4 avec des nombres de 1 à 4 en respectant :

• Chaque ligne et chaque colonne contient les nombres 1 à 4 **sans doublons**
• Des contraintes de visibilité sont données depuis :
- le haut / le bas pour les colonnes
- la gauche / la droite pour les lignes

Une boîte plus haute cache les plus petites derrière elle.

---

## 📥 Utilisation

### Compilation

```bash
cc -Wall -Wextra -Werror *.c -o rush-01

##Execution
```bash
./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"

Format obligatoire :

👉 16 chiffres entre 1 et 4, séparés par un seul espace


Ordre attendu :
col1up col2up col3up col4up
col1down col2down col3down col4down
row1left row2left row3left row4left
row1right row2right row3right row4right

##📤 Sortie attendue


Exemple :
```bash
$> ./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3

En cas d’erreur ou s’il n’existe aucune solution :
Error

##🧠 Fonctionnement du programme


Le programme utilise un algorithme de backtracking récursif :

    Cherche une case vide

    Teste les nombres de 1 à 4

    Vérifie :

    • Pas de doublon dans la ligne

    • Pas de doublon dans la colonne

    • Visibilité respectée si la ligne/colonne est complète

    Si une règle est violée → retour en arrière (backtrack)

    Continue jusqu’à trouver la première solution valide

##🗂️ Structure du projet

Fichier
	

Rôle

main.c
	

Parse l’entrée, initialise la grille et lance la résolution

solver.c
	

Contient l’algorithme récursif

check_row.c
	

Vérifie les lignes (doublons + visibilité)

check_col.c
	

Vérifie les colonnes (doublons + visibilité)

utils.c
	

Fonctions utilitaires (ft_putnbr, ft_putchar, etc.)

skyscraper.h
	

Déclarations + structures

##🧱 Structures utilisées
```c
typedef struct s_view
{
int top[4];
int bottom[4];
int left[4];
int right[4];
} t_view;

typedef struct s_ctx
{
int grid[4][4];
t_view view;
} t_ctx;

