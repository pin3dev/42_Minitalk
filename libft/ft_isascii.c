/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:50:32 by ivbatist          #+#    #+#             */
/*   Updated: 2022/11/12 17:50:51 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch;
	ch = 0x31;

	printf("o caracter do ASCII e o: [%d]\n", ft_isascii(ch));
	ch = 0x00;
	printf("o caracter do ASCII e o: [%d]\n", ft_isascii(ch));
}*/
