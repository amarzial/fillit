/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_algorithm_extras.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 03:16:40 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/23 03:16:42 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static void		check(int (*grid)[GRID_SIZE], t_point *pos, \
						t_cres *best, t_point *dots)
{
	int		score;

	score = 0;
	while (score < TILE_DOTS)
	{
		if (grid[pos->y + dots[score].y][pos->x + dots[score].x])
			break ;
		++score;
	}
	if (score > best->score)
	{
		best->score = score;
		best->pos = *pos;
	}
}

static void		set_tile(int (*gd)[GRID_SIZE], t_tile *tile, \
							int index, t_point *pos)
{
	int		cur;

	cur = 0;
	while (cur < TILE_DOTS)
	{
		gd[pos->y + tile->dots[cur].y][pos->x + tile->dots[cur].x] = index + 1;
		cur++;
	}
}

void			place(int (*grid)[GRID_SIZE], t_tile **tiles, int index)
{
	int		size;
	t_cres	best;
	t_point	pos;

	size = -1;
	best.score = 0;
	best.pos.x = 0;
	best.pos.y = 0;
	while (++size < GRID_SIZE)
	{
		pos.y = -1;
		pos.x = size;
		while (++pos.y < size)
			check(grid, &pos, &best, tiles[index]->dots);
		pos.x = -1;
		pos.y = size;
		while (++pos.x < size + 1)
			check(grid, &pos, &best, tiles[index]->dots);
	}
	set_tile(grid, tiles[index], index, &(best.pos));
}

