/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:13:38 by ivbatist          #+#    #+#             */
/*   Updated: 2024/09/27 18:56:48 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	encoder(int pid, char *str)
{
	int	i;
	int	bin;
	int	c;

	bin = 0;
	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		while (bin < 8)
		{
			if ((c & 1) == 1)
				kill(pid, SIGUSR1);
			else if ((c & 1) == 0)
				kill(pid, SIGUSR2);
			usleep(200);
			c = c >> 1;
			bin++;
		}
		i++;
		bin = 0;
	}
}

bool	ckargs(int ac)
{
	if (ac != 3)
		return (ft_printf ("[Error]: Try ./client <server_pid> <your_msg>"), false);
	return (true);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ckargs(ac))
	{
		pid = ft_atoi(av[1]);
		encoder(pid, av[2]);
		encoder(pid, "\n");
	}
	return (0);
}
