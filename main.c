/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:37:28 by eschoen           #+#    #+#             */
/*   Updated: 2019/02/25 21:38:39 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				ft_print_map_fillit(char **map)
{
	size_t		i;
	size_t		length;

	i = 0;
	length = ft_strlen(*map);
	while (i < length)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

static void			how_to_use_fillit(char *av0)
{
	ft_putstr("usage: ");
	ft_putstr(av0);
	ft_putstr(" [fillit_file]\n");
}

static void			set_letter(t_coordinates *ptr)
{
	char	letter;

	letter = 'A';
	while (ptr)
	{
		ptr->letter = letter;
		ptr = ptr->next;
		letter++;
	}
}

int					main(int ac, char **av)
{
	t_mas			*ptr;
	t_coordinates	*first;
	char			**map;

	if (ac == 2)
	{
		ptr = check_tetrimisions1(av[1]);
		if (ptr == NULL)
		{
			ft_putstr("error\n");
			return (0);
		}
	}
	else
	{
		how_to_use_fillit(av[0]);
		return (0);
	}
	first = fillit(ptr);
	set_letter(first);
	cleanlist(ptr);
	map = fillit_resolve(first);
	ft_print_map_fillit(map);
	ft_memdel_map(&map);
	return (0);
}
