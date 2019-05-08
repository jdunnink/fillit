/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   freeer.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 11:57:53 by jdunnink       #+#    #+#                */
/*   Updated: 2019/05/07 10:48:01 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_list(t_list **lst)
{
	ft_lstdel(lst, &ft_del);
}

void	free_map(char **map, size_t mapsize)
{
	size_t i;

	i = 0;
	while (i < mapsize)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_tetro(char **tetro)
{
	int i;

	i = 0;
	while (tetro[i])
	{
		free(tetro[i]);
		i++;
	}
	free(tetro);
}
