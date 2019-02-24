/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:56:52 by fshade            #+#    #+#             */
/*   Updated: 2018/12/08 18:54:43 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*srcptr1;
	char	*srcptr2;

	srcptr1 = (char*)dst;
	srcptr2 = (char*)src;
	i = -1;
	if (srcptr2 < srcptr1)
		while ((int)(--len) >= 0)
			srcptr1[len] = srcptr2[len];
	else
		while (++i < len)
			*(srcptr1 + i) = *(srcptr2 + i);
	return (dst);
}
