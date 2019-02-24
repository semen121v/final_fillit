/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetrimino_fillit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <eschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:45:44 by eschoen           #+#    #+#             */
/*   Updated: 2019/02/20 20:43:34 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**read_tetrimino_fillit(int fd)
{
	int		i;
	char	**map;

	i = 0;
	if ((map = (char **)malloc(sizeof(char *) * TETROMINO_BUFF_SIZE)) == NULL)
		return (NULL);
	while (i < MAX_NUMBER_OF_TETROMINO)
	{
		if ((map[i] = (char *)malloc(sizeof(char) * TETROMINO_CHR_QTY)) == NULL)
			return (NULL);
		ft_bzero(map[i], TETROMINO_CHR_QTY);
		if (read(fd, map[i], TETROMINO_CHR_QTY) == 0)
		{
			ft_memdel((void **)map[i]);
			free(map[i]);
			map[i] = NULL;
			return (map);
		}
		i++;
		g_tetr_qty = i;
	}
	return (NULL);
}
