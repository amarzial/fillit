/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:05:34 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/24 17:29:14 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define TILE_SIZE 20
# define GRID_SIZE 20
# define MAX_TILES 26
# define TILE_DOTS 4
# define EOA -2
# define BLANK -1
# define OUT_CHARSET ".ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# include "libft.h"

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_tile
{
	t_point	dots[TILE_DOTS];
}				t_tile;

typedef struct	s_sol
{
	int		seq[MAX_TILES];
	int		minsize;
	t_tile	**tiles;
}				t_sol;

typedef	struct	s_cres
{
	t_point	pos;
	int		score;
	int		size;
}				t_cres;

t_tile			**get_tiles(char *filename);

t_sol			*get_solution(t_tile **tiles);

void			set_topleft(t_tile *tile);

void			tabdel(t_tile ***tile);

int				tablen(t_tile **tab);

void			seqcpy(int *dest, const int *src);

void			place(int (*grid)[GRID_SIZE], t_tile **tiles, int index);

int				gridsize(int (*grid)[GRID_SIZE]);

void			putgrid(int (*grid)[GRID_SIZE]);

t_tile			*convert(char *tile, int size);

#endif
