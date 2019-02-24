/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:15:42 by fshade            #+#    #+#             */
/*   Updated: 2018/12/12 17:46:47 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*newstr;

	if (s == NULL)
		return (NULL);
	j = ft_strlen(s);
	while (s[j - 1] == ' ' || s[j - 1] == '\t' || s[j - 1] == '\n')
		j--;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		j--;
	if (j <= 0)
		j = 0;
	newstr = (char*)malloc(sizeof(char) * (j + 1));
	if (newstr == NULL)
		return (NULL);
	s += i;
	i = -1;
	while (++i < j)
		newstr[i] = *s++;
	newstr[i] = '\0';
	return (newstr);
}
