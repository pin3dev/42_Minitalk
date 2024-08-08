/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 00:17:55 by ivbatist          #+#    #+#             */
/*   Updated: 2022/11/19 01:01:06 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	cont;

	if (!dst && !src)
	{
		return (0);
	}
	cont = 0;
	if (((size_t)dst) - ((size_t)src) < n)
	{
		cont = n - 1;
		while (cont < n)
		{
			((unsigned char *)dst)[cont] = ((unsigned char *)src)[cont];
			cont--;
		}
	}
	else
	{
		while (cont < n)
		{
			((unsigned char *)dst)[cont] = ((unsigned char *)src)[cont];
			cont++;
		}
	}
	return (dst);
}
