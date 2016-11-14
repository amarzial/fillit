/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:13:57 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/14 10:44:52 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <fcntl.h>

int		is_valid(char *tile, int size)
{
	if (size != TILE_SIZE)
		return (0);
	
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
