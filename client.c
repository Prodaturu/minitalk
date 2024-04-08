/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:30:06 by sprodatu          #+#    #+#             */
/*   Updated: 2024/04/08 01:52:56 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/** 
//	* Explanation: client.c
//	* --------------------
//	* Sends a string to a server process using UNIX signals.
//  * Each character in the string is sent bit by bit.
//  * SIGUSR1 represents a '1' bit, and SIGUSR2 represents a '0' bit.
//  * After the entire string is sent, an end-of-message signal is transmitted.
//  * @param pid - PID of server process to which the signal is sent.
//  * @param str - string to be transmitted.
*/

/**
 ** erklären: client.c
 ** -----------------------------------
 ** Sendet einen String an einen Serverprozess mit Hilfe von UNIX-Signalen.
 ** Jedes Zeichen im String wird bitweise gesendet.
 ** SIGUSR1 repräsentiert ein '1'-Bit und SIGUSR2 repräsentiert ein '0'-Bit.
 ** Nachdem der gesamte String gesendet wurde, 
 ** 	wird ein End-of-Message-Signal übertragen.
 ** @param pid - PID des Serverprozesses, an den das Signal gesendet wird.
 ** @param str - zu übertragender String.
*/

int	ft_iswhite(char c)
{
	if ((c == ' ') || (c == '\t') || (c == '\n')
		|| (c == '\f') || (c == '\r') || (c == '\v'))
		return (1);
	return (0);
}

/**
 ** Explanation: ft_atoi
 ** ------------------------
 **	Converts a string to an integer.
 ** @param str - string to be converted.
 ** @return - converted integer.
 ** ------------------------
 ** Checks if the character is a whitespace character.
 ** 	If so, the index is incremented.
 ** Checks if the character is a '-' or '+' sign.
 ** 	If so, the sign is set accordingly and the index is incremented.
 ** while the character is a digit,
 ** 	as the digit in ones place is 10^0, the digit in tens place is 10^1, and so on,
 ** 	result is calculated by multiplying previous result by 10 and adding current digit.
 ** 	and Index is incremented to move to the next character.
 ** After the loop, we have the number in result var.
 ** 	which is then multiplied by the sign to get the final result.
 */

/**
 ** Erklärung: ft_atoi
 ** -----------------------------------
 ** Konvertiert einen String in eine Ganzzahl.
*/

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
