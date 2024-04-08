/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:31:35 by sprodatu          #+#    #+#             */
/*   Updated: 2023/11/22 15:13:46 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

size_t	calculate_padding(t_format format_info, size_t print_len)
{
	size_t	padding;

	padding = 0;
	if (format_info.width > (int) print_len)
		padding = format_info.width - print_len;
	return (padding);
}
