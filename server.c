/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:35:14 by ivbatist          #+#    #+#             */
/*   Updated: 2023/04/07 00:35:08 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	descodificar_msg(int sig)
{
	static int	casa_bi;
	static char	caracter;

	if (sig == SIGUSR1)
		caracter = caracter | (1 << casa_bi);
	casa_bi++;
	if (casa_bi == 8)
	{
		casa_bi = 0;
		write(1, &caracter, 1);
		caracter = 0;
	}
}

int	main(void)
{
	int						pid;
	struct sigaction		meu;

	meu.sa_handler = &descodificar_msg;
	sigemptyset(&meu.sa_mask);
	meu.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &meu, NULL);
	sigaction(SIGUSR2, &meu, NULL);
	pid = getpid();
	ft_printf("O numero PID do processo --> %d\n", pid);
	while (1)
		pause();
	return (0);
}
