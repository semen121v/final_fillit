/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:01:18 by eschoen           #+#    #+#             */
/*   Updated: 2019/02/24 16:21:30 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		creat_coordinates2(t_map *ptr, t_coordinates *dot, int i, int j)
{
	int		m;

	while (ptr)
	{
		m = -1;
		j = -1;
		while (++j != ptr->height)
		{
			i = -1;
			while (++i != ptr->width)
				if (ptr->mas[j][i] == '#')
				{
					dot->dot[++m][0] = j;
					dot->dot[m][1] = i;
				}
		}
		dot->width = ptr->width;
		dot->height = ptr->height;
		if (ptr->next == NULL)
			break ;
		dot->next = (t_coordinates*)malloc(sizeof(t_coordinates));
		dot = dot->next;
		ptr = ptr->next;
	}
	dot->next = NULL;
}

t_coordinates	*creat_newcoordinates(t_map *ptr)
{
	t_coordinates	*dot;
	t_coordinates	*first;
	int				i;
	int				j;

	i = -1;
	j = -1;
	if (!ptr)
		return (NULL);
	if ((dot = (t_coordinates*)malloc(sizeof(t_coordinates))) == NULL)
		return (NULL);
	first = dot;
	creat_coordinates2(ptr, dot, i, j);
	return (first);
}
