/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:46:12 by ivbatist          #+#    #+#             */
/*   Updated: 2022/11/19 01:51:12 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	cont;

	cont = 0;
	while (cont < n)
	{
		if (((unsigned char *)s1)[cont] != ((unsigned char *)s2)[cont])
		{
			return (((unsigned char *)s1)[cont] - ((unsigned char *)s2)[cont]);
		}	
		cont++;
	}
	return (0);
}
