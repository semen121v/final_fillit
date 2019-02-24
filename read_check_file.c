/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <eschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:51:24 by eschoen           #+#    #+#             */
/*   Updated: 2019/02/20 10:12:09 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_symbols_calc_length(char *file)
{
	int		i;
	int		fd;
	char	tmp;

	i = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, &tmp, 1))
	{
		if (tmp != DOT && tmp != HASH && tmp != NEW_LINE)
			return (-1);
		i++;
	}
	if (i > (MAX_NUMBER_OF_TETROMINO * TETROMINO_CHR_QTY - 1) || \
			i < (TETROMINO_CHR_QTY - 1))
		return (-1);
	close(fd);
	return (i);
}

char		*ft_read_file(char *file)
{
	int		i;
	int		fd;
	char	*str;
	char	tmp;

	i = ft_check_symbols_calc_length(file);
	if (i == -1)
		return (NULL);
	else
		str = ft_strnew(i + 1);
	fd = open(file, O_RDONLY);
	i = 0;
	while (read(fd, &tmp, 1))
		str[i++] = tmp;
	close(fd);
	return (str);
}
