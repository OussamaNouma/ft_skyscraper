/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ounouma <ounouma@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:12:56 by ounouma           #+#    #+#             */
/*   Updated: 2026/02/08 11:12:58 by ounouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

int	no_duplicate_line(int grid[4][4], int row)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (grid[row][i] != 0 && grid[row][i] == grid[row][j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_visible_left(int grid[4][4], int row)
{
	int	max;
	int	visible;
	int	i;

	max = 0;
	visible = 0;
	i = 0;
	while (i < 4)
	{
		if (grid[row][i] > max)
		{
			max = grid[row][i];
			visible++;
		}
		i++;
	}
	return (visible);
}

int	is_visible_right(int grid[4][4], int row)
{
	int	max;
	int	visible;
	int	i;

	max = 0;
	visible = 0;
	i = 3;
	while (i >= 0)
	{
		if (grid[row][i] > max)
		{
			max = grid[row][i];
			visible++;
		}
		i--;
	}
	return (visible);
}

int	check_row(int grid[4][4], int row, int left, int right)
{
	if (!no_duplicate_line(grid, row))
		return (0);
	if (is_visible_left(grid, row) != left)
		return (0);
	if (is_visible_right(grid, row) != right)
		return (0);
	return (1);
}
