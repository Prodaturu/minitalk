/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:31:35 by sprodatu          #+#    #+#             */
/*   Updated: 2024/01/20 10:05:48 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include "./printf/ft_printf.h"

void	ft_transmit_signal(int pid, char *str);
void	handle_signal(int signal);
int		pid_to_str(char *str, int pid);

#endif