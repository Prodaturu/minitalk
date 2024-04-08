/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:27:55 by sprodatu          #+#    #+#             */
/*   Updated: 2024/04/03 06:20:58 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Signal handler function for SIGUSR1 and SIGUSR2
void	handle_signal(int signal_type)
{
	static int	char_assembly = 0;
	static int	bit_counter = 0;
	static int	sigusr2_counter = 0;

	if (signal_type == SIGUSR1)
	{
		char_assembly <<= 1;
		char_assembly |= 1;
		sigusr2_counter = 0;
	}
	else if (signal_type == SIGUSR2)
	{
		char_assembly <<= 1;
		sigusr2_counter++;
	}
	bit_counter++;
	if (bit_counter == 8)
	{
		if (sigusr2_counter < 8)
			ft_putchar(char_assembly);
		char_assembly = 0;
		bit_counter = 0;
	}
	if (sigusr2_counter == 8)
		sigusr2_counter = 0;
}

int	pid_to_str(char *str, int pid)
{
	int	i;
	int	temp_id;

	i = 0;
	if (pid == 0)
		str[i++] = 0;
	else
	{
		temp_id = pid;
		while (temp_id != 0)
		{
			i++;
			temp_id /= 10;
		}
		str[i] = '\0';
		while (pid != 0)
		{
			str[--i] = pid % 10 + '0';
			pid /= 10;
		}
	}
	return (0);
}

/**
 * @brief The main function of the server program.
 *
 * This function sets up signal handlers for SIGUSR1 and SIGUSR2 signals,
 * prints the server's process ID (PID), and enters an infinite loop where it
 * waits for signals using the pause() function.
 *
 * @return 0 indicating successful execution of the program.
 */

int	main(void)
{
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	ft_printf("Server PID: %d\n", getpid());
	while (9)
		pause();
	return (0);
}
