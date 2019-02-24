/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:01:40 by fshade            #+#    #+#             */
/*   Updated: 2018/12/07 21:15:42 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *src, size_t n)
{
	size_t	b;
	char	*srcptr;

	b = 0;
	srcptr = (char*)src;
	if (n == 0)
		return (src);
	else
	{
		while (b < n)
		{
			srcptr[b] = '\0';
			b++;
		}
	}
	return (src);
}
