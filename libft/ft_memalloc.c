/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:26:11 by jubeal            #+#    #+#             */
/*   Updated: 2018/11/27 15:47:18 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*ret;

	if (!(ret = (char *)malloc(size)))
		return ((void *)0);
	while (size)
	{
		ret[size - 1] = 0;
		size--;
	}
	return ((void *)ret);
}
