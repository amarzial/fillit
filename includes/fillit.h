/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:05:34 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/25 21:39:56 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define TILE_SIZE 20
# define GRID_SIZE 10
# define MAX_TILES 26
# define TILE_DOTS 4
# define EOA -2
# define BLANK -1
# define OUT_CHARSET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# include "libft.h"

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_tile
{
	t_point	pos;
	t_point	dots[TILE_DOTS];
}				t_tile;

t_tile			**get_tiles(char *filename);

void			get_solution(t_tile **tiles);

void			set_topleft(t_tile *tile);

void			tabdel(t_tile ***tile);

int				tablen(t_tile **tab);

void			seqcpy(int *dest, const int *src);

int				gridsize(char (*grid)[GRID_SIZE]);

void			putgrid(int (*grid)[GRID_SIZE]);

t_tile			*convert(char *tile, int size);

#endif
