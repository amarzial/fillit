/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:12:18 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/23 17:58:50 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static void		ongrid(int (*grid)[GRID_SIZE], const int *used, t_tile **tiles)
{
	while (*used >= 0)
	{
		place(grid, tiles, *used++);
	}
}

static int		score(const int *used, t_sol *minsquare, int depth)
{
	int		grid[GRID_SIZE][GRID_SIZE];
	int		max;
	t_point	cur;

	max = 0;
	while (max < GRID_SIZE)
		ft_memset(grid[max++], 0, sizeof(int) * GRID_SIZE);
	ongrid(grid, used, minsquare->tiles);
	max = 0;
	cur.y = -1;
	while (++cur.y < GRID_SIZE)
	{
		cur.x = -1;
		while (++cur.x < GRID_SIZE)
			if (grid[cur.y][cur.x] > 0)
				max = (ft_max(cur.x, cur.y) > max) ? ft_max(cur.x, cur.y) : max;
	}
	if (++max < minsquare->minsize)
	{
		if (depth != 0)
			return (1);
		putgrid(grid);
		minsquare->minsize = max;
		seqcpy(minsquare->seq, used);
	}
	return (0);
}

static void		backtracking(int *used, int *pool, t_sol *minsize, int depth)
{
	int		cur;
	int		idx;

	cur = 0;
	idx = 0;
	while (used[idx] >= 0)
		idx++;
	while (pool[cur] != EOA)
	{
		if (pool[cur] != BLANK)
		{
			used[idx] = pool[cur];
			pool[cur] = BLANK;
			if (score(used, minsize, depth))
				backtracking(used, pool, minsize, depth - 1);
			pool[cur] = used[idx];
			used[idx] = BLANK;
		}
		cur++;
	}
}

t_sol			*get_solution(t_tile **tiles)
{
	t_sol	*minsize;
	int		*seq;
	int		*pool;
	int		size;
	int		cnt;

	size = tablen(tiles);
	seq = (int*)malloc(sizeof(int) * (size + 1));
	pool = (int*)malloc(sizeof(int) * (size + 1));
	minsize = (t_sol*)ft_memalloc(sizeof(t_sol));
	if (!seq && !pool && !minsize)
		return (0);
	cnt = size;
	while (cnt)
	{
		seq[cnt - 1] = BLANK;
		pool[cnt - 1] = cnt - 1;
		cnt--;
	}
	seq[size] = BLANK;
	pool[size] = EOA;
	minsize->tiles = tiles;
	minsize->minsize = GRID_SIZE;
	backtracking(seq, pool, minsize, size - 1);
	return (minsize);
}
