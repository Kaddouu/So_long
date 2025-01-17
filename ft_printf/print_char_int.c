/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:18:08 by ilkaddou          #+#    #+#             */
/*   Updated: 2024/11/21 17:39:44 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

int	ft_print_string(const char *str)
{
	if (!str)
		str = "(null)";
	ft_putstr_fd((char *)str, 1);
	return (ft_strlen(str));
}

int	ft_print_decimal(int n)
{
	char	*str;
	int		length;

	str = ft_itoa_signed(n);
	ft_putstr_fd(str, 1);
	length = ft_strlen(str);
	free(str);
	return (length);
}

int	ft_print_unsigned(unsigned int n)
{
	char	*str;
	int		length;

	str = ft_itoa_unsigned(n);
	ft_putstr_fd(str, 1);
	length = ft_strlen(str);
	free(str);
	return (length);
}
