/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:17:37 by ivbatist          #+#    #+#             */
/*   Updated: 2022/11/19 01:19:29 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	if ((c >= 0x41 && c <= 0x5a))
	{
		return (c + 32);
	}
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	char c;

	c = 'b';
	printf("o char [%c] tranformado por ft_tolower fica: %c \n",c, ft_tolower(c));
	printf("o char [%c] tranformado por tolower fica: %c \n",c, tolower(c));
	c = 'G';
	printf("o char [%c] tranformado por ft_tolower fica: %c \n",c, ft_tolower(c));
	printf("o char [%c] tranformado por tolower fica: %c \n",c, tolower(c));
}*/
