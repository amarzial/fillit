/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:05:34 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/22 00:26:06 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define TILE_SIZE 20
# define MAX_TILES 26
# include "libft.h"

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_tile
{
	t_point	dots[4];
}				t_tile;

typedef struct	s_sol
{
	int		seq[MAX_TILES];
	size_t	minsize;
	t_tile	**tiles;
}				t_sol;

t_tile			**get_tiles(char *filename);

void			set_topleft(t_tile *tile);

void			tabdel(t_tile ***tile);

int				tablen(t_tile **tab);

#endif
