/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:05:01 by fshade            #+#    #+#             */
/*   Updated: 2018/12/15 18:15:37 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int a, size_t i)
{
	size_t	b;
	char	*srcptr;

	srcptr = src;
	b = 0;
	while (b < i)
	{
		srcptr[b] = (char)a;
		b++;
	}
	return (src);
}
