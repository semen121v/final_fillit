/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:11:45 by fshade            #+#    #+#             */
/*   Updated: 2019/01/11 17:48:09 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*srcptr;

	srcptr = (char*)s;
	i = 0;
	while (srcptr[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return (&srcptr[i]);
		else
			i++;
	}
	if (s[i] == (unsigned char)c)
		return (&srcptr[i]);
	return (NULL);
}
