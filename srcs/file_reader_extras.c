/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader_extras.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 02:37:13 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/24 03:24:31 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

static int		checksize(const t_point *p)
{
	int		cur;
	t_point	size;

	cur = -1;
	size.x = 0;
	size.y = 0;
	while (++cur < 4)
	{
		size.x = ft_max(size.x, p[cur].x);
		size.y = ft_max(size.y, p[cur].y);
	}
	size.x++;
	size.y++;
	if ((size.x == 1 && size.y == 4) || (size.x == 2 && size.y <= 3) || \
		(size.x == 3 && size.y == 2) || (size.x == 4 && size.y == 1))
		return (1);
	return (0);
}

static int		hascontact(const t_point *p)
{
	int		cur;
	int		cnt;
	int		contact;

	cur = -1;
	while (++cur < 4)
	{
		cnt = -1;
		contact = 0;
		while (++cnt < 4)
		{
			if (cnt != cur)
			{
				if ((p[cur].x == p[cnt].x && (ft_abs(p[cur].y - p[cnt].y) \
								== 1)) || (p[cur].y == p[cnt].y && \
								(ft_abs(p[cur].x - p[cnt].x)) == 1))
					contact = 1;
			}
		}
		if (!contact)
			return (0);
	}
	return (checksize(p));
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
	if (!hascontact(ntl->dots))
		ft_memdel((void*)&ntl);
	return (ntl);
}
