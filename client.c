/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:13:38 by ivbatist          #+#    #+#             */
/*   Updated: 2024/08/08 17:08:36 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdbool.h>

void	msgEncoder(int pid, char *str)
{
	int	i;
	int	binaryBase;
	int	character;

	binaryBase = 0;
	i = 0;
	while (str[i] != '\0')
	{
		character = str[i];
		while (binaryBase < 8)
		{
			if ((character & 1) == 1)
				kill(pid, SIGUSR1);
			else if ((character & 1) == 0)
				kill(pid, SIGUSR2);
			usleep(200);
			character = character >> 1;
			binaryBase++;
		}
		i++;
		binaryBase = 0;
	}
}

bool	checkArgsAmount(int argc)
{
	if (argc != 3)
		return (ft_printf ("Usage Error: [try] ./client <server pid> <your msg>"), false);
	return (true);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (checkArgsAmount(argc))
	{
		pid = ft_atoi(argv[1]);
		msgEncoder(pid, argv[2]);
		msgEncoder(pid, "\n");
	}
	return (0);
}
