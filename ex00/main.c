/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouma <onouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:53:05 by ounouma           #+#    #+#             */
/*   Updated: 2026/02/08 16:10:50 by onouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

void	print_error(void)
{
	write(1, "Error\n", 6);
}

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
			ft_putnbr(grid[i][j]);
			if (j < 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	parse_input(char *str, t_view *view)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	j = 0;
	while (str[i] && j < 16)
	{
		if (str[i] < '1' || str[i] > '4')
			return (0);
		num = str[i] - '0';
		if (j < 4)
			view->top[j] = num;
		else if (j < 8)
			view->bottom[j - 4] = num;
		else if (j < 12)
			view->left[j - 8] = num;
		else
			view->right[j - 12] = num;
		if ((j < 15 && str[i + 1] != ' ') || (j == 15 && str[i + 1]))
			return (0);
		i += 2;
		j++;
	}
	return (j == 16);
}

int	main(int ac, char **av)
{
	t_ctx	ctx;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ctx.grid[i][j] = 0;
			j++;
		}
		i++;
	}
	if (ac != 2 || !parse_input(av[1], &ctx.view) || !solve(&ctx))
	{
		print_error();
		return (1);
	}
	print_grid(ctx.grid);
	return (0);
}
