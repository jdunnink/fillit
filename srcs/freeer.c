/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   freeer.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 11:57:53 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/06 13:01:49 by jdunnink      ########   odam.nl         */
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
