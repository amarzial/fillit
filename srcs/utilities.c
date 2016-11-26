/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 10:38:35 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/26 13:28:14 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void		tabdel(t_tile ***tiles)
{
	int cnt;
	int *tmp;

	cnt = 0;
	while ((*tiles)[cnt])
	{
		tmp = (int*)(*tiles)[cnt];
		if (*tmp)
			free((*tiles)[cnt]);
		(*tiles)[cnt++] = 0;
	}
	free((*tiles));
	*tiles = 0;
}

int			tablen(t_tile **tab)
{
	t_tile **tmp;

	tmp = tab;
	while (*tmp)
		tmp++;
	return (tmp - tab);
}

void		seqcpy(int *dest, const int *src)
{
	while (*src >= 0)
		*dest++ = *src++;
	*dest = *src;
}

int			gridsize(char (*grid)[GRID_SIZE])
{
	int		size;
	int		x;
	int		y;

	size = 0;
	y = 0;
	while (y < GRID_SIZE)
	{
		x = 0;
		while (x < GRID_SIZE)
		{
			if (grid[y][x] != '.')
				size = ft_max(size, ft_max(x, y));
			x++;
		}
		y++;
	}
	if (size == 0)
		return (size);
	return (size + 1);
}
