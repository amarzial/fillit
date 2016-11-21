/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:12:18 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/22 00:25:59 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int				score(int *used, t_sol *minsquare, int depth)
{
	int		grid[TILE_SIZE][TILE_SIZE];
	int		cnt;

	cnt = 0;
	while (cnt < TILE_SIZE)
		ft_memset(grid[cnt++], 0, sizeof(int) * 20);

}

static int		*backtracking(int *used, int *pool, t_sol *minsize, int depth)
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
	minsize->minsize = TILE_SIZE;
	//backtracking(seq, &minsize);
}
