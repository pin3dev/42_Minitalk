/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:35:14 by ivbatist          #+#    #+#             */
/*   Updated: 2024/09/27 21:09:41 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

/**
 * @brief Decodes signals received from the client and reconstructs characters.
 *
 * This function handles incoming signals (`SIGUSR1` and `SIGUSR2`) from the client.
 * It reconstructs the character bit by bit, where `SIGUSR1` represents a binary 1
 * and `SIGUSR2` represents a binary 0. Once 8 bits (1 byte) are received, it prints
 * the character to the standard output.
 *
 * @param sig The signal received from the client, either `SIGUSR1` or `SIGUSR2`.
 */
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

/**
 * @brief Main function for the server program.
 *
 * This function initializes the server, prints its process ID (PID), and sets up
 * the signal handlers for `SIGUSR1` and `SIGUSR2`. The server then enters an infinite loop,
 * waiting for signals from the client to decode and display the message.
 *
 * @return 0 on successful completion.
 */
int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Process PID number --> %d\n", pid);
	
	signal(SIGUSR1, decoder);
	signal(SIGUSR2, decoder);
	
	while (1)
		pause();
	return (0);
}