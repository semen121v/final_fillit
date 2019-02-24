/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:30:21 by fshade            #+#    #+#             */
/*   Updated: 2018/12/07 20:55:13 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*srcptr1;
	char	*srcptr2;

	srcptr1 = (char*)dst;
	srcptr2 = (char*)src;
	i = 0;
	while (i < n)
	{
		srcptr1[i] = srcptr2[i];
		i++;
	}
	return (dst);
}
