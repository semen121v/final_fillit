/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:23:06 by fshade            #+#    #+#             */
/*   Updated: 2018/12/11 20:02:40 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new_s;

	if (s == NULL || f == NULL)
		return (NULL);
	new_s = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (new_s == NULL)
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		new_s[i] = f(i, s[i]);
	new_s[i] = '\0';
	return (new_s);
}
