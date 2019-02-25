/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:20:30 by fshade            #+#    #+#             */
/*   Updated: 2019/02/25 21:13:27 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			clean_coordinates(t_coordinates *ptr)
{
	t_coordinates	*start;

	if (ptr == NULL)
		return ;
	while (ptr != NULL)
	{
		start = ptr->next;
		free(ptr);
		ptr = start;
	}
}

static void		creat_coordinates2(t_mas *ptr, t_coordinates *dot, int i, int j)
{
	int		m;

	while (ptr)
	{
		m = -1;
		j = -1;
		while (++j != 4)
		{
			i = -1;
			while (++i != 4)
			{
				if (ptr->mas[j][i] == '#')
				{
					dot->dot[++m][0] = j;
					dot->dot[m][1] = i;
				}
			}
		}
		if (ptr->next == NULL)
			break ;
		dot->next = (t_coordinates*)malloc(sizeof(t_coordinates));
		dot = dot->next;
		ptr = ptr->next;
	}
	dot->next = NULL;
}

t_coordinates	*creat_coordinates(t_mas *ptr)
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
