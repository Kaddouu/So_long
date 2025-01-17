/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:21:34 by ilkaddou          #+#    #+#             */
/*   Updated: 2024/11/09 13:23:39 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (s);
}
/*int	main(void)
{
	int i;
	char buffer[50];
	char buffer2[10];

	// test avec mon memset
	i = 0;
	ft_memset(buffer, 67, 10);
	while (i < 10)
	{
		printf("%c ", buffer[i]);
		i++;
	}
		printf("\n");

	// test avec vrai memset
	i = 0;
	memset(buffer2, 67, 10);
	while (i < 10)
	{
		printf("%c ", buffer2[i]);
		i++;
	}
	printf("\n");
	return (0);
}*/