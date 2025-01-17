/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:30:31 by ilkaddou          #+#    #+#             */
/*   Updated: 2024/11/25 20:19:15 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert(char c, va_list args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (c == '%')
		return (ft_print_percent());
	if (c == 's')
		return (ft_print_string(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_print_decimal(va_arg(args, int)));
	if (c == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_print_hex(c, va_arg(args, unsigned int)));
	if (c == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *entry, ...)
{
	va_list	args;
	int		total_length;
	int		i;

	va_start(args, entry);
	total_length = 0;
	i = 0;
	if (!entry)
		return (-1);
	while (entry[i])
	{
		if (entry[i] == '%' && entry[i + 1])
		{
			total_length += convert(entry[i + 1], args);
			i++;
		}
		else
			total_length += ft_print_char(entry[i]);
		i++;
	}
	va_end(args);
	return (total_length);
}
