/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:48:05 by fshade            #+#    #+#             */
/*   Updated: 2019/02/02 19:40:42 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numberword(char const *s, char c)
{
	int		i;
	int		count;
	int		pos;

	i = 0;
	count = 0;
	pos = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && pos == 0)
		{
			count++;
			pos = 1;
		}
		else if (s[i] == c && pos == 1)
		{
			pos = 0;
		}
		i++;
	}
	return (count);
}

static int	ft_size(const char *s, int i, char c)
{
	int		size;

	size = 0;
	while (*(s + i) != c && *(s + i) != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

static char	*ft_newword(char const *s, char c, int i)
{
	int		k;
	char	*words;

	k = ft_size(s, i, c) + 1;
	k = 0;
	if ((words = (char*)malloc(sizeof(char*)
			* (ft_size(s, i, c) + 1))) == NULL)
		return (NULL);
	while (s[i] != c)
		words[k++] = s[i++];
	words[k] = '\0';
	return (words);
}

static char	**ft_masfree(char **words)
{
	int		i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**words;

	if (!s)
		return (NULL);
	i = ft_numberword(s, c);
	if ((words = (char**)malloc(sizeof(char*) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	j = -1;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			if ((words[++j] = ft_newword(s, c, i)) == NULL)
				return (ft_masfree(words));
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	words[++j] = 0;
	return (words);
}
