/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:10:59 by fshade            #+#    #+#             */
/*   Updated: 2018/12/11 16:57:04 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*srcptr;

	srcptr = (char*)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (srcptr[i] == (unsigned char)c)
			return (srcptr + i);
		i--;
	}
	return (NULL);
}
