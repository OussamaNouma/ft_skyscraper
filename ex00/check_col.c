/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ounouma <ounouma@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:13:07 by ounouma           #+#    #+#             */
/*   Updated: 2026/02/08 11:13:09 by ounouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

int	no_duplicate_col(int grid[4][4], int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (grid[i][col] != 0 && grid[i][col] == grid[j][col])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_visible_top(int grid[4][4], int col)
{
	int	max;
	int	visible;
	int	i;

	max = 0;
	visible = 0;
	i = 0;
	while (i < 4)
	{
		if (grid[i][col] > max)
		{
			max = grid[i][col];
			visible++;
		}
		i++;
	}
	return (visible);
}

int	is_visible_bottom(int grid[4][4], int col)
{
	int	max;
	int	visible;
	int	i;

	max = 0;
	visible = 0;
	i = 3;
	while (i >= 0)
	{
		if (grid[i][col] > max)
		{
			max = grid[i][col];
			visible++;
		}
		i--;
	}
	return (visible);
}

int	check_col(int grid[4][4], int col, int top, int bottom)
{
	if (!no_duplicate_col(grid, col))
		return (0);
	if (is_visible_top(grid, col) != top)
		return (0);
	if (is_visible_bottom(grid, col) != bottom)
		return (0);
	return (1);
}
