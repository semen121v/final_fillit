/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 21:02:15 by fshade            #+#    #+#             */
/*   Updated: 2018/12/15 17:47:14 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int		i;

	i = 2;
	if (n < 0)
		i = 3;
	while (n /= 10)
		i++;
	return (i);
}

static int	ft_symbol(int n)
{
	int		i;

	i = 0;
	if (n < 0)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		k;
	int		z;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_size(n);
	k = n;
	str = (char*)malloc(sizeof(char) * (i));
	if (str == NULL)
		return (NULL);
	str[--i] = '\0';
	z = ft_symbol(n);
	if (z == 1)
		n = n * (-1);
	while (i--)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	if (z == 1)
		str[0] = '-';
	return (str);
}
