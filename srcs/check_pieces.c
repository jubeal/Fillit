/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:46:17 by jubeal            #+#    #+#             */
/*   Updated: 2018/11/28 18:31:45 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "fillit.h"

t_pieces	*create_lstlink(t_pieces **link)
{
	int			i;
	t_pieces	*tmp;

	i = -1;	
	tmp = *link;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_pieces *)malloc(sizeof(t_pieces))))
			return ((t_pieces *)0);
		if (!(tmp->next->piece = (short *)malloc(sizeof(short) * 16)))
			return ((t_pieces *)0);
		while (++i < 16)
			(tmp->next->piece)[i] = 0;
		return (tmp->next);
	}
	else
	{
		if (!(tmp = (t_pieces *)malloc(sizeof(t_pieces))))
			return ((t_pieces *)0);
		if (!(tmp->piece = (short *)malloc(sizeof(short) * 16)))
			return ((t_pieces *)0);
		while (++i < 16)
			(tmp->piece)[i] = 0;
		return (tmp);
	}
}

void		line_convert(t_pieces **curr, char *line, int which)
{
	if (line[0] == '#')
		((*curr)->piece)[which] += ft_power(2, 15);
	if (line[1] == '#')
		((*curr)->piece)[which] += ft_power(2, 14);
	if (line[2] == '#')
		((*curr)->piece)[which] += ft_power(2, 13);
	if (line[3] == '#')
		((*curr)->piece)[which] += ft_power(2, 12);
}
