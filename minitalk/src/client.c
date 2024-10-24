/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:13:38 by ivbatist          #+#    #+#             */
/*   Updated: 2024/10/25 00:33:47 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief Encodes a string into binary and sends it as signals to a server.
 *
 * This function takes a string and encodes each character into its binary
 * representation. Each bit of the character is sent as a signal to the server:
 * - SIGUSR1 for a binary 1
 * - SIGUSR2 for a binary 0
 *
 * @param pid The process ID of the server.
 * @param str The string to be encoded and sent.
 */
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

/**
 * @brief Checks if the correct number of arguments were passed to the client program.
 *
 * This function validates the number of arguments passed to the client program.
 * It expects exactly 3 arguments (the program name, server PID, and message).
 * If the number of arguments is incorrect, it prints an error message.
 *
 * @param ac The number of arguments passed to the client.
 * @return true if the argument count is valid, false otherwise.
 */
bool	ckargs(int ac)
{
	if (ac != 3)
		return (ft_printf ("[Error]: Try ./client <server_pid> <your_msg>"), false);
	return (true);
}

/**
 * @brief Main function for the client program.
 *
 * This function serves as the entry point for the client. It validates the arguments,
 * converts the server PID, and sends the message to the server using the `encoder` function.
 *
 * @param ac The number of arguments passed to the program.
 * @param av The array of arguments, where av[1] is the server PID and av[2] is the message.
 * @return 0 on successful completion, 1 otherwise.
 */
int	main(int ac, char **av)
{
	int	pid;

	if (!ckargs(ac))
		return (1);
	pid = ft_atoi(av[1]);
	encoder(pid, av[2]);
	encoder(pid, "\n");
	return (0);
}
