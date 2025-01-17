/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:07:25 by ilkaddou          #+#    #+#             */
/*   Updated: 2024/11/13 17:28:09 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	nlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len += 1;
	while (n)
	{
		n /= 10;
		len += 1;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	len;
	char	*res;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = nlen(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
		i = 1;
	}
	while (len-- > i)
	{
		res[len] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
//int main()
//{
//	char *str = ft_itoa(10);
//	printf("%s\n", str);
//	//printf("%s\n", itoa(-10));
//	free(str);
//}
//