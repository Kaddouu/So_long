/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:10:38 by ilkaddou          #+#    #+#             */
/*   Updated: 2024/11/11 18:29:05 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*#include <ctype.h>
int	main(void)
{
	printf("%d\n", ft_isprint(67));
	int c;
	int result;

	c = 67;
	result = isprint(c);
	printf("%d\n", result);
}*/
