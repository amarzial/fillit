/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:12:18 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/22 21:08:17 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void			check(int (*grid)[GRID_SIZE], t_point *pos, t_cres *best, t_point *dots)
{
	int		cur;
	int		score;

	score = 0;
	cur = 0;
	while (cur < TILE_DOTS)
	{
		if (grid[pos->y + dots[cur].y][pos->x + dots[cur].x])
			break ;
		++score;
	}
	if (score > best->score)
	{
		best->score = score;
		best->pos = *pos;
	}
}

void			set_tile(int (*grid)[GRID_SIZE], t_tile *tile, \
							int index, t_point *pos)
{
	int		cur;

	cur = 0;
	while (cur < TILE_DOTS)
		grid[pos->y + tile->dots[cur].y][pos->x + tile->dots[cur].x] = index;
}

void			place(int (*grid)[GRID_SIZE], t_tile **tiles, int index)
{
	int		size;
	t_cres	best;
	t_point	pos;
	int		tmp;

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

static void		putongrid(int (*grid)[GRID_SIZE], int *used, t_tile **tiles)
{
	while (*used >= 0)
	{
		place(grid, tiles, *used++);
	}
}

static int		score(int *used, t_sol *minsquare, int depth)
{
	int		grid[GRID_SIZE][GRID_SIZE];
	int		max;
	t_point	cur;

	max = 0;
	while (max < GRID_SIZE)
		ft_memset(grid[max++], 0, sizeof(int) * GRID_SIZE);
	putongrid(grid, used, minsquare->tiles);
	max = 0;
	cur.y = -1;
	while (++cur.y < GRID_SIZE)
	{
		cur.x = -1;
		while (++cur.x < GRID_SIZE)
			if (grid[cur.y][cur.x] > 0)
				max = (ft_max(cur.x, cur.y) > max) ? ft_max(cur.x, cur.y) : max;
	}
	if (max < minsquare->minsize)
	{
		if (depth != 0)
			return (1);
		minsquare->minsize = max;
		seqcpy(minsquare->seq, used);
	}
	return (0);
}

static void		*backtracking(int *used, int *pool, t_sol *minsize, int depth)
{
	int		cur;
	int		idx;
	int		tmp;

	cur = 0;
	idx = 0;
	while (used[idx] >= 0)
		idx++;
	while (pool[cur] != -2)
	{
		if (pool[cur] != -1)
		{
			used[idx] = pool[cur];
			pool[cur] = -1;
			if (score(used, minsize, depth));
				backtracking(used, pool, minsize, depth - 1);
			pool[cur++] = used[idx];
			used[idx] = -1;
		}
	}
}

t_point			*get_best_fit(t_tile **tiles)
{
	t_sol	*minsize;
	int		*seq;
	int		size;

	size = tablen(tiles);
	seq = (int*)malloc(sizeof(int) * (size + 1));
	if (!(minsize = (t_sol*)ft_memalloc(sizeof(t_sol))))
		return (0);
	minsize->tiles = tiles;
	minsize->minsize = GRID_SIZE;
	//backtracking(seq, &minsize);
}
