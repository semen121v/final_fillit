/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:13:13 by fshade            #+#    #+#             */
/*   Updated: 2018/12/08 17:47:49 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*srcptr1;
	char	*srcptr2;

	i = 0;
	srcptr1 = (char*)dst;
	srcptr2 = (char*)src;
	while (i < n)
	{
		if (srcptr2[i] == (char)c)
		{
			srcptr1[i] = srcptr2[i];
			i++;
			return (srcptr1 + i);
		}
		else
		{
			srcptr1[i] = srcptr2[i];
			i++;
		}
	}
	return (NULL);
}
