/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:39:41 by fshade            #+#    #+#             */
/*   Updated: 2019/02/24 18:53:41 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char				**fillit_create_map(int size)
{
	char	**map;
	int		row;
	int		col;

	if ((map = (char **)malloc(sizeof(char *) * size)) == NULL)
		return (NULL);
	row = 0;
	while (row < size)
	{
		if ((map[row] = (char *)malloc(sizeof(char) * size + 1)) == NULL)
			return (NULL);
		row++;
	}
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
			map[row][col++] = DOT;
		map[row][col] = '\0';
		row++;
	}
	return (map);
}

static int			ft_sqrt(int i)
{
	int a;

	a = 0;
	while ((a * a) <= i)
	{
		if ((a * a) == i)
			return (a);
		a++;
	}
	return (a);
}

int					count(t_coordinates *ptr)
{
	int		i;

	i = 0;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (ft_sqrt(i * 4));
}
