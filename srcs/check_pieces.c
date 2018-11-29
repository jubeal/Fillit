/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:46:17 by jubeal            #+#    #+#             */
/*   Updated: 2018/11/29 15:49:19 by jubeal           ###   ########.fr       */
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
		tmp = tmp->next;
	}
	else
	{
		if (!(tmp = (t_pieces *)malloc(sizeof(t_pieces))))
			return ((t_pieces *)0);
	}
	if (!(tmp->piece = (unsigned short *)malloc(sizeof(unsigned short)
					* 16)))
		return ((t_pieces *)0);
	while (++i < 16)
		(tmp->piece)[i] = 0;
	tmp->next = NULL;
	return (tmp);
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

void		innitialize_pieces(t_pieces **head)
{
	t_pieces	*tmp;

	tmp = *head;
	while (tmp)
	{
		ft_reset_piece(tmp);
		tmp = tmp->next;
	}
}

int			check_form(t_pieces *tmp)
{
	int		i;
	int		j;
	int		link;

	link = 0;
	i = -1;
	while ((++i) < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if ((tmp->piece)[i] & (0x8000 >> j))
			{
				if (j > 0 && (tmp->piece)[i] & (0x8000 >> (j - 1)))
					link++;
				if (j < 3 && (tmp->piece)[i] & (0x8000 >> (j + 1)))
					link++;
				if (i > 0 && (tmp->piece)[i - 1] & (0x8000 >> j))
					link++;
				if (i < 3 && (tmp->piece)[i + 1] & (0x8000 >> j))
					link++;
			}
		}
	}
	return (link);
}

int			check_pieces(t_pieces **head)
{
	t_pieces	*tmp;
	int			i;
	int			ret;
	int			j;

	tmp = *head;
	ret = 0;
	while (tmp)
	{
		i = -1;
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
				if ((tmp->piece)[i] & (0x8000 >> j))
					ret++;
		}
		if (ret != 4 || check_form(tmp) < 6)
			return (0);
		ret = 0;
		tmp = tmp->next;
	}
	return (1);
}
