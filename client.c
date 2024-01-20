/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:30:06 by sprodatu          #+#    #+#             */
/*   Updated: 2024/01/20 14:00:12 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//	* Sends a string to a server process using UNIX signals.
//  * Each character in the string is sent bit by bit.
//  * SIGUSR1 represents a '1' bit, and SIGUSR2 represents a '0' bit.
//  * After the entire string is sent, an end-of-message signal is transmitted.
//  * @param pid - PID of server process to which the signal is sent.
//  * @param str - string to be transmitted.

int	ft_iswhite(char c)
{
	if ((c == ' ') || (c == '\t') || (c == '\n')
		|| (c == '\f') || (c == '\r') || (c == '\v'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	index;

	result = 0;
	sign = 1;
	index = 0;
	while (ft_iswhite(str[index]))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while ((str[index] >= '0') && (str[index] <= '9'))
	{
		result = 10 * result + (str[index] - '0');
		index++;
	}
	return (result * sign);
}

void	ft_tramsmit_signal(int pid, char *str)
{
	unsigned char	current_char;
	int				bit_index;

	while (*str)
	{
		current_char = *str;
		bit_index = 7;
		while (bit_index >= 0)
		{
			if (current_char & (1 << bit_index))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit_index--;
			usleep(99);
		}
		str++;
	}
	bit_index = 0;
	while (bit_index < 8)
	{
		kill(pid, SIGUSR2);
		usleep(200);
		bit_index++;
	}
}

int	main(int argc, char *argv[])
{
	int	server_pid;

	server_pid = ft_atoi(argv[1]);
	if (argc != 3 || server_pid == -1)
	{
		ft_printf("Inavlid PID: %d\n", server_pid);
		return (1);
	}
	ft_tramsmit_signal(server_pid, argv[2]);
	return (0);
}
