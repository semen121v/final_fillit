/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:07:38 by fshade            #+#    #+#             */
/*   Updated: 2018/12/11 17:50:32 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s3;
	unsigned char	*s4;

	s3 = (unsigned char*)s1;
	s4 = (unsigned char*)s2;
	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s3[i] == s4[i] && s3[i] != '\0' && s4[i] != '\0' && i < n - 1)
	{
		++i;
	}
	return (s3[i] - s4[i]);
}
