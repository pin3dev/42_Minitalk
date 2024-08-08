/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:40:53 by ivbatist          #+#    #+#             */
/*   Updated: 2022/11/12 17:36:37 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))
		|| ((c >= '0') && (c <= '9')))
	{
		return (2048);
	}
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	char c;

	c = 'b';
	printf("o caracter e um alnum? %d \n",ft_isalnum(c));
	c = 'w';
	printf("o caracter e um alnum? %d \n",ft_isalnum(c));
	c = 'C';
	printf("o caracter e um alnum? %d \n",ft_isalnum(c));
	c = 'y';
	printf("o caracter e um alnum? %d \n",ft_isalnum(c));
	c = '3';
	printf("o caracter e um alnum? %d \n",ft_isalnum(c));
	c = '+';
	printf("o caracter e um alnum? %d \n",ft_isalnum(c));
	c = '-';
	printf("o caracter e um alnum? %d \n",ft_isalnum(c));
	return(0);
}*/
