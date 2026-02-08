/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscraper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouma <onouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:25:16 by ounouma           #+#    #+#             */
/*   Updated: 2026/02/08 20:08:40 by onouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKYSCRAPER_H
# define SKYSCRAPER_H

# include <unistd.h>

/*
** =========================
** STRUCTURES
** =========================
*/

/*
** t_view :
** Contient les contraintes de visibilité du puzzle.
** Chaque tableau représente le nombre de bâtiments visibles
** depuis un côté de la grille.
**
** top[i] → vus depuis le haut de la colonne i
** bottom[i] → vus depuis le bas de la colonne i
** left[i] → vus depuis la gauche de la ligne i
** right[i] → vus depuis la droite de la ligne i
*/
typedef struct s_view
{
	int		top[4];
	int		bottom[4];
	int		left[4];
	int		right[4];
}			t_view;

/*
** t_ctx (contexte du solveur) :
** Regroupe toutes les données utiles pour résoudre le puzzle.
** - grid : la grille 4x4 en cours de remplissage
** - view : les contraintes de visibilité
*/
typedef struct s_ctx
{
	int		grid[4][4];
	t_view	view;
}			t_ctx;

/*
** =========================
** CHECK LIGNES
** =========================
*/

/*
** Vérifie qu'il n'y a pas de doublon dans une ligne.
*/
int			no_duplicate_line(int grid[4][4], int row);

/*
** Compte combien de bâtiments sont visibles depuis la gauche
** sur une ligne donnée.
*/
int			is_visible_left(int grid[4][4], int row);

/*
** Compte combien de bâtiments sont visibles depuis la droite
** sur une ligne donnée.
*/
int			is_visible_right(int grid[4][4], int row);

/*
** Vérifie qu'une ligne respecte :
** - Pas de doublon
** - Contrainte left / right
*/
int			check_row(int grid[4][4], int row, int left, int right);

/*
** =========================
** CHECK COLONNES
** =========================
*/

/*
** Vérifie qu'il n'y a pas de doublon dans une colonne.
*/
int			no_duplicate_col(int grid[4][4], int col);

/*
** Compte combien de bâtiments sont visibles depuis le haut
** sur une colonne donnée.
*/
int			is_visible_top(int grid[4][4], int col);

/*
** Compte combien de bâtiments sont visibles depuis le bas
** sur une colonne donnée.
*/
int			is_visible_bottom(int grid[4][4], int col);

/*
** Vérifie qu'une colonne respecte :
** - Pas de doublon
** - Contrainte top / bottom
*/
int			check_col(int grid[4][4], int col, int top, int bottom);

/*
** =========================
** SOLVER
** =========================
*/

/*
** Cherche la première case vide (valeur 0) dans la grille.
** Met sa position dans row et col.
** Retourne 1 si trouvé, 0 sinon.
*/
int			find_empty(int grid[4][4], int *row, int *col);

/*
** Vérifie si on peut placer un chiffre à une position donnée
** sans violer les règles du puzzle.
*/
int			is_safe(t_ctx *ctx, int row, int col, int num);

/*
** Résout la grille avec backtracking récursif.
** Retourne 1 si une solution est trouvée, 0 sinon.
*/
int			solve(t_ctx *ctx);

/*
** =========================
** UTILS
** =========================
*/

/*
** Affiche un nombre sur la sortie standard.
*/
void		ft_putnbr(int nb);

/*
** Affiche un caractère sur la sortie standard.
*/
void		ft_putchar(char c);

/*
** =========================
** MAIN
** =========================
*/

/*
** Parse la chaîne d'entrée et remplit la structure t_view.
** Retourne 1 si l'entrée est valide, 0 sinon.
*/
int			parse_input(char *str, t_view *view);

/*
** Affiche la grille 4x4.
*/
void		print_grid(int grid[4][4]);

/*
** Affiche "Error" suivi d'un retour à la ligne.
*/
void		print_error(void);

#endif
