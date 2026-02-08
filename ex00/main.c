/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouma <onouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:53:05 by ounouma           #+#    #+#             */
/*   Updated: 2026/02/08 20:07:00 by onouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

/*
** print_error : affiche "Error\n" en cas d'entrée invalide
*/
void	print_error(void)
{
	write(1, "Error\n", 6);
}

/*
** print_grid : affiche la grille 4x4 finale
** Chaque chiffre séparé par un espace, chaque ligne par un retour à la ligne
*/
void	print_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putnbr(grid[i][j]); // affiche le chiffre
			if (j < 3)            
				// ajoute un espace sauf après le dernier chiffre
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n'); // nouvelle ligne après chaque ligne
		i++;
	}
}

/*
** parse_input : transforme la chaîne entrée par l'utilisateur en contraintes
** str : la chaîne entrée (ex : "4 3 2 1 1 2 2 2 ...")
** view : structure t_view qui stocke top, bottom, left, right
** Retour : 1 si tout est valide, 0 sinon
*/
int	parse_input(char *str, t_view *view)
{
	int	num;

	int i = 0; // index dans la chaîne
	int j = 0; // compteur de chiffres traités
	while (str[i] && j < 16)
	{
		// Vérifie que le caractère est un chiffre valide
		if (str[i] < '1' || str[i] > '4')
			return (0);
		num = str[i] - '0';
		// Stocke le chiffre dans la bonne position de t_view
		if (j < 4)
			view->top[j] = num;
		else if (j < 8)
			view->bottom[j - 4] = num;
		else if (j < 12)
			view->left[j - 8] = num;
		else
			view->right[j - 12] = num;
		// Vérifie qu'il y a exactement un espace après le chiffre sauf le dernier
		if ((j < 15 && str[i + 1] != ' ') || (j == 15 && str[i + 1]))
			return (0);
		i += 2; // passe au chiffre suivant (1 chiffre + 1 espace)
		j++;
	}
	return (j == 16); // vrai si exactement 16 chiffres
}

/*
** main : point d'entrée du programme
** Étapes :
** 1. Initialise le contexte et la grille
** 2. Vérifie que l'entrée est correcte
** 3. Résout le puzzle avec solve (backtracking)
** 4. Affiche la grille ou "Error" si échec
*/
int	main(int ac, char **av)
{
	int	i;
	int	j;

	t_ctx ctx; // contexte du puzzle : grille + contraintes
	// Initialisation de la grille à 0
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ctx.grid[i][j] = 0; // case vide
			j++;
		}
		i++;
	}
	// Vérifie l'entrée et tente de résoudre le puzzle
	if (ac != 2 || !parse_input(av[1], &ctx.view) || !solve(&ctx))
	{
		print_error(); // entrée invalide ou puzzle impossible
		return (1);
	}
	// Affiche la grille complète
	print_grid(ctx.grid);
	return (0);
}
