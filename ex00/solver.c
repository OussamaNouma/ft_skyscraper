/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouma <onouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:13:15 by ounouma           #+#    #+#             */
/*   Updated: 2026/02/08 20:06:34 by onouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

/*
** find_empty : cherche la première case vide (valeur 0) dans la grille.
** row, col : pointeurs pour renvoyer la position trouvée.
** Retourne 1 si une case vide est trouvée, 0 si la grille est pleine.
*/
int	find_empty(int grid[4][4], int *row, int *col)
{
	int i, j;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (grid[i][j] == 0)
			{
				*row = i;   // enregistre la ligne de la case vide
				*col = j;   // enregistre la colonne de la case vide
				return (1); // case vide trouvée
			}
			j++;
		}
		i++;
	}
	return (0); // pas de case vide → grille complète
}

/*
** is_safe : vérifie si on peut placer "num" à la position (row, col)
** ctx : contexte du puzzle (grille + contraintes)
** Étapes :
** 1. Place temporairement le chiffre
** 2. Vérifie qu'il n'y a pas de doublon dans la ligne ou la colonne
** 3. Si la ligne/colonne est complète, vérifie les contraintes de visibilité
** 4. Retourne 1 si le placement est valide, sinon 0 et vide la case
*/
int	is_safe(t_ctx *ctx, int row, int col, int num)
{
	int i, j;
	ctx->grid[row][col] = num; // place temporairement le chiffre
	// Vérifie doublons dans la ligne et la colonne
	if (!no_duplicate_line(ctx->grid, row) || !no_duplicate_col(ctx->grid, col))
		return (ctx->grid[row][col] = 0, 0);
	// Vérifie contraintes de la ligne si elle est complète
	j = 0;
	while (j < 4 && ctx->grid[row][j] != 0)
		j++;
	if (j == 4 && !check_row(ctx->grid, row, ctx->view.left[row],
			ctx->view.right[row]))
		return (ctx->grid[row][col] = 0, 0);
	// Vérifie contraintes de la colonne si elle est complète
	i = 0;
	while (i < 4 && ctx->grid[i][col] != 0)
		i++;
	if (i == 4 && !check_col(ctx->grid, col, ctx->view.top[col],
			ctx->view.bottom[col]))
		return (ctx->grid[row][col] = 0, 0);
	ctx->grid[row][col] = 0; // retire le chiffre temporaire
	return (1);              // placement possible
}

/*
** solve : résout la grille récursivement avec backtracking
** ctx : contexte du puzzle
** Étapes :
** 1. Cherche la première case vide
** 2. Essaie tous les chiffres possibles (1 à 4)
** 3. Vérifie si le placement est sûr avec is_safe
** 4. Si oui, place le chiffre et appelle solve sur la case suivante
** 5. Si aucune valeur ne fonctionne,
	vide la case et revient en arrière (backtracking)
** Retour : 1 si solution trouvée, 0 sinon
*/
int	solve(t_ctx *ctx)
{
	int	num;

	int row, col;
	// Si pas de case vide, la grille est complète → solution trouvée
	if (!find_empty(ctx->grid, &row, &col))
		return (1);
	num = 1;
	while (num <= 4)
	{
		// Vérifie si on peut placer num dans la case
		if (is_safe(ctx, row, col, num))
		{
			ctx->grid[row][col] = num; // place le chiffre
			// Appel récursif pour la prochaine case
			if (solve(ctx))
				return (1); // solution trouvée, remonte la pile
			ctx->grid[row][col] = 0; // aucun chiffre ne fonctionne → backtrack
		}
		num++;
	}
	return (0); // aucune solution trouvée à partir de cette configuration
}
