/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:09:45 by fshade            #+#    #+#             */
/*   Updated: 2018/12/25 22:14:38 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t i1;
	size_t pause;

	i = 0;
	if (ft_strlen(haystack) < ft_strlen(needle) || len == 0)
		return (NULL);
	while (haystack[i++])
	{
		pause = i - 1;
		i1 = 0;
		while (haystack[i - 1] == needle[i1])
		{
			if (needle[0] && !needle[i1 + 1] && pause + i1 <= len - 1)
				return ((char *)haystack + pause);
			i++;
			i1++;
		}
	}
	if (!needle[0])
		return ((char *)haystack);
	else if (haystack[1] && haystack[len])
		return (ft_strnstr(haystack + 1, needle, len - 1));
	else
		return (NULL);
}
