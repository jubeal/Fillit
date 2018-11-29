/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:41:24 by jubeal            #+#    #+#             */
/*   Updated: 2018/11/29 14:51:34 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "get_next_line.h"

typedef struct				s_pieces
{
	unsigned short			*piece;
	struct s_pieces			*next;
}							t_pieces;

t_pieces					*create_lstlink(t_pieces **link);
void						line_convert(t_pieces **curr, char *line,
										int which);
//void						innitialize_pieces(t_pieces **head);
int							check_pieces(t_pieces **head);
#endif
