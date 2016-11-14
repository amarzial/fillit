/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:13:57 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/14 17:20:43 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

static int		isvalid(char *tile, int size)
{
	int		cnt;
	int		blocks;

	cnt = 0;
	blocks = 0;
	if (size != TILE_SIZE)
		return (0);
	while (cnt < TILE_SIZE)
	{
		if ((cnt + 1) % 5)
		{
			if (tile[cnt] == '.' || (tile[cnt] == '#' && blocks < 4))
				++blocks;
			else
				return (0);
		}
		else
			if (tile[cnt] != '\n')
				return (0);
		++cnt;
	}
	return (1);
}

static int		hascontact(const t_point *p1, const t_point *p2)
{
	if (p1->x == p2->x && abs(p1->y - p2->y) == 1)
		return (1);
	if (p1->y == p2->y && abs(p1->x - p2->x) == 1)
		return (1);
	return (0);
}

static t_tile	*convert(t_tile *dest, char *tile, int size)
{
	t_point	p;
	t_tile	*ntl;
	int		idx;
	int		tmp;

	p.y = 0;
	idx = 0;
	if (!isvalid(tile, size) || (ntl = (t_tile*)ft_memalloc(sizeof(t_tile))))
		return (0);
	while (p.y < 4)
	{
		p.x = 0;
		while (p.x < 4)
			if (tile[(p.y * 5) + p.x] == '#')
			{
				tmp = 0;
				ntl->dots[idx++] = p;
				while (tmp < idx - 2)
					if (!hascontact(&(ntl->dots[idx - 1]), &(ntl->dots[tmp])))
						return (0);
			}
	}
	return (ntl);
}

//todo
int				read_tiles(int fd)
{
	int		cnt;
	char	buffer[TILE_SIZE];

	cnt = 0;
	while (1)
	{
		if ((cnt = read(fd, buffer, TILE_SIZE)) <= 0)
			break ;
		else
			return (0);
	}
}
