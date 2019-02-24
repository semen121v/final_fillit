/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newtetrimo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:55:33 by fshade            #+#    #+#             */
/*   Updated: 2019/02/24 18:02:35 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		createnewtetrimo2(t_map *new, t_coordinates *dot,\
								t_coordinates *size)
{
	int		k;
	int		i;
	int		j;

	k = 3;
	while (k != -1)
	{
		i = dot->dot[k][1] - size->dot[0][0];
		j = dot->dot[k][0] - size->dot[0][1];
		new->mas[j][i] = '#';
		k--;
	}
}

static void		createnewtetrimo1(t_map *new, int i, int j)
{
	if ((new->mas = (char**)malloc(sizeof(char*) * (j + 1))) == NULL)
		return ;
	new->width = i;
	new->height = j;
	new->mas[j] = NULL;
	while (j != 0)
	{
		if ((new->mas[j - 1] = (char*)malloc(sizeof(char*) * i)) == NULL)
			return ;
		ft_memset(new->mas[j - 1], '.', i);
		j--;
	}
}

t_map			*newtetrimo(t_coordinates *dot, t_coordinates *size)
{
	t_map	*new;
	t_map	*first;
	int		i;

	if (!size)
		return (NULL);
	if ((new = (t_map*)malloc(sizeof(t_map))) == NULL)
		return (NULL);
	first = new;
	while (size)
	{
		i = size->dot[3][0] - size->dot[0][0] + 1;
		createnewtetrimo1(new, i, size->dot[3][1] - size->dot[0][1] + 1);
		createnewtetrimo2(new, dot, size);
		if (dot->next == NULL)
			break ;
		new->next = (t_map*)malloc(sizeof(t_map));
		new = new->next;
		dot = dot->next;
		size = size->next;
	}
	return (first);
}
