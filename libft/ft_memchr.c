/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:17:06 by fshade            #+#    #+#             */
/*   Updated: 2018/12/11 19:30:37 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*srcptr1;

	srcptr1 = (unsigned char*)s;
	i = 0;
	while (i != n && srcptr1[i] != (unsigned char)c)
		i++;
	if (i == n)
		return (NULL);
	else
		return (&srcptr1[i]);
}
