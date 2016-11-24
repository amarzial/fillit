/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:13:57 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/24 13:02:07 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

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
		ft_memset(buffer, 0, TILE_SIZE);
		if ((b_cnt = read(fd, buffer, TILE_SIZE)) > 0)
		{
			if ((tiles[cnt++] = convert(buffer, b_cnt)) == 0)
				return (0);
			if (((b_cnt = read(fd, buffer, 1)) == 1 && buffer[0] == '\n'))
				continue ;
		}
		break ;
	}
	if (buffer[0] == 0 || b_cnt == 1)
		return (0);
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
