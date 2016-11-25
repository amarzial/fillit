/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_algorithm_extras.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 03:16:40 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/25 15:55:02 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static void		check(char (*grid)[GRID_SIZE], t_point *pos, \
						t_cres *best, t_point *dots)
{
	int		score;
	int		cnt;
	t_point	cur;

	score = 0;
	cnt = 0;
	while (cnt < TILE_DOTS)
	{
		cur.x = pos->x + dots[cnt].x;
		cur.y = pos->y + dots[cnt].y;
		if (grid[cur.y][cur.x])
		{
			score = 0;
			break ;
		}
		score = ft_max(score, ft_max(cur.x, cur.y));
		cnt++;
	}
	if (score > 0 && score < best->score)
	{
		best->score = score;
		best->pos = *pos;
	}
}

static void		set_tile(char (*gd)[GRID_SIZE], t_tile *tile, \
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

void			place(char (*grid)[GRID_SIZE], t_tile **tiles, int index)
{
	int		size;
	t_cres	best;
	t_point	pos;

	best.score = GRID_SIZE;
	best.pos.x = 0;
	best.pos.y = 0;
	if ((size = gridsize(grid)) == 0)
	{
		set_tile(grid, tiles[index], index, &(best.pos));
		return ;
	}
	best.size = size++;
	pos.y = -1;
	while (++pos.y < size)
	{
		pos.x = -1;
		while (++pos.x < size)
			check(grid, &pos, &best, tiles[index]->dots);
	}
	set_tile(grid, tiles[index], index, &(best.pos));
}
