/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscraper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouma <onouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:25:16 by ounouma           #+#    #+#             */
/*   Updated: 2026/02/08 16:28:06 by onouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKYSCRAPER_H
# define SKYSCRAPER_H
# include <unistd.h>

typedef struct s_view
{
	int		top[4];
	int		bottom[4];
	int		left[4];
	int		right[4];
}			t_view;

typedef struct s_ctx
{
	int		grid[4][4];
	t_view	view;
}			t_ctx;

/* check_row*/
int			no_duplicate_line(int grid[4][4], int row);
int			is_visible_left(int grid[4][4], int row);
int			is_visible_right(int grid[4][4], int row);
int			check_row(int grid[4][4], int row, int left, int right);

/*check_col*/
int			no_duplicate_col(int grid[4][4], int col);
int			is_visible_top(int grid[4][4], int col);
int			is_visible_bottom(int grid[4][4], int col);
int			check_col(int grid[4][4], int col, int top, int bottom);

/*solver*/

int			solve(t_ctx *ctx);
int			is_safe(t_ctx *ctx, int row, int col, int num);
int			find_empty(int grid[4][4], int *row, int *col);
/*utils*/
void		ft_putnbr(int nb);
void		ft_putchar(char c);
/*main*/
int			parse_input(char *str, t_view *view);
void		print_grid(int grid[4][4]);
void		print_error(void);
#endif
