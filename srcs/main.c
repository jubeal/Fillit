/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:41:01 by jubeal            #+#    #+#             */
/*   Updated: 2018/11/27 18:51:36 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <fcntl.h>

int		check_line(char *str, int type)
{
	int		i;

	i = -1;
	if (type == 0)
	{
		if (ft_strlen(str) != 4)
			return (0);
		while (str[++i])
			if (str[i] != '.' && str[i] != '#')
				return (0);
	}
	else
		if (ft_strlen(str) != 0)
			return (0);
	return (1);
}

int		check_file(int fd, t_list_pieces **head)
{
	char			*line;
	int				nbr_lines;
	t_list_pieces	*tmp;

	nbr_lines = 1;
	tmp = *head;
	tmp->piece = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (!tmp->piece && !(tmp->piece = (char **)malloc(sizeof(char *) * 4)))
			return (0);
		tmp->next = NULL;
		if ((nbr_lines % 5))
		{
			if (!(check_line(line, 0)))
				return (0);
			else if ((nbr_lines++))
				(tmp->piece)[(nbr_lines % 5) - 1] = ft_strdup(line);
		}
		else
		{
			if (!(check_line(line, 1)))
				return (0);
			else
			{
				tmp = tmp->next;
				if (!(tmp = (t_list_pieces *)malloc(sizeof(t_list_pieces))))
					return (0);
				tmp->piece = NULL;
				nbr_lines++;
			}
		}
	}
	return (1);
}

int		errors(int type)
{
	if (type == 1)
		ft_putstr("usage: ./fillit pieces_file\n");
	if (type == 2)
		ft_putstr("error\n");
	return (1);
}

int		main(int ac, char **av)
{
	int				fd;
	t_list_pieces	*head;

	if (ac != 2)
		return (errors(1));
	if (!(head = (t_list_pieces *)malloc(sizeof(t_list_pieces))))
		return (errors(2));
	head->next = NULL;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (errors(2));
	if (!check_file(fd, &head))
		return (errors(2));
	/*while (head != NULL)
	{
		ft_putstab(head->piece);
		head = head->next;
	}*/
	ft_putstr("check!\n");
}
