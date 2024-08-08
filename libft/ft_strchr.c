/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:41:59 by ivbatist          #+#    #+#             */
/*   Updated: 2022/11/22 21:10:39 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	cont;

	cont = 0;
	while (str[cont] != '\0' && str[cont] != (unsigned char)c)
	{
		cont++;
	}
	if (str[cont] == (unsigned char)c)
	{
		return ((char *) &str[cont]);
	}
	return (0);
}
