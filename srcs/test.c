/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:23:14 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/25 16:12:24 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static void	printgrid(t_tile **tiles)
{
	int		cnt;
	int		idx;
	char	grid[GRID_SIZE][GRID_SIZE];
	t_point	dest;

	cnt = 0;
	while (cnt < GRID_SIZE)
		ft_memset(grid[cnt++], '.', GRID_SIZE);
	cnt = -1;
	while (tiles[++cnt])
	{
		idx = 0;
		while (idx < 4)
		{
			dest.x = tiles[cnt]->pos.x + tiles[cnt]->dots[idx].x;
			dest.y = tiles[cnt]->pos.y + tiles[cnt]->dots[idx++].y;
			grid[dest.y][dest.x] = OUT_CHARSET[cnt];
		}
	}
	cnt = 0;
	idx = gridsize(grid);
	while (cnt < idx)
		ft_writeendl(1, grid[cnt++], idx);
}

static void	showusage(int args)
{
	if (args == 1)
		ft_putstr_fd("fillit: missing operand file\n", 2);
	else if (args > 2)
		ft_putstr_fd("too many arguments.\n", 2);
}

int			main(int argc, char *argv[])
{
	t_tile	**tiles;

	if (argc != 2)
	{
		showusage(argc);
		return (0);
	}
	tiles = get_tiles(argv[1]);
	if (!tiles)
	{
		ft_putstr("error\n");
		return (1);
	}
	get_solution(tiles);
	printgrid(tiles);
	return (0);
}
