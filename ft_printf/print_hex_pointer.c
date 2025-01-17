/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:18:26 by ilkaddou          #+#    #+#             */
/*   Updated: 2024/11/23 16:34:28 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(char c, unsigned long long n)
{
	char	*hex;
	int		count;

	count = 0;
	if (c == 'x')
		hex = "0123456789abcdef";
	else if (c == 'X')
		hex = "0123456789ABCDEF";
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	if (n >= 16)
		count += ft_print_hex(c, n / 16);
	ft_putchar_fd(hex[n % 16], 1);
	return (count + 1);
}

int	ft_print_pointer(void *ptr)
{
	int					count;
	unsigned long long	adress;
	unsigned long long	temp;

	adress = (unsigned long long)ptr;
	temp = adress;
	count = 2;
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		count = 5;
		return (count);
	}
	while (temp >= 16)
	{
		temp /= 16;
		count ++;
	}
	ft_putstr_fd("0x", 1);
	ft_print_hex('x', adress);
	return (count + 1);
}
