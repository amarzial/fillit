/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 10:38:35 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/22 00:26:03 by amarzial         ###   ########.fr       */
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


