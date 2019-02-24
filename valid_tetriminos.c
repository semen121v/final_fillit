/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:33:27 by fshade            #+#    #+#             */
/*   Updated: 2019/02/24 18:59:07 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				valid_tetriminos1(char *str)
{
	int		i;

	i = 19;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			i++;
		else
			return (-1);
		if (str[i] == '\n')
			i++;
		else if (str[i] != '\0')
			return (-1);
		else if (str[i] == '\0')
			return (1);
		if (str[i] == '\n' || str[i] == '\0')
			return (-1);
		else
			i = i + 19;
	}
	return (-1);
}

int				valid_tetriminos2(char *str, int i, int j)
{
	int		k;

	k = 0;
	while (*str != '\0')
	{
		while (k != 20 && *str != '\0')
		{
			if (*str == '#')
				i++;
			if (*str == '.')
				j++;
			k++;
			str++;
		}
		k = 0;
		if (i == 4 && j == 12)
		{
			i = 0;
			j = 0;
		}
		else
			return (-1);
		str++;
	}
	return (1);
}

static int		checklinks(char *str, int cnt, int j)
{
	int		links;

	links = 0;
	if (((cnt - j) % 20) > 3)
		if ((str[cnt - 5]) && ((str[cnt - 5]) == '#'))
			links++;
	if ((str[cnt - 1]) && ((str[cnt - 1]) == '#'))
		links++;
	if ((str[cnt + 1]) && ((str[cnt + 1]) == '#'))
		links++;
	if (((cnt - j) % 20) < 15)
		if ((str[cnt + 5]) && ((str[cnt + 5]) == '#'))
			links++;
	return (links);
}

int				valid_tetriminos3(char *str)
{
	int links;
	int cnt;
	int bricks;
	int	j;

	bricks = 0;
	links = 0;
	cnt = 0;
	j = 0;
	while (str[cnt] != '\0')
	{
		while (bricks++ != 20)
		{
			if (str[cnt] == '#')
				links = links + checklinks(str, cnt, j);
			cnt++;
		}
		if (links != 6 && links != 8)
			return (-1);
		links = 0;
		bricks = 0;
		cnt++;
		j++;
	}
	return (1);
}
