/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader_extras.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 02:37:13 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/24 12:28:39 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point		g_patterns[19][4] =
{
	{{0, 0}, {1, 0}, {2, 0}, {3, 0}},
	{{0, 0}, {1, 0}, {0, 1}, {1, 1}},
	{{0, 0}, {0, 1}, {0, 2}, {0, 3}},
	{{0, 0}, {0, 1}, {1, 1}, {2, 1}},
	{{0, 0}, {1, 0}, {0, 1}, {0, 2}},
	{{0, 0}, {1, 0}, {2, 0}, {2, 1}},
	{{1, 0}, {1, 1}, {0, 2}, {1, 2}},
	{{2, 0}, {0, 1}, {1, 1}, {2, 1}},
	{{0, 0}, {0, 1}, {0, 2}, {1, 2}},
	{{0, 0}, {1, 0}, {2, 0}, {0, 1}},
	{{0, 0}, {1, 0}, {1, 1}, {1, 2}},
	{{1, 0}, {0, 1}, {1, 1}, {2, 1}},
	{{0, 0}, {0, 1}, {1, 1}, {0, 2}},
	{{0, 0}, {1, 0}, {2, 0}, {1, 1}},
	{{1, 0}, {0, 1}, {1, 1}, {1, 2}},
	{{1, 0}, {2, 0}, {0, 1}, {1, 1}},
	{{0, 0}, {0, 1}, {1, 1}, {1, 2}},
	{{0, 0}, {1, 0}, {1, 1}, {2, 1}},
	{{1, 0}, {0, 1}, {1, 1}, {0, 2}}
};

static int		isvalid(char *tile)
{
	int		cnt;
	int		blocks;

	cnt = 0;
	blocks = 0;
	while (cnt < TILE_SIZE)
	{
		if ((cnt + 1) % 5)
		{
			if (tile[cnt] == '#')
				++blocks;
			else if (tile[cnt] != '.')
				return (0);
			if (blocks > TILE_DOTS)
				return (0);
		}
		else
		{
			if (tile[cnt] != '\n')
				return (0);
		}
		++cnt;
	}
	return (1);
}

static int	ptscmp(const t_point *p1, const t_point *p2)
{
	if ((p1->x == p2->x) && (p1->y == p2->y))
		return (1);
	return (0);
}

static int	istetrimino(const t_point *pts)
{
	int	cur;
	int	idx;
	int	count;

	cur = 0;
	while (cur < 19)
	{
		idx = 0;
		count = 0;
		while (idx < 4)
		{
			if (ptscmp((pts + idx), (g_patterns[cur] + idx)))
				count++;
			idx++;
		}
		if (count == 4)
			return (1);
		cur++;
	}
	return (0);
}

t_tile  	*convert(char *tile, int size)
{
	t_point	p;
	t_tile	*ntl;
	int		idx;

	p.y = -1;
	idx = 0;
	if (size != TILE_SIZE || !isvalid(tile) || \
			!(ntl = (t_tile*)ft_memalloc(sizeof(t_tile))))
		return (0);
	while (++p.y < 4)
	{
		p.x = -1;
		while (++p.x < 4)
			if (tile[(p.y * 5) + p.x] == '#')
			{
				ntl->dots[idx++] = p;
			}
	}
	set_topleft(ntl);
	if (!istetrimino(ntl->dots))
		ft_memdel((void*)&ntl);
	return (ntl);
}
