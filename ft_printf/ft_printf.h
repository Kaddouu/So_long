/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:54:43 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/17 20:19:45 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

int					ft_printf(const char *format, ...);
int					ft_print_char(int c);
int					ft_print_string(const char *str);
int					ft_print_decimal(int n);
int					ft_print_unsigned(unsigned int n);
int					ft_print_hex(char c, unsigned long long n);
int					ft_print_percent(void);
int					ft_print_pointer(void *ptr);
char				*ft_itoa_signed(int n);
char				*ft_itoa_unsigned(unsigned int n);
//int 				main(void);

#endif