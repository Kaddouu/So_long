/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:25:27 by ilkaddou          #+#    #+#             */
/*   Updated: 2024/11/08 13:58:15 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
/*#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_isalnum('5'));
	int c;
	int result;

	c = '5';
	result = isalnum(c);
	printf("When %c is passed, return value is %d\n", c, result);
}*/