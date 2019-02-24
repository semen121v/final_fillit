/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 21:59:47 by fshade            #+#    #+#             */
/*   Updated: 2018/12/11 20:25:12 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		new_s[i] = f(s[i]);
	new_s[i] = '\0';
	return (new_s);
}
