/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:28:46 by fshade            #+#    #+#             */
/*   Updated: 2019/02/18 18:46:01 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		creat_size3(t_mas *ptr, t_coordinates *dot, int i, int j)
{
	int		m;

	m = -1;
	j = -1;
	while (++j != 4)
	{
		i = -1;
		while (++i != 4)
		{
			if (ptr->mas[j][i] == '#')
				dot->dot[++m][1] = j;
		}
	}
}

static void		creat_size2(t_mas *ptr, t_coordinates *dot, int i, int j)
{
	int		m;

	while (ptr)
	{
		m = -1;
		i = -1;
		while (++i != 4)
		{
			j = -1;
			while (++j != 4)
			{
				if (ptr->mas[j][i] == '#')
					dot->dot[++m][0] = i;
			}
		}
		creat_size3(ptr, dot, i, j);
		if (ptr->next != NULL)
		{
			dot->next = (t_coordinates*)malloc(sizeof(t_coordinates));
			dot = dot->next;
		}
		ptr = ptr->next;
	}
	dot->next = NULL;
}

t_coordinates	*creat_size(t_mas *ptr)
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
	creat_size2(ptr, dot, i, j);
	return (first);
}
