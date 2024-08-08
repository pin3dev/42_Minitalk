/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:32:10 by ivbatist          #+#    #+#             */
/*   Updated: 2022/11/19 01:39:47 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	int	cont;

	cont = 0;
	while (n > 0)
	{
		if (((unsigned char *) str)[cont] == (unsigned char)c)
			return ((unsigned char *)str + cont);
		cont++;
		n--;
	}
	return (NULL);
}
