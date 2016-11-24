/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:23:14 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/24 01:03:58 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static void	printgrid(t_sol *solution)
{
	int		size;
	int		cnt;
	int		grid[GRID_SIZE][GRID_SIZE];

	size = tablen(solution->tiles);
	cnt = 0;
	while (cnt < GRID_SIZE)
		ft_memset(grid[cnt++], 0, sizeof(int) * GRID_SIZE);
	cnt = 0;
	while (cnt < size)
		place(grid, solution->tiles, solution->seq[cnt++]);
	cnt = 0;
	while (cnt < solution->minsize)
	{
		size = 0;
		while (size < solution->minsize)
		{
			ft_putchar(OUT_CHARSET[grid[cnt][size++]]);
		}
		ft_putchar('\n');
		cnt++;
	}
}

int			main(int argc, char *argv[])
{
	t_tile	**tiles;
	t_sol	*solution;

	if (argc != 2)
		return (argc);
	tiles = get_tiles(argv[1]);
	if (!tiles)
		return (1);
	solution = get_solution(tiles);
	printgrid(solution);
	return (0);
}
