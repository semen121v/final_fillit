/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:27:17 by eschoen           #+#    #+#             */
/*   Updated: 2019/02/24 18:54:18 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The allowed functions are : exit, open, close, write, read, malloc and free.
** Library fcntl.h for open(), read()
** Library stdlib.h for malloc() and free()
** Library unistd.h for close()
*/

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <libft.h>
# define DOT '.'
# define HASH '#'

typedef struct				s_mas
{
	char					mas[4][4];
	struct s_mas			*next;
	struct s_mas			*prev;
}							t_mas;

typedef struct				s_map
{
	char					letter;
	int						width;
	int						height;
	char					**mas;
	struct s_map			*next;
	struct s_map			*prev;
}							t_map;

typedef struct				s_coordinates
{
	char					letter;
	int						width;
	int						height;
	int						dot[4][2];
	struct s_coordinates	*next;
}							t_coordinates;

int							valid_tetriminos1(char *str);
int							valid_tetriminos2(char *str, int i, int j);
int							valid_tetriminos3(char *str);
int							variation_valid(int i, int m);
int							count(t_coordinates *ptr);
char						**fillit_resolve(t_coordinates *tet);
char						*ft_read(char *fd);
void						cleanlist(t_mas *ptr);
t_mas						*prepare(char *str);
char						**fillit_create_map(int size);
t_coordinates				*creat_coordinates(t_mas *ptr);
t_coordinates				*creat_newcoordinates(t_map *ptr);
t_map						*newtetrimo(t_coordinates *dot,
								t_coordinates *size);
t_coordinates				*fillit(t_mas *ptr);
t_coordinates				*creat_size(t_mas *ptr);
t_mas						*check_tetrimisions1(char *argv);

#endif
