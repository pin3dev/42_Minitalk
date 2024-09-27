/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:35:14 by ivbatist          #+#    #+#             */
/*   Updated: 2024/09/27 03:57:03 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	msgDecoder(int sig)
{
	static int	binaryBase;
	static char	character;

	if (sig == SIGUSR1)
		character = character | (1 << binaryBase);
	binaryBase++;
	if (binaryBase == 8)
	{
		binaryBase = 0;
		write(1, &character, 1);
		character = 0;
	}
}

int	main(void)
{
	int						pid;
	struct sigaction		meu;

	meu.sa_handler = &msgDecoder;
	sigemptyset(&meu.sa_mask);
	meu.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &meu, NULL);
	sigaction(SIGUSR2, &meu, NULL);
	pid = getpid();
	ft_printf("Process PID number --> %d\n", pid);
	while (1)
		pause();
	return (0);
}