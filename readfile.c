/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:31:56 by fshade            #+#    #+#             */
/*   Updated: 2019/02/26 21:54:57 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	ft_readlen(char *fd)
{
	int		i;
	int		file;
	char	tmp;

	i = 0;
	tmp = 0;
	file = open(fd, O_RDONLY);
	while (read(file, &tmp, 1))
	{
		if (tmp != '.' && tmp != '#' && tmp != '\n')
			return (-1);
		i++;
	}
	if (i > 545 || i < 20)
		return (-1);
	close(file);
	return (i);
}

char		*ft_read(char *fd)
{
	int		file;
	char	*str;
	char	tmp;
	int		i;

	i = 0;
	if (ft_readlen(fd) == -1)
		return (NULL);
	else
		str = ft_strnew(ft_readlen(fd) + 1);
	file = open(fd, O_RDONLY);
	while (read(file, &tmp, 1))
	{
		str[i++] = tmp;
	}
	close(file);
	return (str);
}
