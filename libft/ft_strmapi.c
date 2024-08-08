/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 00:52:07 by ivbatist          #+#    #+#             */
/*   Updated: 2022/11/26 00:52:26 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*here;

	i = 0;
	if (!s || !f)
		return (NULL);
	here = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (here == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		here[i] = f(i, s[i]);
		i++;
	}
	here[i] = '\0';
	return (here);
}
