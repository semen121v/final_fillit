/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_fillit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:53:41 by eschoen           #+#    #+#             */
/*   Updated: 2019/02/25 21:24:00 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	fillit_del_tetromino(t_coordinates *tet, char **map, int y, int x)
{
	int		row;
	int		col;
	int		i;

	i = 0;
	col = 0;
	while (tet->height > col)
	{
		row = 0;
		while (tet->width > row)
		{
			if (tet->dot[i][0] == col && tet->dot[i][1] == row)
			{
				map[col + y][row + x] = DOT;
				i++;
			}
			row++;
		}
		col++;
	}
}

static void	fillit_set_tetromino(t_coordinates *tet, char **map, int y, int x)
{
	int		row;
	int		col;
	int		i;

	i = 0;
	col = 0;
	while (tet->height > col)
	{
		row = 0;
		while (tet->width > row)
		{
			if (tet->dot[i][0] == col && tet->dot[i][1] == row)
			{
				map[col + y][row + x] = tet->letter;
				i++;
			}
			row++;
		}
		col++;
	}
}

static int	fillit_check_placement(t_coordinates *tet, char **map, int y, int x)
{
	int		row;
	int		col;
	int		i;

	i = 0;
	col = 0;
	while (tet->height > col)
	{
		row = 0;
		while (tet->width > row)
		{
			if (tet->dot[i][0] == col && tet->dot[i][1] == row)
			{
				if (map[col + y][row + x] != DOT)
					return (0);
				i++;
			}
			row++;
		}
		col++;
	}
	fillit_set_tetromino(tet, map, y, x);
	return (1);
}

static int	fillit_find_solution(char **map, t_coordinates *tet, int size)
{
	int		x;
	int		y;

	y = -1;
	while (++y <= (size - tet->height))
	{
		x = -1;
		while (++x <= (size - tet->width))
		{
			if (fillit_check_placement(tet, map, y, x) == 1)
			{
				if (tet->next == NULL)
					return (1);
				if (fillit_find_solution(map, tet->next, size) == 1)
					return (1);
				fillit_del_tetromino(tet, map, y, x);
			}
		}
	}
	return (0);
}

char		**fillit_resolve(t_coordinates *tet)
{
	char	**map;
	int		i;
	int		size;

	size = count(tet);
	map = fillit_create_map(size);
	while ((i = fillit_find_solution(map, tet, size)) == 0)
	{
		ft_memdel_map(&map);
		size++;
		map = fillit_create_map(size);
	}
	clean_coordinates(tet);
	return (map);
}
