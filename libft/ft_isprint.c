/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:53:08 by ivbatist          #+#    #+#             */
/*   Updated: 2022/11/12 18:35:42 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int c;

	c = '!';
	printf("o caracter e printavel: %d\n", isprint(c));
	
	c = 0x00;
	printf("o caracter e printavel: %d\n", ft_isprint(c));
}*/
