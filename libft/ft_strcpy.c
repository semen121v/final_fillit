/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:53:53 by fshade            #+#    #+#             */
/*   Updated: 2018/12/07 18:58:37 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int		i;
	char	*srcptr;

	srcptr = (char*)src;
	i = 0;
	while (srcptr[i] != '\0')
	{
		dst[i] = srcptr[i];
		i++;
	}
	dst[i] = srcptr[i];
	return (dst);
}
