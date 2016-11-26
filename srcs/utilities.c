/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 10:38:35 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/26 13:52:19 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

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
