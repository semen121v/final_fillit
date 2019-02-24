/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:01:33 by fshade            #+#    #+#             */
/*   Updated: 2018/12/11 16:40:41 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	b;
	size_t	j;
	char	*string;

	string = (char*)src;
	i = 0;
	j = ft_strlen(dst);
	b = ft_strlen(src);
	if (size <= j)
		return (size + b);
	while ((dst[i] != '\0') && i < (size - 1))
		i++;
	while (*string && i < (size - 1))
	{
		dst[i] = *string;
		i++;
		string++;
	}
	dst[i] = '\0';
	return (j + b);
}
