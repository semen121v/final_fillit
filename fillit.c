/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:04:29 by ldonnis           #+#    #+#             */
/*   Updated: 2019/02/24 18:42:50 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_mas		*check_tetrimisions2(int i, char *str)
{
	t_mas *ptr;

	i = valid_tetriminos3(str);
	if (i == 1)
	{
		if (valid_tetriminos2(str, 0, 0) == 1)
		{
			ptr = prepare(str);
			return (ptr);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}

t_mas				*check_tetrimisions1(char *argv)
{
	char	*str;
	int		i;

	i = 0;
	if ((str = ft_read(argv)) == NULL)
		return (NULL);
	i = valid_tetriminos1(str);
	if (i == 1)
		return (check_tetrimisions2(i, str));
	else
		return (NULL);
	return (NULL);
}

t_coordinates		*fillit(t_mas *ptr)
{
	t_map			*map;
	t_map			*first;
	t_coordinates	*size;
	t_coordinates	*dot;

	dot = creat_coordinates(ptr);
	size = creat_size(ptr);
	map = newtetrimo(dot, size);
	first = map;
	return (creat_newcoordinates(first));
}
