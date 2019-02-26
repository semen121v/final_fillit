/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 22:03:19 by fshade            #+#    #+#             */
/*   Updated: 2019/02/26 23:58:17 by fshade           ###   ########.fr       */
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
			ft_strdel(&str);
			return (ptr);
		}
		else
		{
			ft_strdel(&str);
			return (NULL);
		}
	}
	else
	{
		ft_strdel(&str);
		return (NULL);
	}
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
	{
		ft_strdel(&str);
		return (NULL);
	}
	return (NULL);
}

t_coordinates		*fillit(t_mas *ptr)
{
	t_map			*map;
	t_coordinates	*size;
	t_coordinates	*dot;

	dot = creat_coordinates(ptr);
	size = creat_size(ptr);
	if ((map = newtetrimo(dot, size)) == NULL)
	{
		clean_coordinates(dot);
		clean_coordinates(size);
		clean_newtetrimo(map);
		return (0);
	}
	clean_coordinates(dot);
	clean_coordinates(size);
	dot = creat_newcoordinates(map);
	clean_newtetrimo(map);
	return (dot);
}
