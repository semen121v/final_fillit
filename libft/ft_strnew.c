/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 21:22:05 by fshade            #+#    #+#             */
/*   Updated: 2018/12/19 19:43:42 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*src;

	src = (char*)malloc(size + 1);
	if (src == NULL)
		return (NULL);
	else
		ft_memset(src, '\0', size + 1);
	return (src);
}
