/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:05:34 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/18 13:09:27 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define TILE_SIZE 20
# define MAX_TILES 26

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_tile
{
	t_point	dots[4];
}				t_tile;

t_tile			**get_tiles(char *filename);

void			set_topleft(t_tile *tile);

#endif
