/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_mgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 23:57:21 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/18 00:27:04 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_topleft(t_tile	*tile)
{
	t_point	p_min;
	t_point	*pt;
	int		cur;

	if (!tile)
		return ;
	p_min.x = 4;
	p_min.y = 4;
	cur = 0;
	while (cur < 4)
	{
		pt = &tile->dots[cur++];
		p_min.x = (p_min.x < pt->x) ? p_min.x : pt->x;
		p_min.y = (p_min.y < pt->y) ? p_min.y : pt->y;
	}
	cur = 0;
	while (cur < 4)
	{
		tile->dots[cur].x -= p_min.x;
		tile->dots[cur++].y -= p_min.y;
	}
}
