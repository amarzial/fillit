/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:12:18 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/26 13:27:00 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int				outofbounds(t_tile *tile, int size)
{
	int		cnt;

	cnt = 0;
	while (cnt < 4)
	{
		if ((tile->pos.x + tile->dots[cnt].x >= size) || \
		(tile->pos.y + tile->dots[cnt].y >= size))
			return (0);
		cnt++;
	}
	return (1);
}

int				checkiffits(t_tile **tiles, int index, int size)
{
	int		cnt;
	int		pts;
	t_tile	*tile;
	t_point	p;

	tile = tiles[index];
	while (index--)
	{
		cnt = 0;
		while (cnt < 4)
		{
			p.x = tiles[index]->pos.x + tiles[index]->dots[cnt].x;
			p.y = tiles[index]->pos.y + tiles[index]->dots[cnt++].y;
			pts = 0;
			while (pts < 4)
			{
				if (p.x == tile->dots[pts].x + tile->pos.x && \
				p.y == tile->dots[pts].y + tile->pos.y)
					return (0);
				pts++;
			}
		}
	}
	return (outofbounds(tile, size));
}

int				backtracking(t_tile **tiles, int index, int *size)
{
	t_tile	*block;

	if (!tiles[index])
		return (1);
	block = tiles[index];
	block->pos.y = 0;
	while (block->pos.y < *size)
	{
		block->pos.x = 0;
		while (block->pos.x < *size)
		{
			if (checkiffits(tiles, index, *size))
				if (backtracking(tiles, index + 1, size))
					return (1);
			block->pos.x++;
		}
		block->pos.y++;
	}
	return (0);
}

void			get_solution(t_tile **tiles)
{
	int		size;

	size = 0;
	while (!backtracking(tiles, 0, &size))
		size++;
}
