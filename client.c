/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:13:38 by ivbatist          #+#    #+#             */
/*   Updated: 2023/04/06 20:47:48 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	codificar_msg(int pid, char *s)
{
	int	i;
	int	casa_bi;
	int	caracter;

	casa_bi = 0;
	i = 0;
	while (s[i] != '\0')
	{
		caracter = s[i];
		while (casa_bi < 8)
		{
			if ((caracter & 1) == 1)
				kill(pid, SIGUSR1);
			else if ((caracter & 1) == 0)
				kill(pid, SIGUSR2);
			usleep(200);
			caracter = caracter >> 1;
			casa_bi++;
		}
		i++;
		casa_bi = 0;
	}
}

int	verif_param(int argc)
{
	int	verif;

	verif = 0;
	if (argc != 3)
		ft_printf ("Verifique entradas: './client' 'pid' 'sua msg'");
	else
		verif = 1;
	return (verif);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (verif_param(argc) == 1)
	{
		pid = ft_atoi(argv[1]);
		codificar_msg(pid, argv[2]);
		codificar_msg(pid, "\n");
	}
	return (0);
}
