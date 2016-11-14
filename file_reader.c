/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:13:57 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/14 14:41:25 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int		isvalid(char *tile, int size)
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

int		convert(t_tile *dest, char *tile, int size)
{
	t_point	p;
	t_tile	ntl;
	int		idx;

	p.y = 0;
	idx = 0;
	if (!isvalid(tile, size) || (ntl = (t_tile*(ft_memalloc(sizeof(t_tile))))))
		return (0);
	while (p.y < 4)
	{
		p.x = 0;
		while (p.x < 4)
			if (tile[(p.y * 5) + p.x] == '#')
				newtile.dots[idx] = p;
	}
}

int		read_tiles(int fd)
{
	int		cnt;
	char	buffer[TILE_SIZE];

	cnt = 0;
	while (1)
	{
		if ((cnt = read(fd, buffer, TILE_SIZE)) <= 0)
			break ;
		if (is_valid(buffer, cnt))
			convert();
		else
			return (0);
	}
}
