/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouma <onouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:13:15 by ounouma           #+#    #+#             */
/*   Updated: 2026/02/08 15:29:49 by onouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

// fonction qui cherche les cases vides
int	find_empty(int grid[4][4], int *row, int *col)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (grid[i][j] == 0)
			{
				*row = i;
				*col = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
/*function that check if the number is safe*/

int	is_safe(t_ctx *ctx, int row, int col, int num)
{
	int	j;
	int	i;

	ctx->grid[row][col] = num;
	if (!no_duplicate_line(ctx->grid, row) || !no_duplicate_col(ctx->grid, col))
		return (ctx->grid[row][col] = 0, 0);
	j = 0;
	while (j < 4 && ctx->grid[row][j] != 0)
		j++;
	if (j == 4 && !check_row(ctx->grid, row, ctx->view.left[row],
			ctx->view.right[row]))
		return (ctx->grid[row][col] = 0, 0);
	i = 0;
	while (i < 4 && ctx->grid[i][col] != 0)
		i++;
	if (i == 4 && !check_col(ctx->grid, col, ctx->view.top[col],
			ctx->view.bottom[col]))
		return (ctx->grid[row][col] = 0, 0);
	ctx->grid[row][col] = 0;
	return (1);
}
/*solve recursively first it finds en empty place
 *than recursivly check evry number if its safe*/

int	solve(t_ctx *ctx)
{
	int	row;
	int	col;
	int	num;

	num = 1;
	if (!find_empty(ctx->grid, &row, &col))
		return (1);
	while (num <= 4)
	{
		if (is_safe(ctx, row, col, num))
		{
			ctx->grid[row][col] = num;
			if (solve(ctx))
				return (1);
			ctx->grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
