/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:47:21 by ilkaddou          #+#    #+#             */
/*   Updated: 2024/11/13 16:39:10 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dst;
	char	*source;

	if (!dest && !src)
		return (NULL);
	dst = (char *)dest;
	source = (char *)src;
	i = 0;
	while (i < n)
	{
		dst[i] = source[i];
		i++;
	}
	return (dest);
}
/*int	main(void)
{
	// test ft_memcpy
	char src[] = "Hello, world!";
	char dst[20];
	ft_memcpy(dst, src, ft_strlen(src) + 1);
	printf("%s\n", dst);

	// test vrai memcpy
	char src2[] = "Hello, world!";
	char dst2[20];
	memcpy(dst2, src2, strlen(src2) + 1);
	printf("%s\n", dst2);

	return (0);
}*/