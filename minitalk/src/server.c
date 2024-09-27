/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:35:14 by ivbatist          #+#    #+#             */
/*   Updated: 2024/09/27 19:01:18 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	decoder(int sig)
{
	static int	bin;
	static char	c;

	if (sig == SIGUSR1)
		c = c | (1 << bin);
	bin++;
	if (bin == 8)
	{
		bin = 0;
		write(1, &c, 1);
		c = 0;
	}
}

int	main(void)
{
	int						pid;
	//struct sigaction		sig;

	pid = getpid();
	ft_printf("Process PID number --> %d\n", pid);
	
/* 	sig.sa_handler = &decoder;
	sig.sa_flags = SA_RESTART;
	
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL); */
	signal(SIGUSR1, decoder);
	signal(SIGUSR2, decoder);
	
	while (1)
		pause();
	return (0);
}


