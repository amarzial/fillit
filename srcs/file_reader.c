/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:13:57 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/16 19:51:20 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

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
			if (blocks > 4)
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
								(ft_abs(p[cur].x - p[cnt].x))
								== 1))
					contact = 1;
			}
		}
		if (!contact)
			return (0);
	}
	return (1);
}

static t_tile	*convert(char *tile, int size)
{
	t_point	p;
	t_tile	*ntl;
	int		idx;
	int		tmp;

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
				tmp = 0;
				ntl->dots[idx++] = p;
			}
	}
	if (!hascontact(ntl->dots))
		ft_memdel((void*)&ntl);
	return (ntl);
}

static t_tile	**read_tiles(int fd)
{
	int		cnt;
	int		b_cnt;
	char	buffer[TILE_SIZE];
	t_tile	**tiles;

	cnt = 0;
	if (!(tiles = (t_tile**)ft_memalloc(sizeof(t_tile*) * (MAX_TILES + 1))))
		return (0);
	while (1)
	{
		if ((b_cnt = read(fd, buffer, TILE_SIZE)) > 0)
		{
			if ((tiles[cnt++] = convert(buffer, b_cnt)) == 0)
			{
				ft_tabdel((void***)&tiles);
				break ;
			}
			b_cnt = read(fd, buffer, 1);
			if ((b_cnt == 1 && buffer[0] == '\n'))
				continue ;
		}
		break ;
	}
	return (tiles);
}

t_tile			**get_tiles(char *filename)
{
	t_tile	**out;
	int		fd;

	if ((fd = open(filename, O_RDONLY)) <= 0)
		return (0);
	if ((out = read_tiles(fd)))
	{
		close(fd);
		return (out);
	}
	return (0);
}
