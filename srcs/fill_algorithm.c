/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:12:18 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/18 20:09:51 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static t_tile	**remove_tile(t_tile **src, t_tile *tile)
{
	t_tile	**out;
	t_tile	**tmp;

	if (!(*src))
		return (0);
	if ((out = (t_tile**)ft_memalloc(sizeof(t_tile*) * MAX_TILES)))
	{
		tmp = out;
		while (*src)
		{
			if (*src != tile)
				*tmp++ = *src;
			++src;
		}
	}
	return (out);
}

static t_point	*backtracking(

t_point			*get_best_fit(t_tile **tiles)
{
	int		minsize;
	
}
