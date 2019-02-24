/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:12:22 by fshade            #+#    #+#             */
/*   Updated: 2018/12/19 19:33:38 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char		*str1;
	char		*str2;
	int			i;
	int			j;

	str1 = (char*)haystack;
	str2 = (char*)needle;
	i = 0;
	if (*needle == '\0')
		return (str1);
	while (str1[i] != '\0')
	{
		j = 0;
		while (str2[j] == str1[i + j])
		{
			if (str2[j + 1] == '\0')
				return (str1 + i);
			j++;
		}
		i++;
	}
	return (0);
}
